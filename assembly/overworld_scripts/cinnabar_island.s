.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_EXPLOSION, 0x0DC
.equ FLAG_MAY_CINNABAR_SPRITE, 0x944
.equ VAR_MAY_CINNABAR_ENCOUNTER, 0x5032

@@@@@@@@@@@@@@@@@@@@@@
@ Explosion | Cinnabar Island
@@@@@@@@@@@@@@@@@@@@@@
EventScript_CinnabarExplosion:
    textcolor BLUE
    lock
    faceplayer
    checkflag FLAG_OBTAIN_EXPLOSION
    if 0x0 _goto EventScript_GiveExplosion
    msgbox gText_ExplosionObtained MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_GiveExplosion:
    msgbox gText_GiveExplosion MSG_KEEPOPEN
    giveitem ITEM_TM64 0x1 MSG_OBTAIN
    setflag FLAG_OBTAIN_EXPLOSION
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ May in Cinnabar
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Cinnabar_FossilCenter:
    mapscript MAP_SCRIPT_ON_TRANSITION MapScript_0x16E279
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_Cinnabar_May
    .byte MAP_SCRIPT_TERMIN

LevelScript_Cinnabar_May:
    levelscript VAR_MAY_CINNABAR_ENCOUNTER, 0, EventSript_Cinnabar_May
    .hword LEVEL_SCRIPT_TERMIN

MapScript_0x16E279:
    compare 0x406A 0x1
    if 0x1 _call MapScript_0x16E285
    end

MapScript_0x16E285:
    setvar 0x406A 0x2
    return

EventSript_Cinnabar_May:
    lock
    textcolor RED
    applymovement 2 EventScript_Cinnabar_MayNoticePlayer
    applymovement PLAYER EventScript_Cinnabar_PlayerGetCloseToMay
    waitmovement 2
    msgbox gText_Cinnabar_MaySpeaks1 MSG_KEEPOPEN
    closeonkeypress
    applymovement 2 EventScript_Cinnabar_MayPonders
    waitmovement 2
    msgbox gText_Cinnabar_MaySpeaks2 MSG_KEEPOPEN
    closeonkeypress
    applymovement 2 EventScript_Cinnabar_MaySmiles
    waitmovement 2
    msgbox gText_Cinnabar_MaySpeaks3 MSG_KEEPOPEN
    closeonkeypress
    spriteface 2, LEFT
    msgbox gText_Cinnabar_MaySpeaks4 MSG_KEEPOPEN
    closeonkeypress
    applymovement 2 EventScript_Cinnabar_MayLeave
    applymovement PLAYER EventScript_Cinnabar_PlayerSeeMayLeave
    waitmovement 2
    sound 9
    hidesprite 2
    setvar VAR_MAY_CINNABAR_ENCOUNTER 0x1
    setflag FLAG_MAY_CINNABAR_SPRITE
    release
    end

EventScript_Cinnabar_MayNoticePlayer:
    .byte exclaim
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte end_m

EventScript_Cinnabar_PlayerGetCloseToMay:
    .byte pause_long
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_right_onspot_fastest
    .byte end_m

EventScript_Cinnabar_MayPonders:
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte say_question
    .byte pause_long
    .byte end_m

EventScript_Cinnabar_MaySmiles:
    .byte say_smile
    .byte pause_long
    .byte end_m

EventScript_Cinnabar_MayLeave:
    .byte walk_down
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte end_m

EventScript_Cinnabar_PlayerSeeMayLeave:
    .byte walk_down_onspot_fastest
    .byte end_m
