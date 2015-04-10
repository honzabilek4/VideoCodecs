#include "decode.h"
#include "ui_decode.h"

Decode::Decode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Decode)
{
    ui->setupUi(this);
}

Decode::~Decode()
{
    delete ui;
}
