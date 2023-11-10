#include <iostream>
#include  "segmentation.h"
#include  "demo.h"

using namespace std;

int main()
{
	
	// Only worked on linux Windows 10
	// Apparently there is some internal driver that prevents me from using
	// cascade classifiers
	std::string im =  "George_Costanza.jpg";

	FindAndDrawCircles(im);


	destroyAllWindows();
}