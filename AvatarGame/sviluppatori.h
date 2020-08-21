#ifndef SVILUPPATORI_H
#define SVILUPPATORI_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>

class Sviluppatori : public QDialog
{
    Q_OBJECT
private:
    QLabel* immagineSviluppatori;
    QLabel* testoSviluppatori;

public:
    Sviluppatori(QWidget * = nullptr);

public slots:

};


#endif // SVILUPPATORI_H
