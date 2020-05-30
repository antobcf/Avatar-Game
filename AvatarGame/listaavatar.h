#ifndef LISTAAVATAR_H
#define LISTAAVATAR_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QFormLayout>

class ListaAvatar : public QWidget
{
    Q_OBJECT
private:
    QFormLayout* formCrea;
    QPushButton* bottoneHome;
    QPushButton* bottoneModifica;
    QPushButton* bottoneRimuovi;
    QPushButton* bottoneRimuoviTutto;
    QCheckBox* tipoElfo;
    QCheckBox* tipoNano;
    QCheckBox* tipoUmano;
    QCheckBox* tipoAlieno;
    QCheckBox* tipoMostro;
    QLineEdit* cercaNome;
    QGroupBox* boxLista;

public:
    ListaAvatar(QWidget * = nullptr);
    QFormLayout* getFormCrea() const;
    QPushButton* getBottoneHome() const;
    QLineEdit* getCercaNome() const;

public slots:

};

#endif // LISTAAVATAR_H
