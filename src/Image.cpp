#include "opcvwrapper.h"
#include <iostream>



void FindAndDrawCircles(const std::string& image_path)
{
    Mat img;
    int scale = 1;

    if (loadImage(image_path, img) == false)
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return;
    }
    std::vector<Rect> faces = detectFacesInImage(img,false);

    for (auto& roi : faces)
    {
        drawCirclesAtImgFromRoi(img, roi);
    }
    showImage(img, "Final");
}

void FindAndDrawRectangles(const std::string& image_path)
{
    Mat img;
    int scale = 1;

    if (loadImage(image_path, img) == false)
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return;
    }
    std::vector<Rect> faces = detectFacesInImage(img,false);

    for (auto& roi : faces)
    {
        drawSquaresAtImgFromRoi(img, roi);
    }
    showImage(img, "Final");
}

void FindAndDFacesAndEyes(const std::string& image_path)
{
    Mat img;
    int scale = 1;

    if (loadImage(image_path, img) == false)
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return;
    }
    std::vector<Rect> faces = detectFacesInImage(img, false);

    for (auto& roi : faces)
    {
        drawCirclesAtImgFromRoi(img, roi);
        Mat faceROI = convertRectoImg(roi, img);
        std::vector<Rect> eyes = detectEyesInImage(faceROI,false);
        for (auto& roieye : eyes)
        {
            drawCirclesAtImgFromRoi(faceROI, roieye);
        }
    }


    showImage(img, "Final");
}

void FindAndDFacesAndEyes(Mat& img)
{
    int scale = 1;

    std::vector<Rect> faces = detectFacesInImage(img, true);

    for (auto& roi : faces)
    {
        drawCirclesAtImgFromRoi(img, roi);
        Mat faceROI = convertRectoImg(roi, img);
        std::vector<Rect> eyes = detectEyesInImage(faceROI,true);
        for (auto& roieye : eyes)
        {
            drawCirclesAtImgFromRoi(faceROI, roieye);
        }
    }


    showImage(img, "Final");
}

/**
* ImageAdjustmentsTesting
* it tests adjusments in a photo specified by the path image_path
*/
void ImageAdjustmentsTesting(const std::string& image_path)
{
    Mat img;

    if (loadImage(image_path, img) == false)
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return;
    }

    Mat img2 = convertograyScale(img);
    showImage(img, "Original Image");
    if (img2.empty() == false)
    {
        showImage(img2, "Gray Scale");
        Mat img3 = equalizeGrayImage(img2);

        if (img3.empty() == false)
        {
            showImage(img3, "Gray Scale Histogram Adjusted");
        }

        Mat img4 = equalizeColorImage(img);
        if (img4.empty() == false)
        {
            showImage(img4, "Color Image Histogram Adjusted");
        }
    }

    Mat img5 = blurImageSmooth(img, 3);
    if (img5.empty() == false)
    {
        showImage(img5, "Image blurrer 3x3 Kernel");
    }

    Mat img6 = blurImageSmooth(img, 5);
    if (img6.empty() == false)
    {
        showImage(img6, "Image blurrer 5x5 Kernel");
    }

    Mat img7 = GaussianImageSmooth(img, 5);
    if (img7.empty() == false)
    {
        showImage(img7, "Gaussian 5x5 Kernel");
    }
}

/**
* detecting
* Finds edges in a poto specified by the path image_path using the laplacian
* algorithm.
*/
Mat FindEdgesOnPhoto(const std::string& image_path)
{
    Mat img; 

    if (loadImage(image_path, img) == false)
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return img;
    }

    //showImage(img, "Original" );
    //showImage(imglp, "Laplacian");

    auto Imfinal = convertograyScale(img) - laplacian(img);
    showImage(Imfinal, "Final");
    return Imfinal;
}

int main()
{
    //std::string image_path = samples::findFile("eu.jpg");
    std::string image_path = "C:\\code\\image\\Image\\Image\\x64\\Debug\\eu.jpg";
    FindAndDFacesAndEyes(image_path);
    waitKey(0); // Wait for a keystroke in the window
    destroyAllWindows();
    return 0;
}