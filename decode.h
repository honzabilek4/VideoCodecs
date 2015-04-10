#ifndef DECODE_H
#define DECODE_H

#include <QDialog>

namespace Ui {
class Decode;
}

class Decode : public QDialog
{
    Q_OBJECT

public:
    explicit Decode(QWidget *parent = 0);
    ~Decode();

private:
    Ui::Decode *ui;
};

#endif // DECODE_H
