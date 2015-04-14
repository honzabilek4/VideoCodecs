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
    double* computeMsvd(const char* filename1, const char* filename2, int width, int height, int maxFrame);
    std::string error;
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
    Mat getSingular(InputArray src);
    void getMatrix(unsigned char* p, float* a, int window);
};

