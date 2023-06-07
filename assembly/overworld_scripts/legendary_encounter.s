.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ Kyogre Route 21 Marine Cave
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route21_Kyogre:
    lock
    signmsg
    msgbox gText_Route3_Groudon_BlueOrbReacting MSG_KEEPOPEN
    closeonkeypress
    pause 30
    sound 0x15
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    pause 30
    cry SPECIES_KYOGRE 0x0
    setvar 0x8004 3
    setvar 0x8005 3
    setvar 0x8006 5
    setvar 0x8007 5
    special 0x136
    msgbox gText_Route21_Kyogre MSG_KEEPOPEN
    closeonkeypress
    pause 30
    wildbattle SPECIES_KYOGRE 70 ITEM_NONE
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_Legendaries_End
    compare LASTRESULT 0x4
    if TRUE _goto EventScript_Legendaries_End
    fadescreen 0x1
    hidesprite LASTTALKED
    setflag FLAG_KYOGRE_ROUTE21
    clearflag FLAG_ROUTE21_THUNDERSTORMS
    fadescreen 0x0
    release
    end

EventScript_Route21_MarineCave:
    signmsg
    msgbox gText_Route21_MarineCave MSG_NORMAL
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Groudon Route 3 Terra Cave
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route3_Groudon:
    lock
    signmsg
    msgbox gText_Route3_Groudon_RedOrbReacting MSG_KEEPOPEN
    closeonkeypress
    pause 30
    sound 0x15
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    pause 30
    cry SPECIES_GROUDON 0x0
    setvar 0x8004 3
    setvar 0x8005 3
    setvar 0x8006 5
    setvar 0x8007 5
    special 0x136
    msgbox gText_Route3_Groudon MSG_KEEPOPEN
    closeonkeypress
    pause 30
    wildbattle SPECIES_GROUDON 70 ITEM_NONE
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_Legendaries_End
    compare LASTRESULT 0x4
    if TRUE _goto EventScript_Legendaries_End
    fadescreen 0x1
    hidesprite LASTTALKED
    setflag FLAG_GROUDON_ROUTE3
    clearflag FLAG_ROUTE3_STEAM
    fadescreen 0x0
    release
    end

EventScript_Route3_TerraCave:
    signmsg
    msgbox gText_Route3_TerraCave MSG_NORMAL
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Regirock Rock Tunnel
@@@@@@@@@@@@@@@@@@@@@@
EventScript_RockTunnel_Regirock:
    lock
    signmsg
    callasm CheckRelicantWailord
    compare 0x8004 0x1
    if notequal _goto EventScript_RegirockSleep
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    cry SPECIES_REGIROCK 0x0
    setvar 0x8004 3
    setvar 0x8005 3
    setvar 0x8006 5
    setvar 0x8007 5
    special 0x136
    msgbox gText_RockTunnel_Regirock MSG_KEEPOPEN
    closeonkeypress
    pause 30
    wildbattle SPECIES_REGIROCK 60 ITEM_NONE
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_Legendaries_End
    compare LASTRESULT 0x4
    if TRUE _goto EventScript_Legendaries_End
    fadescreen 0x1
    hidesprite LASTTALKED
    setflag FLAG_REGIROCK_ROCKTUNNEL
    fadescreen 0x0
    release
    end

EventScript_RegirockSleep:
    signmsg
    msgbox gText_RegisSleeping MSG_NORMAL
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Regice Seafoam Island
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Seafoam_Regice:
    lock
    signmsg
    callasm CheckRelicantWailord
    compare 0x8004 0x1
    if notequal _goto EventScript_RegiceSleep
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    cry SPECIES_REGICE 0x0
    setvar 0x8004 3
    setvar 0x8005 3
    setvar 0x8006 5
    setvar 0x8007 5
    special 0x136
    msgbox gText_Seafoam_Regice MSG_KEEPOPEN
    closeonkeypress
    pause 30
    wildbattle SPECIES_REGICE 60 ITEM_NONE
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_Legendaries_End
    compare LASTRESULT 0x4
    if TRUE _goto EventScript_Legendaries_End
    fadescreen 0x1
    hidesprite LASTTALKED
    setflag FLAG_REGICE_SEAFOAM
    fadescreen 0x0
    release
    end

EventScript_RegiceSleep:
    signmsg
    msgbox gText_RegisSleeping MSG_NORMAL
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Registeel Mt. Moon
@@@@@@@@@@@@@@@@@@@@@@
EventScript_MtMoon_Registeel:
    lock
    signmsg
    callasm CheckRelicantWailord
    compare 0x8004 0x1
    if notequal _goto EventScript_RegisteelSleep
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    cry SPECIES_REGISTEEL 0x0
    setvar 0x8004 3
    setvar 0x8005 3
    setvar 0x8006 5
    setvar 0x8007 5
    special 0x136
    msgbox gText_MtMoon_Registeel MSG_KEEPOPEN
    closeonkeypress
    pause 30
    wildbattle SPECIES_REGISTEEL 60 ITEM_NONE
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_Legendaries_End
    compare LASTRESULT 0x4
    if TRUE _goto EventScript_Legendaries_End
    fadescreen 0x1
    hidesprite LASTTALKED
    setflag FLAG_REGISTEEL_MTMOON
    fadescreen 0x0
    release
    end

EventScript_RegisteelSleep:
    signmsg
    msgbox gText_RegisSleeping MSG_NORMAL
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Heatran Mt. Ember
@@@@@@@@@@@@@@@@@@@@@@
EventScript_MtEmber_Heatran:
    lock
    signmsg
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    cry SPECIES_HEATRAN 0x0
    setvar 0x8004 3
    setvar 0x8005 3
    setvar 0x8006 5
    setvar 0x8007 5
    special 0x136
    msgbox gText_MtEmber_Heatran MSG_KEEPOPEN
    closeonkeypress
    pause 30
    wildbattle SPECIES_HEATRAN 68 ITEM_NONE
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_Legendaries_End
    compare LASTRESULT 0x4
    if TRUE _goto EventScript_Legendaries_End
    fadescreen 0x1
    hidesprite LASTTALKED
    setflag FLAG_HEATRAN_MTEMBER
    fadescreen 0x0
    msgbox gText_MtEmber_Heatran_MagmaStone MSG_KEEPOPEN
    closeonkeypress
    giveitem ITEM_MAGMA_STONE 0x1 MSG_OBTAIN
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Latias Fullmoon Island
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Fullmoon_Latias:
    lock
    signmsg
    checkitem ITEM_SOUL_DEW 0x1
    compare LASTRESULT 0x1
    if FALSE _goto EventScript_Legendaries_End
    msgbox gText_Fullmoon_Lati_Intro_1 MSG_KEEPOPEN
    closeonkeypress
    pause 30
    sound 0x15
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    msgbox gText_Fullmoon_Lati_Intro_2 MSG_KEEPOPEN
    closeonkeypress
    pause 30
    sound 0x15
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    pause 30
    cry SPECIES_LATIAS 0x0
    msgbox gText_Fullmoon_Lati_Intro_3 MSG_KEEPOPEN
    closeonkeypress
    pause 30
    wildbattle SPECIES_LATIAS 68 ITEM_NONE
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_Legendaries_End
    compare LASTRESULT 0x4
    if TRUE _goto EventScript_Legendaries_End
    fadescreen 0x1
    hidesprite LASTTALKED
    setflag FLAG_LATIAS_FULLMOON
    fadescreen 0x0
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Latios Fullmoon Island
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Fullmoon_Latios:
    lock
    signmsg
    checkitem ITEM_SOUL_DEW 0x1
    compare LASTRESULT 0x1
    if FALSE _goto EventScript_Legendaries_End
    msgbox gText_Fullmoon_Lati_Intro_1 MSG_KEEPOPEN
    closeonkeypress
    pause 30
    sound 0x15
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    msgbox gText_Fullmoon_Lati_Intro_2 MSG_KEEPOPEN
    closeonkeypress
    pause 30
    sound 0x15
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    pause 30
    cry SPECIES_LATIOS 0x0
    msgbox gText_Fullmoon_Lati_Intro_3 MSG_KEEPOPEN
    closeonkeypress
    pause 30
    wildbattle SPECIES_LATIOS 68 ITEM_NONE
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_Legendaries_End
    compare LASTRESULT 0x4
    if TRUE _goto EventScript_Legendaries_End
    fadescreen 0x1
    hidesprite LASTTALKED
    setflag FLAG_LATIOS_FULLMOON
    fadescreen 0x0
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Cresselia Fullmoon Island
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Fullmoon_Cresselia:
    lock
    signmsg
    cry SPECIES_CRESSELIA 0x0
    msgbox gText_Fullmoon_Cresselia MSG_KEEPOPEN
    closeonkeypress
    pause 30
    wildbattle SPECIES_CRESSELIA 68 ITEM_NONE
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_Legendaries_End
    compare LASTRESULT 0x4
    if TRUE _goto EventScript_Legendaries_End
    fadescreen 0x1
    hidesprite LASTTALKED
    setflag FLAG_CRESSELIA_FULLMOON
    fadescreen 0x0
    msgbox gText_Fullmoon_Cresselia_LunarWing MSG_KEEPOPEN
    fanfare 0x13E
    msgbox gText_Fullmoon_PlayerReceivedLunarWing MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    pause 30
    sound 0x15
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    msgbox gText_MtEmber_Heatran_MagmaStone MSG_KEEPOPEN
    closeonkeypress
    fadescreen 0x1
    fadescreen 0x0
    msgbox gText_Fullmoon_Cresselia_MysteriousAir MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_FullmoonIsland_Sign:
    signmsg
    msgbox gText_FullmoonIsland_Sign MSG_NORMAL
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Darkrai Newmoon Island
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Newmoon_Darkrai:
    lock
    signmsg
    msgbox gText_Newmoon_Darkrai MSG_KEEPOPEN
    closeonkeypress
    pause 30
    wildbattle SPECIES_DARKRAI 68 ITEM_NONE
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_Legendaries_End
    compare LASTRESULT 0x4
    if TRUE _goto EventScript_Legendaries_End
    fadescreen 0x1
    hidesprite LASTTALKED
    setflag FLAG_DARKRAI_NEWMOON
    fadescreen 0x0
    pause 30
    sound 0x15
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    msgbox gText_Newmoon_Narrator_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    fadescreen 0x1
    pause 30
    fadescreen 0x0
    fadescreen 0x1
    pause 30
    fadescreen 0x0
    warpmuted 43 7 PLAYER 0x1 0x4
    waitstate
    release
    end

EventScript_NewmoonIsland_Sign:
    signmsg
    msgbox gText_NewmoonIsland_Sign MSG_NORMAL
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Jirachi Rock Tunnel
@@@@@@@@@@@@@@@@@@@@@@
EventScript_RockTunnel_Jirachi_Event:
    lock
    signmsg
    msgbox gText_RockTunnel_Jirachi_1 MSG_KEEPOPEN
    callasm CheckJigglypuff
    compare 0x8004 0
    if equal _goto EventScript_Legendaries_End
    msgbox gText_RockTunnel_Jirachi_2 MSG_YESNO
    compare LASTRESULT 0x1
    if notequal _goto EventScript_Legendaries_End
    fadescreenspeed 0x3 0
    showsprite 0x2
    fadescreenspeed 0x2 0
    cry SPECIES_JIGGLYPUFF 0x0
    msgbox gText_RockTunnel_Jirachi_Jigglypuff_1 MSG_KEEPOPEN
    closeonkeypress
    fadenewbgm 0x114
    pause 30
    applymovement 0x2 Move_RockTunnel_Jirachi_Event_Jigglypuff_1
    waitmovement 0x2
    pause 30
    applymovement 0x2 Move_RockTunnel_Jirachi_Event_Jigglypuff_2
    waitmovement 0x2
    cry SPECIES_JIGGLYPUFF 0x0
    fadescreenspeed 0x3 0
    hidesprite 0x2
    fadescreenspeed 0x2 0
    pause 30
    applymovement 0x1 Move_RockTunnel_Jirachi_Event_Jirachi_1
    waitmovement 0x1
    msgbox gText_RockTunnel_Jirachi_3 MSG_KEEPOPEN
    closeonkeypress
    pause 30
    sound 0x15
    applymovement 0x1 Move_RockTunnel_Jirachi_Event_Jirachi_2
    waitmovement 0x1
    cry SPECIES_JIRACHI 0x0
    msgbox gText_RockTunnel_Jirachi_4 MSG_KEEPOPEN
    closeonkeypress
    pause 30
    wildbattle SPECIES_JIRACHI 40 ITEM_NONE
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_Legendaries_End
    compare LASTRESULT 0x4
    if TRUE _goto EventScript_Legendaries_End
    fadescreen 0x1
    hidesprite LASTTALKED
    setflag FLAG_JIRACHI_ROCKTUNNEL
    fadescreen 0x0
    release
    end

EventScript_RockTunnel_Jirachi_Signpost:
    lock
    signmsg
    checkflag FLAG_READ_SIGNPOST
    if SET _goto EventScript_RockTunnel_Jirachi_Start
    msgbox gText_RockTunnel_Jirachi_Signpost_1 MSG_KEEPOPEN
    closeonkeypress
    checkflag FLAG_TEACH_CLEFAIRY_DAZZLING_GLEAM
    if NOT_SET _goto EventScript_Legendaries_End
    checkflag FLAG_OLD_WOMAN_FIRE_HEAD
    if NOT_SET _goto EventScript_Legendaries_End
    checkflag FLAG_MEAN_LOOKING_FISH
    if NOT_SET _goto EventScript_Legendaries_End
    pause 60
    fadescreenspeed 0x3 5
    cry SPECIES_JIRACHI 0x0
    showsprite 0x1
    clearflag FLAG_JIRACHI_ROCKTUNNEL
    fadescreenspeed 0x2 5
    msgbox gText_RockTunnel_Jirachi_Narrator_1 MSG_KEEPOPEN
    closeonkeypress
    setflag FLAG_READ_SIGNPOST
    release
    end

EventScript_RockTunnel_Jirachi_Start:
    checkflag FLAG_JIRACHI_ROCKTUNNEL
    if SET _goto EventScript_RockTunnel_Jirachi_Signpost_Done
    msgbox gText_RockTunnel_Jirachi_Start_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_RockTunnel_Jirachi_Signpost_Done:
    msgbox gText_RockTunnel_Jirachi_Signpost_2 MSG_KEEPOPEN
    closeonkeypress
    release
    end

Move_RockTunnel_Jirachi_Event_Jigglypuff_1:
    .byte walk_left_slow
    .byte walk_left_slow
    .byte walk_up_onspot_fastest
    .byte jump_onspot_up
    .byte pause_long
    .byte walk_right_slow
    .byte walk_right_slow
    .byte walk_right_slow
    .byte walk_right_slow
    .byte walk_up_onspot_fastest
    .byte jump_onspot_up
    .byte pause_long
    .byte walk_left_slow
    .byte walk_left_slow
    .byte walk_up_onspot_fastest
    .byte jump_onspot_up
    .byte jump_onspot_up
    .byte pause_long
    .byte end_m

Move_RockTunnel_Jirachi_Event_Jigglypuff_2:
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte walk_up_onspot_fastest
    .byte walk_up_onspot_fastest
    .byte walk_up_onspot_fastest
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte jump_onspot_up
    .byte jump_onspot_up
    .byte pause_long
    .byte end_m

Move_RockTunnel_Jirachi_Event_Jirachi_1:
    .byte say_smile
    .byte say_double_exclaim
    .byte end_m

Move_RockTunnel_Jirachi_Event_Jirachi_2:
    .byte exclaim
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Rayquaza Navel Rock
@@@@@@@@@@@@@@@@@@@@@@
EventScript_NavelRock_Rayquaza:
    lock
    signmsg
    msgbox gText_NavelRock_Rayquaza_Narrator_1 MSG_YESNO
    compare LASTRESULT 0x1
    if notequal _goto EventScript_Legendaries_End
    closeonkeypress
    callasm CheckWeatherDuo
    compare 0x8004 0
    if equal _goto EventScript_NavelRock_Rayquaza_End
    fadescreenspeed 0x3 0
    fadescreenspeed 0x2 0
    pause 30
    msgbox gText_NavelRock_Rayquaza_Narrator_2 MSG_KEEPOPEN
    closeonkeypress
    pause 30
    sound 0x15
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    fadescreenspeed 0x3 0
    fadescreenspeed 0x2 0
    cry SPECIES_RAYQUAZA 0x0
    msgbox gText_NavelRock_Rayquaza_1 MSG_KEEPOPEN
    closeonkeypress
    pause 30
    wildbattle SPECIES_RAYQUAZA 70 ITEM_NONE
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_Legendaries_End
    compare LASTRESULT 0x4
    if TRUE _goto EventScript_Legendaries_End
    fadescreenspeed 0x3 0
    hidesprite LASTTALKED
    setflag FLAG_RAYQUAZA_NAVELROCK
    fadescreenspeed 0x2 0
    msgbox gText_NavelRock_Rayquaza_Narrator_3 MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_NavelRock_Rayquaza_End:
    pause 30
    fadescreenspeed 0x3 0
    fadescreenspeed 0x2 0
    msgbox gText_NavelRock_Rayquaza_End MSG_KEEPOPEN
    closeonkeypress
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Celebi Viridian Forest
@@@@@@@@@@@@@@@@@@@@@@
EventScript_VidianForest_Celebi:
    lock
    signmsg
    pause 30
    sound 0x15
    applymovement PLAYER Move_VidianForest_Celebi_Player_1
    waitmovement PLAYER
    msgbox gText_VidianForest_Celebi_Narrator_1 MSG_KEEPOPEN
    closeonkeypress
    fadescreenspeed 0x3 5
    cry SPECIES_CELEBI 0x0
    fadescreenspeed 0x2 5
    pause 30
    msgbox gText_VidianForest_Celebi_Narrator_2 MSG_YESNO
    compare LASTRESULT 0x1
    if notequal _goto EventScript_Legendaries_End
    closeonkeypress
    pause 30
    fadescreenspeed 0x3 3
    fadescreenspeed 0x2 3
    cry SPECIES_CELEBI 0x0
    msgbox gText_VidianForest_Celebi_1 MSG_KEEPOPEN
    closeonkeypress
    pause 30
    wildbattle SPECIES_CELEBI 40 ITEM_NONE
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_Legendaries_End
    compare LASTRESULT 0x4
    if TRUE _goto EventScript_Legendaries_End
    fadescreenspeed 0x3 0
    hidesprite LASTTALKED
    setflag FLAG_CELEBI_VIRIDIAN_FOREST
    fadescreenspeed 0x2 0
    msgbox gText_VidianForest_Celebi_Narrator_3 MSG_KEEPOPEN
    closeonkeypress
    release
    end

Move_VidianForest_Celebi_Player_1:
    .byte exclaim
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Lake Guardian Trio
@@@@@@@@@@@@@@@@@@@@@@
EventScript_ViridianLake_GuardianTrio:
    lock
    checkflag FLAG_AZELF_VIRIDIAN_LAKE
    if NOT_SET _goto EventScript_ViridianLake_Azelf
    checkflag FLAG_MESPRIT_VIRIDIAN_LAKE
    if NOT_SET _goto EventScript_ViridianLake_Mesprit
    checkflag FLAG_UXIE_VIRIDIAN_LAKE
    if NOT_SET _goto EventScript_ViridianLake_Uxie
    release
    end

EventScript_ViridianLake_Azelf:
    signmsg
    pause 30
    msgbox gText_ViridianLake_GuardianTrio_Narrator_1 MSG_YESNO
    compare LASTRESULT 0x1
    if notequal _goto EventScript_Legendaries_End
    closeonkeypress
    pause 15
    sound 0x15
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    pause 15
    cry SPECIES_AZELF 0x0
    msgbox gText_ViridianLake_GuardianTrio MSG_KEEPOPEN
    closeonkeypress
    pause 30
    wildbattle SPECIES_AZELF 60 ITEM_NONE
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if equal _goto EventScript_Legendaries_End
    compare LASTRESULT 0x4
    if equal _goto EventScript_Legendaries_End
    pause 15
    fadescreenspeed 0x3 0
    setflag FLAG_AZELF_VIRIDIAN_LAKE
    fadescreenspeed 0x2 0
    pause 30
    sound 0x15
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    release
    end

EventScript_ViridianLake_Mesprit:
    signmsg
    pause 30
    msgbox gText_ViridianLake_GuardianTrio_Narrator_1 MSG_YESNO
    compare LASTRESULT 0x1
    if notequal _goto EventScript_Legendaries_End
    closeonkeypress
    pause 15
    sound 0x15
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    pause 15
    cry SPECIES_MESPRIT 0x0
    msgbox gText_ViridianLake_GuardianTrio MSG_KEEPOPEN
    closeonkeypress
    pause 30
    wildbattle SPECIES_MESPRIT 60 ITEM_NONE
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if equal _goto EventScript_Legendaries_End
    compare LASTRESULT 0x4
    if equal _goto EventScript_Legendaries_End
    pause 15
    fadescreenspeed 0x3 0
    setflag FLAG_MESPRIT_VIRIDIAN_LAKE
    fadescreenspeed 0x2 0
    pause 30
    sound 0x15
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    release
    end

EventScript_ViridianLake_Uxie:
    signmsg
    pause 30
    msgbox gText_ViridianLake_GuardianTrio_Narrator_1 MSG_YESNO
    compare LASTRESULT 0x1
    if notequal _goto EventScript_Legendaries_End
    closeonkeypress
    pause 15
    sound 0x15
    applymovement PLAYER Move_PlayerExclaim
    waitmovement PLAYER
    pause 15
    cry SPECIES_UXIE 0x0
    msgbox gText_ViridianLake_GuardianTrio MSG_KEEPOPEN
    closeonkeypress
    pause 30
    wildbattle SPECIES_UXIE 60 ITEM_NONE
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if equal _goto EventScript_Legendaries_End
    compare LASTRESULT 0x4
    if equal _goto EventScript_Legendaries_End
    pause 15
    fadescreenspeed 0x3 0
    hidesprite 0x1
    setflag FLAG_UXIE_VIRIDIAN_LAKE
    fadescreenspeed 0x2 0
    msgbox gText_ViridianLake_GuardianTrio_Narrator_2 MSG_KEEPOPEN
    closeonkeypress
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Legendary General
@@@@@@@@@@@@@@@@@@@@@@
Move_PlayerExclaim:
    .byte exclaim
    .byte pause_long
    .byte pause_long
    .byte end_m

EventScript_Legendaries_End:
    release
    end
