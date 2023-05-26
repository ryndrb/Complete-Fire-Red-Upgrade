.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ Prof Aid Give Time Turner
@@@@@@@@@@@@@@@@@@@@@@
EventScript_ProfOakAidLabTimeTurner:
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
@ Amulet Coin
@@@@@@@@@@@@@@@@@@@@@@
EventScript_AmuletCoin:
    lock
    faceplayer
    msgbox 0x817D80D MSG_KEEPOPEN
    checkflag FLAG_OBTAIN_AMULET_COIN
    if 0x0 _goto EventScript_GiveAmuletCoin
    release
    end

EventScript_GiveAmuletCoin:
    lock
    msgbox gText_GiveAmuletCoin MSG_KEEPOPEN
    giveitem ITEM_AMULET_COIN 0x1 MSG_OBTAIN
    setflag FLAG_OBTAIN_AMULET_COIN
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Player Room
@@@@@@@@@@@@@@@@@@@@@@
Map_PalletTown_PlayerRoom:
    mapscript MAP_SCRIPT_ON_TRANSITION MapScript_PalletTown_PlayerRoom
    mapscript MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE LevelScript_PalletTown_PlayerRoom
    .byte MAP_SCRIPT_TERMIN

MapScript_PalletTown_PlayerRoom:
    compare 0x4056 0x0
    if 0x1 _call EventScript_0x8168CBA
    end

EventScript_0x8168CBA:
    sethealingplace 0x1
    return

LevelScript_PalletTown_PlayerRoom:
    levelscript 0x4056, 0, EventScript_PalletTown_PlayerRoom
    .hword LEVEL_SCRIPT_TERMIN

EventScript_PalletTown_PlayerRoom:
    spriteface PLAYER, DOWN
    setvar 0x4056 0x1
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Choose Starter Region (Upto Gen 8)
@@@@@@@@@@@@@@@@@@@@@@
MapScript_ChooseStarterRegion:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_ChooseStarterRegion
    .byte MAP_SCRIPT_TERMIN

LevelScript_ChooseStarterRegion:
    levelscript 0x5042, 0, EventScript_ChooseStarterRegion
    .hword LEVEL_SCRIPT_TERMIN

EventScript_ChooseStarterRegion:
    lock
    call SETNECESSARYGAMEFLAGS
    setvar 0x5042 0x1
    sound 0x15
    applymovement 0x1 Move_PalletTown_ChooseStarterRegion_Mom_1
    applymovement PLAYER Move_PalletTown_ChooseStarterRegion_Player_1
    waitmovement 0x1
    npcmsg gText_ChooseStarterRegion_Mom_Speak_1 MSG_KEEPOPEN gText_Name_Mom
    npcmsg gText_ChooseStarterRegion_Mom_Speak_2 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    setvar 0x8000 12
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
    setflag FLAG_CHOOSE_REGION_KANTO
    goto MomScript_End

EventScript_Gen1:
    setflag FLAG_CHOOSE_REGION_KANTO
    goto MomScript_End

EventScript_Gen2:
    setflag FLAG_CHOOSE_REGION_JOHTO
    goto MomScript_End

EventScript_Gen3:
    setflag FLAG_CHOOSE_REGION_HOENN
    goto MomScript_End

EventScript_Gen4:
    setflag FLAG_CHOOSE_REGION_SINNOH
    goto MomScript_End

EventScript_Gen5:
    setflag FLAG_CHOOSE_REGION_UNOVA
    goto MomScript_End

EventScript_Gen6:
    setflag FLAG_CHOOSE_REGION_KALOS
    goto MomScript_End

EventScript_Gen7:
    setflag FLAG_CHOOSE_REGION_ALOLA
    goto MomScript_End

EventScript_Gen8:
    setflag FLAG_CHOOSE_REGION_GALAR
    goto MomScript_End

MomScript_End:
    npcmsg gText_MomDone MSG_KEEPOPEN gText_Name_Mom
    closemsg
    applymovement 0x1 Move_PalletTown_ChooseStarterRegion_Mom_2
    waitmovement 0x1
    release
    end

Move_PalletTown_ChooseStarterRegion_Mom_1:
    .byte exclaim
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte walk_up
    .byte walk_up
    .byte walk_right
    .byte end_m

Move_PalletTown_ChooseStarterRegion_Player_1:
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte end_m

Move_PalletTown_ChooseStarterRegion_Mom_2:
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_left_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Mom
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Mom:
    lock
    faceplayer
    checkflag 0x4BC
    if SET _goto EventScript_PalletTown_Champion_Mom
    checkflag 0x258
    if 0x1 _goto EventScript_0x8168C4A
    npcmsg gText_PalletTown_Mom_Speak_1 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    applymovement 0x1 0x81A75E5
    waitmovement 0x0
    release
    end

EventScript_0x8168C4A:
    npcmsg gText_PalletTown_Mom_Speak_2 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    call 0x81A6C26
    npcmsg gText_PalletTown_Mom_Speak_3 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    release
    end

EventScript_PalletTown_Champion_Mom:
    checkflag 0x2A7
    if SET _goto EventScript_0x8168C4A
    npcmsg gText_PalletTown_Champion_Mom_Speak_1 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    pause 30
    giveitem ITEM_AURORA_TICKET 0x1 MSG_OBTAIN
    giveitem ITEM_MYSTIC_TICKET 0x1 MSG_OBTAIN
    npcmsg gText_PalletTown_Champion_Mom_Speak_2 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    applymovement 0x1 Move_PalletTown_Champion_Mom_1
    waitmovement 0x1
    faceplayer
    npcmsg gText_PalletTown_Champion_Mom_Speak_3 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    setflag 0x2A7
    setflag 0x2A8
    setflag 0x84A
    setflag 0x84B
    release
    end

Move_PalletTown_Champion_Mom_1:
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
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
    pause 0x1E
    playsong 0x12E 0x0
    npcmsg gText_0x817D72C MSG_KEEPOPEN gText_Name_ProfOak
    pause 0x55
    closemsg
    applymovement PLAYER 0x81A75ED
    waitmovement 0x0
    sound 0x15
    applymovement PLAYER 0x81A75DB
    waitmovement 0x0
    pause 0x1E
    showsprite 0x3
    compare 0x4001 0x0
    if 0x1 _call EventScript_0x81656B8
    compare 0x4001 0x1
    if 0x1 _call EventScript_0x81656C3
    pause 0x1E
    npcmsg gText_0x817D74A MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    pause 0x1E
    compare 0x4001 0x0
    if 0x1 _call EventScript_0x81656CE
    compare 0x4001 0x1
    if 0x1 _call EventScript_0x81656E0
    setdooropen 0x1B 0x6
    opendoor 0x1B 0x6
    waitdooranim
    applymovement 0x3 Move_PalletTown_Outside_Oak_5
    applymovement PLAYER Move_PalletTown_Outside_Player_3
    waitmovement 0x0
    setdoorclosed 0x1B 0x6
    closedoor 0x1B 0x6
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

EventScript_0x81656B8:
    applymovement 0x3 Move_PalletTown_Outside_Oak_1
    waitmovement 0x3
    return

EventScript_0x81656C3:
    applymovement 0x3 Move_PalletTown_Outside_Oak_2
    waitmovement 0x3
    return

EventScript_0x81656CE:
    applymovement 0x3 Move_PalletTown_Outside_Oak_3
    applymovement PLAYER Move_PalletTown_Outside_Player_1
    waitmovement 0x3
    return

EventScript_0x81656E0:
    applymovement 0x3 Move_PalletTown_Outside_Oak_4
    applymovement PLAYER Move_PalletTown_Outside_Player_2
    waitmovement 0x3
    return

Move_PalletTown_Outside_Oak_1:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_up
    .byte end_m

Move_PalletTown_Outside_Oak_2:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_up
    .byte end_m

Move_PalletTown_Outside_Oak_3:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte end_m

Move_PalletTown_Outside_Player_1:
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up_onspot_fastest
    .byte end_m

Move_PalletTown_Outside_Oak_4:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte end_m

Move_PalletTown_Outside_Player_2:
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up_onspot_fastest
    .byte end_m

Move_PalletTown_Outside_Oak_5:
    .byte walk_up
    .byte set_invisible
    .byte end_m

Move_PalletTown_Outside_Player_3:
    .byte walk_up
    .byte walk_up
    .byte set_invisible
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Inside Oak Lab
@@@@@@@@@@@@@@@@@@@@@@
EventScript_InsideOakLab_DontGoAway:
    lockall
    applymovement 0x4 0x81A75F1
    waitmovement 0x0
    npcmsg gText_0x818E177 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
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
    npcmsg gText_0x818DC94 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    pause 0x3C
    npcmsg gText_0x818DFBC MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    pause 30
    sound 0x9
    showsprite 11
    applymovement 11 Move_PalletTown_InsideOakLab_May_1
    waitmovement 11
    npcmsg gText_PalletTown_InsideOakLab_May_Speak_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    pause 30
    npcmsg gText_PalletTown_InsideOakLab_Oak_Speak_1 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    pause 30
    applymovement 0x8 Move_0x81692C0
    waitmovement 0x8
    npcmsg gText_0x818DCB9 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    pause 30
    npcmsg gText_0x818E0EA MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    applymovement 11 Move_PalletTown_InsideOakLab_May_2
    waitmovement 11
    npcmsg gText_PalletTown_InsideOakLab_May_Speak_2 MSG_KEEPOPEN gText_Name_May
    closemsg
    pause 30
    npcmsg gText_PalletTown_InsideOakLab_Oak_Speak_2 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    setvar 0x4055 0x2
    setflag FLAG_MAY_PALLETTOWN_SPRITE
    releaseall
    end

Move_PalletTown_InsideOakLab_May_1:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_right
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_0x81692C0:
    .byte jump_onspot_up
    .byte pause_long
    .byte pause_long
    .byte end_m

Move_PalletTown_InsideOakLab_May_2:
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Choose Starter Oak Lab
@@@@@@@@@@@@@@@@@@@@@@
@ Grass
EventScript_PalletTown_InsideOakLab_StarterGrass:
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
    setvar 0x4005 0x6
    compare 0x4055 0x3
    if 0x4 _goto 0x8169DE4
    compare 0x4055 0x2
    if 0x1 _goto EventScript_0x8169BE1
    msgbox 0x818EA19 MSG_KEEPOPEN
    closeonkeypress
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
EventScript_PalletTown_InsideOakLab_StarterWater:
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
    setvar 0x4005 0x7
    compare 0x4055 0x3
    if 0x4 _goto 0x8169DE4
    compare 0x4055 0x2
    if 0x1 _goto EventScript_0x8169BE1
    msgbox 0x818EA19 MSG_KEEPOPEN
    closeonkeypress
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
EventScript_PalletTown_InsideOakLab_StarterFire:
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
    setvar 0x4005 0x5
    compare 0x4055 0x3
    if 0x4 _goto 0x8169DE4
    compare 0x4055 0x2
    if 0x1 _goto EventScript_0x8169BE1
    msgbox 0x818EA19 MSG_KEEPOPEN
    closeonkeypress
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
    applymovement 0x4 0x81A75EF @ Oak looks to player
    waitmovement 0x0
    showpokepic 0x4002 0xA 0x3
    compare 0x4001 0x0
    if 0x1 _goto EventScript_0x8169C14
    compare 0x4001 0x1
    if 0x1 _goto EventScript_0x8169C33
    compare 0x4001 0x2
    if 0x1 _goto EventScript_0x8169C52
    end

EventScript_0x8169C14:
    msgbox gText_PalletTown_InsideOakLab_PlayerChoseMon_Oak_Speak_Grass MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto EventScript_0x8169C74
    compare LASTRESULT 0x0
    if 0x1 _goto 0x8169C71
    end

EventScript_0x8169C33:
    msgbox gText_PalletTown_InsideOakLab_PlayerChoseMon_Oak_Speak_Water MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto EventScript_0x8169C74
    compare LASTRESULT 0x0
    if 0x1 _goto 0x8169C71
    end

EventScript_0x8169C52:
    msgbox gText_PalletTown_InsideOakLab_PlayerChoseMon_Oak_Speak_Fire MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto EventScript_0x8169C74
    compare LASTRESULT 0x0
    if 0x1 _goto 0x8169C71
    end

EventScript_0x8169C74:
    hidepokepic
    hidesprite LASTTALKED
    msgbox 0x818E2E5 MSG_KEEPOPEN
    setflag 0x828
    setflag 0x291
    givepokemon 0x4002 0x5 0x0 0x0 0x0 0x0
    copyvar 0x4031 0x4001
    bufferpokemon 0x0 0x4002
    preparemsg 0x818E30D
    waitmsg
    fanfare 0x13E
    waitfanfare
    msgbox 0x81A56A7 MSG_YESNO @ nickname?
    compare LASTRESULT 0x1
    if 0x1 _goto EventScript_0x8169CCC @ nickname scene
    compare LASTRESULT 0x0
    if 0x1 _goto EventScript_0x8169CDC
    end

EventScript_0x8169CCC:
    setvar 0x8004 0x0
    call 0x81A74EB
    goto EventScript_0x8169CDC

EventScript_0x8169CDC:
    closeonkeypress
    compare 0x4001 0x0
    if 0x1 _goto EventScript_0x8169CFF
    compare 0x4001 0x1
    if 0x1 _goto EventScript_0x8169D1F
    compare 0x4001 0x2
    if 0x1 _goto EventScript_0x8169D0F
    end

EventScript_0x8169CFF:
    applymovement 0x8 Move_0x8169D62
    waitmovement 0x0
    goto EventScript_0x8169D2F

EventScript_0x8169D1F:
    applymovement 0x8 Move_0x8169D72
    waitmovement 0x0
    goto EventScript_0x8169D2F

EventScript_0x8169D0F:
    applymovement 0x8 Move_0x8169D6B
    waitmovement 0x0
    goto EventScript_0x8169D2F

EventScript_0x8169D2F:
    npcmsg gText_0x818DD34 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    hidesprite 0x4004
    fanfare 0x13E
    msgbox gText_0x818DD52 MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    compare 0x4001 0x0
    if 0x1 _call EventScript_PalletTown_InsideOakLab_May_TakeEevee_Grass
    compare 0x4001 0x1
    if 0x1 _call EventScript_PalletTown_InsideOakLab_May_TakeEevee_Water
    compare 0x4001 0x2
    if 0x1 _call EventScript_PalletTown_InsideOakLab_May_TakeEevee_Fire
    npcmsg gText_PalletTown_InsideOakLab_May_TookMon_Speak_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    hidesprite 0x4005
    fanfare 0x13E
    msgbox gText_PalletTown_InsideOakLab_May_ReceivedMon MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    pause 15
    sound 0x15
    applymovement 0x4 Move_PalletTown_InsideOakLab_Oak_TookMon_1
    waitmovement 0x4
    spriteface 8, LEFT
    spriteface 11, LEFT
    spriteface PLAYER, LEFT
    npcmsg gText_PalletTown_InsideOakLab_TookMon_Oak_Speak_1 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    pause 15
    sound 0x15
    applymovement 11 Move_PalletTown_InsideOakLab_May_TookMon_1
    waitmovement 11
    npcmsg gText_PalletTown_InsideOakLab_May_TookMon_Speak_2 MSG_KEEPOPEN gText_Name_May
    closemsg
    pause 15
    fadescreenspeed 0x3 3
    hidesprite 11
    fadescreenspeed 0x2 3
    applymovement 0x4 Move_PalletTown_InsideOakLab_Oak_TookMon_2
    waitmovement 0x4
    setvar 0x4055 0x3
    spriteface 0x4, DOWN
    checkflag 0x83E
    if 0x1 _call 0x8169D5C
    release
    end

EventScript_PalletTown_InsideOakLab_May_TakeEevee_Grass:
    applymovement 11 Move_PalletTown_InsideOakLab_May_TakeMon_1
    waitmovement 11
    return

EventScript_PalletTown_InsideOakLab_May_TakeEevee_Water:
    applymovement 11 Move_PalletTown_InsideOakLab_May_TakeMon_2
    waitmovement 11
    return

EventScript_PalletTown_InsideOakLab_May_TakeEevee_Fire:
    applymovement 11 Move_PalletTown_InsideOakLab_May_TakeMon_3
    waitmovement 11
    return

Move_0x8169D62:
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte end_m

Move_0x8169D72:
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up_onspot_fastest
    .byte end_m

Move_0x8169D6B:
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up_onspot_fastest
    .byte end_m

Move_PalletTown_InsideOakLab_May_TakeMon_1:
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte end_m

Move_PalletTown_InsideOakLab_May_TakeMon_2:
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte end_m

Move_PalletTown_InsideOakLab_May_TakeMon_3:
    .byte walk_down
    .byte walk_right
    .byte walk_up_onspot_fastest
    .byte end_m

Move_PalletTown_InsideOakLab_May_TookMon_1:
    .byte exclaim
    .byte pause_long
    .byte end_m

Move_PalletTown_InsideOakLab_Oak_TookMon_1:
    .byte exclaim
    .byte pause_long
    .byte walk_down
    .byte walk_down
    .byte walk_right_onspot_fastest
    .byte end_m

Move_PalletTown_InsideOakLab_Oak_TookMon_2:
    .byte walk_up
    .byte walk_up
    .byte walk_down_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Rival Inside Lab
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PalletTown_InsideOakLab_Rival:
    lock
    faceplayer
    compare 0x4055 0x3
    if 0x1 _goto EventScript_16958B
    compare 0x4055 0x2
    if 0x1 _goto EventScript_0x8169581
    npcmsg gText_0x818DC67 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    release
    end

EventScript_16958B:
    npcmsg gText_0x818DD75 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    release
    end

EventScript_0x8169581:
    npcmsg gText_0x818DCE2 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ May Inside Lab
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PalletTown_InsideOakLab_May:
    lock
    faceplayer
    compare 0x4055 0x3
    if 0x1 _goto EventScript_PalletTown_InsideOakLab_Standing_May_AfterGettingPokemon
    compare 0x4055 0x2
    if 0x1 _goto EventScript_PalletTown_InsideOakLab_Standing_May_BeforeGettingPokemon
    compare 0x4055 0x4
    if equal _goto EventScript_PalletTown_InsideOakLab_Standing_May_AfterRivalBattle
    release
    end

EventScript_PalletTown_InsideOakLab_Standing_May_AfterGettingPokemon:
    npcmsg gText_PalletTown_InsideOakLab_Standing_May_Speak_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    release
    end

EventScript_PalletTown_InsideOakLab_Standing_May_BeforeGettingPokemon:
    npcmsg gText_PalletTown_InsideOakLab_Standing_May_Speak_2 MSG_KEEPOPEN gText_Name_May
    closemsg
    release
    end

EventScript_PalletTown_InsideOakLab_Standing_May_AfterRivalBattle:
    npcmsg gText_PalletTown_InsideOakLab_Standing_May_Speak_3 MSG_KEEPOPEN gText_Name_May
    closemsg
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Inside Oak Lab Rival Battle
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PalletTown_InsideOakLab_Rival_Battle_1:
    lockall
    setvar 0x4002 0x1
    goto EventScript_0x816930B

EventScript_PalletTown_InsideOakLab_Rival_Battle_2:
    lockall
    setvar 0x4002 0x2
    goto EventScript_0x816930B

EventScript_PalletTown_InsideOakLab_Rival_Battle_3:
    lockall
    setvar 0x4002 0x3
    goto EventScript_0x816930B

EventScript_0x816930B:
    playsong 0x13B 0x0
    applymovement 0x8 Move_0x81A75ED
    waitmovement 0x0
    npcmsg gText_0x818DDA4 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    applymovement PLAYER Move_0x81A75E9
    waitmovement 0x0
    compare 0x4031 0x0
    if 0x1 _goto EventScript_0x81693D2
    compare 0x4031 0x1
    if 0x1 _goto EventScript_0x816944D
    compare 0x4031 0x2
    if 0x1 _goto EventScript_0x816935A
    end

EventScript_0x81693D2:
    compare 0x4002 0x1
    if 0x1 _goto EventScript_0x81693F4
    compare 0x4002 0x2
    if 0x1 _goto EventScript_0x8169404
    compare 0x4002 0x3
    if 0x1 _goto EventScript_0x8169414
    end

EventScript_0x816944D:
    compare 0x4002 0x1
    if 0x1 _goto EventScript_0x816946F
    compare 0x4002 0x2
    if 0x1 _goto EventScript_0x816947F
    compare 0x4002 0x3
    if 0x1 _goto EventScript_0x816948F
    end

EventScript_0x816935A:
    compare 0x4002 0x1
    if 0x1 _goto EventScript_0x816937C
    compare 0x4002 0x2
    if 0x1 _goto EventScript_0x816938C
    compare 0x4002 0x3
    if 0x1 _goto EventScript_0x816939C
    end

EventScript_0x81693F4:
    applymovement 0x8 Move_0x8169438
    waitmovement 0x0
    goto EventScript_0x8169424

EventScript_0x8169404:
    applymovement 0x8 Move_0x8169440
    waitmovement 0x0
    goto EventScript_0x8169424

EventScript_0x8169414:
    applymovement 0x8 Move_0x8169447
    waitmovement 0x0
    goto EventScript_0x8169424

EventScript_0x816946F:
    applymovement 0x8 Move_0x81694B3
    waitmovement 0x0
    goto EventScript_0x816949F

EventScript_0x816947F:
    applymovement 0x8 Move_0x81694B9
    waitmovement 0x0
    goto EventScript_0x816949F

EventScript_0x816948F:
    applymovement 0x8 Move_0x81694BE
    waitmovement 0x0
    goto EventScript_0x816949F

EventScript_0x816937C:
    applymovement 0x8 Move_0x81693C0
    waitmovement 0x0
    goto EventScript_0x81693AC

EventScript_0x816938C:
    applymovement 0x8 Move_0x81693C7
    waitmovement 0x0
    goto EventScript_0x81693AC

EventScript_0x816939C:
    applymovement 0x8 Move_0x81693CD
    waitmovement 0x0
    goto EventScript_0x81693AC

EventScript_0x8169424:
    trainerbattle9 0x9 0x148 0x3 0x818DDEA 0x818DE1A
    goto EventScript_0x81694C2

EventScript_0x816949F:
    trainerbattle9 0x9 0x147 0x3 0x818DDEA 0x818DE1A
    goto EventScript_0x81694C2

EventScript_0x81693AC:
    trainerbattle9 0x9 0x146 0x3 0x818DDEA 0x818DE1A
    goto EventScript_0x81694C2

EventScript_0x81694C2:
    special 0x0
    pause 30
    npcmsg gText_0x818DE38 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    playsong 0x13C 0x0
    compare 0x4002 0x1
    if 0x1 _call EventScript_0x8169504
    compare 0x4002 0x2
    if 0x1 _call EventScript_0x8169516
    compare 0x4002 0x3
    if 0x1 _call EventScript_0x8169528
    hidesprite 0x8
    sound 0x9
    fadedefault
    setvar 0x4055 0x4
    setflag 0x258
    releaseall
    end

EventScript_0x8169504:
    applymovement 0x8 0x816953A @ im tired
    applymovement PLAYER 0x8169553
    waitmovement 0x8
    return

EventScript_0x8169516:
    applymovement 0x8 0x816954A @ im tired
    applymovement PLAYER 0x8169553
    waitmovement 0x8
    return

EventScript_0x8169528:
    applymovement 0x8 0x8169542 @ im tired
    applymovement PLAYER 0x8169559
    waitmovement 0x8
    return

Move_0x81A75ED:
    .byte walk_down_onspot_fastest
    .byte end_m

Move_0x81A75E9:
    .byte walk_up_onspot_fastest
    .byte end_m

Move_0x8169438:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte end_m

Move_0x8169440:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte end_m

Move_0x8169447:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte end_m

Move_0x81694B3:
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_0x81694B9:
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_0x81694BE:
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_0x81693C0:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte end_m

Move_0x81693C7:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte end_m

Move_0x81693CD:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte end_m

Move_PalletTown_InsideOakLab_Battle_May_1:
    .byte exclaim
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Oak In Lab
@@@@@@@@@@@@@@@@@@@@@@
EventScript_0x169595:
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
    if 0x1 _goto EventScript_0x81698D6
    compare 0x4057 0x1
    if 0x4 _goto EventScript_0x816961E
    compare 0x4055 0x4
    if 0x1 _goto EventScript_0x8169614
    compare 0x4055 0x3
    if 0x1 _goto EventScript_0x816960A
    npcmsg gText_0x818E116 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    release
    end

EventScript_0x8169614:
    npcmsg gText_0x818E3AD MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    release
    end

EventScript_0x816960A:
    npcmsg gText_0x818E330 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    release
    end

EventScript_0x8169600:
    npcmsg 0x81A72AD MSG_KEEPOPEN gText_Name_ProfOak @ thank you dialogue
    closemsg
    release
    end

EventScript_0x81698D6:
    setvar 0x8004 0x0
    special2 LASTRESULT 0xD4
    copyvar 0x8008 0x8005
    copyvar 0x8009 0x8006
    buffernumber 0x0 0x8008
    buffernumber 0x1 0x8009
    compare 0x8009 0x1
    if 0x1 _goto EventScript_0x81699FB
    goto EventScript_0x8169903

EventScript_0x8169A6E:
    npcmsg 0x818E871 MSG_KEEPOPEN gText_Name_ProfOak @ pokemon waiting dialogue
    closemsg
    release
    end

EventScript_0x8169903:
    call EventScript_0x81A737B
    checkflag 0x2F4
    if 0x1 _goto EventScript_0x8169913
    release
    end

EventScript_0x81A737B:
    special 0x187
    compare LASTRESULT 0x2
    if 0x1 _goto 0x81A7AE0 @ end script
    special 0x188
    checkflag 0x2F4
    if 0x1 _call EventScript_0x81A73A4
    checkflag 0x2F4
    if 0x0 _call EventScript_0x81A73AD
    goto EventScript_0x81A73E0 @ see pokedex progess
    return

EventScript_0x8169913:
    closeonkeypress
    pause 0x28
    preparemsg 0x81A7291
    waitmsg
    compare PLAYERFACING 0x2
    if 0x1 _call 0x8169964
    compare PLAYERFACING 0x1
    if 0x1 _call 0x816996F
    compare PLAYERFACING 0x4
    if 0x1 _call 0x816997A
    compare PLAYERFACING 0x3
    if 0x1 _call 0x8169985
    applymovement 0x4 0x81A75E1
    waitmovement 0x0
    closeonkeypress
    pause 0x46
    npcmsg 0x81A72AD MSG_KEEPOPEN gText_Name_ProfOak @ thank you dialogue
    closemsg
    setflag 0x2
    release
    end

EventScript_0x81A73A4:
    npcmsg gText_0x81A72F2 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    return

EventScript_0x81A73AD:
    npcmsg gText_0x81A6C51 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    return

EventScript_0x81A73E0:
    setvar 0x8004 0x1F
    special 0x17E
    special 0x17D
    setvar 0x8004 0x0
    special2 LASTRESULT 0xD4
    copyvar 0x8008 0x8005
    copyvar 0x8009 0x8006
    copyvar 0x800A LASTRESULT
    buffernumber 0x0 0x8008
    buffernumber 0x1 0x8009
    msgbox 0x81A6CA3 MSG_KEEPOPEN
    call 0x81A73B6
    compare 0x800A 0x0
    if 0x1 _goto 0x81A748F
    setvar 0x8004 0x1
    special2 LASTRESULT 0xD4
    copyvar 0x8008 0x8005
    copyvar 0x8009 0x8006
    buffernumber 0x0 0x8008
    buffernumber 0x1 0x8009
    msgbox 0x81A71AA MSG_KEEPOPEN
    special2 LASTRESULT 0x1B0
    compare LASTRESULT 0x0
    if 0x1 _goto 0x81A7470
    compare LASTRESULT 0x1
    if 0x1 _goto 0x81A747E
    end

EventScript_0x816961E:
    npcmsg gText_0x818E405 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    fanfare 0x105
    preparemsg 0x818E4AF @ player delivered message
    waitmsg
    waitfanfare
    call 0x81A6675 @ copy variable
    removeitem 0x15D 0x1
    npcmsg gText_0x818E4CA MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    playsong 0x13B 0x0
    npcmsg gText_0x818DE8D MSG_KEEPOPEN gText_Name_Rival
    closemsg
    compare PLAYERFACING 0x2
    if 0x1 _call EventScript_0x8169A82
    compare PLAYERFACING 0x1
    if 0x1 _call EventScript_0x8169AC1
    compare PLAYERFACING 0x4
    if 0x1 _call EventScript_0x8169A9E_Right
    compare PLAYERFACING 0x3
    if 0x1 _call EventScript_0x8169A9E_Left
    fadedefault
    npcmsg gText_0x818DE99 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    pause 0x1E
    sound 0x15
    applymovement 0x4 0x81A75DB
    waitmovement 0x0
    applymovement 0x4 0x81A75DD
    waitmovement 0x0
    compare PLAYERFACING 0x1
    if 0x1 _call 0x8169B86
    compare PLAYERFACING 0x4
    if 0x1 _call 0x8169B86
    compare PLAYERFACING 0x3
    if 0x1 _call 0x8169B86
    compare PLAYERFACING 0x2
    if 0x1 _call 0x8169B86
    npcmsg gText_0x818E508 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    showsprite 11
    sound 0x9
    applymovement 11 Move_PalletTown_InsideOakLab_May_Entering_1
    waitmovement 11
    pause 15
    npcmsg gText_PalletTown_InsideOakLab_May_Speak_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    pause 15
    npcmsg gText_0x818E536 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    applymovement 0x8 Move_PalletTown_InsideOakLab_ReceivingPokedex_Rival_1
    waitmovement 0x8
    npcmsg gText_PalletTown_InsideOakLab_ReceivingPokedex_Rival_OnlyTwoDex MSG_KEEPOPEN gText_Name_Rival
    closemsg
    pause 15
    sound 0x15
    applymovement 0x4 Move_PalletTown_InsideOakLab_TryingToGivePokedex_Oak_1
    waitmovement 0x4
    npcmsg gText_PalletTown_InsideOakLab_TryingToGivePokedex_Oak_RealizeTwoDex MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    applymovement 0x8 Move_PalletTown_InsideOakLab_ReceivingPokedex_Rival_1
    waitmovement 0x8
    npcmsg gText_PalletTown_InsideOakLab_ReceivingPokedex_Rival_NoFair MSG_KEEPOPEN gText_Name_Rival
    closemsg
    pause 15
    npcmsg gText_PalletTown_InsideOakLab_ReceivingPokedex_May_OKWithIt MSG_KEEPOPEN gText_Name_May
    closemsg
    pause 15
    npcmsg gText_PalletTown_InsideOakLab_TryingToGivePokedex_Oak_ThanksMay MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    pause 30
    compare PLAYERFACING 0x2
    if 0x1 _call 0x8169882
    compare PLAYERFACING 0x1
    if 0x1 _call 0x8169882
    compare PLAYERFACING 0x4
    if 0x1 _call 0x8169882
    compare PLAYERFACING 0x3
    if 0x1 _call 0x8169882
    npcmsg gText_RecentSightings MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    pause 0x28
    npcmsg gText_0x818E5C5 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    applymovement 0x4 0x81A75E9
    waitmovement 0x0
    hidesprite 0x9
    pause 0xA
    hidesprite 0xA
    pause 0x19
    compare PLAYERFACING 0x2
    if 0x1 _call 0x8169845
    compare PLAYERFACING 0x1
    if 0x1 _call 0x8169845
    compare PLAYERFACING 0x4
    if 0x1 _call 0x8169845
    compare PLAYERFACING 0x3
    if 0x1 _call 0x8169845
    pause 0xA
    fanfare 0x13E
    preparemsg 0x818E5EA
    waitmsg
    waitfanfare
    call 0x81A6675
    setflag 0x829
    special 0x16F
    special 0x181
    setvar 0x407C 0x1
    npcmsg gText_0x818E612 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    giveitem ITEM_POKE_BALL 20 MSG_OBTAIN
    npcmsg gText_0x818E6D0 MSG_KEEPOPEN gText_Name_ProfOak
    setvar 0x8004 0x0
    setvar 0x8005 0x1
    special 0x173
    npcmsg gText_0x818E784 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    npcmsg gText_0x818DEC8 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    pause 15
    spriteface 0x8, RIGHT
    spriteface 11, LEFT
    spriteface PLAYER, LEFT
    npcmsg gText_0x818DEF3 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    playsong 0x13C 0x0
    compare PLAYERFACING 0x2
    if 0x1 _call 0x8169B69
    compare PLAYERFACING 0x1
    if 0x1 _call 0x8169B69
    compare PLAYERFACING 0x4
    if 0x1 _call 0x8169B69
    compare PLAYERFACING 0x3
    if 0x1 _call 0x8169B69
    hidesprite 0x8
    fadedefault
    pause 15
    spriteface 11, UP
    npcmsg gText_PalletTown_InsideOakLab_May_ThanksOak MSG_KEEPOPEN gText_Name_May
    spriteface 11, LEFT
    spriteface PLAYER, RIGHT
    npcmsg gText_PalletTown_InsideOakLab_May_LeavingForAdventure MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement 11 Move_PalletTown_InsideOakLab_May_Leaving_1
    waitmovement 11
    sound 0x9
    hidesprite 11
    setvar 0x4055 0x6
    setvar 0x4057 0x2
    setvar 0x4051 0x1
    setvar 0x4058 0x1
    setvar 0x4054 0x1
    clearflag 0x9DD @ jessie viridian
    clearflag 0x9DE @ james viridian
    clearflag 0x9DF @ meowth viridian
    setvar 0x5043 0x1
    release
    end

EventScript_0x81699FB:
    special 0x187
    compare LASTRESULT 0x2
    if 0x1 _goto 0x81A7AE0 @ end script
    special 0x188
    checkflag 0x24F
    if 0x1 _goto EventScript_0x8169A6E
    checkflag 0x247
    if 0x1 _goto EventScript_0x8169A78
    checkitem 0x4 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto EventScript_0x8169A34
    goto EventScript_0x8169A6E

EventScript_0x8169A78:
    npcmsg gText_0x818E98E MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    release
    end

EventScript_0x8169A34:
    compare 0x4054 0x2
    if 0x4 _goto EventScript_0x8169A45
    goto EventScript_0x8169A6E

EventScript_0x8169A45:
    npcmsg 0x818E89C MSG_KEEPOPEN gText_Name_ProfOak @ hows pokedex
    closemsg
    giveitem ITEM_GREAT_BALL 10 MSG_OBTAIN
    setflag 0x247
    release
    end

EventScript_0x8169A82:
    movesprite2 0x8 0x5 0xA
    showsprite 0x8
    applymovement PLAYER 0x8169B94
    applymovement 0x8 0x8169B9D
    waitmovement 0x0
    return

EventScript_0x8169AC1:
    movesprite2 0x8 0x5 0xA
    showsprite 0x8
    applymovement 0x4 0x81A75ED
    applymovement PLAYER Move_PalletTown_InsideOakLab_ReceivingPokedex_Player_Reposition_Down
    applymovement 0x8 0x8169B9D
    waitmovement 0x8
    return

EventScript_0x8169A9E_Right:
    movesprite2 0x8 0x5 0xA
    showsprite 0x8
    applymovement 0x4 0x81A75ED
    applymovement PLAYER Move_PalletTown_InsideOakLab_ReceivingPokedex_Player_Reposition_Right
    applymovement 0x8 0x8169B9D
    waitmovement 0x8
    return

EventScript_0x8169A9E_Left:
    movesprite2 0x8 0x5 0xA
    showsprite 0x8
    applymovement 0x4 0x81A75ED
    applymovement PLAYER Move_PalletTown_InsideOakLab_ReceivingPokedex_Player_Reposition_Left
    applymovement 0x8 0x8169B9D
    waitmovement 0x8
    return

Move_PalletTown_InsideOakLab_ReceivingPokedex_Player_Reposition_Down:
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_down_onspot_fastest
    .byte walk_up_onspot_fastest
    .byte end_m

Move_PalletTown_InsideOakLab_ReceivingPokedex_Player_Reposition_Right:
    .byte walk_down
    .byte walk_right
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

Move_PalletTown_InsideOakLab_ReceivingPokedex_Player_Reposition_Left:
    .byte walk_down
    .byte walk_left
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

Move_PalletTown_InsideOakLab_ReceivingPokedex_Rival_1:
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte walk_up_onspot_fastest
    .byte end_m

Move_PalletTown_InsideOakLab_TryingToGivePokedex_Oak_1:
    .byte exclaim
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte walk_up
    .byte walk_left
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte walk_left
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte end_m

Move_PalletTown_InsideOakLab_May_Entering_1:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_right
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_PalletTown_InsideOakLab_May_Leaving_1:
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Gameboy Console Pallet Town
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GameBoyConsole:
    lock
    sound 0x4
    preparemsg gTetxt_ConsolePrompt
    waitmsg
    multichoiceoption gText_MinimalGrinding 0
    multichoiceoption gText_RandomizePokemon 1
    multichoiceoption gText_RandomizeLearnset 2
    multichoiceoption gText_RandomizeAbility 3
    multichoiceoption gText_EnterCode 4
    multichoice 0x0 0x0 FIVE_MULTICHOICE_OPTIONS 0x0
    switch LASTRESULT
    case 0, EventScript_GameBoyConsole_MinimalGrinding
    case 1, EventScript_GameBoyConsole_RandomizePokemon
    case 2, EventScript_GameBoyConsole_RandomizeLearnset
    case 3, EventScript_GameBoyConsole_RandomizeAbility
    case 4, EventScript_GameBoyConsole_EnterCode
    release
    end

EventScript_GameBoyConsole_MinimalGrinding:
    checkflag FLAG_MINIMAL_GRINDING
    if SET _goto DisableMinimalGrinding
    msgbox gText_GameBoyConsole_MinimalGrinding MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_End
    sound 0x2
    setflag FLAG_MINIMAL_GRINDING
    release
    end
DisableMinimalGrinding:
    msgbox gText_GameBoyConsole_DisableMinimalGrinding MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_End
    sound 0x2
    clearflag FLAG_MINIMAL_GRINDING
    release
    end

EventScript_GameBoyConsole_RandomizePokemon:
    checkflag FLAG_POKEMON_RANDOMIZER
    if SET _goto DisableRandomizePokemon
    msgbox gText_GameBoyConsole_RandomizePokemon MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_End
    sound 0x2
    setflag FLAG_POKEMON_RANDOMIZER
    release
    end
DisableRandomizePokemon:
    msgbox gText_GameBoyConsole_DisableRandomizePokemon MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_End
    sound 0x2
    clearflag FLAG_POKEMON_RANDOMIZER
    release
    end

EventScript_GameBoyConsole_RandomizeLearnset:
    checkflag FLAG_POKEMON_LEARNSET_RANDOMIZER
    if SET _goto DisableRandomizeLearnset
    msgbox gText_GameBoyConsole_RandomizeLearnset MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_End
    sound 0x2
    setflag FLAG_POKEMON_LEARNSET_RANDOMIZER
    release
    end
DisableRandomizeLearnset:
    msgbox gText_GameBoyConsole_DisableRandomizeLearnset MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_End
    sound 0x2
    clearflag FLAG_POKEMON_LEARNSET_RANDOMIZER
    release
    end

EventScript_GameBoyConsole_RandomizeAbility:
    checkflag FLAG_ABILITY_RANDOMIZER
    if SET _goto DisableRandomizeAbility
    msgbox gText_GameBoyConsole_RandomizeAbility MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_End
    sound 0x2
    setflag FLAG_ABILITY_RANDOMIZER
    release
    end
DisableRandomizeAbility:
    msgbox gText_GameBoyConsole_DisableRandomizeAbility MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_End
    sound 0x2
    clearflag FLAG_ABILITY_RANDOMIZER
    release
    end

EventScript_GameBoyConsole_EnterCode: @ In the future... if needed
    end

EventScript_End:
    sound 0x3
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ May House Sign
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PalletTown_MayHouseSign:
    msgbox gText_PalletTown_MayHouseSign MSG_NORMAL
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ May's Mom and Brother
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PalletTown_MayMom:
    lock
    faceplayer
    msgbox gText_PalletTown_MayMom MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_PalletTown_MayBrother:
    lock
    faceplayer
    msgbox gText_PalletTown_MayBrother MSG_KEEPOPEN
    closeonkeypress
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ May Pallet Town
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PalletTown_May:
    lock
    npcmsg gText_PalletTown_MaySpeaks1 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    sound 0x15
    applymovement 0x4 EventScript_PalletTown_MayNoticePlayer
    waitmovement 0x4
    npcmsg gText_PalletTown_MaySpeaks2 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    compare PLAYERFACING RIGHT
    if equal _call EventScript_PalletTown_May_PlayerFacingRight
    compare PLAYERFACING DOWN
    if equal _call EventScript_PalletTown_May_PlayerFacingDown
    setflag FLAG_MAY_PALLET_TOWN_TALKED
    release
    end

EventScript_PalletTown_May_PlayerFacingRight:
    applymovement 0x4 Move_PalletTown_May_PushedPlayerRight
    applymovement PLAYER Move_PalletTown_May_PlayerPushedRight
    waitmovement 0x4
    return

EventScript_PalletTown_May_PlayerFacingDown:
    applymovement 0x4 Move_PalletTown_May_PushedPlayerDown
    applymovement PLAYER Move_PalletTown_May_PlayerPushedDown
    waitmovement 0x4
    return

EventScript_PalletTown_MayNoticePlayer:
    .byte exclaim
    .byte pause_long
    .byte face_player
    .byte end_m

Move_PalletTown_May_PushedPlayerRight:
    .byte run_left
    .byte pause_long
    .byte walk_right
    .byte walk_down_onspot_fastest
    .byte end_m

Move_PalletTown_May_PlayerPushedRight:
    .byte jump_left
    .byte walk_right_onspot_fastest
    .byte end_m

Move_PalletTown_May_PushedPlayerDown:
    .byte run_up
    .byte pause_long
    .byte walk_down
    .byte walk_down_onspot_fastest
    .byte end_m

Move_PalletTown_May_PlayerPushedDown:
    .byte jump_up
    .byte walk_down_onspot_fastest
    .byte end_m

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
    npcmsg gText_0x818D58C MSG_KEEPOPEN gText_Name_Daisy
    closemsg
    applymovement 0x1 0x81A75E5
    waitmovement 0x0
    release
    end

EventScript_0x8168DB9:
    special 0x187
    compare LASTRESULT 0x2
    if 0x1 _goto 0x81A7AE0 @ end script
    special 0x188
    compare 0x4025 0x1F4
    if 0x0 _goto EventScript_0x8168E46
    npcmsg gText_0x818D7D3 MSG_YESNO gText_Name_Daisy
    compare LASTRESULT 0x0
    if 0x1 _goto EventScript_0x8168E3C
    npcmsg gText_0x818D8B2 MSG_KEEPOPEN gText_Name_Daisy
    closemsg
    special 0x9F
    waitstate
    lock
    faceplayer
    compare 0x8004 0x6
    if 0x4 _goto EventScript_0x8168E3C
    special2 LASTRESULT 0x147
    compare LASTRESULT 0x19C
    if 0x1 _goto EventScript_0x8168E32
    npcmsg gText_0x818D8CC MSG_KEEPOPEN gText_Name_Daisy
    closemsg
    fadescreen 0x1
    fanfare 0x100
    waitfanfare
    special 0x197
    fadescreen 0x0
    special 0x7C
    npcmsg gText_0x818D8FE MSG_KEEPOPEN gText_Name_Daisy
    closemsg
    release
    end

EventScript_0x8168EEC:
    npcmsg gText_0x818D701 MSG_KEEPOPEN gText_Name_Daisy
    closemsg
    release
    end

EventScript_0x8168F59:
    npcmsg 0x818D6AF MSG_KEEPOPEN gText_Name_Daisy @ you can use town map
    closemsg
    release
    end

EventScript_0x8168EF6:
    npcmsg gText_0x818D60A MSG_KEEPOPEN gText_Name_Daisy
    closemsg
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
    npcmsg gText_0x818D5C4 MSG_KEEPOPEN gText_Name_Daisy @ wish seen battle
    closemsg
    release
    end

EventScript_0x8168E46:
    npcmsg gText_0x818D9A5 MSG_KEEPOPEN gText_Name_Daisy @ see first mon
    closemsg
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
    npcmsg 0x818D875 MSG_KEEPOPEN gText_Name_Daisy
    closemsg
    release
    end

EventScript_0x8168E32:
    npcmsg 0x818D97B MSG_KEEPOPEN gText_Name_Daisy
    closemsg
    release
    end

EventScript_0x8168F4F:
    npcmsg 0x818D684 MSG_KEEPOPEN gText_Name_Daisy
    closemsg
    release
    end

EventScript_0x8168EA6:
    npcmsg 0x818DBDD MSG_KEEPOPEN gText_Name_Daisy
    closemsg
    release
    end

EventScript_0x8168EB0:
    npcmsg 0x818DB88 MSG_KEEPOPEN gText_Name_Daisy
    closemsg
    release
    end

EventScript_0x8168EBA:
    npcmsg 0x818DB2E MSG_KEEPOPEN gText_Name_Daisy
    closemsg
    release
    end

EventScript_0x8168EC4:
    npcmsg 0x818DAF3 MSG_KEEPOPEN gText_Name_Daisy
    closemsg
    release
    end

EventScript_0x8168ECE:
    npcmsg 0x818DABE MSG_KEEPOPEN gText_Name_Daisy
    closemsg
    release
    end

EventScript_0x8168ED8:
    npcmsg 0x818DA73 MSG_KEEPOPEN gText_Name_Daisy
    closemsg
    release
    end

EventScript_0x8168EE2:
    npcmsg 0x818DA16 MSG_KEEPOPEN gText_Name_Daisy
    closemsg
    release
    end

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
    setflag 0x933 @ team preview
    setflag 0x9B9 @ may league sprite
    setflag 0x9CD @ littleboy dad cinnabar sprite inside house
    setflag 0x9D1 @ eusine sprite celadon outside gym after deafting erika
    setflag 0x9D2 @ eusine sprite celadon resto after starting event
    setflag 0x9DC @ may oak lab sprite
    setflag FLAG_MAY_POKETOWER_SPRITE
    setflag FLAG_ROCKET_GANG_ROUTE25_SPRITE
    setflag FLAG_MAY_LAVENDER_SPRITE
    setflag FLAG_MAY_POKETOWER_SPRITE_2
    setflag FLAG_ROCKET_GANG_LAVENDER_SPRITE
    setflag FLAG_ROCKET_GANG_POKETOWER_SPRITE

    setvar 0x4070 0x1 @ Pallet Town Sign Lady

    setflag 0x9BB @ kyogre
    setflag 0x9BC @ groudon
    setflag 0x9BD @ regirock
    setflag 0x9BE @ regice
    setflag 0x9BF @ registeel
    setflag 0x9C7 @ latias
    setflag 0x9C8 @ latios
    setflag 0x9D7 @ jirachi
    setflag 0x9D8 @ jigglypuff (jirachi event)
    setflag 0x9D9 @ rayquaza
    setflag 0x9DB @ celebi
    setflag 0x9DD @ jessie viridian
    setflag 0x9DE @ james viridian
    setflag 0x9DF @ meowth viridian
    return
