////
////  opencv-image-transparency.cpp
////  OpenCV
////
////  Created by Vincent Llauderes on 2/11/18.
////  Copyright © 2018 Vince Llauderes. All rights reserved.
////
//
//#include <stdio.h>
//
//#include "opencv-image-diff.hpp"
//
//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//
//int main() {
//
//    Mat src = imread("Images/test.png", 1);
//
////    Mat dst; //(src.rows,src.cols,CV_8UC4);
////    Mat tmp,alpha;
////
////
////    cvtColor(src, tmp, CV_BGR2GRAY); // Convert Image to GrayScale...
////
////    threshold(tmp,alpha,100,255,THRESH_BINARY);
////
////    Mat rgb[3];
////    split(src, rgb);
////
////    Mat rgba[4]={rgb[0],rgb[1],rgb[2],alpha};
////    merge(rgba, 4, dst);
////
//////    resize(src, src, Size(600, 450));
////
////
////    imshow("Source Image", src);
////
////    imshow("Destination Image", dst);
//
////    Mat dst; //(src.rows,src.cols,CV_8UC4);
////    Mat tmp,thr;
////
////    cvtColor(src,tmp,CV_BGR2GRAY);
////    threshold(tmp,thr,100,255,THRESH_BINARY);
////
////    vector< vector <Point> > contours; // Vector for storing contour
////    vector< Vec4i > hierarchy;
////    int largest_contour_index=0;
////    int largest_area=0;
////
////    Mat alpha(src.size(),CV_8UC1,Scalar(0));
////    findContours( tmp, contours, hierarchy,CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE ); // Find the contours in the image
////    for( int i = 0; i< contours.size(); i++ ) // iterate through each contour.
////    {
////        double a=contourArea( contours[i],false);  //  Find the area of contour
////        if(a>largest_area){
////            largest_area=a;
////            largest_contour_index=i;                //Store the index of largest contour
////        }
////    }
////    drawContours( alpha,contours, largest_contour_index, Scalar(255),CV_FILLED, 8, hierarchy );
////
////    Mat rgb[3];
////    split(src,rgb);
////
////    Mat rgba[4]={rgb[0],rgb[1],rgb[2],alpha};
////    merge(rgba,4,dst);
////
//////    imwrite("Images/dst.png", dst);
////
////    imshow("Final result", dst);
////
////    waitKey();
////    return 0;
//
//    cv::Mat input = cv::imread("Images/1.png", CV_LOAD_IMAGE_GRAYSCALE);
//
//    cv::Mat mask = input.clone();
//
//    cv::dilate(mask, mask, cv::Mat());
//    cv::dilate(mask, mask, cv::Mat());
//    cv::erode(mask, mask, cv::Mat());
//    cv::erode(mask, mask, cv::Mat());
//
//    cv::erode(mask, mask, cv::Mat());
//    cv::erode(mask, mask, cv::Mat());
//
//    cv::dilate(mask, mask, cv::Mat());
//    cv::dilate(mask, mask, cv::Mat());
//
//    cv::Mat median;
//    cv::medianBlur(input, median, 7);
//
//    cv::Mat resizedIn;
//    cv::Mat resizedMask;
//    cv::Mat resizedMedian;
//
//
//    cv::resize(mask, resizedMask, cv::Size(), 0.5, 0.5);
//    cv::resize(median, resizedMedian, cv::Size(), 0.5, 0.5);
//    cv::resize(input, resizedIn, cv::Size(), 0.5, 0.5);
//
//    cv::imshow("input", resizedIn);
//    cv::imshow("mask", resizedMask);
//    cv::imshow("median", resizedMedian);
////
////    cv::imwrite("C:/StackOverflow/Output/maskNoiseMorph.png", mask);
////    cv::imwrite("C:/StackOverflow/Output/maskNoiseMedian.png", median);
//    cv::waitKey(0);
//    return 0;
//
//
//}
//
//
//
