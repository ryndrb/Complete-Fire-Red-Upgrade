.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ Deleted Kid
@@@@@@@@@@@@@@@@@@@@@@
EventScript_DeletedKid:
    lock
    faceplayer
    msgbox gText_DeletedKid MSG_KEEPOPEN
    closeonkeypress
    release
    end
