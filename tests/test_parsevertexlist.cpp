#include "test_parsevertexlist.h"

test_parseVertexList::test_parseVertexList(QObject *parent) : QObject(parent)
{

}

test_parseVertexList::~test_parseVertexList()
{

}

void test_parseVertexList::test_data()
{
    QList<Vertex> vl;
    Vertex v;
    QTest::addColumn<QString > ("s");
    QTest::addColumn<QList<Vertex> > ("vl");
    QTest::addColumn<bool> ("res");
    QTest::newRow("Пустая строка") << "" << vl << false;
    QTest::newRow("Cтрока содержит только одну введенную позицию") << "22.33 " << vl << false;
    QTest::newRow("Cтрока содержит посторонний символ") << "22.33 a22.1\n" << vl << false;
    v.first = 22.33;
    v.second = 22.1;
    vl.append(v);
    QTest::newRow("Верная строка обе координаты дробные") << "22.33 22.1\n" << vl << true;
    vl.clear();
    v.first = 2233;
    v.second = 22.1;
    vl.append(v);
    QTest::newRow("Верная строка одна координата целочисленная") << "2233 22.1\n" << vl << true;
    vl.clear();
    v.first = 2233;
    v.second = 1000;
    vl.append(v);
    QTest::newRow("Верная строка обе координаты целочисленные") << "2233 1000\n" << vl << true;
    v.first = 2233;
    v.second = 1.000;
    vl.append(v);
    v.first = 2233;
    v.second = 10200;
    vl.append(v);
    QTest::newRow("Несколько строк, все верные") << "2233 1000\n2233 1.000\n2233 10200\n" << vl << true;
    vl.clear();
    QTest::newRow("Несколько строк, все верные") << "2233 1000\n2233 1.000\nasd\n2233 10200\n" << vl << false;
}

void test_parseVertexList::test()
{
    QList<Vertex> resVl;
    QFETCH(QString, s);
    QFETCH(QList<Vertex>, vl);
    QFETCH(bool, res);
    QVERIFY2(parseVertexList(s, resVl) == res, "invalin ans");
    QVERIFY2(resVl == vl, "invalin ans");
}

