#ifndef BERCLASS_H
#define BERCLASS_H
#include <iostream>

class BerClass
{
public:
    BerClass();
    ~BerClass();

    std::string error;
    int simulateBer(const char* filename, const char* saveFilename, double ber);
    long filesize;
private:

    FILE *file;
    FILE *saveFile;

    long getFileSize(const char* filename);
};

#endif // BERCLASS_H
