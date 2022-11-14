.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_ROOST, 0x0D4
.equ FLAG_LANCE_SPRITE_PEWTER, 0x101

@@@@@@@@@@@@@@@@@@@@@@
@ Roost | Pewter City Repel Guy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PewterRoostGuy:
    lock
    faceplayer
    checkflag FLAG_OBTAIN_ROOST
    if 0x0 _goto EventScript_GiveRoost
    msgbox gText_DislikeBirds MSG_KEEPOPEN 
    release
    end

EventScript_GiveRoost:
    msgbox 0x817E602 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x8166263
    msgbox 0x817E644 MSG_KEEPOPEN
    applymovement 0x4 EventScript_RoostGuy1
    waitmovement 0x4
    pause 30
    applymovement 0x4 EventScript_RoostGuy2
    waitmovement 0x4
    pause 30
    applymovement 0x4 EventScript_RoostGuy2GoBack
    waitmovement 0x4
    msgbox gText_GiveRoost MSG_KEEPOPEN
    giveitem ITEM_TM51 0x1 MSG_OBTAIN
    msgbox gText_GiveRoost2 MSG_KEEPOPEN
    msgbox gText_GiveRoost3 MSG_KEEPOPEN
    setflag FLAG_OBTAIN_ROOST
    closeonkeypress
    release
    end

EventScript_RoostGuy1:
    .byte exclaim
    .byte end_m

EventScript_RoostGuy2:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte pause_short
    .byte jump_onspot_up
    .byte pause_short
    .byte jump_onspot_up
    .byte pause_short
    .byte jump_onspot_up
    .byte end_m

EventScript_RoostGuy2GoBack:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte look_down
    .byte end_m

@@@@@@@@@@@@@@@@@@@@
@ Mega Ring Lance | Defeat Surge
@@@@@@@@@@@@@@@@@@@@
EventScript_LanceMegaRing:
    lock
    faceplayer
    msgbox gText_LanceIntro1 MSG_KEEPOPEN
    closeonkeypress
    applymovement 0x6 EventScript_LanceMove
    waitmovement 0x6
    pause 90
    faceplayer
    msgbox gText_LanceGiveMegaRing MSG_KEEPOPEN
    giveitem ITEM_MEGA_RING 0x1 MSG_OBTAIN
    msgbox gText_MegaRingObtained MSG_FACE
    fadescreen 0x1
    pause 65
    hidesprite 0x6
    fadescreen 0x0
    setflag FLAG_LANCE_SPRITE_PEWTER
    release
    end

EventScript_LanceMove:
    .byte look_down
    .byte say_question
    .byte end_m
