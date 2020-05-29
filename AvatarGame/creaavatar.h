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
#include <QTextEdit>

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
    QTextEdit* boxDescrizione;

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
    QPushButton* getResetCampi() const;
    QCheckBox* getPowerUp1() const;
    QCheckBox* getPowerUp2() const;
    QCheckBox* getPowerUp3() const;
    QCheckBox* getPowerUp4() const;
    QGroupBox* getBoxValori() const;
    QTextEdit* getBoxDescrizione() const;

public slots:
    void checkUnoDue() const;
    void checkUnoTre() const;
    void checkUnoQuattro() const;
    void checkDueTre() const;
    void checkDueQuattro() const;
    void checkTreQuattro() const;

};

#endif // CREAAVATAR_H
