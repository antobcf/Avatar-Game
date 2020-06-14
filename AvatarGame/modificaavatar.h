#ifndef MODIFICAAVATAR_H
#define MODIFICAAVATAR_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QGroupBox>
#include <QTextEdit>
#include <QComboBox>
#include <QImage>
#include <QFormLayout>
#include <QRadioButton>
#include <QFileDialog>
#include <QString>

class ModificaAvatar : public QDialog
{
    Q_OBJECT
private:
    QFormLayout* formCrea;
    QLabel* maxPowerUp;
    QLabel* lvl;
    QLabel* valoreForza;
    QLabel* valoreScienza;
    QLabel* valoreDifesa;
    QLabel* valoreMagia;
    QLabel* valoreMedia;
    QLabel* valoreSpeciale;
    QLabel* exp;
    QLabel* labelSesso;
    QLineEdit* inserisciNome;
    QPushButton* bottoneSalvaModifiche;
    QPushButton* resetCampi;
    QCheckBox* powerUp1;
    QCheckBox* powerUp2;
    QCheckBox* powerUp3;
    QCheckBox* powerUp4;
    QCheckBox* powerUp5;
    QCheckBox* powerUp6;
    QCheckBox* powerUp7;
    QCheckBox* powerUp8;
    QGroupBox* boxValori;
    QTextEdit* boxDescrizione;
    QComboBox* sceltaTipo;
    QPushButton* modificaImmagine;
    QRadioButton* sessoM;
    QRadioButton* sessoF;
    QString percorsoImmagine;

public:
    ModificaAvatar(QWidget * = nullptr);
    QFormLayout* getFormCrea() const;
    QLabel* getMaxPowerUp() const;
    QLabel* getLvl() const;
    QLabel* getValoreForza() const;
    QLabel* getValoreScienza() const;
    QLabel* getValoreDifesa() const;
    QLabel* getValoreMagia() const;
    QLabel* getValoreMedia() const;
    QLabel* getValoreSpeciale() const;
    QLabel* getExp() const;
    QLabel* getLabelSesso() const;
    QLineEdit* getInserisciNome() const;
    QPushButton* getBottoneHome() const;
    QPushButton* getBottoneSalvaModifiche() const;
    QPushButton* getResetCampi() const;
    QCheckBox* getPowerUp1() const;
    QCheckBox* getPowerUp2() const;
    QCheckBox* getPowerUp3() const;
    QCheckBox* getPowerUp4() const;
    QCheckBox* getPowerUp5() const;
    QCheckBox* getPowerUp6() const;
    QCheckBox* getPowerUp7() const;
    QCheckBox* getPowerUp8() const;
    QGroupBox* getBoxValori() const;
    QTextEdit* getBoxDescrizione() const;
    QComboBox* getSceltaTipo() const;
    QLabel* getImmagineAvatar() const;
    QRadioButton* getSessoM() const;
    QRadioButton* getSessoF() const;

    //inserisciPercorso(std::string);
    QString getPercorsoImmagine() const;

public slots:
    void checkUno() const;
    void checkDue() const;
    void checkTre() const;
    void checkQuattro() const;
    void checkCinque() const;
    void checkSei() const;
    void checkSette() const;
    void checkOtto() const;
    void groupTipo() const;
    void resetTutto() const;
    void resetCheck() const;

    void cambiaImmagine();
};

#endif // MODIFICAAVATAR_H
