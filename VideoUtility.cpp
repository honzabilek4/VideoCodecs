#include "VideoUtility.h"


int frameSize;
int width, height;
FILE *file1;
FILE *file2;
unsigned char *frame1;
unsigned char *frame2;
VideoUtility::VideoUtility()
{
}


VideoUtility::~VideoUtility()
{
}

int VideoUtility::getFileSize(const char* filename)
{

	struct stat st;
	stat(filename, &st);
	int fileSize = st.st_size;
	if (fileSize <= 0)
		throw "Wrong file size or filename.";
	return fileSize;
}

int VideoUtility::computeFrameSize(int width, int height)
{
	if (width < 1 || height < 1)
		throw "Wrong video dimensions.";
	else
	{
		int frameSize = width * height * 3 / 2;    //from definition of yuv size=h*w*3/2 (yuv420 6bytes per 4 pixels)

		return frameSize;
	}
}
