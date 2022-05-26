#include "opcvwrapper.h"
#include <iostream>


/**
* FindAllFacesInPthoto
* Finds all faces in a photo specified by the path image_path
*/
void FindAllFacesInPthoto(const std::string& image_path)
{
    Mat img;
    int scale = 1;

    if (loadImage(image_path, img) == false)
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return;
    }
   
    CascadeClassifier cascade;
    cascade.load(CASCADE_PATH_FRONTAL_EYE);// haarcascade_frontalface_default.xml

    std::vector<Rect> faces = detectFacesInImage(img, cascade);
    Mat inter = convertRectoImg(faces[0], img);
    drawSquaresFaces(img, 1, faces);
    showImage(img, "Faces at the picture");

}

/**
* findandshowAllFacesInPhoto
* Finds all faces in a photo specified by the path image_path
* C:\opencv2\opencv\sources\data
*/
void findandshowAllFacesInPhoto(const std::string& image_path)
{
    Mat img;
    int scale = 1;

    if (loadImage(image_path, img) == false)
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return;
    }

    CascadeClassifier cascade;
    cascade.load(CASCADE_PATH_FRONTAL);// haarcascade_frontalface_default.xml

    std::vector<Rect> faces = detectFacesInImage(img, cascade);
    std::vector<Mat> submages;
    for (auto& roi : faces)
    {
        submages.emplace_back(convertRectoImg(roi, img));
    }

    int i = 1;
   
    for (auto& image : submages)
    {
        std::string s = "image" + std::to_string(i);
        saveImage(s, image);
        i++;
    }
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
    FindAllFacesInPthoto(image_path);
    waitKey(0); // Wait for a keystroke in the window
    destroyAllWindows();
    return 0;
}