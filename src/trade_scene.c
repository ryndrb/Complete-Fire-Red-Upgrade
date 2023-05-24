#include "defines.h"
#include "defines_battle.h"

#include "../include/string_util.h"
#include "../include/pokemon.h"
#include "../include/random.h"
#include "../include/trade.h"
#include "../include/new/build_pokemon.h"
#include "../include/new/trade_scene.h"
#include "../include/new/Vanilla_functions.h"

// Populates gStringVar1 with the name of the requested species and
// gStringVar2 with the name of the offered species.
// Returns the requested species.
u16 GetInGameTradeSpeciesInfo(void){
    const struct InGameTrade * inGameTrade = &sInGameTrades[Var8004];
    StringCopy(gStringVar1, gSpeciesNames[inGameTrade->requestedSpecies]);
    StringCopy(gStringVar2, gSpeciesNames[inGameTrade->species]);
    return inGameTrade->requestedSpecies;
}

// Populates gStringVar1 with the nickname of the sent Pokemon and
// gStringVar2 with the name of the offered species.
void BufferInGameTradeMonName(void){
    u8 nickname[30];
    const struct InGameTrade * inGameTrade = &sInGameTrades[Var8004];
    GetMonData(&gPlayerParty[Var8005], MON_DATA_NICKNAME, nickname);
    StringCopy10(gStringVar1, nickname);
    StringCopy(gStringVar2, gSpeciesNames[inGameTrade->species]);
}

void TradeBufferOTnameAndNicknames(void){
    u8 nickname[20];
    u8 mpId;
    const struct InGameTrade * inGameTrade;
    if (sTradeAnim->isLinkTrade){
        mpId = GetMultiplayerId();
        StringCopy(gStringVar1, gLinkPlayers[mpId ^ 1].name);
        GetMonData(&gEnemyParty[gSelectedTradeMonPositions[TRADE_PARTNER] % PARTY_SIZE], MON_DATA_NICKNAME, nickname);
        StringCopy10(gStringVar3, nickname);
        GetMonData(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], MON_DATA_NICKNAME, nickname);
        StringCopy10(gStringVar2, nickname);
    }else{
        inGameTrade = &sInGameTrades[Var8004];
        StringCopy(gStringVar1, inGameTrade->otName);
        StringCopy10(gStringVar3, inGameTrade->nickname);
        GetMonData(&gPlayerParty[Var8005], MON_DATA_NICKNAME, nickname);
        StringCopy10(gStringVar2, nickname);
    }
}

void CreateInGameTradePokemonInternal(u8 playerSlot, u8 inGameTradeIdx){
    const struct InGameTrade * inGameTrade = &sInGameTrades[inGameTradeIdx];
    u8 level = GetMonData(&gPlayerParty[playerSlot], MON_DATA_LEVEL, 0);
    struct MailStruct mail;
    u8 metLocation = METLOC_IN_GAME_TRADE;
    struct Pokemon * tradeMon = &gEnemyParty[0];
    u8 mailNum;

    CreateMon(tradeMon, inGameTrade->species, level, USE_RANDOM_IVS, TRUE, inGameTrade->personality, TRUE, inGameTrade->otId);
    SetMonData(tradeMon, MON_DATA_HP_IV, &inGameTrade->ivs[0]);
    SetMonData(tradeMon, MON_DATA_ATK_IV, &inGameTrade->ivs[1]);
    SetMonData(tradeMon, MON_DATA_DEF_IV, &inGameTrade->ivs[2]);
    SetMonData(tradeMon, MON_DATA_SPEED_IV, &inGameTrade->ivs[3]);
    SetMonData(tradeMon, MON_DATA_SPATK_IV, &inGameTrade->ivs[4]);
    SetMonData(tradeMon, MON_DATA_SPDEF_IV, &inGameTrade->ivs[5]);
    SetMonData(tradeMon, MON_DATA_NICKNAME, inGameTrade->nickname);
    SetMonData(tradeMon, MON_DATA_OT_NAME, inGameTrade->otName);
    SetMonData(tradeMon, MON_DATA_OT_GENDER, &inGameTrade->otGender);
    // SetMonData(tradeMon, MON_DATA_ALT_ABILITY, &inGameTrade->abilityNum); doesn't work
    SetMonData(tradeMon, MON_DATA_BEAUTY, &inGameTrade->conditions[1]);
    SetMonData(tradeMon, MON_DATA_CUTE, &inGameTrade->conditions[2]);
    SetMonData(tradeMon, MON_DATA_COOL, &inGameTrade->conditions[0]);
    SetMonData(tradeMon, MON_DATA_SMART, &inGameTrade->conditions[3]);
    SetMonData(tradeMon, MON_DATA_TOUGH, &inGameTrade->conditions[4]);
    SetMonData(tradeMon, MON_DATA_SHEEN, &inGameTrade->sheen);
    SetMonData(tradeMon, MON_DATA_MET_LOCATION, &metLocation);

    SetAbilityFromEnum(tradeMon, inGameTrade->abilityNum, Random32() % 25);

    mailNum = 0;

    if (inGameTrade->heldItem != ITEM_NONE){
        if (ItemIsMail(inGameTrade->heldItem)){
            GetInGameTradeMail(&mail, inGameTrade);
            gLinkPartnerMail[0] = mail;
            SetMonData(tradeMon, MON_DATA_MAIL, &mailNum);
            SetMonData(tradeMon, MON_DATA_HELD_ITEM, &inGameTrade->heldItem);
        }else{
            SetMonData(tradeMon, MON_DATA_HELD_ITEM, &inGameTrade->heldItem);
        }
    }
    CalculateMonStats(&gEnemyParty[0]);
}
