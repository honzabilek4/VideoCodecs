#include "PsnrClass.h"



int i;
int numberOfFrame;
double difference;
double squareYError;
double squareUError;
double squareVError;

const int MAX_PSNR = 100;

double **psnrArray = NULL;

using namespace std;

PsnrClass::PsnrClass()
{

}


PsnrClass::~PsnrClass()
{
}

//returns total size of file



double PsnrClass::getPsnr(double peak, double msqe) {

    double psnr;

    if ((double)msqe > 0.0)
        psnr = 10.0 * log10(peak * peak / msqe);
    else
        psnr = MAX_PSNR;

    if (psnr > MAX_PSNR)
        psnr = MAX_PSNR;

    return psnr;
}



double** PsnrClass::computePSNR(const char* filename1, const char* filename2, int width, int height, int maxFrame)
{
    error.clear();

    frameSize = computeFrameSize(width, height);			//Yuv files are binary files and have no header, you have to set width, height and compute frame size.

    int size1 = getFileSize(filename1);
    int size2 = getFileSize(filename2);

    if ((size1 != size2) || (size1 % frameSize))
    {
        error="File must have same size and must cotain only whole frames.";
        return psnrArray;
    }

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

    if (maxFrame > size1 / frameSize)
        throw "Video has not so much frames.";

    psnrArray = new double*[maxFrame];	//data storage, three results for each frame(YUV)
    for (int u = 0; u < maxFrame; ++u)
        psnrArray[u] = new double[3];
    //Read frame after frame and compute their mean square error.(file pointer is increased of amount of bytes read each time automatically!)
    while ((numberOfFrame < maxFrame) && (fread_s(frame1, frameSize, 1, frameSize, file1) == frameSize) && (fread_s(frame2, frameSize, 1, frameSize, file2)) == frameSize)
    {
        unsigned char *p1 = frame1;				//pointer to a specific frame
        unsigned char *p2 = frame2;

        //psnr calculation for Y
        for (i = 0; i < width*height; ++i)
        {
            difference = (*p2) - (*p1);				//diference between two bytes
            squareYError += difference*difference / (width*height);
            ++p1;
            ++p2;
        }
        psnrArray[numberOfFrame][0] = getPsnr(255.0, squareYError);
        squareYError = 0;

        //cacluclation for U
        for (i; i < (width*height) + (width*height / 4); i++)
        {
            difference = (*p2) - (*p1);
            squareUError += difference*difference / ((frameSize - (width*height)) / 2);
            ++p1;
            ++p2;
        }
        psnrArray[numberOfFrame][1] = getPsnr(255.0, squareUError);
        squareUError = 0;

        //calculation for V
        for (i; i < frameSize; i++)
        {
            difference = (*p2) - (*p1);
            squareVError += difference*difference / ((frameSize - (width*height)) / 2);
            ++p1;
            ++p2;
        }
        psnrArray[numberOfFrame][2] = getPsnr(255.0, squareVError);
        squareVError = 0;

        numberOfFrame++;	//move to next frame
    }

    fclose(file1);
    fclose(file2);

    return psnrArray;

}


