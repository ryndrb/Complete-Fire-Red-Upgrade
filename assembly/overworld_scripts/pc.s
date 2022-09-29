.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_PCMainMenu
EventScript_PCMainMenu:
	message 0x81A508A
	waitmessage
	special 0x106
	waitstate
	goto EventScript_ChoosePCMenu
	end

.global EventScript_ChoosePCMenu
EventScript_ChoosePCMenu:
	switch LASTRESULT
	case 0, EventScript_AccessPokemonStorage
	case 1, EventScript_AccessPlayersPC
	@case 2, EventScript_AccessProfOaksPC
	@case 3, EventScript_AccessHallOfFame
	case 4, EventScript_TurnOffPC
	case 127, EventScript_TurnOffPC
	end

.global EventScript_AccessPlayersPC
EventScript_AccessPlayersPC:
	playse 2
	msgbox 0x81A50DD MSG_NORMAL
	special 0xFA
	waitstate
	goto EventScript_PCMainMenu
	end

.global EventScript_AccessPokemonStorage
EventScript_AccessPokemonStorage:
	playse 2
	call_if_unset 0x834 EventScript_AccessSomeonesPC
	call_if_set 0x834 EventScript_AccessBillsPC
	msgbox 0x81A50BE MSG_NORMAL
	special 0x3C
	waitstate
	setvar 0x8004 27
	special 0x17D
	goto EventScript_PCMainMenu
	end

.global EventScript_AccessSomeonesPC
EventScript_AccessSomeonesPC:
	msgbox 0x81A50A7 MSG_NORMAL
	return

.global EventScript_AccessBillsPC
EventScript_AccessBillsPC:
	msgbox 0x81A50EF MSG_NORMAL
	return

.global EventScript_TurnOffPC
EventScript_TurnOffPC:
	setvar 0x8004 0
	playse 3
	@special 0xD7
	@special 0x190
	releaseall
	end

.global EventScript_AccessHallOfFame
EventScript_AccessHallOfFame:
	goto_if_unset 0x82C EventScript_TurnOffPC
	playse 2
	setvar 0x8004 31
	special 0x17E
	special 0x17D
	special 0x107
	waitstate
	special 0x17F
	goto EventScript_ChoosePCMenu
	end

.global EventScript_AccessProfOaksPC
EventScript_AccessProfOaksPC:
	goto_if_unset 0x829 EventScript_TurnOffPC
	playse 2
	msgbox 0x81A5BC6 MSG_NORMAL
	msgbox 0x81A5C03, MSG_YESNO
	compare LASTRESULT 0x0
	goto_if_eq EventScript_ExitOaksPC
	setflag 0x2FF
	call 0x81A73E0
	clearflag 0x2FF
	goto EventScript_ExitOaksPC
	end

.global EventScript_ExitOaksPC
EventScript_ExitOaksPC:
	msgbox 0x81A5C2E MSG_NORMAL
	goto EventScript_PCMainMenu
	end