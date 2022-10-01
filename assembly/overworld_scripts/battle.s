.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_CUSTOM_TRAINERS, 0x1034

EventScript_TrainerBattle:
	lock
	faceplayer
	setflag FLAG_CUSTOM_TRAINERS
	trainerbattle0 0x0 0x04 0x0 gText_Intro gTextWin
	msgbox gText_AlreadyDefeated MSG_FACE
	release
	end