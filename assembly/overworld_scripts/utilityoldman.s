.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_DEFEATED_BROCK, 0x4B0
.equ FLAG_DEFEATED_MISTY, 0x4B1   
.equ FLAG_DEFEATED_LT_SURGE, 0x4B2       
.equ FLAG_DEFEATED_ERIKA, 0x4B3 
.equ FLAG_DEFEATED_KOGA, 0x4B4           
.equ FLAG_DEFEATED_SABRINA, 0x4B5      
.equ FLAG_DEFEATED_BLAINE, 0x4B6        
.equ FLAG_DEFEATED_LEADER_GIOVANNI, 0x4B7   

EventScript_UtilityOldMan: @will probably add more? inspired by inclement emerald
    lock
	faceplayer
	checkflag 0x946
	if NOT_SET _goto EventScript_UtilityOldMan_FirstEncounter
	preparemsg gText_EventScript_UtilityOldManGreetings
	waitmsg
	multichoiceoption gText_UtilityOldMan_Nickname 0
	multichoiceoption gText_UtilityOldMan_MoveTutor 1
	multichoiceoption gText_UtilityOldMan_NatureChanger 2
	multichoiceoption gText_UtilityOldMan_AbilityChanger 3
	multichoiceoption gText_UtilityOldMan_SeeYa 4
	multichoice 0x0 0x0 FIVE_MULTICHOICE_OPTIONS 0x0
	switch LASTRESULT
	case 0, EventScript_UtilityOldMan_Nickname
	case 1, EventScript_UtilityOldMan_MoveTutor
	case 2, EventScript_UtilityOldMan_NatureChanger
	case 3, EventScript_UtilityOldMan_AbilityChanger
	case 4, EventScript_UtilityOldMan_SeeYa
	release
    end

EventScript_UtilityOldMan_FirstEncounter:
	msgbox gText_UtilityOldManSpeak1 MSG_KEEPOPEN
	msgbox gText_UtilityOldManSpeak2 MSG_KEEPOPEN
	msgbox gText_UtilityOldManSpeak3 MSG_KEEPOPEN
	msgbox gText_UtilityOldManSpeak4 MSG_KEEPOPEN
	msgbox gText_UtilityOldManSpeak5 MSG_KEEPOPEN
	closeonkeypress
	setflag 0x946
	release
	end

@@@@@@@@@@@@@@@@@@@@@@
@ Name Rater
@@@@@@@@@@@@@@@@@@@@@@
EventScript_UtilityOldMan_Nickname:
	msgbox gText_WhichPokemonToChangeNickname MSG_KEEPOPEN
	special 0x9F
	waitstate
	compare 0x8004 0x6
	if greaterorequal _goto EventScript_UtilityOldMan
	special 0x148
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_ThisIsAnEggNameRater
	special 0x7C
	setvar 0x8003 0x8004
	msgbox gText_NewNickname MSG_KEEPOPEN
	fadescreen 0x1
	special 0x9E
	waitstate
	special 0x7C
	setvar 0x8003 0x8004
	msgbox gText_NicknameCompleted MSG_KEEPOPEN
	goto EventScript_End
	end

EventScript_ThisIsAnEggNameRater:
	msgbox gText_EventScript_ThisIsAnEgg MSG_KEEPOPEN
	closeonkeypress
	goto EventScript_UtilityOldMan_Nickname
	end

@@@@@@@@@@@@@@@@@@@@@@
@ Move Tutor
@@@@@@@@@@@@@@@@@@@@@@
EventScript_UtilityOldMan_MoveTutor:
	checkflag FLAG_DEFEATED_BROCK
	if 0x0 _goto EventScript_NoBrockBadge
	msgbox gText_SelectWhichBadge MSG_KEEPOPEN
	goto EventScript_SelectBadge
	end

EventScript_SelectBadge:
	setvar 0x8000 3
	setvar 0x8001 0x5
	setvar 0x8004 0x0
	special 0x158
	waitstate
	compare LASTRESULT 8
	if greaterorequal _goto EventScript_UtilityOldMan
	switch LASTRESULT
	case 0, EventScript_FirstBadgeTutorMoves
	case 1, EventScript_SecondBadgeTutorMoves
	case 2, EventScript_ThirdBadgeTutorMoves
	case 3, EventScript_FourthBadgeTutorMoves
	case 4, EventScript_FifthBadgeTutorMoves
	case 5, EventScript_SixthBadgeTutorMoves
	case 6, EventScript_SeventhBadgeTutorMoves
	case 7, EventScript_EightBadgeTutorMoves
    end

EventScript_FirstBadgeTutorMoves:
	msgbox gText_WhichMoveDoYouWantToLearn MSG_KEEPOPEN
	setvar 0x8000 4
	setvar 0x8001 0x5
	special 0x158
	waitstate
	compare LASTRESULT 8
	if greaterorequal _goto EventScript_UtilityOldMan_MoveTutor
	switch LASTRESULT 
	case 0,  Learn_AfterYou
	case 1,  Learn_Bind
	case 2,  Learn_Block
	case 3,  Learn_Coaching
	case 4,  Learn_Confide
	case 5,  Learn_DualChop
	case 6,  Learn_DualWingbeat
	case 7,  Learn_FireSpin
	case 8,  Learn_FocusEnergy
	case 9,  Learn_GastroAcid
	case 10, Learn_HelpingHand
	case 11, Learn_IcicleSpear
	case 12, Learn_LaserFocus
	case 13, Learn_PinMissile
	case 14, Learn_RockBlast
	case 15, Learn_RolePlay
	case 16, Learn_SandTomb
	case 17, Learn_ScaleShot
	case 18, Learn_ScaryFace
	case 19, Learn_Snatch
	case 20, Learn_Snore
	case 21, Learn_StoredPower
	case 22, Learn_TailSlap
	case 23, Learn_TripleAxel
	case 24, Learn_VenomDrench
	case 25, Learn_VacuumWave
	case 26, Learn_Whirlpool
	case 27, Learn_WorrySeed
	end

EventScript_SecondBadgeTutorMoves:
	checkflag FLAG_DEFEATED_MISTY
	if 0x0 _goto EventScript_DontHaveThisBadgeYet
	msgbox gText_WhichMoveDoYouWantToLearn MSG_KEEPOPEN
	setvar 0x8000 5
	setvar 0x8001 0x5
	special 0x158
	waitstate
	compare LASTRESULT 12
	if greaterorequal _goto EventScript_UtilityOldMan_MoveTutor
	switch LASTRESULT
	case 0,  Learn_BarbBarrage
	case 1,  Learn_BreakingSwipe
	case 2,  Learn_BugBite
	case 3,  Learn_Covet
	case 4,  Learn_Electroball
	case 5,  Learn_Electroweb
	case 6,  Learn_Encore
	case 7,  Learn_Endeavor
	case 8,  Learn_FireFang
	case 9,  Learn_FlipTurn
	case 10, Learn_GrassyGlide
	case 11, Learn_IceFang
	case 12, Learn_IcyWind
	case 13, Learn_InfernalParade
	case 14, Learn_IronDefense
	case 15, Learn_LowKick
	case 16, Learn_MagnetRise
	case 17, Learn_PainSplit
	case 18, Learn_Reversal
	case 19, Learn_Screech
	case 20, Learn_Spikes
	case 21, Learn_StoneAxe
	case 22, Learn_SuperFang
	case 23, Learn_Synthesis
	case 24, Learn_TerrainPulse
	case 25, Learn_ThunderFang
	case 26, Learn_ToxicSpikes
	case 27, Learn_WeatherBall
	end

EventScript_ThirdBadgeTutorMoves:
	checkflag FLAG_DEFEATED_LT_SURGE
	if 0x0 _goto EventScript_DontHaveThisBadgeYet
	msgbox gText_WhichMoveDoYouWantToLearn MSG_KEEPOPEN
	setvar 0x8000 6
	setvar 0x8001 0x5
	special 0x158
	waitstate
	compare LASTRESULT 14
	if greaterorequal _goto EventScript_UtilityOldMan_MoveTutor
	switch LASTRESULT
	case 0,  Learn_BurningJealousy
	case 1,  Learn_CeaselessEdge
	case 2,  Learn_CorrosiveGas
	case 3,  Learn_CrossPoison
	case 4,  Learn_ElectricTerrain
	case 5,  Learn_FakeTears
	case 6,  Learn_FirePunch
	case 7,  Learn_GrassyTerrain
	case 8,  Learn_Hex
	case 9,  Learn_IcePunch
	case 10, Learn_KnockOff
	case 11, Learn_MagicCoat
	case 12, Learn_MagicRoom
	case 13, Learn_MistyTerrain
	case 14, Learn_MysticalPower
	case 15, Learn_PsychUp
	case 16, Learn_PsychicTerrain
	case 17, Learn_PsychoCut
	case 18, Learn_PsyshieldBash
	case 19, Learn_RazorShell
	case 20, Learn_RisingVoltage
	case 21, Learn_ScorchingSands
	case 22, Learn_SkitterSmack
	case 23, Learn_Spite
	case 24, Learn_Telekinesis
	case 25, Learn_ThunderPunch
	case 26, Learn_Trick
	case 27, Learn_WonderRoom
	end

EventScript_FourthBadgeTutorMoves:
	checkflag FLAG_DEFEATED_ERIKA
	if 0x0 _goto EventScript_DontHaveThisBadgeYet
	msgbox gText_WhichMoveDoYouWantToLearn MSG_KEEPOPEN
	setvar 0x8000 7
	setvar 0x8001 0x5
	special 0x158
	waitstate
	compare LASTRESULT 15
	if greaterorequal _goto EventScript_UtilityOldMan_MoveTutor
	switch LASTRESULT
	case 0,  Learn_Agility
	case 1,  Learn_AirSlash
	case 2,  Learn_AuraSphere
	case 3,  Learn_BatonPass
	case 4,  Learn_BitterMalice
	case 5,  Learn_BodyPress
	case 6,  Learn_CosmicPower
	case 7,  Learn_DireClaw
	case 8,  Learn_DragonDance
	case 9,  Learn_DrillRun
	case 10, Learn_EsperWing
	case 11, Learn_FirePledge
	case 12, Learn_GrassPledge
	case 13, Learn_Gravity
	case 14, Learn_HealBell
	case 15, Learn_HeatCrash
	case 16, Learn_HeavySlam
	case 17, Learn_LashOut
	case 18, Learn_LunarBlessing
	case 19, Learn_MysticalFire
	case 20, Learn_NastyPlot
	case 21, Learn_SeedBomb
	case 22, Learn_SignalBeam
	case 23, Learn_StompingTantrum
	case 24, Learn_Tailwind
	case 25, Learn_TakeHeart
	case 26, Learn_VictoryDance
	case 27, Learn_WaterPledge
	end

EventScript_FifthBadgeTutorMoves:
	checkflag FLAG_DEFEATED_SABRINA
	if 0x0 _goto EventScript_DontHaveThisBadgeYet
	msgbox gText_WhichMoveDoYouWantToLearn MSG_KEEPOPEN
	setvar 0x8000 8
	setvar 0x8001 0x5
	special 0x158
	waitstate
	compare LASTRESULT 7
	if greaterorequal _goto EventScript_UtilityOldMan_MoveTutor
	switch LASTRESULT
	case 0,  Learn_AquaTail
	case 1,  Learn_BlazeKick
	case 2,  Learn_BodySlam
	case 3,  Learn_Bounce
	case 4,  Learn_Crunch
	case 5,  Learn_DarkestLariat
	case 6,  Learn_ExpandingForce
	case 7,  Learn_HyperVoice
	case 8,  Learn_IronHead
	case 9,  Learn_Liquidation
	case 10, Learn_PowerGem
	case 11, Learn_PsychicFangs
	case 12, Learn_ThroatChop
	case 13, Learn_Uproar
	case 14, Learn_ZenHeadbutt
	end

EventScript_SixthBadgeTutorMoves:
	checkflag FLAG_DEFEATED_KOGA
	if 0x0 _goto EventScript_DontHaveThisBadgeYet
	msgbox gText_WhichMoveDoYouWantToLearn MSG_KEEPOPEN
	setvar 0x8000 9
	setvar 0x8001 0x5
	special 0x158
	waitstate
	compare LASTRESULT 6
	if greaterorequal _goto EventScript_UtilityOldMan_MoveTutor
	switch LASTRESULT
	case 0,  Learn_BleakwindStorm
	case 1,  Learn_BugBuzz
	case 2,  Learn_EarthPower
	case 3,  Learn_FoulPlay
	case 4,  Learn_HeatWave
	case 5,  Learn_HighHorsepower
	case 6,  Learn_LeafBlade
	case 7,  Learn_MuddyWater
	case 8,  Learn_PhantomForce
	case 9,  Learn_PlayRough
	case 10, Learn_PollenPuff
	case 11, Learn_SandsearStorm
	case 12, Learn_SpringtideStorm
	case 13, Learn_TripleArrows
	case 14, Learn_WindboltStorm
	end

EventScript_SeventhBadgeTutorMoves:
	checkflag FLAG_DEFEATED_BLAINE
	if 0x0 _goto EventScript_DontHaveThisBadgeYet
	msgbox gText_WhichMoveDoYouWantToLearn MSG_KEEPOPEN
	setvar 0x8000 10
	setvar 0x8001 0x5
	special 0x158
	waitstate
	compare LASTRESULT 12
	if greaterorequal _goto EventScript_UtilityOldMan_MoveTutor
	switch LASTRESULT
	case 0,  Learn_BraveBird
	case 1,  Learn_CloseCombat
	case 2,  Learn_FlareBlitz
	case 3,  Learn_GunkShot
	case 4,  Learn_HeadlongRush
	case 5,  Learn_Hurricane
	case 6,  Learn_HydoPump
	case 7,  Learn_MegaHorn
	case 8,  Learn_MistyExplosion
	case 9,  Learn_MountainGale
	case 10, Learn_Poltergeist
	case 11, Learn_PowerWhip
	case 12, Learn_RagingFury
	case 13, Learn_Superpower
	case 14, Learn_WaveCrash
	end

EventScript_EightBadgeTutorMoves:	
	checkflag FLAG_DEFEATED_LEADER_GIOVANNI
	if 0x0 _goto EventScript_DontHaveThisBadgeYet
	msgbox gText_WhichMoveDoYouWantToLearn MSG_KEEPOPEN
	setvar 0x8000 11
	setvar 0x8001 0x5
	special 0x158
	waitstate
	compare LASTRESULT 10
	if greaterorequal _goto EventScript_UtilityOldMan_MoveTutor
	switch LASTRESULT
	case 0,  Learn_BlastBurn
	case 1,  Learn_Chloroblast
	case 2,  Learn_FrenzyPlant
	case 3,  Learn_HydroCannon
	case 4,  Learn_LastResort
	case 5,  Learn_LeafStorm
	case 6,  Learn_MeteorBeam
	case 7,  Learn_Outrage
	case 8,  Learn_SkyAttack
	case 9,  Learn_SolarBlade
	case 10, Learn_SteelRoller
	end

@@@@@@@@@@@@@@@@@@@@@@ BADGE 1
Learn_AfterYou:
	setvar 0x8005 16
	goto EventScript_TutorScreen
	end
Learn_Bind:
	setvar 0x8005 8
	goto EventScript_TutorScreen
	end
Learn_Block:
	setvar 0x8005 10
	goto EventScript_TutorScreen
	end
Learn_Coaching:
	setvar 0x8005 141
	goto EventScript_TutorScreen
	end
Learn_Confide:
	setvar 0x8005 57
	goto EventScript_TutorScreen
	end
Learn_DualChop:
	setvar 0x8005 49
	goto EventScript_TutorScreen
	end
Learn_DualWingbeat:
	setvar 0x8005 144
	goto EventScript_TutorScreen
	end
Learn_FireSpin:
	setvar 0x8005 82
	goto EventScript_TutorScreen
	end
Learn_FocusEnergy:
	setvar 0x8005 64
	goto EventScript_TutorScreen
	end
Learn_GastroAcid:
	setvar 0x8005 40
	goto EventScript_TutorScreen
	end
Learn_HelpingHand:
	setvar 0x8005 9
	goto EventScript_TutorScreen
	end
Learn_IcicleSpear:
	setvar 0x8005 85
	goto EventScript_TutorScreen
	end
Learn_LaserFocus:
	setvar 0x8005 33
	goto EventScript_TutorScreen
	end
Learn_PinMissile:
	setvar 0x8005 84
	goto EventScript_TutorScreen
	end
Learn_RockBlast:
	setvar 0x8005 87
	goto EventScript_TutorScreen
	end
Learn_RolePlay:
	setvar 0x8005 24
	goto EventScript_TutorScreen
	end
Learn_SandTomb:
	setvar 0x8005 83
	goto EventScript_TutorScreen
	end
Learn_ScaleShot:
	setvar 0x8005 130
	goto EventScript_TutorScreen
	end
Learn_ScaryFace:
	setvar 0x8005 70
	goto EventScript_TutorScreen
	end
Learn_Snatch:
	setvar 0x8005 14
	goto EventScript_TutorScreen
	end
Learn_Snore:
	setvar 0x8005 3
	goto EventScript_TutorScreen
	end
Learn_StoredPower:
	setvar 0x8005 97
	goto EventScript_TutorScreen
	end
Learn_TailSlap:
	setvar 0x8005 86
	goto EventScript_TutorScreen
	end
Learn_TripleAxel:
	setvar 0x8005 143
	goto EventScript_TutorScreen
	end
Learn_VacuumWave:
	setvar 0x8005 55
	goto EventScript_TutorScreen
	end
Learn_VenomDrench:
	setvar 0x8005 71
	goto EventScript_TutorScreen
	end
Learn_Whirlpool:
	setvar 0x8005 81
	goto EventScript_TutorScreen
	end
Learn_WorrySeed:
	setvar 0x8005 11
	goto EventScript_TutorScreen
	end

@@@@@@@@@@@@@@@@@@@@@@ BADGE 2
Learn_BarbBarrage:
	setvar 0x8005 157
	goto EventScript_TutorScreen
	end
Learn_BreakingSwipe:
	setvar 0x8005 98
	goto EventScript_TutorScreen
	end
Learn_BugBite:
	setvar 0x8005 13
	goto EventScript_TutorScreen
	end
Learn_Covet:
	setvar 0x8005 12
	goto EventScript_TutorScreen
	end
Learn_Electroball:
	setvar 0x8005 96
	goto EventScript_TutorScreen
	end
Learn_Electroweb:
	setvar 0x8005 5
	goto EventScript_TutorScreen
	end
Learn_Encore:
	setvar 0x8005 67
	goto EventScript_TutorScreen
	end
Learn_Endeavor:
	setvar 0x8005 29
	goto EventScript_TutorScreen
	end
Learn_FireFang:
	setvar 0x8005 90
	goto EventScript_TutorScreen
	end
Learn_FlipTurn:
	setvar 0x8005 11
	goto EventScript_TutorScreen
	end
Learn_GrassyGlide:
	setvar 0x8005 133
	goto EventScript_TutorScreen
	end
Learn_IceFang:
	setvar 0x8005 89
	goto EventScript_TutorScreen
	end
Learn_IcyWind:
	setvar 0x8005 30
	goto EventScript_TutorScreen
	end
Learn_InfernalParade:
	setvar 0x8005 162
	goto EventScript_TutorScreen
	end
Learn_IronDefense:
	setvar 0x8005 20
	goto EventScript_TutorScreen
	end
Learn_LowKick:
	setvar 0x8005 6
	goto EventScript_TutorScreen
	end
Learn_MagnetRise:
	setvar 0x8005 22
	goto EventScript_TutorScreen
	end
Learn_PainSplit:
	setvar 0x8005 27
	goto EventScript_TutorScreen
	end
Learn_Reversal:
	setvar 0x8005 95
	goto EventScript_TutorScreen
	end
Learn_Screech:
	setvar 0x8005 68
	goto EventScript_TutorScreen
	end
Learn_Spikes:
	setvar 0x8005 72
	goto EventScript_TutorScreen
	end
Learn_StoneAxe:
	setvar 0x8005 149
	goto EventScript_TutorScreen
	end
Learn_SuperFang:
	setvar 0x8005 42
	goto EventScript_TutorScreen
	end
Learn_Synthesis:
	setvar 0x8005 17
	goto EventScript_TutorScreen
	end
Learn_TerrainPulse:
	setvar 0x8005 135
	goto EventScript_TutorScreen
	end
Learn_ThunderFang:
	setvar 0x8005 88
	goto EventScript_TutorScreen
	end
Learn_ToxicSpikes:
	setvar 0x8005 73
	goto EventScript_TutorScreen
	end
Learn_WeatherBall:
	setvar 0x8005 101
	goto EventScript_TutorScreen
	end

@@@@@@@@@@@@@@@@@@@@@@ BADGE 3
Learn_BurningJealousy:
	setvar 0x8005 137
	goto EventScript_TutorScreen
	end
Learn_CeaselessEdge:
	setvar 0x8005 163
	goto EventScript_TutorScreen
	end
Learn_CorrosiveGas:
	setvar 0x8005 140
	goto EventScript_TutorScreen
	end
Learn_CrossPoison:
	setvar 0x8005 106
	goto EventScript_TutorScreen
	end
Learn_ElectricTerrain:
	setvar 0x8005 79
	goto EventScript_TutorScreen
	end
Learn_FakeTears:
	setvar 0x8005 69
	goto EventScript_TutorScreen
	end
Learn_FirePunch:
	setvar 0x8005 0
	goto EventScript_TutorScreen
	end
Learn_GrassyTerrain:
	setvar 0x8005 77
	goto EventScript_TutorScreen
	end
Learn_Hex:
	setvar 0x8005 100
	goto EventScript_TutorScreen
	end
Learn_IcePunch:
	setvar 0x8005 1
	goto EventScript_TutorScreen
	end
Learn_KnockOff:
	setvar 0x8005 53
	goto EventScript_TutorScreen
	end
Learn_MagicCoat:
	setvar 0x8005 36
	goto EventScript_TutorScreen
	end
Learn_MagicRoom:
	setvar 0x8005 37
	goto EventScript_TutorScreen
	end
Learn_MistyTerrain:
	setvar 0x8005 78
	goto EventScript_TutorScreen
	end
Learn_MysticalPower:
	setvar 0x8005 150
	goto EventScript_TutorScreen
	end
Learn_PsychUp:
	setvar 0x8005 54
	goto EventScript_TutorScreen
	end
Learn_PsychicTerrain:
	setvar 0x8005 80
	goto EventScript_TutorScreen
	end
Learn_PsychoCut:
	setvar 0x8005 118
	goto EventScript_TutorScreen
	end
Learn_PsyshieldBash:
	setvar 0x8005 147
	goto EventScript_TutorScreen
	end
Learn_RazorShell:
	setvar 0x8005 99
	goto EventScript_TutorScreen
	end
Learn_RisingVoltage:
	setvar 0x8005 134
	goto EventScript_TutorScreen
	end
Learn_ScorchingSands:
	setvar 0x8005 145
	goto EventScript_TutorScreen
	end
Learn_SkitterSmack:
	setvar 0x8005 136
	goto EventScript_TutorScreen
	end
Learn_Spite:
	setvar 0x8005 15
	goto EventScript_TutorScreen
	end
Learn_Telekinesis:
	setvar 0x8005 21
	goto EventScript_TutorScreen
	end
Learn_ThunderPunch:
	setvar 0x8005 2
	goto EventScript_TutorScreen
	end
Learn_Trick:
	setvar 0x8005 34
	goto EventScript_TutorScreen
	end
Learn_WonderRoom:
	setvar 0x8005 38
	goto EventScript_TutorScreen
	end

@@@@@@@@@@@@@@@@@@@@@@ BADGE 4
Learn_Agility:
	setvar 0x8005 75
	goto EventScript_TutorScreen
	end
Learn_AirSlash:
	setvar 0x8005 102
	goto EventScript_TutorScreen
	end
Learn_AuraSphere:
	setvar 0x8005 103
	goto EventScript_TutorScreen
	end
Learn_BatonPass:
	setvar 0x8005 66
	goto EventScript_TutorScreen
	end
Learn_BitterMalice:
	setvar 0x8005 159
	goto EventScript_TutorScreen
	end
Learn_BodyPress:
	setvar 0x8005 92
	goto EventScript_TutorScreen
	end
Learn_CosmicPower:
	setvar 0x8005 65
	goto EventScript_TutorScreen
	end
Learn_DireClaw:
	setvar 0x8005 146
	goto EventScript_TutorScreen
	end
Learn_DragonDance:
	setvar 0x8005 74
	goto EventScript_TutorScreen
	end
Learn_DrillRun:
	setvar 0x8005 35
	goto EventScript_TutorScreen
	end
Learn_EsperWing:
	setvar 0x8005 158
	goto EventScript_TutorScreen
	end
Learn_FirePledge:
	setvar 0x8005 59
	goto EventScript_TutorScreen
	end
Learn_GrassPledge:
	setvar 0x8005 58
	goto EventScript_TutorScreen
	end
Learn_Gravity:
	setvar 0x8005 19
	goto EventScript_TutorScreen
	end
Learn_HealBell:
	setvar 0x8005 4
	goto EventScript_TutorScreen
	end
Learn_HeatCrash:
	setvar 0x8005 93
	goto EventScript_TutorScreen
	end
Learn_HeavySlam:
	setvar 0x8005 94
	goto EventScript_TutorScreen
	end
Learn_LashOut:
	setvar 0x8005 138
	goto EventScript_TutorScreen
	end
Learn_LunarBlessing:
	setvar 0x8005 168
	goto EventScript_TutorScreen
	end
Learn_MysticalFire:
	setvar 0x8005 112
	goto EventScript_TutorScreen
	end
Learn_NastyPlot:
	setvar 0x8005 76
	goto EventScript_TutorScreen
	end
Learn_SeedBomb:
	setvar 0x8005 32
	goto EventScript_TutorScreen
	end
Learn_SignalBeam:
	setvar 0x8005 18
	goto EventScript_TutorScreen
	end
Learn_StompingTantrum:
	setvar 0x8005 46
	goto EventScript_TutorScreen
	end
Learn_Tailwind:
	setvar 0x8005 28
	goto EventScript_TutorScreen
	end
Learn_TakeHeart:
	setvar 0x8005 169
	goto EventScript_TutorScreen
	end
Learn_VictoryDance:
	setvar 0x8005 155
	goto EventScript_TutorScreen
	end
Learn_WaterPledge:
	setvar 0x8005 60
	goto EventScript_TutorScreen
	end

@@@@@@@@@@@@@@@@@@@@@@ BADGE 5
Learn_AquaTail:
	setvar 0x8005 26
	goto EventScript_TutorScreen
	end
Learn_BlazeKick:
	setvar 0x8005 104
	goto EventScript_TutorScreen
	end
Learn_BodySlam:
	setvar 0x8005 91
	goto EventScript_TutorScreen
	end
Learn_Bounce:
	setvar 0x8005 23
	goto EventScript_TutorScreen
	end
Learn_Crunch:
	setvar 0x8005 107
	goto EventScript_TutorScreen
	end
Learn_DarkestLariat:
	setvar 0x8005 108
	goto EventScript_TutorScreen
	end
Learn_ExpandingForce:
	setvar 0x8005 128
	goto EventScript_TutorScreen
	end
Learn_HyperVoice:
	setvar 0x8005 51
	goto EventScript_TutorScreen
	end
Learn_IronHead:
	setvar 0x8005 25
	goto EventScript_TutorScreen
	end
Learn_Liquidation:
	setvar 0x8005 39
	goto EventScript_TutorScreen
	end
Learn_PowerGem:
	setvar 0x8005 116
	goto EventScript_TutorScreen
	end
Learn_PsychicFangs:
	setvar 0x8005 117
	goto EventScript_TutorScreen
	end
Learn_ThroatChop:
	setvar 0x8005 45
	goto EventScript_TutorScreen
	end
Learn_Uproar:
	setvar 0x8005 7
	goto EventScript_TutorScreen
	end
Learn_ZenHeadbutt:
	setvar 0x8005 31
	goto EventScript_TutorScreen
	end

@@@@@@@@@@@@@@@@@@@@@@ BADGE 6
Learn_BleakwindStorm:
	setvar 0x8005 164
	goto EventScript_TutorScreen
	end
Learn_BugBuzz:
	setvar 0x8005 105
	goto EventScript_TutorScreen
	end
Learn_EarthPower:
	setvar 0x8005 47
	goto EventScript_TutorScreen
	end
Learn_FoulPlay:
	setvar 0x8005 41
	goto EventScript_TutorScreen
	end
Learn_HeatWave:
	setvar 0x8005 50
	goto EventScript_TutorScreen
	end
Learn_HighHorsepower:
	setvar 0x8005 109
	goto EventScript_TutorScreen
	end
Learn_LeafBlade:
	setvar 0x8005 110
	goto EventScript_TutorScreen
	end
Learn_MuddyWater:
	setvar 0x8005 111
	goto EventScript_TutorScreen
	end
Learn_PhantomForce:
	setvar 0x8005 113
	goto EventScript_TutorScreen
	end
Learn_PlayRough:
	setvar 0x8005 114
	goto EventScript_TutorScreen
	end
Learn_PollenPuff:
	setvar 0x8005 115
	goto EventScript_TutorScreen
	end
Learn_SandsearStorm:
	setvar 0x8005 166
	goto EventScript_TutorScreen
	end
Learn_SpringtideStorm:
	setvar 0x8005 167
	goto EventScript_TutorScreen
	end
Learn_TripleArrows:
	setvar 0x8005 161
	goto EventScript_TutorScreen
	end
Learn_WindboltStorm:
	setvar 0x8005 165
	goto EventScript_TutorScreen
	end

@@@@@@@@@@@@@@@@@@@@@@ BADGE 7
Learn_BraveBird:
	setvar 0x8005 119
	goto EventScript_TutorScreen
	end
Learn_CloseCombat:
	setvar 0x8005 120
	goto EventScript_TutorScreen
	end
Learn_FlareBlitz:
	setvar 0x8005 121
	goto EventScript_TutorScreen
	end
Learn_GunkShot:
	setvar 0x8005 48
	goto EventScript_TutorScreen
	end
Learn_HeadlongRush:
	setvar 0x8005 156
	goto EventScript_TutorScreen
	end
Learn_Hurricane:
	setvar 0x8005 122
	goto EventScript_TutorScreen
	end
Learn_HydoPump:
	setvar 0x8005 123
	goto EventScript_TutorScreen
	end
Learn_MegaHorn:
	setvar 0x8005 125
	goto EventScript_TutorScreen
	end
Learn_MistyExplosion:
	setvar 0x8005 132
	goto EventScript_TutorScreen
	end
Learn_MountainGale:
	setvar 0x8005 154
	goto EventScript_TutorScreen
	end
Learn_Poltergeist:
	setvar 0x8005 139
	goto EventScript_TutorScreen
	end
Learn_PowerWhip:
	setvar 0x8005 126
	goto EventScript_TutorScreen
	end
Learn_RagingFury:
	setvar 0x8005 151
	goto EventScript_TutorScreen
	end
Learn_Superpower:
	setvar 0x8005 52
	goto EventScript_TutorScreen
	end
Learn_WaveCrash:
	setvar 0x8005 152
	goto EventScript_TutorScreen
	end

@@@@@@@@@@@@@@@@@@@@@@ BADGE 8
Learn_BlastBurn:
	setvar 0x8005 62
	goto EventScript_TutorScreen
	end
Learn_Chloroblast:
	setvar 0x8005 153
	goto EventScript_TutorScreen
	end
Learn_FrenzyPlant:
	setvar 0x8005 61
	goto EventScript_TutorScreen
	end
Learn_HydroCannon:
	setvar 0x8005 63
	goto EventScript_TutorScreen
	end
Learn_LastResort:
	setvar 0x8005 56
	goto EventScript_TutorScreen
	end
Learn_LeafStorm:
	setvar 0x8005 124
	goto EventScript_TutorScreen
	end
Learn_MeteorBeam:
	setvar 0x8005 131
	goto EventScript_TutorScreen
	end
Learn_Outrage:
	setvar 0x8005 43
	goto EventScript_TutorScreen
	end
Learn_SkyAttack:
	setvar 0x8005 44
	goto EventScript_TutorScreen
	end
Learn_SolarBlade:
	setvar 0x8005 127
	goto EventScript_TutorScreen
	end
Learn_SteelRoller:
	setvar 0x8005 129
	goto EventScript_TutorScreen
	end

EventScript_TutorScreen:
	special 0x18D
	waitstate
	compare 0x8004 0x6
	if greaterorequal _goto EventScript_UtilityOldMan_MoveTutor
	goto EventScript_End
	end

EventScript_NoBrockBadge:
	msgbox gText_EventScript_NoBrockBadge MSG_KEEPOPEN
	closeonkeypress
	goto EventScript_End
	end

EventScript_DontHaveThisBadgeYet:
	msgbox gText_EventScript_DontHaveThisBadgeYet MSG_NORMAL
	closeonkeypress
	goto EventScript_UtilityOldMan_MoveTutor
	end

@@@@@@@@@@@@@@@@@@@@@@
@ Nature Changer
@@@@@@@@@@@@@@@@@@@@@@
EventScript_UtilityOldMan_NatureChanger:
	checkflag FLAG_DEFEATED_MISTY
	if 0x0 _goto EventScript_NoMistyBadge
    msgbox gText_NatureChangerQuestion MSG_YESNO 
	compare LASTRESULT 0x1
    if 0x0 _goto EventScript_UtilityOldMan
    special 0x9F
    waitstate
    compare 0x8004 0x6
	if greaterorequal _goto EventScript_UtilityOldMan_SeeYa
	special 0x148
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_ThisIsAnEggNatureChanger
    goto EventScript_NatureList
    end

EventScript_NatureList:
    setvar 0x8000 2
    setvar 0x8001 0x6
    copyvar 0x5106 0x8004
    setvar 0x8004 0x0
    msgbox gText_WhichNature MSG_KEEPOPEN
    special 0x158
    waitstate 
    copyvar 0x8004 0x5106 
    compare LASTRESULT 0x25
    if greaterorequal _goto EventScript_UtilityOldMan_SeeYa
    copyvar 0x8005 LASTRESULT
    callasm ChangeMonNature
	sound 0x2
    goto EventScript_NatureIsChanged
    end

EventScript_NatureIsChanged:
	msgbox gText_EventScript_NatureIsChanged MSG_KEEPOPEN
	closeonkeypress
	release
	end

EventScript_NoMistyBadge:
	msgbox gText_EventScript_NoMistyBadge MSG_KEEPOPEN
	closeonkeypress
	goto EventScript_End
	end

EventScript_ThisIsAnEggNatureChanger:
	msgbox gText_EventScript_ThisIsAnEgg MSG_KEEPOPEN
	closeonkeypress
	goto EventScript_UtilityOldMan_NatureChanger
	end

@@@@@@@@@@@@@@@@@@@@@@
@ Ability Changer
@@@@@@@@@@@@@@@@@@@@@@
EventScript_UtilityOldMan_AbilityChanger:
	additem ITEM_ABILITY_CAPSULE 99
	checkflag FLAG_DEFEATED_LT_SURGE
	if 0x0 _goto EventScript_AbilityChanger_PokemonNotStrongEnough
	msgbox gText_UtilityOldMan_AbilityChanger_WantToChange MSG_YESNO
	compare LASTRESULT 0x1
	if notequal _goto EventScript_UtilityOldMan_SeeYa
	checkitem ITEM_ABILITY_CAPSULE 0x5
	compare LASTRESULT 0x1
	if notequal _goto EventScript_UtilityOldMan_AbilityChanger_NotEnoughPills
	special 0x9F
	waitstate
	copyvar 0x8006 0x8004
	compare 0x8004 0x6
	if greaterorequal _goto EventScript_UtilityOldMan_SeeYa
	special 0x148
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_ThisIsAnEggAbilityChanger
	goto EventScript_DoChangeAbility
	release
	end

EventScript_DoChangeAbility:
	msgbox gText_UtilityOldMan_AbilityChanger_LetsDoThis MSG_KEEPOPEN
	closeonkeypress
	fadescreen 0x1
	copyvar 0x8004 0x8006
	callasm ChangeMonAbility
	msgbox gText_UtilityOldMan_AbilityChanger_ChangingToHidden MSG_KEEPOPEN
	closeonkeypress
	sound 0x1
	pause 60
	fadescreen 0x0
	signbox gText_UtilityOldMan_AbilityChanger_PokemonAte MSG_KEEPOPEN
	msgbox gText_UtilityOldMan_AbilityChanger_LikedMedicine MSG_KEEPOPEN
	closeonkeypress
	removeitem ITEM_ABILITY_CAPSULE 0x5
	release
	end

EventScript_AbilityChanger_PokemonNotStrongEnough:
	msgbox gText_AbilityChanger_PokemonNotStrongEnough MSG_KEEPOPEN 
	closeonkeypress
	release
	end

EventScript_UtilityOldMan_AbilityChanger_NotEnoughPills:
	msgbox gText_UtilityOldMan_AbilityChanger_NotEnoughPills MSG_KEEPOPEN
	closeonkeypress
	release
	end

EventScript_ThisIsAnEggAbilityChanger:
	msgbox gText_EventScript_ThisIsAnEgg MSG_KEEPOPEN
	closeonkeypress
	goto EventScript_UtilityOldMan_AbilityChanger
	end

@@@@@@@@@@@@@@@@@@@@@@
@ End Script Dialogue
@@@@@@@@@@@@@@@@@@@@@@
EventScript_UtilityOldMan_SeeYa:
	msgbox gText_EventScript_ComeAgain MSG_KEEPOPEN
	closeonkeypress
	release
	end

EventScript_End:
	releaseall
	end
	