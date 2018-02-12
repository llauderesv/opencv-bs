////
////  opencv-canny-edge.cpp
////  OpenCV
////
////  Created by Vincent Llauderes on 2/13/18.
////  Copyright © 2018 Vince Llauderes. All rights reserved.
////
//
//
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include <stdlib.h>
//#include <stdio.h>
//
//using namespace cv;
//using namespace std;
//
///// Global variables
//
//Mat src, src_gray;
//Mat dst, detected_edges;
//
//int edgeThresh = 1;
//int lowThreshold;
//int const max_lowThreshold = 100;
//int ratio = 3;
//int kernel_size = 3;
////char* window_name = "Edge Map";
//
///**
// * @function CannyThreshold
// * @brief Trackbar callback - Canny thresholds input with a ratio 1:3
// */
//void CannyThreshold(int, void*)
//{
//    /// Reduce noise with a kernel 3x3
//    blur( src_gray, detected_edges, Size(3,3) );
//
//    /// Canny detector
//    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold, kernel_size );
//
//    /// Using Canny's output as a mask, we display our result
//    dst = Scalar::all(0);
//
//    src.copyTo( dst, detected_edges);
//}
//
//
///** @function main */
//int main( int argc, char** argv )
//{
//
//    VideoCapture cap(0);
//
//    /// Load an image
////    src = imread( argv[1] );
//
//
//    while (true)
//    {
//        if (!cap.grab())
//        {
//            break;
//        }
//        else
//        {
//            cap.retrieve(src, CV_CAP_OPENNI_BGR_IMAGE);
//
//            resize(src, src, Size(550, 300));
//        }
//
//
//        /// Create a matrix of the same type and size as src (for dst)
//        dst.create( src.size(), src.type() );
//
//        /// Convert the image to grayscale
//        cvtColor( src, src_gray, CV_BGR2GRAY );
//
//        /// Create a window
//        namedWindow( "test", CV_WINDOW_AUTOSIZE );
//
//        /// Create a Trackbar for user to enter threshold
//        createTrackbar( "Min Threshold:", "test", &lowThreshold, max_lowThreshold, CannyThreshold );
//
//        /// Show the image
//        CannyThreshold(0, 0);
//
//        imshow("test", dst);
//
//        /// Wait until user exit program by pressing a key
//        waitKey(40);
//    }
//
//
//
//
//        return EXIT_SUCCESS;
//}

