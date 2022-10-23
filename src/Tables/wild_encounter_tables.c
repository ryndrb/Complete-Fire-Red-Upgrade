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

// Adapted Radical Red encounter table. Credits to soupercell
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 1 Land Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute1_LandMonsMorning[] = 
{
	{3, 4, SPECIES_BIDOOF},//20
	{3, 4, SPECIES_ZIGZAGOON},//20
	{3, 4, SPECIES_RATTATA},//10
	{3, 4, SPECIES_PIDGEY},//10
	{3, 4, SPECIES_MEOWTH},//10
	{3, 4, SPECIES_YUNGOOS},//10
	{4, 5, SPECIES_MIENFOO},//5
	{4, 5, SPECIES_MIENFOO},//5
	{4, 5, SPECIES_SEEDOT},//4
	{4, 5, SPECIES_SEEDOT},//4
	{4, 5, SPECIES_PANSEAR},//1
	{4, 5, SPECIES_PANSEAR},//1
};
const struct WildPokemonInfo gRoute1_LandMonsMorningInfo = {21, gRoute1_LandMonsMorning};

const struct WildPokemon gRoute1_LandMonsNight[] = 
{
	{3, 4, SPECIES_POOCHYENA},//20
	{3, 4, SPECIES_ZIGZAGOON_G},//20
	{3, 4, SPECIES_RATTATA_A},//10
	{3, 4, SPECIES_PIDGEY},//10
	{3, 4, SPECIES_MEOWTH_G},//10
	{3, 4, SPECIES_HOOTHOOT},//10
	{4, 5, SPECIES_SCRAGGY},//5
	{4, 5, SPECIES_SCRAGGY},//5
	{4, 5, SPECIES_SEEDOT},//4
	{4, 5, SPECIES_SEEDOT},//4
	{4, 5, SPECIES_PANSEAR},//1
	{4, 5, SPECIES_PANSEAR},//1
};
const struct WildPokemonInfo gRoute1_LandMonsNightInfo = {21, gRoute1_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 1 Surf Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute1_SurfMons[] = 
{
	{55, 60, SPECIES_LANTURN},//60
	{55, 60, SPECIES_LANTURN},//30
	{55, 60, SPECIES_LANTURN},//5
	{55, 60, SPECIES_ALOMOMOLA},//4
	{55, 60, SPECIES_LANTURN},//1
};
const struct WildPokemonInfo gRoute1_SurfMonsInfo = {21, gRoute1_SurfMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 1 Fishing Encounters
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
//@@ Route 2 Land Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute2_LandMonsMorning[] = 
{
	{4, 5, SPECIES_BIDOOF},//20
	{4, 5, SPECIES_SENTRET},//20
	{4, 5, SPECIES_PONYTA},//10
	{4, 5, SPECIES_PHANPY},//10
	{4, 5, SPECIES_MAREEP},//10
	{4, 5, SPECIES_SHINX},//10
	{5, 6, SPECIES_MEDITITE},//5
	{5, 6, SPECIES_LITLEO},//5
	{5, 6, SPECIES_ZIGZAGOON},//4
	{5, 6, SPECIES_ABRA},//4
	{5, 6, SPECIES_PANSAGE},//1
	{5, 6, SPECIES_PANSAGE},//1
};
const struct WildPokemonInfo gRoute2_LandMonsMorningInfo = {21, gRoute2_LandMonsMorning};

const struct WildPokemon gRoute2_LandMonsNight[] = 
{
	{4, 5, SPECIES_POOCHYENA},//20
	{4, 5, SPECIES_SENTRET},//20
	{4, 5, SPECIES_PONYTA_G},//10
	{4, 5, SPECIES_PHANPY},//10
	{4, 5, SPECIES_MAREEP},//10
	{4, 5, SPECIES_SHINX},//10
	{5, 6, SPECIES_MEDITITE},//5 
	{5, 6, SPECIES_HOUNDOUR},//5
	{5, 6, SPECIES_ZIGZAGOON_G},//4
	{5, 6, SPECIES_ABRA},//4
	{5, 6, SPECIES_PANSAGE},//1
	{5, 6, SPECIES_PANSAGE},//1
};
const struct WildPokemonInfo gRoute2_LandMonsNightInfo = {21, gRoute2_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 3 Land Encounters 
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
//@@ Route 4 Land Encounters 
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

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 4 Surf Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute4_SurfMons[] = 
{
	{55, 60, SPECIES_GOLDUCK},//60
	{55, 60, SPECIES_GOLDUCK},//30
	{55, 60, SPECIES_GOLDUCK},//5
	{55, 60, SPECIES_WISHIWASHI_S},//4
	{55, 60, SPECIES_WISHIWASHI_S},//1
};
const struct WildPokemonInfo gRoute4_SurfMonsInfo = {21, gRoute4_SurfMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 4 Fishing Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
	{23, 25, SPECIES_VULPIX},//5
	{23, 25, SPECIES_GRIMER},//4
	{23, 25, SPECIES_GRIMER},//4
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
	{23, 25, SPECIES_GROWLITHE},//5
	{23, 25, SPECIES_GRIMER_A},//4
	{23, 25, SPECIES_GRIMER_A},//4
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
	{23, 25, SPECIES_TOGEPI},//1
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
	{23, 25, SPECIES_TOGEPI},//1
};
const struct WildPokemonInfo gRoute6_LandMonsNightInfo = {21, gRoute6_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 6 Surf Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute6_SurfMons[] = 
{
	{55, 60, SPECIES_SLOWBRO_G},//60
	{55, 60, SPECIES_SLOWBRO_G},//30
	{55, 60, SPECIES_SLOWBRO_G},//5
	{55, 60, SPECIES_GYARADOS},//4
	{55, 60, SPECIES_GYARADOS},//1
};
const struct WildPokemonInfo gRoute6_SurfMonsInfo = {21, gRoute6_SurfMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 6 Fishing Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
//@@ Route 9 Land Encounters 
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
//@@ Route 10 Land Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute10_LandMonsMorning[] = 
{
	{30, 32, SPECIES_VOLTORB},//20
	{30, 32, SPECIES_HELIOPTILE},//20
	{30, 32, SPECIES_HELIOPTILE},//10
	{30, 32, SPECIES_PINCURCHIN},//10
	{30, 32, SPECIES_PLUSLE},//10
	{30, 32, SPECIES_SKITTY},//10
	{32, 34, SPECIES_EMOLGA},//5
	{32, 34, SPECIES_EMOLGA},//5
	{32, 34, SPECIES_MAGNEMITE},//4
	{32, 34, SPECIES_MAGNEMITE},//4
	{32, 34, SPECIES_CROAGUNK},//1
	{32, 34, SPECIES_CROAGUNK},//1
};
const struct WildPokemonInfo gRoute10_LandMonsMorningInfo = {21, gRoute10_LandMonsMorning};

const struct WildPokemon gRoute10_LandMonsNight[] = 
{
	{30, 32, SPECIES_VOLTORB},//20
	{30, 32, SPECIES_ELECTRIKE},//20
	{30, 32, SPECIES_ELECTRIKE},//10
	{30, 32, SPECIES_PINCURCHIN},//10
	{30, 32, SPECIES_MINUN},//10
	{30, 32, SPECIES_SKITTY},//10
	{32, 34, SPECIES_EMOLGA},//5
	{32, 34, SPECIES_EMOLGA},//5
	{32, 34, SPECIES_MAGNEMITE},//4
	{32, 34, SPECIES_MAGNEMITE},//4
	{32, 34, SPECIES_CROAGUNK},//1
	{32, 34, SPECIES_CROAGUNK},//1
};
const struct WildPokemonInfo gRoute10_LandMonsNightInfo = {21, gRoute10_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 10 Surf Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute10_SurfMons[] = 
{
	{55, 60, SPECIES_TENTACOOL},//60
	{55, 60, SPECIES_TENTACOOL},//30
	{55, 60, SPECIES_TENTACOOL},//5
	{55, 60, SPECIES_WINGULL},//4
	{55, 60, SPECIES_WINGULL},//1
};
const struct WildPokemonInfo gRoute10_SurfMonsInfo = {21, gRoute10_SurfMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 10 Fishing Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
//@@ Route 11 Land Encounters 
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

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 11 Surf Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute11_SurfMons[] = 
{
	{55, 60, SPECIES_PELIPPER},//60
	{55, 60, SPECIES_PELIPPER},//30
	{55, 60, SPECIES_TENTACRUEL},//5
	{55, 60, SPECIES_TENTACRUEL},//4
	{55, 60, SPECIES_SQUIRTLE},//1
};
const struct WildPokemonInfo gRoute11_SurfMonsInfo = {21, gRoute11_SurfMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 11 Fishing Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
//@@ Route 22 Land Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute22_LandMonsMorning[] = 
{
	{ 6, 8, SPECIES_STARLY},//20
	{ 6, 8, SPECIES_BUDEW},//20
	{ 6, 8, SPECIES_MANKEY},//10
	{ 6, 8, SPECIES_MORELULL},//10
	{ 6, 8, SPECIES_SNUBBULL},//10
	{ 6, 8, SPECIES_LILLIPUP},//10
	{ 7, 9, SPECIES_ODDISH},//5
	{ 7, 9, SPECIES_SANDYGAST},//5
	{ 7, 9, SPECIES_BELLSPROUT},//4
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
	{ 6, 8, SPECIES_FLABEBE},//10
	{ 6, 8, SPECIES_SKWOVET},//10
	{ 7, 9, SPECIES_APPLIN},//5
	{ 7, 9, SPECIES_SANDYGAST},//5
	{ 7, 9, SPECIES_PARAS},//4
	{ 7, 9, SPECIES_ROGGENROLA},//4
	{ 7, 9, SPECIES_PANPOUR},//1
	{ 7, 9, SPECIES_PANPOUR},//1
};
const struct WildPokemonInfo gRoute22_LandMonsNightInfo = {21, gRoute22_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 22 Surf Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute22_SurfMons[] = 
{
	{55, 60, SPECIES_BRUXISH},//60
	{55, 60, SPECIES_BRUXISH},//30
	{55, 60, SPECIES_BRUXISH},//5
	{55, 60, SPECIES_BARRASKEWDA},//4
	{55, 60, SPECIES_BARRASKEWDA},//1
};
const struct WildPokemonInfo gRoute22_SurfMonsInfo = {21, gRoute22_SurfMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 22 Fishing Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute22_FishingMons[] = 
{
	{ 3,  4, SPECIES_MARILL},//old rod 70
	{ 4,  5, SPECIES_CLAMPERL},//old rod 30
	{30, 32, SPECIES_CLAUNCHER},//good rod 60
	{30, 32, SPECIES_REMORAID},//good rod 20
	{30, 32, SPECIES_CORSOLA},//good rod 20
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_BRUXISH},//super rod 15
	{55, 60, SPECIES_BARRASKEWDA},//super rod 4
	{55, 60, SPECIES_BARRASKEWDA},//super rod 1
};
const struct WildPokemonInfo gRoute22_FishingMonsInfo = {21, gRoute22_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 24 Land Encounters 
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
	{19, 21, SPECIES_GLIGAR},//1
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
	{19, 21, SPECIES_GLIGAR},//1
};
const struct WildPokemonInfo gRoute24_LandMonsNightInfo = {21, gRoute24_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 24 Surf Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute24_SurfMons[] = 
{
	{55, 60, SPECIES_GOLDUCK},//60
	{55, 60, SPECIES_GOLDUCK},//30
	{55, 60, SPECIES_GOLDUCK},//5
	{55, 60, SPECIES_SHARPEDO},//4
	{55, 60, SPECIES_SHARPEDO},//1
};
const struct WildPokemonInfo gRoute24_SurfMonsInfo = {21, gRoute24_SurfMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 24 Fishing Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute24_FishingMons[] = 
{
	{ 3,  4, SPECIES_CARVANHA},//old rod 70
	{ 4,  5, SPECIES_LOTAD},//old rod 30
	{30, 32, SPECIES_WAILMER},//good rod 60
	{30, 32, SPECIES_WISHIWASHI},//good rod 20
	{30, 32, SPECIES_WISHIWASHI},//good rod 20
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_LUVDISC},//super rod 40
	{55, 60, SPECIES_SHARPEDO},//super rod 15
	{55, 60, SPECIES_OCTILLERY},//super rod 4
	{55, 60, SPECIES_OCTILLERY},//super rod 1
};
const struct WildPokemonInfo gRoute24_FishingMonsInfo = {21, gRoute24_FishingMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 25 Land Encounters 
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
	{21, 23, SPECIES_ZANGOOSE},//1
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
	{21, 23, SPECIES_SEVIPER},//1
};
const struct WildPokemonInfo gRoute25_LandMonsNightInfo = {21, gRoute25_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 25 Surf Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRoute25_SurfMons[] = 
{
	{55, 60, SPECIES_ARAQUANID},//60
	{55, 60, SPECIES_ARAQUANID},//30
	{55, 60, SPECIES_ARAQUANID},//5
	{55, 60, SPECIES_GYARADOS},//4
	{55, 60, SPECIES_GYARADOS},//1
};
const struct WildPokemonInfo gRoute25_SurfMonsInfo = {21, gRoute25_SurfMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Route 25 Fishing Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
	{55, 60, SPECIES_ARAQUANID},//super rod 4
	{55, 60, SPECIES_ARAQUANID},//super rod 1
};
const struct WildPokemonInfo gRoute25_FishingMonsInfo = {21, gRoute25_FishingMons};















//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Pallet Town Surf Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gPalletTown_SurfMons[] = 
{
	{55, 60, SPECIES_TENTACRUEL},//60
	{55, 60, SPECIES_TENTACRUEL},//30
	{55, 60, SPECIES_TENTACRUEL},//5
	{55, 60, SPECIES_WHISCASH},//4
	{55, 60, SPECIES_WHISCASH},//1
};
const struct WildPokemonInfo gPalletTown_SurfMonsInfo = {21, gPalletTown_SurfMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Pallet Town Fishing Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
//@@ Viridian City Land Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gViridianCity_LandMonsMorning[] = 
{
	{4, 5, SPECIES_SHINX},//20
	{4, 5, SPECIES_PATRAT},//20
	{4, 5, SPECIES_SANDSHREW},//10
	{4, 5, SPECIES_WINGULL},//10
	{4, 5, SPECIES_WOOLOO},//10
	{4, 5, SPECIES_CUBCHOO},//10
	{5, 6, SPECIES_DEERLING_SUMMER},//5
	{5, 6, SPECIES_PIKIPEK},//5
	{5, 6, SPECIES_SANDILE},//4
	{5, 6, SPECIES_SNOVER},//4
	{5, 6, SPECIES_CHINCHOU},//1
	{5, 6, SPECIES_CHINCHOU},//1
};
const struct WildPokemonInfo gViridianCity_LandMonsMorningInfo = {21, gViridianCity_LandMonsMorning};

const struct WildPokemon gViridianCity_LandMonsNight[] = 
{
	{4, 5, SPECIES_SHINX},//20
	{4, 5, SPECIES_PATRAT},//20
	{4, 5, SPECIES_POOCHYENA},//10
	{4, 5, SPECIES_SPEAROW},//10
	{4, 5, SPECIES_MAREEP},//10
	{4, 5, SPECIES_CUBCHOO},//10
	{5, 6, SPECIES_DEERLING_AUTUMN},//5
	{5, 6, SPECIES_DWEBBLE},//5
	{5, 6, SPECIES_SHUPPET},//4
	{5, 6, SPECIES_SWINUB},//4
	{5, 6, SPECIES_LOTAD},//1
	{5, 6, SPECIES_LOTAD},//1
};
const struct WildPokemonInfo gViridianCity_LandMonsNightInfo = {21, gViridianCity_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Viridian City Surf Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gViridianCity_SurfMons[] = 
{
	{55, 60, SPECIES_LANTURN},//60
	{55, 60, SPECIES_LANTURN},//30
	{55, 60, SPECIES_LANTURN},//5
	{55, 60, SPECIES_LANTURN},//4
	{55, 60, SPECIES_LANTURN},//1
};
const struct WildPokemonInfo gViridianCity_SurfMonsInfo = {21, gViridianCity_SurfMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Viridian City Fishing Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
//@@ Pewter City Land Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gPewterCity_LandMonsMorning[] = 
{
	{7, 9, SPECIES_GRIMER},//20
	{7, 9, SPECIES_STARLY},//20
	{7, 9, SPECIES_EXEGGCUTE},//10
	{7, 9, SPECIES_SPOINK},//10
	{7, 9, SPECIES_HOPPIP},//10
	{7, 9, SPECIES_NUMEL},//10
	{9, 11, SPECIES_PHANPY},//5
	{9, 11, SPECIES_EKANS},//5
	{9, 11, SPECIES_SINISTEA},//4
	{9, 11, SPECIES_CUTIEFLY},//4
	{9, 11, SPECIES_AXEW},//1
	{9, 11, SPECIES_BONSLY},//1
};
const struct WildPokemonInfo gPewterCity_LandMonsMorningInfo = {21, gPewterCity_LandMonsMorning};

const struct WildPokemon gPewterCity_LandMonsNight[] = 
{
	{7, 9, SPECIES_GRIMER_A},//20
	{7, 9, SPECIES_STARLY},//20
	{7, 9, SPECIES_EXEGGUTOR_A},//10
	{7, 9, SPECIES_ESPURR},//10
	{7, 9, SPECIES_SKIDDO},//10
	{7, 9, SPECIES_NUMEL},//10
	{9, 11, SPECIES_PHANPY},//5 
	{9, 11, SPECIES_EKANS},//5
	{9, 11, SPECIES_SINISTEA},//4
	{9, 11, SPECIES_GASTLY},//4
	{9, 11, SPECIES_AXEW},//1
	{9, 11, SPECIES_BONSLY},//1
};
const struct WildPokemonInfo gPewterCity_LandMonsNightInfo = {21, gPewterCity_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Cerulean City Land Encounters 
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

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Cerulean City Surf Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gCeruleanCity_SurfMons[] = 
{
	{55, 60, SPECIES_GOLDUCK},//60
	{55, 60, SPECIES_GOLDUCK},//30
	{55, 60, SPECIES_GOLDUCK},//5
	{55, 60, SPECIES_SHARPEDO},//4
	{55, 60, SPECIES_SHARPEDO},//1
};
const struct WildPokemonInfo gCeruleanCity_SurfMonsInfo = {21, gCeruleanCity_SurfMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Cerulean City Fishing Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
//@@ Vermillion City Surf Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gVermillionCity_SurfMons[] = 
{
	{55, 60, SPECIES_TENTACOOL},//60
	{55, 60, SPECIES_PELIPPER},//30
	{55, 60, SPECIES_TENTACRUEL},//5
	{55, 60, SPECIES_SQUIRTLE},//4
	{55, 60, SPECIES_SQUIRTLE},//1
};
const struct WildPokemonInfo gVermillionCity_SurfMonsInfo = {21, gVermillionCity_SurfMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Vermillion City Fishing Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
//@@ Viridian Forest Land Encounters 
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
	{6, 8, SPECIES_PUMPKABOO_M},//4
	{6, 8, SPECIES_PHANTUMP},//1
	{6, 8, SPECIES_SNOM},//1
};
const struct WildPokemonInfo gViridianForest_LandMonsNightInfo = {21, gViridianForest_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Viridian Forest Surf Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gViridianForest_SurfMons[] = 
{
	{55, 60, SPECIES_LUDICOLO},//60
	{55, 60, SPECIES_LUDICOLO},//30
	{55, 60, SPECIES_LUDICOLO},//5
	{55, 60, SPECIES_ARAQUANID},//4
	{55, 60, SPECIES_ARAQUANID},//1
};
const struct WildPokemonInfo gViridianForest_SurfMonsInfo = {21, gViridianForest_SurfMons};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Viridian Forest Fishing Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
//@@ Digletts Cave Land Encounters 
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

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Digletts Cave B1F Land Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
//@@ Mt Moon 1F Land Encounters 
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

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Mt Moon B1F Land Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gMtMoonB1F_LandMonsMorning[] = 
{
	{12, 16, SPECIES_PARAS},//20
	{12, 16, SPECIES_PARAS},//20
	{12, 16, SPECIES_SLUGMA},//10
	{12, 16, SPECIES_SLUGMA},//10
	{12, 16, SPECIES_TORKOAL},//10
	{12, 16, SPECIES_TEDDIURSA},//10
	{14, 16, SPECIES_DWEBBLE},//5
	{14, 16, SPECIES_BALTOY},//5
	{14, 16, SPECIES_SHUPPET},//4
	{14, 16, SPECIES_SHUPPET},//4
	{14, 16, SPECIES_ELGYEM},//1
	{14, 14, SPECIES_RIOLU},//1
};
const struct WildPokemonInfo gMtMoonB1F_LandMonsMorningInfo = {21, gMtMoonB1F_LandMonsMorning};

const struct WildPokemon gMtMoonB1F_LandMonsNight[] = 
{
	{12, 16, SPECIES_PARAS},//20
	{12, 16, SPECIES_PARAS},//20
	{12, 16, SPECIES_SLUGMA},//10
	{12, 16, SPECIES_SLUGMA},//10
	{12, 16, SPECIES_TORKOAL},//10
	{12, 16, SPECIES_TEDDIURSA},//10
	{14, 16, SPECIES_DWEBBLE},//5 
	{14, 16, SPECIES_SANDILE},//5
	{14, 16, SPECIES_MISDREAVUS},//4
	{14, 16, SPECIES_MISDREAVUS},//4
	{14, 16, SPECIES_ELGYEM},//1
	{14, 14, SPECIES_RIOLU},//1
};
const struct WildPokemonInfo gMtMoonB1F_LandMonsNightInfo = {21, gMtMoonB1F_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Mt Moon B2F Land Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gMtMoonB2F_LandMonsMorning[] = 
{
	{12, 16, SPECIES_MAWILE},//20
	{12, 16, SPECIES_ZUBAT},//20
	{12, 16, SPECIES_PAWNIARD},//10
	{12, 16, SPECIES_NUMEL},//10
	{12, 16, SPECIES_CRANIDOS},//10
	{12, 16, SPECIES_DRILBUR},//10
	{14, 16, SPECIES_MUDBRAY},//5
	{14, 16, SPECIES_SMOOCHUM},//5
	{14, 16, SPECIES_SMOOCHUM},//4
	{14, 16, SPECIES_SOLROCK},//4
	{14, 16, SPECIES_ONIX},//1
	{14, 14, SPECIES_ONIX},//1
};
const struct WildPokemonInfo gMtMoonB2F_LandMonsMorningInfo = {21, gMtMoonB2F_LandMonsMorning};

const struct WildPokemon gMtMoonB2F_LandMonsNight[] = 
{
	{12, 16, SPECIES_MAWILE},//20
	{12, 16, SPECIES_ZUBAT},//20
	{12, 16, SPECIES_PAWNIARD},//10
	{12, 16, SPECIES_ROLYCOLY},//10
	{12, 16, SPECIES_SHIELDON},//10
	{12, 16, SPECIES_DRILBUR},//10
	{14, 16, SPECIES_MUDBRAY},//5 
	{14, 16, SPECIES_MUNNA},//5
	{14, 16, SPECIES_MUNNA},//4
	{14, 16, SPECIES_LUNATONE},//4
	{14, 16, SPECIES_ONIX},//1
	{14, 14, SPECIES_ONIX},//1
};
const struct WildPokemonInfo gMtMoonB2F_LandMonsNightInfo = {21, gMtMoonB2F_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ SS Anne Surf Encounters 
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

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ SS Anne Fishing Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
//@@ Rock Tunnel 1F Land Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRockTunnel1F_LandMonsMorning[] = 
{
	{32, 34, SPECIES_GRAVELER},//20
	{32, 34, SPECIES_ARON},//20
	{32, 34, SPECIES_SHUCKLE},//10
	{32, 34, SPECIES_SOLROCK},//10
	{32, 34, SPECIES_ZUBAT},//10
	{32, 34, SPECIES_CARBINK},//10
	{34, 36, SPECIES_MINIOR_INDIGO},//5
	{34, 36, SPECIES_FERROSEED},//5
	{34, 36, SPECIES_STONJOURNER},//4
	{34, 36, SPECIES_HEATMOR},//4
	{34, 36, SPECIES_DURANT},//1
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
	{32, 34, SPECIES_CARBINK},//10
	{34, 36, SPECIES_MINIOR_INDIGO},//5 
	{34, 36, SPECIES_FERROSEED},//5
	{34, 36, SPECIES_STONJOURNER},//4
	{34, 36, SPECIES_HEATMOR},//4
	{34, 36, SPECIES_DURANT},//1
	{34, 36, SPECIES_DURANT},//1
};
const struct WildPokemonInfo gRockTunnel1F_LandMonsNightInfo = {21, gRockTunnel1F_LandMonsNight};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Rock Tunnel B1F Land Encounters 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemon gRockTunnelB1F_LandMonsMorning[] = 
{
	{33, 35, SPECIES_SANDSLASH},//20
	{33, 35, SPECIES_BOLDORE},//20
	{33, 35, SPECIES_SWINUB},//10
	{33, 35, SPECIES_SNORUNT},//10
	{33, 35, SPECIES_BRONZOR},//10
	{33, 35, SPECIES_BONSLY},//10
	{35, 37, SPECIES_CARKOL},//5
	{35, 37, SPECIES_CARKOL},//5
	{35, 37, SPECIES_CUBCHOO},//4
	{35, 37, SPECIES_CUBCHOO},//4
	{35, 37, SPECIES_KLINK},//1
	{35, 37, SPECIES_KLINK},//1
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
	{35, 37, SPECIES_ONIX},//5
	{35, 37, SPECIES_SNEASEL},//4
	{35, 37, SPECIES_SNEASEL},//4
	{35, 37, SPECIES_KLINK},//1
	{35, 37, SPECIES_KLINK},//1
};
const struct WildPokemonInfo gRockTunnelB1F_LandMonsNightInfo = {21, gRockTunnelB1F_LandMonsNight};













//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Encounter Headers 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct WildPokemonHeader gWildMonMorningHeaders[] =
{
	// Routes
	{
		.mapGroup = MAP_GROUP(ROUTE_1),
		.mapNum = MAP_NUM(ROUTE_1),
		.landMonsInfo = &gRoute1_LandMonsMorningInfo,
		.waterMonsInfo = &gRoute1_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute1_FishingMonsInfo,
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
		.mapGroup = MAP_GROUP(ROUTE_11),
		.mapNum = MAP_NUM(ROUTE_11),
		.landMonsInfo = &gRoute11_LandMonsMorningInfo,
		.waterMonsInfo = &gRoute11_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute11_FishingMonsInfo,
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

	// Cities
	{
		.mapGroup = MAP_GROUP(PALLET_TOWN),
		.mapNum = MAP_NUM(PALLET_TOWN),
		.landMonsInfo = NULL,
		.waterMonsInfo = &gPalletTown_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gPalletTown_FishingMonsInfo,
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
		.mapGroup = MAP_GROUP(PEWTER_CITY),
		.mapNum = MAP_NUM(PEWTER_CITY),
		.landMonsInfo = &gPewterCity_LandMonsMorningInfo,
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

	// Others
	{
		.mapGroup = MAP_GROUP(VIRIDIAN_FOREST),
		.mapNum = MAP_NUM(VIRIDIAN_FOREST),
		.landMonsInfo = &gViridianForest_LandMonsMorningInfo,
		.waterMonsInfo = &gViridianForest_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gViridianForest_FishingMonsInfo,
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
		.mapGroup = MAP_GROUP(SSANNE_EXTERIOR),
		.mapNum = MAP_NUM(SSANNE_EXTERIOR),
		.landMonsInfo = NULL,
		.waterMonsInfo = &gSSAnne_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gSSAnne_FishingMonsInfo,
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

	// Default
	{
		.mapGroup = 0xFF,
		.mapNum = 0xFF,
		.landMonsInfo = NULL,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
	}
};

const struct WildPokemonHeader gWildMonNightHeaders[] =
{
	// Routes
	{
		.mapGroup = MAP_GROUP(ROUTE_1),
		.mapNum = MAP_NUM(ROUTE_1),
		.landMonsInfo = &gRoute1_LandMonsNightInfo,
		.waterMonsInfo = &gRoute1_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute1_FishingMonsInfo,
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
		.mapGroup = MAP_GROUP(ROUTE_11),
		.mapNum = MAP_NUM(ROUTE_11),
		.landMonsInfo = &gRoute11_LandMonsNightInfo,
		.waterMonsInfo = &gRoute11_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gRoute11_FishingMonsInfo,
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

	// Cities
	{
		.mapGroup = MAP_GROUP(PALLET_TOWN),
		.mapNum = MAP_NUM(PALLET_TOWN),
		.landMonsInfo = NULL,
		.waterMonsInfo = &gPalletTown_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gPalletTown_FishingMonsInfo,
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
		.mapGroup = MAP_GROUP(PEWTER_CITY),
		.mapNum = MAP_NUM(PEWTER_CITY),
		.landMonsInfo = &gPewterCity_LandMonsNightInfo,
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

	// Other
	{
		.mapGroup = MAP_GROUP(VIRIDIAN_FOREST),
		.mapNum = MAP_NUM(VIRIDIAN_FOREST),
		.landMonsInfo = &gViridianForest_LandMonsNightInfo,
		.waterMonsInfo = &gViridianForest_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gViridianForest_FishingMonsInfo,
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
		.mapGroup = MAP_GROUP(SSANNE_EXTERIOR),
		.mapNum = MAP_NUM(SSANNE_EXTERIOR),
		.landMonsInfo = NULL,
		.waterMonsInfo = &gSSAnne_SurfMonsInfo,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = &gSSAnne_FishingMonsInfo,
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

	// Default
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
