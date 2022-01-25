#include "jsoncontroller.h"

JsonController::JsonController() :
    m_title(),
    m_url() {
}
JsonController::~JsonController() {
}

QString JsonController::title()
{
    return m_title;
}
void JsonController::setTitle(QString &title)
{
    m_title = title;
}

QString JsonController::url()
{
    return m_url;
}
void JsonController::setUrl(QString &url)
{
    m_url = url;
}

void JsonController::read(const QJsonObject &json)
{
    if(json.contains("title") && json["title"].isString())
        m_title = json["title"].toString();

    if(json.contains("url") && json["url"].isString())
        m_url = json["url"].toString();
}
// QJsonObject::operator[] () 또는 QJsonObject ::value ()를 사용하여 JSON 객체 내의 값에 액세스
// 둘 다 const 함수이며 키가 유효하지 않으면 QJsonValue::Undefined 를 반환
// QJsonObject::contains () 로 키를 읽기 전에 키가 유효한지 확인


void JsonController::write(QJsonObject &json) const
{
    json["title"] = m_title;
    json["url"] = m_url;
}
// QJsonObject에 값을 설정하는 방법에는
// QJsonObject::operator[]() 와 QJsonObject::insert() 가 있음
// 둘 다 주어진 키의 기존 값을 무시한다.

