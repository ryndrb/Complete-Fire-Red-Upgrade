#include "../../../../include/constants/species.h"
#include "../../../../include/constants/items.h"
#include "../../../../include/constants/flags.h"
#include "../../../../include/constants/moves.h"
#include "../../../../include/constants/event_objects.h"
#include "../../../../include/constants/trainer_classes.h"

#include "../../../../include/new/catching.h"
#include "../../../../include/new/frontier.h"
#include "../../../../include/new/build_pokemon.h"

#include "../../../../include/battle.h"
extern const u8 sTrainerName_Madeline[];

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Celadon Rocket Hideout Battle
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
static const struct BattleTowerSpread sTeam_JessieJames_RocketHQ[] = 
{
    {
		.species = SPECIES_JELLICENT_F,
		.nature = NATURE_BOLD,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 31, .defIv = 31, .spAtkIv = 31, .spDefIv = 31, .spdIv = 31,
		.hpEv = 252, .atkEv = 0, .defEv = 252, .spAtkEv = 0, .spDefEv = 4, .spdEv = 0,
		.item = ITEM_COLBUR_BERRY,
		.moves ={MOVE_RECOVER, MOVE_TAUNT, MOVE_WILLOWISP, MOVE_STRENGTHSAP},
		.shiny = 0,
		.forSingles = FALSE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_HIDDEN, // water bubble
	},
    {
		.species = SPECIES_MORPEKO,
		.nature = NATURE_ADAMANT,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 31, .defIv = 31, .spAtkIv = 31, .spDefIv = 31, .spdIv = 31,
		.hpEv = 0, .atkEv = 252, .defEv = 0, .spAtkEv = 0, .spDefEv = 4, .spdEv = 252,
		.item = ITEM_LIFE_ORB,
		.moves ={MOVE_PSYCHICFANGS, MOVE_PARTINGSHOT, MOVE_FAKEOUT, MOVE_SEEDBOMB},
		.shiny = 0,
		.forSingles = FALSE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_HIDDEN, // hunger switch
	},
    {
		.species = SPECIES_ZANGOOSE,
		.nature = NATURE_JOLLY,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 31, .defIv = 31, .spAtkIv = 31, .spDefIv = 31, .spdIv = 31,
		.hpEv = 0, .atkEv = 252, .defEv = 0, .spAtkEv = 0, .spDefEv = 4, .spdEv = 252,
		.item = ITEM_LEFTOVERS,
		.moves ={MOVE_KNOCKOFF, MOVE_SWORDSDANCE, MOVE_QUICKATTACK, MOVE_PROTECT},
		.shiny = 0,
		.forSingles = FALSE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_1, // tough claws
	},
    {
		.species = SPECIES_SEVIPER,
		.nature = NATURE_JOLLY,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 31, .defIv = 31, .spAtkIv = 31, .spDefIv = 31, .spdIv = 31,
		.hpEv = 0, .atkEv = 0, .defEv = 0, .spAtkEv = 252, .spDefEv = 4, .spdEv = 252,
		.item = ITEM_LEFTOVERS,
		.moves ={MOVE_SLUDGEWAVE, MOVE_GIGADRAIN, MOVE_FLAMETHROWER, MOVE_PROTECT},
		.shiny = 0,
		.forSingles = FALSE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_HIDDEN, // fatal precision
	},
    {
		.species = SPECIES_BEWEAR,
		.nature = NATURE_IMPISH,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 31, .defIv = 31, .spAtkIv = 31, .spDefIv = 31, .spdIv = 31,
		.hpEv = 252, .atkEv = 252, .defEv = 4, .spAtkEv = 0, .spDefEv = 0, .spdEv = 0,
		.item = ITEM_ASSAULT_VEST,
		.moves ={MOVE_PLAYROUGH, MOVE_STOMPINGTANTRUM, MOVE_THUNDERPUNCH, MOVE_ICEPUNCH},
		.shiny = 0,
		.forSingles = FALSE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_2, // intimidate
	},
    {
		.species = SPECIES_YANMEGA,
		.nature = NATURE_MODEST,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 31, .defIv = 31, .spAtkIv = 31, .spDefIv = 31, .spdIv = 31,
		.hpEv = 0, .atkEv = 0, .defEv = 0, .spAtkEv = 252, .spDefEv = 4, .spdEv = 252,
		.item = ITEM_LIFE_ORB,
		.moves ={MOVE_BUGBUZZ, MOVE_GIGADRAIN, MOVE_AIRSLASH, MOVE_PROTECT},
		.shiny = 0,
		.forSingles = FALSE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_1, // speed boost
	},
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Set IDs
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct MultiRaidTrainer gTeamRocketGangBattles[] = 
{
    {
		.owNum = EVENT_OBJ_GFX_GIOVANNI,
		.trainerClass = CLASS_TEAM_ROCKET,
		.backSpriteId = DOUBLE_BATTLE,
		.gender = MALE,
		.otId = 10,
		.name = sTrainerName_Madeline,
		.spreads =
		{
			[0] =	 sTeam_JessieJames_RocketHQ,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sTeam_JessieJames_RocketHQ),
		},
    },
};