#include <iostream>
#include  "segmentation.h"
#include  "demo.h"

using namespace std;

int main()
{
	std::string im =  "George_Costanza.jpg";

	FindAndDrawCircles(im);


	destroyAllWindows();
}