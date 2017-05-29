#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

        QRegExp ipRegex1 ("[a-z]\\w{0,20}");
        QRegExp ipRegex2 ("\\w{0,20}");
        QRegExpValidator *ipValidator1 = new QRegExpValidator(ipRegex1, this);
        QRegExpValidator *ipValidator2 = new QRegExpValidator(ipRegex2, this);

        //Log in
        ui->lineEdit->setValidator(ipValidator1);
        ui->lineEdit_3->setValidator(ipValidator1);

        //Sing up
        ui->lineEdit_2->setValidator(ipValidator2);
        ui->lineEdit_4->setValidator(ipValidator2);
        ui->lineEdit_5->setValidator(ipValidator2);
}

    //var_global
    bool lEdit1,lEdit2,lEdit3,lEdit4,lEdit5;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    quick_exit(1);
}

void MainWindow::on_pushButton_4_clicked()
{
    quick_exit(1);
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox msgBox;
    QFile file("allch.txt");
    QStringList strList;
    QString strLogPass = ui->lineEdit->text()+" "+ui->lineEdit_2->text()+"\r\n";

    if (file.open(QIODevice::ReadOnly)){
        while(!file.atEnd())
        {
            strList << file.readLine();
        }
        file.close();
    }

    for (int i=0; i<strList.length();++i){
        if(strLogPass==strList[i]){
        msgBox.setText("Coment HERE!");
            msgBox.exec();
            return;
        } else {
            QMessageBox::warning(0,"2","Noooo");
            return;
        }
    }

    ui->lineEdit  ->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString a =ui->lineEdit_4->text();
    QString b =ui->lineEdit_5->text();
    if ( a == b ){
    QFile file("allch.txt");
    QTextStream out(&file);

    if (file.open(QIODevice::Append)){
        out << ui->lineEdit_3->text()+" "+ui->lineEdit_4->text()<<"\r\n";
        file.close();
    }
    } else {
        QMessageBox::critical(0,"Error","404");
    }

    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    if(checked==true){
   ui->lineEdit_2->setEchoMode(QLineEdit::Normal);}
    else{
   ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    }
}

void MainWindow::on_checkBox_2_toggled(bool checked)
{
    if(checked==true){
    ui->lineEdit_4->setEchoMode(QLineEdit::Normal);
    ui->lineEdit_5->setEchoMode(QLineEdit::Normal);
    }
    else{
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
    ui->lineEdit_5->setEchoMode(QLineEdit::Password);
    }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
   if (arg1.length() >= 3) {
      lEdit1 =  true;
      if (lEdit1&&lEdit2) ui->pushButton->setEnabled(true);
   } else {
      lEdit1 =  false;
      ui->pushButton->setEnabled(false);
   }
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    if (arg1.length() >= 4) {
       lEdit2 =  true;
       if (lEdit1&&lEdit2) ui->pushButton->setEnabled(true);
    } else {
       lEdit2 =  false;
       ui->pushButton->setEnabled(false);
    }
}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    if (arg1.length() >= 4) {
       lEdit5 =  true;
       if (lEdit3&&lEdit4&&lEdit5) ui->pushButton_3->setEnabled(true);
    } else {
       lEdit5 =  false;
       ui->pushButton_3->setEnabled(false);
    }
}

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    if (arg1.length() >= 4) {
       lEdit4 =  true;
       if (lEdit3&&lEdit4&&lEdit5) ui->pushButton_3->setEnabled(true);
    } else {
       lEdit4 =  false;
       ui->pushButton_3->setEnabled(false);
    }
}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    if (arg1.length() >= 4) {
       lEdit3 =  true;
       if (lEdit3&&lEdit4&&lEdit5) ui->pushButton_3->setEnabled(true);
    } else {
       lEdit3 =  false;
       ui->pushButton_3->setEnabled(false);
    }
}
