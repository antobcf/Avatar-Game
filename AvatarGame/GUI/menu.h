#ifndef MENU_H
#define MENU_H

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QWidget>
#include <QMessageBox>

class Menu : public QMenuBar
{
    Q_OBJECT
private:
    QWidget* parent;
    QMenu* file;
    QMenu* personaggio;
    QMenu* info;
    QAction* esci;
    QAction* nuovo;
    QAction* carica;
    QAction* lista;
    QAction* sviluppatori;
    QAction* infoSistema;
    QAction* home;

public:
    Menu(QWidget* parent = nullptr);
};

#endif // MENU_H
