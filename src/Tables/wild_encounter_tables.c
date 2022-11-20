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
	{55, 60, SPECIES_TENTACOOL},//60
	{55, 60, SPECIES_TENTACOOL},//30
	{55, 60, SPECIES_TENTACRUEL},//5
	{55, 60, SPECIES_TENTACRUEL},//4
	{55, 60, SPECIES_TENTACRUEL},//1
};
const struct WildPokemonInfo gPalletTown_SurfMonsInfo = {21, gPalletTown_SurfMons};

const struct WildPokemon gPalletTown_FishingMons[] = 
{
	{ 3,  4, SPECIES_TENTACOOL},//old rod 70
	{ 4,  5, SPECIES_BINACLE},//old rod 30
	{30, 32, SPECIES_BARBOACH},//good rod 60
	{30, 32, SPECIES_CARVANHA},//good rod 20
	{30, 32, SPECIES_QWILFISH},//good rod 20
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_CLAMPERL},//super rod 15
	{55, 60, SPECIES_WHISCASH},//super rod 4
	{55, 60, SPECIES_WHISCASH},//super rod 1
};
const struct WildPokemonInfo gPalletTown_FishingMonsInfo = {21, gPalletTown_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 1
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute1_LandMonsMorning[] = 
{
	{3, 4, SPECIES_BIDOOF},//20
	{3, 4, SPECIES_ZIGZAGOON},//20
	{3, 4, SPECIES_RATTATA},//10
	{3, 4, SPECIES_SEEDOT},//10
	{3, 4, SPECIES_PIDGEY},//10
	{3, 4, SPECIES_YUNGOOS},//10
	{4, 5, SPECIES_MEOWTH},//5
	{4, 5, SPECIES_MEOWTH},//5
	{4, 5, SPECIES_MIENFOO},//4
	{4, 5, SPECIES_MIENFOO},//4
	{4, 5, SPECIES_PANSEAR},//1
	{4, 5, SPECIES_PANSEAR},//1
};
const struct WildPokemonInfo gRoute1_LandMonsMorningInfo = {21, gRoute1_LandMonsMorning};

const struct WildPokemon gRoute1_LandMonsNight[] = 
{
	{3, 4, SPECIES_POOCHYENA},//20
	{3, 4, SPECIES_ZIGZAGOON_G},//20
	{3, 4, SPECIES_RATTATA_A},//10
	{3, 4, SPECIES_SEEDOT},//10
	{3, 4, SPECIES_HOOTHOOT},//10
	{3, 4, SPECIES_YUNGOOS},//10
	{4, 5, SPECIES_MEOWTH_G},//5
	{4, 5, SPECIES_MEOWTH_G},//5
	{4, 5, SPECIES_SCRAGGY},//4
	{4, 5, SPECIES_SCRAGGY},//4
	{4, 5, SPECIES_PANSEAR},//1
	{4, 5, SPECIES_PANSEAR},//1
};
const struct WildPokemonInfo gRoute1_LandMonsNightInfo = {21, gRoute1_LandMonsNight};

const struct WildPokemon gRoute1_SurfMons[] = 
{
	{55, 60, SPECIES_LANTURN},//60
	{55, 60, SPECIES_LANTURN},//30
	{55, 60, SPECIES_LANTURN},//5
	{55, 60, SPECIES_LANTURN},//4
	{55, 60, SPECIES_LANTURN},//1
};
const struct WildPokemonInfo gRoute1_SurfMonsInfo = {21, gRoute1_SurfMons};

const struct WildPokemon gRoute1_FishingMons[] = 
{
	{ 3,  4, SPECIES_MARILL},//old rod 70
	{ 4,  5, SPECIES_CLAMPERL},//old rod 30
	{30, 32, SPECIES_CLAUNCHER},//good rod 60
	{30, 32, SPECIES_REMORAID},//good rod 20
	{30, 32, SPECIES_CORSOLA_G},//good rod 20
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_BRUXISH},//super rod 15
	{55, 60, SPECIES_CLAWITZER},//super rod 4
	{55, 60, SPECIES_CLAWITZER},//super rod 1
};
const struct WildPokemonInfo gRoute1_FishingMonsInfo = {21, gRoute1_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Viridian City
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gViridianCity_LandMonsMorning[] = 
{
	{4, 5, SPECIES_PATRAT},//20
	{4, 5, SPECIES_WOOLOO},//20
	{4, 5, SPECIES_SANDSHREW},//10
	{4, 5, SPECIES_WINGULL},//10
	{4, 5, SPECIES_PIKIPEK},//10
	{4, 5, SPECIES_CUBCHOO},//10
	{5, 6, SPECIES_DEERLING_SUMMER},//5
	{5, 6, SPECIES_SANDILE},//5
	{5, 6, SPECIES_SHINX},//4
	{5, 6, SPECIES_SNOVER},//4
	{5, 6, SPECIES_CHINCHOU},//1
	{5, 6, SPECIES_CHINCHOU},//1
};
const struct WildPokemonInfo gViridianCity_LandMonsMorningInfo = {21, gViridianCity_LandMonsMorning};

const struct WildPokemon gViridianCity_LandMonsNight[] = 
{
	{4, 5, SPECIES_PATRAT},//20
	{4, 5, SPECIES_MAREEP},//20
	{4, 5, SPECIES_POOCHYENA},//10
	{4, 5, SPECIES_SPEAROW},//10
	{4, 5, SPECIES_PIKIPEK},//10
	{4, 5, SPECIES_CUBCHOO},//10
	{5, 6, SPECIES_DEERLING_AUTUMN},//5
	{5, 6, SPECIES_SHUPPET},//5
	{5, 6, SPECIES_SHINX},//4
	{5, 6, SPECIES_SWINUB},//4
	{5, 6, SPECIES_LOTAD},//1
	{5, 6, SPECIES_LOTAD},//1
};
const struct WildPokemonInfo gViridianCity_LandMonsNightInfo = {21, gViridianCity_LandMonsNight};

const struct WildPokemon gViridianCity_SurfMons[] = 
{
	{55, 60, SPECIES_LANTURN},//60
	{55, 60, SPECIES_LANTURN},//30
	{55, 60, SPECIES_LANTURN},//5
	{55, 60, SPECIES_LANTURN},//4
	{55, 60, SPECIES_LANTURN},//1
};
const struct WildPokemonInfo gViridianCity_SurfMonsInfo = {21, gViridianCity_SurfMons};

const struct WildPokemon gViridianCity_FishingMons[] = 
{
	{ 3,  4, SPECIES_MARILL},//old rod 70
	{ 4,  5, SPECIES_CLAMPERL},//old rod 30
	{30, 32, SPECIES_CLAUNCHER},//good rod 60
	{30, 32, SPECIES_REMORAID},//good rod 20
	{30, 32, SPECIES_CORSOLA_G},//good rod 20
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_BRUXISH},//super rod 15
	{55, 60, SPECIES_CLAWITZER},//super rod 4
	{55, 60, SPECIES_CLAWITZER},//super rod 1
};
const struct WildPokemonInfo gViridianCity_FishingMonsInfo = {21, gViridianCity_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 22
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute22_LandMonsMorning[] = 
{
	{ 6, 8, SPECIES_STARLY},//20
	{ 6, 8, SPECIES_BUDEW},//20
	{ 6, 8, SPECIES_MANKEY},//10
	{ 6, 8, SPECIES_MORELULL},//10
	{ 6, 8, SPECIES_BELLSPROUT},//10
	{ 6, 8, SPECIES_LILLIPUP},//10
	{ 7, 9, SPECIES_ODDISH},//5
	{ 7, 9, SPECIES_SANDYGAST},//5
	{ 7, 9, SPECIES_FLABEBE},//4
	{ 7, 9, SPECIES_ROCKRUFF},//4
	{ 7, 9, SPECIES_PANPOUR},//1
	{ 7, 9, SPECIES_PANPOUR},//1
};
const struct WildPokemonInfo gRoute22_LandMonsMorningInfo = {21, gRoute22_LandMonsMorning};

const struct WildPokemon gRoute22_LandMonsNight[] = 
{
	{ 6, 8, SPECIES_STARLY},//20
	{ 6, 8, SPECIES_SANDSHREW_A},//20
	{ 6, 8, SPECIES_MANKEY},//10
	{ 6, 8, SPECIES_MORELULL},//10
	{ 6, 8, SPECIES_PARAS},//10
	{ 6, 8, SPECIES_SKWOVET},//10
	{ 7, 9, SPECIES_APPLIN},//5
	{ 7, 9, SPECIES_SANDYGAST},//5
	{ 7, 9, SPECIES_SNUBBULL},//4
	{ 7, 9, SPECIES_ROGGENROLA},//4
	{ 7, 9, SPECIES_PANPOUR},//1
	{ 7, 9, SPECIES_PANPOUR},//1
};
const struct WildPokemonInfo gRoute22_LandMonsNightInfo = {21, gRoute22_LandMonsNight};

const struct WildPokemon gRoute22_SurfMons[] = 
{
	{55, 60, SPECIES_PSYDUCK},//60
	{55, 60, SPECIES_PSYDUCK},//30
	{55, 60, SPECIES_PSYDUCK},//5
	{55, 60, SPECIES_PSYDUCK},//4
	{55, 60, SPECIES_PSYDUCK},//1
};
const struct WildPokemonInfo gRoute22_SurfMonsInfo = {21, gRoute22_SurfMons};

const struct WildPokemon gRoute22_FishingMons[] = 
{
	{ 3,  4, SPECIES_PSYDUCK},//old rod 70
	{ 4,  5, SPECIES_CORPHISH},//old rod 30
	{30, 32, SPECIES_CORPHISH},//good rod 60
	{30, 32, SPECIES_MANTYKE},//good rod 20
	{30, 32, SPECIES_MAREANIE},//good rod 20
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_BASCULIN_BLUE},//super rod 15
	{55, 60, SPECIES_WAILORD},//super rod 4
	{55, 60, SPECIES_WAILORD},//super rod 1
};
const struct WildPokemonInfo gRoute22_FishingMonsInfo = {21, gRoute22_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 2
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute2_LandMonsMorning[] = 
{
	{4, 5, SPECIES_BIDOOF},//20
	{4, 5, SPECIES_SENTRET},//20
	{4, 5, SPECIES_MAREEP},//10
	{4, 5, SPECIES_PHANPY},//10
	{4, 5, SPECIES_ZIGZAGOON},//10
	{4, 5, SPECIES_SHINX},//10
	{5, 6, SPECIES_PONYTA},//5
	{5, 6, SPECIES_LITLEO},//5
	{5, 6, SPECIES_MEDITITE},//4
	{5, 6, SPECIES_ABRA},//4
	{5, 6, SPECIES_PANSAGE},//1
	{5, 6, SPECIES_PANSAGE},//1
};
const struct WildPokemonInfo gRoute2_LandMonsMorningInfo = {21, gRoute2_LandMonsMorning};

const struct WildPokemon gRoute2_LandMonsNight[] = 
{
	{4, 5, SPECIES_POOCHYENA},//20
	{4, 5, SPECIES_SENTRET},//20
	{4, 5, SPECIES_MAREEP},//10
	{4, 5, SPECIES_PHANPY},//10
	{4, 5, SPECIES_ZIGZAGOON_G},//10
	{4, 5, SPECIES_SHINX},//10
	{5, 6, SPECIES_PONYTA_G},//5 
	{5, 6, SPECIES_HOUNDOUR},//5
	{5, 6, SPECIES_MEDITITE},//4
	{5, 6, SPECIES_ABRA},//4
	{5, 6, SPECIES_PANSAGE},//1
	{5, 6, SPECIES_PANSAGE},//1
};
const struct WildPokemonInfo gRoute2_LandMonsNightInfo = {21, gRoute2_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Viridian Forest
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gViridianForest_LandMonsMorning[] = 
{
	{5, 7, SPECIES_CATERPIE},//20
	{5, 7, SPECIES_WEEDLE},//20
	{5, 7, SPECIES_PIKACHU},//10
	{5, 7, SPECIES_BURMY_SANDY},//10
	{5, 7, SPECIES_SEWADDLE},//10
	{5, 7, SPECIES_SCATTERBUG},//10
	{6, 8, SPECIES_LEDYBA},//5
	{6, 8, SPECIES_SURSKIT},//5
	{6, 8, SPECIES_BURMY},//4
	{6, 8, SPECIES_SHROOMISH},//4
	{6, 8, SPECIES_COMBEE},//1
	{6, 8, SPECIES_JOLTIK},//1
};
const struct WildPokemonInfo gViridianForest_LandMonsMorningInfo = {21, gViridianForest_LandMonsMorning};

const struct WildPokemon gViridianForest_LandMonsNight[] = 
{
	{5, 7, SPECIES_SPINARAK},//20
	{5, 7, SPECIES_WURMPLE},//20
	{5, 7, SPECIES_PIKACHU},//10
	{5, 7, SPECIES_BURMY_TRASH},//10
	{5, 7, SPECIES_NINCADA},//10
	{5, 7, SPECIES_KRICKETOT},//10
	{6, 8, SPECIES_LEDYBA},//5
	{6, 8, SPECIES_BLIPBUG},//5
	{6, 8, SPECIES_GRUBBIN},//4
	{6, 8, SPECIES_PUMPKABOO_L},//4
	{6, 8, SPECIES_PHANTUMP},//1
	{6, 8, SPECIES_CHATOT},//1
};
const struct WildPokemonInfo gViridianForest_LandMonsNightInfo = {21, gViridianForest_LandMonsNight};

const struct WildPokemon gViridianForest_SurfMons[] = 
{
	{55, 60, SPECIES_ARAQUANID},//60
	{55, 60, SPECIES_ARAQUANID},//30
	{55, 60, SPECIES_ARAQUANID},//5
	{55, 60, SPECIES_ARAQUANID},//4
	{55, 60, SPECIES_ARAQUANID},//1
};
const struct WildPokemonInfo gViridianForest_SurfMonsInfo = {21, gViridianForest_SurfMons};

const struct WildPokemon gViridianForest_FishingMons[] = 
{
	{ 3,  4, SPECIES_LOTAD},//old rod 70
	{ 4,  5, SPECIES_SHELLOS},//old rod 30
	{30, 32, SPECIES_CHINCHOU},//good rod 60
	{30, 32, SPECIES_BUIZEL},//good rod 20
	{30, 32, SPECIES_FINNEON},//good rod 20
	{55, 60, SPECIES_LUDICOLO},//super rod 40
	{55, 60, SPECIES_LUDICOLO},//super rod 40
	{55, 60, SPECIES_PYUKUMUKU},//super rod 15
	{55, 60, SPECIES_ARAQUANID},//super rod 4
	{55, 60, SPECIES_ARAQUANID},//super rod 1
};
const struct WildPokemonInfo gViridianForest_FishingMonsInfo = {21, gViridianForest_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Pewter City
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gPewterCity_LandMonsMorning[] = 
{
	{7, 9, SPECIES_GRIMER},//20
	{7, 9, SPECIES_STARLY},//20
	{7, 9, SPECIES_EKANS},//10
	{7, 9, SPECIES_SPOINK},//10
	{7, 9, SPECIES_HOPPIP},//10
	{7, 9, SPECIES_NUMEL},//10
	{9, 11, SPECIES_EXEGGCUTE},//5
	{9, 11, SPECIES_BONSLY},//5
	{9, 11, SPECIES_CUTIEFLY},//4
	{9, 11, SPECIES_PHANPY},//4
	{9, 11, SPECIES_AXEW},//1
	{9, 11, SPECIES_SINISTEA},//1
};
const struct WildPokemonInfo gPewterCity_LandMonsMorningInfo = {21, gPewterCity_LandMonsMorning};

const struct WildPokemon gPewterCity_LandMonsNight[] = 
{
	{7, 9, SPECIES_GRIMER_A},//20
	{7, 9, SPECIES_STARLY},//20
	{7, 9, SPECIES_EKANS},//10
	{7, 9, SPECIES_ESPURR},//10
	{7, 9, SPECIES_SKIDDO},//10
	{7, 9, SPECIES_NUMEL},//10
	{9, 11, SPECIES_EXEGGUTOR_A},//5 
	{9, 11, SPECIES_BONSLY},//5
	{9, 11, SPECIES_GASTLY},//4
	{9, 11, SPECIES_PHANPY},//4
	{9, 11, SPECIES_AXEW},//1
	{9, 11, SPECIES_SINISTEA},//1
};
const struct WildPokemonInfo gPewterCity_LandMonsNightInfo = {21, gPewterCity_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 3
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute3_LandMonsMorning[] = 
{
	{10, 12, SPECIES_FLETCHLING},//20
	{10, 12, SPECIES_EKANS},//20
	{10, 12, SPECIES_SPEAROW},//10
	{10, 12, SPECIES_NIDORAN_M},//10
	{10, 12, SPECIES_NICKIT},//10
	{10, 12, SPECIES_SHROOMISH},//10
	{12, 14, SPECIES_BUNEARY},//5
	{12, 14, SPECIES_BUNEARY},//5
	{12, 14, SPECIES_LITLEO},//4
	{12, 14, SPECIES_STUNKY},//4
	{12, 14, SPECIES_JIGGLYPUFF},//1
	{12, 14, SPECIES_MEOWTH_A},//1
};
const struct WildPokemonInfo gRoute3_LandMonsMorningInfo = {21, gRoute3_LandMonsMorning};

const struct WildPokemon gRoute3_LandMonsNight[] = 
{
	{10, 12, SPECIES_FLETCHLING},//20
	{10, 12, SPECIES_EKANS},//20
	{10, 12, SPECIES_SPEAROW},//10
	{10, 12, SPECIES_NIDORAN_F},//10
	{10, 12, SPECIES_NICKIT},//10
	{10, 12, SPECIES_SKIDDO},//10
	{12, 14, SPECIES_BUNEARY},//5 
	{12, 14, SPECIES_BUNEARY},//5
	{12, 14, SPECIES_LITLEO},//4
	{12, 14, SPECIES_GLAMEOW},//4
	{12, 14, SPECIES_JIGGLYPUFF},//1
	{12, 14, SPECIES_MEOWTH_A},//1
};
const struct WildPokemonInfo gRoute3_LandMonsNightInfo = {21, gRoute3_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 4
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute4_LandMonsMorning[] = 
{
	{14, 16, SPECIES_PIDOVE},//20
	{14, 16, SPECIES_BELLSPROUT},//20
	{14, 16, SPECIES_SHINX},//10
	{14, 16, SPECIES_PACHIRISU},//10
	{14, 16, SPECIES_GLAMEOW},//10
	{14, 16, SPECIES_BUNEARY},//10
	{16, 18, SPECIES_PUMPKABOO},//5
	{16, 18, SPECIES_FLABEBE},//5
	{16, 18, SPECIES_PUMPKABOO_M},//4
	{16, 18, SPECIES_PUMPKABOO_M},//4
	{16, 18, SPECIES_YANMA},//1
	{16, 18, SPECIES_ROOKIDEE},//1
};
const struct WildPokemonInfo gRoute4_LandMonsMorningInfo = {21, gRoute4_LandMonsMorning};

const struct WildPokemon gRoute4_LandMonsNight[] = 
{
	{14, 16, SPECIES_PIDGEY},//20
	{14, 16, SPECIES_ODDISH},//20
	{14, 16, SPECIES_MAREEP},//10
	{14, 16, SPECIES_PACHIRISU},//10
	{14, 16, SPECIES_STUNKY},//10
	{14, 16, SPECIES_BUNEARY},//10
	{16, 18, SPECIES_PHANTUMP},//5 
	{16, 18, SPECIES_FLABEBE},//5
	{16, 18, SPECIES_PUMPKABOO_L},//4
	{16, 18, SPECIES_PUMPKABOO_L},//4
	{16, 18, SPECIES_YANMA},//1
	{16, 18, SPECIES_YANMA},//1
};
const struct WildPokemonInfo gRoute4_LandMonsNightInfo = {21, gRoute4_LandMonsNight};

const struct WildPokemon gRoute4_SurfMons[] = 
{
	{55, 60, SPECIES_GOLDUCK},//60
	{55, 60, SPECIES_GOLDUCK},//30
	{55, 60, SPECIES_GOLDUCK},//5
	{55, 60, SPECIES_GOLDUCK},//4
	{55, 60, SPECIES_GOLDUCK},//1
};
const struct WildPokemonInfo gRoute4_SurfMonsInfo = {21, gRoute4_SurfMons};

const struct WildPokemon gRoute4_FishingMons[] = 
{
	{ 3,  4, SPECIES_CHEWTLE},//old rod 70
	{ 4,  5, SPECIES_CLAUNCHER},//old rod 30
	{30, 32, SPECIES_WISHIWASHI},//good rod 60
	{30, 32, SPECIES_WAILMER},//good rod 20
	{30, 32, SPECIES_REMORAID},//good rod 20
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_SHARPEDO},//super rod 15
	{55, 60, SPECIES_OCTILLERY},//super rod 4
	{55, 60, SPECIES_OCTILLERY},//super rod 1
};
const struct WildPokemonInfo gRoute4_FishingMonsInfo = {21, gRoute4_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Mt Moon
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gMtMoon1F_LandMonsMorning[] = 
{
	{12, 16, SPECIES_GEODUDE},//20
	{12, 16, SPECIES_ZUBAT},//20
	{12, 16, SPECIES_ROCKRUFF},//10
	{12, 16, SPECIES_TIMBURR},//10
	{12, 16, SPECIES_WOOBAT},//10
	{12, 16, SPECIES_CHEWTLE},//10
	{14, 16, SPECIES_MAKUHITA},//5
	{14, 16, SPECIES_MAKUHITA},//5
	{14, 16, SPECIES_TYROGUE},//4
	{14, 16, SPECIES_CLEFAIRY},//4
	{14, 16, SPECIES_ELGYEM},//1
	{14, 14, SPECIES_THROH},//1
};
const struct WildPokemonInfo gMtMoon1F_LandMonsMorningInfo = {21, gMtMoon1F_LandMonsMorning};

const struct WildPokemon gMtMoon1F_LandMonsNight[] = 
{
	{12, 16, SPECIES_GEODUDE_A},//20
	{12, 16, SPECIES_ZUBAT},//20
	{12, 16, SPECIES_ROCKRUFF},//10
	{12, 16, SPECIES_MACHOP},//10
	{12, 16, SPECIES_NOIBAT},//10
	{12, 16, SPECIES_TYMPOLE},//10
	{14, 16, SPECIES_MAKUHITA},//5 
	{14, 16, SPECIES_MAKUHITA},//5
	{14, 16, SPECIES_TYROGUE},//4
	{14, 16, SPECIES_CLEFAIRY},//4
	{14, 16, SPECIES_ELGYEM},//1
	{14, 14, SPECIES_THROH},//1
};
const struct WildPokemonInfo gMtMoon1F_LandMonsNightInfo = {21, gMtMoon1F_LandMonsNight};

const struct WildPokemon gMtMoonB1F_LandMonsMorning[] = 
{
	{12, 16, SPECIES_PARAS},//20
	{12, 16, SPECIES_PARAS},//20
	{12, 16, SPECIES_SLUGMA},//10
	{12, 16, SPECIES_SLUGMA},//10
	{12, 16, SPECIES_DWEBBLE},//10
	{12, 16, SPECIES_TEDDIURSA},//10
	{14, 16, SPECIES_BALTOY},//5
	{14, 16, SPECIES_BALTOY},//5
	{14, 16, SPECIES_SHUPPET},//4
	{14, 16, SPECIES_SHUPPET},//4
	{14, 16, SPECIES_TORKOAL},//1
	{14, 14, SPECIES_RIOLU},//1
};
const struct WildPokemonInfo gMtMoonB1F_LandMonsMorningInfo = {21, gMtMoonB1F_LandMonsMorning};

const struct WildPokemon gMtMoonB1F_LandMonsNight[] = 
{
	{12, 16, SPECIES_PARAS},//20
	{12, 16, SPECIES_PARAS},//20
	{12, 16, SPECIES_SLUGMA},//10
	{12, 16, SPECIES_SLUGMA},//10
	{12, 16, SPECIES_DWEBBLE},//10
	{12, 16, SPECIES_TEDDIURSA},//10
	{14, 16, SPECIES_SANDILE},//5 
	{14, 16, SPECIES_SANDILE},//5
	{14, 16, SPECIES_MISDREAVUS},//4
	{14, 16, SPECIES_MISDREAVUS},//4
	{14, 16, SPECIES_TORKOAL},//1
	{14, 14, SPECIES_RIOLU},//1
};
const struct WildPokemonInfo gMtMoonB1F_LandMonsNightInfo = {21, gMtMoonB1F_LandMonsNight};

const struct WildPokemon gMtMoonB2F_LandMonsMorning[] = 
{
	{12, 16, SPECIES_MAWILE},//20
	{12, 16, SPECIES_ZUBAT},//20
	{12, 16, SPECIES_PAWNIARD},//10
	{12, 16, SPECIES_PAWNIARD},//10
	{12, 16, SPECIES_NUMEL},//10
	{12, 16, SPECIES_MUDBRAY},//10
	{14, 16, SPECIES_MUDBRAY},//5
	{14, 16, SPECIES_SMOOCHUM},//5
	{14, 16, SPECIES_ONIX},//4
	{14, 16, SPECIES_SOLROCK},//4
	{14, 16, SPECIES_DRILBUR},//1
	{14, 14, SPECIES_DRILBUR},//1
};
const struct WildPokemonInfo gMtMoonB2F_LandMonsMorningInfo = {21, gMtMoonB2F_LandMonsMorning};

const struct WildPokemon gMtMoonB2F_LandMonsNight[] = 
{
	{12, 16, SPECIES_MAWILE},//20
	{12, 16, SPECIES_ZUBAT},//20
	{12, 16, SPECIES_PAWNIARD},//10
	{12, 16, SPECIES_PAWNIARD},//10
	{12, 16, SPECIES_ROLYCOLY},//10
	{12, 16, SPECIES_MUDBRAY},//10
	{14, 16, SPECIES_MUDBRAY},//5 
	{14, 16, SPECIES_MUNNA},//5
	{14, 16, SPECIES_ONIX},//4
	{14, 16, SPECIES_LUNATONE},//4
	{14, 16, SPECIES_DRILBUR},//1
	{14, 14, SPECIES_DRILBUR},//1
};
const struct WildPokemonInfo gMtMoonB2F_LandMonsNightInfo = {21, gMtMoonB2F_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Cerulean City Here now
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gCeruleanCity_LandMonsMorning[] = 
{
	{15, 17, SPECIES_PATRAT},//20
	{15, 17, SPECIES_PATRAT},//20
	{15, 17, SPECIES_SANDSHREW},//10
	{15, 17, SPECIES_WINGULL},//10
	{15, 17, SPECIES_WOOLOO},//10
	{15, 17, SPECIES_CUBCHOO},//10
	{17, 19, SPECIES_DEERLING_SUMMER},//5
	{17, 19, SPECIES_TRUMBEAK},//5
	{17, 19, SPECIES_SANDILE},//4
	{17, 19, SPECIES_SNOVER},//4
	{17, 19, SPECIES_LUXIO},//1
	{17, 19, SPECIES_LUXIO},//1
};
const struct WildPokemonInfo gCeruleanCity_LandMonsMorningInfo = {21, gCeruleanCity_LandMonsMorning};

const struct WildPokemon gCeruleanCity_LandMonsNight[] = 
{
	{15, 17, SPECIES_PATRAT},//20
	{15, 17, SPECIES_PATRAT},//20
	{15, 17, SPECIES_POOCHYENA},//10
	{15, 17, SPECIES_SPEAROW},//10
	{15, 17, SPECIES_MAREEP},//10
	{15, 17, SPECIES_CUBCHOO},//10
	{17, 19, SPECIES_DEERLING_AUTUMN},//5
	{17, 19, SPECIES_DWEBBLE},//5
	{17, 19, SPECIES_SHUPPET},//4
	{17, 19, SPECIES_SWINUB},//4
	{17, 19, SPECIES_LOMBRE},//1
	{17, 19, SPECIES_LOMBRE},//1
};
const struct WildPokemonInfo gCeruleanCity_LandMonsNightInfo = {21, gCeruleanCity_LandMonsNight};

const struct WildPokemon gCeruleanCity_SurfMons[] = 
{
	{55, 60, SPECIES_GOLDUCK},//60
	{55, 60, SPECIES_GOLDUCK},//30
	{55, 60, SPECIES_GOLDUCK},//5
	{55, 60, SPECIES_GOLDUCK},//4
	{55, 60, SPECIES_GOLDUCK},//1
};
const struct WildPokemonInfo gCeruleanCity_SurfMonsInfo = {21, gCeruleanCity_SurfMons};

const struct WildPokemon gCeruleanCity_FishingMons[] = 
{
	{ 3,  4, SPECIES_CHEWTLE},//old rod 70
	{ 4,  5, SPECIES_CLAUNCHER},//old rod 30
	{30, 32, SPECIES_WISHIWASHI},//good rod 60
	{30, 32, SPECIES_WAILMER},//good rod 20
	{30, 32, SPECIES_REMORAID},//good rod 20
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_SHARPEDO},//super rod 15
	{55, 60, SPECIES_OCTILLERY},//super rod 4
	{55, 60, SPECIES_OCTILLERY},//super rod 1
};
const struct WildPokemonInfo gCeruleanCity_FishingMonsInfo = {21, gCeruleanCity_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 24
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute24_LandMonsMorning[] = 
{
	{17, 19, SPECIES_SNUBBULL},//20
	{17, 19, SPECIES_PETILIL},//20
	{17, 19, SPECIES_YAMASK},//10
	{17, 19, SPECIES_AIPOM},//10
	{17, 19, SPECIES_KARRABLAST},//10
	{17, 19, SPECIES_VOLBEAT},//10
	{19, 21, SPECIES_MARILL},//5
	{19, 21, SPECIES_FARFETCHD},//5
	{19, 21, SPECIES_RALTS},//4
	{19, 21, SPECIES_ABRA},//4
	{19, 21, SPECIES_GLIGAR},//1
	{19, 21, SPECIES_TOXEL},//1
};
const struct WildPokemonInfo gRoute24_LandMonsMorningInfo = {21, gRoute24_LandMonsMorning};

const struct WildPokemon gRoute24_LandMonsNight[] = 
{
	{17, 19, SPECIES_SNUBBULL},//20
	{17, 19, SPECIES_COTTONEE},//20
	{17, 19, SPECIES_YAMPER},//10
	{17, 19, SPECIES_SLAKOTH},//10
	{17, 19, SPECIES_KARRABLAST},//10
	{17, 19, SPECIES_ILLUMISE},//10
	{19, 21, SPECIES_BUIZEL},//5
	{19, 21, SPECIES_MURKROW},//5
	{19, 21, SPECIES_RALTS},//4
	{19, 21, SPECIES_ABRA},//4
	{19, 21, SPECIES_GLIGAR},//1
	{19, 21, SPECIES_TOXEL},//1
};
const struct WildPokemonInfo gRoute24_LandMonsNightInfo = {21, gRoute24_LandMonsNight};

const struct WildPokemon gRoute24_SurfMons[] = 
{
	{55, 60, SPECIES_GOLDUCK},//60
	{55, 60, SPECIES_GOLDUCK},//30
	{55, 60, SPECIES_GOLDUCK},//5
	{55, 60, SPECIES_GOLDUCK},//4
	{55, 60, SPECIES_GOLDUCK},//1
};
const struct WildPokemonInfo gRoute24_SurfMonsInfo = {21, gRoute24_SurfMons};

const struct WildPokemon gRoute24_FishingMons[] = 
{
	{ 3,  4, SPECIES_CARVANHA},//old rod 70
	{ 4,  5, SPECIES_LOTAD},//old rod 30
	{30, 32, SPECIES_WAILMER},//good rod 60
	{30, 32, SPECIES_WISHIWASHI},//good rod 20
	{30, 32, SPECIES_CARVANHA},//good rod 20
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_SHARPEDO},//super rod 15
	{55, 60, SPECIES_OCTILLERY},//super rod 4
	{55, 60, SPECIES_OCTILLERY},//super rod 1
};
const struct WildPokemonInfo gRoute24_FishingMonsInfo = {21, gRoute24_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 25
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute25_LandMonsMorning[] = 
{
	{19, 21, SPECIES_SWABLU},//20
	{19, 21, SPECIES_TAILLOW},//20
	{19, 21, SPECIES_PINECO},//10
	{19, 21, SPECIES_POLIWAG},//10
	{19, 21, SPECIES_ELEKID},//10
	{19, 21, SPECIES_DODUO},//10
	{21, 23, SPECIES_AUDINO},//5
	{21, 23, SPECIES_WHISMUR},//5
	{21, 23, SPECIES_AIPOM},//4
	{21, 23, SPECIES_ABRA},//4
	{21, 23, SPECIES_ZANGOOSE},//1
	{21, 23, SPECIES_FARFETCHD_G},//1
};
const struct WildPokemonInfo gRoute25_LandMonsMorningInfo = {21, gRoute25_LandMonsMorning};

const struct WildPokemon gRoute25_LandMonsNight[] = 
{
	{19, 21, SPECIES_SWABLU},//20
	{19, 21, SPECIES_TAILLOW},//20
	{19, 21, SPECIES_VENONAT},//10
	{19, 21, SPECIES_PSYDUCK},//10
	{19, 21, SPECIES_MAGBY},//10
	{19, 21, SPECIES_DODUO},//10
	{21, 23, SPECIES_AUDINO},//5
	{21, 23, SPECIES_PURRLOIN},//5
	{21, 23, SPECIES_SLAKOTH},//4
	{21, 23, SPECIES_ABRA},//4
	{21, 23, SPECIES_SEVIPER},//1
	{21, 23, SPECIES_FARFETCHD_G},//1
};
const struct WildPokemonInfo gRoute25_LandMonsNightInfo = {21, gRoute25_LandMonsNight};

const struct WildPokemon gRoute25_SurfMons[] = 
{
	{55, 60, SPECIES_PSYDUCK},//60
	{55, 60, SPECIES_PSYDUCK},//30
	{55, 60, SPECIES_PSYDUCK},//5
	{55, 60, SPECIES_PSYDUCK},//4
	{55, 60, SPECIES_PSYDUCK},//1
};
const struct WildPokemonInfo gRoute25_SurfMonsInfo = {21, gRoute25_SurfMons};

const struct WildPokemon gRoute25_FishingMons[] = 
{
	{ 3,  4, SPECIES_MAGIKARP},//old rod 70
	{ 4,  5, SPECIES_CHINCHOU},//old rod 30
	{30, 32, SPECIES_DEWPIDER},//good rod 60
	{30, 32, SPECIES_MANTYKE},//good rod 20
	{30, 32, SPECIES_GOLDEEN},//good rod 20
	{55, 60, SPECIES_POLIWAG},//super rod 40
	{55, 60, SPECIES_POLIWHIRL},//super rod 40
	{55, 60, SPECIES_GYARADOS},//super rod 15
	{55, 60, SPECIES_PSYDUCK},//super rod 4
	{55, 60, SPECIES_PSYDUCK},//super rod 1
};
const struct WildPokemonInfo gRoute25_FishingMonsInfo = {21, gRoute25_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 5 Land Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute5_LandMonsMorning[] = 
{
	{21, 23, SPECIES_MEOWTH},//20
	{21, 23, SPECIES_HATENNA},//20
	{21, 23, SPECIES_SOLOSIS},//10
	{21, 23, SPECIES_GROWLITHE},//10
	{21, 23, SPECIES_SWIRLIX},//10
	{21, 23, SPECIES_MORELULL},//10
	{23, 25, SPECIES_VULPIX},//5
	{23, 25, SPECIES_SOLOSIS},//5
	{23, 25, SPECIES_GRIMER},//4
	{23, 25, SPECIES_EISCUE},//4
	{23, 25, SPECIES_DRIFLOON},//1
	{23, 25, SPECIES_DRIFLOON},//1
};
const struct WildPokemonInfo gRoute5_LandMonsMorningInfo = {21, gRoute5_LandMonsMorning};

const struct WildPokemon gRoute5_LandMonsNight[] = 
{
	{21, 23, SPECIES_MEOWTH_G},//20
	{21, 23, SPECIES_HATENNA},//20
	{21, 23, SPECIES_GOTHITA},//10
	{21, 23, SPECIES_VULPIX_A},//10
	{21, 23, SPECIES_SPRITZEE},//10
	{21, 23, SPECIES_MORELULL},//10
	{23, 25, SPECIES_GROWLITHE},//5
	{23, 25, SPECIES_GOTHITA},//5
	{23, 25, SPECIES_GRIMER_A},//4
	{23, 25, SPECIES_EISCUE},//4
	{23, 25, SPECIES_DRIFLOON},//1
	{23, 25, SPECIES_DRIFLOON},//1
};
const struct WildPokemonInfo gRoute5_LandMonsNightInfo = {21, gRoute5_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 6 Land Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute6_LandMonsMorning[] = 
{
	{21, 23, SPECIES_SUNKERN},//20
	{21, 23, SPECIES_CHERUBI},//20
	{21, 23, SPECIES_GULPIN},//10
	{21, 23, SPECIES_FURFROU},//10
	{21, 23, SPECIES_SIZZLIPEDE},//10
	{21, 23, SPECIES_DEDENNE},//10
	{23, 25, SPECIES_LICKITUNG},//5
	{23, 25, SPECIES_LICKITUNG},//5
	{23, 25, SPECIES_MEDITITE},//4
	{23, 25, SPECIES_MEDITITE},//4
	{23, 25, SPECIES_TOGEPI},//1
	{23, 25, SPECIES_MILCERY},//1
};
const struct WildPokemonInfo gRoute6_LandMonsMorningInfo = {21, gRoute6_LandMonsMorning};

const struct WildPokemon gRoute6_LandMonsNight[] = 
{
	{21, 23, SPECIES_BOUNSWEET},//20
	{21, 23, SPECIES_GOSSIFLEUR},//20
	{21, 23, SPECIES_TRUBBISH},//10
	{21, 23, SPECIES_FURFROU},//10
	{21, 23, SPECIES_SIZZLIPEDE},//10
	{21, 23, SPECIES_DEDENNE},//10
	{23, 25, SPECIES_KOMALA},//5
	{23, 25, SPECIES_KOMALA},//5
	{23, 25, SPECIES_MEDITITE},//4
	{23, 25, SPECIES_MEDITITE},//4
	{23, 25, SPECIES_TOGEPI},//1
	{23, 25, SPECIES_MILCERY},//1
};
const struct WildPokemonInfo gRoute6_LandMonsNightInfo = {21, gRoute6_LandMonsNight};

const struct WildPokemon gRoute6_SurfMons[] = 
{
	{55, 60, SPECIES_PSYDUCK},//60
	{55, 60, SPECIES_PSYDUCK},//30
	{55, 60, SPECIES_PSYDUCK},//5
	{55, 60, SPECIES_PSYDUCK},//4
	{55, 60, SPECIES_PSYDUCK},//1
};
const struct WildPokemonInfo gRoute6_SurfMonsInfo = {21, gRoute6_SurfMons};

const struct WildPokemon gRoute6_FishingMons[] = 
{
	{ 3,  4, SPECIES_CHINCHOU},//old rod 70
	{ 4,  5, SPECIES_SHELLDER},//old rod 30
	{30, 32, SPECIES_SLOWPOKE_G},//good rod 60
	{30, 32, SPECIES_SLOWPOKE_G},//good rod 20
	{30, 32, SPECIES_QWILFISH},//good rod 20
	{55, 60, SPECIES_SLOWBRO_G},//super rod 40
	{55, 60, SPECIES_LANTURN},//super rod 40
	{55, 60, SPECIES_GYARADOS},//super rod 15
	{55, 60, SPECIES_PSYDUCK},//super rod 4
	{55, 60, SPECIES_GOLDUCK},//super rod 1
};
const struct WildPokemonInfo gRoute6_FishingMonsInfo = {21, gRoute6_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Vermillion City
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gVermillionCity_SurfMons[] = 
{
	{55, 60, SPECIES_TENTACOOL},//60
	{55, 60, SPECIES_PELIPPER},//30
	{55, 60, SPECIES_TENTACRUEL},//5
	{55, 60, SPECIES_TENTACRUEL},//4
	{55, 60, SPECIES_TENTACRUEL},//1
};
const struct WildPokemonInfo gVermillionCity_SurfMonsInfo = {21, gVermillionCity_SurfMons};

const struct WildPokemon gVermillionCity_FishingMons[] = 
{
	{ 3,  4, SPECIES_ARROKUDA},//old rod 70
	{ 4,  5, SPECIES_FINNEON},//old rod 30
	{30, 32, SPECIES_FRILLISH},//good rod 60
	{30, 32, SPECIES_SHELLDER},//good rod 20
	{30, 32, SPECIES_KRABBY},//good rod 20
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_ALOMOMOLA},//super rod 15
	{55, 60, SPECIES_SEADRA},//super rod 4
	{55, 60, SPECIES_GYARADOS},//super rod 1
};
const struct WildPokemonInfo gVermillionCity_FishingMonsInfo = {21, gVermillionCity_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ SS Anne
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gSSAnne_SurfMons[] = 
{
	{55, 60, SPECIES_TENTACOOL},//60
	{55, 60, SPECIES_TENTACOOL},//30
	{55, 60, SPECIES_TENTACRUEL},//5
	{55, 60, SPECIES_BARRASKEWDA},//4
	{55, 60, SPECIES_BARRASKEWDA},//1
};
const struct WildPokemonInfo gSSAnne_SurfMonsInfo = {21, gSSAnne_SurfMons};

const struct WildPokemon gSSAnne_FishingMons[] = 
{
	{ 3,  4, SPECIES_WIMPOD},//old rod 70
	{ 4,  5, SPECIES_FINNEON},//old rod 30
	{30, 32, SPECIES_FRILLISH},//good rod 60
	{30, 32, SPECIES_STARYU},//good rod 20
	{30, 32, SPECIES_KRABBY},//good rod 20
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_ALOMOMOLA},//super rod 15
	{55, 60, SPECIES_SEADRA},//super rod 4
	{55, 60, SPECIES_GYARADOS},//super rod 1
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
	{30, 32, SPECIES_SCRAGGY},//5
	{30, 32, SPECIES_SCRAGGY},//5
	{30, 32, SPECIES_SANDYGAST},//4
	{30, 32, SPECIES_SANDYGAST},//4
	{30, 32, SPECIES_SIGILYPH},//1
	{30, 32, SPECIES_SIGILYPH},//1
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
	{30, 32, SPECIES_SCRAGGY},//5
	{30, 32, SPECIES_SCRAGGY},//5
	{30, 32, SPECIES_GOLETT},//4
	{30, 32, SPECIES_GOLETT},//4
	{30, 32, SPECIES_SIGILYPH},//1
	{30, 32, SPECIES_SIGILYPH},//1
};
const struct WildPokemonInfo gRoute11_LandMonsNightInfo = {21, gRoute11_LandMonsNight};

const struct WildPokemon gRoute11_SurfMons[] = 
{
	{55, 60, SPECIES_TENTACOOL},//60
	{55, 60, SPECIES_PELIPPER},//30
	{55, 60, SPECIES_TENTACRUEL},//5
	{55, 60, SPECIES_TENTACRUEL},//4
	{55, 60, SPECIES_TENTACRUEL},//1
};
const struct WildPokemonInfo gRoute11_SurfMonsInfo = {21, gRoute11_SurfMons};

const struct WildPokemon gRoute11_FishingMons[] = 
{
	{ 3,  4, SPECIES_KRABBY},//old rod 70
	{ 4,  5, SPECIES_HORSEA},//old rod 30
	{30, 32, SPECIES_SHELLDER},//good rod 60
	{30, 32, SPECIES_FRILLISH},//good rod 20
	{30, 32, SPECIES_RELICANTH},//good rod 20
	{55, 60, SPECIES_QWILFISH},//super rod 40
	{55, 60, SPECIES_QWILFISH},//super rod 40
	{55, 60, SPECIES_ALOMOMOLA},//super rod 15
	{55, 60, SPECIES_SEADRA},//super rod 4
	{55, 60, SPECIES_GYARADOS},//super rod 1
};
const struct WildPokemonInfo gRoute11_FishingMonsInfo = {21, gRoute11_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Digletts Cave
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gDiglettsCave_LandMonsMorning[] = 
{
	{ 8, 10, SPECIES_DIGLETT},//20
	{ 8, 10, SPECIES_MACHOP},//20
	{ 8, 10, SPECIES_NUMEL},//10
	{ 8, 10, SPECIES_YAMASK},//10
	{ 8, 10, SPECIES_SANDSHREW},//10
	{ 8, 10, SPECIES_GEODUDE},//10
	{10, 12, SPECIES_TRAPINCH},//5
	{10, 12, SPECIES_SILICOBRA},//5
	{10, 12, SPECIES_BRONZOR},//4
	{10, 12, SPECIES_NOSEPASS},//4
	{10, 12, SPECIES_NOIBAT},//1
	{10, 12, SPECIES_NOIBAT},//1
};
const struct WildPokemonInfo gDiglettsCave_LandMonsMorningInfo = {21, gDiglettsCave_LandMonsMorning};

const struct WildPokemon gDiglettsCave_LandMonsNight[] = 
{
	{ 8, 10, SPECIES_DIGLETT_A},//20
	{ 8, 10, SPECIES_PANCHAM},//20
	{ 8, 10, SPECIES_NUMEL},//10
	{ 8, 10, SPECIES_YAMASK_G},//10
	{ 8, 10, SPECIES_SANDSHREW},//10
	{ 8, 10, SPECIES_GEODUDE_A},//10
	{10, 12, SPECIES_TRAPINCH},//5
	{10, 12, SPECIES_SILICOBRA},//5
	{10, 12, SPECIES_BRONZOR},//4
	{10, 12, SPECIES_NOSEPASS},//4
	{10, 12, SPECIES_NOIBAT},//1
	{10, 12, SPECIES_NOIBAT},//1
};
const struct WildPokemonInfo gDiglettsCave_LandMonsNightInfo = {21, gDiglettsCave_LandMonsNight};

const struct WildPokemon gDiglettsCaveB1F_LandMonsMorning[] = 
{
	{28, 30, SPECIES_DIGLETT},//20
	{28, 30, SPECIES_DIGLETT},//20
	{28, 30, SPECIES_STUNFISK},//10
	{28, 30, SPECIES_SILICOBRA},//10
	{28, 30, SPECIES_WOOPER},//10
	{28, 30, SPECIES_SANDSHREW},//10
	{30, 32, SPECIES_DRILBUR},//5
	{30, 32, SPECIES_GLIGAR},//5
	{30, 32, SPECIES_DUGTRIO},//4
	{30, 32, SPECIES_DUGTRIO},//4
	{30, 32, SPECIES_HIPPOPOTAS},//1
	{30, 32, SPECIES_HIPPOPOTAS},//1
};
const struct WildPokemonInfo gDiglettsCaveB1F_LandMonsMorningInfo = {21, gDiglettsCaveB1F_LandMonsMorning};

const struct WildPokemon gDiglettsCaveB1F_LandMonsNight[] = 
{
	{28, 30, SPECIES_DIGLETT_A},//20
	{28, 30, SPECIES_DIGLETT_A},//20
	{28, 30, SPECIES_STUNFISK_G},//10
	{28, 30, SPECIES_PHANPY},//10
	{28, 30, SPECIES_SHELLOS},//10
	{28, 30, SPECIES_SANDILE},//10
	{30, 32, SPECIES_TRAPINCH},//5
	{30, 32, SPECIES_GLIGAR},//5
	{30, 32, SPECIES_DUGTRIO_A},//4
	{30, 32, SPECIES_DUGTRIO_A},//4
	{30, 32, SPECIES_HIPPOPOTAS},//1
	{30, 32, SPECIES_HIPPOPOTAS},//1
};
const struct WildPokemonInfo gDiglettsCaveB1F_LandMonsNightInfo = {21, gDiglettsCaveB1F_LandMonsNight};


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 9
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute9_LandMonsMorning[] = 
{
	{28, 30, SPECIES_SHELMET},//20
	{28, 30, SPECIES_EXEGGCUTE},//20
	{28, 30, SPECIES_DARUMAKA},//10
	{28, 30, SPECIES_DEWPIDER},//10
	{28, 30, SPECIES_INDEEDEE},//10
	{28, 30, SPECIES_RUFFLET},//10
	{30, 32, SPECIES_MIME_JR},//5
	{30, 32, SPECIES_MIME_JR},//5
	{30, 32, SPECIES_TROPIUS},//4
	{30, 32, SPECIES_TROPIUS},//4
	{30, 32, SPECIES_SKORUPI},//1
	{30, 32, SPECIES_SKORUPI},//1
};
const struct WildPokemonInfo gRoute9_LandMonsMorningInfo = {21, gRoute9_LandMonsMorning};

const struct WildPokemon gRoute9_LandMonsNight[] = 
{
	{32, 34, SPECIES_SHELMET},//20
	{32, 34, SPECIES_EXEGGCUTE_A},//20
	{32, 34, SPECIES_SALANDIT},//10
	{32, 34, SPECIES_DEWPIDER},//10
	{32, 34, SPECIES_INDEEDEE},//10
	{32, 34, SPECIES_RUFFLET},//10
	{34, 36, SPECIES_ESPURR},//5
	{34, 36, SPECIES_ESPURR},//5
	{34, 36, SPECIES_TROPIUS},//4
	{34, 36, SPECIES_TROPIUS},//4
	{34, 36, SPECIES_SKORUPI},//1
	{34, 36, SPECIES_SKORUPI},//1
};
const struct WildPokemonInfo gRoute9_LandMonsNightInfo = {21, gRoute9_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 10
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute10_LandMonsMorning[] = 
{
	{30, 32, SPECIES_VOLTORB},//20
	{30, 32, SPECIES_HELIOPTILE},//20
	{30, 32, SPECIES_HELIOPTILE},//10
	{30, 32, SPECIES_PLUSLE},//10
	{30, 32, SPECIES_PLUSLE},//10
	{30, 32, SPECIES_SKITTY},//10
	{32, 34, SPECIES_EMOLGA},//5
	{32, 34, SPECIES_EMOLGA},//5
	{32, 34, SPECIES_MAGNEMITE},//4
	{32, 34, SPECIES_MAGNEMITE},//4
	{32, 34, SPECIES_PINCURCHIN},//1
	{32, 34, SPECIES_CROAGUNK},//1
};
const struct WildPokemonInfo gRoute10_LandMonsMorningInfo = {21, gRoute10_LandMonsMorning};

const struct WildPokemon gRoute10_LandMonsNight[] = 
{
	{30, 32, SPECIES_VOLTORB},//20
	{30, 32, SPECIES_ELECTRIKE},//20
	{30, 32, SPECIES_ELECTRIKE},//10
	{30, 32, SPECIES_MINUN},//10
	{30, 32, SPECIES_MINUN},//10
	{30, 32, SPECIES_SKITTY},//10
	{32, 34, SPECIES_EMOLGA},//5
	{32, 34, SPECIES_EMOLGA},//5
	{32, 34, SPECIES_MAGNEMITE},//4
	{32, 34, SPECIES_MAGNEMITE},//4
	{32, 34, SPECIES_PINCURCHIN},//1
	{32, 34, SPECIES_CROAGUNK},//1
};
const struct WildPokemonInfo gRoute10_LandMonsNightInfo = {21, gRoute10_LandMonsNight};

const struct WildPokemon gRoute10_SurfMons[] = 
{
	{55, 60, SPECIES_TENTACOOL},//60
	{55, 60, SPECIES_TENTACOOL},//30
	{55, 60, SPECIES_TENTACOOL},//5
	{55, 60, SPECIES_WINGULL},//4
	{55, 60, SPECIES_WINGULL},//1
};
const struct WildPokemonInfo gRoute10_SurfMonsInfo = {21, gRoute10_SurfMons};

const struct WildPokemon gRoute10_FishingMons[] = 
{
	{ 3,  4, SPECIES_WOOPER},//old rod 70
	{ 4,  5, SPECIES_TYNAMO},//old rod 30
	{30, 32, SPECIES_BARBOACH},//good rod 60
	{30, 32, SPECIES_SHELLDER},//good rod 20
	{30, 32, SPECIES_CORSOLA_G},//good rod 20
	{55, 60, SPECIES_WHISCASH},//super rod 40
	{55, 60, SPECIES_WHISCASH},//super rod 40
	{55, 60, SPECIES_BASCULIN_BLUE},//super rod 15
	{55, 60, SPECIES_SEADRA},//super rod 4
	{55, 60, SPECIES_SEADRA},//super rod 1
};
const struct WildPokemonInfo gRoute10_FishingMonsInfo = {21, gRoute10_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Rock Tunnel 1F
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRockTunnel1F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_GRAVELER},//20
	{32, 34, SPECIES_ARON},//20
	{32, 34, SPECIES_SHUCKLE},//10
	{32, 34, SPECIES_SOLROCK},//10
	{32, 34, SPECIES_ZUBAT},//10
	{32, 34, SPECIES_ZUBAT},//10
	{34, 36, SPECIES_MINIOR_INDIGO},//5
	{34, 36, SPECIES_FERROSEED},//5
	{34, 36, SPECIES_STONJOURNER},//4
	{34, 36, SPECIES_HEATMOR},//4
	{34, 36, SPECIES_CARBINK},//1
	{34, 36, SPECIES_DURANT},//1
};
const struct WildPokemonInfo gRockTunnel1F_LandMonsMorningInfo = {21, gRockTunnel1F_LandMonsMorning};

const struct WildPokemon gRockTunnel1F_LandMonsNight[] = 
{
	{32, 34, SPECIES_GRAVELER_A},//20
	{32, 34, SPECIES_ARON},//20
	{32, 34, SPECIES_DWEBBLE},//10
	{32, 34, SPECIES_LUNATONE},//10
	{32, 34, SPECIES_ZUBAT},//10
	{32, 34, SPECIES_ZUBAT},//10
	{34, 36, SPECIES_MINIOR_INDIGO},//5 
	{34, 36, SPECIES_FERROSEED},//5
	{34, 36, SPECIES_STONJOURNER},//4
	{34, 36, SPECIES_HEATMOR},//4
	{34, 36, SPECIES_CARBINK},//1
	{34, 36, SPECIES_DURANT},//1
};
const struct WildPokemonInfo gRockTunnel1F_LandMonsNightInfo = {21, gRockTunnel1F_LandMonsNight};

const struct WildPokemon gRockTunnelB1F_LandMonsMorning[] = 
{
	{33, 35, SPECIES_SANDSLASH},//20
	{33, 35, SPECIES_BOLDORE},//20
	{33, 35, SPECIES_SWINUB},//10
	{33, 35, SPECIES_SNORUNT},//10
	{33, 35, SPECIES_BRONZOR},//10
	{33, 35, SPECIES_BONSLY},//10
	{35, 37, SPECIES_CARKOL},//5
	{35, 37, SPECIES_MORPEKO},//5
	{35, 37, SPECIES_CUBCHOO},//4
	{35, 37, SPECIES_CUBCHOO},//4
	{35, 37, SPECIES_KLINK},//1
	{35, 37, SPECIES_HONEDGE},//1
};
const struct WildPokemonInfo gRockTunnelB1F_LandMonsMorningInfo = {21, gRockTunnelB1F_LandMonsMorning};

const struct WildPokemon gRockTunnelB1F_LandMonsNight[] = 
{
	{33, 35, SPECIES_SANDSLASH_A},//20
	{33, 35, SPECIES_RHYDON},//20
	{33, 35, SPECIES_SWINUB},//10
	{33, 35, SPECIES_CUBONE},//10
	{33, 35, SPECIES_NOSEPASS},//10
	{33, 35, SPECIES_BONSLY},//10
	{35, 37, SPECIES_ONIX},//5 
	{35, 37, SPECIES_MORPEKO},//5
	{35, 37, SPECIES_SNEASEL},//4
	{35, 37, SPECIES_SNEASEL},//4
	{35, 37, SPECIES_KLINK},//1
	{35, 37, SPECIES_HONEDGE},//1
};
const struct WildPokemonInfo gRockTunnelB1F_LandMonsNightInfo = {21, gRockTunnelB1F_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 8
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute8_LandMonsMorning[] = 
{
	{32, 34, SPECIES_LOMBRE},//20
	{32, 34, SPECIES_MINCCINO},//20
	{32, 34, SPECIES_GROWLITHE},//10
	{32, 34, SPECIES_ABSOL},//10
	{32, 34, SPECIES_ABSOL},//10
	{32, 34, SPECIES_VENIPEDE},//10
	{34, 36, SPECIES_COMFEY},//5
	{34, 36, SPECIES_COMFEY},//5
	{34, 36, SPECIES_GIRAFARIG},//4
	{34, 36, SPECIES_GIRAFARIG},//4
	{34, 36, SPECIES_MILTANK},//1
	{34, 36, SPECIES_MILTANK},//1
};
const struct WildPokemonInfo gRoute8_LandMonsMorningInfo = {21, gRoute8_LandMonsMorning};

const struct WildPokemon gRoute8_LandMonsNight[] = 
{
	{32, 34, SPECIES_LOMBRE},//20
	{32, 34, SPECIES_MINCCINO},//20
	{32, 34, SPECIES_VULPIX},//10
	{32, 34, SPECIES_ABSOL},//10
	{32, 34, SPECIES_ABSOL},//10
	{32, 34, SPECIES_VENIPEDE},//10
	{34, 36, SPECIES_MORGREM},//5 
	{34, 36, SPECIES_MORGREM},//5
	{34, 36, SPECIES_STANTLER},//4
	{34, 36, SPECIES_STANTLER},//4
	{34, 36, SPECIES_DRAMPA},//1
	{34, 36, SPECIES_DRAMPA},//1
};
const struct WildPokemonInfo gRoute8_LandMonsNightInfo = {21, gRoute8_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 7
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute7_LandMonsMorning[] = 
{
	{32, 34, SPECIES_DEERLING},//20
	{32, 34, SPECIES_INKAY},//20
	{32, 34, SPECIES_RUFFLET},//10
	{32, 34, SPECIES_RUFFLET},//10
	{32, 34, SPECIES_CUTIEFLY},//10
	{32, 34, SPECIES_APPLIN},//10
	{34, 36, SPECIES_ORANGURU},//5
	{34, 36, SPECIES_ORANGURU},//5
	{34, 36, SPECIES_MIENFOO},//4
	{34, 36, SPECIES_MIENFOO},//4
	{34, 36, SPECIES_PORYGON},//1
	{34, 36, SPECIES_PORYGON},//1
};
const struct WildPokemonInfo gRoute7_LandMonsMorningInfo = {21, gRoute7_LandMonsMorning};

const struct WildPokemon gRoute7_LandMonsNight[] = 
{
	{32, 34, SPECIES_DEERLING_WINTER},//20
	{32, 34, SPECIES_INKAY},//20
	{32, 34, SPECIES_VULLABY},//10
	{32, 34, SPECIES_VULLABY},//10
	{32, 34, SPECIES_CUTIEFLY},//10
	{32, 34, SPECIES_APPLIN},//10
	{34, 36, SPECIES_PASSIMIAN},//5 
	{34, 36, SPECIES_PASSIMIAN},//5
	{34, 36, SPECIES_MIENFOO},//4
	{34, 36, SPECIES_MIENFOO},//4
	{34, 36, SPECIES_PORYGON},//1
	{34, 36, SPECIES_PORYGON},//1
};
const struct WildPokemonInfo gRoute7_LandMonsNightInfo = {21, gRoute7_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Pokemon Tower
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gPokemonTower_LandMonsMorning[] = 
{
	{32, 34, SPECIES_HAUNTER},//20
	{32, 34, SPECIES_COFAGRIGUS},//20
	{32, 34, SPECIES_DUSCLOPS},//10
	{32, 34, SPECIES_MISMAGIUS},//10
	{32, 34, SPECIES_MISMAGIUS},//10
	{32, 34, SPECIES_CUBONE_A},//10
	{34, 36, SPECIES_SPIRITOMB},//5
	{34, 36, SPECIES_SABLEYE},//5
	{34, 36, SPECIES_POLTEAGEIST},//4
	{34, 36, SPECIES_POLTEAGEIST},//4
	{34, 36, SPECIES_LAMPENT},//1
	{34, 36, SPECIES_MIMIKYU},//1
};
const struct WildPokemonInfo gPokemonTower_LandMonsMorningInfo = {21, gPokemonTower_LandMonsMorning};

const struct WildPokemon gPokemonTower_LandMonsNight[] = 
{
	{32, 34, SPECIES_HAUNTER},//20
	{32, 34, SPECIES_RUNERIGUS},//20
	{32, 34, SPECIES_DUSCLOPS},//10
	{32, 34, SPECIES_MISMAGIUS},//10
	{32, 34, SPECIES_MISMAGIUS},//10
	{32, 34, SPECIES_CUBONE_A},//10
	{34, 36, SPECIES_SPIRITOMB},//5 
	{34, 36, SPECIES_SABLEYE},//5
	{34, 36, SPECIES_POLTEAGEIST},//4
	{34, 36, SPECIES_POLTEAGEIST},//4
	{34, 36, SPECIES_LAMPENT},//1
	{34, 36, SPECIES_MIMIKYU},//1
};
const struct WildPokemonInfo gPokemonTower_LandMonsNightInfo = {21, gPokemonTower_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 16
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute16_LandMonsMorning[] = 
{
	{32, 34, SPECIES_HERACROSS},//20
	{32, 34, SPECIES_YANMA},//20
	{32, 34, SPECIES_RHYHORN},//10
	{32, 34, SPECIES_SKORUPI},//10
	{32, 34, SPECIES_SKORUPI},//10
	{32, 34, SPECIES_DURANT},//10
	{34, 36, SPECIES_TOGEDEMARU},//5
	{34, 36, SPECIES_TOGEDEMARU},//5
	{34, 36, SPECIES_SKARMORY},//4
	{34, 36, SPECIES_SKARMORY},//4
	{34, 36, SPECIES_ESCAVALIER},//1
	{34, 36, SPECIES_CUFANT},//1
};
const struct WildPokemonInfo gRoute16_LandMonsMorningInfo = {21, gRoute16_LandMonsMorning};

const struct WildPokemon gRoute16_LandMonsNight[] = 
{
	{32, 34, SPECIES_SCYTHER},//20
	{32, 34, SPECIES_FORRETRESS},//20
	{32, 34, SPECIES_RHYHORN},//10
	{32, 34, SPECIES_FALINKS},//10
	{32, 34, SPECIES_FALINKS},//10
	{32, 34, SPECIES_DURANT},//10
	{34, 36, SPECIES_TOGEDEMARU},//5 
	{34, 36, SPECIES_TOGEDEMARU},//5
	{34, 36, SPECIES_SKARMORY},//4
	{34, 36, SPECIES_SKARMORY},//4
	{34, 36, SPECIES_ESCAVALIER},//1
	{34, 36, SPECIES_CUFANT},//1
};
const struct WildPokemonInfo gRoute16_LandMonsNightInfo = {21, gRoute16_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 17
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute17_LandMonsMorning[] = 
{
	{32, 34, SPECIES_WEEZING},//20
	{32, 34, SPECIES_ZEBSTRIKA},//20
	{32, 34, SPECIES_MUK},//10
	{32, 34, SPECIES_HYPNO},//10
	{32, 34, SPECIES_HYPNO},//10
	{32, 34, SPECIES_TORKOAL},//10
	{34, 36, SPECIES_AUDINO},//5
	{34, 36, SPECIES_AUDINO},//5
	{34, 36, SPECIES_DRAMPA},//4
	{34, 36, SPECIES_DRAMPA},//4
	{34, 36, SPECIES_SKARMORY},//1
	{34, 36, SPECIES_SKARMORY},//1
};
const struct WildPokemonInfo gRoute17_LandMonsMorningInfo = {21, gRoute17_LandMonsMorning};

const struct WildPokemon gRoute17_LandMonsNight[] = 
{
	{32, 34, SPECIES_WEEZING_G},//20
	{32, 34, SPECIES_ZEBSTRIKA},//20
	{32, 34, SPECIES_MUK_A},//10
	{32, 34, SPECIES_GRUMPIG},//10
	{32, 34, SPECIES_GRUMPIG},//10
	{32, 34, SPECIES_TORKOAL},//10
	{34, 36, SPECIES_AUDINO},//5 
	{34, 36, SPECIES_AUDINO},//5
	{34, 36, SPECIES_TURTONATOR},//4
	{34, 36, SPECIES_TURTONATOR},//4
	{34, 36, SPECIES_SKARMORY},//1
	{34, 36, SPECIES_SKARMORY},//1
};
const struct WildPokemonInfo gRoute17_LandMonsNightInfo = {21, gRoute17_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 18
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute18_LandMonsMorning[] = 
{
	{32, 34, SPECIES_XATU},//20
	{32, 34, SPECIES_VIKAVOLT},//20
	{32, 34, SPECIES_POLIWRATH},//10
	{32, 34, SPECIES_ABOMASNOW},//10
	{32, 34, SPECIES_ALTARIA},//10
	{32, 34, SPECIES_PARASECT},//10
	{34, 36, SPECIES_TOXICROAK},//5
	{34, 36, SPECIES_TOXICROAK},//5
	{34, 36, SPECIES_URSARING},//4
	{34, 36, SPECIES_URSARING},//4
	{34, 36, SPECIES_HAWLUCHA},//1
	{34, 36, SPECIES_HAWLUCHA},//1
};
const struct WildPokemonInfo gRoute18_LandMonsMorningInfo = {21, gRoute18_LandMonsMorning};

const struct WildPokemon gRoute18_LandMonsNight[] = 
{
	{32, 34, SPECIES_XATU},//20
	{32, 34, SPECIES_VIKAVOLT},//20
	{32, 34, SPECIES_POLITOED},//10
	{32, 34, SPECIES_ABOMASNOW},//10
	{32, 34, SPECIES_ALTARIA},//10
	{32, 34, SPECIES_JYNX},//10
	{34, 36, SPECIES_HELIOLISK},//5 
	{34, 36, SPECIES_HELIOLISK},//5
	{34, 36, SPECIES_PANGORO},//4
	{34, 36, SPECIES_PANGORO},//4
	{34, 36, SPECIES_HONCHKROW},//1
	{34, 36, SPECIES_HONCHKROW},//1
};
const struct WildPokemonInfo gRoute18_LandMonsNightInfo = {21, gRoute18_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 12
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute12_LandMonsMorning[] = 
{
	{32, 34, SPECIES_SNEASEL},//20
	{32, 34, SPECIES_DEWGONG},//20
	{32, 34, SPECIES_WALREIN},//10
	{32, 34, SPECIES_GLALIE},//10
	{32, 34, SPECIES_THROH},//10
	{32, 34, SPECIES_BEARTIC},//10
	{34, 36, SPECIES_AVALUGG},//5
	{34, 36, SPECIES_AVALUGG},//5
	{34, 36, SPECIES_MR_MIME_G},//4
	{34, 36, SPECIES_MR_MIME_G},//4
	{34, 36, SPECIES_NINETALES_A},//1
	{34, 36, SPECIES_NINETALES_A},//1
};
const struct WildPokemonInfo gRoute12_LandMonsMorningInfo = {21, gRoute12_LandMonsMorning};

const struct WildPokemon gRoute12_LandMonsNight[] = 
{
	{32, 34, SPECIES_SNEASEL},//20
	{32, 34, SPECIES_DEWGONG},//20
	{32, 34, SPECIES_WALREIN},//10
	{32, 34, SPECIES_FROSLASS},//10
	{32, 34, SPECIES_SAWK},//10
	{32, 34, SPECIES_BEARTIC},//10
	{34, 36, SPECIES_AVALUGG},//5 
	{34, 36, SPECIES_AVALUGG},//5
	{34, 36, SPECIES_MR_MIME_G},//4
	{34, 36, SPECIES_MR_MIME_G},//4
	{34, 36, SPECIES_NINETALES_A},//1
	{34, 36, SPECIES_NINETALES_A},//1
};
const struct WildPokemonInfo gRoute12_LandMonsNightInfo = {21, gRoute12_LandMonsNight};

const struct WildPokemon gRoute12_SurfMons[] = 
{
	{55, 60, SPECIES_TENTACOOL},//60
	{55, 60, SPECIES_TENTACOOL},//30
	{55, 60, SPECIES_TENTACOOL},//5
	{55, 60, SPECIES_FINNEON},//4
	{55, 60, SPECIES_FINNEON},//1
};
const struct WildPokemonInfo gRoute12_SurfMonsInfo = {21, gRoute12_SurfMons};

const struct WildPokemon gRoute12_FishingMons[] = 
{
	{ 3,  4, SPECIES_SPHEAL},//old rod 70
	{ 4,  5, SPECIES_SEEL},//old rod 30
	{30, 32, SPECIES_SHELLDER},//good rod 60
	{30, 32, SPECIES_SEALEO},//good rod 20
	{30, 32, SPECIES_DREDNAW},//good rod 20
	{55, 60, SPECIES_SEALEO},//super rod 40
	{55, 60, SPECIES_SEALEO},//super rod 40
	{55, 60, SPECIES_DEWGONG},//super rod 15
	{55, 60, SPECIES_BRUXISH},//super rod 4
	{55, 60, SPECIES_DREDNAW},//super rod 1
};
const struct WildPokemonInfo gRoute12_FishingMonsInfo = {21, gRoute12_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 13
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute13_LandMonsMorning[] = 
{
	{32, 34, SPECIES_TANGROWTH},//20
	{32, 34, SPECIES_EXEGGUTOR},//20
	{32, 34, SPECIES_ROSERADE},//10
	{32, 34, SPECIES_LURANTIS},//10
	{32, 34, SPECIES_SIMISAGE},//10
	{32, 34, SPECIES_SIMISAGE},//10
	{34, 36, SPECIES_JUMPLUFF},//5
	{34, 36, SPECIES_JUMPLUFF},//5
	{34, 36, SPECIES_EXEGGUTOR_A},//4
	{34, 36, SPECIES_DURALUDON},//4
	{34, 36, SPECIES_FERROTHORN},//1
	{34, 36, SPECIES_FERROTHORN},//1
};
const struct WildPokemonInfo gRoute13_LandMonsMorningInfo = {21, gRoute13_LandMonsMorning};

const struct WildPokemon gRoute13_LandMonsNight[] = 
{
	{32, 34, SPECIES_TALONFLAME},//20
	{32, 34, SPECIES_PYROAR},//20
	{32, 34, SPECIES_ARCANINE},//10
	{32, 34, SPECIES_MAGMORTAR},//10
	{32, 34, SPECIES_SIMISEAR},//10
	{32, 34, SPECIES_SIMISEAR},//10
	{34, 36, SPECIES_ORICORIO},//5 
	{34, 36, SPECIES_ORICORIO},//5
	{34, 36, SPECIES_TURTONATOR},//4
	{34, 36, SPECIES_DURALUDON},//4
	{34, 36, SPECIES_CENTISKORCH},//1
	{34, 36, SPECIES_CENTISKORCH},//1
};
const struct WildPokemonInfo gRoute13_LandMonsNightInfo = {21, gRoute13_LandMonsNight};

const struct WildPokemon gRoute13_SurfMons[] = 
{
	{55, 60, SPECIES_TENTACRUEL},//60
	{55, 60, SPECIES_TENTACRUEL},//30
	{55, 60, SPECIES_BUIZEL},//5
	{55, 60, SPECIES_BUIZEL},//4
	{55, 60, SPECIES_BUIZEL},//1
};
const struct WildPokemonInfo gRoute13_SurfMonsInfo = {21, gRoute13_SurfMons};

const struct WildPokemon gRoute13_FishingMons[] = 
{
	{ 3,  4, SPECIES_SKRELP},//old rod 70
	{ 4,  5, SPECIES_TENTACOOL},//old rod 30
	{30, 32, SPECIES_MAREANIE},//good rod 60
	{30, 32, SPECIES_DEWPIDER},//good rod 20
	{30, 32, SPECIES_SKRELP},//good rod 20
	{55, 60, SPECIES_DRAGALGE},//super rod 40
	{55, 60, SPECIES_TENTACRUEL},//super rod 40
	{55, 60, SPECIES_TOXAPEX},//super rod 15
	{55, 60, SPECIES_MANTINE},//super rod 4
	{55, 60, SPECIES_MANTINE},//super rod 1
};
const struct WildPokemonInfo gRoute13_FishingMonsInfo = {21, gRoute13_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 14
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute14_LandMonsMorning[] = 
{
	{32, 34, SPECIES_PELIPPER},//20
	{32, 34, SPECIES_LEAVANNY},//20
	{32, 34, SPECIES_TORKOAL},//10
	{32, 34, SPECIES_TORKOAL},//10
	{32, 34, SPECIES_SCOLIPEDE},//10
	{32, 34, SPECIES_SCOLIPEDE},//10
	{34, 36, SPECIES_CHARJABUG},//5
	{34, 36, SPECIES_CHARJABUG},//5
	{34, 36, SPECIES_DURANT},//4
	{34, 36, SPECIES_DURANT},//4
	{34, 36, SPECIES_GOLISOPOD},//1
	{34, 36, SPECIES_GOLISOPOD},//1
};
const struct WildPokemonInfo gRoute14_LandMonsMorningInfo = {21, gRoute14_LandMonsMorning};

const struct WildPokemon gRoute14_LandMonsNight[] = 
{
	{32, 34, SPECIES_PELIPPER},//20
	{32, 34, SPECIES_LEAVANNY},//20
	{32, 34, SPECIES_TORKOAL},//10
	{32, 34, SPECIES_TORKOAL},//10
	{32, 34, SPECIES_PALOSSAND},//10
	{32, 34, SPECIES_PALOSSAND},//10
	{34, 36, SPECIES_CHARJABUG},//5 
	{34, 36, SPECIES_CHARJABUG},//5
	{34, 36, SPECIES_DURANT},//4
	{34, 36, SPECIES_DURANT},//4
	{34, 36, SPECIES_CENTISKORCH},//1
	{34, 36, SPECIES_GOLISOPOD},//1
};
const struct WildPokemonInfo gRoute14_LandMonsNightInfo = {21, gRoute14_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 15
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute15_LandMonsMorning[] = 
{
	{32, 34, SPECIES_AMOONGUSS},//20
	{32, 34, SPECIES_AMBIPOM},//20
	{32, 34, SPECIES_TSAREENA},//10
	{32, 34, SPECIES_GALVANTULA},//10
	{32, 34, SPECIES_SIMIPOUR},//10
	{32, 34, SPECIES_ORICORIO},//10
	{34, 36, SPECIES_SIGILYPH},//5
	{34, 36, SPECIES_SIGILYPH},//5
	{34, 36, SPECIES_FERROTHORN},//4
	{34, 36, SPECIES_FERROTHORN},//4
	{34, 36, SPECIES_DITTO},//1
	{34, 36, SPECIES_DITTO},//1
};
const struct WildPokemonInfo gRoute15_LandMonsMorningInfo = {21, gRoute15_LandMonsMorning};

const struct WildPokemon gRoute15_LandMonsNight[] = 
{
	{32, 34, SPECIES_AMOONGUSS},//20
	{32, 34, SPECIES_AMBIPOM},//20
	{32, 34, SPECIES_TSAREENA},//10
	{32, 34, SPECIES_GALVANTULA},//10
	{32, 34, SPECIES_SIMIPOUR},//10
	{32, 34, SPECIES_ORICORIO},//10
	{34, 36, SPECIES_SIGILYPH},//5 
	{34, 36, SPECIES_SIGILYPH},//5
	{34, 36, SPECIES_FERROTHORN},//4
	{34, 36, SPECIES_FERROTHORN},//4
	{34, 36, SPECIES_DITTO},//1
	{34, 36, SPECIES_DITTO},//1
};
const struct WildPokemonInfo gRoute15_LandMonsNightInfo = {21, gRoute15_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 19
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute19_SurfMons[] = 
{
	{55, 60, SPECIES_LUMINEON},//60
	{55, 60, SPECIES_JELLICENT},//30
	{55, 60, SPECIES_BASCULIN_BLUE},//5
	{55, 60, SPECIES_CLAWITZER},//4
	{55, 60, SPECIES_CLAWITZER},//1
};
const struct WildPokemonInfo gRoute19_SurfMonsInfo = {21, gRoute19_SurfMons};

const struct WildPokemon gRoute19_FishingMons[] = 
{
	{ 3,  4, SPECIES_CLAMPERL},//old rod 70
	{ 4,  5, SPECIES_HORSEA},//old rod 30
	{30, 32, SPECIES_SHELLDER},//good rod 60
	{30, 32, SPECIES_SLOWPOKE},//good rod 20
	{30, 32, SPECIES_SLOWPOKE},//good rod 20
	{55, 60, SPECIES_SEADRA},//super rod 40
	{55, 60, SPECIES_HUNTAIL},//super rod 40
	{55, 60, SPECIES_GOREBYSS},//super rod 15
	{55, 60, SPECIES_MANTINE},//super rod 4
	{55, 60, SPECIES_MANTINE},//super rod 1
};
const struct WildPokemonInfo gRoute19_FishingMonsInfo = {21, gRoute19_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 20
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute20_SurfMons[] = 
{
	{55, 60, SPECIES_TENTACRUEL},//60
	{55, 60, SPECIES_SHARPEDO},//30
	{55, 60, SPECIES_WAILORD},//5
	{55, 60, SPECIES_LANTURN},//4
	{55, 60, SPECIES_LANTURN},//1
};
const struct WildPokemonInfo gRoute20_SurfMonsInfo = {21, gRoute20_SurfMons};

const struct WildPokemon gRoute20_FishingMons[] = 
{
	{ 3,  4, SPECIES_MAGIKARP},//old rod 70
	{ 4,  5, SPECIES_CHINCHOU},//old rod 30
	{30, 32, SPECIES_WAILMER},//good rod 60
	{30, 32, SPECIES_CLAUNCHER},//good rod 20
	{30, 32, SPECIES_CORSOLA_G},//good rod 20
	{55, 60, SPECIES_SEADRA},//super rod 40
	{55, 60, SPECIES_BASCULIN_BLUE},//super rod 40
	{55, 60, SPECIES_CLAWITZER},//super rod 15
	{55, 60, SPECIES_BRUXISH},//super rod 4
	{55, 60, SPECIES_BRUXISH},//super rod 1
};
const struct WildPokemonInfo gRoute20_FishingMonsInfo = {21, gRoute20_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 21
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute21_LandMonsMorning[] = 
{
	{32, 34, SPECIES_KINGLER},//20
	{32, 34, SPECIES_KINGLER},//20
	{32, 34, SPECIES_VICTREEBEL},//10
	{32, 34, SPECIES_VICTREEBEL},//10
	{32, 34, SPECIES_NIDOQUEEN},//10
	{32, 34, SPECIES_NIDOQUEEN},//10
	{34, 36, SPECIES_KRICKETUNE},//5
	{34, 36, SPECIES_KRICKETUNE},//5
	{34, 36, SPECIES_ARIADOS},//4
	{34, 36, SPECIES_ARIADOS},//4
	{34, 36, SPECIES_SCYTHER},//1
	{34, 36, SPECIES_SCYTHER},//1
};
const struct WildPokemonInfo gRoute21_LandMonsMorningInfo = {21, gRoute21_LandMonsMorning};

const struct WildPokemon gRoute21_LandMonsNight[] = 
{
	{32, 34, SPECIES_KINGLER},//20
	{32, 34, SPECIES_KINGLER},//20
	{32, 34, SPECIES_VICTREEBEL},//10
	{32, 34, SPECIES_VICTREEBEL},//10
	{32, 34, SPECIES_NIDOKING},//10
	{32, 34, SPECIES_NIDOKING},//10
	{34, 36, SPECIES_KRICKETUNE},//5
	{34, 36, SPECIES_KRICKETUNE},//5
	{34, 36, SPECIES_ARIADOS},//4
	{34, 36, SPECIES_ARIADOS},//4
	{34, 36, SPECIES_SCYTHER},//1
	{34, 36, SPECIES_SCYTHER},//1
};
const struct WildPokemonInfo gRoute21_LandMonsNightInfo = {21, gRoute21_LandMonsNight};

const struct WildPokemon gRoute21A_SurfMons[] = 
{
	{55, 60, SPECIES_TENTACRUEL},//60
	{55, 60, SPECIES_BARRASKEWDA},//30
	{55, 60, SPECIES_LUMINEON},//5
	{55, 60, SPECIES_CRAMORANT},//4
	{55, 60, SPECIES_CRAMORANT},//1
};
const struct WildPokemonInfo gRoute21A_SurfMonsInfo = {21, gRoute21A_SurfMons};

const struct WildPokemon gRoute21B_SurfMons[] = 
{
	{55, 60, SPECIES_TENTACRUEL},//60
	{55, 60, SPECIES_MANTINE},//30
	{55, 60, SPECIES_MANTINE},//5
	{55, 60, SPECIES_JELLICENT},//4
	{55, 60, SPECIES_JELLICENT},//1
};
const struct WildPokemonInfo gRoute21B_SurfMonsInfo = {21, gRoute21B_SurfMons};

const struct WildPokemon gRoute21A_FishingMons[] = 
{
	{ 3,  4, SPECIES_MAGIKARP},//old rod 70
	{ 4,  5, SPECIES_SHELLDER},//old rod 30
	{30, 32, SPECIES_KRABBY},//good rod 60
	{30, 32, SPECIES_QWILFISH},//good rod 20
	{30, 32, SPECIES_CORSOLA_G},//good rod 20
	{55, 60, SPECIES_OCTILLERY},//super rod 40
	{55, 60, SPECIES_LUMINEON},//super rod 40
	{55, 60, SPECIES_KINGLER},//super rod 15
	{55, 60, SPECIES_RELICANTH},//super rod 4
	{55, 60, SPECIES_RELICANTH},//super rod 1
};
const struct WildPokemonInfo gRoute21A_FishingMonsInfo = {21, gRoute21A_FishingMons};

const struct WildPokemon gRoute21B_FishingMons[] = 
{
	{ 3,  4, SPECIES_MAGIKARP},//old rod 70
	{ 4,  5, SPECIES_SHELLDER},//old rod 30
	{30, 32, SPECIES_KRABBY},//good rod 60
	{30, 32, SPECIES_QWILFISH},//good rod 20
	{30, 32, SPECIES_CORSOLA},//good rod 20
	{55, 60, SPECIES_OCTILLERY},//super rod 40
	{55, 60, SPECIES_LUMINEON},//super rod 40
	{55, 60, SPECIES_SHARPEDO},//super rod 15
	{55, 60, SPECIES_RELICANTH},//super rod 4
	{55, 60, SPECIES_RELICANTH},//super rod 1
};
const struct WildPokemonInfo gRoute21B_FishingMonsInfo = {21, gRoute21B_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Seafoam Island
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gSeafoam1F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_PILOSWINE},//20
	{32, 34, SPECIES_GLALIE},//20
	{32, 34, SPECIES_BEARTIC},//10
	{32, 34, SPECIES_BEARTIC},//10
	{32, 34, SPECIES_SLOWBRO},//10
	{32, 34, SPECIES_SLOWBRO},//10
	{34, 36, SPECIES_GOLBAT},//5
	{34, 36, SPECIES_GOLBAT},//5
	{34, 36, SPECIES_AVALUGG},//4
	{34, 36, SPECIES_AVALUGG},//4
	{34, 36, SPECIES_JYNX},//1
	{34, 36, SPECIES_JYNX},//1
};
const struct WildPokemonInfo gSeafoam1F_LandMonsMorningInfo = {21, gSeafoam1F_LandMonsMorning};

const struct WildPokemon gSeafoam1F_LandMonsNight[] = 
{
	{32, 34, SPECIES_SANDSLASH_A},//20
	{32, 34, SPECIES_GLALIE},//20
	{32, 34, SPECIES_BEARTIC},//10
	{32, 34, SPECIES_BEARTIC},//10
	{32, 34, SPECIES_WALREIN},//10
	{32, 34, SPECIES_WALREIN},//10
	{34, 36, SPECIES_CROBAT},//5
	{34, 36, SPECIES_CROBAT},//5
	{34, 36, SPECIES_AVALUGG},//4
	{34, 36, SPECIES_AVALUGG},//4
	{34, 36, SPECIES_JYNX},//1
	{34, 36, SPECIES_JYNX},//1
};
const struct WildPokemonInfo gSeafoam1F_LandMonsNightInfo = {21, gSeafoam1F_LandMonsNight};

const struct WildPokemon gSeafoamB1F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_PILOSWINE},//20
	{32, 34, SPECIES_DARMANITAN_G},//20
	{32, 34, SPECIES_VANILLUXE},//10
	{32, 34, SPECIES_VANILLUXE},//10
	{32, 34, SPECIES_SLOWKING},//10
	{32, 34, SPECIES_SLOWKING},//10
	{34, 36, SPECIES_GOLBAT},//5
	{34, 36, SPECIES_GOLBAT},//5
	{34, 36, SPECIES_CRYOGONAL},//4
	{34, 36, SPECIES_CRYOGONAL},//4
	{34, 36, SPECIES_DELIBIRD},//1
	{34, 36, SPECIES_DELIBIRD},//1
};
const struct WildPokemonInfo gSeafoamB1F_LandMonsMorningInfo = {21, gSeafoamB1F_LandMonsMorning};

const struct WildPokemon gSeafoamB1F_LandMonsNight[] = 
{
	{32, 34, SPECIES_PILOSWINE},//20
	{32, 34, SPECIES_DARMANITAN_G},//20
	{32, 34, SPECIES_VANILLUXE},//10
	{32, 34, SPECIES_VANILLUXE},//10
	{32, 34, SPECIES_GOLDUCK},//10
	{32, 34, SPECIES_GOLDUCK},//10
	{34, 36, SPECIES_CROBAT},//5
	{34, 36, SPECIES_CROBAT},//5
	{34, 36, SPECIES_CRYOGONAL},//4
	{34, 36, SPECIES_CRYOGONAL},//4
	{34, 36, SPECIES_DELIBIRD},//1
	{34, 36, SPECIES_DELIBIRD},//1
};
const struct WildPokemonInfo gSeafoamB1F_LandMonsNightInfo = {21, gSeafoamB1F_LandMonsNight};

const struct WildPokemon gSeafoamB2F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_ABOMASNOW},//20
	{32, 34, SPECIES_SNOVER},//20
	{32, 34, SPECIES_NINETALES_A},//10
	{32, 34, SPECIES_NINETALES_A},//10
	{32, 34, SPECIES_CRAWDAUNT},//10
	{32, 34, SPECIES_CRAWDAUNT},//10
	{34, 36, SPECIES_GOLBAT},//5
	{34, 36, SPECIES_GOLBAT},//5
	{34, 36, SPECIES_SNEASEL},//4
	{34, 36, SPECIES_SNEASEL},//4
	{34, 36, SPECIES_JYNX},//1
	{34, 36, SPECIES_JYNX},//1
};
const struct WildPokemonInfo gSeafoamB2F_LandMonsMorningInfo = {21, gSeafoamB2F_LandMonsMorning};

const struct WildPokemon gSeafoamB2F_LandMonsNight[] = 
{
	{32, 34, SPECIES_ABOMASNOW},//20
	{32, 34, SPECIES_SNOVER},//20
	{32, 34, SPECIES_NINETALES_A},//10
	{32, 34, SPECIES_NINETALES_A},//10
	{32, 34, SPECIES_KINGLER},//10
	{32, 34, SPECIES_KINGLER},//10
	{34, 36, SPECIES_CROBAT},//5
	{34, 36, SPECIES_CROBAT},//5
	{34, 36, SPECIES_WEAVILE},//4
	{34, 36, SPECIES_WEAVILE},//4
	{34, 36, SPECIES_JYNX},//1
	{34, 36, SPECIES_JYNX},//1
};
const struct WildPokemonInfo gSeafoamB2F_LandMonsNightInfo = {21, gSeafoamB2F_LandMonsNight};

const struct WildPokemon gSeafoamB2F_SurfMons[] = 
{
	{55, 60, SPECIES_DEWGONG},//60
	{55, 60, SPECIES_WALREIN},//30
	{55, 60, SPECIES_CRAWDAUNT},//5
	{55, 60, SPECIES_CRAWDAUNT},//4
	{55, 60, SPECIES_CRAWDAUNT},//1
};
const struct WildPokemonInfo gSeafoamB2F_SurfMonsInfo = {21, gSeafoamB2F_SurfMons};

const struct WildPokemon gSeafoamB2F_FishingMons[] = 
{
	{ 3,  4, SPECIES_MAGIKARP},//old rod 70
	{ 4,  5, SPECIES_GOLDEEN},//old rod 30
	{30, 32, SPECIES_SPHEAL},//good rod 60
	{30, 32, SPECIES_MAREANIE},//good rod 20
	{30, 32, SPECIES_KRABBY},//good rod 20
	{55, 60, SPECIES_SEADRA},//super rod 40
	{55, 60, SPECIES_SEADRA},//super rod 40
	{55, 60, SPECIES_GYARADOS},//super rod 15
	{55, 60, SPECIES_CRAWDAUNT},//super rod 4
	{55, 60, SPECIES_CRAWDAUNT},//super rod 1
};
const struct WildPokemonInfo gSeafoamB2F_FishingMonsInfo = {21, gSeafoamB2F_FishingMons};

const struct WildPokemon gSeafoamB3F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_PILOSWINE},//20
	{32, 34, SPECIES_DARMANITAN_G},//20
	{32, 34, SPECIES_NINETALES_A},//10
	{32, 34, SPECIES_NINETALES_A},//10
	{32, 34, SPECIES_DEWGONG},//10
	{32, 34, SPECIES_DEWGONG},//10
	{34, 36, SPECIES_GOLBAT},//5
	{34, 36, SPECIES_GOLBAT},//5
	{34, 36, SPECIES_JYNX},//4
	{34, 36, SPECIES_JYNX},//4
	{34, 36, SPECIES_FROSMOTH},//1
	{34, 36, SPECIES_FROSMOTH},//1
};
const struct WildPokemonInfo gSeafoamB3F_LandMonsMorningInfo = {21, gSeafoamB3F_LandMonsMorning};

const struct WildPokemon gSeafoamB3F_LandMonsNight[] = 
{
	{32, 34, SPECIES_SANDSLASH_A},//20
	{32, 34, SPECIES_DARMANITAN_G},//20
	{32, 34, SPECIES_NINETALES_A},//10
	{32, 34, SPECIES_NINETALES_A},//10
	{32, 34, SPECIES_GOLDUCK},//10
	{32, 34, SPECIES_GOLDUCK},//10
	{34, 36, SPECIES_CROBAT},//5
	{34, 36, SPECIES_CROBAT},//5
	{34, 36, SPECIES_JYNX},//4
	{34, 36, SPECIES_JYNX},//4
	{34, 36, SPECIES_FROSMOTH},//1
	{34, 36, SPECIES_FROSMOTH},//1
};
const struct WildPokemonInfo gSeafoamB3F_LandMonsNightInfo = {21, gSeafoamB3F_LandMonsNight};

const struct WildPokemon gSeafoamB3F_SurfMons[] = 
{
	{55, 60, SPECIES_GOLDUCK},//60
	{55, 60, SPECIES_SLOWBRO},//30
	{55, 60, SPECIES_SHARPEDO},//5
	{55, 60, SPECIES_SHARPEDO},//4
	{55, 60, SPECIES_SHARPEDO},//1
};
const struct WildPokemonInfo gSeafoamB3F_SurfMonsInfo = {21, gSeafoamB3F_SurfMons};

const struct WildPokemon gSeafoamB3F_FishingMons[] = 
{
	{ 3,  4, SPECIES_MAGIKARP},//old rod 70
	{ 4,  5, SPECIES_REMORAID},//old rod 30
	{30, 32, SPECIES_SPHEAL},//good rod 60
	{30, 32, SPECIES_SHELLDER},//good rod 20
	{30, 32, SPECIES_CARVANHA},//good rod 20
	{55, 60, SPECIES_SEADRA},//super rod 40
	{55, 60, SPECIES_SEADRA},//super rod 40
	{55, 60, SPECIES_GYARADOS},//super rod 15
	{55, 60, SPECIES_GRAPPLOCT},//super rod 4
	{55, 60, SPECIES_GRAPPLOCT},//super rod 1
};
const struct WildPokemonInfo gSeafoamB3F_FishingMonsInfo = {21, gSeafoamB3F_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Cinnabar Island
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gCinnabarIsland_SurfMons[] = 
{
	{55, 60, SPECIES_TENTACRUEL},//60
	{55, 60, SPECIES_MANTINE},//30
	{55, 60, SPECIES_MANTINE},//5
	{55, 60, SPECIES_CRAMORANT},//4
	{55, 60, SPECIES_CRAMORANT},//1
};
const struct WildPokemonInfo gCinnabarIsland_SurfMonsInfo = {21, gCinnabarIsland_SurfMons};

const struct WildPokemon gCinnabarIsland_FishingMons[] = 
{
	{ 3,  4, SPECIES_MAGIKARP},//old rod 70
	{ 4,  5, SPECIES_CORSOLA},//old rod 30
	{30, 32, SPECIES_KRABBY},//good rod 60
	{30, 32, SPECIES_QWILFISH},//good rod 20
	{30, 32, SPECIES_FEEBAS},//good rod 20
	{55, 60, SPECIES_OCTILLERY},//super rod 40
	{55, 60, SPECIES_LUMINEON},//super rod 40
	{55, 60, SPECIES_SHARPEDO},//super rod 15
	{55, 60, SPECIES_DHELMISE},//super rod 4
	{55, 60, SPECIES_DHELMISE},//super rod 1
};
const struct WildPokemonInfo gCinnabarIsland_FishingMonsInfo = {21, gCinnabarIsland_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Pokemon Mansion
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gPKMNMansion1F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_RATICATE},//20
	{32, 34, SPECIES_ARBOK},//20
	{32, 34, SPECIES_MUK},//10
	{32, 34, SPECIES_MUK},//10
	{32, 34, SPECIES_WEEZING},//10
	{32, 34, SPECIES_LIEPARD},//10
	{34, 36, SPECIES_CHIMECHO},//5
	{34, 36, SPECIES_CHIMECHO},//5
	{34, 36, SPECIES_SABLEYE},//4
	{34, 36, SPECIES_SABLEYE},//4
	{34, 36, SPECIES_NINETALES},//1
	{34, 36, SPECIES_NINETALES},//1
};
const struct WildPokemonInfo gPKMNMansion1F_LandMonsMorningInfo = {21, gPKMNMansion1F_LandMonsMorning};

const struct WildPokemon gPKMNMansion1F_LandMonsNight[] = 
{
	{32, 34, SPECIES_RATICATE_A},//20
	{32, 34, SPECIES_ARBOK},//20
	{32, 34, SPECIES_MUK_A},//10
	{32, 34, SPECIES_MUK_A},//10
	{32, 34, SPECIES_WEEZING_G},//10
	{32, 34, SPECIES_LIEPARD},//10
	{34, 36, SPECIES_CHIMECHO},//5
	{34, 36, SPECIES_CHIMECHO},//5
	{34, 36, SPECIES_SABLEYE},//4
	{34, 36, SPECIES_SABLEYE},//4
	{34, 36, SPECIES_ARCANINE},//1
	{34, 36, SPECIES_ARCANINE},//1
};
const struct WildPokemonInfo gPKMNMansion1F_LandMonsNightInfo = {21, gPKMNMansion1F_LandMonsNight};

const struct WildPokemon gPKMNMansion2F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_GUMSHOOS},//20
	{32, 34, SPECIES_GARBODOR},//20
	{32, 34, SPECIES_WEEZING},//10
	{32, 34, SPECIES_SWALOT},//10
	{32, 34, SPECIES_HEATMOR},//10
	{32, 34, SPECIES_MIGHTYENA},//10
	{34, 36, SPECIES_CHIMECHO},//5
	{34, 36, SPECIES_CHIMECHO},//5
	{34, 36, SPECIES_BANETTE},//4
	{34, 36, SPECIES_BANETTE},//4
	{34, 36, SPECIES_HOUNDOOM},//1
	{34, 36, SPECIES_HOUNDOOM},//1
};
const struct WildPokemonInfo gPKMNMansion2F_LandMonsMorningInfo = {21, gPKMNMansion2F_LandMonsMorning};

const struct WildPokemon gPKMNMansion2F_LandMonsNight[] = 
{
	{32, 34, SPECIES_OBSTAGOON},//20
	{32, 34, SPECIES_GARBODOR},//20
	{32, 34, SPECIES_WEEZING},//10
	{32, 34, SPECIES_SWALOT},//10
	{32, 34, SPECIES_HEATMOR},//10
	{32, 34, SPECIES_MIGHTYENA},//10
	{34, 36, SPECIES_CHIMECHO},//5
	{34, 36, SPECIES_CHIMECHO},//5
	{34, 36, SPECIES_BANETTE},//4
	{34, 36, SPECIES_BANETTE},//4
	{34, 36, SPECIES_SALAZZLE},//1
	{34, 36, SPECIES_SALAZZLE},//1
};
const struct WildPokemonInfo gPKMNMansion2F_LandMonsNightInfo = {21, gPKMNMansion2F_LandMonsNight};

const struct WildPokemon gPKMNMansion3F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_BEWEAR},//20
	{32, 34, SPECIES_SEVIPER},//20
	{32, 34, SPECIES_ARIADOS},//10
	{32, 34, SPECIES_ARIADOS},//10
	{32, 34, SPECIES_RAPIDASH},//10
	{32, 34, SPECIES_SKUNTANK},//10
	{34, 36, SPECIES_CHIMECHO},//5
	{34, 36, SPECIES_CHIMECHO},//5
	{34, 36, SPECIES_CHANDELURE},//4
	{34, 36, SPECIES_CHANDELURE},//4
	{34, 36, SPECIES_KROOKODILE},//1
	{34, 36, SPECIES_KROOKODILE},//1
};
const struct WildPokemonInfo gPKMNMansion3F_LandMonsMorningInfo = {21, gPKMNMansion3F_LandMonsMorning};

const struct WildPokemon gPKMNMansion3F_LandMonsNight[] = 
{
	{32, 34, SPECIES_KOMALA},//20
	{32, 34, SPECIES_SEVIPER},//20
	{32, 34, SPECIES_ARIADOS},//10
	{32, 34, SPECIES_ARIADOS},//10
	{32, 34, SPECIES_RAPIDASH_G},//10
	{32, 34, SPECIES_SKUNTANK},//10
	{34, 36, SPECIES_CHIMECHO},//5
	{34, 36, SPECIES_CHIMECHO},//5
	{34, 36, SPECIES_CHANDELURE},//4
	{34, 36, SPECIES_CHANDELURE},//4
	{34, 36, SPECIES_KROOKODILE},//1
	{34, 36, SPECIES_KROOKODILE},//1
};
const struct WildPokemonInfo gPKMNMansion3F_LandMonsNightInfo = {21, gPKMNMansion3F_LandMonsNight};

const struct WildPokemon gPKMNMansionB1F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_RATICATE},//20
	{32, 34, SPECIES_GARBODOR},//20
	{32, 34, SPECIES_ARIADOS},//10
	{32, 34, SPECIES_ARIADOS},//10
	{32, 34, SPECIES_MAGMAR},//10
	{32, 34, SPECIES_MIGHTYENA},//10
	{34, 36, SPECIES_CHIMECHO},//5
	{34, 36, SPECIES_CHIMECHO},//5
	{34, 36, SPECIES_BANETTE},//4
	{34, 36, SPECIES_BANETTE},//4
	{34, 36, SPECIES_NINETALES},//1
	{34, 36, SPECIES_NINETALES},//1
};
const struct WildPokemonInfo gPKMNMansionB1F_LandMonsMorningInfo = {21, gPKMNMansionB1F_LandMonsMorning};

const struct WildPokemon gPKMNMansionB1F_LandMonsNight[] = 
{
	{32, 34, SPECIES_RATICATE_A},//20
	{32, 34, SPECIES_GARBODOR},//20
	{32, 34, SPECIES_ARIADOS},//10
	{32, 34, SPECIES_ARIADOS},//10
	{32, 34, SPECIES_MAGMAR},//10
	{32, 34, SPECIES_MIGHTYENA},//10
	{34, 36, SPECIES_CHIMECHO},//5
	{34, 36, SPECIES_CHIMECHO},//5
	{34, 36, SPECIES_BANETTE},//4
	{34, 36, SPECIES_BANETTE},//4
	{34, 36, SPECIES_ARCANINE},//1
	{34, 36, SPECIES_ARCANINE},//1
};
const struct WildPokemonInfo gPKMNMansionB1F_LandMonsNightInfo = {21, gPKMNMansionB1F_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Power Plant
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gPowerPlant_LandMonsMorning[] = 
{
	{32, 34, SPECIES_MAGNETON},//20
	{32, 34, SPECIES_ELECTRODE},//20
	{32, 34, SPECIES_ZEBSTRIKA},//10
	{32, 34, SPECIES_EELEKTROSS},//10
	{32, 34, SPECIES_AMPHAROS},//10
	{32, 34, SPECIES_AMPHAROS},//10
	{34, 36, SPECIES_DEDENNE},//5
	{34, 36, SPECIES_DEDENNE},//5
	{34, 36, SPECIES_LUXRAY},//4
	{34, 36, SPECIES_LUXRAY},//4
	{34, 36, SPECIES_ELECTABUZZ},//1
	{34, 36, SPECIES_ELECTABUZZ},//1
};
const struct WildPokemonInfo gPowerPlant_LandMonsMorningInfo = {21, gPowerPlant_LandMonsMorning};

const struct WildPokemon gPowerPlant_LandMonsNight[] = 
{
	{32, 34, SPECIES_MAGNETON},//20
	{32, 34, SPECIES_ELECTRODE},//20
	{32, 34, SPECIES_MANECTRIC},//10
	{32, 34, SPECIES_VIKAVOLT},//10
	{32, 34, SPECIES_AMPHAROS},//10
	{32, 34, SPECIES_AMPHAROS},//10
	{34, 36, SPECIES_TOGEDEMARU},//5
	{34, 36, SPECIES_TOGEDEMARU},//5
	{34, 36, SPECIES_LUXRAY},//4
	{34, 36, SPECIES_LUXRAY},//4
	{34, 36, SPECIES_ELECTABUZZ},//1
	{34, 36, SPECIES_ELECTABUZZ},//1
};
const struct WildPokemonInfo gPowerPlant_LandMonsNightInfo = {21, gPowerPlant_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Cerulean Cave
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gCeruleanCave1F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_PARASECT},//20
	{32, 34, SPECIES_CROBAT},//20
	{32, 34, SPECIES_MACHAMP},//10
	{32, 34, SPECIES_MACHAMP},//10
	{32, 34, SPECIES_MAGNEZONE},//10
	{32, 34, SPECIES_MAGNEZONE},//10
	{34, 36, SPECIES_SEISMITOAD},//5
	{34, 36, SPECIES_SEISMITOAD},//5
	{34, 36, SPECIES_DURALUDON},//4
	{34, 36, SPECIES_DURALUDON},//4
	{34, 36, SPECIES_TYPE_NULL},//1
	{34, 36, SPECIES_TYPE_NULL},//1
};
const struct WildPokemonInfo gCeruleanCave1F_LandMonsMorningInfo = {21, gCeruleanCave1F_LandMonsMorning};

const struct WildPokemon gCeruleanCave1F_LandMonsNight[] = 
{
	{32, 34, SPECIES_PARASECT},//20
	{32, 34, SPECIES_CROBAT},//20
	{32, 34, SPECIES_CONKELDURR},//10
	{32, 34, SPECIES_CONKELDURR},//10
	{32, 34, SPECIES_MAGNEZONE},//10
	{32, 34, SPECIES_MAGNEZONE},//10
	{34, 36, SPECIES_SEISMITOAD},//5
	{34, 36, SPECIES_SEISMITOAD},//5
	{34, 36, SPECIES_DURALUDON},//4
	{34, 36, SPECIES_DURALUDON},//4
	{34, 36, SPECIES_TYPE_NULL},//1
	{34, 36, SPECIES_TYPE_NULL},//1
};
const struct WildPokemonInfo gCeruleanCave1F_LandMonsNightInfo = {21, gCeruleanCave1F_LandMonsNight};

const struct WildPokemon gCeruleanCave1F_SurfMons[] = 
{
	{55, 60, SPECIES_SEISMITOAD},//60
	{55, 60, SPECIES_GOLDUCK},//30
	{55, 60, SPECIES_CRAWDAUNT},//5
	{55, 60, SPECIES_KINGLER},//4
	{55, 60, SPECIES_KINGLER},//1
};
const struct WildPokemonInfo gCeruleanCave1F_SurfMonsInfo = {21, gCeruleanCave1F_SurfMons};

const struct WildPokemon gCeruleanCave1F_FishingMons[] = 
{
	{ 3,  4, SPECIES_MAGIKARP},//old rod 70
	{ 4,  5, SPECIES_STARYU},//old rod 30
	{30, 32, SPECIES_CARVANHA},//good rod 60
	{30, 32, SPECIES_PYUKUMUKU},//good rod 20
	{30, 32, SPECIES_KRABBY},//good rod 20
	{55, 60, SPECIES_SEISMITOAD},//super rod 40
	{55, 60, SPECIES_POLIWHIRL},//super rod 40
	{55, 60, SPECIES_CRAWDAUNT},//super rod 15
	{55, 60, SPECIES_CRAWDAUNT},//super rod 4
	{55, 60, SPECIES_CRAWDAUNT},//super rod 1
};
const struct WildPokemonInfo gCeruleanCave1F_FishingMonsInfo = {21, gCeruleanCave1F_FishingMons};

const struct WildPokemon gCeruleanCave2F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_AMOONGUSS},//20
	{32, 34, SPECIES_SWOOBAT},//20
	{32, 34, SPECIES_PRIMEAPE},//10
	{32, 34, SPECIES_PRIMEAPE},//10
	{32, 34, SPECIES_KLINKLANG},//10
	{32, 34, SPECIES_KLINKLANG},//10
	{34, 36, SPECIES_ALAKAZAM},//5
	{34, 36, SPECIES_ALAKAZAM},//5
	{34, 36, SPECIES_DURALUDON},//4
	{34, 36, SPECIES_DURALUDON},//4
	{34, 36, SPECIES_TYPE_NULL},//1
	{34, 36, SPECIES_TYPE_NULL},//1
};
const struct WildPokemonInfo gCeruleanCave2F_LandMonsMorningInfo = {21, gCeruleanCave2F_LandMonsMorning};

const struct WildPokemon gCeruleanCave2F_LandMonsNight[] = 
{
	{32, 34, SPECIES_AMOONGUSS},//20
	{32, 34, SPECIES_SWOOBAT},//20
	{32, 34, SPECIES_PANGORO},//10
	{32, 34, SPECIES_PANGORO},//10
	{32, 34, SPECIES_KLINKLANG},//10
	{32, 34, SPECIES_KLINKLANG},//10
	{34, 36, SPECIES_REUNICLUS},//5
	{34, 36, SPECIES_REUNICLUS},//5
	{34, 36, SPECIES_DURALUDON},//4
	{34, 36, SPECIES_DURALUDON},//4
	{34, 36, SPECIES_TYPE_NULL},//1
	{34, 36, SPECIES_TYPE_NULL},//1
};
const struct WildPokemonInfo gCeruleanCave2F_LandMonsNightInfo = {21, gCeruleanCave2F_LandMonsNight};

const struct WildPokemon gCeruleanCaveB1F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_SHIINOTIC},//20
	{32, 34, SPECIES_NOIVERN},//20
	{32, 34, SPECIES_MEDICHAM},//10
	{32, 34, SPECIES_MEDICHAM},//10
	{32, 34, SPECIES_LOPUNNY},//10
	{32, 34, SPECIES_LOPUNNY},//10
	{34, 36, SPECIES_GARDEVOIR},//5
	{34, 36, SPECIES_GARDEVOIR},//5
	{34, 36, SPECIES_EXCADRILL},//4
	{34, 36, SPECIES_EXCADRILL},//4
	{34, 36, SPECIES_TYPE_NULL},//1
	{34, 36, SPECIES_TYPE_NULL},//1
};
const struct WildPokemonInfo gCeruleanCaveB1F_LandMonsMorningInfo = {21, gCeruleanCaveB1F_LandMonsMorning};

const struct WildPokemon gCeruleanCaveB1F_LandMonsNight[] = 
{
	{32, 34, SPECIES_SHIINOTIC},//20
	{32, 34, SPECIES_NOIVERN},//20
	{32, 34, SPECIES_TOXICROAK},//10
	{32, 34, SPECIES_TOXICROAK},//10
	{32, 34, SPECIES_LOPUNNY},//10
	{32, 34, SPECIES_LOPUNNY},//10
	{34, 36, SPECIES_GARDEVOIR},//5
	{34, 36, SPECIES_GARDEVOIR},//5
	{34, 36, SPECIES_EXCADRILL},//4
	{34, 36, SPECIES_EXCADRILL},//4
	{34, 36, SPECIES_TYPE_NULL},//1
	{34, 36, SPECIES_TYPE_NULL},//1
};
const struct WildPokemonInfo gCeruleanCaveB1F_LandMonsNightInfo = {21, gCeruleanCaveB1F_LandMonsNight};

const struct WildPokemon gCeruleanCaveB1F_SurfMons[] = 
{
	{55, 60, SPECIES_SHARPEDO},//60
	{55, 60, SPECIES_SLOWBRO},//30
	{55, 60, SPECIES_TOXAPEX},//5
	{55, 60, SPECIES_TOXAPEX},//4
	{55, 60, SPECIES_MILOTIC},//1
};
const struct WildPokemonInfo gCeruleanCaveB1F_SurfMonsInfo = {21, gCeruleanCaveB1F_SurfMons};

const struct WildPokemon gCeruleanCaveB1F_FishingMons[] = 
{
	{ 3,  4, SPECIES_FEEBAS},//old rod 70
	{ 4,  5, SPECIES_MAREANIE},//old rod 30
	{30, 32, SPECIES_CORPHISH},//good rod 60
	{30, 32, SPECIES_KRABBY},//good rod 20
	{30, 32, SPECIES_MAREANIE},//good rod 20
	{55, 60, SPECIES_POLIWRATH},//super rod 40
	{55, 60, SPECIES_CRAWDAUNT},//super rod 40
	{55, 60, SPECIES_SHARPEDO},//super rod 15
	{55, 60, SPECIES_GYARADOS},//super rod 4
	{55, 60, SPECIES_GYARADOS},//super rod 1
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
	{55, 60, SPECIES_PSYDUCK},//60
	{55, 60, SPECIES_PSYDUCK},//30
	{55, 60, SPECIES_PSYDUCK},//5
	{55, 60, SPECIES_PSYDUCK},//4
	{55, 60, SPECIES_PSYDUCK},//1
};
const struct WildPokemonInfo gRoute23_SurfMonsInfo = {21, gRoute23_SurfMons};

const struct WildPokemon gRoute23_FishingMons[] = 
{
	{ 3,  4, SPECIES_MAGIKARP},//old rod 70
	{ 4,  5, SPECIES_MAGIKARP},//old rod 30
	{30, 32, SPECIES_POLIWAG},//good rod 60
	{30, 32, SPECIES_GOLDEEN},//good rod 20
	{30, 32, SPECIES_MAGIKARP},//good rod 20
	{55, 60, SPECIES_POLIWAG},//super rod 40
	{55, 60, SPECIES_PSYDUCK},//super rod 40
	{55, 60, SPECIES_POLIWHIRL},//super rod 15
	{55, 60, SPECIES_GYARADOS},//super rod 4
	{55, 60, SPECIES_GYARADOS},//super rod 1
};
const struct WildPokemonInfo gRoute23_FishingMonsInfo = {21, gRoute23_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Victory Road
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gVictoryRoad1F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_DRAGONITE},//20
	{32, 34, SPECIES_METAGROSS},//20
	{32, 34, SPECIES_GOODRA},//10
	{32, 34, SPECIES_STEELIX},//10
	{32, 34, SPECIES_SNORLAX},//10
	{32, 34, SPECIES_SNORLAX},//10
	{34, 36, SPECIES_VOLCARONA},//5
	{34, 36, SPECIES_AEGISLASH},//5
	{34, 36, SPECIES_MAROWAK},//4
	{34, 36, SPECIES_GOODRA},//4
	{34, 36, SPECIES_METAGROSS},//1
	{34, 36, SPECIES_DRAGONITE},//1
};
const struct WildPokemonInfo gVictoryRoad1F_LandMonsMorningInfo = {21, gVictoryRoad1F_LandMonsMorning};

const struct WildPokemon gVictoryRoad1F_LandMonsNight[] = 
{
	{32, 34, SPECIES_DRAGONITE},//20
	{32, 34, SPECIES_METAGROSS},//20
	{32, 34, SPECIES_GOODRA},//10
	{32, 34, SPECIES_STEELIX},//10
	{32, 34, SPECIES_SNORLAX},//10
	{32, 34, SPECIES_SNORLAX},//10
	{34, 36, SPECIES_VOLCARONA},//5
	{34, 36, SPECIES_AEGISLASH},//5
	{34, 36, SPECIES_MAROWAK_A},//4
	{34, 36, SPECIES_GOODRA},//4
	{34, 36, SPECIES_METAGROSS},//1
	{34, 36, SPECIES_DRAGONITE},//1
};
const struct WildPokemonInfo gVictoryRoad1F_LandMonsNightInfo = {21, gVictoryRoad1F_LandMonsNight};

const struct WildPokemon gVictoryRoad2F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_TYRANITAR},//20
	{32, 34, SPECIES_GARCHOMP},//20
	{32, 34, SPECIES_KOMMO_O},//10
	{32, 34, SPECIES_MACHAMP},//10
	{32, 34, SPECIES_MEDICHAM},//10
	{32, 34, SPECIES_MEDICHAM},//10
	{34, 36, SPECIES_LUCARIO},//5
	{34, 36, SPECIES_LUCARIO},//5
	{34, 36, SPECIES_MACHAMP},//4
	{34, 36, SPECIES_KOMMO_O},//4
	{34, 36, SPECIES_GARCHOMP},//1
	{34, 36, SPECIES_TYRANITAR},//1
};
const struct WildPokemonInfo gVictoryRoad2F_LandMonsMorningInfo = {21, gVictoryRoad2F_LandMonsMorning};

const struct WildPokemon gVictoryRoad2F_LandMonsNight[] = 
{
	{32, 34, SPECIES_TYRANITAR},//20
	{32, 34, SPECIES_GARCHOMP},//20
	{32, 34, SPECIES_KOMMO_O},//10
	{32, 34, SPECIES_MACHAMP},//10
	{32, 34, SPECIES_MEDICHAM},//10
	{32, 34, SPECIES_MEDICHAM},//10
	{34, 36, SPECIES_LUCARIO},//5
	{34, 36, SPECIES_LUCARIO},//5
	{34, 36, SPECIES_MACHAMP},//4
	{34, 36, SPECIES_KOMMO_O},//4
	{34, 36, SPECIES_GARCHOMP},//1
	{34, 36, SPECIES_TYRANITAR},//1
};
const struct WildPokemonInfo gVictoryRoad2F_LandMonsNightInfo = {21, gVictoryRoad2F_LandMonsNight};

const struct WildPokemon gVictoryRoad3F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_SALAMENCE},//20
	{32, 34, SPECIES_HYDREIGON},//20
	{32, 34, SPECIES_DRAGAPULT},//10
	{32, 34, SPECIES_MAWILE},//10
	{32, 34, SPECIES_MAWILE},//10
	{32, 34, SPECIES_TOXTRICITY},//10
	{34, 36, SPECIES_SCIZOR},//5
	{34, 36, SPECIES_DURALUDON},//5
	{34, 36, SPECIES_DURALUDON},//4
	{34, 36, SPECIES_DRAGAPULT},//4
	{34, 36, SPECIES_HYDREIGON},//1
	{34, 36, SPECIES_SALAMENCE},//1
};
const struct WildPokemonInfo gVictoryRoad3F_LandMonsMorningInfo = {21, gVictoryRoad3F_LandMonsMorning};

const struct WildPokemon gVictoryRoad3F_LandMonsNight[] = 
{
	{32, 34, SPECIES_SALAMENCE},//20
	{32, 34, SPECIES_HYDREIGON},//20
	{32, 34, SPECIES_DRAGAPULT},//10
	{32, 34, SPECIES_MAWILE},//10
	{32, 34, SPECIES_MAWILE},//10
	{32, 34, SPECIES_TOXTRICITY},//10
	{34, 36, SPECIES_SCIZOR},//5
	{34, 36, SPECIES_DURALUDON},//5
	{34, 36, SPECIES_DURALUDON},//4
	{34, 36, SPECIES_DRAGAPULT},//4
	{34, 36, SPECIES_HYDREIGON},//1
	{34, 36, SPECIES_SALAMENCE},//1
};
const struct WildPokemonInfo gVictoryRoad3F_LandMonsNightInfo = {21, gVictoryRoad3F_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Safari Zone
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gSafariZoneCenter_LandMonsMorning[] = 
{
	{32, 34, SPECIES_KECLEON},//20
	{32, 34, SPECIES_SPINDA},//20
	{32, 34, SPECIES_CARNIVINE},//10
	{32, 34, SPECIES_ABSOL},//10
	{32, 34, SPECIES_MELTAN},//10
	{32, 34, SPECIES_MELTAN},//10
	{34, 36, SPECIES_PORYGON},//5
	{34, 36, SPECIES_PORYGON},//5
	{34, 36, SPECIES_SCYTHER},//4
	{34, 36, SPECIES_SCYTHER},//4
	{34, 36, SPECIES_CHANSEY},//1
	{34, 36, SPECIES_CHANSEY},//1
};
const struct WildPokemonInfo gSafariZoneCenter_LandMonsMorningInfo = {21, gSafariZoneCenter_LandMonsMorning};

const struct WildPokemon gSafariZoneCenter_LandMonsNight[] = 
{
	{32, 34, SPECIES_KECLEON},//20
	{32, 34, SPECIES_SPINDA},//20
	{32, 34, SPECIES_CARNIVINE},//10
	{32, 34, SPECIES_ABSOL},//10
	{32, 34, SPECIES_MELTAN},//10
	{32, 34, SPECIES_MELTAN},//10
	{34, 36, SPECIES_PORYGON},//5
	{34, 36, SPECIES_PORYGON},//5
	{34, 36, SPECIES_HERACROSS},//4
	{34, 36, SPECIES_HERACROSS},//4
	{34, 36, SPECIES_CHANSEY},//1
	{34, 36, SPECIES_CHANSEY},//1
};
const struct WildPokemonInfo gSafariZoneCenter_LandMonsNightInfo = {21, gSafariZoneCenter_LandMonsNight};

const struct WildPokemon gSafariZoneCenter_SurfMons[] = 
{
	{55, 60, SPECIES_FRILLISH},//60
	{55, 60, SPECIES_GOLDUCK},//30
	{55, 60, SPECIES_JELLICENT},//5
	{55, 60, SPECIES_GOLDUCK},//4
	{55, 60, SPECIES_GOLDUCK},//1
};
const struct WildPokemonInfo gSafariZoneCenter_SurfMonsInfo = {21, gSafariZoneCenter_SurfMons};

const struct WildPokemon gSafariZoneCenter_FishingMons[] = 
{
	{ 3,  4, SPECIES_MAGIKARP},//old rod 70
	{ 4,  5, SPECIES_KRABBY},//old rod 30
	{30, 32, SPECIES_QWILFISH},//good rod 60
	{30, 32, SPECIES_MAREANIE},//good rod 20
	{30, 32, SPECIES_MANTYKE},//good rod 20
	{55, 60, SPECIES_ALOMOMOLA},//super rod 40
	{55, 60, SPECIES_BASCULIN_BLUE},//super rod 40
	{55, 60, SPECIES_SHARPEDO},//super rod 15
	{55, 60, SPECIES_FEEBAS},//super rod 4
	{55, 60, SPECIES_FEEBAS},//super rod 1
};
const struct WildPokemonInfo gSafariZoneCenter_FishingMonsInfo = {21, gSafariZoneCenter_FishingMons};

const struct WildPokemon gSafariZoneEast_LandMonsMorning[] = 
{
	{32, 34, SPECIES_HAWLUCHA},//20
	{32, 34, SPECIES_CASTFORM},//20
	{32, 34, SPECIES_BOUFFALANT},//10
	{32, 34, SPECIES_BOUFFALANT},//10
	{32, 34, SPECIES_WOBBUFFET},//10
	{32, 34, SPECIES_WOBBUFFET},//10
	{34, 36, SPECIES_ZORUA},//5
	{34, 36, SPECIES_ZORUA},//5
	{34, 36, SPECIES_PINSIR},//4
	{34, 36, SPECIES_PINSIR},//4
	{34, 36, SPECIES_KANGASKHAN},//1
	{34, 36, SPECIES_KANGASKHAN},//1
};
const struct WildPokemonInfo gSafariZoneEast_LandMonsMorningInfo = {21, gSafariZoneEast_LandMonsMorning};

const struct WildPokemon gSafariZoneEast_LandMonsNight[] = 
{
	{32, 34, SPECIES_HAWLUCHA},//20
	{32, 34, SPECIES_CASTFORM},//20
	{32, 34, SPECIES_TAUROS},//10
	{32, 34, SPECIES_TAUROS},//10
	{32, 34, SPECIES_WOBBUFFET},//10
	{32, 34, SPECIES_WOBBUFFET},//10
	{34, 36, SPECIES_ZORUA},//5
	{34, 36, SPECIES_ZORUA},//5
	{34, 36, SPECIES_PINSIR},//4
	{34, 36, SPECIES_PINSIR},//4
	{34, 36, SPECIES_KANGASKHAN},//1
	{34, 36, SPECIES_KANGASKHAN},//1
};
const struct WildPokemonInfo gSafariZoneEast_LandMonsNightInfo = {21, gSafariZoneEast_LandMonsNight};

const struct WildPokemon gSafariZoneEast_SurfMons[] = 
{
	{55, 60, SPECIES_WIMPOD},//60
	{55, 60, SPECIES_LANTURN},//30
	{55, 60, SPECIES_ARAQUANID},//5
	{55, 60, SPECIES_SEISMITOAD},//4
	{55, 60, SPECIES_SEISMITOAD},//1
};
const struct WildPokemonInfo gSafariZoneEast_SurfMonsInfo = {21, gSafariZoneEast_SurfMons};

const struct WildPokemon gSafariZoneEast_FishingMons[] = 
{
	{ 3,  4, SPECIES_MAGIKARP},//old rod 70
	{ 4,  5, SPECIES_ARROKUDA},//old rod 30
	{30, 32, SPECIES_CORSOLA},//good rod 60
	{30, 32, SPECIES_SEADRA},//good rod 20
	{30, 32, SPECIES_REMORAID},//good rod 20
	{55, 60, SPECIES_GOREBYSS},//super rod 40
	{55, 60, SPECIES_HUNTAIL},//super rod 40
	{55, 60, SPECIES_STARMIE},//super rod 15
	{55, 60, SPECIES_DHELMISE},//super rod 4
	{55, 60, SPECIES_DHELMISE},//super rod 1
};
const struct WildPokemonInfo gSafariZoneEast_FishingMonsInfo = {21, gSafariZoneEast_FishingMons};

const struct WildPokemon gSafariZoneNorth_LandMonsMorning[] = 
{
	{32, 34, SPECIES_KLEFKI},//20
	{32, 34, SPECIES_KLEFKI},//20
	{32, 34, SPECIES_SAWK},//10
	{32, 34, SPECIES_SAWK},//10
	{32, 34, SPECIES_BISHARP},//10
	{32, 34, SPECIES_BISHARP},//10
	{34, 36, SPECIES_SKARMORY},//5
	{34, 36, SPECIES_SKARMORY},//5
	{34, 36, SPECIES_BINACLE},//4
	{34, 36, SPECIES_BINACLE},//4
	{34, 36, SPECIES_AXEW},//1
	{34, 36, SPECIES_AXEW},//1
};
const struct WildPokemonInfo gSafariZoneNorth_LandMonsMorningInfo = {21, gSafariZoneNorth_LandMonsMorning};

const struct WildPokemon gSafariZoneNorth_LandMonsNight[] = 
{
	{32, 34, SPECIES_KLEFKI},//20
	{32, 34, SPECIES_KLEFKI},//20
	{32, 34, SPECIES_THROH},//10
	{32, 34, SPECIES_THROH},//10
	{32, 34, SPECIES_BISHARP},//10
	{32, 34, SPECIES_BISHARP},//10
	{34, 36, SPECIES_CORVIKNIGHT},//5
	{34, 36, SPECIES_CORVIKNIGHT},//5
	{34, 36, SPECIES_BINACLE},//4
	{34, 36, SPECIES_BINACLE},//4
	{34, 36, SPECIES_AXEW},//1
	{34, 36, SPECIES_AXEW},//1
};
const struct WildPokemonInfo gSafariZoneNorth_LandMonsNightInfo = {21, gSafariZoneNorth_LandMonsNight};

const struct WildPokemon gSafariZoneNorth_SurfMons[] = 
{
	{55, 60, SPECIES_DEWPIDER},//60
	{55, 60, SPECIES_TOXAPEX},//30
	{55, 60, SPECIES_GOLISOPOD},//5
	{55, 60, SPECIES_GOLISOPOD},//4
	{55, 60, SPECIES_GOLISOPOD},//1
};
const struct WildPokemonInfo gSafariZoneNorth_SurfMonsInfo = {21, gSafariZoneNorth_SurfMons};

const struct WildPokemon gSafariZoneNorth_FishingMons[] = 
{
	{ 3,  4, SPECIES_MAGIKARP},//old rod 70
	{ 4,  5, SPECIES_POLIWAG},//old rod 30
	{30, 32, SPECIES_PYUKUMUKU},//good rod 60
	{30, 32, SPECIES_KRABBY},//good rod 20
	{30, 32, SPECIES_WAILMER},//good rod 20
	{55, 60, SPECIES_KINGLER},//super rod 40
	{55, 60, SPECIES_BRUXISH},//super rod 40
	{55, 60, SPECIES_SKRELP},//super rod 15
	{55, 60, SPECIES_SKRELP},//super rod 4
	{55, 60, SPECIES_SKRELP},//super rod 1
};
const struct WildPokemonInfo gSafariZoneNorth_FishingMonsInfo = {21, gSafariZoneNorth_FishingMons};

const struct WildPokemon gSafariZoneWest_LandMonsMorning[] = 
{
	{32, 34, SPECIES_DRUDDIGON},//20
	{32, 34, SPECIES_DRUDDIGON},//20
	{32, 34, SPECIES_VESPIQUEN},//10
	{32, 34, SPECIES_VESPIQUEN},//10
	{32, 34, SPECIES_HIPPOWDON},//10
	{32, 34, SPECIES_HIPPOWDON},//10
	{34, 36, SPECIES_YANMA},//5
	{34, 36, SPECIES_YANMA},//5
	{34, 36, SPECIES_CRABOMINABLE},//4
	{34, 36, SPECIES_CRABOMINABLE},//4
	{34, 36, SPECIES_SMEARGLE},//1
	{34, 36, SPECIES_SMEARGLE},//1
};
const struct WildPokemonInfo gSafariZoneWest_LandMonsMorningInfo = {21, gSafariZoneWest_LandMonsMorning};

const struct WildPokemon gSafariZoneWest_LandMonsNight[] = 
{
	{32, 34, SPECIES_DRUDDIGON},//20
	{32, 34, SPECIES_DRUDDIGON},//20
	{32, 34, SPECIES_VESPIQUEN},//10
	{32, 34, SPECIES_VESPIQUEN},//10
	{32, 34, SPECIES_HIPPOWDON},//10
	{32, 34, SPECIES_HIPPOWDON},//10
	{34, 36, SPECIES_YANMA},//5
	{34, 36, SPECIES_YANMA},//5
	{34, 36, SPECIES_CRABOMINABLE},//4
	{34, 36, SPECIES_CRABOMINABLE},//4
	{34, 36, SPECIES_SMEARGLE},//1
	{34, 36, SPECIES_SMEARGLE},//1
};
const struct WildPokemonInfo gSafariZoneWest_LandMonsNightInfo = {21, gSafariZoneWest_LandMonsNight};

const struct WildPokemon gSafariZoneWest_SurfMons[] = 
{
	{55, 60, SPECIES_LUMINEON},//60
	{55, 60, SPECIES_FLOATZEL},//30
	{55, 60, SPECIES_RELICANTH},//5
	{55, 60, SPECIES_GOLDUCK},//4
	{55, 60, SPECIES_MILOTIC},//1
};
const struct WildPokemonInfo gSafariZoneWest_SurfMonsInfo = {21, gSafariZoneWest_SurfMons};

const struct WildPokemon gSafariZoneWest_FishingMons[] = 
{
	{ 3,  4, SPECIES_MAGIKARP},//old rod 70
	{ 4,  5, SPECIES_HORSEA},//old rod 30
	{30, 32, SPECIES_QWILFISH},//good rod 60
	{30, 32, SPECIES_SEADRA},//good rod 20
	{30, 32, SPECIES_WAILMER},//good rod 20
	{55, 60, SPECIES_CRAWDAUNT},//super rod 40
	{55, 60, SPECIES_SEAKING},//super rod 40
	{55, 60, SPECIES_BASCULIN_RED},//super rod 15
	{55, 60, SPECIES_RELICANTH},//super rod 4
	{55, 60, SPECIES_RELICANTH},//super rod 1
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
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
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
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
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
