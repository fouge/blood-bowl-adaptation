#include "equipe.h"


Equipe::Equipe(race uneRace, int uneComposition, std::vector<std::vector<Case*>*>* leTerrain):saRace(uneRace)
{

//competences :
//esquive, reception, dexterite, passe, blocage, perso,
//cerveaulent, chataigne, crane, epais, lancercoequipier,
//minus, poidsplume, grosdebile, regeneration, toujoursaffame
    std::vector<competences>* lesCompetencesReceveurs = new std::vector<competences>();
    lesCompetencesReceveurs->push_back(esquive);
    lesCompetencesReceveurs->push_back(reception);

    std::vector<competences>* lesCompetencesPasseurs = new std::vector<competences>();
    lesCompetencesPasseurs->push_back(dexterite);
    lesCompetencesPasseurs->push_back(passe);

    std::vector<competences>* lesCompetencesBlitzeurs = new std::vector<competences>();
    lesCompetencesBlitzeurs->push_back(blocage);

    std::vector<competences>* lesCompetencesOgres = new std::vector<competences>();
    lesCompetencesOgres->push_back(perso);
    lesCompetencesOgres->push_back(cerveauLent);
    lesCompetencesOgres->push_back(chataigne);
    lesCompetencesOgres->push_back(craneEpais);
    lesCompetencesOgres->push_back(lancerCoequipier);

    std::vector<competences>* lesCompetencesGobelins = new std::vector<competences>();
    lesCompetencesGobelins->push_back(esquive);
    lesCompetencesGobelins->push_back(minus);
    lesCompetencesGobelins->push_back(poidsPlume);

    std::vector<competences>* lesCompetencesTroll = new std::vector<competences>();
    lesCompetencesTroll->push_back(perso);
    lesCompetencesTroll->push_back(chataigne);
    lesCompetencesTroll->push_back(grosDebile);
    lesCompetencesTroll->push_back(lancerCoequipier);
    lesCompetencesTroll->push_back(regeneration);
    lesCompetencesTroll->push_back(toujoursAffame);


    std::vector<competences>* AucuneCompetence = new std::vector<competences>();

    sesJoueurs = new std::vector<Joueur*>();

    if(saRace == humains)
    {
        sesJoueurs = new std::vector<Joueur*>();
        switch(uneComposition)
        {
        case 0:
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Leo Ulman", getCase(2, 7, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Baldric Advar", getCase(2, 8, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Bertolf Valdred", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Leo Ulman", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(receveur, (*lesCompetencesReceveurs), 8, 2, 3, 7, "Otto Meinard", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(ogre, (*lesCompetencesOgres), 5, 5, 2, 9, "Maxime Girard", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Edgar Le Couard", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Boris Le Destructeur", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Griswold L'Affreux", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Karl Le Troubadour", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Hob le Bel", getCase(2, 3, leTerrain), debout));
            break;
        case 1:
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Hans Flick", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Gothard Seppel", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(receveur, (*lesCompetencesReceveurs), 8, 2, 3, 7, "Bertolf Gottlob", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(receveur, (*lesCompetencesReceveurs), 8, 2, 3, 7, "Mordred Wilfried", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Gerhart Leopold", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(ogre, (*lesCompetencesOgres), 5, 5, 2, 9, "Aggrut Devis-Tete", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Hector le Bavard", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Admmund le Droit", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Davion le Verteux", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Viggo le Buveur", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Fracist le Gros", getCase(2, 3, leTerrain), debout));
            break;
        case 2:
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Jacob von Altdorf", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Fat Mittbrot", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(receveur, (*lesCompetencesReceveurs), 8, 2, 3, 7, "Fast Ben Jansen", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(receveur, (*lesCompetencesReceveurs), 8, 2, 3, 7, "Gregor Meissen", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Sebastien Chabal", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Christiano Ronaldo", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Cyril Fougeray", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Johnny Boy", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Bobby Marley", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Skrillex", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(ogre, (*lesCompetencesOgres), 5, 5, 2, 9, "Zugg", getCase(2, 3, leTerrain), debout));
            break;

        default: ;
        }
    }
    if(saRace == orques)
    {
        switch(uneComposition)
        {
        case 0:
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Aznok", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Globrotta Casse'Main", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Ulgrot Mange'Coeur", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Ugluk Mange'tete", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Ugroth Casse'Crane", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Mug-guzzla", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Ugglut Gutlug", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Flashgit-Stompfoot", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Roglut-Zigzagga", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(gobelin, (*lesCompetencesGobelins), 6, 2, 3, 7, "Kursh", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 5, 3, 3, 9, "Moglor", getCase(2, 3, leTerrain), debout));

            break;
        case 1:
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Gorfang MangeTaTete", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Grubak Broye'main", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Golruk Casse'dents", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Grogu Grintouf", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Gutnok", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Muchteef-slogga", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Stilaz", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(gobelin, (*lesCompetencesGobelins), 6, 2, 3, 7, "Makedir", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troll, (*lesCompetencesTroll), 6, 2, 3, 7, "Powed", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 5, 3, 3, 9, "Ragzag", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 5, 3, 3, 9, "Lugnub", getCase(2, 3, leTerrain), debout));

            break;
        case 2:
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Crase'Cerveau", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Ecari'seur", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Crase'Main", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Flatfoot", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Tokber", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Krolor", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 5, 3, 3, 9, "Taksh", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(gobelin, (*lesCompetencesGobelins), 6, 2, 3, 7, "Weeit", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(troll, (*lesCompetencesTroll), 6, 2, 3, 7, "Trak'k", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Gobfang", getCase(2, 3, leTerrain), debout));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Gutslop", getCase(2, 3, leTerrain), debout));
            break;
        default: ;
        }
    }
}

Case* Equipe::getCase(int unX, int unY, std::vector<std::vector<Case*>*>* unTerrain)
{
    std::vector<std::vector<Case*>*>::iterator itX;
    std::vector<Case*>::iterator itY;
    itX = unTerrain->begin()+unX;
    itY = (*itX)->begin()+unY;
    return (*itY);
}
