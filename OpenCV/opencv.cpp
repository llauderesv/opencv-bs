//
//  opencv.cpp
//  OpenCV
//
//  Created by Vincent Llauderes on 2/8/18.
//  Copyright © 2018 Vince Llauderes. All rights reserved.
//
//

#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>

#include "opencv2/video/background_segm.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

int main(int argc, const char** argv)
{
    
    //  Init background substractor
    Ptr<BackgroundSubtractorMOG2> bg_model = createBackgroundSubtractorMOG2(0, -1, false);
    
    bg_model->setDetectShadows(false);
    bg_model->setNMixtures(3);
    bg_model->setComplexityReductionThreshold(10);
    
    // Create empy input img, foreground and background image and foreground mask.
    Mat img, foregroundMask, backgroundImage, foregroundImg, median;
    
    // Open the camera in the device...
    VideoCapture cap(0);
    
    while(true)
    {
        if (!cap.grab())
        {
            std::cout << "Failed to open camera..." << std::endl;
        }
        else
        {
            // obtain input image from source
            cap.retrieve(img, CV_CAP_OPENNI_BGR_IMAGE);
            
            // Just resize input image if you want
            resize(img, img,Size(300, 300));
            
            // create foreground mask of proper size
            if( foregroundMask.empty() )
                foregroundMask.create(img.size(), img.type());
            
            // compute foreground mask 8 bit image
            bg_model->apply(img, foregroundMask);
            
            /* Algorithm
             1. Threshold first
             2. Apply Median Blur
             3.
             */
            
            // create black foreground image
            foregroundImg = imread("Images/background.png");
            
            // Blur the foreground mask to reduce the effect of noise and false positives
//            cv::blur(foregroundMask, foregroundMask, cv::Size(15, 15), cv::Point(-1, -1));
            
            // Remove the shadow parts and the noise
//            cv::threshold(foregroundMask, foregroundMask, 128, 255, cv::THRESH_BINARY);
            
            // threshold mask to saturate at black and white values
//            threshold(foregroundMask, foregroundMask, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
            
//            medianBlur(foregroundMask, foregroundMask, 1);
            
            // smooth the mask to reduce noise in image
//            GaussianBlur(foregroundMask, foregroundMask, Size(11,11), 3.5,3.5);
            
//            dilate(foregroundMask, foregroundMask, -1);
            
//            cv::blur(foregroundMask, foregroundMask, cv::Size(40, 40), cv::Point(-1, -1));
//
//            threshold(foregroundMask, foregroundMask, 128, 255, cv::THRESH_BINARY | CV_THRESH_OTSU);
//
//            erode(foregroundMask, foregroundMask, -1);
//
//            dilate(foregroundMask, foregroundMask, -1);
//
//            medianBlur(foregroundMask, foregroundMask, 1);
//
//            GaussianBlur(foregroundMask, foregroundMask, Size(11,11), 5, 5);

//            cv::Mat mask = foregroundMask.clone();

//            cv::blur(foregroundMask, foregroundMask, cv::Size(10, 10), cv::Point(-1, -1));
            
            cv::dilate(foregroundMask, foregroundMask, cv::Mat());
            cv::dilate(foregroundMask, foregroundMask, cv::Mat());
            
            cv::erode(foregroundMask, foregroundMask, cv::Mat());
            cv::erode(foregroundMask, foregroundMask, cv::Mat());
            
            cv::erode(foregroundMask, foregroundMask, cv::Mat());
            cv::erode(foregroundMask, foregroundMask, cv::Mat());
            
            cv::dilate(foregroundMask, foregroundMask, cv::Mat());
            cv::dilate(foregroundMask, foregroundMask, cv::Mat());
            
            cv::dilate(foregroundMask, foregroundMask, cv::Mat());
            cv::dilate(foregroundMask, foregroundMask, cv::Mat());
            
            cv::erode(foregroundMask, foregroundMask, cv::Mat());
            cv::erode(foregroundMask, foregroundMask, cv::Mat());
            
            cv::erode(foregroundMask, foregroundMask, cv::Mat());
            cv::erode(foregroundMask, foregroundMask, cv::Mat());
            
            cv::dilate(foregroundMask, foregroundMask, cv::Mat());
            cv::dilate(foregroundMask, foregroundMask, cv::Mat());
            
//            cv::blur(foregroundMask, foregroundMask, cv::Size(10, 10), cv::Point(-1, -1));

            threshold(foregroundMask, foregroundMask, 128, 255, cv::THRESH_BINARY | CV_THRESH_OTSU);
//
            medianBlur(foregroundMask, foregroundMask, 7);
//
            GaussianBlur(foregroundMask, foregroundMask, Size(11,11), 5, 5);

//
//            cv::Mat resizedIn;
//            cv::Mat resizedMask;
//            cv::Mat resizedMedian;
//
//            cv::resize(mask, resizedMask, cv::Size(), 0.5, 0.5);
//            cv::resize(median, resizedMedian, cv::Size(), 0.5, 0.5);
//            cv::resize(img, resizedIn, cv::Size(), 0.5, 0.5);
//
//
            // Copy source image to foreground image only in area with white mask
            img.copyTo(foregroundImg, foregroundMask);
            
            // Get background image
            bg_model->getBackgroundImage(backgroundImage);
            
            // Create a window and Show the results
            imshow("Foreground mask", foregroundMask);
            imshow("Foreground image", foregroundImg);
//            imshow("Foreground mask", mask);
            
            
        }
        
        waitKey(40);
        
    }
    
    return EXIT_SUCCESS;
}







