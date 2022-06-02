﻿#include "opcvwrapper.h"

// https://docs.opencv.org/4.x/d5/d98/tutorial_mat_operations.html
bool loadImage(const std::string& image_path, Mat& img)
{
    img = imread(image_path, IMREAD_COLOR);
    if (img.empty())
    {
        return false;
    }
    return true;
}

// https://docs.opencv.org/4.x/d5/d98/tutorial_mat_operations.html
bool saveImage(const std::string& image_path, Mat& img)
{
    std::string f = image_path + ".jpg";
    return imwrite(f, img);
}

// https://docs.opencv.org/4.x/d5/d98/tutorial_mat_operations.html
void showImage(const Mat& img, const std::string& title)
{
    imshow(title, img);
}

// https://docs.opencv.org/4.x/d5/d98/tutorial_mat_operations.html
Mat convertRectoImg(Rect& r, Mat& img)
{
    Mat roi = Mat(img, r);
    return roi;
}

// https://docs.opencv.org/4.x/d5/d98/tutorial_mat_operations.html
Mat convertograyScale(const Mat& img)
{
    Mat grayscaleimage;
    //change the color image to grayscale image
    cvtColor(img, grayscaleimage, COLOR_BGR2GRAY);
    return grayscaleimage;
}

//https://docs.opencv.org/4.x/d4/d1b/tutorial_histogram_equalization.html
Mat equalizeGrayImage(const Mat& img)
{
    Mat hist_equalized_image;
    equalizeHist(img, hist_equalized_image);
    return hist_equalized_image;
}

//https://docs.opencv.org/4.x/d4/d1b/tutorial_histogram_equalization.html
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

//https://docs.opencv.org/4.x/d4/d1b/tutorial_histogram_equalization.html
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
std::vector<Rect> detectFacesInImage(Mat& img)
{
    if (img.type() != CV_8UC1)
    {   // not gray-level image
        convertograyScale(img);
    }

    std::vector<Rect> faces;
    CascadeClassifier cascade;
    cascade.load(CASCADE_PATH_FRONTAL);
    cascade.detectMultiScale(img, faces);
    return faces;

}

// https://docs.opencv.org/3.4/db/d28/tutorial_cascade_classifier.html
std::vector<Rect> detectEyesInImage(Mat& img)
{

    if (img.type() != CV_8UC1)
    {   // not gray-level image
        convertograyScale(img);
    }

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

// https://docs.opencv.org/4.x/d4/dbd/tutorial_filter_2d.html
Mat ApplyCustom2Dfilter(const Mat& img, Mat& kernel, int ddepth, Point& anchor, double delta)
{
    Mat final;

    //  src: Source image
    //  dst : Destination image
    //  ddepth : The depth of dst.A negative value(such as −1) indicates that the depth is the same as the source.
    //  kernel : The kernel to be scanned through the image
    //  anchor : The position of the anchor relative to its kernel.The location Point(-1, -1) indicates the center by default.
    //  delta : A value to be added to each pixel during the correlation.By default it is 0
    //  BORDER_DEFAULT : We let this value by default (more details in the following tutorial)

    filter2D(   img,            
                final, 
                ddepth, 
                kernel, 
                anchor, 
                delta, 
                BORDER_DEFAULT);
    return final;
}


void segmentationOfROI(Mat& img, Rect& roi,int r, int g, int b)
{

    for (int y = 0; y < img.rows; y++)
    {
        for (int x = 0; x < img.cols; x++)
        {
            Vec3b color = img.at<Vec3b>(Point(x, y));
            if (roi.contains(Point(x, y)) == true)
            {
                color[0] = r;
                color[1] = g;
                color[2] = b;
                //set pixel
                img.at<Vec3b>(Point(x,y)) = color;
            }
        }
    } 

}

// https://docs.opencv.org/4.x/df/d0d/tutorial_find_contours.html
int findcontours(   const Mat& img,
                    RoiAretype& contours,
                    std::vector<Vec4i>& hierarchy,
                    int thresh)
{

    Mat target_image;

    if (img.type() != CV_8UC1)
    {
        cvtColor(img, target_image, COLOR_BGR2GRAY);
    }
    else
        target_image = img;

    blur(target_image, target_image, Size(3, 3));
    Mat canny_output;
    Canny(target_image, canny_output, thresh, thresh*2);
    findContours(   canny_output,
                    contours,
                    hierarchy,
                    RETR_TREE,
                    CHAIN_APPROX_SIMPLE);

    return 0;
}

// https://docs.opencv.org/4.x/df/d0d/tutorial_find_contours.html
void drawCountour(RoiAretype& contours, Mat& img, std::vector<Vec4i>& hierarchy)
{
    RNG rng(12345);
    for (size_t i = 0; i < contours.size(); i++)
    {
        Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
        drawContours(img, contours, (int)i, color, 2, LINE_8, hierarchy, 0);
    }
}