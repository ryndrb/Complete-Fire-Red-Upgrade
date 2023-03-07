.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_X_SCISSOR, 0x0DA

@@@@@@@@@@@@@@@@@@@@@@
@ X Scissor | Route 8
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route8XScissor:
    textcolor BLUE
    lock
    faceplayer
    checkflag FLAG_OBTAIN_X_SCISSOR
    if 0x0 _goto EventScript_GiveXScissor
    msgbox gText_XScissorObtained MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_GiveXScissor:
    msgbox gText_Route8GuyGreet MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_PlayerAnsNo
    msgbox gText_PlayerAnsYes MSG_KEEPOPEN
    giveitem ITEM_TM81 0x1 MSG_OBTAIN
    msgbox gText_XScissorObtained MSG_KEEPOPEN
    setflag FLAG_OBTAIN_X_SCISSOR
    closeonkeypress
    release
    end

EventScript_PlayerAnsNo:
    msgbox gText_PlayerAnsNo MSG_KEEPOPEN
    closeonkeypress
    release
    end
