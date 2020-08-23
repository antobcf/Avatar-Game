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
#include <QTimer>

class ModificaAvatar : public QDialog
{
    Q_OBJECT
private:
    QFormLayout* formCrea;
    QLabel* tipoAvatar;
    QLabel* maxPowerUp;
    QLabel* lvl;
    QLabel* valoreForza;
    QLabel* valoreScienza;
    QLabel* valoreDifesa;
    QLabel* valoreMagia;
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
    QRadioButton* sessoM;
    QRadioButton* sessoF;
    QString pImmagine;

public:
    ModificaAvatar(QWidget * = nullptr);
    QFormLayout* getFormCrea() const;
    QLabel* getTipoAvatar() const;
    QLabel* getMaxPowerUp() const;
    QLabel* getLvl() const;
    QLabel* getValoreForza() const;
    QLabel* getValoreScienza() const;
    QLabel* getValoreDifesa() const;
    QLabel* getValoreMagia() const;
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
    QRadioButton* getSessoM() const;
    QRadioButton* getSessoF() const;
    QString getPercorsoImmagine() const;

    void inserisciPercorso(std::string);

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

#endif // MODIFICAAVATAR_H
