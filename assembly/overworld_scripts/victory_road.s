.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"


.equ FLAG_BRENDAN_VICTORYROAD_ENCOUTER, 0x939

@@@@@@@@@@@@@@@@@@@@@@
@ Brendan Victory Road Battle
@@@@@@@@@@@@@@@@@@@@@@
EventScript_VictoryRoad_Brendan:
    lock
    textcolor BLUE
    applymovement 0xE EventScript_BrendanVictoryRoadNoticePlayer
    waitmovement 0xE
    faceplayer
    special 0x0
    trainerbattle1 0x1 60 0x0 gText_BrendanVictoryRoadIntro gText_BrendanVictoryRoadLost EventScript_BrendanVictoryRoadAfter
    release
    end

EventScript_BrendanVictoryRoadAfter:
    lock
    textcolor BLUE
    spriteface 0xE, DOWN
    msgbox gText_BrendanVictoryRoadDefeatedSpeaks1 MSG_KEEPOPEN
    closeonkeypress
    pause 60
    faceplayer
    msgbox gText_BrendanVictoryRoadDefeatedSpeaks2 MSG_KEEPOPEN
    closeonkeypress
    applymovement 0xE EventScript_BrendanVictoryRoadNoticePlayer
    waitmovement 0xE
    msgbox gText_BrendanVictoryRoadDefeatedSpeaks3 MSG_KEEPOPEN
    closeonkeypress
    giveitem ITEM_GALLADITE 0x1 MSG_OBTAIN
    giveitem ITEM_GARDEVOIRITE 0x1 MSG_OBTAIN
    msgbox gText_BrendanVictoryRoadDefeatedSpeaks4 MSG_KEEPOPEN
    closeonkeypress
    fadescreen 0x1
    hidesprite 0xE
    setflag FLAG_BRENDAN_VICTORYROAD_ENCOUTER
    fadescreen 0x0
    release
    end

EventScript_BrendanVictoryRoadNoticePlayer:
    .byte pause_long
    .byte exclaim
    .byte end_m
