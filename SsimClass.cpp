#include "SsimClass.h"

double* ssimArray = NULL;
double ssimWindow;

int windowSize;
int stepSize;
int meanLuma1;
int meanLuma2;
double sigma1;
double sigma2;
double sigma12;
const double k1 = 0.01;
const double k2 = 0.03;
int L;   //dynamic range of pixel values
double c1;
double c2;
using namespace std;

SsimClass::SsimClass()
{
	L = 255;
	c1 = pow(L*k1, 2.0);
	c2 = pow(L*k2, 2.0);
    windowSize=16;
    stepSize=8;
}

SsimClass::SsimClass(int window,int step)
{
    L= 255;
	c1 = pow(L*k1, 2.0);
	c2 = pow(L*k2, 2.0);

    windowSize=window;
    stepSize=step;
}


SsimClass::~SsimClass()
{
}

double SsimClass::ssim(unsigned char* p1, unsigned char* p2, int windowSize)
{
	unsigned char *p8_1;
	unsigned char *p8_2;
	meanLuma1 = 0;
	meanLuma2 = 0;
	sigma1 = 0;
	sigma2 = 0;
	sigma12 = 0;
	//mean luma
	for (int k = 0; k < windowSize; k++)
	{
		p8_1 = p1 + k*width;
		p8_2 = p2 + k*width;

		for (int l = 0; l < windowSize; l++)
		{
			meanLuma1 += *p8_1;
			meanLuma2 += *p8_2;
			++p8_1;
			++p8_2;

		}

	}
	meanLuma1 = meanLuma1 / (windowSize*windowSize);
	meanLuma2 = meanLuma2 / (windowSize*windowSize);

	//sigma
	for (int k = 0; k < windowSize; k++)
	{
		p8_1 = p1 + k*width;
		p8_2 = p2 + k*width;

		for (int l = 0; l < windowSize; l++)
		{
			sigma1 += pow(*p8_1 - meanLuma1, 2.0);
			sigma2 += pow(*p8_2 - meanLuma2, 2.0);
			++p8_1;
			++p8_2;

		}

	}

	sigma1 = pow(sigma1 / (windowSize*windowSize - 1), 0.5);
	sigma2 = pow(sigma2 / (windowSize*windowSize - 1), 0.5);

	//covariance
	for (int k = 0; k < windowSize; k++)
	{
		p8_1 = p1 + k*width;
		p8_2 = p2 + k*width;

		for (int l = 0; l < windowSize; l++)
		{
			sigma12 += (*p8_1 - meanLuma1)*(*p8_2 - meanLuma2);
			++p8_1;
			++p8_2;
		}
	}

	sigma12 *= 1 / (pow(windowSize, 2.0) - 1);

	//return ssim formula
	double ssim = ((2 * meanLuma1*meanLuma2 + c1)*(2 * sigma12 + c2)) / ((pow(meanLuma1, 2.0) + pow(meanLuma2, 2.0) + c1)*(pow(sigma1, 2.0) + pow(sigma2, 2.0) + c2));
	
	return ssim;
}
double* SsimClass::computeSsim(const char* filename1, const char* filename2, int width, int height, int maxFrame)
{
	frameSize = computeFrameSize(width, height);			//Yuv files are binary files and have no header, you have to set width, height and compute frame size.
	SsimClass::width = width;
	SsimClass::height = height;

	int size1 = getFileSize(filename1);
	int size2 = getFileSize(filename2);

	if ((size1 != size2) || (size1 % frameSize))
		throw  "File must have same size and must cotain only whole frames.";

	fopen_s(&file1, filename1, "rb");
	fopen_s(&file2, filename2, "rb");

	if (file1 == NULL)
		throw "Cannot open file1.";
	if (file2 == NULL)
		throw "Cannot open file2.";

	if ((frame1 = (unsigned char*)calloc(frameSize, sizeof(unsigned char))) == NULL)
		throw "Cannot allocate memory.";
	if ((frame2 = (unsigned char*)calloc(frameSize, sizeof(unsigned char))) == NULL)
		throw "Cannot allocate memory";
	if ((ssimArray = (double*)calloc(maxFrame, sizeof(double))) == NULL)
		throw "Cannot allocate memory";

	if (maxFrame > size1 / frameSize)
		throw "Video has not so much frames.";
	
	if (windowSize > width / 2 || windowSize > height / 2)
		throw "Window size is too large.";

	if (stepSize >= windowSize)
		throw "Step must be lower than window size.";

	int countX = ((width - windowSize) / stepSize) + 1;   //number of steps on axis
	int countY = ((height - windowSize) / stepSize) + 1;

	int frameNumber=0;

	while ((frameNumber < maxFrame) && (fread_s(frame1, frameSize, 1, frameSize, file1) == frameSize) && (fread_s(frame2, frameSize, 1, frameSize, file2)) == frameSize)
	{
		unsigned char *p1;				//pointer to a specific frame
		unsigned char *p2;
		ssimWindow = 0;

		for (int i = 0; i < (height - windowSize); i += stepSize)
		{
			p1 = frame1 + i*width;
			p2 = frame2 + i*width;

			for (int j = 0; j < (width - windowSize); j += stepSize)
			{

				ssimWindow += ssim(p1, p2, windowSize);

				p1+=stepSize;
				p2+=stepSize;

			}

		}

		ssimArray[frameNumber] = ssimWindow / (countX * countY);		//store average ssim for frame into array;
		cout << frameNumber+1<<": " << (ssimWindow / (countX * countY)) << endl;
		frameNumber++;

	}
	return ssimArray;

}
