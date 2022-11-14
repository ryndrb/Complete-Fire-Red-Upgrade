#include "../../config.h"
#include "../../../include/constants/species.h"
#include "../../../include/constants/items.h"
#include "../../../include/constants/moves.h"
#include "../../../include/constants/event_objects.h"
#include "../../../include/constants/trainer_classes.h"
#include "../../../include/new/catching.h"
#include "../../../include/new/build_pokemon.h"
#include "../../../include/battle.h"
#include "trainerids.h"

extern const u8 sTrainerName_Madeline[];

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

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Rival (Blue) Battles 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
static const struct BattleTowerSpread sRivalBattle_BlueSquirtleRoute22[] = {
	{
        .species = 				SPECIES_DRILBUR,
		.level = 				9,
	    .nature = 				NATURE_ADAMANT,
		.ability = 				FRONTIER_ABILITY_HIDDEN, // mold breaker
		.item = 				ITEM_NONE,
	    .ball = 				BALL_TYPE_GREAT_BALL,
	    .hpIv = 				31,
	    .atkIv = 				31,
	    .defIv = 				31,
	    .spdIv = 				31,
	    .spAtkIv = 				31,
	    .spDefIv = 				31,
	    .hpEv = 				0,
	    .atkEv = 				0,
	    .defEv = 				0,
	    .spdEv = 				0,
	    .spAtkEv = 				0,
	    .spDefEv = 				0,
	    .moves =
		{
								MOVE_SCRATCH,
								MOVE_NONE,
								MOVE_NONE,
								MOVE_NONE,
		},

	    .shiny = 				FALSE,
	    .forSingles = 			TRUE,
	    .forDoubles = 			FALSE,
	    .modifyMovesDoubles = 	FALSE,
	},
	{
        .species = 				SPECIES_STARLY,
		.level = 				9,
	    .nature = 				NATURE_ADAMANT,
		.ability = 				FRONTIER_ABILITY_1, // keeneye
		.item = 				ITEM_NONE,
	    .ball = 				BALL_TYPE_GREAT_BALL,
	    .hpIv = 				31,
	    .atkIv = 				31,
	    .defIv = 				31,
	    .spdIv = 				31,
	    .spAtkIv = 				31,
	    .spDefIv = 				31,
	    .hpEv = 				0,
	    .atkEv = 				0,
	    .defEv = 				0,
	    .spdEv = 				0,
	    .spAtkEv = 				0,
	    .spDefEv = 				0,
	    .moves =
		{
								MOVE_QUICKATTACK,
								MOVE_GROWL,
								MOVE_NONE,
								MOVE_NONE,
		},

	    .shiny = 				FALSE,
	    .forSingles = 			TRUE,
	    .forDoubles = 			FALSE,
	    .modifyMovesDoubles = 	FALSE,
	},
	{
        .species = 				SPECIES_SQUIRTLE,
		.level = 				10,
	    .nature = 				NATURE_IMPISH,
		.ability = 				FRONTIER_ABILITY_1, // torrent
		.item = 				ITEM_NONE,
	    .ball = 				BALL_TYPE_GREAT_BALL,
	    .hpIv = 				31,
	    .atkIv = 				31,
	    .defIv = 				31,
	    .spdIv = 				31,
	    .spAtkIv = 				31,
	    .spDefIv = 				31,
	    .hpEv = 				0,
	    .atkEv = 				0,
	    .defEv = 				0,
	    .spdEv = 				0,
	    .spAtkEv = 				0,
	    .spDefEv = 				0,
	    .moves =
		{
								MOVE_WATERGUN,
								MOVE_WITHDRAW,
								MOVE_NONE,
								MOVE_NONE,
		},

	    .shiny = 				FALSE,
	    .forSingles = 			TRUE,
	    .forDoubles = 			FALSE,
	    .modifyMovesDoubles = 	FALSE,
	},
};

static const struct BattleTowerSpread sRivalBattle_BlueBulbasaurRoute22[] = 
{
	{
        .species = 				SPECIES_DRILBUR,
		.level = 				9,
	    .nature = 				NATURE_ADAMANT,
		.ability = 				FRONTIER_ABILITY_HIDDEN, // mold breaker
		.item = 				ITEM_NONE,
	    .ball = 				BALL_TYPE_GREAT_BALL,
	    .hpIv = 				31,
	    .atkIv = 				31,
	    .defIv = 				31,
	    .spdIv = 				31,
	    .spAtkIv = 				31,
	    .spDefIv = 				31,
	    .hpEv = 				0,
	    .atkEv = 				0,
	    .defEv = 				0,
	    .spdEv = 				0,
	    .spAtkEv = 				0,
	    .spDefEv = 				0,
	    .moves =
		{
								MOVE_SCRATCH,
								MOVE_NONE,
								MOVE_NONE,
								MOVE_NONE,
		},

	    .shiny = 				FALSE,
	    .forSingles = 			TRUE,
	    .forDoubles = 			FALSE,
	    .modifyMovesDoubles = 	FALSE,
	},
	{
        .species = 				SPECIES_STARLY,
		.level = 				9,
	    .nature = 				NATURE_ADAMANT,
		.ability = 				FRONTIER_ABILITY_1, // keeneye
		.item = 				ITEM_NONE,
	    .ball = 				BALL_TYPE_GREAT_BALL,
	    .hpIv = 				31,
	    .atkIv = 				31,
	    .defIv = 				31,
	    .spdIv = 				31,
	    .spAtkIv = 				31,
	    .spDefIv = 				31,
	    .hpEv = 				0,
	    .atkEv = 				0,
	    .defEv = 				0,
	    .spdEv = 				0,
	    .spAtkEv = 				0,
	    .spDefEv = 				0,
	    .moves =
		{
								MOVE_QUICKATTACK,
								MOVE_GROWL,
								MOVE_NONE,
								MOVE_NONE,
		},

	    .shiny = 				FALSE,
	    .forSingles = 			TRUE,
	    .forDoubles = 			FALSE,
	    .modifyMovesDoubles = 	FALSE,
	},
	{
        .species = 				SPECIES_BULBASAUR,
		.level = 				10,
	    .nature = 				NATURE_IMPISH,
		.ability = 				FRONTIER_ABILITY_1, // overgrow
		.item = 				ITEM_NONE,
	    .ball = 				BALL_TYPE_GREAT_BALL,
	    .hpIv = 				31,
	    .atkIv = 				31,
	    .defIv = 				31,
	    .spdIv = 				31,
	    .spAtkIv = 				31,
	    .spDefIv = 				31,
	    .hpEv = 				0,
	    .atkEv = 				0,
	    .defEv = 				0,
	    .spdEv = 				0,
	    .spAtkEv = 				0,
	    .spDefEv = 				0,
	    .moves =
		{
								MOVE_VINEWHIP,
								MOVE_LEECHSEED,
								MOVE_NONE,
								MOVE_NONE,
		},

	    .shiny = 				FALSE,
	    .forSingles = 			TRUE,
	    .forDoubles = 			FALSE,
	    .modifyMovesDoubles = 	FALSE,
	},
};

static const struct BattleTowerSpread sRivalBattle_BlueCharmanderRoute22[] = 
{
	{
        .species = 				SPECIES_DRILBUR,
		.level = 				9,
	    .nature = 				NATURE_ADAMANT,
		.ability = 				FRONTIER_ABILITY_HIDDEN, // mold breaker
		.item = 				ITEM_NONE,
	    .ball = 				BALL_TYPE_GREAT_BALL,
	    .hpIv = 				31,
	    .atkIv = 				31,
	    .defIv = 				31,
	    .spdIv = 				31,
	    .spAtkIv = 				31,
	    .spDefIv = 				31,
	    .hpEv = 				0,
	    .atkEv = 				0,
	    .defEv = 				0,
	    .spdEv = 				0,
	    .spAtkEv = 				0,
	    .spDefEv = 				0,
	    .moves =
		{
								MOVE_SCRATCH,
								MOVE_NONE,
								MOVE_NONE,
								MOVE_NONE,
		},

	    .shiny = 				FALSE,
	    .forSingles = 			TRUE,
	    .forDoubles = 			FALSE,
	    .modifyMovesDoubles = 	FALSE,
	},
	{
        .species = 				SPECIES_STARLY,
		.level = 				9,
	    .nature = 				NATURE_ADAMANT,
		.ability = 				FRONTIER_ABILITY_1, // keeneye
		.item = 				ITEM_NONE,
	    .ball = 				BALL_TYPE_GREAT_BALL,
	    .hpIv = 				31,
	    .atkIv = 				31,
	    .defIv = 				31,
	    .spdIv = 				31,
	    .spAtkIv = 				31,
	    .spDefIv = 				31,
	    .hpEv = 				0,
	    .atkEv = 				0,
	    .defEv = 				0,
	    .spdEv = 				0,
	    .spAtkEv = 				0,
	    .spDefEv = 				0,
	    .moves =
		{
								MOVE_QUICKATTACK,
								MOVE_GROWL,
								MOVE_NONE,
								MOVE_NONE,
		},

	    .shiny = 				FALSE,
	    .forSingles = 			TRUE,
	    .forDoubles = 			FALSE,
	    .modifyMovesDoubles = 	FALSE,
	},
	{
        .species = 				SPECIES_CHARMANDER,
		.level = 				10,
	    .nature = 				NATURE_TIMID,
		.ability = 				FRONTIER_ABILITY_1, // blaze
		.item = 				ITEM_NONE,
	    .ball = 				BALL_TYPE_GREAT_BALL,
	    .hpIv = 				31,
	    .atkIv = 				31,
	    .defIv = 				31,
	    .spdIv = 				31,
	    .spAtkIv = 				31,
	    .spDefIv = 				31,
	    .hpEv = 				0,
	    .atkEv = 				0,
	    .defEv = 				0,
	    .spdEv = 				0,
	    .spAtkEv = 				0,
	    .spDefEv = 				0,
	    .moves =
		{
								MOVE_EMBER,
								MOVE_SCRATCH,
								MOVE_NONE,
								MOVE_NONE,
		},

	    .shiny = 				FALSE,
	    .forSingles = 			TRUE,
	    .forDoubles = 			FALSE,
	    .modifyMovesDoubles = 	FALSE,
	},
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Gym Leader Battles 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
static const struct BattleTowerSpread sGymBattle_Brock[] = 
{
	{
        .species = 				SPECIES_ARON,
		.level = 				15,
	    .nature = 				NATURE_IMPISH,
		.ability = 				FRONTIER_ABILITY_1, // STURDY
		.item = 				ITEM_NONE,
	    .ball = 				BALL_TYPE_GREAT_BALL,
	    .hpIv = 				31,
	    .atkIv = 				31,
	    .defIv = 				31,
	    .spdIv = 				31,
	    .spAtkIv = 				31,
	    .spDefIv = 				31,
	    .hpEv = 				0,
	    .atkEv = 				0,
	    .defEv = 				0,
	    .spdEv = 				0,
	    .spAtkEv = 				0,
	    .spDefEv = 				0,
	    .moves =
		{
								MOVE_STEALTHROCK,
								MOVE_ROCKTOMB,
								MOVE_ROAR,
								MOVE_NONE,
		},

	    .shiny = 				FALSE,
	    .forSingles = 			TRUE,
	    .forDoubles = 			FALSE,
	    .modifyMovesDoubles = 	FALSE,
	},
	{
        .species = 				SPECIES_GEODUDE_A,
		.level = 				15,
	    .nature = 				NATURE_ADAMANT,
		.ability = 				FRONTIER_ABILITY_2, // STURDY
		.item = 				ITEM_NONE,
	    .ball = 				BALL_TYPE_GREAT_BALL,
	    .hpIv = 				31,
	    .atkIv = 				31,
	    .defIv = 				31,
	    .spdIv = 				31,
	    .spAtkIv = 				31,
	    .spDefIv = 				31,
	    .hpEv = 				0,
	    .atkEv = 				0,
	    .defEv = 				0,
	    .spdEv = 				0,
	    .spAtkEv = 				0,
	    .spDefEv = 				0,
	    .moves =
		{
								MOVE_SPARK,
								MOVE_TACKLE,
								MOVE_ROLLOUT,
								MOVE_NONE,
		},

	    .shiny = 				FALSE,
	    .forSingles = 			TRUE,
	    .forDoubles = 			FALSE,
	    .modifyMovesDoubles = 	FALSE,
	},
	{
        .species = 				SPECIES_DWEBBLE,
		.level = 				15,
	    .nature = 				NATURE_IMPISH,
		.ability = 				FRONTIER_ABILITY_HIDDEN, // weakarmor
		.item = 				ITEM_NONE,
	    .ball = 				BALL_TYPE_GREAT_BALL,
	    .hpIv = 				31,
	    .atkIv = 				31,
	    .defIv = 				31,
	    .spdIv = 				31,
	    .spAtkIv = 				31,
	    .spDefIv = 				31,
	    .hpEv = 				0,
	    .atkEv = 				0,
	    .defEv = 				0,
	    .spdEv = 				0,
	    .spAtkEv = 				0,
	    .spDefEv = 				0,
	    .moves =
		{
								MOVE_FURYCUTTER,
								MOVE_SMACKDOWN,
								MOVE_NONE,
								MOVE_NONE,
		},

	    .shiny = 				FALSE,
	    .forSingles = 			TRUE,
	    .forDoubles = 			FALSE,
	    .modifyMovesDoubles = 	FALSE,
	},
	{
        .species = 				SPECIES_LILEEP,
		.level = 				15,
	    .nature = 				NATURE_QUIET,
		.ability = 				FRONTIER_ABILITY_HIDDEN, // storm drain
		.item = 				ITEM_NONE,
	    .ball = 				BALL_TYPE_GREAT_BALL,
	    .hpIv = 				31,
	    .atkIv = 				31,
	    .defIv = 				31,
	    .spdIv = 				31,
	    .spAtkIv = 				31,
	    .spDefIv = 				31,
	    .hpEv = 				0,
	    .atkEv = 				0,
	    .defEv = 				0,
	    .spdEv = 				0,
	    .spAtkEv = 				0,
	    .spDefEv = 				0,
	    .moves =
		{
								MOVE_CONFUSERAY,
								MOVE_GIGADRAIN,
								MOVE_INGRAIN,
								MOVE_ATTRACT,
		},

	    .shiny = 				FALSE,
	    .forSingles = 			TRUE,
	    .forDoubles = 			FALSE,
	    .modifyMovesDoubles = 	FALSE,
	},
	{
        .species = 				SPECIES_ONIX,
		.level = 				15,
	    .nature = 				NATURE_QUIET,
		.ability = 				FRONTIER_ABILITY_1, // sturdy
		.item = 				ITEM_NONE,
	    .ball = 				BALL_TYPE_GREAT_BALL,
	    .hpIv = 				31,
	    .atkIv = 				31,
	    .defIv = 				31,
	    .spdIv = 				31,
	    .spAtkIv = 				31,
	    .spDefIv = 				31,
	    .hpEv = 				0,
	    .atkEv = 				0,
	    .defEv = 				0,
	    .spdEv = 				0,
	    .spAtkEv = 				0,
	    .spDefEv = 				0,
	    .moves =
		{
								MOVE_SMACKDOWN,
								MOVE_BIND,
								MOVE_SANDSTORM,
								MOVE_TAUNT,
		},

	    .shiny = 				FALSE,
	    .forSingles = 			TRUE,
	    .forDoubles = 			FALSE,
	    .modifyMovesDoubles = 	FALSE,
	},
	{
        .species = 				SPECIES_ARCHEN,
		.level = 				16,
	    .nature = 				NATURE_JOLLY,
		.ability = 				FRONTIER_ABILITY_1, // defeatist
		.item = 				ITEM_NONE,
	    .ball = 				BALL_TYPE_GREAT_BALL,
	    .hpIv = 				31,
	    .atkIv = 				31,
	    .defIv = 				31,
	    .spdIv = 				31,
	    .spAtkIv = 				31,
	    .spDefIv = 				31,
	    .hpEv = 				0,
	    .atkEv = 				0,
	    .defEv = 				0,
	    .spdEv = 				0,
	    .spAtkEv = 				0,
	    .spDefEv = 				0,
	    .moves =
		{
								MOVE_WINGATTACK,
								MOVE_ROCKTHROW,
								MOVE_NONE,
								MOVE_NONE,
		},

	    .shiny = 				FALSE,
	    .forSingles = 			TRUE,
	    .forDoubles = 			FALSE,
	    .modifyMovesDoubles = 	FALSE,
	},
};

static const struct BattleTowerSpread sGymBattle_Misty[] = 
{
	{
		.species = SPECIES_PELIPPER,
		.nature = NATURE_BOLD,
		.level = 25,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 0,
        .atkEv = 0,
		.defEv = 0,
		.spAtkEv = 0,
		.spDefEv = 0,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_HIDDEN, // DRIZZLE
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_SCALD,
			MOVE_ROOST,
			MOVE_AIRCUTTER,
			MOVE_UTURN,
		},
		.ball = BALL_TYPE_GREAT_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_AZUMARILL,
		.nature = NATURE_ADAMANT,
		.level = 25,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 0,
        .atkEv = 0,
		.defEv = 0,
		.spAtkEv = 0,
		.spDefEv = 0,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_2, // HUGE POWER
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_AQUAJET,
			MOVE_SLAM,
			MOVE_REST,
			MOVE_SLEEPTALK,
		},
		.ball = BALL_TYPE_GREAT_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_MARSHTOMP,
		.nature = NATURE_RELAXED,
		.level = 25,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 0,
        .atkEv = 0,
		.defEv = 0,
		.spAtkEv = 0,
		.spDefEv = 0,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_2, // STAMINA
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_STEALTHROCK,
			MOVE_BARRIER,
			MOVE_YAWN,
			MOVE_BULLDOZE,
		},
		.ball = BALL_TYPE_GREAT_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_FROGADIER,
		.nature = NATURE_ADAMANT,
		.level = 25,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 0,
        .atkEv = 0,
		.defEv = 0,
		.spAtkEv = 0,
		.spDefEv = 0,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_HIDDEN, // PROTEAN
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_TOXICSPIKES,
			MOVE_SCALD,
			MOVE_PROTECT,
			MOVE_UTURN,
		},
		.ball = BALL_TYPE_GREAT_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_BIBAREL,
		.nature = NATURE_ADAMANT,
		.level = 25,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 0,
        .atkEv = 0,
		.defEv = 0,
		.spAtkEv = 0,
		.spDefEv = 0,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_2, // UNAWARE
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_QUICKATTACK,
			MOVE_AQUAJET,
			MOVE_REST,
			MOVE_WORKUP,
		},
		.ball = BALL_TYPE_GREAT_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_STARMIE,
		.nature = NATURE_MODEST,
		.level = 25,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 0,
        .atkEv = 0,
		.defEv = 0,
		.spAtkEv = 0,
		.spDefEv = 0,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_2, // NATURAL CURE
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_SCALD,
			MOVE_RECOVER,
			MOVE_POWERGEM,
			MOVE_PSYBEAM,
		},
		.ball = BALL_TYPE_GREAT_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
};

const struct MultiRaidTrainer gImportantTrainers[] = 
{
	{
		.owNum = EVENT_OBJ_GFX_BRENDAN,
		.trainerClass = CLASS_PKMN_TRAINER_1,
		.backSpriteId = SINGLE_BATTLE,
		.gender = MALE,
		.otId = TRAINER_RIVAL_ROUTE22_EARLY_SQUIRTLE,
		.name = sTrainerName_Madeline,
		.spreads =
		{
			[0] =	 sRivalBattle_BlueSquirtleRoute22,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sRivalBattle_BlueSquirtleRoute22),
		},
    },
	{
		.owNum = EVENT_OBJ_GFX_BRENDAN,
		.trainerClass = CLASS_PKMN_TRAINER_1,
		.backSpriteId = SINGLE_BATTLE,
		.gender = MALE,
		.otId = TRAINER_RIVAL_ROUTE22_EARLY_BULBASAUR,
		.name = sTrainerName_Madeline,
		.spreads =
		{
			[0] =	 sRivalBattle_BlueBulbasaurRoute22,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sRivalBattle_BlueBulbasaurRoute22),
		},
    },
	{
		.owNum = EVENT_OBJ_GFX_BRENDAN,
		.trainerClass = CLASS_PKMN_TRAINER_1,
		.backSpriteId = SINGLE_BATTLE,
		.gender = MALE,
		.otId = TRAINER_RIVAL_ROUTE22_EARLY_CHARMANDER,
		.name = sTrainerName_Madeline,
		.spreads =
		{
			[0] =	 sRivalBattle_BlueCharmanderRoute22,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sRivalBattle_BlueCharmanderRoute22),
		},
    },
	{
		.owNum = EVENT_OBJ_GFX_BRENDAN,
		.trainerClass = CLASS_PKMN_TRAINER_1,
		.backSpriteId = SINGLE_BATTLE,
		.gender = MALE,
		.otId = TRAINER_LEADER_BROCK,
		.name = sTrainerName_Madeline,
		.spreads =
		{
			[0] =	 sGymBattle_Brock,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sGymBattle_Brock),
		},
    },
	{
		.owNum = EVENT_OBJ_GFX_BRENDAN,
		.trainerClass = CLASS_PKMN_TRAINER_1,
		.backSpriteId = SINGLE_BATTLE,
		.gender = FEMALE,
		.otId = TRAINER_LEADER_MISTY,
		.name = sTrainerName_Madeline,
		.spreads =
		{
			[0] =	 sGymBattle_Misty,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sGymBattle_Misty),
		},
    },
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

const u8 gNumImportantTrainers = NELEMS(gImportantTrainers);