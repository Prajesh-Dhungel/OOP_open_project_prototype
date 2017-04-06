#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString mFilename="task.txt";
    QFile sFile (mFilename,this);
    if (sFile.open(QFile::ReadOnly | QFile::Text) )
    {
        QTextStream in (&sFile);
        QString text=in.readAll();
        sFile.close();

        ui->textEdit->setPlainText(text);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString mFilename="task.txt";
    QFile sFile (mFilename);
    if (sFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out (&sFile);
        out<<ui->textEdit->toPlainText();
        sFile.close();
    }
}
