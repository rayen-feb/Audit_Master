#ifndef NORMES_H
#define NORMES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QDate>
#include <QDebug>
#include "QDataStream"
#include <QtDebug>

class Normes
{
public:
    Normes();
    Normes(int,QString,QString,QString,QString);
    QString getNom() ;
    QString getDes() ;
    QString getdate_n() ;
    QString getconformite() ;
    int getId() ;
    void setId(int );
    void setNom( QString ) ;
    void setDes( QString ) ;
    void setdate_n( QString ) ;
    void setconformite( QString ) ;
    bool ajouter();
    QSqlQueryModel* afficher();
    bool  supprimer (int);
    bool estDejaSupprime(int id);
    bool modifier();
    QSqlQueryModel * tri();
    QSqlQueryModel  * recherche(QString );
    QJsonObject toJsonObject() const;
        static bool saveNormesHistoryToFile(const QString &filePath);
        static QVector<Normes> NormesHistory;
        int getID() const;
            QString getAction() const;
            QDateTime getDateTime() const;
            QString getDetails() const;
            int generateUniqueID();



private:
    int id;
    QString nom,des,date_n,conformite;
    QString action,details;
    QDateTime date;
    int ID;
    static int lastGeneratedID ;


};

#endif // NORMES_H
