.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_RECIEVED_POCKETPC, 0x0B0
.equ FLAG_RECEIVED_TIMETURNER, 0x0B1
.equ FLAG_RECEIVED_STATSCANNER, 0x0B2
.equ FLAG_CHOOSE_REGION_KANTO, 0x208
.equ FLAG_CHOOSE_REGION_JOHTO, 0x209
.equ FLAG_CHOOSE_REGION_HOENN, 0x20A
.equ FLAG_CHOOSE_REGION_SINNOH, 0x20B
.equ FLAG_CHOOSE_REGION_UNOVA, 0x20C
.equ FLAG_CHOOSE_REGION_KALOS, 0x20D
.equ FLAG_CHOOSE_REGION_ALOLA, 0x20E
.equ FLAG_CHOOSE_REGION_GALAR, 0x20F
.equ FLAG_OBTAIN_AMULET_COIN, 0x0B1

@@@@@@@@@@@@@@@@@@@@@@
@ Prof Aid Give Time Turner
@@@@@@@@@@@@@@@@@@@@@@
EventScript_ProfOakAidLabTimeTurner:
    textcolor 0x0
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
    textcolor 0x0
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
    textcolor 0x1
    setvar 0x502A 0x1
    lock
    call SETNECESSARYGAMEFLAGS
    applymovement 0x1 EventScript_MomSawYou
    waitmovement 0x1
    msgbox gText_MomChooseRegion MSG_KEEPOPEN
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
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress 
    release
    end

EventScript_Gen1:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_KANTO
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress
    release
    end

EventScript_Gen2:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_JOHTO
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress
    release
    end

EventScript_Gen3:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_HOENN
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress
    release
    end

EventScript_Gen4:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_SINNOH
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress
    release
    end

EventScript_Gen5:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_UNOVA
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress
    release
    end

EventScript_Gen6:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_KALOS
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress
    release
    end

EventScript_Gen7:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_ALOLA
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress
    release
    end

EventScript_Gen8:
    setvar 0x5029 0x1
    setflag FLAG_CHOOSE_REGION_GALAR
    msgbox gText_MomDone MSG_KEEPOPEN
    applymovement 0x1 EventScript_MomDone
    waitmovement 0x1
    closeonkeypress
    release
    end

EventScript_MomSawYou:
    .byte exclaim
    .byte pause_short
    .byte walk_up_onspot_fastest
    .byte end_m

EventScript_MomDone:
    .byte walk_left_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Choose Starter Oak Lab
@@@@@@@@@@@@@@@@@@@@@@
@ Grass
EventScript_StarterGrass:
    textcolor 0x0
    lock
    faceplayer
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
    msgbox 0x818EA19 MSG_KEEPOPEN
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
    msgbox 0x818EA19 MSG_KEEPOPEN
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
    msgbox 0x818EA19 MSG_KEEPOPEN
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
    textcolor 0x0
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
    if 0x1 _goto 0x8169C74
    compare LASTRESULT 0x0
    if 0x1 _goto 0x8169C71
    end

EventScript_0x8169C33:
    msgbox gText_WaterChoice MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x8169C74
    compare LASTRESULT 0x0
    if 0x1 _goto 0x8169C71
    end

EventScript_0x8169C52:
    msgbox gText_FireChoice MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x8169C74
    compare LASTRESULT 0x0
    if 0x1 _goto 0x8169C71
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Amulet Coin
@@@@@@@@@@@@@@@@@@@@@@
EventScript_AmuletCoin:
    textcolor 0x0
    lock
    faceplayer
    msgbox 0x817D80D MSG_FACE
    checkflag FLAG_OBTAIN_AMULET_COIN
    if 0x0 _goto EventScript_GiveAmuletCoin
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
    textcolor 0x0
    lock
    faceplayer
    checkflag 0x2
    if 0x1 _goto 0x8169600
    compare 0x4055 0x9
    if 0x1 _goto 0x8169903
    compare 0x4055 0x8
    if 0x1 _goto 0x8169A6E
    compare 0x4052 0x1
    if 0x1 _goto 0x8169903
    compare 0x4055 0x6
    if 0x1 _goto 0x81698D6
    compare 0x4057 0x1
    if 0x4 _goto EventScript_0x816961E
    compare 0x4055 0x4
    if 0x1 _goto 0x8169614
    compare 0x4055 0x3
    if 0x1 _goto 0x816960A
    msgbox 0x818E116 MSG_KEEPOPEN
    release
    end

EventScript_0x816961E:
    msgbox 0x818E405 MSG_KEEPOPEN
    textcolor 0x3
    fanfare 0x105
    preparemsg 0x818E4AF
    waitmsg
    waitfanfare
    call 0x81A6675
    removeitem 0x15D 0x1
    msgbox 0x818E4CA MSG_KEEPOPEN
    playsong 0x13B 0x0
    msgbox 0x818DE8D MSG_KEEPOPEN
    closeonkeypress
    compare PLAYERFACING 0x2
    if 0x1 _call 0x8169A82
    compare PLAYERFACING 0x1
    if 0x1 _call 0x8169AC1
    compare PLAYERFACING 0x4
    if 0x1 _call 0x8169A9E
    compare PLAYERFACING 0x3
    if 0x1 _call 0x8169A9E
    fadedefault
    msgbox 0x818DE99 MSG_KEEPOPEN
    closeonkeypress
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
    msgbox 0x818E508 MSG_KEEPOPEN
    closeonkeypress
    compare PLAYERFACING 0x2
    if 0x1 _call 0x8169882
    compare PLAYERFACING 0x1
    if 0x1 _call 0x816988D
    compare PLAYERFACING 0x4
    if 0x1 _call 0x81698A6
    compare PLAYERFACING 0x3
    if 0x1 _call 0x81698B8
    msgbox gText_RecentSightings MSG_KEEPOPEN
    closeonkeypress
    pause 0x28
    msgbox 0x818E5C5 MSG_KEEPOPEN
    closeonkeypress
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
    msgbox 0x818E612 MSG_KEEPOPEN
    additem 0x4 0x5
    loadpointer 0x0 0x818E6B3
    giveitem 0x4 0x14 MSG_OBTAIN
    msgbox 0x818E6D0 MSG_KEEPOPEN
    setvar 0x8004 0x0
    setvar 0x8005 0x1
    special 0x173
    msgbox 0x818E784 MSG_KEEPOPEN
    msgbox 0x818DEC8 MSG_KEEPOPEN
    compare PLAYERFACING 0x2
    if 0x1 _call 0x8169B33
    compare PLAYERFACING 0x1
    if 0x1 _call 0x8169B45
    compare PLAYERFACING 0x4
    if 0x1 _call 0x8169B57
    compare PLAYERFACING 0x3
    if 0x1 _call 0x8169B57
    msgbox 0x818DEF3 MSG_KEEPOPEN
    closeonkeypress
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

SETNECESSARYGAMEFLAGS: @ will add more
    setflag 0x300
    setflag 0x304
    setflag 0x30D
    return
