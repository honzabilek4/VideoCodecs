#include "BerClass.h"
#include <bitset>
#include <random>
#include <time.h>
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

int BerClass::simulateBer(const char* filename,const char* saveFilename, double ber)
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

    uint8_t b = 0;
    uint8_t *buffer = new uint8_t[filesize];

    double min = 1;
    double max = pow(10,30);
    std::uniform_real_distribution<double> unif(min,max);
    std::default_random_engine re;
    re.seed((unsigned)time(NULL));

    if(fread_s(buffer,filesize,1,filesize,file)==filesize)
    {

        unsigned char *p = buffer;

        for(int u=0;u<filesize;u++)
        {

            for(int i=0;i<8;i++)
            {

                double val = unif(re);
                val=val/max;
                if(val<ber)
                {
                    b = (b << 1) + 1;
                }
                else
                {
                    b = b<<1;
                }
            }

            *p^=b;      //modify bits

            if(b!=0)
            {
                std::cout<<(int)b<<std::endl;
            }

            p++;
            b=0;

        }

        FILE *saveFile;
        fopen_s(&saveFile,saveFilename,"wb");

        if(saveFile==NULL)
        {
            error="Cannot open file.";
            return -1;
        }

        fwrite(buffer,sizeof(uint8_t),filesize,saveFile);
        fclose(saveFile);


    }
    fclose(file);
    delete buffer;

    return 0;

}
