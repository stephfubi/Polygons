#ifndef TEST_SORTLIST_H
#define TEST_SORTLIST_H

#include <QObject>
#include <QTest>

#include "poligons.h"

class test_sortList : public QObject
{
    Q_OBJECT
public:
    explicit test_sortList(QObject *parent = 0);

signals:

private Q_SLOTS:
    void test_data();
    void test();
};

#endif // TEST_SORTLIST_H
