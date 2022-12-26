.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ VAR_BRENDAN_ROUTE1_ENCOUNTER, 0x5013
.equ FLAG_BRENDAN_ROUTE1_ENCOUNTER, 0x300
.equ FLAG_EXP_SHARE, 0x906
.equ BRENDAN, 0x3

@@@@@@@@@@@@@@@@@@@@@@
@ Meet Brendan | Exp Share
@@@@@@@@@@@@@@@@@@@@@@
EvenntScript_Route1_Brendan1:
    textcolor 0x0
    lock
    showsprite BRENDAN
    applymovement PLAYER EventScript_PlayerNotice
    playsong 0x13C
    waitmovement 0x0
    msgbox gText_Oh MSG_NORMAL
    applymovement BRENDAN EventScript_BrendanMovement1
    waitmovement BRENDAN
    msgbox gText_HeyThere MSG_NORMAL
    giveitem ITEM_EXP_SHARE 0x1 MSG_OBTAIN
    msgbox gText_BrendanGaveExpShare MSG_KEEPOPEN
    msgbox gText_HeadingToOak MSG_KEEPOPEN
    closeonkeypress
    applymovement BRENDAN EventScript_BrendanMovement2
    waitmovement BRENDAN
    hidesprite BRENDAN
    goto EventScript_BrendanLeft
    end

EvenntScript_Route1_Brendan2:
    textcolor 0x0
    lock
    showsprite BRENDAN
    applymovement PLAYER EventScript_PlayerNotice
    playsong 0x13C
    waitmovement 0x0
    msgbox gText_Oh MSG_NORMAL
    applymovement BRENDAN EventScript_BrendanMovement3
    waitmovement BRENDAN
    msgbox gText_HeyThere MSG_NORMAL
    giveitem ITEM_EXP_SHARE 0x1 MSG_OBTAIN
    msgbox gText_BrendanGaveExpShare MSG_KEEPOPEN
    msgbox gText_HeadingToOak MSG_KEEPOPEN
    closeonkeypress
    applymovement BRENDAN EventScript_BrendanMovement4
    waitmovement BRENDAN
    hidesprite BRENDAN
    goto EventScript_BrendanLeft
    end

EventScript_BrendanLeft:
    setvar VAR_BRENDAN_ROUTE1_ENCOUNTER 0x1
    setflag FLAG_BRENDAN_ROUTE1_ENCOUNTER 
    setflag FLAG_EXP_SHARE
    fadedefaultbgm
    release
    end

EventScript_PlayerNotice:
    .byte say_question
    .byte end_m

EventScript_BrendanMovement1:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

EventScript_BrendanMovement2:
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

EventScript_BrendanMovement3:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

EventScript_BrendanMovement4:
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m
