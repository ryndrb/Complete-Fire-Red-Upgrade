.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ May Route 9 battle
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route9_MayBattle:
    lock
    applymovement 16 Move_Route9_May_1
    waitmovement 16
    sound 0x15
    applymovement 16 Move_Route9_May_2
    waitmovement 16
    playsong 0x1A7 0x1
    npcmsg gText_Route9_MayIntro MSG_KEEPOPEN gText_Name_May
    closemsg
    trainerbattle3 0x3 63 0x0 gText_Route9_MayLost
    npcmsg gText_Route9_MayAfterSpeaks1 MSG_KEEPOPEN gText_Name_May
    closemsg
    fanfare 0x0100
    special 0x1
    waitfanfare
    npcmsg gText_Route9_MayAfterSpeaks2 MSG_KEEPOPEN gText_Name_May
    closemsg
    giveitem ITEM_POKE_BALL 50 MSG_OBTAIN
    pause 10
    giveitem ITEM_GREAT_BALL 25 MSG_OBTAIN
    pause 10
    giveitem ITEM_ULTRA_BALL 10 MSG_OBTAIN
    npcmsg gText_Route9_MayAfterSpeaks3 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement 16 Move_Route9_May_3
    waitmovement 16
    hidesprite 16
    setflag FLAG_MAY_ROUTE9_SPRITE
    setvar VAR_MAY_ENCOUNTER 0x4
    fadedefaultbgm
    release
    end

Move_Route9_May_1:
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte walk_down
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Route9_May_2:
    .byte exclaim
    .byte jump_onspot_left
    .byte pause_long
    .byte run_down
    .byte run_down
    .byte run_down
    .byte run_left
    .byte run_left
    .byte run_left
    .byte run_left
    .byte run_left
    .byte run_left
    .byte end_m

Move_Route9_May_3:
    .byte say_smile
    .byte walk_right
    .byte walk_right
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
    .byte walk_right
    .byte end_m
