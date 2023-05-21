#include "defines.h"
#include "defines_battle.h"
#include "../include/string_util.h"
#include "../include/constants/abilities.h"
#include "../include/constants/pokedex.h"
#include "../include/constants/species.h"

#include "../include/new/ability_tables.h"
#include "../include/new/ability_util.h"
#include "../include/new/battle_util.h"
#include "../include/new/move_tables.h"
#include "../include/new/util.h"

extern const u8 gAbilityNames[][ABILITY_NAME_LENGTH + 1];
extern const u8* gAbilityDescriptions[];
extern const u8 gText_AbilityName_AirLock[];
extern const u8 gText_AbilityName_VitalSpirit[];
extern const u8 gText_AbilityName_WhiteSmoke[];
extern const u8 gText_AbilityName_PurePower[];
extern const u8 gText_AbilityName_IronBarbs[];
extern const u8 gText_AbilityName_SolidRock[];
extern const u8 gText_AbilityName_Turboblaze[];
extern const u8 gText_AbilityName_Teravolt[];
extern const u8 gText_AbilityName_ChillingNeigh[];
extern const u8 gText_AbilityName_Libero[];
extern const u8 gText_AbilityName_TanglingHair[];
extern const u8 gText_AbilityName_WimpOut[];
extern const u8 gText_AbilityName_QueenlyMajesty[];
extern const u8 gText_AbilityName_PowerOfAlchemy[];
extern const u8 gText_AbilityName_PropellerTail[];

// new but same logic
extern const u8 gText_AbilityName_Royalty[];
extern const u8 gText_AbilityName_FieryNeigh[];
extern const u8 gText_AbilityName_Bluster[];
extern const u8 gText_AbilityName_FaceShield[];
extern const u8 gText_AbilityName_Fortification[];
extern const u8 gText_AbilityName_Carapace[];

// new but similar
extern const u8 gText_AbilityName_Striker[]; // similar to iron fist

// Descriptions
extern const u8 gText_AbilityDescription_Striker[];

const u8* GetAbilityNameOverride(const u8 ability, const u16 species) //Bypasses the 255 Ability limitation and implements clone Abilities
{
	u16 dexNum = SpeciesToNationalPokedexNum(species);

	switch (ability)
	{
		case ABILITY_CLOUDNINE:
			switch (dexNum)
			{
				#ifdef NATIONAL_DEX_RAYQUAZA
				case NATIONAL_DEX_RAYQUAZA:
					return gText_AbilityName_AirLock;
				#endif
			}
			break;
		case ABILITY_INSOMNIA:
			if (IsVitalSpiritAbility(ability, species))
				return gText_AbilityName_VitalSpirit;
			break;
		case ABILITY_CLEARBODY:
			if (IsWhiteSmokeAbility(ability, species))
				return gText_AbilityName_WhiteSmoke;
			break;
		case ABILITY_HUGEPOWER:
			switch (dexNum)
			{
				#if (defined NATIONAL_DEX_MEDITITE && defined NATIONAL_DEX_MEDICHAM)
				case NATIONAL_DEX_MEDITITE:
				case NATIONAL_DEX_MEDICHAM:
					return gText_AbilityName_PurePower;
				#endif
			}
			break;
		case ABILITY_ROUGHSKIN:
			switch (dexNum)
			{
				#if (defined NATIONAL_DEX_FERROSEED && defined NATIONAL_DEX_FERROTHORN)
				case NATIONAL_DEX_FERROSEED:
				case NATIONAL_DEX_FERROTHORN:
					return gText_AbilityName_IronBarbs;
				#endif
			}
			break;
		case ABILITY_FILTER:
			switch (dexNum)
			{
				#if (defined NATIONAL_DEX_CAMERUPT && defined NATIONAL_DEX_RHYPERIOR && defined NATIONAL_DEX_TIRTOUGA && defined NATIONAL_DEX_CARRACOSTA)
				case NATIONAL_DEX_CAMERUPT:
				case NATIONAL_DEX_RHYPERIOR:
				case NATIONAL_DEX_TIRTOUGA:
				case NATIONAL_DEX_CARRACOSTA:
				#ifdef NATIONAL_DEX_STONJOURNER
				case NATIONAL_DEX_STONJOURNER:
				#endif
					return gText_AbilityName_SolidRock;
				#endif
			}
			break;
		case ABILITY_MOLDBREAKER:
			if (SpeciesHasTurboblaze(species))
				return gText_AbilityName_Turboblaze;
			else if (SpeciesHasTeravolt(species))
				return gText_AbilityName_Teravolt;
			break;
		case ABILITY_MOXIE:
			switch (dexNum)
			{
				#ifdef NATIONAL_DEX_GLASTRIER
				case NATIONAL_DEX_GLASTRIER:
					return gText_AbilityName_ChillingNeigh;
				#endif
				#if (defined NATIONAL_DEX_PONYTA && defined NATIONAL_DEX_RAPIDASH)
				case NATIONAL_DEX_PONYTA:
				case NATIONAL_DEX_RAPIDASH:
					return gText_AbilityName_FieryNeigh;
				#endif
			}
			break;
		case ABILITY_PROTEAN:
			if(SpeciesHasLibero(species))
				return gText_AbilityName_Libero;
			break;
		case ABILITY_GOOEY:
			switch (dexNum)
			{
				#if (defined NATIONAL_DEX_DIGLETT && defined NATIONAL_DEX_DUGTRIO)
				case NATIONAL_DEX_DIGLETT:
				case NATIONAL_DEX_DUGTRIO:
					return gText_AbilityName_TanglingHair;
				#endif
			}
			break;
		case ABILITY_EMERGENCYEXIT:
			switch (dexNum)
			{
				#ifdef NATIONAL_DEX_WIMPOD
				case NATIONAL_DEX_WIMPOD:
					return gText_AbilityName_WimpOut;
				#endif
			}
			break;
        #ifdef ABILITY_QUEENLYMAJESTY
        case ABILITY_QUEENLYMAJESTY:
        #endif
		case ABILITY_DAZZLING:
			switch (dexNum)
			{
				default:
					break;
				#ifdef NATIONAL_DEX_TSAREENA
				case NATIONAL_DEX_TSAREENA:
				#endif
				#ifdef NATIONAL_DEX_NIDOQUEEN
				case NATIONAL_DEX_NIDOQUEEN:
				#endif
				#ifdef NATIONAL_DEX_VESPIQUEN
				case NATIONAL_DEX_VESPIQUEN:
				#endif
					return gText_AbilityName_QueenlyMajesty;
			}
			break;
		case ABILITY_RECEIVER:
			switch (dexNum)
			{
				#if (defined NATIONAL_DEX_GRIMER && defined NATIONAL_DEX_MUK)
				case NATIONAL_DEX_GRIMER:
				case NATIONAL_DEX_MUK:
					return gText_AbilityName_PowerOfAlchemy;
				#endif
			}
			break;
		case ABILITY_STALWART:
			switch (dexNum)
			{
				#if (defined NATIONAL_DEX_ARROKUDA && defined NATIONAL_DEX_BARRASKEWDA)
				case NATIONAL_DEX_ARROKUDA:
				case NATIONAL_DEX_BARRASKEWDA:
					return gText_AbilityName_PropellerTail;
				#endif
			}
			break;
		case ABILITY_PUNKROCK:
			switch (dexNum)
			{
				#if (defined NATIONAL_DEX_WHISMUR && defined NATIONAL_DEX_LOUDRED && defined NATIONAL_DEX_EXPLOUD)
				case NATIONAL_DEX_WHISMUR:
				case NATIONAL_DEX_LOUDRED:
				case NATIONAL_DEX_EXPLOUD:
					return gText_AbilityName_Bluster;
				#endif
			}
			break;
		case ABILITY_DAUNTLESSSHIELD:
			switch (dexNum)
			{
				#if (defined NATIONAL_DEX_SHIELDON && defined NATIONAL_DEX_BASTIODON)
				case NATIONAL_DEX_SHIELDON:
				case NATIONAL_DEX_BASTIODON:
					return gText_AbilityName_FaceShield;
				#endif
			}
			break;
		case ABILITY_GRIMNEIGH:
			switch (dexNum)
			{
				#if (defined NATIONAL_DEX_LITLEO && defined NATIONAL_DEX_PYROAR)
				case NATIONAL_DEX_LITLEO:
				case NATIONAL_DEX_PYROAR:
					return gText_AbilityName_Royalty;
				#endif
			}
			break;
		case ABILITY_IRONFIST:
			if(SpeciesHasStriker(species))
				return gText_AbilityName_Striker;
			break;
	}

	return NULL;
}

const u8* GetAbilityName(const u8 ability, const u16 species)
{
	const u8* override = GetAbilityNameOverride(ability, species);
	if (override != NULL)
		return override;

	const u8* ptr = gAbilityNames[ability];

	if (ptr[3] == 0x8 || ptr[3] == 0x9) //Expanded Ability Names
		ptr = T1_READ_PTR(ptr);

	return ptr;
}

const u8* GetAbilityDescriptionOverride(const u8 ability, const u16 species) //Bypasses the 255 Ability limitation and implements new Abilities
{
	switch (ability)
	{
        case ABILITY_IRONFIST:
            if(SpeciesHasStriker(species))
                return gText_AbilityDescription_Striker;
            break;
	}

	return NULL;
}

const u8* GetAbilityDescription(const u8 ability, unusedArg const u16 species)
{
	const u8* override = GetAbilityDescriptionOverride(ability, species);
	if (override != NULL)
		return override;

	const u8* desc = gAbilityDescriptions[ability];
	return desc;
}

void CopyAbilityName(u8* dst, const u8 ability, const u16 species)
{
	StringCopy(dst, GetAbilityName(ability, species));
}

void CopyAbilityDescription(u8* dst, const u8 ability, const u16 species)
{
	StringCopy(dst, GetAbilityDescription(ability, species));
}

u16 GetProperAbilityPopUpSpecies(u8 bank)
{
	if (gNewBS->tookAbilityFrom[bank] != SPECIES_NONE)
		return gNewBS->tookAbilityFrom[bank];
	else
		return SPECIES(bank);
}

void SetProperAbilityPopUpSpecies(u8 bank)
{
	gAbilityPopUpSpecies = GetProperAbilityPopUpSpecies(bank);
}

void SetTookAbilityFrom(u8 taker, u8 takenFrom)
{
	if (gNewBS->tookAbilityFrom[takenFrom] != SPECIES_NONE)
		gNewBS->tookAbilityFrom[taker] = gNewBS->tookAbilityFrom[takenFrom]; //Pass along species
	else
		gNewBS->tookAbilityFrom[taker] = SPECIES(takenFrom);
}

void SwapTookAbilityFrom(u8 bank1, u8 bank2)
{
	u16 species1 = GetProperAbilityPopUpSpecies(bank1);
	u16 species2 = GetProperAbilityPopUpSpecies(bank2);

	gNewBS->tookAbilityFrom[bank1] = species2;
	gNewBS->tookAbilityFrom[bank2] = species1;
}

void ResetTookAbilityFrom(u8 bank)
{
	gNewBS->tookAbilityFrom[bank] = SPECIES_NONE;
}

bool8 IsTargetAbilityIgnored(u8 defAbility, u8 atkAbility, u16 move)
{
	return IS_MOLD_BREAKER(atkAbility, move) && gSpecialAbilityFlags[defAbility].gMoldBreakerIgnoredAbilities;
}

bool8 IsTargetAbilityIgnoredNoMove(u8 defAbility, u8 atkAbility)
{
	return IsMoldBreakerAbility(atkAbility) && gSpecialAbilityFlags[defAbility].gMoldBreakerIgnoredAbilities;
}

bool8 SpeciesHasTurboblaze(unusedArg u16 species)
{
	#if (defined SPECIES_RESHIRAM && defined SPECIES_KYUREM_WHITE)
	return species == SPECIES_RESHIRAM
		|| species == SPECIES_KYUREM_WHITE;
	#else
	return FALSE;
	#endif
}

bool8 SpeciesHasTeravolt(unusedArg u16 species)
{
	#if (defined SPECIES_ZEKROM && defined SPECIES_KYUREM_BLACK)
	return species == SPECIES_ZEKROM
		|| species == SPECIES_KYUREM_BLACK;
	#else
	return FALSE;
	#endif
}

bool8 SpeciesHasDrillBeak(unusedArg u16 species) //Custom Unbound Ability
{
	#if (defined SPECIES_SPEAROW && defined SPECIES_FEAROW)
	return species == SPECIES_SPEAROW || species == SPECIES_FEAROW;
	#else
	return FALSE;
	#endif
}

bool8 SpeciesHasGrassDash(unusedArg u16 species) //Custom Unbound Ability
{
	#ifdef SPECIES_SUNFLORA
	return species == SPECIES_SUNFLORA;
	#else
	return FALSE;
	#endif
}

bool8 SpeciesHasSlipperyTail(unusedArg u16 species) //Custom Unbound Ability
{
	#ifdef SPECIES_SEVIPER
	return species == SPECIES_SEVIPER;
	#else
	return FALSE;
	#endif
}

bool8 IsClearBodyAbility(u8 ability)
{
	return ability == ABILITY_CLEARBODY
		#ifdef ABILITY_FULLMETALBODY
		|| ability == ABILITY_FULLMETALBODY
		#endif
		#ifdef ABILITY_WHITESMOKE
		|| ability == ABILITY_WHITESMOKE
		#endif
		;
}

bool8 IsMoldBreakerAbility(u8 ability)
{
	return ability == ABILITY_MOLDBREAKER
		#ifdef ABILITY_TURBOBLAZE
		|| ability == ABILITY_TURBOBLAZE
		#endif
		#ifdef ABILITY_TERAVOLT
		|| ability == ABILITY_TERAVOLT
		#endif
		;
}

bool8 IsMoxieAbility(u8 ability)
{
	switch (ability)
	{
		case ABILITY_MOXIE:
		#ifdef ABILITY_GRIMNEIGH
		case ABILITY_GRIMNEIGH:
		#endif
		#ifdef ABILITY_CHILLINGNEIGH
		case ABILITY_CHILLINGNEIGH:
		#endif
		#ifdef ABILITY_ASONE_GRIM
		case ABILITY_ASONE_GRIM:
		#endif
		#ifdef ABILITY_ASONE_CHILLING
		case ABILITY_ASONE_CHILLING:
		#endif
		case ABILITY_BEASTBOOST:
		case ABILITY_SOULHEART:
		case ABILITY_BATTLEBOND:
			return TRUE;
		default:
			return FALSE;
	}
}

bool8 IsChoiceAbility(u8 ability)
{
	return ability == ABILITY_GORILLATACTICS || ability == ABILITY_SAGEPOWER;
}

bool8 IsHPAbsorptionAbility(u8 ability)
{
	switch (ability)
	{
		case ABILITY_WATERABSORB:
		case ABILITY_VOLTABSORB:
			return TRUE;
		default:
			return FALSE;
	}
}

bool8 IsElectricAbsorptionAblity(u8 ability)
{
	switch (ability)
	{
		case ABILITY_VOLTABSORB:
		case ABILITY_MOTORDRIVE:
		case ABILITY_LIGHTNINGROD:
			return TRUE;
		default:
			return FALSE;
	}
}

bool8 IsPlusMinusAbility(u8 ability)
{
	switch (ability)
	{
		case ABILITY_PLUS:
		case ABILITY_MINUS:
			return TRUE;
		default:
			return FALSE;
	}
}

bool8 IsMultiscaleAbility(u8 ability)
{
	switch (ability)
	{
		case ABILITY_MULTISCALE:
		#ifdef ABILITY_SHADOWSHIELD
		case ABILITY_SHADOWSHIELD:
		#endif
			return TRUE;
		default:
			return FALSE;
	}
}

bool8 IsPriorityBlockingAbility(u8 ability)
{
	switch (ability)
	{
		case ABILITY_DAZZLING:
		#ifdef ABILITY_QUEENLYMAJESTY
		case ABILITY_QUEENLYMAJESTY:
		#endif
			return TRUE;
		default:
			return FALSE;
	}
}

bool8 IsUnnerveAbility(u8 ability)
{
	return ability == ABILITY_UNNERVE
		#ifdef ABILITY_ASONE_GRIM
		|| ability == ABILITY_ASONE_GRIM
		#endif
		#ifdef ABILITY_ASONE_CHILLING
		|| ability == ABILITY_ASONE_CHILLING
		#endif
		;
}

bool8 UnnerveOnOpposingField(u8 bank)
{
	return ABILITY_ON_OPPOSING_FIELD(bank, ABILITY_UNNERVE)
		#ifdef ABILITY_ASONE_GRIM
		|| ABILITY_ON_OPPOSING_FIELD(bank, ABILITY_ASONE_GRIM)
		#endif
		#ifdef ABILITY_ASONE_CHILLING
		|| ABILITY_ON_OPPOSING_FIELD(bank, ABILITY_ASONE_CHILLING)
		#endif
		;
}

bool8 AbilityIncreasesWildItemChance(u8 ability)
{
	return ability == ABILITY_COMPOUNDEYES || ability == ABILITY_SUPERLUCK;
}

bool8 AbilityBlocksIntimidate(u8 ability)
{
	return ability == ABILITY_INNERFOCUS
		|| ability == ABILITY_OWNTEMPO
		|| ability == ABILITY_OBLIVIOUS
		|| ability == ABILITY_SCRAPPY;
}

bool8 AbilityPreventsLoweringAtk(u8 ability)
{
	return ability == ABILITY_HYPERCUTTER
		|| ability == ABILITY_MIRRORARMOR
		|| IsClearBodyAbility(ability);
}

bool8 AbilityPreventsLoweringStat(u8 ability, u8 statId)
{
	switch (ability)
	{
		case ABILITY_HYPERCUTTER:
			return statId == STAT_STAGE_ATK;
		case ABILITY_BIGPECKS:
			return statId == STAT_STAGE_DEF;
		case ABILITY_KEENEYE:
			return statId == STAT_STAGE_ACC;
		default:
			return FALSE;
	}
}

bool8 AbilityRaisesOneStatWhenSomeStatIsLowered(u8 ability)
{
	return ability == ABILITY_DEFIANT
		|| ability == ABILITY_COMPETITIVE;
}

bool8 IsAffectedBySturdy(u8 defAbility, u8 bankDef)
{
	return defAbility == ABILITY_STURDY
		&& BATTLER_MAX_HP(bankDef);
}

bool8 IsAffectedByDisguse(unusedArg u8 defAbility, unusedArg u16 defSpecies, unusedArg u8 moveSplit)
{
	#ifdef SPECIES_MIMIKYU
	if (defAbility == ABILITY_DISGUISE && defSpecies == SPECIES_MIMIKYU)
		return TRUE;
	#endif
	#ifdef SPECIES_EISCUE
	if (defAbility == ABILITY_ICEFACE && defSpecies == SPECIES_EISCUE && moveSplit == SPLIT_PHYSICAL)
		return TRUE;
	#endif

	return FALSE;
}

bool8 IsAffectedByBadDreams(u8 bank)
{
	return BATTLER_ALIVE(bank)
		&& (gBattleMons[bank].status1 & STATUS_SLEEP
		 || ABILITY(FOE(bank)) == ABILITY_COMATOSE)
		&& ABILITY(bank) != ABILITY_MAGICGUARD;
}

bool8 IsTrappedByAbility(u8 bankDef, u8 trapAbility)
{
	if (!CanBeTrapped(bankDef))
		return FALSE;

	switch (trapAbility)
	{
		case ABILITY_SHADOWTAG:
			return ABILITY(bankDef) != ABILITY_SHADOWTAG; //Shadow Tag's not affected by Shadow Tag
		case ABILITY_ARENATRAP:
			return CheckGrounding(bankDef) == GROUNDED;
		case ABILITY_MAGNETPULL:
			return IsOfType(bankDef, TYPE_STEEL);
		default:
			return FALSE;
	}
}

bool8 BankHasEvaporate(u8 bank)
{
	(void) bank; // Get rid of warning since not using
	#ifdef ABILITY_EVAPORATE
	return ABILITY(bank) == ABILITY_EVAPORATE
		&& SpeciesHasEvaporate(GetProperAbilityPopUpSpecies(bank));
	#endif
	return FALSE;
}

bool8 BankOnFieldHasEvaporate(void)
{
	for (u32 i = 0; i < gBattlersCount; ++i)
	{
		u8 bank = gBanksByTurnOrder[i];

		if (BATTLER_ALIVE(bank)
		&& BankHasEvaporate(bank)
		&& AffectedByRain(bank))
			return bank + 1;
	}

	return FALSE;
}

bool8 IsWhiteSmokeAbility(u8 ability, u16 species)
{
	if (!IsClearBodyAbility(ability))
		return FALSE;

	switch (SpeciesToNationalPokedexNum(species))
	{
		#if (defined NATIONAL_DEX_TORKOAL && defined NATIONAL_DEX_HEATMOR && defined NATIONAL_DEX_SIZZLIPEDE && defined NATIONAL_DEX_CENTISKORCH)
		case NATIONAL_DEX_TORKOAL:
		case NATIONAL_DEX_HEATMOR:
		case NATIONAL_DEX_SIZZLIPEDE:
		case NATIONAL_DEX_CENTISKORCH:
			return TRUE;
		#endif
	}

	return FALSE;
}

bool8 IsVitalSpiritAbility(u8 ability, u16 species)
{
	if (ability != ABILITY_INSOMNIA)
		return FALSE;

	switch (SpeciesToNationalPokedexNum(species))
	{
		#ifdef NATIONAL_DEX_MANKEY
		case NATIONAL_DEX_MANKEY:
		#endif
		#ifdef NATIONAL_DEX_PRIMEAPE
		case NATIONAL_DEX_PRIMEAPE:
		#endif
		#ifdef NATIONAL_DEX_MR_MIME
		case NATIONAL_DEX_MR_MIME:
		#endif
		#ifdef NATIONAL_DEX_ELECTABUZZ
		case NATIONAL_DEX_ELECTABUZZ:
		#endif
		#ifdef NATIONAL_DEX_ELECTABUZZ
		case NATIONAL_DEX_MAGMAR:
		#endif
		#ifdef NATIONAL_DEX_DELIBIRD
		case NATIONAL_DEX_DELIBIRD:
		#endif
		#ifdef NATIONAL_DEX_TYROGUE
		case NATIONAL_DEX_TYROGUE:
		#endif
		#ifdef NATIONAL_DEX_ELEKID
		case NATIONAL_DEX_ELEKID:
		#endif
		#ifdef NATIONAL_DEX_MAGBY
		case NATIONAL_DEX_MAGBY:
		#endif
		#ifdef NATIONAL_DEX_VIGOROTH
		case NATIONAL_DEX_VIGOROTH:
		#endif
		#ifdef NATIONAL_DEX_ELECTIVIRE
		case NATIONAL_DEX_ELECTIVIRE:
		#endif
		#ifdef NATIONAL_DEX_MAGMORTAR
		case NATIONAL_DEX_MAGMORTAR:
		#endif
		#ifdef NATIONAL_DEX_LILLIPUP
		case NATIONAL_DEX_LILLIPUP:
		#endif
		#ifdef NATIONAL_DEX_ROCKRUFF
		case NATIONAL_DEX_ROCKRUFF:
		#endif
		#ifdef NATIONAL_DEX_LYCANROC
		case NATIONAL_DEX_LYCANROC:
		#endif
			return TRUE;
	}

	return FALSE;
}

bool8 SpeciesHasStriker(unusedArg u16 species)
{
    #if (defined SPECIES_HITMONLEE && defined SPECIES_TORCHIC && defined SPECIES_COMBUSKEN && defined SPECIES_BLAZIKEN && defined SPECIES_STEENEE && defined SPECIES_TSAREENA)
    return species == SPECIES_HITMONLEE || species == SPECIES_TORCHIC || species == SPECIES_COMBUSKEN || species == SPECIES_BLAZIKEN || species == SPECIES_STEENEE || species == SPECIES_TSAREENA;
    #else
    return FALSE;
    #endif
}

bool8 SpeciesHasLibero(unusedArg u16 species)
{
    #if (defined SPECIES_SCORBUNNY && defined SPECIES_RABOOT && defined SPECIES_CINDERACE)
    return species == SPECIES_SCORBUNNY || species == SPECIES_RABOOT || species == SPECIES_CINDERACE;
    #else
    return FALSE;
    #endif
}
