.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ RIVAL_2F, 1
.equ MAY_2F, 2

@@@@@@@@@@@@@@@@@@@@@@
@ Player Room Map Script
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Pallet_Town_Player_House_2F:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_Pallet_Town_Player_House_2F
    mapscript MAP_SCRIPT_ON_LOAD MapOnLoadScript_Pallet_Town_Player_House_2F
    mapscript MAP_SCRIPT_ON_TRANSITION MapOnTransition_Pallet_Town_Player_House_2F
    .byte MAP_SCRIPT_TERMIN

MapOnLoadScript_Pallet_Town_Player_House_2F:
    setflag FLAG_HIDE_PALLET_TOWN_PLAYER_HOUSE_2F_MAY
    end

MapOnTransition_Pallet_Town_Player_House_2F:
    sethealingplace 0x1
    end

LevelScript_Pallet_Town_Player_House_2F:
    levelscript VAR_MAP_SCENE_PALLET_TOWN_PLAYER_HOUSE, 0, EventScript_Pallet_Town_Player_House_2F_Intro
    .hword LEVEL_SCRIPT_TERMIN

@@@@@@@@@@@@@@@@@@@@@@
@ Intro Cutscene inside player room
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_Player_House_2F_Intro:
    lock
    pause 30
    applymovement RIVAL_2F Move_Pallet_Town_Player_House_2F_Intro_Rival_1
    waitmovement RIVAL_2F
    npcmsg gText_Pallet_Town_Player_House_2F_Intro_Rival_1 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    applymovement RIVAL_2F Move_Pallet_Town_Player_House_2F_Intro_Rival_2
    waitmovement RIVAL_2F
    npcmsg gText_Pallet_Town_Player_House_2F_Intro_Rival_2 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    pause 30
    special 0x113
    applymovement CAMERA Move_Pallet_Town_Player_House_2F_Intro_Camera_1
    waitmovement CAMERA
    special 0x114
    showsprite MAY_2F
    sound 0x9
    applymovement MAY_2F Move_Pallet_Town_Player_House_2F_Intro_May_1
    waitmovement MAY_2F
    playsong 0x1A7 0x0
    spriteface PLAYER UP
    spriteface RIVAL_2F UP
    npcmsg gText_Pallet_Town_Player_House_2F_Intro_May_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement RIVAL_2F Move_Pallet_Town_Player_House_2F_Intro_Rival_3
    waitmovement RIVAL_2F
    spriteface MAY_2F RIGHT
    npcmsg gText_Pallet_Town_Player_House_2F_Intro_Rival_3 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    pause 15
    special 0x113
    applymovement CAMERA Move_Pallet_Town_Player_House_2F_Intro_Camera_2
    waitmovement CAMERA
    special 0x114
    applymovement MAY_2F Move_Pallet_Town_Player_House_2F_Intro_May_2
    waitmovement MAY_2F
    spriteface RIVAL_2F DOWN
    npcmsg gText_Pallet_Town_Player_House_2F_Intro_May_2 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement MAY_2F Move_Pallet_Town_Player_House_2F_Intro_May_3
    waitmovement MAY_2F
    spriteface PLAYER LEFT
    npcmsg gText_Pallet_Town_Player_House_2F_Intro_May_3 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_Pallet_Town_Player_House_2F_Intro_Rival_4 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    fadedefaultbgm
    applymovement RIVAL_2F Move_Pallet_Town_Player_House_2F_Intro_Rival_4
    waitmovement RIVAL_2F
    spriteface PLAYER DOWN
    spriteface MAY_2F DOWN
    npcmsg gText_Pallet_Town_Player_House_2F_Intro_Rival_5 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    setvar VAR_MAP_SCENE_PALLET_TOWN_PLAYER_HOUSE 0x1
    call EventScript_SetAllMapFlags
    release
    end

Move_Pallet_Town_Player_House_2F_Intro_Rival_1:
    .byte walk_down
    .byte walk_left_onspot_fastest
    .byte end_m

Move_Pallet_Town_Player_House_2F_Intro_Rival_2:
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Pallet_Town_Player_House_2F_Intro_Rival_3:
    .byte walk_up
    .byte walk_up
    .byte walk_left
    .byte end_m

Move_Pallet_Town_Player_House_2F_Intro_Rival_4:
    .byte pause_long
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_Pallet_Town_Player_House_2F_Intro_May_1:
    .byte walk_right
    .byte pause_short
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Pallet_Town_Player_House_2F_Intro_May_2:
    .byte pause_short
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte end_m

Move_Pallet_Town_Player_House_2F_Intro_May_3:
    .byte pause_long
    .byte walk_down
    .byte walk_right
    .byte end_m

Move_Pallet_Town_Player_House_2F_Intro_Camera_1:
    .byte walk_left
    .byte walk_left
    .byte end_m

Move_Pallet_Town_Player_House_2F_Intro_Camera_2:
    .byte walk_right
    .byte walk_right
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Trio Choosing Starters
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_Player_House_2F_Ball_Left:
    setvar 0x4001 0x0
    goto EventScript_Pallet_Town_Player_House_2F_Choose_Starter

EventScript_Pallet_Town_Player_House_2F_Ball_Center:
    setvar 0x4001 0x1
    goto EventScript_Pallet_Town_Player_House_2F_Choose_Starter

EventScript_Pallet_Town_Player_House_2F_Ball_Right:
    setvar 0x4001 0x2
    goto EventScript_Pallet_Town_Player_House_2F_Choose_Starter

EventScript_Pallet_Town_Player_House_2F_Choose_Starter:
    lock
    checkflag 0x1
    if SET _goto EventScript_Pallet_Town_Player_House_2F_Choose_Starter_2
    msgbox gText_Pallet_Town_Player_House_2F_Choose_Starter_Attachment MSG_KEEPOPEN
    closeonkeypress
    setflag 0x1
    goto EventScript_Pallet_Town_Player_House_2F_Choose_Starter_2

EventScript_Pallet_Town_Player_House_2F_Choose_Starter_2:
    pause 5
    compare 0x4001 0x0
    if equal _goto EventScript_Pallet_Town_Player_House_2F_Choose_Starter_Show_Snivy
    compare 0x4001 0x1
    if equal _goto EventScript_Pallet_Town_Player_House_2F_Choose_Starter_Show_Oshawott
    compare 0x4001 0x2
    if equal _goto EventScript_Pallet_Town_Player_House_2F_Choose_Starter_Show_Tepig
    end

EventScript_Pallet_Town_Player_House_2F_Choose_Starter_Show_Snivy:
    setvar 0x4002 0x3
    showpokepic SPECIES_SNIVY
    cry SPECIES_SNIVY 0x0
    msgbox gText_Pallet_Town_Player_House_2F_Choose_Starter_Snivy MSG_YESNO
    compare LASTRESULT 0x1
    if equal _goto EventScript_Pallet_Town_Player_House_2F_Received_Starter
    hidepokepic
    release
    end

EventScript_Pallet_Town_Player_House_2F_Choose_Starter_Show_Oshawott:
    setvar 0x4002 0x4
    showpokepic SPECIES_OSHAWOTT
    cry SPECIES_OSHAWOTT 0x0
    msgbox gText_Pallet_Town_Player_House_2F_Choose_Starter_Oshawott MSG_YESNO
    compare LASTRESULT 0x1
    if equal _goto EventScript_Pallet_Town_Player_House_2F_Received_Starter
    hidepokepic
    release
    end

EventScript_Pallet_Town_Player_House_2F_Choose_Starter_Show_Tepig:
    setvar 0x4002 0x5
    showpokepic SPECIES_TEPIG
    cry SPECIES_TEPIG 0x0
    msgbox gText_Pallet_Town_Player_House_2F_Choose_Starter_Tepig MSG_YESNO
    compare LASTRESULT 0x1
    if equal _goto EventScript_Pallet_Town_Player_House_2F_Received_Starter
    hidepokepic
    release
    end

EventScript_Pallet_Town_Player_House_2F_Received_Starter:
    pause 15
    hidesprite 0x4002
    fanfare 0x13E
    msgbox gText_Pallet_Town_Player_House_2F_Obtained_Pokemon MSG_KEEPOPEN
    closeonkeypress
    waitfanfare
    hidepokepic
    setflag 0x828
    copyvar VAR_STARTER_MON 0x4001
    compare VAR_STARTER_MON 0x0
    if equal _call EventScript_GivePlayer_Snivy
    compare VAR_STARTER_MON 0x1
    if equal _call EventScript_GivePlayer_Oshawott
    compare VAR_STARTER_MON 0x2
    if equal _call EventScript_GivePlayer_Tepig
    msgbox gText_Pallet_Town_Player_House_2F_Received_Starter_WantToNickName MSG_YESNO
    compare LASTRESULT 0x1
    if equal _call EventScript_Nickname_Scene
    closeonkeypress
    compare 0x4001 0x0
    if equal _call EventScript_Pallet_Town_Player_House_2F_May_Oshawott
    compare 0x4001 0x1
    if equal _call EventScript_Pallet_Town_Player_House_2F_May_Tepig
    compare 0x4001 0x2
    if equal _call EventScript_Pallet_Town_Player_House_2F_May_Snivy
    npcmsg gText_Pallet_Town_Player_House_2F_Received_Starter_Rival_2 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    pause 15
    fadescreen 0x1
    movesprite MAY_2F 7 5
    movesprite RIVAL_2F 6 3
    spriteface MAY_2F LEFT
    getplayerpos 0x8001 0x8002
    compare 0x8001 4
    if equal _call Reposition_Player_4
    compare 0x8001 5
    if equal _call Reposition_Player_5
    compare 0x8001 6
    if equal _call Reposition_Player_6
    compare 0x8001 7
    if equal _call Reposition_Player_7
    compare 0x8001 8
    if equal _call Reposition_Player_8
    fadescreen 0x0
    npcmsg gText_Pallet_Town_Player_House_2F_Received_Starter_May_2 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_Pallet_Town_Player_House_2F_Received_Starter_Rival_3 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    npcmsg gText_Pallet_Town_Player_House_2F_Received_Starter_May_3 MSG_KEEPOPEN gText_Name_May
    closemsg
    pause 5
    compare VAR_STARTER_MON 0x0
    if equal _call EventScript_Pallet_Town_Player_House_2F_May_Battle_Oshawott
    compare VAR_STARTER_MON 0x1
    if equal _call EventScript_Pallet_Town_Player_House_2F_May_Battle_Tepig
    compare VAR_STARTER_MON 0x2
    if equal _call EventScript_Pallet_Town_Player_House_2F_May_Battle_Snivy
    special 0x0
    pause 15
    npcmsg gText_Pallet_Town_Player_House_2F_After_Battle_May_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_Pallet_Town_Player_House_2F_After_Battle_Rival_1 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    applymovement MAY_2F Move_Pallet_Town_Player_House_2F_After_Batte_May_1
    waitmovement MAY_2F
    sound 0x15
    npcmsg gText_Pallet_Town_Player_House_2F_After_Battle_May_2 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement MAY_2F Move_Pallet_Town_Player_House_2F_After_Batte_May_2
    waitmovement MAY_2F
    npcmsg gText_Pallet_Town_Player_House_2F_After_Battle_May_3 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement RIVAL_2F Move_Pallet_Town_Player_House_2F_After_Batte_Rival_1
    waitmovement RIVAL_2F
    npcmsg gText_Pallet_Town_Player_House_2F_After_Battle_Rival_2 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    sound 0x1
    msgbox gText_Pallet_Town_Player_House_2F_After_Battle_Rival_HealedMayPokemon MSG_KEEPOPEN
    closeonkeypress
    spriteface RIVAL_2F LEFT
    npcmsg gText_Pallet_Town_Player_House_2F_After_Battle_Rival_3 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    sound 0x1
    msgbox gText_Pallet_Town_Player_House_2F_After_Battle_Rival_HealedPlayerPokemon MSG_KEEPOPEN
    closeonkeypress
    pause 15
    sound 0x15
    applymovement MAY_2F Move_Pallet_Town_Player_House_2F_After_Batte_May_3
    waitmovement MAY_2F
    spriteface RIVAL_2F UP
    spriteface PLAYER UP
    npcmsg gText_Pallet_Town_Player_House_2F_After_Battle_May_4 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_Pallet_Town_Player_House_2F_After_Battle_Rival_4 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    applymovement RIVAL_2F Move_Pallet_Town_Player_House_2F_After_Batte_Rival_2
    applymovement PLAYER Move_Pallet_Town_Player_House_2F_After_Batte_Player_1
    waitmovement RIVAL_2F
    npcmsg gText_Pallet_Town_Player_House_2F_After_Battle_Rival_5 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    pause 5
    compare VAR_STARTER_MON 0x0
    if equal _call EventScript_Pallet_Town_Player_House_2F_Rival_Battle_Tepig
    compare VAR_STARTER_MON 0x1
    if equal _call EventScript_Pallet_Town_Player_House_2F_Rival_Battle_Snivy
    compare VAR_STARTER_MON 0x2
    if equal _call EventScript_Pallet_Town_Player_House_2F_Rival_Battle_Oshawott
    special 0x0
    pause 15
    npcmsg gText_Pallet_Town_Player_House_2F_After_Battle_Rival_6 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    applymovement RIVAL_2F Move_Pallet_Town_Player_House_2F_After_Batte_Rival_3
    waitmovement RIVAL_2F
    sound 0x9
    hidesprite RIVAL_2F
    setflag FLAG_HIDE_PALLET_TOWN_PLAYER_HOUSE_2F_RIVAL
    npcmsg gText_Pallet_Town_Player_House_2F_After_Battle_May_5 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement MAY_2F Move_Pallet_Town_Player_House_2F_After_Batte_May_4
    waitmovement MAY_2F
    sound 0x9
    hidesprite MAY_2F
    setflag FLAG_HIDE_PALLET_TOWN_PLAYER_HOUSE_2F_STARTER_SNIVY
    setflag FLAG_HIDE_PALLET_TOWN_PLAYER_HOUSE_2F_STARTER_OSHAWOTT
    setflag FLAG_HIDE_PALLET_TOWN_PLAYER_HOUSE_2F_STARTER_TEPIG
    setvar VAR_MAP_SCENE_PALLET_TOWN_PLAYER_HOUSE 0x2
    release
    end

EventScript_Pallet_Town_Player_House_2F_May_Battle_Oshawott:
    trainerbattle9 0x9 62 0x1 gText_Pallet_Town_Player_House_2F_May_Battle_Defeat gText_Pallet_Town_Player_House_2F_May_Battle_Win
    return

EventScript_Pallet_Town_Player_House_2F_May_Battle_Tepig:
    trainerbattle9 0x9 63 0x1 gText_Pallet_Town_Player_House_2F_May_Battle_Defeat gText_Pallet_Town_Player_House_2F_May_Battle_Win
    return

EventScript_Pallet_Town_Player_House_2F_May_Battle_Snivy:
    trainerbattle9 0x9 64 0x1 gText_Pallet_Town_Player_House_2F_May_Battle_Defeat gText_Pallet_Town_Player_House_2F_May_Battle_Win
    return

EventScript_Pallet_Town_Player_House_2F_Rival_Battle_Tepig:
    trainerbattle9 0x9 326 0x3 gText_Pallet_Town_Player_House_2F_Rival_Battle_Defeat gText_Pallet_Town_Player_House_2F_Rival_Battle_Win
    return

EventScript_Pallet_Town_Player_House_2F_Rival_Battle_Snivy:
    trainerbattle9 0x9 327 0x3 gText_Pallet_Town_Player_House_2F_Rival_Battle_Defeat gText_Pallet_Town_Player_House_2F_Rival_Battle_Win
    return

EventScript_Pallet_Town_Player_House_2F_Rival_Battle_Oshawott:
    trainerbattle9 0x9 328 0x3 gText_Pallet_Town_Player_House_2F_Rival_Battle_Defeat gText_Pallet_Town_Player_House_2F_Rival_Battle_Win
    return

EventScript_Pallet_Town_Player_House_2F_May_Oshawott:
    applymovement MAY_2F Move_Pallet_Town_Player_House_2F_May_Oshawott_1
    waitmovement MAY_2F
    pause 5
    hidesprite 0x4
    npcmsg gText_Pallet_Town_Player_House_2F_Received_Starter_May_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement RIVAL_2F Move_Pallet_Town_Player_House_2F_Rival_Agitated
    waitmovement RIVAL_2F
    npcmsg gText_Pallet_Town_Player_House_2F_Received_Starter_Rival_1 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    applymovement RIVAL_2F Move_Pallet_Town_Player_House_2F_Rival_Tepig_1
    waitmovement RIVAL_2F
    pause 5
    hidesprite 0x5
    return

EventScript_Pallet_Town_Player_House_2F_May_Tepig:
    applymovement MAY_2F Move_Pallet_Town_Player_House_2F_May_Tepig_1
    waitmovement MAY_2F
    pause 5
    hidesprite 0x5
    npcmsg gText_Pallet_Town_Player_House_2F_Received_Starter_May_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement RIVAL_2F Move_Pallet_Town_Player_House_2F_Rival_Agitated
    waitmovement RIVAL_2F
    npcmsg gText_Pallet_Town_Player_House_2F_Received_Starter_Rival_1 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    applymovement RIVAL_2F Move_Pallet_Town_Player_House_2F_Rival_Snivy_1
    waitmovement RIVAL_2F
    pause 5
    hidesprite 0x3
    return

EventScript_Pallet_Town_Player_House_2F_May_Snivy:
    applymovement MAY_2F Move_Pallet_Town_Player_House_2F_May_Snivy_1
    waitmovement MAY_2F
    pause 5
    hidesprite 0x3
    npcmsg gText_Pallet_Town_Player_House_2F_Received_Starter_May_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement RIVAL_2F Move_Pallet_Town_Player_House_2F_Rival_Agitated
    waitmovement RIVAL_2F
    npcmsg gText_Pallet_Town_Player_House_2F_Received_Starter_Rival_1 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    applymovement RIVAL_2F Move_Pallet_Town_Player_House_2F_Rival_Oshawott_1
    waitmovement RIVAL_2F
    pause 5
    hidesprite 0x4
    return

EventScript_GivePlayer_Snivy:
    givepokemon SPECIES_SNIVY 0x5 ITEM_NONE
    return

EventScript_GivePlayer_Oshawott:
    givepokemon SPECIES_OSHAWOTT 0x5 ITEM_NONE
    return

EventScript_GivePlayer_Tepig:
    givepokemon SPECIES_TEPIG 0x5 ITEM_NONE
    return

EventScript_Nickname_Scene:
    setvar 0x8004 0x0
    fadescreen 0x1
    special 0x9E
    waitstate
    return

Move_Pallet_Town_Player_House_2F_May_Oshawott_1:
    .byte walk_right
    .byte walk_down
    .byte end_m

Move_Pallet_Town_Player_House_2F_May_Tepig_1:
    .byte walk_up
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Pallet_Town_Player_House_2F_May_Snivy_1:
    .byte walk_down
    .byte end_m

Move_Pallet_Town_Player_House_2F_Rival_Agitated:
    .byte pause_long
    .byte say_question
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Pallet_Town_Player_House_2F_Rival_Tepig_1:
    .byte walk_down
    .byte end_m

Move_Pallet_Town_Player_House_2F_Rival_Snivy_1:
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte end_m

Move_Pallet_Town_Player_House_2F_Rival_Oshawott_1:
    .byte walk_left
    .byte walk_down
    .byte end_m

Reposition_Player_4:
    applymovement PLAYER Move_Player_4
    waitmovement PLAYER
    return

Move_Player_4:
    .byte walk_up
    .byte walk_up
    .byte walk_right
    .byte end_m

Reposition_Player_5:
    applymovement PLAYER Move_Player_5
    waitmovement PLAYER
    return

Move_Player_5:
    .byte walk_up
    .byte walk_right_onspot_fastest
    .byte end_m

Reposition_Player_6:
    applymovement PLAYER Move_Player_6
    waitmovement PLAYER
    return

Move_Player_6:
    .byte walk_left
    .byte walk_up
    .byte walk_right_onspot_fastest
    .byte end_m

Reposition_Player_7:
    applymovement PLAYER Move_Player_7
    waitmovement PLAYER
    return

Move_Player_7:
    .byte walk_left
    .byte walk_left
    .byte walk_up
    .byte walk_right_onspot_fastest
    .byte end_m

Reposition_Player_8:
    applymovement PLAYER Move_Player_8
    waitmovement PLAYER
    return

Move_Player_8:
    .byte walk_up
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_up
    .byte walk_right_onspot_fastest
    .byte end_m

Move_Pallet_Town_Player_House_2F_After_Batte_May_1:
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte exclaim
    .byte end_m

Move_Pallet_Town_Player_House_2F_After_Batte_May_2:
    .byte pause_long
    .byte face_player
    .byte end_m

Move_Pallet_Town_Player_House_2F_After_Batte_May_3:
    .byte exclaim
    .byte pause_long
    .byte pause_long
    .byte walk_up
    .byte walk_up
    .byte walk_left
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Pallet_Town_Player_House_2F_After_Batte_May_4:
    .byte pause_long
    .byte pause_long
    .byte walk_up
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte end_m

Move_Pallet_Town_Player_House_2F_After_Batte_Rival_1:
    .byte pause_long
    .byte walk_down
    .byte walk_down
    .byte walk_right_onspot_fastest
    .byte end_m

Move_Pallet_Town_Player_House_2F_After_Batte_Rival_2:
    .byte pause_long
    .byte walk_right
    .byte walk_left_onspot_fastest
    .byte end_m

Move_Pallet_Town_Player_House_2F_After_Batte_Rival_3:
    .byte walk_up
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_up
    .byte walk_up
    .byte walk_left
    .byte end_m

Move_Pallet_Town_Player_House_2F_After_Batte_Player_1:
    .byte pause_long
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Rival
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_Player_House_2F_Rival:
    lock
    faceplayer
    npcmsg gText_Pallet_Town_Player_House_2F_Rival_1 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ May
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_Player_House_2F_May:
    lock
    faceplayer
    npcmsg gText_Pallet_Town_Player_House_2F_May_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Rival says check the mons
@@@@@@@@@@@@@@@@@@@@@@
TileScript_Pallet_Town_Player_House_2F:
    applymovement PLAYER Move_Pallet_Town_Player_House_2F_Player_1
    applymovement RIVAL_2F Move_Pallet_Town_Player_House_2F_Rival_1
    waitmovement PLAYER
    npcmsg gText_Pallet_Town_Player_House_2F_CheckOutTheMons MSG_KEEPOPEN gText_Name_Rival
    closemsg
    applymovement PLAYER Move_Pallet_Town_Player_House_2F_Player_2
    waitmovement PLAYER
    release
    end

Move_Pallet_Town_Player_House_2F_Player_1:
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Pallet_Town_Player_House_2F_Rival_1:
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Pallet_Town_Player_House_2F_Player_2:
    .byte walk_right
    .byte end_m

EventScript_SetAllMapFlags:
    setflag FLAG_HIDE_PALLET_TOWN_OUTSIDE_MOM
	clearflag 0x02B @ show oak inside his lab
	clearflag 0x02C @ show kid in pallet town to prevent player

	@setflag @FLAG_HIDE_BILL_HUMAN_SEA_COTTAGE
	@setflag @FLAG_HIDE_PEWTER_CITY_RUNNING_SHOES_GUY
	@setflag @FLAG_HIDE_POKEHOUSE_FUJI
	@setflag @FLAG_HIDE_LIFT_KEY
	@setflag @FLAG_HIDE_SILPH_SCOPE
	@setflag @FLAG_HIDE_CERULEAN_RIVAL
	@setflag @FLAG_HIDE_SS_ANNE_RIVAL
	@setflag @FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
	@setflag @FLAG_HIDE_SAFFRON_CIVILIANS
	@setflag @FLAG_HIDE_ROUTE_22_RIVAL
	@setflag @FLAG_HIDE_OAK_IN_CHAMP_ROOM
	@setflag @FLAG_HIDE_CREDITS_RIVAL
	@setflag @FLAG_HIDE_CREDITS_OAK
	@setflag @FLAG_HIDE_CINNABAR_BILL
	@setflag @FLAG_HIDE_CINNABAR_SEAGALLOP
	@setflag @FLAG_HIDE_CINNABAR_POKECENTER_BILL
	@setflag @FLAG_HIDE_LORELEI_IN_HER_HOUSE
	@setflag @FLAG_HIDE_SAFFRON_FAN_CLUB_BLACKBELT
	@setflag @FLAG_HIDE_SAFFRON_FAN_CLUB_ROCKER
	@setflag @FLAG_HIDE_SAFFRON_FAN_CLUB_WOMAN
	@setflag @FLAG_HIDE_SAFFRON_FAN_CLUB_BEAUTY
	@setflag @FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE
	@setflag @FLAG_HIDE_TWO_ISLAND_GAME_CORNER_BIKER
	@setflag @FLAG_HIDE_TWO_ISLAND_WOMAN
	@setflag @FLAG_HIDE_TWO_ISLAND_BEAUTY
	@setflag @FLAG_HIDE_TWO_ISLAND_SUPER_NERD
	@setflag @FLAG_HIDE_LOSTELLE_IN_HER_HOME
	@setflag @FLAG_HIDE_THREE_ISLAND_LONE_BIKER
	@setflag @FLAG_HIDE_FOUR_ISLAND_RIVAL
	@setflag @FLAG_HIDE_DOTTED_HOLE_SCIENTIST
	@setflag @FLAG_HIDE_RESORT_GORGEOUS_SELPHY
	@setflag @FLAG_HIDE_RESORT_GORGEOUS_INSIDE_SELPHY
	@setflag @FLAG_HIDE_SELPHYS_BUTLER
	@setflag @FLAG_HIDE_DEOXYS
	@setflag @FLAG_HIDE_LORELEI_HOUSE_MEOWTH_DOLL
	@setflag @FLAG_HIDE_LORELEI_HOUSE_CHANSEY_DOLL
	@setflag @FLAG_HIDE_LORELEIS_HOUSE_NIDORAN_F_DOLL
	@setflag @FLAG_HIDE_LORELEI_HOUSE_JIGGLYPUFF_DOLL
	@setflag @FLAG_HIDE_LORELEIS_HOUSE_NIDORAN_M_DOLL
	@setflag @FLAG_HIDE_LORELEIS_HOUSE_FEAROW_DOLL
	@setflag @FLAG_HIDE_LORELEIS_HOUSE_PIDGEOT_DOLL
	@setflag @FLAG_HIDE_LORELEIS_HOUSE_LAPRAS_DOLL
	@setflag @FLAG_HIDE_POSTGAME_GOSSIPERS
	@setflag @FLAG_HIDE_FAME_CHECKER_ERIKA_JOURNALS
	@setflag @FLAG_HIDE_FAME_CHECKER_KOGA_JOURNAL
	@setflag @FLAG_HIDE_FAME_CHECKER_LT_SURGE_JOURNAL
	@setflag @FLAG_HIDE_SAFFRON_CITY_POKECENTER_SABRINA_JOURNALS
	@setvar @VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500
	end
    return
