#pragma once
#include "opcvwrapper.h"

class NoduleRec final
{
public:
	NoduleRec(const std::string& path)
	{
		loadImage(path, original);
	};
	~NoduleRec()
	{
		
	};
	const Mat& getOriginalImg() const { return original; };
	const Mat& getFinalImg() const { return original; };
	const bool ErrorInOriginalLoading() const { return original.empty(); };
	RoiAretype getRoi() const { return contours; };
	std::vector<Vec4i> gethierarchy() const { return hierarchy; };
	bool preprocess();
	bool findContornos();
	
private:
	NoduleRec(const NoduleRec&) = delete;
	NoduleRec operator=(const NoduleRec&) = delete;
	Mat original;
	Mat final;
	RoiAretype contours;
	std::vector<Vec4i> hierarchy;
};