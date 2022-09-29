.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

EventScript_TrainerBattle:
	lock
	faceplayer
	trainerbattle0 0x0 0x02E3 0x0 gText_Intro gTextWin
	msgbox gText_AlreadyDefeated MSG_FACE
	release
	end

