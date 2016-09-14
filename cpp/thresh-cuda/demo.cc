#include "opencv2/opencv.hpp"

#include "threshold.h"

int main() {
  cv::Mat src, dst;
  src = cv::imread("../2016_RealFullField/0.jpg", cv::IMREAD_GRAYSCALE);
  threshold_cpu(src, dst);
  cv::imshow("CPU Demo", dst);
  cv::waitKey();
  threshold_gpu(src, dst);
  cv::imshow("GPU Demo", dst);
  cv::waitKey();
}
