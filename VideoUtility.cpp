#include "VideoUtility.h"

VideoUtility::VideoUtility()
{
}


VideoUtility::~VideoUtility()
{
}

long VideoUtility::getFileSize(const char* filename)
{
    struct stat st;
    stat(filename, &st);
    off_t fileSize = st.st_size;
    if (fileSize <= 0)
    {
        return -1;
    }
    return fileSize;

}

int VideoUtility::computeFrameSize(int width, int height)
{
	if (width < 1 || height < 1)
        return -1;
	else
	{
		int frameSize = width * height * 3 / 2;    //from definition of yuv size=h*w*3/2 (yuv420 6bytes per 4 pixels)

		return frameSize;
	}
}
