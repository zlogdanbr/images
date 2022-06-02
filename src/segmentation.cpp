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
	findcontours(final, this->contours, this->hierarchy, 3);
	return final.empty();
}

