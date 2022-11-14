.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_PAYBACK, 0x0D7
.equ FLAG_OBTAIN_GYRO_BALL, 0x0DE

@@@@@@@@@@@@@@@@@@@@@@
@ Payback | Route 6
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route6Payback:
    lock
    faceplayer
    checkflag FLAG_OBTAIN_PAYBACK
    if 0x0 _goto EventScript_GivePayback
    msgbox 0x8174559 MSG_FACE
    end

EventScript_GivePayback:
    msgbox gText_GivePayback MSG_KEEPOPEN
    applymovement 0x1 EventScript_GivePaybackMove
    waitmovement 0x1
    msgbox gText_GivePayback1 MSG_KEEPOPEN
    giveitem ITEM_TM66 0x1 MSG_OBTAIN
    msgbox gText_GivePaybackObtained MSG_KEEPOPEN
    setflag FLAG_OBTAIN_PAYBACK
    release
    end

EventScript_GivePaybackMove:
    .byte exclaim
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Gyro Ball | Route 6 Underground Path
@@@@@@@@@@@@@@@@@@@@@@
EventScipt_Route6GyroBall:
    lock
    faceplayer
    checkflag FLAG_OBTAIN_GYRO_BALL
    if 0x0 _goto EventScript_GyroBall
    msgbox gText_GyroBallObtained MSG_KEEPOPEN
    release
    end

EventScript_GyroBall:
    msgbox gText_GiveGyroBall MSG_KEEPOPEN
    giveitem ITEM_TM74 0x1 MSG_OBTAIN
    msgbox gText_GyroBallObtained MSG_KEEPOPEN
    setflag FLAG_OBTAIN_GYRO_BALL
    closeonkeypress
    release
    end
