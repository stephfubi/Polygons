#include "poligons.h"


void graham(QList<Vertex> &allVertex, QList<Vertex> &vl)
{
    if (allVertex.length() < 3) // Вырожденная ситуация. Недостаточно длинный список
        return;

    sortList(allVertex);

    vl.append(allVertex[0]);
    vl.append(allVertex[1]);

    int len = allVertex.length();
    for (int i = 2; i < len; ++i){
        while(getVectorProduct(vl[vl.length() - 2], vl[vl.length() - 1], allVertex[i]) < 0){
            vl.pop_back();
        }
        vl.append(allVertex[i]);
    }
}


double getVectorProduct(const Vertex &A, const Vertex &B, const Vertex &C)
{
    return (B.first - A.first)*(C.second - A.second) - (B.second - A.second)*(C.first - A.first);
}


Vertex getLeftVertex(QList<Vertex> &vl)
{
    if (vl.isEmpty()) // Вырожденная ситуация. Пустой список
        return Vertex();

    int min = 0;
    int len = vl.length();
    for (int i = 1; i < len; ++i){
        if (vl[i].first < vl[min].first)
            min = i;
    }
    return vl.takeAt(min);
}

void sortList(QList<Vertex> &vl)
{
    if (vl.isEmpty()) // Вырожденная ситуация. Пустой список
        return;

    vl.push_front(getLeftVertex(vl));

    Vertex tmp;
    int len = vl.length();
    for (int i = 1; i < len; ++i){
        for (int j = i + 1; j < len; ++j){
            if (getVectorProduct(vl[0], vl[i], vl[j]) < 0){
                tmp = vl[i];
                vl[i] = vl[j];
                vl[j] = tmp;
            }
        }
    }
}
