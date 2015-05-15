#include "channel.h"
#include "ui_channel.h"

Channel::Channel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Channel)
{
    ui->setupUi(this);
}

Channel::~Channel()
{
    delete ui;
}



void Channel::on_browseButton_clicked()
{

}

void Channel::on_saveButton_clicked()
{

}

void Channel::on_okButton_clicked()
{

}

void Channel::on_cancelButton_clicked()
{
    this->close();
}
