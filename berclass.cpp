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


   // std::bitset<8> b;
  //  b.reset();
    uint8_t b = 0;
    uint8_t *buffer = new uint8_t[filesize];
    if(fread_s(buffer,filesize,1,filesize,file)==filesize)
    {

        unsigned char *p = buffer;

        for(int u=0;u<filesize;u++)
        {

            for(int i=0;i<8;i++)
            {
                double val = (double)rand()/RAND_MAX;
                if(val<ber)
                {
                   // b.set(i,true);
                    b = (b+1) << 1;
                }
                else
                {
                    b=b<<1;
                }
            }

          buffer[u]^=b;
          p++;
        }

        FILE *saveFile;
        fopen_s(&saveFile,"test.webm","wb");
        if(saveFile==NULL)
        {
            error="Cannot open file.";
            return -1;
        }
        fwrite(buffer,sizeof(uint8_t),filesize,saveFile);
        fclose(saveFile);


    }
    return 0;

}
