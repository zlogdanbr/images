#include "opcvwrapper.h"

bool loadImage(const std::string& image_path, Mat& img)
{
    img = imread(image_path, IMREAD_COLOR);
    if (img.empty())
    {
        return false;
    }
    return true;
}

bool saveImage(const std::string& image_path, Mat& img)
{
    std::string f = image_path + ".jpg";
    return imwrite(f, img);
}

void showImage(const Mat& img, const std::string& title)
{
    imshow(title, img);
}

Mat convertRectoImg(Rect& r, Mat& img)
{
    Mat roi = Mat(img, r);
    return roi;
}

// https://www.opencv-srf.com/2018/02/h
Mat convertograyScale(const Mat& img)
{
    Mat grayscaleimage;
    //change the color image to grayscale image
    cvtColor(img, grayscaleimage, COLOR_BGR2GRAY);
    return grayscaleimage;
}

// https://www.opencv-srf.com/2018/02/h
Mat equalizeGrayImage(const Mat& img)
{
    Mat hist_equalized_image;
    equalizeHist(img, hist_equalized_image);
    return hist_equalized_image;
}

// https://www.opencv-srf.com/2018/02/h
Mat equalizeColorImage(const Mat& img)
{
    Mat hist_equalized_image;
    cvtColor(img, hist_equalized_image, COLOR_BGR2YCrCb);
    std::vector<Mat> vec_channels;
    split(hist_equalized_image, vec_channels);

    //Equalize the histogram of only the Y channel 
    equalizeHist(vec_channels[0], vec_channels[0]);

    //Merge 3 channels in the vector to form the color image in YCrCB color space.
    merge(vec_channels, hist_equalized_image);

    //Convert the histogram equalized image from YCrCb to BGR color space again
    cvtColor(hist_equalized_image, hist_equalized_image, COLOR_YCrCb2BGR);
    return hist_equalized_image;
}

std::vector<Mat> splitChannel(Mat& img)
{
    Mat colorrgb;
    cvtColor(img, colorrgb, COLOR_BGR2YCrCb);
    std::vector<Mat> vec_channels;
    split(colorrgb, vec_channels);
    return vec_channels;
}

// https://docs.opencv.org/3.4/dc/dd3/tutorial_gausian_median_blur_bilateral_filter.html
Mat blurImageSmooth(const Mat& img, int kernel_size)
{
    Mat Blurred;
    blur(img, Blurred, Size(kernel_size, kernel_size));
    return Blurred;
}

// https://docs.opencv.org/3.4/dc/dd3/tutorial_gausian_median_blur_bilateral_filter.html
Mat GaussianImageSmooth(const Mat& img, int kernel_size)
{
    Mat Blurred;
    GaussianBlur(img, Blurred, Size(kernel_size, kernel_size), 0);
    return Blurred;
}

// https://www.opencv-srf.com/2018/02/h
void doThresholdBinary(const Mat& img)
{
    threshold(img, img, 128, 255, 1);
}

// https://docs.opencv.org/3.4/d5/db5/tutorial_laplace_operator.html
Mat laplacian(Mat& src)
{
    // Declare the variables we are going to use
    Mat src_gray, dst;
    int kernel_size = 3;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;

    // Reduce noise by blurring with a Gaussian filter ( kernel size = 3 )
    GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
    src_gray = convertograyScale(src);
    Mat abs_dst;
    Laplacian(  src_gray, 
                dst, 
                ddepth, 
                kernel_size, 
                scale, 
                delta, 
                BORDER_DEFAULT);

    // converting back to CV_8U
    convertScaleAbs(dst, abs_dst);
    return abs_dst;
}

// https://docs.opencv.org/3.4/db/d28/tutorial_cascade_classifier.html
std::vector<Rect> detectFacesInImage(Mat& img, bool skip)
{
    if (skip == false )
        Mat gray = convertograyScale(img);
    std::vector<Rect> faces;
    CascadeClassifier cascade;
    cascade.load(CASCADE_PATH_FRONTAL);
    cascade.detectMultiScale(img, faces);
    return faces;

}

// https://docs.opencv.org/3.4/db/d28/tutorial_cascade_classifier.html
std::vector<Rect> detectEyesInImage(Mat& img, bool skip)
{

    Mat gray;

    if (skip == false )
        gray = convertograyScale(img);
    std::vector<Rect> eyes;
    CascadeClassifier cascade;
    cascade.load(CASCADE_PATH_FRONTAL_EYE);
    cascade.detectMultiScale(img, eyes);
    return eyes;

}

// https://docs.opencv.org/3.4/db/d28/tutorial_cascade_classifier.html
void drawCirclesAtImgFromRoi(Mat& img,Rect& roi)
{
    Point Mycenter(     roi.x + roi.width/2, 
                        roi.y + roi.height/2 );

    int radius = cvRound( (roi.width + roi.height)*0.25 );
    circle( img, Mycenter, radius, Scalar( 255, 0, 0 ), 4 );

}

// https://docs.opencv.org/3.4/db/d28/tutorial_cascade_classifier.html
void drawSquaresAtImgFromRoi(Mat& img, Rect& roi)
{    
    Scalar color = Scalar(255, 0, 0);
    rectangle(img,
        Point(cvRound(roi.x * 1),
            cvRound(roi.y * 1)),
        Point(cvRound((roi.x + roi.width - 1) * 1),
            cvRound((roi.y + roi.height - 1) * 1)),
        color,
        3,
        8,
        0);

}