////
////  main.cpp
////  OpenCV
////
////  Created by Vincent Llauderes on 1/31/18.
////  Copyright © 2018 Vince Llauderes. All rights reserved.
////
////#include "opencv2/highgui.hpp"
////#include "opencv2/imgproc.hpp"
////
////#include <vector>
////#include <fstream>
////#include <iostream>
////#include <math.h>
////
////#include "opencv2/video/background_segm.hpp"
////#include "opencv2/highgui.hpp"
////#include "opencv2/imgproc.hpp"
////
////using namespace cv;
////using namespace std;
////
////int main(int argc, const char** argv)
////{
////
////
////
////
//////    cv::BackgroundSubtractorMOG2 bg(0, 0, 0.7,);
////    Ptr<BackgroundSubtractorMOG2> bg_model = createBackgroundSubtractorMOG2(20, 16, true);
////
////
////    // Init background substractor
//////    Ptr<BackgroundSubtractor> bg_model = createBackgroundSubtractorMOG2();
////
////    // Create empy input img, foreground and background image and foreground mask.
////    Mat frame, fgMask, fgMaskMOG2, clone;
////
////    // capture video from source 0, which is web camera, If you want capture video from file just replace //by  VideoCapture cap("videoFile.mov")
////    VideoCapture cap(0); //"Videos/vid.mkv"
////
////    bg_model->setDetectShadows(false);
////    bg_model->setNMixtures(3);
////    bg_model->setShadowValue(0);
////    bg_model->setHistory(0);
////
////    // main loop to grab sequence of input files
////    for(;;)
////    {
////
////        if (!cap.isOpened())
////        {
////            std::cout << "Video Capture Fail" << std::endl;
////        }
////        else
////        {
////            if (!cap.read(frame))
////            {
////                cout << "Invalid Frame" << std::endl;
////            }
////
////
////
////            // obtain input image from source
//////            cap.retrieve(img, CV_CAP_OPENNI_BGR_IMAGE);
//////
//////            // Just resize input image if you want
//////            resize(img, img, Size(640,480));
//////
//////            // create foreground mask of proper size
//////            if( foregroundMask.empty() ){
//////                foregroundMask.create(img.size(), img.type());
//////            }
//////
////            // compute foreground mask 8 bit image
////            // -1 is parameter that chose automatically your learning rate
////
////            bg_model->apply(frame, fgMask);
////
//////             smooth the mask to reduce noise in image
//////            GaussianBlur(fgMask, fgMask, Size(11, 11), 3.5, 3.5);
////
////            // threshold mask to saturate at black and white values
//////            threshold(fgMask, fgMask, 10, 10, THRESH_BINARY);
////
//////            create black foreground image
//////            fgMaskMOG2 = Scalar::all(255);
////
//////            Copy source image to foreground image only in area with white mask
////            frame.copyTo(fgMask, clone);
////
//////            Get background image
////            bg_model->getBackgroundImage(fgMaskMOG2);
////
//////             Show the results
////            imshow("Foreground mask", fgMask);
////
////            imshow("Foreground image", fgMaskMOG2);
////
////            imshow("Clone image", clone);
////
////            int key6 = waitKey(40);
////
//////            if(!backgroundImage .empty()){
//////
//////                imshow("mean background image", backgroundImage );
//////                int key5 = waitKey(40);
//////            }
////        }
////    }
////    return EXIT_SUCCESS;
////}
////
////
////
////
//////opencv
////#include "opencv2/imgcodecs.hpp"
////#include "opencv2/imgproc.hpp"
////#include "opencv2/videoio.hpp"
////#include <opencv2/highgui.hpp>
////#include <opencv2/video.hpp>
////
//////C
////#include <stdio.h>
////
//////C++
////#include <iostream>
////#include <sstream>
////using namespace cv;
////using namespace std;
////// Global variables
////Mat frame; //current frame
////Mat fgMaskMOG2; //fg mask fg mask generated by MOG2 method
////Ptr<BackgroundSubtractorMOG2> pMOG2; //MOG2 Background subtractor
////int keyboard; //input from keyboard
////void help();
////void processVideo();
////void processImages(char* firstFrameFilename);
////void help()
////{
////    cout
////    << "--------------------------------------------------------------------------" << endl
////    << "This program shows how to use background subtraction methods provided by "  << endl
////    << " OpenCV. You can process both videos (-vid) and images (-img)."             << endl
////    << endl
////    << "Usage:"                                                                     << endl
////    << "./bs {-vid <video filename>|-img <image filename>}"                         << endl
////    << "for example: ./bs -vid video.avi"                                           << endl
////    << "or: ./bs -img /data/images/1.png"                                           << endl
////    << "--------------------------------------------------------------------------" << endl
////    << endl;
////}
////
////int main(int argc, char* argv[])
////{
////    //print help information
////    //    help();
////    //    //check for the input parameter correctness
////    //    if(argc != 3) {
////    //        cerr <<"Incorret input list" << endl;
////    //        cerr <<"exiting..." << endl;
////    //        return EXIT_FAILURE;
////    //    }
////    //    //create GUI windows
////    namedWindow("Frame");
////    namedWindow("FG Mask MOG 2");
////
////    //    //create Background Subtractor objects
////    pMOG2 = createBackgroundSubtractorMOG2(); //MOG2 approach
////
////
//////    pMOG2->setDetectShadows(false);
//////    pMOG2->setNMixtures(3);
//////    pMOG2->setShadowValue(100);
//////    pMOG2->setHistory(0);
////
////
////    //    if(strcmp(argv[1], "-vid") == 0) {
////    //input data coming from a video
////    processVideo();
////    //    }
////    //    else if(strcmp(argv[1], "-img") == 0) {
////    //        //input data coming from a sequence of images
////    //        processImages(argv[2]);
////    //    }
////    //    else {
////    //        //error in reading input parameters
////    //        cerr <<"Please, check the input parameters." << endl;
////    //        cerr <<"Exiting..." << endl;
////    //        return EXIT_FAILURE;
////    //    }
////    //    //destroy GUI windows
////    //    destroyAllWindows();
////    //    return EXIT_SUCCESS;
////}
////
////void processVideo()
////{
////
////    //create the capture object
////    VideoCapture cap(0);
////
////    Mat clone;
////
////    if(!cap.isOpened())
////    {
////        //error in opening the video input
////        //        cerr << "Unable to open video file: " << videoFilename << endl;
////        exit(EXIT_FAILURE);
////    }
////    //read input data. ESC or 'q' for quitting
////    while( (char)keyboard != 'q' && (char)keyboard != 27 )
////    {
////
////        //read the current frame
////        if(!cap.read(frame))
////        {
////            cerr << "Unable to read next frame." << endl;
////            cerr << "Exiting..." << endl;
////            exit(EXIT_FAILURE);
////        }
////
////        //        clone = frame.clone();
////
////        clone = Scalar::all(255);
////
////        //update the background model
////        pMOG2->apply(frame, fgMaskMOG2, 0.0);
////
////        // smooth the mask to reduce noise in image
////        GaussianBlur(fgMaskMOG2, fgMaskMOG2, Size(11,11), 3.5,3.5);
////
////        // threshold mask to saturate at black and white values
////        threshold(fgMaskMOG2, fgMaskMOG2, 10, 255,THRESH_BINARY);
////
//////        frame.copyTo(clone, fgMaskMOG2);
////
////        //get the frame number and write it on the current frame
////        //        stringstream ss;
////        //        rectangle(frame, cv::Point(10, 2), cv::Point(100,20),
////        //                  cv::Scalar(255,255,255), -1);
////        //
////        //        ss << cap.get(CAP_PROP_POS_FRAMES);
////        //        string frameNumberString = ss.str();
////        //        putText(frame, frameNumberString.c_str(), cv::Point(15, 15),
////        //                FONT_HERSHEY_SIMPLEX, 0.5 , cv::Scalar(0,0,0));
////        //
////        //show the current frame and the fg masks
////        imshow("Frame", frame);
//////        imshow("Cloned Frame", clone);
////        imshow("FG Mask MOG 2", fgMaskMOG2);
////
////        //get the input from the keyboard
////        keyboard = waitKey( 30 );
////    }
////
////    //delete capture object
////    cap.release();
////}
////void processImages(char* fistFrameFilename) {
////    //read the first file of the sequence
////    frame = imread(fistFrameFilename);
////    if(frame.empty()){
////        //error in opening the first image
////        cerr << "Unable to open first image frame: " << fistFrameFilename << endl;
////        exit(EXIT_FAILURE);
////    }
////    //current image filename
////    string fn(fistFrameFilename);
////    //read input data. ESC or 'q' for quitting
////    while( (char)keyboard != 'q' && (char)keyboard != 27 ){
////        //update the background model
////        pMOG2->apply(frame, fgMaskMOG2);
////        //get the frame number and write it on the current frame
////        size_t index = fn.find_last_of("/");
////        if(index == string::npos) {
////            index = fn.find_last_of("\\");
////        }
////        size_t index2 = fn.find_last_of(".");
////        string prefix = fn.substr(0,index+1);
////        string suffix = fn.substr(index2);
////        string frameNumberString = fn.substr(index+1, index2-index-1);
////        istringstream iss(frameNumberString);
////        int frameNumber = 0;
////        iss >> frameNumber;
////        rectangle(frame, cv::Point(10, 2), cv::Point(100,20),
////                  cv::Scalar(255,255,255), -1);
////        putText(frame, frameNumberString.c_str(), cv::Point(15, 15),
////                FONT_HERSHEY_SIMPLEX, 0.5 , cv::Scalar(0,0,0));
////        //show the current frame and the fg masks
////        imshow("Frame", frame);
////        imshow("FG Mask MOG 2", fgMaskMOG2);
////        //get the input from the keyboard
////        keyboard = waitKey( 30 );
////        //search for the next image in the sequence
////        ostringstream oss;
////        oss << (frameNumber + 1);
////        string nextFrameNumberString = oss.str();
////        string nextFrameFilename = prefix + nextFrameNumberString + suffix;
////        //read the next frame
////        frame = imread(nextFrameFilename);
////        if(frame.empty()){
////            //error in opening the next image in the sequence
////            cerr << "Unable to open image frame: " << nextFrameFilename << endl;
////            exit(EXIT_FAILURE);
////        }
////        //update the path of the current frame
////        fn.assign(nextFrameFilename);
////    }
////}
////
////#include "opencv2/highgui.hpp"
////#include "opencv2/imgproc.hpp"
////
////#include <vector>
////#include <fstream>
////#include <iostream>
////#include <math.h>
////
////#include "opencv2/video/background_segm.hpp"
////#include "opencv2/highgui.hpp"
////#include "opencv2/imgproc.hpp"
////
////using namespace cv;
////using namespace std;
////
////int main(int argc, const char** argv)
////{
////    Mat src = imread("Images/bill.png");
////
////    imshow("Sourece", src);
////
////    Mat gray;
////
////    cvtColor(src, gray, CV_BGR2GRAY);
////
////    imshow("Gray Source", gray);
////
////    Mat threshhold;
////
////    threshold(src, threshhold, 50, 255,THRESH_BINARY);
////
////    imshow("Threshold", threshhold);
////
//////    int key6 = waitKey(40);
////
//////    Ptr<BackgroundSubtractorKNN> bg_model = createBackgroundSubtractorKNN();
////
////    // Init background substractor
////
//////    Ptr<BackgroundSubtractorMOG2> bg_model = createBackgroundSubtractorMOG2();
//////
//////    bg_model->setDetectShadows(false);
//////
//////    bg_model->setNMixtures(3);
//////
////////    bg_model->setComplexityReductionThreshold(0.5);
//////
//////    // Create empy input img, foreground and background image and foreground mask.
//////    Mat img, foregroundMask, backgroundImage, foregroundImg;
//////
//////    // capture video from source 0, which is web camera, If you want capture video from file just replace //by  VideoCapture cap("videoFile.mov")
//////    VideoCapture cap(0);
//////
//////    // main loop to grab sequence of input files
//////    for(;;)
//////    {
//////
//////        bool ok = cap.grab();
//////
//////        if (!ok)
//////        {
//////            std::cout << "Video Capture Fail" << std::endl ;
//////        }
//////        else
//////        {
//////
//////            // obtain input image from source
//////            cap.retrieve(img, CV_CAP_OPENNI_BGR_IMAGE);
//////
//////            // Just resize input image if you want
//////            resize(img,img,Size(640,480));
//////
//////            // create foreground mask of proper size
//////            if( foregroundMask.empty() )
//////            {
//////                foregroundMask.create(img.size(), img.type());
//////            }
//////
//////            // compute foreground mask 8 bit image
//////            // -1 is parameter that chose automatically your learning rate
//////
//////            bg_model->apply(img, foregroundMask, 0.0);
//////
//////            // create black foreground image
//////            foregroundImg = Scalar::all(255);
//////
//////            // smooth the mask to reduce noise in image
//////            GaussianBlur(foregroundMask, foregroundMask, Size(11,11), 3.5,3.5);
//////
//////            // threshold mask to saturate at black and white values
//////            threshold(foregroundMask, foregroundMask, 50, 255,THRESH_BINARY);
//////
//////            dilate(foregroundMask, foregroundMask, NULL);
//////            erode(foregroundMask, foregroundMask, NULL);
//////
//////            // Copy source image to foreground image only in area with white mask
//////            img.copyTo(foregroundImg, foregroundMask);
//////
//////            //Get background image
//////            bg_model->getBackgroundImage(backgroundImage);
//////
//////            // Show the results
//////            imshow("foreground mask", foregroundMask);
//////            imshow("foreground image", foregroundImg);
//////
//////            int key6 = waitKey(40);
//////
//////            if(!backgroundImage .empty()){
//////
//////                imshow("mean background image", backgroundImage );
//////                int key5 = waitKey(40);
//////
//////            }
//////        }
//////
//////    }
////
////    waitKey(0);
////    return 0;
////}
////
//
//
 

////
////#include "opencv2/imgproc.hpp"
////#include "opencv2/imgcodecs.hpp"
////#include "opencv2/highgui.hpp"
////
////using namespace cv;
////Mat src, src_gray;
////Mat dst, detected_edges;
////int edgeThresh = 1;
////int lowThreshold;
////int const max_lowThreshold = 100;
////int ratio = 3;
////int kernel_size = 3;
////const char* window_name = "Edge Map";
////static void CannyThreshold(int, void*)
////{
////    blur( src_gray, detected_edges, Size(3,3) );
////    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
////    dst = Scalar::all(255);
////    src.copyTo( dst, detected_edges);
////    imshow( window_name, dst );
////}
////
////int main( int, char** argv )
////{
////
////    VideoCapture cap(0);
////
////    while(cap.read(src))
////    {
//////        src = imread( "Images/bill.png", IMREAD_COLOR ); // Load an image
////        if( src.empty() )
////        { return -1; }
////        dst.create( src.size(), src.type() );
////        cvtColor( src, src_gray, COLOR_BGR2GRAY );
////
////        namedWindow( window_name, WINDOW_AUTOSIZE );
////
////        createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold );
////
////        CannyThreshold(0, 0);
////        int key6 = waitKey(0);
////    }
////
////    return 0;
////
////}
//
//
////convert jobs.png -fill none -fuzz 1% -draw "alpha 0,0 floodfill" -flop  -draw "alpha 0,0 floodfill" -flop me.png
//
