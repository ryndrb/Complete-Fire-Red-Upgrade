.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_ROOST, 0x0D4
.equ FLAG_LANCE_SPRITE_PEWTER, 0x30D

@@@@@@@@@@@@@@@@@@@@@@
@ Roost | Pewter City Repel Guy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PewterRoostGuy:
    textcolor 0x0
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
    textcolor 0x0
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

@@@@@@@@@@@@@@@@@@@@
@ Did you check Museam guy | Fix
@@@@@@@@@@@@@@@@@@@@
EventScript_0x16607E:
    textcolor 0x0
    lock
    faceplayer
    msgbox 0x817E53E MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto EventScript_0x8166136
    msgbox 0x817E589 MSG_KEEPOPEN
    closeonkeypress
    pause 0xA
    playsong 0x110 0x0
    compare PLAYERFACING 0x2
    if 0x1 _call EventScript_0x81660EE
    msgbox 0x817E5AC MSG_KEEPOPEN
    closeonkeypress
    pause 0xA
    applymovement 0x2 EventScript_0x816621C
    waitmovement 0x0
    fadedefault
    hidesprite 0x2
    clearflag 0x50
    release
    end

EventScript_0x8166136:
    msgbox 0x817E55C MSG_KEEPOPEN
    release
    end

EventScript_0x81660EE:
    applymovement 0x2 EventScript_0x816615C
    applymovement PLAYER EventScript_0x8166140
    waitmovement 0x0
    return

EventScript_0x816621C:
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

EventScript_0x816615C:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_up_onspot_fastest
    .byte end_m

EventScript_0x8166140:
    .byte walk_right
    .byte walk_right_onspot_fastest
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte 0x1B
    .byte walk_up_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@
@ Check Brock Guy | Fix
@@@@@@@@@@@@@@@@@@@@
EventScript_0x165B9D:
    textcolor 0x0
    lock
    faceplayer
    msgbox gText_0x817E67E MSG_KEEPOPEN
    closeonkeypress
    playsong 0x110 0x0
    fadedefault
    @hidesprite 0x5
    @clearflag 0x2E
    release
    end

EventScript_0x165D8E:
    lockall
    spriteface PLAYER, UP
    setvar 0x4001 0x0
    goto EventScript_0x165DBE

EventScript_0x165D9A:
    lockall
    spriteface PLAYER, UP
    setvar 0x4001 0x1
    goto EventScript_0x165DBE

EventScript_0x165DA6:
    lockall
    spriteface PLAYER, UP
    setvar 0x4001 0x2
    goto EventScript_0x165DBE

EventScript_0x165DBE:
    textcolor 0x0
    applymovement 0x5 EventScript_LookDown
    waitmovement 0x5
    msgbox gText_0x817E67E MSG_KEEPOPEN
    closeonkeypress
    playsong 0x110 0x0
    compare 0x4001 0x0
    if 0x1 _call Eventscript_PlayerNotAllowed
    compare 0x4001 0x1
    if 0x1 _call Eventscript_PlayerNotAllowed
    compare 0x4001 0x2
    if 0x1 _call Eventscript_PlayerNotAllowed
    fadedefault
    @hidesprite 0x5
    @clearflag 0x2E
    releaseall
    end

Eventscript_PlayerNotAllowed:
    applymovement PLAYER Eventscript_PlayerNotAllowedMove
    waitmovement 0x1
    return

Eventscript_PlayerNotAllowedMove:
    .byte walk_left
    .byte end_m

EventScript_LookDown:
    .byte walk_down_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Prof. Aide Dex Nav
@@@@@@@@@@@@@@@@@@@@@@
EventScript_0x1662A9:
    textcolor 0x0
    lock
    faceplayer
    setvar 0x4001 0x0
    call EventScrit_0x81662DE
    release
    end

EventScript_0x1662B7:
    lockall
    setvar 0x4001 0x1
    call EventScrit_0x81662DE
    releaseall
    end

EventScript_0x1662C4:
    lockall
    setvar 0x4001 0x2
    call EventScrit_0x81662DE
    releaseall
    end

EventScript_0x1662D1:
    lockall
    setvar 0x4001 0x3
    call EventScrit_0x81662DE
    releaseall
    end

EventScrit_0x81662DE:
    textcolor 0x0
    compare 0x4001 0x1
    if 0x1 _call 0x81663CA
    compare 0x4001 0x2
    if 0x1 _call 0x81663CA
    compare 0x4001 0x3
    if 0x1 _call 0x81663CA
    checksound
    sound 0x15
    applymovement 0x7 0x81A75DB
    waitmovement 0x0
    applymovement 0x7 0x81A75DD
    waitmovement 0x0
    msgbox 0x817E902 MSG_KEEPOPEN
    compare 0x4001 0x0
    if 0x1 _call 0x81663D5
    compare 0x4001 0x1
    if 0x1 _call 0x81663DA
    compare 0x4001 0x2
    if 0x1 _call 0x81663E6
    compare 0x4001 0x3
    if 0x1 _call 0x81663FC
    msgbox 0x817E90C MSG_KEEPOPEN
    textcolor 0x3
    fanfare 0x13E
    preparemsg gText_ReceivedDexNav
    waitmsg
    waitfanfare
    special 0x171
    signmsg
    msgbox gText_PressRightArrow MSG_KEEPOPEN
    normalmsg
    call 0x81A6675
    msgbox 0x817EA06 MSG_KEEPOPEN
    closeonkeypress
    compare 0x4001 0x0
    if 0x1 _call 0x8166412
    compare 0x4001 0x1
    if 0x1 _call 0x816641D
    compare 0x4001 0x2
    if 0x1 _call 0x8166428
    compare 0x4001 0x3
    if 0x1 _call 0x8166433
    pause 0x1E
    textcolor 0x3
    signmsg
    msgbox gText_MomLetter MSG_KEEPOPEN
    msgbox gText_PlayerFeelWarm MSG_KEEPOPEN
    applymovement PLAYER EventScript_PlayerSmile
    waitmovement 0x0
    closeonkeypress
    hidesprite 0x7
    setflag 0x91E
    setvar 0x406C 0x2
    return

EventScript_PlayerSmile:
    .byte say_smile
    .byte end_m
