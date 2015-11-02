#ifndef TEST_GRAHAM_H
#define TEST_GRAHAM_H

#include <QObject>
#include <QTest>

#include "poligons.h"

class test_graham : public QObject
{
    Q_OBJECT
public:
    explicit test_graham(QObject *parent = 0);

signals:

private Q_SLOTS:
    void test_data();
    void test();

};

#endif // TEST_GRAHAM_H
