#pragma once
#include "opcvwrapper.h"

class NoduleRec final
{
public:
	explicit NoduleRec(const std::string& path)
	{
		loadImage(path, original);
	};
	~NoduleRec()
	{
		resetInternal();
	};
	const Mat& getOriginalImg() const { return original; };
	const Mat& getFinalImg() const { return final; };
	const Mat& getEdgesImg() const { return edges; };
	const bool ErrorInOriginalLoading() const { return original.empty(); };
	RoiAretype getRoi() const { return contours; };
	std::vector<Vec4i> gethierarchy() const { return hierarchy; };
	bool preprocess();
	bool findContornos();
	void HighlightRoi();
	void resetInternal()
	{
		contours.clear();
		hierarchy.clear();
	}

	
	
private:
	NoduleRec(const NoduleRec&) = delete;
	NoduleRec operator=(const NoduleRec&) = delete;
	Mat original;
	Mat final;
	Mat edges;
	RoiAretype contours;
	std::vector<Vec4i> hierarchy;
};