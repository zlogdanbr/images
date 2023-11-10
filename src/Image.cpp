#include <iostream>
#include  "segmentation.h"
#include  "demo.h"

using namespace std;


/**

From : https://github.com/opencv/opencv/issues/10071
Code snippet doesn't look valid:

1st call should be ocl::haveOpenCl() (checks that OpenCL support is compiled and OpenCL 1.2+ runtime is found) with checking of return value. 
Calling ocv::setUseOpenCL(true) without this check is programming error.
It is usually used to initialize OpenCL context in a custom way (D3D/OpenGL sharing).

2nd call should be ocl::setUseOpenCL(). Mostly used to disable/enable (in this order) OpenCL optimizations in the current thread..
 Not needed to call at all in normal programs (allow users to configure OpenCV-OpenCL externally). 
 This function raises an error, because you explicitly asks to enable OpenCL support, but it can't do it, so you got proper answer about this via exception.
Why it still eats problem in Release mode? I believe this will be fixed in the next major OpenCV update.

3rd call should be ocl::useOpenCL() - checks that OpenCL is activated successfully. It is enough to have this 
call only to check OpenCL final activation. This function should not raise any exceptions.

so your snippet code should be:
if (ocl::useOpenCl()) cout << "OpenCL is activated\n";

Apparently I cannot initialize these at my current computer ( either a CPU or my onboard graphic board does not work )

*/

int main()
{
	
	// Only worked on linux Windows 10
	// cascade classifiers
	std::string im =  "George_Costanza.jpg";

	FindAndDrawCircles(im);


	destroyAllWindows();
}