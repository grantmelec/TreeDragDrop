#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStandardItemModel"
#include "QDebug"
#include <QDragEnterEvent>          //need support from this include

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Create tree view model and bind to treeview
    modeldrag = new QStandardItemModel();
    modeldrop = new QStandardItemModel();



    static QString ico = "LinuxIco.png";
    static QString ico2 = "windows.png";

    //Standard Item models are created
    QStandardItem* item0 = new QStandardItem(QIcon(ico), "1. First item");
    QStandardItem* item1 = new QStandardItem(QIcon(ico), "2 second item");
    QStandardItem* item2 = new QStandardItem(QIcon(ico), "3 third item");
    QStandardItem* item3 = new QStandardItem(QIcon(ico2),"4 forth item");
    QStandardItem* item4 = new QStandardItem(QIcon(ico2),"5 fith item");

    QStandardItem * itemp1 = new QStandardItem(QIcon(ico), "First item");
    QStandardItem * itemp2 = new QStandardItem(QIcon(ico), "Second item");


    modeldrag->appendRow(item0);    //high level hiearchy
    item0->appendRow(item1);        //child of item 0
    item0->appendRow(item2);        //child of item 0
    modeldrag->appendRow(item3);    //high level hiearchy
    item3->appendRow(item4);
    ui->viewdrag->setModel(modeldrag);

    modeldrop->appendRow(itemp1);
    itemp1->appendRow(itemp2);
    ui->viewdrop->setModel(modeldrop);

    ui->viewdrop->setHeaderHidden(true);
    ui->viewdrag->setHeaderHidden(true);
    ui->viewdrag->setDragEnabled(true);
    ui->viewdrop->setDragEnabled(true);

    setAcceptDrops(true);                   //!!!!!!!!!!the main window has to accept drops

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<<"dragging enter";
    if(event->mimeData())
        ui->viewdrop->setAcceptDrops(true);
}



