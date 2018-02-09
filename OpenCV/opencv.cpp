//
//  opencv.cpp
//  OpenCV
//
//  Created by Vincent Llauderes on 2/8/18.
//  Copyright © 2018 Vince Llauderes. All rights reserved.
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
    Ptr<BackgroundSubtractorMOG2> bg_model = createBackgroundSubtractorMOG2();
    
    bg_model->setDetectShadows(false);
    bg_model->setNMixtures(3);
    bg_model->setComplexityReductionThreshold(0.5);
    
    // Create empy input img, foreground and background image and foreground mask.
    Mat img, foregroundMask, backgroundImage, foregroundImg, median;
    
    // Open the camera in the device...
    VideoCapture cap(0);
    
    for(;;)
    {
        
        if (!cap.grab())
        {
            std::cout << "Video Capture Fail" << std::endl ;
        }
        else
        {
            // obtain input image from source
            cap.retrieve(img, CV_CAP_OPENNI_BGR_IMAGE);
            
            // Just resize input image if you want
            resize(img,img,Size(640,480));
            
            // create foreground mask of proper size
            if( foregroundMask.empty() )
            {
                foregroundMask.create(img.size(), img.type());
            }
            
            // compute foreground mask 8 bit image
            bg_model->apply(img, foregroundMask);
            
            // Blur the foreground mask to reduce the effect of noise and false positives
            cv::blur(foregroundMask, foregroundMask, cv::Size(15, 15), cv::Point(-1, -1));
            
            // Remove the shadow parts and the noise
            cv::threshold(foregroundMask, foregroundMask, 128, 255, cv::THRESH_BINARY);
            
            // create black foreground image
            foregroundImg = cv::Scalar::all(255);
            
            // smooth the mask to reduce noise in image
            GaussianBlur(foregroundMask, foregroundMask, Size(11,11), 3.5,3.5);
            
            // threshold mask to saturate at black and white values
            threshold(foregroundMask, foregroundMask, 10, 255, THRESH_BINARY);
            
            dilate(foregroundMask, foregroundMask, NULL);
            
            erode(foregroundMask, foregroundMask, NULL);
            
            // Copy source image to foreground image only in area with white mask
            img.copyTo(foregroundImg, foregroundMask);
            
            //Get background image
            bg_model->getBackgroundImage(backgroundImage);
            
            // Create a window and Show the results
            imshow("Foreground mask", foregroundMask);
            imshow("Foregounr image", foregroundImg);
        }
        
        waitKey(40);
        
    }
    
    return EXIT_SUCCESS;
}
