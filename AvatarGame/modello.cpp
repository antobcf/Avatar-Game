#include "modello.h"

Modello::Modello(std::string p) : lista(new Container<Avatar*>), salvato(true), percorso(p) {}


Modello::~Modello()
{
    delete lista;
}

void Modello::salvare()
{
    QSaveFile fileS(QString::fromStdString(percorso));

    if(!fileS.open(QIODevice::WriteOnly)) {
        return;
    }

    QXmlStreamWriter reader(&fileS);
    reader.setAutoFormatting(true);
    reader.writeStartDocument();
    reader.writeComment("!!!Non commentare il documento!!!");
    reader.writeStartElement("start");

    auto it = beginConst();
    while(it != endConst()) {
        const Avatar* salvaElemento = *it;
        const QString tipo = QString::fromStdString(salvaElemento->getTerrNon());
        const QString tipoAvatar = QString::fromStdString(salvaElemento->getTipo());
        reader.writeEmptyElement(tipoAvatar);
        reader.writeAttribute("Nome", QString::fromStdString(salvaElemento->GetNome()));
        reader.writeAttribute("Descrizione", QString::fromStdString(salvaElemento->getDescrizione()));
        reader.writeAttribute("Livello", QString("%1").arg(salvaElemento->GetLiv()));
        reader.writeAttribute("Exp", QString("%1").arg(salvaElemento->GetExp()));
        reader.writeAttribute("Forza", QString("%1").arg(salvaElemento->getForza()));
        reader.writeAttribute("Magia", QString("%1").arg(salvaElemento->getMagia()));
        reader.writeAttribute("Difesa", QString("%1").arg(salvaElemento->getDifesa()));
        reader.writeAttribute("Scienza", QString("%1").arg(salvaElemento->getScienza()));
        reader.writeAttribute("Sesso", salvaElemento->GetSesso() ? "true" : "false");
        reader.writeAttribute("Percorso", QString::fromStdString(salvaElemento->getPercorsoImmagine()));
        reader.writeAttribute("Media", QString("%1").arg(salvaElemento->getMedia())); //è un double quindio non so se vada bene
        reader.writeAttribute("Terreno", QString::fromStdString(salvaElemento->getTerreno()));
        if(tipo == "Terrestre") {
            const Terrestre* tipoTerrestre = static_cast<const Terrestre*>(salvaElemento);
            reader.writeAttribute("Scudo", tipoTerrestre->GetScu() ? "true" : "false");
            reader.writeAttribute("Spada", tipoTerrestre->GetSpada() ? "true" : "false");
            reader.writeAttribute("Anello", tipoTerrestre->GetAnello() ? "true" : "false");
            reader.writeAttribute("Libro", tipoTerrestre->GetLibro() ? "true" : "false");
            if(tipoAvatar == "Elfo") {
                const Elfo* tipoElfo = static_cast<const Elfo*>(tipoTerrestre); //o salvaElemento??
                reader.writeAttribute("Trasparentia", QString("%1").arg(tipoElfo->GetTrasparentia()));
            } else if(tipoAvatar == "Nano") {
                const Nano* tipoNano = static_cast<const Nano*>(tipoTerrestre);
                reader.writeAttribute("Corteccia", QString("%1").arg(tipoNano->GetCorteccia()));
            } else if(tipoAvatar == "Umano") {
                const Umano* tipoUmano = static_cast<const Umano*>(tipoTerrestre);
                reader.writeAttribute("Ingegnoscientifico", QString("%1").arg(tipoUmano->GetIngegno()));
            }
        } else if (tipo == "Non terrestre") {
            const NOTerrestre* tipoNoTerrestre = static_cast<const NOTerrestre*>(salvaElemento);
            reader.writeAttribute("Barriera", tipoNoTerrestre->GetBar() ? "true" : "false");
            reader.writeAttribute("Laser", tipoNoTerrestre->GetLaser() ? "true" : "false");
            reader.writeAttribute("Amuleto", tipoNoTerrestre->GetAmuleto() ? "true" : "false");
            reader.writeAttribute("Chip", tipoNoTerrestre->GetChip() ? "true" : "false");
            if(tipoAvatar == "Alieno") {
                const Alieno* tipoAlieno = static_cast<const Alieno*>(tipoNoTerrestre);
                reader.writeAttribute("Ufo", QString("%1").arg(tipoAlieno->GetUfo()));
            } else if(tipoAvatar == "Mostro") {
                const Mostro* tipoMostro = static_cast<const Mostro*>(tipoNoTerrestre);
                reader.writeAttribute("Portademoniaca", QString("%1").arg(tipoMostro->GetPorta())); //con lo spazio tra porta e demoniaca non funziona
            }
        }

        ++it;
    }

    reader.writeEndElement();
    reader.writeEndDocument();
    salvato = true;
    fileS.commit();

}

void Modello::caricare()
{
    QFile fileC(QString::fromStdString(percorso));

    if(!fileC.open(QIODevice::ReadOnly)) {
        qWarning() << "Apertura file fallita !!!"<<fileC.errorString();
        return;
    }

    QXmlStreamReader reader(&fileC);
    if(reader.readNextStartElement()) {
        if(reader.name() == "start") {
            while(reader.readNextStartElement()) {
                const QXmlStreamAttributes newAttributo = reader.attributes();

                std::string nome = newAttributo.hasAttribute("Nome") ? newAttributo.value("Nome").toString().toStdString() : "";
                std::string descrizione = newAttributo.hasAttribute("Descrizione") ? newAttributo.value("Descrizione").toString().toStdString() : "";
                unsigned int lvl = newAttributo.hasAttribute("Livello") ? newAttributo.value("Livello").toUInt() : 0;
                unsigned int exp = newAttributo.hasAttribute("Exp") ? newAttributo.value("Exp").toUInt() : 0;
                unsigned int forza = newAttributo.hasAttribute("Forza") ? newAttributo.value("Forza").toUInt() : 0;
                unsigned int magia = newAttributo.hasAttribute("Magia") ? newAttributo.value("Magia").toUInt() : 0;
                unsigned int difesa = newAttributo.hasAttribute("Difesa") ? newAttributo.value("Difesa").toUInt() : 0;
                unsigned int scienza = newAttributo.hasAttribute("Scienza") ? newAttributo.value("Scienza").toUInt() : 0;
                bool sesso = newAttributo.hasAttribute("Sesso") ? newAttributo.value("Sesso").toString() == "true" ? true : false : false;
                std::string percorso = newAttributo.hasAttribute("Percorso") ? newAttributo.value("Percorso").toString().toStdString() : "";
                double media = newAttributo.hasAttribute("Media") ? newAttributo.value("Media").toDouble() : 0;
                std::string terreno = newAttributo.hasAttribute("Terreno") ? newAttributo.value("Terreno").toString().toStdString() : "";

                Avatar* inserire = nullptr;

                if(reader.name() == "Elfo") {
                    bool scudo = newAttributo.hasAttribute("Scudo") ? newAttributo.value("Scudo").toString() == "true" ? true : false : false;
                    bool spada = newAttributo.hasAttribute("Spada") ? newAttributo.value("Spada").toString() == "true" ? true : false : false;
                    bool anello = newAttributo.hasAttribute("Anello") ? newAttributo.value("Anello").toString() == "true" ? true : false : false;
                    bool libro = newAttributo.hasAttribute("Libro") ? newAttributo.value("Libro").toString() == "true" ? true : false : false;
                    unsigned int trasparentia = newAttributo.hasAttribute("Trasparentia") ? newAttributo.value("Trasparentia").toUInt() : 0;
                    inserire = new Elfo(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, percorso, scudo, spada, anello, libro, trasparentia);
                } else if(reader.name() == "Nano") {
                    bool scudo = newAttributo.hasAttribute("Scudo") ? newAttributo.value("Scudo").toString() == "true" ? true : false : false;
                    bool spada = newAttributo.hasAttribute("Spada") ? newAttributo.value("Spada").toString() == "true" ? true : false : false;
                    bool anello = newAttributo.hasAttribute("Anello") ? newAttributo.value("Anello").toString() == "true" ? true : false : false;
                    bool libro = newAttributo.hasAttribute("Libro") ? newAttributo.value("Libro").toString() == "true" ? true : false : false;
                    unsigned int corteccia = newAttributo.hasAttribute("Corteccia") ? newAttributo.value("Corteccia").toUInt() : 0;
                    inserire = new Nano(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, percorso, scudo, spada, anello, libro, corteccia);
                } else if(reader.name() == "Umano") {
                    bool scudo = newAttributo.hasAttribute("Scudo") ? newAttributo.value("Scudo").toString() == "true" ? true : false : false;
                    bool spada = newAttributo.hasAttribute("Spada") ? newAttributo.value("Spada").toString() == "true" ? true : false : false;
                    bool anello = newAttributo.hasAttribute("Anello") ? newAttributo.value("Anello").toString() == "true" ? true : false : false;
                    bool libro = newAttributo.hasAttribute("Libro") ? newAttributo.value("Libro").toString() == "true" ? true : false : false;
                    unsigned int ingegno = newAttributo.hasAttribute("Ingegnoscientifico") ? newAttributo.value("Ingegnoscientifico").toUInt() : 0; //qui invece avere lo spazio non conta nulla
                    inserire = new Umano(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, percorso, scudo, spada, anello, libro, ingegno);
                } else if(reader.name() == "Alieno") {
                    bool barriera = newAttributo.hasAttribute("Barriera") ? newAttributo.value("Barriera").toString() == "true" ? true : false : false;
                    bool laser = newAttributo.hasAttribute("Laser") ? newAttributo.value("Laser").toString() == "true" ? true : false : false;
                    bool amuleto = newAttributo.hasAttribute("Amuleto") ? newAttributo.value("Amuleto").toString() == "true" ? true : false : false;
                    bool chip = newAttributo.hasAttribute("Chip") ? newAttributo.value("Chip").toString() == "true" ? true : false : false;
                    unsigned int ufo = newAttributo.hasAttribute("Ufo") ? newAttributo.value("Ufo").toUInt() : 0;
                    inserire = new Alieno(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, percorso, barriera, laser, amuleto, chip, ufo);
                } else if(reader.name() == "Mostro") {
                    bool barriera = newAttributo.hasAttribute("Barriera") ? newAttributo.value("Barriera").toString() == "true" ? true : false : false;
                    bool laser = newAttributo.hasAttribute("Laser") ? newAttributo.value("Laser").toString() == "true" ? true : false : false;
                    bool amuleto = newAttributo.hasAttribute("Amuleto") ? newAttributo.value("Amuleto").toString() == "true" ? true : false : false;
                    bool chip = newAttributo.hasAttribute("Chip") ? newAttributo.value("Chip").toString() == "true" ? true : false : false;
                    unsigned int porta = newAttributo.hasAttribute("Portademoniaca") ? newAttributo.value("Portademoniaca").toUInt() : 0;
                    inserire = new Mostro(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, percorso, barriera, laser, amuleto, chip, porta);
                }

                if(inserire!=nullptr) {
                    lista->inserisci(inserire);
                }

                if(!reader.isEndDocument()) {
                    reader.skipCurrentElement();
                }
            }
        }
    }

    salvato = true;
    fileC.close();
}

void Modello::rimuovi(Avatar* a)
{
    lista->removeElement(a);
}

void Modello::rimuoviTutto()
{
    Container<Avatar*>::iteratore inizio = lista->begin();
    Container<Avatar*>::iteratore fine = lista->end();

    if(inizio != fine) {
        rimuovi(*inizio);
        ++inizio;
    }
}

void Modello::setPercorso(std::string p)
{
    percorso = p;
    delete lista;
    salvato = false;
    lista = new Container<Avatar*>();
}

Container<Avatar*> *Modello::getLista() const
{
    return lista;
}

Container<Avatar*>::iteratore Modello::begin()
{
    return lista->begin();
}

Container<Avatar*>::iteratore Modello::end()
{
    return lista->end();
}

Container<Avatar*>::iteratoreConst Modello::beginConst() const
{
    return lista->beginC();
}

Container<Avatar*>::iteratoreConst Modello::endConst() const
{
    return lista->endC();
}
