#include "SsimClass.h"

SsimClass::SsimClass()
{
    L = 255;


	c1 = pow(L*k1, 2.0);
	c2 = pow(L*k2, 2.0);
    windowSize=16;
    stepSize=8;

    ssimArray=NULL;
    ssimWindow=0;

}

SsimClass::SsimClass(int window,int step)
{
    L= 255;
	c1 = pow(L*k1, 2.0);
	c2 = pow(L*k2, 2.0);

    windowSize=window;
    stepSize=step;

    ssimArray=NULL;
    ssimWindow=0;
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
     _abort=false;
    error.clear();

	frameSize = computeFrameSize(width, height);			//Yuv files are binary files and have no header, you have to set width, height and compute frame size.
    if(frameSize<=0)
    {
        error= "Wrong video dimensions.";
        return ssimArray;
    }
    SsimClass::width = width;
	SsimClass::height = height;

    long size1 = getFileSize(filename1);
    long size2 = getFileSize(filename2);
    if(size1<=0||size2<=0)
    {
         error= "Wrong file size or filename.";
         return ssimArray;
    }
	if ((size1 != size2) || (size1 % frameSize))
    {
        error=  "File must have same size and must cotain only whole frames.";
        return ssimArray;
    }

	fopen_s(&file1, filename1, "rb");
	fopen_s(&file2, filename2, "rb");

	if (file1 == NULL)
    {
        error= "Cannot open file1.";
        return ssimArray;
    }
	if (file2 == NULL)
    {
        error= "Cannot open file2.";
        return ssimArray;
    }

	if ((frame1 = (unsigned char*)calloc(frameSize, sizeof(unsigned char))) == NULL)
    {
        error= "Cannot allocate memory.";
        return ssimArray;
    }
	if ((frame2 = (unsigned char*)calloc(frameSize, sizeof(unsigned char))) == NULL)
    {
        error= "Cannot allocate memory";
        return ssimArray;
    }
	if ((ssimArray = (double*)calloc(maxFrame, sizeof(double))) == NULL)
    {
        error= "Cannot allocate memory";
        return ssimArray;
    }

	if (maxFrame > size1 / frameSize)
    {
        error= "Video has not so much frames.";
        return ssimArray;
    }

	
	if (windowSize > width / 2 || windowSize > height / 2)
    {
        error= "Window size is too large.";
        return ssimArray;
    }

	if (stepSize >= windowSize)
    {
        error= "Step must be lower than window size.";
        return ssimArray;
    }

    int countX = ((width - windowSize) / stepSize)+1;   //number of steps on axis
    int countY = ((height - windowSize)/ stepSize)+1;

	int frameNumber=0;

	while ((frameNumber < maxFrame) && (fread_s(frame1, frameSize, 1, frameSize, file1) == frameSize) && (fread_s(frame2, frameSize, 1, frameSize, file2)) == frameSize)
	{
        if(_abort)
        {
            fclose(file1);
            fclose(file2);
			free(frame1);
			free(frame2);
            return ssimArray;
        }

		unsigned char *p1;				//pointer to a specific frame
		unsigned char *p2;
		ssimWindow = 0;

        for (int i = 0; i <= (height - windowSize); i += stepSize)
		{
			p1 = frame1 + i*width;
			p2 = frame2 + i*width;

            for (int j = 0; j <= (width - windowSize); j += stepSize)
			{

				ssimWindow += ssim(p1, p2, windowSize);

				p1+=stepSize;
				p2+=stepSize;

			}

		}

		ssimArray[frameNumber] = ssimWindow / (countX * countY);		//store average ssim for frame into array;        
		frameNumber++;
        std::cout << frameNumber<<": " << (ssimWindow / (countX * countY)) << std::endl;
	}
	fclose(file1);
	fclose(file2);
	free(frame1);
	free(frame2);
	return ssimArray;

}
