#ifndef THRESH_CUDA_THRESH_
#define THRESH_CUDA_THRESH_

#include "opencv2/opencv.hpp"

void threshold_cpu(const cv::Mat& src, cv::Mat& dst);

void threshold_gpu(const cv::Mat& src, cv::Mat& dst);

#endif /* end of include guard: THRESH_CUDA_THRESH_ */
