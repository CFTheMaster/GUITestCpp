#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QGraphicsOpacityEffect>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int scaled = 75;
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
}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::paintEvent(QPaintEvent *event){

    QPainter p2(this);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry  = screen->geometry();

    int height = screenGeometry.height() + 100;
    int width = screenGeometry.width() + 100;

    QLinearGradient linearGrad(QPointF(0, 0), QPointF(width, height));
    linearGrad.setColorAt(0, qRgba(2,0,36,1));
    linearGrad.setColorAt(0.42, qRgba(51,82,142,1));
    linearGrad.setColorAt(0.68, qRgba(46,68,154,1));
    linearGrad.setColorAt(0.92, qRgba(0,212,255,1));

    QRect rect_linear(0,0, width, height);

    p2.fillRect(rect_linear, linearGrad);
    p2.end();

    QWidget::paintEvent(event);
}

void MainWindow::resizeEvent(QResizeEvent *event){
    QMainWindow::resizeEvent(event);
}
