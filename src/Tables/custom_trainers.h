#include "../config.h"
#include "../../include/constants/species.h"
#include "../../include/constants/items.h"
#include "../../include/constants/moves.h"
#include "../../include/new/build_pokemon.h"

// Sample trainer builder for now
static const struct BattleTowerSpread sDifficult_TestBattle[] = 
{
    {
		.species = SPECIES_MEW,
		.nature = NATURE_ADAMANT,
		.level = 100,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
        .hpEv = 120,
        .atkEv = 252,
        .spdEv = 136,
		.ability = FRONTIER_ABILITY_1, //ABILITY_SYNCHRONIZE
		.item = ITEM_COLBUR_BERRY,
		.moves =
		{
			MOVE_STEALTHROCK,
			MOVE_GRAVITY,
			MOVE_CLOSECOMBAT,
			MOVE_EXPLOSION,
		},
		.ball = BALL_TYPE_GREAT_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_LANDORUS_THERIAN,
		.nature = NATURE_NAUGHTY,
		.level = 100,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
        .hpEv = 8,
        .atkEv = 252,
        .spdEv = 248,
		.ability = FRONTIER_ABILITY_1, //intimidate
		.item = ITEM_CHOICE_BAND,
		.moves =
		{
			MOVE_EARTHQUAKE,
			MOVE_STONEEDGE,
			MOVE_UTURN,
			MOVE_DEFOG,
		},
		.ball = BALL_TYPE_GREAT_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_DURANT,
		.nature = NATURE_JOLLY,
		.level = 100,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 0,
        .atkEv = 252,
		.defEv = 0,
		.spAtkEv = 0,
		.spDefEv = 4,
        .spdEv = 252,
		.ability = FRONTIER_ABILITY_2, //hustle
		.item = ITEM_LIFE_ORB,
		.moves =
		{
			MOVE_FIRSTIMPRESSION,
			MOVE_IRONHEAD,
			MOVE_ROCKSLIDE,
			MOVE_STOMPINGTANTRUM,
		},
		.ball = BALL_TYPE_GREAT_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
		{
		.species = SPECIES_PORYGON2,
		.nature = NATURE_CALM,
		.level = 100,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 232,
        .atkEv = 0,
		.defEv = 176,
		.spAtkEv = 56,
		.spDefEv = 44,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_HIDDEN, //anylitic
		.item = ITEM_EVIOLITE,
		.moves =
		{
			MOVE_GRAVITY,
			MOVE_TELEPORT,
			MOVE_BLIZZARD,
			MOVE_ZAPCANNON,
		},
		.ball = BALL_TYPE_GREAT_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
		{
		.species = SPECIES_THUNDURUS_THERIAN,
		.nature = NATURE_TIMID,
		.level = 100,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 8,
        .atkEv = 0,
		.defEv = 0,
		.spAtkEv = 252,
		.spDefEv = 0,
        .spdEv = 248,
		.ability = FRONTIER_ABILITY_1, //volt absorb
		.item = ITEM_CHOICE_SCARF,
		.moves =
		{
			MOVE_THUNDER,
			MOVE_FOCUSBLAST,
			MOVE_UTURN,
			MOVE_SLUDGEWAVE,
		},
		.ball = BALL_TYPE_GREAT_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
		{
		.species = SPECIES_POLIWRATH,
		.nature = NATURE_BOLD,
		.level = 100,
		.hpIv = 31,
		.atkIv = 0,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 248,
        .atkEv = 0,
		.defEv = 252,
		.spAtkEv = 8,
		.spDefEv = 0,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_1, //water absorb
		.item = ITEM_LIFE_ORB,
		.moves =
		{
			MOVE_HYDROPUMP,
			MOVE_FOCUSBLAST,
			MOVE_BLIZZARD,
			MOVE_HYPNOSIS,
		},
		.ball = BALL_TYPE_GREAT_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	}
};

extern const u8 sTrainerName_Madeline[];

const struct MultiRaidTrainer gCustomTrainerBattles[] = 
{
    {
		.owNum = EVENT_OBJ_GFX_AROMA_LADY,
		.trainerClass = CLASS_AROMA_LADY,
		.backSpriteId = SINGLE_BATTLE,
		.gender = FEMALE,
		.otId = 0x04,
		.name = sTrainerName_Madeline,
		.spreads =
		{
			[0] =	 sDifficult_TestBattle,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sDifficult_TestBattle),
		},
    }
};

const u8 gNumCustomTrainerBattles = NELEMS(gCustomTrainerBattles);