#include "test_sortlist.h"

test_sortList::test_sortList(QObject *parent) : QObject(parent)
{

}

void test_sortList::test_data()
{
    QList<Vertex> allVertexList;
    QList<Vertex> res;
    Vertex v;

    QTest::addColumn<QList<Vertex> > ("allVertexList");
    QTest::addColumn<QList<Vertex> > ("res");

    allVertexList.append(Vertex(0,0));
    allVertexList.append(Vertex(4,0));
    allVertexList.append(Vertex(1,2));
    allVertexList.append(Vertex(3,2));
    allVertexList.append(Vertex(1,-2));
    allVertexList.append(Vertex(2,-2));

    res.append(Vertex(0,0));
    res.append(Vertex(1,-2));
    res.append(Vertex(2,-2));
    res.append(Vertex(4,0));
    res.append(Vertex(3,2));
    res.append(Vertex(1,2));
    QTest::newRow("Передан список из уникальных знаний") << allVertexList << res;

    allVertexList.clear();
    res.clear();

    allVertexList.append(Vertex(0,0));
    allVertexList.append(Vertex(4,0));
    allVertexList.append(Vertex(1,2));
    allVertexList.append(Vertex(3,2));
    allVertexList.append(Vertex(1,-2));
    allVertexList.append(Vertex(2,-2));
    allVertexList.append(Vertex(4,0));

    res.append(Vertex(0,0));
    res.append(Vertex(1,-2));
    res.append(Vertex(2,-2));
    res.append(Vertex(4,0));
    res.append(Vertex(4,0));
    res.append(Vertex(3,2));
    res.append(Vertex(1,2));
    QTest::newRow("переданный список содержит не уникальные значения") << allVertexList << res;

    allVertexList.clear();

}

void test_sortList::test()
{
    QFETCH(QList<Vertex>, allVertexList);
    QFETCH(QList<Vertex>, res);
    sortByLeftism(allVertexList);
    QVERIFY2(allVertexList == res, "invalin ans");
}
