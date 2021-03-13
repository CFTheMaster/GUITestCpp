#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QLabel>
#include <QPixmap>


QByteArray readTextFile(const QString &file_path) {
  QFile input_file(file_path);
  QByteArray input_data;

  if (input_file.open(QIODevice::Text | QIODevice::Unbuffered | QIODevice::ReadOnly)) {
    input_data = input_file.readAll();
    input_file.close();
    return input_data;
  }
  else {
    return QByteArray();
  }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString style_sheet = readTextFile(":/stylesheets/main.qss");
    app.setStyleSheet(style_sheet);

    MainWindow window;
    window.show();

    return app.exec();
}
