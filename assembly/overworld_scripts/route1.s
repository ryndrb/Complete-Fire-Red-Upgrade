.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ BRENDAN_ROUTE1_ENCOUNTER, 0x300
.equ FLAG_CUSTOM_TRAINERS, 0x0AF
.equ FLAG_EXP_SHARE, 0x906

EvenntScript_Route1_Brendan1:
    lock
    setflag FLAG_CUSTOM_TRAINERS
    showsprite 0x3
    applymovement PLAYER EventScript_PlayerNotice
    waitmovement 0x0
    msgbox gText_Oh MSG_NORMAL
    applymovement 0x3 EventScript_BrendanMovement1
    waitmovement 0x3
    msgbox gText_HeyThere MSG_NORMAL
    giveitem ITEM_EXP_SHARE 0x1 MSG_OBTAIN
    msgbox gText_BrendanGaveExpShare MSG_KEEPOPEN
    msgbox gText_HeadingToOak MSG_KEEPOPEN
    closeonkeypress
    applymovement 0x3 EventScript_BrendanMovement2
    waitmovement 0x3
    hidesprite 0x3
    goto EventScript_BrendanLeft
    end

EvenntScript_Route1_Brendan2:
    lock
    showsprite 0x3
    applymovement PLAYER EventScript_PlayerNotice
    waitmovement 0x0
    msgbox gText_Oh MSG_NORMAL
    applymovement 0x3 EventScript_BrendanMovement3
    waitmovement 0x3
    msgbox gText_HeyThere MSG_NORMAL
    giveitem ITEM_EXP_SHARE 0x1 MSG_OBTAIN
    msgbox gText_BrendanGaveExpShare MSG_KEEPOPEN
    msgbox gText_HeadingToOak MSG_KEEPOPEN
    closeonkeypress
    applymovement 0x3 EventScript_BrendanMovement4
    waitmovement 0x3
    hidesprite 0x3
    goto EventScript_BrendanLeft
    end

EventScript_BrendanLeft:
    setvar 0x4010 0x1
    setflag BRENDAN_ROUTE1_ENCOUNTER 
    setflag FLAG_EXP_SHARE
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