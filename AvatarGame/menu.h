#ifndef MENU_H
#define MENU_H

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QWidget>

class Menu : public QMenuBar
{
    Q_OBJECT
private:
    QWidget* parent;
    QMenuBar* menuBar;
    QMenu* file;
    QMenu* personaggio;
    QMenu* finestra;
    QMenu* info;
    QAction* esci;
    QAction* nuovo;
    QAction* carica;
    QAction* salva;
    QAction* lista;
    QAction* sviluppatori;
    QAction* infoSistema;
    QAction* schermoIntero;
    QAction* riduci;
    QAction* darkMode;
    QAction* home;

public:
    Menu(QWidget* parent = nullptr);
};

#endif // MENU_H
