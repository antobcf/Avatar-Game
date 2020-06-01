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
#include <QComboBox>
#include <QImage>
#include <QFormLayout>
#include <QRadioButton>

class CreaAvatar : public QWidget
{
    Q_OBJECT
private:
    QFormLayout* formCrea;
    QLabel* maxPowerUp;
    QLabel* lvl;
    QLabel* valoreForza;
    QLabel* valoreMagia;
    QLabel* valoreDifesa;
    QLabel* valoreScienza;
    QLabel* valoreMedia;
    QLabel* labelSesso;
    QLineEdit* inserisciNome;
    QPushButton* bottoneHome;
    QPushButton* bottoneCreaDef;
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
    QLabel* immagineAvatar;
    QRadioButton* sessoM;
    QRadioButton* sessoF;

public:
    CreaAvatar(QWidget * = nullptr);
    QFormLayout* getFormCrea() const;
    QLabel* getMaxPowerUp() const;
    QLabel* getLvl() const;
    QLabel* getValoreForza() const;
    QLabel* getValoreMagia() const;
    QLabel* getValoreDifesa() const;
    QLabel* getValoreScienza() const;
    QLabel* getValoreMedia() const;
    QLabel* getLabelSesso() const;
    QLineEdit* getInserisciNome() const;
    QPushButton* getBottoneHome() const;
    QPushButton* getBottoneCreaDef() const;
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
    void calcoloValori() const;

};

#endif // CREAAVATAR_H
