#pragma once

#include "opencv2/objdetect.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include <vector>

#define CASCADE_PATH_FRONTAL_EXTENDED	"C:\\opencv2\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalcatface_extended.xml"
#define CASCADE_PATH_FRONTAL			"C:\\opencv2\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml"
#define CASCADE_PATH_FRONTAL_EYE		"C:\\opencv2\\opencv\\sources\\data\\haarcascades\\haarcascade_eye.xml"

using namespace cv;

bool loadImage(const std::string& image_path, Mat& img);
void showImage(const Mat& img, const std::string& title);
bool saveImage(const std::string& image_path, Mat& img);
Mat convertograyScale(const Mat& img);
Mat equalizeGrayImage(const Mat& img);
Mat equalizeColorImage(const Mat& img);
Mat blurImageSmooth(const Mat& img, int kernel_size);
Mat GaussianImageSmooth(const Mat& img, int kernel_size);
void doThresholdBinary(const Mat& img);
Mat laplacian(Mat& src);
std::vector<Rect> detectFacesInImage(Mat& img, bool skip);
std::vector<Rect> detectEyesInImage(Mat& img, bool skip);
Mat convertRectoImg(Rect& r, Mat& img);
void drawCirclesAtImgFromRoi(Mat& img, Rect& roi);
void drawSquaresAtImgFromRoi(Mat& img, Rect& roi);
std::vector<Mat> splitChannel(Mat& img);
