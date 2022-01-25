#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "SmMissionManager.h"


int main()
{
    QString path = "/home/eunyoung/.config/smMission/smMissionJsonTest.json";
    SmMissionManager manager;    
    manager.newList();
    manager.loadList(path);
    manager.saveList(path);
    return 0;
}
