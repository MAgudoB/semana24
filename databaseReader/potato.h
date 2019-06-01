#ifndef POTATO_H
#define POTATO_H
#include "QObject"

class Potato : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged)
    public:
        void setAuthor(const QString &a) {
            if (a != m_author) {
                m_author = a;
                emit authorChanged();
            }
        }
        QString author() const {
            return m_author;
        }
    signals:
        void authorChanged();
    private:
        QString m_author;
};
#endif // POTATO_H
