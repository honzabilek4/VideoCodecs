
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <sys/stat.h>
#pragma once

class VideoUtility
{
public:
	VideoUtility();
	~VideoUtility();

	int frameSize;
	int width, height;
	FILE *file1;
	FILE *file2;

	unsigned char *frame1;
	unsigned char *frame2;
	int getFileSize(const char* filename);
	int computeFrameSize(int width, int height);

    std::string error;
    bool _abort;

};

