.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

EventScript_GivePoke:
	lock
	faceplayer
	checkflag 0x300
	if 0x1 _goto GivePlayerPokemon
	end

GivePlayerPokemon:
	givepokemon SPECIES_KYOGRE 100 0x0 0x0 0x0
	givepokemon SPECIES_GROUDON 100 0x0 0x0 0x0
	givepokemon SPECIES_RAYQUAZA 100 0x0 0x0 0x0
	givepokemon SPECIES_ARCEUS 100 0x0 0x0 0x0
	setflag 0x300
	fanfare 0x13E
	waitfanfare
	release
	end