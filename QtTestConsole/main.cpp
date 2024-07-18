#include <QtCore/QCoreApplication>
#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList testList;
    testList << "Hello" << "World";
    qDebug() << testList;

    return a.exec();
}
