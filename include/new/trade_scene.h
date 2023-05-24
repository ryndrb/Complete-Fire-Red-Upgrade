#include "../global.h"
#include "../pokemon.h"
#include "../string_util.h"

#include "../constants/easy_chat.h"
#include "../constants/items.h"
#include "../constants/items.h"
#include "../constants/region_map_sections.h"
#include "../constants/species.h"

#include "build_pokemon_2.h"

#include "../../src/Tables/Trainer_Tables/trainerids.h" // String utils

#define TRADE_PLAYER                0
#define TRADE_PARTNER               1

#define USE_RANDOM_IVS              32

// Contests
#define CONTEST_CATEGORIES_COUNT    5

#define EC_GROUP_PEOPLE             0x5
#define EC_GROUP_VOICES             0x6
#define EC_GROUP_SPEECH             0x7
#define EC_GROUP_ENDINGS            0x8
#define EC_GROUP_CONDITIONS         0xa

// In-game Trade IDs
#define INGAME_TRADE_MR_MIME        0
#define INGAME_TRADE_JYNX           1
#define INGAME_TRADE_NIDORAN        2  // M or F depending on version
#define INGAME_TRADE_FARFETCHD      3
#define INGAME_TRADE_NIDORINOA      4  // Nidorino or Nidorina depending on version
#define INGAME_TRADE_LICKITUNG      5
#define INGAME_TRADE_ELECTRODE      6
#define INGAME_TRADE_TANGELA        7
#define INGAME_TRADE_SEEL           8

struct{
    /*0x00*/ struct Pokemon tempMon; // Used as a temp variable when swapping Pokémon
    /*0x64*/ u32 timer;
    /*0x68*/ u32 monPersonalities[2];
    /*0x70*/ u8 filler_70[2];
    /*0x72*/ u8 playerFinishStatus;
    /*0x73*/ u8 partnerFinishStatus;
    /*0x74*/ u16 linkData[10];
    /*0x88*/ u8 linkTimeoutCheck1;
    /*0x89*/ u8 linkTimeoutCheck2;
    /*0x8A*/ u16 linkTimeoutTimer;
    /*0x8C*/ u16 neverRead_8C;
    /*0x8E*/ u8 monSpriteIds[2];
    /*0x90*/ u8 connectionSpriteId1; // Multi-purpose sprite ids used during the transfer sequence
    /*0x91*/ u8 connectionSpriteId2;
    /*0x92*/ u8 cableEndSpriteId;
    /*0x93*/ u8 scheduleLinkTransfer;
    /*0x94*/ u16 state;
    /*0x96*/ u8 filler_96[0xD2 - 0x96];
    /*0xD2*/ u8 releasePokeballSpriteId;
    /*0xD3*/ u8 bouncingPokeballSpriteId;
    /*0xD4*/ u16 bg2texX;
    /*0xD6*/ u16 bg2texY;
    /*0xD8*/ u16 neverRead_D8;
    /*0xDA*/ u16 neverRead_DA;
    /*0xDC*/ u16 bg2srcX;
    /*0xDE*/ u16 bg2srcY;
    /*0xE0*/ s16 bg1vofs;
    /*0xE2*/ s16 bg1hofs;
    /*0xE4*/ s16 bg2vofs;
    /*0xE6*/ s16 bg2hofs;
    /*0xE8*/ u16 sXY;
    /*0xEA*/ u16 bg2Zoom;
    /*0xEC*/ u16 bg2alpha;
    /*0xEE*/ bool8 isLinkTrade;
    /*0xF0*/ u16 monSpecies[2];
    /*0xF4*/ u16 cachedMapMusic;
    /*0xF6*/ u8 unk_F6;
    /*0xF8*/ u16 questLogSpecies[2];
    /*0xFC*/ u8 linkPartnerName[7];
    /*0x103*/ u8 filler_103[1];
    /*0x104*/ u8 textColor[3];
    /*0x107*/ u8 filler_107[1];
    /*0x108*/ bool8 isCableTrade;
    /*0x109*/ u8 win0left;
    /*0x10A*/ u8 win0top;
    /*0x10B*/ u8 win0right;
    /*0x10C*/ u8 win0bottom;
} *sTradeAnim = NULL; // ???

struct InGameTrade {
    /*0x00*/ u8 nickname[POKEMON_NAME_LENGTH + 1];
    /*0x0C*/ u16 species;
    /*0x0E*/ u8 ivs[NUM_STATS];
    /*0x14*/ u8 abilityNum;
    /*0x18*/ u32 otId;
    /*0x1C*/ u8 conditions[CONTEST_CATEGORIES_COUNT];
    /*0x24*/ u32 personality;
    /*0x28*/ u16 heldItem;
    /*0x2A*/ u8 mailNum;
    /*0x2B*/ u8 otName[11];
    /*0x36*/ u8 otGender;
    /*0x37*/ u8 sheen;
    /*0x38*/ u16 requestedSpecies;
};

void __attribute__((long_call)) GetInGameTradeMail(struct MailStruct* mail, const struct InGameTrade* inGameTrade);
bool8 __attribute__((long_call)) ItemIsMail(u16 itemId);

const struct InGameTrade sInGameTrades[] = {
    [INGAME_TRADE_MR_MIME] = 
    {
        .nickname = {_M,_i,_m,_i,_e,_n,_END},
        .species = SPECIES_MR_MIME,
        .ivs = {20, 15, 17, 24, 23, 22},
        .abilityNum = Ability_RandomAll,
        .otId = 1985,
        .conditions = {5, 5, 5, 30, 5},
        .personality = 0x00009cae,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = {_R,_e,_y,_l,_e,_y,_END},
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_ABRA
    }, 
    [INGAME_TRADE_JYNX] = 
    {
        .nickname = {_Z,_y,_n,_x,_END},
        .species = SPECIES_JYNX,
        .ivs = {18, 17, 18, 22, 25, 21},
        .abilityNum = Ability_RandomAll,
        .otId = 36728,
        .conditions = {5, 30, 5, 5, 5},
        .personality = 0x498a2e1d,
        .heldItem = ITEM_FAB_MAIL,
        .mailNum = 0,
        .otName = {_D,_o,_n,_t,_a,_e,_END},
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_POLIWHIRL
    }, 
    [INGAME_TRADE_NIDORAN] = 
    {
        .nickname = {_M,_s,_PERIOD,_SPACE,_N,_i,_d,_o,_END},
        .species = SPECIES_NIDORAN_F,
        .ivs = {22, 18, 25, 19, 15, 22},
        .abilityNum = Ability_RandomAll,
        .otId = 63184,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x4c970b89,
        .heldItem = ITEM_TINY_MUSHROOM,
        .mailNum = 255,
        .otName = {_S,_a,_i,_g,_e,_END},
        .otGender = FEMALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_NIDORAN_M
    }, 
    [INGAME_TRADE_FARFETCHD] = 
    {
        .nickname = {_C,_h,_APOSTROPHE,_D,_i,_n,_g,_END},
        .species = SPECIES_FARFETCHD,
        .ivs = {20, 25, 21, 24, 15, 20},
        .abilityNum = Ability_RandomAll,
        .otId = 8810,
        .conditions = {30, 5, 5, 5, 5},
        .personality = 0x151943d7,
        .heldItem = ITEM_LEEK,
        .mailNum = 255,
        .otName = {_E,_l,_y,_s,_s,_a,_END},
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_SPEAROW
    }, 
    [INGAME_TRADE_NIDORINOA] = 
    {
        .nickname = {_N,_i,_n,_a,_END},
        .species = SPECIES_NIDORINA,
        .ivs = {22, 25, 18, 19, 22, 15},
        .abilityNum = Ability_RandomAll,
        .otId = 13637,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x00eeca15,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = {_T,_u,_r,_n,_e,_r,_END},
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_NIDORINO
    }, 
    [INGAME_TRADE_LICKITUNG] = 
    {
        .nickname = {_M,_a,_r,_c,_END},
        .species = SPECIES_LICKITUNG,
        .ivs = {24, 19, 21, 15, 23, 21},
        .abilityNum = Ability_RandomAll,
        .otId = 1239,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x451308ab,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = {_H,_a,_d,_e,_n,_END},
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_GOLDUCK
    }, 
    [INGAME_TRADE_ELECTRODE] = 
    {
        .nickname = {_E,_s,_p,_h,_e,_r,_e,_END},
        .species = SPECIES_ELECTRODE,
        .ivs = {19, 16, 18, 25, 25, 19},
        .abilityNum = Ability_RandomAll,
        .otId = 50298,
        .conditions = {30, 5, 5, 5, 5},
        .personality = 0x06341016,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = {_C,_l,_i,_f,_t,_o,_n,_END},
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_RAICHU
    }, 
    [INGAME_TRADE_TANGELA] = 
    {
        .nickname = {_T,_a,_n,_g,_e,_n,_y,_END},
        .species = SPECIES_TANGELA,
        .ivs = {22, 17, 25, 16, 23, 20},
        .abilityNum = Ability_RandomAll,
        .otId = 60042,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x5c77ecfa,
        .heldItem = ITEM_STARDUST,
        .mailNum = 255,
        .otName = {_N,_o,_r,_m,_a,_END},
        .otGender = FEMALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_VENONAT
    },
    [INGAME_TRADE_SEEL] = 
    {
        .nickname = {_S,_e,_e,_l,_o,_r,_END},
        .species = SPECIES_SEEL,
        .ivs = {24, 15, 22, 16, 23, 22},
        .abilityNum = Ability_RandomAll,
        .otId = 9853,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x482cac89,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = {_G,_a,_r,_e,_t,_t,_END},
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_PONYTA
    },
};

static const u16 sInGameTradeMailMessages[][10] = {
    {
        EC_WORD_THAT_S,
        EC_WORD_A,
        EC_WORD_HEALTHY,
        EC_POKEMON(JYNX),
        EC_WORD_EXCL,
        EC_WORD_BE,
        EC_WORD_KIND,
        EC_WORD_TO,
        EC_WORD_IT
    }
};
