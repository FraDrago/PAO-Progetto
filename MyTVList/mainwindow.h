#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QHBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QMenuBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QFileDialog>
#include <QCheckBox>
#include <QMenuBar>
#include <QMainWindow>
#include <QMessageBox>

#include <QMainWindow>
#include <QMenuBar>
#include <QListView>

#include "GUI/qlistmodel.h"
#include "GUI/tipotv.h"
#include "GUI/aggiungielemento.h"
#include "GUI/visualizzalayout.h"
#include "GUI/proxymodel.h"
#include "modello.h"




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = nullptr );
    ~MainWindow();



public slots:
    void eliminaserie();
    void eliminafilm();
    void eliminadocum();
    void modificabutton();
    void plusone();
    void cecca(int=0);
    void saveData() const;
    void loadData() const;
    void textFilterChanged();
    void aggiungilayout();
    void addlist();
    void modifica();
    void elimina() const;
private:

    int current;
    TipoTV *genere;
    QLabel* min;
    Visualizzalayout* visual;
    aggiungielemento* addel;
    proxymodel* proxy;
    qlistmodel* qmodel;
    QWidget* qparent;
    QListView *list;
    QLineEdit *cerca;
    QPushButton* buttonModifica;
    QPushButton* buttonRimuovi;

};

#endif // MAINWINDOW_H
