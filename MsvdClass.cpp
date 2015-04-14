#include "MsvdClass.h"

int window;

float msvd;
Mat A, B;
Mat svdA, svdB;
float* a;
float* b;
double Dk;
double* msvdArray;
double* DkArray;

MsvdClass::MsvdClass()
{
	window = 8;
}


MsvdClass::~MsvdClass()
{
}

Mat MsvdClass::getSingular(InputArray src)
{
	SVD svd = SVD::SVD(src, SVD::NO_UV);

	return svd.w;
}
void MsvdClass::getMatrix(unsigned char* p, float* a, int window)  //returns window matrix with left upper corner at *p
{

	for (int k = 0; k < window; k++)
	{
		p = p + k*width;

		for (int l = 0; l < window; l++)
		{
			a[k*window + l] = *p;
			++p;
		}

	}

}

double* MsvdClass::computeMsvd(const char* filename1, const char* filename2, int width, int height, int maxFrame)
{

	frameSize = computeFrameSize(width, height);			//Yuv files are binary files and have no header, you have to set width, height and compute frame size.
	MsvdClass::width = width;
	MsvdClass::height = height;

	int size1 = getFileSize(filename1);
	int size2 = getFileSize(filename2);

	if ((size1 != size2) || (size1 % frameSize))
    {
        error=  "File must have same size and must cotain only whole frames.";
        return msvdArray;
    }

	fopen_s(&file1, filename1, "rb");
	fopen_s(&file2, filename2, "rb");

	if (file1 == NULL)
    {
        error= "Cannot open file1.";
        return msvdArray;
    }
	if (file2 == NULL)
    {
        error= "Cannot open file2.";
        return msvdArray;
    }

	if ((frame1 = (unsigned char*)calloc(frameSize, sizeof(unsigned char))) == NULL)
    {
        error= "Cannot allocate memory.";
        return msvdArray;
    }
	if ((frame2 = (unsigned char*)calloc(frameSize, sizeof(unsigned char))) == NULL)
    {
        error= "Cannot allocate memory";
        return msvdArray;
    }
	if ((msvdArray = (double*)calloc(maxFrame, sizeof(float))) == NULL)
    {
        error= "Cannot allocate memory";
        return msvdArray;
    }

	if (maxFrame > size1 / frameSize)
    {
        error= "Video has not so much frames.";
        return msvdArray;
    }




	a = new float[window*window];		//bufer for window values
	b = new float[window*window];		//buffer for window values

	int stepX = width / window;			//number of steps on axis
	int stepY = height / window;		//number of steps on axis

	DkArray = new double[stepX*stepY];		//allocate Dk array
	msvdArray = new double[maxFrame];		//allocate msvdAray
	
	
	int frameNumber = 0;	

	while ((frameNumber < maxFrame) && (fread_s(frame1, frameSize, 1, frameSize, file1) == frameSize) && (fread_s(frame2, frameSize, 1, frameSize, file2)) == frameSize) // per frame cycle
	{
		unsigned char *p1;				//pointer to a specific frame
		unsigned char *p2;				//pointer to a specific frame
		msvd = 0;

		for (int i = 0; i < stepY; i++)			// per window cycle
		{
			p1 = frame1 + i*width;
			p2 = frame2 + i*width;

			for (int j = 0; j < stepX; j++)
			{
				getMatrix(p1, a, window);	// fill provided buffer with window values
				getMatrix(p2, b, window);

				A = Mat(8, 8, CV_32F, a);		//create Mat object, which can be input to getSingular
				B = Mat(8, 8, CV_32F, b);

				//cout << "A = " << endl << " " << A << endl << endl;
				//cout << "B = " << endl << " " << B << endl << endl;

				svdA = getSingular(A);		//computes svd of given Mat, returns Mat(8,1) with singularities
				svdB = getSingular(B);

				//cout << "svdA = " << endl << " " << svdA << endl << endl;
				//cout << "svdB = " << endl << " " << svdB << endl << endl;

				Mat diff = (svdA - svdB);			//per element operations, Dk formula
				//cout << diff << endl;
				multiply(diff, diff, diff);    //each element pow ^2
				//cout << diff << endl;
				Dk = sum(diff)[0];	
				//cout << Dk << endl;
				Dk = sqrt(Dk);			//square root of sum
				//cout << "Dk" << Dk << endl;
				DkArray[i*(width / window) + j] = Dk;			//store Dk

				p1 += window;  //window step is as big as  its size, non-overlapping window
				p2 += window;

			}

		}

		int size = stepX*stepY;		//size of Dk array					
		std::sort(&DkArray[0], &DkArray[size]);
		double median = size % 2 ? DkArray[size / 2] : (DkArray[size / 2 - 1] + DkArray[size / 2]) / 2;		//get median



		for (int i = 0; i < size; i++)
		{
			msvd += (DkArray[i] - median) > 0 ? (DkArray[i] - median) : (median - DkArray[i]);			//absolute difference
		}

		msvdArray[frameNumber] = msvd / size;			//store msvd for frame
        std::cout << msvd/size << std::endl;
		frameNumber++;
	}
	return msvdArray;
}
