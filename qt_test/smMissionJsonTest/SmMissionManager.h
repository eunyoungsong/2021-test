#ifndef SMMISSIONMANAGER_H
#define SMMISSIONMANAGER_H

#include <QString>
#include <QVector>
#include <QtCore>
#include <iostream>
#include <QIODevice>

#include "SmMission.h"

class SmMissionManager
{
public:
    SmMissionManager();
/*
    struct Mission
    {
        std::string title;
        std::string mission_path;
        Mission( std::string _title, std::string _mission_path )
        {
            title = _title;
            mission_path = _mission_path;
        }
    };
*/
    //QVector<Mission> missions();

    void newList();
    void loadList(const QString &path);
    void saveList(QString &path) const;


    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

private:
    QVector<SmMission> _missions;

};

#endif // SMMISSIONMANAGER_H
