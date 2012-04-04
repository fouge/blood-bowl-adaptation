#include "equipe.h"
#include "joueur.h"

Equipe::Equipe(race uneRace, int uneComposition, bool cote, TableModel* unModele):saRace(uneRace), sonCote(cote)
{

    Joueur* leJoueurModele = new Joueur(unModele);
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
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Leo Ulman", 12, 12, sonCote));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Baldric Advar", 12, 2, sonCote));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Bertolf Valdred", 5, 7, sonCote));
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Leo Ulman", 1, 1, sonCote));
            sesJoueurs->push_back(new Joueur(receveur, (*lesCompetencesReceveurs), 8, 2, 3, 7, "Otto Meinard", 2, 9, sonCote));
            sesJoueurs->push_back(new Joueur(ogre, (*lesCompetencesOgres), 5, 5, 2, 9, "Maxime Girard", 12,7, sonCote));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Edgar Le Couard",12, 10, sonCote));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Boris Le Destructeur", 12, 4, sonCote));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Griswold L'Affreux", 8, 13, sonCote));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Karl Le Troubadour", 8, 1, sonCote));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Hob le Bel",2, 3, sonCote));
            break;
        case 1:
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Hans Flick", 2, 3, sonCote));
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Gothard Seppel", 2, 3, sonCote));
            sesJoueurs->push_back(new Joueur(receveur, (*lesCompetencesReceveurs), 8, 2, 3, 7, "Bertolf Gottlob",2, 3, sonCote));
            sesJoueurs->push_back(new Joueur(receveur, (*lesCompetencesReceveurs), 8, 2, 3, 7, "Mordred Wilfried", 2, 3, sonCote));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Gerhart Leopold",2, 3, sonCote));
            sesJoueurs->push_back(new Joueur(ogre, (*lesCompetencesOgres), 5, 5, 2, 9, "Aggrut Devis-Tete", 2, 3, sonCote));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Hector le Bavard", 2, 3, sonCote));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Admmund le Droit", 2, 3, sonCote));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Davion le Verteux", 2, 3, sonCote));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Viggo le Buveur", 2, 3, sonCote));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Fracist le Gros", 2, 3, sonCote));
            break;
        case 2:
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Jacob von Altdorf",2, 3, sonCote));
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Fat Mittbrot", 2, 3, sonCote));
            sesJoueurs->push_back(new Joueur(receveur, (*lesCompetencesReceveurs), 8, 2, 3, 7, "Fast Ben Jansen", 2, 3, sonCote));
            sesJoueurs->push_back(new Joueur(receveur, (*lesCompetencesReceveurs), 8, 2, 3, 7, "Gregor Meissen", 2, 3, sonCote));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Sebastien Chabal", 2, 3,  sonCote));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Christiano Ronaldo", 2, 3,  sonCote));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Cyril Fougeray", 2, 3,  sonCote));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Johnny Boy",2, 3,  sonCote));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Bobby Marley",2, 3,  sonCote));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 6, 3, 3, 8, "Skrillex", 2, 3,  sonCote));
            sesJoueurs->push_back(new Joueur(ogre, (*lesCompetencesOgres), 5, 5, 2, 9, "Zugg", 2, 3,  sonCote));
            break;

        default: ;
        }
    }
    if(saRace == orques)
    {
        switch(uneComposition)
        {
        case 0:
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Aznok", 1 , 1, sonCote));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Globrotta Casse'Main", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Ulgrot Mange'Coeur", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Ugluk Mange'tete", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Ugroth Casse'Crane", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Mug-guzzla", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Ugglut Gutlug", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Flashgit-Stompfoot", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Roglut-Zigzagga", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(gobelin, (*lesCompetencesGobelins), 6, 2, 3, 7, "Kursh", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 5, 3, 3, 9, "Moglor", 2 , 3, sonCote));

            break;
        case 1:
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Gorfang MangeTaTete", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Grubak Broye'main", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Golruk Casse'dents", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Grogu Grintouf", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Gutnok", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Muchteef-slogga", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Stilaz", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(gobelin, (*lesCompetencesGobelins), 6, 2, 3, 7, "Makedir", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(troll, (*lesCompetencesTroll), 6, 2, 3, 7, "Powed", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 5, 3, 3, 9, "Ragzag", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 5, 3, 3, 9, "Lugnub", 2 , 3, sonCote));

            break;
        case 2:
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Crase'Cerveau", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Ecari'seur", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Crase'Main", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Flatfoot", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Tokber", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(passeur, (*lesCompetencesPasseurs), 6, 3, 3, 8, "Krolor", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(troisquarts, (*AucuneCompetence), 5, 3, 3, 9, "Taksh", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(gobelin, (*lesCompetencesGobelins), 6, 2, 3, 7, "Weeit", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(troll, (*lesCompetencesTroll), 6, 2, 3, 7, "Trak'k", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(bloqueur, (*AucuneCompetence), 4, 4, 2, 9, "Gobfang", 2 , 3, sonCote));
            sesJoueurs->push_back(new Joueur(blitzeur, (*lesCompetencesBlitzeurs), 7, 3, 3, 8, "Gutslop", 2 , 3, sonCote));
            break;
        default: ;
        }
    }
}

