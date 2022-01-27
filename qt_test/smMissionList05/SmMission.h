#ifndef SMMISSION_H
#define SMMISSION_H

#include <QJsonObject>
#include <QObject>
#include <QString>

class SmMission : public QObject
{
    Q_OBJECT

public:
    SmMission(QObject *parent = nullptr) {};
    SmMission(const SmMission& other)
    {
        _title = other._title;
        _path = other._path;
    };
    SmMission(const QString &title, const QString &path);

    Q_INVOKABLE QString title();
    Q_INVOKABLE QString path();


    Q_INVOKABLE void setTitle(QString title);
    Q_INVOKABLE void setFilePath(QString path);

    Q_INVOKABLE void read(const QJsonObject &json);
    Q_INVOKABLE void write(QJsonObject &json) const;

    SmMission& operator=(const SmMission& other)
    {
        _title = other._title;
        _path = other._path;
    }

private:
    QString _title;
    QString _path;

};

#endif // SMMISSION_H
