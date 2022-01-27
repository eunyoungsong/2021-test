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
    _missions.clear();
    _missions.reserve(2);

    SmMission smMission01("A-mission", "aaa/aaa/aaa");
    _missions.append(smMission01);

    SmMission smMission02("B-mission", "bbb/bbb/bbb");
    _missions.append(smMission02);

}


void SmMissionManager::loadList(const QString &path)
{
    QFile loadFile( path );

    if (!loadFile.open(QIODevice::ReadOnly)) {   // 파일을 열 수 없으면 경고
        qWarning("Couldn't open save file.");
        //return false;
        return;
    }

    QByteArray saveData = loadFile.readAll();
    loadFile.close();

    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

    read(loadDoc.object());

}


void SmMissionManager::saveList(QString &path) const
{
    QFile saveFile(path);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }

    QJsonObject missionObject;
    write(missionObject);
    saveFile.write(QJsonDocument(missionObject).toJson());
}



void SmMissionManager::read(const QJsonObject &json)
{
    if(json.contains("missions") && json["missions"].isObject()) {
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
}



void SmMissionManager::write(QJsonObject &json) const
{
    QJsonArray missionArray;
    for (const SmMission &mission : _missions) {
        QJsonObject missionObject;
        mission.write(missionObject);
        missionArray.append(missionObject);
    }
    json["missions"] = missionArray;
}
