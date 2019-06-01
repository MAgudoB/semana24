#ifndef QUERYROW_H
#define QUERYROW_H
#include "QObject"

class queryRow : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString row_Name READ getName WRITE setName NOTIFY rowChanged)
    Q_PROPERTY(int success READ getSuccess WRITE setSuccess NOTIFY rowChanged)
    Q_PROPERTY(int games READ getGames WRITE setGames NOTIFY rowChanged)
    Q_PROPERTY(int fails READ getFails WRITE setFails NOTIFY rowChanged)
public:
    void setName(const QString &a){
        row_name = a;
    }

    QString getName() const {
        return row_name;
    }

    void setSuccess(const int &s){
        success = s;
    }

    int getSuccess() const{
        return success;
    }

    void setGames(const int &g){
        success = g;
    }

    int getGames() const{
        return success;
    }

    void setFails(const int &f){
        success = f;
    }

    int getFails() const{
        return success;
    }

signals:
    void rowChanged();

private:
    QString row_name;
    int success;
    int fails;
    int games;

};


#endif // QUERYROW_H
