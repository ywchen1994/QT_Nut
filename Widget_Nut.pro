#-------------------------------------------------
#
# Project created by QtCreator 2019-08-17T17:53:49
#
#-------------------------------------------------

QT       += core gui
QT +=serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Widget_Nut
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    flycam.cpp

HEADERS += \
        mainwindow.h \
    flycam.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
INCLUDEPATH +=C:/OpenCV342/build/include  \
             C:/OpenCV342/build/include/opencv \
             C:/OpenCV342/build/include/opencv2 
         

CONFIG( debug, debug|release ) {
    # debug

       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_aruco342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_bgsegm342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_bioinspired342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_calib3d342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_ccalib342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_core342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_datasets342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_dnn342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_dnn_objdetect342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_dpm342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_face342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_features2d342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_flann342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_fuzzy342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_hdf342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_hfs342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_highgui342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_imgcodecs342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_imgproc342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_img_hash342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_line_descriptor342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_ml342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_objdetect342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_optflow342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_phase_unwrapping342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_photo342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_plot342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_reg342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_rgbd342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_saliency342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_shape342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_stereo342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_stitching342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_structured_light342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_superres342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_superres342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_surface_matching342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_text342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_tracking342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_video342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_videoio342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_videostab342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_world342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_xfeatures2d342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_ximgproc342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_xobjdetect342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_xphoto342d.lib
   

} else {
    # release
LIBS +=
       LIBS +=C:/tensorflow-master/tensorflow/contrib/cmake/build/Release/tensorflow.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_aruco342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_bgsegm342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_bioinspired342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_calib3d342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_ccalib342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_core342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_datasets342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_dnn342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_dnn_objdetect342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_dpm342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_face342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_features2d342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_flann342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_fuzzy342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_hdf342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_hfs342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_highgui342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_imgcodecs342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_imgproc342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_img_hash342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_line_descriptor342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_ml342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_objdetect342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_optflow342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_phase_unwrapping342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_photo342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_plot342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_reg342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_rgbd342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_saliency342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_shape342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_stereo342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_stitching342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_structured_light342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_superres342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_superres342d.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_surface_matching342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_text342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_tracking342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_video342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_videoio342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_videostab342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_world342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_xfeatures2d342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_ximgproc342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_xobjdetect342.lib
       LIBS +=C:/OpenCV342/build/x64/vc14/lib/opencv_xphoto342.lib
     
}
