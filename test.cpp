
#include <opencv2/core.hpp>
#include <opencv2/core/ocl.hpp>
#include <iostream>

using std::cout;
using std::endl;

// http://answers.opencv.org/question/62635/opencv-30-how-to-determine-which-gpu-is-used-for-opencl/

int main() {
  if (!cv::ocl::haveOpenCL()) {
    cout << "OpenCL is not available..." << endl;
    //return;
  }
  
  cv::ocl::setUseOpenCL(true);

  cv::ocl::Context context;
  if (!context.create(cv::ocl::Device::TYPE_ALL)) {
    cout << "Failed creating the context..." << endl;
    //return;
  }

  cout << context.ndevices() << " GPU devices are detected." << endl; //This bit provides an overview of the OpenCL devices you have in your computer
  for (int i = 0; i < (int)context.ndevices(); i++) {
    cv::ocl::Device device = context.device(i);
    cout << "name:              " << device.name() << endl;
    cout << "available:         " << device.available() << endl;
    cout << "imageSupport:      " << device.imageSupport() << endl;
    cout << "OpenCL_C_Version:  " << device.OpenCL_C_Version() << endl;
    cout << endl;
  }

  cv::ocl::Device(context.device(0)); //Here is where you change which GPU to use (e.g. 0 or 1)
}

