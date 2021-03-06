// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <opencv2/ximgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/cudafeatures2d.hpp>
#include <opencv2/xfeatures2d/cuda.hpp>
#include <opencv2/cudacodec.hpp>
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <vector>
#include <string>

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;
using namespace cv::cuda;

int main()
{
	//VideoCapture cap_1("seq86_2.mp4");
	VideoCapture cap_2("seq86_1.mp4");

	const std::string fname = "seq86_2.mp4";

	cv::cuda::GpuMat d_frame;
	cv::Ptr<cv::cudacodec::VideoReader> cap_1 = cv::cudacodec::createVideoReader(fname);

	int i = 0;
	
	for (;;)
	{
		cv::cuda::printShortCudaDeviceInfo(cv::cuda::getDevice());
		
		if (!cap_1->nextFrame(d_frame))
			break;

		cv::Mat frame;
		d_frame.download(frame);
		cv::imshow("GPU", frame);

		i++;
		if ((char)cv::waitKey(33) >= 0) break;
	}
	cap_1.release();
	cap_2.release();
	destroyAllWindows();
	waitKey(1);
	return 0;
}
