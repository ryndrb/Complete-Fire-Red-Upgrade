.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_ChangeAbility
EventScript_ChangeAbility:
	lock
	faceplayer
	setflag 0x91E
	special 0x9F
	waitstate
	compare 0x8004 0x6
	if greaterorequal _goto EndScriptComeBack
	goto ChangeAbility
	release
	end

ChangeAbility:
	setvar 0x8000 0x3
	setvar 0x8001 0x3
	copyvar 0x5106 0x8004
	setvar 0x8004 0x0
	special 0x158
	waitstate
	copyvar 0x8004 0x5106
	compare LASTRESULT 0x3
	if greaterorequal _goto EndScriptComeBack
	copyvar 0x8005 LASTRESULT
	callasm ChangeMonAbility
	goto EndScriptAbilityHasBeenChanged
	end

EndScriptAbilityHasBeenChanged:
	msgbox gText_EndScriptAbilityHasBeenChanged MSG_KEEPOPEN
	closeonkeypress
	release
	end

EndScriptComeBack:
	msgbox gText_EndScriptComeBack MSG_KEEPOPEN
	closeonkeypress
	release
	end
	