#ifndef SMMISSIONMANAGER_H
#define SMMISSIONMANAGER_H

#include <QIODevice>
#include <QObject>
#include <QString>
#include <QtCore>
#include <QVector>

#include <iostream>

#include "SmMission.h"

class SmMissionManager : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE void newList();
    Q_INVOKABLE void loadList(const QString &path);
    Q_INVOKABLE void saveList(QString &path) const;


    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

private:
    QVector<SmMission> _missions;

};

#endif // SMMISSIONMANAGER_H
