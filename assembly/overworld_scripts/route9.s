.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_MAY_ROUTE9_SPRITE, 0x93E
.equ VAR_MAY_ROUTE9_ENCOUNTER, 0x5031

@@@@@@@@@@@@@@@@@@@@@@
@ May Route 9 battle
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route9_MayBattle:
    lock
    textcolor RED
    playsong 0x1A7
    applymovement 16 EventScript_Route9_MayLookingAroundNoticePlayer
    waitmovement 16
    call MayNameBox
    trainerbattle1 0x1 63 0x0 gText_Route9_MayIntro gText_Route9_MayLost EventScript_Route9_MayAfter
    release
    end

EventScript_Route9_MayAfter:
    textcolor RED
    playsong 0x1A7
    call MayNameBox
    msgbox gText_Route9_MayAfterSpeaks1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    fadescreen 0x1
    fanfare 0x0100
    special 0x1
    waitfanfare
    fadescreen 0x0
    call MayNameBox
    msgbox gText_Route9_MayAfterSpeaks2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    giveitem ITEM_POKE_BALL 50 MSG_OBTAIN
    pause 10
    giveitem ITEM_GREAT_BALL 25 MSG_OBTAIN
    pause 10
    giveitem ITEM_ULTRA_BALL 10 MSG_OBTAIN
    call MayNameBox
    msgbox gText_Route9_MayAfterSpeaks3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 16 EventScript_Route9_MayLeaves
    waitmovement 16
    hidesprite 16
    setflag FLAG_MAY_ROUTE9_SPRITE
    setvar VAR_MAY_ROUTE9_ENCOUNTER 0x1
    fadedefaultbgm
    release
    end

EventScript_Route9_MayLookingAroundNoticePlayer:
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte walk_down
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte jump_onspot_left
    .byte exclaim
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

EventScript_Route9_MayLeaves:
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

@@@@@@@@@@@@@@@@@@@@@@
@ Route 9 NameBox
@@@@@@@@@@@@@@@@@@@@@@
MayNameBox:
    setvar 0x8000 2
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
