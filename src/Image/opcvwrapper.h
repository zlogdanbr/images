#pragma once

// Adaptated from
// https://www.opencv-srf.com/2018/02/h
// https://docs.opencv.org/3.4/dc/dd3/tutorial_gausian_median_blur_bilateral_filter.html
// https://docs.opencv.org/3.4/d5/db5/tutorial_laplace_operator.html
// https://stackoverflow.com/questions/33994930/how-to-convert-the-selected-rectangle-from-the-image-into-grayscale


#include "opencv2/objdetect.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include <vector>

using namespace cv;

bool loadImage(const std::string& image_path, Mat& img);
void showImage(const Mat& img, const std::string& title);
Mat convertograyScale(const Mat& img);
Mat equalizeGrayImage(const Mat& img);
Mat equalizeColorImage(const Mat& img);
Mat blurImageSmooth(const Mat& img, int kernel_size);
Mat GaussianImageSmooth(const Mat& img, int kernel_size);
void doThresholdBinary(const Mat& img);
Mat laplacian(Mat& src);
std::vector<Rect> detectFacesInImage(Mat& img, CascadeClassifier& cascade);