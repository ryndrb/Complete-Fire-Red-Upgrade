.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_GOT_HM06, 0x2EF

@@@@@@@@@@@@@@@@@@@@@@
@ Rock Smash | Inside Poke Center | Route 10
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route10RockSmash:
    textcolor 0x0
    lock
    faceplayer
    checkflag FLAG_GOT_HM06
    if 0x0 _goto EventScript_GiveRockSmash
    msgbox gText_RockSmashObtained MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_GiveRockSmash:
    msgbox gText_GiveRockSmash MSG_KEEPOPEN
    giveitem ITEM_HM06 0x1 MSG_OBTAIN
    msgbox gText_RockSmashObtained MSG_KEEPOPEN
    setflag FLAG_GOT_HM06
    closeonkeypress
    release
    end
