#include "ImageProcess.h"



Point2d getCramer(Vec4f L1, Vec4f L2)//y=ax+b
{
	double a1 = (L1[1] / L1[0]);
	double a2 = (L2[1] / L2[0]);
	double b1 = L1[3] - a1 * L1[2];
	double b2 = L2[3] - a2 * L2[2];
	return Point2d((b1 - b2) / (a2 - a1), (b1*a2 - a1 * b2) / (a2 - a1));
}
cv::Scalar obj_id_to_color(int obj_id) {
	int const colors[6][3] = { { 1,0,1 },{ 0,0,1 },{ 0,1,1 },{ 0,1,0 },{ 1,1,0 },{ 1,0,0 } };
	int const offset = obj_id * 123457 % 6;
	int const color_scale = 150 + (obj_id * 123457) % 100;
	cv::Scalar color(colors[offset][0], colors[offset][1], colors[offset][2]);
	color *= color_scale;
	return color;
}
vector<vector<LS>>Cluster2List(vector<LS>&XYcord, vector<int> labels, int NoObj)
{
	vector<vector<LS> >ListTemp;
	ListTemp.resize(NoObj);
	for (uint i = 0; i < XYcord.size(); i++)
	{
		ListTemp[labels[i]].push_back(XYcord[i]);

	}
	return 	ListTemp;
}
bool predicate(LS P1, LS P2, cv::Point center)
{
	Mat tmp = Mat::zeros(cv::Size(2048, 2048), CV_8UC3);
	line(tmp, P1.start, P1.end, Scalar(255, 0, 0), 5);
	line(tmp, P2.start, P2.end, Scalar(0, 0, 255), 5);
	double slope1 = (P1.start.y - P1.end.y) / (P1.start.x - P1.end.x);
	double slope2 = (P2.start.y - P2.end.y) / (P2.start.x - P2.end.x);
	double angle1 = atan(slope1) * 180 / M_PI;
	double angle2 = atan(slope2) * 180 / M_PI;
	bool isParallel = abs(angle2 - angle1) < 3.6;
	if (isParallel)
	{
		double bias = center.y - slope1 * center.x;
		return (slope1*P1.start.x + bias - P1.end.y)*(slope1*P2.start.x + bias - P2.end.y) > 0;

	}
	else
	{
		return false;
	}


}

int partition(vector<LS>& _vec, vector<int>& labels, cv::Point center)
{
	int i, j, N = _vec.size();
	const LS * vec = &_vec[0];

	const int PARENT = 0;
	const int RANK = 1;

	vector<int> _nodes(N * 2);
	int(*nodes)[2] = (int(*)[2])&_nodes[0];

	for (i = 0; i < N; i++)
	{
		nodes[i][PARENT] = -1;
		nodes[i][RANK] = 0;
	}
	for (i = 0; i < N; i++)
	{
		int root = i;

		// find root
		while (nodes[root][PARENT] >= 0)
			root = nodes[root][PARENT];

		for (j = 0; j < N; j++)
		{
			if (i == j || !predicate(vec[i], vec[j],center))
				continue;
			int root2 = j;

			while (nodes[root2][PARENT] >= 0)
				root2 = nodes[root2][PARENT];

			if (root2 != root)
			{
				// unite both trees
				int rank = nodes[root][RANK], rank2 = nodes[root2][RANK];
				if (rank > rank2)
					nodes[root2][PARENT] = root;
				else
				{
					nodes[root][PARENT] = root2;
					nodes[root2][RANK] += rank == rank2;
					root = root2;
				}
				//assert(nodes[root][PARENT] < 0);

				int k = j, parent;

				// compress the path from node2 to root
				while ((parent = nodes[k][PARENT]) >= 0)
				{
					nodes[k][PARENT] = root;
					k = parent;
				}

				// compress the path from node to root
				k = i;
				while ((parent = nodes[k][PARENT]) >= 0)
				{
					nodes[k][PARENT] = root;
					k = parent;
				}
			}
		}
	}
	for (unsigned int i = 0; i < N; i++)
		labels.push_back(0);
	int nclasses = 0;

	for (i = 0; i < N; i++)
	{
		int root = i;
		while (nodes[root][PARENT] >= 0)
			root = nodes[root][PARENT];
		if (nodes[root][RANK] >= 0)
			nodes[root][RANK] = ~nclasses++;
		labels[i] = ~nodes[root][RANK];
	}
	return nclasses;

}
double get_Distance(Point P1, Point P2)
{
	return sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
}

void get_edgeLineParameter(Mat frame, vector<Vec4f> &parameter)
{

	Mat imageEnhance;


	medianBlur(frame, imageEnhance, 3);
	Mat img_Canny;
	cv::Canny(imageEnhance, img_Canny, 12, 15);
	cv::rectangle(img_Canny, Point(0, 0), Point(2047, 8), Scalar(0), CV_FILLED);
	cv::rectangle(img_Canny, Point(0, 2042), Point(2047, 2047), Scalar(0), CV_FILLED);
	Mat erodeStruct = getStructuringElement(MORPH_RECT, Size(3, 3));


	dilate(img_Canny, img_Canny, erodeStruct, Point(-1, -1), 3);

	cv::erode(img_Canny, img_Canny, erodeStruct, Point(-1, -1), 2);

	vector<vector<cv::Point>> contours; // Vector for storing contour
	vector<Vec4i>hierarchy;
	findContours(img_Canny, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	Mat Mask = Mat::zeros(img_Canny.size(), CV_8UC1);

	Point center;

	for (int i = 0; i < contours.size(); i++)
	{
		double Area = contourArea(contours[i], false);
		if (Area > pow(10, 6))//Area must bigger than 
		{
			drawContours(Mask, contours, i, Scalar(255), CV_FILLED, 8);
			cv::Moments m = cv::moments(Mask, false);
			center = cv::Point(m.m10 / m.m00, m.m01 / m.m00);
		}
	}


	cv::erode(Mask, Mask, erodeStruct, Point(-1, -1), 4);

	EDLines edline = EDLines(Mask);
	vector<LS> mlines = edline.getLines();
	Mat LineImg = edline.getLineImage();
	for (vector<LS>::iterator i = mlines.begin(); i != mlines.end();)
	{
		if (get_Distance((*i).start, (*i).end) < 50)
		{

			i = mlines.erase(i);
		}
		else
		{
			++i;
		}
	}
	vector<int> labels;

	int cluster = partition(mlines, labels, center);
	vector<vector<Point>> clusterPt;
	clusterPt.resize(cluster);
	
	parameter.resize(cluster);
	for (uint8_t i = 0; i < mlines.size(); i++)
	{
		clusterPt[labels[i]].push_back(mlines[i].start);
		clusterPt[labels[i]].push_back(mlines[i].end);
	}

	for (uint8_t i = 0; i < cluster; i++) 
		cv::fitLine(clusterPt[i], parameter[i], cv::DIST_L2, 0, 1e-2, 1e-2);
	
	
	/*Point2d intersect[6];

	for (uint8_t i = 1; i < 6; i++)
	{
		intersect[i - 1] = getCramer(parameter[i], parameter[i - 1]);
	}
	intersect[5] = getCramer(parameter[5], parameter[0]);

	vector<vector<LS>>LineList = Cluster2List(mlines, labels, cluster);
	Mat colorMask;
	cv::cvtColor(Mask, colorMask, CV_GRAY2BGR);
	
	for (size_t i = 0; i < 6; i++)
	{
		circle(colorMask, intersect[i], 15, Scalar(0, 255, 0), CV_FILLED);
	}


	for (uint8_t i = 0; i < LineList.size(); i++)
	{

		for (uint8_t j = 0; j < LineList[i].size(); j++)
		{
			putText(colorMask, std::to_string(i), cv::Point2f(LineList[i][j].start.x - 10, LineList[i][j].start.y - 10), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, cv::Scalar(20, 200, 240), 2);

			cv::line(colorMask, LineList[i][j].start, LineList[i][j].end, obj_id_to_color(i), 8);
		}

	}
	int a = 99;*/
	
}
