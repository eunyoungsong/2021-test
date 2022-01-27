#ifndef SMMISSIONMANAGER_H
#define SMMISSIONMANAGER_H

#include <QIODevice>
#include <QObject>
#include <QString>
#include <QtCore>
#include <QVector>

#include <iostream>
#include "qqmlfile.h"

#include "SmMission.h"

class SmMissionManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVector<SmMission>* missions READ getMissions)

public:
    Q_INVOKABLE void newList();
    Q_INVOKABLE void loadList();
    Q_INVOKABLE void saveList() const;

    Q_INVOKABLE void addList(QString &title, QString &path);
    //Q_INVOKABLE void deleteList(int row);

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

public:
    QVector<SmMission>* getMissions()
    {
        return &_missions;
    }

private:
    QVector<SmMission> _missions;

};

#endif // SMMISSIONMANAGER_H
