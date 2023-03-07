.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@ test script for custom trainers
EventScript_TrainerBattle:
	setflag 0x933
	lock
	faceplayer
	@setflag 0x907
	trainerbattle0 0x0 60 0x0 gText_Intro gTextWin
	msgbox gText_AlreadyDefeated MSG_FACE
	@clearflag 0x907
	release
	end

@ bootleg "trade" script sample
@ same oT and no nickname...
EventScript_TradeScript:
	lock
	msgbox gText_DoYouHaveStaravia MSG_YESNO
	compare LASTRESULT 0x1
	if 0x0 _goto EventScript_ComeBackIfYouHaveIt
	special 0x9F
	waitstate
	setvar 0x8003 0x0
	special2 LASTRESULT 0x18
	compare LASTRESULT SPECIES_STARAPTOR
	if TRUE _goto EventScript_IsStaravia
	msgbox gText_NotStaravia MSG_FACE
	end

EventScript_ComeBackIfYouHaveIt:
	msgbox gText_ComeBackIfYouHaveIt MSG_FACE
	release
	end

EventScript_IsStaravia:
	special 0x7C
	setvar 0x8003 LASTRESULT
	fadescreen 0x1
	pause 10
	msgbox gText_WillBeSentOver MSG_SIGN
	fanfare 0x013D
	waitfanfare
	msgbox gText_SentOver MSG_SIGN
	pause 10
	fadescreen 0x0
	special 0x62
	givepokemon SPECIES_ZAPDOS 25 ITEM_HEAVY_DUTY_BOOTS
	msgbox gText_TakeGoodCare MSG_FACE
	release
	end

@ Legendary Encounters | Random
EventScript_LegendaryEncounter:
	lock
	faceplayer
	random 0x5
	switch LASTRESULT
	case 0, EventScript_Arceus
	case 1, EventScript_Palkia
	case 2, EventScript_Dialga
	case 3, EventScript_Giratina
	case 4, EventScript_Heatran
	end

EventScript_Arceus:
	cry SPECIES_ARCEUS 0x0
	wildbattle SPECIES_ARCEUS 50 0x0
	end

EventScript_Palkia:
	cry SPECIES_PALKIA 0x0
	wildbattle SPECIES_PALKIA 50 0x0
	end

EventScript_Dialga:
	cry SPECIES_DIALGA 0x0
	wildbattle SPECIES_DIALGA 50 0x0
	end

EventScript_Giratina:
	cry SPECIES_GIRATINA 0x0
	wildbattle SPECIES_GIRATINA 50 0x0
	end

EventScript_Heatran:
	cry SPECIES_HEATRAN 0x0
	wildbattle SPECIES_HEATRAN 50 0x0
	end
