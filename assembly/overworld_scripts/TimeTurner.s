.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_TURN_DAY      , 0x931
.equ FLAG_TURN_NIGHT    , 0x932

.global EventScript_TimeTurner
EventScript_TimeTurner:
    preparemsg gText_TimeOfDay
    waitmsg
    setvar 0x8000 0x4
    setvar 0x8001 0x4
    setvar 0x8004 0x0
    special 0x158
    waitstate
    compare LASTRESULT 0x3
    if greaterorequal _goto End
    switch LASTRESULT 
    case 0, EventScript_Day
    case 1, EventScript_Night
    case 2, EventScript_Reset
    release
    end

EventScript_Day:
    clearflag FLAG_TURN_NIGHT
    setflag FLAG_TURN_DAY
    sound 0x2
    release
    end

EventScript_Night:
    clearflag FLAG_TURN_DAY
    setflag FLAG_TURN_NIGHT
    sound 0x2
    release
    end

EventScript_Reset:
    clearflag FLAG_TURN_DAY
    clearflag FLAG_TURN_NIGHT
    sound 0x2
    release
    end

End:
    release
    end