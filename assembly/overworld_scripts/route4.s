.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_MAY_ROUTE4_SPRITE, 0x93C
.equ VAR_MAY_ROUTE4_ENCOUNTER, 0x502B

@@@@@@@@@@@@@@@@@@@@@@
@ May Route 4 Battle
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route4_May:
    lock
    textcolor RED
    playsong 0x1A7
    call UnknownNameBox
    msgbox gText_Route4_MaySpeaks1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement PLAYER EventScript_Route4_PlayerNoticeMay
    waitmovement PLAYER
    sound 0x9
    showsprite 0x9
    applymovement 0x9 EventScript_Route4_MayGetCloserToPlayer
    applymovement PLAYER EventScript_Route4_PlayerPushedByMay
    waitmovement 0x9
    call MayNameBox
    msgbox gText_Route4_MaySpeaks2 MSG_KEEPOPEN
    msgbox gText_Route4_MaySpeaks3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement PLAYER EventScript_Route4_PlayerSeeWhatMayPointed
    waitmovement PLAYER
    call MayNameBox
    msgbox gText_Route4_MaySpeaks4 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    pause 45
    spriteface 0x9, RIGHT
    spriteface PLAYER, RIGHT
    call MayNameBox
    msgbox gText_Route4_MaySpeaks5 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    spriteface 0x9, DOWN
    spriteface PLAYER, UP
    call MayNameBox
    msgbox gText_Route4_MaySpeaks6 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x9 EventScript_Route4_MayLeaving
    applymovement PLAYER EventScript_Route4_PlayerMoveAside
    waitmovement 0x9
    hidesprite 0x9
    setflag FLAG_MAY_ROUTE4_SPRITE
    setvar VAR_MAY_ROUTE4_ENCOUNTER 0x1
    fadedefaultbgm
    release
    end

EventScript_Route4_PlayerNoticeMay:
    .byte exclaim
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

EventScript_Route4_MayGetCloserToPlayer:
    .byte run_down
    .byte walk_down
    .byte end_m

EventScript_Route4_PlayerPushedByMay:
    .byte jump_down
    .byte pause_short
    .byte walk_up_onspot_fastest
    .byte end_m

EventScript_Route4_PlayerSeeWhatMayPointed:
    .byte exclaim
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

EventScript_Route4_MayLeaving:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_right
    .byte walk_down
    .byte walk_right
    .byte end_m

EventScript_Route4_PlayerMoveAside:
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Girl in water
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GirlInWater:
    textcolor RED
    msgbox gText_GirlInWater MSG_FACE
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Route 4 NameBox
@@@@@@@@@@@@@@@@@@@@@@
MayNameBox:
    setvar 0x8000 2
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

UnknownNameBox:
    setvar 0x8000 0
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
