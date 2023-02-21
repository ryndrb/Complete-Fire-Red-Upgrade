.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_LAVENDER_MECHANT_1, 0x302
.equ FLAG_LAVENDER_MECHANT_2, 0x303

@@@@@@@@@@@@@@@@@@@@@@
@ Lavender Town Items Merchant
@@@@@@@@@@@@@@@@@@@@@@
EventScript_LavenderTownMerchant:
    textcolor 0x0
    lock
    faceplayer
    checkflag 0x23C
    if 0x1 _goto EventScript_LavenderTownMerchantSell
    msgbox 0x817F5B6 MSG_FACE
    end

EventScript_LavenderTownMerchantSell:
    checkflag FLAG_LAVENDER_MECHANT_1
    if 0x0 _call EventScript_PlayerRescuedFuji
    checkflag FLAG_LAVENDER_MECHANT_2
    if 0x0 _call EventScript_LavenderTownMerchantAdmit
    msgbox gText_LavenderTownMerchantSell MSG_KEEPOPEN
    pokemart EventScript_LavenderTownMerchantList
    msgbox gText_LavenderTownMerchantBye MSG_KEEPOPEN
    release
    end

EventScript_PlayerRescuedFuji:
    msgbox EventScript_LavenderTownMerchantFujiRescued MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_DoesntMatter
    setflag FLAG_LAVENDER_MECHANT_1
    goto EventScript_LavenderTownMerchantAdmit
    return

EventScript_LavenderTownMerchantAdmit:
    msgbox gText_LavenderTownMerchantAdmit MSG_KEEPOPEN
    setflag FLAG_LAVENDER_MECHANT_2
    return

EventScript_LavenderTownMerchantExclaim:
    .byte exclaim
    .byte end_m

.align 1
EventScript_LavenderTownMerchantList:
    .hword ITEM_ASSAULT_VEST
    .hword ITEM_DESTINY_KNOT
    .hword ITEM_EXPERT_BELT
    .hword ITEM_MACHO_BRACE
    .hword ITEM_RING_TARGET
    .hword ITEM_ROCKY_HELMET
    .hword ITEM_SAFETY_GOGGLES
    .hword ITEM_SCOPE_LENS
    .hword ITEM_TERRAIN_EXTENDER
    .hword ITEM_BLUNDER_POLICY
    .hword ITEM_ROOM_SERVICE
    .hword ITEM_EJECT_PACK
    .hword ITEM_HEAVY_DUTY_BOOTS
    .hword ITEM_UTILITY_UMBRELLA
    .hword ITEM_LUCKY_PUNCH
    .hword 0x0

EventScript_ThisFlagIsSet:
    return

EventScript_DoesntMatter:
    msgbox gText_DoesntMatter MSG_KEEPOPEN
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Pokemon Tower Lady Preventing Enter
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PokeTowerLady:
    textcolor 0x1
    lock
    faceplayer
    checkflag 0x4B3
    if SET _goto EventScript_CanEnterLady
    msgbox gText_PokeTowerLady MSG_KEEPOPEN
    msgbox gText_CheckWorthiness MSG_KEEPOPEN
    release
    end

EventScript_CanEnterLady:
    msgbox gText_PokeTowerLady MSG_FACE
    end

EventScript_PokeTowerLadyTile:
    lock
    checkflag 0x4B3
    if NOT_SET _goto EventScript_CanEnterPokeTower
    msgbox gText_PokeTowerLady MSG_KEEPOPEN
    release
    end

EventScript_CanEnterPokeTower:
    spriteface 0x2, DOWN
    spriteface PLAYER, UP
    msgbox gText_PokeTowerLady MSG_KEEPOPEN
    msgbox gText_CheckWorthiness MSG_KEEPOPEN
    applymovement PLAYER EventScript_MovePlayer
    waitmovement PLAYER
    release
    end

EventScript_MovePlayer:
    .byte walk_left
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Mr Fuji PokeTower | After Sabrina Now
@@@@@@@@@@@@@@@@@@@@@@
EventScript_MrFuji:
    lock
    faceplayer
    setvar 0x8004 0xE
    setvar 0x8005 0x2
    special 0x174
    setflag 0x34
    setflag 0x23C
    msgbox 0x817A529 MSG_KEEPOPEN
    closeonkeypress
    warp 0x8 0x2 0xFF 0x4 0x7
    waitstate
    release
    end
