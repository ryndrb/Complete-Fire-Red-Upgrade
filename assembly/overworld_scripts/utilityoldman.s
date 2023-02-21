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
	textcolor 0x0
    lock
	faceplayer
    msgbox gText_EventScript_UtilityOldManGreetings MSG_KEEPOPEN
    setvar 0x8000 0xE
    setvar 0x8001 0x5
	setvar 0x8004 0x0
    special 0x158
    waitstate
    compare LASTRESULT 5
    if greaterorequal _goto EventScript_ComeAgain
    switch LASTRESULT
	case 0, EventScript_NameRater
    case 1, EventScript_MoveTutor
    case 2, EventScript_NatureChanger
	case 3, EventScript_AbilityChanger
    case 4, EventScript_ComeAgain
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Name Rater
@@@@@@@@@@@@@@@@@@@@@@
EventScript_NameRater:
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
	goto EventScript_NameRater
	end

@@@@@@@@@@@@@@@@@@@@@@
@ Move Tutor
@@@@@@@@@@@@@@@@@@@@@@
EventScript_MoveTutor:
	checkflag FLAG_DEFEATED_BROCK
	if 0x0 _goto EventScript_NoBrockBadge
	msgbox gText_SelectWhichBadge MSG_KEEPOPEN
	goto EventScript_SelectBadge
	end

EventScript_SelectBadge:
	setvar 0x8000 0x5
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
	setvar 0x8000 0x6
	setvar 0x8001 0x5
	special 0x158
	waitstate
	compare LASTRESULT 8
	if greaterorequal _goto EventScript_MoveTutor
	switch LASTRESULT 
	case 0, Learn_Spikes
	case 1, Learn_FireFang
	case 2, Learn_RazorShell
	case 3, Learn_ThunderFang
	case 4, Learn_IceFang
	case 5, Learn_LowKick
	case 6, Learn_BugBite
	case 7, Learn_Hex
	end

EventScript_SecondBadgeTutorMoves:
	checkflag FLAG_DEFEATED_MISTY
	if 0x0 _goto EventScript_DontHaveThisBadgeYet
	msgbox gText_WhichMoveDoYouWantToLearn MSG_KEEPOPEN
	setvar 0x8000 0x7
	setvar 0x8001 0x5
	special 0x158
	waitstate
	compare LASTRESULT 12
	if greaterorequal _goto EventScript_MoveTutor
	switch LASTRESULT
	case 0, Learn_Endeavor
	case 1, Learn_FirePunch
	case 2, Learn_ThunderPunch
	case 3, Learn_LeafBlade
	case 4, Learn_IcePunch
	case 5, Learn_Reversal
	case 6, Learn_ToxicSpikes
	case 7, Learn_StompingTantrum
	case 8, Learn_AirSlash
	case 9, Learn_SignalBeam
	case 10, Learn_RockBlast
	case 11, Learn_DualChop
	end

EventScript_ThirdBadgeTutorMoves:
	checkflag FLAG_DEFEATED_LT_SURGE
	if 0x0 _goto EventScript_DontHaveThisBadgeYet
	msgbox gText_WhichMoveDoYouWantToLearn MSG_KEEPOPEN
	setvar 0x8000 0x8
	setvar 0x8001 0x5
	special 0x158
	waitstate
	compare LASTRESULT 14
	if greaterorequal _goto EventScript_MoveTutor
	switch LASTRESULT
	case 0, Learn_BodySlam
	case 1, Learn_BlazeKick
	case 2, Learn_Liquidation
	case 3, Learn_ElectroWeb
	case 4, Learn_SeedBomb
	case 5, Learn_IcyWind
	case 6, Learn_VacuumWave
	case 7, Learn_TailWind
	case 8, Learn_ZenHeadbutt
	case 9, Learn_BugBuzz
	case 10, Learn_PowerGem
	case 11, Learn_KnockOff
	case 12, Learn_IronHead
	case 13, Learn_Playrough
	end

EventScript_FourthBadgeTutorMoves:
	checkflag FLAG_DEFEATED_ERIKA
	if 0x0 _goto EventScript_DontHaveThisBadgeYet
	msgbox gText_WhichMoveDoYouWantToLearn MSG_KEEPOPEN
	setvar 0x8000 0x9
	setvar 0x8001 0x5
	special 0x158
	waitstate
	compare LASTRESULT 15
	if greaterorequal _goto EventScript_MoveTutor
	switch LASTRESULT
	case 0, Learn_SuperFang
	case 1, Learn_MysticalFire
	case 2, Learn_AquaTail
	case 3, Learn_ElectricTerrain
	case 4, Learn_GrassyTerrain
	case 5, Learn_IcicleSpear
	case 6, Learn_AuraSphere
	case 7, Learn_CrossPoison
	case 8, Learn_HighHorsePower
	case 9, Learn_SkyAttack
	case 10, Learn_PsychicTerrain
	case 11, Learn_PollenPuff
	case 12, Learn_DragonDance
	case 13, Learn_Crunch
	case 14, Learn_MistyTerrrain
	end

EventScript_FifthBadgeTutorMoves:
	checkflag FLAG_DEFEATED_SABRINA
	if 0x0 _goto EventScript_DontHaveThisBadgeYet
	msgbox gText_WhichMoveDoYouWantToLearn MSG_KEEPOPEN
	setvar 0x8000 0xA
	setvar 0x8001 0x5
	special 0x158
	waitstate
	compare LASTRESULT 7
	if greaterorequal _goto EventScript_MoveTutor
	switch LASTRESULT
	case 0, Learn_HyperVoice
	case 1, Learn_HeatWave
	case 2, Learn_MuddyWater
	case 3, Learn_EarthPower
	case 4, Learn_Bounce
	case 5, Learn_PsychicFangs
	case 6, Learn_FoulPlay
	end

EventScript_SixthBadgeTutorMoves:
	checkflag FLAG_DEFEATED_KOGA
	if 0x0 _goto EventScript_DontHaveThisBadgeYet
	msgbox gText_WhichMoveDoYouWantToLearn MSG_KEEPOPEN
	setvar 0x8000 0xB
	setvar 0x8001 0x5
	special 0x158
	waitstate
	compare LASTRESULT 6
	if greaterorequal _goto EventScript_MoveTutor
	switch LASTRESULT
	case 0, Learn_BatonPass
	case 1, Learn_HeatCrash
	case 2, Learn_DrillRun
	case 3, Learn_FirePledge
	case 4, Learn_WaterPledge
	case 5, Learn_GrassPledge
	end

EventScript_SeventhBadgeTutorMoves:
	checkflag FLAG_DEFEATED_BLAINE
	if 0x0 _goto EventScript_DontHaveThisBadgeYet
	msgbox gText_WhichMoveDoYouWantToLearn MSG_KEEPOPEN
	setvar 0x8000 0xC
	setvar 0x8001 0x5
	special 0x158
	waitstate
	compare LASTRESULT 12
	if greaterorequal _goto EventScript_MoveTutor
	switch LASTRESULT
	case 0, Learn_WeatherBall
	case 1, Learn_FlareBlitz
	case 2, Learn_HydroPump
	case 3, Learn_LeafStorm
	case 4, Learn_SuperPower
	case 5, Learn_GunkShot
	case 6, Learn_BraveBird
	case 7, Learn_MegaHorn
	case 8, Learn_PhantomForce
	case 9, Learn_Outrage
	case 10, Learn_DarkestLariat
	case 11, Learn_HeavySlam
	end

EventScript_EightBadgeTutorMoves:	
	checkflag FLAG_DEFEATED_LEADER_GIOVANNI
	if 0x0 _goto EventScript_DontHaveThisBadgeYet
	msgbox gText_WhichMoveDoYouWantToLearn MSG_KEEPOPEN
	setvar 0x8000 0xD
	setvar 0x8001 0x5
	special 0x158
	waitstate
	compare LASTRESULT 10
	if greaterorequal _goto EventScript_MoveTutor
	switch LASTRESULT
	case 0, Learn_PowerWhip
	case 1, Learn_CloseCombat
	case 2, Learn_Hurricane
	case 3, Learn_PsychoCut
	case 4, Learn_BreakingSwipe
	case 5, Learn_ThroatChop
	case 6, Learn_SolarBlade
	case 7, Learn_BlastBurn
	case 8, Learn_HydroCannon
	case 9, Learn_FrenzyPlant
	end

Learn_Spikes:
	setvar 0x8005 0x48
	goto EventScript_TutorScreen
	end
Learn_FireFang:
	setvar 0x8005 0x5A
	goto EventScript_TutorScreen
	end
Learn_RazorShell:
	setvar 0x8005 0x63
	goto EventScript_TutorScreen
	end
Learn_ThunderFang:
	setvar 0x8005 0x58
	goto EventScript_TutorScreen
	end
Learn_IceFang:
	setvar 0x8005 0x59
	goto EventScript_TutorScreen
	end
Learn_LowKick:
	setvar 0x8005 0x6
	goto EventScript_TutorScreen
	end
Learn_BugBite:
	setvar 0x8005 0xD
	goto EventScript_TutorScreen
	end
Learn_Hex:
	setvar 0x8005 0x64
	goto EventScript_TutorScreen
	end

Learn_Endeavor:
	setvar 0x8005 0x1D
	goto EventScript_TutorScreen
	end
Learn_FirePunch:
	setvar 0x8005 0x0
	goto EventScript_TutorScreen
	end
Learn_ThunderPunch:
	setvar 0x8005 0x2
	goto EventScript_TutorScreen
	end
Learn_LeafBlade:
	setvar 0x8005 0x6E
	goto EventScript_TutorScreen
	end
Learn_IcePunch:
	setvar 0x8005 0x1
	goto EventScript_TutorScreen
	end
Learn_Reversal:
	setvar 0x8005 0x5F
	goto EventScript_TutorScreen
	end
Learn_ToxicSpikes:
	setvar 0x8005 0x49
	goto EventScript_TutorScreen
	end
Learn_StompingTantrum:
	setvar 0x8005 0x2E
	goto EventScript_TutorScreen
	end
Learn_AirSlash:
	setvar 0x8005 0x66
	goto EventScript_TutorScreen
	end
Learn_SignalBeam:
	setvar 0x8005 0x12
	goto EventScript_TutorScreen
	end
Learn_RockBlast:
	setvar 0x8005 0x57
	goto EventScript_TutorScreen
	end
Learn_DualChop:
	setvar 0x8005 0x31
	goto EventScript_TutorScreen
	end

Learn_BodySlam:
	setvar 0x8005  0x5B
	goto EventScript_TutorScreen
	end
Learn_BlazeKick:
	setvar 0x8005  0x68
	goto EventScript_TutorScreen
	end
Learn_Liquidation:
	setvar 0x8005  0x27
	goto EventScript_TutorScreen
	end
Learn_ElectroWeb:
	setvar 0x8005  0x5
	goto EventScript_TutorScreen
	end
Learn_SeedBomb:
	setvar 0x8005  0x20
	goto EventScript_TutorScreen
	end
Learn_IcyWind:
	setvar 0x8005  0x1E
	goto EventScript_TutorScreen
	end
Learn_VacuumWave:
	setvar 0x8005  0x37
	goto EventScript_TutorScreen
	end
Learn_TailWind:
	setvar 0x8005  0x1C
	goto EventScript_TutorScreen
	end
Learn_ZenHeadbutt:
	setvar 0x8005  0x1F
	goto EventScript_TutorScreen
	end
Learn_BugBuzz:
	setvar 0x8005  0x69
	goto EventScript_TutorScreen
	end
Learn_PowerGem:
	setvar 0x8005  0x74
	goto EventScript_TutorScreen
	end
Learn_KnockOff:
	setvar 0x8005  0x35
	goto EventScript_TutorScreen
	end
Learn_IronHead:
	setvar 0x8005  0x19
	goto EventScript_TutorScreen
	end
Learn_Playrough:
	setvar 0x8005  0x72
	goto EventScript_TutorScreen
	end

Learn_SuperFang:
	setvar 0x8005  0x2A
	goto EventScript_TutorScreen
	end
Learn_MysticalFire:
	setvar 0x8005  0x70
	goto EventScript_TutorScreen
	end
Learn_AquaTail:
	setvar 0x8005  0x1A
	goto EventScript_TutorScreen
	end
Learn_ElectricTerrain:
	setvar 0x8005  0x4F
	goto EventScript_TutorScreen
	end
Learn_GrassyTerrain:
	setvar 0x8005  0x4D
	goto EventScript_TutorScreen
	end
Learn_IcicleSpear:
	setvar 0x8005  0x55
	goto EventScript_TutorScreen
	end
Learn_AuraSphere:
	setvar 0x8005  0x67
	goto EventScript_TutorScreen
	end
Learn_CrossPoison:
	setvar 0x8005  0x6A
	goto EventScript_TutorScreen
	end
Learn_HighHorsePower:
	setvar 0x8005  0x6D
	goto EventScript_TutorScreen
	end
Learn_SkyAttack:
	setvar 0x8005  0x2C
	goto EventScript_TutorScreen
	end
Learn_PsychicTerrain:
	setvar 0x8005  0x50
	goto EventScript_TutorScreen
	end
Learn_PollenPuff:
	setvar 0x8005  0x73
	goto EventScript_TutorScreen
	end
Learn_DragonDance:
	setvar 0x8005  0x4A
	goto EventScript_TutorScreen
	end
Learn_Crunch:
	setvar 0x8005  0x6B
	goto EventScript_TutorScreen
	end
Learn_MistyTerrrain:
	setvar 0x8005  0x4E
	goto EventScript_TutorScreen
	end

Learn_HyperVoice:
	setvar 0x8005  0x33
	goto EventScript_TutorScreen
	end
Learn_HeatWave:
	setvar 0x8005  0x32
	goto EventScript_TutorScreen
	end
Learn_MuddyWater:
	setvar 0x8005  0x6F
	goto EventScript_TutorScreen
	end
Learn_EarthPower:
	setvar 0x8005  0x2F
	goto EventScript_TutorScreen
	end
Learn_Bounce:
	setvar 0x8005  0x17
	goto EventScript_TutorScreen
	end
Learn_PsychicFangs:
	setvar 0x8005  0x75
	goto EventScript_TutorScreen
	end
Learn_FoulPlay:
	setvar 0x8005  0x29
	goto EventScript_TutorScreen
	end

Learn_BatonPass:
	setvar 0x8005  0x42
	goto EventScript_TutorScreen
	end
Learn_HeatCrash:
	setvar 0x8005  0x5D
	goto EventScript_TutorScreen
	end
Learn_DrillRun:
	setvar 0x8005  0x23
	goto EventScript_TutorScreen
	end
Learn_FirePledge:
	setvar 0x8005  0x3B
	goto EventScript_TutorScreen
	end
Learn_WaterPledge:
	setvar 0x8005  0x3C
	goto EventScript_TutorScreen
	end
Learn_GrassPledge:
	setvar 0x8005  0x3A
	goto EventScript_TutorScreen
	end

Learn_WeatherBall:
	setvar 0x8005  0x65
	goto EventScript_TutorScreen
	end
Learn_FlareBlitz:
	setvar 0x8005  0x79
	goto EventScript_TutorScreen
	end
Learn_HydroPump:
	setvar 0x8005  0x7B
	goto EventScript_TutorScreen
	end
Learn_LeafStorm:
	setvar 0x8005  0x7C
	goto EventScript_TutorScreen
	end
Learn_SuperPower:
	setvar 0x8005  0x35
	goto EventScript_TutorScreen
	end
Learn_GunkShot:
	setvar 0x8005  0x30
	goto EventScript_TutorScreen
	end
Learn_BraveBird:
	setvar 0x8005  0x77
	goto EventScript_TutorScreen
	end
Learn_MegaHorn:
	setvar 0x8005  0x7D
	goto EventScript_TutorScreen
	end
Learn_PhantomForce:
	setvar 0x8005  0x71
	goto EventScript_TutorScreen
	end
Learn_Outrage:
	setvar 0x8005  0x2B
	goto EventScript_TutorScreen
	end
Learn_DarkestLariat:
	setvar 0x8005  0x6C
	goto EventScript_TutorScreen
	end
Learn_HeavySlam:
	setvar 0x8005  0x5E
	goto EventScript_TutorScreen
	end

Learn_PowerWhip:
	setvar 0x8005  0x7E
	goto EventScript_TutorScreen
	end
Learn_CloseCombat:
	setvar 0x8005  0x78
	goto EventScript_TutorScreen
	end
Learn_Hurricane:
	setvar 0x8005  0x7A
	goto EventScript_TutorScreen
	end
Learn_PsychoCut:
	setvar 0x8005  0x76
	goto EventScript_TutorScreen
	end
Learn_BreakingSwipe:
	setvar 0x8005  0x62
	goto EventScript_TutorScreen
	end
Learn_ThroatChop:
	setvar 0x8005  0x2D
	goto EventScript_TutorScreen
	end
Learn_SolarBlade:
	setvar 0x8005  0x7F
	goto EventScript_TutorScreen
	end
Learn_BlastBurn:
	setvar 0x8005  0x3E
	goto EventScript_TutorScreen
	end
Learn_HydroCannon:
	setvar 0x8005  0x3F
	goto EventScript_TutorScreen
	end
Learn_FrenzyPlant:
	setvar 0x8005  0x3D
	goto EventScript_TutorScreen
	end

EventScript_TutorScreen:
	special 0x18D
	waitstate
	compare 0x8004 0x6
	if greaterorequal _goto EventScript_MoveTutor
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
	goto EventScript_MoveTutor
	end

@@@@@@@@@@@@@@@@@@@@@@
@ Nature Changer
@@@@@@@@@@@@@@@@@@@@@@
EventScript_NatureChanger:
	sound 0x2
	checkflag FLAG_DEFEATED_MISTY
	if 0x0 _goto EventScript_NoMistyBadge
    msgbox gText_NatureChangerQuestion MSG_YESNO 
	compare LASTRESULT 0x1
    if 0x0 _goto EventScript_UtilityOldMan
    special 0x9F
    waitstate
    compare 0x8004 0x6
	if greaterorequal _goto EventScript_ComeAgain
	special 0x148
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_ThisIsAnEggNatureChanger
    goto EventScript_NatureList
    end

EventScript_NatureList:
    setvar 0x8000 0x2
    setvar 0x8001 0x6
    copyvar 0x5106 0x8004
    setvar 0x8004 0x0
    msgbox gText_WhichNature MSG_KEEPOPEN
    special 0x158
    waitstate 
    copyvar 0x8004 0x5106 
    compare LASTRESULT 0x25
    if greaterorequal _goto EventScript_ComeAgain
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
	goto EventScript_NatureChanger
	end

@@@@@@@@@@@@@@@@@@@@@@
@ Ability Changer
@@@@@@@@@@@@@@@@@@@@@@
EventScript_AbilityChanger:
	sound 0x2
	checkflag FLAG_DEFEATED_LT_SURGE
	if 0x0 _goto EventScript_NoSurgeBadge
	msgbox gText_AbilityChangerQuestion MSG_YESNO
	compare LASTRESULT 0x1
	if 0x0 _goto EventScript_ComeAgain
	special 0x9F
	waitstate
	copyvar 0x8006 0x8004
	compare 0x8004 0x6
	if greaterorequal _goto EventScript_ComeAgain
	special 0x148
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_ThisIsAnEggAbilityChanger
	goto EventScript_DoChangeAbility
	release
	end

EventScript_DoChangeAbility:
	callasm DisplayCurrentMonAbility
	msgbox gText_WhichAbility MSG_KEEPOPEN
	setvar 0x8000 0x3
	setvar 0x8001 0x3
	copyvar 0x5106 0x8004
	setvar 0x8004 0x0
	special 0x158
	waitstate
	copyvar 0x8004 0x5106
	compare LASTRESULT 0x3
	if greaterorequal _goto EventScript_ComeAgain
	copyvar 0x8005 LASTRESULT
	switch LASTRESULT
	case 0, EventScript_SelectedAbility 
	case 1, EventScript_SelectedAbility
	case 2, EventScript_SelectedAbility
	release
	end

EventScript_SelectedAbility:
	sound 0x2
	callasm DisplayCurrentMonAbility2
	msgbox gText_SelectedAbility MSG_YESNO
	compare LASTRESULT 0x1
	if 0x0 _goto EventScript_DoChangeAbility
	copyvar 0x8004 0x8006
	callasm ChangeMonAbility
	msgbox gText_FeedingAbilityPill MSG_KEEPOPEN
	sound 0x2
	msgbox gText_AbilityChangedSucessful MSG_KEEPOPEN
	release
	end

EventScript_NoSurgeBadge:
	msgbox gText_EventScript_NoSurgeBadge MSG_KEEPOPEN 
	closeonkeypress
	goto EventScript_End
	end

EventScript_ThisIsAnEggAbilityChanger:
	msgbox gText_EventScript_ThisIsAnEgg MSG_KEEPOPEN
	closeonkeypress
	goto EventScript_AbilityChanger
	end

@@@@@@@@@@@@@@@@@@@@@@
@ End Script Dialogue
@@@@@@@@@@@@@@@@@@@@@@
EventScript_ComeAgain:
	msgbox gText_EventScript_ComeAgain MSG_KEEPOPEN
	closeonkeypress
	release
	end

EventScript_End:
	releaseall
	end
	