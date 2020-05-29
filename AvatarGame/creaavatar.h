#ifndef CREAAVATAR_H
#define CREAAVATAR_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QGroupBox>

class CreaAvatar : public QWidget
{
    Q_OBJECT
private:
    QLabel* scrittaNome;
    QLabel* maxPowerUps;
    QLabel* lvl;
    QLabel* valoreForza;
    QLabel* valoreScienza;
    QLabel* valoreDifesa;
    QLabel* valoreMagia;
    QLabel* valoreMedia;
    QLineEdit* inserisciNome;
    QPushButton* bottoneHome;
    QPushButton* bottoneCreaDef;
    QPushButton* scegliImmagine;
    QPushButton* resetCampi;
    QCheckBox* powerUp1;
    QCheckBox* powerUp2;
    QCheckBox* powerUp3;
    QCheckBox* powerUp4;
    QGroupBox* boxValori;

public:
    CreaAvatar(QWidget * = nullptr);
    QLabel* getScrittaNome() const;
    QLabel* getMaxPowerUps() const;
    QLabel* getLvl() const;
    QLabel* getValoreForza() const;
    QLabel* getValoreScienza() const;
    QLabel* getValoreDifesa() const;
    QLabel* getValoreMagia() const;
    QLabel* getValoreMedia() const;
    QLineEdit* getInserisciNome() const;
    QPushButton* getBottoneHome() const;
    QPushButton* getBottoneCreaDef() const;
    QPushButton* getScegliImmagine() const;
    QCheckBox* getPowerUp1() const;
    QCheckBox* getPowerUp2() const;
    QCheckBox* getPowerUp3() const;
    QCheckBox* getPowerUp4() const;

signals:

};

#endif // CREAAVATAR_H
