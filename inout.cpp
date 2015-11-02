#include "inout.h"


bool readFile(const QString &file, QString &data)
{
    QFile f(file);
    if (f.open(QIODevice::ReadOnly)){
        data = f.readAll();
        f.close();
        return true;
    }
    return false;
}


bool writeVertexList(const QString &file, const QList<Vertex> &vl)
{
    QString data;
    QFile f(file);
    if (f.open(QIODevice::WriteOnly)){
        int len = vl.length();
        for (int i = 0; i < len; ++i){
            data += QString::number(vl[i].first) + " " + QString::number(vl[i].second) + "\n";
        }
        f.write(data.toLocal8Bit());
        f.close();
        return true;
    }
    return false;
}

bool parseVertexList(const QString &string, QList<Vertex> &vl)
{
    QRegExp s("(\\d+(\\.\\d+)?\\s\\d+(\\.\\d+)?\\n)+");
    if (!s.exactMatch(string))
        return false;

    int lastN = -1;
    int space;
    Vertex v;
    int lastIndexOf = string.lastIndexOf("\n");
    while (lastN != lastIndexOf){
        ++lastN;
        space = string.indexOf(" ", lastN);
        v.first = string.mid(lastN, space - lastN).toDouble();
        lastN = string.indexOf("\n", lastN);
        v.second = string.mid(space + 1, lastN - space - 1).toDouble();
        vl.append(v);
    }
    return true;
}
