#include <iostream>
#include  "segmentation.h"
#include  "demo.h"

using namespace std;

int main()
{
	NoduleRec n{ "George_Costanza.jpg" };

	if (n.ErrorInOriginalLoading() == false)
	{
		n.findContornos(1);
		n.HighlightRoi();
		showImage(n.getFinalImg(), "Final");
		waitKey(0);
		showImage(n.getEdgesImg(), "Edges");
		waitKey(0);
	}

	waitKey(0);


	destroyAllWindows();
}