.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ Sleeping Lax
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route12_Snorlax:
    lock
    faceplayer
    checkflag 0x23D
    if 0x0 _goto 0x8168099
    special 0x187
    compare LASTRESULT 0x2
    if 0x1 _goto 0x81A7AE0
    special 0x188
    msgbox 0x81853CC MSG_YESNO
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816808D
    call EventScript_0x81A924B @ shared with route 16
    setwildbattle 0x8F 0x1E 0x0
    checksound
    cry 0x8F 0x2
    pause 0x28
    waitcry
    setflag 0x54
    setflag 0x807
    setflag 0x253
    dowildbattle
    clearflag 0x807
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if 0x1 _goto 0x816808F
    compare LASTRESULT 0x4
    if 0x1 _goto 0x816808F
    compare LASTRESULT 0x5
    if 0x1 _goto 0x816808F
    release
    end
