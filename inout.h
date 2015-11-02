/*!
 * \file
 * \brief Заголовочный файл с прототипами функций ввода, проверки и вывода данных
 */


//QT
#include <QString>
#include <QFile>
#include <QRegExp>

#include "global.h"

/*!
 * \brief readFile Считать файл в строку
 * \param file Имя файла
 * \param data Строка с содержимым файла
 * \return Удалось ли открыть файл?
 */
bool readFile(const QString &file, QString &data);
/*!
 * \brief writeVertexList Записать список координат в файл
 * \param file Имя фалйа
 * \param vl Список координат
 * \return Удалось ли открыть файл?
 */
bool writeVertexList(const QString &file, const QList < Vertex> &vl);
/*!
 * \brief parseVertexList Преобразовать строку в список координат
 * \param string Строка
 * \param vl Список координат
 * \return Удалось ли преобразовать?
 */
bool parseVertexList(const QString &string, QList <Vertex> &vl);
