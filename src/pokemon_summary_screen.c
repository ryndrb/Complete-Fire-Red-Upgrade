#include "../include/menu.h"
#include "../include/pokemon_summary_screen.h"
#include "../include/string_util.h"

// From pokeemerald wiki

static const s8 sNatureStatTable[NUM_NATURES][NUM_NATURE_STATS] =
{                      // Attack  Defense  Speed  Sp.Atk  Sp.Def
    [NATURE_HARDY]   = {    0,      0,      0,      0,      0   },
    [NATURE_LONELY]  = {   +1,     -1,      0,      0,      0   },
    [NATURE_BRAVE]   = {   +1,      0,     -1,      0,      0   },
    [NATURE_ADAMANT] = {   +1,      0,      0,     -1,      0   },
    [NATURE_NAUGHTY] = {   +1,      0,      0,      0,     -1   },
    [NATURE_BOLD]    = {   -1,     +1,      0,      0,      0   },
    [NATURE_DOCILE]  = {    0,      0,      0,      0,      0   },
    [NATURE_RELAXED] = {    0,     +1,     -1,      0,      0   },
    [NATURE_IMPISH]  = {    0,     +1,      0,     -1,      0   },
    [NATURE_LAX]     = {    0,     +1,      0,      0,     -1   },
    [NATURE_TIMID]   = {   -1,      0,     +1,      0,      0   },
    [NATURE_HASTY]   = {    0,     -1,     +1,      0,      0   },
    [NATURE_SERIOUS] = {    0,      0,      0,      0,      0   },
    [NATURE_JOLLY]   = {    0,      0,     +1,     -1,      0   },
    [NATURE_NAIVE]   = {    0,      0,     +1,      0,     -1   },
    [NATURE_MODEST]  = {   -1,      0,      0,     +1,      0   },
    [NATURE_MILD]    = {    0,     -1,      0,     +1,      0   },
    [NATURE_QUIET]   = {    0,      0,     -1,     +1,      0   },
    [NATURE_BASHFUL] = {    0,      0,      0,      0,      0   },
    [NATURE_RASH]    = {    0,      0,      0,     +1,     -1   },
    [NATURE_CALM]    = {   -1,      0,      0,      0,     +1   },
    [NATURE_GENTLE]  = {    0,     -1,      0,      0,     +1   },
    [NATURE_SASSY]   = {    0,      0,     -1,      0,     +1   },
    [NATURE_CAREFUL] = {    0,      0,      0,     -1,     +1   },
    [NATURE_QUIRKY]  = {    0,      0,      0,      0,      0   },
};

static const u8 sNatureTextColors[][3] = {
    {0, 14, 10}, // Dark Grey - Neutral
    {0, 5, 10}, // Green - Up
    {0, 1, 10}, // Red - Down
};

static u8 GetColor(s8 natureMod){
    if (natureMod == 0)
        return 0;
    else if (natureMod > 0)
        return 1;
    else
        return 2;
}

void PrintSkillsPage(void){
    const s8 *natureMod = sNatureStatTable[GetNature(&sMonSummaryScreen->currentMon)];
    u16 curHpStr = GetNumberRightAlign63(sMonSummaryScreen->summary.curHpStrBuf);
    u16 atkStr = GetNumberRightAlign27(sMonSummaryScreen->summary.statValueStrBufs[PSS_STAT_ATK]);
    u16 defStr = GetNumberRightAlign27(sMonSummaryScreen->summary.statValueStrBufs[PSS_STAT_DEF]);
    u16 spAStr = GetNumberRightAlign27(sMonSummaryScreen->summary.statValueStrBufs[PSS_STAT_SPA]);
    u16 spDStr = GetNumberRightAlign27(sMonSummaryScreen->summary.statValueStrBufs[PSS_STAT_SPD]);
    u16 speStr = GetNumberRightAlign27(sMonSummaryScreen->summary.statValueStrBufs[PSS_STAT_SPE]);
    u16 expStr = GetNumberRightAlign63(sMonSummaryScreen->summary.expPointsStrBuf);
    u16 toNextLevel = GetNumberRightAlign63(sMonSummaryScreen->summary.expToNextLevelStrBuf);

    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[POKESUM_WIN_RIGHT_PANE], FONT_NORMAL, 14 + curHpStr, 4, sNatureTextColors[0], TEXT_SKIP_DRAW, sMonSummaryScreen->summary.curHpStrBuf);
    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[POKESUM_WIN_RIGHT_PANE], FONT_NORMAL, 50 + atkStr, 22, sNatureTextColors[GetColor(natureMod[STAT_ATK - 1])], TEXT_SKIP_DRAW, sMonSummaryScreen->summary.statValueStrBufs[PSS_STAT_ATK]);
    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[POKESUM_WIN_RIGHT_PANE], FONT_NORMAL, 50 + defStr, 35, sNatureTextColors[GetColor(natureMod[STAT_DEF - 1])], TEXT_SKIP_DRAW, sMonSummaryScreen->summary.statValueStrBufs[PSS_STAT_DEF]);
    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[POKESUM_WIN_RIGHT_PANE], FONT_NORMAL, 50 + spAStr, 48, sNatureTextColors[GetColor(natureMod[STAT_SPATK - 1])], TEXT_SKIP_DRAW, sMonSummaryScreen->summary.statValueStrBufs[PSS_STAT_SPA]);
    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[POKESUM_WIN_RIGHT_PANE], FONT_NORMAL, 50 + spDStr, 61, sNatureTextColors[GetColor(natureMod[STAT_SPDEF - 1])], TEXT_SKIP_DRAW, sMonSummaryScreen->summary.statValueStrBufs[PSS_STAT_SPD]);
    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[POKESUM_WIN_RIGHT_PANE], FONT_NORMAL, 50 + speStr, 74, sNatureTextColors[GetColor(natureMod[STAT_SPD - 1])], TEXT_SKIP_DRAW, sMonSummaryScreen->summary.statValueStrBufs[PSS_STAT_SPE]);
    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[POKESUM_WIN_RIGHT_PANE], FONT_NORMAL, 15 + expStr, 87, sNatureTextColors[0], TEXT_SKIP_DRAW, sMonSummaryScreen->summary.expPointsStrBuf);
    AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[POKESUM_WIN_RIGHT_PANE], FONT_NORMAL, 15 + toNextLevel, 100, sNatureTextColors[0], TEXT_SKIP_DRAW, sMonSummaryScreen->summary.expToNextLevelStrBuf);

    // Ugly...
    // Display IVs numerically, but I'm already using S-E format so will stick with it. This works.

    // ConvertIntToDecimalStringN(gStringVar1, GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP_IV, 0), STR_CONV_MODE_RIGHT_ALIGN, 2);
    // AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[POKESUM_WIN_RIGHT_PANE], FONT_NORMAL, 0xD, 4, sNatureTextColors[0], TEXT_SKIP_DRAW, gStringVar1);
    // ConvertIntToDecimalStringN(gStringVar1, GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_ATK_IV, 0), STR_CONV_MODE_RIGHT_ALIGN, 2);
    // AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[POKESUM_WIN_RIGHT_PANE], FONT_NORMAL, 0xD, 22, sNatureTextColors[GetColor(natureMod[STAT_ATK - 1])], TEXT_SKIP_DRAW, gStringVar1);
    // ConvertIntToDecimalStringN(gStringVar1, GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_DEF_IV, 0), STR_CONV_MODE_RIGHT_ALIGN, 2);
    // AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[POKESUM_WIN_RIGHT_PANE], FONT_NORMAL, 0xD, 35, sNatureTextColors[GetColor(natureMod[STAT_DEF - 1])], TEXT_SKIP_DRAW, gStringVar1);
    // ConvertIntToDecimalStringN(gStringVar1, GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPATK_IV, 0), STR_CONV_MODE_RIGHT_ALIGN, 2);
    // AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[POKESUM_WIN_RIGHT_PANE], FONT_NORMAL, 0xD, 48, sNatureTextColors[GetColor(natureMod[STAT_SPATK - 1])], TEXT_SKIP_DRAW, gStringVar1);
    // ConvertIntToDecimalStringN(gStringVar1, GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPDEF_IV, 0), STR_CONV_MODE_RIGHT_ALIGN, 2);
    // AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[POKESUM_WIN_RIGHT_PANE], FONT_NORMAL, 0xD, 61, sNatureTextColors[GetColor(natureMod[STAT_SPDEF - 1])], TEXT_SKIP_DRAW, gStringVar1);
    // ConvertIntToDecimalStringN(gStringVar1, GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPEED_IV, 0), STR_CONV_MODE_RIGHT_ALIGN, 2);
    // AddTextPrinterParameterized3(sMonSummaryScreen->windowIds[POKESUM_WIN_RIGHT_PANE], FONT_NORMAL, 0xD, 74, sNatureTextColors[GetColor(natureMod[STAT_SPD - 1])], TEXT_SKIP_DRAW, gStringVar1);
}