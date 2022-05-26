#include "opcvwrapper.h"
#include <iostream>



void Facefindinphoto(const std::string& image_path)
{
    Mat img;
    int scale = 1;

    if (loadImage(image_path, img) == false)
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return;
    }
    CascadeClassifier cascade;
    cascade.load("C:\\code\\image\\Image\\Image\\x64\\Debug\\haarcascade_frontalface_default.xml");// haarcascade_frontalface_default.xml

    
    std::vector<Rect> faces = detectFacesInImage(img, cascade );

    for (size_t i = 0; i < faces.size(); i++)
    {
        Rect r = faces[i];
        Scalar color = Scalar(255, 0, 0);
        rectangle(img,
            cv::Point(cvRound(r.x * scale),
                cvRound(r.y * scale)),
            Point(cvRound((r.x + r.width - 1) * scale),
                cvRound((r.y + r.height - 1) * scale)),
            color,
            3,
            8,
            0);

    }
    showImage(img, "Faces");
}

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

void detecting(const std::string& image_path)
{
    Mat img;

    if (loadImage(image_path, img) == false)
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return;
    }

    Mat imglp = laplacian(img);

    showImage(img, "Original" );
    showImage(imglp, "Laplacian");

    auto Imfinal = convertograyScale(img) - imglp;
    showImage(Imfinal, "Final");
}

int main()
{
    //std::string image_path = samples::findFile("eu.jpg");
    std::string image_path = "C:\\code\\image\\Image\\Image\\x64\\Debug\\f.jpg";
    Facefindinphoto(image_path);
    waitKey(0); // Wait for a keystroke in the window
    destroyAllWindows();
    return 0;
}