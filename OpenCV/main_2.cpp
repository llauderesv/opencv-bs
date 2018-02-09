////
////  main_2.cpp
////  OpenCV
////
////  Created by Vincent Llauderes on 2/6/18.
////  Copyright © 2018 Vince Llauderes. All rights reserved.
////
//
//#include "main_2.hpp"
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//    int exitCode;
//
//    std::cout << "Choose program:\n1 - webcam stream\n2 - video background subtraction\n3 - webcam stereo disparity\n0 - exit" << std::endl;
//
//    exitCode = handleInputs();
//
//    return exitCode;
//}
//
////** MAIN FUNCTIONS **//
//
//int handleInputs()
//{
//    char keychoice;
//    int exitCode = -1;
//
//    // Get valid inputs
//    std::cin >> keychoice;
//
//    // Test inputs
//    switch (keychoice)
//    {
//        case '0':
//            exitCode = 0;
//            break;
//        case '1':
//            exitCode = webcamBGSub();
//            break;
//        case '2':
//            exitCode = videoBGSub();
//            break;
//        case '3':
////            exitCode = webcamStereo(0,2);
//            break;
//        default:
//            std::cout << "Invalid input, try again" << std::endl;
//            exitCode = handleInputs();
//            break;
//    }
//
//    return exitCode;
//}
//
//int videoBGSub()
//{
//    cv::VideoCapture video;
//    cv::Ptr<cv::BackgroundSubtractorMOG2> bsMOG2;
//    double videoScale = 0.5;
//
//    // Load video
//    video.open("Dashcam.avi");
//
//    // Check if it opened properly
//    if (!video.isOpened())
//        return -1;
//
//    // Init background subtraction object
//    bsMOG2 = cv::createBackgroundSubtractorMOG2(500, 16.0, false);
//
//    // Loop until exit
//    for (;;)
//    {
//        cv::Mat frame, fgMask, fgFrame, structElement;
//
//        // Ensure there's a video frame to read then copy it into the frame mat, break otherwise
//        if (!video.read(frame))
//            break;
//
//        // Resize frame if needed
//        if (videoScale != 1.0);
//            cv::resize(frame, frame, cv::Size(), videoScale, videoScale, cv::INTER_CUBIC);
//
//        // Run background subtraction
//        bsMOG2->apply(frame, fgMask);
//
//        // Run mophology filter on the mask
//        structElement = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(2, 2));
//        cv::morphologyEx(fgMask, fgMask, cv::MORPH_OPEN, structElement);
//        cv::morphologyEx(fgMask, fgMask, cv::MORPH_CLOSE, structElement);
//
//        // Generate our masked foreground
//        frame.copyTo(fgFrame, fgMask);
//
//        // Draw outputs
//        cv::imshow("Video", frame);
//        cv::imshow("Mask", fgMask);
//        cv::imshow("Foreground", fgFrame);
//
//        // Break on keyboard input
//        if (cv::waitKey(30) >= 0)
//            break;
//    }
//
//    return 0;
//}
//
//int webcamBGSub()
//{
//    return webcamBGSub(0, 1.f, false, 30, false, 80);
//}
//
//int webcamBGSub(int webcamID, float windowscale, bool saveFrames, unsigned int savedFrameInterval, bool backgroundTrainOnInit, int backgroundTrainTime)
//{
//    // Time stuff
//    std::time_t epochtime;
//    std::tm timestruct;
//
//    // frame stuff
//    cv::VideoCapture captureStream;
//    cv::Mat frame;
//    bool savedFrame = false;
//
//    // background subtraction
//    cv::Ptr<cv::BackgroundSubtractorMOG2> bsMOG2;
//    cv::Mat fgMask;
//    int bgsubTrainTime;
//    bool bgsubEnabled = false;
//    bool bgFiltered = true;
//    int filterSize = 2;
//
//    // Start the camera stream if valid
//    captureStream.open(webcamID);
//    if (!captureStream.isOpened())
//    {
//        std::cout << "Failed to get webcam." << std::endl;
//        return -1;
//    }
//
//    // Loop until we hit ESC
//    while (true)
//    {
//        epochtime = std::time(nullptr);
//
//        // Convert to local time
////        localtime_s(&timestruct, &epochtime);
//
//        // Get the camera frame
//        captureStream >> frame;
//
//        // Ensure the frame is valid
//        if (frame.empty())
//            return -1;
//
//        // If foreground detection is enabled perform the operations
//        if (bgsubEnabled)
//        {
//            cv::Mat fgImage;
//            cv::Mat bgImage = cv::imread("./bgimage.jpg", 1);
//
//            // Perform the MOG2 function depending on training options
//            if (!backgroundTrainOnInit)
//            {
//                // Training is disabled, run the function with default settings
//                bsMOG2->apply(frame, fgMask);
//            }
//            else if (bgsubTrainTime > 0)
//            {
//                // Training is enabled but not yet run, train for the n amount of time
//                bsMOG2->apply(frame, fgMask, 0.5);
//                bgsubTrainTime--;
//            }
//            else
//            {
//                // Training is enabled and done, run the function using only the generated bg data
//                bsMOG2->apply(frame, fgMask, 0);
//            }
//
//            // Filter if enabled
//            if (bgFiltered)
//            {
//                cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(filterSize, filterSize));
//                cv::morphologyEx(fgMask, fgMask, cv::MORPH_OPEN, element);
//                cv::morphologyEx(fgMask, fgMask, cv::MORPH_CLOSE, element);
//            }
//
//            // Mask our input image (onto a nice beach image!)
//            bgImage.copyTo(fgImage);
//            frame.copyTo(fgImage, fgMask);
//
//            if (backgroundTrainOnInit && bgsubTrainTime > 0)
//                drawMessage(fgMask, fgMask, "TRAINING");
//
//            // Draw windows
//            cv::imshow("Foreground mask", fgMask);
//            cv::imshow("Foreground image", fgImage);
//        }
//
//        // Timestamp the image
//        timestamp(frame, frame);
//
//        // Save a frame every 30 seconds
//        if (saveFrames && (timestruct.tm_sec % savedFrameInterval) == 0)
//        {
//            if (!savedFrame)
//            {
//                // Generate the filename
//                std::string filename = "FRAME_" + std::to_string(timestruct.tm_mon + 1) + "_" + std::to_string(timestruct.tm_mday) + "_" + std::to_string(timestruct.tm_hour) + "." + std::to_string(timestruct.tm_min) + "." + std::to_string(timestruct.tm_sec) + ".jpg";
//
//                // Save the frame
//                cv::imwrite(filename, frame);
//
//                savedFrame = true;
//            }
//        }
//        else
//            savedFrame = false;
//
//        // Upscale the image
//        cv::Mat resizedFrame;
//        cv::resize(frame, resizedFrame, resizedFrame.size(), windowscale, windowscale, cv::INTER_CUBIC);
//
//        // Draw the window
//        cv::imshow("OpenCV Webcam", resizedFrame);
//
//        // Input handling
//        switch (cv::waitKey(10))
//        {
//            case '+':
//                filterSize++;
//                break;
//            case '-':
//                if (filterSize > 1)
//                    filterSize--;
//                break;
//            case 'f':   // Toggle filtering of foreground mask
//                bgFiltered = !bgFiltered;
//                break;
//            case 'h':   // bg subtraction initalize and enable
//                bsMOG2 = cv::createBackgroundSubtractorMOG2(500, 16.0, false);
//                if (backgroundTrainOnInit)
//                    bgsubTrainTime = backgroundTrainTime;
//                bgsubEnabled = true;
//                break;
//            case 27:    // Esc exit
//                return 0;
//                break;
//            default:
//                break;
//        }
//    }
//
//    return 0;
//}
////
////int webcamStereo(unsigned int camID_Left, unsigned int camID_Right)
////{
////    unsigned const int camIDs[2] = { camID_Left, camID_Right };
////    cv::VideoCapture camStream[2];
//////    cv::Ptr<cv::StereoBM> stereoGen = cv::StereoBM::create(0, 21);
////
////    // Start the camera streams and ensure they're valid
////    for (int i = 0; i < 2; i++)
////    {
////
////        camStream[i].open(camIDs[i]);
////        if (!camStream[i].isOpened())
////        {
////            int error = -301 - i;
////
////            std::cout << "Failed to get webcam #" << camIDs[i] << "." << std::endl;
////
////            return error;
////        }
////    }
////
////    // Run the loop logic
////    for (;;)
////    {
////        cv::Mat frames[2], procFrames[2], depthM, depthDisp;
////
////        // Load the frames and ensure they're valid
////        for (int i = 0; i < 2; i++)
////        {
////            camStream[i] >> frames[i];
////
////            if (frames[i].empty())
////                return -341 - i;
////
////            // Generate the greyscale images
////            cv::cvtColor(frames[i], procFrames[i], CV_BGR2GRAY);
////        }
////
////        // Run stereo disparity
////        depthM = cv::Mat(frames[0].rows, frames[1].cols, CV_16S);
////        depthDisp = cv::Mat(frames[0].rows, frames[1].cols, CV_8U);
//////        stereoGen->compute(procFrames[0], procFrames[1], depthM);
////
////        // Convert output mask image
////        double depthMin, depthMax;
////        cv::minMaxLoc(depthM, &depthMin, &depthMax);
////        cv::normalize(depthM, depthDisp, 0, 255, CV_MINMAX, CV_8U);
////
////        // Draw output windows
////        cv::imshow("Camera 0", frames[0]);
////        cv::imshow("Camera 1", frames[1]);
////        cv::imshow("Depth map", depthDisp);
////
////        // Break on keyboard input
////        if (cv::waitKey(30) >= 0)
////            break;
////    }
////}
//
//
////** SUB FUNCITONS **//
//
//void timestamp(cv::Mat inframe, cv::OutputArray outframe)
//{
////    std::time_t epochtime;
////    char timestr[26];
////    std::tm timestruct;
////
////    // Get the time and update the timestr
////    epochtime = std::time(nullptr);
////    localtime_s(&timestruct, &epochtime);
////    asctime_s(timestr, sizeof timestr, &timestruct);
////    timestr[24] = '\0'; // Clear the last character, else opencv's putText draws it as an unknown
////
////    // Draw the timestamp
////    cv::rectangle(inframe, cvPoint(0, inframe.size().height), cvPoint((sizeof(timestr) - 1) * 8 + 1, inframe.size().height - 13), cvScalar(0, 0, 0), CV_FILLED, 8, 0);
////    cv::putText(inframe, timestr, cvPoint(0, inframe.size().height - 2.0), CV_FONT_HERSHEY_PLAIN, 0.9, cvScalar(255, 255, 255), 1, 8, false);
////
////    // Update outframe with the final image
////    inframe.copyTo(outframe);
//}
//
//void drawMessage(cv::Mat inframe, cv::OutputArray outframe, char message[])
//{
//    // Draw the message
//    cv::rectangle(inframe, cvPoint(0, inframe.size().height), cvPoint((sizeof(message) - 1) * 8 + 1, inframe.size().height - 13), cvScalar(0, 0, 0), CV_FILLED, 8, 0);
//    cv::putText(inframe, message, cvPoint(0, inframe.size().height - 2.0), CV_FONT_HERSHEY_PLAIN, 0.9, cvScalar(255, 255, 255), 1, 8, false);
//
//    // Update outframe with the final image
//    inframe.copyTo(outframe);
//}

