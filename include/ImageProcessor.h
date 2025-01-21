#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <opencv2/opencv.hpp>
#include <vector>
#include <map>
#include <string>
#include <memory>  // for std::unique_ptr

// Forward declaration of the implementation class
class ImageProcessorImpl;

class ImageProcessor {
public:
    ImageProcessor();           // Constructor
    ~ImageProcessor();          // Destructor

    // Public method to process an image based on a list of operations and parameters
    cv::Mat processImage(const cv::Mat& inputImage,
                         const std::vector<std::string>& operations,
                         const std::vector<std::map<std::string, double>>& params);

    // Public methods for individual operations (with different names)
    cv::Mat applyCustomGaussianBlur(const cv::Mat& inputImage, int kernelSize);
    cv::Mat enhanceImageWithCLAHE(const cv::Mat& inputImage, double clipLimit, int tileWidth, int tileHeight);
    cv::Mat modifyBrightnessAndContrast(const cv::Mat& inputImage, double alpha, double beta);
    cv::Mat adjustGamma(const cv::Mat& inputImage, double gamma);

private:
    // Pointer to the implementation class (pimpl idiom)
    std::unique_ptr<ImageProcessorImpl> pimpl;
};

#endif // IMAGEPROCESSOR_H

