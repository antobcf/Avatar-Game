#ifndef SVILUPPATORI_H
#define SVILUPPATORI_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class FineScontro : public QDialog
{
    Q_OBJECT
private:
    QLabel* esito;
    QLabel* guadagno;
    QPushButton* ritornoHome;
    QPushButton* cambioAvatarFineScontro;
    QPushButton* continua;

public:
    FineScontro(QWidget * = nullptr);
    QPushButton* getHomeFine() const;
    QPushButton* getCambioAvatarFine() const;
    QPushButton* getContinuaFine() const;

public slots:

};

#endif // SVILUPPATORI_H
