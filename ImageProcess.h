#pragma once
#include<opencv2\opencv.hpp>
#include <opencv2\highgui.hpp>
#include"..\ED\ED.h"
#include"..\ED\EDLines.h"
#include"..\ED\EDCircles.h"
using namespace std;
using namespace cv;


Point2d getCramer(Vec4f L1, Vec4f L2);
cv::Scalar obj_id_to_color(int obj_id);
int partition(vector<LS>& _vec, vector<int>& labels, cv::Point center);
void get_edgeLineParameter(Mat frame, vector<Vec4f> &parameter);
double get_Distance(Point P1, Point P2);