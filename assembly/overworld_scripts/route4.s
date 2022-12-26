.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_BRENDAN_ROUTE4_ENCOUNTER, 0x304
.equ VAR_BRENDAN_ROUTE4_ENCOUNTER, 0x502B
.equ BRENDAN, 0x9

@@@@@@@@@@@@@@@@@@@@@@
@ Brendan Route 4 Battle
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route4_Brendan:
    textcolor 0x0
    lock
    showsprite 0x9
    msgbox gText_BrendanCallPlayer MSG_FACE
    playsong 0x13C
    spriteface PLAYER, DOWN
    applymovement BRENDAN EventScript_BrendanMoveTowardPlayer
    waitmovement BRENDAN
    msgbox gText_BrendanAskForBattle MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_PlayerDeclinedBattle
    trainerbattle1 0x1 0x3B 0x0 gText_BrendanIntroBattle gText_BrendanLostBattle EventScript_AfterWinningBattle
    end

EventScript_AfterWinningBattle:
    playsong 0x13C
    msgbox gText_PlayerWonBattle MSG_KEEPOPEN
    giveitem ITEM_MYSTIC_WATER 0x1 MSG_OBTAIN
    giveitem ITEM_CHARCOAL 0x1 MSG_OBTAIN
    giveitem ITEM_MIRACLE_SEED 0x1 MSG_OBTAIN
    msgbox gText_BrendanOnHisWay MSG_KEEPOPEN
    closeonkeypress
    call EventScript_BrendanLeft
    release
    end

EventScript_PlayerDeclinedBattle:
    msgbox gText_BrendanJest MSG_FACE
    pause 30
    applymovement BRENDAN EventScript_BrendanSmiles
    waitmovement BRENDAN
    msgbox gText_BrendanJestAfter MSG_KEEPOPEN
    closeonkeypress
    call EventScript_BrendanLeft
    release
    end

EventScript_BrendanLeft:
    applymovement PLAYER EventScript_PlayerMoveAside
    waitmovement PLAYER
    applymovement BRENDAN EventScript_GoIntoMtMoon
    waitmovement BRENDAN
    fadescreen 0x1
    hidesprite 0x9
    setflag FLAG_BRENDAN_ROUTE4_ENCOUNTER
    setvar VAR_BRENDAN_ROUTE4_ENCOUNTER 0x1
    fadescreen 0x0
    fadedefaultbgm
    return

EventScript_BrendanMoveTowardPlayer:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte walk_up
    .byte end_m

EventScript_BrendanSmiles:
    .byte say_smile
    .byte end_m

EventScript_PlayerMoveAside:
    .byte walk_right
    .byte walk_left_onspot_fastest
    .byte end_m

EventScript_GoIntoMtMoon:
    .byte walk_up
    .byte walk_up
    .byte end_m
