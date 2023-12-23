#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QIntValidator>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "normes.h"
#include <iostream>
#include <QPrinter>
#include<QPainter>
#include <QDesktopServices>
#include <QtCharts>
#include <QUrl>
#include <QRegularExpressionValidator>
#include "arduino.h"
#include"connection.h"
#include"smtp.h"
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

//ghassen  included

#include"recaptcha.h"
#include "ui_recaptcha.h"
#include "randomstringgenerator.h"
#include <QSqlQueryModel>
#include "rapport.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QIntValidator>
#include <QSqlTableModel>
#include <QKeyEvent>
#include <QInputDialog>
#include <QDate>
#include <QListWidget>
#include <QDebug>
#include <QSortFilterProxyModel>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QStandardItemModel>
#include <QMap>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QPainter>
#include <QFileDialog>
#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
#include<qcustomplot.h>
#include<QtSql/QSqlQuery>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QPainter>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QPainter>
#include <QtCharts>

#include <QSqlQueryModel>
#include <QSqlRecord>

//  includes ranim



#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "questionnaire.h"
#include "auditeur.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QSqlQueryModel>
#include <QPrinter>
#include <QPrintDialog>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLegend>
#include <QtCharts/QLegendMarker>
#include<QBuffer>
#include <QImage>
#include<QFileDialog>
#include <QDebug>
#include <QStyledItemDelegate>
#include"qcustomplot.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    //captchaDialog(new recaptcha(this))
{


    //  video


   /* QWidget  mainWindow;

    // Creating the video player widget.
    VideoPlayerWidget videoPlayerWidget(&mainWindow);

    // Creating a button to trigger video playback.
    QPushButton playButton("Play Video", &mainWindow);

    // Connecting the button's clicked signal to the playVideo slot of the video player widget.
    QObject::connect(&playButton, &QPushButton::clicked, [&videoPlayerWidget]() {
        videoPlayerWidget.playVideo("C:/Users/SOSORDINATEUR/Videos/Jeu.mp4");
    });

    // Setting up the layout for the main window.
    QVBoxLayout* layout = new QVBoxLayout(&mainWindow);
    layout->addWidget(&playButton);
    layout->addWidget(&videoPlayerWidget);

    // Setting the layout for the main window.
    mainWindow.setLayout(layout);

    // Showing the main window.
    mainWindow.show();
*/




















    ui->setupUi(this);
    ui->gridStackedWidget->setCurrentIndex(0);
    //ui->login_error->hide();
    ui->le_id->setValidator(new   QIntValidator(0, 999999, this));
    ui->tab_normes->hide();
   Normes P;
   ui->tab_normes->setModel(P.afficher());
   ui->tab_normes->update();
   ui->tab_normes->show();
   on_stat();

   //     RAYEN


   E.calculernombre();
    //controle de saisie
   ui->lineEdit_id_entre->setValidator((new QIntValidator(100,9999,this)));
   ui->lineEdit_nbree_entre->setValidator((new QIntValidator(1,100000,this)));
   ui->lineEdit_numero_entre->setValidator((new QIntValidator(00000000,999999999,this)));
   ui->lineEdit_id_modifier__entre->setValidator((new QIntValidator(100,9999,this)));
      ui->lineEdit_nbree_mod_entre->setValidator((new QIntValidator(0,100000,this)));
      ui->lineEdit_numero_mod_entre->setValidator((new QIntValidator(00000000,999999999,this)));

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


      // statitistiques

     QSqlQuery qry,q2;
      qry.prepare("select NOM  from ENTREPRISE");
      qry.exec();
      ui->customPlot->legend->setVisible(true);
      ui->customPlot->legend->setFont(QFont("Helvetica",9));
      // set locale to english, so we get english decimal separator:
      ui->customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
      // add confidence band graphs:
      ui->customPlot->addGraph();
      ui->customPlot->setBackground(QBrush(Qt::darkCyan));
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


      //GHASSEN


      //ui->setupUi(this);
      ui->ID->setValidator(new QIntValidator(0,9999999,this));
      ui->Etat->setValidator(new QIntValidator(0,1,this));
      ui->tab_rapport->setModel(R.afficher());

      QIcon icon(":/C:/logo.png");
          setWindowIcon(icon);

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

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Normes p;
        int id=ui->le_id->text().toInt();
        QString nom=ui->le_nom->text();
        QString des=ui->le_description->text();
        QString date_n=ui->le_date->text();
        QString conformite=ui->le_conformite->text();
        ui->le_id->setText(QString::number(id));
      Normes P(id,nom,des,date_n,conformite);

      bool test1=P.ajouter();
      QMessageBox msgBox;
    if(test1){
        msgBox.setText("Ajout avec succes");
    ui->tab_normes->setModel(P.afficher());
    on_stat();
    }
    else
        msgBox.setText("Echec d'ajout.");
    msgBox.exec();

}

void MainWindow::on_pushButton_3_clicked()
{
    Normes p1;
    p1.setId(ui->le_idsupp->text().toInt());

    if (p1.estDejaSupprime(p1.getId())) {
        QMessageBox::information(this, "Suppression", "Ce norme est déjà supprimé.");
        return;
    }

    bool test = p1.supprimer(p1.getId());
    QMessageBox msgBox;
    if (test) {
        msgBox.setText("Suppression avec succès");
        ui->tab_normes->setModel(p1.afficher());
        on_stat();
    } else {
        msgBox.setText("Échec de la suppression.");
    }
    msgBox.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->le_id2->text().toInt();
        QString nom=ui->le_nom2->text();
        QString des=ui->le_description2->text();
        QString date_n=ui->le_date2->text();
        QString conformite=ui->le_conformite2->text();

        ui->le_id2->setText(QString::number(id));

            Normes P(id,nom,des,date_n,conformite);

            bool test=P.modifier();
            if (test)
            {
                QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Modification effectué\n""click cancel to exit."),QMessageBox::Cancel);
               ui->tab_normes->setModel((P.afficher()));
               on_stat();
                }
                else
                QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Modification non effectué\n""click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{
    Normes P;
    
            ui->tab_normes->setModel(P.tri());


}

void MainWindow::on_pushButton_5_clicked()
{
    Normes P;
        QString id = ui->le_idrech->text();

          QSqlQueryModel* res = P.recherche(id);

          if (res->rowCount() > 0) {
             // ui->tab_normes->setModel(res);
              QMessageBox::information(nullptr, QObject::tr("Recherche"),
                                       QObject::tr("Recherche avec succes."), QMessageBox::Ok);
              ui->tab_normes_rech->setModel(res);

          } else {
              QMessageBox::information(nullptr, QObject::tr("Recherche"),
                                       QObject::tr("Aucun résultat trouvé pour cet ID."), QMessageBox::Ok);
          }
}
   void MainWindow::on_pushButton_6_clicked()
{
    QPixmap pix(ui->tab_normes->size());
    QPainter painter(&pix);
    ui->tab_normes->render(&painter);
    painter.end();
    QPrinter printer(QPrinter::HighResolution);
    printer.setOrientation(QPrinter::Landscape);
    QString outputPath = "C:/Users/MED LIWA/Desktop/test.pdf";

    printer.setOutputFormat(QPrinter::PdfFormat);

    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(outputPath);

    painter.begin(&printer);
    double xscale = printer.pageRect().width() / double(pix.width());
    double yscale = printer.pageRect().height() / double(pix.height());
    double scale = qMin(xscale, yscale);
    painter.translate(printer.paperRect().x() + printer.pageRect().width() / 2,
                      printer.paperRect().y() + printer.pageRect().height() / 2);
    painter.scale(scale, scale);
    painter.translate(-ui->tab_normes->width() / 2, -ui->tab_normes->height() / 2);
    painter.drawPixmap(0, 0, pix);


    painter.end();
    QMessageBox::information(this,"Done","PDF is saved successfully");
    QDesktopServices::openUrl(QUrl::fromLocalFile(outputPath));
}

   int MainWindow::countNormes(const QString& conformite)
   {
       int count = 0;

       QSqlQuery query;
       query.prepare("SELECT COUNT(conformite) FROM NORMES WHERE conformite = :conformite");
       query.bindValue(":conformite", conformite);

       if (query.exec() && query.next()) {
           count = query.value(0).toInt();
       }

       return count;
   }
   void MainWindow::on_stat()
   {
       QList<QWidget*> childWidgets = ui->lab_stat->findChildren<QWidget*>();
       for (QWidget* childWidget : childWidgets) {
           childWidget->deleteLater();

       }

       ui->lab_stat->clear();
       ui->lab_stat->hide();

       float s0, s1;
       s0 = countNormes("conforme");
       s1 = countNormes("non conforme");

       float stat = s0 + s1;
       float x = (stat != 0) ? (s0 * 100) / stat : 0.0;
       float y = (stat != 0) ? (s1 * 100) / stat : 0.0;

       QString ch1 = QString("Conforme: %1%").arg(x);
       QString ch2 = QString("Non  conforme: %1%").arg(y);

       QPieSeries *series=new QPieSeries();
       series->setHoleSize(0.39);
       QPieSlice *slice= series->append(ch1,x);
       slice->setLabelVisible();

       slice->setLabelColor(QColor("#FFFFFF"));
       slice->setBrush(QColor(14, 51, 242, 1));

       QPieSlice *slice1 = series->append(ch2, y);
       slice1->setLabelVisible();
       slice1->setLabelColor(QColor("#FFFFFF"));
       slice1->setBrush(QColor(14, 183, 242, 1));

       QChart *chart=new QChart();
       chart->addSeries(series);
       chart->setAnimationOptions(QChart::SeriesAnimations);
       QBrush backgroundBrush(QColor(187,93,87,0));
       chart->setBackgroundBrush(backgroundBrush);
       QChartView *chartview=new QChartView(chart);
       chartview->setRenderHint(QPainter::Antialiasing);
       chartview->setFixedSize(ui->lab_stat->size());
       chartview->setParent(ui->lab_stat);
       ui->lab_stat->setStyleSheet("background:transparent; color:white; ");
       ui->lab_stat->show();
   }


void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index==1){

    }
}

void MainWindow::on_pushButton_7_clicked()
{ QString  name =ui->username->text();
    QString pass=ui->password->text();
            // ui->login_error->show();
   // ui->login_error->setStyleSheet("color: rgb(71, 85, 105);");
    //ui->login_error->setText("Connecting...");

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM AUDITEURS WHERE USERNAME = '" + ui->username->text()+"' AND PASSWORD = '"+ui->password->text()+"'");
    qDebug()<<"Found: "<<model->rowCount();
    if(model->rowCount()>0){
      //  ui->login_error->setStyleSheet("Successful login! Welcome back.");
        //ui->login_error->setText("color: #72C14E;");
        ui->gridStackedWidget->setCurrentIndex(3);
    }else{
        if( name=="admin" && pass=="admin")
            Ard.write_to_arduino(E.calculernombre());
         ui->gridStackedWidget->setCurrentIndex(1);
        //ui->login_error->setText("Invalid username or password. Please try again.");
        //ui->login_error->setStyleSheet("color: rgb(255, 80, 83);");
    }
}

void MainWindow::on_logoutButton_clicked()
{
    ui->username->clear();
    ui->password->clear();
    //ui->login_error->hide();
    ui->gridStackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Plateforme_emp_3_clicked()
{
    ui->gridStackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Plateforme_emp_2_clicked()
{
    ui->gridStackedWidget->setCurrentIndex(3);
}

   // RAYEN  MENU

void MainWindow::on_pushButton_ajout_entreprise_clicked()
{
    ui->gridStackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_chercher_entreprise_clicked()
{
    ui->gridStackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_afficher_entreprise_clicked()
{
    ui->gridStackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_supprimer_entreprise_clicked()
{

    ui->gridStackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_modifier_entreprise_clicked()
{
    ui->gridStackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_statistiques_entreprise_clicked()
{
    ui->gridStackedWidget->setCurrentIndex(9);
}

void MainWindow::on_confirme_ajout_5_accepted()
{

    int id =ui->lineEdit_id_entre->text().toInt();
    QString nom =ui->lineEdit_nom_entre->text();
    QString pays=ui->lineEdit_pays_entre->text();
    QString ville=ui->lineEdit_ville_entre->text();
    QString adresse=ui->lineEdit_adreese_entre->text();
    QString date=ui->lineEdit_date_entre->text();
    QString email=ui->lineEdit_email_entre->text();
    int nombree=ui->lineEdit_nbree_entre->text().toInt();
    int  numero=ui->lineEdit_numero_entre->text().toInt();
    QString domaine=ui->lineEdit_domaine_entre->text();
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
       //Ard.write_to_arduino("0");

}

void MainWindow::on_commandLinkButton_18_clicked()
{
    ui->gridStackedWidget->setCurrentIndex(3);
}

void MainWindow::on_commandLinkButton_19_clicked()
{
    ui->gridStackedWidget->setCurrentIndex(3);

}

void MainWindow::on_commandLinkButton_20_clicked()
{
    ui->gridStackedWidget->setCurrentIndex(3);

}

void MainWindow::on_commandLinkButton_21_clicked()
{
    ui->gridStackedWidget->setCurrentIndex(3);

}

void MainWindow::on_commandLinkButton_22_clicked()
{
    ui->gridStackedWidget->setCurrentIndex(3);
}

void MainWindow::on_commandLinkButton_23_clicked()
{
     ui->gridStackedWidget->setCurrentIndex(1);
}

void MainWindow::on_commandLinkButton_24_clicked()
{
     ui->gridStackedWidget->setCurrentIndex(1);

}

void MainWindow::on_confirme_ajout_entre_accepted()
{

            int id =ui->lineEdit_id_entre->text().toInt();
            QString nom =ui->lineEdit_nom_entre->text();
            QString pays=ui->lineEdit_pays_entre->text();
            QString ville=ui->lineEdit_ville_entre->text();
            QString adresse=ui->lineEdit_adreese_entre->text();
            QString date=ui->lineEdit_date_entre->text();
            QString email=ui->lineEdit_email_entre->text();
            int nombree=ui->lineEdit_nbree_entre->text().toInt();
            int  numero=ui->lineEdit_numero_entre->text().toInt();
            QString domaine=ui->lineEdit_domaine_entre->text();
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

void MainWindow::on_triNM_17_clicked()
{



    ui->gridStackedWidget->setCurrentIndex(10);


}

void MainWindow::on_confirme_ajout_entre_rejected()
{
    ui->gridStackedWidget->setCurrentIndex(3);

}



void MainWindow::on_pushButton_confirmer_rechercher_entre_clicked()
{
    int iden=ui->lineEdit_id_chercher_entre->text().toInt();
       ui->table_recherche_entre->setModel(E.recherche(iden));
}

void MainWindow::on_pushButton_19_clicked()
{
    QString nm =ui->li_recherche_entre->text();
    ui->tableview_afficher_entre->setModel((E.recherche(nm)));

}

void MainWindow::on_checkBox_nomup_entre_stateChanged(int arg1)
{
    ui->tableview_afficher_entre->setModel(E.afficherup_nom());
}

void MainWindow::on_checkBox_pays_up_entre_clicked()
{
    ui->tableview_afficher_entre->setModel(E.afficherup_pays());
}

void MainWindow::on_checkBox_nombre_up_entre_clicked()
{
     ui->tableview_afficher_entre->setModel(E.afficherup_nombree());
}

void MainWindow::on_checkBox_nomdown_entre_clicked()
{
     ui->tableview_afficher_entre->setModel(E.afficherdown_nom());
}

void MainWindow::on_checkBox_pays_down_entre_clicked()
{
     ui->tableview_afficher_entre->setModel(E.afficherdown_pays());
}

void MainWindow::on_checkBox_date_entre_clicked()
{
    ui->tableview_afficher_entre->setModel(E.afficherup_date());
}

void MainWindow::on_confirme_supression_entre_clicked()
{
    Ard.write_to_arduino(E.calculernombre());
    ui->table_suppression_entre->setModel(E.afficher());
   E.setid(ui->lineEdit_suppression_entre->text().toInt());

   bool test=E.supprimer(E.getid());
   //int n=E.calculer(E.getid());
   ui->table_suppression_entre->setModel(E.afficher());
   //bool test1=E.recherche(E.getid());
   QMessageBox msg ;
   if(test  ){ Ard.write_to_arduino(E.calculernombre());
       msg.setText("suppression avec succees");}
   else
       msg.setText(("echec de suppression "));
   msg.exec();
}

void MainWindow::on_confirmer_mod_entre_clicked()
{

    int id =ui->lineEdit_id_modifier__entre->text().toInt();
     QString nom =ui->lineEdit_nom_mod_entre->text();
     QString pays=ui->lineEdit_pays_mod_entre->text();
     QString ville=ui->lineEdit_ville_mod_entre->text();
     QString adresse=ui->lineEdit_adreese_mod_entre->text();
     QString date=ui->lineEdit_date_mod_entre->text();
     QString email=ui->lineEdit_email_mod_entre->text();
     int nombree=ui->lineEdit_nbree_mod_entre->text().toInt();
     int  numero=ui->lineEdit_numero_mod_entre->text().toInt();
     QString domaine=ui->lineEdit_domaine_mod_entre->text();
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
                                                  "click cancel to exit"),QMessageBox::Cancel);*/
}

void MainWindow::on_envoyer_email_2_clicked()
{
    Smtp* smtp = new Smtp("arayen138@gmail.com", "bhjjb", "smtp.gmail.com" ,465);

    smtp->sendMail("arayen138@gmail.com","rayen.bouazizi@esprit.tn", "email de verification  ",ui->descriptionemail_entre->toPlainText());

}

void MainWindow::on_anuler_email_2_clicked()
{
    ui->gridStackedWidget->setCurrentIndex(3);
}

void MainWindow::on_triNM_18_clicked()
{
    int id =ui->lineEdit_id_entre->text().toInt();
    QString nom =ui->lineEdit_nom_entre->text();
    QString pays=ui->lineEdit_pays_entre->text();
    QString ville=ui->lineEdit_ville_entre->text();
    QString adresse=ui->lineEdit_adreese_entre->text();
    QString date=ui->lineEdit_date_entre->text();
    QString email=ui->lineEdit_email_entre->text();
    int nombree=ui->lineEdit_nbree_entre->text().toInt();
    int  numero=ui->lineEdit_numero_entre->text().toInt();
    QString domaine=ui->lineEdit_domaine_entre->text();
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
    ui->QR_aff->setPixmap(pix);
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

void MainWindow::on_triNM_19_clicked()
{
    int  Code=ui->lineEdit_id_chercher_entre->text().toInt();
    E.recherche(Code);


    const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(std::to_string(Code).c_str(), qrcodegen::QrCode::Ecc::LOW);
   //const qrcodegen::QrCode qr1 = qrcodegen::QrCode::encodeText(p, qrcodegen::QrCode::Ecc::LOW);
    std::ofstream myfile;
    myfile.open ("qrcode.svg") ;
    myfile << qr.toSvgString(1);
    myfile.close    ();
    QSvgRenderer svgRenderer(QString("qrcode.svg"));
    QPixmap pix( QSize(150, 150));
    QPainter pixPainter( &pix );
    svgRenderer.render(&pixPainter);
    ui->QR_aff_entrep->setPixmap(pix);
}

void MainWindow::on_triNM_20_clicked()
{

}

void MainWindow::on_pb_ajouter_clicked()
{
    Notification N;
    int ID=ui->ID->text().toInt();
    QString Titre=ui->Titre->text();
    QString Objectif=ui->Objectif->text();
    int Dateaudit = ui->Dateaudit->text().toInt();
    QString Resume=ui->Resume->text();
    int Etat=ui->Etat->text().toInt();

    /*if (captchaDialog->exec() == QDialog::Accepted)*/

    Rapport R(ID,Titre,Objectif,Dateaudit,Resume,Etat);

        bool test=R.ajouter();

        if(test)
        {
            {QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("Ajout effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

                ui->tab_rapport->setModel(R.afficher());}

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                        QObject::tr("Ajout non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        if(Etat==1)
        {N.showNotification();
        }
}

void MainWindow::on_supp_clicked()
{

}

void MainWindow::on_supp_rapport_clicked()
{
    Notification N;
    Rapport R1;R1.setId(ui->le_id_supp->text().toInt());
    bool test=R1.supprimer(R1.getid());
    QMessageBox msgBox;

    if(test){
        {
            QMessageBox::critical(nullptr, QObject::tr("  ok"),
                        QObject::tr("Suppression effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
                      ui->tab_rapport->setModel(R.afficher());
          }
    }
          else
          {
              QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                          QObject::tr("Suppression non effectué.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
}

void MainWindow::on_pb_modifier_clicked()
{

    Notification N;
    int newId=ui->newId->text().toInt();
    QString newTitre=ui->newTitre->text();
    QString newObjectif=ui->newObjectif->text();
    int newDateaudit = ui->newDateaudit->text().toInt();
    QString newResume=ui->newResume->text();
    int newEtat=ui->newEtat->text().toInt();
    Rapport R(newId,newTitre,newObjectif,newDateaudit,newResume,newEtat);
    bool test=R.modifier();
    if(test){
       QMessageBox::critical(nullptr , QObject::tr(" Ok "),QObject::tr("modifier effectie.\n""click cancel  ."),QMessageBox::Cancel);
        ui->tab_rapport->setModel(R.afficher());


    }else{ QMessageBox::critical(nullptr , QObject::tr("Not Ok "),QObject::tr("modifier non effectie.\n""click cancel  ."),QMessageBox::Cancel);

    }
    if(newEtat==1)
    {N.showNotification();
}}

void MainWindow::on_exporter_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
       if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("liste_rapport.pdf"); }

       QPrinter printer;
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       printer.setOutputFileName(fileName);

       QTextDocument doc;
       QSqlQuery q;
       q.prepare("SELECT * FROM RAPPORT ");
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
}

void MainWindow::on_le_chercher_clicked()
{
    Rapport R;
                  int ID = ui->id_recherche->text().toInt();

                  QSqlQueryModel* res = R.recherche(ID);

                  if (res->rowCount() > 0) {

                      QMessageBox::information(nullptr, QObject::tr("Recherche"),
                                               QObject::tr("Rapport existant."), QMessageBox::Ok);
                      QSqlQueryModel *model = R.tri1();


                      ui->tab_rapport_3->setModel(model);
                    // ui->tab_rapport= R.afficher();
                                            }
                  else {
                      QMessageBox::information(nullptr, QObject::tr("Recherche"),
                                               QObject::tr("Aucun résultat trouvé pour cet id."), QMessageBox::Ok);
                  }

}

void MainWindow::on_le_chercher_2_clicked()
{

    Rapport R;
                  QString TITRE = ui->titre_recherche->text();

                  QSqlQueryModel* res = R.recherche1(TITRE);

                  if (res->rowCount() > 0) {

                      QMessageBox::information(nullptr, QObject::tr("Recherche"),
                                               QObject::tr("Rapport existant."), QMessageBox::Ok);
                      QSqlQueryModel *model = R.tri1();


                      ui->tab_rapport_3->setModel(model);
                                            }
                  else {
                      QMessageBox::information(nullptr, QObject::tr("Recherche"),
                                               QObject::tr("Aucun résultat trouvé pour cet id."), QMessageBox::Ok);
                  }

}

void MainWindow::on_le_chercher_3_clicked()
{
    Rapport R;
                  QString OBJECTIF = ui->objectif_recherche->text();

                  QSqlQueryModel* res = R.recherche2(OBJECTIF);

                  if (res->rowCount() > 0) {

                      QMessageBox::information(nullptr, QObject::tr("Recherche"),
                                               QObject::tr("Rapport existant."), QMessageBox::Ok);
                      QSqlQueryModel *model = R.tri1();


                      ui->tab_rapport_3->setModel(model);
                                            }
                  else {
                      QMessageBox::information(nullptr, QObject::tr("Recherche"),
                                               QObject::tr("Aucun résultat trouvé pour cet id."), QMessageBox::Ok);
                  }

}

void MainWindow::on_tri_2_clicked()
{
    Rapport R;
               QSqlQueryModel *model = R.tri();


               ui->tab_rapport_2->setModel(model);
}

void MainWindow::on_tri_3_clicked()
{
    Rapport R;
               QSqlQueryModel *model = R.tri1();


               ui->tab_rapport_2->setModel(model);

}

void MainWindow::on_tri_4_clicked()
{
    Rapport R;
               QSqlQueryModel *model = R.tri2();


               ui->tab_rapport_2->setModel(model);
}

void MainWindow::on_commandLinkButton_25_clicked()
{
     ui->gridStackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pb_ajouter_2_clicked()
{
    //questionaire q ;
   // q.exec();

    int idf=ui->le_id->text().toInt();
    int numero=ui->le_numero->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString sexe=ui->le_sexe->currentText();
    QString adresse=ui->le_adresse->text();

    QString classe=ui->le_classe->currentText();
    QString imagePath = QFileDialog::getOpenFileName(this, "Sélectionnez une image", QString(), "Images (*.png *.xpm *.jpg)");
    if (imagePath.isEmpty())
    {
        QMessageBox::warning(this, "Avertissement", "Aucune image sélectionnée.");
        return;

    }

    QImage image(imagePath);
    if (image.isNull()) {
        QMessageBox::warning(this, "Avertissement", "Impossible de charger l'image sélectionnée.");
        return;
    }

    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "JPG");




    Auditeur A(idf,numero,nom,prenom,sexe, adresse,classe,byteArray,imagePath);
    bool test=A.ajouter();
         QMessageBox msgBox;
         if(test)
        { msgBox.setText("Ajout avec succes.");
             QSqlQueryModel* model= A.afficher();
         ui->tab_auditeur->setModel(model);
         msgBox.exec();
         }
         else {
             msgBox.setText("Echec d'ajout");
                     msgBox.exec();}
}

void MainWindow::on_modefier_clicked()
{
    int idf=ui->le_id_2->text().toInt();
    int numero=ui->le_numero_2->text().toInt();
    QString imagePath;
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString sexe=ui->le_sexe_2->text();
    QString adresse=ui->le_adresse_2->text();
    QString classe=ui->le_classe_2->text();
    QByteArray image;
    Auditeur A(idf,numero,nom,prenom,sexe, adresse,classe,image,imagePath);
    bool test=A.modifier();
         QMessageBox msgBox;
         if(test)
        { msgBox.setText("modification avec succes.");
             QSqlQueryModel* model= A.afficher();
         ui->tab_auditeur->setModel(model);
         msgBox.exec();
         }
         else {
             msgBox.setText("Echec de mofication");
                     msgBox.exec();}
}

void MainWindow::on_pb_suppr_clicked()
{

    QMessageBox msgBox;
    Auditeur auditeur;
    int idToSupprimer = ui->le_id_suppr->text().toInt();

    if (idToSupprimer <= 0) {
        msgBox.setText("L'ID n'est pas valide. Suppression échouée.");
        msgBox.exec();
    } else {
        auditeur.setid(idToSupprimer);

        if (!auditeur.existeID(auditeur.getid())) {
            msgBox.setText("L'ID n'existe pas. Suppression échouée.");
            msgBox.exec();
        } else {
            bool supprime = auditeur.supprimer(auditeur.getid());
            if (supprime) {
                msgBox.setText("Suppression réussie.");
                ui->tab_auditeur->setModel(auditeur.afficher());
                msgBox.exec();
                // Mettez à jour votre affichage ou autre traitement si nécessaire
            } else {
                msgBox.setText("Échec de la suppression.");
                msgBox.exec();
            }
        }
    }
}

void MainWindow::on_pushButton_pdf_2_clicked()
{

}

void MainWindow::on_pushButton_pdf_2_pressed()
{
    QPrinter printer;
    printer.setPrinterName("AUDITEURS");
    QPrintDialog dialog(&printer, this);
    if (dialog.exec() == QDialog::Rejected) return;

    QTextDocument document;

    QString htmlContent = "<html><body><h1>Liste des employés</h1><table border='1'>";
    htmlContent += "<tr>";
    for (int column = 0; column < ui->tab_auditeur->model()->columnCount(); ++column) {
        if (!ui->tab_auditeur->isColumnHidden(column)) {
            QString headerText = ui->tab_auditeur->model()->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
            htmlContent += QString("<th>%1</th>").arg(headerText);
        }
    }
    htmlContent += "</tr>";

    for (int row = 0; row < ui->tab_auditeur->model()->rowCount(); ++row) {
        htmlContent += "<tr>";
        for (int column = 0; column < ui->tab_auditeur->model()->columnCount(); ++column) {
            if (!ui->tab_auditeur->isColumnHidden(column)) {
                QString data = ui->tab_auditeur->model()->data(ui->tab_auditeur->model()->index(row, column)).toString();
                htmlContent += QString("<td>%1</td>").arg(data);
            }
        }
        htmlContent += "</tr>";
    }

    htmlContent += "</table></body></html>";

    document.setHtml(htmlContent);

    document.print(&printer);
}

void MainWindow::on_generer_stat_clicked()
{
    QPieSeries *series = new QPieSeries();

    QStringList classes = {"A", "B", "C"};
    for (const QString &classe : classes)
    {
        int nombreAuditeurs = A.getNombreAuditeursParClasse(classe);

        if (nombreAuditeurs > 0)
        {
            series->append(classe, nombreAuditeurs);
        }
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des auditeurs par classe");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow *chartWindow = new QMainWindow();
    chartWindow->setCentralWidget(chartView);
    chartWindow->resize(400, 300);
    chartWindow->show();
}


void MainWindow::on_stat_femme_clicked()
{
    QPieSeries *series = new QPieSeries();

    QStringList sexes = {"homme", "femme"};
    for (const QString &sexe : sexes)
    {
        int nombreAuditeurs = A.getNombreAuditeursParSexe(sexe);

        if (nombreAuditeurs > 0)
        {
            series->append(sexe, nombreAuditeurs);
        }
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques par sexe");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->centralWidget);
    chartView->resize(400, 300);
    chartView->show();
}

void MainWindow::on_pushButton_37_clicked()
{
    QPieSeries *series = new QPieSeries();

    QStringList classes = {"A", "B"};
    for (const QString &classe : classes)
    {
        int nombreAuditeurs = A.getNombreAuditeursParClasse(classe);
        if (nombreAuditeurs > 0)
        {
            series->append(classe, nombreAuditeurs);
        }
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques entre les classes A et B");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->centralWidget);
    chartView->resize(400, 300);
    chartView->show();
}

void MainWindow::on_checkBoxQuestion1A_stateChanged(int arg1)
{

}

void MainWindow::on_Plateforme_emp_4_clicked()
{
    ui->gridStackedWidget->setCurrentIndex(12);
}

void MainWindow::on_Plateforme_emp_clicked()
{
     ui->gridStackedWidget->setCurrentIndex(11);
}

void MainWindow::on_commandLinkButton_26_clicked()
{
     ui->gridStackedWidget->setCurrentIndex(1);
}

void MainWindow::on_videoPlayerWidget_customContextMenuRequested(const QPoint &pos)
{

}

void MainWindow::on_pushButton_statistiques_entreprise_2_clicked()
{
     ui->gridStackedWidget->setCurrentIndex(1);

}

void MainWindow::on_Plateforme_emp_5_clicked()
{
    ui->gridStackedWidget->setCurrentIndex(0);
}
void MainWindow::outputard()
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


void MainWindow::inputard(){
    data=Ard.read_from_arduino();

    qDebug() << "data from arduino : "<< data;

    if (data.contains('2'))
    {
        qDebug()<<"boutton allumee:";
        outputard();
    }
}


void MainWindow::on_triNM_20_pressed()
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
}

void MainWindow::on_pushButton_8_clicked()
{
    QPixmap pix(ui->tab_normes->size());
    QPainter painter(&pix);
    ui->tab_normes->render(&painter);
    painter.end();
    QPrinter printer(QPrinter::HighResolution);
    printer.setOrientation(QPrinter::Landscape);
    QString outputPath = "C:/Users/MED LIWA/Desktop/test.pdf";

    printer.setOutputFormat(QPrinter::PdfFormat);

    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(outputPath);

    painter.begin(&printer);
    double xscale = printer.pageRect().width() / double(pix.width());
    double yscale = printer.pageRect().height() / double(pix.height());
    double scale = qMin(xscale, yscale);
    painter.translate(printer.paperRect().x() + printer.pageRect().width() / 2,
                      printer.paperRect().y() + printer.pageRect().height() / 2);
    painter.scale(scale, scale);
    painter.translate(-ui->tab_normes->width() / 2, -ui->tab_normes->height() / 2);
    painter.drawPixmap(0, 0, pix);


    painter.end();
    QMessageBox::information(this,"Done","PDF is saved successfully");
    QDesktopServices::openUrl(QUrl::fromLocalFile(outputPath));
}

void MainWindow::on_pushButton_9_clicked()
{
    Normes P;

            ui->tab_normes->setModel(P.tri());
}
