.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ May Route 4 Battle
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route4_May:
    lock
    call UnknownNameBox
    msgbox gText_Route4_MaySpeaks1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    sound 0x15
    applymovement PLAYER Move_Route4_Player_1
    waitmovement PLAYER
    sound 0x9
    showsprite 0x9
    pause 30
    applymovement 0x9 Move_Route4_May_1
    applymovement PLAYER Move_Route4_Player_2
    waitmovement 0x9
    playsong 0x1A7
    call MayNameBox
    msgbox gText_Route4_MaySpeaks2 MSG_KEEPOPEN
    msgbox gText_Route4_MaySpeaks3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    sound 0x15
    applymovement 0x9 Move_Route4_May_2
    applymovement PLAYER Move_Route4_Player_3
    waitmovement 0x9
    call MayNameBox
    msgbox gText_Route4_MaySpeaks4 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x9 Move_Route4_May_3
    applymovement PLAYER Move_Route4_Player_4
    waitmovement 0x9
    call MayNameBox
    msgbox gText_Route4_MaySpeaks5 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    pause 30
    sound 0x15
    applymovement 0x9 Move_Route4_May_4
    applymovement PLAYER Move_Route4_Player_5
    waitmovement 0x9
    call MayNameBox
    msgbox gText_Route4_MaySpeaks7 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement PLAYER Move_Route4_Player_6
    waitmovement 0x9
    call MayNameBox
    msgbox gText_Route4_MaySpeaks8 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    spriteface 0x9, DOWN
    spriteface PLAYER, UP
    call MayNameBox
    msgbox gText_Route4_MaySpeaks9 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x9 Move_Route4_May_5
    applymovement PLAYER Move_Route4_Player_7
    waitmovement 0x9
    hidesprite 0x9
    setflag FLAG_MAY_ROUTE4_SPRITE
    setvar VAR_MAY_ENCOUNTER 0x3
    fadedefaultbgm
    release
    end

Move_Route4_Player_1:
    .byte exclaim
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Route4_May_1:
    .byte run_down
    .byte walk_down
    .byte end_m

Move_Route4_Player_2:
    .byte jump_down
    .byte pause_short
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Route4_Player_3:
    .byte exclaim
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Route4_May_2:
    .byte pause_long
    .byte pause_long
    .byte walk_left
    .byte walk_down
    .byte end_m

Move_Route4_May_3:
    .byte walk_right_onspot_fastest
    .byte end_m

Move_Route4_Player_4:
    .byte walk_left_onspot_fastest
    .byte end_m
    
Move_Route4_May_4:
    .byte exclaim
    .byte pause_long
    .byte walk_up
    .byte walk_right
    .byte end_m

Move_Route4_Player_5:
    .byte pause_long
    .byte say_question
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Route4_Player_6:
    .byte say_question
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte end_m

Move_Route4_May_5:
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

Move_Route4_Player_7:
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Girl in water
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GirlInWater:
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
