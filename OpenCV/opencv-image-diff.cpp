////
////  opencv-image-diff.cpp
////  OpenCV
////
////  Created by Vincent Llauderes on 2/11/18.
////  Copyright © 2018 Vince Llauderes. All rights reserved.
////
//
//#include "opencv-image-diff.hpp"
//
//#include <opencv2/opencv.hpp>
//#include <iostream>
//using namespace std;
//using namespace cv;
//int main() {
//
//    Mat img1 = imread("Images/2.png");
//    Mat img2 = imread("Images/2(copy).png");
//
//
//    cv::blur(img1, img1, cv::Size(40, 40), cv::Point(-1, -1));
//    cv::blur(img2, img2, cv::Size(40, 40), cv::Point(-1, -1));
//
//    threshold(img1, img1, 128, 255, cv::THRESH_BINARY | CV_THRESH_OTSU);
//
//    erode(img1, img1, -1);
//    erode(img2, img2, -1);
//
//    dilate(img1, img1, -1);
//    dilate(img2, img2, -1);
//
//    medianBlur(img1, img1, 1);
//    medianBlur(img2, img2, 1);
//
//    GaussianBlur(img1, img1, Size(11,11), 5, 5);
//    GaussianBlur(img2, img2, Size(11,11), 5, 5);
//
//    // calc the difference
//    Mat diff;
//    absdiff(img1, img2, diff);
//
//    // Get the mask if difference greater than th
//    int th = 10;  // 0
//    Mat mask(img1.size(), CV_8UC1);
//    for(int j=0; j<diff.rows; ++j) {
//        for(int i=0; i<diff.cols; ++i){
//            cv::Vec3b pix = diff.at<cv::Vec3b>(j,i);
//            int val = (pix[0] + pix[1] + pix[2]);
//            if(val>th){
//                mask.at<unsigned char>(j,i) = 255;
//            }
//        }
//    }
//
//    // get the foreground
//    Mat res;
//    Mat resBackground;
//    Mat res2;
//    bitwise_and(img2, img2, res, mask);
//
//    res2 = res;
//
//    resBackground = imread("Images/background.png");
//
//    res.copyTo(resBackground, res2);
//
//    // display
//    imshow("res", res);
//
//    imshow("res2", res2);
//
//    imshow("resCopy", resBackground);
//
//    //    threshold(diffImage, diffImage, 128, 255, cv::THRESH_BINARY | CV_THRESH_OTSU);
////
////    cv::Mat diffImage;
////    cv::absdiff(img1, img2, diffImage);
////    cv::Mat foregroundMask = cv::Mat::zeros(diffImage.rows, diffImage.cols, CV_8UC1);
////
////    float threshold = 30.0f;
////    float dist;
////
////    for(int j=0; j<diffImage.rows; ++j)
////        for(int i=0; i<diffImage.cols; ++i)
////        {
////            cv::Vec3b pix = diffImage.at<cv::Vec3b>(j,i);
////
////            dist = (pix[0]*pix[0] + pix[1]*pix[1] + pix[2]*pix[2]);
////            dist = sqrt(dist);
////
////            if(dist>threshold)
////            {
////                foregroundMask.at<unsigned char>(j,i) = 255;
////            }
////        }
////
////    imshow("res", diffImage);
//
////    imshow("res2", res2);
//
////    imshow("resCopy", resBackground);
//
//    waitKey();
//    return 0;
//}
//
//
