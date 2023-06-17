.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ KID, 3
.equ MAY, 4
.equ RIVAL, 5
.equ MOM, 6

@@@@@@@@@@@@@@@@@@@@@@
@ Pallet Town Map
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Pallet_Town:
    mapscript MAP_SCRIPT_ON_TRANSITION MapOnTransition_Pallet_Town
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_Pallet_Town
    .byte MAP_SCRIPT_TERMIN

MapOnTransition_Pallet_Town:
    setworldmapflag 0x890
    checkflag FLAG_HIDE_PALLET_TOWN_MAY_HOUSE_MAY
    if SET _call EventScript_Pallet_Town_MoveMaySpriteBesideRival
    compare VAR_MAP_SCENE_PALLET_TOWN 0x2
    if equal _call EventScript_Pallet_Town_MoveMaySpriteBehindDoor
    compare VAR_MAP_SCENE_PALLET_TOWN 0x2
    if lessorequal _call EventScript_Pallet_Town_PlayerCantGoToRoute1
    end

EventScript_Pallet_Town_PlayerCantGoToRoute1:
    setvar 0x4002 0x1
    end

EventScript_Pallet_Town_MoveMaySpriteBesideRival:
    movesprite2 MAY 0x1C 0x7
    spritebehave MAY 0x0
    return

EventScript_Pallet_Town_MoveMaySpriteBehindDoor:
    movesprite2 MAY 0x1B 0x6
    spritebehave MAY 0x0
    movesprite2 RIVAL 0x1B 0x6
    spritebehave RIVAL 0x0
    return

LevelScript_Pallet_Town:
    levelscript VAR_MAP_SCENE_PALLET_TOWN, 0, EventScript_Pallet_Town_MayHeadingHome
    levelscript VAR_MAP_SCENE_PALLET_TOWN, 2, EventScript_Pallet_Town_AfterReceivingDex
    .hword LEVEL_SCRIPT_TERMIN

@@@@@@@@@@@@@@@@@@@@@@
@ May Heading home
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_MayHeadingHome:
    lock
    pause 30
    cry SPECIES_RUFFLET 0x0
    cry SPECIES_WOOBAT 0x0
    cry SPECIES_PIDOVE 0x0
    applymovement MAY Move_Pallet_Town_MayHeadingHome_May_1
    waitmovement MAY
    pause 10
    hidesprite MAY
    setflag FLAG_HIDE_PALLET_TOWN_OUTSIDE_MAY
    setvar VAR_MAP_SCENE_PALLET_TOWN 0x1
    release
    end

Move_Pallet_Town_MayHeadingHome_May_1:
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Pallet Town Go to Oak in Route 1
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_AfterReceivingDex:
    lock
    pause 30
    setdooropen 0x1B 0x6
    opendoor 0x1B 0x6
    waitdooranim
    showsprite MAY
    npcmsg gText_Pallet_Town_AfterReceivingDex_May_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    pause 15
    applymovement PLAYER Move_Pallet_Town_AfterReceivingDex_Player_1
    waitmovement PLAYER
    applymovement MAY Move_Pallet_Town_AfterReceivingDex_May_1
    waitmovement MAY
    showsprite RIVAL
    applymovement RIVAL Move_Pallet_Town_AfterReceivingDex_Rival_1
    waitmovement RIVAL
    setdoorclosed 0x1B 0x6
    closedoor 0x1B 0x6
    waitdooranim
    applymovement PLAYER Move_Pallet_Town_AfterReceivingDex_Player_2
    waitmovement PLAYER
    npcmsg gText_Pallet_Town_AfterReceivingDex_Mom_1 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    applymovement MOM Move_Pallet_Town_AfterReceivingDex_Mom_1
    waitmovement MOM
    npcmsg gText_Pallet_Town_AfterReceivingDex_Mom_2 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    pause 5
    fanfare 0x13E
    giveitem ITEM_TOWN_MAP 0x1 MSG_OBTAIN
    waitfanfare
    applymovement MOM Move_Pallet_Town_AfterReceivingDex_Mom_2
    waitmovement MOM
    npcmsg gText_Pallet_Town_AfterReceivingDex_Mom_3 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    applymovement RIVAL Move_Pallet_Town_AfterReceivingDex_Rival_2
    waitmovement RIVAL
    npcmsg gText_Pallet_Town_AfterReceivingDex_Rival_1 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    applymovement MOM Move_Pallet_Town_AfterReceivingDex_Mom_3
    waitmovement MOM
    npcmsg gText_Pallet_Town_AfterReceivingDex_Mom_4 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    applymovement MAY Move_Pallet_Town_AfterReceivingDex_May_2
    waitmovement MAY
    npcmsg gText_Pallet_Town_AfterReceivingDex_May_2 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement MOM Move_Pallet_Town_AfterReceivingDex_Mom_4
    waitmovement MOM
    npcmsg gText_Pallet_Town_AfterReceivingDex_Mom_5 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    applymovement MOM Move_Pallet_Town_AfterReceivingDex_Mom_5
    waitmovement MOM
    npcmsg gText_Pallet_Town_AfterReceivingDex_Mom_6 MSG_KEEPOPEN gText_Name_Mom
    closemsg
    applymovement MOM Move_Pallet_Town_AfterReceivingDex_Mom_6
    waitmovement MOM
    hidesprite MOM
    setflag FLAG_HIDE_PALLET_TOWN_OUTSIDE_MOM
    applymovement RIVAL Move_Pallet_Town_AfterReceivingDex_Rival_3
    applymovement PLAYER Move_Pallet_Town_AfterReceivingDex_Player_3
    applymovement MAY Move_Pallet_Town_AfterReceivingDex_May_3
    waitmovement MAY
    npcmsg gText_Pallet_Town_AfterReceivingDex_Rival_2 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    applymovement MAY Move_Pallet_Town_AfterReceivingDex_May_4
    waitmovement MAY
    npcmsg gText_Pallet_Town_AfterReceivingDex_May_3 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement RIVAL Move_Pallet_Town_AfterReceivingDex_Rival_4
    applymovement MAY Move_Pallet_Town_AfterReceivingDex_May_5
    waitmovement MAY
    hidesprite MAY
    hidesprite RIVAL
    setflag FLAG_HIDE_PALLET_TOWN_OAK_LAB_RIVAL
    setflag FLAG_HIDE_PALLET_TOWN_OAK_LAB_MAY
    setvar VAR_MAP_SCENE_PALLET_TOWN 0x3
    setvar 0x4002 0x0
    release
    end

Move_Pallet_Town_AfterReceivingDex_Player_1:
    .byte walk_down
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_Player_2:
    .byte walk_up
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_Player_3:
    .byte pause_long
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_Rival_1:
    .byte walk_down
    .byte walk_left
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_Rival_2:
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_Rival_3:
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_Rival_4:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_May_1:
    .byte walk_down
    .byte walk_right
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_May_2:
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_May_3:
    .byte pause_long
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_May_4:
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_May_5:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_Mom_1:
    .byte walk_up
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_Mom_2:
    .byte pause_long
    .byte walk_left
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_Mom_3:
    .byte pause_long
    .byte walk_right
    .byte walk_right
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_Mom_4:
    .byte pause_long
    .byte walk_left
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_Mom_5:
    .byte pause_long
    .byte walk_down
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Pallet_Town_AfterReceivingDex_Mom_6:
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m



@@@@@@@@@@@@@@@@@@@@@@
@ Pallet Town Rival Standing Before Lab Door
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_Rival:
    lock
    faceplayer
    checkflag FLAG_HIDE_PALLET_TOWN_MAY_HOUSE_MAY
    if SET _goto EventScript_Pallet_Town_Rival_LetsMeetProf
    npcmsg gText_Pallet_Town_Rival_GoSeeMay MSG_KEEPOPEN gText_Name_Rival
    closemsg
    release
    end

EventScript_Pallet_Town_Rival_LetsMeetProf:
    npcmsg gText_Pallet_Town_Rival_LetsMeetProf MSG_KEEPOPEN gText_Name_Rival
    closemsg
    applymovement RIVAL Move_Pallet_Town_LetsMeetProf_Rival_1
    waitmovement RIVAL
    setdooropen 0x1B 0x6
    opendoor 0x1B 0x6
    waitdooranim
    applymovement RIVAL Move_Pallet_Town_LetsMeetProf_Rival_2
    applymovement MAY Move_Pallet_Town_LetsMeetProf_May_1
    getplayerpos 0x8000 0x8001
    compare 0x8001 0x7
    if equal _call EventScript_Pallet_Town_LetsMeetProf_Player_7
    compare 0x8001 0x8
    if equal _call EventScript_Pallet_Town_LetsMeetProf_Player_8
    waitmovement PLAYER
    setdoorclosed 0x1B 0x6
    closedoor 0x1B 0x6
    waitdooranim
    hidesprite RIVAL
    hidesprite MAY
    setflag FLAG_HIDE_PALLET_TOWN_OUTSIDE_MAY
    setflag FLAG_HIDE_PALLET_TOWN_OUTSIDE_RIVAL
    warp 0x4 0x3 PLAYER 0x6 0xC
    waitstate
    release
    end

EventScript_Pallet_Town_LetsMeetProf_Player_7:
    applymovement PLAYER Move_Pallet_Town_LetsMeetProf_Player_1
    return

EventScript_Pallet_Town_LetsMeetProf_Player_8:
    applymovement PLAYER Move_Pallet_Town_LetsMeetProf_Player_2
    return

Move_Pallet_Town_LetsMeetProf_Rival_1:
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Pallet_Town_LetsMeetProf_Rival_2:
    .byte walk_up
    .byte set_invisible
    .byte end_m

Move_Pallet_Town_LetsMeetProf_May_1:
    .byte walk_left
    .byte walk_up
    .byte set_invisible
    .byte end_m

Move_Pallet_Town_LetsMeetProf_Player_1:
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_right
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte walk_up
    .byte set_invisible
    .byte end_m

Move_Pallet_Town_LetsMeetProf_Player_2:
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_up
    .byte walk_up
    .byte set_invisible
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Pallet Town May Standing Before Lab Door
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_May:
    lock
    faceplayer
    npcmsg gText_Pallet_Town_May_ItsASecret MSG_KEEPOPEN gText_Name_May
    closemsg
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Pallet Town Signpost
@@@@@@@@@@@@@@@@@@@@@@
SignScript_Pallet_Town_Signpost:
    signbox gText_Pallet_Town_Signpost MSG_NORMAL
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Pallet Town May Mailbox
@@@@@@@@@@@@@@@@@@@@@@
SignScript_Pallet_Town_MayMailBox:
    signbox gText_Pallet_Town_MayMailBox MSG_NORMAL
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Pallet Town Science Guy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_ScienceGuy:
    msgbox gText_Pallet_Town_ScienceGuy_PowerOfScience MSG_FACE
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Pallet Town Question Lady
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_QuestionLady:
    lock
    faceplayer
    msgbox gText_Pallet_Town_QuestionLady_MonChangesPeople MSG_YESNO
    compare LASTRESULT 0x1
    if equal _goto EventScript_Pallet_Town_QuestionLady_Yes
    msgbox gText_Pallet_Town_QuestionLady_MonChangesPeople_AnswerdNo MSG_KEEPOPEN
    release
    end

EventScript_Pallet_Town_QuestionLady_Yes:
    msgbox gText_Pallet_Town_QuestionLady_MonChangesPeople_AnswerdYes MSG_KEEPOPEN
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Pallet Town Kid Prevent Player
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_Kid:
    lock
    faceplayer
    msgbox gText_Pallet_Town_Kid_CantGoToRoute1 MSG_KEEPOPEN
    closeonkeypress
    release
    end

TileScript_Pallet_Town_Kid:
    lock
    applymovement PLAYER Move_Pallet_Town_Kid_Player_1
    applymovement KID Move_Pallet_Town_Kid_Kid_1
    waitmovement KID
    msgbox gText_Pallet_Town_Kid_CantGoToRoute1 MSG_KEEPOPEN
    closeonkeypress
    applymovement PLAYER Move_Pallet_Town_Kid_Player_2
    waitmovement PLAYER
    release
    end

Move_Pallet_Town_Kid_Player_1:
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Pallet_Town_Kid_Player_2:
    .byte walk_down
    .byte end_m

Move_Pallet_Town_Kid_Kid_1:
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

