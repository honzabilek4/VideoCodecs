
#include "VideoUtility.h"
#pragma once
class PsnrClass: public VideoUtility
{
public:
	PsnrClass();
	~PsnrClass();

    double** computePSNR(const char* filename1, const char* filename2, int width, int height, int maxFrames);
	double PsnrClass::getAveragePsnr(double** psnrArray);
	
	

private:
	//private attributes
	const int MAX_PSNR=100;
	int i;
	
	
	int numberOfFrame = 0;
	double difference;
	double squareYError= 0;
	double squareUError = 0;
	double squareVError = 0;


	double **psnrArray;
	// private methods
	double getPsnr(double peak, double mse);
	
	
	
	
};



