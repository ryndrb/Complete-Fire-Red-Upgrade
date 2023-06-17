.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ MOM, 1
.equ RIVAL, 2
.equ MAY, 3

@@@@@@@@@@@@@@@@@@@@@@
@ Player House Map Script
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Pallet_Town_Player_House_1F:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_Pallet_Town_Player_House_1F
    mapscript MAP_SCRIPT_ON_TRANSITION MapOnTransition_Pallet_Town_Player_House_1F
    .byte MAP_SCRIPT_TERMIN

MapOnTransition_Pallet_Town_Player_House_1F:
    compare VAR_MAP_SCENE_PALLET_TOWN_PLAYER_HOUSE 0x2
    if equal _call EventScript_Pallet_Town_Player_House_1F_MoveMom
    end

EventScript_Pallet_Town_Player_House_1F_MoveMom:
    movesprite2 MOM 0x7 0x5
    spritebehave MOM 10
    return

LevelScript_Pallet_Town_Player_House_1F:
    levelscript VAR_MAP_SCENE_PALLET_TOWN_PLAYER_HOUSE, 2, EventScript_Pallet_Town_Player_House_1F_Leaving
    .hword LEVEL_SCRIPT_TERMIN

EventScript_Pallet_Town_Player_House_1F_Leaving:
    lock
    pause 15
    spriteface PLAYER DOWN
    pause 15
    special 0x113
    applymovement CAMERA Move_Pallet_Town_Player_House_1F_Camera_1
    waitmovement CAMERA
    special 0x114
    npcmsg gText_Pallet_Town_Player_House_1F_Leaving_Rival_1 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    applymovement MAY Move_Pallet_Town_Player_House_1F_Leaving_May_1
    waitmovement MAY
    npcmsg gText_Pallet_Town_Player_House_1F_Leaving_May_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_Pallet_Town_Player_House_1F_Leaving_Mom_1 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    npcmsg gText_Pallet_Town_Player_House_1F_Leaving_Rival_2 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    applymovement RIVAL Move_Pallet_Town_Player_House_1F_Leaving_Rival_1
    waitmovement RIVAL
    npcmsg gText_Pallet_Town_Player_House_1F_Leaving_Rival_3 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    pause 15
    sound 0x15
    applymovement MAY Move_Pallet_Town_Player_House_1F_Leaving_May_2
    waitmovement MAY
    npcmsg gText_Pallet_Town_Player_House_1F_Leaving_May_2 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement MAY Move_Pallet_Town_Player_House_1F_Leaving_May_3
    waitmovement MAY
    npcmsg gText_Pallet_Town_Player_House_1F_Leaving_May_3 MSG_KEEPOPEN gText_Name_May
    closemsg
    pause 5
    applymovement MAY Move_Pallet_Town_Player_House_1F_Leaving_May_4
    applymovement RIVAL Move_Pallet_Town_Player_House_1F_Leaving_Rival_2
    waitmovement MAY
    sound 0x9
    hidesprite RIVAL
    hidesprite MAY
    setflag FLAG_HIDE_PALLET_TOWN_PLAYER_HOUSE_1F_RIVAL
    setflag FLAG_HIDE_PALLET_TOWN_PLAYER_HOUSE_1F_MAY
    pause 15
    special 0x113
    applymovement CAMERA Move_Pallet_Town_Player_House_1F_Camera_2
    waitmovement CAMERA
    special 0x114
    applymovement MOM Move_Pallet_Town_Player_House_1F_Leaving_Mom_1
    applymovement PLAYER Move_Pallet_Town_Player_House_1F_Leaving_Player_1
    waitmovement MOM
    npcmsg gText_Pallet_Town_Player_House_1F_Leaving_Mom_2 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    pause 15
    spriteface MOM DOWN
    pause 5
    npcmsg gText_Pallet_Town_Player_House_1F_Leaving_Mom_3 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    pause 5
    spriteface MOM RIGHT
    npcmsg gText_Pallet_Town_Player_House_1F_Leaving_Mom_4 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    fadescreen 0x1
    fanfare 0x100
    waitfanfare
    fadescreen 0x0
    npcmsg gText_Pallet_Town_Player_House_1F_Leaving_Mom_5 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    fanfare 0x13E
    msgbox gText_Pallet_Town_Player_House_1F_PlayerObtainedDexNav MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    npcmsg gText_Pallet_Town_Player_House_1F_Leaving_Mom_6 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    setflag 0x2
    setflag 0x91E
    setvar VAR_MAP_SCENE_PALLET_TOWN_PLAYER_HOUSE 0x3
    release
    end

Move_Pallet_Town_Player_House_1F_Camera_1:
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte end_m

Move_Pallet_Town_Player_House_1F_Camera_2:
    .byte walk_up
    .byte walk_up
    .byte walk_right
    .byte end_m

Move_Pallet_Town_Player_House_1F_Leaving_May_1:
    .byte walk_left
    .byte pause_long
    .byte end_m

Move_Pallet_Town_Player_House_1F_Leaving_May_2:
    .byte exclaim
    .byte pause_long
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Pallet_Town_Player_House_1F_Leaving_May_3:
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte end_m

Move_Pallet_Town_Player_House_1F_Leaving_May_4:
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down_onspot_fastest
    .byte walk_down
    .byte end_m

Move_Pallet_Town_Player_House_1F_Leaving_Rival_1:
    .byte pause_long
    .byte walk_right
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Pallet_Town_Player_House_1F_Leaving_Rival_2:
    .byte pause_long
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte set_invisible
    .byte end_m

Move_Pallet_Town_Player_House_1F_Leaving_Mom_1:
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_right_onspot_fastest
    .byte end_m

Move_Pallet_Town_Player_House_1F_Leaving_Player_1:
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Player House Mom
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_Player_House_1F_Mom:
    lock
    faceplayer
    compare VAR_MAP_SCENE_PALLET_TOWN 0x2
    if lessorequal _goto EventScript_Pallet_Town_Player_House_1F_Mom_GoSeeProf
    checkflag 0x1
    if SET _goto EventScript_Pallet_Town_Player_House_1F_Mom_WonderWhere
    npcmsg gText_Pallet_Town_Player_House_1F_Leaving_Mom_TakeABreak MSG_KEEPOPEN gText_Name_Mom
    closemsg
    call EventScript_Pallet_Town_Player_House_1F_Mom_HealPlayer
    npcmsg gText_Pallet_Town_Player_House_1F_Leaving_Mom_AllBetterNow MSG_KEEPOPEN gText_Name_Mom
    closemsg
    setflag 0x1
    release
    end

EventScript_Pallet_Town_Player_House_1F_Mom_WonderWhere:
    npcmsg gText_Pallet_Town_Player_House_1F_Mom_WonderWhere MSG_KEEPOPEN gText_Name_Mom
    closemsg
    release
    end

EventScript_Pallet_Town_Player_House_1F_Mom_GoSeeProf:
    npcmsg gText_Pallet_Town_Player_House_1F_Leaving_Mom_6 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    release
    end

EventScript_Pallet_Town_Player_House_1F_Mom_HealPlayer:
    fadescreen 0x1
    fanfare 0x100
    waitfanfare
    special 0x0
    fadescreen 0x0
    return
