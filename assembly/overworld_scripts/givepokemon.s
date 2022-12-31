.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

EventScript_GivePoke:
	lock
	faceplayer
	checkflag 0x301
	if 0x0 _goto GivePlayerPokemon
	release
	end

GivePlayerPokemon:
	givepokemon SPECIES_HITMONLEE 100 0x0 0x0 0x0
	givepokemon SPECIES_ZANGOOSE 100 0x0 0x0 0x0
	givepokemon SPECIES_GARCHOMP 100 0x0 0x0 0x0
	givepokemon SPECIES_SKUNTANK 100 0x0 0x0 0x0
	@setflag 0x301
	fanfare 0x13E
	waitfanfare
	release
	end
	