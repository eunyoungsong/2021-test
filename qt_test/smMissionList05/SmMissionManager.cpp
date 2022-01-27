#include "SmMissionManager.h"

/*
 * < QJSON 사용법 >
 * 1. json 에 들어갈 내용 개체 생성해주기
 * 2. QJsonObject 생성하기
 * 3. QJsonObject 에 내용 개체 값 삽입
 * 4. QJsonDocument 에 QJsonObject 저장하기
 * 5. QFile 에 QJsonDocument 내용 쓰기
 * 6. Read 함수를 생성하여 QFile (.json) 내용 읽기
 *
 */


void SmMissionManager::newList()
{
    qDebug("eunyoung : Create new list.");

    _missions.clear();
    _missions.reserve(3); // reserve : 최소한 크기의 요소에 대한 메모리 할당을 시도, int 또는 double 과 같은 유형의 경우에는 resize()가 더 빠름

    SmMission smMission01("A-mission", "/home/eunyoung/aaa");
    _missions.append(smMission01);

    SmMission smMission02("B-mission", "/home/eunyoung/bbb");
    _missions.append(smMission02);

    SmMission smMission03("C-mission", "/home/eunyoung/ccc");
    _missions.append(smMission03);

}

const static char saveFileUrl[] = "/home/eunyoung/.config/smMission/smMissionList.json";

void SmMissionManager::loadList()
{

//    if(QFile::exists(url) == false) {                               // 파일이 없으면
//        qDebug("eunyoung : The file does not exist.");
//        newList();
//        saveList(url);
//    }
//    else {                                                                        // 파일이 있으면
//        qDebug("eunyoung : The file exist.");

        QFile loadFile(saveFileUrl);
        if (!loadFile.open(QIODevice::ReadOnly)) {
            qWarning("eunyoung : Couldn't open load file.");
            return;
        }

        QByteArray saveData = loadFile.readAll();
        loadFile.close();

        QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

        read(loadDoc.object());

//    }

}


void SmMissionManager::saveList() const
{
    QFile saveFile(saveFileUrl);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("eunyoung : Couldn't open save file.");
        return;
    }

    QJsonObject missionObject;
    write(missionObject);
    saveFile.write(QJsonDocument(missionObject).toJson());
}


void SmMissionManager::addList(QString &title, QString &path)
{
//    SmMission smMission(title, path);
//    _missions.append(smMission);
//    //saveList(saveFileUrl);
    // 수정중
}

//void SmMissionManager::deleteList(int row)
//{

//}



void SmMissionManager::read(const QJsonObject &json)
{
    if(json.contains("missions")) {
        qDebug("eunyoung : read JSON");

        QJsonArray missionArray = json["missions"].toArray();
        _missions.clear();
        _missions.reserve(missionArray.size());

        for(int index=0; index<missionArray.size(); ++index) {
            QJsonObject missionObject = missionArray[index].toObject();
            SmMission mission;
            mission.read(missionObject);
            _missions.append(mission);
        }
    }
    else {
        qWarning("eunyoung : Couldn't read JSON.");
    }
}



void SmMissionManager::write(QJsonObject &json) const
{
    qDebug("eunyoung : write JSON");
    QJsonArray missionArray;
    for (const SmMission &mission : _missions) {
        QJsonObject missionObject;
        mission.write(missionObject);
        missionArray.append(missionObject);
    }
    json["missions"] = missionArray;
}



