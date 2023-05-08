.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ VAR_MEW_VERMILLION_CITY_ENCOUNTER, 0x5014
.equ VAR_VERMILLION_CITY_GYM_LOCKED, 0x5044
.equ VAR_ENCOUNTER_VERMILLION_KALOS_MEGARING, 0x503F
.equ FLAG_BRENDAN_VERMILLION_ENCOUTER, 0x935
.equ FLAG_BRENDAN_VERMILLION_SPRITE, 0x936
.equ FLAG_BRENDAN_UNCLE_VERMILLION_SPRITE, 0x937
.equ FLAG_BRENDAN_CERULEAN_SPRITE, 0x938
.equ FLAG_CAP_RIVALSSANNE, 0x945
.equ FLAG_OBTAIN_MANECTITE, 0x95E
.equ FLAG_OBTAIN_EVIOLITE, 0x973

@@@@@@@@@@@@@@@@@@@@@@
@ Surge
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymLeaderSurge:
    setvar 0x8004 0x4
    setvar 0x8005 0x2
    special 0x174
    call LtSurgeNameBox
    trainerbattle1 0x1 0x1A0 0x0 0x8194BA4 0x8194E03 EventScript_0x816B97C
    callasm RemoveNameBox
    checkflag 0x231
    if 0x0 _goto EventScript_0x816B9AF
    call LtSurgeNameBox
    msgbox 0x8194C8E MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x816B97C:
    setvar 0x8004 0x4
    setvar 0x8005 0x1
    special 0x173
    clearflag 0xA0
    setflag 0x4B2
    setflag 0x822
    setvar 0x8008 0x3
    call 0x81A6B18
    goto EventScript_0x816B9AF
    end

EventScript_0x816B9AF:
    call LtSurgeNameBox
    msgbox 0x8194CFA MSG_KEEPOPEN
    callasm RemoveNameBox
    checkitemspace 0x142 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816B9F0
    giveitem_msg 0x8194D87 ITEM_TM34
    setflag 0x231
    call LtSurgeNameBox
    msgbox 0x8194DA8 MSG_KEEPOPEN
    callasm RemoveNameBox
    clearflag 0xA1
    setvar VAR_ENCOUNTER_VERMILLION_KALOS_MEGARING 0x1
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Manectite | Vermillion City | Gym Guy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymGuyManectite:
    lock
    faceplayer
    checkflag 0x4B2
    if 0x1 _goto EventScript_GiveManectite
    msgbox 0x8191298 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x816A689
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816A697
    end

EventScript_GiveManectite:
    checkflag FLAG_OBTAIN_MANECTITE
    if 0x1 _goto Obtained
    msgbox gText_GymGuyGiveStone MSG_KEEPOPEN
    giveitem ITEM_MANECTITE 0x1 MSG_OBTAIN
    bufferitem 0x0 ITEM_MANECTITE
    bufferpokemon 0x1 SPECIES_MANECTRIC
    msgbox gText_ObtainedStone MSG_KEEPOPEN
    setflag FLAG_OBTAIN_MANECTITE
    release
    end

Obtained:
    goto 0x816A67F
    end

@@@@@@@@@@@@@@@@@@@@
@ Eviolite
@@@@@@@@@@@@@@@@@@@@
EventScript_Eviolite:
    lock
    faceplayer
    checkflag FLAG_OBTAIN_EVIOLITE
    if 0x0 _goto EventScript_GiveEviolite
    msgbox gText_GenericDialogue MSG_FACE
    end

EventScript_GiveEviolite:
    msgbox gText_EventScript_GiveEviolite MSG_FACE
    applymovement 0x2 EventScript_GiveEvioliteNPCMove
    waitmovement 0x2
    msgbox gText_EventScript_GiveEviolite2 MSG_FACE
    giveitem ITEM_EVIOLITE 0x1 MSG_OBTAIN
    msgbox gText_EventScript_GiveEviolite3 MSG_FACE
    setflag FLAG_OBTAIN_EVIOLITE
    release
    end

EventScript_GiveEvioliteNPCMove:
    .byte exclaim
    .byte end_m

@@@@@@@@@@@@@@@@@@@@
@ Power Items Seller Old Man
@@@@@@@@@@@@@@@@@@@@
EventScript_PowerItemsSeller:
    lock
    faceplayer
    msgbox gText_EventScript_PowerItemsSeller MSG_KEEPOPEN
    pokemart EventScript_PowerItemsList
    msgbox gText_PowerItemsSelleComeAgain MSG_KEEPOPEN
    release
    end

.align 1
EventScript_PowerItemsList:
    .hword ITEM_POWER_ANKLET
    .hword ITEM_POWER_BAND
    .hword ITEM_POWER_BELT
    .hword ITEM_POWER_BRACER
    .hword ITEM_POWER_LENS
    .hword ITEM_POWER_WEIGHT
    .hword 0x0

@@@@@@@@@@@@@@@@@@@@
@ Mew Under Truck | Req. Champion | Re-battle if not beat or catch
@@@@@@@@@@@@@@@@@@@@
EventScript_MewUnderTruckEncounter:
    lock
    call EventScript_ReturnMewEvent
    checkflag 0x4BC
    if 0x1 _goto EventScript_MewEncounter
    release
    end

EventScript_ReturnMewEvent:
    applymovement PLAYER EventScript_PlayerMovementMew1
    waitmovement 0x0
    pause 30
    msgbox gText_SomethingHere MSG_FACE
    return

EventScript_MewEncounter:
    applymovement PLAYER EventScript_PlayerMovementMew2
    waitmovement 0x0
    pause 30
    cry SPECIES_MEW 0x0
    msgbox gText_MewString MSG_KEEPOPEN
    wildbattle SPECIES_MEW 30 0x0
    fadescreen 0x1
    hidesprite 0x9
    fadescreen 0x0
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_DidNotBeatCatchMew
    setvar VAR_MEW_VERMILLION_CITY_ENCOUNTER 0x1
    release
    end

EventScript_PlayerMovementMew1:
    .byte say_question
    .byte look_left
    .byte end_m

EventScript_PlayerMovementMew2:
    .byte exclaim
    .byte end_m

EventScript_DidNotBeatCatchMew:
    release
    end

@@@@@@@@@@@@@@@@@@@@
@ Vermillion City TM Merchant
@@@@@@@@@@@@@@@@@@@@
EventScript_VermillionTMMerchant:
    lock
    faceplayer
    msgbox gText_VermillionTMMerchantGreet MSG_KEEPOPEN
    pokemart EventScript_VermillionTMMerchantList
    msgbox gText_VermillionTMMerchantBye MSG_KEEPOPEN
    closeonkeypress
    release
    end

.align 1
EventScript_VermillionTMMerchantList:
    .hword ITEM_TM57
    .hword ITEM_TM58
    .hword ITEM_TM67
    .hword ITEM_TM73
    .hword ITEM_TM76
    .hword ITEM_TM78
    .hword ITEM_TM87
    .hword ITEM_TM92
    .hword ITEM_TM93
    .hword ITEM_TM96
    .hword 0x0

@@@@@@@@@@@@@@@@@@@@
@ Vermillion City Gym Door Locked
@@@@@@@@@@@@@@@@@@@@
EventScript_VermillionCityGymLocked:
    lock
    spriteface PLAYER, UP
    msgbox gText_VermillionGymLocked MSG_KEEPOPEN
    applymovement PLAYER EventScript_PlayerBack
    waitmovement PLAYER
    release
    end

EventScript_PlayerBack:
    .byte pause_short
    .byte walk_down
    .byte end_m

@@@@@@@@@@@@@@@@@@@@
@ SS Anne Captain
@@@@@@@@@@@@@@@@@@@@
EventScript_0x160B3A:
    lock
    checkflag 0x237
    if 0x1 _goto 0x8160BB5
    msgbox 0x8173646 MSG_KEEPOPEN
    preparemsg 0x8173676
    waitmsg
    fanfare 0x100
    waitfanfare
    call 0x81A6675
    pause 0x32
    applymovement 0x1 0x81A75E1
    waitmovement 0x0
    msgbox 0x81736A6 MSG_KEEPOPEN
    @additem 0x153 0x1
    @loadpointer 0x0 0x81737AF
    giveitem 0x153 0x1 MSG_OBTAIN
    msgbox 0x81737D2 MSG_KEEPOPEN
    setflag 0x237
    setvar VAR_VERMILLION_CITY_GYM_LOCKED 0x1
    setvar 0x407E 0x1
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Brendan and his uncle in Vermillion Gym
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Vermillion_Brendan:
    lock
    playsong 0x1D5
    checkflag FLAG_BRENDAN_VERMILLION_ENCOUTER
    if SET _goto EventScript_Vermillion_Brendan_AskAgain
    spriteface 0x9, RIGHT
    call BrendanNameBox
    msgbox gText_BrendanVermillionSpeaks1 MSG_KEEPOPEN
    callasm RemoveNameBox
    msgbox gText_UncleVermillionSpeaks1 MSG_KEEPOPEN
    call BrendanNameBox
    msgbox gText_BrendanVermillionSpeaks2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x9 EventScript_BrendanVermillionNoticePlayer
    waitmovement 0x9
    getplayerpos 0x8000 0x8001
    compare 0x8000 17
    if equal _call CheckPlayerY1
    compare 0x8000 20
    if equal _call CheckPlayerY2
    compare 0x8000 19
    if equal _call CheckPlayerY3
    spriteface 0x9, DOWN
    spriteface 0xA, DOWN
    call BrendanNameBox
    msgbox gText_BrendanVermillionSpeaks3 MSG_YESNO
    callasm RemoveNameBox
    compare LASTRESULT 0x1
    if 0x0 _goto PlayerAnsweredNo
    goto EventScript_Vermillion_BrendanFight
    release
    end

PlayerAnsweredNo:
    call BrendanNameBox
    msgbox gText_BrendanVermillionSpeaks4 MSG_NORMAL
    callasm RemoveNameBox
    setflag FLAG_BRENDAN_VERMILLION_ENCOUTER
    end

EventScript_Vermillion_Brendan_AskAgain:
    faceplayer
    call BrendanNameBox
    msgbox gText_BrendanVermillionSpeaks5 MSG_YESNO
    callasm RemoveNameBox
    compare LASTRESULT 0x1
    if 0x0 _goto End
    goto EventScript_Vermillion_BrendanFight
    release
    end

EventScript_Vermillion_BrendanFight:
    call BrendanNameBox
    trainerbattle1 0x1 59 0x0 gText_Vermillion_BrendanFight_Intro gText_Vermillion_BrendanFight_Lost EvenScript_Vermillion_BrendanFight_After
    release
    end

EvenScript_Vermillion_BrendanFight_After:
    playsong 0x1D5
    callasm RemoveNameBox
    applymovement 0x9 EventScript_BrendanVermillionBattleLost
    waitmovement 0x9
    spriteface 0xA, LEFT
    call BrendanNameBox
    msgbox gText_BrendanVermillionSpeaks6 MSG_KEEPOPEN
    spriteface 0x9, DOWN
    spriteface 0xA, DOWN
    msgbox gText_BrendanVermillionSpeaks7 MSG_KEEPOPEN
    spriteface 0x9, RIGHT
    spriteface 0xA, LEFT
    callasm RemoveNameBox
    msgbox gText_UncleVermillionSpeaks2 MSG_KEEPOPEN
    spriteface 0x9, DOWN
    spriteface 0xA, DOWN
    call BrendanNameBox
    msgbox gText_BrendanVermillionSpeaks8 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0xA EventScript_VermillionUncleLeaving
    applymovement 0x9 EventScript_VermillionBrendanLeaving
    waitmovement 0xA
    spriteface PLAYER, RIGHT
    applymovement 0xA EventScript_VermillionUncleBackToPlayer
    waitmovement 0xA
    msgbox gText_UncleVermillionSpeaks3 MSG_KEEPOPEN
    closeonkeypress
    applymovement 0xA EventScript_VermillionUncleFinallyLeaving
    applymovement 0x9 EventScript_VermillionBrendanFinallyLeaving
    waitmovement 0xA
    hidesprite 0x9
    hidesprite 0xA
    setflag FLAG_BRENDAN_VERMILLION_SPRITE
    setflag FLAG_BRENDAN_UNCLE_VERMILLION_SPRITE
    setflag FLAG_BRENDAN_VERMILLION_ENCOUTER
    clearflag FLAG_BRENDAN_CERULEAN_SPRITE
    fadedefaultbgm
    release
    end

End:
    release
    end

CheckPlayerY1:
    compare 0x8001 15
    if equal _call RepositionPlayer1
    return

CheckPlayerY2:
    compare 0x8001 15
    if equal _call RepositionPlayer2
    return

CheckPlayerY3:
    compare 0x8001 16
    if equal _call RepositionPlayer3
    return

RepositionPlayer1:
    applymovement PLAYER EventScript_PlayerToFaceBrendan1
    waitmovement PLAYER
    return

RepositionPlayer2:
    applymovement PLAYER EventScript_PlayerToFaceBrendan2
    waitmovement PLAYER
    return

RepositionPlayer3:
    applymovement PLAYER EventScript_PlayerToFaceBrendan3
    waitmovement PLAYER
    return

EventScript_PlayerToFaceBrendan1:
    .byte walk_down
    .byte walk_right
    .byte walk_up_onspot_fastest
    .byte end_m

EventScript_PlayerToFaceBrendan2:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_up_onspot_fastest
    .byte end_m

EventScript_PlayerToFaceBrendan3:
    .byte walk_left
    .byte walk_up_onspot_fastest

EventScript_BrendanVermillionNoticePlayer:
    .byte exclaim
    .byte end_m

EventScript_BrendanVermillionBattleLost:
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte end_m

EventScript_VermillionUncleLeaving:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte end_m

EventScript_VermillionBrendanLeaving:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte end_m

EventScript_VermillionUncleBackToPlayer:
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte exclaim
    .byte walk_down
    .byte walk_left
    .byte end_m

EventScript_VermillionUncleFinallyLeaving:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

EventScript_VermillionBrendanFinallyLeaving:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Rival SS Anne
@@@@@@@@@@@@@@@@@@@@@@
EventScript_SSAnne_Rival0:
    lockall
    setvar 0x4001 0x0
    goto EventScript_0x8160903

EventScript_SSAnne_Rival1:
    lockall
    setvar 0x4001 0x1
    goto EventScript_0x8160903

EventScript_SSAnne_Rival2:
    lockall
    setvar 0x4001 0x2
    goto EventScript_0x8160903

EventScript_0x8160903:
    sound 0x9
    pause 0x5
    playsong 0x13B 0x0
    showsprite 0x1
    pause 0xA
    applymovement 0x1 0x81A75ED
    waitmovement 0x0
    pause 0x14
    compare 0x4001 0x0
    if 0x1 _call 0x81609AD
    compare 0x4001 0x1
    if 0x1 _call 0x81609B8
    compare 0x4001 0x2
    if 0x1 _call 0x81609CA
    call RivalNameBox
    msgbox gText_SSAnne_RivalSpeak1 MSG_KEEPOPEN
    callasm RemoveNameBox
    setvar LASTTALKED 0x1
    compare 0x4031 0x2
    if 0x1 _call 0x81609DC
    compare 0x4031 0x1
    if 0x1 _call 0x81609E7
    compare 0x4031 0x0
    if 0x1 _call 0x81609F2
    call RivalNameBox
    msgbox gText_SSAnne_RivalSpeak2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    pause 0xA
    playsong 0x13C 0x0
    compare 0x4001 0x0
    if 0x1 _call 0x81609FD
    compare 0x4001 0x1
    if 0x1 _call 0x8160A08
    compare 0x4001 0x2
    if 0x1 _call 0x8160A13
    fadedefault
    hidesprite 0x1
    setvar 0x405B 0x1
    setflag FLAG_CAP_RIVALSSANNE
    releaseall
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Good Fising Rod
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Vermillion_GoodRod:
    lock
    faceplayer
    checkflag 0x244
    if 0x1 _goto 0x816D83F
    msgbox 0x819918E MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x816D849
    msgbox 0x8199337 MSG_KEEPOPEN
    release
    end

@@@@@@@@@@@@@@@@@@@@
@ Kalos Researcher Giving Mega Ring
@@@@@@@@@@@@@@@@@@@@
MapScript_Vermillion:
    mapscript MAP_SCRIPT_ON_TRANSITION MapScript_0x166906
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_0x1668F1
    .byte MAP_SCRIPT_TERMIN
    
MapScript_0x166906:
    setworldmapflag 0x895
    end

LevelScript_0x1668F1:
    levelscript 0x407E, 2, EventScript_0x1668F1
    levelscript VAR_ENCOUNTER_VERMILLION_KALOS_MEGARING, 1, EventScript_Vermillion_MegaRingResearcher
    .hword LEVEL_SCRIPT_TERMIN

EventScript_0x1668F1:
    lockall
    applymovement PLAYER 0x8166903
    waitmovement 0x0
    setvar 0x407E 0x3
    releaseall
    end

EventScript_Vermillion_MegaRingResearcher:
    lock
    pause 30
    sound 0x15
    applymovement 8 Move_Vermillion_Researcher1
    applymovement PLAYER Move_Vermillion_Player1
    waitmovement 8
    msgbox gText_Vermillion_MegaRingResearcherSpeak1 MSG_KEEPOPEN
    closeonkeypress
    call EventScript_Vermillion_CheckMegaStones
    goto EventScript_Vermillion_MegaRingResearcher2
    release
    end

EventScript_Vermillion_MegaRingResearcher2:
    pause 30
    spriteface 8, LEFT
    pause 60
    spriteface 8, UP
    msgbox gText_Vermillion_MegaRingResearcherSpeak2 MSG_KEEPOPEN
    closeonkeypress
    pause 30
    playfanfare 0x101
    giveitem ITEM_MEGA_RING 1 MSG_OBTAIN
    waitfanfare
    pause 45
    msgbox gText_Vermillion_MegaRingResearcherSpeak3 MSG_KEEPOPEN
    closeonkeypress
    applymovement 8 Move_Vermillion_Researcher2
    waitmovement 8
    hidesprite 8
    setflag 0xA1
    setvar VAR_ENCOUNTER_VERMILLION_KALOS_MEGARING 2
    release
    end

EventScript_Vermillion_CheckMegaStones:
    checkitem ITEM_AERODACTYLITE 1
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_Vermillion_PlayerHasStones
    checkitem ITEM_GYARADOSITE 1
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_Vermillion_PlayerHasStones
    checkitem ITEM_MAWILITE 1
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_Vermillion_PlayerHasStones
    return

EventScript_Vermillion_PlayerHasStones:
    sound 0x15
    applymovement 8 Move_Vermillion_Researcher3
    waitmovement 8
    msgbox gTest_gText_Vermillion_MegaRingResearcherSpeak4 MSG_KEEPOPEN
    closeonkeypress
    sound 0x15
    applymovement 8 Move_Vermillion_Researcher3
    waitmovement 8
    msgbox gTest_gText_Vermillion_MegaRingResearcherSpeak5 MSG_KEEPOPEN
    closeonkeypress
    applymovement 8 Move_Vermillion_Researcher4
    waitmovement 8
    msgbox gTest_gText_Vermillion_MegaRingResearcherSpeak6 MSG_KEEPOPEN
    closeonkeypress
    goto EventScript_Vermillion_MegaRingResearcher2
    release
    end

Move_Vermillion_Researcher1:
    .byte exclaim
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_up_onspot_fastest
    .byte end_m
    
Move_Vermillion_Player1:
    .byte pause_long
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Vermillion_Researcher2:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_Vermillion_Researcher3:
    .byte exclaim
    .byte pause_long
    .byte end_m

Move_Vermillion_Researcher4:
    .byte jump_onspot_up
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte end_m

@@@@@@@@@@@@@@@@@@@@
@ Wattson Vermillion City
@@@@@@@@@@@@@@@@@@@@
EventScript_Vermillion_Wattson:
    lock
    pause 30
    sound 0x15
    applymovement 7 Move_Vermillion_Wattson_1
    waitmovement 7
    npcmsg gText_Vermillion_Wattson_Speak_1 MSG_KEEPOPEN 0 LEFT
    closemsg
    npcmsg gText_Vermillion_Wattson_Speak_2 MSG_YESNO 34 LEFT
    compare LASTRESULT 0x1
    if notequal _goto EventScript_Vermillion_Wattson_PlayerDontWantToBattle
    closemsg
    trainerbattle3 0x3 82 0x0 gText_Vermillion_Wattson_Defeat
    npcmsg gText_Vermillion_Wattson_Speak_3 MSG_KEEPOPEN 34 LEFT
    closemsg
    giveitem ITEM_MAGNET 0x1 MSG_OBTAIN
    npcmsg gText_Vermillion_Wattson_Speak_4 MSG_KEEPOPEN 34 LEFT
    closemsg
    spriteface 7, LEFT
    spriteface 1, RIGHT
    npcmsg gText_Vermillion_Wattson_Speak_5 MSG_KEEPOPEN 34 LEFT
    closemsg
    faceplayer
    npcmsg gText_Vermillion_Wattson_Speak_6 MSG_KEEPOPEN 34 LEFT
    closemsg
    fadescreen 0x1
    hidesprite 7
    setflag FLAG_WATTSON_VERMILLION_SPRITE
    fadescreen 0x0
    release
    end

EventScript_Vermillion_Wattson_PlayerDontWantToBattle:
    npcmsg gText_Vermillion_Wattson_PlayerDontWantToBattle MSG_KEEPOPEN 34 LEFT
    closemsg
    spriteface 7, DOWN
    release
    end

Move_Vermillion_Wattson_1:
    .byte exclaim
    .byte pause_long
    .byte face_player
    .byte end_m

@@@@@@@@@@@@@@@@@@@@
@ Vermillion NameBox
@@@@@@@@@@@@@@@@@@@@
BrendanNameBox:
    setvar 0x8000 3
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

LtSurgeNameBox:
    setvar 0x8000 13
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

RivalNameBox:
    setvar 0x8000 1
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
