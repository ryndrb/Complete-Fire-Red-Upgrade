#include "defines.h"
#include "defines_battle.h"
#include "../include/dynamic_placeholder_text_util.h"
#include "../include/event_object_movement.h"
#include "../include/field_effect_helpers.h"
#include "../include/field_player_avatar.h"
#include "../include/link.h"
#include "../include/random.h"
#include "../include/sprite.h"
#include "../include/trainer_pokemon_sprites.h"
#include "../include/constants/character_customization.h"
#include "../include/constants/event_object_movement_constants.h"
#include "../include/constants/event_objects.h"
#include "../include/constants/trainers.h"

#include "../include/new/character_customization.h"
#include "../include/new/follow_me.h"
#include "../include/new/frontier.h"
#include "../include/new/multi.h"
#include "../include/new/util.h"

/*
character_customization.c
	functions for altering the player's sprite based on the current sprite/palette selections

tables to edit:
	gOverworldTableSwitcher
	sPlayerAvatarGfxIds

*/

#ifdef UNBOUND
//extern const u16 MalePlayer_Trainer_Outfit_RedPal[];
extern const u16 MalePlayer_Trainer_Outfit_BlackPal[];
extern const u16 MalePlayer_Trainer_Outfit_BluePal[];
extern const u16 MalePlayer_Trainer_Outfit_GrayPal[];
extern const u16 MalePlayer_Trainer_Outfit_PurplePal[];
extern const u16 MalePlayer_Trainer_Outfit_YellowPal[];
extern const u16 MalePlayer_Trainer_Outfit_GreenPal[];
extern const u16 MalePlayer_Trainer_Outfit_TealPal[];
extern const u16 MalePlayer_Trainer_Outfit_BrownPal[];
extern const u16 MalePlayer_Trainer_Outfit_OrangePal[];
extern const u16 MalePlayer_Trainer_Outfit_PinkPal[];

//extern const u16 MalePlayer_Trainer_Trim_GoldPal[];
extern const u16 MalePlayer_Trainer_Trim_BlackPal[];
extern const u16 MalePlayer_Trainer_Trim_BluePal[];
extern const u16 MalePlayer_Trainer_Trim_BrownPal[];
extern const u16 MalePlayer_Trainer_Trim_BrownOrangePal[];
extern const u16 MalePlayer_Trainer_Trim_GreenPal[];
extern const u16 MalePlayer_Trainer_Trim_LightBluePal[];
extern const u16 MalePlayer_Trainer_Trim_LightGreenPal[];
extern const u16 MalePlayer_Trainer_Trim_LightPinkPal[];
extern const u16 MalePlayer_Trainer_Trim_LightRedPal[];
extern const u16 MalePlayer_Trainer_Trim_OrangePal[];
extern const u16 MalePlayer_Trainer_Trim_PinkPal[];
extern const u16 MalePlayer_Trainer_Trim_PurplePal[];
extern const u16 MalePlayer_Trainer_Trim_Purple2Pal[];
extern const u16 MalePlayer_Trainer_Trim_RedPal[];
extern const u16 MalePlayer_Trainer_Trim_TealPal[];
extern const u16 MalePlayer_Trainer_Trim_WhitePal[];
extern const u16 MalePlayer_Trainer_Trim_YellowPal[];

//extern const u16 MalePlayer_Trainer_Hair_BrownPal[];
extern const u16 MalePlayer_Trainer_Hair_BlondePal[];
extern const u16 MalePlayer_Trainer_Hair_LBlondePal[];
extern const u16 MalePlayer_Trainer_Hair_BlackPal[];
extern const u16 MalePlayer_Trainer_Hair_RedPal[];
extern const u16 MalePlayer_Trainer_Hair_GreenPal[];
extern const u16 MalePlayer_Trainer_Hair_PurplePal[];
extern const u16 MalePlayer_Trainer_Hair_BluePal[];
extern const u16 MalePlayer_Trainer_Hair_TealPal[];
extern const u16 MalePlayer_Trainer_Hair_PinkPal[];
extern const u16 MalePlayer_Trainer_Hair_SilverPal[];
extern const u16 MalePlayer_Trainer_Hair_GreyPal[];
extern const u16 MalePlayer_Trainer_Hair_WhitePal[];
extern const u16 MalePlayer_Trainer_Hair_OrangePal[];
extern const u16 MalePlayer_Trainer_Hair_LightBrownPal[];
extern const u16 MalePlayer_Trainer_Hair_DarkBrownPal[];

//extern const u16 MalePlayer_Trainer_Skin_LightPal[];
extern const u16 MalePlayer_Trainer_Skin_LBrownPal[];
extern const u16 MalePlayer_Trainer_Skin_BrownPal[];
extern const u16 MalePlayer_Trainer_Skin_DarkBrownPal[];
extern const u16 MalePlayer_Trainer_Skin_YellowPal[];

//extern const u16 MalePlayer_Champion_RedPal[];
extern const u16 MalePlayer_Champion_RedPal[];
extern const u16 MalePlayer_Champion_BluePal[];
extern const u16 MalePlayer_Champion_TealPal[];
extern const u16 MalePlayer_Champion_LimePal[];
extern const u16 MalePlayer_Champion_GreenPal[];
extern const u16 MalePlayer_Champion_YellowPal[];
extern const u16 MalePlayer_Champion_BlackPal[];
extern const u16 MalePlayer_Champion_GrayPal[];
extern const u16 MalePlayer_Champion_WhitePal[];
extern const u16 MalePlayer_Champion_PurplePal[];
extern const u16 MalePlayer_Champion_PinkPal[];
extern const u16 MalePlayer_Champion_BrownPal[];
extern const u16 MalePlayer_Champion_OrangePal[];

//extern const u16 MalePlayer_Champion_Trim_LightOrangePal[];
extern const u16 MalePlayer_Champion_Trim_RedPal[];
extern const u16 MalePlayer_Champion_Trim_BluePal[];
extern const u16 MalePlayer_Champion_Trim_TealPal[];
extern const u16 MalePlayer_Champion_Trim_LimePal[];
extern const u16 MalePlayer_Champion_Trim_GreenPal[];
extern const u16 MalePlayer_Champion_Trim_YellowPal[];
extern const u16 MalePlayer_Champion_Trim_BlackPal[];
extern const u16 MalePlayer_Champion_Trim_GrayPal[];
extern const u16 MalePlayer_Champion_Trim_WhitePal[];
extern const u16 MalePlayer_Champion_Trim_PurplePal[];
extern const u16 MalePlayer_Champion_Trim_PinkPal[];
extern const u16 MalePlayer_Champion_Trim_BrownPal[];
extern const u16 MalePlayer_Champion_Trim_OrangePal[];

//extern const u16 MalePlayer_Marlon_RedPal[];
extern const u16 MalePlayer_Marlon_BluePal[];
extern const u16 MalePlayer_Marlon_TealPal[];
extern const u16 MalePlayer_Marlon_GreenPal[];
extern const u16 MalePlayer_Marlon_LimePal[];
extern const u16 MalePlayer_Marlon_YellowPal[];
extern const u16 MalePlayer_Marlon_BlackPal[];
extern const u16 MalePlayer_Marlon_WhitePal[];
extern const u16 MalePlayer_Marlon_PurplePal[];
extern const u16 MalePlayer_Marlon_PinkPal[];
extern const u16 MalePlayer_Marlon_BrownPal[];
extern const u16 MalePlayer_Marlon_OrangePal[];
extern const u16 MalePlayer_Marlon_BrightRedPal[];
	
static const u16* sPlayerOutfitColours[] =
{
	NULL /*MalePlayer_Trainer_Outfit_RedPal*/, //Defaults are loaded from elsewhere
	MalePlayer_Trainer_Outfit_BlackPal,
	MalePlayer_Trainer_Outfit_BluePal,
	MalePlayer_Trainer_Outfit_TealPal,
	MalePlayer_Trainer_Outfit_GrayPal,
	MalePlayer_Trainer_Outfit_GreenPal,
	MalePlayer_Trainer_Outfit_YellowPal,
	MalePlayer_Trainer_Outfit_OrangePal,
	MalePlayer_Trainer_Outfit_BrownPal,
	MalePlayer_Trainer_Outfit_PurplePal,
	MalePlayer_Trainer_Outfit_PinkPal,
};

static const u16* sPlayerTrimColours[] =
{
	NULL /*MalePlayer_Trainer_Trim_GoldPal*/,
	MalePlayer_Trainer_Trim_RedPal,
	MalePlayer_Trainer_Trim_LightRedPal,
	MalePlayer_Trainer_Trim_OrangePal,
	MalePlayer_Trainer_Trim_YellowPal,
	MalePlayer_Trainer_Trim_GreenPal,
	MalePlayer_Trainer_Trim_LightGreenPal,
	MalePlayer_Trainer_Trim_BrownPal,
	MalePlayer_Trainer_Trim_BrownOrangePal,
	MalePlayer_Trainer_Trim_BlackPal,
	MalePlayer_Trainer_Trim_WhitePal,
	MalePlayer_Trainer_Trim_BluePal,
	MalePlayer_Trainer_Trim_TealPal,
	MalePlayer_Trainer_Trim_LightBluePal,
	MalePlayer_Trainer_Trim_PinkPal,
	MalePlayer_Trainer_Trim_LightPinkPal,
	MalePlayer_Trainer_Trim_Purple2Pal,
	MalePlayer_Trainer_Trim_PurplePal,
};

static const u16* sPlayerHairColours[] =
{
	NULL /*MalePlayer_Trainer_Hair_BrownPal*/,
	MalePlayer_Trainer_Hair_LBlondePal,
	MalePlayer_Trainer_Hair_BlondePal,
	MalePlayer_Trainer_Hair_BlackPal,
	MalePlayer_Trainer_Hair_RedPal,
	MalePlayer_Trainer_Hair_GreenPal,
	MalePlayer_Trainer_Hair_PurplePal,
	MalePlayer_Trainer_Hair_BluePal,
	MalePlayer_Trainer_Hair_PinkPal,
	MalePlayer_Trainer_Hair_SilverPal,
	MalePlayer_Trainer_Hair_GreyPal,
	MalePlayer_Trainer_Hair_WhitePal,
	MalePlayer_Trainer_Hair_TealPal,
	MalePlayer_Trainer_Hair_OrangePal,
	MalePlayer_Trainer_Hair_LightBrownPal,
	MalePlayer_Trainer_Hair_DarkBrownPal,
};

static const u16* sPlayerSkinColours[] =
{
    NULL /*MalePlayer_Trainer_Skin_LightPal*/,
    MalePlayer_Trainer_Skin_LBrownPal,
    MalePlayer_Trainer_Skin_BrownPal,
    MalePlayer_Trainer_Skin_DarkBrownPal,
    MalePlayer_Trainer_Skin_YellowPal,
};

static const u16* sPlayerChampionOutfitColours[] =
{
	NULL /*MalePlayer_Champion_ReddishOrangePal*/, //Defaults are loaded from elsewhere
	MalePlayer_Champion_RedPal,
	MalePlayer_Champion_BluePal,
	MalePlayer_Champion_TealPal,
	MalePlayer_Champion_LimePal,
	MalePlayer_Champion_GreenPal,
	MalePlayer_Champion_YellowPal,
	MalePlayer_Champion_BlackPal,
	MalePlayer_Champion_GrayPal,
	MalePlayer_Champion_WhitePal,
	MalePlayer_Champion_PinkPal,
	MalePlayer_Champion_PurplePal,
	MalePlayer_Champion_BrownPal,
	MalePlayer_Champion_OrangePal,
};

static const u16* sPlayerChampionTrimColours[] =
{
	NULL /*MalePlayer_Champion_Trim_LightOrangePal*/, //Defaults are loaded from elsewhere
	MalePlayer_Champion_Trim_RedPal,
	MalePlayer_Champion_Trim_BluePal,
	MalePlayer_Champion_Trim_TealPal,
	MalePlayer_Champion_Trim_LimePal,
	MalePlayer_Champion_Trim_GreenPal,
	MalePlayer_Champion_Trim_YellowPal,
	MalePlayer_Champion_Trim_BlackPal,
	MalePlayer_Champion_Trim_GrayPal,
	MalePlayer_Champion_Trim_WhitePal,
	MalePlayer_Champion_Trim_PinkPal,
	MalePlayer_Champion_Trim_PurplePal,
	MalePlayer_Champion_Trim_BrownPal,
	MalePlayer_Champion_Trim_OrangePal,
};

static const u16* sPlayerMarlonOutfitColours[] =
{
	NULL /*MalePlayer_Marlon_RedPal*/, //Defaults are loaded from elsewhere
	MalePlayer_Marlon_BluePal,
	MalePlayer_Marlon_TealPal,
	MalePlayer_Marlon_LimePal,
	MalePlayer_Marlon_GreenPal,
	MalePlayer_Marlon_YellowPal,
	MalePlayer_Marlon_BlackPal,
	MalePlayer_Marlon_WhitePal,
	MalePlayer_Marlon_PurplePal,
	MalePlayer_Marlon_PinkPal,
	MalePlayer_Marlon_BrownPal,
	MalePlayer_Marlon_OrangePal,
	MalePlayer_Marlon_BrightRedPal,
};
#endif

#ifdef EXISTING_OW_TABLE_ADDRESS
	#define gOverworldTableSwitcher ((struct EventObjectGraphicsInfo***) EXISTING_OW_TABLE_ADDRESS)
#elif defined UNBOUND //For Pokemon Unbound
	const struct EventObjectGraphicsInfo** const gOverworldTableSwitcher[] =
	{
		(NPCPtr*) 0x88110E0,
		(NPCPtr*) 0x88B2720,
		(NPCPtr*) 0x88B2B20,
	};

#else //Modify this

extern const u16 gEventObjectPic_NurseJoyPal[];
extern const u16 gEventObjectPic_OakPal[];
extern const u16 gEventObjectPic_ScientistPal[];
extern const u16 gEventObjectPic_NerdPal[];
extern const u16 gEventObjectPic_PolicePal[];
extern const u16 gEventObjectPic_SailorPal[];
extern const u16 gEventObjectPic_OldManPal[];
extern const u16 gEventObjectPic_GrannyPal[];
extern const u16 gEventObjectPic_ArcherPal[];
extern const u16 gEventObjectPic_ArianaPal[];
extern const u16 gEventObjectPic_ProtonPal[];
extern const u16 gEventObjectPic_KyogrePal[];
extern const u16 gEventObjectPic_GroudonPal[];
extern const u16 gEventObjectPic_RegirockPal[];
extern const u16 gEventObjectPic_RegicePal[];
extern const u16 gEventObjectPic_RegisteelPal[];
extern const u16 gEventObjectPic_StevenPal[];
extern const u16 gEventObjectPic_HeatranPal[];
extern const u16 gEventObjectPic_LatiasPal[];
extern const u16 gEventObjectPic_LatiosPal[];
extern const u16 gEventObjectPic_CresseliaPal[];
extern const u16 gEventObjectPic_DarkraiPal[];
extern const u16 gEventObjectPic_EusinePal[];
extern const u16 gEventObjectPic_JirachiPal[];
extern const u16 gEventObjectPic_PortalPal[];
extern const u16 gEventObjectPic_MomPal[];
extern const u16 gEventObjectPic_JessiePal[];
extern const u16 gEventObjectPic_JamesPal[];
extern const u16 gEventObjectPic_MeowthPal[];
extern const u16 gEventObjectPic_RoxannePal[];
extern const u16 gEventObjectPic_BrawlyPal[];
extern const u16 gEventObjectPic_WattsonPal[];
extern const u16 gEventObjectPic_FlanneryPal[];
extern const u16 gEventObjectPic_NormanPal[];
extern const u16 gEventObjectPic_WinonaPal[];
extern const u16 gEventObjectPic_TatePal[];
extern const u16 gEventObjectPic_LizaPal[];
extern const u16 gEventObjectPic_WallacePal[];
extern const u16 gEventObjectPic_AshPal[];

extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Archer;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Ariana;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Proton;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Kyogre;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Groudon;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Regirock;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Regice;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Registeel;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Steven;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Heatran;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Latias;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Latios;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Cresselia;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Darkrai;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Eusine;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Jirachi;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Portal;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Jessie;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_James;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Meowth;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Roxanne;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Brawly;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Wattson;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Flannery;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Norman;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Winona;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Tate;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Liza;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Wallace;
extern const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Ash;

static NPCPtr sOverworldTable2[] = {
	/*  0 */ &gEventObjectGraphicsInfo_Archer,
	/*  1 */ &gEventObjectGraphicsInfo_Ariana,
	/*  2 */ &gEventObjectGraphicsInfo_Proton,
	/*  3 */ &gEventObjectGraphicsInfo_Kyogre,
	/*  4 */ &gEventObjectGraphicsInfo_Groudon,
	/*  5 */ &gEventObjectGraphicsInfo_Regirock,
	/*  6 */ &gEventObjectGraphicsInfo_Regice,
	/*  7 */ &gEventObjectGraphicsInfo_Registeel,
	/*  8 */ &gEventObjectGraphicsInfo_Steven,
	/*  9 */ &gEventObjectGraphicsInfo_Heatran,
	/* 10 */ &gEventObjectGraphicsInfo_Latias,
	/* 11 */ &gEventObjectGraphicsInfo_Latios,
	/* 12 */ &gEventObjectGraphicsInfo_Cresselia,
	/* 13 */ &gEventObjectGraphicsInfo_Darkrai,
	/* 14 */ &gEventObjectGraphicsInfo_Eusine,
	/* 15 */ &gEventObjectGraphicsInfo_Jirachi,
	/* 16 */ &gEventObjectGraphicsInfo_Portal,
	/* 17 */ &gEventObjectGraphicsInfo_Jessie,
	/* 18 */ &gEventObjectGraphicsInfo_James,
	/* 19 */ &gEventObjectGraphicsInfo_Meowth,
	/* 20 */ &gEventObjectGraphicsInfo_Roxanne,
	/* 21 */ &gEventObjectGraphicsInfo_Brawly,
	/* 22 */ &gEventObjectGraphicsInfo_Wattson,
	/* 23 */ &gEventObjectGraphicsInfo_Flannery,
	/* 24 */ &gEventObjectGraphicsInfo_Norman,
	/* 25 */ &gEventObjectGraphicsInfo_Winona,
	/* 26 */ &gEventObjectGraphicsInfo_Tate,
	/* 27 */ &gEventObjectGraphicsInfo_Liza,
	/* 28 */ &gEventObjectGraphicsInfo_Wallace,
	/* 29 */ &gEventObjectGraphicsInfo_Ash,
};

// create 255 OW tables
const struct EventObjectGraphicsInfo** const gOverworldTableSwitcher[255] ={
		(NPCPtr*) 0x8EB1000,
		sOverworldTable2,
		(NPCPtr*) 0x0,
		// etc...
		// please note that this method makes compatability with OW Manager challenging
};

// Switcher from Stevebel repo
static const struct SpritePalette sObjectEventSpritePalettes12[] = {
	{gEventObjectPic_NurseJoyPal, 0x1201},
	{gEventObjectPic_OakPal, 0x1202},
	{gEventObjectPic_ArcherPal, 0x1203},
	{gEventObjectPic_ArianaPal, 0x1204},
	{gEventObjectPic_ProtonPal, 0x1205},
	{gEventObjectPic_ScientistPal, 0x1206},
	{gEventObjectPic_NerdPal, 0x1207},
	{gEventObjectPic_PolicePal, 0x1208},
	{gEventObjectPic_SailorPal, 0x1209},
	{gEventObjectPic_OldManPal, 0x120A},
	{gEventObjectPic_GrannyPal, 0x120B},
	{gEventObjectPic_KyogrePal, 0x120C},
	{gEventObjectPic_GroudonPal, 0x120D},
	{gEventObjectPic_RegirockPal, 0x120E},
	{gEventObjectPic_RegicePal, 0x120F},
	{gEventObjectPic_RegisteelPal, 0x1210},
	{gEventObjectPic_StevenPal, 0x1211},
	{gEventObjectPic_HeatranPal, 0x1212},
	{gEventObjectPic_LatiasPal, 0x1213},
	{gEventObjectPic_LatiosPal, 0x1214},
	{gEventObjectPic_CresseliaPal, 0x1215},
	{gEventObjectPic_DarkraiPal, 0x1216},
	{gEventObjectPic_EusinePal, 0x1217},
	{gEventObjectPic_JirachiPal, 0x1218},
	{gEventObjectPic_PortalPal, 0x1219},
	{gEventObjectPic_MomPal, 0x121A},
	{gEventObjectPic_JessiePal, 0x121B},
	{gEventObjectPic_JamesPal, 0x121C},
	{gEventObjectPic_MeowthPal, 0x121D},
	{gEventObjectPic_RoxannePal, 0x121E},
	{gEventObjectPic_BrawlyPal, 0x121F},
	{gEventObjectPic_WattsonPal, 0x1220},
	{gEventObjectPic_FlanneryPal, 0x1221},
	{gEventObjectPic_NormanPal, 0x1222},
	{gEventObjectPic_WinonaPal, 0x1223},
	{gEventObjectPic_TatePal, 0x1224},
	{gEventObjectPic_LizaPal, 0x1225},
	{gEventObjectPic_WallacePal, 0x1226},
	{gEventObjectPic_AshPal, 0x1227},
	{NULL, 0x11FF},
};

const struct SpritePalette* const gObjectEventSpritePalettesSwitcher[255] = {
	[0x11] = (const struct SpritePalette*) 0x8F15E70,
	[0x12] = sObjectEventSpritePalettes12,
};
#endif

struct PlayerGraphics
{
	u16 graphicsId;
	u8 stateFlag;
};

static const struct PlayerGraphics sPlayerAvatarGfxIds[][2] =
{
	[PLAYER_AVATAR_STATE_NORMAL] =     {{EVENT_OBJ_GFX_RED_NORMAL, PLAYER_AVATAR_FLAG_ON_FOOT},          {EVENT_OBJ_GFX_LEAF_NORMAL, PLAYER_AVATAR_FLAG_ON_FOOT}},
	[PLAYER_AVATAR_STATE_BIKE] =       {{EVENT_OBJ_GFX_RED_BIKE, PLAYER_AVATAR_FLAG_BIKE},               {EVENT_OBJ_GFX_LEAF_BIKE, PLAYER_AVATAR_FLAG_BIKE}},
	[PLAYER_AVATAR_STATE_SURFING] =    {{EVENT_OBJ_GFX_RED_SURFING, PLAYER_AVATAR_FLAG_SURFING},         {EVENT_OBJ_GFX_LEAF_SURFING, PLAYER_AVATAR_FLAG_SURFING}},
	[PLAYER_AVATAR_STATE_FIELD_MOVE] = {{EVENT_OBJ_GFX_RED_FIELD_MOVE, PLAYER_AVATAR_FLAG_FIELD_MOVE},   {EVENT_OBJ_GFX_LEAF_FIELD_MOVE, PLAYER_AVATAR_FLAG_FIELD_MOVE}},
	[PLAYER_AVATAR_STATE_FISHING] =    {{EVENT_OBJ_GFX_RED_FISHING, 0},                                  {EVENT_OBJ_GFX_LEAF_FISHING, 0}},
	[PLAYER_AVATAR_STATE_VS_SEEKER] =  {{EVENT_OBJ_GFX_RED_VS_SEEKER, 0},                                {EVENT_OBJ_GFX_LEAF_VS_SEEKER, 0}},
	[PLAYER_AVATAR_STATE_UNDERWATER] = {{EVENT_OBJ_GFX_RED_UNDERWATER, PLAYER_AVATAR_FLAG_UNDERWATER},   {EVENT_OBJ_GFX_LEAF_UNDERWATER, PLAYER_AVATAR_FLAG_UNDERWATER}},
};

//npc_get_type hack for character customization
//hook at 0805F2C8 via r1
NPCPtr GetEventObjectGraphicsInfo(u16 graphicsId)
{
	u16 newId;
	u8 tableId = (graphicsId >> 8) & 0xFF;	// upper byte
	u8 spriteId = graphicsId & 0xFF;		// lower byte

	//Check runtime changeable OWs
	if (tableId == 0xFF && spriteId <= 0xF)
	{
		//Runtime changeable
		newId = VarGet(VAR_RUNTIME_CHANGEABLE + spriteId);
		tableId = (newId >> 8) & 0xFF;	// upper byte
		spriteId = (newId & 0xFF);		// lower byte
	}
	else
	{
		switch (spriteId) {
			case EVENT_OBJ_GFX_RED_BIKE_VS_SEEKER:
			case EVENT_OBJ_GFX_LEAF_BIKE_VS_SEEKER:
				if (tableId == 0) //Actually the Vs. Seeker sprites
				{
					newId = VarGet(VAR_PLAYER_VS_SEEKER_ON_BIKE);
					if (newId != 0) //Actually set to something different
					{
						tableId = (newId >> 8) & 0xFF;	// upper byte
						spriteId = (newId & 0xFF);		// lower byte
					}
				}
				break;
		}

		#ifndef UNBOUND
		if (spriteId > 239 && tableId == 0)
		{
			newId = VarGetEventObjectGraphicsId(spriteId + 16);
			tableId = (newId >> 8) & 0xFF;	// upper byte
			spriteId = (newId & 0xFF);		// lower byte
		}
		#endif
	}

	NPCPtr spriteAddr;
	#ifndef EXISTING_OW_TABLE_ADDRESS
	if (tableId >= NELEMS(gOverworldTableSwitcher)
	|| gOverworldTableSwitcher[tableId] == 0)
		spriteAddr = gOverworldTableSwitcher[0][spriteId];
	else
	#endif
		spriteAddr = gOverworldTableSwitcher[tableId][spriteId];

	if (spriteAddr == NULL)
		spriteAddr = gOverworldTableSwitcher[0][EVENT_OBJ_GFX_LITTLE_BOY];	// first non-player sprite in first table default

	return spriteAddr;
};

NPCPtr GetEventObjectGraphicsInfoByEventObj(struct EventObject* eventObj)
{
	return GetEventObjectGraphicsInfo(GetEventObjectGraphicsId(eventObj));
}

static u16 GetCustomGraphicsIdByState(u8 state)
{
	u16 gfxId = 0;

	switch (state) {
		case PLAYER_AVATAR_STATE_NORMAL:
			gfxId = VarGet(VAR_PLAYER_WALKRUN);
			break;
		case PLAYER_AVATAR_STATE_BIKE:
			gfxId = VarGet(VAR_PLAYER_BIKING);
			break;
		case PLAYER_AVATAR_STATE_SURFING:
			gfxId = VarGet(VAR_PLAYER_SURFING);
			break;
		case PLAYER_AVATAR_STATE_FIELD_MOVE: //HM Use
			gfxId = VarGet(VAR_PLAYER_HM_USE);
			break;
		case PLAYER_AVATAR_STATE_VS_SEEKER:
			gfxId = VarGet(VAR_PLAYER_VS_SEEKER);
			break;
		case PLAYER_AVATAR_STATE_FISHING:
			gfxId = VarGet(VAR_PLAYER_FISHING);
			break;
		case PLAYER_AVATAR_STATE_UNDERWATER:
			gfxId = VarGet(VAR_PLAYER_UNDERWATER);
			break;
	}

	return gfxId;
}

u16 GetPlayerAvatarGraphicsIdByStateIdAndGender(u8 state, u8 gender)
{
	u16 graphicsId = GetCustomGraphicsIdByState(state);
	if (graphicsId != 0)
		return graphicsId;

	return sPlayerAvatarGfxIds[state][gender].graphicsId;
}

u16 GetPlayerAvatarGraphicsIdByStateId(u8 state)
{
	return GetPlayerAvatarGraphicsIdByStateIdAndGender(state, gPlayerAvatar->gender);
}

u8 GetPlayerAvatarStateTransitionByGraphicsId(u16 graphicsId, u8 gender)
{
    for (u8 state = 0; state < NELEMS(sPlayerAvatarGfxIds); ++state)
    {
		u16 customGraphicsId = GetCustomGraphicsIdByState(state);
		if (customGraphicsId == graphicsId)
			graphicsId = sPlayerAvatarGfxIds[state][gender].graphicsId;

        if (sPlayerAvatarGfxIds[state][gender].graphicsId == graphicsId)
            return sPlayerAvatarGfxIds[state][gender].stateFlag;
    }

    return PLAYER_AVATAR_FLAG_ON_FOOT;
}

u16 GetPlayerAvatarGraphicsIdByCurrentState(void)
{
	u8 state = 0;
	u8 gender = gPlayerAvatar->gender;
    u8 flags = gPlayerAvatar->flags;

    for (; state < NELEMS(sPlayerAvatarGfxIds); ++state)
    {
        if (sPlayerAvatarGfxIds[state][gender].stateFlag & flags)
		{
			u16 graphicsId = sPlayerAvatarGfxIds[state][gender].graphicsId;
			u16 customGraphicsId = GetCustomGraphicsIdByState(state);
			if (customGraphicsId != 0)
				graphicsId = customGraphicsId;

			return graphicsId;
		}
    }

    return sPlayerAvatarGfxIds[0][0].graphicsId;
}

u8 GetPlayerAvatarGenderByGraphicsId(u8 gfxId)
{
    for (u8 state = 0; state < NELEMS(sPlayerAvatarGfxIds); ++state)
    {
		for (u8 gender = 0; gender < NELEMS(sPlayerAvatarGfxIds[0]); ++gender)
		{
			if (sPlayerAvatarGfxIds[state][gender].graphicsId == gfxId)
				return gender;

			u16 customGraphicsId = GetCustomGraphicsIdByState(state);
			if (customGraphicsId != 0 && customGraphicsId == gfxId)
				return gSaveBlock2->playerGender;
		}
	}

	return MALE;
}

static void SetPlayerAvatarExtraStateTransition(u16 graphicsId, u8 b)
{
    u8 unk = GetPlayerAvatarStateTransitionByGraphicsId(graphicsId, gPlayerAvatar->gender);
	SetPlayerAvatarTransitionFlags(unk | b);
}

u16 GetEventObjectGraphicsId(struct EventObject* eventObj)
{
	u8 lowerByte = eventObj->graphicsIdLowerByte;
	u8 upperByte = eventObj->graphicsIdUpperByte;

	#ifndef EXISTING_OW_TABLE_ADDRESS
	if (upperByte >= NELEMS(gOverworldTableSwitcher)
	&& upperByte != 0xFF) //Dynamic OW table
		return lowerByte;
	#endif

	if (upperByte == 0xFF && lowerByte <= 0xF)
		return VarGet(VAR_RUNTIME_CHANGEABLE + lowerByte); //Runtime changeable

	return lowerByte | (upperByte << 8);
}

void SetPlayerAvatarEventObjectIdAndObjectId(u8 eventObjectId, u8 spriteId)
{
    gPlayerAvatar->eventObjectId = eventObjectId;
    gPlayerAvatar->spriteId = spriteId;
    gPlayerAvatar->gender = GetPlayerAvatarGenderByGraphicsId(GetEventObjectGraphicsId(&gEventObjects[eventObjectId]));
    SetPlayerAvatarExtraStateTransition(GetEventObjectGraphicsId(&gEventObjects[eventObjectId]), 0x20);
}

static u8 GetColorFromTextColorTableNew(u16 gfxId)
{
	#ifdef UNBOUND
	u8 gender = GetEventObjectGraphicsInfo(gfxId)->gender;
	return gender == MALE ? 0 : gender == FEMALE ? 1 : 2; //Blue, Red, Black
	#else
	return GetColorFromTextColorTable(gfxId);
	#endif
}

u8 ContextNpcGetTextColor(void)
{
	u16 gfxId;

	if (gSpecialVar_TextColor != 0xFF)
	{
		return gSpecialVar_TextColor;
	}
	else if (gSelectedEventObject == 0)
	{
		return 3;
	}
	else
	{
		gfxId = GetEventObjectGraphicsId(&gEventObjects[gSelectedEventObject]);

		#ifndef UNBOUND
		if (gfxId >= EVENT_OBJ_GFX_VAR_0 && gfxId <= 0xFF) //Vanilla dynamic id
			gfxId = VarGetEventObjectGraphicsId(gfxId - EVENT_OBJ_GFX_VAR_0);
		#endif

		return GetColorFromTextColorTableNew(gfxId);
	}
}

// load trainer card sprite based on variables
// 	hook at 810c374 via r2
u8 PlayerGenderToFrontTrainerPicId(u8 gender, bool8 modify)
{
	if (modify != TRUE)
		return gender;

	u16 trainerId = VarGet(VAR_TRAINERCARD_MALE + gender);
	if (trainerId == 0)
		trainerId = TRAINER_PIC_PLAYER_M + gender;

	return trainerId;
};

void InitPlayerAvatar(s16 x, s16 y, u8 direction, u8 gender)
{
	u8 eventObjectId;
	struct EventObject* eventObject;
	struct EventObjectTemplate playerEventObjTemplate = {0};
	u16 graphicsId = GetPlayerAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_NORMAL, gender);

	playerEventObjTemplate.localId = EVENT_OBJ_ID_PLAYER;
	playerEventObjTemplate.graphicsIdLowerByte = graphicsId & 0xFF;
	playerEventObjTemplate.graphicsIdUpperByte = graphicsId >> 8;
	playerEventObjTemplate.x = x - 7;
	playerEventObjTemplate.y = y - 7;
	playerEventObjTemplate.movementType = MOVEMENT_TYPE_PLAYER;

	eventObjectId = SpawnSpecialEventObject(&playerEventObjTemplate);
	eventObject = &gEventObjects[eventObjectId];
	eventObject->isPlayer = 1;
	eventObject->warpArrowSpriteId = CreateWarpArrowSprite();
	EventObjectTurn(eventObject, direction);
	ClearPlayerAvatarInfo();

	gPlayerAvatar->runningState = NOT_MOVING;
	gPlayerAvatar->tileTransitionState = T_NOT_MOVING;
	gPlayerAvatar->eventObjectId = eventObjectId;
	gPlayerAvatar->spriteId = eventObject->spriteId;
	gPlayerAvatar->gender = gender;
	SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_FIELD_MOVE | PLAYER_AVATAR_FLAG_ON_FOOT);
	CreateFollowerAvatar();
}

void PlayerHandleDrawTrainerPic(void)
{
	s16 xPos, yPos;
	u32 trainerPicId = GetBackspriteId();

	if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
	{
		if ((GetBattlerPosition(gActiveBattler) & BIT_FLANK) != B_FLANK_LEFT) // Second mon, on the right.
			xPos = 90;
		else // First mon, on the left.
			xPos = 32;

		yPos = (8 - gTrainerBackPicCoords[trainerPicId].coords) * 4 + 80;
	}

	else
	{
		xPos = 80;
		yPos = (8 - gTrainerBackPicCoords[trainerPicId].coords) * 4 + 80;
	}

	LoadTrainerBackPal(trainerPicId, gActiveBattler);
	SetMultiuseSpriteTemplateToTrainerBack(trainerPicId, GetBattlerPosition(gActiveBattler));
	gBattlerSpriteIds[gActiveBattler] = CreateSprite(&gMultiuseSpriteTemplate[0], xPos, yPos, GetBattlerSpriteSubpriority(gActiveBattler));

	if (IS_DOUBLE_BATTLE)
		gSprites[gBattlerSpriteIds[gActiveBattler]].oam.priority = 0; //So it appears above enemy healthbars

	gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = gActiveBattler;
	gSprites[gBattlerSpriteIds[gActiveBattler]].pos2.x = 240;
	gSprites[gBattlerSpriteIds[gActiveBattler]].data[0] = -3; //-2; //Speed scrolling in
	gSprites[gBattlerSpriteIds[gActiveBattler]].callback = SpriteCB_TrainerSlideIn; //sub_805D7AC in Emerald

	gBattlerControllerFuncs[gActiveBattler] = Player_CompleteOnBattlerSpriteCallbackDummy;
}

void PlayerHandleTrainerSlide(void)
{
	u32 trainerPicId = GetBackspriteId();

	LoadTrainerBackPal(trainerPicId, gActiveBattler);
	SetMultiuseSpriteTemplateToTrainerBack(trainerPicId, GetBattlerPosition(gActiveBattler));
	gBattlerSpriteIds[gActiveBattler] = CreateSprite(&gMultiuseSpriteTemplate[0], 80, (8 - gTrainerBackPicCoords[trainerPicId].coords) * 4 + 80, 30);

	if (IS_DOUBLE_BATTLE)
		gSprites[gBattlerSpriteIds[gActiveBattler]].oam.priority = 0;

	gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = gActiveBattler;
	gSprites[gBattlerSpriteIds[gActiveBattler]].pos2.x = -96;
	gSprites[gBattlerSpriteIds[gActiveBattler]].data[0] = 2;
	gSprites[gBattlerSpriteIds[gActiveBattler]].callback = SpriteCB_TrainerSlideIn;

	gBattlerControllerFuncs[gActiveBattler] = Player_CompleteOnBattlerSpriteCallbackDummy2;
}

u16 GetBackspriteId(void)
{
	u16 trainerPicId;

	if (gBattleTypeFlags & BATTLE_TYPE_LINK)
	{
		if ((gLinkPlayers[GetMultiplayerId()].version & 0xFF) == VERSION_FIRE_RED
		|| (gLinkPlayers[GetMultiplayerId()].version & 0xFF) == VERSION_LEAF_GREEN)
			trainerPicId = gLinkPlayers[GetMultiplayerId()].gender;
		else
			trainerPicId = gLinkPlayers[GetMultiplayerId()].gender + BACK_PIC_BRENDAN;
	}
	else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gActiveBattler == 2)
	{
		trainerPicId = LoadPartnerBackspriteIndex();
	}
	else if (IsAIControlledBattle())
	{
		trainerPicId = LoadPartnerBackspriteIndex(); //The trainer's backsprite for the Battle Sands is stored in the multi partner var
	}
	else
	{
		if (VarGet(VAR_BACKSPRITE_SWITCH))
			trainerPicId = VarGet(VAR_BACKSPRITE_SWITCH);
		else
			trainerPicId = gSaveBlock2->playerGender;
	}

	return trainerPicId;
}

#ifdef UNBOUND
bool8 IsPaletteTagAffectedByCharacterCustomization(u16 tag)
{
	switch (tag)
	{
		case EVENT_OBJ_PAL_TAG_DEFAULT:
		case EVENT_OBJ_PAL_TAG_MOM:
		case EVENT_OBJ_PAL_TAG_AROS:
		case EVENT_OBJ_PAL_TAG_RED_PLAYER:
		case EVENT_OBJ_PAL_TAG_LEAF_PLAYER:
		case EVENT_OBJ_PAL_TAG_ETHAN_PLAYER:
		case EVENT_OBJ_PAL_TAG_LYRA_PLAYER:
		case EVENT_OBJ_PAL_TAG_LUCAS_PLAYER:
		case EVENT_OBJ_PAL_TAG_DAWN_PLAYER:
		case EVENT_OBJ_PAL_TAG_SHADOW_GRUNT_PLAYER:
		case EVENT_OBJ_PAL_TAG_MARLON_PLAYER:
		case EVENT_OBJ_PAL_TAG_PLAYER_CHAMPION:
			return TRUE;
		default:
			return FALSE;
	}
}

static bool8 IsPaletteTagAffectedBySkinCharacterCustomization(unusedArg u16 tag)
{
	return tag != EVENT_OBJ_PAL_TAG_MARLON_PLAYER;
}

static bool8 IsPaletteTagAffectedByHairCharacterCustomization(u16 tag)
{
	return tag != EVENT_OBJ_PAL_TAG_AROS
		&& tag != EVENT_OBJ_PAL_TAG_MARLON_PLAYER;
}

static u8 GetOutfitStyleByEventObjTag(u16 tag)
{
	switch (tag)
	{
		case EVENT_OBJ_PAL_TAG_DEFAULT:
			return OUTFIT_STYLE_DEFAULT;
		case EVENT_OBJ_PAL_TAG_PLAYER_CHAMPION:
			return OUTFIT_STYLE_CHAMPION;
		case EVENT_OBJ_PAL_TAG_MARLON_PLAYER:
			return OUTFIT_STYLE_MARLON;
		default:
			return OUTFIT_STYLE_NONE;
	}
}

#define SKIN_TONE_OFFSET 1
#define HAIR_COLOUR_OFFSET 4
#define OUTFIT_OFFSET 7
#define DEFAULT_TRIM_OFFSET (OUTFIT_OFFSET + 2)
static void ChangePlayerPaletteByPaletteAndOffset(u16 paletteOffset, bool8 changeSkin, bool8 changeHair, u8 outfitStyle)
{
	u16 skinTone = VarGet(VAR_PLAYER_SKIN_TONE);
	u16 hairColour = VarGet(VAR_PLAYER_HAIR_COLOUR);

	if (changeSkin && skinTone > 0 && skinTone < NELEMS(sPlayerSkinColours))
	{
		u16 skinOffset = paletteOffset + SKIN_TONE_OFFSET;
		CpuCopy16(sPlayerSkinColours[skinTone] + SKIN_TONE_OFFSET, gPlttBufferUnfaded + skinOffset, 3 * sizeof(u16));
		CpuCopy16(sPlayerSkinColours[skinTone] + SKIN_TONE_OFFSET, gPlttBufferFaded + skinOffset, 3 * sizeof(u16));
	}

	if (changeHair && hairColour > 0 && hairColour < NELEMS(sPlayerHairColours))
	{
		u16 hairOffset = paletteOffset + HAIR_COLOUR_OFFSET;
		CpuCopy16(sPlayerHairColours[hairColour] + HAIR_COLOUR_OFFSET, gPlttBufferUnfaded + hairOffset, 3 * sizeof(u16));
		CpuCopy16(sPlayerHairColours[hairColour] + HAIR_COLOUR_OFFSET, gPlttBufferFaded + hairOffset, 3 * sizeof(u16));
	}

	if (outfitStyle != OUTFIT_STYLE_NONE)
	{
		const u16* const* outfitPals;
		const u16* const* trimPals;
		u16 outfitColour, trimColour;
		u32 outfitPalCount, trimPalCount, copyAmount;
		trimColour = 0;

		if (outfitStyle == OUTFIT_STYLE_CHAMPION)
		{
			outfitColour = VarGet(VAR_PLAYER_CHAMPION_OUTFIT_COLOUR);
			trimColour = VarGet(VAR_PLAYER_CHAMPION_TRIM_COLOUR);
			outfitPals = sPlayerChampionOutfitColours;
			outfitPalCount = NELEMS(sPlayerChampionOutfitColours);
			trimPals = sPlayerChampionTrimColours;
			trimPalCount = NELEMS(sPlayerChampionTrimColours);
			copyAmount = 3;
		}
		else if (outfitStyle == OUTFIT_STYLE_MARLON)
		{
			outfitColour = VarGet(VAR_PLAYER_MARLON_OUTFIT_COLOUR);
			outfitPals = sPlayerMarlonOutfitColours;
			outfitPalCount = NELEMS(sPlayerMarlonOutfitColours);
			copyAmount = 3;
		}
		else
		{
			//Default outfit
			outfitColour = VarGet(VAR_PLAYER_OUTFIT_COLOUR);
			trimColour = VarGet(VAR_PLAYER_TRIM_COLOUR);
			outfitPals = sPlayerOutfitColours;
			outfitPalCount = NELEMS(sPlayerOutfitColours);
			trimPals = sPlayerTrimColours;
			trimPalCount = NELEMS(sPlayerTrimColours);
			copyAmount = 2;
		}

		if (outfitColour > 0 && outfitColour < outfitPalCount)
		{
			u16 outfitOffset = paletteOffset + OUTFIT_OFFSET;
			CpuCopy16(outfitPals[outfitColour] + OUTFIT_OFFSET, gPlttBufferUnfaded + outfitOffset, copyAmount * sizeof(u16));
			CpuCopy16(outfitPals[outfitColour] + OUTFIT_OFFSET, gPlttBufferFaded + outfitOffset, copyAmount * sizeof(u16));
		}

		if (trimColour > 0 && trimColour < trimPalCount)
		{
			u8 baseTrimOffset = OUTFIT_OFFSET + copyAmount;
			u16 trimOffset = paletteOffset + baseTrimOffset;
			CpuCopy16(trimPals[trimColour] + baseTrimOffset, gPlttBufferUnfaded + trimOffset, 2 * sizeof(u16));
			CpuCopy16(trimPals[trimColour] + baseTrimOffset, gPlttBufferFaded + trimOffset, 2 * sizeof(u16));
		}
	}
}
#endif

void ChangeEventObjPal(unusedArg u16 paletteOffset, unusedArg u16 palTag)
{
	#ifdef UNBOUND
	ChangePlayerPaletteByPaletteAndOffset(paletteOffset, IsPaletteTagAffectedBySkinCharacterCustomization(palTag),
	                                                     IsPaletteTagAffectedByHairCharacterCustomization(palTag),
	                                                     GetOutfitStyleByEventObjTag(palTag));
	#endif
}

void ChangeTrainerPicPal(unusedArg u16 paletteOffset, unusedArg u8 outfitStyle)
{
	#ifdef UNBOUND
	if (outfitStyle == OUTFIT_STYLE_MARLON)
		ChangePlayerPaletteByPaletteAndOffset(paletteOffset, FALSE, FALSE, outfitStyle); //Just outfit, no skin and hair
	else
		ChangePlayerPaletteByPaletteAndOffset(paletteOffset, TRUE, TRUE, outfitStyle);
	#endif
}

void ChangeTrainerBackPal(unusedArg u16 backPicId, unusedArg u8 palSot)
{
	#ifdef UNBOUND
	//Dynamically changes the palette of the player character in Unbound
	switch (backPicId)
	{
		case TRAINER_BACK_PIC_RED: //Player M
		case TRAINER_BACK_PIC_LEAF: //Player F
			ChangeTrainerPicPal(0x100 + palSot * 16, OUTFIT_STYLE_DEFAULT); //All colours
			break;
		case TRAINER_BACK_PIC_PLAYER_CHAMPION_M:
		case TRAINER_BACK_PIC_PLAYER_CHAMPION_F:
			ChangeTrainerPicPal(0x100 + palSot * 16, OUTFIT_STYLE_CHAMPION); //All colours
			break;
		case TRAINER_BACK_PIC_MARLON_PLAYER_M:
		case TRAINER_BACK_PIC_MARLON_PLAYER_F:
		case TRAINER_BACK_PIC_IVORY_PLAYER_M:
		case TRAINER_BACK_PIC_IVORY_PLAYER_F:
			ChangePlayerPaletteByPaletteAndOffset(0x100 + palSot * 16, TRUE, FALSE, OUTFIT_STYLE_MARLON); //Just skin and outfit - no hair
			break;
		case TRAINER_BACK_PIC_RED_PLAYER:
		case TRAINER_BACK_PIC_LEAF_PLAYER:
		case TRAINER_BACK_PIC_ETHAN_PLAYER:
		case TRAINER_BACK_PIC_LYRA_PLAYER:
		case TRAINER_BACK_PIC_LUCAS_PLAYER:
		case TRAINER_BACK_PIC_DAWN_PLAYER:
			ChangePlayerPaletteByPaletteAndOffset(0x100 + palSot * 16, TRUE, TRUE, OUTFIT_STYLE_NONE); //Just skin & hair
			break;
	}
	#endif
}

void LoadTrainerBackPal(u16 backPicId, u8 battlerId)
{
	DecompressTrainerBackPalette(backPicId, battlerId);
	ChangeTrainerBackPal(backPicId, battlerId);
}

const u8* GetTrainerSpritePal(u16 trainerPicId)
{
	return gTrainerFrontPicPaletteTable[trainerPicId].data;
}

#ifdef UNBOUND
static bool8 IsTrainerPicAffectedByCustomization(u16 trainerPicId)
{
	return trainerPicId == TRAINER_PIC_PLAYER_M
		|| trainerPicId == TRAINER_PIC_PLAYER_F
		|| trainerPicId == TRAINER_PIC_PLAYER_CHAMPION_M
		|| trainerPicId == TRAINER_PIC_PLAYER_CHAMPION_F
		|| trainerPicId == TRAINER_PIC_PLAYER_MARLON_M
		|| trainerPicId == TRAINER_PIC_PLAYER_MARLON_F
		|| trainerPicId == TRAINER_PIC_PLAYER_RED
		|| trainerPicId == TRAINER_PIC_PLAYER_LEAF
		|| trainerPicId == TRAINER_PIC_PLAYER_ETHAN
		|| trainerPicId == TRAINER_PIC_PLAYER_LYRA;
}

u8 GetOutfitStyleByTrainerPic(u16 trainerPicId)
{
	if (trainerPicId == TRAINER_PIC_PLAYER_CHAMPION_M
	|| trainerPicId == TRAINER_PIC_PLAYER_CHAMPION_F)
	{
		return OUTFIT_STYLE_CHAMPION;
	}
	else if (trainerPicId == TRAINER_PIC_PLAYER_M
		|| trainerPicId == TRAINER_PIC_PLAYER_F)
	{
		return OUTFIT_STYLE_DEFAULT;
	}
	else if (trainerPicId == TRAINER_PIC_PLAYER_MARLON_M
	|| trainerPicId == TRAINER_PIC_PLAYER_MARLON_F)
	{
		return OUTFIT_STYLE_MARLON;
	}

	return OUTFIT_STYLE_NONE;
}
#endif

void TryUpdateTrainerPicPalTrainerCard(u16 trainerPicId, u16 palOffset)
{
	LoadCompressedPalette(GetTrainerSpritePal(trainerPicId), palOffset * 16, 0x20);
	#ifdef UNBOUND
	if (IsTrainerPicAffectedByCustomization(trainerPicId))
	{
		u32 offset = palOffset * 16;
		ChangeTrainerPicPal(offset, GetOutfitStyleByTrainerPic(trainerPicId));
	}
	#endif
}

u16 CreateTrainerPicSprite(u16 species, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag)
{
    u16 spriteId = CreatePicSprite_HandleDeoxys(species, 0, 0, isFrontPic, x, y, paletteSlot, paletteTag, TRUE);
	#ifdef UNBOUND
	if (isFrontPic && IsTrainerPicAffectedByCustomization(species))
	{
		u32 offset = 0x100 + gSprites[spriteId].oam.paletteNum * 16;
		ChangeTrainerPicPal(offset, GetOutfitStyleByTrainerPic(species));
	}
	#endif
	return spriteId;
}

void TryModifyMugshotTrainerPicPal(unusedArg u16 trainerPicId, unusedArg u8 index)
{
	#ifdef UNBOUND
	if (IsTrainerPicAffectedByCustomization(trainerPicId)) //Is player sprite
	{
		if (index != 0xFF)
		{
			u32 offset = 0x100 + index * 16;
			ChangeTrainerPicPal(offset, GetOutfitStyleByTrainerPic(trainerPicId));
		}
	}
	#endif
}

void TryUpdateRegionMapIconPal(void)
{
	#ifdef UNBOUND
	u8 paletteSlot = IndexOfSpritePaletteTag(1);
	if (paletteSlot != 0xFF)
		ChangeEventObjPal(0x100 + paletteSlot * 16, EVENT_OBJ_PAL_TAG_DEFAULT);
	#endif
}
