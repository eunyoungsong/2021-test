#include "SmMission.h"


SmMission::SmMission(const QString &title, const QString &path)
{
    _title = title;
    _path = path;
}

Q_INVOKABLE QString SmMission::title()
{
    return _title;
}
Q_INVOKABLE QString SmMission::path()
{
    return _path;
}


Q_INVOKABLE void SmMission::setTitle(QString title)
{
    _title = title;
}


Q_INVOKABLE void SmMission::setFilePath(QString path)
{
    _path = path;
}


Q_INVOKABLE void SmMission::read(const QJsonObject &json)
{
    if(json.contains("title") && json["title"].isString())
        _title = json["title"].toString();

    if(json.contains("path") && json["path"].isString())
        _path = json["path"].toString();
}

Q_INVOKABLE void SmMission::write(QJsonObject &json) const
{
    json["title"] = _title;
    json["path"] = _path;
}
