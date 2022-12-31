#include "../config.h"
#include "../../include/constants/species.h"
#include "../../include/constants/items.h"
#include "../../include/constants/moves.h"

// Credits to Greenphx9

extern const u8 NAME_PURE_POWER[]; // huge power
extern const u8 NAME_LIBERO[]; // protean
extern const u8 NAME_WIMP_OUT[]; // emergency exit
extern const u8 NAME_PROPELLER_TAIL[]; // stalwart
extern const u8 NAME_CLOUD_NINE[]; // air lock
extern const u8 NAME_SHELL_ARMOR[]; // battle armor
extern const u8 NAME_WHITE_SMOKE[]; // clear body
extern const u8 NAME_FULL_METAL_BODY[]; // clear body
extern const u8 NAME_QUEENLY_MAJESTY[]; // dazzling
extern const u8 NAME_SOLID_ROCK[]; // filter
extern const u8 NAME_PRISM_ARMOR[]; // filter
extern const u8 NAME_TANGLING_HAIR[]; // gooey
extern const u8 NAME_VITAL_SPIRIT[]; // insomnia
extern const u8 NAME_TURBOBLAZE[]; // mold breaker
extern const u8 NAME_TERAVOLT[]; // mold breaker
extern const u8 NAME_SHADOW_SHIELD[]; // multiscale
extern const u8 NAME_POWER_OF_ALCHEMY[]; // recevier
extern const u8 NAME_IRON_BARBS[]; // rough skin
extern const u8 NAME_CHILLING_NEIGH[]; // moxie
extern const u8 NAME_SHADOW_SHIELD[]; // multiscale

// CUSTOME NAMES BUT SAME FUNCTIONALITY
extern const u8 NAME_ROYALTY[];
extern const u8 NAME_FIERY_NEIGH[];
extern const u8 NAME_BLUSTER[];
extern const u8 NAME_FACE_SHIELD[];
extern const u8 NAME_FORTIFICATION[];
extern const u8 NAME_CARAPACE[];
extern const u8 NAME_ELASTIC_BODY[];

static struct DuplicateAbility sDuplicateAbilities[] =
{
    {
        .species = SPECIES_MEDITITE, //Mon
        .currAbility = ABILITY_HUGEPOWER, //The original abilitiy
        .replaceAbilityString = NAME_PURE_POWER, //The new ability name
    },
    {
        .species = SPECIES_MEDICHAM,
        .currAbility = ABILITY_HUGEPOWER,
        .replaceAbilityString = NAME_PURE_POWER,
    },
    {
        .species = SPECIES_MEDICHAM_MEGA,
        .currAbility = ABILITY_HUGEPOWER,
        .replaceAbilityString = NAME_PURE_POWER,
    },
    {
        .species = SPECIES_SCORBUNNY,
        .currAbility = ABILITY_PROTEAN,
        .replaceAbilityString = NAME_LIBERO,
    },
    {
        .species = SPECIES_RABOOT,
        .currAbility = ABILITY_PROTEAN,
        .replaceAbilityString = NAME_LIBERO,
    },
    {
        .species = SPECIES_CINDERACE,
        .currAbility = ABILITY_PROTEAN,
        .replaceAbilityString = NAME_LIBERO,
    },
    {
        .species = SPECIES_WIMPOD,
        .currAbility = ABILITY_EMERGENCYEXIT,
        .replaceAbilityString = NAME_WIMP_OUT,
    },
    {
        .species = SPECIES_ARROKUDA,
        .currAbility = ABILITY_STALWART,
        .replaceAbilityString = NAME_PROPELLER_TAIL,
    },
    {
        .species = SPECIES_BARRASKEWDA,
        .currAbility = ABILITY_STALWART,
        .replaceAbilityString = NAME_PROPELLER_TAIL,
    },
    {
        .species = SPECIES_PSYDUCK,
        .currAbility = ABILITY_AIRLOCK,
        .replaceAbilityString = NAME_CLOUD_NINE,
    },
    {
        .species = SPECIES_GOLDUCK,
        .currAbility = ABILITY_AIRLOCK,
        .replaceAbilityString = NAME_CLOUD_NINE,
    },
    {
        .species = SPECIES_SWABLU,
        .currAbility = ABILITY_AIRLOCK,
        .replaceAbilityString = NAME_CLOUD_NINE,
    },
    {
        .species = SPECIES_ALTARIA,
        .currAbility = ABILITY_AIRLOCK,
        .replaceAbilityString = NAME_CLOUD_NINE,
    },
    {
        .species = SPECIES_DRAMPA,
        .currAbility = ABILITY_AIRLOCK,
        .replaceAbilityString = NAME_CLOUD_NINE,
    },
    {
        .species = SPECIES_SHELLDER,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityString = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_CLOYSTER,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityString = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_KRABBY,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityString = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_KINGLER,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityString = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_CLAMPERL,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityString = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_CORPHISH,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityString = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_CRAWDAUNT,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityString = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_TORKOAL,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityString = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_OSHAWOTT,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityString = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_DWEBBLE,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityString = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_CRUSTLE,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityString = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_ESCAVALIER,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityString = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_SHELMET,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityString = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_TURTONATOR,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityString = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_CHEWTLE,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityString = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_DREDNAW,
        .currAbility = ABILITY_BATTLEARMOR,
        .replaceAbilityString = NAME_SHELL_ARMOR,
    },
    {
        .species = SPECIES_CYNDAQUIL,
        .currAbility = ABILITY_CLEARBODY,
        .replaceAbilityString = NAME_WHITE_SMOKE,
    },
    {
        .species = SPECIES_QUILAVA,
        .currAbility = ABILITY_CLEARBODY,
        .replaceAbilityString = NAME_WHITE_SMOKE,
    },
    {
        .species = SPECIES_TYPHLOSION,
        .currAbility = ABILITY_CLEARBODY,
        .replaceAbilityString = NAME_WHITE_SMOKE,
    },
    {
        .species = SPECIES_TORKOAL,
        .currAbility = ABILITY_CLEARBODY,
        .replaceAbilityString = NAME_WHITE_SMOKE,
    },
    {
        .species = SPECIES_HEATMOR,
        .currAbility = ABILITY_CLEARBODY,
        .replaceAbilityString = NAME_WHITE_SMOKE,
    },
    {
        .species = SPECIES_SIZZLIPEDE,
        .currAbility = ABILITY_CLEARBODY,
        .replaceAbilityString = NAME_WHITE_SMOKE,
    },
    {
        .species = SPECIES_CENTISKORCH,
        .currAbility = ABILITY_CLEARBODY,
        .replaceAbilityString = NAME_WHITE_SMOKE,
    },
    {
        .species = SPECIES_SOLGALEO,
        .currAbility = ABILITY_CLEARBODY,
        .replaceAbilityString = NAME_FULL_METAL_BODY,
    },
    {
        .species = SPECIES_STEENEE,
        .currAbility = ABILITY_DAZZLING,
        .replaceAbilityString = NAME_QUEENLY_MAJESTY,
    },
    {
        .species = SPECIES_TSAREENA,
        .currAbility = ABILITY_DAZZLING,
        .replaceAbilityString = NAME_QUEENLY_MAJESTY,
    },
    {
        .species = SPECIES_SHUCKLE,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityString = NAME_SOLID_ROCK,
    },
    {
        .species = SPECIES_MAGCARGO,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityString = NAME_SOLID_ROCK,
    },
    {
        .species = SPECIES_CAMERUPT,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityString = NAME_SOLID_ROCK,
    },
    {
        .species = SPECIES_REGIROCK,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityString = NAME_SOLID_ROCK,
    },
    {
        .species = SPECIES_TIRTOUGA,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityString = NAME_SOLID_ROCK,
    },
    {
        .species = SPECIES_CARRACOSTA,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityString = NAME_SOLID_ROCK,
    },
    {
        .species = SPECIES_NECROZMA,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityString = NAME_PRISM_ARMOR,
    },
    {
        .species = SPECIES_NECROZMA_DUSK_MANE,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityString = NAME_PRISM_ARMOR,
    },
    {
        .species = SPECIES_NECROZMA_DAWN_WINGS,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityString = NAME_PRISM_ARMOR,
    },
    {
        .species = SPECIES_TANGELA,
        .currAbility = ABILITY_GOOEY,
        .replaceAbilityString = NAME_TANGLING_HAIR,
    },
    {
        .species = SPECIES_TANGROWTH,
        .currAbility = ABILITY_GOOEY,
        .replaceAbilityString = NAME_TANGLING_HAIR,
    },
    {
        .species = SPECIES_PHANTUMP,
        .currAbility = ABILITY_GOOEY,
        .replaceAbilityString = NAME_TANGLING_HAIR,
    },
    {
        .species = SPECIES_TREVENANT,
        .currAbility = ABILITY_GOOEY,
        .replaceAbilityString = NAME_TANGLING_HAIR,
    },
    {
        .species = SPECIES_ELECTABUZZ,
        .currAbility = ABILITY_INSOMNIA,
        .replaceAbilityString = NAME_VITAL_SPIRIT,
    },
    {
        .species = SPECIES_MAGMAR,
        .currAbility = ABILITY_INSOMNIA,
        .replaceAbilityString = NAME_VITAL_SPIRIT,
    },
    {
        .species = SPECIES_TYROGUE,
        .currAbility = ABILITY_INSOMNIA,
        .replaceAbilityString = NAME_VITAL_SPIRIT,
    },
    {
        .species = SPECIES_ELEKID,
        .currAbility = ABILITY_INSOMNIA,
        .replaceAbilityString = NAME_VITAL_SPIRIT,
    },
    {
        .species = SPECIES_MAGBY,
        .currAbility = ABILITY_INSOMNIA,
        .replaceAbilityString = NAME_VITAL_SPIRIT,
    },
    {
        .species = SPECIES_ROCKRUFF,
        .currAbility = ABILITY_INSOMNIA,
        .replaceAbilityString = NAME_VITAL_SPIRIT,
    },
    {
        .species = SPECIES_LYCANROC,
        .currAbility = ABILITY_INSOMNIA,
        .replaceAbilityString = NAME_VITAL_SPIRIT,
    },
    {
        .species = SPECIES_LYCANROC_DUSK,
        .currAbility = ABILITY_INSOMNIA,
        .replaceAbilityString = NAME_VITAL_SPIRIT,
    },
    {
        .species = SPECIES_LYCANROC_N,
        .currAbility = ABILITY_INSOMNIA,
        .replaceAbilityString = NAME_VITAL_SPIRIT,
    },
    {
        .species = SPECIES_RESHIRAM,
        .currAbility = ABILITY_MOLDBREAKER,
        .replaceAbilityString = NAME_TURBOBLAZE,
    },
    {
        .species = SPECIES_KYUREM_WHITE,
        .currAbility = ABILITY_MOLDBREAKER,
        .replaceAbilityString = NAME_TURBOBLAZE,
    },
    {
        .species = SPECIES_ZEKROM,
        .currAbility = ABILITY_MOLDBREAKER,
        .replaceAbilityString = NAME_TERAVOLT,
    },
    {
        .species = SPECIES_KYUREM_BLACK,
        .currAbility = ABILITY_MOLDBREAKER,
        .replaceAbilityString = NAME_TERAVOLT,
    },
    {
        .species = SPECIES_LUNALA,
        .currAbility = ABILITY_MULTISCALE,
        .replaceAbilityString = NAME_SHADOW_SHIELD,
    },
    {
        .species = SPECIES_GRIMER_A,
        .currAbility = ABILITY_RECEIVER,
        .replaceAbilityString = NAME_POWER_OF_ALCHEMY,
    },
    {
        .species = SPECIES_MUK_A,
        .currAbility = ABILITY_RECEIVER,
        .replaceAbilityString = NAME_POWER_OF_ALCHEMY,
    },
    {
        .species = SPECIES_FERROSEED,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityString = NAME_IRON_BARBS,
    },
    {
        .species = SPECIES_FERROTHORN,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityString = NAME_IRON_BARBS,
    },
    {
        .species = SPECIES_STUNFISK_G,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityString = NAME_IRON_BARBS,
    },
    {
        .species = SPECIES_CHESPIN,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityString = NAME_IRON_BARBS,
    },
    {
        .species = SPECIES_QUILLADIN,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityString = NAME_IRON_BARBS,
    },
    {
        .species = SPECIES_CHESNAUGHT,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityString = NAME_IRON_BARBS,
    },
    {
        .species = SPECIES_TOGEDEMARU,
        .currAbility = ABILITY_ROUGHSKIN,
        .replaceAbilityString = NAME_IRON_BARBS,
    },
    {
        .species = SPECIES_CALYREX_ICE_RIDER,
        .currAbility = ABILITY_MOXIE,
        .replaceAbilityString = NAME_CHILLING_NEIGH,
    },
    // BELOW ARE CUSTOM NAMES BUT SIMILAR FUNCTIONALITY AS ABOVE
    // JUST FOR INDIVIDUALITY SAKE.. I DON'T KNOW...
    {
        .species = SPECIES_PYROAR,
        .currAbility = ABILITY_GRIMNEIGH,
        .replaceAbilityString = NAME_ROYALTY,
    },
    {
        .species = SPECIES_PONYTA,
        .currAbility = ABILITY_MOXIE,
        .replaceAbilityString = NAME_FIERY_NEIGH,
    },
    {
        .species = SPECIES_RAPIDASH,
        .currAbility = ABILITY_MOXIE,
        .replaceAbilityString = NAME_FIERY_NEIGH,
    },
    {
        .species = SPECIES_WHISMUR,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityString = NAME_BLUSTER,
    },
    {
        .species = SPECIES_LOUDRED,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityString = NAME_BLUSTER,
    },
    {
        .species = SPECIES_EXPLOUD,
        .currAbility = ABILITY_PUNKROCK,
        .replaceAbilityString = NAME_BLUSTER,
    },
    {
        .species = SPECIES_SHIELDON,
        .currAbility = ABILITY_DAUNTLESSSHIELD,
        .replaceAbilityString = NAME_FACE_SHIELD,
    },
    {
        .species = SPECIES_BASTIODON,
        .currAbility = ABILITY_DAUNTLESSSHIELD,
        .replaceAbilityString = NAME_FACE_SHIELD,
    },
    {
        .species = SPECIES_CHESPIN,
        .currAbility = ABILITY_DAUNTLESSSHIELD,
        .replaceAbilityString = NAME_FORTIFICATION,
    },
    {
        .species = SPECIES_QUILLADIN,
        .currAbility = ABILITY_DAUNTLESSSHIELD,
        .replaceAbilityString = NAME_FORTIFICATION,
    },
    {
        .species = SPECIES_CHESNAUGHT,
        .currAbility = ABILITY_DAUNTLESSSHIELD,
        .replaceAbilityString = NAME_FORTIFICATION,
    },
    {
        .species = SPECIES_TURTONATOR,
        .currAbility = ABILITY_DAUNTLESSSHIELD,
        .replaceAbilityString = NAME_CARAPACE,
    },
    {
        .species = SPECIES_LICKITUNG,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityString = NAME_ELASTIC_BODY,
    },
    {
        .species = SPECIES_LICKILICKY,
        .currAbility = ABILITY_FILTER,
        .replaceAbilityString = NAME_ELASTIC_BODY,
    },
};