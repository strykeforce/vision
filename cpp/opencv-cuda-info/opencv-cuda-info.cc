#include "opencv2/core/cuda.hpp"
#include <iostream>
#include <iomanip>

const int WIDTH = 45;

int main() {
  std::cout << std::setw(WIDTH) << "getCudaEnabledDeviceCount: "
            << cv::cuda::getCudaEnabledDeviceCount() << std::endl;
  std::cout << std::setw(WIDTH) << "getDevice: " << cv::cuda::getDevice()
            << std::endl;

  cv::cuda::DeviceInfo::DeviceInfo info = cv::cuda::DeviceInfo::DeviceInfo();
  std::cout << std::setw(WIDTH) << "DeviceInfo.name: " << info.name()
            << std::endl;
  std::cout << std::setw(WIDTH)
            << "DeviceInfo.majorVersion: " << info.majorVersion() << std::endl;
  std::cout << std::setw(WIDTH)
            << "DeviceInfo.minorVersion: " << info.minorVersion() << std::endl;
  std::cout << std::setw(WIDTH)
            << "DeviceInfo.freeMemory: " << info.freeMemory() << std::endl;
  std::cout << std::setw(WIDTH)
            << "DeviceInfo.totalMemory: " << info.totalMemory() << std::endl;
  std::cout << std::setw(WIDTH)
            << "DeviceInfo.isCompatible(): " << std::boolalpha
            << info.isCompatible() << std::endl;

  std::cout << std::setw(WIDTH)
            << "DeviceInfo.supports(FEATURE_SET_COMPUTE_10): " << std::boolalpha
            << info.supports(cv::cuda::FEATURE_SET_COMPUTE_10) << std::endl;
  std::cout << std::setw(WIDTH)
            << "DeviceInfo.supports(FEATURE_SET_COMPUTE_11): " << std::boolalpha
            << info.supports(cv::cuda::FEATURE_SET_COMPUTE_11) << std::endl;
  std::cout << std::setw(WIDTH)
            << "DeviceInfo.supports(FEATURE_SET_COMPUTE_12): " << std::boolalpha
            << info.supports(cv::cuda::FEATURE_SET_COMPUTE_12) << std::endl;
  std::cout << std::setw(WIDTH)
            << "DeviceInfo.supports(FEATURE_SET_COMPUTE_13): " << std::boolalpha
            << info.supports(cv::cuda::FEATURE_SET_COMPUTE_13) << std::endl;
  std::cout << std::setw(WIDTH)
            << "DeviceInfo.supports(FEATURE_SET_COMPUTE_20): " << std::boolalpha
            << info.supports(cv::cuda::FEATURE_SET_COMPUTE_20) << std::endl;
  std::cout << std::setw(WIDTH)
            << "DeviceInfo.supports(FEATURE_SET_COMPUTE_21): " << std::boolalpha
            << info.supports(cv::cuda::FEATURE_SET_COMPUTE_21) << std::endl;
  std::cout << std::setw(WIDTH)
            << "DeviceInfo.supports(GLOBAL_ATOMICS): " << std::boolalpha
            << info.supports(cv::cuda::GLOBAL_ATOMICS) << std::endl;
  std::cout << std::setw(WIDTH)
            << "DeviceInfo.supports(SHARED_ATOMICS): " << std::boolalpha
            << info.supports(cv::cuda::SHARED_ATOMICS) << std::endl;
  std::cout << std::setw(WIDTH)
            << "DeviceInfo.supports(NATIVE_DOUBLE): " << std::boolalpha
            << info.supports(cv::cuda::NATIVE_DOUBLE) << std::endl;
}
