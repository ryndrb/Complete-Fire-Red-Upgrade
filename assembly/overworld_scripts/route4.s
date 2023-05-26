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
    npcmsg gText_Route4_MaySpeaks1 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
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
    npcmsg gText_Route4_MaySpeaks2 MSG_KEEPOPEN gText_Name_May
    npcmsg gText_Route4_MaySpeaks3 MSG_KEEPOPEN gText_Name_May
    closemsg
    sound 0x15
    applymovement 0x9 Move_Route4_May_2
    applymovement PLAYER Move_Route4_Player_3
    waitmovement 0x9
    npcmsg gText_Route4_MaySpeaks4 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement 0x9 Move_Route4_May_3
    applymovement PLAYER Move_Route4_Player_4
    waitmovement 0x9
    npcmsg gText_Route4_MaySpeaks5 MSG_KEEPOPEN gText_Name_May
    closemsg
    pause 30
    sound 0x15
    applymovement 0x9 Move_Route4_May_4
    applymovement PLAYER Move_Route4_Player_5
    waitmovement 0x9
    npcmsg gText_Route4_MaySpeaks7 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement PLAYER Move_Route4_Player_6
    waitmovement 0x9
    npcmsg gText_Route4_MaySpeaks8 MSG_KEEPOPEN gText_Name_May
    closemsg
    spriteface 0x9, DOWN
    spriteface PLAYER, UP
    npcmsg gText_Route4_MaySpeaks9 MSG_KEEPOPEN gText_Name_May
    closemsg
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
@ Roxanne Route 4
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route4_Roxanne:
    lock
    npcmsg gText_Route4_Roxanne_Speak_1 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    pause 30
    sound 0x15
    applymovement 10 Move_Route4_Roxanne_1
    waitmovement 10
    npcmsg gText_Route4_Roxanne_Speak_2 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    applymovement 10 Move_Route4_Roxanne_2
    waitmovement 10
    npcmsg gText_Route4_Roxanne_Speak_3 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    npcmsg gText_Route4_Roxanne_Speak_4 MSG_KEEPOPEN gText_Name_Roxanne
    closemsg
    npcmsg gText_Route4_Roxanne_Speak_5 MSG_YESNO gText_Name_Roxanne
    compare LASTRESULT 0x1
    if notequal _goto EventScript_Route4_Roxanne_PlayerDontWantToBattle
    closemsg
    trainerbattle3 0x3 27 0x0 gText_Route4_Roxanne_Defeat
    npcmsg gText_Route4_Roxanne_Speak_6 MSG_KEEPOPEN gText_Name_Roxanne
    closemsg
    giveitem ITEM_HARD_STONE 0x1 MSG_OBTAIN
    npcmsg gText_Route4_Roxanne_Speak_7 MSG_KEEPOPEN gText_Name_Roxanne
    closemsg
    fadescreen 0x1
    hidesprite 10
    setflag FLAG_ROXANNE_ROUTE4_SPRITE
    fadescreen 0x0
    release
    end

EventScript_Route4_Roxanne_PlayerDontWantToBattle:
    npcmsg gText_Route4_Roxanne_PlayerDontWantToBattle MSG_KEEPOPEN gText_Name_Roxanne
    closemsg
    release
    end

Move_Route4_Roxanne_1:
    .byte exclaim
    .byte pause_long
    .byte face_player
    .byte end_m

Move_Route4_Roxanne_2:
    .byte say_question
    .byte pause_long
    .byte end_m
