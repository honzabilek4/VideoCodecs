#include "BerClass.h"
#include <bitset>
#include <random>
#include <sys/stat.h>
#include <stdint.h>

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

int BerClass::simulateBer(const char* filename, double ber)
{
    if (ber>1 || ber<0)
    {
        error="Wrong BER value.";
        return -1;
    }
    filesize=getFileSize(filename);


    if(filesize<=0)
    {
        error="Wrong file size.";
        return -1;
    }

    fopen_s(&file,filename,"rb");

    if(file==NULL)
    {
        error="Cannot open file.";
        return -1;
    }

    double p = ber;
    std::bitset<8> b;

    for(int i=0;i<100;i++)
    {


    for(int i=0;i<8;i++)
    {
        double val = (double)rand()/RAND_MAX;
        if(val<p)
        {
            b.set(i,true);
        }


    }

    std::cout<<"bset:"<<b<<std::endl;
    b.reset();
    }

    uint8_t *buffer = new uint8_t[filesize];
    fread_s(buffer,filesize,1,filesize,file);

    std::cout<<buffer[0]<<std::endl;

    return 0;

}
