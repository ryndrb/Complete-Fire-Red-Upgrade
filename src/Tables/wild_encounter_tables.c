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

// Test
const struct WildPokemon gRoute1_LandMonsMorning[] = 
{
	{2, 4, SPECIES_BIDOOF},//20
	{2, 4, SPECIES_ZIGZAGOON},//20
	{2, 4, SPECIES_RATTATA},//10
	{2, 4, SPECIES_MIENFOO},//10
	{2, 4, SPECIES_MEOWTH},//10
	{2, 4, SPECIES_YUNGOOS},//10
	{3, 4, SPECIES_PIDGEY},//5
	{3, 4, SPECIES_PIDGEY},//5
	{3, 5, SPECIES_SEEDOT},//4
	{3, 5, SPECIES_SEEDOT},//4
	{4, 5, SPECIES_PANSEAR},//1
	{4, 5, SPECIES_PANSEAR},//1
};
const struct WildPokemonInfo gRoute1_LandMonsMorningInfo = {21, gRoute1_LandMonsMorning};

const struct WildPokemonHeader gWildMonMorningHeaders[] =
{
	{
		.mapGroup = MAP_GROUP(ROUTE_1),
		.mapNum = MAP_NUM(ROUTE_1),
		.landMonsInfo = &gRoute1_LandMonsMorningInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
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

const struct WildPokemon gRoute1_LandMonsDusk[] = 
{
	{2, 4, SPECIES_PATRAT},//20
	{2, 4, SPECIES_ZIGZAGOON},//20
	{2, 4, SPECIES_RATTATA},//10
	{2, 4, SPECIES_MIENFOO},//10
	{2, 4, SPECIES_MEOWTH},//10
	{2, 4, SPECIES_YUNGOOS},//10
	{3, 4, SPECIES_TAILLOW},//5
	{3, 4, SPECIES_TAILLOW},//5
	{3, 5, SPECIES_SEEDOT},//4
	{3, 5, SPECIES_SEEDOT},//4
	{4, 5, SPECIES_PANSEAR},//1
	{4, 5, SPECIES_PANSEAR},//1
};
const struct WildPokemonInfo gRoute1_LandMonsDuskInfo = {21, gRoute1_LandMonsDusk};

// DUSK
const struct WildPokemonHeader gWildMonEveningHeaders[] =
{
	{
		.mapGroup = MAP_GROUP(ROUTE_1),
		.mapNum = MAP_NUM(ROUTE_1),
		.landMonsInfo = &gRoute1_LandMonsDuskInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
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

const struct WildPokemon gRoute1_LandMonsNight[] = 
{
	{2, 4, SPECIES_PATRAT},//20
	{2, 4, SPECIES_ZIGZAGOON_G},//20
	{2, 4, SPECIES_RATTATA_A},//10
	{2, 4, SPECIES_MIENFOO},//10
	{2, 4, SPECIES_MEOWTH_G},//10
	{2, 4, SPECIES_YUNGOOS},//10
	{3, 4, SPECIES_HOOTHOOT},//5
	{3, 4, SPECIES_HOOTHOOT},//5
	{3, 5, SPECIES_PURRLOIN},//4
	{3, 5, SPECIES_PURRLOIN},//4
	{4, 5, SPECIES_PANSEAR},//1
	{4, 5, SPECIES_PANSEAR},//1
};
const struct WildPokemonInfo gRoute1_LandMonsNightInfo = {21, gRoute1_LandMonsNight};

const struct WildPokemonHeader gWildMonNightHeaders[] =
{
	{
		.mapGroup = MAP_GROUP(ROUTE_1),
		.mapNum = MAP_NUM(ROUTE_1),
		.landMonsInfo = &gRoute1_LandMonsNightInfo,
		.waterMonsInfo = NULL,
		.rockSmashMonsInfo = NULL,
		.fishingMonsInfo = NULL,
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

const struct SwarmData gSwarmTable[] =
{
	/*{
		.mapName = 0xFF,
		.species = 0xFFFF,
	},*/
};

const u16 gSwarmTableLength = NELEMS(gSwarmTable);
