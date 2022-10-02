.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_TURN_DAY, 0x931

EventScript_GivePoke:
	lock
	faceplayer
	checkflag 0x300
	if 0x1 _goto GivePlayerPokemon
	end

GivePlayerPokemon:
	setflag FLAG_TURN_DAY
	givepokemon SPECIES_CHARIZARD 100 0x0 0x0 0x0
	givepokemon SPECIES_CLEFABLE 100 0x0 0x0 0x0
	setflag 0x300
	fanfare 0x13E
	waitfanfare
	release
	end