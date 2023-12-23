#include "menu.h"
#include"connection.h"
#include"smtp.h"
#include "ui_menu.h"
#include "qrcode.h"
#include "qrwidget.h"
#include"arduino.h"
#include"entreprise.h"
#include "qrcodegeneratorworker.h"
#include <QPixmap>
#include"QRgb"
#include <QPainter>
#include <QFileDialog>
#include<QWidget>
#include"QMessageBox"
#include <QSystemTrayIcon>
#include<QTextDocument>
#include<QTextStream>
#include <qtableview.h>
#include<QtPrintSupport/QPrintDialog>
#include"QFileDialog"
#include <QUrl>
#include<QTextDocument>
#include<QTextStream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <QIntValidator>
#include <QDate>
#include <QString>
#include <QComboBox>
#include <QSqlQuery>
#include <QSqlRecord>
#include <ostream>
#include <QMessageBox>
#include <QTextEdit>
#include <QIntValidator>
#include<QWidget>
#include <QTextDocument>
#include <windows.h>
#include <QTextStream>
#include <QRadioButton>
#include <string>
#include <QtSvg/QSvgRenderer>
#include<QDirModel>
#include <QtPrintSupport/QAbstractPrintDialog>
#include<QDirModel>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <string>



menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    E.calculernombre();

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(5);
     //controle de saisie
    ui->lineEdit_id->setValidator((new QIntValidator(100,9999,this)));
    ui->lineEdit_nbree->setValidator((new QIntValidator(1,100000,this)));
    ui->lineEdit_numero->setValidator((new QIntValidator(00000000,999999999,this)));
    ui->lineEdit_id_modifier->setValidator((new QIntValidator(100,9999,this)));
       ui->lineEdit_nbree_mod->setValidator((new QIntValidator(0,100000,this)));
       ui->lineEdit_numero_mod->setValidator((new QIntValidator(00000000,999999999,this)));


       //// arduino  connection

       int ret=Ard.connect_arduino();
       switch(ret){
       case(0):qDebug()<<"arduino is available and connected to: "<< Ard.getarduino_port_name();
       break;
       case(1):qDebug()<<"arduino is available but not connected to "<< Ard.getarduino_port_name();
       break;
       case(-1):qDebug()<<"arduino is not available ";
       }
       QObject::connect(Ard.getserial(),SIGNAL(readyRead()),this,SLOT(inputard()));

       outputard();
       inputard();





      QSqlQuery qry,q2;
       qry.prepare("select NOM  from ENTREPRISE");
       qry.exec();
       ui->customPlot->legend->setVisible(true);
       ui->customPlot->legend->setFont(QFont("Helvetica",9));
       // set locale to english, so we get english decimal separator:
       ui->customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
       // add confidence band graphs:
       ui->customPlot->addGraph();
       QPen pen;
       pen.setStyle(Qt::DashLine);
       pen.setWidth(2);
       pen.setColor(Qt::red);
       ui->customPlot->graph(0)->setPen(pen);
       ui->customPlot->graph(0)->setName("Nombre d'employees");
       // add theory curve graph:
      // ui->customPlot->graph(1)->setName("identifiant");
       // add error bars:
       QCPErrorBars *errorBars = new QCPErrorBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
       errorBars->removeFromLegend();
       errorBars->setAntialiased(false);
       errorBars->setPen(QPen(QColor(180,180,180)));

       QVector<double>  y1(50), y1err(50), x1(50);
       for (int i=0; i<6; ++i)
       {
         x1[i]=i;
         if(qry.next())
         y1[i]=qry.value(0).toInt();
       }
       // pass data to graphs and let Qui->customPlot determine the axes ranges so the whole thing is visible:
       ui->customPlot->graph(0)->setData(x1, y1);
       ui->customPlot->graph(0)->rescaleAxes(true);
       // setup look of bottom tick labels:
       ui->customPlot->xAxis->setTickLabelRotation(30);
       ui->customPlot->xAxis->ticker()->setTickCount(6);
       // make top right axes clones of bottom left axes. Looks prettier:
       ui->customPlot->axisRect()->setupFullAxesBox();
}
void envoyerNombreVersArduino(int nombre, QSerialPort& serialPort) {
    QByteArray byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream << nombre;


    serialPort.write(byteArray);
      serialPort.waitForBytesWritten();
      // Vous pouvez également fermer la connexion série si nécessaire
      // serialPort.close();
  }


menu::~menu()
{
    delete ui;

}

// icone
void menu::notif(QString t,QString m)
{
    QPixmap p(32,32);
    p.load("C:/Users/SOSORDINATEUR/Pictures/icon.jpg");
    QIcon icon(p);
    QSystemTrayIcon n(icon);
    n.setVisible(true);
    n.showMessage(t,m,QSystemTrayIcon::Information,1000);

}
void menu::on_pushButton_chercher_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
     ui->table_recherche->setModel(E.afficher());
}

void menu::on_pushButton_ajout_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu::on_pushButton_afficher_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->tableview_afficher->setModel(E.afficher());

}

void menu::on_pushButton_supprimer_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->table_suppression->setModel(E.afficher());


}

void menu::on_pushButton_modifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);}








void menu::on_confirme_ajout_accepted()
{

    int id =ui->lineEdit_id->text().toInt();
    QString nom =ui->lineEdit_nom->text();
    QString pays=ui->lineEdit_pays->text();
    QString ville=ui->lineEdit_ville->text();
    QString adresse=ui->lineEdit_adreese->text();
    QString date=ui->lineEdit_date->text();
    QString email=ui->lineEdit_email->text();
    int nombree=ui->lineEdit_nbree->text().toInt();
    int  numero=ui->lineEdit_numero->text().toInt();
    QString domaine=ui->lineEdit_domaine->text();
    entreprise E(id , nom , pays , ville , adresse ,numero,nombree, email, domaine,date ) ;


    bool test=E.ajouter();
            if(test){
                Ard.write_to_arduino(E.calculernombre());
    QMessageBox::information(nullptr,QObject::tr(" OK"),
                   QObject::tr("ajout effectuee\n"
             "click cancel to exit "),QMessageBox::Cancel);
    //ard
     //Ard.write_to_arduino("1");
            }
         else
                QMessageBox::critical(nullptr,QObject::tr(" NOT OK "),
                                      QObject::tr("ajout non effectuee\n"
                                                  "click cancel to exit"),QMessageBox::Cancel);
      // Ard.write_to_arduino("0");


}

void menu::on_pushButton_clicked()
{

    int iden=ui->lineEdit_id->text().toInt();
    ui->table_recherche->setModel(E.recherche(iden));

}

void menu::on_confirme_supression_clicked()
{

     ui->table_suppression->setModel(E.afficher());
    E.setid(ui->lineEdit_suppression->text().toInt());

    bool test=E.supprimer(E.getid());
    //int n=E.calculer(E.getid());
    ui->table_suppression->setModel(E.afficher());
    //bool test1=E.recherche(E.getid());
    QMessageBox msg ;
    if(test  ){ Ard.write_to_arduino(E.calculernombre());
        msg.setText("suppression avec succees");}
    else
        msg.setText(("echec de suppression "));
    msg.exec();
}

void menu::on_pushButton_2_clicked()
{
    QString nm =ui->li_recherche->text();
    ui->tableview_afficher->setModel((E.recherche(nm)));

}


void menu::on_commandLinkButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void menu::on_checkBox_nomup_clicked()
{
     ui->tableview_afficher->setModel(E.afficherup_nom());
}

void menu::on_checkBox_nomdown_clicked()
{
    ui->tableview_afficher->setModel(E.afficherdown_nom());
}

void menu::on_checkBox_pays_up_clicked()
{
    ui->tableview_afficher->setModel(E.afficherup_pays());
}

void menu::on_checkBox_pays_down_clicked()
{
    ui->tableview_afficher->setModel(E.afficherdown_pays());
}

void menu::on_checkBox_nombre_up_clicked()
{
     ui->tableview_afficher->setModel(E.afficherup_nombree());
}

void menu::on_checkBox_date_clicked()
{
    ui->tableview_afficher->setModel(E.afficherup_date());

}

void menu::on_commandLinkButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void menu::on_commandLinkButton_4_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void menu::on_confirme_recherche_clicked()
{
    int iden=ui->lineEdit_id_chercher->text().toInt();
       ui->table_recherche->setModel(E.recherche(iden));

}
////////////////////////////
void menu::on_pushButton_confirmer_rechercher_clicked()
{
    int iden=ui->lineEdit_id_chercher->text().toInt();
       ui->table_recherche->setModel(E.recherche(iden));
}

void menu::on_confirme_ajout_rejected()
{
    ui->stackedWidget->setCurrentIndex(5);
}





void menu::on_triNM_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
       if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("liste_ENTREPRISES.pdf"); }

       QPrinter printer;
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       printer.setOutputFileName(fileName);

       QTextDocument doc;
       QSqlQuery q;
       q.prepare("SELECT * FROM ENTREPRISE ");
       q.exec();
       QString pdf="<br> <img src='C:/Users/SOSORDINATEUR/Desktop/Smart_wedding_reception_2A8-master/Smart_wedding_reception_2A8-master/image/pdf.png' height='239' width='211'/> <h1  style='color:red'>       LISTE DES ENTREPRISES  <br></h1>\n <br> <table>  <tr>  <th> ID </th> <th> NOM </th> <th> PAYS </th> <th> VILLE  </th> <th> ADRESSE </th><th> NUMERO </th> <th> NOMBRE_EMPLOYEES </th> <th> EMAIL </th>  <th> DOMAINE </th>  <th> DATE_FONDATION </th>  </tr>" ;
      /* QString pdf="<br> <img src='C:/Users/wissa/OneDrive/Bureau/projet/logo.png' height='42' width='144'/> <h1  style='color:red'>       LISTE DES GRAPHISTES  <br></h1>\n <br> <table>  <tr>  <th> ID </th> <th> NOM </th> <th> PRENOM </th> <th> TEL  </th> <th> E-MAIL </th>  </tr>" ;
      */

       while ( q.next()) {

           pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>" + q.value(1).toString() +"</td>  <td>" +q.value(2).toString() +"</td>      <td>     "+q.value(3).toString()+"</td>       <td>    "+q.value(4).toString()+"</td>       <td>    "+q.value(5).toString()+"</td>       <td>    "+q.value(6).toString()+"</td>       <td>    "+q.value(7).toString()+"</td>       <td>    "+q.value(8).toString()+"</td>       <td>    "+q.value(9).toString()+"</td>       <td>    "+q.value(10).toString()   +  "</td>" ;

       }
       doc.setHtml(pdf);
       doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
       doc.print(&printer);

      /* QPropertyAnimation *animation;
       animation = new QPropertyAnimation(ui->exporterpdf_photographe,"geometry");
       animation->setDuration(1000);
       animation->setStartValue(QRect(390,290,91,23));
       animation->setEndValue(QRect(390,290,150,23));
       animation->setEasingCurve(QEasingCurve::InOutQuint);
       animation->start();*/

}





void menu::on_confirme_ajout_2_rejected()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void menu::on_confirme_modifier_accepted()
{

    int id =ui->lineEdit_id_modifier->text().toInt();
     QString nom =ui->lineEdit_nom_mod->text();
     QString pays=ui->lineEdit_pays_mod->text();
     QString ville=ui->lineEdit_ville_mod->text();
     QString adresse=ui->lineEdit_adreese_mod->text();
     QString date=ui->lineEdit_date_mod->text();
     QString email=ui->lineEdit_email_mod->text();
     int nombree=ui->lineEdit_nbree_mod->text().toInt();
     int  numero=ui->lineEdit_numero_mod->text().toInt();
     QString domaine=ui->lineEdit_domaine_mod->text();
     entreprise E(id , nom , pays , ville , adresse ,numero,nombree, email, domaine,date ) ;

      //E.modifier(id);

    bool test=E.modifier();
            if(test || !test){
     QMessageBox::information(nullptr,QObject::tr(" OK"),
                    QObject::tr("modification  effectuee\n"
              "click cancel to exit "),QMessageBox::Cancel);}
         /* else
                QMessageBox::critical(nullptr,QObject::tr(" NOT OK "),
                                    QObject::tr("modification non effectuee\n"
                                                  "click cancel to exit"),QMessageBox::Cancel);*/}




void menu::on_triNM_2_clicked()
{
    int  Code=ui->lineEdit_id_chercher->text().toInt();
    E.recherche(Code);


    const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(std::to_string(Code).c_str(), qrcodegen::QrCode::Ecc::LOW);
   //const qrcodegen::QrCode qr1 = qrcodegen::QrCode::encodeText(p, qrcodegen::QrCode::Ecc::LOW);
    std::ofstream myfile;
    myfile.open ("qrcode.svg") ;
    myfile << qr.toSvgString(1);
    myfile.close();
    QSvgRenderer svgRenderer(QString("qrcode.svg"));
    QPixmap pix( QSize(150, 150));
    QPainter pixPainter( &pix );
    svgRenderer.render(&pixPainter);
    ui->QR_aff_5->setPixmap(pix);
}

void menu::on_triNM_3_clicked()
{

    int id =ui->lineEdit_id->text().toInt();
    QString nom =ui->lineEdit_nom->text();
    QString pays=ui->lineEdit_pays->text();
    QString ville=ui->lineEdit_ville->text();
    QString adresse=ui->lineEdit_adreese->text();
    QString date=ui->lineEdit_date->text();
    QString email=ui->lineEdit_email->text();
    int nombree=ui->lineEdit_nbree->text().toInt();
    int  numero=ui->lineEdit_numero->text().toInt();
    QString domaine=ui->lineEdit_domaine->text();
  //  entreprise E(id , nom , pays , ville , adresse ,numero,nombree, email, domaine,date ) ;
    const char * id1=std::to_string(id).c_str();
    const char * nombree1=std::to_string(nombree).c_str();
    const char * numero1=std::to_string(numero).c_str();




    QString str ="nom :  "+nom +"\n"+"identifiant  :"+id1+"\n"+"pays  :"+pays+"\n"+"ville  :"+ville+"\n"+"adresse  :"+adresse+"\n"+"email : "+email+"\n"+"doamine  : "+domaine+"\n"+"nombre   : "+nombree1+"\n"+"date   :"+date+"\n"+"numero  :"+numero1;
    std::string stra = str.toStdString();
    const char* p = stra.c_str();

   // const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(std::to_string(Code).c_str(), qrcodegen::QrCode::Ecc::LOW);
   const qrcodegen::QrCode qr1 = qrcodegen::QrCode::encodeText(p, qrcodegen::QrCode::Ecc::LOW);
    std::ofstream myfile;
    myfile.open ("qrcode.svg") ;
    myfile << qr1.toSvgString(1);
    myfile.close();
    QSvgRenderer svgRenderer(QString("qrcode.svg"));
    QPixmap pix( QSize(200, 200));
    QPainter pixPainter( &pix );
    svgRenderer.render(&pixPainter);
    ui->QR_aff_6->setPixmap(pix);
      qint32 sz = qr1.getSize();
        QImage im(sz, sz, QImage::Format_RGB32);
       // QRgb black = qRgb(191, 112, 105);
        //QRgb white = qRgb(255, 255, 255);

     //   for (int y = 0; y < sz; y++) {
         //   for (int x = 0; x < sz; x++) {
                //im.setPixel(x, y, qr1.getModule(x, y) ? black : white);
          //  }
       // }

       // ui->qrcodecommande->setPixmap(QPixmap::fromImage(im.scaled(200, 200, Qt::KeepAspectRatio, Qt::FastTransformation), Qt::MonoOnly));

            QString folderPath = "C:/Users/SOSORDINATEUR/Desktop/qrcode"; // Specify the desired folder path

               // Create the folder if it doesn't exist
               QDir folderDir(folderPath);
               if (!folderDir.exists()) {
                   folderDir.mkpath(".");
               }

               QString filePath = folderPath  + ".png"; // Use the matricule as the file name
               im.save(filePath);
}



void menu::on_pushButton_statistiques_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

    QTableView table_necessiteux,table_n2;
             QSqlQueryModel * Mod=new  QSqlQueryModel();
             QSqlQueryModel * Mod2=new  QSqlQueryModel();
                 // connexion c;
                  QSqlQuery qry,q2;
                  qry.prepare("select  NOMBRE_EMPLOYEES from ENTREPRISE group by NOMBRE_EMPLOYEES");
                  qry.exec();
                  Mod->setQuery(qry);
                  table_necessiteux.setModel(Mod);

                  q2.prepare("select COUNT(NOMBRE_EMPLOYEES) from Entreprise group by NOMBRE_EMPLOYEES");
                  q2.exec();
                  Mod2->setQuery(q2);
                  table_n2.setModel(Mod2);


                  const int rowCount = table_necessiteux.model()->rowCount();
                  const int rowCount2 = table_n2.model()->rowCount();
                 qDebug()<<table_necessiteux.model()->data(table_necessiteux.model()->index(0, 0)).toString().simplified();
                 qDebug()<<table_n2.model()->data(table_n2.model()->index(0, 0)).toInt();
    QCPStatisticalBox *statistical = new QCPStatisticalBox(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QBrush boxBrush(QColor(60, 60, 255, 100));
    boxBrush.setStyle(Qt::Dense6Pattern); // make it look oldschool
    statistical->setBrush(boxBrush);

    // specify data:
    QCPBars *besoin = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);

                     besoin->setAntialiased(false); // gives more crisp, pixel aligned bar borders

                     besoin->setStackingGap(1);

    // prepare manual x axis labels:
          QVector<double> ticks;
                 QVector<QString> labels;


                   for(int i=0; i<rowCount; ++i){
                                         ticks.push_back(i);
                                         labels.push_back(table_necessiteux.model()->data(table_necessiteux.model()->index(i, 0)).toString().simplified());
                                         qDebug()<<ticks[i];
                                         qDebug()<<labels[i];
                                     }
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0,4);
    ui->customPlot->xAxis->setTickLabelRotation(20);
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
                     ui->customPlot->xAxis->setTicker(textTicker);
                     ui->customPlot->xAxis->setTickLabelRotation(60);
                     ui->customPlot->xAxis->setSubTicks(false);
                     ui->customPlot->xAxis->setTickLength(0, 5);
                     ui->customPlot->xAxis->setRange(0, 8);
                     ui->customPlot->xAxis->setBasePen(QPen(Qt::black));
                     ui->customPlot->xAxis->setTickPen(QPen(Qt::black));
                     ui->customPlot->xAxis->grid()->setVisible(true);
                     ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
                     ui->customPlot->xAxis->setTickLabelColor(Qt::black);
                     ui->customPlot->xAxis->setLabelColor(Qt::black);
                     ui->customPlot->xAxis->setTicker(textTicker);
    // prepare axes:
    ui->customPlot->xAxis->setLabel(QString::fromUtf8("Nombre de employees"));
    // ui->customPlot->xAxis->setLabel(QString::fromUtf8(""));
    ui->customPlot->rescaleAxes();
    ui->customPlot->xAxis->scaleRange(1.7, ui->customPlot->xAxis->range().center());
    ui->customPlot->yAxis->setRange(0,1);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);





    QVector<double>besoinData;

                     for(int i=0; i<rowCount2; ++i){
                         besoinData.push_back(table_n2.model()->data(table_n2.model()->index(i, 0)).toInt());
                         qDebug()<<besoinData;

                     }

                     besoin->setData(ticks, besoinData);

}

void menu::on_commandLinkButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void menu::on_confirme_modifier_rejected()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void menu::on_triNM_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void menu::on_envoyer_email_clicked()
{
    Smtp* smtp = new Smtp("arayen138@gmail.com", "bhjjb", "smtp.gmail.com" ,465);

    smtp->sendMail("arayen138@gmail.com","rayen.bouazizi@esprit.tn", "email de verification  ",ui->descriptionemail->toPlainText());


/*
   const  QString user="arayen138@gmail.com";
   const QString pass="RAYEN123";
    const QString host="142.250.102.108";
    Smtp Smtp( user, pass, host,  465,  30000 );

   const QString from="arayen138@gmail.com";
   const QString to=ui->lineEdit_email->text();
   const QString subject="email de verification ";
   const QString body="   cher  client  votre  commande  a ete ajoutee par succees";

    Smtp.sendMail( from, to,subject , body);*/




}

void menu::on_anuler_email_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void menu::outputard()
{int valueToSend =E.calculernombre();

    if (Ard.write_to_arduino(valueToSend))
    {
        qDebug() << "Successfully sent value to Arduino: " << valueToSend;
    }
    else
    {
        qDebug() << "Failed to send value to Arduino!";
    }

}


void menu::inputard(){
    data=Ard.read_from_arduino();

    qDebug() << "data from arduino : "<< data;

    if (data.contains('2'))
    {
        qDebug()<<"boutton allumee:";
        outputard();
    }
}

