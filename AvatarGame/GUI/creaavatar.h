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
#include <QFileDialog>

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
    QLabel* valoreSpeciale;
    QLabel* exp;
    QLabel* nomeLvl;
    QLabel* nomeForza;
    QLabel* nomeMagia;
    QLabel* nomeDifesa;
    QLabel* nomeScienza;
    QLabel* nomeMedia;
    QLabel* nomeSpeciale;
    QLabel* nomeExp;
    QLabel* nomeTerreno;
    QLabel* labelSesso;
    QLabel* terrenoPreferito;
    QLabel* immagineAvatar;
    QLabel* nome;
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
    QRadioButton* sessoM;
    QRadioButton* sessoF;
    QString pImmagine;

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
    QLabel* getValoreSpeciale() const;
    QLabel* getExp() const;
    QLabel* getNomeLvl() const;
    QLabel* getNomeForza() const;
    QLabel* getNomeMagia() const;
    QLabel* getNomeDifesa() const;
    QLabel* getNomeScienza() const;
    QLabel* getNomeMedia() const;
    QLabel* getNomeSpeciale() const;
    QLabel* getNomeExp() const;
    QLabel* getNomeTerreno() const;
    QLabel* getLabelSesso() const;
    QLabel* getTerrenoPreferito() const;
    QLabel* getImmagineAvatar() const;
    QLabel* getNome() const;
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
    QRadioButton* getSessoM() const;
    QRadioButton* getSessoF() const;
    QString getPercorso() const;

public slots:
    void checkUno();
    void checkDue();
    void checkTre();
    void checkQuattro();
    void checkCinque();
    void checkSei();
    void checkSette();
    void checkOtto();
    void groupTipo();
    void resetTutto() const;
    void resetCheck() const;
    void calcoloValori();
    void setImmagine();
};

#endif // CREAAVATAR_H
