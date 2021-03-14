#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QGraphicsOpacityEffect>
#include <QScreen>
#include <QUrl>
#include <fstream>
#include "single_include/nlohmann/json.hpp"
#include <QtNetwork/QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QXmlStreamReader>
#include <QtNetwork/QNetworkReply>
#include <QFile>
#include <QPixmap>
#include <QVBoxLayout>
#include <QScrollArea>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
    void onImageResult(QNetworkReply*);
    void on_refresh_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QNetworkRequest request;

protected:
    void paintEvent(QPaintEvent*);
    void resizeEvent(QResizeEvent*);
};



#endif // MAINWINDOW_H
