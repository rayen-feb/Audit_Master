#include "entreprise.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDebug>
#include<QObject>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>

entreprise::entreprise()
{
    id=0 ;numero=0;nombree=0; nom=""; pays=""; ville="";adresse=""; email=""; domaine= ""; date="";

}
entreprise::entreprise (int id , QString nom ,QString  pays ,QString ville  ,QString adresse ,int  numero ,int nombree ,QString  email,QString domaine,QString date   ){ this->id=id; this->nom=nom ;this->pays=pays ; this->ville=ville;this->adresse=adresse; this->numero=numero ; this->nombree=nombree ; this->email=email ; this->domaine=domaine ; this->date = date ;}

int  entreprise::getid(){return id ; }
QString entreprise::getnom(){return nom;}
QString entreprise::getpays(){return pays; }
QString entreprise::getville() {return ville ; }
QString entreprise::getadresse(){return adresse;}
int entreprise::getnumero() {return numero ; }
int entreprise::getnombree() {return nombree;}
QString entreprise::getemail(){return email ; }
QString entreprise::getdomaine(){return domaine;}
QString entreprise::getdate(){return date; }
void entreprise::setid(int id ){this->id=id;  }
void entreprise::setnom(QString nom){this->nom=nom ; }
void entreprise::setville(QString ville){this->ville = ville ;}
void entreprise::setadresse(QString adresse) {this->adresse=adresse;}
void entreprise::setnumero(int numero ) {this->numero=numero ; }
void entreprise::setnombree(int nombree){this->nombree=nombree;}
void entreprise::setemail(QString email){this->email=email ; }
void entreprise::setdomaine(QString domaine){this->domaine = domaine ; }
void entreprise::setdate(QString date) {this->date=date;}
bool entreprise::ajouter()
{


       QSqlQuery query;
         query.prepare("insert into ENTREPRISE (ID, NOM, PAYS , VILLE , ADRESSE,NUMERO,NOMBRE_EMPLOYEES,EMAIL,DOMAINE,DATE_FONDATION) "
                       "values (:id, :nom, :pays ,:ville , :adresse,:numero,:nombre_employees,:email,:domaine,:date_fondation)");

         query.bindValue(":id",id);
         query.bindValue(":nom",nom);
         query.bindValue(":pays",pays);
         query.bindValue(":ville",ville);
         query.bindValue(":adresse",adresse);
         query.bindValue(":numero",numero);
         query.bindValue(":nombre_employees",nombree);
         query.bindValue(":email",email);
         query.bindValue(":domaine",domaine);
         query.bindValue(":date_fondation", date);




         return query.exec();

}
QSqlQueryModel* entreprise::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT*  FROM ENTREPRISE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYS"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMERO"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("NOMBRE_EMPLOYEES"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("DOMAINE"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("DATE_FONDATION"));

    return model ;
}
bool entreprise::supprimer(int id)
{
    QSqlQuery query;
      query.prepare("Delete from  ENTREPRISE where id=:id");

      query.bindValue(0, id);
      query.bindValue(1, nom);
      query.bindValue(2, pays);
      query.bindValue(3, ville);
      query.bindValue(4, adresse);
      query.bindValue(5, numero);
      query.bindValue(6, nombree);
      query.bindValue(7,email );
      query.bindValue(8,domaine);
      query.bindValue(9, date);
      return query.exec();





}
bool entreprise::modifier(){
    QSqlQuery query;
    query.prepare("UPDATE ENTREPRISE SET ID=:id, NOM=:nom,PAYS=:pays,VILLE=:ville,ADRESSE=:adresse,NUMERO=:numero,NOMBRE_EMPLOYEES=:nombree,EMAIL=:email,DOMAINE=:domaine,DATE_FONDATION=:date"
                  "WHERE ID=:id ");
        query.bindValue(":ID", id);
       query.bindValue(":NOM", nom);
       query.bindValue(":PAYS", pays);
       query.bindValue(":VILLE", ville);
       query.bindValue(":ADRESSE", adresse);
       query.bindValue(":NUMERO", numero);
       query.bindValue(":NOMBRE_EMPLOYEES", nombree);
       query.bindValue(":EMAIL",email );
       query.bindValue(":DOMAINE",domaine);
       query.bindValue(":DATE_FONDATION", date);

       return query.exec();


}
QSqlQueryModel * entreprise::recherche(int a)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString c=QString::number(a);
    model->setQuery("select * from ENTREPRISE where id="+c);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYS"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMERO"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("NOMBRE_EMPLOYEES"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("DOMAINE"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("DATE_FONDATION"));


    return(model);
}



QSqlQueryModel * entreprise::recherche(const QString &rech)
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Entreprise where (ID LIKE '"+rech+"%' OR NOM LIKE '"+rech+"%' OR PAYS LIKE '"+rech+"%' OR VILLE LIKE '"+rech+"%' OR ADRESSE LIKE '"+rech+"%' OR  NUMERO LIKE '"+rech+"%' OR NOMBRE_EMPLOYEES LIKE '"+rech+"%' OR EMAIL  LIKE '"+rech+"%' OR DOMAINE  LIKE '"+rech+"%' OR DATE_FONDATION LIKE '"+rech+"%' ) ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("NOMBRE_EMPLOYEES"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("DOMAINE"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("DATE_FONDATION"));
return model;
}

QSqlQueryModel *entreprise::afficherup_nom()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM ENTREPRISE  ORDER BY NOM ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("NOMBRE_EMPLOYEES"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("DOMAINE"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("DATE_FONDATION"));

return model;
}
QSqlQueryModel * entreprise::afficherdown_nom()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM ENTREPRISE ORDER BY NOM DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("NOMBRE_EMPLOYEES"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("DOMAINE"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("DATE_FONDATION"));
return model;
}
QSqlQueryModel *entreprise::afficherup_pays()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM ENTREPRISE  ORDER BY PAYS ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("NOMBRE_EMPLOYEES"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("DOMAINE"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("DATE_FONDATION"));

return model;
}
QSqlQueryModel *entreprise::afficherup_date()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM ENTREPRISE  ORDER BY DATE_FONDATION ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("NOMBRE_EMPLOYEES"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("DOMAINE"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("DATE_FONDATION"));

return model;
}
QSqlQueryModel * entreprise::afficherdown_pays()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM ENTREPRISE ORDER BY PAYS DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("NOMBRE_EMPLOYEES"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("DOMAINE"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("DATE_FONDATION"));
return model;
}

QSqlQueryModel * entreprise::afficherup_nombree()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM ENTREPRISE ORDER BY NOMBRE_EMPLOYEES ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PAYS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("VILLE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMERO"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("NOMBRE_EMPLOYEES"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("DOMAINE"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("DATE_FONDATION"));
return model;
}

QSqlQueryModel * entreprise::afficherdown_nombree()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM  ENTREPRISE ORDER BY NOMBRE_EMPLOYEES DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
return model;}


QSqlQueryModel * entreprise::trier_nom_a()//asc
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM ENTREPRISE\
                         ORDER BY NOM ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

    return model;
}
QSqlQueryModel * entreprise::trier_nom_d()//desc
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM ENTREPRISE\
                         ORDER BY NOM DESC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

    return model;
}
int entreprise::calculer(int  operateur) {
  QSqlQuery query;
  query.prepare("select * from ENTREPRISE where operateur =:operateur");
  query.bindValue(":operateur", operateur);

  query.exec();
  int total = 0;
  while (query.next()) {
    total++;
  }

  return total;
}
int  entreprise::calculernombre()
{
    QSqlQuery query("SELECT * FROM  ENTREPRISE ");
    int rowCount = 0;

       // Check if the query is valid
       if (query.isActive()) {
           // Iterate through the result set
           while (query.next()) {
               rowCount++; }
      return rowCount;}}


























