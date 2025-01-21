#include <opencv2/opencv.hpp>
#include <iostream>
#include "ImageProcessor.h"

int main() {
    // Load an image from the 'test' directory
    cv::Mat inputImage = cv::imread("test/your-input-image.jpg");

    // Check if the image is loaded successfully
    if (inputImage.empty()) {
        std::cerr << "Error: Could not load image!" << std::endl;
        return -1;
    }

    // Initialize ImageProcessor
    ImageProcessor processor;

    // Use a reasonable window size for Gaussian Blur (e.g., 15x15 kernel)
    int kernelSize = 15;

    // Apply Gaussian Blur with the appropriate window size
    cv::Mat blurredImage = processor.applyCustomGaussianBlur(inputImage, kernelSize);

    // Resize the blurred image to fit into a more manageable window size
    int displayWidth = 800;  // Set the display width for the window
    int displayHeight = static_cast<int>((displayWidth * inputImage.rows) / inputImage.cols);  // Maintain aspect ratio

    // Resize the image for display
    cv::Mat resizedImage;
    cv::resize(blurredImage, resizedImage, cv::Size(displayWidth, displayHeight));

    // Show the resized image
    cv::imshow("Blurred Image", resizedImage);
    cv::waitKey(0);  // Wait for a key press

    // Ask the user if they want to save the output image
    char userChoice;
    std::cout << "Do you want to save the processed image? (y/n): ";
    std::cin >> userChoice;

    if (userChoice == 'y' || userChoice == 'Y') {
        // Ask the user for a file path to save the image
        std::string savePath;
        std::cout << "Enter the path (including filename and extension, e.g., output.jpg): ";
        std::cin >> savePath;

        // Save the image
        bool saveSuccess = cv::imwrite(savePath, blurredImage);

        if (saveSuccess) {
            std::cout << "Image saved successfully!" << std::endl;
        } else {
            std::cerr << "Error: Could not save the image!" << std::endl;
        }
    }

    return 0;
}

