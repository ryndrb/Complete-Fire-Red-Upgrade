.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_TURN_DAY      , 0x931
.equ FLAG_TURN_NIGHT    , 0x932

@@@@@@@@@@@@@@@@@@@@@@
@ Pocket PC
@@@@@@@@@@@@@@@@@@@@@@
.global EventScript_PCMainMenu
EventScript_PCMainMenu:
	playse 2
	special 0x3C
	waitstate
	setvar 0x8004 0x0
	release
	end

@@@@@@@@@@@@@@@@@@@@@@
@ TIme Turner
@@@@@@@@@@@@@@@@@@@@@@
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

@@@@@@@@@@@@@@@@@@@@@@
@ Stat Scanner / Pokestat
@@@@@@@@@@@@@@@@@@@@@@
.global EventScript_StatScanner
EventScript_StatScanner:
	callasm 0x08f90001
	end

@@@@@@@@@@@@@@@@@@@@@@
@ Poke Vial | Inclement Emerald inspired
@@@@@@@@@@@@@@@@@@@@@@
.global EventScript_PokeVial
EventScript_PokeVial:
    buffernumber 0x0 0x502D
    compare 0x502D 0x0
    if equal _goto EventScript_RefillVial
    msgbox gText_CurrentCharges MSG_YESNO
    compare LASTRESULT 0x1
    if equal _call EventScript_ConsumeVialCharge
    release
	end

EventScript_ConsumeVialCharge:
    fadescreen 0x1
    fanfare 0x0100
	special 0x0
    waitfanfare
    fadescreen 0x0
    callasm DecreseCharges
    return

EventScript_RefillVial:
    msgbox gText_RefillVial MSG_KEEPOPEN
    release
    end
