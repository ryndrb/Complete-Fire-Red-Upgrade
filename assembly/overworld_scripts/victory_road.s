.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ Brendan Victory Road Battle
@@@@@@@@@@@@@@@@@@@@@@
EventScript_VictoryRoad_Brendan:
    lock
    applymovement 0xE EventScript_BrendanVictoryRoadNoticePlayer
    waitmovement 0xE
    faceplayer
    special 0x0
    trainerbattle1 0x1 60 0x0 gText_BrendanVictoryRoadIntro gText_BrendanVictoryRoadLost EventScript_BrendanVictoryRoadAfter
    release
    end

EventScript_BrendanVictoryRoadAfter:
    lock
    spriteface 0xE, DOWN
    call BrendanNameBox
    msgbox gText_BrendanVictoryRoadDefeatedSpeaks1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    pause 60
    faceplayer
    call BrendanNameBox
    msgbox gText_BrendanVictoryRoadDefeatedSpeaks2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0xE EventScript_BrendanVictoryRoadNoticePlayer
    waitmovement 0xE
    call BrendanNameBox
    msgbox gText_BrendanVictoryRoadDefeatedSpeaks3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    giveitem ITEM_GALLADITE 0x1 MSG_OBTAIN
    giveitem ITEM_GARDEVOIRITE 0x1 MSG_OBTAIN
    call BrendanNameBox
    msgbox gText_BrendanVictoryRoadDefeatedSpeaks4 MSG_KEEPOPEN
    callasm RemoveNameBox
    closeonkeypress
    fadescreen 0x1
    hidesprite 0xE
    setflag FLAG_BRENDAN_VICTORYROAD_SPRITE
    fadescreen 0x0
    release
    end

EventScript_BrendanVictoryRoadNoticePlayer:
    .byte pause_long
    .byte exclaim
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Victory Road NameBox
@@@@@@@@@@@@@@@@@@@@@@
BrendanNameBox:
    setvar 0x8000 3
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
