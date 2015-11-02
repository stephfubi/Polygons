/*!
 * \file
 * \brief Заголовочный файл содержащий прототипы функций необходимых для построения многоугольника
 */

//QT
#include <QList>

#include "global.h"

/*!
 * \brief graham Функция выделения наибольшего выпуклого многоугольника
 * \param allVertex Все точки
 * \param vl Вершины многоугольника
 */
void graham(QList<Vertex> &allVertex, QList<Vertex> &vl);
/*!
 * \brief getVectorProduct Фунция волучения векторного произведения
 * \param A Точка вектора <i>АВ</i>
 * \param B Точка вектора <i>АВ</i>
 * \param C Точка с которой строим векторное произведение
 * \return Значение
 */
double getVectorProduct(const Vertex &A, const Vertex &B, const Vertex &C);
/*!
 * \brief getLeftVertex Извлечь самую левую вершину из множество
 * \param vl Все верщины
 * \return Самая левая
 */
Vertex getLeftVertex(QList<Vertex> &vl);
/*!
 * \brief ​sortByLeftism​ - Отсортировать точки слева на право
 * \param vl - Список точек
 */
void sortList(QList<Vertex> &vl);
