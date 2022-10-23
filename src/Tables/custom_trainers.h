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

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Rival (Blue) Battles 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
static const struct BattleTowerSpread sRivalBattle_BlueSquirtleRoute22[] = {
	{
		.species = SPECIES_DRILBUR,
		.nature = NATURE_ADAMANT,
		.level = 9,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 8,
        .atkEv = 0,
		.defEv = 0,
		.spAtkEv = 0,
		.spDefEv = 0,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_HIDDEN, // mold breaker
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_SCRATCH,
			MOVE_NONE,
			MOVE_NONE,
			MOVE_NONE,
		},
		.ball = BALL_TYPE_POKE_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_STARLY,
		.nature = NATURE_ADAMANT,
		.level = 9,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 0,
        .atkEv = 8,
		.defEv = 0,
		.spAtkEv = 0,
		.spDefEv = 0,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_1, // keen eye
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_QUICKATTACK,
			MOVE_GROWL,
			MOVE_NONE,
			MOVE_NONE,
		},
		.ball = BALL_TYPE_POKE_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_SQUIRTLE,
		.nature = NATURE_BOLD,
		.level = 10,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 0,
        .atkEv = 0,
		.defEv = 8,
		.spAtkEv = 0,
		.spDefEv = 0,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_1, // torrent
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_WITHDRAW,
			MOVE_WATERGUN,
			MOVE_NONE,
			MOVE_NONE,
		},
		.ball = BALL_TYPE_POKE_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
};

static const struct BattleTowerSpread sRivalBattle_BlueBulbasaurRoute22[] = {
	{
		.species = SPECIES_DRILBUR,
		.nature = NATURE_ADAMANT,
		.level = 9,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 8,
        .atkEv = 0,
		.defEv = 0,
		.spAtkEv = 0,
		.spDefEv = 0,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_HIDDEN, // mold breaker
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_SCRATCH,
			MOVE_NONE,
			MOVE_NONE,
			MOVE_NONE,
		},
		.ball = BALL_TYPE_POKE_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_STARLY,
		.nature = NATURE_ADAMANT,
		.level = 9,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 0,
        .atkEv = 8,
		.defEv = 0,
		.spAtkEv = 0,
		.spDefEv = 0,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_1, // keen eye
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_QUICKATTACK,
			MOVE_GROWL,
			MOVE_NONE,
			MOVE_NONE,
		},
		.ball = BALL_TYPE_POKE_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_BULBASAUR,
		.nature = NATURE_IMPISH,
		.level = 10,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 0,
        .atkEv = 0,
		.defEv = 8,
		.spAtkEv = 0,
		.spDefEv = 0,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_1, // overgrow
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_VINEWHIP,
			MOVE_LEECHSEED,
			MOVE_NONE,
			MOVE_NONE,
		},
		.ball = BALL_TYPE_POKE_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
};

static const struct BattleTowerSpread sRivalBattle_BlueCharmanderRoute22[] = {
	{
		.species = SPECIES_DRILBUR,
		.nature = NATURE_ADAMANT,
		.level = 9,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 8,
        .atkEv = 0,
		.defEv = 0,
		.spAtkEv = 0,
		.spDefEv = 0,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_HIDDEN, // mold breaker
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_SCRATCH,
			MOVE_NONE,
			MOVE_NONE,
			MOVE_NONE,
		},
		.ball = BALL_TYPE_POKE_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_STARLY,
		.nature = NATURE_ADAMANT,
		.level = 9,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 0,
        .atkEv = 8,
		.defEv = 0,
		.spAtkEv = 0,
		.spDefEv = 0,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_1, // keen eye
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_QUICKATTACK,
			MOVE_GROWL,
			MOVE_NONE,
			MOVE_NONE,
		},
		.ball = BALL_TYPE_POKE_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_CHARMANDER,
		.nature = NATURE_TIMID,
		.level = 10,
		.hpIv = 31,
		.atkIv = 31,
		.defIv = 31,
		.spAtkIv = 31,
		.spDefIv = 31,
		.spdIv = 31,
		.hpEv = 0,
        .atkEv = 0,
		.defEv = 0,
		.spAtkEv = 8,
		.spDefEv = 0,
        .spdEv = 0,
		.ability = FRONTIER_ABILITY_1, // blaze
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_EMBER,
			MOVE_SCRATCH,
			MOVE_NONE,
			MOVE_NONE,
		},
		.ball = BALL_TYPE_POKE_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Gym Leader Battles 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
static const struct BattleTowerSpread sGymBattle_Brock[] = 
{
	{
		.species = SPECIES_ARON,
		.nature = NATURE_IMPISH,
		.level = 15,
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
		.ability = FRONTIER_ABILITY_1, // STURDY
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_STEALTHROCK,
			MOVE_ROCKTOMB,
			MOVE_ROAR,
			MOVE_NONE,
		},
		.ball = BALL_TYPE_HEAVY_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_GEODUDE_A,
		.nature = NATURE_ADAMANT,
		.level = 15,
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
		.ability = FRONTIER_ABILITY_2, // STURDY
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_SPARK,
			MOVE_TACKLE,
			MOVE_ROLLOUT,
			MOVE_NONE,
		},
		.ball = BALL_TYPE_HEAVY_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_DWEBBLE,
		.nature = NATURE_IMPISH,
		.level = 15,
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
		.ability = FRONTIER_ABILITY_HIDDEN, // WEAK ARMOR
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_FURYCUTTER,
			MOVE_SMACKDOWN,
			MOVE_NONE,
			MOVE_NONE,
		},
		.ball = BALL_TYPE_FRIEND_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_LILEEP,
		.nature = NATURE_QUIET,
		.level = 15,
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
		.ability = FRONTIER_ABILITY_HIDDEN, // STORM DRAIN
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_CONFUSERAY,
			MOVE_GIGADRAIN,
			MOVE_INGRAIN,
			MOVE_ATTRACT,
		},
		.ball = BALL_TYPE_FRIEND_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_ONIX,
		.nature = NATURE_QUIET,
		.level = 15,
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
		.ability = FRONTIER_ABILITY_1, // STURDY
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_SMACKDOWN,
			MOVE_BIND,
			MOVE_SANDSTORM,
			MOVE_TAUNT,
		},
		.ball = BALL_TYPE_HEAVY_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	},
	{
		.species = SPECIES_ARCHEN,
		.nature = NATURE_JOLLY,
		.level = 15,
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
		.ability = FRONTIER_ABILITY_1, // DEFEATIST
		.item = ITEM_NONE,
		.moves =
		{
			MOVE_WINGATTACK,
			MOVE_ROCKTHROW,
			MOVE_NONE,
			MOVE_NONE,
		},
		.ball = BALL_TYPE_LEVEL_BALL,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.modifyMovesDoubles = FALSE,
	}
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

extern const u8 sTrainerName_Madeline[];

const struct MultiRaidTrainer gCustomTrainerBattles[] = 
{
	{
		.owNum = EVENT_OBJ_GFX_BRENDAN,
		.trainerClass = CLASS_PKMN_TRAINER_1,
		.backSpriteId = SINGLE_BATTLE,
		.gender = MALE,
		.otId = 0x149,
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
		.otId = 0x14A,
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
		.otId = 0x14B,
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
		.otId = 0x19E,
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
		.otId = 0x19F,
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

const u8 gNumCustomTrainerBattles = NELEMS(gCustomTrainerBattles);