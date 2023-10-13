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
		showImage(n.getEdgesImg(), "Edges");
	}

	waitKey(0);


	destroyAllWindows();
}