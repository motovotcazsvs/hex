#include <QCoreApplication>
#include <QDebug>
#include <QByteArray>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int c1 = 'd';
    int c2 = 16;
    QByteArray f;
    f.resize(2);
    f[0] = 0x0D;
    qDebug() << hex << c1;
    qDebug() << f[0];
    //qDebug() << "arr1 " << f[1];


    return a.exec();
}
