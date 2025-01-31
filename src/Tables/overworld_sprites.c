#include "../defines.h"
#include "../../include/constants/event_objects.h"

/*
    Credits:
    OW Sprites: aveontrainer (it was a bit large so I had to re-scale), kalarie (pokecommunity post)
    Battle Sprites: GreenPHX, MrDollSteak (Pokecommunity post) and people on credits
*/

#define EVENT_OBJ_PAL_TAG_NONE 0x1102
#define gEventObjectBaseOam_16x16 ((const struct OamData*) 0x83A36F8)
#define gEventObjectBaseOam_16x32 ((const struct OamData*) 0x83A3710)
#define gEventObjectBaseOam_32x32 ((const struct OamData*) 0x83A3718)
#define gEventObjectBaseOam_64x64 ((const struct OamData*) 0x83A3720)
#define gEventObjectSpriteOamTables_16x16 ((const struct SubspriteTable*) 0x83A3748)
#define gEventObjectSpriteOamTables_16x32 ((const struct SubspriteTable*) 0x83A379C)
#define gEventObjectSpriteOamTables_32x32 ((const struct SubspriteTable*) 0x83A37F0)
#define gEventObjectSpriteOamTables_64x64 ((const struct SubspriteTable*) 0x83A38D0)
#define gEventObjectImageAnimTable_PlayerNormal ((const union AnimCmd* const*) 0x83A3470)
#define gEventObjectImageAnimTable_Standard ((const union AnimCmd* const*) 0x83A3368)
#define gEventObjectImageAnimTable_Surfing ((const union AnimCmd* const*) 0x83A3584)
#define gEventObjectImageAnimTable_FieldMove ((const union AnimCmd* const*) 0x83A3638)
#define gEventObjectImageAnimTable_Fishing ((const union AnimCmd* const*) 0x83A3668)
#define gEventObjectImageAnimTable_VsSeekerBike ((const union AnimCmd* const*) 0x83A3640)

extern const u8 gEventObjectPic_NurseJoyTiles[];
extern const u8 gEventObjectPic_OakTiles[];
extern const u8 gEventObjectPic_MomTiles[];
extern const u8 gEventObjectPic_AshTiles[];

extern const u8 gEventObjectPic_ArcherTiles[];
extern const u8 gEventObjectPic_ArianaTiles[];
extern const u8 gEventObjectPic_ProtonTiles[];
extern const u8 gEventObjectPic_JessieTiles[];
extern const u8 gEventObjectPic_JamesTiles[];
extern const u8 gEventObjectPic_MeowthTiles[];

extern const u8 gEventObjectPic_ScientistTiles[];
extern const u8 gEventObjectPic_NerdTiles[];
extern const u8 gEventObjectPic_PoliceTiles[];
extern const u8 gEventObjectPic_SailorTiles[];
extern const u8 gEventObjectPic_OldManTiles[];
extern const u8 gEventObjectPic_GrannyTiles[];

extern const u8 gEventObjectPic_KyogreTiles[];
extern const u8 gEventObjectPic_GroudonTiles[];
extern const u8 gEventObjectPic_RegirockTiles[];
extern const u8 gEventObjectPic_RegiceTiles[];
extern const u8 gEventObjectPic_RegisteelTiles[];
extern const u8 gEventObjectPic_HeatranTiles[];
extern const u8 gEventObjectPic_LatiasTiles[];
extern const u8 gEventObjectPic_LatiosTiles[];
extern const u8 gEventObjectPic_CresseliaTiles[];
extern const u8 gEventObjectPic_DarkraiTiles[];
extern const u8 gEventObjectPic_JirachiTiles[];
extern const u8 gEventObjectPic_PortalTiles[];

extern const u8 gEventObjectPic_StevenTiles[];
extern const u8 gEventObjectPic_EusineTiles[];
extern const u8 gEventObjectPic_RoxanneTiles[];
extern const u8 gEventObjectPic_BrawlyTiles[];
extern const u8 gEventObjectPic_WattsonTiles[];
extern const u8 gEventObjectPic_FlanneryTiles[];
extern const u8 gEventObjectPic_NormanTiles[];
extern const u8 gEventObjectPic_WinonaTiles[];
extern const u8 gEventObjectPic_TateTiles[];
extern const u8 gEventObjectPic_LizaTiles[];
extern const u8 gEventObjectPic_WallaceTiles[];

static const struct SpriteFrameImage gEventObjectPicTable_NurseJoy[] =
{
    overworld_frame(gEventObjectPic_NurseJoyTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_NurseJoyTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_NurseJoyTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_NurseJoyTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_NurseJoyTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_NurseJoyTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_NurseJoyTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_NurseJoyTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_NurseJoyTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_NurseJoyTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_NurseJoy =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1201,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_NurseJoy,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Oak[] =
{
    overworld_frame(gEventObjectPic_OakTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_OakTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_OakTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_OakTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_OakTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_OakTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_OakTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_OakTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_OakTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_OakTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Oak =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1202,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Oak,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Archer[] =
{
    overworld_frame(gEventObjectPic_ArcherTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_ArcherTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_ArcherTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_ArcherTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_ArcherTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_ArcherTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_ArcherTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_ArcherTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_ArcherTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_ArcherTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Archer =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1203,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Archer,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Ariana[] =
{
    overworld_frame(gEventObjectPic_ArianaTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_ArianaTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_ArianaTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_ArianaTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_ArianaTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_ArianaTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_ArianaTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_ArianaTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_ArianaTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_ArianaTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Ariana =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1204,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Ariana,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Proton[] =
{
    overworld_frame(gEventObjectPic_ProtonTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_ProtonTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_ProtonTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_ProtonTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_ProtonTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_ProtonTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_ProtonTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_ProtonTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_ProtonTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_ProtonTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Proton =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1205,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Proton,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Scientist[] =
{
    overworld_frame(gEventObjectPic_ScientistTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_ScientistTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_ScientistTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_ScientistTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_ScientistTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_ScientistTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_ScientistTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_ScientistTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_ScientistTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_ScientistTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Scientist =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1206,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Scientist,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Nerd[] =
{
    overworld_frame(gEventObjectPic_NerdTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_NerdTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_NerdTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_NerdTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_NerdTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_NerdTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_NerdTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_NerdTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_NerdTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_NerdTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Nerd =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1207,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Nerd,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Police[] =
{
    overworld_frame(gEventObjectPic_PoliceTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_PoliceTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_PoliceTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_PoliceTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_PoliceTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_PoliceTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_PoliceTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_PoliceTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_PoliceTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_PoliceTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Police =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1208,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Police,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Sailor[] =
{
    overworld_frame(gEventObjectPic_SailorTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_SailorTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_SailorTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_SailorTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_SailorTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_SailorTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_SailorTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_SailorTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_SailorTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_SailorTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Sailor =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1209,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Sailor,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_OldMan[] =
{
    overworld_frame(gEventObjectPic_OldManTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_OldManTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_OldManTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_OldManTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_OldManTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_OldManTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_OldManTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_OldManTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_OldManTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_OldManTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_OldMan =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x120A,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_OldMan,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Granny[] =
{
    overworld_frame(gEventObjectPic_GrannyTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_GrannyTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_GrannyTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_GrannyTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_GrannyTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_GrannyTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_GrannyTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_GrannyTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_GrannyTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_GrannyTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Granny =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x120B,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Granny,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Kyogre[] =
{
    overworld_frame(gEventObjectPic_KyogreTiles, 8, 8, 0),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Kyogre =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x120C,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (64 * 64) / 2,
    .width = 64,
    .height = 64,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_64x64,
    .subspriteTables = gEventObjectSpriteOamTables_64x64,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Kyogre,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Groudon[] =
{
    overworld_frame(gEventObjectPic_GroudonTiles, 8, 8, 0),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Groudon =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x120D,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (64 * 64) / 2,
    .width = 64,
    .height = 64,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_64x64,
    .subspriteTables = gEventObjectSpriteOamTables_64x64,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Groudon,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Regirock[] =
{
    overworld_frame(gEventObjectPic_RegirockTiles, 4, 4, 0),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Regirock =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x120E,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Regirock,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Regice[] =
{
    overworld_frame(gEventObjectPic_RegiceTiles, 4, 4, 0),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Regice =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x120F,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Regice,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Registeel[] =
{
    overworld_frame(gEventObjectPic_RegisteelTiles, 4, 4, 0),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Registeel =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1210,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Registeel,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Steven[] =
{
    overworld_frame(gEventObjectPic_StevenTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_StevenTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_StevenTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_StevenTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_StevenTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_StevenTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_StevenTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_StevenTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_StevenTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_StevenTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Steven =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1211,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Steven,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Heatran[] =
{
    overworld_frame(gEventObjectPic_HeatranTiles, 4, 4, 0),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Heatran =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1212,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Heatran,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Latias[] =
{
    overworld_frame(gEventObjectPic_LatiasTiles, 4, 4, 0),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Latias =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1213,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Latias,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Latios[] =
{
    overworld_frame(gEventObjectPic_LatiosTiles, 4, 4, 0),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Latios =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1214,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Latios,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Cresselia[] =
{
    overworld_frame(gEventObjectPic_CresseliaTiles, 4, 4, 0),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Cresselia =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1215,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Cresselia,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Darkrai[] =
{
    overworld_frame(gEventObjectPic_DarkraiTiles, 4, 4, 0),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Darkrai =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1216,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Darkrai,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Eusine[] =
{
    overworld_frame(gEventObjectPic_EusineTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_EusineTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_EusineTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_EusineTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_EusineTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_EusineTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_EusineTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_EusineTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_EusineTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_EusineTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Eusine =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1217,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Eusine,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Jirachi[] =
{
    overworld_frame(gEventObjectPic_JirachiTiles, 4, 4, 0),

};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Jirachi =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1218,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Jirachi,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Portal[] =
{
    overworld_frame(gEventObjectPic_PortalTiles, 4, 4, 0),
    overworld_frame(gEventObjectPic_PortalTiles, 4, 4, 1),
    overworld_frame(gEventObjectPic_PortalTiles, 4, 4, 2),
    overworld_frame(gEventObjectPic_PortalTiles, 4, 4, 3),
    overworld_frame(gEventObjectPic_PortalTiles, 4, 4, 4),
    overworld_frame(gEventObjectPic_PortalTiles, 4, 4, 5),
    overworld_frame(gEventObjectPic_PortalTiles, 4, 4, 6),
    overworld_frame(gEventObjectPic_PortalTiles, 4, 4, 7),
    overworld_frame(gEventObjectPic_PortalTiles, 4, 4, 8),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Portal =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1219,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Portal,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Mom[] =
{
    overworld_frame(gEventObjectPic_MomTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_MomTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_MomTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_MomTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_MomTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_MomTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_MomTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_MomTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_MomTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_MomTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Mom =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x121A,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Mom,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Jessie[] =
{
    overworld_frame(gEventObjectPic_JessieTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_JessieTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_JessieTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_JessieTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_JessieTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_JessieTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_JessieTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_JessieTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_JessieTiles, 2, 4, 8),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Jessie =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x121B,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Jessie,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_James[] =
{
    overworld_frame(gEventObjectPic_JamesTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_JamesTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_JamesTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_JamesTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_JamesTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_JamesTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_JamesTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_JamesTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_JamesTiles, 2, 4, 8),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_James =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x121C,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_James,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Meowth[] =
{
    overworld_frame(gEventObjectPic_MeowthTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_MeowthTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_MeowthTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_MeowthTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_MeowthTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_MeowthTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_MeowthTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_MeowthTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_MeowthTiles, 2, 4, 8),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Meowth =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x121D,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Meowth,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Roxanne[] =
{
    overworld_frame(gEventObjectPic_RoxanneTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_RoxanneTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_RoxanneTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_RoxanneTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_RoxanneTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_RoxanneTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_RoxanneTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_RoxanneTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_RoxanneTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_RoxanneTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Roxanne =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x121E,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Roxanne,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Brawly[] =
{
    overworld_frame(gEventObjectPic_BrawlyTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_BrawlyTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_BrawlyTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_BrawlyTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_BrawlyTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_BrawlyTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_BrawlyTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_BrawlyTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_BrawlyTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_BrawlyTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Brawly =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x121F,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Brawly,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Wattson[] =
{
    overworld_frame(gEventObjectPic_WattsonTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_WattsonTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_WattsonTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_WattsonTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_WattsonTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_WattsonTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_WattsonTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_WattsonTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_WattsonTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_WattsonTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Wattson =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1220,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Wattson,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Flannery[] =
{
    overworld_frame(gEventObjectPic_FlanneryTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_FlanneryTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_FlanneryTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_FlanneryTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_FlanneryTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_FlanneryTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_FlanneryTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_FlanneryTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_FlanneryTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_FlanneryTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Flannery =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1221,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Flannery,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Norman[] =
{
    overworld_frame(gEventObjectPic_NormanTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_NormanTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_NormanTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_NormanTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_NormanTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_NormanTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_NormanTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_NormanTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_NormanTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_NormanTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Norman =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1222,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Norman,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Winona[] =
{
    overworld_frame(gEventObjectPic_WinonaTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_WinonaTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_WinonaTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_WinonaTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_WinonaTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_WinonaTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_WinonaTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_WinonaTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_WinonaTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_WinonaTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Winona =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1223,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Winona,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Tate[] =
{
    overworld_frame(gEventObjectPic_TateTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_TateTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_TateTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_TateTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_TateTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_TateTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_TateTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_TateTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_TateTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_TateTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Tate =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1224,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Tate,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Liza[] =
{
    overworld_frame(gEventObjectPic_LizaTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_LizaTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_LizaTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_LizaTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_LizaTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_LizaTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_LizaTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_LizaTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_LizaTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_LizaTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Liza =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1225,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Liza,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Wallace[] =
{
    overworld_frame(gEventObjectPic_WallaceTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_WallaceTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_WallaceTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_WallaceTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_WallaceTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_WallaceTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_WallaceTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_WallaceTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_WallaceTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_WallaceTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Wallace =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1226,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Wallace,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static const struct SpriteFrameImage gEventObjectPicTable_Ash[] =
{
    overworld_frame(gEventObjectPic_AshTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_AshTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_AshTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_AshTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_AshTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_AshTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_AshTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_AshTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_AshTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_AshTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Ash =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1227,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Ash,
    .affineAnims = gDummySpriteAffineAnimTable,
};