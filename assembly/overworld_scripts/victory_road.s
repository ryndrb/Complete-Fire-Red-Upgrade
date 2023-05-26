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
    npcmsg gText_BrendanVictoryRoadDefeatedSpeaks1 MSG_KEEPOPEN gText_Name_Brendan
    closemsg
    pause 60
    faceplayer
    npcmsg gText_BrendanVictoryRoadDefeatedSpeaks2 MSG_KEEPOPEN gText_Name_Brendan
    closemsg
    applymovement 0xE EventScript_BrendanVictoryRoadNoticePlayer
    waitmovement 0xE
    npcmsg gText_BrendanVictoryRoadDefeatedSpeaks3 MSG_KEEPOPEN gText_Name_Brendan
    closemsg
    giveitem ITEM_GALLADITE 0x1 MSG_OBTAIN
    giveitem ITEM_GARDEVOIRITE 0x1 MSG_OBTAIN
    npcmsg gText_BrendanVictoryRoadDefeatedSpeaks4 MSG_KEEPOPEN gText_Name_Brendan
    closemsg
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
