#include "threshold.h"

#include "opencv2/opencv.hpp"
#include "opencv2/cudaarithm.hpp"
#include "opencv2/cudafilters.hpp"

void threshold_cpu(const cv::Mat& src, cv::Mat& dst) {
  cv::Mat b;
  cv::GaussianBlur(src, b, cv::Size(15, 15), 3);
  cv::threshold(b, dst, 90.0, 255.0, CV_THRESH_BINARY);
}

void threshold_gpu(const cv::Mat& src, cv::Mat& dst) {
  cv::cuda::GpuMat gpuSrc, gpuBlur, gpuThresh;
  cv::Ptr<cv::cuda::Filter> gaussian = cv::cuda::createGaussianFilter(
      src.type(), src.type(), cv::Size(15, 15), 3);
  gpuSrc.upload(src);
  gaussian->apply(gpuSrc, gpuBlur);
  cv::cuda::threshold(gpuBlur, gpuThresh, 90.0, 255.0, CV_THRESH_BINARY);

  gpuThresh.download(dst);
}
