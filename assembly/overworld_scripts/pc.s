.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_PCMainMenu
EventScript_PCMainMenu:
	playse 2
	special 0x3C
	waitstate
	setvar 0x8004 0x0
	release
	end