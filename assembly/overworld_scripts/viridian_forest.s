.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_GIFT_VENOSHOCK, 0x0BF

@@@@@@@@@@@@@@@@@@@@@@
@ Venoshock | after battle gift
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Venoshock:
    lock
    faceplayer
    trainerbattle0 0x0 0x68 0x0 0x81723D4 0x8172402
    checkflag FLAG_OBTAIN_GIFT_VENOSHOCK
    if 0x0 _goto EventScript_GiveVenoshock
    msgbox 0x817241F MSG_NORMAL
    end

EventScript_GiveVenoshock:
    lock
    msgbox gText_GiveVenoshock MSG_KEEPOPEN
    giveitem ITEM_TM63 0x1 MSG_OBTAIN
    msgbox gText_GiveVenoshock2 MSG_KEEPOPEN
    closeonkeypress
    setflag FLAG_OBTAIN_GIFT_VENOSHOCK
    release
    end
