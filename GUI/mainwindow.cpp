#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QGraphicsOpacityEffect>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int scaled = 185;
    QPixmap pixmap(":/resources/profile.png");
    QPixmap temp(pixmap.scaled(scaled, scaled, Qt::KeepAspectRatio).size());
    temp.fill(Qt::transparent);

    QPainter p(&temp);
    p.setCompositionMode(QPainter::CompositionMode_Source);
    p.drawPixmap(0,0, pixmap.scaled(scaled, scaled, Qt::KeepAspectRatio));
    p.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p.fillRect(temp.rect(), QColor(0,0,0,150));
    p.end();

    pixmap = temp;

    ui->setupUi(this);
    ui->watermark->setPixmap(pixmap);
    ui->centralWidget->setStyleSheet("* { background: #000000};");

}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    this->close();
}
