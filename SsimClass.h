#include "VideoUtility.h"
#pragma once
class SsimClass : public VideoUtility
{
public:
	SsimClass();
    SsimClass(int window, int step);
	~SsimClass();

    double* computeSsim(const char* filename1, const char* filename2, int width, int height, int maxFrame);
    double* ssimArray;

private:

	int meanLuma1;
	int meanLuma2;
    int windowSize;
    int stepSize;
	double sigma1;
	double sigma2;
	double sigma12;
	const double k1 = 0.01;
	const double k2 = 0.03;
    double ssimWindow;
	int L;
	double c1;
	double c2;
    double ssim(unsigned char* p1, unsigned char* p2,int windowSize);
};

