#include "../include/bg.h"
#include "../include/event_data.h"
#include "../include/global.h"
#include "../include/menu.h"
#include "../include/menu_helpers.h"
#include "../include/new_menu_helpers.h"
#include "../include/string_util.h"
#include "../include/text.h"
#include "../include/text_window.h"
#include "../include/window.h"

#include "../include/gba/syscall.h"

void DrawNameBox(void);
void RemoveNameBox(void);

extern u8 sTimeWindowId;

// Text Colors
static const u8 sDarkTextColor[3]    = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_GREEN, TEXT_COLOR_LIGHT_GREY};

extern u8 gText_Name_Unknown[];

extern u8 gText_Name_Rival[];
extern u8 gText_Name_May[];
extern u8 gText_Name_Brendan[];
extern u8 gText_Name_ProfOak[];
extern u8 gText_Name_Mom[];
extern u8 gText_Name_Daisy[];
extern u8 gText_Name_Bill[];
extern u8 gText_Name_MrFuji[];
extern u8 gText_Name_Traynee[];
extern u8 gText_Name_Ivy[];
extern u8 gText_Name_Brock[];
extern u8 gText_Name_Misty[];
extern u8 gText_Name_LtSurge[];
extern u8 gText_Name_Erika[];
extern u8 gText_Name_Sabrina[];
extern u8 gText_Name_Koga[];
extern u8 gText_Name_Blaine[];
extern u8 gText_Name_Giovanni[];
extern u8 gText_Name_Lorelei[];
extern u8 gText_Name_Bruno[];
extern u8 gText_Name_Agatha[];
extern u8 gText_Name_Lance[];
extern u8 gText_Name_Proton[];
extern u8 gText_Name_Archer[];
extern u8 gText_Name_Ariana[];
extern u8 gText_Name_Steven[];
extern u8 gText_Name_Celio[];
extern u8 gText_Name_Eusine[];
extern u8 gText_Name_Jessie[];
extern u8 gText_Name_James[];
extern u8 gText_Name_Meowth[];
extern u8 gText_Name_Roxanne[];
extern u8 gText_Name_Brawly[];
extern u8 gText_Name_Wattson[];
extern u8 gText_Name_Flannery[];

// Add Character names here
u8* CharacterNames[] = {
    /*  0 */ gText_Name_Unknown,
    /*  1 */ gText_Name_Rival,
	/*  2 */ gText_Name_May,
    /*  3 */ gText_Name_Brendan,
    /*  4 */ gText_Name_ProfOak,
    /*  5 */ gText_Name_Mom,
    /*  6 */ gText_Name_Daisy,
    /*  7 */ gText_Name_Bill,
    /*  8 */ gText_Name_MrFuji,
    /*  9 */ gText_Name_Traynee,
    /* 10 */ gText_Name_Ivy,
    /* 11 */ gText_Name_Brock,
    /* 12 */ gText_Name_Misty,
    /* 13 */ gText_Name_LtSurge,
    /* 14 */ gText_Name_Erika,
    /* 15 */ gText_Name_Sabrina,
    /* 16 */ gText_Name_Koga,
    /* 17 */ gText_Name_Blaine,
    /* 18 */ gText_Name_Giovanni,
    /* 19 */ gText_Name_Lorelei,
    /* 20 */ gText_Name_Bruno,
    /* 21 */ gText_Name_Agatha,
    /* 22 */ gText_Name_Lance,
    /* 23 */ gText_Name_Proton,
    /* 24 */ gText_Name_Archer,
    /* 25 */ gText_Name_Ariana,
    /* 26 */ gText_Name_Steven,
    /* 27 */ gText_Name_Celio,
    /* 28 */ gText_Name_Eusine,
    /* 29 */ gText_Name_Jessie,
    /* 30 */ gText_Name_James,
    /* 31 */ gText_Name_Meowth,
    /* 32 */ gText_Name_Roxanne,
    /* 33 */ gText_Name_Brawly,
    /* 34 */ gText_Name_Wattson,
    /* 35 */ gText_Name_Flannery,
};

/*
    setvar 0x8000 @ Index in CharacterNames[]
    setvar 0x8001 @ LEFT or RIGHT
    callasm DrawNameBox
    msgbox ...
    callasm RemoveNameBox
*/
void DrawNameBox(void) {
    u8* name = CharacterNames[Var8000];
    u8 nameLen = StringLength(name);

    // 3 = Left, 4 = Right
    if(Var8001 == 3){
        struct WindowTemplate Left = SetWindowTemplateFields(0, 1, 11, nameLen, 2, 15, 0x008);
        if(Var8000 == 1){
            Left.width = StringLength(gSaveBlock1->rivalName);
        }
	    sTimeWindowId = AddWindow(&Left);
    }else if(Var8001 == 4){
        struct WindowTemplate Right = SetWindowTemplateFields(0, 19 + (10 - nameLen), 11, nameLen, 2, 15, 0x008);
        if(Var8000 == 1){
            Right.width = StringLength(gSaveBlock1->rivalName);
            Right.tilemapLeft = 19 + (10 - StringLength(gSaveBlock1->rivalName));
        }
        sTimeWindowId = AddWindow(&Right);
    }

	if (sTimeWindowId != 0xFF){
        DrawStdWindowFrame(sTimeWindowId, FALSE);
		PutWindowTilemap(sTimeWindowId);
		FillWindowPixelBuffer(sTimeWindowId, PIXEL_FILL(1));
	}

    if(Var8000 == 1){
        name = gSaveBlock1->rivalName;
    }

    AddTextPrinterParameterized3(sTimeWindowId, 2, nameLen, 0, sDarkTextColor, 0xFF, name);
	CopyWindowToVram(sTimeWindowId, COPYWIN_GFX);
}

void RemoveNameBox(void)
{
	if (sTimeWindowId != 0xFF){
		ClearStdWindowAndFrame(sTimeWindowId, TRUE);
		CopyWindowToVram(sTimeWindowId, COPYWIN_GFX);
		RemoveWindow(sTimeWindowId);
	}
}