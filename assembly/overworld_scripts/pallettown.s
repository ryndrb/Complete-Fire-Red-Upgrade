.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_EXP_SHARE, 0x906
.equ FLAG_MINIMAL_GRINDING, 0x934
.equ FLAG_MAY_PALLETTOWN_SPRITE, 0x93A
.equ FLAG_POKEMON_RANDOMIZER, 0x940
.equ FLAG_POKEMON_LEARNSET_RANDOMIZER, 0x941
.equ FLAG_ABILITY_RANDOMIZER, 0x942
.equ FLAG_CHOOSE_REGION_KANTO, 0x9A8
.equ FLAG_CHOOSE_REGION_JOHTO, 0x9A9
.equ FLAG_CHOOSE_REGION_HOENN, 0x9AA
.equ FLAG_CHOOSE_REGION_SINNOH, 0x9AB
.equ FLAG_CHOOSE_REGION_UNOVA, 0x9AC
.equ FLAG_CHOOSE_REGION_KALOS, 0x9AD
.equ FLAG_CHOOSE_REGION_ALOLA, 0x9AE
.equ FLAG_CHOOSE_REGION_GALAR, 0x9AF
.equ FLAG_RECEIVED_POCKETPC, 0x9B0
.equ FLAG_RECEIVED_TIMETURNER, 0x9B1
.equ FLAG_RECEIVED_STATSCANNER, 0x9B2
.equ FLAG_OBTAIN_AMULET_COIN, 0x9B3
.equ FLAG_MAY_PALLET_TOWN_TALKED, 0x9BA

@@@@@@@@@@@@@@@@@@@@@@
@ Prof Aid Give Time Turner
@@@@@@@@@@@@@@@@@@@@@@
EventScript_ProfOakAidLabTimeTurner:
    textcolor BLUE
    lock
    faceplayer
    checkflag 0x82C
    if 0x1 _goto 0x8169E03
    msgbox 0x818EBE6 MSG_KEEPOPEN
    checkflag 0x829 @pokedex received?
    if 0x0 _goto EventScript_NoPokedex
    checkflag FLAG_RECEIVED_TIMETURNER
    if 0x1 _goto EventScript_ReceivedDevices
    msgbox gText_HavePokedex1 MSG_KEEPOPEN
    setflag FLAG_RECEIVED_TIMETURNER
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Prof Aid PokeStat / Stat Scanner
@@@@@@@@@@@@@@@@@@@@@@
EventScript_ProfOakAidLabStatScanner:
    textcolor BLUE
    lock
    faceplayer
    checkflag 0x82C
    if 0x1 _goto 0x8169E2F
    msgbox 0x818EBE6 MSG_KEEPOPEN
    checkflag 0x829 @pokedex received?
    if 0x0 _goto EventScript_NoPokedex
    checkflag FLAG_RECEIVED_STATSCANNER
    if 0x1 _goto EventScript_ReceivedDevices 
    msgbox gText_HavePokedex2 MSG_KEEPOPEN
    setflag FLAG_RECEIVED_STATSCANNER
    release
    end

EventScript_ReceivedDevices:
    release
    end

EventScript_NoPokedex:
    msgbox gText_EventScript_NoPokedex MSG_KEEPOPEN
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Choose Starter Region (Upto Gen 8)
@@@@@@@@@@@@@@@@@@@@@@
MapScript_ChooseStarterRegion:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_ChooseStarterRegion
    .byte MAP_SCRIPT_TERMIN

LevelScript_ChooseStarterRegion:
    levelscript 0x502A, 0, EventScript_ChooseStarterRegion
    .hword MAP_SCRIPT_TERMIN

EventScript_ChooseStarterRegion:
    textcolor RED
    setvar 0x502A 0x1
    lock
    call SETNECESSARYGAMEFLAGS
    sound 0x15
    applymovement 0x1 EventScript_MomSawYou
    waitmovement 0x1
    call MomNameBox
    msgbox gText_MomChooseRegion MSG_KEEPOPEN
    callasm RemoveNameBox
    setvar 0x8000 0xF
    setvar 0x8001 0x5
    setvar 0x8004 0x0
    special 0x158
    waitstate
    compare LASTRESULT 8
    if greaterorequal _goto EventScript_RemainKanto
    switch LASTRESULT
    case 0, EventScript_Gen1
    case 1, EventScript_Gen2
    case 2, EventScript_Gen3
    case 3, EventScript_Gen4
    case 4, EventScript_Gen5
    case 5, EventScript_Gen6
    case 6, EventScript_Gen7
    case 7, EventScript_Gen8
    end

EventScript_RemainKanto:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_KANTO
    call MomNameBox
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress 
    goto MomScript_End

EventScript_Gen1:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_KANTO
    call MomNameBox
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress
    goto MomScript_End

EventScript_Gen2:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_JOHTO
    call MomNameBox
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress
    goto MomScript_End

EventScript_Gen3:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_HOENN
    call MomNameBox
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress
    goto MomScript_End

EventScript_Gen4:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_SINNOH
    call MomNameBox
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress
    goto MomScript_End

EventScript_Gen5:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_UNOVA
    call MomNameBox
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress
    goto MomScript_End

EventScript_Gen6:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_KALOS
    call MomNameBox
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress
    goto MomScript_End

EventScript_Gen7:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_ALOLA
    call MomNameBox
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress
    goto MomScript_End

EventScript_Gen8:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_GALAR
    call MomNameBox
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress
    goto MomScript_End

MomScript_End:
    callasm RemoveNameBox
    release
    end

EventScript_MomSawYou:
    .byte exclaim
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte walk_up
    .byte walk_up
    .byte walk_right
    .byte end_m

EventScript_MomDone:
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_left_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Oak Stop Player from Leaving
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PalletTown_OakStopPlayer1:
    lockall
    setvar 0x4001 0x0
    goto EventScript_0x8165605
    end

EventScript_PalletTown_OakStopPlayer2:
    lockall
    setvar 0x4001 0x1
    goto EventScript_0x8165605
    end

EventScript_0x8165605:
    setvar 0x8004 0x0
    setvar 0x8005 0x2
    special 0x174
    textcolor 0x0
    pause 0x1E
    playsong 0x12E 0x0
    call OakNameBox
    preparemsg gText_OakStopPlayer
    waitmsg
    pause 0x55
    closeonkeypress
    callasm RemoveNameBox
    applymovement PLAYER 0x81A75ED
    waitmovement 0x0
    sound 0x15
    applymovement PLAYER 0x81A75DB
    waitmovement 0x0
    pause 0x1E
    showsprite 0x3
    compare 0x4001 0x0
    if 0x1 _call 0x81656B8
    compare 0x4001 0x1
    if 0x1 _call 0x81656C3
    pause 0x1E
    call OakNameBox
    msgbox gText_OakSayUnsafe MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    pause 0x1E
    compare 0x4001 0x0
    if 0x1 _call 0x81656CE
    compare 0x4001 0x1
    if 0x1 _call 0x81656E0
    setdooropen 0x10 0xD
    opendoor 0x10 0xD
    waitdooranim
    applymovement 0x3 0x816572E
    applymovement PLAYER 0x8165758
    waitmovement 0x0
    setdoorclosed 0x10 0xD
    closedoor 0x10 0xD
    waitdooranim
    setvar 0x4055 0x1
    clearflag 0x2B
    setvar 0x4050 0x1
    setflag 0x2C
    setflag 0x4001
    warp 0x4 0x3 0xFF 0x6 0xC
    waitstate
    releaseall
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Inside Oak Lab
@@@@@@@@@@@@@@@@@@@@@@
EventScript_InsideOakLab_DontGoAway:
    lockall
    textcolor BLUE
    applymovement 0x4 0x81A75F1
    waitmovement 0x0
    call OakNameBox
    msgbox gText_InsideOakLab_OakSpeak1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement PLAYER 0x81692E5
    waitmovement 0x0
    releaseall
    end

MapScript_InsideOakLab:
    mapscript MAP_SCRIPT_ON_TRANSITION MapScript_0x168F8E
    mapscript MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE LevelScript2_InsideOakLab
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_InsideOakLab
    .byte MAP_SCRIPT_TERMIN

MapScript_0x168F8E:
    setflag 0x2CF
    compare 0x4055 0x1
    if 0x1 _call 0x8168FC6
    compare 0x4055 0x7
    if 0x1 _call 0x8168FD5
    compare 0x4055 0x8
    if 0x1 _call 0x8168FC0
    checkflag 0x247
    if 0x1 _call 0x8168FBC
    end

LevelScript2_InsideOakLab:
    levelscript 0x4055, 1, EventScript_LevelScript2_InsideOakLab
    .hword LEVEL_SCRIPT_TERMIN

EventScript_LevelScript2_InsideOakLab:
    spriteface 0xFF 0x2
    end

LevelScript_InsideOakLab:
    levelscript 0x4055, 1, EventScript_LevelScript_InsideOakLab
    .hword LEVEL_SCRIPT_TERMIN

EventScript_LevelScript_InsideOakLab:
    lockall
    textcolor 0x0
    applymovement 0x4 0x81692B0
    waitmovement 0x0
    hidesprite 0x4
    movesprite2 0x4 0x6 0x3
    spritebehave 0x4 0x8
    clearflag 0x2B
    applymovement PLAYER 0x81692B7
    waitmovement 0x0
    applymovement 0x8 0x81A75E9
    waitmovement 0x0
    clearflag 0x4001
    playsong2 0x0
    fadedefault
    call RivalNameBox
    msgbox gText_RivalTiredWaiting MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    pause 0x3C
    call OakNameBox
    msgbox gText_OakExplaining MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    pause 0x1E
    applymovement 0x8 0x81692C0
    waitmovement 0x0
    call RivalNameBox
    msgbox gText_RivalSayNoFair MSG_KEEPOPEN
    closeonkeypress
    call OakNameBox
    msgbox gText_OakPatient MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    setvar 0x4055 0x2
    releaseall
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Choose Starter Oak Lab
@@@@@@@@@@@@@@@@@@@@@@
@ Grass
EventScript_StarterGrass:
    textcolor BLUE
    lock
    faceplayer
    setflag FLAG_MAY_PALLETTOWN_SPRITE
    checkflag FLAG_CHOOSE_REGION_KANTO
    if 0x1 _call EventScript_KantoStartersGrass
    checkflag FLAG_CHOOSE_REGION_JOHTO
    if 0x1 _call EventScript_JohtoStartersGrass
    checkflag FLAG_CHOOSE_REGION_HOENN
    if 0x1 _call EventScript_HoennStartersGrass
    checkflag FLAG_CHOOSE_REGION_SINNOH
    if 0x1 _call EventScript_SinnohStartersGrass
    checkflag FLAG_CHOOSE_REGION_UNOVA
    if 0x1 _call EventScript_UnovaStartersGrass
    checkflag FLAG_CHOOSE_REGION_KALOS
    if 0x1 _call EventScript_KalosStartersGrass
    checkflag FLAG_CHOOSE_REGION_ALOLA
    if 0x1 _call EventScript_AlolaStartersGrass
    checkflag FLAG_CHOOSE_REGION_GALAR
    if 0x1 _call EventScript_GalarStartersGrass
    setvar 0x4001 0x0
    setvar 0x4003 0x4
    setvar 0x4004 0x7
    compare 0x4055 0x3
    if 0x4 _goto 0x8169DE4
    compare 0x4055 0x2
    if 0x1 _goto EventScript_0x8169BE1
    call OakNameBox
    msgbox 0x818EA19 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    release
    end

EventScript_KantoStartersGrass:
    setvar 0x4002 0x1
    bufferpokemon 0x0 0x4002
    return

EventScript_JohtoStartersGrass:
    setvar 0x4002 0x98
    bufferpokemon 0x0 0x4002
    return

EventScript_HoennStartersGrass:
    setvar 0x4002 0x115
    bufferpokemon 0x0 0x4002
    return

EventScript_SinnohStartersGrass:
    setvar 0x4002 0x1B8
    bufferpokemon 0x0 0x4002
    return

EventScript_UnovaStartersGrass:
    setvar 0x4002 0x224
    bufferpokemon 0x0 0x4002
    return

EventScript_KalosStartersGrass:
    setvar 0x4002 0x2F6
    bufferpokemon 0x0 0x4002
    return

EventScript_AlolaStartersGrass:
    setvar 0x4002 0x3AB
    bufferpokemon 0x0 0x4002
    return

EventScript_GalarStartersGrass:
    setvar 0x4002 0x44E
    bufferpokemon 0x0 0x4002
    return

@ Water
EventScript_StarterWater:
    lock
    faceplayer
    checkflag FLAG_CHOOSE_REGION_KANTO
    if 0x1 _call EventScript_KantoStartersWater
    checkflag FLAG_CHOOSE_REGION_JOHTO
    if 0x1 _call EventScript_JohtoStartersWater
    checkflag FLAG_CHOOSE_REGION_HOENN
    if 0x1 _call EventScript_HoennStartersWater
    checkflag FLAG_CHOOSE_REGION_SINNOH
    if 0x1 _call EventScript_SinnohStartersWater
    checkflag FLAG_CHOOSE_REGION_UNOVA
    if 0x1 _call EventScript_UnovaStartersWater
    checkflag FLAG_CHOOSE_REGION_KALOS
    if 0x1 _call EventScript_KalosStartersWater
    checkflag FLAG_CHOOSE_REGION_ALOLA
    if 0x1 _call EventScript_AlolaStartersWater
    checkflag FLAG_CHOOSE_REGION_GALAR
    if 0x1 _call EventScript_GalarStartersWater
    setvar 0x4001 0x1
    setvar 0x4003 0x1
    setvar 0x4004 0x5
    compare 0x4055 0x3
    if 0x4 _goto 0x8169DE4
    compare 0x4055 0x2
    if 0x1 _goto EventScript_0x8169BE1
    call OakNameBox
    msgbox 0x818EA19 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    release
    end

EventScript_KantoStartersWater:
    setvar 0x4002 0x7
    bufferpokemon 0x0 0x4002
    return

EventScript_JohtoStartersWater:
    setvar 0x4002 0x9E
    bufferpokemon 0x0 0x4002
    return

EventScript_HoennStartersWater:
    setvar 0x4002 0x11B
    bufferpokemon 0x0 0x4002
    return

EventScript_SinnohStartersWater:
    setvar 0x4002 0x1BE
    bufferpokemon 0x0 0x4002
    return

EventScript_UnovaStartersWater:
    setvar 0x4002 0x22A
    bufferpokemon 0x0 0x4002
    return

EventScript_KalosStartersWater:
    setvar 0x4002 0x2FC
    bufferpokemon 0x0 0x4002
    return

EventScript_AlolaStartersWater:
    setvar 0x4002 0x3B1
    bufferpokemon 0x0 0x4002
    return

EventScript_GalarStartersWater:
    setvar 0x4002 0x454
    bufferpokemon 0x0 0x4002
    return

@ Fire
EventScript_StarterFire:
    lock
    faceplayer
    checkflag FLAG_CHOOSE_REGION_KANTO
    if 0x1 _call EventScript_KantoStartersFire
    checkflag FLAG_CHOOSE_REGION_JOHTO
    if 0x1 _call EventScript_JohtoStartersFire
    checkflag FLAG_CHOOSE_REGION_HOENN
    if 0x1 _call EventScript_HoennStartersFire
    checkflag FLAG_CHOOSE_REGION_SINNOH
    if 0x1 _call EventScript_SinnohStartersFire
    checkflag FLAG_CHOOSE_REGION_UNOVA
    if 0x1 _call EventScript_UnovaStartersFire
    checkflag FLAG_CHOOSE_REGION_KALOS
    if 0x1 _call EventScript_KalosStartersFire
    checkflag FLAG_CHOOSE_REGION_ALOLA
    if 0x1 _call EventScript_AlolaStartersFire
    checkflag FLAG_CHOOSE_REGION_GALAR
    if 0x1 _call EventScript_GalarStartersFire
    setvar 0x4001 0x2
    setvar 0x4003 0x7
    setvar 0x4004 0x6
    compare 0x4055 0x3
    if 0x4 _goto 0x8169DE4
    compare 0x4055 0x2
    if 0x1 _goto EventScript_0x8169BE1
    call OakNameBox
    msgbox 0x818EA19 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    release
    end

EventScript_KantoStartersFire:
    setvar 0x4002 0x4
    bufferpokemon 0x0 0x4002
    return

EventScript_JohtoStartersFire:
    setvar 0x4002 0x9B
    bufferpokemon 0x0 0x4002
    return

EventScript_HoennStartersFire:
    setvar 0x4002 0x118
    bufferpokemon 0x0 0x4002
    return

EventScript_SinnohStartersFire:
    setvar 0x4002 0x1BB
    bufferpokemon 0x0 0x4002
    return

EventScript_UnovaStartersFire:
    setvar 0x4002 0x227
    bufferpokemon 0x0 0x4002
    return

EventScript_KalosStartersFire:
    setvar 0x4002 0x2F9
    bufferpokemon 0x0 0x4002
    return

EventScript_AlolaStartersFire:
    setvar 0x4002 0x3AE
    bufferpokemon 0x0 0x4002
    return

EventScript_GalarStartersFire:
    setvar 0x4002 0x451
    bufferpokemon 0x0 0x4002
    return

EventScript_0x8169BE1:
    applymovement 0x4 0x81A75EF
    waitmovement 0x0
    showpokepic 0x4002 0xA 0x3
    textcolor BLUE
    compare 0x4001 0x0
    if 0x1 _goto EventScript_0x8169C14
    compare 0x4001 0x1
    if 0x1 _goto EventScript_0x8169C33
    compare 0x4001 0x2
    if 0x1 _goto EventScript_0x8169C52
    end

EventScript_0x8169C14:
    msgbox gText_GrassChoice MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto EventScript_0x8169C74
    compare LASTRESULT 0x0
    if 0x1 _goto 0x8169C71
    end

EventScript_0x8169C33:
    msgbox gText_WaterChoice MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto EventScript_0x8169C74
    compare LASTRESULT 0x0
    if 0x1 _goto 0x8169C71
    end

EventScript_0x8169C52:
    msgbox gText_FireChoice MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto EventScript_0x8169C74
    compare LASTRESULT 0x0
    if 0x1 _goto 0x8169C71
    end

EventScript_0x8169C74:
    hidepokepic
    hidesprite LASTTALKED
    msgbox 0x818E2E5 MSG_KEEPOPEN
    call 0x81A6675
    setflag 0x828
    setflag 0x291
    givepokemon 0x4002 0x5 0x0 0x0 0x0 0x0
    copyvar 0x4031 0x4001
    bufferpokemon 0x0 0x4002
    textcolor BLACK
    preparemsg 0x818E30D
    waitmsg
    fanfare 0x13E
    waitfanfare
    msgbox 0x81A56A7 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x8169CCC
    compare LASTRESULT 0x0
    if 0x1 _goto EventScript_0x8169CDC
    end

EventScript_0x8169CDC:
    closeonkeypress
    compare 0x4001 0x0
    if 0x1 _goto EventScript_0x169CFF
    compare 0x4001 0x1
    if 0x1 _goto EventScript_0x169D1F
    compare 0x4001 0x2
    if 0x1 _goto EventScript_0x169D0F
    end

EventScript_0x169CFF:
    applymovement 0x8 0x8169D62
    waitmovement 0x0
    goto EventScript_0x8169D2F

EventScript_0x169D1F:
    applymovement 0x8 0x8169D72
    waitmovement 0x0
    goto EventScript_0x8169D2F

EventScript_0x169D0F:
    applymovement 0x8 0x8169D6B
    waitmovement 0x0
    goto EventScript_0x8169D2F

EventScript_0x8169D2F:
    textcolor BLUE
    call RivalNameBox
    msgbox gText_RivalTakeIt MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    hidesprite 0x4004
    textcolor BLACK
    bufferpokemon 0x0 0x4003
    preparemsg 0x818DD52
    waitmsg
    fanfare 0x13E
    waitfanfare
    setvar 0x4055 0x3
    checkflag 0x83E
    if 0x1 _call 0x8169D5C
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Amulet Coin
@@@@@@@@@@@@@@@@@@@@@@
EventScript_AmuletCoin:
    textcolor BLUE
    lock
    faceplayer
    msgbox 0x817D80D MSG_KEEPOPEN
    checkflag FLAG_OBTAIN_AMULET_COIN
    if 0x0 _goto EventScript_GiveAmuletCoin
    release
    end

EventScript_GiveAmuletCoin:
    lock
    msgbox gText_EventScript_GiveAmuletCoin MSG_KEEPOPEN
    giveitem ITEM_AMULET_COIN 0x1 MSG_OBTAIN
    setflag FLAG_OBTAIN_AMULET_COIN
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Oak In Lab | National Dex 
@@@@@@@@@@@@@@@@@@@@@@
EventScript_0x169595:
    textcolor BLUE
    lock
    faceplayer
    checkflag 0x2
    if 0x1 _goto EventScript_0x8169600
    compare 0x4055 0x9
    if 0x1 _goto EventScript_0x8169903
    compare 0x4055 0x8
    if 0x1 _goto EventScript_0x8169A6E
    compare 0x4052 0x1
    if 0x1 _goto EventScript_0x8169903
    compare 0x4055 0x6
    if 0x1 _goto 0x81698D6
    compare 0x4057 0x1
    if 0x4 _goto EventScript_0x816961E
    compare 0x4055 0x4
    if 0x1 _goto 0x8169614
    compare 0x4055 0x3
    if 0x1 _goto 0x816960A
    call OakNameBox
    msgbox gText_OakSayChoosePokeball MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8169600:
    call OakNameBox
    msgbox 0x81A72AD MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8169A6E:
    call OakNameBox
    msgbox 0x818E871 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8169903:
    call EventScript_0x81A737B
    checkflag 0x2F4
    if 0x1 _goto 0x8169913
    release
    end

EventScript_0x81A737B:
    special 0x187
    compare LASTRESULT 0x2
    if 0x1 _goto 0x81A7AE0
    special 0x188
    checkflag 0x2F4
    if 0x1 _call EventScript_0x81A73A4
    checkflag 0x2F4
    if 0x0 _call EventScript_0x81A73AD
    call 0x81A73E0
    return

EventScript_0x81A73A4:
    call OakNameBox
    msgbox gText_InsideOakLab_OakSpeak2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    return

EventScript_0x81A73AD:
    call OakNameBox
    msgbox gText_InsideOakLab_OakSpeak3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    return

EventScript_0x816961E:
    call OakNameBox
    msgbox gText_PlayerDeliveredParcelToOak MSG_KEEPOPEN
    callasm RemoveNameBox
    textcolor 0x3
    fanfare 0x105
    preparemsg 0x818E4AF
    waitmsg
    waitfanfare
    call 0x81A6675
    removeitem 0x15D 0x1
    call OakNameBox
    msgbox gText_OakSayCustomPokeball MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    playsong 0x13B 0x0
    call RivalNameBox
    msgbox gText_RivalArrivedAtLab MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    compare PLAYERFACING 0x2
    if 0x1 _call 0x8169A82
    compare PLAYERFACING 0x1
    if 0x1 _call 0x8169AC1
    compare PLAYERFACING 0x4
    if 0x1 _call 0x8169A9E
    compare PLAYERFACING 0x3
    if 0x1 _call 0x8169A9E
    fadedefault
    call RivalNameBox
    msgbox gText_RivalForgotOakMessage MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    pause 0x1E
    sound 0x15
    applymovement 0x4 0x81A75DB
    waitmovement 0x0
    applymovement 0x4 0x81A75DD
    waitmovement 0x0
    compare PLAYERFACING 0x1
    if 0x1 _call 0x8169ADD
    compare PLAYERFACING 0x4
    if 0x1 _call 0x8169B14
    compare PLAYERFACING 0x3
    if 0x1 _call 0x8169AF5
    compare PLAYERFACING 0x2
    if 0x1 _call 0x8169B86
    call OakNameBox
    msgbox gText_OakSayRequest MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    compare PLAYERFACING 0x2
    if 0x1 _call 0x8169882
    compare PLAYERFACING 0x1
    if 0x1 _call 0x816988D
    compare PLAYERFACING 0x4
    if 0x1 _call 0x81698A6
    compare PLAYERFACING 0x3
    if 0x1 _call 0x81698B8
    call OakNameBox
    msgbox gText_RecentSightings MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    pause 0x28
    msgbox gText_OakGavePlayerAndRivalDex MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x4 0x81A75E9
    waitmovement 0x0
    hidesprite 0x9
    pause 0xA
    hidesprite 0xA
    pause 0x19
    compare PLAYERFACING 0x2
    if 0x1 _call 0x8169845
    compare PLAYERFACING 0x1
    if 0x1 _call 0x8169850
    compare PLAYERFACING 0x4
    if 0x1 _call 0x816985B
    compare PLAYERFACING 0x3
    if 0x1 _call 0x816986D
    pause 0xA
    textcolor 0x3
    fanfare 0x13E
    preparemsg 0x818E5EA
    waitmsg
    waitfanfare
    call 0x81A6675
    setflag 0x829
    special 0x16F
    special 0x181
    setvar 0x407C 0x1
    call OakNameBox
    msgbox gText_OakExplainDex MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    additem 0x4 0x5
    loadpointer 0x0 0x818E6B3
    giveitem 0x4 0x14 MSG_OBTAIN
    call OakNameBox
    msgbox gText_OakExplainPokeball MSG_KEEPOPEN
    setvar 0x8004 0x0
    setvar 0x8005 0x1
    special 0x173
    msgbox gText_OakEmotional MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_RivalConfident MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    compare PLAYERFACING 0x2
    if 0x1 _call 0x8169B33
    compare PLAYERFACING 0x1
    if 0x1 _call 0x8169B45
    compare PLAYERFACING 0x4
    if 0x1 _call 0x8169B57
    compare PLAYERFACING 0x3
    if 0x1 _call 0x8169B57
    call RivalNameBox
    msgbox gText_RivalSayTownMapDaisy MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    playsong 0x13C 0x0
    compare PLAYERFACING 0x2
    if 0x1 _call 0x8169B69
    compare PLAYERFACING 0x1
    if 0x1 _call 0x8169B7B
    compare PLAYERFACING 0x4
    if 0x1 _call 0x8169B7B
    compare PLAYERFACING 0x3
    if 0x1 _call 0x8169B7B
    hidesprite 0x8
    fadedefault
    setvar 0x4055 0x6
    setvar 0x4057 0x2
    setvar 0x4051 0x1
    setvar 0x4058 0x1
    setvar 0x4054 0x1
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Gameboy Console Pallet Town
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GameBoyConsole:
    lock
    sound 0x4
    msgbox gTetxt_ConsolePrompt MSG_KEEPOPEN
    setvar 0x8000 0x19
    setvar 0x8001 0x5
    setvar 0x8004 0x0
    special 0x158
    waitstate
    compare LASTRESULT 0x5
    if greaterorequal _goto EventScript_End
    switch LASTRESULT
    case 0, EventScript_MinimalGrinding
    case 1, EventScript_RandomizePokemon
    case 2, EventScript_RandomizeLearnset
    case 3, EventScript_RandomizeAbility
    case 4, EventScript_CheatCodes
    release
    end

EventScript_MinimalGrinding:
    checkflag FLAG_MINIMAL_GRINDING
    if SET _goto DisableMinimalGrinding
    msgbox gText_MinimalGrinding MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_End
    sound 0x2
    setflag FLAG_MINIMAL_GRINDING
    release
    end
DisableMinimalGrinding:
    msgbox gText_DisableMinimalGrinding MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_End
    sound 0x2
    clearflag FLAG_MINIMAL_GRINDING
    release
    end

EventScript_RandomizePokemon:
    checkflag FLAG_POKEMON_RANDOMIZER
    if SET _goto DisableRandomizePokemon
    msgbox gText_RandomizePokemon MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_End
    sound 0x2
    setflag FLAG_POKEMON_RANDOMIZER
    release
    end
DisableRandomizePokemon:
    msgbox gText_DisableRandomizePokemon MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_End
    sound 0x2
    clearflag FLAG_POKEMON_RANDOMIZER
    release
    end

EventScript_RandomizeLearnset:
    checkflag FLAG_POKEMON_LEARNSET_RANDOMIZER
    if SET _goto DisableRandomizeLearnset
    msgbox gText_RandomizeLearnset MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_End
    sound 0x2
    setflag FLAG_POKEMON_LEARNSET_RANDOMIZER
    release
    end
DisableRandomizeLearnset:
    msgbox gText_DisableRandomizeLearnset MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_End
    sound 0x2
    clearflag FLAG_POKEMON_LEARNSET_RANDOMIZER
    release
    end

EventScript_RandomizeAbility:
    checkflag FLAG_ABILITY_RANDOMIZER
    if SET _goto DisableRandomizeAbility
    msgbox gText_RandomizeAbility MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_End
    sound 0x2
    setflag FLAG_ABILITY_RANDOMIZER
    release
    end
DisableRandomizeAbility:
    msgbox gText_DisableRandomizeAbility MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_End
    sound 0x2
    clearflag FLAG_ABILITY_RANDOMIZER
    release
    end

EventScript_CheatCodes: @ In the future... if needed
    end

EventScript_End:
    sound 0x3
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ May House Sign
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PalletTown_MayHouseSign:
    textcolor BLACK
    msgbox gText_PalletTown_MayHouseSign MSG_NORMAL
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ May's Mom and Brother
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PalletTown_MayMom:
    lock
    faceplayer
    textcolor RED
    msgbox gText_PalletTown_MayMom MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_PalletTown_MayBrother:
    lock
    faceplayer
    textcolor BLUE
    msgbox gText_PalletTown_MayBrother MSG_KEEPOPEN
    closeonkeypress
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ May Pallet Town
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PalletTown_May:
    lock
    textcolor RED
    call MayNameBox
    msgbox gText_PalletTown_MaySpeaks1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    sound 0x15
    applymovement 0x4 EventScript_PalletTown_MayNoticePlayer
    waitmovement 0x4
    faceplayer
    call MayNameBox
    msgbox gText_PalletTown_MaySpeaks2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x4 EventScript_PalletTown_MayPushPlayer
    applymovement PLAYER EventScript_PalletTown_Pushed
    waitmovement 0x4
    setflag FLAG_MAY_PALLET_TOWN_TALKED
    release
    end

EventScript_PalletTown_MayNoticePlayer:
    .byte exclaim
    .byte pause_long
    .byte end_m

EventScript_PalletTown_MayPushPlayer:
    .byte run_left
    .byte pause_long
    .byte walk_right
    .byte walk_up_onspot_fastest
    .byte end_m

EventScript_PalletTown_Pushed:
    .byte jump_left
    .byte walk_right_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Rival Inside Lab
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PalletTown_Rival:
    lock
    faceplayer
    compare 0x4055 0x3
    if 0x1 _goto EventScript_0x816958B
    compare 0x4055 0x2
    if 0x1 _goto EventScript_0x8169581
    call RivalNameBox
    msgbox gText_PalletTown_RivalSpeak1 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x816958B:
    call RivalNameBox
    msgbox gText_PalletTown_RivalSpeak2 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8169581:
    call RivalNameBox
    msgbox gText_PalletTown_RivalSpeak3 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Mom
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Mom:
    lock
    faceplayer
    checkflag 0x258
    if 0x1 _goto EventScript_0x8168C4A
    checkgender
    compare LASTRESULT 0x0
    if 0x1 _call EventScript_0x8168C38
    compare LASTRESULT 0x1
    if 0x1 _call EventScript_0x8168C41
    closeonkeypress
    applymovement 0x1 0x81A75E5
    waitmovement 0x0
    release
    end

EventScript_0x8168C4A:
    call MomNameBox
    msgbox gText_MomTakeAQuickRest MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    call 0x81A6C26
    call MomNameBox
    msgbox gText_MomTakeCare MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8168C38:
    call MomNameBox
    msgbox gText_MomAllBoys MSG_KEEPOPEN
    callasm RemoveNameBox
    return

EventScript_0x8168C41:
    call MomNameBox
    msgbox gText_MomAllGirls MSG_KEEPOPEN
    callasm RemoveNameBox
    return

@@@@@@@@@@@@@@@@@@@@@@
@ Daisy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Daisy:
    lock
    faceplayer
    setvar 0x8004 0x1
    setvar 0x8005 0x2
    special 0x174
    checkflag 0x82C
    if 0x1 _goto EventScript_0x8168DB9
    compare 0x4001 0x1
    if 0x1 _goto EventScript_0x8168EEC
    compare 0x4058 0x2
    if 0x1 _goto EventScript_0x8168F59
    compare 0x4058 0x1
    if 0x1 _goto EventScript_0x8168EF6
    compare 0x4055 0x1
    if 0x4 _goto EventScript_0x8168DAF
    call DaisyNameBox
    msgbox gText_Daisy_BrotherIsOut MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x1 0x81A75E5
    waitmovement 0x0
    release
    end

EventScript_0x8168DB9:
    special 0x187
    compare LASTRESULT 0x2
    if 0x1 _goto EventScript_0x81A7AE0
    special 0x188
    compare 0x4025 0x1F4
    if 0x0 _goto EventScript_0x8168E46
    call DaisyNameBox
    msgbox gText_Daisy_JoinSomeTea MSG_YESNO
    compare LASTRESULT 0x0
    if 0x1 _goto EventScript_0x8168E3C
    msgbox gText_Daisy_WhichOneToGroom MSG_KEEPOPEN
    callasm RemoveNameBox
    special 0x9F
    waitstate
    lock
    faceplayer
    compare 0x8004 0x6
    if 0x4 _goto EventScript_0x8168E3C
    special2 LASTRESULT 0x147
    compare LASTRESULT 0x19C
    if 0x1 _goto EventScript_0x8168E32
    call DaisyNameBox
    msgbox gText_Daisy_PlayerAnsweredYes MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    fadescreen 0x1
    fanfare 0x100
    waitfanfare
    special 0x197
    fadescreen 0x0
    special 0x7C
    call DaisyNameBox
    msgbox gText_Daisy_DoneGrooming MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8168EEC:
    call DaisyNameBox
    msgbox gText_Daisy_PokemonLivingThing MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8168F59:
    call DaisyNameBox
    msgbox 0x818D6AF MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8168EF6:
    call DaisyNameBox
    msgbox gText_Daisy_GrandpaErrand MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    checkitemspace 0x169 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto EventScript_0x8168F4F
    applymovement 0x1 0x81A75EB
    waitmovement 0x0
    hidesprite 0x2
    setvar 0x4058 0x2
    pause 0xF
    applymovement 0x1 0x81A75E1
    waitmovement 0x0
    pause 0xC
    additem 0x169 0x1
    loadpointer 0x0 0x818D661
    giveitemwithfanfare 0x169 0x1 0x13E
    release
    end

EventScript_0x8168DAF:
    call DaisyNameBox
    msgbox gText_Daisy_WishedSeenBattle MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x81A7AE0:
    release
    end

EventScript_0x8168E46:
    call DaisyNameBox
    msgbox gText_Daisy_SeeFirstMon MSG_KEEPOPEN
    callasm RemoveNameBox
    special2 LASTRESULT 0xE6
    copyvar 0x8000 LASTRESULT
    compare 0x8000 0x0
    if 0x1 _goto EventScript_0x8168EA6
    compare 0x8000 0x1
    if 0x1 _goto EventScript_0x8168EB0
    compare 0x8000 0x2
    if 0x1 _goto EventScript_0x8168EBA
    compare 0x8000 0x3
    if 0x1 _goto EventScript_0x8168EC4
    compare 0x8000 0x4
    if 0x1 _goto EventScript_0x8168ECE
    compare 0x8000 0x5
    if 0x1 _goto EventScript_0x8168ED8
    compare 0x8000 0x6
    if 0x1 _goto EventScript_0x8168EE2
    end

EventScript_0x8168E3C:
    call DaisyNameBox
    msgbox 0x818D875 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8168E32:
    call DaisyNameBox
    msgbox 0x818D97B MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8168F4F:
    call DaisyNameBox
    msgbox 0x818D684 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8168EA6:
    call DaisyNameBox
    msgbox 0x818DBDD MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8168EB0:
    call DaisyNameBox
    msgbox 0x818DB88 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8168EBA:
    call DaisyNameBox
    msgbox 0x818DB2E MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8168EC4:
    call DaisyNameBox
    msgbox 0x818DAF3 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8168ECE:
    call DaisyNameBox
    msgbox 0x818DABE MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8168ED8:
    call DaisyNameBox
    msgbox 0x818DA73 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8168EE2:
    call DaisyNameBox
    msgbox 0x818DA16 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Pallet Town NameBoxes
@@@@@@@@@@@@@@@@@@@@@@
MomNameBox:
    setvar 0x8000 5
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

OakNameBox:
    setvar 0x8000 4
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

RivalNameBox:
    setvar 0x8000 1
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

MayNameBox:
    setvar 0x8000 0
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

DaisyNameBox:
    setvar 0x8000 6
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

@@@@@@@@@@@@@@@@@@@@@@
@ GAME FLAGS
@@@@@@@@@@@@@@@@@@@@@@
SETNECESSARYGAMEFLAGS: @ will add more
    additem ITEM_EXP_SHARE 0x1
    setflag FLAG_EXP_SHARE @ always enabled
    setflag FLAG_RECEIVED_POCKETPC
    setflag 0x954 @ Brendan pewter sprite, inside Gym
    setflag 0x953 @ Brendan pewter sprite, outside Gym
    setflag 0x955 @ Brendan pewter sprite, inside Gym after catching mon
    setflag 0x936 @ Brendan vermillion sprite
    setflag 0x937 @ Brendan's uncle vermillion sprite
    setflag 0x938 @ Brendan cerulean sprite
    setflag 0x93B @ May route 1 sprite
    setflag 0x93C @ May route 4 sprite
    setflag 0x943 @ May celadon sprite
    setflag 0x933 @ team preview
    setflag 0x9B7 @ ariana rocket hq
    setflag 0x9B9 @ may league sprite
    setflag 0x9CD @ littleboy dad cinnabar sprite inside house
    setflag 0x9D1 @ eusine sprite celadon outside gym after deafting erika
    setflag 0x9D2 @ eusine sprite celadon resto after starting event
    
    setvar 0x4070 0x1 @ Pallet Town Sign Lady
    setvar 0x5030 0x1 @ Route 1 May encounter
    setvar 0x5013 0x1 @ Brendan Pewter Encounter Inside Gym
    setvar 0x502F 0x1 @ Brendan Pewter Encounter Outside Gym
    setvar 0x503F 0x1 @ vermillion kalos researcher mega ring

    setflag 0x9BB @ kyogre
    setflag 0x9BC @ groudon
    setflag 0x9BD @ regirock
    setflag 0x9BE @ regice
    setflag 0x9BF @ registeel
    setflag 0x9C7 @ latias
    setflag 0x9C8 @ latios
    return
