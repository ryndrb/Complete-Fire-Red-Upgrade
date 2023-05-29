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
//@@ Silph Co. Ariana
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
static const struct BattleTowerSpread sTeam_Ariana_SilphCo[] = 
{
    {
		.species = SPECIES_CORVIKNIGHT,
		.nature = NATURE_CAREFUL,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 31, .defIv = 31, .spAtkIv = 31, .spDefIv = 31, .spdIv = 31,
		.hpEv = 248, .atkEv = 0, .defEv = 8, .spAtkEv = 0, .spDefEv = 252, .spdEv = 0,
		.item = ITEM_LEFTOVERS,
		.moves ={MOVE_BRAVEBIRD, MOVE_UTURN, MOVE_ROOST, MOVE_TAILWIND},
		.shiny = 1,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_1, // pressure
	},
    {
		.species = SPECIES_GARCHOMP,
		.nature = NATURE_JOLLY,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 30, .defIv = 30, .spAtkIv = 30, .spDefIv = 31, .spdIv = 30,
		.hpEv = 0, .atkEv = 252, .defEv = 8, .spAtkEv = 0, .spDefEv = 4, .spdEv = 252,
		.item = ITEM_CHOICE_SCARF,
		.moves ={MOVE_EARTHQUAKE, MOVE_HIDDENPOWER, MOVE_STONEEDGE, MOVE_DRAGONCLAW},
		.shiny = 0,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_HIDDEN, // rough skin
	},
    {
		.species = SPECIES_CONKELDURR,
		.nature = NATURE_ADAMANT,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 31,.defIv = 31, .spAtkIv = 31, .spDefIv = 31, .spdIv = 31,
		.hpEv = 0, .atkEv = 252, .defEv = 8, .spAtkEv = 0, .spDefEv = 4, .spdEv = 252,
		.item = ITEM_LIFE_ORB,
		.moves ={MOVE_CLOSECOMBAT, MOVE_MACHPUNCH, MOVE_ICEPUNCH, MOVE_THUNDERPUNCH},
		.shiny = 0,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_2, // sheer force
	},
    {
		.species = SPECIES_PORYGON_Z,
		.nature = NATURE_TIMID,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 30, .defIv = 31, .spAtkIv = 30, .spDefIv = 31, .spdIv = 30,
		.hpEv = 0, .atkEv = 0, .defEv = 8, .spAtkEv = 252, .spDefEv = 4, .spdEv = 252,
		.item = ITEM_CHOICE_SCARF,
		.moves ={MOVE_THUNDERBOLT, MOVE_DARKPULSE, MOVE_ICEBEAM, MOVE_HIDDENPOWER},
		.shiny = 0,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_1, // adaptability
	},
    {
		.species = SPECIES_GLISCOR,
		.nature = NATURE_JOLLY,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 31, .defIv = 31, .spAtkIv = 31, .spDefIv = 31, .spdIv = 31,
		.hpEv = 252, .atkEv = 0, .defEv = 4, .spAtkEv = 0, .spDefEv = 252, .spdEv = 0,
		.item = ITEM_TOXIC_ORB,
		.moves ={MOVE_EARTHQUAKE, MOVE_ROOST, MOVE_FACADE, MOVE_SWORDSDANCE},
		.shiny = 0,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_HIDDEN, // poison heal
	},
    {
		.species = SPECIES_GENGAR,
		.nature = NATURE_TIMID,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 1,
		.hpIv = 30, .atkIv = 30, .defIv = 31, .spAtkIv = 30, .spDefIv = 30, .spdIv = 30,
        .hpEv = 0, .atkEv = 0, .defEv = 0, .spAtkEv = 252, .spDefEv = 4, .spdEv = 252,
		.item = ITEM_GENGARITE,
		.moves ={MOVE_SHADOWBALL, MOVE_SUBSTITUTE, MOVE_NASTYPLOT, MOVE_HIDDENPOWER},
		.shiny = 0,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_1, // levitate
	},
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Set IDs
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct MultiRaidTrainer gArianaBattles[] = 
{
    {
		.owNum = EVENT_OBJ_GFX_GIOVANNI,
		.trainerClass = CLASS_BOSS,
		.backSpriteId = SINGLE_BATTLE,
		.gender = FEMALE,
		.otId = 8,
		.name = sTrainerName_Madeline,
		.spreads =
		{
			[0] =	 sTeam_Ariana_SilphCo,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sTeam_Ariana_SilphCo),
		},
    },
};