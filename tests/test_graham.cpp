#include "test_graham.h"

/*!
* \brief graham – Функция, проверяющая является ли частью препятствия данная позиция
* \param[in] allVertex – Список всех вершин
* \param[out] pos  – Вершины входящие в многоугольник
*/
//void graham(const QList < Vertex> &allVertex, QList < Vertex> &vl)


test_graham::test_graham(QObject *parent) : QObject(parent)
{

}

void test_graham::test_data()
{
    QList<Vertex> allVertexList;
    QList<Vertex> res;
    Vertex v;

    QTest::addColumn<QList<Vertex> > ("allVertexList");
    QTest::addColumn<QList<Vertex> > ("res");

    allVertexList.append(Vertex(0,0));
    allVertexList.append(Vertex(1,1));
    QTest::newRow("Переданы две точки") << allVertexList << res;

    allVertexList.clear();

    allVertexList.append(Vertex(0,0));
    allVertexList.append(Vertex(1,1));
    allVertexList.append(Vertex(2,1));

    res.append(Vertex(0,0));
    res.append(Vertex(2,1));
    res.append(Vertex(1,1));
    QTest::newRow("Переданы три точки") << allVertexList << res;

    allVertexList.clear();
    res.clear();

    allVertexList.append(Vertex(0,0));
    allVertexList.append(Vertex(4,0));
    allVertexList.append(Vertex(1,2));
    allVertexList.append(Vertex(3,2));
    allVertexList.append(Vertex(1,-2));
    allVertexList.append(Vertex(3,-2));

    res.append(Vertex(0,0));
    res.append(Vertex(1,-2));
    res.append(Vertex(3,-2));
    res.append(Vertex(4,0));
    res.append(Vertex(3,2));
    res.append(Vertex(1,2));
    QTest::newRow("Передано множество точек, все являются вершинами многоугольника") << allVertexList << res;

    allVertexList.clear();

    allVertexList.append(Vertex(0,0));
    allVertexList.append(Vertex(4,0));
    allVertexList.append(Vertex(2,5));
    res = allVertexList;
    allVertexList.append(Vertex(2,2));
    allVertexList.append(Vertex(2,3));
    allVertexList.append(Vertex(2,4));
    QTest::newRow("Передано множество точек, многоугольником будет треугольник") << allVertexList << res;

    allVertexList.clear();

}

void test_graham::test()
{
    QList<Vertex> resVl;
    QFETCH(QList<Vertex>, allVertexList);
    QFETCH(QList<Vertex>, res);
    graham(allVertexList, resVl);
    QVERIFY2(resVl == res, "invalin ans");
}

