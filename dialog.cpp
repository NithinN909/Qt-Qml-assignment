#include "dialog.h"
#include "ui_dialog.h"
#include "mythread.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    
       mThread = new mythread(this,false,false);

        
        connect(mThread, SIGNAL(valueChanged(int)),
                this, SLOT(onValueChanged(int)));

}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::onValueChanged(int count)
{
    ui->label->setText(QString::number(count));
}

// Start button
void Dialog::on_pushButton_clicked()
{
    mThread->Stop = false;
    mThread->start();


}

// Stop button
void Dialog::on_pushButton_2_clicked()
{
    mThread->stopped=true;
    mThread->Stop = true;
}

void Dialog::on_pushButton_3_clicked()
{
    mThread->Stop = false;
     mThread->i=0;
    mThread->start();

}
