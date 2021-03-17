#include "mainwindow.h"
#include "ui_mainwindow.h"



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


void MainWindow::on_actionExit_triggered()
{
    this->close();
}


void MainWindow::paintEvent(QPaintEvent *event){
    int scaled = 80;
    QPixmap pixmap(":/resources/profile.png");
    ui->thingThatAnnoys->setPixmap(pixmap.scaled(scaled, scaled, Qt::KeepAspectRatio));

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


}

void MainWindow::resizeEvent(QResizeEvent *event){
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_anime_clicked()
{
    MainWindow::onImageFromApi("anime");
}

void MainWindow::onImageResult(QNetworkReply *reply){
    QJsonParseError jerror;
    QJsonDocument d = QJsonDocument::fromJson(reply->readAll(), &jerror);
    if(jerror.error != QJsonParseError::NoError){
        qDebug() << jerror.errorString();
    }
    QJsonObject obj = d.object();

    QUrl uri(obj["url"].toString());

    QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
    QNetworkRequest request2(uri);
    QNetworkReply *reply2 = netAccManager->get(request2);
    QEventLoop loop;
    QObject::connect(reply2, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    QByteArray bytes = reply2->readAll();
    QImage img(20, 20, QImage::Format_Indexed8);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry  = screen->geometry();
    img.loadFromData(bytes);
    ui->displayImage->setPixmap(QPixmap::fromImage(img).scaled(screenGeometry.width() -200, screenGeometry.height()-200, Qt::KeepAspectRatio));
    ui->scrollArea->setGeometry(0,0, QPixmap::fromImage(img).scaled(screenGeometry.width(), screenGeometry.height(), Qt::KeepAspectRatio).width() -100,
                                QPixmap::fromImage(img).scaled(screenGeometry.width(), screenGeometry.height(), Qt::KeepAspectRatio).height() -100);


}

void MainWindow::on_neko_clicked()
{
    MainWindow::onImageFromApi("neko");
}

void MainWindow::on_hug_clicked()
{
    MainWindow::onImageFromApi("hug");
}

void MainWindow::on_yuri_clicked()
{
    MainWindow::onImageFromApi("yuri");
}

void MainWindow::onImageFromApi(QString uri){
    QByteArray headText = "GUITest + QT6 / ";
    headText.append(uri.toUtf8());
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::onImageResult);
    const QUrl url("https://api.computerfreaker.pw/v1/" + uri);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("user-agent", headText);
    manager->get(request);
}

void MainWindow::on_baguette_clicked()
{
    MainWindow::onImageFromApi("baguette");
}
