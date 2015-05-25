#ifndef Y4MPARSER_H
#define Y4MPARSER_H

#include <QString>

class Y4mParser
{
public:
    Y4mParser();
    int getWidth(QString filename);
    int getHeight(QString filename);
    double getFrameRate(QString filename);
    QString error;
private:
    QString getParameter(char parameter, QString filename);
};

#endif // Y4MPARSER_H
