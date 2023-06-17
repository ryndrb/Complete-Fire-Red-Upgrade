#include "../../config.h"
#include "../../../include/constants/species.h"
#include "../../../include/constants/items.h"
#include "../../../include/constants/moves.h"
#include "../../../include/constants/event_objects.h"
#include "../../../include/constants/trainer_classes.h"
#include "../../../include/new/catching.h"
#include "../../../include/new/build_pokemon.h"
#include "../../../include/new/build_pokemon_2.h"
#include "../../../include/battle.h"
#include "../../../include/pokemon.h"
#include "trainerids.h"

// Trainer IVS
#define IV_ZERO         0,   0,  0,  0,  0,  0
#define IV_MEDIUM       16, 16, 16, 16, 16, 16
#define IV_MAX          31, 31, 31, 31, 31, 31
#define IV_HP_DARK      31, 31, 31, 31, 31, 31
#define IV_HP_DRAGON    30, 31, 31, 31, 31, 31
#define IV_HP_ICE       30, 31, 30, 31, 31, 31
#define IV_HP_PSYCHIC   30, 31, 31, 31, 31, 30
#define IV_HP_ELECTRIC  30, 31, 30, 31, 31, 30
#define IV_HP_GRASS     30, 31, 31, 30, 31, 31
#define IV_HP_WATER     31, 30, 30, 30, 31, 31  
#define IV_HP_FIRE      31, 30, 31, 30, 31, 30
#define IV_HP_STEEL     31, 30, 30, 30, 31, 30
#define IV_HP_GHOST     31, 30, 31, 31, 30, 31
#define IV_HP_BUG       31, 30, 30, 31, 30, 31
#define IV_HP_ROCK      30, 30, 31, 31, 30, 30
#define IV_HP_GROUND    30, 30, 30, 31, 30, 30
#define IV_HP_POISON    30, 30, 31, 30, 30, 31
#define IV_HP_FLYING    30, 30, 30, 30, 30, 31
#define IV_HP_FIGHTING  30, 30, 31, 30, 30, 30

// Overworld Trainers Ev Spread for game progression| Ace Trainers/Gym Leaders/Rivals/Elite Fours will have Custom
#define EV_0            0,   0,  0,  0,  0,  0
#define EV_20           20, 20, 20, 20, 20, 20
#define EV_40           40, 40, 40, 40, 40, 40
#define EV_60           60, 60, 60, 60, 60, 60
#define EV_80           80, 80, 80, 80, 80, 80

// Taken data from decomp

// Trainer party data exists for all of the RS trainer classes, but
// are only filled with one of the following placeholder pokemon.
// The actual FRLG trainer party data starts after these.
#define DUMMY_TRAINER_MON       \
{                               \
    .lvl = 5,                   \
    .species = SPECIES_EKANS,   \
}

#define DUMMY_TRAINER_MON_IV    \
{                               \
    .lvl = 5,                   \
    .species = SPECIES_EKANS,   \
}

// Copy of Swimmer Male Finn's party
#define DUMMY_TRAINER_STARMIE   \
{                               \
    .lvl = 38,                  \
    .species = SPECIES_STARMIE, \
}

static const struct TrainerMonItemCustomMoves sParty_AquaLeader[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_AquaGruntM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_AquaGruntF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSAromaLady[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSRuinManiac[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_Proton[] = {
    {
        .lvl = 0,
        .species = SPECIES_TENTACOOL,
        .ability = Ability_1, // clear body
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_BLACK_SLUDGE,
        .moves = {MOVE_TOXICSPIKES, MOVE_CONFUSERAY, MOVE_KNOCKOFF, MOVE_BRINE},
    },
    {
        .lvl = 0,
        .species = SPECIES_MISDREAVUS,
        .ability = Ability_1, // levitate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_EVIOLITE,
        .moves = {MOVE_DRAININGKISS, MOVE_OMINOUSWIND, MOVE_NASTYPLOT, MOVE_ICYWIND},
    },
    {
        .lvl = 0,
        .species = SPECIES_LINOONE_G,
        .ability = Ability_2, // glutonny
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_KNOCKOFF, MOVE_HONECLAWS, MOVE_HEADBUTT, MOVE_DIG},
    },
    {
        .lvl = 1,
        .species = SPECIES_THWACKEY,
        .ability = Ability_Hidden, // grassy surge
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_LEECHSEED, MOVE_RAZORLEAF, MOVE_TAUNT, MOVE_STRENGTH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_Archer[] = {
    {
        .lvl = 0,
        .species = SPECIES_GRIMMSNARL,
        .ability = Ability_1, // prankster
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_LIGHT_CLAY,
        .moves = {MOVE_REFLECT, MOVE_LIGHTSCREEN, MOVE_PLAYROUGH, MOVE_TAUNT},
    },
    {
        .lvl = 0,
        .species = SPECIES_WEAVILE,
        .ability = Ability_2, // technician
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_KNOCKOFF, MOVE_TRIPLEAXEL, MOVE_ICESHARD, MOVE_LOWKICK},
    },
    {
        .lvl = 0,
        .species = SPECIES_SLOWKING_G,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 252, 4, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_PSYCHIC, MOVE_SLUDGEBOMB, MOVE_ICEBEAM, MOVE_FLAMETHROWER},
    },
    {
        .lvl = 0,
        .species = SPECIES_JELLICENT,
        .ability = Ability_1, // water absorb
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_COLBUR_BERRY,
        .moves = {MOVE_RECOVER, MOVE_WILLOWISP, MOVE_HEX, MOVE_STRENGTHSAP},
    },
    {
        .lvl = 0,
        .species = SPECIES_ARCHEOPS,
        .ability = Ability_Hidden, // touch claws
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_EARTHQUAKE, MOVE_UTURN, MOVE_DUALWINGBEAT, MOVE_ROOST},
    },
    {
        .lvl = 1,
        .species = SPECIES_HOUNDOOM,
        .ability = Ability_Hidden, // intimidate / dark aura
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_HOUNDOOMINITE,
        .moves = {MOVE_NASTYPLOT, MOVE_FIREBLAST, MOVE_DARKPULSE, MOVE_SLUDGEBOMB},
    },
};

static const struct TrainerMonItemCustomMoves sParty_Ariana[] = {
    {
        .lvl = 0,
        .species = SPECIES_CORVIKNIGHT,
        .ability = Ability_1, // pressure
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 0, 8, 0, 252, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_BRAVEBIRD, MOVE_UTURN, MOVE_ROOST, MOVE_TAILWIND},
    },
    // {
    //     .lvl = 0,
    //     .species = SPECIES_GARCHOMP,
    //     .ability = Ability_Hidden, // rough skin
    //     .nature = NATURE_JOLLY,
    //     .ivSpread = {IV_HP_STEEL},
    //     .evSpread = {0, 252, 0, 0, 4, 252},
    //     .heldItem = ITEM_CHOICE_SCARF,
    //     .moves = {MOVE_EARTHQUAKE, MOVE_HIDDENPOWER, MOVE_STONEEDGE, MOVE_DRAGONCLAW},
    // },
    {
        .lvl = 0,
        .species = SPECIES_CONKELDURR,
        .ability = Ability_2, // sheer force
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_CLOSECOMBAT, MOVE_MACHPUNCH, MOVE_ICEPUNCH, MOVE_THUNDERPUNCH},
    },
    {
        .lvl = 0,
        .species = SPECIES_PORYGON_Z,
        .ability = Ability_1, // adaptability
        .nature = NATURE_TIMID,
        .ivSpread = {IV_HP_FIRE},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_TRIATTACK, MOVE_DARKPULSE, MOVE_NASTYPLOT, MOVE_HIDDENPOWER},
    },
    {
        .lvl = 0,
        .species = SPECIES_GLISCOR,
        .ability = Ability_Hidden, // poison heal
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 4, 0, 252, 0},
        .heldItem = ITEM_TOXIC_ORB,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROOST, MOVE_FACADE, MOVE_SWORDSDANCE},
    },
    // {
    //     .lvl = 1,
    //     .species = SPECIES_GENGAR,
    //     .ability = Ability_1, // levitate
    //     .nature = NATURE_TIMID,
    //     .ivSpread = {IV_HP_FIGHTING},
    //     .evSpread = {0, 0, 0, 252, 4, 252},
    //     .heldItem = ITEM_GENGARITE,
    //     .moves = {MOVE_SHADOWBALL, MOVE_SUBSTITUTE, MOVE_NASTYPLOT, MOVE_HIDDENPOWER},
    // },
};

static const struct TrainerMonItemCustomMoves sParty_Eusine[] = {
    {
        .lvl = 0,
        .species = SPECIES_NINETALES,
        .ability = Ability_Hidden, // drought
        .nature = NATURE_TIMID,
        .ivSpread = {IV_HP_ICE},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_CHARCOAL,
        .moves = {MOVE_NASTYPLOT, MOVE_SOLARBEAM, MOVE_FIREBLAST, MOVE_HIDDENPOWER},
    },
    {
        .lvl = 0,
        .species = SPECIES_DRAPION,
        .ability = Ability_2, // sniper
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_EARTHQUAKE, MOVE_PURSUIT, MOVE_WICKEDBLOW, MOVE_POISONJAB},
    },
    {
        .lvl = 0,
        .species = SPECIES_YANMEGA,
        .ability = Ability_1, // speed boost
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_PROTECT, MOVE_BUGBUZZ, MOVE_AIRSLASH, MOVE_GIGADRAIN},
    },
    {
        .lvl = 0,
        .species = SPECIES_FLYGON,
        .ability = Ability_Hidden, // tinted lens
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_HP_FLYING},
        .evSpread = {252, 0, 0, 0, 4, 252},
        .heldItem = ITEM_LUM_BERRY,
        .moves = {MOVE_UTURN, MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_HIDDENPOWER},
    },
    {
        .lvl = 0,
        .species = SPECIES_COFAGRIGUS,
        .ability = Ability_Hidden, // mummy
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 200, 0, 56, 0},
        .heldItem = ITEM_COLBUR_BERRY,
        .moves = {MOVE_WILLOWISP, MOVE_SHADOWBALL, MOVE_PAINSPLIT, MOVE_HAZE},
    },
    {
        .lvl = 2,
        .species = SPECIES_ALTARIA,
        .ability = Ability_Hidden, // cloud nine / pixilate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_HP_FIRE},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_ALTARIANITE,
        .moves = {MOVE_DRAGONDANCE, MOVE_BODYSLAM, MOVE_HIDDENPOWER, MOVE_ROOST},
    },
};
static const struct TrainerMonItemCustomMoves sParty_Route25_JessieJames[] = {
    {
        .lvl = 0,
        .species = SPECIES_FRILLISH_F,
        .ability = Ability_Hidden, // water bubble
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_EVIOLITE,
        .moves = {MOVE_WATERPULSE, MOVE_OMINOUSWIND, MOVE_STRENGTHSAP, MOVE_RECOVER},
    },
    {
        .lvl = 0,
        .species = SPECIES_MORPEKO,
        .ability = Ability_Hidden, // hunger switch
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_SPARK, MOVE_BITE, MOVE_FAKEOUT, MOVE_SUPERFANG},
    },
    {
        .lvl = 0,
        .species = SPECIES_SEVIPER,
        .ability = Ability_Hidden, // fatal precision
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_EXPERT_BELT,
        .moves = {MOVE_POISONFANG, MOVE_NIGHTSLASH, MOVE_IRONTAIL, MOVE_GLARE},
    },
    {
        .lvl = 0,
        .species = SPECIES_ZANGOOSE,
        .ability = Ability_1, // tough claws
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SLASH, MOVE_NIGHTSLASH, MOVE_QUICKATTACK, MOVE_METALCLAW},
    },
};
static const struct TrainerMonItemCustomMoves sParty_Viridian_Ash[] = { // outside gym / not leader fight yet
    {
        .lvl = 0,
        .species = SPECIES_DRAGONITE,
        .ability = Ability_Hidden, // multi scale
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 52, 56, 0, 152, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_DRAGONDANCE, MOVE_DUALWINGBEAT, MOVE_EARTHQUAKE, MOVE_ROOST},
    },
    {
        .lvl = 0,
        .species = SPECIES_SNORLAX,
        .ability = Ability_Hidden, // fluffy
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {12, 0, 244, 0, 252, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_BODYSLAM, MOVE_EARTHQUAKE, MOVE_FIREPUNCH, MOVE_PURSUIT},
    },
    {
        .lvl = 0,
        .species = SPECIES_CHARIZARD,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_CHARIZARDITE_X,
        .moves = {MOVE_DRAGONDANCE, MOVE_FLAREBLITZ, MOVE_EARTHQUAKE, MOVE_ROOST},
    },
    {
        .lvl = 0,
        .species = SPECIES_LUCARIO,
        .ability = Ability_Hidden, // justified
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 252, 0, 0, 4, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_MACHPUNCH, MOVE_EXTREMESPEED, MOVE_BULLETPUNCH, MOVE_POWERUPPUNCH},
    },
    {
        .lvl = 0,
        .species = SPECIES_GRENINJA,
        .ability = Ability_2, // battle bond
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_CHOICE_SPECS,
        .moves = {MOVE_SURF, MOVE_DARKPULSE, MOVE_WATERSHURIKEN, MOVE_SPIKES},
    },
    {
        .lvl = 5,
        .species = SPECIES_PIKACHU,
        .ability = Ability_Hidden, // lightning rod
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 252, 252, 252, 252, 252},
        .heldItem = ITEM_LIGHT_BALL,
        .moves = {MOVE_VOLTSWITCH, MOVE_THUNDERBOLT, MOVE_KNOCKOFF, MOVE_SURF},
    },
};
static const struct TrainerMonItemCustomMoves sParty_RSLady[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSBeauty[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RichBoy[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSPokemaniac[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSSwimmerM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSBlackBelt[] = {DUMMY_TRAINER_MON_IV};
static const struct TrainerMonItemCustomMoves sParty_Guitarist[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_Kindler[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSCamper[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_BugManiac[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSPsychicM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSPsychicF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSGentleman[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_EliteFourSidney[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_EliteFourPhoebe[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_Route4_LeaderRoxanne[] = {
    {
        .lvl = 0,
        .species = SPECIES_CORSOLA,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_BERRY_JUICE,
        .moves = {MOVE_RECOVER, MOVE_CONFUSERAY, MOVE_BARRIER, MOVE_WATERPULSE},
    },
    {
        .lvl = 0,
        .species = SPECIES_MAGCARGO,
        .ability = Ability_Hidden, // weak armor
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_CHESTO_BERRY,
        .moves = {MOVE_ANCIENTPOWER, MOVE_FLAMEBURST},
    },
    {
        .lvl = 0,
        .species = SPECIES_ARCHEN,
        .ability = Ability_Hidden, // tough claws
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_EXPERT_BELT,
        .moves = {MOVE_WINGATTACK, MOVE_ROCKTHROW, MOVE_KNOCKOFF, MOVE_STEELWING},
    },
    {
        .lvl = 0,
        .species = SPECIES_TYRUNT,
        .ability = Ability_1, // strong jaw
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_PASSHO_BERRY,
        .moves = {MOVE_ICEFANG, MOVE_FIREFANG, MOVE_THUNDERFANG, MOVE_BITE},
    },
};
static const struct TrainerMonItemCustomMoves sParty_Route25_LeaderBrawly[] = {
    {
        .lvl = 0,
        .species = SPECIES_MEDITITE,
        .ability = Ability_Hidden, // pure power
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_HP_ICE},
        .evSpread = {EV_60},
        .heldItem = ITEM_LIGHT_CLAY,
        .moves = {MOVE_REFLECT, MOVE_LIGHTSCREEN, MOVE_DRAINPUNCH, MOVE_HIDDENPOWER},
    },
    {
        .lvl = 0,
        .species = SPECIES_HAKAMO_O,
        .ability = Ability_Hidden, // multiscale
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SKYUPPERCUT, MOVE_DRAGONTAIL, MOVE_WORKUP, MOVE_PROTECT},
    },
    {
        .lvl = 0,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_EXPERT_BELT,
        .moves = {MOVE_MACHPUNCH, MOVE_SPORE, MOVE_BULLETSEED, MOVE_DRAINPUNCH},
    },
    {
        .lvl = 0,
        .species = SPECIES_HITMONCHAN,
        .ability = Ability_2, // iron fist
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_COBA_BERRY,
        .moves = {MOVE_MACHPUNCH, MOVE_BULLETPUNCH, MOVE_PURSUIT, MOVE_FAKEOUT},
    },
    {
        .lvl = 0,
        .species = SPECIES_HARIYAMA,
        .ability = Ability_1, // thick fat
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_KNOCKOFF, MOVE_CROSSCHOP, MOVE_BULLETPUNCH},
    },
};
static const struct TrainerMonItemCustomMoves sParty_Fuschia_LeaderTateLiza[] = {
    {
        .lvl = 0,
        .species = SPECIES_HATTERENE,
        .ability = Ability_Hidden, // magic bounce
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_EXPANDINGFORCE, MOVE_DRAININGKISS, MOVE_MYSTICALFIRE, MOVE_PROTECT},
    },
    {
        .lvl = 0,
        .species = SPECIES_INDEEDEE,
        .ability = Ability_Hidden, // psychic surge
        .nature = NATURE_TIMID,
        .ivSpread = {IV_HP_ICE},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_EXPANDINGFORCE, MOVE_FAKEOUT, MOVE_HIDDENPOWER, MOVE_PROTECT},
    },
    {
        .lvl = 0,
        .species = SPECIES_SIGILYPH,
        .ability = Ability_Hidden, // tinted lens
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_EXPERT_BELT,
        .moves = {MOVE_AIRSLASH, MOVE_HEATWAVE, MOVE_ENERGYBALL, MOVE_PSYSHOCK},
    },
    {
        .lvl = 0,
        .species = SPECIES_MEDICHAM,
        .ability = Ability_Hidden, // pure power
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_ZENHEADBUTT, MOVE_DRAINPUNCH, MOVE_ICEPUNCH, MOVE_BULLETPUNCH},
    },
    {
        .lvl = 2,
        .species = SPECIES_GALLADE,
        .ability = Ability_Hidden, // blademaster / intrepid sword
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_HP_ICE},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_GALLADITE,
        .moves = {MOVE_CLOSECOMBAT, MOVE_ZENHEADBUTT, MOVE_KNOCKOFF, MOVE_HIDDENPOWER},
    },
    {
        .lvl = 2,
        .species = SPECIES_GARDEVOIR,
        .ability = Ability_2, // trace / pixilate
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_GARDEVOIRITE,
        .moves = {MOVE_EXPANDINGFORCE, MOVE_HYPERVOICE, MOVE_TAUNT, MOVE_FOCUSBLAST},
    },
};
static const struct TrainerMonItemCustomMoves sParty_SchoolKidM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_SchoolKidF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_SrAndJr[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_PokefanM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_PokefanF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_ExpertM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_ExpertF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSYoungster[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSChampion[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSFisherman[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_CyclingTriathleteM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_CyclingTriathleteF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RunningTriathleteM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RunningTriathleteF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_SwimmingTriathleteM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_SwimmingTriathleteF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_DragonTamer[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSBirdKeeper[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_NinjaBoy[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_BattleGirl[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_ParasolLady[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSSwimmerF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSPicnicker[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSTwins[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSSailor[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_BoarderM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_BoarderF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_Collector[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_Wally[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_Brendan[] = {
    {
        .lvl = -15,
        .species = SPECIES_MAGNEMITE,
        .ability = Ability_2, // sturdy
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MAGNETBOMB, MOVE_THUNDERWAVE, MOVE_THUNDERSHOCK},
    },
    {
        .lvl = -15,
        .species = SPECIES_RALTS,
        .ability = Ability_2, // trace
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DISARMINGVOICE, MOVE_CONFUSION},
    },
    
};
static const struct TrainerMonItemCustomMoves sParty_Brendan2[] = {
    {
        .lvl = 1,
        .species = SPECIES_RIBOMBEE,
        .ability = Ability_2, // shield dust
        .nature = NATURE_TIMID,
        .ivSpread = {IV_HP_FIRE},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_FOCUS_SASH,
        .moves = {MOVE_MOONBLAST, MOVE_STUNSPORE, MOVE_STICKYWEB, MOVE_HIDDENPOWER},
    },
    {
        .lvl = 1,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_Hidden, // excadrill
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_HP_ICE},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRONHEAD, MOVE_HIDDENPOWER, MOVE_SWORDSDANCE},
    },
    {
        .lvl = 1,
        .species = SPECIES_HYDREIGON,
        .ability = Ability_1, // levitate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_DARKPULSE, MOVE_EARTHPOWER, MOVE_NASTYPLOT, MOVE_ROOST},
    },
    {
        .lvl = 1,
        .species = SPECIES_DRACOVISH,
        .ability = Ability_2, // strong jaw
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_FISHIOUSREND, MOVE_PSYCHICFANGS, MOVE_CRUNCH, MOVE_EARTHQUAKE},
    },
    {
        .lvl = 1,
        .species = SPECIES_MAGNEZONE,
        .ability = Ability_1, // magnet pull
        .nature = NATURE_MODEST,
        .ivSpread = {IV_HP_FIRE},
        .evSpread = {0, 0, 4, 252, 0, 252},
        .heldItem = ITEM_CHOICE_SPECS,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLTSWITCH, MOVE_HIDDENPOWER, MOVE_FLASHCANNON},
    },
    {
        .lvl = 2,
        .species = SPECIES_GALLADE,
        .ability = Ability_Hidden, // blademaster / intrepid sword
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_GALLADITE,
        .moves = {MOVE_CLOSECOMBAT, MOVE_SWORDSDANCE, MOVE_ZENHEADBUTT, MOVE_NIGHTSLASH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_Brendan3[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_May_PlayerHouse_Oshawott[] = {
    {
        .lvl = 0,
        .species = SPECIES_OSHAWOTT,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TACKLE},
    },
};
static const struct TrainerMonItemCustomMoves sParty_May_PlayerHouse_Tepig[] = {
    {
        .lvl = 0,
        .species = SPECIES_TEPIG,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TACKLE},
    },
};
static const struct TrainerMonItemCustomMoves sParty_May_PlayerHouse_Snivy[] = {
    {
        .lvl = 0,
        .species = SPECIES_SNIVY,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TACKLE},
    },
};
static const struct TrainerMonItemCustomMoves sParty_RSPkmnBreederM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_Route5_Traynee[] = {
    {
        .lvl = 0,
        .species = SPECIES_CHANSEY,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_ZERO},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HEALINGWISH},
    },
    {
        .lvl = 0,
        .species = SPECIES_CHANSEY,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_ZERO},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HEALINGWISH},
    },
    {
        .lvl = 0,
        .species = SPECIES_CHANSEY,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_ZERO},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HEALINGWISH},
    },
    {
        .lvl = 0,
        .species = SPECIES_CHANSEY,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_ZERO},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HEALINGWISH},
    },
    {
        .lvl = 0,
        .species = SPECIES_CHANSEY,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_ZERO},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HEALINGWISH},
    },
    {
        .lvl = 0,
        .species = SPECIES_CHANSEY,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_ZERO},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HEALINGWISH},
    },
};
static const struct TrainerMonItemCustomMoves sParty_RSPkmnRangerM[] = {DUMMY_TRAINER_MON_IV};
static const struct TrainerMonItemCustomMoves sParty_RSPkmnRangerF[] = {DUMMY_TRAINER_MON_IV};
static const struct TrainerMonItemCustomMoves sParty_MagmaLeader[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_MagmaGruntM[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_MagmaGruntF[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSLass[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSBugCatcher[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSHiker[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSYoungCouple[] = {DUMMY_TRAINER_MON, DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_OldCouple[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_RSSisAndBro[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_AquaAdminMatt[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_AquaAdminShelly[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_MagmaAdminTabitha[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_MagmaAdminCourtney[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_Vermillion_LeaderWattson[] = {
    {
        .lvl = 0,
        .species = SPECIES_DEDENNE,
        .ability = Ability_Hidden, // electric surge
        .nature = NATURE_BOLD,
        .ivSpread = {IV_HP_ICE},
        .evSpread = {EV_60},
        .heldItem = ITEM_TERRAIN_EXTENDER,
        .moves = {MOVE_SNARL, MOVE_THUNDERWAVE, MOVE_ROAR, MOVE_HIDDENPOWER},
    },
    {
        .lvl = 0,
        .species = SPECIES_ROTOM_FROST,
        .ability = Ability_1, // levitate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_HP_ICE},
        .evSpread = {EV_60},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SHADOWBALL, MOVE_VOLTSWITCH, MOVE_HIDDENPOWER, MOVE_PAINSPLIT},
    },
    {
        .lvl = 0,
        .species = SPECIES_RAICHU_A,
        .ability = Ability_1, // surge surfer
        .nature = NATURE_MODEST,
        .ivSpread = {IV_HP_FIGHTING},
        .evSpread = {EV_60},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_VOLTSWITCH, MOVE_PSYSHOCK, MOVE_AGILITY, MOVE_HIDDENPOWER},
    },
    {
        .lvl = 0,
        .species = SPECIES_ELECTIVIRE,
        .ability = Ability_1, // motor drive
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_DRAINPUNCH, MOVE_THUNDERPUNCH, MOVE_MACHPUNCH, MOVE_ICEPUNCH},
    },
    {
        .lvl = 2,
        .species = SPECIES_MANECTRIC,
        .ability = Ability_Hidden, // intimidate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_HP_ICE},
        .evSpread = {EV_60},
        .heldItem = ITEM_AIR_BALLOON,
        .moves = {MOVE_FLAMETHROWER, MOVE_VOLTSWITCH, MOVE_HIDDENPOWER, MOVE_SIGNALBEAM},
    },
};
static const struct TrainerMonItemCustomMoves sParty_LeaderFlannery[] = {
    {
        .lvl = 2,
        .species = SPECIES_TORKOAL,
        .ability = Ability_2, // drought
        .nature = NATURE_BOLD,
        .ivSpread = {IV_HP_GROUND},
        .evSpread = {EV_80},
        .heldItem = ITEM_HEAT_ROCK,
        .moves = {MOVE_LAVAPLUME, MOVE_YAWN, MOVE_STEALTHROCK, MOVE_HIDDENPOWER},
    },
    {
        .lvl = 0,
        .species = SPECIES_BLAZIKEN,
        .ability = Ability_Hidden, // speed boost
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_80},
        .heldItem = ITEM_WEAKNESS_POLICY,
        .moves = {MOVE_PROTECT, MOVE_OVERHEAT, MOVE_LOWKICK, MOVE_UTURN},
    },
    {
        .lvl = 0,
        .species = SPECIES_TALONFLAME,
        .ability = Ability_Hidden, // gale wings
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_80},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_FLAREBLITZ, MOVE_ACROBATICS, MOVE_ROOST, MOVE_UTURN},
    },
    {
        .lvl = 0,
        .species = SPECIES_ROTOM_HEAT,
        .ability = Ability_Hidden, // levitate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_80},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_PAINSPLIT, MOVE_VOLTSWITCH, MOVE_OVERHEAT, MOVE_WILLOWISP},
    },
    {
        .lvl = 0,
        .species = SPECIES_ARCANINE,
        .ability = Ability_1, // intimidate
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_EXTREMESPEED, MOVE_MORNINGSUN, MOVE_WILDCHARGE, MOVE_FLAREBLITZ},
    },
    {
        .lvl = 0,
        .species = SPECIES_CHANDELURE,
        .ability = Ability_Hidden, // infiltrator
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_80},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_FLAMETHROWER, MOVE_SHADOWBALL, MOVE_CALMMIND, MOVE_SUBSTITUTE},
    },
};
static const struct TrainerMonItemCustomMoves sParty_Celadon_LeaderNorman[] = {
    {
        .lvl = 0,
        .species = SPECIES_ZANGOOSE,
        .ability = Ability_1, // touch claws
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_KNOCKOFF, MOVE_XSCISSOR, MOVE_PURSUIT, MOVE_CRUSHCLAW},
    },
    {
        .lvl = 0,
        .species = SPECIES_BRAVIARY,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_BRAVEBIRD, MOVE_BULKUP, MOVE_ROOST, MOVE_SUBSTITUTE},
    },
    {
        .lvl = 0,
        .species = SPECIES_PORYGON2,
        .ability = Ability_1, // trace
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_EVIOLITE,
        .moves = {MOVE_RECOVER, MOVE_ICEBEAM, MOVE_FOULPLAY, MOVE_THUNDERWAVE},
    },
    {
        .lvl = 0,
        .species = SPECIES_PYROAR,
        .ability = Ability_Hidden, // royalty
        .nature = NATURE_MODEST,
        .ivSpread = {IV_HP_GRASS},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_CHOICE_SPECS,
        .moves = {MOVE_FIREBLAST, MOVE_HYPERVOICE, MOVE_HIDDENPOWER, MOVE_TAUNT},
    },
    {
        .lvl = 0,
        .species = SPECIES_LOPUNNY,
        .ability = Ability_2, // dazzling / scrappy
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LOPUNNITE,
        .moves = {MOVE_STRENGTH, MOVE_UTURN, MOVE_ICEPUNCH, MOVE_MACHPUNCH},
    },
    {
        .lvl = 2,
        .species = SPECIES_SLAKING,
        .ability = Ability_1, // glutonny
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_SLACKOFF, MOVE_EARTHQUAKE, MOVE_STRENGTH, MOVE_PURSUIT},
    },
};
static const struct TrainerMonItemCustomMoves sParty_Route16_LeaderWinona[] = {
    {
        .lvl = 0,
        .species = SPECIES_SKARMORY,
        .ability = Ability_1, // sturdy
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = {MOVE_ROOST, MOVE_TAILWIND, MOVE_WHIRLWIND, MOVE_SPIKES},
    },
    {
        .lvl = 0,
        .species = SPECIES_HAWLUCHA,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_HP_DARK},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_HIDDENPOWER, MOVE_HIGHJUMPKICK, MOVE_ROOST, MOVE_BRAVEBIRD},
    },
    {
        .lvl = 0,
        .species = SPECIES_TOGEKISS,
        .ability = Ability_1, // serene grace
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_AIRSLASH, MOVE_THUNDERWAVE, MOVE_TRICK, MOVE_ROOST},
    },
    {
        .lvl = 0,
        .species = SPECIES_GLISCOR,
        .ability = Ability_Hidden, // poison heal
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {244, 0, 52, 0, 76, 136},
        .heldItem = ITEM_TOXIC_ORB,
        .moves = {MOVE_EARTHQUAKE, MOVE_DEFOG, MOVE_ROOST, MOVE_KNOCKOFF},
    },
    {
        .lvl = 0,
        .species = SPECIES_NOIVERN,
        .ability = Ability_2, // infiltrator
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 252, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_HURRICANE, MOVE_TAUNT, MOVE_ROOST, MOVE_UTURN},
    },
    {
        .lvl = 2,
        .species = SPECIES_ALTARIA,
        .ability = Ability_1, // natural cure / pixilate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_ALTARIANITE,
        .moves = {MOVE_DRAGONDANCE, MOVE_ROOST, MOVE_RETURN, MOVE_FIREBLAST},
    },
};
static const struct TrainerMonItemCustomMoves sParty_Route20_LeaderWallace[] = {
    {
        .lvl = 0,
        .species = SPECIES_PELIPPER,
        .ability = Ability_Hidden, // drizzle
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 56, 0, 200, 0},
        .heldItem = ITEM_DAMP_ROCK,
        .moves = {MOVE_SCALD, MOVE_UTURN, MOVE_ROOST, MOVE_HURRICANE},
    },
    {
        .lvl = 0,
        .species = SPECIES_KINGDRA,
        .ability = Ability_1, // swift swim
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_CHOICE_SPECS,
        .moves = {MOVE_SURF, MOVE_HURRICANE, MOVE_DRACOMETEOR, MOVE_ICEBEAM},
    },
    {
        .lvl = 0,
        .species = SPECIES_GOLISOPOD,
        .ability = Ability_Hidden, // tough claws
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_FIRSTIMPRESSION, MOVE_SUCKERPUNCH, MOVE_AQUAJET, MOVE_LEECHLIFE},
    },
    {
        .lvl = 0,
        .species = SPECIES_GRENINJA,
        .ability = Ability_Hidden, // protean
        .nature = NATURE_HASTY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_EXPERT_BELT,
        .moves = {MOVE_DIG, MOVE_ICEBEAM, MOVE_GUNKSHOT, MOVE_UTURN},
    },
    {
        .lvl = 0,
        .species = SPECIES_SWAMPERT,
        .ability = Ability_Hidden, // swift swim
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_SWAMPERTITE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICEPUNCH, MOVE_FLIPTURN, MOVE_WATERFALL},
    },
    {
        .lvl = 2,
        .species = SPECIES_MILOTIC,
        .ability = Ability_1, // competitive
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 126, 4, 126, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SCALD, MOVE_RECOVER, MOVE_HAZE, MOVE_ICEBEAM},
    },
};
static const struct TrainerMonItemCustomMoves sParty_EliteFourGlacia[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_EliteFourDrake[] = {DUMMY_TRAINER_MON};

// Start of actual trainer data
static const struct TrainerMonItemCustomMoves sParty_YoungsterBen[] = {
    {
        .lvl = -2,
        .species = SPECIES_RUFFLET,
        .ability = Ability_Hidden, // hustle
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_ORAN_BERRY,
        .moves = {MOVE_QUICKATTACK, MOVE_AERIALACE, MOVE_HONECLAWS},
    },
    {
        .lvl = -2,
        .species = SPECIES_SKWOVET,
        .ability = Ability_Hidden, // gluttony
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_ORAN_BERRY,
        .moves = {MOVE_STUFFCHEEKS, MOVE_BITE, MOVE_SUPERFANG, MOVE_BULLETSEED},
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterCalvin[] = {
    {
        .lvl = -2,
        .species = SPECIES_PORYGON,
        .ability = Ability_2, // download
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SIGNALBEAM, MOVE_PSYBEAM, MOVE_THUNDERSHOCK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterJosh[] = {
    {
        .lvl = -2,
        .species = SPECIES_RATTATA,
        .ability = Ability_Hidden, // hustle
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERFANG, MOVE_CRUNCH, MOVE_PURSUIT, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_SANDILE,
        .ability = Ability_1, // initimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DIG, MOVE_BITE, MOVE_SANDTOMB},
    },
    {
        .lvl = -2,
        .species = SPECIES_TIMBURR,
        .ability = Ability_Hidden, // iron fist
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_LOWKICK, MOVE_ROCKTHROW, MOVE_SLAM, MOVE_WAKEUPSLAP},
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterTimmy[] = {
    {
        .lvl = -2,
        .species = SPECIES_SANDSLASH_A,
        .ability = Ability_1, // slush rush
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ICEPUNCH, MOVE_HAIL, MOVE_RAPIDSPIN, MOVE_COUNTER},
    },
    {
        .lvl = -2,
        .species = SPECIES_SEVIPER,
        .ability = Ability_Hidden, // fatal precision
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_POISONTAIL, MOVE_GLARE, MOVE_HAZE, MOVE_BITE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterJoey[] = {
    {
        .lvl = -2,
        .species = SPECIES_RATICATE_A,
        .ability = Ability_2, // hustle
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUPERFANG, MOVE_PURSUIT, MOVE_COUNTER},
    },
    {
        .lvl = -2,
        .species = SPECIES_STARAVIA,
        .ability = Ability_2, // intimidate
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WINGATTACK, MOVE_WHIRLWIND, MOVE_ENDEAVOR},
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterDan[] = {
    {
        .lvl = -2,
        .species = SPECIES_SLOWPOKE_G,
        .ability = Ability_1, // quick draw
        .nature = NATURE_RELAXED,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ZENHEADBUTT, MOVE_WATERPULSE, MOVE_YAWN, MOVE_ACID},
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterChad[] = {
    {
        .lvl = -2,
        .species = SPECIES_RATICATE_A,
        .ability = Ability_2, // hustle
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUPERFANG, MOVE_PURSUIT, MOVE_COUNTER},
    },
    {
        .lvl = -2,
        .species = SPECIES_SLOWPOKE_G,
        .ability = Ability_1, // quick draw
        .nature = NATURE_RELAXED,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ZENHEADBUTT, MOVE_WATERPULSE, MOVE_YAWN, MOVE_ACID},
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterTyler[] = {
    {
        .lvl = -2,
        .species = SPECIES_ARBOK,
        .ability = Ability_1, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_BULLDOZE, MOVE_FIREFANG, MOVE_THUNDERFANG},
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterEddie[] = {
    {
        .lvl = -2,
        .species = SPECIES_ELECTABUZZ,
        .ability = Ability_1, // static
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_THUNDERPUNCH, MOVE_LOWKICK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterDillon[] = {
    {
        .lvl = -2,
        .species = SPECIES_SANDSLASH,
        .ability = Ability_1, // speed boost
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ARMTHRUST, MOVE_DIG, MOVE_POWERUPPUNCH, MOVE_POISONSTING},
    },
    {
        .lvl = -2,
        .species = SPECIES_SWOOBAT,
        .ability = Ability_Hidden, // simple
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CONFUSION, MOVE_AIRCUTTER, MOVE_ENDEAVOR, MOVE_AMNESIA},
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterYasu[] = {
    {
        .lvl = -2,
        .species = SPECIES_RATICATE,
        .ability = Ability_Hidden, // hustle
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_SUPERFANG, MOVE_COUNTER, MOVE_PURSUIT},
    },
    {
        .lvl = -2,
        .species = SPECIES_LINOONE,
        .ability = Ability_Hidden, // quick feet
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HEADBUTT, MOVE_BABYDOLLEYES},
    },
    {
        .lvl = -2,
        .species = SPECIES_GUMSHOOS,
        .ability = Ability_2, // strong jaw
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FIREFANG, MOVE_SUPERFANG, MOVE_ICEFANG, MOVE_THUNDERFANG},
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterDave[] = {
    {
        .lvl = -2,
        .species = SPECIES_KADABRA,
        .ability = Ability_2, // sage power
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYBEAM, MOVE_REFLECT},
    },
    {
        .lvl = -2,
        .species = SPECIES_HAUNTER,
        .ability = Ability_1, // levitate
        .nature = NATURE_RELAXED,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TOXIC, MOVE_CONFUSERAY, MOVE_WILLOWISP, MOVE_HEX},
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterBen2[] = {
    {
        .lvl = 17,
        .species = SPECIES_RATTATA,
    },
    {
        .lvl = 17,
        .species = SPECIES_EKANS,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherRick[] = {
    {
        .lvl = -2,
        .species = SPECIES_WURMPLE,
        .ability = Ability_RandomAll,
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .moves = {MOVE_POISONSTING, MOVE_STRINGSHOT, MOVE_BUGBITE},
    },
    {
        .lvl = -2,
        .species = SPECIES_JOLTIK,
        .ability = Ability_Hidden, // compound eyes
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .moves = {MOVE_ELECTROWEB, MOVE_FURYCUTTER, MOVE_ABSORB, MOVE_THUNDERWAVE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherDoug[] = {
    {
        .lvl = -2,
        .species = SPECIES_LEDYBA,
        .ability = Ability_Hidden, //technician
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .moves = {MOVE_POWERUPPUNCH, MOVE_BUGBITE, MOVE_COMETPUNCH, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_CATERPIE,
        .ability = Ability_RandomAll,
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .moves = {MOVE_TACKLE, MOVE_STRINGSHOT, MOVE_NONE, MOVE_NONE},
    },
    {
        .lvl = -2,
        .species = SPECIES_VENONAT,
        .ability = Ability_Hidden, // wonderskin
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .moves = {MOVE_DISABLE, MOVE_SUPERSONIC, MOVE_TOXICSPIKES, MOVE_SLEEPPOWDER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherSammy[] = {
    {
        .lvl = -2,
        .species = SPECIES_JOLTIK,
        .ability = Ability_Hidden, // compound eyes
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .moves = {MOVE_ELECTROWEB, MOVE_FURYCUTTER, MOVE_ABSORB, MOVE_BUGBITE},
    },
    {
        .lvl = -2,
        .species = SPECIES_SKORUPI,
        .ability = Ability_Hidden, // merciless
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .moves = {MOVE_HONECLAWS, MOVE_FELLSTINGER, MOVE_POISONSTING, MOVE_PURSUIT},
    },
    {
        .lvl = -2,
        .species = SPECIES_VOLBEAT,
        .ability = Ability_Hidden, // pranskter
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .moves = {MOVE_STRUGGLEBUG, MOVE_QUICKATTACK, MOVE_CHARGEBEAM, MOVE_INFESTATION},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherColton[] = {
    {
        .lvl = -2,
        .species = SPECIES_PINECO,
        .ability = Ability_RandomAll,
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_SPIKES, MOVE_BUGBITE, MOVE_PROTECT},
    },
    {
        .lvl = -2,
        .species = SPECIES_CUTIEFLY,
        .ability = Ability_RandomAll,
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .moves = {MOVE_DRAININGKISS, MOVE_SILVERWIND, MOVE_STUNSPORE, MOVE_ABSORB},
    },
    {
        .lvl = -2,
        .species = SPECIES_SWADLOON,
        .ability = Ability_RandomAll,
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_BUGBITE, MOVE_RAZORLEAF, MOVE_PROTECT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherGreg[] = {
    {
        .lvl = -2,
        .species = SPECIES_KRICKETOT,
        .ability = Ability_1, // technician
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_BUGBITE},
    },
    {
        .lvl = -2,
        .species = SPECIES_DEWPIDER,
        .ability = Ability_RandomAll,
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_SPIDERWEB, MOVE_BUBBLEBEAM, MOVE_BUGBITE, MOVE_HEADBUTT},
    },
    {
        .lvl = -2,
        .species = SPECIES_SKORUPI,
        .ability = Ability_RandomAll,
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_KNOCKOFF, MOVE_POISONFANG, MOVE_FELLSTINGER, MOVE_PURSUIT},
    },
    {
        .lvl = -2,
        .species = SPECIES_SIZZLIPEDE,
        .ability = Ability_Hidden, // flame body
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .moves = {MOVE_BUGBITE, MOVE_FLAMEWHEEL, MOVE_BITE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherJames[] = {
    {
        .lvl = -2,
        .species = SPECIES_VENONAT,
        .ability = Ability_RandomAll,
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_VENOSHOCK, MOVE_PSYBEAM, MOVE_POISONPOWDER, MOVE_SLEEPPOWDER},
    },
    {
        .lvl = -2,
        .species = SPECIES_ANORITH,
        .ability = Ability_1, // battle armor
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_SMACKDOWN, MOVE_METALCLAW, MOVE_FURYCUTTER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherKent[] = {
    {
        .lvl = -2,
        .species = SPECIES_VIVILLON_CONTINENTAL,
        .ability = Ability_RandomAll,
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_DRAININGKISS, MOVE_STRUGGLEBUG, MOVE_STUNSPORE, MOVE_GUST},
    },
    {
        .lvl = -2,
        .species = SPECIES_BEEDRILL,
        .ability = Ability_RandomAll,
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_BUGBITE, MOVE_POISONSTING, MOVE_PURSUIT, MOVE_PECK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherRobby[] = {
    {
        .lvl = -2,
        .species = SPECIES_CUTIEFLY,
        .ability = Ability_RandomAll,
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SILVERWIND, MOVE_STUNSPORE, MOVE_DRAININGKISS, MOVE_ABSORB},
    },
    {
        .lvl = -2,
        .species = SPECIES_WHIRLIPEDE,
        .ability = Ability_Hidden, // speed boost
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_POISONTAIL, MOVE_BUGBITE, MOVE_ROLLOUT, MOVE_IRONDEFENSE},
    },
    {
        .lvl = -2,
        .species = SPECIES_CHARJABUG,
        .ability = Ability_1, // battery
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BUGBITE, MOVE_SPARK, MOVE_DIG, MOVE_ACROBATICS},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherCale[] = {
    {
        .lvl = -2,
        .species = SPECIES_BUTTERFREE,
        .ability = Ability_1, // compound eyes
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYBEAM, MOVE_SILVERWIND, MOVE_SLEEPPOWDER, MOVE_WHIRLWIND},
    },
    {
        .lvl = -2,
        .species = SPECIES_BEEDRILL,
        .ability = Ability_1, // swarm
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BUGBITE, MOVE_PURSUIT, MOVE_PECK, MOVE_RAGE},
    },
    {
        .lvl = -2,
        .species = SPECIES_VIVILLON,
        .ability = Ability_2, // compound eyes
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_STRUGGLE, MOVE_DRAININGKISS, MOVE_POISONPOWDER, MOVE_PROTECT},
    },
    {
        .lvl = -2,
        .species = SPECIES_ARAQUANID,
        .ability = Ability_2, // compound eyes
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BUGBITE, MOVE_WATERSPORT, MOVE_SPIDERWEB, MOVE_BITE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherKeigo[] = {
    {
        .lvl = -2,
        .species = SPECIES_MASQUERAIN,
        .ability = Ability_Hidden, // intimidate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MUDDYWATER, MOVE_STICKYWEB, MOVE_STUNSPORE, MOVE_AIRCUTTER},
    },
    {
        .lvl = -2,
        .species = SPECIES_CHARJABUG,
        .ability = Ability_1, // battery
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_ACROBATICS, MOVE_DIG, MOVE_BUGBITE},
    },
    {
        .lvl = -2,
        .species = SPECIES_LEDIAN,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ACROBATICS, MOVE_POWERUPPUNCH, MOVE_MACHPUNCH, MOVE_BUGBITE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherElijah[] = {
    {
        .lvl = -2,
        .species = SPECIES_BUTTERFREE,
        .ability = Ability_1, // compound eyes
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BUGBUZZ, MOVE_PSYBEAM, MOVE_SLEEPPOWDER, MOVE_WHIRLWIND},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcher2[] = {
    {
        .lvl = 18,
        .species = SPECIES_METAPOD,
    },
    {
        .lvl = 18,
        .species = SPECIES_CATERPIE,
    },
    {
        .lvl = 18,
        .species = SPECIES_VENONAT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherBrent[] = {
    {
        .lvl = -2,
        .species = SPECIES_ORBEETLE,
        .ability = Ability_1, // swarm
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_STRUGGLEBUG, MOVE_MIRRORCOAT, MOVE_PSYBEAM, MOVE_CONFUSERAY},
    },
    {
        .lvl = -2,
        .species = SPECIES_SCYTHER,
        .ability = Ability_2, // technician
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WINGATTACK, MOVE_QUICKATTACK, MOVE_FURYATTACK, MOVE_PURSUIT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherConner[] = {
    {
        .lvl = -2,
        .species = SPECIES_DUSTOX,
        .ability = Ability_RandomAll,
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BUGBUZZ, MOVE_QUIVERDANCE, MOVE_TOXIC, MOVE_VENOSHOCK},
    },
    {
        .lvl = -2,
        .species = SPECIES_ARAQUANID,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MIRRORCOAT, MOVE_BUGBITE, MOVE_CRUNCH, MOVE_SPIDERWEB},
    },
    {
        .lvl = -2,
        .species = SPECIES_RIBOMBEE,
        .ability = Ability_RandomAll,
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_STUNSPORE, MOVE_DAZZLINGGLEAM, MOVE_BUGBUZZ},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassJanice[] = {
    {
        .lvl = -2,
        .species = SPECIES_BRONZOR,
        .ability = Ability_1, // levitate
        .nature = NATURE_CALM,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CONFUSION, MOVE_METALSOUND, MOVE_GYROBALL, MOVE_SAFEGUARD},
    },
    {
        .lvl = -2,
        .species = SPECIES_TOGETIC,
        .ability = Ability_1, // serene grace
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_FAIRYWIND, MOVE_METRONOME, MOVE_ANCIENTPOWER, MOVE_MAGICALLEAF},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassSally[] = {
    {
        .lvl = -2,
        .species = SPECIES_RATTATA,
        .ability = Ability_1, // simple
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_QUICKATTACK, MOVE_HYPERFANG, MOVE_PURSUIT},
    },
    {
        .lvl = -2,
        .species = SPECIES_LILLIPUP,
        .ability = Ability_Hidden, // scrappy
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_QUICKATTACK, MOVE_HYPERFANG, MOVE_PURSUIT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassRobin[] = {
    {
        .lvl = -2,
        .species = SPECIES_SPRITZEE,
        .ability = Ability_2, // fairy aura
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .moves = {MOVE_DRAININGKISS, MOVE_SWEETKISS, MOVE_CHARM, MOVE_DISARMINGVOICE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassCrissy[] = {
    {
        .lvl = -2,
        .species = SPECIES_SHIINOTIC,
        .ability = Ability_2, // effect spore
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .moves = {MOVE_SPORE, MOVE_STRENGTHSAP, MOVE_GIGADRAIN, MOVE_DAZZLINGGLEAM},
    },
    {
        .lvl = -2,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .moves = {MOVE_BULLETSEED, MOVE_MACHPUNCH, MOVE_COUNTER, MOVE_SPORE},
    },
    {
        .lvl = -2,
        .species = SPECIES_AMOONGUSS,
        .ability = Ability_1, // effect spore
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .moves = {MOVE_GIGADRAIN, MOVE_TOXIC, MOVE_SPORE, MOVE_STUNSPORE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassMiriam[] = {
    {
        .lvl = -2,
        .species = SPECIES_PANSAGE,
        .ability = Ability_1, // overgrow
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_ACROBATICS, MOVE_LEECHSEED, MOVE_BITE, MOVE_VINEWHIP},
    },
    {
        .lvl = -2,
        .species = SPECIES_GROVYLE,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_FURYCUTTER, MOVE_QUICKATTACK, MOVE_LEAFBLADE, MOVE_LEAFAGE},
    },
    {
        .lvl = -2,
        .species = SPECIES_SWIRLIX,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_DRAININGKISS, MOVE_LIGHTSCREEN, MOVE_FAKETEARS, MOVE_STRINGSHOT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassIris[] = {
    {
        .lvl = -2,
        .species = SPECIES_CLEFAIRY,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .moves = {MOVE_DISARMINGVOICE, MOVE_CHARM, MOVE_SING, MOVE_METRONOME},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassReli[] = {
    {
        .lvl = -2,
        .species = SPECIES_NIDORINO,
        .ability = Ability_Hidden, // hustle
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TOXICSPIKES, MOVE_DOUBLEKICK, MOVE_HORNATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_NIDORINA,
        .ability = Ability_1, // poison point
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUPERFANG, MOVE_BITE, MOVE_DOUBLEKICK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassAli[] = {
    {
        .lvl = -2,
        .species = SPECIES_CORVISQUIRE,
        .ability = Ability_Hidden, // big pecks
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TAUNT, MOVE_PLUCK},
    },
    {
        .lvl = -2,
        .species = SPECIES_KECLEON,
        .ability = Ability_Hidden, // protean
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWSNEAK, MOVE_FURYSWIPES, MOVE_FEINTATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_LINOONE,
        .ability = Ability_Hidden, // quick feet
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HEADBUTT, MOVE_TAUNT, MOVE_HONECLAWS, MOVE_SNARL},
    },
};

static const struct TrainerMonItemCustomMoves sParty_Lass2[] = {
    {
        .lvl = 15,
        .species = SPECIES_NIDORAN_M,
    },
    {
        .lvl = 15,
        .species = SPECIES_NIDORAN_F,
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassHaley[] = {
    {
        .lvl = -2,
        .species = SPECIES_SKIDDO,
        .ability = Ability_2, // sap sipper
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BULKUP, MOVE_LEECHSEED, MOVE_HORNLEECH},
    },
    {
        .lvl = -2,
        .species = SPECIES_STARAVIA,
        .ability = Ability_2, // intimidate
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WINGATTACK, MOVE_WHIRLWIND, MOVE_ENDEAVOR},
    },
    {
        .lvl = -2,
        .species = SPECIES_WOOLOO,
        .ability = Ability_1, // fluffy
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HEADBUTT, MOVE_DEFENSECURL, MOVE_DOUBLEKICK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassAnn[] = {
    {
        .lvl = -2,
        .species = SPECIES_DELCATTY,
        .ability = Ability_1, // cute charm
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DISARMINGVOICE, MOVE_FAKEOUT, MOVE_CHARM, MOVE_ATTRACT},
    },
    {
        .lvl = -2,
        .species = SPECIES_CHIMECHO,
        .ability = Ability_1, // levitate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EXTRASENSORY, MOVE_YAWN},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassDawn[] = {
    {
        .lvl = -2,
        .species = SPECIES_GREEDENT,
        .ability = Ability_Hidden, // gluttony
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_COUNTER, MOVE_SUPERFANG, MOVE_BULLETSEED, MOVE_BITE},
    },
    {
        .lvl = -2,
        .species = SPECIES_TOGEDEMARU,
        .ability = Ability_RandomAll,
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ZINGZAP, MOVE_PINMISSILE, MOVE_ROLLOUT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassPaige[] = {
    {
        .lvl = -2,
        .species = SPECIES_NIDOQUEEN,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CHIPAWAY, MOVE_CRUNCH, MOVE_SUPERFANG, MOVE_POISONFANG},
    },
    {
        .lvl = -2,
        .species = SPECIES_NIDOKING,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_POISONJAB, MOVE_CHIPAWAY, MOVE_TOXIC, MOVE_COUNTER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassAndrea[] = {
    {
        .lvl = -2,
        .species = SPECIES_PERSIAN,
        .ability = Ability_2, // technician
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FURYSWIPES, MOVE_BITE, MOVE_TAUNT, MOVE_SCREECH},
    },
    {
        .lvl = -2,
        .species = SPECIES_PERSIAN_A,
        .ability = Ability_1, // intimidate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_POWERGEM, MOVE_HYPNOSIS, MOVE_ASSURANCE, MOVE_AMNESIA},
    },
    {
        .lvl = -2,
        .species = SPECIES_THIEVUL,
        .ability = Ability_Hidden, // stakeout
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_NASTYPLOT, MOVE_MYSTICALFIRE, MOVE_NIGHTDAZE, MOVE_SNARL},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassMegan[] = {
    {
        .lvl = -2,
        .species = SPECIES_CORVIKNIGHT,
        .ability = Ability_1, // pressure
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TAUNT, MOVE_STEELWING, MOVE_DRILLPECK, MOVE_SCARYFACE},
    },
    {
        .lvl = -2,
        .species = SPECIES_THIEVUL,
        .ability = Ability_Hidden, // stakeout
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_NASTYPLOT, MOVE_MYSTICALFIRE, MOVE_NIGHTDAZE, MOVE_SNARL},
    },
    {
        .lvl = -2,
        .species = SPECIES_NIDOKING,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_POISONJAB, MOVE_CHIPAWAY, MOVE_TOXIC, MOVE_COUNTER},
    },
    {
        .lvl = -2,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_RandomAll,
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MOONBLAST, MOVE_COSMICPOWER, MOVE_STOREDPOWER, MOVE_MAGICALLEAF},
    },
    {
        .lvl = -2,
        .species = SPECIES_RAICHU,
        .ability = Ability_Hidden, // lightning rod
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_THUNDERBOLT, MOVE_THUNDERWAVE, MOVE_ENCORE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassJulia[] = {
    {
        .lvl = -2,
        .species = SPECIES_WIGGLYTUFF,
        .ability = Ability_RandomAll,
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MOONBLAST, MOVE_BOOMBURST, MOVE_SOFTBOILED, MOVE_AMNESIA},
    },
    {
        .lvl = -2,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_RandomAll,
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MOONBLAST, MOVE_COSMICPOWER, MOVE_STOREDPOWER, MOVE_MAGICALLEAF},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassKay[] = {
    {
        .lvl = -2,
        .species = SPECIES_VICTREEBEL,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_KNOCKOFF, MOVE_LEECHLIFE, MOVE_POISONJAB, MOVE_LEAFBLADE},
    },
    {
        .lvl = -2,
        .species = SPECIES_ELDEGOSS,
        .ability = Ability_Hidden, // effect spore
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_COTTONSPORE, MOVE_LEAFTORNADO, MOVE_SYNTHESIS, MOVE_SING},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassLisa[] = {
    {
        .lvl = -2,
        .species = SPECIES_TORTERRA,
        .ability = Ability_Hidden, // self sufficient
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_RAZORLEAF, MOVE_CRUNCH, MOVE_SYNTHESIS},
    },
    {
        .lvl = -2,
        .species = SPECIES_CHESNAUGHT,
        .ability = Ability_Hidden, // dauntless shield
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_RAZORLEAF, MOVE_LEECHSEED, MOVE_BULKUP, MOVE_BULLDOZE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SailorEdmond[] = {
    {
        .lvl = -2,
        .species = SPECIES_HITMONCHAN,
        .ability = Ability_2, // iron fist
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_THUNDERPUNCH, MOVE_ICEPUNCH, MOVE_FIREPUNCH, MOVE_MACHPUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_WATCHOG,
        .ability = Ability_RandomAll, //
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUPERFANG, MOVE_MEGAKICK, MOVE_CONFUSERAY, MOVE_HYPNOSIS},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SailorTrevor[] = {
    {
        .lvl = -2,
        .species = SPECIES_HITMONLEE,
        .ability = Ability_1, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUCKERPUNCH, MOVE_JUMPKICK, MOVE_FAKEOUT, MOVE_REVENGE},
    },
    {
        .lvl = -2,
        .species = SPECIES_HITMONCHAN,
        .ability = Ability_2, // iron fist
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_THUNDERPUNCH, MOVE_ICEPUNCH, MOVE_FIREPUNCH, MOVE_MACHPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SailorLeonard[] = {
    {
        .lvl = -2,
        .species = SPECIES_BASCULIN_RED,
        .ability = Ability_2, // adaptability
        .nature = NATURE_HASTY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AQUAJET, MOVE_HEADBUTT, MOVE_BITE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SailorDuncan[] = {
    {
        .lvl = -2,
        .species = SPECIES_CORSOLA,
        .ability = Ability_2, // natural cure
        .nature = NATURE_CALM,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CONFUSERAY, MOVE_STRENGTHSAP, MOVE_DISABLE, MOVE_SPITE},
    },
    {
        .lvl = -2,
        .species = SPECIES_LANTURN,
        .ability = Ability_1, // volt absorb
        .nature = NATURE_CALM,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PARABOLICCHARGE, MOVE_BUBBLEBEAM, MOVE_THUNDERWAVE, MOVE_EERIEIMPULSE},
    },
    {
        .lvl = -2,
        .species = SPECIES_WHISCASH,
        .ability = Ability_Hidden, // sap sipper
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MUDDYWATER, MOVE_MUDBOMB, MOVE_REST, MOVE_AMNESIA},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SailorHuey[] = {
    {
        .lvl = -2,
        .species = SPECIES_TENTACRUEL,
        .ability = Ability_2, // liquid ooze
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_POISONJAB, MOVE_BUBBLEBEAM, MOVE_HEX, MOVE_TOXICSPIKES},
    },
    {
        .lvl = -2,
        .species = SPECIES_STARMIE,
        .ability = Ability_2, // natural cure
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_POWERGEM, MOVE_SURF, MOVE_RECOVER, MOVE_PSYBEAM},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SailorDylan[] = {
    {
        .lvl = -2,
        .species = SPECIES_BASCULIN_RED,
        .ability = Ability_2, // adaptability
        .nature = NATURE_HASTY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AQUAJET, MOVE_HEADBUTT, MOVE_BITE},
    },
    {
        .lvl = -2,
        .species = SPECIES_LANTURN,
        .ability = Ability_1, // volt absorb
        .nature = NATURE_CALM,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PARABOLICCHARGE, MOVE_BUBBLEBEAM, MOVE_THUNDERWAVE, MOVE_EERIEIMPULSE},
    },
    {
        .lvl = -2,
        .species = SPECIES_WHISCASH,
        .ability = Ability_Hidden, // sap sipper
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MUDDYWATER, MOVE_MUDBOMB, MOVE_REST, MOVE_AMNESIA},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SailorPhillip[] = {
    {
        .lvl = -2,
        .species = SPECIES_FALINKS,
        .ability = Ability_2, // stamina
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BULKUP, MOVE_FIRSTIMPRESSION, MOVE_HEADBUTT, MOVE_ROCKSMASH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SailorDwayne[] = {
    {
        .lvl = -2,
        .species = SPECIES_PACHIRISU,
        .ability = Ability_1, // prankster
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUPERFANG, MOVE_SWEETKISS, MOVE_THUNDERWAVE, MOVE_SPARK},
    },
    {
        .lvl = -2,
        .species = SPECIES_HELIOLISK,
        .ability = Ability_2, // solar power
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERVOICE, MOVE_PARABOLICCHARGE, MOVE_THUNDERWAVE, MOVE_VOLTSWITCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperLiam[] = {
    {
        .lvl = -2,
        .species = SPECIES_NOSEPASS,
        .ability = Ability_1,
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BLOCK, MOVE_ROCKTHROW, MOVE_SPARK, MOVE_THUNDERWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_CRANIDOS,
        .ability = Ability_Hidden,
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PURSUIT, MOVE_ROCKTHROW, MOVE_HEADBUTT, MOVE_ROCKTOMB},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperShane[] = {
    {
        .lvl = -2,
        .species = SPECIES_ILLUMISE,
        .ability = Ability_Hidden, // prankster
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CHARM, MOVE_ENCORE, MOVE_DRAININGKISS, MOVE_STRUGGLE},
    },
    {
        .lvl = -2,
        .species = SPECIES_MURKROW,
        .ability = Ability_Hidden, // prankster
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WINGATTACK, MOVE_TAUNT, MOVE_PURSUIT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperEthan[] = {
    {
        .lvl = -2,
        .species = SPECIES_HARIYAMA,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_KNOCKOFF, MOVE_FORCEPALM, MOVE_BRINE, MOVE_WHIRLWIND},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperRicky[] = {
    {
        .lvl = -2,
        .species = SPECIES_KINGLER,
        .ability = Ability_2, // battle armor
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HAMMERARM, MOVE_AQUAJET, MOVE_AGILITY, MOVE_METALCLAW},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperJeff[] = {
    {
        .lvl = -2,
        .species = SPECIES_GLIGAR,
        .ability = Ability_1, // hyper cutter
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_UTURN, MOVE_ACROBATICS, MOVE_KNOCKOFF},
    },
    {
        .lvl = -2,
        .species = SPECIES_RATICATE_A,
        .ability = Ability_2, // hustle
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERFANG, MOVE_CRUNCH, MOVE_COUNTER, MOVE_PURSUIT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_Camper2[] = {DUMMY_TRAINER_MON};

static const struct TrainerMonItemCustomMoves sParty_CamperChris[] = {
    {
        .lvl = -2,
        .species = SPECIES_PYROAR,
        .ability = Ability_Hidden, // grim neigh
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FLAMETHROWER, MOVE_DARKPULSE, MOVE_WORKUP, MOVE_NOBLEROAR},
    },
    {
        .lvl = -2,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SOFTBOILED, MOVE_MOONBLAST, MOVE_METRONOME},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperDrew[] = {
    {
        .lvl = -2,
        .species = SPECIES_WATCHOG,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUPERFANG, MOVE_LOWKICK, MOVE_CONFUSERAY, MOVE_CRUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_KOMALA,
        .ability = Ability_1, // comatose
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUCKERPUNCH, MOVE_YAWN, MOVE_RAPIDSPIN, MOVE_WOODHAMMER},
    },
    {
        .lvl = -2,
        .species = SPECIES_DUBWOOL,
        .ability = Ability_1, // fluffy
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SWAGGER, MOVE_DOUBLEKICK, MOVE_COPYCAT, MOVE_HEADBUTT},
    },
    {
        .lvl = -2,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_1, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CLOSECOMBAT, MOVE_WINGATTACK, MOVE_AGILITY, MOVE_ENDEAVOR},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerDiana[] = {
    {
        .lvl = -2,
        .species = SPECIES_KRABBY,
        .ability = Ability_1, // hyper cutter
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AQUAJET, MOVE_METALCLAW},
    },
    {
        .lvl = -2,
        .species = SPECIES_BASCULIN_RED,
        .ability = Ability_2, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AQUAJET, MOVE_HEADBUTT, MOVE_BITE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerNancy[] = {
    {
        .lvl = -2,
        .species = SPECIES_RATICATE_A,
        .ability = Ability_2, // hustle
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERFANG, MOVE_CRUNCH, MOVE_COUNTER, MOVE_PURSUIT},
    },
    {
        .lvl = -2,
        .species = SPECIES_ELECTRODE,
        .ability = Ability_Hidden, // galvanize
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TRIATTACK, MOVE_MAGNETRISE, MOVE_SELFDESTRUCT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerIsabelle[] = {
    {
        .lvl = -2,
        .species = SPECIES_GLIGAR,
        .ability = Ability_1, // hyper cutter
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_UTURN, MOVE_ACROBATICS, MOVE_KNOCKOFF},
    },
    {
        .lvl = -2,
        .species = SPECIES_EMOLGA,
        .ability = Ability_1, // static
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ACROBATICS, MOVE_SPARK, MOVE_ELECTROBALL},
    },
    {
        .lvl = -2,
        .species = SPECIES_DARTRIX,
        .ability = Ability_1, // overgrow
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_LEAFBLADE, MOVE_SHADOWSNEAK, MOVE_PLUCK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerKelsey[] = {
    {
        .lvl = -2,
        .species = SPECIES_NIDORINO,
        .ability = Ability_1, // poison point
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TOXICSPIKES, MOVE_DOUBLEKICK, MOVE_POISONSTING},
    },
    {
        .lvl = -2,
        .species = SPECIES_NIDORINA,
        .ability = Ability_Hidden, // hustle
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TOXICSPIKES, MOVE_DOUBLEKICK, MOVE_POISONSTING, MOVE_SUPERFANG},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerAlicia[] = {
    {
        .lvl = -2,
        .species = SPECIES_VICTREEBEL,
        .ability = Ability_Random_1_2,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_LEECHLIFE, MOVE_KNOCKOFF, MOVE_LEAFBLADE, MOVE_SWORDSDANCE},
    },
    {
        .lvl = -2,
        .species = SPECIES_GASTRODON_EAST,
        .ability = Ability_2, // storm drain
        .nature = NATURE_SASSY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ANCIENTPOWER, MOVE_RECOVER, MOVE_MUDDYWATER, MOVE_ACIDARMOR},
    },
    {
        .lvl = -2,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MACHPUNCH, MOVE_SPORE, MOVE_BULLETSEED, MOVE_COUNTER},
    },
    {
        .lvl = 0,
        .species = SPECIES_MR_MIME,
        .ability = Ability_Random_1_2,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_TRICK, MOVE_ENCORE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerCaitlin[] = {
    {
        .lvl = -2,
        .species = SPECIES_BEWEAR,
        .ability = Ability_1, // fluffy
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PLAYROUGH, MOVE_HAMMERARM, MOVE_BRUTALSWING},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerHeidi[] = {
    {
        .lvl = -2,
        .species = SPECIES_DIGGERSBY,
        .ability = Ability_Hidden, // huge power
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HAMMERARM, MOVE_DIG, MOVE_SWORDSDANCE, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_GREEDENT,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BULLETSEED, MOVE_COUNTER, MOVE_SUPERFANG, MOVE_REST},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerCarol[] = {
    {
        .lvl = -2,
        .species = SPECIES_CORVIKNIGHT,
        .ability = Ability_1, // pressure
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TAUNT, MOVE_STEELWING, MOVE_DRILLPECK, MOVE_SCARYFACE},
    },
    {
        .lvl = -2,
        .species = SPECIES_GLISCOR,
        .ability = Ability_RandomAll,
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_SWORDSDANCE, MOVE_ACROBATICS, MOVE_THUNDERFANG},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerSofia[] = {
    {
        .lvl = -2,
        .species = SPECIES_DONPHAN,
        .ability = Ability_1, // sturdy
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_THUNDERFANG, MOVE_KNOCKOFF, MOVE_BULLDOZE},
    },
    {
        .lvl = -2,
        .species = SPECIES_DIGGERSBY,
        .ability = Ability_Hidden, // huge power
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HAMMERARM, MOVE_DIG, MOVE_SWORDSDANCE, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_GOTHITELLE,
        .ability = Ability_Hidden, // shadow tag
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYSHOCK, MOVE_DARKPULSE, MOVE_NASTYPLOT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerMartha[] = {
    {
        .lvl = -2,
        .species = SPECIES_JUMPLUFF,
        .ability = Ability_Hidden, // aerialte
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_STRENGTHSAP, MOVE_TRIATTACK, MOVE_QUICKATTACK, MOVE_BULLETSEED},
    },
    {
        .lvl = -2,
        .species = SPECIES_AMOONGUSS,
        .ability = Ability_RandomAll,
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TOXIC, MOVE_SPORE, MOVE_GIGADRAIN, MOVE_SLUDGEBOMB},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerTina[] = {
    {
        .lvl = -2,
        .species = SPECIES_VENUSAUR,
        .ability = Ability_2, // thick fat
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGE, MOVE_PETALBLIZZARD, MOVE_LEECHSEED, MOVE_SLEEPPOWDER},
    },
    {
        .lvl = -2,
        .species = SPECIES_SAWSBUCK_WINTER,
        .ability = Ability_Hidden, // serene grace
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HORNLEECH, MOVE_JUMPKICK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerHannah[] = {
    {
        .lvl = 24,
        .species = SPECIES_PIDGEY,
    },
    {
        .lvl = 24,
        .species = SPECIES_MEOWTH,
    },
    {
        .lvl = 24,
        .species = SPECIES_RATTATA,
    },
    {
        .lvl = 24,
        .species = SPECIES_PIKACHU,
    },
    {
        .lvl = 24,
        .species = SPECIES_MEOWTH,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PokemaniacMark[] = {
    {
        .lvl = 29,
        .species = SPECIES_RHYHORN,
    },
    {
        .lvl = 29,
        .species = SPECIES_LICKITUNG,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PokemaniacHerman[] = {
    {
        .lvl = -2,
        .species = SPECIES_MISMAGIUS,
        .ability = Ability_1, // levitate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MOONBLAST, MOVE_SHADOWBALL, MOVE_MYSTICALFIRE, MOVE_POWERGEM},
    },
    {
        .lvl = -2,
        .species = SPECIES_SLOWBRO,
        .ability = Ability_RandomAll,
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLACKOFF, MOVE_CONFUSION, MOVE_SHELLSIDEARM, MOVE_SURF},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PokemaniacCooper[] = {
    {
        .lvl = -2,
        .species = SPECIES_SLOWBRO,
        .ability = Ability_RandomAll,
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLACKOFF, MOVE_CONFUSION, MOVE_SHELLSIDEARM, MOVE_SURF},
    },
    {
        .lvl = -2,
        .species = SPECIES_SLOWKING,
        .ability = Ability_RandomAll,
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CONFUSION, MOVE_SLACKOFF, MOVE_SURF, MOVE_POWERGEM},
    },
    {
        .lvl = -2,
        .species = SPECIES_SLOWKING_G,
        .ability = Ability_2, // gooey
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGEBOMB, MOVE_SLACKOFF, MOVE_CONFUSION, MOVE_POWERGEM},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PokemaniacSteve[] = {
    {
        .lvl = -2,
        .species = SPECIES_CHARIZARD,
        .ability = Ability_1, // blaze
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FLAMEBURST, MOVE_WINGATTACK, MOVE_METALCLAW, MOVE_DRAGONCLAW},
    },
    {
        .lvl = -2,
        .species = SPECIES_MAROWAK_A,
        .ability = Ability_Hidden, // cursed body
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWBONE, MOVE_STOMPINGTANTRUM, MOVE_FLAMEWHEEL, MOVE_SWORDSDANCE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PokemaniacWinston[] = {
    {
        .lvl = -2,
        .species = SPECIES_SMEARGLE,
        .ability = Ability_Hidden, // moody
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWBALL, MOVE_FLAMETHROWER, MOVE_DARKPULSE, MOVE_SURF},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PokemaniacDawson[] = {
    {
        .lvl = 0,
        .species = SPECIES_HIPPOWDON,
        .ability = Ability_1, // sand stream
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 120, 0, 136, 0},
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = {MOVE_EARTHQUAKE, MOVE_SLACKOFF, MOVE_STEALTHROCK, MOVE_TOXIC},
    },
    {
        .lvl = 0,
        .species = SPECIES_TOXAPEX,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_RELAXED,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_BLACK_SLUDGE,
        .moves = {MOVE_SCALD, MOVE_RECOVER, MOVE_HAZE, MOVE_KNOCKOFF},
    },
    {
        .lvl = 0,
        .species = SPECIES_HYDREIGON,
        .ability = Ability_1, // levitate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 244, 32, 232},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_DARKPULSE, MOVE_EARTHPOWER, MOVE_ROOST, MOVE_NASTYPLOT},
    },
    {
        .lvl = 0,
        .species = SPECIES_DARMANITAN_G,
        .ability = Ability_1, // gorilla tactics
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_ICICLECRASH, MOVE_FLAREBLITZ, MOVE_UTURN, MOVE_EARTHQUAKE},
    },
    {
        .lvl = 0,
        .species = SPECIES_SKARMORY,
        .ability = Ability_1, // sturdy
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = {MOVE_IRONDEFENSE, MOVE_BODYPRESS, MOVE_ROOST, MOVE_SPIKES},
    },
    {
        .lvl = 0,
        .species = SPECIES_METAGROSS,
        .ability = Ability_1, // tough claws
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_METAGROSSITE,
        .moves = {MOVE_METEORMASH, MOVE_ZENHEADBUTT, MOVE_THUNDERPUNCH, MOVE_EARTHQUAKE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PokemaniacAshton[] = {
    {
        .lvl = -2,
        .species = SPECIES_CLAYDOL,
        .ability = Ability_Hidden, // sturdy
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ANCIENTPOWER, MOVE_EXTRASENSORY, MOVE_POWERSPLIT, MOVE_GUARDSPLIT},
    },
    {
        .lvl = -2,
        .species = SPECIES_TREVENANT,
        .ability = Ability_2, // gooey
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WOODHAMMER, MOVE_HORNLEECH, MOVE_SHADOWCLAW},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SuperNerdJovan[] = {
    {
        .lvl = -2,
        .species = SPECIES_MAGNEMITE,
        .ability = Ability_1, // magnet pull
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_THUNDERWAVE, MOVE_THUNDERSHOCK, MOVE_SCREECH, MOVE_MIRRORSHOT},
    },
    {
        .lvl = -2,
        .species = SPECIES_ELGYEM,
        .ability = Ability_Hidden, // analytic
        .nature = NATURE_BOLD,
        .ivSpread = {IV_HP_FIRE},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYBEAM, MOVE_HIDDENPOWER, MOVE_TELEPORT},
    },
    {
        .lvl = -2,
        .species = SPECIES_CHARJABUG,
        .ability = Ability_1, // battery
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BUGBITE, MOVE_SPARK, MOVE_DIG, MOVE_ACROBATICS},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SuperNerdMiguel[] = {
    {
        .lvl = -2,
        .species = SPECIES_KADABRA,
        .ability = Ability_2, // sage power
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TELEPORT, MOVE_CONFUSION, MOVE_NIGHTSHADE},
    },
    {
        .lvl = -2,
        .species = SPECIES_METANG,
        .ability = Ability_2, // clear body
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PURSUIT, MOVE_METALCLAW, MOVE_MAGNETRISE},
    },
    {
        .lvl = -2,
        .species = SPECIES_ROTOM,
        .ability = Ability_1, // levitate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_OMINOUSWIND, MOVE_SHOCKWAVE, MOVE_THUNDERWAVE, MOVE_CONFUSERAY},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SuperNerdAidan[] = {
    {
        .lvl = -2,
        .species = SPECIES_LUXRAY,
        .ability = Ability_2, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUCKERPUNCH, MOVE_THUNDERFANG, MOVE_ROAR, MOVE_THUNDERWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_MUK_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_POISONFANG, MOVE_DISABLE, MOVE_ACIDARMOR},
    },
    {
        .lvl = -2,
        .species = SPECIES_MAGNEZONE,
        .ability = Ability_1, // magnet pull
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DISCHARGE, MOVE_FLASHCANNON, MOVE_THUNDERWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_TOXTRICITY,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHOCKWAVE, MOVE_TAUNT, MOVE_ACIDSPRAY, MOVE_NUZZLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SuperNerdGlenn[] = {
    {
        .lvl = -2,
        .species = SPECIES_MUK_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_POISONFANG, MOVE_DISABLE, MOVE_ACIDARMOR},
    },
    {
        .lvl = -2,
        .species = SPECIES_CORVIKNIGHT,
        .ability = Ability_1, // pressure
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TAUNT, MOVE_STEELWING, MOVE_DRILLPECK},
    },
    {
        .lvl = -2,
        .species = SPECIES_TOXTRICITY,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHOCKWAVE, MOVE_TAUNT, MOVE_ACIDSPRAY, MOVE_NUZZLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SuperNerdLeslie[] = {
    {
        .lvl = -2,
        .species = SPECIES_MUK_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_POISONFANG, MOVE_DISABLE, MOVE_ACIDARMOR},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SuperNerd1[] = {
    {
        .lvl = 22,
        .species = SPECIES_KOFFING,
    },
    {
        .lvl = 22,
        .species = SPECIES_MAGNEMITE,
    },
    {
        .lvl = 22,
        .species = SPECIES_WEEZING,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SuperNerd2[] = {
    {
        .lvl = 20,
        .species = SPECIES_MAGNEMITE,
    },
    {
        .lvl = 20,
        .species = SPECIES_MAGNEMITE,
    },
    {
        .lvl = 20,
        .species = SPECIES_KOFFING,
    },
    {
        .lvl = 20,
        .species = SPECIES_MAGNEMITE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SuperNerd3[] = {
    {
        .lvl = 24,
        .species = SPECIES_MAGNEMITE,
    },
    {
        .lvl = 24,
        .species = SPECIES_VOLTORB,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SuperNerdErik[] = {
    {
        .lvl = -2,
        .species = SPECIES_NINETALES,
        .ability = Ability_Hidden, // drought
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 4, 252, 0},
        .heldItem = ITEM_HEAT_ROCK,
        .moves = {MOVE_LIGHTSCREEN, MOVE_ROAR, MOVE_DISABLE, MOVE_FIREBLAST},
    },
    {
        .lvl = -2,
        .species = SPECIES_RAPIDASH,
        .ability = Ability_Hidden, // moxie
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 252, 0, 0, 4, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_MEGAHORN, MOVE_SOLARBLADE, MOVE_FLAREBLITZ, MOVE_HIGHHORSEPOWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SuperNerdAvery[] = {
    {
        .lvl = -2,
        .species = SPECIES_NINETALES,
        .ability = Ability_Hidden, // drought
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 4, 252, 0},
        .heldItem = ITEM_HEAT_ROCK,
        .moves = {MOVE_LIGHTSCREEN, MOVE_ROAR, MOVE_DISABLE, MOVE_FIREBLAST},
    },
    {
        .lvl = -2,
        .species = SPECIES_RAPIDASH,
        .ability = Ability_Hidden, // moxie
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 252, 0, 0, 4, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_MEGAHORN, MOVE_SOLARBLADE, MOVE_FLAREBLITZ, MOVE_HIGHHORSEPOWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SuperNerdDerek[] = {
    {
        .lvl = -2,
        .species = SPECIES_NINETALES,
        .ability = Ability_Hidden, // drought
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 4, 252, 0},
        .heldItem = ITEM_HEAT_ROCK,
        .moves = {MOVE_LIGHTSCREEN, MOVE_ROAR, MOVE_DISABLE, MOVE_FIREBLAST},
    },
    {
        .lvl = -2,
        .species = SPECIES_RAPIDASH,
        .ability = Ability_Hidden, // moxie
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 252, 0, 0, 4, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_MEGAHORN, MOVE_SOLARBLADE, MOVE_FLAREBLITZ, MOVE_HIGHHORSEPOWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SuperNerdZac[] = {
    {
        .lvl = -2,
        .species = SPECIES_NINETALES,
        .ability = Ability_Hidden, // drought
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 4, 252, 0},
        .heldItem = ITEM_HEAT_ROCK,
        .moves = {MOVE_LIGHTSCREEN, MOVE_ROAR, MOVE_DISABLE, MOVE_FIREBLAST},
    },
    {
        .lvl = -2,
        .species = SPECIES_RAPIDASH,
        .ability = Ability_Hidden, // moxie
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 252, 0, 0, 4, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_MEGAHORN, MOVE_SOLARBLADE, MOVE_FLAREBLITZ, MOVE_HIGHHORSEPOWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerMarcos[] = {
    {
        .lvl = -2,
        .species = SPECIES_SANDYGAST,
        .ability = Ability_1, // water compaction
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MEGADRAIN, MOVE_HYPNOSIS, MOVE_MUDSHOT, MOVE_ASTONISH},
    },
    {
        .lvl = -2,
        .species = SPECIES_HIPPOPOTAS,
        .ability = Ability_1, // sand stream
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ROAR, MOVE_YAWN, MOVE_THUNDERFANG, MOVE_FIREFANG},
    },
    {
        .lvl = -2,
        .species = SPECIES_GEODUDE_A,
        .ability = Ability_Hidden, // galvanize
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TAKEDOWN, MOVE_ROCKPOLISH, MOVE_SMACKDOWN},
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerFranklin[] = {
    {
        .lvl = -2,
        .species = SPECIES_GURDURR,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ROCKTHROW, MOVE_LOWKICK, MOVE_CHIPAWAY},
    },
    {
        .lvl = -2,
        .species = SPECIES_SUDOWOODO,
        .ability = Ability_1, // sturdy
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ROCKTOMB, MOVE_TEARFULLOOK, MOVE_WOODHAMMER, MOVE_LOWKICK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerNob[] = {
    {
        .lvl = -2,
        .species = SPECIES_GRAVELER_A,
        .ability = Ability_Hidden, // galvanize
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ROCKPOLISH, MOVE_TAKEDOWN, MOVE_ROCKTHROW},
    },
    {
        .lvl = -2,
        .species = SPECIES_ARCHEN,
        .ability = Ability_Hidden, // tough claws
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PLUCK, MOVE_ROCKTHROW},
    },
    {
        .lvl = -2,
        .species = SPECIES_MUDBRAY,
        .ability = Ability_2, // stamina
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BULLDOZE, MOVE_COUNTER, MOVE_ROCKSMASH},
    },
    {
        .lvl = -2,
        .species = SPECIES_GURDURR,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ROCKTHROW, MOVE_LOWKICK, MOVE_CHIPAWAY},
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerWayne[] = {
    {
        .lvl = 0,
        .species = SPECIES_ONIX,
        .ability = Ability_Hidden, // weak armor
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ROCKTOMB, MOVE_DRAGONBREATH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerAlan[] = {
    {
        .lvl = -2,
        .species = SPECIES_SUDOWOODO,
        .ability = Ability_Hidden, // rock head
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WOODHAMMER, MOVE_COPYCAT, MOVE_ROCKSLIDE, MOVE_SUCKERPUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_BARBARACLE,
        .ability = Ability_1, // tough claws
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ROCKPOLISH, MOVE_ROCKSLIDE, MOVE_NIGHTSLASH, MOVE_RAZORSHELL},
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerBrice[] = {
    {
        .lvl = -2,
        .species = SPECIES_CRUSTLE,
        .ability = Ability_1, // sturdy
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHELLSMASH, MOVE_XSCISSOR, MOVE_ROCKPOLISH, MOVE_ROCKSLIDE},
    },
    {
        .lvl = -2,
        .species = SPECIES_OMASTAR,
        .ability = Ability_2, // adrenaline
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHELLSMASH, MOVE_SURF, MOVE_ANCIENTPOWER},
    },
    {
        .lvl = -2,
        .species = SPECIES_LYCANROC_N,
        .ability = Ability_Hidden, // tough claws
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_ROCKSLIDE, MOVE_TAUNT, MOVE_COUNTER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerClark[] = {
    {
        .lvl = -2,
        .species = SPECIES_CARBINK,
        .ability = Ability_RandomAll,
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_REFLECT, MOVE_LIGHTSCREEN, MOVE_ROCKSLIDE},
    },
    {
        .lvl = -2,
        .species = SPECIES_CARRACOSTA,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AQUAJET, MOVE_KNOCKOFF, MOVE_ROCKSLIDE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerTrent[] = {
    {
        .lvl = -2,
        .species = SPECIES_RAMPARDOS,
        .ability = Ability_1, // mold breaker
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ROCKSLIDE, MOVE_ZENHEADBUTT, MOVE_PURSUIT, MOVE_HEADBUTT},
    },
    {
        .lvl = -2,
        .species = SPECIES_CARRACOSTA,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AQUAJET, MOVE_KNOCKOFF, MOVE_ROCKSLIDE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerDudley[] = {
    {
        .lvl = -2,
        .species = SPECIES_CRUSTLE,
        .ability = Ability_1, // sturdy
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHELLSMASH, MOVE_XSCISSOR, MOVE_ROCKPOLISH, MOVE_ROCKSLIDE},
    },
    {
        .lvl = -2,
        .species = SPECIES_OMASTAR,
        .ability = Ability_2, // adrenaline
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHELLSMASH, MOVE_SURF, MOVE_ANCIENTPOWER},
    },
    {
        .lvl = -2,
        .species = SPECIES_LYCANROC_N,
        .ability = Ability_Hidden, // tough claws
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_ROCKSLIDE, MOVE_TAUNT, MOVE_COUNTER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerAllen[] = {
    {
        .lvl = -2,
        .species = SPECIES_LYCANROC_N,
        .ability = Ability_Hidden, // tough claws
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_ROCKSLIDE, MOVE_TAUNT, MOVE_COUNTER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerEric[] = {
    {
        .lvl = -2,
        .species = SPECIES_CRUSTLE,
        .ability = Ability_1, // sturdy
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHELLSMASH, MOVE_XSCISSOR, MOVE_ROCKPOLISH, MOVE_ROCKSLIDE},
    },
    {
        .lvl = -2,
        .species = SPECIES_GRAPPLOCT,
        .ability = Ability_Hidden, // tehcnican
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FLIPTURN, MOVE_LOWSWEEP, MOVE_BULKUP, MOVE_AQUAJET},
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerLenny[] = {
    {
        .lvl = -2,
        .species = SPECIES_CRADILY,
        .ability = Ability_Hidden, // storm drain
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_LEECHSEED, MOVE_GIGADRAIN, MOVE_CONFUSERAY, MOVE_ANCIENTPOWER},
    },
    {
        .lvl = -2,
        .species = SPECIES_OMASTAR,
        .ability = Ability_2, // adrenaline
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHELLSMASH, MOVE_SURF, MOVE_ANCIENTPOWER},
    },
    {
        .lvl = -2,
        .species = SPECIES_TYRANTRUM,
        .ability = Ability_Hidden, // sturdy
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRAGONTAIL, MOVE_ROAR, MOVE_ROCKTHROW, MOVE_CRUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_AURORUS,
        .ability = Ability_2, // refrigerate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FREEZEDRY, MOVE_BOOMBURST, MOVE_ANCIENTPOWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerOliver[] = {
    {
        .lvl = -2,
        .species = SPECIES_CRADILY,
        .ability = Ability_Hidden, // storm drain
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_LEECHSEED, MOVE_GIGADRAIN, MOVE_CONFUSERAY, MOVE_ANCIENTPOWER},
    },
    {
        .lvl = -2,
        .species = SPECIES_OMASTAR,
        .ability = Ability_2, // adrenaline
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHELLSMASH, MOVE_SURF, MOVE_ANCIENTPOWER},
    },
    {
        .lvl = -2,
        .species = SPECIES_AURORUS,
        .ability = Ability_2, // refrigerate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FREEZEDRY, MOVE_BOOMBURST, MOVE_ANCIENTPOWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerLucas[] = {
    {
        .lvl = -2,
        .species = SPECIES_AURORUS,
        .ability = Ability_2, // refrigerate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FREEZEDRY, MOVE_BOOMBURST, MOVE_ANCIENTPOWER},
    },
    {
        .lvl = -2,
        .species = SPECIES_TYRANTRUM,
        .ability = Ability_Hidden, // sturdy
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRAGONTAIL, MOVE_ROAR, MOVE_ROCKTHROW, MOVE_CRUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerJared[] = {
    {
        .lvl = -2,
        .species = SPECIES_HAWLUCHA,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_HIGHJUMPKICK, MOVE_SWORDSDANCE, MOVE_ROOST, MOVE_ENCORE},
    },
    {
        .lvl = -2,
        .species = SPECIES_NIDOKING,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_POISONJAB, MOVE_MEGAHORN, MOVE_TOXIC, MOVE_EARTHPOWER},
    },
    {
        .lvl = -2,
        .species = SPECIES_SHARPEDO,
        .ability = Ability_Hidden, // speed boost
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_EXPERT_BELT,
        .moves = {MOVE_LIQUIDATION, MOVE_CRUNCH, MOVE_ICEFANG, MOVE_POISONFANG},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerMalik[] = {
    {
        .lvl = -2,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_FOCUS_SASH,
        .moves = {MOVE_MACHPUNCH, MOVE_BULLETSEED, MOVE_TOXIC, MOVE_LEECHSEED},
    },
    {
        .lvl = -2,
        .species = SPECIES_TENTACRUEL,
        .ability = Ability_1, // clear body
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_BLACK_SLUDGE,
        .moves = {MOVE_SLUDGEWAVE, MOVE_HEX, MOVE_SURF, MOVE_ACIDARMOR},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerErnest[] = {
    {
        .lvl = -2,
        .species = SPECIES_SCRAFTY,
        .ability = Ability_Hidden, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_HEADSMASH, MOVE_DRAGONDANCE, MOVE_CRUNCH, MOVE_HIGHJUMPKICK},
    },
    {
        .lvl = -2,
        .species = SPECIES_WEAVILE,
        .ability = Ability_2, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_EXPERT_BELT,
        .moves = {MOVE_ASSURANCE, MOVE_QUICKATTACK, MOVE_HONECLAWS, MOVE_ICESHARD},
    },
    {
        .lvl = -2,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_FOCUS_SASH,
        .moves = {MOVE_MACHPUNCH, MOVE_BULLETSEED, MOVE_TOXIC, MOVE_LEECHSEED},
    },
    {
        .lvl = -2,
        .species = SPECIES_TENTACRUEL,
        .ability = Ability_1, // clear body
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_BLACK_SLUDGE,
        .moves = {MOVE_SLUDGEWAVE, MOVE_HEX, MOVE_SURF, MOVE_ACIDARMOR},
    },
    {
        .lvl = -2,
        .species = SPECIES_PASSIMIAN,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_CLOSECOMBAT, MOVE_BULKUP, MOVE_MACHPUNCH, MOVE_SUCKERPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerAlex[] = {
    {
        .lvl = -2,
        .species = SPECIES_SHARPEDO,
        .ability = Ability_Hidden, // speed boost
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_EXPERT_BELT,
        .moves = {MOVE_LIQUIDATION, MOVE_CRUNCH, MOVE_ICEFANG, MOVE_POISONFANG},
    },
    {
        .lvl = -2,
        .species = SPECIES_HAWLUCHA,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_HIGHJUMPKICK, MOVE_SWORDSDANCE, MOVE_ROOST, MOVE_ENCORE},
    },
    {
        .lvl = -2,
        .species = SPECIES_NIDOKING,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_POISONJAB, MOVE_MEGAHORN, MOVE_TOXIC, MOVE_EARTHPOWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerLao[] = {
    {
        .lvl = -2,
        .species = SPECIES_NIDOKING,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_POISONJAB, MOVE_MEGAHORN, MOVE_TOXIC, MOVE_EARTHPOWER},
    },
    {
        .lvl = -2,
        .species = SPECIES_HAWLUCHA,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_HIGHJUMPKICK, MOVE_SWORDSDANCE, MOVE_ROOST, MOVE_ENCORE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_Biker1[] = {DUMMY_TRAINER_MON};

static const struct TrainerMonItemCustomMoves sParty_BikerHideo[] = {
    {
        .lvl = -2,
        .species = SPECIES_MACHAMP,
        .ability = Ability_1, // guts
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_FLAME_ORB,
        .moves = {MOVE_CLOSECOMBAT, MOVE_BULKUP, MOVE_MACHPUNCH, MOVE_BULLETPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerRuben[] = {
    {
        .lvl = -2,
        .species = SPECIES_SEVIPER,
        .ability = Ability_Hidden, // fatal precision
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_GUNKSHOT, MOVE_CRUNCH, MOVE_COIL, MOVE_GLARE},
    },
    {
        .lvl = -2,
        .species = SPECIES_SHARPEDO,
        .ability = Ability_Hidden, // speed boost
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_EXPERT_BELT,
        .moves = {MOVE_LIQUIDATION, MOVE_CRUNCH, MOVE_ICEFANG, MOVE_POISONFANG},
    },
    {
        .lvl = -2,
        .species = SPECIES_INFERNAPE,
        .ability = Ability_Hidden, // iron fist
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_FOCUS_SASH,
        .moves = {MOVE_PYROBALL, MOVE_ACROBATICS, MOVE_MACHPUNCH, MOVE_CLOSECOMBAT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerBilly[] = {
    {
        .lvl = -2,
        .species = SPECIES_MUK_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_BLACK_SLUDGE,
        .moves = {MOVE_GUNKSHOT, MOVE_CRUNCH, MOVE_ACIDARMOR, MOVE_DISABLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerNikolas[] = {
    {
        .lvl = -2,
        .species = SPECIES_MALAMAR,
        .ability = Ability_1, // contrary
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_SUPERPOWER, MOVE_KNOCKOFF, MOVE_PSYCHOCUT, MOVE_PLUCK},
    },
    {
        .lvl = -2,
        .species = SPECIES_VENUSAUR,
        .ability = Ability_2, // thick fat
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_BLACK_SLUDGE,
        .moves = {MOVE_SLUDGEBOMB, MOVE_SYNTHESIS, MOVE_PETALBLIZZARD, MOVE_LEECHSEED},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerJaxon[] = {
    {
        .lvl = -2,
        .species = SPECIES_CACTURNE,
        .ability = Ability_Hidden, // water absorb
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SUCKERPUNCH, MOVE_ENERGYBALL, MOVE_COTTONSPORE, MOVE_LEECHSEED},
    },
    {
        .lvl = -2,
        .species = SPECIES_SALAZZLE,
        .ability = Ability_1, // corrosion
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_EXPERT_BELT,
        .moves = {MOVE_FLAMETHROWER, MOVE_DRAGONPULSE, MOVE_TOXIC, MOVE_VENOSHOCK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerWilliam[] = {
    {
        .lvl = -2,
        .species = SPECIES_TOXAPEX,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_BLACK_SLUDGE,
        .moves = {MOVE_TOXICSPIKES, MOVE_TOXIC, MOVE_BANEFULBUNKER, MOVE_RECOVER},
    },
    {
        .lvl = -2,
        .species = SPECIES_HAWLUCHA,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_SWORDSDANCE, MOVE_FLYINGPRESS, MOVE_ROOST, MOVE_ENCORE},
    },
    {
        .lvl = -2,
        .species = SPECIES_EMBOAR,
        .ability = Ability_Hidden, // iron head
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_EARTHQUAKE, MOVE_HEADSMASH, MOVE_FLAREBLITZ, MOVE_HAMMERARM},
    },
    {
        .lvl = -2,
        .species = SPECIES_SALAZZLE,
        .ability = Ability_1, // corrosion
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_EXPERT_BELT,
        .moves = {MOVE_FLAMETHROWER, MOVE_DRAGONPULSE, MOVE_TOXIC, MOVE_VENOSHOCK},
    },
    {
        .lvl = -2,
        .species = SPECIES_VENUSAUR,
        .ability = Ability_2, // thick fat
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SLUDGEBOMB, MOVE_SYNTHESIS, MOVE_PETALBLIZZARD, MOVE_LEECHSEED},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerLukas[] = {
    {
        .lvl = -2,
        .species = SPECIES_SCRAFTY,
        .ability = Ability_Hidden, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_EXPERT_BELT,
        .moves = {MOVE_HEADSMASH, MOVE_DRAGONDANCE, MOVE_CRUNCH, MOVE_HIGHJUMPKICK},
    },
    {
        .lvl = -2,
        .species = SPECIES_WEAVILE,
        .ability = Ability_2, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_ASSURANCE, MOVE_QUICKATTACK, MOVE_HONECLAWS, MOVE_ICESHARD},
    },
    {
        .lvl = -2,
        .species = SPECIES_MUK,
        .ability = Ability_1, // poison touch
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_GUNKSHOT, MOVE_PLAYROUGH, MOVE_ACIDARMOR, MOVE_SCREECH},
    },
    {
        .lvl = -2,
        .species = SPECIES_MUK_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_BLUNDER_POLICY,
        .moves = {MOVE_GUNKSHOT, MOVE_CRUNCH, MOVE_ACIDARMOR, MOVE_SCREECH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerIsaac[] = {
    {
        .lvl = -2,
        .species = SPECIES_MUK,
        .ability = Ability_1, // poison touch
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_BLUNDER_POLICY,
        .moves = {MOVE_GUNKSHOT, MOVE_PLAYROUGH, MOVE_ACIDARMOR, MOVE_SCREECH},
    },
    {
        .lvl = -2,
        .species = SPECIES_ROSERADE,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = {MOVE_ANCIENTPOWER, MOVE_MAGICALLEAF, MOVE_SYNTHESIS, MOVE_TOXIC},
    },
    {
        .lvl = -2,
        .species = SPECIES_WEAVILE,
        .ability = Ability_2, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_ASSURANCE, MOVE_QUICKATTACK, MOVE_HONECLAWS, MOVE_ICESHARD},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerGerald[] = {
    {
        .lvl = -2,
        .species = SPECIES_NIDOKING,
        .ability = Ability_1, // poison jab
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_EARTHPOWER, MOVE_MEGAHORN, MOVE_POISONJAB, MOVE_TOXIC},
    },
    {
        .lvl = -2,
        .species = SPECIES_PASSIMIAN,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_CLOSECOMBAT, MOVE_BULKUP, MOVE_MACHPUNCH, MOVE_SUCKERPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_Burglar1[] = {
    {
        .lvl = 29,
        .species = SPECIES_GROWLITHE,
    },
    {
        .lvl = 29,
        .species = SPECIES_VULPIX,
    },
};

static const struct TrainerMonItemCustomMoves sParty_Burglar2[] = {
    {
        .lvl = 33,
        .species = SPECIES_GROWLITHE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_Burglar3[] = {
    {
        .lvl = 28,
        .species = SPECIES_VULPIX,
    },
    {
        .lvl = 28,
        .species = SPECIES_CHARMANDER,
    },
    {
        .lvl = 28,
        .species = SPECIES_PONYTA,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BurglarQuinn[] = {
    {
        .lvl = -2,
        .species = SPECIES_PYROAR,
        .ability = Ability_Hidden, // royalty
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_FLAMETHROWER, MOVE_DARKPULSE, MOVE_HYPERVOICE, MOVE_NOBLEROAR},
    },
    {
        .lvl = -2,
        .species = SPECIES_ARCANINE,
        .ability = Ability_1, // intimidate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 4, 0, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_HELPINGHAND, MOVE_ROAR, MOVE_EXTREMESPEED, MOVE_HEATWAVE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BurglarRamon[] = {
    {
        .lvl = -2,
        .species = SPECIES_PYROAR,
        .ability = Ability_Hidden, // royalty
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_FLAMETHROWER, MOVE_DARKPULSE, MOVE_HYPERVOICE, MOVE_NOBLEROAR},
    },
    {
        .lvl = -2,
        .species = SPECIES_ARCANINE,
        .ability = Ability_1, // intimidate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 4, 0, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_HELPINGHAND, MOVE_ROAR, MOVE_EXTREMESPEED, MOVE_HEATWAVE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BurglarDusty[] = {
    {
        .lvl = -2,
        .species = SPECIES_PYROAR,
        .ability = Ability_Hidden, // royalty
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_FLAMETHROWER, MOVE_DARKPULSE, MOVE_HYPERVOICE, MOVE_NOBLEROAR},
    },
    {
        .lvl = -2,
        .species = SPECIES_ARCANINE,
        .ability = Ability_1, // intimidate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 4, 0, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_HELPINGHAND, MOVE_ROAR, MOVE_EXTREMESPEED, MOVE_HEATWAVE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BurglarArnie[] = {
    {
        .lvl = -2,
        .species = SPECIES_CHARIZARD,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HEATWAVE, MOVE_AIRSLASH, MOVE_DRAGONCLAW, MOVE_CRUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_GRENINJA,
        .ability = Ability_Hidden, // protean
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EXTRASENSORY, MOVE_SHADOWSNEAK, MOVE_HYDROPUMP, MOVE_BOUNCE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_Burglar4[] = {
    {
        .lvl = 34,
        .species = SPECIES_CHARMANDER,
    },
    {
        .lvl = 34,
        .species = SPECIES_CHARMELEON,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BurglarSimon[] = {
    {
        .lvl = -2,
        .species = SPECIES_CHANDELURE,
        .ability = Ability_1, // flame body
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WILLOWISP, MOVE_SHADOWBALL, MOVE_PAINSPLIT, MOVE_OVERHEAT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BurglarLewis[] = {
    {
        .lvl = -2,
        .species = SPECIES_HEATMOR,
        .ability = Ability_2, // flash fire
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FLAREBLITZ, MOVE_HONECLAWS, MOVE_BUGBITE, MOVE_SNATCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_RAPIDASH,
        .ability = Ability_Hidden, // moxie
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WILDCHARGE, MOVE_JUMPKICK, MOVE_FLAREBLITZ, MOVE_POISONJAB},
    },
};

static const struct TrainerMonItemCustomMoves sParty_EngineerBaily[] = {
    {
        .lvl = -2,
        .species = SPECIES_DEDENNE,
        .ability = Ability_Hidden, // electric surge
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_SUPERFANG, MOVE_PARABOLICCHARGE, MOVE_THUNDERWAVE, MOVE_DRAININGKISS},
    },
    {
        .lvl = -2,
        .species = SPECIES_GOLEM_A,
        .ability = Ability_Hidden, // galvanize
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TAKEDOWN, MOVE_SMACKDOWN, MOVE_ROCKPOLISH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_EngineerBraxton[] = {
    {
        .lvl = -2,
        .species = SPECIES_MORPEKO,
        .ability = Ability_1, // hangry switch
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BULLETSEED, MOVE_SPARK, MOVE_BITE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_EngineerBernie[] = {
    {
        .lvl = -2,
        .species = SPECIES_EMOLGA,
        .ability = Ability_1, // static
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_NUZZLE, MOVE_ACROBATICS, MOVE_PURSUIT, MOVE_SPARK},
    },
    {
        .lvl = -2,
        .species = SPECIES_PACHIRISU,
        .ability = Ability_1, // prankster
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUPERFANG, MOVE_THUNDERWAVE, MOVE_CHARM, MOVE_NUZZLE},
    },
    {
        .lvl = -2,
        .species = SPECIES_TOGEDEMARU,
        .ability = Ability_1, // rough skin
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ZINGZAP, MOVE_PINMISSILE, MOVE_ROLLOUT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_FishermanDale[] = {
    {
        .lvl = -2,
        .species = SPECIES_SEAKING,
        .ability = Ability_Hidden, // lightning rod
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_FLIPTURN, MOVE_AGILITY, MOVE_AQUAJET, MOVE_POISONJAB},
    },
    {
        .lvl = -2,
        .species = SPECIES_TENTACRUEL,
        .ability = Ability_2, // liquid ooze
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_POISONJAB, MOVE_BUBBLEBEAM, MOVE_HEX, MOVE_TOXICSPIKES},
    },
    {
        .lvl = -2,
        .species = SPECIES_WAILMER,
        .ability = Ability_Hidden, // pressure
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WATERPULSE, MOVE_CALMMIND, MOVE_MIST, MOVE_REST},
    },
};

static const struct TrainerMonItemCustomMoves sParty_FishermanBarny[] = {
    {
        .lvl = -2,
        .species = SPECIES_LUMINEON,
        .ability = Ability_1, // swift swim
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_RAINDANCE, MOVE_SIGNALBEAM, MOVE_WATERPULSE, MOVE_CONFUSERAY},
    },
    {
        .lvl = -2,
        .species = SPECIES_BASCULIN_RED,
        .ability = Ability_2, // adaptability
        .nature = NATURE_HASTY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AQUAJET, MOVE_HEADBUTT, MOVE_BITE},
    },
    {
        .lvl = -2,
        .species = SPECIES_SHARPEDO,
        .ability = Ability_1, // rough skin
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AQUAJET, MOVE_ICEFANG, MOVE_POISONFANG, MOVE_TAUNT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_FishermanNed[] = {
    {
        .lvl = -2,
        .species = SPECIES_PELIPPER,
        .ability = Ability_Hidden, // drizzle
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_DAMP_ROCK,
        .moves = {MOVE_AIRCUTTER, MOVE_ROOST, MOVE_WATERPULSE},
    },
    {
        .lvl = -2,
        .species = SPECIES_BARRASKEWDA,
        .ability = Ability_1, // swift swim
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WATERFALL, MOVE_CRUNCH, MOVE_DRILLRUN},
    },
    {
        .lvl = -2,
        .species = SPECIES_RELICANTH,
        .ability = Ability_1, // swift swim
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AQUATAIL, MOVE_YAWN, MOVE_ROCKTOMB},
    },
};

static const struct TrainerMonItemCustomMoves sParty_FishermanChip[] = {
    {
        .lvl = -2,
        .species = SPECIES_TENTACRUEL,
        .ability = Ability_1, // clear body
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_VENOSHOCK, MOVE_SURF, MOVE_HEX, MOVE_ACIDARMOR},
    },
    {
        .lvl = -2,
        .species = SPECIES_OCTILLERY,
        .ability = Ability_Hidden, // moody
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BUBBLEBEAM, MOVE_AURORABEAM, MOVE_SIGNALBEAM, MOVE_PSYBEAM},
    },
};

static const struct TrainerMonItemCustomMoves sParty_FishermanHank[] = {
    {
        .lvl = -2,
        .species = SPECIES_ARCTOVISH,
        .ability = Ability_1, // water absorb
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUPERFANG, MOVE_ICICLECRASH, MOVE_FREEZEDRY},
    },
};

static const struct TrainerMonItemCustomMoves sParty_FishermanElliot[] = {
    {
        .lvl = -2,
        .species = SPECIES_POLIWRATH,
        .ability = Ability_Hidden, // swift swim
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FLIPTURN, MOVE_BULKUP, MOVE_LOWKICK},
    },
    {
        .lvl = -2,
        .species = SPECIES_QUAGSIRE,
        .ability = Ability_1, // clear body
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_YAWN, MOVE_TOXIC, MOVE_HAZE},
    },
    {
        .lvl = -2,
        .species = SPECIES_TOXAPEX,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TOXICSPIKES, MOVE_TOXIC, MOVE_BANEFULBUNKER, MOVE_RECOVER},
    },
    {
        .lvl = -2,
        .species = SPECIES_OCTILLERY,
        .ability = Ability_Hidden, // moody
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BUBBLEBEAM, MOVE_AURORABEAM, MOVE_SIGNALBEAM, MOVE_PSYBEAM},
    },
};

static const struct TrainerMonItemCustomMoves sParty_FishermanRonald[] = {
    {
        .lvl = -2,
        .species = SPECIES_LUMINEON,
        .ability = Ability_2, // storm drain
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SIGNALBEAM, MOVE_WATERPULSE, MOVE_TAILGLOW, MOVE_UTURN},
    },
    {
        .lvl = -2,
        .species = SPECIES_OCTILLERY,
        .ability = Ability_Hidden, // moody
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SNIPESHOT, MOVE_ICEBEAM, MOVE_SIGNALBEAM, MOVE_GUNKSHOT},
    },
    {
        .lvl = -2,
        .species = SPECIES_SEAKING,
        .ability = Ability_Hidden, // lightning rod
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FISHIOUSREND, MOVE_MEGAHORN, MOVE_HORNDRILL, MOVE_AGILITY},
    },
    {
        .lvl = -2,
        .species = SPECIES_HUNTAIL,
        .ability = Ability_2, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AQUATAIL, MOVE_COIL, MOVE_SUCKERPUNCH, MOVE_PSYCHICFANGS},
    },
    {
        .lvl = -2,
        .species = SPECIES_GOREBYSS,
        .ability = Ability_2, // dazzling
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MOONBLAST, MOVE_HYDROPUMP, MOVE_PSYCHIC, MOVE_AGILITY},
    },
};

static const struct TrainerMonItemCustomMoves sParty_FishermanClaude[] = {
    {
        .lvl = -2,
        .species = SPECIES_GYARADOS,
        .ability = Ability_Hidden, // moxie
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRAGONDANCE, MOVE_WATERFALL, MOVE_CRUNCH, MOVE_ICEFANG},
    },
};

static const struct TrainerMonItemCustomMoves sParty_FishermanWade[] = {
    {
        .lvl = -10,
        .species = SPECIES_MAGIKARP,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPLASH},
    },
    {
        .lvl = -10,
        .species = SPECIES_MAGIKARP,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPLASH},
    },
    {
        .lvl = -10,
        .species = SPECIES_MAGIKARP,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPLASH},
    },
    {
        .lvl = -10,
        .species = SPECIES_MAGIKARP,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPLASH},
    },
    {
        .lvl = -10,
        .species = SPECIES_MAGIKARP,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPLASH},
    },
    {
        .lvl = -10,
        .species = SPECIES_MAGIKARP,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPLASH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_FishermanNolan[] = {
    {
        .lvl = -2,
        .species = SPECIES_MILOTIC,
        .ability = Ability_Hidden, // serene grace
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPARKLINGARIA, MOVE_MOONBLAST, MOVE_RECOVER, MOVE_ATTRACT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_FishermanAndrew[] = {
    {
        .lvl = -2,
        .species = SPECIES_GYARADOS,
        .ability = Ability_1, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WATERFALL, MOVE_CRUNCH, MOVE_ICEFANG, MOVE_RAINDANCE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleLuis[] = {
    {
        .lvl = -2,
        .species = SPECIES_PYUKUMUKU,
        .ability = Ability_2, // gooey
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TAUNT, MOVE_COUNTER, MOVE_SAFEGUARD},
    },
    {
        .lvl = -2,
        .species = SPECIES_BRUXISH,
        .ability = Ability_1, // dazzling
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BITE, MOVE_AQUAJET, MOVE_DISABLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleRichard[] = {
    {
        .lvl = -2,
        .species = SPECIES_PALOSSAND,
        .ability = Ability_1, // water compaction
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHPOWER, MOVE_SHADOWBALL, MOVE_GIGADRAIN, MOVE_DESTINYBOND},
    },
    {
        .lvl = -2,
        .species = SPECIES_KINGLER,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HAMMERARM, MOVE_ICEHAMMER, MOVE_METEORMASH, MOVE_CRABHAMMER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleReece[] = {
    {
        .lvl = -2,
        .species = SPECIES_SEISMITOAD,
        .ability = Ability_1, // swift swim
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_DAMP_ROCK,
        .moves = {MOVE_HYDROPUMP, MOVE_RAINDANCE, MOVE_DRAINPUNCH, MOVE_HYPERVOICE},
    },
    {
        .lvl = -2,
        .species = SPECIES_PELIPPER,
        .ability = Ability_2, // rain dish
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HURRICANE, MOVE_HYDROPUMP, MOVE_AIRSLASH, MOVE_ROOST},
    },
    {
        .lvl = -2,
        .species = SPECIES_WHISCASH,
        .ability = Ability_Hidden, // sap sipper
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_HEADBUTT, MOVE_AQUATAIL},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleMatthew[] = {
    {
        .lvl = -2,
        .species = SPECIES_CLAWITZER,
        .ability = Ability_1, // mega launcher
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ORIGINPULSE, MOVE_DRAGONPULSE, MOVE_AURASPHERE, MOVE_DARKPULSE},
    },
    {
        .lvl = -2,
        .species = SPECIES_WHISCASH,
        .ability = Ability_Hidden, // sap sipper
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_HEADBUTT, MOVE_AQUATAIL},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleDouglas[] = {
    {
        .lvl = -2,
        .species = SPECIES_BRUXISH,
        .ability = Ability_2, // strong jaw
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHICFANGS, MOVE_CRUNCH, MOVE_AQUAJET},
    },
    {
        .lvl = -2,
        .species = SPECIES_LANTURN,
        .ability = Ability_1, // volt absorb
        .nature = NATURE_CALM,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYDROPUMP, MOVE_PARABOLICCHARGE, MOVE_CONFUSERAY, MOVE_THUNDERWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_WHISCASH,
        .ability = Ability_Hidden, // sap sipper
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_HEADBUTT, MOVE_AQUATAIL},
    },
    {
        .lvl = -2,
        .species = SPECIES_PELIPPER,
        .ability = Ability_2, // rain dish
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HURRICANE, MOVE_HYDROPUMP, MOVE_AIRSLASH, MOVE_ROOST},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleDavid[] = {
    {
        .lvl = -2,
        .species = SPECIES_HUNTAIL,
        .ability = Ability_2, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AQUATAIL, MOVE_COIL, MOVE_SUCKERPUNCH, MOVE_PSYCHICFANGS},
    },
    {
        .lvl = -2,
        .species = SPECIES_LANTURN,
        .ability = Ability_1, // volt absorb
        .nature = NATURE_CALM,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYDROPUMP, MOVE_PARABOLICCHARGE, MOVE_CONFUSERAY, MOVE_THUNDERWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_SEAKING,
        .ability = Ability_Hidden, // lightning rod
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FISHIOUSREND, MOVE_MEGAHORN, MOVE_HORNDRILL, MOVE_AGILITY},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleTony[] = {
    {
        .lvl = -2,
        .species = SPECIES_CRAWDAUNT,
        .ability = Ability_Hidden, // aerilate
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRABHAMMER, MOVE_KNOCKOFF, MOVE_SWORDSDANCE, MOVE_TAUNT},
    },
    {
        .lvl = -2,
        .species = SPECIES_QUAGSIRE,
        .ability = Ability_2, // water absorb
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_YAWN, MOVE_TOXIC, MOVE_HAZE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleAxle[] = {
    {
        .lvl = -2,
        .species = SPECIES_QUAGSIRE,
        .ability = Ability_2, // water absorb
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_YAWN, MOVE_TOXIC, MOVE_HAZE},
    },
    {
        .lvl = -2,
        .species = SPECIES_SEAKING,
        .ability = Ability_Hidden, // lightning rod
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FISHIOUSREND, MOVE_MEGAHORN, MOVE_HORNDRILL, MOVE_AGILITY},
    },
    {
        .lvl = -2,
        .species = SPECIES_HUNTAIL,
        .ability = Ability_2, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AQUATAIL, MOVE_COIL, MOVE_SUCKERPUNCH, MOVE_PSYCHICFANGS},
    },
    {
        .lvl = -2,
        .species = SPECIES_PELIPPER,
        .ability = Ability_2, // rain dish
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HURRICANE, MOVE_HYDROPUMP, MOVE_AIRSLASH, MOVE_ROOST},
    },
    {
        .lvl = -2,
        .species = SPECIES_CLAWITZER,
        .ability = Ability_1, // mega launcher
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ORIGINPULSE, MOVE_DRAGONPULSE, MOVE_AURASPHERE, MOVE_DARKPULSE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleBarry[] = {
    {
        .lvl = -2,
        .species = SPECIES_CLOYSTER,
        .ability = Ability_1, // battle armor
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHELLSMASH, MOVE_ICICLECRASH, MOVE_RAZORSHELL, MOVE_TWINEEDLE},
    },
    {
        .lvl = -2,
        .species = SPECIES_WALREIN,
        .ability = Ability_Hidden, // ice scales
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BLIZZARD, MOVE_HYPERVOICE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleDean[] = {
    {
        .lvl = -2,
        .species = SPECIES_STARMIE,
        .ability = Ability_2, // natural cure
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_POWERGEM, MOVE_RECOVER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleDarrin[] = {
    {
        .lvl = -2,
        .species = SPECIES_HUNTAIL,
        .ability = Ability_2, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AQUATAIL, MOVE_COIL, MOVE_SUCKERPUNCH, MOVE_PSYCHICFANGS},
    },
    {
        .lvl = -2,
        .species = SPECIES_CLAWITZER,
        .ability = Ability_1, // mega launcher
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ORIGINPULSE, MOVE_DRAGONPULSE, MOVE_AURASPHERE, MOVE_DARKPULSE},
    },
    {
        .lvl = -2,
        .species = SPECIES_LANTURN,
        .ability = Ability_1, // volt absorb
        .nature = NATURE_CALM,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYDROPUMP, MOVE_PARABOLICCHARGE, MOVE_CONFUSERAY, MOVE_THUNDERWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_CRAWDAUNT,
        .ability = Ability_Hidden, // adaptability
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRABHAMMER, MOVE_KNOCKOFF, MOVE_SWORDSDANCE, MOVE_TAUNT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleSpencer[] = {
    {
        .lvl = -2,
        .species = SPECIES_CRAWDAUNT,
        .ability = Ability_Hidden, // adaptability
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRABHAMMER, MOVE_KNOCKOFF, MOVE_SWORDSDANCE, MOVE_TAUNT},
    },
    {
        .lvl = -2,
        .species = SPECIES_CLAWITZER,
        .ability = Ability_1, // mega launcher
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ORIGINPULSE, MOVE_DRAGONPULSE, MOVE_AURASPHERE, MOVE_DARKPULSE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleJack[] = {
    {
        .lvl = -2,
        .species = SPECIES_STARMIE,
        .ability = Ability_2, // natural cure
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_POWERGEM, MOVE_RECOVER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleJerome[] = {
    {
        .lvl = -2,
        .species = SPECIES_BARRASKEWDA,
        .ability = Ability_Hidden, // stalwart
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_LIQUIDATION, MOVE_THROATCHOP, MOVE_DRILLRUN, MOVE_AQUAJET},
    },
    {
        .lvl = -2,
        .species = SPECIES_WAILORD,
        .ability = Ability_Hidden, // pressure
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CALMMIND, MOVE_HYDROPUMP, MOVE_CHATTER, MOVE_NOBLEROAR},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleRoland[] = {
    {
        .lvl = -2,
        .species = SPECIES_TENTACRUEL,
        .ability = Ability_1, // clear body
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGEWAVE, MOVE_HEX, MOVE_SURF, MOVE_ACIDARMOR},
    },
    {
        .lvl = -2,
        .species = SPECIES_OCTILLERY,
        .ability = Ability_Hidden, // moody
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SNIPESHOT, MOVE_ICEBEAM, MOVE_SIGNALBEAM, MOVE_BULLETSEED},
    },
    {
        .lvl = -2,
        .species = SPECIES_KINGDRA,
        .ability = Ability_Hidden, // sniper
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRAGONDANCE, MOVE_WATERFALL, MOVE_DRAGONPULSE, MOVE_YAWN},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CueBallKoji[] = {
    {
        .lvl = -2,
        .species = SPECIES_PRIMEAPE,
        .ability = Ability_Hidden, // adrenaline
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CLOSECOMBAT, MOVE_STOMPINGTANTRUM, MOVE_UTURN, MOVE_PURSUIT},
    },
    {
        .lvl = -2,
        .species = SPECIES_SPIRITOMB,
        .ability = Ability_Hidden, // intimidate
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWSNEAK, MOVE_SUCKERPUNCH, MOVE_PARTINGSHOT, MOVE_SPITE},
    },
    {
        .lvl = -2,
        .species = SPECIES_DRAPION,
        .ability = Ability_Hidden, // sniper
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SWORDSDANCE, MOVE_WICKEDBLOW, MOVE_CROSSPOISON, MOVE_ICEFANG},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CueBallLuke[] = {
    {
        .lvl = -2,
        .species = SPECIES_ARBOK,
        .ability = Ability_Hidden, // fatal precision
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GUNKSHOT, MOVE_CRUNCH, MOVE_ICEFANG, MOVE_BULLDOZE},
    },
    {
        .lvl = -2,
        .species = SPECIES_ROSERADE,
        .ability = Ability_2, // poison point
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GIGADRAIN, MOVE_EXTRASENSORY, MOVE_ANCIENTPOWER, MOVE_WEATHERBALL},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CueBallCamron[] = {
    {
        .lvl = -2,
        .species = SPECIES_GARBODOR,
        .ability = Ability_Hidden, // aftermath
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BODYSLAM, MOVE_GUNKSHOT, MOVE_PAINSPLIT},
    },
    {
        .lvl = -2,
        .species = SPECIES_CRAWDAUNT,
        .ability = Ability_Hidden, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRABHAMMER, MOVE_KNOCKOFF, MOVE_SWORDSDANCE, MOVE_TAUNT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CueBallRaul[] = {
    {
        .lvl = -2,
        .species = SPECIES_ROSERADE,
        .ability = Ability_2, // poison point
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GIGADRAIN, MOVE_EXTRASENSORY, MOVE_ANCIENTPOWER, MOVE_WEATHERBALL},
    },
    {
        .lvl = -2,
        .species = SPECIES_ARBOK,
        .ability = Ability_Hidden, // fatal precision
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GUNKSHOT, MOVE_CRUNCH, MOVE_ICEFANG, MOVE_BULLDOZE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CueBallIsaiah[] = {
    {
        .lvl = -2,
        .species = SPECIES_CRAWDAUNT,
        .ability = Ability_2, // aftermath
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUCKERPUNCH, MOVE_TOXIC, MOVE_CROSSPOISON},
    },
    {
        .lvl = -2,
        .species = SPECIES_HONCHKROW,
        .ability = Ability_2, // super luck
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_NIGHTSLASH, MOVE_BRAVEBIRD, MOVE_TAUNT, MOVE_SWAGGER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CueBallZeek[] = {
    {
        .lvl = -2,
        .species = SPECIES_DRAGALGE,
        .ability = Ability_Hidden, // adaptability
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGEBOMB, MOVE_DRAGONPULSE, MOVE_HYDROPUMP, MOVE_SCALD},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CueBallJamal[] = {
    {
        .lvl = -2,
        .species = SPECIES_BLAZIKEN,
        .ability = Ability_Hidden, // speed boost
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HIGHJUMPKICK, MOVE_FLAREBLITZ, MOVE_BRAVEBIRD, MOVE_BULKUP},
    },
    {
        .lvl = -2,
        .species = SPECIES_EMBOAR,
        .ability = Ability_Hidden, // iron head
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_HEADSMASH, MOVE_FLAREBLITZ, MOVE_HAMMERARM},
    },
    {
        .lvl = -2,
        .species = SPECIES_INFERNAPE,
        .ability = Ability_Hidden, // iron fist
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PYROBALL, MOVE_ACROBATICS, MOVE_MACHPUNCH, MOVE_CLOSECOMBAT},
    },
    {
        .lvl = -2,
        .species = SPECIES_WEAVILE,
        .ability = Ability_2, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ASSURANCE, MOVE_QUICKATTACK, MOVE_HONECLAWS, MOVE_ICESHARD},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CueBallCorey[] = {
    {
        .lvl = -2,
        .species = SPECIES_PRIMEAPE,
        .ability = Ability_Hidden, // adrenaline
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CLOSECOMBAT, MOVE_STOMPINGTANTRUM, MOVE_UTURN, MOVE_PURSUIT},
    },
    {
        .lvl = -2,
        .species = SPECIES_KROOKODILE,
        .ability = Ability_2, // moxie
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LUM_BERRY,
        .moves = {MOVE_EARTHQUAKE, MOVE_WICKEDBLOW, MOVE_OUTRAGE, MOVE_HONECLAWS},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CueBallChase[] = {
    {
        .lvl = 31,
        .species = SPECIES_TENTACOOL,
    },
    {
        .lvl = 31,
        .species = SPECIES_TENTACOOL,
    },
    {
        .lvl = 31,
        .species = SPECIES_TENTACRUEL,
    },
};

static const struct TrainerMonItemCustomMoves sParty_GamerHugo[] = {
    {
        .lvl = -2,
        .species = SPECIES_PORYGON,
        .ability = Ability_2, // download
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TRIATTACK, MOVE_SIGNALBEAM, MOVE_THUNDERWAVE, MOVE_AGILITY},
    },
    {
        .lvl = -2,
        .species = SPECIES_FURRET,
        .ability = Ability_Hidden, // speed boost
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EXTREMESPEED, MOVE_SUCKERPUNCH, MOVE_BULLDOZE, MOVE_COIL},
    },
};

static const struct TrainerMonItemCustomMoves sParty_GamerJasper[] = {
    {
        .lvl = -2,
        .species = SPECIES_STUNFISK,
        .ability = Ability_Hidden, // sap sipper
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MUDBOMB, MOVE_THUNDERSHOCK, MOVE_WATERGUN},
    },
    {
        .lvl = -2,
        .species = SPECIES_STUNFISK_G,
        .ability = Ability_2, // filter
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_REVENGE, MOVE_METALCLAW, MOVE_SNAPTRAP, MOVE_MUDSHOT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_GamerDirk[] = {
    {
        .lvl = -2,
        .species = SPECIES_PLUSLE,
        .ability = Ability_Hidden, // transistor
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AGILITY, MOVE_ENCORE, MOVE_ELECTROBALL, MOVE_SWIFT},
    },
    {
        .lvl = -2,
        .species = SPECIES_MINUN,
        .ability = Ability_Hidden, // transistor
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AGILITY, MOVE_ENCORE, MOVE_FAKEOUT, MOVE_ELECTROBALL},
    },
};

static const struct TrainerMonItemCustomMoves sParty_GamerDarian[] = {
    {
        .lvl = -2,
        .species = SPECIES_COMBUSKEN,
        .ability = Ability_2, // speed boost
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FLAMEBURST, MOVE_AERIALACE, MOVE_MIRRORMOVE, MOVE_DOUBLEKICK},
    },
    {
        .lvl = -2,
        .species = SPECIES_RABOOT,
        .ability = Ability_Hidden, // protean
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BOUNCE, MOVE_HEADBUTT, MOVE_FLAMECHARGE, MOVE_COUNTER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_GamerStan[] = {
    {
        .lvl = -2,
        .species = SPECIES_POLIWRATH,
        .ability = Ability_Hidden, // swift swim
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FLIPTURN, MOVE_BULKUP, MOVE_SUPERPOWER, MOVE_RAINDANCE},
    },
    {
        .lvl = -2,
        .species = SPECIES_BARRASKEWDA,
        .ability = Ability_Hidden, // swift swim
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WATERFALL, MOVE_CRUNCH, MOVE_DRILLRUN},
    },
    {
        .lvl = -2,
        .species = SPECIES_SCRAFTY,
        .ability = Ability_2, // moxie
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_LOWKICK, MOVE_CRUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_Gamer1[] = {DUMMY_TRAINER_MON};

static const struct TrainerMonItemCustomMoves sParty_GamerRich[] = {
    {
        .lvl = -2,
        .species = SPECIES_ARCANINE,
        .ability = Ability_1, // intimidate
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FIREFANG, MOVE_PLAYROUGH, MOVE_CRUNCH, MOVE_EXTREMESPEED},
    },
    {
        .lvl = -2,
        .species = SPECIES_RAPIDASH,
        .ability = Ability_Hidden, // moxie
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ZINGZAP, MOVE_POISONJAB, MOVE_POISONJAB, MOVE_BOUNCE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BeautyBridget[] = {
    {
        .lvl = -2,
        .species = SPECIES_LILLIGANT,
        .ability = Ability_1, // chlorophyll
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_RECOVER, MOVE_SLEEPPOWDER, MOVE_ENERGYBALL, MOVE_SUNNYDAY},
    },
    {
        .lvl = -2,
        .species = SPECIES_SUNFLORA,
        .ability = Ability_1, // chlorophyll
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SOLARBEAM, MOVE_GIGADRAIN, MOVE_FLAMEBURST, MOVE_GROWTH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BeautyTamia[] = {
    {
        .lvl = -2,
        .species = SPECIES_ELDEGOSS,
        .ability = Ability_Hidden, // effect spore
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_COTTONSPORE, MOVE_LEAFTORNADO, MOVE_SYNTHESIS, MOVE_SING},
    },
    {
        .lvl = -2,
        .species = SPECIES_SAWSBUCK_AUTUMN,
        .ability = Ability_Hidden, // serene grace
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HORNLEECH, MOVE_JUMPKICK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BeautyLori[] = {
    {
        .lvl = -2,
        .species = SPECIES_DECIDUEYE,
        .ability = Ability_2, // tinted lens
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPIRITSHACKLE, MOVE_SHADOWSNEAK, MOVE_LEAFBLADE, MOVE_SYNTHESIS},
    },
    {
        .lvl = -2,
        .species = SPECIES_CACTURNE,
        .ability = Ability_Hidden, // water absorb
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ENERGYBALL, MOVE_LEECHSEED, MOVE_SUCKERPUNCH, MOVE_SPIKES},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BeautyLola[] = {
    {
        .lvl = -2,
        .species = SPECIES_GUMSHOOS,
        .ability = Ability_2, // string jaw
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERFANG, MOVE_ICEFANG, MOVE_CRUNCH, MOVE_THUNDERFANG},
    },
    {
        .lvl = -2,
        .species = SPECIES_SCYTHER,
        .ability = Ability_Hidden, // blademaster
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SWORDSDANCE, MOVE_NIGHTSLASH, MOVE_XSCISSOR, MOVE_WINGATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_SIMIPOUR,
        .ability = Ability_2, // adrenaline
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_SCALD, MOVE_ACROBATICS, MOVE_TAUNT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BeautySheila[] = {
    {
        .lvl = -2,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SOFTBOILED, MOVE_MOONBLAST, MOVE_METRONOME, MOVE_AMNESIA},
    },
    {
        .lvl = -2,
        .species = SPECIES_PERSIAN,
        .ability = Ability_Hidden, // unnerve
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PLAYROUGH, MOVE_NIGHTSLASH, MOVE_TAUNT, MOVE_SLASH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerFemaleTiffany[] = {
    {
        .lvl = -2,
        .species = SPECIES_LAPRAS,
        .ability = Ability_1, // swift swim
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYDROPUMP, MOVE_ICEBEAM, MOVE_DRAGONPULSE, MOVE_CONFUSERAY},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerFemaleNora[] = {
    {
        .lvl = -2,
        .species = SPECIES_HUNTAIL,
        .ability = Ability_2, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_COIL, MOVE_AQUATAIL, MOVE_PSYCHICFANGS},
    },
    {
        .lvl = -2,
        .species = SPECIES_GOREBYSS,
        .ability = Ability_2, // dazzling
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MOONBLAST, MOVE_HYDROPUMP, MOVE_PSYCHIC, MOVE_AGILITY},
    },
    {
        .lvl = -2,
        .species = SPECIES_CLOYSTER,
        .ability = Ability_1, // battle armor
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHELLSMASH, MOVE_ICICLECRASH, MOVE_RAZORSHELL, MOVE_TWINEEDLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerFemaleMelissa[] = {
    {
        .lvl = -2,
        .species = SPECIES_TENTACRUEL,
        .ability = Ability_1, // clear body
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGEWAVE, MOVE_SURF, MOVE_HEX, MOVE_ACIDARMOR},
    },
    {
        .lvl = -2,
        .species = SPECIES_OCTILLERY,
        .ability = Ability_Hidden, // moody
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SNIPESHOT, MOVE_ICEBEAM, MOVE_SIGNALBEAM, MOVE_GUNKSHOT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BeautyGrace[] = {
    {
        .lvl = -2,
        .species = SPECIES_LOPUNNY,
        .ability = Ability_2, // dazzling
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MACHPUNCH, MOVE_HIGHJUMPKICK, MOVE_DOUBLEEDGE, MOVE_BOUNCE},
    },
    {
        .lvl = -2,
        .species = SPECIES_BEWEAR,
        .ability = Ability_2, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PLAYROUGH, MOVE_PAINSPLIT, MOVE_HAMMERARM, MOVE_BRUTALSWING},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BeautyOlivia[] = {
    {
        .lvl = -2,
        .species = SPECIES_CHESNAUGHT,
        .ability = Ability_2, // rough skin
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HAMMERARM, MOVE_PAINSPLIT, MOVE_HORNLEECH, MOVE_LEECHSEED},
    },
    {
        .lvl = -2,
        .species = SPECIES_VENUSAUR,
        .ability = Ability_2, // thick fat
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGEBOMB, MOVE_PETALBLIZZARD, MOVE_SYNTHESIS, MOVE_SLEEPPOWDER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BeautyLauren[] = {
    {
        .lvl = 33,
        .species = SPECIES_WEEPINBELL,
    },
    {
        .lvl = 33,
        .species = SPECIES_BELLSPROUT,
    },
    {
        .lvl = 33,
        .species = SPECIES_WEEPINBELL,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerFemaleAnya[] = {
    {
        .lvl = -2,
        .species = SPECIES_MILOTIC,
        .ability = Ability_Hidden, // serene grace
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPARKLINGARIA, MOVE_MOONBLAST, MOVE_RECOVER, MOVE_ATTRACT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerFemaleAlice[] = {
    {
        .lvl = -2,
        .species = SPECIES_GYARADOS,
        .ability = Ability_Hidden, // moxie
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRAGONDANCE, MOVE_WATERFALL, MOVE_CRUNCH, MOVE_ICEFANG},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerFemaleConnie[] = {
    {
        .lvl = -2,
        .species = SPECIES_PRIMARINA,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPARKLINGARIA, MOVE_MOONBLAST, MOVE_AQUAJET, MOVE_ICYWIND},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerFemaleShirley[] = {
    {
        .lvl = -2,
        .species = SPECIES_SEAKING,
        .ability = Ability_Hidden, // lightning rod
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FISHIOUSREND, MOVE_MEGAHORN, MOVE_HORNDRILL, MOVE_AGILITY},
    },
    {
        .lvl = -2,
        .species = SPECIES_OCTILLERY,
        .ability = Ability_Hidden, // moody
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SNIPESHOT, MOVE_ICEBEAM, MOVE_SIGNALBEAM, MOVE_BULLETSEED},
    },
    {
        .lvl = -2,
        .species = SPECIES_KINGDRA,
        .ability = Ability_Hidden, // sniper
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRAGONDANCE, MOVE_WATERFALL, MOVE_DRAGONPULSE, MOVE_YAWN},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PsychicJohan[] = {
    {
        .lvl = -2,
        .species = SPECIES_GIRAFARIG,
        .ability = Ability_1, // intimidate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BOOMBURST, MOVE_PSYCHIC, MOVE_NASTYPLOT, MOVE_WISH},
    },
    {
        .lvl = -2,
        .species = SPECIES_MEOWSTIC,
        .ability = Ability_1, // prankster
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FAKEOUT, MOVE_PSYSHOCK, MOVE_YAWN, MOVE_TRICK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PsychicTyron[] = {
    {
        .lvl = -2,
        .species = SPECIES_MR_MIME,
        .ability = Ability_Hidden, // misty surge
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DAZZLINGGLEAM, MOVE_PSYCHIC, MOVE_TRICK, MOVE_MAGICALLEAF},
    },
    {
        .lvl = -2,
        .species = SPECIES_MR_MIME_G,
        .ability = Ability_1, // serene cleaner
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_TRICK, MOVE_FREEZEDRY, MOVE_MIRRORCOAT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PsychicCameron[] = {
    {
        .lvl = -2,
        .species = SPECIES_SLOWBRO,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_RELAXED,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_SCALD, MOVE_SLACKOFF, MOVE_TELEPORT},
    },
    {
        .lvl = -2,
        .species = SPECIES_SLOWBRO_G,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_SLUDGEBOMB, MOVE_FLAMETHROWER, MOVE_SCALD},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PsychicPreston[] = {
    {
        .lvl = -2,
        .species = SPECIES_GOLDUCK,
        .ability = Ability_1, // cloud nine
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_NASTYPLOT, MOVE_EXTRASENSORY, MOVE_SURF, MOVE_ICEBEAM},
    },
    {
        .lvl = -2,
        .species = SPECIES_STARMIE,
        .ability = Ability_2, // natural cure
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYDROPUMP, MOVE_PSYCHIC, MOVE_ICEBEAM, MOVE_THUNDERBOLT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RockerRandall[] = {
    {
        .lvl = 20,
        .species = SPECIES_VOLTORB,
    },
    {
        .lvl = 20,
        .species = SPECIES_MAGNEMITE,
    },
    {
        .lvl = 20,
        .species = SPECIES_VOLTORB,
    },
};

static const struct TrainerMonItemCustomMoves sParty_RockerLuca[] = {
    {
        .lvl = -2,
        .species = SPECIES_STUNFISK,
        .ability = Ability_Hidden, // sap sipper
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_THUNDERBOLT, MOVE_SUCKERPUNCH, MOVE_BOUNCE, MOVE_MUDDYWATER},
    },
    {
        .lvl = -2,
        .species = SPECIES_RAPIDASH,
        .ability = Ability_Hidden, // moxie
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MEGAHORN, MOVE_WILDCHARGE, MOVE_POISONJAB, MOVE_FLAMECHARGE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_JugglerDalton[] = {
    {
        .lvl = -2,
        .species = SPECIES_ALAKAZAM,
        .ability = Ability_Hidden, // magic guard
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYSHOCK, MOVE_TRICK, MOVE_CALMMIND, MOVE_RECOVER},
    },
    {
        .lvl = -2,
        .species = SPECIES_MR_RIME,
        .ability = Ability_1, // screen cleaner
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FREEZEDRY, MOVE_DAZZLINGGLEAM, MOVE_SUBSTITUTE, MOVE_PSYCHIC},
    },
};

static const struct TrainerMonItemCustomMoves sParty_JugglerNelson[] = {
    {
        .lvl = 0,
        .species = SPECIES_HATTERENE,
        .ability = Ability_Hidden, // magic bounce
        .nature = NATURE_RELAXED,
        .ivSpread = {31, 0, 31, 31, 31, 0},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_CALMMIND, MOVE_DRAININGKISS, MOVE_PSYSHOCK, MOVE_TRICKROOM},
    },
    {
        .lvl = 0,
        .species = SPECIES_SLOWKING_G,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_SASSY,
        .ivSpread = {IV_HP_GROUND},
        .evSpread = {252, 0, 4, 0, 252, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_SLUDGEBOMB, MOVE_FLAMETHROWER, MOVE_PSYSHOCK, MOVE_HIDDENPOWER},
    },
    {
        .lvl = 0,
        .species = SPECIES_SLOWBRO,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .moves = {MOVE_SCALD, MOVE_ICEBEAM, MOVE_SLACKOFF, MOVE_TELEPORT},
    },
    {
        .lvl = 0,
        .species = SPECIES_BRONZONG,
        .ability = Ability_1, // levitate
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_COLBUR_BERRY,
        .moves = {MOVE_STEALTHROCK, MOVE_IRONHEAD, MOVE_BODYPRESS, MOVE_TOXIC},
    },
    {
        .lvl = 0,
        .species = SPECIES_DELPHOX,
        .ability = Ability_1, // blaze
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_COLBUR_BERRY,
        .moves = {MOVE_FIREBLAST, MOVE_CALMMIND, MOVE_PSYCHIC, MOVE_GRASSKNOT},
    },
    {
        .lvl = 0,
        .species = SPECIES_ESPEON,
        .ability = Ability_1, // magic bounce
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 4, 252, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_CALMMIND, MOVE_PSYCHIC, MOVE_SHADOWBALL, MOVE_MORNINGSUN},
    },
};

static const struct TrainerMonItemCustomMoves sParty_JugglerKirk[] = {
    {
        .lvl = -2,
        .species = SPECIES_METAGROSS,
        .ability = Ability_1, // clear body
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_BODYPRESS, MOVE_ICEPUNCH, MOVE_EARTHQUAKE, MOVE_BULLETPUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_SIGILYPH,
        .ability = Ability_Hidden, // tinted lens
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_TAILWIND, MOVE_LIGHTSCREEN, MOVE_REFLECT, MOVE_MIRRORMOVE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_JugglerShawn[] = {
    {
        .lvl = -2,
        .species = SPECIES_METAGROSS,
        .ability = Ability_1, // clear body
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_BODYPRESS, MOVE_ICEPUNCH, MOVE_EARTHQUAKE, MOVE_BULLETPUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_SIGILYPH,
        .ability = Ability_Hidden, // tinted lens
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_TAILWIND, MOVE_LIGHTSCREEN, MOVE_REFLECT, MOVE_MIRRORMOVE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_JugglerGregory[] = {
    {
        .lvl = 0,
        .species = SPECIES_UMBREON,
        .ability = Ability_Hidden, // magic bounce
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {200, 0, 252, 0, 56, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_FOULPLAY, MOVE_WISH, MOVE_PROTECT, MOVE_HEALBELL},
    },
    {
        .lvl = 0,
        .species = SPECIES_DRACOZOLT,
        .ability = Ability_2, // dracozolt
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_BOLTBEAK, MOVE_DRAGONCLAW, MOVE_FIREFANG, MOVE_SUBSTITUTE},
    },
    {
        .lvl = 0,
        .species = SPECIES_CORVIKNIGHT,
        .ability = Ability_1, // pressure
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {232, 4, 216, 0, 56, 0},
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = {MOVE_BRAVEBIRD, MOVE_BODYPRESS, MOVE_ROOST, MOVE_TAILWIND},
    },
    {
        .lvl = 0,
        .species = SPECIES_HIPPOWDON,
        .ability = Ability_1, // sand stream
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 4, 32, 0, 220, 0},
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = {MOVE_EARTHQUAKE, MOVE_WHIRLWIND, MOVE_SLACKOFF, MOVE_STEALTHROCK},
    },
    {
        .lvl = 0,
        .species = SPECIES_VAPOREON,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {112, 0, 176, 16, 176, 28},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SCALD, MOVE_TOXIC, MOVE_WISH, MOVE_PROTECT},
    },
    {
        .lvl = 0,
        .species = SPECIES_DARMANITANZEN,
        .ability = Ability_1, // zen mode
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {52, 0, 0, 216, 0, 240},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_FLAMETHROWER, MOVE_PSYCHIC, MOVE_GRASSKNOT, MOVE_SUBSTITUTE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_JugglerEdward[] = {
    {
        .lvl = 46,
        .species = SPECIES_VOLTORB,
        .moves = {MOVE_SWIFT, MOVE_LIGHTSCREEN, MOVE_SPARK, MOVE_SONICBOOM},
    },
    {
        .lvl = 46,
        .species = SPECIES_VOLTORB,
        .moves = {MOVE_SWIFT, MOVE_LIGHTSCREEN, MOVE_SPARK, MOVE_SONICBOOM},
    },
    {
        .lvl = 47,
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_SWIFT, MOVE_SPARK, MOVE_SELFDESTRUCT, MOVE_SONICBOOM},
    },
    {
        .lvl = 48,
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_PSYCHIC, MOVE_ROLEPLAY, MOVE_REFLECT, MOVE_ENCORE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_JugglerKayden[] = {
    {
        .lvl = -2,
        .species = SPECIES_INDEEDEE,
        .ability = Ability_Hidden, // psychic surge
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 252, 4, 0},
        .heldItem = ITEM_COLBUR_BERRY,
        .moves = {MOVE_EXPANDINGFORCE, MOVE_ENCORE, MOVE_SHADOWBALL, MOVE_HYPERVOICE},
    },
    {
        .lvl = -2,
        .species = SPECIES_RAICHU_A,
        .ability = Ability_1, // surge surfer
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUSBLAST, MOVE_NASTYPLOT, MOVE_DISCHARGE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_JugglerNate[] = {
    {
        .lvl = -2,
        .species = SPECIES_INDEEDEE,
        .ability = Ability_Hidden, // psychic surge
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 252, 4, 0},
        .heldItem = ITEM_COLBUR_BERRY,
        .moves = {MOVE_EXPANDINGFORCE, MOVE_ENCORE, MOVE_SHADOWBALL, MOVE_HYPERVOICE},
    },
    {
        .lvl = -2,
        .species = SPECIES_RAICHU_A,
        .ability = Ability_1, // surge surfer
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_PSYCHIC, MOVE_FOCUSBLAST, MOVE_NASTYPLOT, MOVE_DISCHARGE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TamerPhil[] = {
    {
        .lvl = -2,
        .species = SPECIES_NIDOKING,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_ICEBEAM, MOVE_SLUDGEWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_GENGAR,
        .ability = Ability_1, // levitate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {4, 0, 0, 252, 0, 252},
        .heldItem = ITEM_BLACK_SLUDGE,
        .moves = {MOVE_SHADOWBALL, MOVE_SLUDGEWAVE, MOVE_WILLOWISP, MOVE_TAUNT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TamerEdgar[] = {
    {
        .lvl = -2,
        .species = SPECIES_TOXAPEX,
        .ability = Ability_1, // merciless
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_BLACK_SLUDGE,
        .moves = {MOVE_TOXIC, MOVE_VENOSHOCK, MOVE_BANEFULBUNKER, MOVE_RECOVER},
    },
    {
        .lvl = -2,
        .species = SPECIES_ROSERADE,
        .ability = Ability_1, // natural cure
        .nature = NATURE_TIMID,
        .ivSpread = {IV_HP_FIRE},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_HIDDENPOWER, MOVE_SLUDGEBOMB, MOVE_LEAFSTORM, MOVE_SYNTHESIS},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TamerJason[] = {
    {
        .lvl = -2,
        .species = SPECIES_EXPLOUD,
        .ability = Ability_Hidden, // punk rock
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 4, 252, 0, 252},
        .heldItem = ITEM_CHOICE_SPECS,
        .moves = {MOVE_BOOMBURST, MOVE_FIREBLAST, MOVE_OVERDRIVE, MOVE_SURF},
    },
    {
        .lvl = -2,
        .species = SPECIES_TOXTRICITY,
        .ability = Ability_1, // punk rock
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_CHOICE_SPECS,
        .moves = {MOVE_BOOMBURST, MOVE_OVERDRIVE, MOVE_VOLTSWITCH, MOVE_SNARL},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TamerCole[] = {
    {
        .lvl = -2,
        .species = SPECIES_ARBOK,
        .ability = Ability_Hidden, // fatal precision
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_GUNKSHOT, MOVE_JAWLOCK, MOVE_COIL, MOVE_ICEFANG},
    },
    {
        .lvl = -2,
        .species = SPECIES_TAUROS,
        .ability = Ability_2, // stamina
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 252, 4, 0, 0, 0},
        .heldItem = ITEM_LUM_BERRY,
        .moves = {MOVE_OUTRAGE, MOVE_ZENHEADBUTT, MOVE_THRASH, MOVE_REST},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TamerVincent[] = {
    {
        .lvl = 0,
        .species = SPECIES_GASTRODON_EAST,
        .ability = Ability_1, // storm drain
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 4, 0, 252, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_EARTHQUAKE, MOVE_RECOVER, MOVE_TOXIC, MOVE_CLEARSMOG},
    },
    {
        .lvl = 0,
        .species = SPECIES_SABLEYE,
        .ability = Ability_1, // magic bounce
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_SABLENITE,
        .moves = {MOVE_KNOCKOFF, MOVE_RECOVER, MOVE_WILLOWISP, MOVE_PROTECT},
    },
    {
        .lvl = 0,
        .species = SPECIES_CORVIKNIGHT,
        .ability = Ability_1, // pressure
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_BRAVEBIRD, MOVE_ROOST, MOVE_DEFOG, MOVE_BULKUP},
    },
    {
        .lvl = 0,
        .species = SPECIES_CHANSEY,
        .ability = Ability_1, // natural cure
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_EVIOLITE,
        .moves = {MOVE_SEISMICTOSS, MOVE_SOFTBOILED, MOVE_STEALTHROCK, MOVE_HEALBELL},
    },
    {
        .lvl = 0,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MOONBLAST, MOVE_SOFTBOILED, MOVE_FLAMETHROWER, MOVE_CALMMIND},
    },
    {
        .lvl = 0,
        .species = SPECIES_ALOMOMOLA,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {40, 0, 216, 0, 252, 0},
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = {MOVE_SCALD, MOVE_TOXIC, MOVE_WISH, MOVE_PROTECT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TamerJohn[] = {
    {
        .lvl = 42,
        .species = SPECIES_RHYHORN,
    },
    {
        .lvl = 42,
        .species = SPECIES_PRIMEAPE,
    },
    {
        .lvl = 42,
        .species = SPECIES_ARBOK,
    },
    {
        .lvl = 42,
        .species = SPECIES_TAUROS,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperSebastian[] = {
    {
        .lvl = -2,
        .species = SPECIES_PIDGEOT,
        .ability = Ability_Hidden, // big pecks
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HURRICANE, MOVE_ROOST, MOVE_QUICKATTACK, MOVE_TWISTER},
    },
    {
        .lvl = -2,
        .species = SPECIES_GLISCOR,
        .ability = Ability_1, // hyper cutter
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_SWORDSDANCE, MOVE_KNOCKOFF, MOVE_ACROBATICS},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperPerry[] = {
    {
        .lvl = -2,
        .species = SPECIES_TOGEKISS,
        .ability = Ability_2, // serene grace
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AURASPHERE, MOVE_EXTRASENSORY, MOVE_MOONBLAST, MOVE_YAWN},
    },
    {
        .lvl = -2,
        .species = SPECIES_GLISCOR,
        .ability = Ability_1, // hyper cutter
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_SWORDSDANCE, MOVE_KNOCKOFF, MOVE_ACROBATICS},
    },
    {
        .lvl = -2,
        .species = SPECIES_JUMPLUFF,
        .ability = Ability_Hidden, // aerilate
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DOUBLEEDGE, MOVE_STRENGTHSAP, MOVE_SLEEPPOWDER, MOVE_UTURN},
    },
    {
        .lvl = -2,
        .species = SPECIES_SWANNA,
        .ability = Ability_Hidden, // moody
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SCALD, MOVE_HURRICANE, MOVE_ROOST, MOVE_FEATHERDANCE},
    },
    {
        .lvl = -2,
        .species = SPECIES_CHARIZARD,
        .ability = Ability_1, // blaze
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FLAMETHROWER, MOVE_AIRSLASH, MOVE_FIRESPIN, MOVE_SHADOWCLAW},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperRobert[] = {
    {
        .lvl = -2,
        .species = SPECIES_PIDGEOT,
        .ability = Ability_Hidden, // big pecks
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HURRICANE, MOVE_ROOST, MOVE_QUICKATTACK, MOVE_TWISTER},
    },
    {
        .lvl = -2,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_Hidden, // reckless
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CLOSECOMBAT, MOVE_DOUBLEEDGE, MOVE_BRAVEBIRD, MOVE_ENDEAVOR},
    },
    {
        .lvl = -2,
        .species = SPECIES_TOUCANNON,
        .ability = Ability_2, // skill link
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BODYSLAM, MOVE_FEATHERDANCE, MOVE_ROCKBLAST, MOVE_BRAVEBIRD},
    },
    {
        .lvl = -2,
        .species = SPECIES_TALONFLAME,
        .ability = Ability_Hidden, // gale wings
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ACROBATICS, MOVE_ROOST, MOVE_FLAREBLITZ, MOVE_QUICKATTACK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperDonald[] = {
    {
        .lvl = -2,
        .species = SPECIES_DRIFBLIM,
        .ability = Ability_1, // aftermath
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AIRSLASH, MOVE_SHADOWBALL, MOVE_STRENGTHSAP, MOVE_DESTINYBOND},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperBenny[] = {
    {
        .lvl = -2,
        .species = SPECIES_MOTHIM,
        .ability = Ability_Hidden, // tinted lens
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_QUIVERDANCE, MOVE_BUGBUZZ, MOVE_PSYCHIC, MOVE_AIRSLASH},
    },
    {
        .lvl = -2,
        .species = SPECIES_PELIPPER,
        .ability = Ability_Hidden, // drizzle
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HURRICANE, MOVE_HYDROPUMP, MOVE_ROOST, MOVE_AGILITY},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperEdwin[] = {
    {
        .lvl = -2,
        .species = SPECIES_DRIFBLIM,
        .ability = Ability_1, // aftermath
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AIRSLASH, MOVE_SHADOWBALL, MOVE_STRENGTHSAP, MOVE_DESTINYBOND},
    },
    {
        .lvl = -2,
        .species = SPECIES_TALONFLAME,
        .ability = Ability_Hidden, // gale wings
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ACROBATICS, MOVE_ROOST, MOVE_FLAREBLITZ, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_Hidden, // reckless
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CLOSECOMBAT, MOVE_DOUBLEEDGE, MOVE_BRAVEBIRD, MOVE_ENDEAVOR},
    },
    {
        .lvl = -2,
        .species = SPECIES_SWANNA,
        .ability = Ability_Hidden, // moody
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SCALD, MOVE_HURRICANE, MOVE_ROOST, MOVE_FEATHERDANCE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperChester[] = {
    {
        .lvl = -2,
        .species = SPECIES_DODRIO,
        .ability = Ability_Hidden, // gale wings
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRILLPECK, MOVE_ACUPRESSURE, MOVE_PURSUIT, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_TALONFLAME,
        .ability = Ability_Hidden, // gale wings
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ACROBATICS, MOVE_ROOST, MOVE_FLAREBLITZ, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_GLISCOR,
        .ability = Ability_1, // hyper cutter
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_SWORDSDANCE, MOVE_KNOCKOFF, MOVE_ACROBATICS},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperWilton[] = {
    {
        .lvl = -2,
        .species = SPECIES_SKARMORY,
        .ability = Ability_1, // sturdy
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPIKES, MOVE_AUTOTOMIZE, MOVE_DRILLPECK, MOVE_NIGHTSLASH},
    },
    {
        .lvl = -2,
        .species = SPECIES_DRAGONITE,
        .ability = Ability_Hidden, // multiscale
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EXTREMESPEED, MOVE_ROOST, MOVE_DRAGONDANCE, MOVE_ICEPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperRamiro[] = {
    {
        .lvl = -2,
        .species = SPECIES_GLISCOR,
        .ability = Ability_Hidden, // poison heal
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_TOXIC_ORB,
        .moves = {MOVE_EARTHQUAKE, MOVE_SWORDSDANCE, MOVE_KNOCKOFF, MOVE_ACROBATICS},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperJacob[] = {
    {
        .lvl = -2,
        .species = SPECIES_TOGEKISS,
        .ability = Ability_1, // serene grace
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MOONBLAST, MOVE_AURASPHERE, MOVE_AIRSLASH, MOVE_YAWN},
    },
    {
        .lvl = -2,
        .species = SPECIES_GLISCOR,
        .ability = Ability_Hidden, // poison heal
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_TOXIC_ORB,
        .moves = {MOVE_EARTHQUAKE, MOVE_SWORDSDANCE, MOVE_KNOCKOFF, MOVE_ACROBATICS},
    },
    {
        .lvl = -2,
        .species = SPECIES_YANMEGA,
        .ability = Ability_1, // speed boost
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BUGBUZZ, MOVE_AIRSLASH, MOVE_ANCIENTPOWER, MOVE_UTURN},
    },
    {
        .lvl = -2,
        .species = SPECIES_GYARADOS,
        .ability = Ability_Hidden, // moxie
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LUM_BERRY,
        .moves = {MOVE_WATERFALL, MOVE_DRAGONDANCE, MOVE_ICEFANG, MOVE_OUTRAGE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperRoger[] = {
    {
        .lvl = -2,
        .species = SPECIES_MANTINE,
        .ability = Ability_2, // water absorb
        .nature = NATURE_CALM,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ROOST, MOVE_AIRSLASH, MOVE_WATERPULSE, MOVE_SIGNALBEAM},
    },
    {
        .lvl = -2,
        .species = SPECIES_BRAVIARY,
        .ability = Ability_1, // fatal precision
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BRAVEBIRD, MOVE_QUICKATTACK, MOVE_SUPERPOWER, MOVE_DOUBLEEDGE},
    },
    {
        .lvl = -2,
        .species = SPECIES_GLISCOR,
        .ability = Ability_1, // hyper cutter
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_SWORDSDANCE, MOVE_KNOCKOFF, MOVE_ACROBATICS},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperReed[] = {
    {
        .lvl = 39,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 39,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 39,
        .species = SPECIES_PIDGEY,
    },
    {
        .lvl = 39,
        .species = SPECIES_PIDGEOTTO,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperKeith[] = {
    {
        .lvl = 39,
        .species = SPECIES_FARFETCHD,
    },
    {
        .lvl = 39,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperCarter[] = {
    {
        .lvl = -2,
        .species = SPECIES_UNFEZANT,
        .ability = Ability_2, // super luck
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRILLPECK, MOVE_ROOST, MOVE_QUICKATTACK, MOVE_FEATHERDANCE},
    },
    {
        .lvl = -2,
        .species = SPECIES_FEAROW,
        .ability = Ability_Hidden, // gale wings
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRILLRUN, MOVE_DRILLPECK, MOVE_ROOST, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_DODRIO,
        .ability = Ability_Hidden, // gale wings
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRILLPECK, MOVE_ACUPRESSURE, MOVE_PURSUIT, MOVE_QUICKATTACK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperMitch[] = {
    {
        .lvl = -2,
        .species = SPECIES_DUNSPARCE,
        .ability = Ability_1, // serene grace
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_NORETREAT, MOVE_EARTHQUAKE, MOVE_ICEFANG, MOVE_KNOCKOFF},
    },
    {
        .lvl = -2,
        .species = SPECIES_TALONFLAME,
        .ability = Ability_Hidden, // gale wings
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ACROBATICS, MOVE_ROOST, MOVE_FLAREBLITZ, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_GLISCOR,
        .ability = Ability_1, // hyper cutter
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_SWORDSDANCE, MOVE_KNOCKOFF, MOVE_ACROBATICS},
    },
    {
        .lvl = -2,
        .species = SPECIES_DODRIO,
        .ability = Ability_Hidden, // gale wings
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRILLPECK, MOVE_ACUPRESSURE, MOVE_PURSUIT, MOVE_QUICKATTACK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperBeck[] = {
    {
        .lvl = -2,
        .species = SPECIES_TALONFLAME,
        .ability = Ability_Hidden, // gale wings
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ACROBATICS, MOVE_ROOST, MOVE_FLAREBLITZ, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_DUNSPARCE,
        .ability = Ability_1, // serene grace
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_NORETREAT, MOVE_EARTHQUAKE, MOVE_ICEFANG, MOVE_KNOCKOFF},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperMarlon[] = {
    {
        .lvl = -2,
        .species = SPECIES_BEAUTIFLY,
        .ability = Ability_1, // swarm
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BUGBUZZ, MOVE_QUIVERDANCE, MOVE_GIGADRAIN, MOVE_AIRCUTTER},
    },
    {
        .lvl = -2,
        .species = SPECIES_YANMEGA,
        .ability = Ability_1, // speed eyes
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BUGBUZZ, MOVE_AIRSLASH, MOVE_ANCIENTPOWER, MOVE_UTURN},
    },
    {
        .lvl = -2,
        .species = SPECIES_SIGILYPH,
        .ability = Ability_Hidden, // tinted lens
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_AIRSLASH, MOVE_MIRRORMOVE, MOVE_LIGHTSCREEN},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BlackBeltKoichi[] = {
    {
        .lvl = 37,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 37,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BlackBeltMike[] = {
    {
        .lvl = 31,
        .species = SPECIES_MANKEY,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 31,
        .species = SPECIES_MANKEY,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 31,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BlackBeltHideki[] = {
    {
        .lvl = 32,
        .species = SPECIES_MACHOP,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 32,
        .species = SPECIES_MACHOKE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BlackBeltAaron[] = {
    {
        .lvl = 36,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BlackBeltHitoshi[] = {
    {
        .lvl = 31,
        .species = SPECIES_MACHOP,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 31,
        .species = SPECIES_MANKEY,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 31,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BlackBeltAtsushi[] = {
    {
        .lvl = -2,
        .species = SPECIES_SCRAFTY,
        .ability = Ability_Hidden, // intimidate
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 4, 0, 0, 252, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_BULKUP, MOVE_KNOCKOFF, MOVE_DRAINPUNCH, MOVE_REST},
    },
    {
        .lvl = -2,
        .species = SPECIES_HAWLUCHA,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ACROBATICS, MOVE_SWORDSDANCE, MOVE_HIGHJUMPKICK, MOVE_ROOST},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BlackBeltKiyo[] = {
    {
        .lvl = -2,
        .species = SPECIES_SAWK,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_EARTHQUAKE, MOVE_CLOSECOMBAT, MOVE_KNOCKOFF, MOVE_POISONJAB},
    },
    {
        .lvl = -2,
        .species = SPECIES_HARIYAMA,
        .ability = Ability_1, // thick fat
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 4, 0, 252, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_CLOSECOMBAT, MOVE_KNOCKOFF, MOVE_HEAVYSLAM, MOVE_ICEPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BlackBeltTakashi[] = {
    {
        .lvl = -2,
        .species = SPECIES_MEDICHAM,
        .ability = Ability_Hidden, // pure power
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_HIGHJUMPKICK, MOVE_ZENHEADBUTT, MOVE_ICEPUNCH, MOVE_BULLETPUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_LUCARIO,
        .ability = Ability_2, // inner focus
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_CLOSECOMBAT, MOVE_METEORMASH, MOVE_SWORDSDANCE, MOVE_EXTREMESPEED},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BlackBeltDaisuke[] = {
    {
        .lvl = 0,
        .species = SPECIES_GARCHOMP,
        .ability = Ability_Hidden, // rough skin
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_SWORDSDANCE, MOVE_EARTHQUAKE, MOVE_STONEEDGE, MOVE_STEALTHROCK},
    },
    {
        .lvl = 0,
        .species = SPECIES_BLISSEY,
        .ability = Ability_1, // natural cure
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .moves = {MOVE_SEISMICTOSS, MOVE_THUNDERWAVE, MOVE_TELEPORT, MOVE_SOFTBOILED},
    },
    {
        .lvl = 0,
        .species = SPECIES_SLOWBRO,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .moves = {MOVE_SCALD, MOVE_FUTURESIGHT, MOVE_SLACKOFF, MOVE_TELEPORT},
    },
    {
        .lvl = 0,
        .species = SPECIES_WEAVILE,
        .ability = Ability_2, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_TRIPLEAXEL, MOVE_KNOCKOFF, MOVE_ICESHARD, MOVE_PURSUIT},
    },
    {
        .lvl = 0,
        .species = SPECIES_ROTOM_WASH,
        .ability = Ability_1, // levitate
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 248, 8, 0, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_VOLTSWITCH, MOVE_HYDROPUMP, MOVE_PAINSPLIT, MOVE_THUNDERWAVE},
    },
    {
        .lvl = 0,
        .species = SPECIES_LOPUNNY,
        .ability = Ability_1, // scrappy
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LOPUNNITE,
        .moves = {MOVE_FAKEOUT, MOVE_CLOSECOMBAT, MOVE_RETURN, MOVE_UTURN},
    },
};

static const struct TrainerMonItemCustomMoves sParty_Rival_PlayerHouse_Tepig[] = {
    {
        .lvl = 0,
        .species = SPECIES_TEPIG,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .moves = {MOVE_TACKLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_Rival_PlayerHouse_Snivy[] = {
    {
        .lvl = 0,
        .species = SPECIES_SNIVY,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .moves = {MOVE_TACKLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_Rival_PlayerHouse_Oshawott[] = {
    {
        .lvl = 0,
        .species = SPECIES_OSHAWOTT,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .moves = {MOVE_TACKLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalRoute22EarlySquirtle[] = {
    {
        .lvl = -2,
        .species = SPECIES_STARLY,
        .ability = Ability_1, // keeneye
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .moves = {MOVE_QUICKATTACK, MOVE_GROWL},
    },
    {
        .lvl = 0,
        .species = SPECIES_SQUIRTLE,
        .ability = Ability_1, // torrent
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .moves = {MOVE_WITHDRAW, MOVE_WATERGUN},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalRoute22EarlyBulbasaur[] = {
    {
        .lvl = -2,
        .species = SPECIES_STARLY,
        .ability = Ability_1, // keeneye
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .moves = {MOVE_QUICKATTACK, MOVE_GROWL},
    },
    {
        .lvl = 0,
        .species = SPECIES_BULBASAUR,
        .ability = Ability_1, // overgrow
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},        
        .moves = {MOVE_VINEWHIP, MOVE_LEECHSEED},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalRoute22EarlyCharmander[] = {
    {
        .lvl = -2,
        .species = SPECIES_STARLY,
        .ability = Ability_1, // keeneye
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .moves = {MOVE_QUICKATTACK, MOVE_GROWL},
    },
    {
        .lvl = 0,
        .species = SPECIES_CHARMANDER,
        .ability = Ability_1, // blaze
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},               
        .moves = {MOVE_SCRATCH, MOVE_EMBER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalCeruleanSquirtle[] = {
    {
        .lvl = -2,
        .species = SPECIES_DRILBUR,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_0},
        .heldItem = ITEM_SOFT_SAND,
        .moves = {MOVE_HONECLAWS, MOVE_DIG, MOVE_METALCLAW, MOVE_ROCKTOMB},
    },
    {
        .lvl = -2,
        .species = SPECIES_STARAVIA,
        .ability = Ability_1, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_0},
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_WINGATTACK, MOVE_ENDEAVOR, MOVE_QUICKATTACK, MOVE_UTURN},
    },
    {
        .lvl = -2,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_0},
        .heldItem = ITEM_MIRACLE_SEED,
        .moves = {MOVE_BULLETSEED, MOVE_MACHPUNCH, MOVE_SPORE, MOVE_STUNSPORE},
    },
    {
        .lvl = 0,
        .species = SPECIES_WARTORTLE,
        .ability = Ability_Hidden, // marvel scale
        .nature = NATURE_BRAVE,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_MYSTIC_WATER,
        .moves = {MOVE_BRINE, MOVE_AQUAJET, MOVE_FAKEOUT, MOVE_BITE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalCeruleanBulbasaur[] = {
    {
        .lvl = -2,
        .species = SPECIES_DRILBUR,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_0},
        .heldItem = ITEM_SOFT_SAND,
        .moves = {MOVE_HONECLAWS, MOVE_DIG, MOVE_METALCLAW, MOVE_ROCKTOMB},
    },
    {
        .lvl = -2,
        .species = SPECIES_STARAVIA,
        .ability = Ability_1, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_0},
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_WINGATTACK, MOVE_ENDEAVOR, MOVE_QUICKATTACK, MOVE_UTURN},
    },
    {
        .lvl = -2,
        .species = SPECIES_HITMONTOP,
        .ability = Ability_1, // intimidate
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MACHPUNCH, MOVE_FAKEOUT, MOVE_BULLETPUNCH, MOVE_COUNTER},
    },
    {
        .lvl = 0,
        .species = SPECIES_IVYSAUR,
        .ability = Ability_2, // thick fat
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_BIG_ROOT,
        .moves = {MOVE_SLUDGE, MOVE_GIGADRAIN, MOVE_LEECHSEED, MOVE_STUNSPORE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalCeruleanCharmander[] = {
    {
        .lvl = -2,
        .species = SPECIES_DRILBUR,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_0},
        .heldItem = ITEM_SOFT_SAND,
        .moves = {MOVE_HONECLAWS, MOVE_DIG, MOVE_METALCLAW, MOVE_ROCKTOMB},
    },
    {
        .lvl = -2,
        .species = SPECIES_STARAVIA,
        .ability = Ability_1, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_0},
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_WINGATTACK, MOVE_ENDEAVOR, MOVE_QUICKATTACK, MOVE_UTURN},
    },
    {
        .lvl = -2,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_0},
        .heldItem = ITEM_MIRACLE_SEED,
        .moves = {MOVE_BULLETSEED, MOVE_MACHPUNCH, MOVE_SPORE, MOVE_STUNSPORE},
    },
    {
        .lvl = 0,
        .species = SPECIES_CHARMELEON,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_CHARCOAL,
        .moves = {MOVE_FIREPUNCH, MOVE_METALCLAW, MOVE_CRUNCH, MOVE_THUNDERPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ScientistTed[] = {
    {
        .lvl = -2,
        .species = SPECIES_ILLUMISE,
        .ability = Ability_2, // tinted lens
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MOONBLAST, MOVE_BUGBUZZ, MOVE_STRUGGLEBUG, MOVE_FLATTER},
    },
    {
        .lvl = -2,
        .species = SPECIES_VOLBEAT,
        .ability = Ability_2, // swarm
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_QUIVERDANCE, MOVE_BUGBUZZ, MOVE_CHARGEBEAM, MOVE_CONFUSERAY},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ScientistConnor[] = {
    {
        .lvl = -2,
        .species = SPECIES_TOXAPEX,
        .ability = Ability_1, // merciless
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BANEFULBUNKER, MOVE_TOXICSPIKES, MOVE_VENOSHOCK, MOVE_RECOVER},
    },
    {
        .lvl = -2,
        .species = SPECIES_MUK_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GUNKSHOT, MOVE_CRUNCH, MOVE_ACIDARMOR, MOVE_DISABLE},
    },
    {
        .lvl = -2,
        .species = SPECIES_EMOLGA,
        .ability = Ability_1, // static
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DISCHARGE, MOVE_AIRSLASH, MOVE_ENCORE},
    },
    {
        .lvl = -2,
        .species = SPECIES_ZEBSTRIKA,
        .ability = Ability_Hidden, // adrenaline
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WILDCHARGE, MOVE_FLAREBLITZ, MOVE_AGILITY, MOVE_PURSUIT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ScientistJerry[] = {
    {
        .lvl = -2,
        .species = SPECIES_MANECTRIC,
        .ability = Ability_Hidden, // intimidate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_THUNDER, MOVE_ROAR, MOVE_SNARL, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_ZEBSTRIKA,
        .ability = Ability_Hidden, // adrenaline
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WILDCHARGE, MOVE_FLAREBLITZ, MOVE_AGILITY, MOVE_PURSUIT},
    },
    {
        .lvl = -2,
        .species = SPECIES_EMOLGA,
        .ability = Ability_1, // static
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DISCHARGE, MOVE_AIRSLASH, MOVE_ENCORE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ScientistJose[] = {
    {
        .lvl = -2,
        .species = SPECIES_ELECTRODE,
        .ability = Ability_Hidden, // galvanize
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TRIATTACK, MOVE_MIRRORCOAT, MOVE_CHARGEBEAM, MOVE_EXPLOSION},
    },
    {
        .lvl = -2,
        .species = SPECIES_GOLEM,
        .ability = Ability_Hidden, // galvanize
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_STONEEDGE, MOVE_EARTHQUAKE, MOVE_DOUBLEEDGE, MOVE_EXPLOSION},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ScientistRodney[] = {
    {
        .lvl = -2,
        .species = SPECIES_ELECTRODE,
        .ability = Ability_Hidden, // galvanize
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TRIATTACK, MOVE_MIRRORCOAT, MOVE_CHARGEBEAM, MOVE_EXPLOSION},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ScientistBeau[] = {
    {
        .lvl = -2,
        .species = SPECIES_MAGNEZONE,
        .ability = Ability_1, // magnet pull
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLASHCANNON, MOVE_LIGHTSCREEN, MOVE_THUNDERWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_WEEZING,
        .ability = Ability_1, // levitate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGEBOMB, MOVE_TOXIC, MOVE_DESTINYBOND, MOVE_HEATWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_ZEBSTRIKA,
        .ability = Ability_Hidden, // adrenaline
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WILDCHARGE, MOVE_FLAREBLITZ, MOVE_AGILITY, MOVE_PURSUIT},
    },
    {
        .lvl = -2,
        .species = SPECIES_MUK_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GUNKSHOT, MOVE_CRUNCH, MOVE_ACIDARMOR, MOVE_DISABLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ScientistTaylor[] = {
    {
        .lvl = -2,
        .species = SPECIES_MAGNEZONE,
        .ability = Ability_1, // magnet pull
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLASHCANNON, MOVE_LIGHTSCREEN, MOVE_THUNDERWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_WEEZING,
        .ability = Ability_1, // levitate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGEBOMB, MOVE_TOXIC, MOVE_DESTINYBOND, MOVE_HEATWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_ELECTRODE,
        .ability = Ability_Hidden, // galvanize
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TRIATTACK, MOVE_MIRRORCOAT, MOVE_CHARGEBEAM, MOVE_EXPLOSION},
    },
    {
        .lvl = -2,
        .species = SPECIES_MUK_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GUNKSHOT, MOVE_CRUNCH, MOVE_ACIDARMOR, MOVE_DISABLE},
    },
    {
        .lvl = -2,
        .species = SPECIES_MANECTRIC,
        .ability = Ability_Hidden, // intimidate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_THUNDER, MOVE_ROAR, MOVE_SNARL, MOVE_QUICKATTACK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ScientistJoshua[] = {
    {
        .lvl = -2,
        .species = SPECIES_ELECTRODE,
        .ability = Ability_Hidden, // galvanize
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TRIATTACK, MOVE_MIRRORCOAT, MOVE_CHARGEBEAM, MOVE_EXPLOSION},
    },
    {
        .lvl = -2,
        .species = SPECIES_MUK_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GUNKSHOT, MOVE_CRUNCH, MOVE_ACIDARMOR, MOVE_DISABLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ScientistParker[] = {
    {
        .lvl = -2,
        .species = SPECIES_MUK_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GUNKSHOT, MOVE_CRUNCH, MOVE_ACIDARMOR, MOVE_DISABLE},
    },
    {
        .lvl = -2,
        .species = SPECIES_MANECTRIC,
        .ability = Ability_Hidden, // intimidate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_THUNDER, MOVE_ROAR, MOVE_SNARL, MOVE_QUICKATTACK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ScientistEd[] = {
    {
        .lvl = -2,
        .species = SPECIES_MAGNEZONE,
        .ability = Ability_1, // magnet pull
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLASHCANNON, MOVE_LIGHTSCREEN, MOVE_THUNDERWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_WEEZING,
        .ability = Ability_1, // levitate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGEBOMB, MOVE_TOXIC, MOVE_DESTINYBOND, MOVE_HEATWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_ZEBSTRIKA,
        .ability = Ability_Hidden, // adrenaline
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WILDCHARGE, MOVE_FLAREBLITZ, MOVE_AGILITY, MOVE_PURSUIT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ScientistTravis[] = {
    {
        .lvl = -2,
        .species = SPECIES_EMOLGA,
        .ability = Ability_1, // volt absorb
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DISCHARGE, MOVE_AIRSLASH, MOVE_ENCORE},
    },
    {
        .lvl = -2,
        .species = SPECIES_LANTURN,
        .ability = Ability_1, // static
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PARABOLICCHARGE, MOVE_HYDROPUMP, MOVE_SIGNALBEAM, MOVE_THUNDERWAVE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ScientistBraydon[] = {
    {
        .lvl = -2,
        .species = SPECIES_DEDENNE,
        .ability = Ability_Hidden, // electric surge
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUPERFANG, MOVE_PARABOLICCHARGE, MOVE_DRAININGKISS, MOVE_VOLTSWITCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_PACHIRISU,
        .ability = Ability_1, // prankster
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_NUZZLE, MOVE_SUPERFANG, MOVE_SWEETKISS, MOVE_CHARM},
    },
    {
        .lvl = -2,
        .species = SPECIES_EMOLGA,
        .ability = Ability_1, // static
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_VOLTSWITCH, MOVE_AIRSLASH, MOVE_ENCORE, MOVE_NUZZLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ScientistIvan[] = {
    {
        .lvl = -2,
        .species = SPECIES_MAGNEZONE,
        .ability = Ability_1, // magnet pull
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLASHCANNON, MOVE_LIGHTSCREEN, MOVE_THUNDERWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_TOGEDEMARU,
        .ability = Ability_1, // rough skin
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MAGNETRISE, MOVE_ZINGZAP, MOVE_FELLSTINGER, MOVE_NUZZLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BossGiovanni[] = {
    {
        .lvl = 1,
        .species = SPECIES_HIPPOWDON,
        .ability = Ability_1, // sand stream
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = {MOVE_STEALTHROCK, MOVE_EARTHQUAKE, MOVE_SLACKOFF, MOVE_WHIRLWIND},
    },
    {
        .lvl = 1,
        .species = SPECIES_NIDOKING,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_ICEBEAM, MOVE_SLUDGEWAVE},
    },
    {
        .lvl = 1,
        .species = SPECIES_MAMOSWINE,
        .ability = Ability_Hidden, // thick fat
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_ICICLECRASH, MOVE_EARTHQUAKE, MOVE_ICESHARD, MOVE_KNOCKOFF},
    },
    {
        .lvl = 1,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_1, // sand rush
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_FOCUS_SASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRONHEAD, MOVE_ROCKSLIDE, MOVE_SWORDSDANCE},
    },
    {
        .lvl = 1,
        .species = SPECIES_GASTRODON_EAST,
        .ability = Ability_2, // storm drain
        .nature = NATURE_SASSY,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 4, 0, 252, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SCALD, MOVE_RECOVER, MOVE_EARTHQUAKE, MOVE_TOXIC},
    },
    {
        .lvl = 2,
        .species = SPECIES_KANGASKHAN,
        .ability = Ability_2, // Scrappy
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_KANGASKHANITE,
        .moves = {MOVE_FAKEOUT, MOVE_BODYSLAM, MOVE_CRUNCH, MOVE_POWERUPPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BossGiovanni2[] = {
    {
        .lvl = 1,
        .species = SPECIES_HIPPOWDON,
        .ability = Ability_1, // sand stream
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_SMOOTH_ROCK,
        .moves = {MOVE_STEALTHROCK, MOVE_EARTHQUAKE, MOVE_SLACKOFF, MOVE_WHIRLWIND},
    },
    {
        .lvl = 1,
        .species = SPECIES_NIDOKING,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_ICEBEAM, MOVE_SLUDGEWAVE},
    },
    {
        .lvl = 1,
        .species = SPECIES_MAMOSWINE,
        .ability = Ability_Hidden, // thick fat
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_ICICLECRASH, MOVE_EARTHQUAKE, MOVE_ICESHARD, MOVE_KNOCKOFF},
    },
    {
        .lvl = 1,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_1, // sand rush
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_FOCUS_SASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRONHEAD, MOVE_ROCKSLIDE, MOVE_SWORDSDANCE},
    },
    {
        .lvl = 1,
        .species = SPECIES_GASTRODON_EAST,
        .ability = Ability_2, // storm drain
        .nature = NATURE_SASSY,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 4, 0, 252, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SCALD, MOVE_RECOVER, MOVE_EARTHQUAKE, MOVE_TOXIC},
    },
    {
        .lvl = 2,
        .species = SPECIES_KANGASKHAN,
        .ability = Ability_2, // Scrappy
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_KANGASKHANITE,
        .moves = {MOVE_FAKEOUT, MOVE_BODYSLAM, MOVE_CRUNCH, MOVE_POWERUPPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LeaderGiovanni[] = {
    {
        .lvl = 1,
        .species = SPECIES_HIPPOWDON,
        .ability = Ability_1, // sand stream
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_SMOOTH_ROCK,
        .moves = {MOVE_STEALTHROCK, MOVE_EARTHQUAKE, MOVE_SLACKOFF, MOVE_WHIRLWIND},
    },
    {
        .lvl = 1,
        .species = SPECIES_NIDOKING,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_ICEBEAM, MOVE_SLUDGEWAVE},
    },
    {
        .lvl = 1,
        .species = SPECIES_MAMOSWINE,
        .ability = Ability_Hidden, // thick fat
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_ICICLECRASH, MOVE_EARTHQUAKE, MOVE_ICESHARD, MOVE_KNOCKOFF},
    },
    {
        .lvl = 1,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_1, // sand rush
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRONHEAD, MOVE_ROCKSLIDE, MOVE_SWORDSDANCE},
    },
    {
        .lvl = 1,
        .species = SPECIES_GASTRODON,
        .ability = Ability_2, // storm drain
        .nature = NATURE_SASSY,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 4, 0, 252, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SCALD, MOVE_RECOVER, MOVE_EARTHPOWER, MOVE_TOXIC},
    },
    {
        .lvl = 3,
        .species = SPECIES_KANGASKHAN,
        .ability = Ability_2, // Scrappy
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_KANGASKHANITE,
        .moves = {MOVE_FAKEOUT, MOVE_BODYSLAM, MOVE_CRUNCH, MOVE_POWERUPPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt[] = {
    {
        .lvl = -2,
        .species = SPECIES_GRIMER_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_POISONFANG, MOVE_DISABLE, MOVE_POISONGAS, MOVE_BITE},
    },
    {
        .lvl = -2,
        .species = SPECIES_ROSELIA,
        .ability = Ability_2, // poison point
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .moves = {MOVE_GRASSWHISTLE, MOVE_MEGADRAIN, MOVE_LEECHSEED, MOVE_STUNSPORE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt2[] = {
    {
        .lvl = -2,
        .species = SPECIES_WHIRLIPEDE,
        .ability = Ability_Hidden, // speed boost
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_IRONDEFENSE, MOVE_BUGBITE, MOVE_PROTECT, MOVE_PURSUIT},
    },
    {
        .lvl = -2,
        .species = SPECIES_RATICATE_A,
        .ability = Ability_2, // hustle
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_ASSURANCE, MOVE_SUPERFANG, MOVE_PURSUIT, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_GOLBAT,
        .ability = Ability_Hidden, // pranster
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .moves = {MOVE_CRUNCH, MOVE_WINGATTACK, MOVE_POISONFANG, MOVE_SUPERSONIC},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt3[] = {
    {
        .lvl = -2,
        .species = SPECIES_QWILFISH,
        .ability = Ability_Hidden, // intimidate
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_TOXICSPIKES, MOVE_SPIKES, MOVE_BUBBLE, MOVE_PINMISSILE},
    },
    {
        .lvl = -2,
        .species = SPECIES_SALANDIT,
        .ability = Ability_1, // corrosion
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_POISONGAS, MOVE_POISONFANG, MOVE_FLAMEBURST},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt4[] = {
    {
        .lvl = -2,
        .species = SPECIES_ARIADOS,
        .ability = Ability_1, // swarm
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_FELLSTINGER, MOVE_SWORDSDANCE, MOVE_SHADOWSNEAK},
    },
    {
        .lvl = -2,
        .species = SPECIES_SANDSLASH,
        .ability = Ability_1, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .moves = {MOVE_DOUBLEKICK, MOVE_POWERUPPUNCH, MOVE_SANDTOMB, MOVE_FURYCUTTER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt5[] = {
    {
        .lvl = -2,
        .species = SPECIES_MIGHTYENA,
        .ability = Ability_1, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHICFANGS, MOVE_JAWLOCK, MOVE_ICEFANG, MOVE_FIREFANG},
    },
    {
        .lvl = -2,
        .species = SPECIES_THIEVUL,
        .ability = Ability_Hidden, // stakeout
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SNARL, MOVE_HONECLAWS, MOVE_THIEF},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt6[] = {
    {
        .lvl = -2,
        .species = SPECIES_QWILFISH,
        .ability = Ability_Hidden, // intimidate
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPIKES, MOVE_TOXICSPIKES, MOVE_STOCKPILE, MOVE_SPITUP},
    },
    {
        .lvl = -2,
        .species = SPECIES_BEEDRILL,
        .ability = Ability_1, // swarm
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BUGBITE, MOVE_PECK, MOVE_PURSUIT, MOVE_RAGE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt7[] = {
    {
        .lvl = -2,
        .species = SPECIES_RATICATE,
        .ability = Ability_Hidden, // hustle
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SWORDSDANCE, MOVE_SUCKERPUNCH, MOVE_DOUBLEEDGE, MOVE_SUPERFANG},
    },
    {
        .lvl = -2,
        .species = SPECIES_CROBAT,
        .ability = Ability_Hidden, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CROSSPOISON, MOVE_LEECHLIFE, MOVE_WINGATTACK, MOVE_CRUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt8[] = {
    {
        .lvl = -2,
        .species = SPECIES_HYPNO,
        .ability = Ability_Hidden, // bad dreams
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FOULPLAY, MOVE_HYPNOSIS, MOVE_PSYCHOCUT, MOVE_SWITCHEROO},
    },
    {
        .lvl = -2,
        .species = SPECIES_MACHAMP,
        .ability = Ability_Hidden, // steadfast
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BULKUP, MOVE_CROSSCHOP, MOVE_MACHPUNCH, MOVE_BULLETPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt9[] = {
    {
        .lvl = -2,
        .species = SPECIES_SKUNTANK,
        .ability = Ability_2, // aftermath
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUCKERPUNCH, MOVE_CROSSPOISON, MOVE_TOXIC, MOVE_MEMENTO},
    },
    {
        .lvl = -2,
        .species = SPECIES_BISHARP,
        .ability = Ability_1, // defiant
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SWORDSDANCE, MOVE_KNOCKOFF, MOVE_IRONHEAD},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt10[] = {
    {
        .lvl = -2,
        .species = SPECIES_MUK_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GUNKSHOT, MOVE_VENOMDRENCH, MOVE_CRUNCH, MOVE_POISONGAS},
    },
    {
        .lvl = -2,
        .species = SPECIES_ROSERADE,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EXTRASENSORY, MOVE_ANCIENTPOWER, MOVE_SYNTHESIS, MOVE_GIGADRAIN},
    },
    {
        .lvl = -2,
        .species = SPECIES_WEEZING_G,
        .ability = Ability_1, // levitate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_STRANGESTEAM, MOVE_SLUDGEBOMB, MOVE_HEATWAVE, MOVE_HAZE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt11[] = {
    {
        .lvl = -2,
        .species = SPECIES_RATICATE,
        .ability = Ability_Hidden, // hustle
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SWORDSDANCE, MOVE_SUCKERPUNCH, MOVE_DOUBLEEDGE, MOVE_SUPERFANG},
    },
    {
        .lvl = -2,
        .species = SPECIES_OBSTAGOON,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUCKERPUNCH, MOVE_CROSSCHOP, MOVE_HONECLAWS, MOVE_HEADBUTT},
    },
    {
        .lvl = -2,
        .species = SPECIES_DIGGERSBY,
        .ability = Ability_Hidden, // huge power
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AGILITY, MOVE_BULLDOZE, MOVE_SWORDSDANCE, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_CORVIKNIGHT,
        .ability = Ability_1, // pressure
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRILLPECK, MOVE_IRONHEAD, MOVE_TAUNT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt12[] = {
    {
        .lvl = -2,
        .species = SPECIES_SLOWBRO_G,
        .ability = Ability_1, // quick draw
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SURF, MOVE_SHELLSIDEARM, MOVE_SLACKOFF, MOVE_PSYCHIC},
    },
    {
        .lvl = -2,
        .species = SPECIES_SLOWKING_G,
        .ability = Ability_2, // storm drain
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SURF, MOVE_SLUDGEBOMB, MOVE_SLACKOFF, MOVE_PSYCHIC},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt13[] = {
    {
        .lvl = -2,
        .species = SPECIES_CROBAT,
        .ability = Ability_Hidden, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CROSSPOISON, MOVE_LEECHLIFE, MOVE_WINGATTACK, MOVE_CRUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_WEEZING_G,
        .ability = Ability_1, // levitate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_STRANGESTEAM, MOVE_SLUDGEBOMB, MOVE_HEATWAVE, MOVE_HAZE},
    },
    {
        .lvl = -2,
        .species = SPECIES_MUK_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GUNKSHOT, MOVE_VENOMDRENCH, MOVE_CRUNCH, MOVE_POISONGAS},
    },
    {
        .lvl = -2,
        .species = SPECIES_BEEDRILL,
        .ability = Ability_1, // swarm
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MEGAHORN, MOVE_FELLSTINGER, MOVE_POISONJAB, MOVE_AGILITY},
    },
    {
        .lvl = -2,
        .species = SPECIES_GENGAR,
        .ability = Ability_1, // levitate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWBALL, MOVE_WILLOWISP, MOVE_DARKPULSE, MOVE_DISABLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt14[] = {
    {
        .lvl = -2,
        .species = SPECIES_MIGHTYENA,
        .ability = Ability_1, // intimidate
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PLAYROUGH, MOVE_SUCKERPUNCH, MOVE_PSYCHICFANGS, MOVE_JAWLOCK},
    },
    {
        .lvl = -2,
        .species = SPECIES_SCRAFTY,
        .ability = Ability_1, // levitate
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRAGONDANCE, MOVE_HIGHJUMPKICK, MOVE_CRUNCH, MOVE_FOCUSPUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_MANDIBUZZ,
        .ability = Ability_2, // overcoat
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_KNOCKOFF, MOVE_TOXIC, MOVE_WHIRLWIND, MOVE_BONERUSH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt15[] = {
    {
        .lvl = -2,
        .species = SPECIES_HONCHKROW,
        .ability = Ability_Hidden, // moxie
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BRAVEBIRD, MOVE_TAUNT, MOVE_SUCKERPUNCH, MOVE_TAILWIND},
    },
    {
        .lvl = -2,
        .species = SPECIES_WEAVILE,
        .ability = Ability_2, // technician
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ASSURANCE, MOVE_ICESHARD, MOVE_QUICKATTACK, MOVE_REVENGE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt16[] = {
    {
        .lvl = -2,
        .species = SPECIES_SANDSLASH,
        .ability = Ability_1, // technician
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_REVENGE, MOVE_SWORDSDANCE, MOVE_MACHPUNCH, MOVE_BULLDOZE},
    },
    {
        .lvl = -2,
        .species = SPECIES_ARBOK,
        .ability = Ability_Hidden, // huge power
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_COIL, MOVE_POISONJAB, MOVE_BULLDOZE},
    },
    {
        .lvl = -2,
        .species = SPECIES_SHARPEDO,
        .ability = Ability_Hidden, // speed boost
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_LIQUIDATION, MOVE_CRUNCH, MOVE_ICEFANG, MOVE_POISONFANG},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt17[] = {
    {
        .lvl = -2,
        .species = SPECIES_SEVIPER,
        .ability = Ability_Hidden, // fatal precision
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_COIL, MOVE_GUNKSHOT, MOVE_CRUNCH, MOVE_SWORDSDANCE},
    },
    {
        .lvl = -2,
        .species = SPECIES_TOXICROAK,
        .ability = Ability_Hidden, // poison touch
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRAINPUNCH, MOVE_SUCKERPUNCH, MOVE_POISONJAB, MOVE_TAUNT},
    },
    {
        .lvl = -2,
        .species = SPECIES_SHIFTRY,
        .ability = Ability_1, // chlorophyll
        .nature = NATURE_NAUGHTY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUNNYDAY, MOVE_GIGADRAIN, MOVE_SUCKERPUNCH, MOVE_LEAFBLADE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt18[] = {
    {
        .lvl = -2,
        .species = SPECIES_CRAWDAUNT,
        .ability = Ability_Hidden, // adaptability
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRABHAMMER, MOVE_CRUNCH, MOVE_SWORDSDANCE, MOVE_KNOCKOFF},
    },
    {
        .lvl = -2,
        .species = SPECIES_DIGGERSBY,
        .ability = Ability_Hidden, // huge power
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AGILITY, MOVE_BULLDOZE, MOVE_SWORDSDANCE, MOVE_QUICKATTACK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt19[] = {
    {
        .lvl = -2,
        .species = SPECIES_CROBAT,
        .ability = Ability_Hidden, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CROSSCHOP, MOVE_WINGATTACK, MOVE_LEECHLIFE, MOVE_CRUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_SCOLIPEDE,
        .ability = Ability_Hidden, // speed boost
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_STEAMROLLER, MOVE_ROCKCLIMB, MOVE_POISONTAIL, MOVE_PURSUIT},
    },
    {
        .lvl = -2,
        .species = SPECIES_GRIMMSNARL,
        .ability = Ability_Hidden, // infiltrator
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPIRITBREAK, MOVE_HAMMERARM, MOVE_BULKUP, MOVE_SUCKERPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt20[] = {
    {
        .lvl = -2,
        .species = SPECIES_WEEZING,
        .ability = Ability_1, // levitate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGEBOMB, MOVE_TOXIC, MOVE_DESTINYBOND, MOVE_HEATWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_MUK_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GUNKSHOT, MOVE_CRUNCH, MOVE_ACIDARMOR, MOVE_DISABLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt21[] = {
    {
        .lvl = -2,
        .species = SPECIES_TOXAPEX,
        .ability = Ability_1, // merciless
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BANEFULBUNKER, MOVE_TOXICSPIKES, MOVE_VENOSHOCK, MOVE_RECOVER},
    },
    {
        .lvl = -2,
        .species = SPECIES_MUK_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GUNKSHOT, MOVE_CRUNCH, MOVE_ACIDARMOR, MOVE_DISABLE},
    },
    {
        .lvl = -2,
        .species = SPECIES_SALAZZLE,
        .ability = Ability_Hidden, // oblivious
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_NASTYPLOT, MOVE_VENOSHOCK, MOVE_FLAMETHROWER, MOVE_ENCORE},
    },
    {
        .lvl = -2,
        .species = SPECIES_GRIMMSNARL,
        .ability = Ability_Hidden, // infiltrator
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPIRITBREAK, MOVE_HAMMERARM, MOVE_BULKUP, MOVE_SUCKERPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt22[] = {
    {
        .lvl = 26,
        .species = SPECIES_DROWZEE,
    },
    {
        .lvl = 26,
        .species = SPECIES_KOFFING,
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt23[] = {
    {
        .lvl = -2,
        .species = SPECIES_MAROWAK_A,
        .ability = Ability_1, // rock head
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FLAREBLITZ, MOVE_SWORDSDANCE, MOVE_STOMPINGTANTRUM, MOVE_SHADOWBONE},
    },
    {
        .lvl = -2,
        .species = SPECIES_SALAZZLE,
        .ability = Ability_Hidden, // oblivious
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_NASTYPLOT, MOVE_VENOSHOCK, MOVE_FLAMETHROWER, MOVE_ENCORE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt24[] = {
    {
        .lvl = -2,
        .species = SPECIES_CROBAT,
        .ability = Ability_Hidden, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CROSSCHOP, MOVE_WINGATTACK, MOVE_LEECHLIFE, MOVE_CRUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_AMOONGUSS,
        .ability = Ability_1, // effect spore
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGEBOMB, MOVE_GIGADRAIN, MOVE_SPORE},
    },
    {
        .lvl = -2,
        .species = SPECIES_SWALOT,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BODYSLAM, MOVE_ENCORE, MOVE_SLUDGEBOMB, MOVE_YAWN},
    },
    {
        .lvl = -2,
        .species = SPECIES_MANDIBUZZ,
        .ability = Ability_2, // overcoat
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_KNOCKOFF, MOVE_TAILWIND, MOVE_TOXIC, MOVE_BONERUSH},
    },
    {
        .lvl = -2,
        .species = SPECIES_MUK_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GUNKSHOT, MOVE_CRUNCH, MOVE_ACIDARMOR, MOVE_DISABLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt25[] = {
    {
        .lvl = -2,
        .species = SPECIES_THIEVUL,
        .ability = Ability_Hidden, // stakeout
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MYSTICALFIRE, MOVE_NIGHTDAZE, MOVE_PARTINGSHOT, MOVE_SNARL},
    },
    {
        .lvl = -2,
        .species = SPECIES_MANDIBUZZ,
        .ability = Ability_2, // overcoat
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_KNOCKOFF, MOVE_TAILWIND, MOVE_TOXIC, MOVE_BONERUSH},
    },
    {
        .lvl = -2,
        .species = SPECIES_CROBAT,
        .ability = Ability_Hidden, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CROSSCHOP, MOVE_WINGATTACK, MOVE_LEECHLIFE, MOVE_CRUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt26[] = {
    {
        .lvl = -2,
        .species = SPECIES_CONKELDURR,
        .ability = Ability_Hidden, // iron fist
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRAINPUNCH, MOVE_STONEEDGE, MOVE_BULKUP},
    },
    {
        .lvl = -2,
        .species = SPECIES_HYPNO,
        .ability = Ability_Hidden, // bad dreams
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUCKERPUNCH, MOVE_ZENHEADBUTT, MOVE_HYPNOSIS, MOVE_SWAGGER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt27[] = {
    {
        .lvl = -2,
        .species = SPECIES_ARBOK,
        .ability = Ability_Hidden, // fatal precision
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_POISONJAB, MOVE_COIL, MOVE_ICEFANG},
    },
    {
        .lvl = -2,
        .species = SPECIES_CROBAT,
        .ability = Ability_Hidden, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CROSSCHOP, MOVE_WINGATTACK, MOVE_LEECHLIFE, MOVE_CRUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_MAROWAK_A,
        .ability = Ability_1, // rock head
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SWORDSDANCE, MOVE_FLAREBLITZ, MOVE_STOMPINGTANTRUM, MOVE_SHADOWBONE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt28[] = {
    {
        .lvl = -2,
        .species = SPECIES_MUK_A,
        .ability = Ability_1, // poison touch
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GUNKSHOT, MOVE_CRUNCH, MOVE_ACIDARMOR, MOVE_DISABLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt29[] = {
    {
        .lvl = -2,
        .species = SPECIES_HYPNO,
        .ability = Ability_Hidden, // bad dreams
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUCKERPUNCH, MOVE_TAUNT, MOVE_HYPNOSIS, MOVE_KNOCKOFF},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt30[] = {
    {
        .lvl = -2,
        .species = SPECIES_SAWK,
        .ability = Ability_1, // sturdy
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BULKUP, MOVE_CLOSECOMBAT, MOVE_COUNTER, MOVE_RETALIATE},
    },
    {
        .lvl = -2,
        .species = SPECIES_THROH,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MATBLOCK, MOVE_BULKUP, MOVE_BODYSLAM, MOVE_REVENGE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt31[] = {
    {
        .lvl = -2,
        .species = SPECIES_CROBAT,
        .ability = Ability_Hidden, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CROSSCHOP, MOVE_WINGATTACK, MOVE_LEECHLIFE, MOVE_CRUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_MANDIBUZZ,
        .ability = Ability_2, // overcoat
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_KNOCKOFF, MOVE_TAILWIND, MOVE_TOXIC, MOVE_BONERUSH},
    },
    {
        .lvl = -2,
        .species = SPECIES_MAROWAK_A,
        .ability = Ability_1, // rock head
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SWORDSDANCE, MOVE_FLAREBLITZ, MOVE_STOMPINGTANTRUM, MOVE_SHADOWBONE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt32[] = {
    {
        .lvl = -2,
        .species = SPECIES_RATICATE,
        .ability = Ability_Hidden, // hustle
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SWORDSDANCE, MOVE_SUCKERPUNCH, MOVE_DOUBLEEDGE, MOVE_SUPERFANG},
    },
    {
        .lvl = -2,
        .species = SPECIES_DIGGERSBY,
        .ability = Ability_Hidden, // huge power
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AGILITY, MOVE_BULLDOZE, MOVE_SWORDSDANCE, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_CLAYDOL,
        .ability = Ability_Hidden, // psych
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHPOWER, MOVE_EXTRASENSORY, MOVE_COSMICPOWER, MOVE_ROCKTOMB},
    },
    {
        .lvl = -2,
        .species = SPECIES_MAROWAK_A,
        .ability = Ability_1, // rock head
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SWORDSDANCE, MOVE_FLAREBLITZ, MOVE_STOMPINGTANTRUM, MOVE_SHADOWBONE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt33[] = {
    {
        .lvl = -2,
        .species = SPECIES_CLAYDOL,
        .ability = Ability_Hidden, // psych
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHPOWER, MOVE_EXTRASENSORY, MOVE_COSMICPOWER, MOVE_ROCKTOMB},
    },
    {
        .lvl = -2,
        .species = SPECIES_MAROWAK_A,
        .ability = Ability_1, // rock head
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SWORDSDANCE, MOVE_FLAREBLITZ, MOVE_STOMPINGTANTRUM, MOVE_SHADOWBONE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt34[] = {
    {
        .lvl = -2,
        .species = SPECIES_MANDIBUZZ,
        .ability = Ability_2, // overcoat
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_KNOCKOFF, MOVE_TAILWIND, MOVE_TOXIC, MOVE_BONERUSH},
    },
    {
        .lvl = -2,
        .species = SPECIES_SANDSLASH,
        .ability = Ability_1, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_REVENGE, MOVE_SWORDSDANCE, MOVE_MACHPUNCH, MOVE_BULLDOZE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt35[] = {
    {
        .lvl = -2,
        .species = SPECIES_RATICATE,
        .ability = Ability_Hidden, // hustle
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SWORDSDANCE, MOVE_SUCKERPUNCH, MOVE_DOUBLEEDGE, MOVE_SUPERFANG},
    },
    {
        .lvl = -2,
        .species = SPECIES_OBSTAGOON,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUCKERPUNCH, MOVE_CROSSCHOP, MOVE_HONECLAWS, MOVE_HEADBUTT},
    },
    {
        .lvl = -2,
        .species = SPECIES_DIGGERSBY,
        .ability = Ability_Hidden, // huge power
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AGILITY, MOVE_BULLDOZE, MOVE_SWORDSDANCE, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_CORVIKNIGHT,
        .ability = Ability_1, // pressure
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRILLPECK, MOVE_IRONHEAD, MOVE_SWAGGER, MOVE_TAUNT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt36[] = {
    {
        .lvl = -2,
        .species = SPECIES_TOXAPEX,
        .ability = Ability_1, // merciless
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BANEFULBUNKER, MOVE_TOXICSPIKES, MOVE_VENOSHOCK, MOVE_RECOVER},
    },
    {
        .lvl = -2,
        .species = SPECIES_CORVIKNIGHT,
        .ability = Ability_1, // pressure
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRILLPECK, MOVE_IRONHEAD, MOVE_SWAGGER, MOVE_TAUNT},
    },
    {
        .lvl = -2,
        .species = SPECIES_HYPNO,
        .ability = Ability_Hidden, // bad dreams
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUCKERPUNCH, MOVE_TAUNT, MOVE_HYPNOSIS, MOVE_KNOCKOFF},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt37[] = {
    {
        .lvl = -2,
        .species = SPECIES_GLISCOR,
        .ability = Ability_1, // hyper cutter
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_KNOCKOFF, MOVE_ACROBATICS, MOVE_UTURN},
    },
    {
        .lvl = -2,
        .species = SPECIES_CROBAT,
        .ability = Ability_Hidden, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CROSSCHOP, MOVE_WINGATTACK, MOVE_LEECHLIFE, MOVE_CRUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_CORVIKNIGHT,
        .ability = Ability_1, // pressure
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRILLPECK, MOVE_IRONHEAD, MOVE_SWAGGER, MOVE_TAUNT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt38[] = {
    {
        .lvl = -2,
        .species = SPECIES_CROBAT,
        .ability = Ability_Hidden, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CROSSCHOP, MOVE_WINGATTACK, MOVE_LEECHLIFE, MOVE_CRUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_CORVIKNIGHT,
        .ability = Ability_1, // pressure
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRILLPECK, MOVE_IRONHEAD, MOVE_SWAGGER, MOVE_TAUNT},
    },
    {
        .lvl = -2,
        .species = SPECIES_GLISCOR,
        .ability = Ability_1, // hyper cutter
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_KNOCKOFF, MOVE_ACROBATICS, MOVE_UTURN},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt39[] = {
    {
        .lvl = -2,
        .species = SPECIES_MIENSHAO,
        .ability = Ability_1, // inner focus
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BOUNCE, MOVE_DRAINPUNCH, MOVE_UTURN, MOVE_HONECLAWS},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt40[] = {
    {
        .lvl = -2,
        .species = SPECIES_HAWLUCHA,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HONECLAWS, MOVE_FLYINGPRESS, MOVE_ROOST, MOVE_ENCORE},
    },
    {
        .lvl = -2,
        .species = SPECIES_OBSTAGOON,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUCKERPUNCH, MOVE_CROSSCHOP, MOVE_HONECLAWS, MOVE_HEADBUTT},
    },
    {
        .lvl = -2,
        .species = SPECIES_DIGGERSBY,
        .ability = Ability_Hidden, // huge power
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AGILITY, MOVE_BULLDOZE, MOVE_SWORDSDANCE, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_GLISCOR,
        .ability = Ability_1, // hyper cutter
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_KNOCKOFF, MOVE_ACROBATICS, MOVE_UTURN},
    },
    {
        .lvl = -2,
        .species = SPECIES_HYPNO,
        .ability = Ability_Hidden, // bad dreams
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUCKERPUNCH, MOVE_TAUNT, MOVE_HYPNOSIS, MOVE_KNOCKOFF},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt41[] = {
    {
        .lvl = -2,
        .species = SPECIES_OBSTAGOON,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUCKERPUNCH, MOVE_CROSSCHOP, MOVE_HONECLAWS, MOVE_HEADBUTT},
    },
    {
        .lvl = -2,
        .species = SPECIES_HYPNO,
        .ability = Ability_Hidden, // bad dreams
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SUCKERPUNCH, MOVE_TAUNT, MOVE_HYPNOSIS, MOVE_KNOCKOFF},
    },
    {
        .lvl = -2,
        .species = SPECIES_CORVIKNIGHT,
        .ability = Ability_1, // pressure
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRILLPECK, MOVE_IRONHEAD, MOVE_SWAGGER, MOVE_TAUNT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerSamuel[] = {
    {
        .lvl = -2,
        .species = SPECIES_STUNFISK,
        .ability = Ability_Hidden, // sap sipper
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_DISCHARGE, MOVE_EARTHPOWER, MOVE_PROTECT, MOVE_TOXIC},
    },
    {
        .lvl = -2,
        .species = SPECIES_KROOKODILE,
        .ability = Ability_2, // moxie
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_WICKEDBLOW, MOVE_EARTHQUAKE, MOVE_STONEEDGE, MOVE_PURSUIT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerGeorge[] = {
    {
        .lvl = 0,
        .species = SPECIES_GENGAR,
        .ability = Ability_1, // levitate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_HP_FIGHTING},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_NASTYPLOT, MOVE_SHADOWBALL, MOVE_SLUDGEWAVE, MOVE_HIDDENPOWER},
    },
    {
        .lvl = 0,
        .species = SPECIES_HOUNDOOM,
        .ability = Ability_Hidden, // intimidate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_HOUNDOOMINITE,
        .moves = {MOVE_NASTYPLOT, MOVE_DARKPULSE, MOVE_FLAMETHROWER, MOVE_SLUDGEBOMB},
    },
    {
        .lvl = 0,
        .species = SPECIES_UMBREON,
        .ability = Ability_Hidden, // magic bounce
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {232, 0, 168, 0, 108, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_WISH, MOVE_PROTECT, MOVE_FOULPLAY, MOVE_HEALBELL},
    },
    {
        .lvl = 0,
        .species = SPECIES_MURKROW,
        .ability = Ability_Hidden, // prankster
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 0, 248, 0, 12, 0},
        .heldItem = ITEM_EVIOLITE,
        .moves = {MOVE_MEANLOOK, MOVE_PERISHSONG, MOVE_ROOST, MOVE_DEFOG},
    },
    {
        .lvl = 0,
        .species = SPECIES_WEAVILE,
        .ability = Ability_2, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_TRIPLEAXEL, MOVE_KNOCKOFF, MOVE_ICESHARD, MOVE_LOWKICK},
    },
    {
        .lvl = 0,
        .species = SPECIES_SLOWBRO,
        .ability = Ability_Hidden, // regenrator
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {184, 0, 252, 16, 56, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_SCALD, MOVE_PSYSHOCK, MOVE_FLAMETHROWER, MOVE_ICEBEAM},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerColby[] = {
    {
        .lvl = 0,
        .species = SPECIES_PELIPPER,
        .ability = Ability_Hidden, // drizzle
        .nature = NATURE_RELAXED,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 8, 252, 0, 0, 0},
        .heldItem = ITEM_DAMP_ROCK,
        .moves = {MOVE_SCALD, MOVE_ROOST, MOVE_HURRICANE, MOVE_DEFOG},
    },
    {
        .lvl = 0,
        .species = SPECIES_SWAMPERT,
        .ability = Ability_1, // swift swim
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_SWAMPERTITE,
        .moves = {MOVE_EARTHQUAKE, MOVE_WATERFALL, MOVE_ICEPUNCH, MOVE_SUBSTITUTE},
    },
    {
        .lvl = 0,
        .species = SPECIES_DRACOVISH,
        .ability = Ability_Hidden, // swift swim
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {4, 252, 0, 0, 0, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_FISHIOUSREND, MOVE_OUTRAGE, MOVE_PSYCHICFANGS, MOVE_CRUNCH},
    },
    {
        .lvl = 0,
        .species = SPECIES_FERROTHORN,
        .ability = Ability_1, // iron barbs
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 8, 252, 0, 0, 0},
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = {MOVE_LEECHSEED, MOVE_BODYPRESS, MOVE_KNOCKOFF, MOVE_SPIKES},
    },
    {
        .lvl = 0,
        .species = SPECIES_MANTINE,
        .ability = Ability_2, // water absorb
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 4, 0, 252, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SCALD, MOVE_ROOST, MOVE_TOXIC, MOVE_HAZE},
    },
    {
        .lvl = 0,
        .species = SPECIES_GARCHOMP,
        .ability = Ability_Hidden, // rough skin
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LUM_BERRY,
        .moves = {MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_STEALTHROCK, MOVE_SWORDSDANCE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerPaul[] = {
    {
        .lvl = 42,
        .species = SPECIES_SLOWPOKE,
        .moves = {MOVE_HEADBUTT, MOVE_CONFUSION, MOVE_WATERGUN, MOVE_DISABLE},
    },
    {
        .lvl = 42,
        .species = SPECIES_SHELLDER,
        .moves = {MOVE_AURORABEAM, MOVE_CLAMP, MOVE_SUPERSONIC, MOVE_LEER},
    },
    {
        .lvl = 42,
        .species = SPECIES_KINGLER,
        .moves = {MOVE_GUILLOTINE, MOVE_STOMP, MOVE_MUDSHOT, MOVE_BUBBLE},
    },
    {
        .lvl = 42,
        .species = SPECIES_STARMIE,
        .moves = {MOVE_BUBBLEBEAM, MOVE_SWIFT, MOVE_RECOVER, MOVE_RAPIDSPIN},
    },
    {
        .lvl = 42,
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_CONFUSION, MOVE_SCRATCH, MOVE_SCREECH, MOVE_DISABLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerRolando[] = {
    {
        .lvl = 0,
        .species = SPECIES_SKARMORY,
        .ability = Ability_1, // sturdy
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = {MOVE_IRONDEFENSE, MOVE_BODYPRESS, MOVE_ROOST, MOVE_SPIKES},
    },
    {
        .lvl = 0,
        .species = SPECIES_CHANSEY,
        .ability = Ability_1, // natural cure
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 0, 252, 0, 8, 0},
        .heldItem = ITEM_EVIOLITE,
        .moves = {MOVE_AROMATHERAPY, MOVE_SOFTBOILED, MOVE_STEALTHROCK, MOVE_SEISMICTOSS},
    },
    {
        .lvl = 0,
        .species = SPECIES_TOXAPEX,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 104, 0, 152, 0},
        .heldItem = ITEM_PAYAPA_BERRY,
        .moves = {MOVE_KNOCKOFF, MOVE_RECOVER, MOVE_TOXIC, MOVE_HAZE},
    },
    {
        .lvl = 0,
        .species = SPECIES_ROTOM_WASH,
        .ability = Ability_1, // levitate
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 188, 68, 0, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_VOLTSWITCH, MOVE_HYDROPUMP, MOVE_PAINSPLIT, MOVE_THUNDERWAVE},
    },
    {
        .lvl = 0,
        .species = SPECIES_GLISCOR,
        .ability = Ability_Hidden, // poison heal
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 0, 144, 112},
        .heldItem = ITEM_TOXIC_ORB,
        .moves = {MOVE_EARTHQUAKE, MOVE_DEFOG, MOVE_TOXIC, MOVE_ROOST},
    },
    {
        .lvl = 0,
        .species = SPECIES_SCIZOR,
        .ability = Ability_1, // technician
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 40, 0, 0, 0, 220},
        .heldItem = ITEM_SCIZORITE,
        .moves = {MOVE_BULLETPUNCH, MOVE_KNOCKOFF, MOVE_ROOST, MOVE_SWORDSDANCE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerGilbert[] = {
    {
        .lvl = 42,
        .species = SPECIES_PIDGEOTTO,
        .moves = {MOVE_WINGATTACK, MOVE_FEATHERDANCE, MOVE_WHIRLWIND, MOVE_QUICKATTACK},
    },
    {
        .lvl = 42,
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DRILLPECK, MOVE_MIRRORMOVE, MOVE_PURSUIT, MOVE_LEER},
    },
    {
        .lvl = 42,
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_PAYDAY, MOVE_FEINTATTACK, MOVE_SCREECH, MOVE_BITE},
    },
    {
        .lvl = 42,
        .species = SPECIES_LICKITUNG,
        .moves = {MOVE_SLAM, MOVE_DISABLE, MOVE_WRAP, MOVE_SUPERSONIC},
    },
    {
        .lvl = 42,
        .species = SPECIES_TAUROS,
        .moves = {MOVE_HORNATTACK, MOVE_SCARYFACE, MOVE_SWAGGER, MOVE_TAILWHIP},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerOwen[] = {
    {
        .lvl = 42,
        .species = SPECIES_NIDORINO,
        .moves = {MOVE_SCRATCH, MOVE_POISONSTING, MOVE_DOUBLEKICK, MOVE_BITE},
    },
    {
        .lvl = 42,
        .species = SPECIES_NIDORINA,
        .moves = {MOVE_HORNATTACK, MOVE_POISONSTING, MOVE_DOUBLEKICK, MOVE_LEER},
    },
    {
        .lvl = 42,
        .species = SPECIES_RATICATE,
        .moves = {MOVE_SUPERFANG, MOVE_PURSUIT, MOVE_SCARYFACE, MOVE_QUICKATTACK},
    },
    {
        .lvl = 42,
        .species = SPECIES_SANDSLASH,
        .moves = {MOVE_FURYSWIPES, MOVE_SWIFT, MOVE_SLASH, MOVE_POISONSTING},
    },
    {
        .lvl = 42,
        .species = SPECIES_RHYHORN,
        .moves = {MOVE_ROCKBLAST, MOVE_SCARYFACE, MOVE_STOMP, MOVE_TAILWHIP},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerBerke[] = {
    {
        .lvl = 42,
        .species = SPECIES_SEEL,
        .moves = {MOVE_TAKEDOWN, MOVE_AURORABEAM, MOVE_ICYWIND, MOVE_GROWL},
    },
    {
        .lvl = 42,
        .species = SPECIES_GRAVELER,
        .moves = {MOVE_ROCKBLAST, MOVE_MAGNITUDE, MOVE_ROCKTHROW, MOVE_MUDSPORT},
    },
    {
        .lvl = 42,
        .species = SPECIES_KINGLER,
        .moves = {MOVE_GUILLOTINE, MOVE_STOMP, MOVE_MUDSHOT, MOVE_BUBBLE},
    },
    {
        .lvl = 42,
        .species = SPECIES_ONIX,
        .moves = {MOVE_SLAM, MOVE_SANDSTORM, MOVE_DRAGONBREATH, MOVE_ROCKTHROW},
    },
    {
        .lvl = 42,
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_SPIKECANNON, MOVE_AURORABEAM, MOVE_SUPERSONIC, MOVE_PROTECT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerYuji[] = {
    {
        .lvl = -2,
        .species = SPECIES_FLYGON,
        .ability = Ability_2, // compound eyes
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 252, 0, 0, 0, 4},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_DRAGONDANCE, MOVE_EARTHQUAKE, MOVE_LEECHLIFE, MOVE_STONEEDGE},
    },
    {
        .lvl = -2,
        .species = SPECIES_SANDSLASH,
        .ability = Ability_1, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_CLOSECOMBAT, MOVE_EARTHQUAKE, MOVE_SWORDSDANCE, MOVE_MACHPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerWarren[] = {
    {
        .lvl = -2,
        .species = SPECIES_NIDOQUEEN,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_ICEBEAM, MOVE_EARTHPOWER, MOVE_SLUDGEBOMB, MOVE_FLAMETHROWER},
    },
    {
        .lvl = -2,
        .species = SPECIES_NIDOKING,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_ICEBEAM, MOVE_EARTHPOWER, MOVE_SLUDGEBOMB, MOVE_FLAMETHROWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerMary[] = {
    {
        .lvl = -2,
        .species = SPECIES_SHIINOTIC,
        .ability = Ability_2, // effect spore
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DAZZLINGGLEAM, MOVE_STRENGTHSAP, MOVE_SPORE, MOVE_LEECHSEED},
    },
    {
        .lvl = -2,
        .species = SPECIES_JUMPLUFF,
        .ability = Ability_Hidden, // aerilate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TRIATTACK, MOVE_QUICKATTACK, MOVE_STRENGTHSAP, MOVE_BULLETSEED},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerCaroline[] = {
    {
        .lvl = 0,
        .species = SPECIES_PASSIMIAN,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_UTURN, MOVE_CLOSECOMBAT, MOVE_KNOCKOFF, MOVE_ROCKSLIDE},
    },
    {
        .lvl = 0,
        .species = SPECIES_BRONZONG,
        .ability = Ability_1, // levitate
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 4, 252, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_STEALTHROCK, MOVE_PSYCHIC, MOVE_TOXIC, MOVE_PROTECT},
    },
    {
        .lvl = 0,
        .species = SPECIES_WEEZING_G,
        .ability = Ability_1, // levitate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 0, 0, 216, 0, 44},
        .heldItem = ITEM_BLACK_SLUDGE,
        .moves = {MOVE_SLUDGEBOMB, MOVE_FIREBLAST, MOVE_STRANGESTEAM, MOVE_TOXICSPIKES},
    },
    {
        .lvl = 0,
        .species = SPECIES_HAXORUS,
        .ability = Ability_1, // tough claws
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_SCALESHOT, MOVE_DOUBLEIRONBASH, MOVE_EARTHQUAKE, MOVE_FIRSTIMPRESSION},
    },
    {
        .lvl = 0,
        .species = SPECIES_GOLISOPOD,
        .ability = Ability_Hidden, // tough claws
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_SPIKES, MOVE_FIRSTIMPRESSION, MOVE_LIQUIDATION, MOVE_LEECHLIFE},
    },
    {
        .lvl = 0,
        .species = SPECIES_TSAREENA,
        .ability = Ability_Hidden, // queenly majesty
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {4, 252, 0, 0, 0, 252},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .moves = {MOVE_POWERWHIP, MOVE_KNOCKOFF, MOVE_UTURN, MOVE_RAPIDSPIN},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerAlexa[] = {
    {
        .lvl = 0,
        .species = SPECIES_DIGGERSBY,
        .ability = Ability_Hidden, // huge power
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_RETURN, MOVE_HIGHHORSEPOWER, MOVE_ICEPUNCH, MOVE_UTURN},
    },
    {
        .lvl = 0,
        .species = SPECIES_ROTOM_HEAT,
        .ability = Ability_1, // levitate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_OVERHEAT, MOVE_VOLTSWITCH, MOVE_NASTYPLOT, MOVE_PAINSPLIT},
    },
    {
        .lvl = 0,
        .species = SPECIES_RILLABOOM,
        .ability = Ability_Hidden, // grassy surge
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_GRASSYGLIDE, MOVE_KNOCKOFF, MOVE_DRAINPUNCH, MOVE_UTURN},
    },
    {
        .lvl = 0,
        .species = SPECIES_MANDIBUZZ,
        .ability = Ability_2, // overcoat
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 4, 0, 0, 252},
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = {MOVE_TAUNT, MOVE_TOXIC, MOVE_ROOST, MOVE_FOULPLAY},
    },
    {
        .lvl = 0,
        .species = SPECIES_MAGNEZONE,
        .ability = Ability_1, // magnet pull
        .nature = NATURE_MODEST,
        .ivSpread = {IV_HP_FIRE},
        .evSpread = {0, 0, 4, 252, 0, 252},
        .heldItem = ITEM_CHOICE_SPECS,
        .moves = {MOVE_THUNDERBOLT, MOVE_VOLTSWITCH, MOVE_HIDDENPOWER, MOVE_FLASHCANNON},
    },
    {
        .lvl = 0,
        .species = SPECIES_GYARADOS,
        .ability = Ability_1, // intimidate / mold breaker
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 0, 4, 252},
        .heldItem = ITEM_GYARADOSITE,
        .moves = {MOVE_WATERFALL, MOVE_CRUNCH, MOVE_STONEEDGE, MOVE_THUNDERWAVE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerShannon[] = {
    {
        .lvl = 42,
        .species = SPECIES_BEEDRILL,
        .moves = {MOVE_PINMISSILE, MOVE_TWINEEDLE, MOVE_AGILITY, MOVE_PURSUIT},
    },
    {
        .lvl = 42,
        .species = SPECIES_BUTTERFREE,
        .moves = {MOVE_SAFEGUARD, MOVE_PSYBEAM, MOVE_GUST, MOVE_SUPERSONIC},
    },
    {
        .lvl = 42,
        .species = SPECIES_PARASECT,
        .moves = {MOVE_SPORE, MOVE_LEECHLIFE, MOVE_SLASH, MOVE_GROWTH},
    },
    {
        .lvl = 42,
        .species = SPECIES_VENONAT,
        .moves = {MOVE_PSYBEAM, MOVE_STUNSPORE, MOVE_LEECHLIFE, MOVE_DISABLE},
    },
    {
        .lvl = 42,
        .species = SPECIES_VENOMOTH,
        .moves = {MOVE_PSYBEAM, MOVE_GUST, MOVE_SUPERSONIC, MOVE_LEECHLIFE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerNaomi[] = {
    {
        .lvl = 0,
        .species = SPECIES_ROTOM_WASH,
        .ability = Ability_1, // levitate
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 68, 188, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_VOLTSWITCH, MOVE_HYDROPUMP, MOVE_PAINSPLIT, MOVE_THUNDERWAVE},
    },
    {
        .lvl = 0,
        .species = SPECIES_MEDICHAM,
        .ability = Ability_1, // pure power
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_MEDICHAMITE,
        .moves = {MOVE_FAKEOUT, MOVE_HIGHJUMPKICK, MOVE_ZENHEADBUTT, MOVE_BULLETPUNCH},
    },
    {
        .lvl = 0,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_THUNDERWAVE, MOVE_MOONBLAST, MOVE_SOFTBOILED, MOVE_STEALTHROCK},
    },
    {
        .lvl = 0,
        .species = SPECIES_FERROTHORN,
        .ability = Ability_1, // iron barbs
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 92, 0, 164, 0},
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = {MOVE_THUNDERWAVE, MOVE_IRONHEAD, MOVE_SPIKES, MOVE_LEECHSEED},
    },
    {
        .lvl = 0,
        .species = SPECIES_WEAVILE,
        .ability = Ability_2, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_TRIPLEAXEL, MOVE_KNOCKOFF, MOVE_ICESHARD, MOVE_PURSUIT},
    },
    {
        .lvl = 0,
        .species = SPECIES_GLISCOR,
        .ability = Ability_Hidden, // poison heal
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {244, 0, 52, 0, 100, 112},
        .heldItem = ITEM_TOXIC_ORB,
        .moves = {MOVE_EARTHQUAKE, MOVE_DEFOG, MOVE_KNOCKOFF, MOVE_ROOST},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerBrooke[] = {
    {
        .lvl = 42,
        .species = SPECIES_TANGELA,
        .moves = {MOVE_SLAM, MOVE_BIND, MOVE_MEGADRAIN, MOVE_INGRAIN},
    },
    {
        .lvl = 42,
        .species = SPECIES_GLOOM,
        .moves = {MOVE_ACID, MOVE_MOONLIGHT, MOVE_SLEEPPOWDER, MOVE_STUNSPORE},
    },
    {
        .lvl = 42,
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_MEGADRAIN, MOVE_ACID, MOVE_STUNSPORE, MOVE_AROMATHERAPY},
    },
    {
        .lvl = 42,
        .species = SPECIES_IVYSAUR,
        .moves = {MOVE_RAZORLEAF, MOVE_SWEETSCENT, MOVE_GROWL, MOVE_LEECHSEED},
    },
    {
        .lvl = 42,
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_RAZORLEAF, MOVE_GROWTH, MOVE_SLEEPPOWDER, MOVE_POISONPOWDER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerAustina[] = {
    {
        .lvl = 42,
        .species = SPECIES_RHYHORN,
        .moves = {MOVE_HORNDRILL, MOVE_ROCKBLAST, MOVE_SCARYFACE, MOVE_STOMP},
    },
    {
        .lvl = 42,
        .species = SPECIES_NIDORINA,
        .moves = {MOVE_DOUBLEKICK, MOVE_FURYSWIPES, MOVE_BITE, MOVE_FLATTER},
    },
    {
        .lvl = 42,
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_BODYSLAM, MOVE_DOUBLEKICK, MOVE_BITE, MOVE_GROWL},
    },
    {
        .lvl = 42,
        .species = SPECIES_NIDORINO,
        .moves = {MOVE_HORNATTACK, MOVE_POISONSTING, MOVE_FOCUSENERGY, MOVE_LEER},
    },
    {
        .lvl = 42,
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_THRASH, MOVE_DOUBLEKICK, MOVE_POISONSTING, MOVE_PECK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerJulie[] = {
    {
        .lvl = 42,
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_FURYSWIPES, MOVE_BITE, MOVE_SCREECH, MOVE_FEINTATTACK},
    },
    {
        .lvl = 42,
        .species = SPECIES_NINETALES,
        .moves = {MOVE_FLAMETHROWER, MOVE_WILLOWISP, MOVE_CONFUSERAY, MOVE_GRUDGE},
    },
    {
        .lvl = 42,
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FURYATTACK, MOVE_FIRESPIN, MOVE_TAKEDOWN, MOVE_AGILITY},
    },
    {
        .lvl = 42,
        .species = SPECIES_PIKACHU,
        .moves = {MOVE_THUNDERBOLT, MOVE_THUNDERWAVE, MOVE_DOUBLETEAM, MOVE_QUICKATTACK},
    },
    {
        .lvl = 42,
        .species = SPECIES_RAICHU,
        .moves = {MOVE_THUNDER, MOVE_THUNDERWAVE, MOVE_SLAM, MOVE_DOUBLETEAM},
    },
};

static const struct TrainerMonItemCustomMoves sParty_EliteFourLorelei[] = {
    {
        .lvl = 0,
        .species = SPECIES_NINETALES_A,
        .ability = Ability_Hidden, // snow warning
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 4, 0, 252},
        .heldItem = ITEM_ICY_ROCK,
        .moves = {MOVE_AURORAVEIL, MOVE_FREEZEDRY, MOVE_ENCORE, MOVE_PAINSPLIT},
    },
    {
        .lvl = 0,
        .species = SPECIES_ARCTOZOLT,
        .ability = Ability_Hidden, // slush rush
        .nature = NATURE_NAIVE,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 4, 0, 252},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .moves = {MOVE_SUBSTITUTE, MOVE_BOLTBEAK, MOVE_BLIZZARD, MOVE_LOWKICK},
    },
    {
        .lvl = 0,
        .species = SPECIES_DARMANITAN_G,
        .ability = Ability_2, // gorilla tactics
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_UTURN, MOVE_ICICLECRASH, MOVE_FLAREBLITZ, MOVE_EARTHQUAKE},
    },
    {
        .lvl = 0,
        .species = SPECIES_MAMOSWINE,
        .ability = Ability_Hidden, // thick fat
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_ICESHARD, MOVE_EARTHQUAKE, MOVE_ICICLECRASH, MOVE_KNOCKOFF},
    },
    {
        .lvl = 0,
        .species = SPECIES_FROSMOTH,
        .ability = Ability_Hidden, // ice scales
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .moves = {MOVE_QUIVERDANCE, MOVE_SUBSTITUTE, MOVE_ICEBEAM, MOVE_GIGADRAIN},
    },
    {
        .lvl = 2,
        .species = SPECIES_ABOMASNOW,
        .ability = Ability_1, // snow warning
        .nature = NATURE_MODEST,
        .ivSpread = {IV_HP_FIRE},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_ABOMASITE,
        .moves = {MOVE_BLIZZARD, MOVE_GIGADRAIN, MOVE_FOCUSBLAST, MOVE_HIDDENPOWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_EliteFourBruno[] = {
    {
        .lvl = 0,
        .species = SPECIES_SKARMORY,
        .ability = Ability_1, // sturdy
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 160, 0, 0, 96},
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = {MOVE_IRONDEFENSE, MOVE_BODYPRESS, MOVE_ROOST, MOVE_SPIKES},
    },
    {
        .lvl = 0,
        .species = SPECIES_HITMONTOP,
        .ability = Ability_2, // technician
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 252, 0, 0, 8, },
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_TRIPLEAXEL, MOVE_RAPIDSPIN, MOVE_MACHPUNCH, MOVE_CLOSECOMBAT},
    },
    {
        .lvl = 0,
        .species = SPECIES_KOMMO_O,
        .ability = Ability_Hidden, // multiscale
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 0, 116, 140},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_STEALTHROCK, MOVE_TOXIC, MOVE_PROTECT, MOVE_DRAINPUNCH},
    },
    {
        .lvl = 0,
        .species = SPECIES_SCIZOR,
        .ability = Ability_2, // technician
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 16, 104, 0, 140, 0},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .moves = {MOVE_BULLETPUNCH, MOVE_UTURN, MOVE_KNOCKOFF, MOVE_ROOST},
    },
    {
        .lvl = 0,
        .species = SPECIES_ARCHEOPS,
        .ability = Ability_Hidden, // touch claws
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 4, 0, 126, 126},
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = {MOVE_EARTHQUAKE, MOVE_UTURN, MOVE_ROOST, MOVE_CRUNCH},
    },
    {
        .lvl = 2,
        .species = SPECIES_LUCARIO,
        .ability = Ability_1, // steadfast / adaptability
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LUCARIONITE,
        .moves = {MOVE_SWORDSDANCE, MOVE_EARTHQUAKE, MOVE_BULLETPUNCH, MOVE_CLOSECOMBAT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_EliteFourAgatha[] = {
    {
        .lvl = 0,
        .species = SPECIES_SPIRITOMB,
        .ability = Ability_Hidden, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 252, 8, 0, 0, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_PURSUIT, MOVE_SUCKERPUNCH, MOVE_PSYCHIC, MOVE_WILLOWISP},
    },
    {
        .lvl = 0,
        .species = SPECIES_DRAGAPULT,
        .ability = Ability_2, // infiltrator
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_CHOICE_SPECS,
        .moves = {MOVE_DRAGONDANCE, MOVE_DRAGONDARTS, MOVE_PHANTOMFORCE, MOVE_SUBSTITUTE},
    },
    {
        .lvl = 0,
        .species = SPECIES_AEGISLASH,
        .ability = Ability_1, // stance change
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_AIR_BALLOON,
        .moves = {MOVE_SWORDSDANCE, MOVE_CLOSECOMBAT, MOVE_IRONHEAD, MOVE_SHADOWSNEAK},
    },
    {
        .lvl = 0,
        .species = SPECIES_CORSOLA_G,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_EVIOLITE,
        .moves = {MOVE_STEALTHROCK, MOVE_WILLOWISP, MOVE_NIGHTSHADE, MOVE_STRENGTHSAP},
    },
    {
        .lvl = 0,
        .species = SPECIES_JELLICENT_F,
        .ability = Ability_2, // cursed body
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_COLBUR_BERRY,
        .moves = {MOVE_STRENGTHSAP, MOVE_TAUNT, MOVE_TOXIC, MOVE_HEX},
    },
    {
        .lvl = 2,
        .species = SPECIES_GENGAR,
        .ability = Ability_1, // levitate / shadow tag
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_GENGARITE,
        .moves = {MOVE_SHADOWBALL, MOVE_SLUDGEWAVE, MOVE_ICYWIND, MOVE_TAUNT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_EliteFourLance[] = {
    {
        .lvl = 0,
        .species = SPECIES_GARCHOMP,
        .ability = Ability_Hidden, // rough skin
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 108, 0, 0, 148},
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = {MOVE_STEALTHROCK, MOVE_EARTHQUAKE, MOVE_ROAR, MOVE_TOXIC},
    },
    {
        .lvl = 0,
        .species = SPECIES_DRAGAPULT,
        .ability = Ability_Hidden, // cursed body
        .nature = NATURE_HASTY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 4, 0, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_UTURN, MOVE_THUNDERWAVE, MOVE_SHADOWBALL, MOVE_DRAGONDARTS},
    },
    {
        .lvl = 0,
        .species = SPECIES_HYDREIGON,
        .ability = Ability_1, // levitate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_NASTYPLOT, MOVE_DARKPULSE, MOVE_FLAMETHROWER, MOVE_SUBSTITUTE},
    },
    {
        .lvl = 0,
        .species = SPECIES_DRAGONITE,
        .ability = Ability_Hidden, // multiscale
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 52, 56, 0, 0, 152},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_DRAGONDANCE, MOVE_DUALWINGBEAT, MOVE_EARTHQUAKE, MOVE_ROOST},
    },
    {
        .lvl = 0,
        .species = SPECIES_KOMMO_O,
        .ability = Ability_Hidden, // multiscale
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 0, 48, 208},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_IRONDEFENSE, MOVE_EARTHQUAKE, MOVE_BODYPRESS, MOVE_SUBSTITUTE},
    },
    {
        .lvl = 2,
        .species = SPECIES_SALAMENCE,
        .ability = Ability_1, // intimidate / aerilate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_HP_FIRE},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_SALAMENCITE,
        .moves = {MOVE_DRAGONDANCE, MOVE_RETURN, MOVE_ROOST, MOVE_HIDDENPOWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LeaderBrock[] = {
    {
        .lvl = 0,
        .species = SPECIES_ARON,
        .nature = NATURE_IMPISH,
        .ability = Ability_1, // sturdy
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_RED_CARD,
        .moves = {MOVE_STEALTHROCK, MOVE_ROCKTOMB, MOVE_ROAR},
    },
    {
        .lvl = 0,
        .species = SPECIES_DWEBBLE,
        .nature = NATURE_IMPISH,
        .ability = Ability_Hidden, // weakarmor
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_QUICK_CLAW,
        .moves = {MOVE_FURYCUTTER, MOVE_SMACKDOWN},
    },
    {
        .lvl = 0,
        .species = SPECIES_LILEEP,
        .nature = NATURE_QUIET,
        .ability = Ability_Hidden, // storm drain
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_CONFUSERAY, MOVE_MEGADRAIN, MOVE_INGRAIN, MOVE_ATTRACT},
    },
    {
        .lvl = 1,
        .species = SPECIES_ARCHEN,
        .nature = NATURE_JOLLY,
        .ability = Ability_1, // defeatist
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_BERRY_JUICE,
        .moves = {MOVE_WINGATTACK, MOVE_ROCKTHROW},
    },     
};

static const struct TrainerMonItemCustomMoves sParty_LeaderMisty[] = {
    {
        .lvl = -1,
        .species = SPECIES_PELIPPER,
        .nature = NATURE_BOLD,
        .ability = Ability_Hidden, // drizzle
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WATERPULSE, MOVE_ROOST, MOVE_AIRCUTTER, MOVE_UTURN},
    },        
    {
        .lvl = 0,
        .species = SPECIES_MARSHTOMP,
        .nature = NATURE_RELAXED,
        .ability = Ability_2, // stamina
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_STEALTHROCK, MOVE_BARRIER, MOVE_YAWN, MOVE_BULLDOZE},
    },       
    {
        .lvl = 0,
        .species = SPECIES_FROGADIER,
        .nature = NATURE_ADAMANT,
        .ability = Ability_Hidden, // protean
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TOXICSPIKES, MOVE_WATERPULSE, MOVE_PROTECT, MOVE_UTURN},
    },
    {
        .lvl = 0,
        .species = SPECIES_BIBAREL,
        .nature = NATURE_ADAMANT,
        .ability = Ability_2, // unaware
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_QUICKATTACK, MOVE_AQUAJET, MOVE_REST, MOVE_WORKUP},
    },  
    {
        .lvl = 1,
        .species = SPECIES_STARMIE,
        .nature = NATURE_MODEST,
        .ability = Ability_2, // natural cure
        .ivSpread = {IV_MAX},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BUBBLEBEAM, MOVE_RECOVER, MOVE_POWERGEM, MOVE_PSYBEAM},
    },        
};

static const struct TrainerMonItemCustomMoves sParty_LeaderLtSurge[] = {
    {
        .lvl = 0,
        .species = SPECIES_PINCURCHIN,
        .ability = Ability_Hidden, // electric surge
        .nature = NATURE_BOLD,
        .ivSpread = {IV_HP_FIRE},
        .evSpread = {EV_60},
        .heldItem = ITEM_ELECTRIC_SEED,
        .moves = {MOVE_DISCHARGE, MOVE_SCALD, MOVE_HIDDENPOWER, MOVE_SPIKES},
    },
    {
        .lvl = 0,
        .species = SPECIES_RAICHU_A,
        .ability = Ability_1, // surge surfer
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_TWISTED_SPOON,
        .moves = {MOVE_PSYCHIC, MOVE_KNOCKOFF, MOVE_VOLTSWITCH, MOVE_SURF},
    },
    {
        .lvl = 0,
        .species = SPECIES_GALVANTULA,
        .ability = Ability_Hidden, // swarm
        .nature = NATURE_MODEST,
        .ivSpread = {IV_HP_WATER},
        .evSpread = {EV_60},
        .heldItem = ITEM_LEPPA_BERRY,
        .moves = {MOVE_STICKYWEB, MOVE_VOLTSWITCH, MOVE_HIDDENPOWER, MOVE_SIGNALBEAM},
    },
    {
        .lvl = 0,
        .species = SPECIES_ROTOM_WASH,
        .ability = Ability_1, // levitate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_HP_GROUND},
        .evSpread = {EV_60},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_VOLTSWITCH, MOVE_WILLOWISP, MOVE_PAINSPLIT, MOVE_HIDDENPOWER},
    },
    {
        .lvl = 0,
        .species = SPECIES_ROTOM_HEAT,
        .ability = Ability_1, // levitate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_SHUCA_BERRY,
        .moves = {MOVE_VOLTSWITCH, MOVE_TOXIC, MOVE_REFLECT, MOVE_LIGHTSCREEN},
    },
    {
        .lvl = 2,
        .species = SPECIES_BOLTUND,
        .ability = Ability_1, // strong jaw
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_EXPERT_BELT,
        .moves = {MOVE_PSYCHICFANGS, MOVE_ICEFANG, MOVE_THUNDERFANG, MOVE_FIREFANG},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LeaderErika[] = {
    {
        .lvl = 0,
        .species = SPECIES_RILLABOOM,
        .ability = Ability_Hidden, // grassy surge
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHOICE_BAND,
        .moves = {MOVE_GRASSYGLIDE, MOVE_DRAINPUNCH, MOVE_KNOCKOFF, MOVE_UTURN},
    },
    {
        .lvl = 0,
        .species = SPECIES_CRADILY,
        .ability = Ability_Hidden, // storm drain
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 8, 0, 0, 252, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_STEALTHROCK, MOVE_ROCKBLAST, MOVE_TOXIC, MOVE_RECOVER},
    },
    {
        .lvl = 1,
        .species = SPECIES_WHIMSICOTT,
        .ability = Ability_1, // prankster
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 4, 252, 0, 252},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .moves = {MOVE_DAZZLINGGLEAM, MOVE_ENCORE, MOVE_DEFOG, MOVE_KNOCKOFF},
    },
    {
        .lvl = 0,
        .species = SPECIES_ROTOM_MOW,
        .ability = Ability_1, // levitate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_THUNDERBOLT, MOVE_LEAFSTORM, MOVE_VOLTSWITCH, MOVE_TRICK},
    },
    {
        .lvl = 0,
        .species = SPECIES_FERROTHORN,
        .ability = Ability_1, // iron barbs
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_KNOCKOFF, MOVE_SPIKES, MOVE_LEECHSEED, MOVE_BODYPRESS},
    },
    {
        .lvl = 2,
        .species = SPECIES_VENUSAUR,
        .ability = Ability_1, // thick fat
        .nature = NATURE_BOLD,
        .ivSpread = {IV_HP_FIRE},
        .evSpread = {248, 0, 176, 0, 84, 0},
        .heldItem = ITEM_VENUSAURITE,
        .moves = {MOVE_GIGADRAIN, MOVE_LEECHSEED, MOVE_EARTHPOWER, MOVE_HIDDENPOWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LeaderKoga[] = {
    {
        .lvl = 0,
        .species = SPECIES_AMOONGUSS,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_BLACK_SLUDGE,
        .moves = {MOVE_SPORE, MOVE_GIGADRAIN, MOVE_FOULPLAY, MOVE_SYNTHESIS},
    },
    {
        .lvl = 0,
        .species = SPECIES_SLOWKING_G,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_SASSY,
        .ivSpread = {IV_HP_GROUND},
        .evSpread = {252, 0, 0, 4, 252, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_FUTURESIGHT, MOVE_SLUDGEBOMB, MOVE_HIDDENPOWER, MOVE_ICEBEAM},
    },
    {
        .lvl = 0,
        .species = SPECIES_TOXAPEX,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 4, 0},
        .heldItem = ITEM_BLACK_SLUDGE,
        .moves = {MOVE_SCALD, MOVE_RECOVER, MOVE_TOXIC, MOVE_BANEFULBUNKER},
    },
    {
        .lvl = 0,
        .species = SPECIES_NIDOKING,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_ICEBEAM, MOVE_EARTHPOWER, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER},
    },
    {
        .lvl = 0,
        .species = SPECIES_WEEZING_G,
        .ability = Ability_1, // levitate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 4, 0, 0},
        .heldItem = ITEM_BLACK_SLUDGE,
        .moves = {MOVE_WILLOWISP, MOVE_STRANGESTEAM, MOVE_PAINSPLIT, MOVE_HAZE},
    },
    {
        .lvl = 2,
        .species = SPECIES_GENGAR,
        .ability = Ability_1, // levitate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_HP_FIGHTING},
        .evSpread = {0, 0, 252, 252, 4, 252},
        .heldItem = ITEM_GENGARITE,
        .moves = {MOVE_SHADOWBALL, MOVE_SLUDGEWAVE, MOVE_TAUNT, MOVE_HIDDENPOWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LeaderBlaine[] = {
    {
        .lvl = 0,
        .species = SPECIES_TORKOAL,
        .ability = Ability_2, // drought
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 0, 252, 8, 0, 0},
        .heldItem = ITEM_HEAT_ROCK,
        .moves = {MOVE_LAVAPLUME, MOVE_STEALTHROCK, MOVE_RAPIDSPIN, MOVE_YAWN},
    },
    {
        .lvl = 0,
        .species = SPECIES_CINDERACE,
        .ability = Ability_Hidden, // libero
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_PYROBALL, MOVE_UTURN, MOVE_SUCKERPUNCH, MOVE_BULKUP},
    },
    {
        .lvl = 0,
        .species = SPECIES_VOLCARONA,
        .ability = Ability_2, // flame body
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .moves = {MOVE_QUIVERDANCE, MOVE_FIREBLAST, MOVE_PSYCHIC, MOVE_SUBSTITUTE},
    },
    {
        .lvl = 0,
        .species = SPECIES_CHANDELURE,
        .ability = Ability_2, // flame body
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_FOCUS_SASH,
        .moves = {MOVE_FIREBLAST, MOVE_SHADOWBALL, MOVE_TOXIC, MOVE_ENERGYBALL},
    },
    {
        .lvl = 0,
        .species = SPECIES_INCINEROAR,
        .ability = Ability_Hidden, // intimidae
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 4, 0, 0, 252, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_KNOCKOFF, MOVE_TOXIC, MOVE_TAUNT, MOVE_PARTINGSHOT},
    },
    {
        .lvl = 2,
        .species = SPECIES_CHARIZARD,
        .ability = Ability_1, // drought
        .nature = NATURE_TIMID,
        .ivSpread = {IV_HP_FIGHTING},
        .evSpread = {0, 0, 4, 252, 0, 252},
        .heldItem = ITEM_CHARIZARDITE_Y,
        .moves = {MOVE_FIREBLAST, MOVE_HIDDENPOWER, MOVE_SOLARBEAM, MOVE_ROOST},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LeaderSabrina[] = {
    {
        .lvl = 0,
        .species = SPECIES_INDEEDEE_FEMALE,
        .ability = Ability_Hidden, // psychic surge
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 4, 252, 0, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_HYPERVOICE, MOVE_MYSTICALFIRE, MOVE_TRICK, MOVE_PSYCHIC},
    },
    {
        .lvl = 0,
        .species = SPECIES_GARDEVOIR,
        .ability = Ability_2, // trace
        .nature = NATURE_TIMID,
        .ivSpread = {IV_HP_FIGHTING},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_CHOICE_SPECS,
        .moves = {MOVE_PSYCHIC, MOVE_DAZZLINGGLEAM, MOVE_HIDDENPOWER, MOVE_SHADOWBALL},
    },
    {
        .lvl = 0,
        .species = SPECIES_SPIRITOMB,
        .ability = Ability_1, // pressure
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 4, 0, 252, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_PAINSPLIT, MOVE_TAUNT, MOVE_WILLOWISP, MOVE_SHADOWBALL},
    },
    {
        .lvl = 0,
        .species = SPECIES_CLAYDOL,
        .ability = Ability_1, // levitate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 252, 0, 0, 4},
        .heldItem = ITEM_COLBUR_BERRY,
        .moves = {MOVE_STEALTHROCK, MOVE_TOXIC, MOVE_PSYCHIC, MOVE_TELEPORT},
    },
    {
        .lvl = 0,
        .species = SPECIES_SIGILYPH,
        .ability = Ability_Hidden, // tinted lens
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_PSYSHOCK, MOVE_HEATWAVE, MOVE_ROOST, MOVE_HURRICANE},
    },
    {
        .lvl = 2,
        .species = SPECIES_ALAKAZAM,
        .ability = Ability_1, // trace
        .nature = NATURE_MODEST,
        .ivSpread = {IV_HP_FIGHTING},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_ALAKAZITE,
        .moves = {MOVE_PSYCHIC, MOVE_HIDDENPOWER, MOVE_RECOVER, MOVE_SHADOWBALL},
    },
};

static const struct TrainerMonItemCustomMoves sParty_GentlemanThomas[] = {
    {
        .lvl = -2,
        .species = SPECIES_SIMISAGE,
        .ability = Ability_2, // adrenaline
        .nature = NATURE_HASTY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ACROBATICS, MOVE_GIGADRAIN, MOVE_BITE, MOVE_LEECHSEED},
    },
    {
        .lvl = -2,
        .species = SPECIES_SIMISEAR,
        .ability = Ability_2, // adrenaline
        .nature = NATURE_HASTY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ACROBATICS, MOVE_GIGADRAIN, MOVE_BITE, MOVE_YAWN},
    },
};

static const struct TrainerMonItemCustomMoves sParty_GentlemanArthur[] = {
    {
        .lvl = 19,
        .species = SPECIES_NIDORAN_M,
    },
    {
        .lvl = 19,
        .species = SPECIES_NIDORAN_F,
    },
};

static const struct TrainerMonItemCustomMoves sParty_GentlemanTucker[] = {
    {
        .lvl = -2,
        .species = SPECIES_MAGNETON,
        .ability = Ability_2, // stamina
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TRIATTACK, MOVE_DISCHARGE, MOVE_MAGNETRISE, MOVE_THUNDERWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_GOLEM_A,
        .ability = Ability_Hidden, // galvanize
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TAKEDOWN, MOVE_SMACKDOWN, MOVE_ROCKPOLISH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_GentlemanNorton[] = {
    {
        .lvl = 48,
        .species = SPECIES_PERSIAN,
    },
};

static const struct TrainerMonItemCustomMoves sParty_GentlemanWalter[] = {
    {
        .lvl = 17,
        .species = SPECIES_GROWLITHE,
    },
    {
        .lvl = 17,
        .species = SPECIES_PONYTA,
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalSsAnneSquirtle[] = {
    {
        .lvl = 1,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_SOFT_SAND,
        .moves = {MOVE_SWORDSDANCE, MOVE_DRILLRUN, MOVE_STEALTHROCK, MOVE_IRONHEAD},
    },
    {
        .lvl = 0,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_1, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_WINGATTACK, MOVE_CLOSECOMBAT, MOVE_UTURN, MOVE_WHIRLWIND},
    },
    {
        .lvl = 0,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_MIRACLE_SEED,
        .moves = {MOVE_BULLETSEED, MOVE_MACHPUNCH, MOVE_SPORE, MOVE_STUNSPORE},
    },
    {
        .lvl = 2,
        .species = SPECIES_BLASTOISE,
        .ability = Ability_Hidden, // marvel scale
        .nature = NATURE_BRAVE,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_MYSTIC_WATER,
        .moves = {MOVE_AQUARING, MOVE_AURASPHERE, MOVE_FLASHCANNON, MOVE_WATERPULSE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalSsAnneBulbasaur[] = {
    {
        .lvl = 1,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_SOFT_SAND,
        .moves = {MOVE_SWORDSDANCE, MOVE_DRILLRUN, MOVE_STEALTHROCK, MOVE_IRONHEAD},
    },
    {
        .lvl = 0,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_1, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_WINGATTACK, MOVE_CLOSECOMBAT, MOVE_UTURN, MOVE_WHIRLWIND},
    },
    {
        .lvl = 0,
        .species = SPECIES_HITMONTOP,
        .ability = Ability_1, // intimidate
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MACHPUNCH, MOVE_COUNTER, MOVE_BULLETPUNCH, MOVE_SUCKERPUNCH},
    },
    {
        .lvl = 1,
        .species = SPECIES_VENUSAUR,
        .ability = Ability_Hidden, // chlorophyl
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_BIG_ROOT,
        .moves = {MOVE_SLUDGE, MOVE_GIGADRAIN, MOVE_LEECHSEED, MOVE_SUNNYDAY},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalSsAnneCharmander[] = {
    {
        .lvl = 1,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_SOFT_SAND,
        .moves = {MOVE_SWORDSDANCE, MOVE_DRILLRUN, MOVE_STEALTHROCK, MOVE_IRONHEAD},
    },
    {
        .lvl = 0,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_1, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_SHARP_BEAK,
        .moves = {MOVE_WINGATTACK, MOVE_CLOSECOMBAT, MOVE_UTURN, MOVE_WHIRLWIND},
    },
    {
        .lvl = 0,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_MIRACLE_SEED,
        .moves = {MOVE_BULLETSEED, MOVE_MACHPUNCH, MOVE_SPORE, MOVE_STUNSPORE},
    },
    {
        .lvl = 1,
        .species = SPECIES_CHARIZARD,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_20},
        .heldItem = ITEM_CHARCOAL,
        .moves = {MOVE_FIRELASH, MOVE_DRAGONDANCE, MOVE_DRAGONCLAW, MOVE_BULLDOZE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalPokenonTowerSquirtle[] = {
    {
        .lvl = 1,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SWORDSDANCE, MOVE_IRONHEAD, MOVE_EARTHQUAKE, MOVE_RAPIDSPIN},
    },
    {
        .lvl = 0,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_Hidden, // reckless
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_BRAVEBIRD, MOVE_UTURN, MOVE_CLOSECOMBAT, MOVE_ENDEAVOR},
    },
    {
        .lvl = 0,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_FOCUS_SASH,
        .moves = {MOVE_SWORDSDANCE, MOVE_SPORE, MOVE_MACHPUNCH, MOVE_BULLETSEED},
    },
    {
        .lvl = 1,
        .species = SPECIES_SLOWKING_G,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 12, 124, 120, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_FUTURESIGHT, MOVE_SLUDGEBOMB, MOVE_FLAMETHROWER, MOVE_SCALD},
    },
    {
        .lvl = 0,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 200, 0, 56, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MOONBLAST, MOVE_SOFTBOILED, MOVE_STEALTHROCK, MOVE_KNOCKOFF},
    },
    {
        .lvl = 2,
        .species = SPECIES_BLASTOISE,
        .ability = Ability_Hidden, // marvel scale
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_BLASTOISINITE,
        .moves = {MOVE_RAPIDSPIN, MOVE_AURASPHERE, MOVE_DARKPULSE, MOVE_ICEBEAM},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalPokenonTowerBulbasaur[] = {
    {
        .lvl = 1,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SWORDSDANCE, MOVE_IRONHEAD, MOVE_EARTHQUAKE, MOVE_RAPIDSPIN},
    },
    {
        .lvl = 0,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_Hidden, // reckless
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_BRAVEBIRD, MOVE_UTURN, MOVE_CLOSECOMBAT, MOVE_DOUBLEEDGE},
    },
    {
        .lvl = 0,
        .species = SPECIES_HITMONTOP,
        .ability = Ability_1, // intimidate
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 252, 0, 0, 8, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_MACHPUNCH, MOVE_SUCKERPUNCH, MOVE_STONEEDGE, MOVE_EARTHQUAKE},
    },
    {
        .lvl = 1,
        .species = SPECIES_ROTOM_WASH,
        .ability = Ability_1, // levitate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 0, 12, 0 ,0, 248},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_VOLTSWITCH, MOVE_HYDROPUMP, MOVE_PAINSPLIT, MOVE_WILLOWISP},
    },
    {
        .lvl = 0,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 200, 0, 56, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MOONBLAST, MOVE_SOFTBOILED, MOVE_STEALTHROCK, MOVE_KNOCKOFF},
    },
    {
        .lvl = 2,
        .species = SPECIES_VENUSAUR,
        .ability = Ability_2, // thick fat
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 252, 4, 0},
        .heldItem = ITEM_VENUSAURITE,
        .moves = {MOVE_GIGADRAIN, MOVE_SLUDGEBOMB, MOVE_SYNTHESIS, MOVE_EARTHPOWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalPokenonTowerCharmander[] = {
    {
        .lvl = 1,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SWORDSDANCE, MOVE_IRONHEAD, MOVE_EARTHQUAKE, MOVE_RAPIDSPIN},
    },
    {
        .lvl = 0,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_Hidden, // reckless
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_BRAVEBIRD, MOVE_UTURN, MOVE_CLOSECOMBAT, MOVE_DOUBLEEDGE},
    },
    {
        .lvl = 0,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_FOCUS_SASH,
        .moves = {MOVE_SWORDSDANCE, MOVE_SPORE, MOVE_MACHPUNCH, MOVE_BULLETSEED},
    },
    {
        .lvl = 1,
        .species = SPECIES_SLOWKING_G,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 12, 124, 120, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_FUTURESIGHT, MOVE_SLUDGEBOMB, MOVE_FLAMETHROWER, MOVE_SCALD},
    },
    {
        .lvl = 0,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 200, 0, 56, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MOONBLAST, MOVE_SOFTBOILED, MOVE_STEALTHROCK, MOVE_KNOCKOFF},
    },
    {
        .lvl = 2,
        .species = SPECIES_CHARIZARD,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHARIZARDITE_X,
        .moves = {MOVE_DRAGONDANCE, MOVE_FLAREBLITZ, MOVE_DRAGONCLAW, MOVE_ROOST},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalSilphSquirtle[] = {
    {
        .lvl = 1,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SWORDSDANCE, MOVE_IRONHEAD, MOVE_EARTHQUAKE, MOVE_RAPIDSPIN},
    },
    {
        .lvl = 0,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_Hidden, // reckless
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_BRAVEBIRD, MOVE_UTURN, MOVE_CLOSECOMBAT, MOVE_DOUBLEEDGE},
    },
    {
        .lvl = 0,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_FOCUS_SASH,
        .moves = {MOVE_SWORDSDANCE, MOVE_SPORE, MOVE_MACHPUNCH, MOVE_BULLETSEED},
    },
    {
        .lvl = 1,
        .species = SPECIES_SLOWKING_G,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 12, 124, 120, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_FUTURESIGHT, MOVE_SLUDGEBOMB, MOVE_FLAMETHROWER, MOVE_SCALD},
    },
    {
        .lvl = 0,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 200, 0, 56, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MOONBLAST, MOVE_SOFTBOILED, MOVE_STEALTHROCK, MOVE_KNOCKOFF},
    },
    {
        .lvl = 2,
        .species = SPECIES_BLASTOISE,
        .ability = Ability_Hidden, // marvel scale
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 252, 4, 0},
        .heldItem = ITEM_BLASTOISINITE,
        .moves = {MOVE_SHELLSMASH, MOVE_AURASPHERE, MOVE_FLASHCANNON, MOVE_WATERPULSE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalSilphBulbasaur[] = {
    {
        .lvl = 1,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SWORDSDANCE, MOVE_IRONHEAD, MOVE_EARTHQUAKE, MOVE_RAPIDSPIN},
    },
    {
        .lvl = 0,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_Hidden, // reckless
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_BRAVEBIRD, MOVE_UTURN, MOVE_CLOSECOMBAT, MOVE_DOUBLEEDGE},
    },
    {
        .lvl = 1,
        .species = SPECIES_HITMONTOP,
        .ability = Ability_1, // intimidate
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 252, 0, 0, 8, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_MACHPUNCH, MOVE_SUCKERPUNCH, MOVE_STONEEDGE, MOVE_EARTHQUAKE},
    },
    {
        .lvl = 0,
        .species = SPECIES_ROTOM_WASH,
        .ability = Ability_1, // levitate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 0, 12, 0 ,0, 248},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_VOLTSWITCH, MOVE_HYDROPUMP, MOVE_PAINSPLIT, MOVE_WILLOWISP},
    },
    {
        .lvl = 0,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 200, 0, 56, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MOONBLAST, MOVE_SOFTBOILED, MOVE_STEALTHROCK, MOVE_KNOCKOFF},
    },
    {
        .lvl = 2,
        .species = SPECIES_VENUSAUR,
        .ability = Ability_2, // thick fat
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 252, 4, 0},
        .heldItem = ITEM_VENUSAURITE,
        .moves = {MOVE_GIGADRAIN, MOVE_SLUDGEBOMB, MOVE_SYNTHESIS, MOVE_EARTHPOWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalSilphCharmander[] = {
    {
        .lvl = 1,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SWORDSDANCE, MOVE_IRONHEAD, MOVE_EARTHQUAKE, MOVE_RAPIDSPIN},
    },
    {
        .lvl = 0,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_Hidden, // reckless
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_BRAVEBIRD, MOVE_UTURN, MOVE_CLOSECOMBAT, MOVE_DOUBLEEDGE},
    },
    {
        .lvl = 0,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_FOCUS_SASH,
        .moves = {MOVE_SWORDSDANCE, MOVE_SPORE, MOVE_MACHPUNCH, MOVE_BULLETSEED},
    },
    {
        .lvl = 1,
        .species = SPECIES_SLOWKING_G,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 12, 124, 120, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_FUTURESIGHT, MOVE_SLUDGEBOMB, MOVE_FLAMETHROWER, MOVE_SCALD},
    },
    {
        .lvl = 0,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 200, 0, 56, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MOONBLAST, MOVE_SOFTBOILED, MOVE_STEALTHROCK, MOVE_KNOCKOFF},
    },
    {
        .lvl = 2,
        .species = SPECIES_CHARIZARD,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHARIZARDITE_X,
        .moves = {MOVE_DRAGONDANCE, MOVE_FLAREBLITZ, MOVE_DRAGONCLAW, MOVE_ROOST},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalRoute22LateSquirtle[] = {
    {
        .lvl = 0,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SWORDSDANCE, MOVE_IRONHEAD, MOVE_EARTHQUAKE, MOVE_RAPIDSPIN},
    },
    {
        .lvl = 0,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_Hidden, // reckless
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_BRAVEBIRD, MOVE_UTURN, MOVE_CLOSECOMBAT, MOVE_DOUBLEEDGE},
    },
    {
        .lvl = 0,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_FOCUS_SASH,
        .moves = {MOVE_SWORDSDANCE, MOVE_SPORE, MOVE_MACHPUNCH, MOVE_BULLETSEED},
    },
    {
        .lvl = 0,
        .species = SPECIES_SLOWKING_G,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 4, 126, 126, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_FUTURESIGHT, MOVE_SLUDGEBOMB, MOVE_FLAMETHROWER, MOVE_SCALD},
    },
    {
        .lvl = 0,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 200, 0, 56, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MOONBLAST, MOVE_SOFTBOILED, MOVE_STEALTHROCK, MOVE_KNOCKOFF},
    },
    {
        .lvl = 2,
        .species = SPECIES_BLASTOISE,
        .ability = Ability_Hidden, // marvel scale
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 252, 4, 0},
        .heldItem = ITEM_BLASTOISINITE,
        .moves = {MOVE_SHELLSMASH, MOVE_AURASPHERE, MOVE_FLASHCANNON, MOVE_WATERPULSE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalRoute22LateBulbasaur[] = {
    {
        .lvl = 0,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SWORDSDANCE, MOVE_IRONHEAD, MOVE_EARTHQUAKE, MOVE_RAPIDSPIN},
    },
    {
        .lvl = 0,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_Hidden, // reckless
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_BRAVEBIRD, MOVE_UTURN, MOVE_CLOSECOMBAT, MOVE_DOUBLEEDGE},
    },
    {
        .lvl = 0,
        .species = SPECIES_HITMONTOP,
        .ability = Ability_1, // intimidate
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 252, 0, 0, 8, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_MACHPUNCH, MOVE_SUCKERPUNCH, MOVE_STONEEDGE, MOVE_EARTHQUAKE},
    },
    {
        .lvl = 0,
        .species = SPECIES_ROTOM_WASH,
        .ability = Ability_1, // levitate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 0, 4, 0 ,0, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_VOLTSWITCH, MOVE_HYDROPUMP, MOVE_PAINSPLIT, MOVE_WILLOWISP},
    },
    {
        .lvl = 0,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 200, 0, 56, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MOONBLAST, MOVE_SOFTBOILED, MOVE_STEALTHROCK, MOVE_KNOCKOFF},
    },
    {
        .lvl = 2,
        .species = SPECIES_VENUSAUR,
        .ability = Ability_2, // thick fat
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 252, 4, 0},
        .heldItem = ITEM_VENUSAURITE,
        .moves = {MOVE_GIGADRAIN, MOVE_SLUDGEBOMB, MOVE_SYNTHESIS, MOVE_EARTHPOWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RivalRoute22LateCharmander[] = {
    {
        .lvl = 0,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SWORDSDANCE, MOVE_IRONHEAD, MOVE_EARTHQUAKE, MOVE_RAPIDSPIN},
    },
    {
        .lvl = 0,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_Hidden, // reckless
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_BRAVEBIRD, MOVE_UTURN, MOVE_CLOSECOMBAT, MOVE_DOUBLEEDGE},
    },
    {
        .lvl = 0,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_FOCUS_SASH,
        .moves = {MOVE_SWORDSDANCE, MOVE_SPORE, MOVE_MACHPUNCH, MOVE_BULLETSEED},
    },
    {
        .lvl = 0,
        .species = SPECIES_SLOWKING_G,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 4, 126, 126, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_FUTURESIGHT, MOVE_SLUDGEBOMB, MOVE_FLAMETHROWER, MOVE_SCALD},
    },
    {
        .lvl = 0,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 200, 0, 56, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MOONBLAST, MOVE_SOFTBOILED, MOVE_STEALTHROCK, MOVE_KNOCKOFF},
    },
    {
        .lvl = 2,
        .species = SPECIES_CHARIZARD,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHARIZARDITE_X,
        .moves = {MOVE_DRAGONDANCE, MOVE_FLAREBLITZ, MOVE_DRAGONCLAW, MOVE_ROOST},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChampionFirstSquirtle[] = {
    {
        .lvl = 0,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_HP_FIRE},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SWORDSDANCE, MOVE_IRONHEAD, MOVE_EARTHQUAKE, MOVE_HIDDENPOWER},
    },
    {
        .lvl = 0,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_Hidden, // reckless
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_BRAVEBIRD, MOVE_UTURN, MOVE_CLOSECOMBAT, MOVE_DOUBLEEDGE},
    },
    {
        .lvl = 0,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_FOCUS_SASH,
        .moves = {MOVE_SWORDSDANCE, MOVE_SPORE, MOVE_MACHPUNCH, MOVE_BULLETSEED},
    },
    {
        .lvl = 0,
        .species = SPECIES_SLOWKING_G,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 4, 126, 126, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_PSYCHIC, MOVE_SLUDGEBOMB, MOVE_FLAMETHROWER, MOVE_SCALD},
    },
    {
        .lvl = 0,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 200, 0, 56, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MOONBLAST, MOVE_SOFTBOILED, MOVE_STEALTHROCK, MOVE_KNOCKOFF},
    },
    {
        .lvl = 2,
        .species = SPECIES_BLASTOISE,
        .ability = Ability_Hidden, // marvel scale
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 252, 4, 0},
        .heldItem = ITEM_BLASTOISINITE,
        .moves = {MOVE_SHELLSMASH, MOVE_AURASPHERE, MOVE_FLASHCANNON, MOVE_WATERPULSE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChampionFirstBulbasaur[] = {
    {
        .lvl = 0,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_HP_FIRE},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SWORDSDANCE, MOVE_IRONHEAD, MOVE_EARTHQUAKE, MOVE_HIDDENPOWER},
    },
    {
        .lvl = 0,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_Hidden, // reckless
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_BRAVEBIRD, MOVE_UTURN, MOVE_CLOSECOMBAT, MOVE_DOUBLEEDGE},
    },
    {
        .lvl = 0,
        .species = SPECIES_HITMONTOP,
        .ability = Ability_1, // intimidate
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 252, 0, 0, 8, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_MACHPUNCH, MOVE_SUCKERPUNCH, MOVE_STONEEDGE, MOVE_EARTHQUAKE},
    },
    {
        .lvl = 0,
        .species = SPECIES_ROTOM_WASH,
        .ability = Ability_1, // levitate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {248, 0, 4, 0 ,0, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_VOLTSWITCH, MOVE_HYDROPUMP, MOVE_PAINSPLIT, MOVE_WILLOWISP},
    },
    {
        .lvl = 0,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 200, 0, 56, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MOONBLAST, MOVE_SOFTBOILED, MOVE_STEALTHROCK, MOVE_KNOCKOFF},
    },
    {
        .lvl = 2,
        .species = SPECIES_VENUSAUR,
        .ability = Ability_2, // thick fat
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 0, 252, 4, 0},
        .heldItem = ITEM_VENUSAURITE,
        .moves = {MOVE_GIGADRAIN, MOVE_SLUDGEBOMB, MOVE_SYNTHESIS, MOVE_EARTHPOWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChampionFirstCharmander[] = {
    {
        .lvl = 0,
        .species = SPECIES_EXCADRILL,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_HP_FIRE},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_SWORDSDANCE, MOVE_IRONHEAD, MOVE_EARTHQUAKE, MOVE_HIDDENPOWER},
    },
    {
        .lvl = 0,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_Hidden, // reckless
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 4, 0, 0, 252},
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = {MOVE_BRAVEBIRD, MOVE_UTURN, MOVE_CLOSECOMBAT, MOVE_DOUBLEEDGE},
    },
    {
        .lvl = 0,
        .species = SPECIES_BRELOOM,
        .ability = Ability_Hidden, // technician
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 252, 0, 0, 4, 252},
        .heldItem = ITEM_FOCUS_SASH,
        .moves = {MOVE_SWORDSDANCE, MOVE_SPORE, MOVE_MACHPUNCH, MOVE_BULLETSEED},
    },
    {
        .lvl = 0,
        .species = SPECIES_SLOWKING_G,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 4, 126, 126, 0},
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = {MOVE_PSYCHIC, MOVE_SLUDGEBOMB, MOVE_FLAMETHROWER, MOVE_SCALD},
    },
    {
        .lvl = 0,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_CALM,
        .ivSpread = {IV_MAX},
        .evSpread = {252, 0, 200, 0, 56, 0},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_MOONBLAST, MOVE_SOFTBOILED, MOVE_STEALTHROCK, MOVE_KNOCKOFF},
    },
    {
        .lvl = 2,
        .species = SPECIES_CHARIZARD,
        .ability = Ability_1, // drought
        .nature = NATURE_TIMID,
        .ivSpread = {IV_HP_FIGHTING},
        .evSpread = {0, 0, 4, 252, 0, 252},
        .heldItem = ITEM_CHARIZARDITE_Y,
        .moves = {MOVE_FIREBLAST, MOVE_HIDDENPOWER, MOVE_SOLARBEAM, MOVE_ROOST},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChannelerPatricia[] = {
    {
        .lvl = -2,
        .species = SPECIES_CHANDELURE,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWBALL, MOVE_OVERHEAT, MOVE_PAINSPLIT, MOVE_WILLOWISP},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChannelerCarly[] = {
    {
        .lvl = -2,
        .species = SPECIES_DUSKNOIR,
        .ability = Ability_1, // levitate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWPUNCH, MOVE_ICEPUNCH, MOVE_FIREPUNCH, MOVE_THUNDERPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChannelerHope[] = {
    {
        .lvl = -2,
        .species = SPECIES_GENGAR,
        .ability = Ability_1, // levitate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWBALL, MOVE_WILLOWISP, MOVE_DARKPULSE, MOVE_DISABLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChannelerPaula[] = {
    {
        .lvl = -2,
        .species = SPECIES_DRIFBLIM,
        .ability = Ability_1, // aftermath
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWBALL, MOVE_HURRICANE, MOVE_TAILWIND, MOVE_STRENGTHSAP},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChannelerLaurel[] = {
    {
        .lvl = -2,
        .species = SPECIES_COFAGRIGUS,
        .ability = Ability_1, // mummy
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HEX, MOVE_WILLOWISP, MOVE_PROTECT, MOVE_DESTINYBOND},
    },
    {
        .lvl = -2,
        .species = SPECIES_RUNERIGUS,
        .ability = Ability_1, // wandering spirit
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HEX, MOVE_WILLOWISP, MOVE_PROTECT, MOVE_EARTHQUAKE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChannelerJody[] = {
    {
        .lvl = -2,
        .species = SPECIES_FROSLASS,
        .ability = Ability_1, // levitate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FREEZEDRY, MOVE_SHADOWBALL, MOVE_PROTECT, MOVE_DRAININGKISS},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChannelerTammy[] = {
    {
        .lvl = -2,
        .species = SPECIES_CURSOLA,
        .ability = Ability_Hidden, // perish body
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_STRENGTHSAP, MOVE_POWERGEM, MOVE_EARTHPOWER, MOVE_HEX},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChannelerRuth[] = {
    {
        .lvl = -2,
        .species = SPECIES_MIMIKYU,
        .ability = Ability_1, // disguise
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PLAYROUGH, MOVE_WOODHAMMER, MOVE_SHADOWCLAW, MOVE_SHADOWSNEAK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChannelerKarina[] = {
    {
        .lvl = -2,
        .species = SPECIES_AEGISLASH,
        .ability = Ability_1, // stance change
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_KINGSSHIELD, MOVE_SHADOWSNEAK, MOVE_IRONHEAD, MOVE_SACREDSWORD},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChannelerJanae[] = {
    {
        .lvl = -2,
        .species = SPECIES_MISMAGIUS,
        .ability = Ability_1, // levitate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MOONBLAST, MOVE_SHADOWBALL, MOVE_POWERGEM, MOVE_NASTYPLOT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChannelerAngelica[] = {
    {
        .lvl = -2,
        .species = SPECIES_COFAGRIGUS,
        .ability = Ability_1, // mummy
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HEX, MOVE_WILLOWISP, MOVE_PROTECT, MOVE_DESTINYBOND},
    },
    {
        .lvl = -2,
        .species = SPECIES_AEGISLASH,
        .ability = Ability_1, // stance change
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_KINGSSHIELD, MOVE_SHADOWSNEAK, MOVE_IRONHEAD, MOVE_SACREDSWORD},
    },
    {
        .lvl = -2,
        .species = SPECIES_MISMAGIUS,
        .ability = Ability_1, // levitate
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MOONBLAST, MOVE_SHADOWBALL, MOVE_POWERGEM, MOVE_NASTYPLOT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChannelerEmilia[] = {
    {
        .lvl = -2,
        .species = SPECIES_BANETTE,
        .ability = Ability_Hidden, // cursed body
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_POLTERGEIST, MOVE_SUCKERPUNCH, MOVE_WILLOWISP, MOVE_TRICK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChannelerJennifer[] = {
    {
        .lvl = -2,
        .species = SPECIES_DECIDUEYE,
        .ability = Ability_2, // tinted lens
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPIRITSHACKLE, MOVE_BRAVEBIRD, MOVE_SUCKERPUNCH, MOVE_LEAFBLADE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_Channeler1[] = {
    {
        .lvl = 23,
        .species = SPECIES_HAUNTER,
    },
};

static const struct TrainerMonItemCustomMoves sParty_Channeler2[] = {
    {
        .lvl = 24,
        .species = SPECIES_GASTLY,
    },
};

static const struct TrainerMonItemCustomMoves sParty_Channeler3[] = {
    {
        .lvl = 22,
        .species = SPECIES_GASTLY,
    },
};

static const struct TrainerMonItemCustomMoves sParty_Channeler4[] = {
    {
        .lvl = 24,
        .species = SPECIES_GASTLY,
    },
};

static const struct TrainerMonItemCustomMoves sParty_Channeler5[] = {
    {
        .lvl = 22,
        .species = SPECIES_HAUNTER,
    },
};

static const struct TrainerMonItemCustomMoves sParty_Channeler6[] = {
    {
        .lvl = 22,
        .species = SPECIES_GASTLY,
    },
    {
        .lvl = 22,
        .species = SPECIES_GASTLY,
    },
    {
        .lvl = 22,
        .species = SPECIES_GASTLY,
    },
};

static const struct TrainerMonItemCustomMoves sParty_Channeler7[] = {
    {
        .lvl = 24,
        .species = SPECIES_GASTLY,
    },
};

static const struct TrainerMonItemCustomMoves sParty_Channeler8[] = {
    {
        .lvl = 24,
        .species = SPECIES_GASTLY,
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChannelerAmanda[] = {
    {
        .lvl = -2,
        .species = SPECIES_BANETTE,
        .ability = Ability_Hidden, // cursed body
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_POLTERGEIST, MOVE_SUCKERPUNCH, MOVE_TRICK, MOVE_SHADOWSNEAK},
    },
    {
        .lvl = -2,
        .species = SPECIES_DUSKNOIR,
        .ability = Ability_1, // levitate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWPUNCH, MOVE_FIREPUNCH, MOVE_ICEPUNCH, MOVE_THUNDERPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChannelerStacy[] = {
    {
        .lvl = -2,
        .species = SPECIES_JELLICENT,
        .ability = Ability_2, // cursed body
        .nature = NATURE_CAREFUL,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_STRENGTHSAP, MOVE_DESTINYBOND, MOVE_WILLOWISP, MOVE_HEX},
    },
    {
        .lvl = -2,
        .species = SPECIES_GOURGEIST_XL,
        .ability = Ability_1, // intimidate
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CONFUSERAY, MOVE_SEEDBOMB, MOVE_SHADOWSNEAK, MOVE_PAINSPLIT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChannelerTasha[] = {
    {
        .lvl = -2,
        .species = SPECIES_GENGAR,
        .ability = Ability_1, // levitate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HEX, MOVE_WILLOWISP, MOVE_DISABLE, MOVE_HAZE},
    },
    {
        .lvl = -2,
        .species = SPECIES_MISMAGIUS,
        .ability = Ability_1, // levitate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MOONBLAST, MOVE_SHADOWBALL, MOVE_MYSTICALFIRE, MOVE_POWERGEM},
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerJeremy[] = {
    {
        .lvl = -2,
        .species = SPECIES_MACHOKE,
        .ability = Ability_2, // no guard
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MACHPUNCH, MOVE_BRICKBREAK, MOVE_KNOCKOFF},
    },
    {
        .lvl = -2,
        .species = SPECIES_ARBOK,
        .ability = Ability_1, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FIREFANG, MOVE_CRUNCH, MOVE_TOXIC, MOVE_ICEFANG},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerAlma[] = {
    {
        .lvl = -2,
        .species = SPECIES_HUNTAIL,
        .ability = Ability_2, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_COIL, MOVE_AQUATAIL, MOVE_PSYCHICFANGS},
    },
    {
        .lvl = -2,
        .species = SPECIES_PALOSSAND,
        .ability = Ability_1, // water compaction
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWBALL, MOVE_GIGADRAIN, MOVE_EARTHPOWER},
    },
    {
        .lvl = -2,
        .species = SPECIES_NINETALES,
        .ability = Ability_Hidden, // drought
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYSHOCK, MOVE_FIREBLAST, MOVE_WILLOWISP, MOVE_HEX},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerSusie[] = {
    {
        .lvl = -2,
        .species = SPECIES_CORVIKNIGHT,
        .ability = Ability_1, // pressure
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BRAVEBIRD, MOVE_IRONDEFENSE, MOVE_IRONHEAD, MOVE_TAUNT},
    },
    {
        .lvl = -2,
        .species = SPECIES_DIGGERSBY,
        .ability = Ability_Hidden, // huge power
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_BOUNCE, MOVE_HAMMERARM, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_BUTTERFREE,
        .ability = Ability_Hidden, // tinted lens
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_QUIVERDANCE, MOVE_BUGBUZZ, MOVE_SLEEPPOWDER, MOVE_AIRSLASH},
    },
    {
        .lvl = -2,
        .species = SPECIES_PIKACHU,
        .ability = Ability_1, // static
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIGHT_BALL,
        .moves = {MOVE_THUNDERBOLT, MOVE_NUZZLE, MOVE_LIGHTSCREEN, MOVE_NASTYPLOT},
    },
    {
        .lvl = -2,
        .species = SPECIES_EISCUE,
        .ability = Ability_1, // ice face
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ICESHARD, MOVE_FREEZEDRY, MOVE_HEADBUTT, MOVE_WEATHERBALL},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerValerie[] = {
    {
        .lvl = -2,
        .species = SPECIES_ELECTIVIRE,
        .ability = Ability_2, // motor drive
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PLASMAFISTS, MOVE_DRAINPUNCH, MOVE_BULKUP, MOVE_THUNDERWAVE},
    },
    {
        .lvl = -2,
        .species = SPECIES_MAGMORTAR,
        .ability = Ability_1, // flame body
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_STEAMERUPTION, MOVE_LOWKICK, MOVE_THUNDERPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerGwen[] = {
    {
        .lvl = -2,
        .species = SPECIES_FARFETCHD,
        .ability = Ability_2, // defiant
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SWORDSDANCE, MOVE_SUPERPOWER, MOVE_KNOCKOFF, MOVE_BRAVEBIRD},
    },
    {
        .lvl = -2,
        .species = SPECIES_MUNCHLAX,
        .ability = Ability_Hidden, // fluffy
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_BELLYDRUM, MOVE_BODYSLAM, MOVE_BITE},
    },
    {
        .lvl = -2,
        .species = SPECIES_SIRFETCHD,
        .ability = Ability_2, // blademaster
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SWORDSDANCE, MOVE_SUPERPOWER, MOVE_KNOCKOFF, MOVE_POISONJAB},
    },
    {
        .lvl = -2,
        .species = SPECIES_SNORLAX,
        .ability = Ability_Hidden, // fluffy
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_REST, MOVE_HIGHHORSEPOWER, MOVE_SLEEPTALK, MOVE_YAWN},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerVirgil[] = {
    {
        .lvl = -2,
        .species = SPECIES_SIRFETCHD,
        .ability = Ability_2, // blademaster
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_EXPERT_BELT,
        .moves = {MOVE_SWORDSDANCE, MOVE_SUPERPOWER, MOVE_KNOCKOFF, MOVE_POISONJAB},
    },
    {
        .lvl = -2,
        .species = SPECIES_SPIRITOMB,
        .ability = Ability_1, // pressure
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LEFTOVERS,
        .moves = {MOVE_PARTINGSHOT, MOVE_EXTRASENSORY, MOVE_SHADOWBALL, MOVE_NASTYPLOT},
    },
    {
        .lvl = -2,
        .species = SPECIES_WEEZING,
        .ability = Ability_2, // levitate
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = {MOVE_SLUDGEBOMB, MOVE_HEATWAVE, MOVE_HAZE, MOVE_PSYBEAM},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperFlint[] = {
    {
        .lvl = -2,
        .species = SPECIES_ZANGOOSE,
        .ability = Ability_1, // tough claws
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TAUNT, MOVE_NIGHTSLASH, MOVE_REVENGE, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_SEVIPER,
        .ability = Ability_Hidden, // fatal precision
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_0},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_POISONTAIL, MOVE_GLARE, MOVE_SWAGGER, MOVE_BITE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerMissy[] = {
    {
        .lvl = -2,
        .species = SPECIES_SEISMITOAD,
        .ability = Ability_1, // swift swim
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_DAMP_ROCK,
        .moves = {MOVE_HYDROPUMP, MOVE_RAINDANCE, MOVE_DRAINPUNCH, MOVE_HYPERVOICE},
    },
    {
        .lvl = -2,
        .species = SPECIES_EMPOLEON,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYDROPUMP, MOVE_DRILLPECK, MOVE_AQUAJET, MOVE_SWAGGER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerIrene[] = {
    {
        .lvl = -2,
        .species = SPECIES_POLIWRATH,
        .ability = Ability_1, // water absorb
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SURGINGSTRIKES, MOVE_STOMPINGTANTRUM, MOVE_BULKUP, MOVE_FLIPTURN},
    },
    {
        .lvl = -2,
        .species = SPECIES_SEISMITOAD,
        .ability = Ability_1, // swift swim
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_DAMP_ROCK,
        .moves = {MOVE_HYDROPUMP, MOVE_RAINDANCE, MOVE_DRAINPUNCH, MOVE_HYPERVOICE},
    },
    {
        .lvl = -2,
        .species = SPECIES_EMPOLEON,
        .ability = Ability_Hidden, // defiant
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYDROPUMP, MOVE_DRILLPECK, MOVE_AQUAJET, MOVE_SWAGGER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerDana[] = {
    {
        .lvl = -2,
        .species = SPECIES_HITMONCHAN,
        .ability = Ability_2, // iron fist
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MACHPUNCH, MOVE_THUNDERPUNCH, MOVE_FIREPUNCH, MOVE_ICEPUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_PILOSWINE,
        .ability = Ability_Hidden, // thich fat
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TAKEDOWN, MOVE_ICESHARD},
    },
    {
        .lvl = -2,
        .species = SPECIES_GOLISOPOD,
        .ability = Ability_Hidden, // tough claws
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FIRSTIMPRESSION, MOVE_ROCKSMASH, MOVE_RAZORSHELL},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerAriana[] = {
    {
        .lvl = -2,
        .species = SPECIES_CLAWITZER,
        .ability = Ability_1, // mega launcher
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRAGONPULSE, MOVE_DARKPULSE, MOVE_WATERPULSE},
    },
    {
        .lvl = -2,
        .species = SPECIES_NOCTOWL,
        .ability = Ability_Hidden, // TINTEDLENS
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_REFLECT, MOVE_PSYSHOCK, MOVE_ROOST},
    },
    {
        .lvl = -2,
        .species = SPECIES_SANDACONDA,
        .ability = Ability_RandomAll,
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DIG, MOVE_BRUTALSWING, MOVE_GLARE, MOVE_COIL},
    },
    {
        .lvl = -2,
        .species = SPECIES_FRAXURE,
        .ability = Ability_1, // tough claws
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BULLETPUNCH, MOVE_DRAGONDANCE, MOVE_DUALCHOP, MOVE_CRUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerLeah[] = {
    {
        .lvl = -2,
        .species = SPECIES_BELLOSSOM,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_HEAT_ROCK,
        .moves = {MOVE_TOXIC, MOVE_MOONLIGHT, MOVE_MAGICALLEAF, MOVE_GIGADRAIN},
    },
    {
        .lvl = -2,
        .species = SPECIES_VENUSAUR,
        .ability = Ability_Hidden, // chlrophyl
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLEEPPOWDER, MOVE_SLUDGE, MOVE_LEECHSEED, MOVE_PETALBLIZZARD},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperJustin[] = {
    {
        .lvl = -2,
        .species = SPECIES_CLEFAIRY,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_METRONOME, MOVE_MOONBLAST, MOVE_MAGICALLEAF, MOVE_ENCORE},
    },
    {
        .lvl = -2,
        .species = SPECIES_NIDORINO,
        .ability = Ability_Hidden, // hustle
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_POISONJAB, MOVE_TOXIC, MOVE_DOUBLEKICK, MOVE_FLATTER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerYazmin[] = {
    {
        .lvl = -2,
        .species = SPECIES_TANGROWTH,
        .ability = Ability_1, // self sufficient
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GIGADRAIN, MOVE_KNOCKOFF, MOVE_LEECHSEED, MOVE_BLOCK},
    },
    {
        .lvl = -2,
        .species = SPECIES_CLEFABLE,
        .ability = Ability_Hidden, // unaware
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_METRONOME, MOVE_MOONBLAST, MOVE_SOFTBOILED, MOVE_ENCORE},
    },
    {
        .lvl = -2,
        .species = SPECIES_LUDICOLO,
        .ability = Ability_RandomAll,
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIGHT_BALL,
        .moves = {MOVE_HYDROPUMP, MOVE_GIGADRAIN, MOVE_EXTRASENSORY, MOVE_DARKPULSE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerKindra[] = {
    {
        .lvl = -2,
        .species = SPECIES_SHIINOTIC,
        .ability = Ability_2, // effect spore
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIGHT_BALL,
        .moves = {MOVE_STRENGTHSAP, MOVE_MOONBLAST, MOVE_LEECHSEED, MOVE_SPORE},
    },
    {
        .lvl = -2,
        .species = SPECIES_LUDICOLO,
        .ability = Ability_RandomAll,
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIGHT_BALL,
        .moves = {MOVE_HYDROPUMP, MOVE_GIGADRAIN, MOVE_EXTRASENSORY, MOVE_DARKPULSE},
    },
    {
        .lvl = -2,
        .species = SPECIES_EMOLGA,
        .ability = Ability_1, // static
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIGHT_BALL,
        .moves = {MOVE_DISCHARGE, MOVE_ACROBATICS, MOVE_ENCORE, MOVE_PURSUIT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerBecky[] = {
    {
        .lvl = -2,
        .species = SPECIES_PIKACHU,
        .ability = Ability_1, // static
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIGHT_BALL,
        .moves = {MOVE_THUNDERBOLT, MOVE_NUZZLE, MOVE_LIGHTSCREEN, MOVE_NASTYPLOT},
    },
    {
        .lvl = -2,
        .species = SPECIES_STUNFISK,
        .ability = Ability_1, // static
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIGHT_BALL,
        .moves = {MOVE_THUNDERBOLT, MOVE_NUZZLE, MOVE_LIGHTSCREEN, MOVE_NASTYPLOT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerCelia[] = {
    {
        .lvl = -2,
        .species = SPECIES_SCIZOR,
        .ability = Ability_2, // technician
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BULLETPUNCH, MOVE_SWORDSDANCE, MOVE_VACUUMWAVE, MOVE_FURYCUTTER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_GentlemanBrooks[] = {
    {
        .lvl = -2,
        .species = SPECIES_MAGNETON,
        .ability = Ability_Hidden, // analytic
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DISARMINGVOICE, MOVE_THUNDERWAVE, MOVE_TRIATTACK, MOVE_MAGNETRISE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_GentlemanLamar[] = {
    {
        .lvl = -2,
        .species = SPECIES_QUILAVA,
        .ability = Ability_1, // blaze
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_LAVAPLUME, MOVE_SWIFT, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_TORRACAT,
        .ability = Ability_Hidden, // intimidate
        .nature = NATURE_RASH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FLAMETHROWER, MOVE_BITE, MOVE_ROAR, MOVE_DOUBLEKICK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TwinsEliAnne[] = {
    {
        .lvl = -2,
        .species = SPECIES_GRIMMSNARL,
        .ability = Ability_1, // pranskter
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_REFLECT, MOVE_LIGHTSCREEN, MOVE_SPIRITBREAK, MOVE_SUCKERPUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_HATTERENE,
        .ability = Ability_RandomAll,
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_LIFEDEW, MOVE_PSYCHIC, MOVE_CALMMIND, MOVE_DRAININGKISS},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CoolCoupleRayTyra[] = {
    {
        .lvl = 0,
        .species = SPECIES_NIDOQUEEN,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_ICEBEAM, MOVE_EARTHPOWER, MOVE_SLUDGEBOMB, MOVE_FLAMETHROWER},
    },
    {
        .lvl = 0,
        .species = SPECIES_NIDOKING,
        .ability = Ability_Hidden, // sheer force
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MAX},
        .evSpread = {0, 0, 0, 252, 4, 252},
        .heldItem = ITEM_LIFE_ORB,
        .moves = {MOVE_ICEBEAM, MOVE_EARTHPOWER, MOVE_SLUDGEBOMB, MOVE_FLAMETHROWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungCoupleGiaJes[] = {
    {
        .lvl = -2,
        .species = SPECIES_MILOTIC,
        .ability = Ability_Hidden, // serene grace
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MOONBLAST, MOVE_RECOVER, MOVE_SPARKLINGARIA, MOVE_ATTRACT},
    },
    {
        .lvl = -2,
        .species = SPECIES_GYARADOS,
        .ability = Ability_1, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_40},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_AQUATAIL, MOVE_CRUNCH, MOVE_ICEFANG},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TwinsKiriJan[] = {
    {
        .lvl = -2,
        .species = SPECIES_CHARIZARD,
        .ability = Ability_2, // solar power
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HEATWAVE, MOVE_AIRSLASH, MOVE_DRAGONCLAW, MOVE_CRUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_TORKOAL,
        .ability = Ability_2, // drought
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_HEAT_ROCK,
        .moves = {MOVE_HEATWAVE, MOVE_PROTECT, MOVE_FIRESPIN, MOVE_SMOG},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CrushKinRonMya[] = {
    {
        .lvl = -2,
        .species = SPECIES_HITMONCHAN,
        .ability = Ability_1, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIGHT_BALL,
        .moves = {MOVE_CLOSECOMBAT, MOVE_SUCKERPUNCH, MOVE_ICEPUNCH, MOVE_THUNDERPUNCH},
    },
    {
        .lvl = -2,
        .species = SPECIES_HITMONLEE,
        .ability = Ability_1, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_LIGHT_BALL,
        .moves = {MOVE_PYROBALL, MOVE_HIGHJUMPKICK, MOVE_SUCKERPUNCH, MOVE_ENDURE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungCoupleLeaJed[] = {
    {
        .lvl = -2,
        .species = SPECIES_BARRASKEWDA,
        .ability = Ability_1, // swift swim
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRILLRUN, MOVE_CRUNCH, MOVE_WATERFALL},
    },
    {
        .lvl = -2,
        .species = SPECIES_POLITOED,
        .ability = Ability_Hidden, // drizle
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_60},
        .heldItem = ITEM_DAMP_ROCK,
        .moves = {MOVE_LOWKICK, MOVE_BUBBLEBEAM, MOVE_HYPNOSIS, MOVE_SWAGGER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SisAndBroLiaLuc[] = {
    {
        .lvl = -2,
        .species = SPECIES_DRACOVISH,
        .ability = Ability_Hidden, // swift swim
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_FISHIOUSREND, MOVE_CRUNCH, MOVE_IRONHEAD, MOVE_HEADBUTT},
    },
    {
        .lvl = -2,
        .species = SPECIES_POLITOED,
        .ability = Ability_Hidden, // drizle
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MAX},
        .evSpread = {EV_80},
        .heldItem = ITEM_DAMP_ROCK,
        .moves = {MOVE_HYDROPUMP, MOVE_EARTHPOWER, MOVE_HYPNOSIS, MOVE_SWAGGER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SisAndBroLilIan[] = {
    {
        .lvl = -2,
        .species = SPECIES_GASTRODON,
        .ability = Ability_2, // storm drain
        .nature = NATURE_SASSY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_RECOVER, MOVE_BODYSLAM, MOVE_RAINDANCE, MOVE_EARTHPOWER},
    },
    {
        .lvl = -2,
        .species = SPECIES_STARMIE,
        .ability = Ability_2, // natural cure
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_POWERGEM, MOVE_RECOVER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcher3[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_BugCatcher4[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_BugCatcher5[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_BugCatcher6[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_BugCatcher7[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_BugCatcher8[] = {DUMMY_TRAINER_MON};

static const struct TrainerMonItemCustomMoves sParty_YoungsterBen3[] = {
    {
        .lvl = 28,
        .species = SPECIES_RATICATE,
    },
    {
        .lvl = 28,
        .species = SPECIES_EKANS,
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterBen4[] = {
    {
        .lvl = 48,
        .species = SPECIES_RATICATE,
    },
    {
        .lvl = 48,
        .species = SPECIES_ARBOK,
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterChad2[] = {
    {
        .lvl = 20,
        .species = SPECIES_EKANS,
    },
    {
        .lvl = 20,
        .species = SPECIES_SANDSHREW,
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassReli2[] = {
    {
        .lvl = 20,
        .species = SPECIES_PIDGEY,
    },
    {
        .lvl = 20,
        .species = SPECIES_NIDORAN_F,
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassReli3[] = {
    {
        .lvl = 28,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 28,
        .species = SPECIES_NIDORINA,
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterTimmy2[] = {
    {
        .lvl = 19,
        .species = SPECIES_RATICATE,
    },
    {
        .lvl = 19,
        .species = SPECIES_EKANS,
    },
    {
        .lvl = 19,
        .species = SPECIES_ZUBAT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterTimmy3[] = {
    {
        .lvl = 27,
        .species = SPECIES_RATICATE,
    },
    {
        .lvl = 27,
        .species = SPECIES_EKANS,
    },
    {
        .lvl = 27,
        .species = SPECIES_GOLBAT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterTimmy4[] = {
    {
        .lvl = 52,
        .species = SPECIES_RATICATE,
    },
    {
        .lvl = 52,
        .species = SPECIES_ARBOK,
    },
    {
        .lvl = 52,
        .species = SPECIES_GOLBAT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterChad3[] = {
    {
        .lvl = 28,
        .species = SPECIES_ARBOK,
    },
    {
        .lvl = 28,
        .species = SPECIES_SANDSHREW,
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassJanice2[] = {
    {
        .lvl = 20,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 20,
        .species = SPECIES_PIDGEOTTO,
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassJanice3[] = {
    {
        .lvl = 28,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 28,
        .species = SPECIES_PIDGEOTTO,
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterChad4[] = {
    {
        .lvl = 48,
        .species = SPECIES_ARBOK,
    },
    {
        .lvl = 48,
        .species = SPECIES_SANDSLASH,
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerFranklin2[] = {
    {
        .lvl = 25,
        .species = SPECIES_MACHOKE,
    },
    {
        .lvl = 25,
        .species = SPECIES_GRAVELER,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PkmnProfProfOak[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_PlayerBrendan[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_PlayerMay[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_PlayerRed[] = {DUMMY_TRAINER_MON};
static const struct TrainerMonItemCustomMoves sParty_PlayerLeaf[] = {DUMMY_TRAINER_MON};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt42[] = {
    {
        .lvl = 49,
        .species = SPECIES_HOUNDOUR,
    },
    {
        .lvl = 49,
        .species = SPECIES_HOUNDOUR,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PsychicJaclyn[] = {
    {
        .lvl = 48,
        .species = SPECIES_NATU,
        .moves = {MOVE_NIGHTSHADE, MOVE_CONFUSERAY, MOVE_FUTURESIGHT, MOVE_WISH},
    },
    {
        .lvl = 48,
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_PSYCHIC, MOVE_HEADBUTT, MOVE_AMNESIA, MOVE_YAWN},
    },
    {
        .lvl = 49,
        .species = SPECIES_KADABRA,
        .moves = {MOVE_PSYCHIC, MOVE_FUTURESIGHT, MOVE_RECOVER, MOVE_REFLECT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CrushGirlSharon[] = {
    {
        .lvl = -2,
        .species = SPECIES_PRIMEAPE,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CLOSECOMBAT, MOVE_STOMPINGTANTRUM, MOVE_UTURN, MOVE_ASSURANCE},
    },
    {
        .lvl = -2,
        .species = SPECIES_POLIWRATH,
        .ability = Ability_1, // water absorb
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SURGINGSTRIKES, MOVE_STOMPINGTANTRUM, MOVE_BULKUP},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TuberAmira[] = {
    {
        .lvl = 34,
        .species = SPECIES_POLIWAG,
    },
    {
        .lvl = 35,
        .species = SPECIES_POLIWHIRL,
    },
    {
        .lvl = 34,
        .species = SPECIES_POLIWAG,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PkmnBreederAlize[] = {
    {
        .lvl = 48,
        .species = SPECIES_PIKACHU,
    },
    {
        .lvl = 48,
        .species = SPECIES_CLEFAIRY,
    },
    {
        .lvl = 48,
        .species = SPECIES_MARILL,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PkmnRangerNicolas[] = {
    {
        .lvl = 51,
        .species = SPECIES_WEEPINBELL,
        .moves = {MOVE_RAZORLEAF, MOVE_ACID, MOVE_SWEETSCENT, MOVE_WRAP},
    },
    {
        .lvl = 51,
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_RAZORLEAF, MOVE_ACID, MOVE_SLEEPPOWDER, MOVE_STUNSPORE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PkmnRangerMadeline[] = {
    {
        .lvl = 51,
        .species = SPECIES_GLOOM,
        .moves = {MOVE_PETALDANCE, MOVE_ACID, MOVE_SWEETSCENT, MOVE_POISONPOWDER},
    },
    {
        .lvl = 51,
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_PETALDANCE, MOVE_MOONLIGHT, MOVE_ACID, MOVE_STUNSPORE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_AromaLadyNikki[] = {
    {
        .lvl = 37,
        .species = SPECIES_BELLSPROUT,
    },
    {
        .lvl = 37,
        .species = SPECIES_WEEPINBELL,
    },
};

static const struct TrainerMonItemCustomMoves sParty_RuinManiacStanly[] = {
    {
        .lvl = 48,
        .species = SPECIES_GRAVELER,
    },
    {
        .lvl = 48,
        .species = SPECIES_ONIX,
    },
    {
        .lvl = 48,
        .species = SPECIES_GRAVELER,
    },
};

static const struct TrainerMonItemCustomMoves sParty_LadyJacki[] = {
    {
        .lvl = 48,
        .species = SPECIES_HOPPIP,
        .heldItem = ITEM_STARDUST,
    },
    {
        .lvl = 50,
        .species = SPECIES_SKIPLOOM,
        .heldItem = ITEM_STARDUST,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PainterDaisy[] = {
    {
        .lvl = 50,
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_DYNAMICPUNCH, MOVE_DIZZYPUNCH, MOVE_FOCUSPUNCH, MOVE_MEGAPUNCH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerGoon[] = {
    {
        .lvl = 37,
        .species = SPECIES_KOFFING,
        .moves = {MOVE_HAZE, MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_TACKLE},
    },
    {
        .lvl = 37,
        .species = SPECIES_GRIMER,
        .moves = {MOVE_ACIDARMOR, MOVE_SCREECH, MOVE_MINIMIZE, MOVE_SLUDGE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerGoon2[] = {
    {
        .lvl = 38,
        .species = SPECIES_KOFFING,
        .moves = {MOVE_HAZE, MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_TACKLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerGoon3[] = {
    {
        .lvl = 38,
        .species = SPECIES_GRIMER,
    },
};

static const struct TrainerMonItemCustomMoves sParty_Biker2[] = {DUMMY_TRAINER_MON};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherAnthony[] = {
    {
        .lvl = -2,
        .species = SPECIES_PUMPKABOO_M,
        .ability = Ability_1, // intimidate
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .moves = {MOVE_ABSORB, MOVE_ASTONISH, MOVE_BULLETSEED, MOVE_DISABLE},
    },
    {
        .lvl = -2,
        .species = SPECIES_JOLTIK,
        .ability = Ability_Hidden, // compound eyes
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .moves = {MOVE_ELECTROWEB, MOVE_FURYCUTTER, MOVE_ABSORB, MOVE_BUGBITE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherCharlie[] = {
    {
        .lvl = -2,
        .species = SPECIES_PUMPKABOO_M,
        .ability = Ability_1, // intimidate
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .moves = {MOVE_ABSORB, MOVE_ASTONISH, MOVE_BULLETSEED, MOVE_DISABLE},
    },
    {
        .lvl = -2,
        .species = SPECIES_PIKACHU,
        .ability = Ability_1, // static
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .moves = {MOVE_DOUBLEKICK, MOVE_THUNDERSHOCK, MOVE_CHARM, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_SKORUPI,
        .ability = Ability_Hidden, // merciless
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .moves = {MOVE_HONECLAWS, MOVE_FELLSTINGER, MOVE_POISONSTING, MOVE_PURSUIT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TwinsEliAnne2[] = {
    {
        .lvl = 28,
        .species = SPECIES_CLEFAIRY,
    },
    {
        .lvl = 28,
        .species = SPECIES_JIGGLYPUFF,
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterJohnson[] = {
    {
        .lvl = -2,
        .species = SPECIES_ARBOK,
        .ability = Ability_Hidden, // fatal precision
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GUNKSHOT, MOVE_CRUNCH, MOVE_ICEFANG, MOVE_BULLDOZE},
    },
    {
        .lvl = -2,
        .species = SPECIES_DODRIO,
        .ability = Ability_Hidden, // gale wings
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRILLPECK, MOVE_ACUPRESSURE, MOVE_PURSUIT, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_GASTRODON,
        .ability = Ability_2, // storm drain
        .nature = NATURE_SASSY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_RECOVER, MOVE_BODYSLAM, MOVE_RAINDANCE, MOVE_EARTHPOWER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerRicardo[] = {
    {
        .lvl = -2,
        .species = SPECIES_TOXAPEX,
        .ability = Ability_Hidden, // regenerator
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_QUICK_CLAW,
        .moves = {MOVE_VENOMDRENCH, MOVE_RECOVER, MOVE_TOXICSPIKES, MOVE_BANEFULBUNKER},
    },
    {
        .lvl = -2,
        .species = SPECIES_CROBAT,
        .ability = Ability_Hidden, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_POISON_BARB,
        .moves = {MOVE_CROSSPOISON, MOVE_LEECHLIFE, MOVE_WINGATTACK, MOVE_TOXIC},
    },
    {
        .lvl = -2,
        .species = SPECIES_GENGAR,
        .ability = Ability_1, // levitate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_SPELL_TAG,
        .moves = {MOVE_WILLOWISP, MOVE_HEX, MOVE_CONFUSERAY, MOVE_DISABLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerJaren[] = {
    {
        .lvl = -2,
        .species = SPECIES_CROBAT,
        .ability = Ability_Hidden, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_POISON_BARB,
        .moves = {MOVE_CROSSPOISON, MOVE_LEECHLIFE, MOVE_WINGATTACK, MOVE_TOXIC},
    },
    {
        .lvl = -2,
        .species = SPECIES_GENGAR,
        .ability = Ability_1, // levitate
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_20},
        .heldItem = ITEM_SPELL_TAG,
        .moves = {MOVE_WILLOWISP, MOVE_HEX, MOVE_CONFUSERAY, MOVE_DISABLE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt43[] = {
    {
        .lvl = 37,
        .species = SPECIES_CUBONE,
    },
    {
        .lvl = 37,
        .species = SPECIES_MAROWAK,
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt44[] = {
    {
        .lvl = 35,
        .species = SPECIES_RATTATA,
    },
    {
        .lvl = 35,
        .species = SPECIES_RATICATE,
    },
    {
        .lvl = 35,
        .species = SPECIES_SANDSHREW,
    },
    {
        .lvl = 35,
        .species = SPECIES_SANDSLASH,
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt45[] = {
    {
        .lvl = 38,
        .species = SPECIES_ZUBAT,
    },
    {
        .lvl = 38,
        .species = SPECIES_ZUBAT,
    },
    {
        .lvl = 38,
        .species = SPECIES_GOLBAT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt46[] = {
    {
        .lvl = 48,
        .species = SPECIES_MUK,
    },
    {
        .lvl = 48,
        .species = SPECIES_GOLBAT,
    },
    {
        .lvl = 48,
        .species = SPECIES_RATICATE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt47[] = {
    {
        .lvl = 48,
        .species = SPECIES_MACHOP,
    },
    {
        .lvl = 48,
        .species = SPECIES_MACHOP,
    },
    {
        .lvl = 48,
        .species = SPECIES_MACHOKE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt48[] = {
    {
        .lvl = 49,
        .species = SPECIES_HYPNO,
    },
    {
        .lvl = 49,
        .species = SPECIES_HYPNO,
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketAdmin[] = {
    {
        .lvl = 52,
        .species = SPECIES_MUK,
        .moves = {MOVE_SLUDGEBOMB, MOVE_SCREECH, MOVE_MINIMIZE, MOVE_ROCKTOMB},
    },
    {
        .lvl = 53,
        .species = SPECIES_ARBOK,
        .moves = {MOVE_SLUDGEBOMB, MOVE_BITE, MOVE_EARTHQUAKE, MOVE_IRONTAIL},
    },
    {
        .lvl = 54,
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_SLUDGEBOMB, MOVE_GIGADRAIN, MOVE_SLEEPPOWDER, MOVE_STUNSPORE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketAdmin2[] = {
    {
        .lvl = 53,
        .species = SPECIES_GOLBAT,
        .moves = {MOVE_CONFUSERAY, MOVE_SLUDGEBOMB, MOVE_AIRCUTTER, MOVE_SHADOWBALL},
    },
    {
        .lvl = 54,
        .species = SPECIES_WEEZING,
        .moves = {MOVE_SLUDGEBOMB, MOVE_THUNDERBOLT, MOVE_EXPLOSION, MOVE_SHADOWBALL},
    },
    {
        .lvl = 55,
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FLAMETHROWER, MOVE_CRUNCH, MOVE_IRONTAIL, MOVE_SHADOWBALL},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ScientistGideon[] = {
    {
        .lvl = 46,
        .species = SPECIES_VOLTORB,
        .moves = {MOVE_SWIFT, MOVE_SCREECH, MOVE_SPARK, MOVE_SONICBOOM},
    },
    {
        .lvl = 46,
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_SPARK, MOVE_SONICBOOM, MOVE_SCREECH, MOVE_CHARGE},
    },
    {
        .lvl = 46,
        .species = SPECIES_MAGNEMITE,
        .moves = {MOVE_SCREECH, MOVE_SWIFT, MOVE_SPARK, MOVE_THUNDERWAVE},
    },
    {
        .lvl = 46,
        .species = SPECIES_MAGNETON,
        .moves = {MOVE_TRIATTACK, MOVE_SPARK, MOVE_THUNDERWAVE, MOVE_SONICBOOM},
    },
    {
        .lvl = 46,
        .species = SPECIES_PORYGON,
        .moves = {MOVE_TRIATTACK, MOVE_CONVERSION, MOVE_RECOVER, MOVE_PSYBEAM},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerFemaleAmara[] = {
    {
        .lvl = -2,
        .species = SPECIES_TENTACRUEL,
        .ability = Ability_1, // clear body
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGEWAVE, MOVE_HEX, MOVE_SURF, MOVE_ACIDARMOR},
    },
    {
        .lvl = -2,
        .species = SPECIES_OCTILLERY,
        .ability = Ability_Hidden, // moody
        .nature = NATURE_TIMID,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SNIPESHOT, MOVE_ICEBEAM, MOVE_SIGNALBEAM, MOVE_BULLETSEED},
    },
    {
        .lvl = -2,
        .species = SPECIES_KINGDRA,
        .ability = Ability_Hidden, // sniper
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRAGONDANCE, MOVE_WATERFALL, MOVE_DRAGONPULSE, MOVE_YAWN},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerFemaleMaria[] = {
    {
        .lvl = -2,
        .species = SPECIES_KINGDRA,
        .ability = Ability_Hidden, // sniper
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRAGONDANCE, MOVE_SNIPESHOT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerFemaleAbigail[] = {
    {
        .lvl = -2,
        .species = SPECIES_PELIPPER,
        .ability = Ability_Hidden, // drizzle
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HURRICANE, MOVE_HYDROPUMP, MOVE_ROOST},
    },
    {
        .lvl = -2,
        .species = SPECIES_GOLDUCK,
        .ability = Ability_Hidden, // swift swim
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EXTRASENSORY, MOVE_SURF, MOVE_NASTYPLOT, MOVE_AQUAJET},
    },
    {
        .lvl = -2,
        .species = SPECIES_SWAMPERT,
        .ability = Ability_Hidden, // swift swim
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCKSLIDE, MOVE_HAMMERARM},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleFinn[] = {
    {
        .lvl = -2,
        .species = SPECIES_STARMIE,
        .ability = Ability_2, // natural cure
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_SURF, MOVE_POWERGEM, MOVE_RECOVER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleGarrett[] = {
    {
        .lvl = -2,
        .species = SPECIES_JELLICENT,
        .ability = Ability_2, // cursed body
        .nature = NATURE_BOLD,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWBALL, MOVE_RECOVER, MOVE_ACIDARMOR, MOVE_WHIRLPOOL},
    },
    {
        .lvl = -2,
        .species = SPECIES_CLOYSTER,
        .ability = Ability_2, // skill link
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TWINEEDLE, MOVE_SHELLSMASH, MOVE_ICICLESPEAR, MOVE_PROTECT},
    },
    {
        .lvl = -2,
        .species = SPECIES_QUAGSIRE,
        .ability = Ability_2, // water absorb
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_TOXIC, MOVE_YAWN, MOVE_HAZE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_FishermanTommy[] = {
    {
        .lvl = -10,
        .species = SPECIES_MAGIKARP,
        .ability = Ability_RandomAll,
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SPLASH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CrushGirlTanya[] = {
    {
        .lvl = -2,
        .species = SPECIES_HITMONCHAN,
        .ability = Ability_1, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CLOSECOMBAT, MOVE_SUCKERPUNCH, MOVE_DRAINPUNCH, MOVE_AGILITY},
    },
    {
        .lvl = -2,
        .species = SPECIES_HITMONLEE,
        .ability = Ability_1, // adaptability
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PYROBALL, MOVE_HIGHJUMPKICK, MOVE_SUCKERPUNCH, MOVE_FAKEOUT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BlackBeltShea[] = {
    {
        .lvl = -2,
        .species = SPECIES_BLAZIKEN,
        .ability = Ability_Hidden, // speed boost
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HIGHJUMPKICK, MOVE_FLAREBLITZ, MOVE_BULKUP, MOVE_DETECT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BlackBeltHugh[] = {
    {
        .lvl = -2,
        .species = SPECIES_INFERNAPE,
        .ability = Ability_Hidden, // swift swim
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PYROBALL, MOVE_ACROBATICS, MOVE_SLACKOFF, MOVE_CLOSECOMBAT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperBryce[] = {
    {
        .lvl = -2,
        .species = SPECIES_NIDOKING,
        .ability = Ability_Hidden, // earth power
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHPOWER, MOVE_MEGAHORN},
    },
    {
        .lvl = -2,
        .species = SPECIES_TAUROS,
        .ability = Ability_1, // intimidate
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DOUBLEEDGE, MOVE_ZENHEADBUTT, MOVE_ASSURANCE, MOVE_WORKUP},
    },
    {
        .lvl = -2,
        .species = SPECIES_INDEEDEE_FEMALE,
        .ability = Ability_Hidden, // psychic surge
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CALMMIND, MOVE_PSYCHIC, MOVE_STOREDPOWER, MOVE_DISARMINGVOICE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerClaire[] = {
    {
        .lvl = 35,
        .species = SPECIES_MEOWTH,
    },
    {
        .lvl = 35,
        .species = SPECIES_MEOWTH,
    },
    {
        .lvl = 35,
        .species = SPECIES_PIKACHU,
    },
    {
        .lvl = 35,
        .species = SPECIES_CLEFAIRY,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CrushKinMikKia[] = {
    {
        .lvl = -2,
        .species = SPECIES_HAWLUCHA,
        .ability = Ability_Hidden, // mold breaker
        .nature = NATURE_MODEST,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_TAUNT, MOVE_HIGHJUMPKICK, MOVE_SWORDSDANCE, MOVE_FLYINGPRESS},
    },
    {
        .lvl = -2,
        .species = SPECIES_PANGORO,
        .ability = Ability_Hidden, // scrappy
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WICKEDBLOW, MOVE_BULLETPUNCH, MOVE_PARTINGSHOT, MOVE_TAUNT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_AromaLadyViolet[] = {
    {
        .lvl = 36,
        .species = SPECIES_BULBASAUR,
    },
    {
        .lvl = 36,
        .species = SPECIES_IVYSAUR,
    },
    {
        .lvl = 36,
        .species = SPECIES_IVYSAUR,
    },
};

static const struct TrainerMonItemCustomMoves sParty_TuberAlexis[] = {
    {
        .lvl = 34,
        .species = SPECIES_STARYU,
    },
    {
        .lvl = 34,
        .species = SPECIES_STARYU,
    },
    {
        .lvl = 34,
        .species = SPECIES_KRABBY,
    },
    {
        .lvl = 34,
        .species = SPECIES_KRABBY,
    },
};

static const struct TrainerMonItemCustomMoves sParty_TwinsJoyMeg[] = {
    {
        .lvl = 37,
        .species = SPECIES_CLEFAIRY,
    },
    {
        .lvl = 37,
        .species = SPECIES_CLEFAIRY,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerFemaleTisha[] = {
    {
        .lvl = 38,
        .species = SPECIES_KINGLER,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PainterCelina[] = {
    {
        .lvl = 50,
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_FLY, MOVE_DIG, MOVE_DIVE, MOVE_BOUNCE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PainterRayna[] = {
    {
        .lvl = 50,
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_CROSSCHOP, MOVE_MEGAHORN, MOVE_DOUBLEEDGE, MOVE_SELFDESTRUCT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_LadyGillian[] = {
    {
        .lvl = 47,
        .species = SPECIES_MAREEP,
        .heldItem = ITEM_STARDUST,
    },
    {
        .lvl = 48,
        .species = SPECIES_MAREEP,
        .heldItem = ITEM_STARDUST,
    },
    {
        .lvl = 49,
        .species = SPECIES_FLAAFFY,
        .heldItem = ITEM_NUGGET,
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterDestin[] = {
    {
        .lvl = 48,
        .species = SPECIES_RATICATE,
    },
    {
        .lvl = 48,
        .species = SPECIES_PIDGEOTTO,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleToby[] = {
    {
        .lvl = 48,
        .species = SPECIES_POLIWHIRL,
    },
    {
        .lvl = 48,
        .species = SPECIES_TENTACOOL,
    },
    {
        .lvl = 48,
        .species = SPECIES_TENTACRUEL,
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt49[] = {
    {
        .lvl = 48,
        .species = SPECIES_RATTATA,
    },
    {
        .lvl = 48,
        .species = SPECIES_GRIMER,
    },
    {
        .lvl = 48,
        .species = SPECIES_MUK,
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt50[] = {
    {
        .lvl = 49,
        .species = SPECIES_KOFFING,
        .moves = {MOVE_MEMENTO, MOVE_HAZE, MOVE_SMOKESCREEN, MOVE_SLUDGE},
    },
    {
        .lvl = 49,
        .species = SPECIES_WEEZING,
        .moves = {MOVE_HAZE, MOVE_SMOKESCREEN, MOVE_SLUDGE, MOVE_SELFDESTRUCT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_TeamRocketGrunt51[] = {
    {
        .lvl = 48,
        .species = SPECIES_EKANS,
    },
    {
        .lvl = 48,
        .species = SPECIES_GLOOM,
    },
    {
        .lvl = 48,
        .species = SPECIES_GLOOM,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperMilo[] = {
    {
        .lvl = 47,
        .species = SPECIES_PIDGEY,
    },
    {
        .lvl = 49,
        .species = SPECIES_PIDGEOTTO,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperChaz[] = {
    {
        .lvl = 47,
        .species = SPECIES_SPEAROW,
    },
    {
        .lvl = 49,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperHarold[] = {
    {
        .lvl = -2,
        .species = SPECIES_FURFROU_HEART,
        .ability = Ability_1, // fur coat
        .nature = NATURE_IMPISH,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_COTTONGUARD, MOVE_SUCKERPUNCH, MOVE_CHARM, MOVE_SANDATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_STARAPTOR,
        .ability = Ability_1, // imtimidate
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BRAVEBIRD, MOVE_DOUBLEEDGE, MOVE_CLOSECOMBAT, MOVE_AGILITY},
    },
};

static const struct TrainerMonItemCustomMoves sParty_FishermanTylor[] = {
    {
        .lvl = 49,
        .species = SPECIES_QWILFISH,
    },
    {
        .lvl = 49,
        .species = SPECIES_QWILFISH,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleMymo[] = {
    {
        .lvl = 49,
        .species = SPECIES_KINGLER,
    },
    {
        .lvl = 49,
        .species = SPECIES_WARTORTLE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerFemaleNicole[] = {
    {
        .lvl = 50,
        .species = SPECIES_MARILL,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SisAndBroAvaGeb[] = {
    {
        .lvl = 50,
        .species = SPECIES_POLIWHIRL,
    },
    {
        .lvl = 50,
        .species = SPECIES_STARMIE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_AromaLadyRose[] = {
    {
        .lvl = 49,
        .species = SPECIES_SUNKERN,
    },
    {
        .lvl = 49,
        .species = SPECIES_SUNFLORA,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleSamir[] = {
    {
        .lvl = 50,
        .species = SPECIES_GYARADOS,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerFemaleDenise[] = {
    {
        .lvl = 49,
        .species = SPECIES_CHINCHOU,
    },
    {
        .lvl = 49,
        .species = SPECIES_LANTURN,
    },
};

static const struct TrainerMonItemCustomMoves sParty_TwinsMiuMia[] = {
    {
        .lvl = 50,
        .species = SPECIES_PIKACHU,
    },
    {
        .lvl = 50,
        .species = SPECIES_PIKACHU,
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerEarl[] = {
    {
        .lvl = 49,
        .species = SPECIES_ONIX,
    },
    {
        .lvl = 49,
        .species = SPECIES_MACHOKE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_RuinManiacFoster[] = {
    {
        .lvl = 50,
        .species = SPECIES_GOLEM,
    },
};

static const struct TrainerMonItemCustomMoves sParty_RuinManiacLarry[] = {
    {
        .lvl = 49,
        .species = SPECIES_MACHOKE,
    },
    {
        .lvl = 49,
        .species = SPECIES_MACHOKE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerDaryl[] = {
    {
        .lvl = 50,
        .species = SPECIES_SUDOWOODO,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PokemaniacHector[] = {
    {
        .lvl = 49,
        .species = SPECIES_RHYHORN,
    },
    {
        .lvl = 49,
        .species = SPECIES_KANGASKHAN,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PsychicDario[] = {
    {
        .lvl = 52,
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_CRUNCH, MOVE_PSYBEAM, MOVE_ODORSLEUTH, MOVE_AGILITY},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PsychicRodette[] = {
    {
        .lvl = 48,
        .species = SPECIES_NATU,
        .moves = {MOVE_NIGHTSHADE, MOVE_CONFUSERAY, MOVE_WISH, MOVE_FUTURESIGHT},
    },
    {
        .lvl = 48,
        .species = SPECIES_DROWZEE,
        .moves = {MOVE_PSYCHIC, MOVE_DISABLE, MOVE_PSYCHUP, MOVE_FUTURESIGHT},
    },
    {
        .lvl = 50,
        .species = SPECIES_HYPNO,
        .moves = {MOVE_PSYCHIC, MOVE_HYPNOSIS, MOVE_PSYCHUP, MOVE_FUTURESIGHT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_AromaLadyMiah[] = {
    {
        .lvl = 50,
        .species = SPECIES_BELLOSSOM,
    },
    {
        .lvl = 50,
        .species = SPECIES_BELLOSSOM,
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungCoupleEveJon[] = {
    {
        .lvl = 50,
        .species = SPECIES_GOLDUCK,
    },
    {
        .lvl = 50,
        .species = SPECIES_PSYDUCK,
    },
};

static const struct TrainerMonItemCustomMoves sParty_JugglerMason[] = {
    {
        .lvl = 47,
        .species = SPECIES_VOLTORB,
        .moves = {MOVE_SWIFT, MOVE_LIGHTSCREEN, MOVE_SPARK, MOVE_SONICBOOM},
    },
    {
        .lvl = 47,
        .species = SPECIES_PINECO,
        .moves = {MOVE_SPIKES, MOVE_BIDE, MOVE_RAPIDSPIN, MOVE_TAKEDOWN},
    },
    {
        .lvl = 47,
        .species = SPECIES_VOLTORB,
        .moves = {MOVE_SWIFT, MOVE_LIGHTSCREEN, MOVE_SPARK, MOVE_SONICBOOM},
    },
    {
        .lvl = 47,
        .species = SPECIES_PINECO,
        .moves = {MOVE_SPIKES, MOVE_BIDE, MOVE_RAPIDSPIN, MOVE_EXPLOSION},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CrushGirlCyndy[] = {
    {
        .lvl = 48,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 48,
        .species = SPECIES_HITMONTOP,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 48,
        .species = SPECIES_MACHOKE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CrushGirlJocelyn[] = {
    {
        .lvl = 38,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 38,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_TamerEvan[] = {
    {
        .lvl = 48,
        .species = SPECIES_SANDSLASH,
    },
    {
        .lvl = 48,
        .species = SPECIES_LICKITUNG,
    },
    {
        .lvl = 49,
        .species = SPECIES_URSARING,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PokemaniacMark2[] = {
    {
        .lvl = 33,
        .species = SPECIES_RHYHORN,
    },
    {
        .lvl = 33,
        .species = SPECIES_LICKITUNG,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PkmnRangerLogan[] = {
    {
        .lvl = 37,
        .species = SPECIES_EXEGGCUTE,
        .moves = {MOVE_SLEEPPOWDER, MOVE_POISONPOWDER, MOVE_STUNSPORE, MOVE_CONFUSION},
    },
    {
        .lvl = 40,
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_EGGBOMB, MOVE_STOMP, MOVE_CONFUSION, MOVE_HYPNOSIS},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PkmnRangerJackson[] = {
    {
        .lvl = 49,
        .species = SPECIES_TANGELA,
        .moves = {MOVE_SLAM, MOVE_MEGADRAIN, MOVE_BIND, MOVE_INGRAIN},
    },
    {
        .lvl = 49,
        .species = SPECIES_EXEGGCUTE,
        .moves = {MOVE_CONFUSION, MOVE_POISONPOWDER, MOVE_BARRAGE, MOVE_REFLECT},
    },
    {
        .lvl = 49,
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_CONFUSION, MOVE_EGGBOMB, MOVE_SLEEPPOWDER, MOVE_STOMP},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PkmnRangerBeth[] = {
    {
        .lvl = 38,
        .species = SPECIES_BELLSPROUT,
    },
    {
        .lvl = 38,
        .species = SPECIES_GLOOM,
    },
    {
        .lvl = 38,
        .species = SPECIES_GLOOM,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PkmnRangerKatelyn[] = {
    {
        .lvl = 52,
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_EGGBOMB, MOVE_DEFENSECURL, MOVE_MINIMIZE, MOVE_SOFTBOILED},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerLeroy[] = {
    {
        .lvl = 47,
        .species = SPECIES_RHYDON,
        .moves = {MOVE_TAKEDOWN, MOVE_HORNDRILL, MOVE_ROCKBLAST, MOVE_SCARYFACE},
    },
    {
        .lvl = 48,
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_PSYCHIC, MOVE_HEADBUTT, MOVE_AMNESIA, MOVE_DISABLE},
    },
    {
        .lvl = 47,
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_DIZZYPUNCH, MOVE_BITE, MOVE_ENDURE, MOVE_REVERSAL},
    },
    {
        .lvl = 48,
        .species = SPECIES_MACHOKE,
        .moves = {MOVE_CROSSCHOP, MOVE_VITALTHROW, MOVE_REVENGE, MOVE_SEISMICTOSS},
    },
    {
        .lvl = 50,
        .species = SPECIES_URSARING,
        .moves = {MOVE_SLASH, MOVE_FEINTATTACK, MOVE_SNORE, MOVE_REST},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerMichelle[] = {
    {
        .lvl = 47,
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_SLASH, MOVE_SCREECH, MOVE_FEINTATTACK, MOVE_BITE},
    },
    {
        .lvl = 47,
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_ICEBEAM, MOVE_TAKEDOWN, MOVE_ICYWIND, MOVE_GROWL},
    },
    {
        .lvl = 48,
        .species = SPECIES_NINETALES,
        .moves = {MOVE_FLAMETHROWER, MOVE_CONFUSERAY, MOVE_WILLOWISP, MOVE_GRUDGE},
    },
    {
        .lvl = 48,
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_BOUNCE, MOVE_AGILITY, MOVE_FIRESPIN, MOVE_TAKEDOWN},
    },
    {
        .lvl = 50,
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_CRUNCH, MOVE_PSYBEAM, MOVE_STOMP, MOVE_ODORSLEUTH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CoolCoupleLexNya[] = {
    {
        .lvl = 52,
        .species = SPECIES_MILTANK,
        .moves = {MOVE_BODYSLAM, MOVE_MILKDRINK, MOVE_GROWL, MOVE_DEFENSECURL},
    },
    {
        .lvl = 52,
        .species = SPECIES_TAUROS,
        .moves = {MOVE_THRASH, MOVE_HORNATTACK, MOVE_PURSUIT, MOVE_SWAGGER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RuinManiacBrandon[] = {
    {
        .lvl = 50,
        .species = SPECIES_ONIX,
    },
};

static const struct TrainerMonItemCustomMoves sParty_RuinManiacBenjamin[] = {
    {
        .lvl = 48,
        .species = SPECIES_GEODUDE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCKBLAST, MOVE_ROLLOUT, MOVE_SELFDESTRUCT},
    },
    {
        .lvl = 48,
        .species = SPECIES_GRAVELER,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCKBLAST, MOVE_ROCKTHROW, MOVE_SELFDESTRUCT},
    },
    {
        .lvl = 48,
        .species = SPECIES_GRAVELER,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCKBLAST, MOVE_ROCKTHROW, MOVE_SELFDESTRUCT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PainterEdna[] = {
    {
        .lvl = 50,
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_FAKEOUT, MOVE_EXTREMESPEED, MOVE_PROTECT, MOVE_QUICKATTACK},
    },
};

static const struct TrainerMonItemCustomMoves sParty_GentlemanClifford[] = {
    {
        .lvl = 49,
        .species = SPECIES_MAROWAK,
    },
    {
        .lvl = 49,
        .species = SPECIES_GOLDUCK,
    },
};

static const struct TrainerMonItemCustomMoves sParty_LadySelphy[] = {
    {
        .lvl = 49,
        .species = SPECIES_PERSIAN,
        .heldItem = ITEM_NUGGET,
        .moves = {MOVE_PAYDAY, MOVE_BITE, MOVE_TAUNT, MOVE_TORMENT},
    },
    {
        .lvl = 49,
        .species = SPECIES_PERSIAN,
        .heldItem = ITEM_NUGGET,
        .moves = {MOVE_PAYDAY, MOVE_SCRATCH, MOVE_TORMENT, MOVE_TAUNT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_RuinManiacLawson[] = {
    {
        .lvl = 47,
        .species = SPECIES_ONIX,
    },
    {
        .lvl = 48,
        .species = SPECIES_GRAVELER,
    },
    {
        .lvl = 49,
        .species = SPECIES_MAROWAK,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PsychicLaura[] = {
    {
        .lvl = 48,
        .species = SPECIES_NATU,
    },
    {
        .lvl = 48,
        .species = SPECIES_NATU,
    },
    {
        .lvl = 49,
        .species = SPECIES_XATU,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PkmnBreederBethany[] = {
    {
        .lvl = 50,
        .species = SPECIES_CHANSEY,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PkmnBreederAllison[] = {
    {
        .lvl = 48,
        .species = SPECIES_CLEFAIRY,
    },
    {
        .lvl = 48,
        .species = SPECIES_CLEFAIRY,
    },
    {
        .lvl = 48,
        .species = SPECIES_CLEFABLE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherGarret[] = {
    {
        .lvl = 49,
        .species = SPECIES_HERACROSS,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherJonah[] = {
    {
        .lvl = 45,
        .species = SPECIES_YANMA,
    },
    {
        .lvl = 45,
        .species = SPECIES_BEEDRILL,
    },
    {
        .lvl = 46,
        .species = SPECIES_YANMA,
    },
    {
        .lvl = 47,
        .species = SPECIES_BEEDRILL,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherVance[] = {
    {
        .lvl = 48,
        .species = SPECIES_VENONAT,
    },
    {
        .lvl = 48,
        .species = SPECIES_VENOMOTH,
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterNash[] = {
    {
        .lvl = 47,
        .species = SPECIES_WEEPINBELL,
    },
    {
        .lvl = 47,
        .species = SPECIES_WEEPINBELL,
    },
    {
        .lvl = 49,
        .species = SPECIES_VICTREEBEL,
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterCordell[] = {
    {
        .lvl = 48,
        .species = SPECIES_FARFETCHD,
    },
    {
        .lvl = 48,
        .species = SPECIES_FARFETCHD,
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassDalia[] = {
    {
        .lvl = 46,
        .species = SPECIES_HOPPIP,
    },
    {
        .lvl = 47,
        .species = SPECIES_HOPPIP,
    },
    {
        .lvl = 47,
        .species = SPECIES_SKIPLOOM,
    },
    {
        .lvl = 48,
        .species = SPECIES_SKIPLOOM,
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassJoana[] = {
    {
        .lvl = 49,
        .species = SPECIES_SNUBBULL,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperRiley[] = {
    {
        .lvl = 49,
        .species = SPECIES_PINSIR,
    },
    {
        .lvl = 50,
        .species = SPECIES_HERACROSS,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerMarcy[] = {
    {
        .lvl = 48,
        .species = SPECIES_PARAS,
    },
    {
        .lvl = 48,
        .species = SPECIES_PARAS,
    },
    {
        .lvl = 49,
        .species = SPECIES_PARASECT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_RuinManiacLayton[] = {
    {
        .lvl = 48,
        .species = SPECIES_SANDSLASH,
    },
    {
        .lvl = 48,
        .species = SPECIES_ONIX,
    },
    {
        .lvl = 48,
        .species = SPECIES_SANDSLASH,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerKelsey2[] = {
    {
        .lvl = 21,
        .species = SPECIES_NIDORAN_M,
    },
    {
        .lvl = 21,
        .species = SPECIES_NIDORAN_F,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerKelsey3[] = {
    {
        .lvl = 29,
        .species = SPECIES_NIDORINO,
    },
    {
        .lvl = 29,
        .species = SPECIES_NIDORINA,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerKelsey4[] = {
    {
        .lvl = 49,
        .species = SPECIES_NIDORINO,
    },
    {
        .lvl = 49,
        .species = SPECIES_NIDORINA,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperRicky2[] = {
    {
        .lvl = 22,
        .species = SPECIES_SQUIRTLE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperRicky3[] = {
    {
        .lvl = 30,
        .species = SPECIES_WARTORTLE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperRicky4[] = {
    {
        .lvl = 55,
        .species = SPECIES_WARTORTLE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperJeff2[] = {
    {
        .lvl = 21,
        .species = SPECIES_SPEAROW,
    },
    {
        .lvl = 21,
        .species = SPECIES_RATICATE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperJeff3[] = {
    {
        .lvl = 29,
        .species = SPECIES_FEAROW,
    },
    {
        .lvl = 29,
        .species = SPECIES_RATICATE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperJeff4[] = {
    {
        .lvl = 54,
        .species = SPECIES_FEAROW,
    },
    {
        .lvl = 54,
        .species = SPECIES_RATICATE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerIsabelle2[] = {
    {
        .lvl = 21,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 21,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 18,
        .species = SPECIES_PIDGEY,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerIsabelle3[] = {
    {
        .lvl = 29,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 29,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 26,
        .species = SPECIES_PIDGEOTTO,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerIsabelle4[] = {
    {
        .lvl = 47,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 47,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 50,
        .species = SPECIES_PIDGEOT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterYasu2[] = {
    {
        .lvl = 22,
        .species = SPECIES_RATTATA,
    },
    {
        .lvl = 22,
        .species = SPECIES_RATICATE,
    },
    {
        .lvl = 22,
        .species = SPECIES_RATICATE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterYasu3[] = {
    {
        .lvl = 47,
        .species = SPECIES_RATICATE,
    },
    {
        .lvl = 47,
        .species = SPECIES_RATICATE,
    },
    {
        .lvl = 47,
        .species = SPECIES_RATICATE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_EngineerBernie2[] = {
    {
        .lvl = 28,
        .species = SPECIES_MAGNETON,
    },
    {
        .lvl = 28,
        .species = SPECIES_MAGNETON,
    },
    {
        .lvl = 28,
        .species = SPECIES_MAGNETON,
    },
};

static const struct TrainerMonItemCustomMoves sParty_GamerDarian2[] = {
    {
        .lvl = 29,
        .species = SPECIES_GROWLITHE,
    },
    {
        .lvl = 29,
        .species = SPECIES_VULPIX,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperChris2[] = {
    {
        .lvl = 24,
        .species = SPECIES_GROWLITHE,
    },
    {
        .lvl = 24,
        .species = SPECIES_CHARMANDER,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperChris3[] = {
    {
        .lvl = 29,
        .species = SPECIES_GROWLITHE,
    },
    {
        .lvl = 29,
        .species = SPECIES_CHARMELEON,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CamperChris4[] = {
    {
        .lvl = 54,
        .species = SPECIES_ARCANINE,
    },
    {
        .lvl = 54,
        .species = SPECIES_CHARMELEON,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerAlicia2[] = {
    {
        .lvl = 25,
        .species = SPECIES_MEOWTH,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerAlicia3[] = {
    {
        .lvl = 30,
        .species = SPECIES_PERSIAN,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerAlicia4[] = {
    {
        .lvl = 55,
        .species = SPECIES_PERSIAN,
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerJeremy2[] = {
    {
        .lvl = 30,
        .species = SPECIES_MACHOKE,
    },
    {
        .lvl = 28,
        .species = SPECIES_ONIX,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PokemaniacMark3[] = {
    {
        .lvl = 54,
        .species = SPECIES_RHYDON,
    },
    {
        .lvl = 54,
        .species = SPECIES_LICKITUNG,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PokemaniacHerman2[] = {
    {
        .lvl = 29,
        .species = SPECIES_MAROWAK,
    },
    {
        .lvl = 29,
        .species = SPECIES_SLOWBRO,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PokemaniacHerman3[] = {
    {
        .lvl = 54,
        .species = SPECIES_MAROWAK,
    },
    {
        .lvl = 54,
        .species = SPECIES_SLOWBRO,
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerTrent2[] = {
    {
        .lvl = 31,
        .species = SPECIES_ONIX,
    },
    {
        .lvl = 31,
        .species = SPECIES_GRAVELER,
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassMegan2[] = {
    {
        .lvl = 22,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 22,
        .species = SPECIES_RATICATE,
    },
    {
        .lvl = 23,
        .species = SPECIES_NIDORAN_M,
    },
    {
        .lvl = 21,
        .species = SPECIES_MEOWTH,
    },
    {
        .lvl = 22,
        .species = SPECIES_PIKACHU,
    },
};

static const struct TrainerMonItemCustomMoves sParty_LassMegan3[] = {
    {
        .lvl = 46,
        .species = SPECIES_PIDGEOT,
    },
    {
        .lvl = 47,
        .species = SPECIES_RATICATE,
    },
    {
        .lvl = 47,
        .species = SPECIES_NIDORINO,
    },
    {
        .lvl = 47,
        .species = SPECIES_PERSIAN,
    },
    {
        .lvl = 48,
        .species = SPECIES_RAICHU,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SuperNerdGlenn2[] = {
    {
        .lvl = 28,
        .species = SPECIES_MUK,
    },
    {
        .lvl = 28,
        .species = SPECIES_MUK,
    },
    {
        .lvl = 28,
        .species = SPECIES_MUK,
    },
};

static const struct TrainerMonItemCustomMoves sParty_GamerRich2[] = {
    {
        .lvl = 30,
        .species = SPECIES_GROWLITHE,
    },
    {
        .lvl = 30,
        .species = SPECIES_VULPIX,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerJaren2[] = {
    {
        .lvl = 28,
        .species = SPECIES_MUK,
    },
    {
        .lvl = 30,
        .species = SPECIES_MUK,
    },
};

static const struct TrainerMonItemCustomMoves sParty_FishermanElliot2[] = {
    {
        .lvl = 28,
        .species = SPECIES_POLIWHIRL,
    },
    {
        .lvl = 28,
        .species = SPECIES_CLOYSTER,
    },
    {
        .lvl = 28,
        .species = SPECIES_SEAKING,
    },
    {
        .lvl = 28,
        .species = SPECIES_SEADRA,
    },
};

static const struct TrainerMonItemCustomMoves sParty_RockerLuca2[] = {
    {
        .lvl = 33,
        .species = SPECIES_ELECTRODE,
    },
    {
        .lvl = 33,
        .species = SPECIES_ELECTRODE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BeautySheila2[] = {
    {
        .lvl = 49,
        .species = SPECIES_CLEFAIRY,
    },
    {
        .lvl = 49,
        .species = SPECIES_PERSIAN,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperRobert2[] = {
    {
        .lvl = 28,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 28,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 28,
        .species = SPECIES_FEAROW,
    },
    {
        .lvl = 28,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperRobert3[] = {
    {
        .lvl = 47,
        .species = SPECIES_PIDGEOT,
    },
    {
        .lvl = 47,
        .species = SPECIES_PIDGEOT,
    },
    {
        .lvl = 47,
        .species = SPECIES_FEAROW,
    },
    {
        .lvl = 47,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerSusie2[] = {
    {
        .lvl = 27,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 27,
        .species = SPECIES_MEOWTH,
    },
    {
        .lvl = 27,
        .species = SPECIES_RATICATE,
    },
    {
        .lvl = 27,
        .species = SPECIES_PIKACHU,
    },
    {
        .lvl = 27,
        .species = SPECIES_MEOWTH,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerSusie3[] = {
    {
        .lvl = 47,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 47,
        .species = SPECIES_PERSIAN,
    },
    {
        .lvl = 47,
        .species = SPECIES_RATICATE,
    },
    {
        .lvl = 47,
        .species = SPECIES_PIKACHU,
    },
    {
        .lvl = 47,
        .species = SPECIES_PERSIAN,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerSusie4[] = {
    {
        .lvl = 52,
        .species = SPECIES_PIDGEOT,
    },
    {
        .lvl = 52,
        .species = SPECIES_PERSIAN,
    },
    {
        .lvl = 52,
        .species = SPECIES_RATICATE,
    },
    {
        .lvl = 52,
        .species = SPECIES_RAICHU,
    },
    {
        .lvl = 52,
        .species = SPECIES_PERSIAN,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerLukas2[] = {
    {
        .lvl = 47,
        .species = SPECIES_KOFFING,
    },
    {
        .lvl = 47,
        .species = SPECIES_KOFFING,
    },
    {
        .lvl = 47,
        .species = SPECIES_MUK,
    },
    {
        .lvl = 47,
        .species = SPECIES_WEEZING,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperBenny2[] = {
    {
        .lvl = 32,
        .species = SPECIES_FEAROW,
    },
    {
        .lvl = 32,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperBenny3[] = {
    {
        .lvl = 49,
        .species = SPECIES_FEAROW,
    },
    {
        .lvl = 49,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperMarlon2[] = {
    {
        .lvl = 30,
        .species = SPECIES_FEAROW,
    },
    {
        .lvl = 30,
        .species = SPECIES_DODUO,
    },
    {
        .lvl = 30,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperMarlon3[] = {
    {
        .lvl = 48,
        .species = SPECIES_FEAROW,
    },
    {
        .lvl = 48,
        .species = SPECIES_DODRIO,
    },
    {
        .lvl = 48,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BeautyGrace2[] = {
    {
        .lvl = 49,
        .species = SPECIES_PIDGEOT,
    },
    {
        .lvl = 49,
        .species = SPECIES_WIGGLYTUFF,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperChester2[] = {
    {
        .lvl = -2,
        .species = SPECIES_DODRIO,
        .ability = Ability_Hidden, // gale wings
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_DRILLPECK, MOVE_ACUPRESSURE, MOVE_PURSUIT, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_TALONFLAME,
        .ability = Ability_Hidden, // gale wings
        .nature = NATURE_ADAMANT,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ACROBATICS, MOVE_ROOST, MOVE_FLAREBLITZ, MOVE_QUICKATTACK},
    },
    {
        .lvl = -2,
        .species = SPECIES_GLISCOR,
        .ability = Ability_1, // hyper cutter
        .nature = NATURE_JOLLY,
        .ivSpread = {IV_MEDIUM},
        .evSpread = {EV_80},
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_SWORDSDANCE, MOVE_KNOCKOFF, MOVE_ACROBATICS},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperChester3[] = {
    {
        .lvl = 48,
        .species = SPECIES_DODRIO,
    },
    {
        .lvl = 48,
        .species = SPECIES_DODRIO,
    },
    {
        .lvl = 48,
        .species = SPECIES_DODRIO,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerBecky2[] = {
    {
        .lvl = 32,
        .species = SPECIES_PIKACHU,
    },
    {
        .lvl = 32,
        .species = SPECIES_RAICHU,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerBecky3[] = {
    {
        .lvl = 49,
        .species = SPECIES_PIKACHU,
    },
    {
        .lvl = 49,
        .species = SPECIES_RAICHU,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerBecky4[] = {
    {
        .lvl = 54,
        .species = SPECIES_RAICHU,
    },
    {
        .lvl = 54,
        .species = SPECIES_RAICHU,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CrushKinRonMya2[] = {
    {
        .lvl = 33,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 33,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CrushKinRonMya3[] = {
    {
        .lvl = 51,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 51,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CrushKinRonMya4[] = {
    {
        .lvl = 56,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 56,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerRuben2[] = {
    {
        .lvl = 48,
        .species = SPECIES_WEEZING,
    },
    {
        .lvl = 48,
        .species = SPECIES_WEEZING,
    },
    {
        .lvl = 48,
        .species = SPECIES_WEEZING,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CueBallCamron2[] = {
    {
        .lvl = 49,
        .species = SPECIES_PRIMEAPE,
    },
    {
        .lvl = 49,
        .species = SPECIES_MACHOKE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BikerJaxon2[] = {
    {
        .lvl = 49,
        .species = SPECIES_WEEZING,
    },
    {
        .lvl = 49,
        .species = SPECIES_MUK,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CueBallIsaiah2[] = {
    {
        .lvl = 49,
        .species = SPECIES_MACHOKE,
    },
    {
        .lvl = 49,
        .species = SPECIES_MACHAMP,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CueBallCorey2[] = {
    {
        .lvl = 49,
        .species = SPECIES_PRIMEAPE,
    },
    {
        .lvl = 49,
        .species = SPECIES_MACHAMP,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperJacob2[] = {
    {
        .lvl = 28,
        .species = SPECIES_FEAROW,
    },
    {
        .lvl = 28,
        .species = SPECIES_SPEAROW,
    },
    {
        .lvl = 28,
        .species = SPECIES_FEAROW,
    },
    {
        .lvl = 28,
        .species = SPECIES_SPEAROW,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperJacob3[] = {
    {
        .lvl = 47,
        .species = SPECIES_FEAROW,
    },
    {
        .lvl = 47,
        .species = SPECIES_FEAROW,
    },
    {
        .lvl = 47,
        .species = SPECIES_FEAROW,
    },
    {
        .lvl = 47,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerFemaleAlice2[] = {
    {
        .lvl = 49,
        .species = SPECIES_SEAKING,
    },
    {
        .lvl = 49,
        .species = SPECIES_SEAKING,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleDarrin2[] = {
    {
        .lvl = 52,
        .species = SPECIES_SEADRA,
    },
    {
        .lvl = 52,
        .species = SPECIES_SEADRA,
    },
    {
        .lvl = 52,
        .species = SPECIES_SEADRA,
    },
    {
        .lvl = 52,
        .species = SPECIES_SEADRA,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerMissy2[] = {
    {
        .lvl = 49,
        .species = SPECIES_SEAKING,
    },
    {
        .lvl = 49,
        .species = SPECIES_SEAKING,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PicnickerMissy3[] = {
    {
        .lvl = 54,
        .species = SPECIES_SEAKING,
    },
    {
        .lvl = 54,
        .species = SPECIES_SEAKING,
    },
};

static const struct TrainerMonItemCustomMoves sParty_FishermanWade2[] = {
    {
        .lvl = 47,
        .species = SPECIES_MAGIKARP,
    },
    {
        .lvl = 47,
        .species = SPECIES_MAGIKARP,
    },
    {
        .lvl = 47,
        .species = SPECIES_MAGIKARP,
    },
    {
        .lvl = 47,
        .species = SPECIES_MAGIKARP,
    },
    {
        .lvl = 47,
        .species = SPECIES_MAGIKARP,
    },
    {
        .lvl = 47,
        .species = SPECIES_MAGIKARP,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleJack2[] = {
    {
        .lvl = 50,
        .species = SPECIES_STARMIE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SisAndBroLilIan2[] = {
    {
        .lvl = 50,
        .species = SPECIES_SEADRA,
    },
    {
        .lvl = 50,
        .species = SPECIES_STARMIE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SisAndBroLilIan3[] = {
    {
        .lvl = 55,
        .species = SPECIES_SEADRA,
    },
    {
        .lvl = 55,
        .species = SPECIES_STARMIE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleFinn2[] = {
    {
        .lvl = 50,
        .species = SPECIES_STARMIE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CrushGirlSharon2[] = {
    {
        .lvl = 50,
        .species = SPECIES_MANKEY,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 50,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CrushGirlSharon3[] = {
    {
        .lvl = 55,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 55,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CrushGirlTanya2[] = {
    {
        .lvl = 50,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 50,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CrushGirlTanya3[] = {
    {
        .lvl = 55,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 55,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BlackBeltShea2[] = {
    {
        .lvl = 50,
        .species = SPECIES_MACHOKE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 50,
        .species = SPECIES_MACHOKE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BlackBeltShea3[] = {
    {
        .lvl = 55,
        .species = SPECIES_MACHOKE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 55,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BlackBeltHugh2[] = {
    {
        .lvl = 50,
        .species = SPECIES_MACHOKE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 50,
        .species = SPECIES_MACHOKE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BlackBeltHugh3[] = {
    {
        .lvl = 55,
        .species = SPECIES_MACHOKE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 55,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CrushKinMikKia2[] = {
    {
        .lvl = 51,
        .species = SPECIES_MACHOKE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 51,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_CrushKinMikKia3[] = {
    {
        .lvl = 56,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 56,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_TuberAmira2[] = {
    {
        .lvl = 47,
        .species = SPECIES_POLIWHIRL,
    },
    {
        .lvl = 47,
        .species = SPECIES_POLIWHIRL,
    },
    {
        .lvl = 47,
        .species = SPECIES_POLIWHIRL,
    },
};

static const struct TrainerMonItemCustomMoves sParty_TwinsJoyMeg2[] = {
    {
        .lvl = 49,
        .species = SPECIES_CLEFAIRY,
    },
    {
        .lvl = 49,
        .species = SPECIES_CLEFAIRY,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PainterRayna2[] = {
    {
        .lvl = 54,
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_CROSSCHOP, MOVE_MEGAHORN, MOVE_DOUBLEEDGE, MOVE_SELFDESTRUCT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungsterDestin2[] = {
    {
        .lvl = 53,
        .species = SPECIES_RATICATE,
    },
    {
        .lvl = 53,
        .species = SPECIES_PIDGEOT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PkmnBreederAlize2[] = {
    {
        .lvl = 53,
        .species = SPECIES_PIKACHU,
    },
    {
        .lvl = 53,
        .species = SPECIES_CLEFAIRY,
    },
    {
        .lvl = 53,
        .species = SPECIES_MARILL,
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungCoupleGiaJes2[] = {
    {
        .lvl = 30,
        .species = SPECIES_NIDORINA,
    },
    {
        .lvl = 30,
        .species = SPECIES_NIDORINO,
    },
};

static const struct TrainerMonItemCustomMoves sParty_YoungCoupleGiaJes3[] = {
    {
        .lvl = 55,
        .species = SPECIES_NIDOKING,
    },
    {
        .lvl = 55,
        .species = SPECIES_NIDOQUEEN,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperMilo2[] = {
    {
        .lvl = 53,
        .species = SPECIES_PIDGEOTTO,
    },
    {
        .lvl = 55,
        .species = SPECIES_PIDGEOT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperChaz2[] = {
    {
        .lvl = 53,
        .species = SPECIES_FEAROW,
    },
    {
        .lvl = 55,
        .species = SPECIES_FEAROW,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BirdKeeperHarold2[] = {
    {
        .lvl = 53,
        .species = SPECIES_NOCTOWL,
    },
    {
        .lvl = 55,
        .species = SPECIES_NOCTOWL,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerFemaleNicole2[] = {
    {
        .lvl = 54,
        .species = SPECIES_MARILL,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PsychicJaclyn2[] = {
    {
        .lvl = 52,
        .species = SPECIES_NATU,
        .moves = {MOVE_PSYCHIC, MOVE_CONFUSERAY, MOVE_FUTURESIGHT, MOVE_WISH},
    },
    {
        .lvl = 52,
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_PSYCHIC, MOVE_HEADBUTT, MOVE_AMNESIA, MOVE_YAWN},
    },
    {
        .lvl = 54,
        .species = SPECIES_KADABRA,
        .moves = {MOVE_PSYCHIC, MOVE_FUTURESIGHT, MOVE_RECOVER, MOVE_REFLECT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleSamir2[] = {
    {
        .lvl = 55,
        .species = SPECIES_GYARADOS,
    },
};

static const struct TrainerMonItemCustomMoves sParty_HikerEarl2[] = {
    {
        .lvl = 54,
        .species = SPECIES_ONIX,
    },
    {
        .lvl = 54,
        .species = SPECIES_MACHAMP,
    },
};

static const struct TrainerMonItemCustomMoves sParty_RuinManiacLarry2[] = {
    {
        .lvl = 54,
        .species = SPECIES_MACHOKE,
    },
    {
        .lvl = 54,
        .species = SPECIES_MACHOKE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PokemaniacHector2[] = {
    {
        .lvl = 55,
        .species = SPECIES_RHYDON,
    },
    {
        .lvl = 55,
        .species = SPECIES_KANGASKHAN,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PsychicDario2[] = {
    {
        .lvl = 56,
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_CRUNCH, MOVE_PSYBEAM, MOVE_ODORSLEUTH, MOVE_AGILITY},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PsychicRodette2[] = {
    {
        .lvl = 53,
        .species = SPECIES_NATU,
        .moves = {MOVE_PSYCHIC, MOVE_CONFUSERAY, MOVE_WISH, MOVE_FUTURESIGHT},
    },
    {
        .lvl = 53,
        .species = SPECIES_HYPNO,
        .moves = {MOVE_PSYCHIC, MOVE_DISABLE, MOVE_PSYCHUP, MOVE_FUTURESIGHT},
    },
    {
        .lvl = 53,
        .species = SPECIES_HYPNO,
        .moves = {MOVE_PSYCHIC, MOVE_HYPNOSIS, MOVE_PSYCHUP, MOVE_FUTURESIGHT},
    },
};

static const struct TrainerMonItemCustomMoves sParty_JugglerMason2[] = {
    {
        .lvl = 52,
        .species = SPECIES_ELECTRODE,
    },
    {
        .lvl = 52,
        .species = SPECIES_PINECO,
    },
    {
        .lvl = 52,
        .species = SPECIES_ELECTRODE,
    },
    {
        .lvl = 52,
        .species = SPECIES_PINECO,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PkmnRangerNicolas2[] = {
    {
        .lvl = 55,
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_RAZORLEAF, MOVE_ACID, MOVE_STUNSPORE, MOVE_WRAP},
    },
    {
        .lvl = 55,
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_RAZORLEAF, MOVE_ACID, MOVE_SLEEPPOWDER, MOVE_SLAM},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PkmnRangerMadeline2[] = {
    {
        .lvl = 55,
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_PETALDANCE, MOVE_MOONLIGHT, MOVE_ACID, MOVE_SLEEPPOWDER},
    },
    {
        .lvl = 55,
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_PETALDANCE, MOVE_MOONLIGHT, MOVE_ACID, MOVE_STUNSPORE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CrushGirlCyndy2[] = {
    {
        .lvl = 54,
        .species = SPECIES_PRIMEAPE,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 54,
        .species = SPECIES_HITMONTOP,
        .heldItem = ITEM_BLACK_BELT,
    },
    {
        .lvl = 54,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_BLACK_BELT,
    },
};

static const struct TrainerMonItemCustomMoves sParty_TamerEvan2[] = {
    {
        .lvl = 52,
        .species = SPECIES_SANDSLASH,
    },
    {
        .lvl = 52,
        .species = SPECIES_LICKITUNG,
    },
    {
        .lvl = 55,
        .species = SPECIES_URSARING,
    },
};

static const struct TrainerMonItemCustomMoves sParty_PkmnRangerJackson2[] = {
    {
        .lvl = 53,
        .species = SPECIES_TANGELA,
        .moves = {MOVE_SLAM, MOVE_MEGADRAIN, MOVE_BIND, MOVE_INGRAIN},
    },
    {
        .lvl = 54,
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_CONFUSION, MOVE_EGGBOMB, MOVE_STUNSPORE, MOVE_REFLECT},
    },
    {
        .lvl = 55,
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_CONFUSION, MOVE_EGGBOMB, MOVE_SLEEPPOWDER, MOVE_STOMP},
    },
};

static const struct TrainerMonItemCustomMoves sParty_PkmnRangerKatelyn2[] = {
    {
        .lvl = 56,
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_EGGBOMB, MOVE_DEFENSECURL, MOVE_MINIMIZE, MOVE_SOFTBOILED},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerLeroy2[] = {
    {
        .lvl = 52,
        .species = SPECIES_RHYDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_HORNDRILL, MOVE_ROCKBLAST, MOVE_SCARYFACE},
    },
    {
        .lvl = 54,
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_PSYCHIC, MOVE_HEADBUTT, MOVE_AMNESIA, MOVE_DISABLE},
    },
    {
        .lvl = 52,
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_DIZZYPUNCH, MOVE_BITE, MOVE_ENDURE, MOVE_REVERSAL},
    },
    {
        .lvl = 52,
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CROSSCHOP, MOVE_VITALTHROW, MOVE_REVENGE, MOVE_SEISMICTOSS},
    },
    {
        .lvl = 55,
        .species = SPECIES_URSARING,
        .moves = {MOVE_SLASH, MOVE_FEINTATTACK, MOVE_SNORE, MOVE_REST},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CooltrainerMichelle2[] = {
    {
        .lvl = 53,
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_SLASH, MOVE_SCREECH, MOVE_FEINTATTACK, MOVE_BITE},
    },
    {
        .lvl = 53,
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_ICEBEAM, MOVE_TAKEDOWN, MOVE_ICYWIND, MOVE_SHEERCOLD},
    },
    {
        .lvl = 54,
        .species = SPECIES_NINETALES,
        .moves = {MOVE_FLAMETHROWER, MOVE_CONFUSERAY, MOVE_WILLOWISP, MOVE_GRUDGE},
    },
    {
        .lvl = 54,
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_BOUNCE, MOVE_AGILITY, MOVE_FIRESPIN, MOVE_TAKEDOWN},
    },
    {
        .lvl = 56,
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_CRUNCH, MOVE_PSYBEAM, MOVE_STOMP, MOVE_ODORSLEUTH},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CoolCoupleLexNya2[] = {
    {
        .lvl = 57,
        .species = SPECIES_MILTANK,
        .moves = {MOVE_BODYSLAM, MOVE_MILKDRINK, MOVE_GROWL, MOVE_DEFENSECURL},
    },
    {
        .lvl = 57,
        .species = SPECIES_TAUROS,
        .moves = {MOVE_TAKEDOWN, MOVE_SCARYFACE, MOVE_PURSUIT, MOVE_SWAGGER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherColton2[] = {
    {
        .lvl = 19,
        .species = SPECIES_METAPOD,
    },
    {
        .lvl = 19,
        .species = SPECIES_WEEDLE,
    },
    {
        .lvl = 19,
        .species = SPECIES_METAPOD,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherColton3[] = {
    {
        .lvl = 27,
        .species = SPECIES_BUTTERFREE,
    },
    {
        .lvl = 27,
        .species = SPECIES_KAKUNA,
    },
    {
        .lvl = 27,
        .species = SPECIES_BUTTERFREE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_BugCatcherColton4[] = {
    {
        .lvl = 51,
        .species = SPECIES_BUTTERFREE,
    },
    {
        .lvl = 54,
        .species = SPECIES_BEEDRILL,
    },
    {
        .lvl = 51,
        .species = SPECIES_BUTTERFREE,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleMatthew2[] = {
    {
        .lvl = 49,
        .species = SPECIES_POLIWHIRL,
    },
    {
        .lvl = 49,
        .species = SPECIES_POLIWRATH,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerMaleTony2[] = {
    {
        .lvl = 49,
        .species = SPECIES_SEADRA,
    },
    {
        .lvl = 49,
        .species = SPECIES_SEADRA,
    },
};

static const struct TrainerMonItemCustomMoves sParty_SwimmerFemaleMelissa2[] = {
    {
        .lvl = 49,
        .species = SPECIES_POLIWHIRL,
    },
    {
        .lvl = 49,
        .species = SPECIES_SEAKING,
    },
};

static const struct TrainerMonItemCustomMoves sParty_EliteFourLorelei2[] = {
    {
        .lvl = 64,
        .species = SPECIES_DEWGONG,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ICEBEAM, MOVE_SURF, MOVE_SIGNALBEAM, MOVE_DOUBLETEAM},
    },
    {
        .lvl = 63,
        .species = SPECIES_CLOYSTER,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ICEBEAM, MOVE_SURF, MOVE_SUPERSONIC, MOVE_RAINDANCE},
    },
    {
        .lvl = 63,
        .species = SPECIES_PILOSWINE,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_BLIZZARD, MOVE_EARTHQUAKE, MOVE_DOUBLEEDGE, MOVE_ROCKSLIDE},
    },
    {
        .lvl = 66,
        .species = SPECIES_JYNX,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_ICEBEAM, MOVE_PSYCHIC, MOVE_LOVELYKISS, MOVE_ATTRACT},
    },
    {
        .lvl = 66,
        .species = SPECIES_LAPRAS,
        .heldItem = ITEM_CHERI_BERRY,
        .moves = {MOVE_ICEBEAM, MOVE_SURF, MOVE_PSYCHIC, MOVE_THUNDER},
    },
};

static const struct TrainerMonItemCustomMoves sParty_EliteFourBruno2[] = {
    {
        .lvl = 65,
        .species = SPECIES_STEELIX,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRONTAIL, MOVE_CRUNCH, MOVE_ROCKTOMB},
    },
    {
        .lvl = 65,
        .species = SPECIES_HITMONCHAN,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SKYUPPERCUT, MOVE_MACHPUNCH, MOVE_ROCKSLIDE, MOVE_COUNTER},
    },
    {
        .lvl = 65,
        .species = SPECIES_HITMONLEE,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MEGAKICK, MOVE_FORESIGHT, MOVE_EARTHQUAKE, MOVE_ROCKSLIDE},
    },
    {
        .lvl = 66,
        .species = SPECIES_STEELIX,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRONTAIL, MOVE_CRUNCH, MOVE_DRAGONBREATH},
    },
    {
        .lvl = 68,
        .species = SPECIES_MACHAMP,
        .heldItem = ITEM_PERSIM_BERRY,
        .moves = {MOVE_CROSSCHOP, MOVE_EARTHQUAKE, MOVE_BRICKBREAK, MOVE_ROCKSLIDE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_EliteFourAgatha2[] = {
    {
        .lvl = 66,
        .species = SPECIES_GENGAR,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWBALL, MOVE_PSYCHIC, MOVE_CONFUSERAY, MOVE_HYPNOSIS},
    },
    {
        .lvl = 66,
        .species = SPECIES_CROBAT,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGEBOMB, MOVE_AIRCUTTER, MOVE_SHADOWBALL, MOVE_CONFUSERAY},
    },
    {
        .lvl = 65,
        .species = SPECIES_MISDREAVUS,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SHADOWBALL, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ATTRACT},
    },
    {
        .lvl = 68,
        .species = SPECIES_ARBOK,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_SLUDGEBOMB, MOVE_EARTHQUAKE, MOVE_GIGADRAIN, MOVE_DOUBLETEAM},
    },
    {
        .lvl = 70,
        .species = SPECIES_GENGAR,
        .heldItem = ITEM_CHESTO_BERRY,
        .moves = {MOVE_SHADOWBALL, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_SLUDGEBOMB},
    },
};

static const struct TrainerMonItemCustomMoves sParty_EliteFourLance2[] = {
    {
        .lvl = 68,
        .species = SPECIES_GYARADOS,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERBEAM, MOVE_DRAGONDANCE, MOVE_EARTHQUAKE, MOVE_THUNDERWAVE},
    },
    {
        .lvl = 66,
        .species = SPECIES_DRAGONITE,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERBEAM, MOVE_EARTHQUAKE, MOVE_DRAGONCLAW, MOVE_FLAMETHROWER},
    },
    {
        .lvl = 66,
        .species = SPECIES_KINGDRA,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERBEAM, MOVE_DRAGONDANCE, MOVE_SURF, MOVE_ICEBEAM},
    },
    {
        .lvl = 70,
        .species = SPECIES_AERODACTYL,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYPERBEAM, MOVE_ANCIENTPOWER, MOVE_AERIALACE, MOVE_EARTHQUAKE},
    },
    {
        .lvl = 72,
        .species = SPECIES_DRAGONITE,
        .heldItem = ITEM_PERSIM_BERRY,
        .moves = {MOVE_HYPERBEAM, MOVE_OUTRAGE, MOVE_THUNDERBOLT, MOVE_ICEBEAM},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChampionRematchSquirtle[] = {
    {
        .lvl = 72,
        .species = SPECIES_HERACROSS,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_ROCKTOMB},
    },
    {
        .lvl = 73,
        .species = SPECIES_ALAKAZAM,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOWBALL, MOVE_CALMMIND, MOVE_REFLECT},
    },
    {
        .lvl = 72,
        .species = SPECIES_TYRANITAR,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_THUNDERBOLT, MOVE_AERIALACE},
    },
    {
        .lvl = 73,
        .species = SPECIES_ARCANINE,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EXTREMESPEED, MOVE_OVERHEAT, MOVE_AERIALACE, MOVE_IRONTAIL},
    },
    {
        .lvl = 73,
        .species = SPECIES_EXEGGUTOR,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GIGADRAIN, MOVE_PSYCHIC, MOVE_SLEEPPOWDER, MOVE_LIGHTSCREEN},
    },
    {
        .lvl = 75,
        .species = SPECIES_BLASTOISE,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_HYDROPUMP, MOVE_ICEBEAM, MOVE_EARTHQUAKE, MOVE_RAINDANCE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChampionRematchBulbasaur[] = {
    {
        .lvl = 72,
        .species = SPECIES_HERACROSS,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_ROCKTOMB},
    },
    {
        .lvl = 73,
        .species = SPECIES_ALAKAZAM,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOWBALL, MOVE_CALMMIND, MOVE_REFLECT},
    },
    {
        .lvl = 72,
        .species = SPECIES_TYRANITAR,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_THUNDERBOLT, MOVE_AERIALACE},
    },
    {
        .lvl = 73,
        .species = SPECIES_GYARADOS,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYDROPUMP, MOVE_DRAGONDANCE, MOVE_EARTHQUAKE, MOVE_HYPERBEAM},
    },
    {
        .lvl = 73,
        .species = SPECIES_ARCANINE,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_EXTREMESPEED, MOVE_OVERHEAT, MOVE_AERIALACE, MOVE_IRONTAIL},
    },
    {
        .lvl = 75,
        .species = SPECIES_VENUSAUR,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_SOLARBEAM, MOVE_SLUDGEBOMB, MOVE_EARTHQUAKE, MOVE_SUNNYDAY},
    },
};

static const struct TrainerMonItemCustomMoves sParty_ChampionRematchCharmander[] = {
    {
        .lvl = 72,
        .species = SPECIES_HERACROSS,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_ROCKTOMB},
    },
    {
        .lvl = 73,
        .species = SPECIES_ALAKAZAM,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOWBALL, MOVE_CALMMIND, MOVE_REFLECT},
    },
    {
        .lvl = 72,
        .species = SPECIES_TYRANITAR,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_THUNDERBOLT, MOVE_AERIALACE},
    },
    {
        .lvl = 73,
        .species = SPECIES_EXEGGUTOR,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_GIGADRAIN, MOVE_PSYCHIC, MOVE_SLEEPPOWDER, MOVE_LIGHTSCREEN},
    },
    {
        .lvl = 73,
        .species = SPECIES_GYARADOS,
        .heldItem = ITEM_NONE,
        .moves = {MOVE_HYDROPUMP, MOVE_DRAGONDANCE, MOVE_EARTHQUAKE, MOVE_HYPERBEAM},
    },
    {
        .lvl = 75,
        .species = SPECIES_CHARIZARD,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = {MOVE_FIREBLAST, MOVE_DRAGONCLAW, MOVE_AERIALACE, MOVE_EARTHQUAKE},
    },
};

static const struct TrainerMonItemCustomMoves sParty_CueBallPaxton[] = {
    {
        .lvl = 39,
        .species = SPECIES_WEEZING,
    },
    {
        .lvl = 39,
        .species = SPECIES_MUK,
    },
};