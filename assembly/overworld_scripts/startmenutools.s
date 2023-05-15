.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

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
@ Time Turner / Poketch
@@@@@@@@@@@@@@@@@@@@@@
.global EventScript_TimeTurner
EventScript_TimeTurner:
    preparemsg gText_TimeOfDay
    waitmsg
    multichoiceoption gText_TimeTurner_Day 0
    multichoiceoption gText_TimeTurner_Night 1
    multichoiceoption gText_TimeTurner_Reset 2
    multichoice 0x0 0x0 THREE_MULTICHOICE_OPTIONS 0x0
    switch LASTRESULT
    case 0, EventScript_TimeTurner_Day
    case 1, EventScript_TimeTurner_Night
    case 2, EventScript_TimeTurner_Reset
    release
    end

EventScript_TimeTurner_Day:
    clearflag FLAG_TURN_NIGHT
    setflag FLAG_TURN_DAY
    sound 0x2
    release
    end

EventScript_TimeTurner_Night:
    clearflag FLAG_TURN_DAY
    setflag FLAG_TURN_NIGHT
    sound 0x2
    release
    end

EventScript_TimeTurner_Reset:
    clearflag FLAG_TURN_DAY
    clearflag FLAG_TURN_NIGHT
    sound 0x2
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Stat Scanner / Pokestat
@@@@@@@@@@@@@@@@@@@@@@
.global EventScript_StatScanner
EventScript_StatScanner:
	callasm CB2_ShowEvIv
	end

@@@@@@@@@@@@@@@@@@@@@@
@ Pokevial | Inclement Emerald inspired
@@@@@@@@@@@@@@@@@@@@@@
.global EventScript_PokeVial
EventScript_PokeVial:
    buffernumber 0x0 0x5045
    compare 0x5045 0x0
    if equal _goto EventScript_RefillVial
    msgbox gText_CurrentCharges MSG_YESNO
    compare LASTRESULT 0x1
    if equal _call EventScript_ConsumeVialCharge
    release
	end

EventScript_ConsumeVialCharge:
    closemessage
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
