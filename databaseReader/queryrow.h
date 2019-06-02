#ifndef QUERYROW_H
#define QUERYROW_H
#include "QObject"

class queryRow : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString row_Name READ getName WRITE setName NOTIFY rowChanged)
    Q_PROPERTY(qint32 success READ getSuccess WRITE setSuccess NOTIFY rowChanged)
    Q_PROPERTY(qint32 games READ getGames WRITE setGames NOTIFY rowChanged)
    Q_PROPERTY(qint32 fails READ getFails WRITE setFails NOTIFY rowChanged)
public:
    queryRow(QString, qint32,qint32,qint32);
    void setName(const QString &a);
    QString getName();
    void setSuccess(const qint32 &s);
    qint32 getSuccess();
    void setGames(const qint32 &g);
    qint32 getGames();
    void setFails(const qint32 &f);
    qint32 getFails();

signals:
    void rowChanged();

private:
    QString row_name;
    qint32 success;
    qint32 fails;
    qint32 games;
};


#endif // QUERYROW_H
