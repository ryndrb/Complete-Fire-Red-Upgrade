#include "../config.h"
#include "../../include/global.h"
#include "../../include/constants/maps.h"
#include "../../include/wild_encounter.h"
#include "../../include/constants/region_map_sections.h"
#include "../../include/constants/species.h"

/*
wild_encounter_tables.c
	day/night and/or regular map wild encounter species

tables to edit:
	gWildMonMorningHeaders
	gWildMonEveningHeaders
	gWildMonNightHeaders
	gSwarmTable

*/
//Modify this section

// adapted most of Radical Red encounter table since there's sooo many mons and it's a pain. Big credits to soupercell
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Pallet Town
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gPalletTown_SurfMons[] = 
{
	{50, 60, SPECIES_TENTACRUEL},//60
	{50, 60, SPECIES_CRAWDAUNT},//30
	{50, 60, SPECIES_GRAPPLOCT},//5
	{50, 60, SPECIES_CLOYSTER},//4
	{50, 60, SPECIES_BARRASKEWDA},//1
};
const struct WildPokemonInfo gPalletTown_SurfMonsInfo = {21, gPalletTown_SurfMons};

const struct WildPokemon gPalletTown_FishingMons[] = 
{
	{ 3,  5, SPECIES_TENTACOOL},//old rod 70
	{ 3,  5, SPECIES_SHELLDER},//old rod 30
	{25, 28, SPECIES_BASCULIN_BLUE},//good rod 60
	{25, 28, SPECIES_INKAY},//good rod 20
	{25, 28, SPECIES_PYUKUMUKU},//good rod 20
	{50, 55, SPECIES_ALOMOMOLA},//super rod 40
	{50, 55, SPECIES_ALOMOMOLA},//super rod 40
	{50, 55, SPECIES_CRAWDAUNT},//super rod 15
	{50, 55, SPECIES_MANTINE},//super rod 4
	{50, 55, SPECIES_MALAMAR},//super rod 1
};
const struct WildPokemonInfo gPalletTown_FishingMonsInfo = {21, gPalletTown_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 21
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute21_LandMonsMorning[] = 
{
	{2, 4, SPECIES_MEOWTH},//20
	{2, 4, SPECIES_WINGULL},//20
	{2, 4, SPECIES_MEOWTH},//10
	{2, 4, SPECIES_WINGULL},//10
	{2, 4, SPECIES_BOUNSWEET},//10
	{2, 4, SPECIES_BOUNSWEET},//10
	{2, 4, SPECIES_ROCKRUFF},//5
	{2, 4, SPECIES_ROCKRUFF},//5
	{2, 4, SPECIES_ZIGZAGOON},//4
	{2, 4, SPECIES_ZIGZAGOON},//4
	{2, 4, SPECIES_TYROGUE},//1
	{2, 4, SPECIES_TYROGUE},//1
};
const struct WildPokemonInfo gRoute21_LandMonsMorningInfo = {21, gRoute21_LandMonsMorning};

const struct WildPokemon gRoute21_LandMonsNight[] = 
{
	{2, 4, SPECIES_POOCHYENA},//20
	{2, 4, SPECIES_BUNNELBY},//20
	{2, 4, SPECIES_POOCHYENA},//10
	{2, 4, SPECIES_BUNNELBY},//10
	{2, 4, SPECIES_KRICKETOT},//10
	{2, 4, SPECIES_KRICKETOT},//10
	{2, 4, SPECIES_YUNGOOS},//5
	{2, 4, SPECIES_YUNGOOS},//5
	{2, 4, SPECIES_PURRLOIN},//4
	{2, 4, SPECIES_PURRLOIN},//4
	{2, 4, SPECIES_EEVEE},//1
	{2, 4, SPECIES_EEVEE},//1
};
const struct WildPokemonInfo gRoute21_LandMonsNightInfo = {21, gRoute21_LandMonsNight};

const struct WildPokemon gRoute21A_SurfMons[] = 
{
	{50, 60, SPECIES_TENTACRUEL},//60
	{50, 60, SPECIES_CRAWDAUNT},//30
	{50, 60, SPECIES_GRAPPLOCT},//5
	{50, 60, SPECIES_CLOYSTER},//4
	{50, 60, SPECIES_BARRASKEWDA},//1
};
const struct WildPokemonInfo gRoute21A_SurfMonsInfo = {21, gRoute21A_SurfMons};

const struct WildPokemon gRoute21A_FishingMons[] = 
{
	{ 3,  5, SPECIES_BUIZEL},//old rod 70
	{ 3,  5, SPECIES_MANTYKE},//old rod 30
	{25, 28, SPECIES_QWILFISH},//good rod 60
	{25, 28, SPECIES_CLAMPERL},//good rod 20
	{25, 28, SPECIES_CLOBBOPUS},//good rod 20
	{50, 55, SPECIES_MANTINE},//super rod 40
	{50, 55, SPECIES_CRAWDAUNT},//super rod 40
	{50, 55, SPECIES_GOREBYSS},//super rod 15
	{50, 55, SPECIES_GOREBYSS},//super rod 4
	{50, 55, SPECIES_WAILORD},//super rod 1
};
const struct WildPokemonInfo gRoute21A_FishingMonsInfo = {21, gRoute21A_FishingMons};

const struct WildPokemon gRoute21B_SurfMons[] = 
{
	{50, 60, SPECIES_TENTACRUEL},//60
	{50, 60, SPECIES_TENTACRUEL},//30
	{50, 60, SPECIES_GRAPPLOCT},//5
	{50, 60, SPECIES_CLOYSTER},//4
	{50, 60, SPECIES_BARRASKEWDA},//1
};
const struct WildPokemonInfo gRoute21B_SurfMonsInfo = {21, gRoute21B_SurfMons};

const struct WildPokemon gRoute21B_FishingMons[] = 
{
	{ 3,  5, SPECIES_MANTYKE},//old rod 70
	{ 3,  5, SPECIES_REMORAID},//old rod 30
	{25, 28, SPECIES_LUVDISC},//good rod 60
	{25, 28, SPECIES_CLAMPERL},//good rod 20
	{25, 28, SPECIES_CORSOLA},//good rod 20
	{50, 55, SPECIES_MANTINE},//super rod 40
	{50, 55, SPECIES_MANTINE},//super rod 40
	{50, 55, SPECIES_HUNTAIL},//super rod 15
	{50, 55, SPECIES_HUNTAIL},//super rod 4
	{50, 55, SPECIES_WAILORD},//super rod 1
};
const struct WildPokemonInfo gRoute21B_FishingMonsInfo = {21, gRoute21B_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 1
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute1_LandMonsMorning[] = 
{
	{2, 4, SPECIES_RATTATA},//20
	{2, 4, SPECIES_PIDGEY},//20
	{2, 4, SPECIES_RATTATA},//10
	{2, 4, SPECIES_PIDGEY},//10
	{2, 4, SPECIES_ROCKRUFF},//10
	{2, 4, SPECIES_ROCKRUFF},//10
	{2, 4, SPECIES_MEOWTH},//5
	{2, 4, SPECIES_MEOWTH},//5
	{2, 4, SPECIES_PIKIPEK},//4
	{2, 4, SPECIES_PIKIPEK},//4
	{2, 4, SPECIES_PANSEAR},//1
	{2, 4, SPECIES_PANSEAR},//1
};
const struct WildPokemonInfo gRoute1_LandMonsMorningInfo = {21, gRoute1_LandMonsMorning};

const struct WildPokemon gRoute1_LandMonsNight[] = 
{
	{2, 4, SPECIES_PATRAT},//20
	{2, 4, SPECIES_NATU},//20
	{2, 4, SPECIES_PATRAT},//10
	{2, 4, SPECIES_NATU},//10
	{2, 4, SPECIES_YUNGOOS},//10
	{2, 4, SPECIES_YUNGOOS},//10
	{2, 4, SPECIES_POOCHYENA},//5
	{2, 4, SPECIES_POOCHYENA},//5
	{2, 4, SPECIES_FLETCHLING},//4
	{2, 4, SPECIES_FLETCHLING},//4
	{2, 4, SPECIES_MIENFOO},//1
	{2, 4, SPECIES_MIENFOO},//1
};
const struct WildPokemonInfo gRoute1_LandMonsNightInfo = {21, gRoute1_LandMonsNight};

const struct WildPokemon gRoute1_SurfMons[] = 
{
	{50, 60, SPECIES_GOLDUCK},//60
	{50, 60, SPECIES_GOLDUCK},//30
	{50, 60, SPECIES_SWANNA},//5
	{50, 60, SPECIES_SWANNA},//4
	{50, 60, SPECIES_MILOTIC},//1
};
const struct WildPokemonInfo gRoute1_SurfMonsInfo = {21, gRoute1_SurfMons};

const struct WildPokemon gRoute1_FishingMons[] = 
{
	{ 3,  5, SPECIES_POLIWAG},//old rod 70
	{ 3,  5, SPECIES_TYMPOLE},//old rod 30
	{25, 28, SPECIES_PSYDUCK},//good rod 60
	{25, 28, SPECIES_CARVANHA},//good rod 20
	{25, 28, SPECIES_CARVANHA},//good rod 20
	{50, 55, SPECIES_GOLDUCK},//super rod 40
	{50, 55, SPECIES_GOLDUCK},//super rod 40
	{50, 55, SPECIES_POLIWRATH},//super rod 15
	{50, 55, SPECIES_POLIWRATH},//super rod 4
	{50, 55, SPECIES_SEISMITOAD},//super rod 1
};
const struct WildPokemonInfo gRoute1_FishingMonsInfo = {21, gRoute1_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Viridian City
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gViridianCity_LandMonsMorning[] = 
{
	{3, 5, SPECIES_TAILLOW},//20
	{3, 5, SPECIES_BIDOOF},//20
	{3, 5, SPECIES_TAILLOW},//10
	{3, 5, SPECIES_BIDOOF},//10
	{3, 5, SPECIES_SKWOVET},//10
	{3, 5, SPECIES_SKWOVET},//10
	{3, 5, SPECIES_MEOWTH},//5
	{3, 5, SPECIES_MEOWTH},//5
	{3, 5, SPECIES_LOTAD},//4
	{3, 5, SPECIES_LOTAD},//4
	{3, 5, SPECIES_YAMPER},//1
	{3, 5, SPECIES_YAMPER},//1
};
const struct WildPokemonInfo gViridianCity_LandMonsMorningInfo = {21, gViridianCity_LandMonsMorning};

const struct WildPokemon gViridianCity_LandMonsNight[] = 
{
	{3, 5, SPECIES_STARLY},//20
	{3, 5, SPECIES_LILLIPUP},//20
	{3, 5, SPECIES_STARLY},//10
	{3, 5, SPECIES_LILLIPUP},//10
	{3, 5, SPECIES_BLIPBUG},//10
	{3, 5, SPECIES_BLIPBUG},//10
	{3, 5, SPECIES_MEOWTH_A},//5
	{3, 5, SPECIES_MEOWTH_G},//5
	{3, 5, SPECIES_SEEDOT},//4
	{3, 5, SPECIES_SEEDOT},//4
	{3, 5, SPECIES_NICKIT},//1
	{3, 5, SPECIES_NICKIT},//1
};
const struct WildPokemonInfo gViridianCity_LandMonsNightInfo = {21, gViridianCity_LandMonsNight};

const struct WildPokemon gViridianCity_SurfMons[] = 
{
	{50, 60, SPECIES_SWANNA},//60
	{50, 60, SPECIES_SWANNA},//30
	{50, 60, SPECIES_LANTURN},//5
	{50, 60, SPECIES_GYARADOS},//4
	{50, 60, SPECIES_MILOTIC},//1
};
const struct WildPokemonInfo gViridianCity_SurfMonsInfo = {21, gViridianCity_SurfMons};

const struct WildPokemon gViridianCity_FishingMons[] = 
{
	{ 3,  5, SPECIES_MAGIKARP},//old rod 70
	{ 3,  5, SPECIES_FEEBAS},//old rod 30
	{25, 28, SPECIES_PSYDUCK},//good rod 60
	{25, 28, SPECIES_BRUXISH},//good rod 20
	{25, 28, SPECIES_BRUXISH},//good rod 20
	{50, 25, SPECIES_GOLDUCK},//super rod 40
	{50, 25, SPECIES_GOLDUCK},//super rod 40
	{50, 25, SPECIES_LANTURN},//super rod 15
	{50, 25, SPECIES_GYARADOS},//super rod 4
	{50, 25, SPECIES_MILOTIC},//super rod 1
};
const struct WildPokemonInfo gViridianCity_FishingMonsInfo = {21, gViridianCity_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 22
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute22_LandMonsMorning[] = 
{
	{4, 6, SPECIES_SPEAROW},//20
	{4, 6, SPECIES_MANKEY},//20
	{4, 6, SPECIES_SPEAROW},//10
	{4, 6, SPECIES_MANKEY},//10
	{4, 6, SPECIES_SANDSHREW},//10
	{4, 6, SPECIES_SANDSHREW},//10
	{4, 6, SPECIES_LOTAD},//5
	{4, 6, SPECIES_LOTAD},//5
	{4, 6, SPECIES_MIENFOO},//4
	{4, 6, SPECIES_MIENFOO},//4
	{4, 6, SPECIES_PANPOUR},//1
	{4, 6, SPECIES_PANPOUR},//1
};
const struct WildPokemonInfo gRoute22_LandMonsMorningInfo = {21, gRoute22_LandMonsMorning};

const struct WildPokemon gRoute22_LandMonsNight[] = 
{
	{4, 6, SPECIES_HOOTHOOT},//20
	{4, 6, SPECIES_PURRLOIN},//20
	{4, 6, SPECIES_HOOTHOOT},//10
	{4, 6, SPECIES_PURRLOIN},//10
	{4, 6, SPECIES_SWINUB},//10
	{4, 6, SPECIES_SWINUB},//10
	{4, 6, SPECIES_SEEDOT},//5
	{4, 6, SPECIES_SEEDOT},//5
	{4, 6, SPECIES_TYROGUE},//4
	{4, 6, SPECIES_TYROGUE},//4
	{4, 6, SPECIES_MILCERY},//1
	{4, 6, SPECIES_MILCERY},//1
};
const struct WildPokemonInfo gRoute22_LandMonsNightInfo = {21, gRoute22_LandMonsNight};

const struct WildPokemon gRoute22_SurfMons[] = 
{
	{50, 60, SPECIES_GOLDUCK},//60
	{50, 60, SPECIES_GOLDUCK},//30
	{50, 60, SPECIES_GASTRODON},//5
	{50, 60, SPECIES_GASTRODON_EAST},//4
	{50, 60, SPECIES_MILOTIC},//1
};
const struct WildPokemonInfo gRoute22_SurfMonsInfo = {21, gRoute22_SurfMons};

const struct WildPokemon gRoute22_FishingMons[] = 
{
	{ 3,  5, SPECIES_POLIWAG},//old rod 70
	{ 3,  5, SPECIES_SHELLOS},//old rod 30
	{25, 28, SPECIES_PSYDUCK},//good rod 60
	{25, 28, SPECIES_CARVANHA},//good rod 20
	{25, 28, SPECIES_CARVANHA},//good rod 20
	{50, 55, SPECIES_GOLDUCK},//super rod 40
	{50, 55, SPECIES_GOLDUCK},//super rod 40
	{50, 55, SPECIES_POLIWRATH},//super rod 15
	{50, 55, SPECIES_POLIWRATH},//super rod 4
	{50, 55, SPECIES_GYARADOS},//super rod 1
};
const struct WildPokemonInfo gRoute22_FishingMonsInfo = {21, gRoute22_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 2
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute2_LandMonsMorning[] = 
{
	{4, 6, SPECIES_SENTRET},//20
	{4, 6, SPECIES_ZIGZAGOON},//20
	{4, 6, SPECIES_SENTRET},//10
	{4, 6, SPECIES_ZIGZAGOON},//10
	{4, 6, SPECIES_ODDISH},//10
	{4, 6, SPECIES_ODDISH},//10
	{4, 6, SPECIES_WOOLOO},//5
	{4, 6, SPECIES_WOOLOO},//5
	{4, 6, SPECIES_PONYTA},//4
	{4, 6, SPECIES_PONYTA},//4
	{4, 6, SPECIES_PANSAGE},//1
	{4, 6, SPECIES_PANSAGE},//1
};
const struct WildPokemonInfo gRoute2_LandMonsMorningInfo = {21, gRoute2_LandMonsMorning};

const struct WildPokemon gRoute2_LandMonsNight[] = 
{
	{4, 6, SPECIES_PIDOVE},//20
	{4, 6, SPECIES_ZIGZAGOON_G},//20
	{4, 6, SPECIES_PIDOVE},//10
	{4, 6, SPECIES_ZIGZAGOON_G},//10
	{4, 6, SPECIES_VENONAT},//10
	{4, 6, SPECIES_VENONAT},//10
	{4, 6, SPECIES_ELDEGOSS},//5 
	{4, 6, SPECIES_ELDEGOSS},//5
	{4, 6, SPECIES_PONYTA_G},//4
	{4, 6, SPECIES_PONYTA_G},//4
	{4, 6, SPECIES_FOMANTIS},//1
	{4, 6, SPECIES_FOMANTIS},//1
};
const struct WildPokemonInfo gRoute2_LandMonsNightInfo = {21, gRoute2_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Viridian Forest
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gViridianForest_LandMonsMorning[] = 
{
	{6, 8, SPECIES_CATERPIE},//20
	{6, 8, SPECIES_WEEDLE},//20
	{6, 8, SPECIES_CATERPIE},//10
	{6, 8, SPECIES_WEEDLE},//10
	{6, 8, SPECIES_STARLY},//10
	{6, 8, SPECIES_STARLY},//10
	{6, 8, SPECIES_VOLBEAT},//5
	{6, 8, SPECIES_VOLBEAT},//5
	{6, 8, SPECIES_FOMANTIS},//4
	{6, 8, SPECIES_FOMANTIS},//4
	{6, 8, SPECIES_PUMPKABOO},//1
	{6, 8, SPECIES_PUMPKABOO},//1
};
const struct WildPokemonInfo gViridianForest_LandMonsMorningInfo = {21, gViridianForest_LandMonsMorning};

const struct WildPokemon gViridianForest_LandMonsNight[] = 
{
	{6, 8, SPECIES_SPINARAK},//20
	{6, 8, SPECIES_WURMPLE},//20
	{6, 8, SPECIES_SPINARAK},//10
	{6, 8, SPECIES_WURMPLE},//10
	{6, 8, SPECIES_EKANS},//10
	{6, 8, SPECIES_EKANS},//10
	{6, 8, SPECIES_ILLUMISE},//5
	{6, 8, SPECIES_ILLUMISE},//5
	{6, 8, SPECIES_VENIPEDE},//4
	{6, 8, SPECIES_VENIPEDE},//4
	{6, 8, SPECIES_PHANTUMP},//1
	{6, 8, SPECIES_PHANTUMP},//1
};
const struct WildPokemonInfo gViridianForest_LandMonsNightInfo = {21, gViridianForest_LandMonsNight};

const struct WildPokemon gViridianForest_SurfMons[] = 
{
	{50, 60, SPECIES_LANTURN},//60
	{50, 60, SPECIES_LANTURN},//30
	{50, 60, SPECIES_WHISCASH},//5
	{50, 60, SPECIES_LUMINEON},//4
	{50, 60, SPECIES_JELLICENT},//1
};
const struct WildPokemonInfo gViridianForest_SurfMonsInfo = {21, gViridianForest_SurfMons};

const struct WildPokemon gViridianForest_FishingMons[] = 
{
	{ 3,  5, SPECIES_DEWPIDER},//old rod 70
	{ 3,  5, SPECIES_CHINCHOU},//old rod 30
	{25, 28, SPECIES_BARBOACH},//good rod 60
	{25, 28, SPECIES_WIMPOD},//good rod 20
	{25, 28, SPECIES_FINNEON},//good rod 20
	{50, 55, SPECIES_LANTURN},//super rod 40
	{50, 55, SPECIES_LANTURN},//super rod 40
	{50, 55, SPECIES_WHISCASH},//super rod 15
	{50, 55, SPECIES_LUMINEON},//super rod 4
	{50, 55, SPECIES_ARAQUANID},//super rod 1
};
const struct WildPokemonInfo gViridianForest_FishingMonsInfo = {21, gViridianForest_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Pewter City
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gPewterCity_LandMonsMorning[] = 
{
	{9, 11, SPECIES_BELLSPROUT},//20
	{9, 11, SPECIES_BUNEARY},//20
	{9, 11, SPECIES_BELLSPROUT},//10
	{9, 11, SPECIES_BUNEARY},//10
	{9, 11, SPECIES_SURSKIT},//10
	{9, 11, SPECIES_SURSKIT},//10
	{9, 11, SPECIES_PIDOVE},//5
	{9, 11, SPECIES_PIDOVE},//5
	{9, 11, SPECIES_FLABEBE},//4
	{9, 11, SPECIES_FLABEBE},//4
	{9, 11, SPECIES_RALTS},//1
	{9, 11, SPECIES_RALTS},//1
};
const struct WildPokemonInfo gPewterCity_LandMonsMorningInfo = {21, gPewterCity_LandMonsMorning};

const struct WildPokemon gPewterCity_LandMonsNight[] = 
{
	{9, 11,	SPECIES_PIDGEY},//20
	{9, 11,	SPECIES_NICKIT},//20
	{9, 11,	SPECIES_PIDGEY},//10
	{9, 11,	SPECIES_NICKIT},//10
	{9, 11,	SPECIES_LEDYBA},//10
	{9, 11,	SPECIES_LEDYBA},//10
	{9, 11, SPECIES_CUTIEFLY},//5 
	{9, 11, SPECIES_CUTIEFLY},//5
	{9, 11, SPECIES_SHINX},//4
	{9, 11, SPECIES_SHINX},//4
	{9, 11, SPECIES_PIKACHU},//1
	{9, 11, SPECIES_PIKACHU},//1
};
const struct WildPokemonInfo gPewterCity_LandMonsNightInfo = {21, gPewterCity_LandMonsNight};

const struct WildPokemon gPewterCity_SurfMons[] = 
{
	{50, 60, SPECIES_GOLDUCK},//60
	{50, 60, SPECIES_GOLDUCK},//30
	{50, 60, SPECIES_SWANNA},//5
	{50, 60, SPECIES_GYARADOS},//4
	{50, 60, SPECIES_MILOTIC},//1
};
const struct WildPokemonInfo gPewterCity_SurfMonsInfo = {21, gPewterCity_SurfMons};

const struct WildPokemon gPewterCity_FishingMons[] = 
{
	{ 3,  5, SPECIES_WOOPER},//old rod 70
	{ 3,  5, SPECIES_MARILL},//old rod 30
	{25, 28, SPECIES_PSYDUCK},//good rod 60
	{25, 28, SPECIES_AZUMARILL},//good rod 20
	{25, 28, SPECIES_AZUMARILL},//good rod 20
	{50, 55, SPECIES_GOLDUCK},//super rod 40
	{50, 55, SPECIES_GOLDUCK},//super rod 40
	{50, 55, SPECIES_LANTURN},//super rod 15
	{50, 55, SPECIES_GYARADOS},//super rod 4
	{50, 55, SPECIES_MILOTIC},//super rod 1
};
const struct WildPokemonInfo gPewterCity_FishingMonsInfo = {21, gPewterCity_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 3
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute3_LandMonsMorning[] = 
{
	{11, 13, SPECIES_NIDORAN_F},//20
	{11, 13, SPECIES_KARRABLAST},//20
	{11, 13, SPECIES_NIDORAN_F},//10
	{11, 13, SPECIES_KARRABLAST},//10
	{11, 13, SPECIES_SNOVER},//10
	{11, 13, SPECIES_SNOVER},//10
	{11, 13, SPECIES_MAREEP},//5
	{11, 13, SPECIES_MAREEP},//5
	{11, 13, SPECIES_SKIDDO},//4
	{11, 13, SPECIES_SKIDDO},//4
	{11, 13, SPECIES_CRABRAWLER},//1
	{11, 13, SPECIES_CRABRAWLER},//1
};
const struct WildPokemonInfo gRoute3_LandMonsMorningInfo = {21, gRoute3_LandMonsMorning};

const struct WildPokemon gRoute3_LandMonsNight[] = 
{
	{11, 13, SPECIES_NIDORAN_M},//20
	{11, 13, SPECIES_DODUO},//20
	{11, 13, SPECIES_NIDORAN_M},//10
	{11, 13, SPECIES_DODUO},//10
	{11, 13, SPECIES_SEWADDLE},//10
	{11, 13, SPECIES_SEWADDLE},//10
	{11, 13, SPECIES_GRUBBIN},//5 
	{11, 13, SPECIES_GRUBBIN},//5
	{11, 13, SPECIES_MORELULL},//4
	{11, 13, SPECIES_MORELULL},//4
	{11, 13, SPECIES_SCRAGGY},//1
	{11, 13, SPECIES_SCRAGGY},//1
};
const struct WildPokemonInfo gRoute3_LandMonsNightInfo = {21, gRoute3_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 4
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute4_LandMonsMorning[] = 
{
	{14, 16, SPECIES_COMBEE},//20
	{14, 16, SPECIES_HOPPIP},//20
	{14, 16, SPECIES_COMBEE},//10
	{14, 16, SPECIES_HOPPIP},//10
	{14, 16, SPECIES_DUSTOX},//10
	{14, 16, SPECIES_DUSTOX},//10
	{14, 16, SPECIES_JIGGLYPUFF},//5
	{14, 16, SPECIES_JIGGLYPUFF},//5
	{14, 16, SPECIES_BLITZLE},//4
	{14, 16, SPECIES_BLITZLE},//4
	{14, 16, SPECIES_AUDINO},//1
	{14, 16, SPECIES_AUDINO},//1
};
const struct WildPokemonInfo gRoute4_LandMonsMorningInfo = {21, gRoute4_LandMonsMorning};

const struct WildPokemon gRoute4_LandMonsNight[] = 
{
	{14, 16, SPECIES_BURMY},//20
	{14, 16, SPECIES_BUDEW},//20
	{14, 16, SPECIES_BURMY},//10
	{14, 16, SPECIES_BUDEW},//10
	{14, 16, SPECIES_BEAUTIFLY},//10
	{14, 16, SPECIES_BEAUTIFLY},//10
	{14, 16, SPECIES_APPLIN},//5 
	{14, 16, SPECIES_APPLIN},//5
	{14, 16, SPECIES_JOLTIK},//4
	{14, 16, SPECIES_JOLTIK},//4
	{14, 16, SPECIES_SLAKOTH},//1
	{14, 16, SPECIES_SLAKOTH},//1
};
const struct WildPokemonInfo gRoute4_LandMonsNightInfo = {21, gRoute4_LandMonsNight};

const struct WildPokemon gRoute4_SurfMons[] = 
{
	{50, 60, SPECIES_LANTURN},//60
	{50, 60, SPECIES_LANTURN},//30
	{50, 60, SPECIES_GASTRODON},//5
	{50, 60, SPECIES_TOXAPEX},//4
	{50, 60, SPECIES_JELLICENT_F},//1
};
const struct WildPokemonInfo gRoute4_SurfMonsInfo = {21, gRoute4_SurfMons};

const struct WildPokemon gRoute4_FishingMons[] = 
{
	{ 3,  5, SPECIES_WOOPER},//old rod 70
	{ 3,  5, SPECIES_CHEWTLE},//old rod 30
	{25, 28, SPECIES_QUAGSIRE},//good rod 60
	{25, 28, SPECIES_MAREANIE},//good rod 20
	{25, 28, SPECIES_FRILLISH_F},//good rod 20
	{50, 55, SPECIES_QUAGSIRE},//super rod 40
	{50, 55, SPECIES_QUAGSIRE},//super rod 40
	{50, 55, SPECIES_DREDNAW},//super rod 15
	{50, 55, SPECIES_TOXAPEX},//super rod 4
	{50, 55, SPECIES_JELLICENT_F},//super rod 1
};
const struct WildPokemonInfo gRoute4_FishingMonsInfo = {21, gRoute4_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Mt Moon
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gMtMoon1F_LandMonsMorning[] = 
{
	{12, 14, SPECIES_ZUBAT},//20
	{12, 14, SPECIES_GEODUDE},//20
	{12, 14, SPECIES_ZUBAT},//10
	{12, 14, SPECIES_GEODUDE},//10
	{12, 14, SPECIES_ROLYCOLY},//10
	{12, 14, SPECIES_ROLYCOLY},//10
	{12, 14, SPECIES_MUNNA},//5
	{12, 14, SPECIES_MUNNA},//5
	{12, 14, SPECIES_SHUPPET},//4
	{12, 14, SPECIES_SHUPPET},//4
	{12, 14, SPECIES_STUFFUL},//1
	{12, 14, SPECIES_STUFFUL},//1
};
const struct WildPokemonInfo gMtMoon1F_LandMonsMorningInfo = {21, gMtMoon1F_LandMonsMorning};

const struct WildPokemon gMtMoon1F_LandMonsNight[] = 
{
	{12, 14, SPECIES_WOOBAT},//20
	{12, 14, SPECIES_GEODUDE_A},//20
	{12, 14, SPECIES_WOOBAT},//10
	{12, 14, SPECIES_GEODUDE_A},//10
	{12, 14, SPECIES_MAGNEMITE},//10
	{12, 14, SPECIES_MAGNEMITE},//10
	{12, 14, SPECIES_CLEFAIRY},//5 
	{12, 14, SPECIES_CLEFAIRY},//5
	{12, 14, SPECIES_GASTLY},//4
	{12, 14, SPECIES_GASTLY},//4
	{12, 14, SPECIES_PANCHAM},//1
	{12, 14, SPECIES_PANCHAM},//1
};
const struct WildPokemonInfo gMtMoon1F_LandMonsNightInfo = {21, gMtMoon1F_LandMonsNight};

const struct WildPokemon gMtMoonB1F_LandMonsMorning[] = 
{
	{12, 14, SPECIES_WHISMUR},//20
	{12, 14, SPECIES_PARAS},//20
	{12, 14, SPECIES_WHISMUR},//10
	{12, 14, SPECIES_PARAS},//10
	{12, 14, SPECIES_MAGNEMITE},//10
	{12, 14, SPECIES_MAGNEMITE},//10
	{12, 14, SPECIES_SANDSHREW},//5
	{12, 14, SPECIES_SANDSHREW},//5
	{12, 14, SPECIES_ONIX},//4
	{12, 14, SPECIES_ONIX},//4
	{12, 14, SPECIES_DARUMAKA},//1
	{12, 14, SPECIES_DARUMAKA},//1
};
const struct WildPokemonInfo gMtMoonB1F_LandMonsMorningInfo = {21, gMtMoonB1F_LandMonsMorning};

const struct WildPokemon gMtMoonB1F_LandMonsNight[] = 
{
	{12, 14, SPECIES_MAKUHITA},//20
	{12, 14, SPECIES_DWEBBLE},//20
	{12, 14, SPECIES_MAKUHITA},//10
	{12, 14, SPECIES_DWEBBLE},//10
	{12, 14, SPECIES_ROLYCOLY},//10
	{12, 14, SPECIES_ROLYCOLY},//10
	{12, 14, SPECIES_SIZZLIPEDE},//5 
	{12, 14, SPECIES_SIZZLIPEDE},//5
	{12, 14, SPECIES_DUSKULL},//4
	{12, 14, SPECIES_DUSKULL},//4
	{12, 14, SPECIES_SANDILE},//1
	{12, 14, SPECIES_SANDILE},//1
};
const struct WildPokemonInfo gMtMoonB1F_LandMonsNightInfo = {21, gMtMoonB1F_LandMonsNight};

const struct WildPokemon gMtMoonB2F_LandMonsMorning[] = 
{
	{12, 14, SPECIES_FOONGUS},//20
	{12, 14, SPECIES_NOIBAT},//20
	{12, 14, SPECIES_FOONGUS},//10
	{12, 14, SPECIES_NOIBAT},//10
	{12, 14, SPECIES_MACHOP},//10
	{12, 14, SPECIES_MACHOP},//10
	{12, 14, SPECIES_GOLETT},//5
	{12, 14, SPECIES_GOLETT},//5
	{12, 14, SPECIES_SILICOBRA},//4
	{12, 14, SPECIES_SILICOBRA},//4
	{12, 14, SPECIES_DARUMAKA_G},//1
	{12, 14, SPECIES_DARUMAKA_G},//1
};
const struct WildPokemonInfo gMtMoonB2F_LandMonsMorningInfo = {21, gMtMoonB2F_LandMonsMorning};

const struct WildPokemon gMtMoonB2F_LandMonsNight[] = 
{
	{12, 14, SPECIES_GEODUDE},//20
	{12, 14, SPECIES_ZUBAT},//20
	{12, 14, SPECIES_GEODUDE},//10
	{12, 14, SPECIES_ZUBAT},//10
	{12, 14, SPECIES_MEDITITE},//10
	{12, 14, SPECIES_MEDITITE},//10
	{12, 14, SPECIES_PINECO},//5 
	{12, 14, SPECIES_PINECO},//5
	{12, 14, SPECIES_ROGGENROLA},//4
	{12, 14, SPECIES_ROGGENROLA},//4
	{12, 14, SPECIES_PAWNIARD},//1
	{12, 14, SPECIES_DRILBUR},//1
};
const struct WildPokemonInfo gMtMoonB2F_LandMonsNightInfo = {21, gMtMoonB2F_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Cerulean City Here now
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gCeruleanCity_LandMonsMorning[] = 
{
	{15, 17, SPECIES_SKITTY},//20
	{15, 17, SPECIES_MINCCINO},//20
	{15, 17, SPECIES_SKITTY},//10
	{15, 17, SPECIES_MINCCINO},//10
	{15, 17, SPECIES_FARFETCHD},//10
	{15, 17, SPECIES_FARFETCHD},//10
	{15, 17, SPECIES_KOFFING},//5
	{15, 17, SPECIES_KOFFING},//5
	{15, 17, SPECIES_TRUMBEAK},//4
	{15, 17, SPECIES_TRUMBEAK},//4
	{15, 17, SPECIES_ORICORIO},//1
	{15, 17, SPECIES_ORICORIO},//1
};
const struct WildPokemonInfo gCeruleanCity_LandMonsMorningInfo = {21, gCeruleanCity_LandMonsMorning};

const struct WildPokemon gCeruleanCity_LandMonsNight[] = 
{
	{15, 17, SPECIES_PACHIRISU},//20
	{15, 17, SPECIES_GLAMEOW},//20
	{15, 17, SPECIES_PACHIRISU},//10
	{15, 17, SPECIES_GLAMEOW},//10
	{15, 17, SPECIES_FARFETCHD_G},//10
	{15, 17, SPECIES_FARFETCHD_G},//10
	{15, 17, SPECIES_VIVILLON},//5
	{15, 17, SPECIES_VIVILLON},//5
	{15, 17, SPECIES_STARAVIA},//4
	{15, 17, SPECIES_STARAVIA},//4
	{15, 17, SPECIES_ROOKIDEE},//1
	{15, 17, SPECIES_ROOKIDEE},//1
};
const struct WildPokemonInfo gCeruleanCity_LandMonsNightInfo = {21, gCeruleanCity_LandMonsNight};

const struct WildPokemon gCeruleanCity_SurfMons[] = 
{
	{50, 60, SPECIES_GOLDUCK},//60
	{50, 60, SPECIES_GOLDUCK},//30
	{50, 60, SPECIES_SWANNA},//5
	{50, 60, SPECIES_SWANNA},//4
	{50, 60, SPECIES_STARMIE},//1
};
const struct WildPokemonInfo gCeruleanCity_SurfMonsInfo = {21, gCeruleanCity_SurfMons};

const struct WildPokemon gCeruleanCity_FishingMons[] = 
{
	{ 3,  5, SPECIES_PSYDUCK},//old rod 70
	{ 3,  5, SPECIES_MARILL},//old rod 30
	{25, 28, SPECIES_PSYDUCK},//good rod 60
	{25, 28, SPECIES_BRUXISH},//good rod 20
	{25, 28, SPECIES_BRUXISH},//good rod 20
	{50, 55, SPECIES_GOLDUCK},//super rod 40
	{50, 55, SPECIES_GOLDUCK},//super rod 40
	{50, 55, SPECIES_SEAKING},//super rod 15
	{50, 55, SPECIES_SEAKING},//super rod 4
	{50, 55, SPECIES_STARMIE},//super rod 1
};
const struct WildPokemonInfo gCeruleanCity_FishingMonsInfo = {21, gCeruleanCity_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 24
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute24_LandMonsMorning[] = 
{
	{16, 18, SPECIES_NINCADA},//20
	{16, 18, SPECIES_COTTONEE},//20
	{16, 18, SPECIES_NINCADA},//10
	{16, 18, SPECIES_COTTONEE},//10
	{16, 18, SPECIES_GRIMER},//10
	{16, 18, SPECIES_GRIMER},//10
	{16, 18, SPECIES_BEEDRILL},//5
	{16, 18, SPECIES_BEEDRILL},//5
	{16, 18, SPECIES_HELIOPTILE},//4
	{16, 18, SPECIES_HELIOPTILE},//4
	{16, 18, SPECIES_ABRA},//1
	{16, 18, SPECIES_ABRA},//1
};
const struct WildPokemonInfo gRoute24_LandMonsMorningInfo = {21, gRoute24_LandMonsMorning};

const struct WildPokemon gRoute24_LandMonsNight[] = 
{
	{16, 18, SPECIES_SURSKIT},//20
	{16, 18, SPECIES_PETILIL},//20
	{16, 18, SPECIES_SURSKIT},//10
	{16, 18, SPECIES_PETILIL},//10
	{16, 18, SPECIES_GRIMER_A},//10
	{16, 18, SPECIES_GRIMER_A},//10
	{16, 18, SPECIES_BUTTERFREE},//5
	{16, 18, SPECIES_BUTTERFREE},//5
	{16, 18, SPECIES_ESPURR},//4
	{16, 18, SPECIES_ESPURR},//4
	{16, 18, SPECIES_ABRA},//1
	{16, 18, SPECIES_ABRA},//1
};
const struct WildPokemonInfo gRoute24_LandMonsNightInfo = {21, gRoute24_LandMonsNight};

const struct WildPokemon gRoute24_SurfMons[] = 
{
	{50, 60, SPECIES_TENTACRUEL},//60
	{50, 60, SPECIES_TENTACRUEL},//30
	{50, 60, SPECIES_MANTINE},//5
	{50, 60, SPECIES_MANTINE},//4
	{50, 60, SPECIES_CLOYSTER},//1
};
const struct WildPokemonInfo gRoute24_SurfMonsInfo = {21, gRoute24_SurfMons};

const struct WildPokemon gRoute24_FishingMons[] = 
{
	{ 3,  5, SPECIES_TENTACOOL},//old rod 70
	{ 3,  5, SPECIES_KRABBY},//old rod 30
	{25, 28, SPECIES_BASCULIN_BLUE},//good rod 60
	{25, 28, SPECIES_INKAY},//good rod 20
	{25, 28, SPECIES_PYUKUMUKU},//good rod 20
	{50, 55, SPECIES_SEAKING},//super rod 40
	{50, 55, SPECIES_SEAKING},//super rod 40
	{50, 55, SPECIES_MANTINE},//super rod 15
	{50, 55, SPECIES_MANTINE},//super rod 4
	{50, 55, SPECIES_STARMIE},//super rod 1
};
const struct WildPokemonInfo gRoute24_FishingMonsInfo = {21, gRoute24_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 25
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute25_LandMonsMorning[] = 
{
	{18, 20, SPECIES_SOLOSIS},//20
	{18, 20, SPECIES_DUCKLETT},//20
	{18, 20, SPECIES_SOLOSIS},//10
	{18, 20, SPECIES_DUCKLETT},//10
	{18, 20, SPECIES_SHROOMISH},//10
	{18, 20, SPECIES_SHROOMISH},//10
	{18, 20, SPECIES_FARFETCHD},//5
	{18, 20, SPECIES_FARFETCHD},//5
	{18, 20, SPECIES_FURFROU},//4
	{18, 20, SPECIES_FURFROU},//4
	{18, 20, SPECIES_ZANGOOSE},//1
	{18, 20, SPECIES_TOGEPI},//1
};
const struct WildPokemonInfo gRoute25_LandMonsMorningInfo = {21, gRoute25_LandMonsMorning};

const struct WildPokemon gRoute25_LandMonsNight[] = 
{
	{18, 20, SPECIES_GOTHITA},//20
	{18, 20, SPECIES_WINGULL},//20
	{18, 20, SPECIES_GOTHITA},//10
	{18, 20, SPECIES_WINGULL},//10
	{18, 20, SPECIES_TANGELA},//10
	{18, 20, SPECIES_TANGELA},//10
	{18, 20, SPECIES_FARFETCHD_G},//5
	{18, 20, SPECIES_FARFETCHD_G},//5
	{18, 20, SPECIES_PHANPY},//4
	{18, 20, SPECIES_PHANPY},//4
	{18, 20, SPECIES_SEVIPER},//1
	{18, 20, SPECIES_TOGEPI},//1
};
const struct WildPokemonInfo gRoute25_LandMonsNightInfo = {21, gRoute25_LandMonsNight};

const struct WildPokemon gRoute25_SurfMons[] = 
{
	{50, 60, SPECIES_GOLDUCK},//60
	{50, 60, SPECIES_GOLDUCK},//30
	{50, 60, SPECIES_SWANNA},//5
	{50, 60, SPECIES_SWANNA},//4
	{50, 60, SPECIES_SLOWBRO},//1
};
const struct WildPokemonInfo gRoute25_SurfMonsInfo = {21, gRoute25_SurfMons};

const struct WildPokemon gRoute25_FishingMons[] = 
{
	{ 3,  5, SPECIES_SLOWPOKE},//old rod 70
	{ 3,  5, SPECIES_SLOWPOKE_G},//old rod 30
	{25, 28, SPECIES_PSYDUCK},//good rod 60
	{25, 28, SPECIES_BRUXISH},//good rod 20
	{25, 28, SPECIES_BRUXISH},//good rod 20
	{50, 55, SPECIES_SLOWBRO},//super rod 40
	{50, 55, SPECIES_SLOWBRO},//super rod 40
	{50, 55, SPECIES_SEAKING},//super rod 15
	{50, 55, SPECIES_SEAKING},//super rod 4
	{50, 55, SPECIES_STARMIE},//super rod 1
};
const struct WildPokemonInfo gRoute25_FishingMonsInfo = {21, gRoute25_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 5 Land Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute5_LandMonsMorning[] = 
{
	{18, 20, SPECIES_PIDGEOTTO},//20
	{18, 20, SPECIES_SUNKERN},//20
	{18, 20, SPECIES_PIDGEOTTO},//10
	{18, 20, SPECIES_SUNKERN},//10
	{18, 20, SPECIES_VIVILLON},//10
	{18, 20, SPECIES_VIVILLON},//10
	{18, 20, SPECIES_CUFANT},//5
	{18, 20, SPECIES_CUFANT},//5
	{18, 20, SPECIES_GROWLITHE},//4
	{18, 20, SPECIES_GROWLITHE},//4
	{18, 20, SPECIES_FERROSEED},//1
	{18, 20, SPECIES_FERROSEED},//1
};
const struct WildPokemonInfo gRoute5_LandMonsMorningInfo = {21, gRoute5_LandMonsMorning};

const struct WildPokemon gRoute5_LandMonsNight[] = 
{
	{18, 20, SPECIES_CARNIVINE},//20
	{18, 20, SPECIES_CHERUBI},//20
	{18, 20, SPECIES_CARNIVINE},//10
	{18, 20, SPECIES_CHERUBI},//10
	{18, 20, SPECIES_SNUBBULL},//10
	{18, 20, SPECIES_SNUBBULL},//10
	{18, 20, SPECIES_LUXIO},//5
	{18, 20, SPECIES_LUXIO},//5
	{18, 20, SPECIES_LITLEO},//4
	{18, 20, SPECIES_LITLEO},//4
	{18, 20, SPECIES_CHANSEY},//1
	{18, 20, SPECIES_CHANSEY},//1
};
const struct WildPokemonInfo gRoute5_LandMonsNightInfo = {21, gRoute5_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 6 Land Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute6_LandMonsMorning[] = 
{
	{20, 22, SPECIES_ELECTRIKE},//20
	{20, 22, SPECIES_TRUBBISH},//20
	{20, 22, SPECIES_ELECTRIKE},//10
	{20, 22, SPECIES_TRUBBISH},//10
	{20, 22, SPECIES_TIMBURR},//10
	{20, 22, SPECIES_TIMBURR},//10
	{20, 22, SPECIES_EXEGGCUTE},//5
	{20, 22, SPECIES_EXEGGCUTE},//5
	{20, 22, SPECIES_MILTANK},//4
	{20, 22, SPECIES_MILTANK},//4
	{20, 22, SPECIES_HATENNA},//1
	{20, 22, SPECIES_HATENNA},//1
};
const struct WildPokemonInfo gRoute6_LandMonsMorningInfo = {21, gRoute6_LandMonsMorning};

const struct WildPokemon gRoute6_LandMonsNight[] = 
{
	{20, 22, SPECIES_LUXIO},//20
	{20, 22, SPECIES_CUBCHOO},//20
	{20, 22, SPECIES_LUXIO},//10
	{20, 22, SPECIES_CUBCHOO},//10
	{20, 22, SPECIES_HOUNDOUR},//10
	{20, 22, SPECIES_HOUNDOUR},//10
	{20, 22, SPECIES_GULPIN},//5
	{20, 22, SPECIES_GULPIN},//5
	{20, 22, SPECIES_CROAGUNK},//4
	{20, 22, SPECIES_CROAGUNK},//4
	{20, 22, SPECIES_IMPIDIMP},//1
	{20, 22, SPECIES_IMPIDIMP},//1
};
const struct WildPokemonInfo gRoute6_LandMonsNightInfo = {21, gRoute6_LandMonsNight};

const struct WildPokemon gRoute6_SurfMons[] = 
{
	{50, 60, SPECIES_GOLDUCK},//60
	{50, 60, SPECIES_GOLDUCK},//30
	{50, 60, SPECIES_SWANNA},//5
	{50, 60, SPECIES_SWANNA},//4
	{50, 60, SPECIES_BARRASKEWDA},//1
};
const struct WildPokemonInfo gRoute6_SurfMonsInfo = {21, gRoute6_SurfMons};

const struct WildPokemon gRoute6_FishingMons[] = 
{
	{ 3,  5, SPECIES_WOOPER},//old rod 70
	{ 3,  5, SPECIES_ARROKUDA},//old rod 30
	{25, 28, SPECIES_QUAGSIRE},//good rod 60
	{25, 28, SPECIES_CRAMORANT},//good rod 20
	{25, 28, SPECIES_CRAMORANT},//good rod 20
	{50, 55, SPECIES_QUAGSIRE},//super rod 40
	{50, 55, SPECIES_QUAGSIRE},//super rod 40
	{50, 55, SPECIES_LANTURN},//super rod 15
	{50, 55, SPECIES_TOXAPEX},//super rod 4
	{50, 55, SPECIES_JELLICENT},//super rod 1
};
const struct WildPokemonInfo gRoute6_FishingMonsInfo = {21, gRoute6_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Vermillion City
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gVermillionCity_SurfMons[] = 
{
	{50, 60, SPECIES_TENTACRUEL},//60
	{50, 60, SPECIES_TENTACRUEL},//30
	{50, 60, SPECIES_DEWGONG},//5
	{50, 60, SPECIES_ALOMOMOLA},//4
	{50, 60, SPECIES_CLOYSTER},//1
};
const struct WildPokemonInfo gVermillionCity_SurfMonsInfo = {21, gVermillionCity_SurfMons};

const struct WildPokemon gVermillionCity_FishingMons[] = 
{
	{ 3,  5, SPECIES_TENTACOOL},//old rod 70
	{ 3,  5, SPECIES_KRABBY},//old rod 30
	{25, 28, SPECIES_SEEL},//good rod 60
	{25, 28, SPECIES_INKAY},//good rod 20
	{25, 28, SPECIES_INKAY},//good rod 20
	{50, 55, SPECIES_DEWGONG},//super rod 40
	{50, 55, SPECIES_DEWGONG},//super rod 40
	{50, 55, SPECIES_MANTINE},//super rod 15
	{50, 55, SPECIES_ALOMOMOLA},//super rod 4
	{50, 55, SPECIES_MALAMAR},//super rod 1
};
const struct WildPokemonInfo gVermillionCity_FishingMonsInfo = {21, gVermillionCity_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ SS Anne
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gSSAnne_SurfMons[] = 
{
	{50, 60, SPECIES_TENTACRUEL},//60
	{50, 60, SPECIES_TENTACRUEL},//30
	{50, 60, SPECIES_SHARPEDO},//5
	{50, 60, SPECIES_SHARPEDO},//4
	{50, 60, SPECIES_CLOYSTER},//1
};
const struct WildPokemonInfo gSSAnne_SurfMonsInfo = {21, gSSAnne_SurfMons};

const struct WildPokemon gSSAnne_FishingMons[] = 
{
	{ 3,  5, SPECIES_TENTACOOL},//old rod 70
	{ 3,  5, SPECIES_SHELLDER},//old rod 30
	{25, 28, SPECIES_SEEL},//good rod 60
	{25, 28, SPECIES_CLAUNCHER},//good rod 20
	{25, 28, SPECIES_CLAUNCHER},//good rod 20
	{50, 55, SPECIES_MANTINE},//super rod 40
	{50, 55, SPECIES_MANTINE},//super rod 40
	{50, 55, SPECIES_CLAWITZER},//super rod 15
	{50, 55, SPECIES_CLAWITZER},//super rod 4
	{50, 55, SPECIES_WAILORD},//super rod 1
};
const struct WildPokemonInfo gSSAnne_FishingMonsInfo = {21, gSSAnne_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 11
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute11_LandMonsMorning[] = 
{
	{28, 30, SPECIES_STUFFUL},//20
	{28, 30, SPECIES_DUCKLETT},//20
	{28, 30, SPECIES_DROWZEE},//10
	{28, 30, SPECIES_BALTOY},//10
	{28, 30, SPECIES_MARACTUS},//10
	{28, 30, SPECIES_BUNNELBY},//10
	{25, 28, SPECIES_SCRAGGY},//5
	{25, 28, SPECIES_SCRAGGY},//5
	{25, 28, SPECIES_SANDYGAST},//4
	{25, 28, SPECIES_SANDYGAST},//4
	{25, 28, SPECIES_SIGILYPH},//1
	{25, 28, SPECIES_SIGILYPH},//1
};
const struct WildPokemonInfo gRoute11_LandMonsMorningInfo = {21, gRoute11_LandMonsMorning};

const struct WildPokemon gRoute11_LandMonsNight[] = 
{
	{28, 30, SPECIES_PANCHAM},//20
	{28, 30, SPECIES_DUCKLETT},//20
	{28, 30, SPECIES_DROWZEE},//10
	{28, 30, SPECIES_BALTOY},//10
	{28, 30, SPECIES_CACNEA},//10
	{28, 30, SPECIES_BUNNELBY},//10
	{25, 28, SPECIES_SCRAGGY},//5
	{25, 28, SPECIES_SCRAGGY},//5
	{25, 28, SPECIES_GOLETT},//4
	{25, 28, SPECIES_GOLETT},//4
	{25, 28, SPECIES_SIGILYPH},//1
	{25, 28, SPECIES_SIGILYPH},//1
};
const struct WildPokemonInfo gRoute11_LandMonsNightInfo = {21, gRoute11_LandMonsNight};

const struct WildPokemon gRoute11_SurfMons[] = 
{
	{50, 60, SPECIES_TENTACOOL},//60
	{50, 60, SPECIES_KRABBY},//30
	{50, 60, SPECIES_SEEL},//5
	{50, 60, SPECIES_INKAY},//4
	{50, 60, SPECIES_INKAY},//1
};
const struct WildPokemonInfo gRoute11_SurfMonsInfo = {21, gRoute11_SurfMons};

const struct WildPokemon gRoute11_FishingMons[] = 
{
	{ 3,  5, SPECIES_TENTACOOL},//old rod 70
	{ 3,  5, SPECIES_KRABBY},//old rod 30
	{25, 28, SPECIES_BASCULIN_BLUE},//good rod 60
	{25, 28, SPECIES_INKAY},//good rod 20
	{25, 28, SPECIES_BINACLE},//good rod 20
	{50, 55, SPECIES_GOLDUCK},//super rod 40
	{50, 55, SPECIES_GOLDUCK},//super rod 40
	{50, 55, SPECIES_LANTURN},//super rod 15
	{50, 55, SPECIES_MANTINE},//super rod 4
	{50, 55, SPECIES_BARRASKEWDA},//super rod 1
};
const struct WildPokemonInfo gRoute11_FishingMonsInfo = {21, gRoute11_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Digletts Cave
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gDiglettsCave_LandMonsMorning[] = 
{
	{8, 10, SPECIES_DIGLETT},//20
	{8, 10, SPECIES_SANDYGAST},//20
	{8, 10, SPECIES_DIGLETT},//10
	{8, 10, SPECIES_SANDYGAST},//10
	{8, 10, SPECIES_MUDBRAY},//10
	{8, 10, SPECIES_MUDBRAY},//10
	{8, 10, SPECIES_VULPIX_A},//5
	{8, 10, SPECIES_VULPIX_A},//5
	{8, 10, SPECIES_SWINUB},//4
	{8, 10, SPECIES_SWINUB},//4
	{8, 10, SPECIES_SALANDIT},//1
	{8, 10, SPECIES_SALANDIT},//1
};
const struct WildPokemonInfo gDiglettsCave_LandMonsMorningInfo = {21, gDiglettsCave_LandMonsMorning};

const struct WildPokemon gDiglettsCave_LandMonsNight[] = 
{
	{8, 10, SPECIES_DIGLETT_A},//20
	{8, 10, SPECIES_SPOINK},//20
	{8, 10, SPECIES_DIGLETT_A},//10
	{8, 10, SPECIES_SPOINK},//10
	{8, 10, SPECIES_ROLYCOLY},//10
	{8, 10, SPECIES_ROLYCOLY},//10
	{8, 10, SPECIES_VULPIX},//5
	{8, 10, SPECIES_VULPIX},//5
	{8, 10, SPECIES_SANDSHREW},//4
	{8, 10, SPECIES_SANDSHREW},//4
	{8, 10, SPECIES_DRIFLOON},//1
	{8, 10, SPECIES_DRIFLOON},//1
};
const struct WildPokemonInfo gDiglettsCave_LandMonsNightInfo = {21, gDiglettsCave_LandMonsNight};

const struct WildPokemon gDiglettsCaveB1F_LandMonsMorning[] = 
{
	{26, 28, SPECIES_DUGTRIO},//20
	{25, 27, SPECIES_GOLBAT},//20
	{26, 28, SPECIES_DUGTRIO},//10
	{25, 27, SPECIES_GOLBAT},//10
	{25, 27, SPECIES_ARON},//10
	{25, 27, SPECIES_ARON},//10
	{25, 27, SPECIES_HIPPOPOTAS},//5
	{25, 27, SPECIES_HIPPOPOTAS},//5
	{25, 27, SPECIES_MORPEKO},//4
	{25, 27, SPECIES_MORPEKO},//4
	{25, 27, SPECIES_MINIOR_BLUE},//1
	{25, 27, SPECIES_MINIOR_BLUE},//1
};
const struct WildPokemonInfo gDiglettsCaveB1F_LandMonsMorningInfo = {21, gDiglettsCaveB1F_LandMonsMorning};

const struct WildPokemon gDiglettsCaveB1F_LandMonsNight[] = 
{
	{26, 28, SPECIES_DUGTRIO_A},//20
	{25, 27, SPECIES_SWOOBAT},//20
	{26, 28, SPECIES_DUGTRIO_A},//10
	{25, 27, SPECIES_SWOOBAT},//10
	{25, 27, SPECIES_BRONZOR},//10
	{25, 27, SPECIES_BRONZOR},//10
	{25, 27, SPECIES_DRILBUR},//5
	{25, 27, SPECIES_DRILBUR},//5
	{25, 27, SPECIES_YAMASK},//4
	{25, 27, SPECIES_YAMASK_G},//4
	{25, 27, SPECIES_STONJOURNER},//1
	{25, 27, SPECIES_STONJOURNER},//1
};
const struct WildPokemonInfo gDiglettsCaveB1F_LandMonsNightInfo = {21, gDiglettsCaveB1F_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 9
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute9_LandMonsMorning[] = 
{
	{27, 29, SPECIES_CHATOT},//20
	{27, 29, SPECIES_DEERLING},//20
	{27, 29, SPECIES_CHATOT},//10
	{27, 29, SPECIES_DEERLING},//10
	{27, 29, SPECIES_AIPOM},//10
	{27, 29, SPECIES_AIPOM},//10
	{27, 29, SPECIES_LICKITUNG},//5
	{27, 29, SPECIES_LICKITUNG},//5
	{27, 29, SPECIES_STANTLER},//4
	{27, 29, SPECIES_STANTLER},//4
	{27, 29, SPECIES_EXEGGUTOR_A},//1
	{27, 29, SPECIES_EXEGGUTOR_A},//1
};
const struct WildPokemonInfo gRoute9_LandMonsMorningInfo = {21, gRoute9_LandMonsMorning};

const struct WildPokemon gRoute9_LandMonsNight[] = 
{
	{27, 29, SPECIES_CACNEA},//20
	{27, 29, SPECIES_CORVISQUIRE},//20
	{27, 29, SPECIES_CACNEA},//10
	{27, 29, SPECIES_CORVISQUIRE},//10
	{27, 29, SPECIES_NUMEL},//10
	{27, 29, SPECIES_NUMEL},//10
	{27, 29, SPECIES_STUNKY},//5
	{27, 29, SPECIES_STUNKY},//5
	{27, 29, SPECIES_GIRAFARIG},//4
	{27, 29, SPECIES_GIRAFARIG},//4
	{27, 29, SPECIES_SKORUPI},//1
	{27, 29, SPECIES_SKORUPI},//1
};
const struct WildPokemonInfo gRoute9_LandMonsNightInfo = {21, gRoute9_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 10
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute10_LandMonsMorning[] = 
{
	{28, 30, SPECIES_VOLTORB},//20
	{28, 30, SPECIES_PLUSLE},//20
	{28, 30, SPECIES_VOLTORB},//10
	{28, 30, SPECIES_PLUSLE},//10
	{28, 30, SPECIES_TEDDIURSA},//10
	{28, 30, SPECIES_TEDDIURSA},//10
	{28, 30, SPECIES_SWABLU},//5
	{28, 30, SPECIES_SWABLU},//5
	{28, 30, SPECIES_VANILLITE},//4
	{28, 30, SPECIES_VANILLITE},//4
	{28, 30, SPECIES_STUNFISK},//1
	{28, 30, SPECIES_STUNFISK},//1
};
const struct WildPokemonInfo gRoute10_LandMonsMorningInfo = {21, gRoute10_LandMonsMorning};

const struct WildPokemon gRoute10_LandMonsNight[] = 
{
	{28, 30, SPECIES_PINCURCHIN},//20
	{28, 30, SPECIES_MINUN},//20
	{28, 30, SPECIES_PINCURCHIN},//10
	{28, 30, SPECIES_MINUN},//10
	{28, 30, SPECIES_MARACTUS},//10
	{28, 30, SPECIES_MARACTUS},//10
	{28, 30, SPECIES_MURKROW},//5
	{28, 30, SPECIES_MURKROW},//5
	{28, 30, SPECIES_MISDREAVUS},//4
	{28, 30, SPECIES_MISDREAVUS},//4
	{28, 30, SPECIES_STUNFISK_G},//1
	{28, 30, SPECIES_STUNFISK_G},//1
};
const struct WildPokemonInfo gRoute10_LandMonsNightInfo = {21, gRoute10_LandMonsNight};

const struct WildPokemon gRoute10_SurfMons[] = 
{
	{50, 60, SPECIES_SEAKING},//60
	{50, 60, SPECIES_SEAKING},//30
	{50, 60, SPECIES_BARRASKEWDA},//5
	{50, 60, SPECIES_SHARPEDO},//4
	{50, 60, SPECIES_SHARPEDO},//1
};
const struct WildPokemonInfo gRoute10_SurfMonsInfo = {21, gRoute10_SurfMons};

const struct WildPokemon gRoute10_FishingMons[] = 
{
	{ 3,  5, SPECIES_GOLDEEN},//old rod 70
	{ 3,  5, SPECIES_STARYU},//old rod 30
	{25, 28, SPECIES_BASCULIN_RED},//good rod 60
	{25, 28, SPECIES_PYUKUMUKU},//good rod 20
	{25, 28, SPECIES_PYUKUMUKU},//good rod 20
	{50, 55, SPECIES_SEAKING},//super rod 40
	{50, 55, SPECIES_SEAKING},//super rod 40
	{50, 55, SPECIES_BARRASKEWDA},//super rod 15
	{50, 55, SPECIES_GYARADOS},//super rod 4
	{50, 55, SPECIES_MILOTIC},//super rod 1
};
const struct WildPokemonInfo gRoute10_FishingMonsInfo = {21, gRoute10_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Rock Tunnel 1F
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRockTunnel1F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_BALTOY},//20
	{32, 34, SPECIES_KLINK},//20
	{32, 34, SPECIES_BALTOY},//10
	{32, 34, SPECIES_KLINK},//10
	{32, 34, SPECIES_CUBONE},//10
	{32, 34, SPECIES_CUBONE},//10
	{32, 34, SPECIES_SOLROCK},//5
	{32, 34, SPECIES_SOLROCK},//5
	{32, 34, SPECIES_TURTONATOR},//4
	{32, 34, SPECIES_TURTONATOR},//4
	{32, 34, SPECIES_HONEDGE},//1
	{32, 34, SPECIES_HONEDGE},//1
};
const struct WildPokemonInfo gRockTunnel1F_LandMonsMorningInfo = {21, gRockTunnel1F_LandMonsMorning};

const struct WildPokemon gRockTunnel1F_LandMonsNight[] = 
{
	{32, 34, SPECIES_NOSEPASS},//20
	{32, 34, SPECIES_TYNAMO},//20
	{32, 34, SPECIES_NOSEPASS},//10
	{32, 34, SPECIES_TYNAMO},//10
	{32, 34, SPECIES_DRUDDIGON},//10
	{32, 34, SPECIES_DRUDDIGON},//10
	{32, 34, SPECIES_LUNATONE},//5 
	{32, 34, SPECIES_LUNATONE},//5
	{32, 34, SPECIES_CURSOLA},//4
	{32, 34, SPECIES_CURSOLA},//4
	{32, 34, SPECIES_SHUCKLE},//1
	{32, 34, SPECIES_SHUCKLE},//1
};
const struct WildPokemonInfo gRockTunnel1F_LandMonsNightInfo = {21, gRockTunnel1F_LandMonsNight};

const struct WildPokemon gRockTunnelB1F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_SIGILYPH},//20
	{32, 34, SPECIES_HEATMOR},//20
	{32, 34, SPECIES_SIGILYPH},//10
	{32, 34, SPECIES_HEATMOR},//10
	{32, 34, SPECIES_SLUGMA},//10
	{32, 34, SPECIES_SLUGMA},//10
	{32, 34, SPECIES_CARBINK},//5
	{32, 34, SPECIES_CARBINK},//5
	{32, 34, SPECIES_MAWILE},//4
	{32, 34, SPECIES_MAWILE},//4
	{32, 34, SPECIES_TRAPINCH},//1
	{32, 34, SPECIES_TRAPINCH},//1
};
const struct WildPokemonInfo gRockTunnelB1F_LandMonsMorningInfo = {21, gRockTunnelB1F_LandMonsMorning};

const struct WildPokemon gRockTunnelB1F_LandMonsNight[] = 
{
	{32, 34, SPECIES_TOGEDEMARU},//20
	{32, 34, SPECIES_DURANT},//20
	{32, 34, SPECIES_TOGEDEMARU},//10
	{32, 34, SPECIES_DURANT},//10
	{32, 34, SPECIES_TORKOAL},//10
	{32, 34, SPECIES_TORKOAL},//10
	{32, 34, SPECIES_ABSOL},//5 
	{32, 34, SPECIES_ABSOL},//5
	{32, 34, SPECIES_SABLEYE},//4
	{32, 34, SPECIES_SABLEYE},//4
	{32, 34, SPECIES_DUNSPARCE},//1
	{32, 34, SPECIES_DUNSPARCE},//1
};
const struct WildPokemonInfo gRockTunnelB1F_LandMonsNightInfo = {21, gRockTunnelB1F_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 8
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute8_LandMonsMorning[] = 
{
	{34, 36, SPECIES_CHATOT},//20
	{34, 36, SPECIES_SNORUNT},//20
	{34, 36, SPECIES_CHATOT},//10
	{34, 36, SPECIES_SNORUNT},//10
	{34, 36, SPECIES_BELLOSSOM},//10
	{34, 36, SPECIES_BELLOSSOM},//10
	{34, 36, SPECIES_SPRITZEE},//5
	{34, 36, SPECIES_SPRITZEE},//5
	{34, 36, SPECIES_MAGMAR},//4
	{34, 36, SPECIES_MAGMAR},//4
	{34, 36, SPECIES_THROH},//1
	{34, 36, SPECIES_THROH},//1
};
const struct WildPokemonInfo gRoute8_LandMonsMorningInfo = {21, gRoute8_LandMonsMorning};

const struct WildPokemon gRoute8_LandMonsNight[] = 
{
	{34, 36, SPECIES_CHIMECHO},//20
	{34, 36, SPECIES_CORVISQUIRE},//20
	{34, 36, SPECIES_CHIMECHO},//10
	{34, 36, SPECIES_CORVISQUIRE},//10
	{34, 36, SPECIES_KOMALA},//10
	{34, 36, SPECIES_KOMALA},//10
	{34, 36, SPECIES_SWIRLIX},//5 
	{34, 36, SPECIES_SWIRLIX},//5
	{34, 36, SPECIES_ELECTABUZZ},//4
	{34, 36, SPECIES_ELECTABUZZ},//4
	{34, 36, SPECIES_SAWK},//1
	{34, 36, SPECIES_SAWK},//1
};
const struct WildPokemonInfo gRoute8_LandMonsNightInfo = {21, gRoute8_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 7
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute7_LandMonsMorning[] = 
{
	{36, 38, SPECIES_SNORUNT},//20
	{36, 38, SPECIES_GUMSHOOS},//20
	{36, 38, SPECIES_SNORUNT},//10
	{36, 38, SPECIES_GUMSHOOS},//10
	{36, 38, SPECIES_GIRAFARIG},//10
	{36, 38, SPECIES_GIRAFARIG},//10
	{36, 38, SPECIES_SCYTHER},//5
	{36, 38, SPECIES_SCYTHER},//5
	{36, 38, SPECIES_ORANGURU},//4
	{36, 38, SPECIES_ORANGURU},//4
	{36, 38, SPECIES_AXEW},//1
	{36, 38, SPECIES_AXEW},//1
};
const struct WildPokemonInfo gRoute7_LandMonsMorningInfo = {21, gRoute7_LandMonsMorning};

const struct WildPokemon gRoute7_LandMonsNight[] = 
{
	{36, 38, SPECIES_MIGHTYENA},//20
	{36, 38, SPECIES_CHIMECHO},//20
	{36, 38, SPECIES_MIGHTYENA},//10
	{36, 38, SPECIES_CHIMECHO},//10
	{36, 38, SPECIES_STANTLER},//10
	{36, 38, SPECIES_STANTLER},//10
	{36, 38, SPECIES_PINSIR},//5 
	{36, 38, SPECIES_PINSIR},//5
	{36, 38, SPECIES_PASSIMIAN},//4
	{36, 38, SPECIES_PASSIMIAN},//4
	{36, 38, SPECIES_JYNX},//1
	{36, 38, SPECIES_JYNX},//1
};
const struct WildPokemonInfo gRoute7_LandMonsNightInfo = {21, gRoute7_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Celadon City
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gCeladonCity_LandMonsMorning[] = 
{
	{36, 38, SPECIES_VIVILLON},//20
	{36, 38, SPECIES_BIBAREL},//20
	{36, 38, SPECIES_VIVILLON},//10
	{36, 38, SPECIES_BIBAREL},//10
	{36, 38, SPECIES_BOLTUND},//10
	{36, 38, SPECIES_BOLTUND},//10
	{36, 38, SPECIES_MR_MIME},//5
	{36, 38, SPECIES_MR_MIME},//5
	{36, 38, SPECIES_KLEFKI},//4
	{36, 38, SPECIES_KLEFKI},//4
	{36, 38, SPECIES_INDEEDEE},//1
	{36, 38, SPECIES_INDEEDEE},//1
};
const struct WildPokemonInfo gCeladonCity_LandMonsMorningInfo = {21, gCeladonCity_LandMonsMorning};

const struct WildPokemon gCeladonCity_LandMonsNight[] = 
{
	{36, 38, SPECIES_DELCATTY},//20
	{36, 38, SPECIES_RATICATE},//20
	{36, 38, SPECIES_DELCATTY},//10
	{36, 38, SPECIES_RATICATE},//10
	{36, 38, SPECIES_THIEVUL},//10
	{36, 38, SPECIES_THIEVUL},//10
	{36, 38, SPECIES_MR_MIME_G},//5 
	{36, 38, SPECIES_MR_MIME_G},//5
	{36, 38, SPECIES_DEDENNE},//4
	{36, 38, SPECIES_DEDENNE},//4
	{36, 38, SPECIES_INDEEDEE_FEMALE},//1
	{36, 38, SPECIES_INDEEDEE_FEMALE},//1
};
const struct WildPokemonInfo gCeladonCity_LandMonsNightInfo = {21, gCeladonCity_LandMonsNight};

const struct WildPokemon gCeladonCity_SurfMons[] = 
{
	{50, 60, SPECIES_SWANNA},//60
	{50, 60, SPECIES_SWANNA},//30
	{50, 60, SPECIES_SWANNA},//5
	{50, 60, SPECIES_SWANNA},//4
	{50, 60, SPECIES_SWANNA},//1
};
const struct WildPokemonInfo gCeladonCity_SurfMonsInfo = {21, gCeladonCity_SurfMons};

const struct WildPokemon gCeladonCity_FishingMons[] = 
{
	{ 3,  5, SPECIES_MAGIKARP},//old rod 70
	{ 3,  5, SPECIES_FEEBAS},//old rod 30
	{25, 28, SPECIES_PSYDUCK},//good rod 60
	{25, 28, SPECIES_AZUMARILL},//good rod 20
	{25, 28, SPECIES_AZUMARILL},//good rod 20
	{50, 55, SPECIES_GOLDUCK},//super rod 40
	{50, 55, SPECIES_GOLDUCK},//super rod 40
	{50, 55, SPECIES_LUMINEON},//super rod 15
	{50, 55, SPECIES_GYARADOS},//super rod 4
	{50, 55, SPECIES_MILOTIC},//super rod 1
};
const struct WildPokemonInfo gCeladonCity_FishingMonsInfo = {21, gCeladonCity_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Pokemon Tower
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gPokemonTower_LandMonsMorning[] = 
{
	{45, 50, SPECIES_POLTEAGEIST},//20
	{45, 50, SPECIES_DUSCLOPS},//20
	{45, 50, SPECIES_POLTEAGEIST},//10
	{45, 50, SPECIES_DUSCLOPS},//10
	{45, 50, SPECIES_COFAGRIGUS},//10
	{45, 50, SPECIES_COFAGRIGUS},//10
	{45, 50, SPECIES_SPIRITOMB},//5
	{45, 50, SPECIES_SPIRITOMB},//5
	{45, 50, SPECIES_BANETTE},//4
	{45, 50, SPECIES_BANETTE},//4
	{45, 50, SPECIES_MIMIKYU},//1
	{45, 50, SPECIES_MIMIKYU},//1
};
const struct WildPokemonInfo gPokemonTower_LandMonsMorningInfo = {21, gPokemonTower_LandMonsMorning};

const struct WildPokemon gPokemonTower_LandMonsNight[] = 
{
	{45, 50, SPECIES_MISMAGIUS},//20
	{45, 50, SPECIES_DUSCLOPS},//20
	{45, 50, SPECIES_MISMAGIUS},//10
	{45, 50, SPECIES_DUSCLOPS},//10
	{45, 50, SPECIES_RUNERIGUS},//10
	{45, 50, SPECIES_RUNERIGUS},//10
	{45, 50, SPECIES_BEHEEYEM},//5 
	{45, 50, SPECIES_BEHEEYEM},//5
	{45, 50, SPECIES_GENGAR},//4
	{45, 50, SPECIES_GENGAR},//4
	{45, 50, SPECIES_CHANDELURE},//1
	{45, 50, SPECIES_CHANDELURE},//1
};
const struct WildPokemonInfo gPokemonTower_LandMonsNightInfo = {21, gPokemonTower_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 16
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute16_LandMonsMorning[] = 
{
	{38, 40, SPECIES_LINOONE},//20
	{38, 40, SPECIES_PERSIAN},//20
	{38, 40, SPECIES_LINOONE},//10
	{38, 40, SPECIES_PERSIAN},//10
	{38, 40, SPECIES_SWELLOW},//10
	{38, 40, SPECIES_SWELLOW},//10
	{38, 40, SPECIES_SCYTHER},//5
	{38, 40, SPECIES_SCYTHER},//5
	{38, 40, SPECIES_SAWSBUCK},//4
	{38, 40, SPECIES_SAWSBUCK},//4
	{38, 40, SPECIES_HERACROSS},//1
	{38, 40, SPECIES_HERACROSS},//1
};
const struct WildPokemonInfo gRoute16_LandMonsMorningInfo = {21, gRoute16_LandMonsMorning};

const struct WildPokemon gRoute16_LandMonsNight[] = 
{
	{38, 40, SPECIES_LINOONE_G},//20
	{38, 40, SPECIES_PERSIAN_A},//20
	{38, 40, SPECIES_LINOONE_G},//10
	{38, 40, SPECIES_PERSIAN_A},//10
	{38, 40, SPECIES_TOUCANNON},//10
	{38, 40, SPECIES_TOUCANNON},//10
	{38, 40, SPECIES_PINSIR},//5 
	{38, 40, SPECIES_PINSIR},//5
	{38, 40, SPECIES_FALINKS},//4
	{38, 40, SPECIES_FALINKS},//4
	{38, 40, SPECIES_SMEARGLE},//1
	{38, 40, SPECIES_SMEARGLE},//1
};
const struct WildPokemonInfo gRoute16_LandMonsNightInfo = {21, gRoute16_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 17
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute17_LandMonsMorning[] = 
{
	{46, 48, SPECIES_DELIBIRD},//20
	{46, 48, SPECIES_CASTFORM},//20
	{46, 48, SPECIES_DELIBIRD},//10
	{46, 48, SPECIES_CASTFORM},//10
	{46, 48, SPECIES_PIDGEOT},//10
	{46, 48, SPECIES_PIDGEOT},//10
	{46, 48, SPECIES_SWELLOW},//5
	{46, 48, SPECIES_SWELLOW},//5
	{46, 48, SPECIES_ALTARIA},//4
	{46, 48, SPECIES_ALTARIA},//4
	{46, 48, SPECIES_SKARMORY},//1
	{46, 48, SPECIES_SKARMORY},//1
};
const struct WildPokemonInfo gRoute17_LandMonsMorningInfo = {21, gRoute17_LandMonsMorning};

const struct WildPokemon gRoute17_LandMonsNight[] = 
{
	{46, 48, SPECIES_DELIBIRD},//20
	{46, 48, SPECIES_UNFEZANT},//20
	{46, 48, SPECIES_DELIBIRD},//10
	{46, 48, SPECIES_UNFEZANT},//10
	{46, 48, SPECIES_STARAPTOR},//10
	{46, 48, SPECIES_STARAPTOR},//10
	{46, 48, SPECIES_ZEBSTRIKA},//5 
	{46, 48, SPECIES_ZEBSTRIKA},//5
	{46, 48, SPECIES_DRAMPA},//4
	{46, 48, SPECIES_DRAMPA},//4
	{46, 48, SPECIES_HAWLUCHA},//1
	{46, 48, SPECIES_HAWLUCHA},//1
};
const struct WildPokemonInfo gRoute17_LandMonsNightInfo = {21, gRoute17_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 18
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute18_LandMonsMorning[] = 
{
	{48, 50, SPECIES_DODRIO},//20
	{48, 50, SPECIES_TALONFLAME},//20
	{48, 50, SPECIES_DODRIO},//10
	{48, 50, SPECIES_TALONFLAME},//10
	{48, 50, SPECIES_STOUTLAND},//10
	{48, 50, SPECIES_STOUTLAND},//10
	{48, 50, SPECIES_HELIOLISK},//5
	{48, 50, SPECIES_HELIOLISK},//5
	{48, 50, SPECIES_AUDINO},//4
	{48, 50, SPECIES_AUDINO},//4
	{48, 50, SPECIES_TROPIUS},//1
	{48, 50, SPECIES_TROPIUS},//1
};
const struct WildPokemonInfo gRoute18_LandMonsMorningInfo = {21, gRoute18_LandMonsMorning};

const struct WildPokemon gRoute18_LandMonsNight[] = 
{
	{48, 50, SPECIES_CORVIKNIGHT},//20
	{48, 50, SPECIES_TOUCANNON},//20
	{48, 50, SPECIES_CORVIKNIGHT},//10
	{48, 50, SPECIES_TOUCANNON},//10
	{48, 50, SPECIES_LIEPARD},//10
	{48, 50, SPECIES_LIEPARD},//10
	{48, 50, SPECIES_TOXICROAK},//5 
	{48, 50, SPECIES_TOXICROAK},//5
	{48, 50, SPECIES_CHANSEY},//4
	{48, 50, SPECIES_CHANSEY},//4
	{48, 50, SPECIES_HONCHKROW},//1
	{48, 50, SPECIES_HONCHKROW},//1
};
const struct WildPokemonInfo gRoute18_LandMonsNightInfo = {21, gRoute18_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Fuschia City
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gFuschiaCity_LandMonsMorning[] = 
{
	{50, 52, SPECIES_GREEDENT},//20
	{50, 52, SPECIES_PELIPPER},//20
	{50, 52, SPECIES_GREEDENT},//10
	{50, 52, SPECIES_PELIPPER},//10
	{50, 52, SPECIES_VENOMOTH},//10
	{50, 52, SPECIES_VENOMOTH},//10
	{50, 52, SPECIES_GARBODOR},//5
	{50, 52, SPECIES_GARBODOR},//5
	{50, 52, SPECIES_MUK},//4
	{50, 52, SPECIES_MUK},//4
	{50, 52, SPECIES_SLOWBRO},//1
	{50, 52, SPECIES_SLOWBRO},//1
};
const struct WildPokemonInfo gFuschiaCity_LandMonsMorningInfo = {21, gFuschiaCity_LandMonsMorning};

const struct WildPokemon gFuschiaCity_LandMonsNight[] = 
{
	{50, 52, SPECIES_DIGGERSBY},//20
	{50, 52, SPECIES_NOCTOWL},//20
	{50, 52, SPECIES_DIGGERSBY},//10
	{50, 52, SPECIES_NOCTOWL},//10
	{50, 52, SPECIES_MOTHIM},//10
	{50, 52, SPECIES_MOTHIM},//10
	{50, 52, SPECIES_SKUNTANK},//5 
	{50, 52, SPECIES_SKUNTANK},//5
	{50, 52, SPECIES_MUK_A},//4
	{50, 52, SPECIES_MUK_A},//4
	{50, 52, SPECIES_SLOWKING_G},//1
	{50, 52, SPECIES_SLOWKING_G},//1
};
const struct WildPokemonInfo gFuschiaCity_LandMonsNightInfo = {21, gFuschiaCity_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 12
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute12_LandMonsMorning[] = 
{
	{50, 52, SPECIES_CHESNAUGHT},//20
	{50, 52, SPECIES_TYPHLOSION},//20
	{50, 52, SPECIES_INTELEON},//10
	{50, 52, SPECIES_SCEPTILE},//10
	{50, 52, SPECIES_INFERNAPE},//10
	{50, 52, SPECIES_FERALIGATR},//10
	{50, 52, SPECIES_TORTERRA},//5
	{50, 52, SPECIES_BLAZIKEN},//5
	{50, 52, SPECIES_PRIMARINA},//4
	{50, 52, SPECIES_RILLABOOM},//4
	{50, 52, SPECIES_CINDERACE},//1
	{50, 52, SPECIES_EMPOLEON},//1
};
const struct WildPokemonInfo gRoute12_LandMonsMorningInfo = {21, gRoute12_LandMonsMorning};

const struct WildPokemon gRoute12_LandMonsNight[] = 
{
	{50, 52, SPECIES_MEGANIUM},//20
	{50, 52, SPECIES_DELPHOX},//20
	{50, 52, SPECIES_BLASTOISE},//10
	{50, 52, SPECIES_SERPERIOR},//10
	{50, 52, SPECIES_CHARIZARD},//10
	{50, 52, SPECIES_SAMUROTT},//10
	{50, 52, SPECIES_DECIDUEYE},//5 
	{50, 52, SPECIES_EMBOAR},//5
	{50, 52, SPECIES_SWAMPERT},//4
	{50, 52, SPECIES_VENUSAUR},//4
	{50, 52, SPECIES_INCINEROAR},//1
	{50, 52, SPECIES_GRENINJA},//1
};
const struct WildPokemonInfo gRoute12_LandMonsNightInfo = {21, gRoute12_LandMonsNight};

const struct WildPokemon gRoute12_SurfMons[] = 
{
	{50, 60, SPECIES_SEAKING},//60
	{50, 60, SPECIES_SEAKING},//30
	{50, 60, SPECIES_SHARPEDO},//5
	{50, 60, SPECIES_SHARPEDO},//4
	{50, 60, SPECIES_STARMIE},//1
};
const struct WildPokemonInfo gRoute12_SurfMonsInfo = {21, gRoute12_SurfMons};

const struct WildPokemon gRoute12_FishingMons[] = 
{
	{ 3,  5, SPECIES_GOLDEEN},//old rod 70
	{ 3,  5, SPECIES_STARYU},//old rod 30
	{25, 28, SPECIES_BASCULIN_BLUE},//good rod 60
	{25, 28, SPECIES_CLAUNCHER},//good rod 20
	{25, 28, SPECIES_SKRELP},//good rod 20
	{50, 55, SPECIES_SEAKING},//super rod 40
	{50, 55, SPECIES_SEAKING},//super rod 40
	{50, 55, SPECIES_CLAWITZER},//super rod 15
	{50, 55, SPECIES_CLAWITZER},//super rod 4
	{50, 55, SPECIES_STARMIE},//super rod 1
};
const struct WildPokemonInfo gRoute12_FishingMonsInfo = {21, gRoute12_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 13
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute13_LandMonsMorning[] = 
{
	{46, 48, SPECIES_LURANTIS},//20
	{46, 48, SPECIES_LUDICOLO},//20
	{46, 48, SPECIES_LURANTIS},//10
	{46, 48, SPECIES_LUDICOLO},//10
	{46, 48, SPECIES_ACCELGOR},//10
	{46, 48, SPECIES_ACCELGOR},//10
	{46, 48, SPECIES_GOGOAT},//5
	{46, 48, SPECIES_GOGOAT},//5
	{46, 48, SPECIES_RAPIDASH},//4
	{46, 48, SPECIES_RAPIDASH},//4
	{46, 48, SPECIES_ARCANINE},//1
	{46, 48, SPECIES_ARCANINE},//1
};
const struct WildPokemonInfo gRoute13_LandMonsMorningInfo = {21, gRoute13_LandMonsMorning};

const struct WildPokemon gRoute13_LandMonsNight[] = 
{
	{46, 48, SPECIES_TSAREENA},//20
	{46, 48, SPECIES_SHIFTRY},//20
	{46, 48, SPECIES_TSAREENA},//10
	{46, 48, SPECIES_SHIFTRY},//10
	{46, 48, SPECIES_ESCAVALIER},//10
	{46, 48, SPECIES_ESCAVALIER},//10
	{46, 48, SPECIES_SHIINOTIC},//5 
	{46, 48, SPECIES_SHIINOTIC},//5
	{46, 48, SPECIES_RAPIDASH_G},//4
	{46, 48, SPECIES_RAPIDASH_G},//4
	{46, 48, SPECIES_HOUNDOOM},//1
	{46, 48, SPECIES_HOUNDOOM},//1
};
const struct WildPokemonInfo gRoute13_LandMonsNightInfo = {21, gRoute13_LandMonsNight};

const struct WildPokemon gRoute13_SurfMons[] = 
{
	{50, 60, SPECIES_SEAKING},//60
	{50, 60, SPECIES_SEAKING},//30
	{50, 60, SPECIES_SHARPEDO},//5
	{50, 60, SPECIES_SHARPEDO},//4
	{50, 60, SPECIES_STARMIE},//1
};
const struct WildPokemonInfo gRoute13_SurfMonsInfo = {21, gRoute13_SurfMons};

const struct WildPokemon gRoute13_FishingMons[] = 
{
	{ 3,  5, SPECIES_GOLDEEN},//old rod 70
	{ 3,  5, SPECIES_STARYU},//old rod 30
	{25, 28, SPECIES_BASCULIN_BLUE},//good rod 60
	{25, 28, SPECIES_CLAUNCHER},//good rod 20
	{25, 28, SPECIES_SKRELP},//good rod 20
	{50, 55, SPECIES_SEAKING},//super rod 40
	{50, 55, SPECIES_SEAKING},//super rod 40
	{50, 55, SPECIES_CLAWITZER},//super rod 15
	{50, 55, SPECIES_CLAWITZER},//super rod 4
	{50, 55, SPECIES_STARMIE},//super rod 1
};
const struct WildPokemonInfo gRoute13_FishingMonsInfo = {21, gRoute13_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 14
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute14_LandMonsMorning[] = 
{
	{47, 49, SPECIES_PIDGEOT},//20
	{47, 49, SPECIES_LEAVANNY},//20
	{47, 49, SPECIES_PIDGEOT},//10
	{47, 49, SPECIES_LEAVANNY},//10
	{47, 49, SPECIES_AMBIPOM},//10
	{47, 49, SPECIES_AMBIPOM},//10
	{47, 49, SPECIES_BRAVIARY},//5
	{47, 49, SPECIES_BRAVIARY},//5
	{47, 49, SPECIES_STUNFISK},//4
	{47, 49, SPECIES_STUNFISK},//4
	{47, 49, SPECIES_GOLISOPOD},//1
	{47, 49, SPECIES_GOLISOPOD},//1
};
const struct WildPokemonInfo gRoute14_LandMonsMorningInfo = {21, gRoute14_LandMonsMorning};

const struct WildPokemon gRoute14_LandMonsNight[] = 
{
	{47, 49, SPECIES_TALONFLAME},//20
	{47, 49, SPECIES_VESPIQUEN},//20
	{47, 49, SPECIES_TALONFLAME},//10
	{47, 49, SPECIES_VESPIQUEN},//10
	{47, 49, SPECIES_CAMERUPT},//10
	{47, 49, SPECIES_CAMERUPT},//10
	{47, 49, SPECIES_MANDIBUZZ},//5 
	{47, 49, SPECIES_MANDIBUZZ},//5
	{47, 49, SPECIES_STUNFISK_G},//4
	{47, 49, SPECIES_STUNFISK_G},//4
	{47, 49, SPECIES_DRAPION},//1
	{47, 49, SPECIES_DRAPION},//1
};
const struct WildPokemonInfo gRoute14_LandMonsNightInfo = {21, gRoute14_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 15
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute15_LandMonsMorning[] = 
{
	{48, 50, SPECIES_VICTREEBEL},//20
	{48, 50, SPECIES_DODRIO},//20
	{48, 50, SPECIES_VICTREEBEL},//10
	{48, 50, SPECIES_DODRIO},//10
	{48, 50, SPECIES_URSARING},//10
	{48, 50, SPECIES_URSARING},//10
	{48, 50, SPECIES_HELIOLISK},//5
	{48, 50, SPECIES_HELIOLISK},//5
	{48, 50, SPECIES_RIBOMBEE},//4
	{48, 50, SPECIES_RIBOMBEE},//4
	{48, 50, SPECIES_AUDINO},//1
	{48, 50, SPECIES_AUDINO},//1
};
const struct WildPokemonInfo gRoute15_LandMonsMorningInfo = {21, gRoute15_LandMonsMorning};

const struct WildPokemon gRoute15_LandMonsNight[] = 
{
	{32, 34, SPECIES_AMOONGUSS},//20
	{32, 34, SPECIES_TOUCANNON},//20
	{32, 34, SPECIES_AMOONGUSS},//10
	{32, 34, SPECIES_TOUCANNON},//10
	{32, 34, SPECIES_MARACTUS},//10
	{32, 34, SPECIES_MARACTUS},//10
	{34, 36, SPECIES_TOXICROAK},//5 
	{34, 36, SPECIES_TOXICROAK},//5
	{34, 36, SPECIES_HONCHKROW},//4
	{34, 36, SPECIES_HONCHKROW},//4
	{34, 36, SPECIES_CHANSEY},//1
	{34, 36, SPECIES_CHANSEY},//1
};
const struct WildPokemonInfo gRoute15_LandMonsNightInfo = {21, gRoute15_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 19
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute19_SurfMons[] = 
{
	{50, 60, SPECIES_TENTACRUEL},//60
	{50, 60, SPECIES_CRAWDAUNT},//30
	{50, 60, SPECIES_CLOYSTER},//5
	{50, 60, SPECIES_WAILORD},//4
	{50, 60, SPECIES_KINGDRA},//1
};
const struct WildPokemonInfo gRoute19_SurfMonsInfo = {21, gRoute19_SurfMons};

const struct WildPokemon gRoute19_FishingMons[] = 
{
	{ 3,  5, SPECIES_CHINCHOU},//old rod 70
	{ 3,  5, SPECIES_HORSEA},//old rod 30
	{25, 28, SPECIES_LUVDISC},//good rod 60
	{25, 28, SPECIES_CLAMPERL},//good rod 20
	{25, 28, SPECIES_RELICANTH},//good rod 20
	{50, 55, SPECIES_MANTINE},//super rod 40
	{50, 55, SPECIES_MANTINE},//super rod 40
	{50, 55, SPECIES_DHELMISE},//super rod 15
	{50, 55, SPECIES_WISHIWASHI},//super rod 4
	{50, 55, SPECIES_WAILORD},//super rod 1
};
const struct WildPokemonInfo gRoute19_FishingMonsInfo = {21, gRoute19_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 20
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute20_SurfMons[] = 
{
	{50, 60, SPECIES_TENTACRUEL},//60
	{50, 60, SPECIES_CRAWDAUNT},//30
	{50, 60, SPECIES_CLOYSTER},//5
	{50, 60, SPECIES_WAILORD},//4
	{50, 60, SPECIES_KINGDRA},//1
};
const struct WildPokemonInfo gRoute20_SurfMonsInfo = {21, gRoute20_SurfMons};

const struct WildPokemon gRoute20_FishingMons[] = 
{
	{ 3,  5, SPECIES_CHINCHOU},//old rod 70
	{ 3,  5, SPECIES_HORSEA},//old rod 30
	{25, 28, SPECIES_LUVDISC},//good rod 60
	{25, 28, SPECIES_CLAMPERL},//good rod 20
	{25, 28, SPECIES_RELICANTH},//good rod 20
	{50, 55, SPECIES_MANTINE},//super rod 40
	{50, 55, SPECIES_MANTINE},//super rod 40
	{50, 55, SPECIES_DHELMISE},//super rod 15
	{50, 55, SPECIES_WISHIWASHI},//super rod 4
	{50, 55, SPECIES_WAILORD},//super rod 1
};
const struct WildPokemonInfo gRoute20_FishingMonsInfo = {21, gRoute20_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Seafoam Island
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gSeafoam1F_LandMonsMorning[] = 
{
	{62, 64, SPECIES_GLALIE},//20
	{62, 64, SPECIES_WALREIN},//20
	{62, 64, SPECIES_GLALIE},//10
	{62, 64, SPECIES_WALREIN},//10
	{62, 64, SPECIES_MR_RIME},//10
	{62, 64, SPECIES_MR_RIME},//10
	{62, 64, SPECIES_JYNX},//5
	{62, 64, SPECIES_JYNX},//5
	{62, 64, SPECIES_BEARTIC},//4
	{62, 64, SPECIES_BEARTIC},//4
	{62, 64, SPECIES_EISCUE},//1
	{62, 64, SPECIES_EISCUE},//1
};
const struct WildPokemonInfo gSeafoam1F_LandMonsMorningInfo = {21, gSeafoam1F_LandMonsMorning};

const struct WildPokemon gSeafoam1F_LandMonsNight[] = 
{
	{62, 64, SPECIES_GLALIE},//20
	{62, 64, SPECIES_WALREIN},//20
	{62, 64, SPECIES_GLALIE},//10
	{62, 64, SPECIES_WALREIN},//10
	{62, 64, SPECIES_MR_RIME},//10
	{62, 64, SPECIES_MR_RIME},//10
	{62, 64, SPECIES_JYNX},//5
	{62, 64, SPECIES_JYNX},//5
	{62, 64, SPECIES_BEARTIC},//4
	{62, 64, SPECIES_BEARTIC},//4
	{62, 64, SPECIES_EISCUE},//1
	{62, 64, SPECIES_EISCUE},//1
};
const struct WildPokemonInfo gSeafoam1F_LandMonsNightInfo = {21, gSeafoam1F_LandMonsNight};

const struct WildPokemon gSeafoamB1F_LandMonsMorning[] = 
{
	{62, 64, SPECIES_PILOSWINE},//20
	{62, 64, SPECIES_DEWGONG},//20
	{62, 64, SPECIES_PILOSWINE},//10
	{62, 64, SPECIES_DEWGONG},//10
	{62, 64, SPECIES_MR_RIME},//10
	{62, 64, SPECIES_MR_RIME},//10
	{62, 64, SPECIES_DELIBIRD},//5
	{62, 64, SPECIES_DELIBIRD},//5
	{62, 64, SPECIES_SANDSLASH_A},//4
	{62, 64, SPECIES_SANDSLASH_A},//4
	{62, 64, SPECIES_CRYOGONAL},//1
	{62, 64, SPECIES_CRYOGONAL},//1
};
const struct WildPokemonInfo gSeafoamB1F_LandMonsMorningInfo = {21, gSeafoamB1F_LandMonsMorning};

const struct WildPokemon gSeafoamB1F_LandMonsNight[] = 
{
	{62, 64, SPECIES_PILOSWINE},//20
	{62, 64, SPECIES_DEWGONG},//20
	{62, 64, SPECIES_PILOSWINE},//10
	{62, 64, SPECIES_DEWGONG},//10
	{62, 64, SPECIES_MR_RIME},//10
	{62, 64, SPECIES_MR_RIME},//10
	{62, 64, SPECIES_DELIBIRD},//5
	{62, 64, SPECIES_DELIBIRD},//5
	{62, 64, SPECIES_SANDSLASH_A},//4
	{62, 64, SPECIES_SANDSLASH_A},//4
	{62, 64, SPECIES_CRYOGONAL},//1
	{62, 64, SPECIES_CRYOGONAL},//1
};
const struct WildPokemonInfo gSeafoamB1F_LandMonsNightInfo = {21, gSeafoamB1F_LandMonsNight};

const struct WildPokemon gSeafoamB2F_LandMonsMorning[] = 
{
	{62, 64, SPECIES_GLALIE},//20
	{62, 64, SPECIES_WALREIN},//20
	{62, 64, SPECIES_GLALIE},//10
	{62, 64, SPECIES_WALREIN},//10
	{62, 64, SPECIES_MR_RIME},//10
	{62, 64, SPECIES_MR_RIME},//10
	{62, 64, SPECIES_JYNX},//5
	{62, 64, SPECIES_JYNX},//5
	{62, 64, SPECIES_BEARTIC},//4
	{62, 64, SPECIES_BEARTIC},//4
	{62, 64, SPECIES_DARMANITAN_G},//1
	{62, 64, SPECIES_DARMANITAN_G},//1
};
const struct WildPokemonInfo gSeafoamB2F_LandMonsMorningInfo = {21, gSeafoamB2F_LandMonsMorning};

const struct WildPokemon gSeafoamB2F_LandMonsNight[] = 
{
	{62, 64, SPECIES_GLALIE},//20
	{62, 64, SPECIES_WALREIN},//20
	{62, 64, SPECIES_GLALIE},//10
	{62, 64, SPECIES_WALREIN},//10
	{62, 64, SPECIES_MR_RIME},//10
	{62, 64, SPECIES_MR_RIME},//10
	{62, 64, SPECIES_JYNX},//5
	{62, 64, SPECIES_JYNX},//5
	{62, 64, SPECIES_BEARTIC},//4
	{62, 64, SPECIES_BEARTIC},//4
	{62, 64, SPECIES_DARMANITAN_G},//1
	{62, 64, SPECIES_DARMANITAN_G},//1
};
const struct WildPokemonInfo gSeafoamB2F_LandMonsNightInfo = {21, gSeafoamB2F_LandMonsNight};

const struct WildPokemon gSeafoamB2F_SurfMons[] = 
{
	{50, 60, SPECIES_DEWGONG},//60
	{50, 60, SPECIES_DEWGONG},//30
	{50, 60, SPECIES_WALREIN},//5
	{50, 60, SPECIES_WAILORD},//4
	{50, 60, SPECIES_LAPRAS},//1
};
const struct WildPokemonInfo gSeafoamB2F_SurfMonsInfo = {21, gSeafoamB2F_SurfMons};

const struct WildPokemon gSeafoamB2F_FishingMons[] = 
{
	{ 3,  5, SPECIES_SPHEAL},//old rod 70
	{ 3,  5, SPECIES_REMORAID},//old rod 30
	{25, 28, SPECIES_WAILMER},//good rod 60
	{25, 28, SPECIES_DELIBIRD},//good rod 20
	{25, 28, SPECIES_DELIBIRD},//good rod 20
	{50, 55, SPECIES_DEWGONG},//super rod 40
	{50, 55, SPECIES_DEWGONG},//super rod 40
	{50, 55, SPECIES_GYARADOS},//super rod 15
	{50, 55, SPECIES_MILOTIC},//super rod 4
	{50, 55, SPECIES_CLOYSTER},//super rod 1
};
const struct WildPokemonInfo gSeafoamB2F_FishingMonsInfo = {21, gSeafoamB2F_FishingMons};

const struct WildPokemon gSeafoamB3F_LandMonsMorning[] = 
{
	{62, 64, SPECIES_PILOSWINE},//20
	{62, 64, SPECIES_DEWGONG},//20
	{62, 64, SPECIES_PILOSWINE},//10
	{62, 64, SPECIES_DEWGONG},//10
	{62, 64, SPECIES_MR_RIME},//10
	{62, 64, SPECIES_MR_RIME},//10
	{62, 64, SPECIES_DELIBIRD},//5
	{62, 64, SPECIES_DELIBIRD},//5
	{62, 64, SPECIES_SANDSLASH_A},//4
	{62, 64, SPECIES_SANDSLASH_A},//4
	{62, 64, SPECIES_VANILLUXE},//1
	{62, 64, SPECIES_VANILLUXE},//1
};
const struct WildPokemonInfo gSeafoamB3F_LandMonsMorningInfo = {21, gSeafoamB3F_LandMonsMorning};

const struct WildPokemon gSeafoamB3F_LandMonsNight[] = 
{
	{62, 64, SPECIES_PILOSWINE},//20
	{62, 64, SPECIES_DEWGONG},//20
	{62, 64, SPECIES_PILOSWINE},//10
	{62, 64, SPECIES_DEWGONG},//10
	{62, 64, SPECIES_MR_RIME},//10
	{62, 64, SPECIES_MR_RIME},//10
	{62, 64, SPECIES_DELIBIRD},//5
	{62, 64, SPECIES_DELIBIRD},//5
	{62, 64, SPECIES_SANDSLASH_A},//4
	{62, 64, SPECIES_SANDSLASH_A},//4
	{62, 64, SPECIES_VANILLUXE},//1
	{62, 64, SPECIES_VANILLUXE},//1
};
const struct WildPokemonInfo gSeafoamB3F_LandMonsNightInfo = {21, gSeafoamB3F_LandMonsNight};

const struct WildPokemon gSeafoamB3F_SurfMons[] = 
{
	{50, 60, SPECIES_DEWGONG},//60
	{50, 60, SPECIES_DEWGONG},//30
	{50, 60, SPECIES_WALREIN},//5
	{50, 60, SPECIES_WAILORD},//4
	{50, 60, SPECIES_LAPRAS},//1
};
const struct WildPokemonInfo gSeafoamB3F_SurfMonsInfo = {21, gSeafoamB3F_SurfMons};

const struct WildPokemon gSeafoamB3F_FishingMons[] = 
{
	{ 3,  5, SPECIES_SPHEAL},//old rod 70
	{ 3,  5, SPECIES_REMORAID},//old rod 30
	{25, 28, SPECIES_WAILMER},//good rod 60
	{25, 28, SPECIES_DELIBIRD},//good rod 20
	{25, 28, SPECIES_DELIBIRD},//good rod 20
	{50, 55, SPECIES_DEWGONG},//super rod 40
	{50, 55, SPECIES_DEWGONG},//super rod 40
	{50, 55, SPECIES_GYARADOS},//super rod 15
	{50, 55, SPECIES_MILOTIC},//super rod 4
	{50, 55, SPECIES_CLOYSTER},//super rod 1
};
const struct WildPokemonInfo gSeafoamB3F_FishingMonsInfo = {21, gSeafoamB3F_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Cinnabar Island
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gCinnabarIsland_SurfMons[] = 
{
	{50, 60, SPECIES_TENTACRUEL},//60
	{50, 60, SPECIES_TENTACRUEL},//30
	{50, 60, SPECIES_CLOYSTER},//5
	{50, 60, SPECIES_DEWGONG},//4
	{50, 60, SPECIES_WALREIN},//1
};
const struct WildPokemonInfo gCinnabarIsland_SurfMonsInfo = {21, gCinnabarIsland_SurfMons};

const struct WildPokemon gCinnabarIsland_FishingMons[] = 
{
	{ 3,  5, SPECIES_TENTACOOL},//old rod 70
	{ 3,  5, SPECIES_SHELLDER},//old rod 30
	{25, 28, SPECIES_KRABBY},//good rod 60
	{25, 28, SPECIES_QWILFISH},//good rod 20
	{25, 28, SPECIES_QWILFISH},//good rod 20
	{50, 55, SPECIES_OCTILLERY},//super rod 40
	{50, 55, SPECIES_OCTILLERY},//super rod 40
	{50, 55, SPECIES_MANTINE},//super rod 15
	{50, 55, SPECIES_MANTINE},//super rod 4
	{50, 55, SPECIES_DHELMISE},//super rod 1
};
const struct WildPokemonInfo gCinnabarIsland_FishingMonsInfo = {21, gCinnabarIsland_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Pokemon Mansion
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gPKMNMansion1F_LandMonsMorning[] = 
{
	{62, 64, SPECIES_RATICATE},//20
	{62, 64, SPECIES_WEEZING},//20
	{62, 64, SPECIES_RATICATE},//10
	{62, 64, SPECIES_WEEZING},//10
	{62, 64, SPECIES_ZANGOOSE},//10
	{62, 64, SPECIES_ZANGOOSE},//10
	{62, 64, SPECIES_CHIMECHO},//5
	{62, 64, SPECIES_CHIMECHO},//5
	{62, 64, SPECIES_LYCANROC_DUSK},//4
	{62, 64, SPECIES_LYCANROC_DUSK},//4
	{62, 64, SPECIES_GRANBULL},//1
	{62, 64, SPECIES_GRANBULL},//1
};
const struct WildPokemonInfo gPKMNMansion1F_LandMonsMorningInfo = {21, gPKMNMansion1F_LandMonsMorning};

const struct WildPokemon gPKMNMansion1F_LandMonsNight[] = 
{
	{62, 64, SPECIES_RATICATE_A},//20
	{62, 64, SPECIES_WEEZING_G},//20
	{62, 64, SPECIES_RATICATE_A},//10
	{62, 64, SPECIES_WEEZING_G},//10
	{62, 64, SPECIES_SEVIPER},//10
	{62, 64, SPECIES_SEVIPER},//10
	{62, 64, SPECIES_KLEFKI},//5
	{62, 64, SPECIES_KLEFKI},//5
	{62, 64, SPECIES_LYCANROC_N},//4
	{62, 64, SPECIES_LYCANROC_N},//4
	{62, 64, SPECIES_BEWEAR},//1
	{62, 64, SPECIES_BEWEAR},//1
};
const struct WildPokemonInfo gPKMNMansion1F_LandMonsNightInfo = {21, gPKMNMansion1F_LandMonsNight};

const struct WildPokemon gPKMNMansion2F_LandMonsMorning[] = 
{
	{62, 64, SPECIES_MUK},//20
	{62, 64, SPECIES_WATCHOG},//20
	{62, 64, SPECIES_MUK},//10
	{62, 64, SPECIES_WATCHOG},//10
	{62, 64, SPECIES_ZANGOOSE},//10
	{62, 64, SPECIES_ZANGOOSE},//10
	{62, 64, SPECIES_CHIMECHO},//5
	{62, 64, SPECIES_CHIMECHO},//5
	{62, 64, SPECIES_LYCANROC_DUSK},//4
	{62, 64, SPECIES_LYCANROC_DUSK},//4
	{62, 64, SPECIES_ARCANINE},//1
	{62, 64, SPECIES_ARCANINE},//1
};
const struct WildPokemonInfo gPKMNMansion2F_LandMonsMorningInfo = {21, gPKMNMansion2F_LandMonsMorning};

const struct WildPokemon gPKMNMansion2F_LandMonsNight[] = 
{
	{62, 64, SPECIES_MUK_A},//20
	{62, 64, SPECIES_MIGHTYENA},//20
	{62, 64, SPECIES_MUK_A},//10
	{62, 64, SPECIES_MIGHTYENA},//10
	{62, 64, SPECIES_SEVIPER},//10
	{62, 64, SPECIES_SEVIPER},//10
	{62, 64, SPECIES_KLEFKI},//5
	{62, 64, SPECIES_KLEFKI},//5
	{62, 64, SPECIES_LYCANROC_N},//4
	{62, 64, SPECIES_LYCANROC_N},//4
	{62, 64, SPECIES_HOUNDOOM},//1
	{62, 64, SPECIES_HOUNDOOM},//1
};
const struct WildPokemonInfo gPKMNMansion2F_LandMonsNightInfo = {21, gPKMNMansion2F_LandMonsNight};

const struct WildPokemon gPKMNMansion3F_LandMonsMorning[] = 
{
	{62, 64, SPECIES_GARBODOR},//20
	{62, 64, SPECIES_GUMSHOOS},//20
	{62, 64, SPECIES_GARBODOR},//10
	{62, 64, SPECIES_GUMSHOOS},//10
	{62, 64, SPECIES_ZANGOOSE},//10
	{62, 64, SPECIES_ZANGOOSE},//10
	{62, 64, SPECIES_CHIMECHO},//5
	{62, 64, SPECIES_CHIMECHO},//5
	{62, 64, SPECIES_LYCANROC_DUSK},//4
	{62, 64, SPECIES_LYCANROC_DUSK},//4
	{62, 64, SPECIES_BANETTE},//1
	{62, 64, SPECIES_BANETTE},//1
};
const struct WildPokemonInfo gPKMNMansion3F_LandMonsMorningInfo = {21, gPKMNMansion3F_LandMonsMorning};

const struct WildPokemon gPKMNMansion3F_LandMonsNight[] = 
{
	{62, 64, SPECIES_SKUNTANK},//20
	{62, 64, SPECIES_OBSTAGOON},//20
	{62, 64, SPECIES_SKUNTANK},//10
	{62, 64, SPECIES_OBSTAGOON},//10
	{62, 64, SPECIES_SEVIPER},//10
	{62, 64, SPECIES_SEVIPER},//10
	{62, 64, SPECIES_KLEFKI},//5
	{62, 64, SPECIES_KLEFKI},//5
	{62, 64, SPECIES_LYCANROC_N},//4
	{62, 64, SPECIES_LYCANROC_N},//4
	{62, 64, SPECIES_POLTEAGEIST},//1
	{62, 64, SPECIES_POLTEAGEIST},//1
};
const struct WildPokemonInfo gPKMNMansion3F_LandMonsNightInfo = {21, gPKMNMansion3F_LandMonsNight};

const struct WildPokemon gPKMNMansionB1F_LandMonsMorning[] = 
{
	{62, 64, SPECIES_RATICATE},//20
	{62, 64, SPECIES_GOLBAT},//20
	{62, 64, SPECIES_RATICATE},//10
	{62, 64, SPECIES_GOLBAT},//10
	{62, 64, SPECIES_ZANGOOSE},//10
	{62, 64, SPECIES_ZANGOOSE},//10
	{62, 64, SPECIES_CHIMECHO},//5
	{62, 64, SPECIES_CHIMECHO},//5
	{62, 64, SPECIES_LIEPARD},//4
	{62, 64, SPECIES_LIEPARD},//4
	{62, 64, SPECIES_DUSCLOPS},//1
	{62, 64, SPECIES_DUSCLOPS},//1
};
const struct WildPokemonInfo gPKMNMansionB1F_LandMonsMorningInfo = {21, gPKMNMansionB1F_LandMonsMorning};

const struct WildPokemon gPKMNMansionB1F_LandMonsNight[] = 
{
	{62, 64, SPECIES_RATICATE_A},//20
	{62, 64, SPECIES_SWOOBAT},//20
	{62, 64, SPECIES_RATICATE_A},//10
	{62, 64, SPECIES_SWOOBAT},//10
	{62, 64, SPECIES_SEVIPER},//10
	{62, 64, SPECIES_SEVIPER},//10
	{62, 64, SPECIES_KLEFKI},//5
	{62, 64, SPECIES_KLEFKI},//5
	{62, 64, SPECIES_ARBOK},//4
	{62, 64, SPECIES_ARBOK},//4
	{62, 64, SPECIES_CHANDELURE},//1
	{62, 64, SPECIES_CHANDELURE},//1
};
const struct WildPokemonInfo gPKMNMansionB1F_LandMonsNightInfo = {21, gPKMNMansionB1F_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Power Plant
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gPowerPlant_LandMonsMorning[] = 
{
	{50, 52, SPECIES_ELECTRODE},//20
	{50, 52, SPECIES_MINUN},//20
	{50, 52, SPECIES_ELECTRODE},//10
	{50, 52, SPECIES_MINUN},//10
	{50, 52, SPECIES_KLINKLANG},//10
	{50, 52, SPECIES_KLINKLANG},//10
	{50, 52, SPECIES_MAGNETON},//5
	{50, 52, SPECIES_MAGNETON},//5
	{50, 52, SPECIES_DEDENNE},//4
	{50, 52, SPECIES_DEDENNE},//4
	{50, 52, SPECIES_AMPHAROS},//1
	{50, 52, SPECIES_AMPHAROS},//1
};
const struct WildPokemonInfo gPowerPlant_LandMonsMorningInfo = {21, gPowerPlant_LandMonsMorning};

const struct WildPokemon gPowerPlant_LandMonsNight[] = 
{
	{50, 52, SPECIES_ELECTRODE},//20
	{50, 52, SPECIES_PLUSLE},//20
	{50, 52, SPECIES_ELECTRODE},//10
	{50, 52, SPECIES_PLUSLE},//10
	{50, 52, SPECIES_ELECTABUZZ},//10
	{50, 52, SPECIES_ELECTABUZZ},//10
	{50, 52, SPECIES_MANECTRIC},//5
	{50, 52, SPECIES_MANECTRIC},//5
	{50, 52, SPECIES_TOGEDEMARU},//4
	{50, 52, SPECIES_TOGEDEMARU},//4
	{50, 52, SPECIES_VIKAVOLT},//1
	{50, 52, SPECIES_VIKAVOLT},//1
};
const struct WildPokemonInfo gPowerPlant_LandMonsNightInfo = {21, gPowerPlant_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Cerulean Cave
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gCeruleanCave1F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_PARASECT},//20
	{32, 34, SPECIES_GOLBAT},//20
	{32, 34, SPECIES_PARASECT},//10
	{32, 34, SPECIES_GOLBAT},//10
	{32, 34, SPECIES_NOIVERN},//10
	{32, 34, SPECIES_NOIVERN},//10
	{34, 36, SPECIES_MAROWAK},//5
	{34, 36, SPECIES_MAROWAK},//5
	{34, 36, SPECIES_MAWILE},//4
	{34, 36, SPECIES_MAWILE},//4
	{34, 36, SPECIES_DURALUDON},//1
	{34, 36, SPECIES_DURALUDON},//1
};
const struct WildPokemonInfo gCeruleanCave1F_LandMonsMorningInfo = {21, gCeruleanCave1F_LandMonsMorning};

const struct WildPokemon gCeruleanCave1F_LandMonsNight[] = 
{
	{68, 70, SPECIES_PARASECT},//20
	{68, 70, SPECIES_SWOOBAT},//20
	{68, 70, SPECIES_PARASECT},//10
	{68, 70, SPECIES_SWOOBAT},//10
	{68, 70, SPECIES_NOIVERN},//10
	{68, 70, SPECIES_NOIVERN},//10
	{68, 70, SPECIES_MAROWAK_A},//5
	{68, 70, SPECIES_MAROWAK_A},//5
	{68, 70, SPECIES_SABLEYE},//4
	{68, 70, SPECIES_SABLEYE},//4
	{68, 70, SPECIES_EXCADRILL},//1
	{68, 70, SPECIES_EXCADRILL},//1
};
const struct WildPokemonInfo gCeruleanCave1F_LandMonsNightInfo = {21, gCeruleanCave1F_LandMonsNight};

const struct WildPokemon gCeruleanCave1F_SurfMons[] = 
{
	{50, 60, SPECIES_SEISMITOAD},//60
	{50, 60, SPECIES_SHARPEDO},//30
	{50, 60, SPECIES_STARMIE},//5
	{50, 60, SPECIES_KINGLER},//4
	{50, 60, SPECIES_GYARADOS},//1
};
const struct WildPokemonInfo gCeruleanCave1F_SurfMonsInfo = {21, gCeruleanCave1F_SurfMons};

const struct WildPokemon gCeruleanCave1F_FishingMons[] = 
{
	{ 3,  5, SPECIES_MAGIKARP},//old rod 70
	{ 3,  5, SPECIES_STARYU},//old rod 30
	{25, 28, SPECIES_CARVANHA},//good rod 60
	{25, 28, SPECIES_PYUKUMUKU},//good rod 20
	{25, 28, SPECIES_SKRELP},//good rod 20
	{50, 55, SPECIES_SEISMITOAD},//super rod 40
	{50, 55, SPECIES_SEISMITOAD},//super rod 40
	{50, 55, SPECIES_SHARPEDO},//super rod 15
	{50, 55, SPECIES_SHARPEDO},//super rod 4
	{50, 55, SPECIES_GYARADOS},//super rod 1
};
const struct WildPokemonInfo gCeruleanCave1F_FishingMonsInfo = {21, gCeruleanCave1F_FishingMons};

const struct WildPokemon gCeruleanCave2F_LandMonsMorning[] = 
{
	{68, 70, SPECIES_AMOONGUSS},//20
	{68, 70, SPECIES_GOLBAT},//20
	{68, 70, SPECIES_AMOONGUSS},//10
	{68, 70, SPECIES_GOLBAT},//10
	{68, 70, SPECIES_NOIVERN},//10
	{68, 70, SPECIES_NOIVERN},//10
	{68, 70, SPECIES_MAROWAK},//5
	{68, 70, SPECIES_MAROWAK},//5
	{68, 70, SPECIES_CENTISKORCH},//4
	{68, 70, SPECIES_CENTISKORCH},//4
	{68, 70, SPECIES_CONKELDURR},//1
	{68, 70, SPECIES_CONKELDURR},//1
};
const struct WildPokemonInfo gCeruleanCave2F_LandMonsMorningInfo = {21, gCeruleanCave2F_LandMonsMorning};

const struct WildPokemon gCeruleanCave2F_LandMonsNight[] = 
{
	{68, 70, SPECIES_AMOONGUSS},//20
	{68, 70, SPECIES_SWOOBAT},//20
	{68, 70, SPECIES_AMOONGUSS},//10
	{68, 70, SPECIES_SWOOBAT},//10
	{68, 70, SPECIES_NOIVERN},//10
	{68, 70, SPECIES_NOIVERN},//10
	{68, 70, SPECIES_MAROWAK_A},//5
	{68, 70, SPECIES_MAROWAK_A},//5
	{68, 70, SPECIES_KROOKODILE},//4
	{68, 70, SPECIES_KROOKODILE},//4
	{68, 70, SPECIES_PANGORO},//1
	{68, 70, SPECIES_PANGORO},//1
};
const struct WildPokemonInfo gCeruleanCave2F_LandMonsNightInfo = {21, gCeruleanCave2F_LandMonsNight};

const struct WildPokemon gCeruleanCaveB1F_LandMonsMorning[] = 
{
	{68, 70, SPECIES_SHIINOTIC},//20
	{68, 70, SPECIES_GOLBAT},//20
	{68, 70, SPECIES_SHIINOTIC},//10
	{68, 70, SPECIES_GOLBAT},//10
	{68, 70, SPECIES_NOIVERN},//10
	{68, 70, SPECIES_NOIVERN},//10
	{68, 70, SPECIES_MAROWAK},//5
	{68, 70, SPECIES_MAROWAK},//5
	{68, 70, SPECIES_CRUSTLE},//4
	{68, 70, SPECIES_CRUSTLE},//4
	{68, 70, SPECIES_TURTONATOR},//1
	{68, 70, SPECIES_TURTONATOR},//1
};
const struct WildPokemonInfo gCeruleanCaveB1F_LandMonsMorningInfo = {21, gCeruleanCaveB1F_LandMonsMorning};

const struct WildPokemon gCeruleanCaveB1F_LandMonsNight[] = 
{
	{68, 70, SPECIES_SHIINOTIC},//20
	{68, 70, SPECIES_SWOOBAT},//20
	{68, 70, SPECIES_SHIINOTIC},//10
	{68, 70, SPECIES_SWOOBAT},//10
	{68, 70, SPECIES_NOIVERN},//10
	{68, 70, SPECIES_NOIVERN},//10
	{68, 70, SPECIES_MAROWAK_A},//5
	{68, 70, SPECIES_MAROWAK_A},//5
	{68, 70, SPECIES_CARBINK},//4
	{68, 70, SPECIES_CARBINK},//4
	{68, 70, SPECIES_SHUCKLE},//1
	{68, 70, SPECIES_SHUCKLE},//1
};
const struct WildPokemonInfo gCeruleanCaveB1F_LandMonsNightInfo = {21, gCeruleanCaveB1F_LandMonsNight};

const struct WildPokemon gCeruleanCaveB1F_SurfMons[] = 
{
	{50, 60, SPECIES_POLIWRATH},//60
	{50, 60, SPECIES_CRAWDAUNT},//30
	{50, 60, SPECIES_TOXAPEX},//5
	{50, 60, SPECIES_KINGLER},//4
	{50, 60, SPECIES_MILOTIC},//1
};
const struct WildPokemonInfo gCeruleanCaveB1F_SurfMonsInfo = {21, gCeruleanCaveB1F_SurfMons};

const struct WildPokemon gCeruleanCaveB1F_FishingMons[] = 
{
	{ 3,  5, SPECIES_FEEBAS},//old rod 70
	{ 3,  5, SPECIES_MAREANIE},//old rod 30
	{25, 28, SPECIES_CORPHISH},//good rod 60
	{25, 28, SPECIES_PYUKUMUKU},//good rod 20
	{25, 28, SPECIES_SKRELP},//good rod 20
	{50, 55, SPECIES_POLIWRATH},//super rod 40
	{50, 55, SPECIES_POLIWRATH},//super rod 40
	{50, 55, SPECIES_CRAWDAUNT},//super rod 15
	{50, 55, SPECIES_CRAWDAUNT},//super rod 4
	{50, 55, SPECIES_MILOTIC},//super rod 1
};
const struct WildPokemonInfo gCeruleanCaveB1F_FishingMonsInfo = {21, gCeruleanCaveB1F_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 23
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute23_LandMonsMorning[] = 
{
	{32, 34, SPECIES_PRIMEAPE},//20
	{32, 34, SPECIES_FEAROW},//20
	{32, 34, SPECIES_SIMISAGE},//10
	{32, 34, SPECIES_SIMISEAR},//10
	{32, 34, SPECIES_SIMIPOUR},//10
	{32, 34, SPECIES_SIMIPOUR},//10
	{34, 36, SPECIES_SEVIPER},//5
	{34, 36, SPECIES_SEVIPER},//5
	{34, 36, SPECIES_GOLBAT},//4
	{34, 36, SPECIES_GOLBAT},//4
	{34, 36, SPECIES_STARAPTOR},//1
	{34, 36, SPECIES_STARAPTOR},//1
};
const struct WildPokemonInfo gRoute23_LandMonsMorningInfo = {21, gRoute23_LandMonsMorning};

const struct WildPokemon gRoute23_LandMonsNight[] = 
{
	{32, 34, SPECIES_PRIMEAPE},//20
	{32, 34, SPECIES_FEAROW},//20
	{32, 34, SPECIES_SIMISAGE},//10
	{32, 34, SPECIES_SIMISEAR},//10
	{32, 34, SPECIES_SIMIPOUR},//10
	{32, 34, SPECIES_SIMIPOUR},//10
	{34, 36, SPECIES_SEVIPER},//5
	{34, 36, SPECIES_SEVIPER},//5
	{34, 36, SPECIES_GOLBAT},//4
	{34, 36, SPECIES_GOLBAT},//4
	{34, 36, SPECIES_STARAPTOR},//1
	{34, 36, SPECIES_STARAPTOR},//1
};
const struct WildPokemonInfo gRoute23_LandMonsNightInfo = {21, gRoute23_LandMonsNight};

const struct WildPokemon gRoute23_SurfMons[] = 
{
	{50, 60, SPECIES_CRAWDAUNT},//60
	{50, 60, SPECIES_CRAWDAUNT},//30
	{50, 60, SPECIES_CLAWITZER},//5
	{50, 60, SPECIES_CLAWITZER},//4
	{50, 60, SPECIES_WALREIN},//1
};
const struct WildPokemonInfo gRoute23_SurfMonsInfo = {21, gRoute23_SurfMons};

const struct WildPokemon gRoute23_FishingMons[] = 
{
	{ 3,  5, SPECIES_MAGIKARP},//old rod 70
	{ 3,  5, SPECIES_FEEBAS},//old rod 30
	{25, 28, SPECIES_BASCULIN_RED},//good rod 60
	{25, 28, SPECIES_CLAUNCHER},//good rod 20
	{25, 28, SPECIES_CLAUNCHER},//good rod 20
	{50, 55, SPECIES_DEWGONG},//super rod 40
	{50, 55, SPECIES_DEWGONG},//super rod 40
	{50, 55, SPECIES_SEAKING},//super rod 15
	{50, 55, SPECIES_GYARADOS},//super rod 4
	{50, 55, SPECIES_MILOTIC},//super rod 1
};
const struct WildPokemonInfo gRoute23_FishingMonsInfo = {21, gRoute23_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Victory Road
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gVictoryRoad1F_LandMonsMorning[] = 
{
	{75, 85, SPECIES_DRAGONITE},//20
	{75, 85, SPECIES_METAGROSS},//20
	{75, 85, SPECIES_GOODRA},//10
	{75, 85, SPECIES_STEELIX},//10
	{75, 85, SPECIES_HAXORUS},//10
	{75, 85, SPECIES_AEGISLASH},//10
	{75, 85, SPECIES_VOLCARONA},//5
	{75, 85, SPECIES_HAXORUS},//5
	{75, 85, SPECIES_STEELIX},//4
	{75, 85, SPECIES_GOODRA},//4
	{75, 85, SPECIES_METAGROSS},//1
	{75, 85, SPECIES_DRAGONITE},//1
};
const struct WildPokemonInfo gVictoryRoad1F_LandMonsMorningInfo = {21, gVictoryRoad1F_LandMonsMorning};

const struct WildPokemon gVictoryRoad1F_LandMonsNight[] = 
{
	{75, 85, SPECIES_DRAGONITE},//20
	{75, 85, SPECIES_METAGROSS},//20
	{75, 85, SPECIES_GOODRA},//10
	{75, 85, SPECIES_STEELIX},//10
	{75, 85, SPECIES_HAXORUS},//10
	{75, 85, SPECIES_AEGISLASH},//10
	{75, 85, SPECIES_VOLCARONA},//5
	{75, 85, SPECIES_HAXORUS},//5
	{75, 85, SPECIES_STEELIX},//4
	{75, 85, SPECIES_GOODRA},//4
	{75, 85, SPECIES_METAGROSS},//1
	{75, 85, SPECIES_DRAGONITE},//1
};
const struct WildPokemonInfo gVictoryRoad1F_LandMonsNightInfo = {21, gVictoryRoad1F_LandMonsNight};

const struct WildPokemon gVictoryRoad2F_LandMonsMorning[] = 
{
	{75, 85, SPECIES_TYRANITAR},//20
	{75, 85, SPECIES_GARCHOMP},//20
	{75, 85, SPECIES_KOMMO_O},//10
	{75, 85, SPECIES_LUCARIO},//10
	{75, 85, SPECIES_MEDICHAM},//10
	{75, 85, SPECIES_MACHAMP},//10
	{75, 85, SPECIES_FROSMOTH},//5
	{75, 85, SPECIES_MEDICHAM},//5
	{75, 85, SPECIES_LUCARIO},//4
	{75, 85, SPECIES_KOMMO_O},//4
	{75, 85, SPECIES_GARCHOMP},//1
	{75, 85, SPECIES_TYRANITAR},//1
};
const struct WildPokemonInfo gVictoryRoad2F_LandMonsMorningInfo = {21, gVictoryRoad2F_LandMonsMorning};

const struct WildPokemon gVictoryRoad2F_LandMonsNight[] = 
{
	{75, 85, SPECIES_TYRANITAR},//20
	{75, 85, SPECIES_GARCHOMP},//20
	{75, 85, SPECIES_KOMMO_O},//10
	{75, 85, SPECIES_LUCARIO},//10
	{75, 85, SPECIES_MEDICHAM},//10
	{75, 85, SPECIES_MACHAMP},//10
	{75, 85, SPECIES_FROSMOTH},//5
	{75, 85, SPECIES_MEDICHAM},//5
	{75, 85, SPECIES_LUCARIO},//4
	{75, 85, SPECIES_KOMMO_O},//4
	{75, 85, SPECIES_GARCHOMP},//1
	{75, 85, SPECIES_TYRANITAR},//1
};
const struct WildPokemonInfo gVictoryRoad2F_LandMonsNightInfo = {21, gVictoryRoad2F_LandMonsNight};

const struct WildPokemon gVictoryRoad3F_LandMonsMorning[] = 
{
	{75, 85, SPECIES_SALAMENCE},//20
	{75, 85, SPECIES_HYDREIGON},//20
	{75, 85, SPECIES_DRAGAPULT},//10
	{75, 85, SPECIES_DURALUDON},//10
	{75, 85, SPECIES_MAWILE},//10
	{75, 85, SPECIES_TOXTRICITY},//10
	{75, 85, SPECIES_SCIZOR},//5
	{75, 85, SPECIES_MAWILE},//5
	{75, 85, SPECIES_DURALUDON},//4
	{75, 85, SPECIES_DRAGAPULT},//4
	{75, 85, SPECIES_HYDREIGON},//1
	{75, 85, SPECIES_SALAMENCE},//1
};
const struct WildPokemonInfo gVictoryRoad3F_LandMonsMorningInfo = {21, gVictoryRoad3F_LandMonsMorning};

const struct WildPokemon gVictoryRoad3F_LandMonsNight[] = 
{
	{75, 85, SPECIES_SALAMENCE},//20
	{75, 85, SPECIES_HYDREIGON},//20
	{75, 85, SPECIES_DRAGAPULT},//10
	{75, 85, SPECIES_DURALUDON},//10
	{75, 85, SPECIES_MAWILE},//10
	{75, 85, SPECIES_TOXTRICITY},//10
	{75, 85, SPECIES_SCIZOR},//5
	{75, 85, SPECIES_MAWILE},//5
	{75, 85, SPECIES_DURALUDON},//4
	{75, 85, SPECIES_DRAGAPULT},//4
	{75, 85, SPECIES_HYDREIGON},//1
	{75, 85, SPECIES_SALAMENCE},//1
};
const struct WildPokemonInfo gVictoryRoad3F_LandMonsNightInfo = {21, gVictoryRoad3F_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Safari Zone
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gSafariZoneCenter_LandMonsMorning[] = 
{
	{50, 52, SPECIES_TAUROS},//20
	{50, 52, SPECIES_HAWLUCHA},//20
	{50, 52, SPECIES_TAUROS},//10
	{50, 52, SPECIES_HAWLUCHA},//10
	{50, 52, SPECIES_FARFETCHD},//10
	{50, 52, SPECIES_FARFETCHD},//10
	{50, 52, SPECIES_CASTFORM},//5
	{50, 52, SPECIES_CASTFORM},//5
	{50, 52, SPECIES_DRACOZOLT},//4
	{50, 52, SPECIES_ARCTOZOLT},//4
	{50, 52, SPECIES_DITTO},//1
	{50, 52, SPECIES_DITTO},//1
};
const struct WildPokemonInfo gSafariZoneCenter_LandMonsMorningInfo = {21, gSafariZoneCenter_LandMonsMorning};

const struct WildPokemon gSafariZoneCenter_LandMonsNight[] = 
{
	{50, 52, SPECIES_BOUFFALANT},//20
	{50, 52, SPECIES_HAWLUCHA},//20
	{50, 52, SPECIES_BOUFFALANT},//10
	{50, 52, SPECIES_HAWLUCHA},//10
	{50, 52, SPECIES_FARFETCHD_G},//10
	{50, 52, SPECIES_FARFETCHD_G},//10
	{50, 52, SPECIES_WOBBUFFET},//5
	{50, 52, SPECIES_WOBBUFFET},//5
	{50, 52, SPECIES_DRACOVISH},//4
	{50, 52, SPECIES_ARCTOVISH},//4
	{50, 52, SPECIES_KANGASKHAN},//1
	{50, 52, SPECIES_KANGASKHAN},//1
};
const struct WildPokemonInfo gSafariZoneCenter_LandMonsNightInfo = {21, gSafariZoneCenter_LandMonsNight};

const struct WildPokemon gSafariZoneCenter_SurfMons[] = 
{
	{50, 60, SPECIES_SEAKING},//60
	{50, 60, SPECIES_SEAKING},//30
	{50, 60, SPECIES_LANTURN},//5
	{50, 60, SPECIES_LANTURN},//4
	{50, 60, SPECIES_GYARADOS},//1
};
const struct WildPokemonInfo gSafariZoneCenter_SurfMonsInfo = {21, gSafariZoneCenter_SurfMons};

const struct WildPokemon gSafariZoneCenter_FishingMons[] = 
{
	{ 3,  5, SPECIES_MAGIKARP},//old rod 70
	{ 3,  5, SPECIES_KRABBY},//old rod 30
	{25, 28, SPECIES_PSYDUCK},//good rod 60
	{25, 28, SPECIES_OMANYTE},//good rod 20
	{25, 28, SPECIES_OMANYTE},//good rod 20
	{50, 55, SPECIES_GOLDUCK},//super rod 40
	{50, 55, SPECIES_GOLDUCK},//super rod 40
	{50, 55, SPECIES_GYARADOS},//super rod 15
	{50, 55, SPECIES_GYARADOS},//super rod 4
	{50, 55, SPECIES_OMASTAR},//super rod 1
};
const struct WildPokemonInfo gSafariZoneCenter_FishingMonsInfo = {21, gSafariZoneCenter_FishingMons};

const struct WildPokemon gSafariZoneEast_LandMonsMorning[] = 
{
	{50, 52, SPECIES_TAUROS},//20
	{50, 52, SPECIES_HAWLUCHA},//20
	{50, 52, SPECIES_TAUROS},//10
	{50, 52, SPECIES_HAWLUCHA},//10
	{50, 52, SPECIES_HITMONLEE},//10
	{50, 52, SPECIES_HITMONLEE},//10
	{50, 52, SPECIES_SCYTHER},//5
	{50, 52, SPECIES_SCYTHER},//5
	{50, 52, SPECIES_AERODACTYL},//4
	{50, 52, SPECIES_AERODACTYL},//4
	{50, 52, SPECIES_RHYDON},//1
	{50, 52, SPECIES_RHYDON},//1
};
const struct WildPokemonInfo gSafariZoneEast_LandMonsMorningInfo = {21, gSafariZoneEast_LandMonsMorning};

const struct WildPokemon gSafariZoneEast_LandMonsNight[] = 
{
	{50, 52, SPECIES_BOUFFALANT},//20
	{50, 52, SPECIES_HAWLUCHA},//20
	{50, 52, SPECIES_BOUFFALANT},//10
	{50, 52, SPECIES_HAWLUCHA},//10
	{50, 52, SPECIES_HITMONCHAN},//10
	{50, 52, SPECIES_HITMONCHAN},//10
	{50, 52, SPECIES_PINSIR},//5
	{50, 52, SPECIES_PINSIR},//5
	{50, 52, SPECIES_ARCHEN},//4
	{50, 52, SPECIES_ARCHEN},//4
	{50, 52, SPECIES_RIOLU},//1
	{50, 52, SPECIES_RIOLU},//1
};
const struct WildPokemonInfo gSafariZoneEast_LandMonsNightInfo = {21, gSafariZoneEast_LandMonsNight};

const struct WildPokemon gSafariZoneEast_SurfMons[] = 
{
	{50, 60, SPECIES_SEAKING},//60
	{50, 60, SPECIES_SEAKING},//30
	{50, 60, SPECIES_LANTURN},//5
	{50, 60, SPECIES_LANTURN},//4
	{50, 60, SPECIES_BARRASKEWDA},//1
};
const struct WildPokemonInfo gSafariZoneEast_SurfMonsInfo = {21, gSafariZoneEast_SurfMons};

const struct WildPokemon gSafariZoneEast_FishingMons[] = 
{
	{ 3,  5, SPECIES_MAGIKARP},//old rod 70
	{ 3,  5, SPECIES_ARROKUDA},//old rod 30
	{25, 28, SPECIES_CHINCHOU},//good rod 60
	{25, 28, SPECIES_TIRTOUGA},//good rod 20
	{25, 28, SPECIES_TIRTOUGA},//good rod 20
	{50, 55, SPECIES_LANTURN},//super rod 40
	{50, 55, SPECIES_LANTURN},//super rod 40
	{50, 55, SPECIES_BARRASKEWDA},//super rod 15
	{50, 55, SPECIES_BARRASKEWDA},//super rod 4
	{50, 55, SPECIES_CARRACOSTA},//super rod 1
};
const struct WildPokemonInfo gSafariZoneEast_FishingMonsInfo = {21, gSafariZoneEast_FishingMons};

const struct WildPokemon gSafariZoneNorth_LandMonsMorning[] = 
{
	{50, 52, SPECIES_TAUROS},//20
	{50, 52, SPECIES_HAWLUCHA},//20
	{50, 52, SPECIES_TAUROS},//10
	{50, 52, SPECIES_HAWLUCHA},//10
	{50, 52, SPECIES_HATTERENE},//10
	{50, 52, SPECIES_HATTERENE},//10
	{50, 52, SPECIES_SHIELDON},//5
	{50, 52, SPECIES_SHIELDON},//5
	{50, 52, SPECIES_PORYGON},//4
	{50, 52, SPECIES_PORYGON},//4
	{50, 52, SPECIES_TYPE_NULL},//1
	{50, 52, SPECIES_TYPE_NULL},//1
};
const struct WildPokemonInfo gSafariZoneNorth_LandMonsMorningInfo = {21, gSafariZoneNorth_LandMonsMorning};

const struct WildPokemon gSafariZoneNorth_LandMonsNight[] = 
{
	{50, 52, SPECIES_BOUFFALANT},//20
	{50, 52, SPECIES_HAWLUCHA},//20
	{50, 52, SPECIES_BOUFFALANT},//10
	{50, 52, SPECIES_HAWLUCHA},//10
	{50, 52, SPECIES_GRIMMSNARL},//10
	{50, 52, SPECIES_GRIMMSNARL},//10
	{50, 52, SPECIES_CRANIDOS},//5
	{50, 52, SPECIES_CRANIDOS},//5
	{50, 52, SPECIES_DONPHAN},//4
	{50, 52, SPECIES_DONPHAN},//4
	{50, 52, SPECIES_ZORUA},//1
	{50, 52, SPECIES_ZORUA},//1
};
const struct WildPokemonInfo gSafariZoneNorth_LandMonsNightInfo = {21, gSafariZoneNorth_LandMonsNight};

const struct WildPokemon gSafariZoneNorth_SurfMons[] = 
{
	{50, 60, SPECIES_SEAKING},//60
	{50, 60, SPECIES_SEAKING},//30
	{50, 60, SPECIES_LANTURN},//5
	{50, 60, SPECIES_LANTURN},//4
	{50, 60, SPECIES_TOXAPEX},//1
};
const struct WildPokemonInfo gSafariZoneNorth_SurfMonsInfo = {21, gSafariZoneNorth_SurfMons};

const struct WildPokemon gSafariZoneNorth_FishingMons[] = 
{
	{ 3,  5, SPECIES_MAGIKARP},//old rod 70
	{ 3,  5, SPECIES_POLIWAG},//old rod 30
	{25, 28, SPECIES_MAREANIE},//good rod 60
	{25, 28, SPECIES_KABUTO},//good rod 20
	{25, 28, SPECIES_KABUTO},//good rod 20
	{50, 55, SPECIES_TOXAPEX},//super rod 40
	{50, 55, SPECIES_TOXAPEX},//super rod 40
	{50, 55, SPECIES_POLIWRATH},//super rod 15
	{50, 55, SPECIES_POLIWRATH},//super rod 4
	{50, 55, SPECIES_KABUTOPS},//super rod 1
};
const struct WildPokemonInfo gSafariZoneNorth_FishingMonsInfo = {21, gSafariZoneNorth_FishingMons};

const struct WildPokemon gSafariZoneWest_LandMonsMorning[] = 
{
	{50, 52, SPECIES_SKARMORY},//20
	{50, 52, SPECIES_ACCELGOR},//20
	{50, 52, SPECIES_SKARMORY},//10
	{50, 52, SPECIES_ACCELGOR},//10
	{50, 52, SPECIES_CRABOMINABLE},//10
	{50, 52, SPECIES_CRABOMINABLE},//10
	{50, 52, SPECIES_LILEEP},//5
	{50, 52, SPECIES_LILEEP},//5
	{50, 52, SPECIES_AMAURA},//4
	{50, 52, SPECIES_AMAURA},//4
	{50, 52, SPECIES_MUNCHLAX},//1
	{50, 52, SPECIES_MUNCHLAX},//1
};
const struct WildPokemonInfo gSafariZoneWest_LandMonsMorningInfo = {21, gSafariZoneWest_LandMonsMorning};

const struct WildPokemon gSafariZoneWest_LandMonsNight[] = 
{
	{50, 52, SPECIES_CORVIKNIGHT},//20
	{50, 52, SPECIES_ESCAVALIER},//20
	{50, 52, SPECIES_CORVIKNIGHT},//10
	{50, 52, SPECIES_ESCAVALIER},//10
	{50, 52, SPECIES_MIENSHAO},//10
	{50, 52, SPECIES_MIENSHAO},//10
	{50, 52, SPECIES_ANORITH},//5
	{50, 52, SPECIES_ANORITH},//5
	{50, 52, SPECIES_TYRUNT},//4
	{50, 52, SPECIES_TYRUNT},//4
	{50, 52, SPECIES_MUNCHLAX},//1
	{50, 52, SPECIES_MUNCHLAX},//1
};
const struct WildPokemonInfo gSafariZoneWest_LandMonsNightInfo = {21, gSafariZoneWest_LandMonsNight};

const struct WildPokemon gSafariZoneWest_SurfMons[] = 
{
	{50, 60, SPECIES_SEAKING},//60
	{50, 60, SPECIES_SEAKING},//30
	{50, 60, SPECIES_LANTURN},//5
	{50, 60, SPECIES_LANTURN},//4
	{50, 60, SPECIES_MILOTIC},//1
};
const struct WildPokemonInfo gSafariZoneWest_SurfMonsInfo = {21, gSafariZoneWest_SurfMons};

const struct WildPokemon gSafariZoneWest_FishingMons[] = 
{
	{ 3,  5, SPECIES_MAGIKARP},//old rod 70
	{ 3,  5, SPECIES_FEEBAS},//old rod 30
	{25, 28, SPECIES_FINNEON},//good rod 60
	{25, 28, SPECIES_STARYU},//good rod 20
	{25, 28, SPECIES_STARYU},//good rod 20
	{50, 55, SPECIES_LUMINEON},//super rod 40
	{50, 55, SPECIES_LUMINEON},//super rod 40
	{50, 55, SPECIES_MILOTIC},//super rod 15
	{50, 55, SPECIES_MILOTIC},//super rod 4
	{50, 55, SPECIES_STARMIE},//super rod 1
};
const struct WildPokemonInfo gSafariZoneWest_FishingMonsInfo = {21, gSafariZoneWest_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Encounter Headers Morning
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemonHeader gWildMonMorningHeaders[] =
{
	{
		.mapGroup = MAP_GROUP(PALLET_TOWN),
		.mapNum = MAP_NUM(PALLET_TOWN),
		.landMonsInfo = NULL,
		.waterMonsInfo = &gPalletTown_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gPalletTown_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_1),
		.mapNum = MAP_NUM(ROUTE_1),
		.landMonsInfo = &gRoute1_LandMonsMorningInfo,
		.waterMonsInfo = &gRoute1_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute1_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(VIRIDIAN_CITY),
		.mapNum = MAP_NUM(VIRIDIAN_CITY),
		.landMonsInfo = &gViridianCity_LandMonsMorningInfo,
		.waterMonsInfo = &gViridianCity_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gViridianCity_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_22),
		.mapNum = MAP_NUM(ROUTE_22),
		.landMonsInfo = &gRoute22_LandMonsMorningInfo,
		.waterMonsInfo = &gRoute22_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute22_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_2),
		.mapNum = MAP_NUM(ROUTE_2),
		.landMonsInfo = &gRoute2_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(VIRIDIAN_FOREST),
		.mapNum = MAP_NUM(VIRIDIAN_FOREST),
		.landMonsInfo = &gViridianForest_LandMonsMorningInfo,
		.waterMonsInfo = &gViridianForest_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gViridianForest_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(PEWTER_CITY),
		.mapNum = MAP_NUM(PEWTER_CITY),
		.landMonsInfo = &gPewterCity_LandMonsMorningInfo,
		.waterMonsInfo = &gPewterCity_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gPewterCity_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_3),
		.mapNum = MAP_NUM(ROUTE_3),
		.landMonsInfo = &gRoute3_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_4),
		.mapNum = MAP_NUM(ROUTE_4),
		.landMonsInfo = &gRoute4_LandMonsMorningInfo,
		.waterMonsInfo = &gRoute4_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute4_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(MT_MOON_1F),
		.mapNum = MAP_NUM(MT_MOON_1F),
		.landMonsInfo = &gMtMoon1F_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(MT_MOON_B1F),
		.mapNum = MAP_NUM(MT_MOON_B1F),
		.landMonsInfo = &gMtMoonB1F_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(MT_MOON_B2F),
		.mapNum = MAP_NUM(MT_MOON_B2F),
		.landMonsInfo = &gMtMoonB2F_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(CERULEAN_CITY),
		.mapNum = MAP_NUM(CERULEAN_CITY),
		.landMonsInfo = &gCeruleanCity_LandMonsMorningInfo,
		.waterMonsInfo = &gCeruleanCity_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gCeruleanCity_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_24),
		.mapNum = MAP_NUM(ROUTE_24),
		.landMonsInfo = &gRoute24_LandMonsMorningInfo,
		.waterMonsInfo = &gRoute24_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute24_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_25),
		.mapNum = MAP_NUM(ROUTE_25),
		.landMonsInfo = &gRoute25_LandMonsMorningInfo,
		.waterMonsInfo = &gRoute25_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute25_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_5),
		.mapNum = MAP_NUM(ROUTE_5),
		.landMonsInfo = &gRoute5_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_6),
		.mapNum = MAP_NUM(ROUTE_6),
		.landMonsInfo = &gRoute6_LandMonsMorningInfo,
		.waterMonsInfo = &gRoute6_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute6_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(VERMILION_CITY),
		.mapNum = MAP_NUM(VERMILION_CITY),
		.landMonsInfo = NULL,
		.waterMonsInfo = &gVermillionCity_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gVermillionCity_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(SSANNE_EXTERIOR),
		.mapNum = MAP_NUM(SSANNE_EXTERIOR),
		.landMonsInfo = NULL,
		.waterMonsInfo = &gSSAnne_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gSSAnne_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_11),
		.mapNum = MAP_NUM(ROUTE_11),
		.landMonsInfo = &gRoute11_LandMonsMorningInfo,
		.waterMonsInfo = &gRoute11_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute11_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(DIGLETTS_CAVE_NORTH_ENTRANCE),
		.mapNum = MAP_NUM(DIGLETTS_CAVE_NORTH_ENTRANCE),
		.landMonsInfo = &gDiglettsCave_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(DIGLETTS_CAVE_B1F),
		.mapNum = MAP_NUM(DIGLETTS_CAVE_B1F),
		.landMonsInfo = &gDiglettsCaveB1F_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(DIGLETTS_CAVE_SOUTH_ENTRANCE),
		.mapNum = MAP_NUM(DIGLETTS_CAVE_SOUTH_ENTRANCE),
		.landMonsInfo = &gDiglettsCave_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_9),
		.mapNum = MAP_NUM(ROUTE_9),
		.landMonsInfo = &gRoute9_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_10),
		.mapNum = MAP_NUM(ROUTE_10),
		.landMonsInfo = &gRoute10_LandMonsMorningInfo,
		.waterMonsInfo = &gRoute10_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute10_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROCK_TUNNEL_1F),
		.mapNum = MAP_NUM(ROCK_TUNNEL_1F),
		.landMonsInfo = &gRockTunnel1F_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROCK_TUNNEL_B1F),
		.mapNum = MAP_NUM(ROCK_TUNNEL_B1F),
		.landMonsInfo = &gRockTunnelB1F_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_7),
		.mapNum = MAP_NUM(ROUTE_7),
		.landMonsInfo = &gRoute7_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_8),
		.mapNum = MAP_NUM(ROUTE_8),
		.landMonsInfo = &gRoute8_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_TOWER_3F),
		.mapNum = MAP_NUM(POKEMON_TOWER_3F),
		.landMonsInfo = &gPokemonTower_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_TOWER_4F),
		.mapNum = MAP_NUM(POKEMON_TOWER_4F),
		.landMonsInfo = &gPokemonTower_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_TOWER_5F),
		.mapNum = MAP_NUM(POKEMON_TOWER_5F),
		.landMonsInfo = &gPokemonTower_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_TOWER_6F),
		.mapNum = MAP_NUM(POKEMON_TOWER_6F),
		.landMonsInfo = &gPokemonTower_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_TOWER_7F),
		.mapNum = MAP_NUM(POKEMON_TOWER_7F),
		.landMonsInfo = &gPokemonTower_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_16),
		.mapNum = MAP_NUM(ROUTE_16),
		.landMonsInfo = &gRoute16_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_17),
		.mapNum = MAP_NUM(ROUTE_17),
		.landMonsInfo = &gRoute17_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_18),
		.mapNum = MAP_NUM(ROUTE_18),
		.landMonsInfo = &gRoute18_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(FUCHSIA_CITY),
		.mapNum = MAP_NUM(FUCHSIA_CITY),
		.landMonsInfo = &gFuschiaCity_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_12),
		.mapNum = MAP_NUM(ROUTE_12),
		.landMonsInfo = &gRoute12_LandMonsMorningInfo,
		.waterMonsInfo = &gRoute12_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute12_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_13),
		.mapNum = MAP_NUM(ROUTE_13),
		.landMonsInfo = &gRoute13_LandMonsMorningInfo,
		.waterMonsInfo = &gRoute13_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute13_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_14),
		.mapNum = MAP_NUM(ROUTE_14),
		.landMonsInfo = &gRoute14_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_15),
		.mapNum = MAP_NUM(ROUTE_15),
		.landMonsInfo = &gRoute15_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_19),
		.mapNum = MAP_NUM(ROUTE_19),
		.landMonsInfo = NULL,
		.waterMonsInfo = &gRoute19_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute19_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_20),
		.mapNum = MAP_NUM(ROUTE_20),
		.landMonsInfo = NULL,
		.waterMonsInfo = &gRoute20_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute20_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_21_A),
		.mapNum = MAP_NUM(ROUTE_21_A),
		.landMonsInfo = &gRoute21_LandMonsMorningInfo,
		.waterMonsInfo = &gRoute21A_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute21A_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_21_B),
		.mapNum = MAP_NUM(ROUTE_21_B),
		.landMonsInfo = NULL,
		.waterMonsInfo = &gRoute21B_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute21B_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_1F),
		.mapNum = MAP_NUM(SEAFOAM_ISLANDS_1F),
		.landMonsInfo = &gSeafoam1F_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B1F),
		.mapNum = MAP_NUM(SEAFOAM_ISLANDS_B1F),
		.landMonsInfo = &gSeafoamB1F_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B2F),
		.mapNum = MAP_NUM(SEAFOAM_ISLANDS_B2F),
		.landMonsInfo = &gSeafoamB2F_LandMonsMorningInfo,
		.waterMonsInfo = &gSeafoamB2F_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gSeafoamB2F_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B3F),
		.mapNum = MAP_NUM(SEAFOAM_ISLANDS_B3F),
		.landMonsInfo = &gSeafoamB3F_LandMonsMorningInfo,
		.waterMonsInfo = &gSeafoamB3F_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gSeafoamB3F_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(CINNABAR_ISLAND),
		.mapNum = MAP_NUM(CINNABAR_ISLAND),
		.landMonsInfo = NULL,
		.waterMonsInfo = &gCinnabarIsland_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gCinnabarIsland_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_MANSION_1F),
		.mapNum = MAP_NUM(POKEMON_MANSION_1F),
		.landMonsInfo = &gPKMNMansion1F_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_MANSION_2F),
		.mapNum = MAP_NUM(POKEMON_MANSION_2F),
		.landMonsInfo = &gPKMNMansion2F_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_MANSION_3F),
		.mapNum = MAP_NUM(POKEMON_MANSION_3F),
		.landMonsInfo = &gPKMNMansion3F_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_MANSION_B1F),
		.mapNum = MAP_NUM(POKEMON_MANSION_B1F),
		.landMonsInfo = &gPKMNMansionB1F_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POWER_PLANT),
		.mapNum = MAP_NUM(POWER_PLANT),
		.landMonsInfo = &gPowerPlant_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(CERULEAN_CAVE_1F),
		.mapNum = MAP_NUM(CERULEAN_CAVE_1F),
		.landMonsInfo = &gCeruleanCave1F_LandMonsMorningInfo,
		.waterMonsInfo = &gCeruleanCave1F_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gCeruleanCave1F_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(CERULEAN_CAVE_2F),
		.mapNum = MAP_NUM(CERULEAN_CAVE_2F),
		.landMonsInfo = &gCeruleanCave2F_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(CERULEAN_CAVE_B1F),
		.mapNum = MAP_NUM(CERULEAN_CAVE_B1F),
		.landMonsInfo = &gCeruleanCaveB1F_LandMonsMorningInfo,
		.waterMonsInfo = &gCeruleanCave1F_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gCeruleanCave1F_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_23),
		.mapNum = MAP_NUM(ROUTE_23),
		.landMonsInfo = &gRoute23_LandMonsMorningInfo,
		.waterMonsInfo = &gRoute23_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute23_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(VICTORY_ROAD_1F),
		.mapNum = MAP_NUM(VICTORY_ROAD_1F),
		.landMonsInfo = &gVictoryRoad1F_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(VICTORY_ROAD_2F),
		.mapNum = MAP_NUM(VICTORY_ROAD_2F),
		.landMonsInfo = &gVictoryRoad2F_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(VICTORY_ROAD_3F),
		.mapNum = MAP_NUM(VICTORY_ROAD_3F),
		.landMonsInfo = &gVictoryRoad3F_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(SAFARI_ZONE_CENTER),
		.mapNum = MAP_NUM(SAFARI_ZONE_CENTER),
		.landMonsInfo = &gSafariZoneCenter_LandMonsMorningInfo,
		.waterMonsInfo = &gSafariZoneCenter_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gSafariZoneCenter_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(SAFARI_ZONE_EAST),
		.mapNum = MAP_NUM(SAFARI_ZONE_EAST),
		.landMonsInfo = &gSafariZoneEast_LandMonsMorningInfo,
		.waterMonsInfo = &gSafariZoneEast_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gSafariZoneEast_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(SAFARI_ZONE_NORTH),
		.mapNum = MAP_NUM(SAFARI_ZONE_NORTH),
		.landMonsInfo = &gSafariZoneNorth_LandMonsMorningInfo,
		.waterMonsInfo = &gSafariZoneNorth_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gSafariZoneNorth_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(SAFARI_ZONE_WEST),
		.mapNum = MAP_NUM(SAFARI_ZONE_WEST),
		.landMonsInfo = &gSafariZoneWest_LandMonsMorningInfo,
		.waterMonsInfo = &gSafariZoneWest_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gSafariZoneWest_FishingMonsInfo,
	},
	{
		.mapGroup = 0xFF,
		.mapNum = 0xFF,
		.landMonsInfo = NULL,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	}
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Encounter Headers Night
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemonHeader gWildMonNightHeaders[] =
{
	{
		.mapGroup = MAP_GROUP(PALLET_TOWN),
		.mapNum = MAP_NUM(PALLET_TOWN),
		.landMonsInfo = NULL,
		.waterMonsInfo = &gPalletTown_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gPalletTown_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_1),
		.mapNum = MAP_NUM(ROUTE_1),
		.landMonsInfo = &gRoute1_LandMonsNightInfo,
		.waterMonsInfo = &gRoute1_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute1_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(VIRIDIAN_CITY),
		.mapNum = MAP_NUM(VIRIDIAN_CITY),
		.landMonsInfo = &gViridianCity_LandMonsNightInfo,
		.waterMonsInfo = &gViridianCity_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gViridianCity_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_22),
		.mapNum = MAP_NUM(ROUTE_22),
		.landMonsInfo = &gRoute22_LandMonsNightInfo,
		.waterMonsInfo = &gRoute22_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute22_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_2),
		.mapNum = MAP_NUM(ROUTE_2),
		.landMonsInfo = &gRoute2_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(VIRIDIAN_FOREST),
		.mapNum = MAP_NUM(VIRIDIAN_FOREST),
		.landMonsInfo = &gViridianForest_LandMonsNightInfo,
		.waterMonsInfo = &gViridianForest_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gViridianForest_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(PEWTER_CITY),
		.mapNum = MAP_NUM(PEWTER_CITY),
		.landMonsInfo = &gPewterCity_LandMonsNightInfo,
		.waterMonsInfo = &gPewterCity_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gPewterCity_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_3),
		.mapNum = MAP_NUM(ROUTE_3),
		.landMonsInfo = &gRoute3_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_4),
		.mapNum = MAP_NUM(ROUTE_4),
		.landMonsInfo = &gRoute4_LandMonsNightInfo,
		.waterMonsInfo = &gRoute4_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute4_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(MT_MOON_1F),
		.mapNum = MAP_NUM(MT_MOON_1F),
		.landMonsInfo = &gMtMoon1F_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(MT_MOON_B1F),
		.mapNum = MAP_NUM(MT_MOON_B1F),
		.landMonsInfo = &gMtMoonB1F_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(MT_MOON_B2F),
		.mapNum = MAP_NUM(MT_MOON_B2F),
		.landMonsInfo = &gMtMoonB2F_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(CERULEAN_CITY),
		.mapNum = MAP_NUM(CERULEAN_CITY),
		.landMonsInfo = &gCeruleanCity_LandMonsNightInfo,
		.waterMonsInfo = &gCeruleanCity_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gCeruleanCity_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_24),
		.mapNum = MAP_NUM(ROUTE_24),
		.landMonsInfo = &gRoute24_LandMonsNightInfo,
		.waterMonsInfo = &gRoute24_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute24_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_25),
		.mapNum = MAP_NUM(ROUTE_25),
		.landMonsInfo = &gRoute25_LandMonsNightInfo,
		.waterMonsInfo = &gRoute25_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute25_FishingMonsInfo,
	},

	{
		.mapGroup = MAP_GROUP(ROUTE_5),
		.mapNum = MAP_NUM(ROUTE_5),
		.landMonsInfo = &gRoute5_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_6),
		.mapNum = MAP_NUM(ROUTE_6),
		.landMonsInfo = &gRoute6_LandMonsNightInfo,
		.waterMonsInfo = &gRoute6_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute6_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(VERMILION_CITY),
		.mapNum = MAP_NUM(VERMILION_CITY),
		.landMonsInfo = NULL,
		.waterMonsInfo = &gVermillionCity_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gVermillionCity_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(SSANNE_EXTERIOR),
		.mapNum = MAP_NUM(SSANNE_EXTERIOR),
		.landMonsInfo = NULL,
		.waterMonsInfo = &gSSAnne_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gSSAnne_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_11),
		.mapNum = MAP_NUM(ROUTE_11),
		.landMonsInfo = &gRoute11_LandMonsNightInfo,
		.waterMonsInfo = &gRoute11_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute11_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(DIGLETTS_CAVE_NORTH_ENTRANCE),
		.mapNum = MAP_NUM(DIGLETTS_CAVE_NORTH_ENTRANCE),
		.landMonsInfo = &gDiglettsCave_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(DIGLETTS_CAVE_B1F),
		.mapNum = MAP_NUM(DIGLETTS_CAVE_B1F),
		.landMonsInfo = &gDiglettsCaveB1F_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(DIGLETTS_CAVE_SOUTH_ENTRANCE),
		.mapNum = MAP_NUM(DIGLETTS_CAVE_SOUTH_ENTRANCE),
		.landMonsInfo = &gDiglettsCave_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_9),
		.mapNum = MAP_NUM(ROUTE_9),
		.landMonsInfo = &gRoute9_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_10),
		.mapNum = MAP_NUM(ROUTE_10),
		.landMonsInfo = &gRoute9_LandMonsNightInfo,
		.waterMonsInfo = &gRoute10_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute10_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROCK_TUNNEL_1F),
		.mapNum = MAP_NUM(ROCK_TUNNEL_1F),
		.landMonsInfo = &gRockTunnel1F_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROCK_TUNNEL_B1F),
		.mapNum = MAP_NUM(ROCK_TUNNEL_B1F),
		.landMonsInfo = &gRockTunnelB1F_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_7),
		.mapNum = MAP_NUM(ROUTE_7),
		.landMonsInfo = &gRoute7_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_8),
		.mapNum = MAP_NUM(ROUTE_8),
		.landMonsInfo = &gRoute8_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_TOWER_3F),
		.mapNum = MAP_NUM(POKEMON_TOWER_3F),
		.landMonsInfo = &gPokemonTower_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_TOWER_4F),
		.mapNum = MAP_NUM(POKEMON_TOWER_4F),
		.landMonsInfo = &gPokemonTower_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_TOWER_5F),
		.mapNum = MAP_NUM(POKEMON_TOWER_5F),
		.landMonsInfo = &gPokemonTower_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_TOWER_6F),
		.mapNum = MAP_NUM(POKEMON_TOWER_6F),
		.landMonsInfo = &gPokemonTower_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_TOWER_7F),
		.mapNum = MAP_NUM(POKEMON_TOWER_7F),
		.landMonsInfo = &gPokemonTower_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_16),
		.mapNum = MAP_NUM(ROUTE_16),
		.landMonsInfo = &gRoute16_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_17),
		.mapNum = MAP_NUM(ROUTE_17),
		.landMonsInfo = &gRoute17_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_18),
		.mapNum = MAP_NUM(ROUTE_18),
		.landMonsInfo = &gRoute18_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(FUCHSIA_CITY),
		.mapNum = MAP_NUM(FUCHSIA_CITY),
		.landMonsInfo = &gFuschiaCity_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_12),
		.mapNum = MAP_NUM(ROUTE_12),
		.landMonsInfo = &gRoute12_LandMonsNightInfo,
		.waterMonsInfo = &gRoute12_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute12_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_13),
		.mapNum = MAP_NUM(ROUTE_13),
		.landMonsInfo = &gRoute13_LandMonsNightInfo,
		.waterMonsInfo = &gRoute13_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute13_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_14),
		.mapNum = MAP_NUM(ROUTE_14),
		.landMonsInfo = &gRoute14_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_15),
		.mapNum = MAP_NUM(ROUTE_15),
		.landMonsInfo = &gRoute15_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_21_A),
		.mapNum = MAP_NUM(ROUTE_21_A),
		.landMonsInfo = &gRoute21_LandMonsNightInfo,
		.waterMonsInfo = &gRoute21A_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute21A_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_21_B),
		.mapNum = MAP_NUM(ROUTE_21_B),
		.landMonsInfo = NULL,
		.waterMonsInfo = &gRoute21B_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute21B_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_1F),
		.mapNum = MAP_NUM(SEAFOAM_ISLANDS_1F),
		.landMonsInfo = &gSeafoam1F_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B1F),
		.mapNum = MAP_NUM(SEAFOAM_ISLANDS_B1F),
		.landMonsInfo = &gSeafoamB1F_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B2F),
		.mapNum = MAP_NUM(SEAFOAM_ISLANDS_B2F),
		.landMonsInfo = &gSeafoamB2F_LandMonsNightInfo,
		.waterMonsInfo = &gSeafoamB2F_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gSeafoamB2F_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B3F),
		.mapNum = MAP_NUM(SEAFOAM_ISLANDS_B3F),
		.landMonsInfo = &gSeafoamB3F_LandMonsNightInfo,
		.waterMonsInfo = &gSeafoamB3F_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gSeafoamB3F_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(CINNABAR_ISLAND),
		.mapNum = MAP_NUM(CINNABAR_ISLAND),
		.landMonsInfo = NULL,
		.waterMonsInfo = &gCinnabarIsland_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gCinnabarIsland_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_MANSION_1F),
		.mapNum = MAP_NUM(POKEMON_MANSION_1F),
		.landMonsInfo = &gPKMNMansion1F_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_MANSION_2F),
		.mapNum = MAP_NUM(POKEMON_MANSION_2F),
		.landMonsInfo = &gPKMNMansion2F_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_MANSION_3F),
		.mapNum = MAP_NUM(POKEMON_MANSION_3F),
		.landMonsInfo = &gPKMNMansion3F_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POKEMON_MANSION_B1F),
		.mapNum = MAP_NUM(POKEMON_MANSION_B1F),
		.landMonsInfo = &gPKMNMansionB1F_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(POWER_PLANT),
		.mapNum = MAP_NUM(POWER_PLANT),
		.landMonsInfo = &gPowerPlant_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(CERULEAN_CAVE_1F),
		.mapNum = MAP_NUM(CERULEAN_CAVE_1F),
		.landMonsInfo = &gCeruleanCave1F_LandMonsNightInfo,
		.waterMonsInfo = &gCeruleanCave1F_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gCeruleanCave1F_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(CERULEAN_CAVE_2F),
		.mapNum = MAP_NUM(CERULEAN_CAVE_2F),
		.landMonsInfo = &gCeruleanCave2F_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(CERULEAN_CAVE_B1F),
		.mapNum = MAP_NUM(CERULEAN_CAVE_B1F),
		.landMonsInfo = &gCeruleanCaveB1F_LandMonsNightInfo,
		.waterMonsInfo = &gCeruleanCave1F_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gCeruleanCave1F_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(ROUTE_23),
		.mapNum = MAP_NUM(ROUTE_23),
		.landMonsInfo = &gRoute23_LandMonsNightInfo,
		.waterMonsInfo = &gRoute23_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute23_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(VICTORY_ROAD_1F),
		.mapNum = MAP_NUM(VICTORY_ROAD_1F),
		.landMonsInfo = &gVictoryRoad1F_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(VICTORY_ROAD_2F),
		.mapNum = MAP_NUM(VICTORY_ROAD_2F),
		.landMonsInfo = &gVictoryRoad2F_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(VICTORY_ROAD_3F),
		.mapNum = MAP_NUM(VICTORY_ROAD_3F),
		.landMonsInfo = &gVictoryRoad3F_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	},
	{
		.mapGroup = MAP_GROUP(SAFARI_ZONE_CENTER),
		.mapNum = MAP_NUM(SAFARI_ZONE_CENTER),
		.landMonsInfo = &gSafariZoneCenter_LandMonsNightInfo,
		.waterMonsInfo = &gSafariZoneCenter_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gSafariZoneCenter_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(SAFARI_ZONE_EAST),
		.mapNum = MAP_NUM(SAFARI_ZONE_EAST),
		.landMonsInfo = &gSafariZoneEast_LandMonsNightInfo,
		.waterMonsInfo = &gSafariZoneEast_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gSafariZoneEast_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(SAFARI_ZONE_NORTH),
		.mapNum = MAP_NUM(SAFARI_ZONE_NORTH),
		.landMonsInfo = &gSafariZoneNorth_LandMonsNightInfo,
		.waterMonsInfo = &gSafariZoneNorth_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gSafariZoneNorth_FishingMonsInfo,
	},
	{
		.mapGroup = MAP_GROUP(SAFARI_ZONE_WEST),
		.mapNum = MAP_NUM(SAFARI_ZONE_WEST),
		.landMonsInfo = &gSafariZoneWest_LandMonsNightInfo,
		.waterMonsInfo = &gSafariZoneWest_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gSafariZoneWest_FishingMonsInfo,
	},
	{
		.mapGroup = 0xFF,
		.mapNum = 0xFF,
		.landMonsInfo = NULL,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	}
};

const struct WildPokemonHeader gWildMonEveningHeaders[] =
{
	{
		.mapGroup = 0xFF,
		.mapNum = 0xFF,
		.landMonsInfo = NULL,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	}
};

const struct SwarmData gSwarmTable[] =
{
	/*{
		.mapName = 0xFF,
		.species = 0xFFFF,
	},*/
};

const u16 gSwarmTableLength = NELEMS(gSwarmTable);
