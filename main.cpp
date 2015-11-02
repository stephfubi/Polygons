#include <QCoreApplication>

#include <tests/test_graham.h>
#include <tests/test_parsevertexlist.h>
#include <tests/test_sortlist.h>

#include <QDebug>

void testing(){
    QTest::qExec(new test_sortList);
    QTest::qExec(new test_graham);
    QTest::qExec(new test_parseVertexList);
}

int main(int argc, char *argv[])
{
    if (argc == 1){
        testing();
    }
    else if (argc > 1){
        QString data;
        QList<Vertex> vl;
        QList<Vertex> poligon;
        if (readFile(argv[1], data)){
            if (parseVertexList(data, vl)){
                graham(vl, poligon);
                if (argc == 2){
                    if (!writeVertexList("OUT.TXT", poligon))
                        qDebug() << "Can not open file: OUT.TXT";
                }
                else {
                    if (!writeVertexList(argv[2], poligon))
                        qDebug() << "Can not open file: " << argv[2];
                }
            }
            qDebug() << "Invalid input data!";
        }
        qDebug() << "Can not open file: " << argv[1];
    }
    return 0;
}
