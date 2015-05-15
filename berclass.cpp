#include "BerClass.h"

BerClass::BerClass()
{   

}
BerClass::~BerClass()
{

}
int BerClass::getFileSize(const char* filename)
{

    struct stat st;
    stat(filename, &st);
    int fileSize = st.st_size;
    if (fileSize <= 0)
        return -1;
    return fileSize;
}

int BerClass::simulateBer(const char *filename, double ber)
{
    if (ber>1 || ber<0)
    {
        error="Wrong BER value.";
        return -1;
    }

    fopen_s(&file,filename,"rwb");

    if(file==NULL)
    {
        error="Cannot open file.";
        return -1;
    }

    filesize=getFileSize(filename);

    if(filesize<=0)
    {
        error="Wrong file size.";
        return -1;
    }


    return 0;

}
