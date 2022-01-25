#ifndef JSONCONTROLLER_H
#define JSONCONTROLLER_H

#include <QFile>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

class JsonController : public QObject
{
    Q_OBJECT

public:
    JsonController();
    ~JsonController();

    QString title();
    void setTitle(QString &title);

    QString url();
    void setUrl(QString &url);

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

private:
    QString m_title;
    QString m_url;
};

#endif // JSONCONTROLLERR_H
