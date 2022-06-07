#ifndef _CVWDMOS_
#define _CVWDMOS_

#include "opcvwrapper.h"

#ifdef _WIN_
#define image_path_mamo1 "C:\\code\\image\\Image\\Image\\x64\\Debug\\TESTE4.BMP"
#define image_path_mamo2 "C:\\code\\image\\Image\\Image\\x64\\Debug\\TESTE.BMP"
#define image_path_eu "C:\\code\\image\\Image\\Image\\x64\\Debug\\eu.jpg"
#define image_path_faces "C:\\code\\image\\Image\\Image\\x64\\Debug\\f.jpg"
#define image_path_duda "C:\\code\\image\\Image\\Image\\x64\\Debug\\DSCI0343.JPG"
#endif

void FindAndDrawCircles(const std::string& image_path);
void FindAndDrawRectangles(const std::string& image_path);
void FindAndDFacesAndEyes(const std::string& image_path);
void FindAndDFacesAndEyes(Mat& img);
void segmentImage(const std::string& image_path);
/**
* ImageAdjustmentsTesting
* it tests adjusments in a photo specified by the path image_path
*/
void ImageAdjustmentsTesting(const std::string& image_path);
/**
* detecting
* Finds edges in a poto specified by the path image_path using the laplacian
* algorithm.
*/
void FindEdgesOnPhoto(const std::string& image_path);
void ApplyCustomFilter(const std::string& image_path);
void FindTheCountours(const std::string& image_path);

#endif