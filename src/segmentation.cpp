#include "segmentation.h"


bool NoduleRec::preprocess()
{
	final = equalizeColorImage(original);

	if (final.empty() == true)
	{
		return false;
	}

	final = laplacian(final);

	if (final.empty() == true)
	{
		return false;
	}

	return true;
}

bool NoduleRec::findContornos()
{
	findcontours(final, this->contours, this->hierarchy, 50, this->edges);
	return final.empty();
}


void NoduleRec::HighlightRoi()
{
	final.release();
	original.copyTo(final);
	drawCountour(this->contours, final, this->hierarchy);
}


//typedef std::vector< std::vector<Point> > RoiAretype;

