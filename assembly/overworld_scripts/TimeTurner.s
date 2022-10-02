.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_TURN_DAY      , 0x931
.equ FLAG_TURN_DUSK     , 0x932
.equ FLAG_TURN_NIGHT    , 0x933

.global EventScript_TimeTurner
EventScript_TimeTurner:
    lock   
    setvar 0x8000 0x4
    setvar 0x8001 0x4
    msgbox gText_TimeOfDay MSG_KEEPOPEN
    special 0x158
    waitstate
    switch LASTRESULT 
    case 0, EventScript_Day
    case 1, EventScript_Dusk
    case 2, EventScript_Night
    case 3, EventScript_Reset
    end

EventScript_Day:
    clearflag FLAG_TURN_DUSK
    clearflag FLAG_TURN_NIGHT
    setflag FLAG_TURN_DAY
    release
    end
    
EventScript_Dusk:
    clearflag FLAG_TURN_DAY
    clearflag FLAG_TURN_NIGHT
    setflag FLAG_TURN_DUSK
    release
    end

EventScript_Night:
    clearflag FLAG_TURN_DAY
    clearflag FLAG_TURN_DUSK
    setflag FLAG_TURN_NIGHT
    release
    end

EventScript_Reset:
    clearflag FLAG_TURN_DAY
    clearflag FLAG_TURN_DUSK
    clearflag FLAG_TURN_NIGHT
    release
    end

End:
    release
    end