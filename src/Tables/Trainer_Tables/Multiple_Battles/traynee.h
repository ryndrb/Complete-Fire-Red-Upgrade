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
//@@ Route 5 Traynee
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// Traynee HP Team
static const struct BattleTowerSpread sTeam_TrayneeHP[] = 
{
    {
		.species = SPECIES_WIGGLYTUFF,
		.nature = NATURE_RELAXED,
		.ability = FRONTIER_ABILITY_2,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_WIGGLYTUFF,
		.nature = NATURE_RELAXED,
		.ability = FRONTIER_ABILITY_2,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_WIGGLYTUFF,
		.nature = NATURE_RELAXED,
		.ability = FRONTIER_ABILITY_2,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_WIGGLYTUFF,
		.nature = NATURE_RELAXED,
		.ability = FRONTIER_ABILITY_2,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_WIGGLYTUFF,
		.nature = NATURE_RELAXED,
		.ability = FRONTIER_ABILITY_2,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_WIGGLYTUFF,
		.nature = NATURE_RELAXED,
		.ability = FRONTIER_ABILITY_2,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},

};
// Traynee Attack
static const struct BattleTowerSpread sTeam_TrayneeAtt[] = 
{
    {
		.species = SPECIES_VICTREEBEL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_VICTREEBEL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_VICTREEBEL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_VICTREEBEL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_VICTREEBEL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_VICTREEBEL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},

};

// Traynee Defense
static const struct BattleTowerSpread sTeam_TrayneeDef[] = 
{
    {
		.species = SPECIES_COALOSSAL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_COALOSSAL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_COALOSSAL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_COALOSSAL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_COALOSSAL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_COALOSSAL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
};

// Traynee Sp Attack
static const struct BattleTowerSpread sTeam_TrayneeSpA[] = 
{
    {
		.species = SPECIES_BEAUTIFLY,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_BEAUTIFLY,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_BEAUTIFLY,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_BEAUTIFLY,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_BEAUTIFLY,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_BEAUTIFLY,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
};

// Traynee Sp Defense
static const struct BattleTowerSpread sTeam_TrayneeSpD[] = 
{
    {
		.species = SPECIES_DUSTOX,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_DUSTOX,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_DUSTOX,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_DUSTOX,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_DUSTOX,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_DUSTOX,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
};

// Traynee Speed
static const struct BattleTowerSpread sTeam_TrayneeSpe[] = 
{
    {
		.species = SPECIES_JUMPLUFF,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_JUMPLUFF,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_JUMPLUFF,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_JUMPLUFF,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_JUMPLUFF,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_JUMPLUFF,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0, .atkIv = 0, .defIv = 0, .spAtkIv = 0, .spDefIv = 0, .spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@ Set IDs
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const struct MultiRaidTrainer gTrayneeBattles[] = 
{
    {
		.owNum = EVENT_OBJ_GFX_AROMA_LADY,
		.trainerClass = CLASS_PKMN_BREEDER_RS,
		.backSpriteId = SINGLE_BATTLE,
		.gender = FEMALE,
		.otId = 66,
		.name = sTrainerName_Madeline,
		.spreads =
		{
			[0] =	 sTeam_TrayneeHP,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sTeam_TrayneeHP),
		},
    },
    {
		.owNum = EVENT_OBJ_GFX_AROMA_LADY,
		.trainerClass = CLASS_PKMN_BREEDER_RS,
		.backSpriteId = SINGLE_BATTLE,
		.gender = FEMALE,
		.otId = 66,
		.name = sTrainerName_Madeline,
		.spreads =
		{
			[0] =	 sTeam_TrayneeAtt,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sTeam_TrayneeAtt),
		},
    },
    {
		.owNum = EVENT_OBJ_GFX_AROMA_LADY,
		.trainerClass = CLASS_PKMN_BREEDER_RS,
		.backSpriteId = SINGLE_BATTLE,
		.gender = FEMALE,
		.otId = 66,
		.name = sTrainerName_Madeline,
		.spreads =
		{
			[0] =	 sTeam_TrayneeDef,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sTeam_TrayneeDef),
		},
    },
    {
		.owNum = EVENT_OBJ_GFX_AROMA_LADY,
		.trainerClass = CLASS_PKMN_BREEDER_RS,
		.backSpriteId = SINGLE_BATTLE,
		.gender = FEMALE,
		.otId = 66,
		.name = sTrainerName_Madeline,
		.spreads =
		{
			[0] =	 sTeam_TrayneeSpA,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sTeam_TrayneeSpA),
		},
    },
    {
		.owNum = EVENT_OBJ_GFX_AROMA_LADY,
		.trainerClass = CLASS_PKMN_BREEDER_RS,
		.backSpriteId = SINGLE_BATTLE,
		.gender = FEMALE,
		.otId = 66,
		.name = sTrainerName_Madeline,
		.spreads =
		{
			[0] =	 sTeam_TrayneeSpD,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sTeam_TrayneeSpD),
		},
    },
    {
		.owNum = EVENT_OBJ_GFX_AROMA_LADY,
		.trainerClass = CLASS_PKMN_BREEDER_RS,
		.backSpriteId = SINGLE_BATTLE,
		.gender = FEMALE,
		.otId = 66,
		.name = sTrainerName_Madeline,
		.spreads =
		{
			[0] =	 sTeam_TrayneeSpe,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sTeam_TrayneeSpe),
		},
    },


};