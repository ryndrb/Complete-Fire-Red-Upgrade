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

// Traynee HP Team
static const struct BattleTowerSpread sDifficult_TrayneeHP[] = 
{
    {
		.species = SPECIES_WIGGLYTUFF,
		.nature = NATURE_RELAXED,
		.ability = FRONTIER_ABILITY_2,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_WIGGLYTUFF,
		.nature = NATURE_RELAXED,
		.ability = FRONTIER_ABILITY_2,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_WIGGLYTUFF,
		.nature = NATURE_RELAXED,
		.ability = FRONTIER_ABILITY_2,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_WIGGLYTUFF,
		.nature = NATURE_RELAXED,
		.ability = FRONTIER_ABILITY_2,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_WIGGLYTUFF,
		.nature = NATURE_RELAXED,
		.ability = FRONTIER_ABILITY_2,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_WIGGLYTUFF,
		.nature = NATURE_RELAXED,
		.ability = FRONTIER_ABILITY_2,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},

};
// Traynee Attack
static const struct BattleTowerSpread sDifficult_TrayneeAtt[] = 
{
    {
		.species = SPECIES_VICTREEBEL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_VICTREEBEL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_VICTREEBEL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_VICTREEBEL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_VICTREEBEL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_VICTREEBEL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},

};

// Traynee Defense
static const struct BattleTowerSpread sDifficult_TrayneeDef[] = 
{
    {
		.species = SPECIES_COALOSSAL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_COALOSSAL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_COALOSSAL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_COALOSSAL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_COALOSSAL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_COALOSSAL,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
};

// Traynee Sp Attack
static const struct BattleTowerSpread sDifficult_TrayneeSpA[] = 
{
    {
		.species = SPECIES_BEAUTIFLY,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_BEAUTIFLY,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_BEAUTIFLY,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_BEAUTIFLY,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_BEAUTIFLY,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_BEAUTIFLY,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
};

// Traynee Sp Defense
static const struct BattleTowerSpread sDifficult_TrayneeSpD[] = 
{
    {
		.species = SPECIES_DUSTOX,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_DUSTOX,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_DUSTOX,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_DUSTOX,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_DUSTOX,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_DUSTOX,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
};

// Traynee Speed
static const struct BattleTowerSpread sDifficult_TrayneeSpe[] = 
{
    {
		.species = SPECIES_JUMPLUFF,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_JUMPLUFF,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_JUMPLUFF,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_JUMPLUFF,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_JUMPLUFF,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
    {
		.species = SPECIES_JUMPLUFF,
		.nature = NATURE_RELAXED,
		.level = 5,
		.hpIv = 0,
		.atkIv = 0,
		.defIv = 0,
		.spAtkIv = 0,
		.spDefIv = 0,
		.spdIv = 0,
		.moves ={MOVE_HEALINGWISH},
	},
};

const struct MultiRaidTrainer gImportantTrainers[] = 
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
			[0] =	 sDifficult_TrayneeHP,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sDifficult_TrayneeHP),
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
			[0] =	 sDifficult_TrayneeAtt,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sDifficult_TrayneeAtt),
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
			[0] =	 sDifficult_TrayneeDef,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sDifficult_TrayneeDef),
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
			[0] =	 sDifficult_TrayneeSpA,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sDifficult_TrayneeSpA),
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
			[0] =	 sDifficult_TrayneeSpD,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sDifficult_TrayneeSpD),
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
			[0] =	 sDifficult_TrayneeSpe,
		},
		.spreadSizes =
		{
			[0] =   NELEMS(sDifficult_TrayneeSpe),
		},
    }
};

const u8 gNumImportantTrainers = NELEMS(gImportantTrainers);