#include "opencv2/opencv.hpp"
#include "opencv2/cudaarithm.hpp"
#include "opencv2/cudafilters.hpp"
#include "benchmark/benchmark.h"

#include "threshold.h"

// static void BM_Threshold_GPU(benchmark::State& state) {
//   cv::Mat src_host =
//       cv::imread("../2016_RealFullField/0.jpg", CV_LOAD_IMAGE_GRAYSCALE);
//   cv::cuda::GpuMat src, blur, thresh;
//   cv::Ptr<cv::cuda::Filter> gaussian = cv::cuda::createGaussianFilter(
//       src_host.type(), src_host.type(), cv::Size(15, 15), 3);
//   while (state.KeepRunning()) {
//     src.upload(src_host);
//     gaussian->apply(src, blur);
//     cv::cuda::threshold(blur, thresh, 90.0, 255.0, CV_THRESH_BINARY);
//
//     cv::Mat result_host;
//     thresh.download(result_host);
//   }
//   state.SetBytesProcessed(int64_t(state.iterations()) *
//                           int64_t(src_host.total()) *
//                           int64_t(src_host.elemSize()));
// }
//
// BENCHMARK(BM_Threshold_GPU)->UseRealTime();

static void BM_Threshold_CPU(benchmark::State& state) {
  cv::Mat src, dst;
  src = cv::imread("../2016_RealFullField/0.jpg", cv::IMREAD_GRAYSCALE);
  while (state.KeepRunning()) {
    threshold_cpu(src, dst);
  }
  state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(src.total()) *
                          int64_t(src.elemSize()));
}

BENCHMARK(BM_Threshold_CPU);
BENCHMARK(BM_Threshold_CPU)->UseRealTime();

BENCHMARK_MAIN();
