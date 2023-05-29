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
//@@ Silph Co. Proton
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
static const struct BattleTowerSpread sTeam_Proton_SilphCo[] = 
{
    {
		.species = SPECIES_TENTACRUEL,
		.nature = NATURE_TIMID,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 31, .defIv = 31, .spAtkIv = 31, .spDefIv = 31, .spdIv = 31,
		.hpEv = 252, .atkEv = 0, .defEv = 252, .spAtkEv = 0, .spDefEv = 4, .spdEv = 0,
		.item = ITEM_BLACK_SLUDGE,
		.moves ={MOVE_SCALD, MOVE_HAZE, MOVE_TOXICSPIKES, MOVE_KNOCKOFF},
		.shiny = 0,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_1, // clearbody
	},
    {
		.species = SPECIES_MISMAGIUS,
		.nature = NATURE_TIMID,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 31, .defIv = 31, .spAtkIv = 31, .spDefIv = 31, .spdIv = 31, 
        .hpEv = 0, .atkEv = 0, .defEv = 0, .spAtkEv = 252, .spDefEv = 4, .spdEv = 0,
		.item = ITEM_LIFE_ORB,
		.moves ={MOVE_SHADOWBALL, MOVE_MOONBLAST, MOVE_POWERGEM, MOVE_NASTYPLOT},
		.shiny = 0,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_1, // levitate
	},
    {
		.species = SPECIES_OBSTAGOON,
		.nature = NATURE_JOLLY,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 31, .defIv = 31, .spAtkIv = 31, .spDefIv = 31, .spdIv = 31,
		.hpEv = 0, .atkEv = 252, .defEv = 0, .spAtkEv = 0, .spDefEv = 4, .spdEv = 252,
		.item = ITEM_FLAME_ORB,
		.moves ={MOVE_KNOCKOFF, MOVE_FACADE, MOVE_ICEPUNCH, MOVE_PARTINGSHOT},
		.shiny = 0,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_2, // guts
	},
    {
		.species = SPECIES_RILLABOOM,
		.nature = NATURE_ADAMANT,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 31, .defIv = 31, .spAtkIv = 31, .spDefIv = 31, .spdIv = 31,
		.hpEv = 0, .atkEv = 252, .defEv = 0, .spAtkEv = 0, .spDefEv = 4, .spdEv = 252,
		.item = ITEM_CHOICE_BAND,
		.moves ={MOVE_GRASSYGLIDE, MOVE_KNOCKOFF, MOVE_UTURN, MOVE_DRAINPUNCH},
		.shiny = 0,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_HIDDEN, // grassy surge
	},
    {
		.species = SPECIES_SCIZOR,
		.nature = NATURE_JOLLY,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 31, .defIv = 31, .spAtkIv = 31, .spDefIv = 31, .spdIv = 31,
		.hpEv = 252, .atkEv = 0, .defEv = 0, .spAtkEv = 0, .spDefEv = 252, .spdEv = 4,
		.item = ITEM_LIFE_ORB,
		.moves ={MOVE_SWORDSDANCE, MOVE_BULLETPUNCH, MOVE_ROOST, MOVE_KNOCKOFF},
		.shiny = 0,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_2, // technician
	},
    {
		.species = SPECIES_TYRANITAR,
		.nature = NATURE_ADAMANT,
		.ball = BALL_TYPE_POKE_BALL,
		.level = 0,
		.hpIv = 31, .atkIv = 31, .defIv = 31, .spAtkIv = 31, .spDefIv = 31, .spdIv = 31,
		.hpEv = 252, .atkEv = 252, .defEv = 4, .spAtkEv = 0, .spDefEv = 4, .spdEv = 0,
		.item = ITEM_TYRANITARITE,
		.moves ={MOVE_DRAGONDANCE, MOVE_ICEPUNCH, MOVE_PURSUIT, MOVE_FIREPUNCH},
		.shiny = 0,
		.forSingles = TRUE,
		.forDoubles = TRUE,
		.ability = FRONTIER_ABILITY_1, // sand stream
	},
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Set IDs
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct MultiRaidTrainer gProtonBattles[] = 
{
    {
		.owNum = EVENT_OBJ_GFX_GIOVANNI,
		.trainerClass = CLASS_BOSS,
		.backSpriteId = SINGLE_BATTLE,
		.gender = MALE,
		.otId = 6,
		.name = sTrainerName_Madeline,
		.spreads =
		{
			[0] =	 sTeam_Proton_SilphCo,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sTeam_Proton_SilphCo),
		},
    },
};