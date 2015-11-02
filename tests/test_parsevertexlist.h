#ifndef TEST_PARSEVERTEXLIST_H
#define TEST_PARSEVERTEXLIST_H

#include <QObject>
#include <QTest>

#include "inout.h"

class test_parseVertexList : public QObject
{
    Q_OBJECT
public:
    explicit test_parseVertexList(QObject *parent = 0);
    ~test_parseVertexList();

signals:

private Q_SLOTS:
    void test_data();
    void test();
};

#endif // TEST_PARSEVERTEXLIST_H
