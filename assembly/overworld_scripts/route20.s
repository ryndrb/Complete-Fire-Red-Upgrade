.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ Wallace Route 20 | Seafoam
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route20_Wallace:
    lock
    pause 30
    sound 0x15
    applymovement 14 Move_Route20_Wallace_1
    waitmovement 14
    npcmsg gText_Route20_Wallace_Speak_1 MSG_KEEPOPEN 0 LEFT
    closemsg
    npcmsg gText_Route20_Wallace_Speak_2 MSG_YESNO 40 LEFT
    compare LASTRESULT 0x1
    if notequal _goto EventScript_Route20_Wallace_PlayerDontWantToBattle
    closemsg
    trainerbattle3 0x3 86 0x0 gText_Route20_Wallace_Defeat
    npcmsg gText_Route20_Wallace_Speak_3 MSG_KEEPOPEN 40 LEFT
    closemsg
    giveitem ITEM_MYSTIC_WATER 0x1 MSG_OBTAIN
    npcmsg gText_Route20_Wallace_Speak_4 MSG_KEEPOPEN 40 LEFT
    closemsg
    fadescreen 0x1
    hidesprite 14
    setflag FLAG_WALLACE_ROUTE20_SPRITE
    fadescreen 0x0
    release
    end

EventScript_Route20_Wallace_PlayerDontWantToBattle:
    npcmsg gText_Route20_Wallace_PlayerDontWantToBattle MSG_KEEPOPEN 40 LEFT
    closemsg
    spriteface 14 RIGHT
    release
    end

Move_Route20_Wallace_1:
    .byte exclaim
    .byte pause_long
    .byte face_player
    .byte end_m
