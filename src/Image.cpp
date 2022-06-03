#include <iostream>
#include  "segmentation.h"
#include  "demo.h"

using namespace std;
#include <iostream>

using namespace std;

int main()
{
	NoduleRec n{ image_path_eu };
	n.preprocess();
	n.findContornos();
	n.HighlightRoi();
	showImage(n.getOriginalImg(), "Original");
	showImage(n.getEdgesImg(), "Edges");
	showImage(n.getFinalImg(), "Final");
	waitKey(0);
}