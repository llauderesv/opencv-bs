//
//  main_2.hpp
//  OpenCV
//
//  Created by Vincent Llauderes on 2/6/18.
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

int main();

//** MAIN FUNCTIONS **//

int handleInputs();

// Run background subtraction on a video
int videoBGSub();

// Run background subtraction on webcam stream
int webcamBGSub();
int webcamBGSub(int webcam_ID, float window_scale, bool save_frames, unsigned int saved_frame_interval, bool background_train_on_initalize, int background_train_time);

int webcamStereo(unsigned int camera_ID_left, unsigned int camera_ID_right);


//** SUB FUNCTIONS **//

// Timestamp an image
void timestamp(cv::Mat inframe, cv::OutputArray outframe);

// Print a message on a image
void drawMessage(cv::Mat inframe, cv::OutputArray outframe, char message[]);
