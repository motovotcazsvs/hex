#include <QCoreApplication>
#include <QDebug>
#include <QByteArray>

#define ENQ 0x05
#define ACK 0x06
#define EOT 0x04
#define STX 0x02
#define ETX 0x03
#define CR 0x0D
#define LF 0x0A

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int c1 = 'd';
    int c2 = 16;
    QByteArray f;
    f[0] = 0x0D;
    f[1] = 0x0A;
    qDebug() << hex << c1;
    //QString f1 = f.at(0);
    //qDebug() << f1;
    QByteArray art2;
    art2.append(STX);
    art2.append(0x31); //FN первый фрейм передается
    art2.append("012345678");
    art2.append(ETX);
    art2.append(0x30);
    art2.append(0x38);
    art2.append(CR);
    art2.append(LF);
    qDebug() << "art2" << art2 << "art2.at(i)" << art2.at(3);
    if(art2[2] == '4')qDebug() << "uraaaaaa44444";


    //if(indexOf(art3[1] == io) qDebug << "ura rabotaet";

    QByteArray data2;
    //data2.append(STX);// rabotaet i eto
    data2[0]=STX;//i eto
    if(data2.at(0) == STX) qDebug() << "uraaaaaa";//rabotaet
    QByteArray data;
    //data.append(STX);
    data[1]=STX;
    //if(data[0] == STX) qDebug() << "uraaaaaa";//ne rabotaet

    if(art2.right(5).at(0) == 0x03) qDebug() << "right rabotaet" << art2.right(5).at(0);
    //qDebug() << "right rabotaet" << art2.at(4);

    int ch = 0x00; //ch1, ch2;
    qDebug() << art2.at(art2.length() - 5);

    for(int i = 1; i <= art2.length() - 5; i++){
        ch += art2.at(i);
        if(ch >= 0x100) ch -= 0x100;
    }
    //ch = 0x78;
    unsigned char ch1 = ch >> 4;
    unsigned char ch2 = ch & 0x0F;
    qDebug() << hex << ch << ch1 << ch2;
    //qDebug() << hex << ch;
    if(ch == 0x08) qDebug() << "checksum rabotaet";

    return a.exec();
}
