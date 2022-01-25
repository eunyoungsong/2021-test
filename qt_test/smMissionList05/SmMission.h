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