#ifndef ENUM_H
#define ENUM_H

/**
 * \file      enum.h
 * \author    CF-MG
 * \version   1.0
 * \date      7 Mai 2012
 * \brief     Défini toutes les énumérations
 *
 */
enum zone{enbut, laterale, engagement};

enum race{humains, orques};

enum typeJ{blitzeur, troisquarts, receveur, passeur, ogre, gobelin, bloqueur, troll};

enum etat{debout, parterre};

enum competences{esquive, reception, dexterite, passe, blocage, perso,
                 cerveauLent, chataigne, craneEpais, lancerCoequipier,
                 minus, poidsPlume, grosDebile, regeneration, toujoursAffame};

enum coach{joueur1, joueur2};



#endif // ENUM_H
