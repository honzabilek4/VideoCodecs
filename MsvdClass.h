#include "include/core.hpp"
#include "VideoUtility.h"
#include <vector>
#include <algorithm>
#pragma once

using namespace cv;
class MsvdClass : public VideoUtility
{
public:
	MsvdClass();
	~MsvdClass();
	double* msvdArray;
	double* MsvdClass::computeMsvd(const char* filename1, const char* filename2, int width, int height, int maxFrame);

private:

	int window;
	Mat A, B;
	Mat svdA, svdB;
	Mat C;
	double Dk;
	double* DkArray;
	float* a;
	float* b;
	double msvd;
	Mat MsvdClass::getSingular(InputArray src);
	void MsvdClass::getMatrix(unsigned char* p, float* a, int window);
};

