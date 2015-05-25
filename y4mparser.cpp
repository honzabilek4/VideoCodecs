#include "y4mparser.h"
#include <QStringList>

Y4mParser::Y4mParser()
{

}

int Y4mParser::getHeight(QString filename)
{
    int height;
    height = getParameter('H',filename).toInt();
    return height;

}
int Y4mParser::getWidth(QString filename)
{
    int width;
    width = getParameter('W',filename).toInt();
    return width;
}

double Y4mParser::getFrameRate(QString filename)
{
    double frameRate;
    QString temp = getParameter('F',filename);
    if(temp!=NULL)
    {
      QStringList list = temp.split(':');
       if(list.length()!=2)
           return NULL;
       frameRate=list.at(0).toDouble()/list.at(1).toDouble();
    }
    return frameRate;
}

QString  Y4mParser::getParameter(char parameter,QString filename)
{
    FILE *file;
    QString value;
    char *header = new char[80];
    char y4m_Delimiter[] {'Y','U','V','4','M','P','E','G','2',' '};

    fopen_s(&file,filename.toStdString().c_str(),"r");

    if(file==NULL)
    {
        error="Cannot open file for reading.";
        return NULL;
    }
    if(fread_s(header,80,1,80,file)==80)
    {
        int i;
        for(i=0;i<10;i++)
        {
            if(header[i]!=y4m_Delimiter[i])
            {
                error="Wrong y4m header.";
                return NULL;
            }
        }
        while(i<80)
        {
            if(header[i]==parameter)
            {
                i++;
                while(header[i]!=' ')
                {

                    value.append(header[i]);
                    i++;
                }
                return value;
            }

            i++;
        }


    }

    return NULL;

}

