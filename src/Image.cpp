#include <iostream>
#include  "segmentation.h"

int main()
{
    NoduleRec n{ "C:\\code\\image\\Image\\Image\\x64\\Debug\\eu.jpg" };

    if (n.ErrorInOriginalLoading() == true)
    {
        std::cout << "Empty original image" << std::endl;
    }
    if (n.preprocess() == true)
    {
        if (n.findContornos() == false)
        {
            showImage(n.getOriginalImg(), "original");
            showImage(n.getFinalImg(), "final");
        }
    }
    waitKey(0); // Wait for a keystroke in the window
    destroyAllWindows();
    return 0;
}