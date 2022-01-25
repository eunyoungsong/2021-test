#ifndef SMMISSION_H
#define SMMISSION_H

#include <QJsonObject>
#include <QObject>
#include <QString>

class SmMission
{
    Q_GADGET;

public:
    SmMission();
    SmMission(const QString &title, const QString &path);

    Q_INVOKABLE QString title();
    Q_INVOKABLE QString filePath();


    Q_INVOKABLE void setTitle(QString title);
    Q_INVOKABLE void setFilePath(QString path);

    Q_INVOKABLE void read(const QJsonObject &json);
    Q_INVOKABLE void write(QJsonObject &json) const;

private:
    QString _title;
    QString _filePath;

};

#endif // SMMISSION_H
