#include "queryrow.h"

queryRow::queryRow(QString rowName, qint32 success,qint32 games,qint32 fails){
    this->row_name = rowName;
    this->success = success;
    this->games = games;
    this->fails = fails;
}

void queryRow::setName(const QString &a){
    row_name = a;
}

QString queryRow::getName()  {
    return row_name;
}

void queryRow::setSuccess(const qint32 &s){
    success = s;
}

qint32 queryRow::getSuccess() {
    return success;
}


void queryRow::setGames(const qint32 &g){
    games = g;
}

qint32 queryRow::getGames(){
    return games;
}

void queryRow::setFails(const qint32 &f){
    fails = f;
}

qint32 queryRow::getFails(){
    return fails;
}
