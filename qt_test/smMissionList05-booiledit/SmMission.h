#ifndef SMMISSION_H
#define SMMISSION_H

#include <QJsonObject>
#include <QObject>
#include <QString>

class SmMission : public QObject
{
    //Q_GADGET
    Q_OBJECT

public:
    SmMission(QObject *parent = nullptr) {};
    SmMission(const SmMission& other)
    {
        _title = other._title;
        _filePath = other._filePath;
    };
    SmMission(const QString &title, const QString &path);

    Q_INVOKABLE QString title();
    Q_INVOKABLE QString filePath();


    Q_INVOKABLE void setTitle(QString title);
    Q_INVOKABLE void setFilePath(QString path);

    Q_INVOKABLE void read(const QJsonObject &json);
    Q_INVOKABLE void write(QJsonObject &json) const;

    SmMission& operator=(const SmMission& other)
    {
        _title = other._title;
        _filePath = other._filePath;
    }

private:
    QString _title;
    QString _filePath;

};

#endif // SMMISSION_H
