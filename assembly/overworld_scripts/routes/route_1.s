.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ MAY, 5
.equ RIVAL, 6
.equ OAK, 7

@@@@@@@@@@@@@@@@@@@@@@
@ Route 1 Map Scripts
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Route_1:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_Route_1
    .byte MAP_SCRIPT_TERMIN

LevelScript_Route_1:
    levelscript VAR_MAP_SCENE_PALLET_TOWN, 3, EventScript_Route_1_OakExplainCatch
    .hword LEVEL_SCRIPT_TERMIN

@@@@@@@@@@@@@@@@@@@@@@
@ Route 1 Oak
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route_1_OakExplainCatch:
    lock
    getplayerpos 0x8000 0x8001
    compare 0x8000 0xC
    if equal _call EventScript_Route_1_OakExplainCatch_Left
    compare 0x8000 0xD
    if equal _call EventScript_Route_1_OakExplainCatch_Right
    pause 30
    applymovement MAY Move_Route_1_OakExplainCatch_May_1
    applymovement PLAYER Move_Route_1_OakExplainCatch_Player_1
    applymovement RIVAL Move_Route_1_OakExplainCatch_Rival_1
    waitmovement MAY
    npcmsg gText_Route_1_OakExplainCatch_May_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement MAY Move_Route_1_OakExplainCatch_May_2
    applymovement PLAYER Move_Route_1_OakExplainCatch_Player_2
    applymovement RIVAL Move_Route_1_OakExplainCatch_Rival_2
    waitmovement MAY
    npcmsg gText_Route_1_OakExplainCatch_Rival_1 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    npcmsg gText_Route_1_OakExplainCatch_Oak_1 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    pause 5
    special 0x188
    special 0x9D
    waitstate
    npcmsg gText_Route_1_OakExplainCatch_Oak_2 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    pause 5
    giveitem ITEM_POKE_BALL 20 MSG_OBTAIN
    pause 5
    npcmsg gText_Route_1_OakExplainCatch_Oak_3 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    applymovement OAK Move_Route_1_OakExplainCatch_Oak_1
    waitmovement OAK
    sound 0x15
    npcmsg gText_Route_1_OakExplainCatch_Oak_4 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    applymovement MAY Move_Route_1_OakExplainCatch_May_3
    applymovement PLAYER Move_Route_1_OakExplainCatch_Player_3
    applymovement RIVAL Move_Route_1_OakExplainCatch_Rival_3
    applymovement OAK Move_Route_1_OakExplainCatch_Oak_2
    waitmovement OAK
    hidesprite OAK
    setflag FLAG_HIDE_ROUTE_1_OAK
    npcmsg gText_Route_1_OakExplainCatch_Rival_2 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    pause 15
    spriteface RIVAL RIGHT
    npcmsg gText_Route_1_OakExplainCatch_Rival_3 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    pause 15
    spriteface MAY LEFT
    npcmsg gText_Route_1_OakExplainCatch_May_2 MSG_KEEPOPEN gText_Name_May
    closemsg
    sound 0x15
    applymovement MAY Move_Route_1_OakExplainCatch_May_4
    waitmovement MAY
    npcmsg gText_Route_1_OakExplainCatch_May_3 MSG_KEEPOPEN gText_Name_May
    closemsg
    pause 15
    sound 0x15
    applymovement RIVAL Move_Route_1_OakExplainCatch_Rival_4
    waitmovement RIVAL
    npcmsg gText_Route_1_OakExplainCatch_Rival_4 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    npcmsg gText_Route_1_OakExplainCatch_May_4 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement MAY Move_Route_1_OakExplainCatch_May_5
    applymovement RIVAL Move_Route_1_OakExplainCatch_Rival_5
    waitmovement RIVAL
    hidesprite MAY
    hidesprite RIVAL
    setflag FLAG_HIDE_ROUTE_1_MAY
    setflag FLAG_HIDE_ROUTE_1_RIVAL
    setvar VAR_MAP_SCENE_PALLET_TOWN 0x4
    clearflag FLAG_HIDE_PALLET_TOWN_OAK_LAB_OAK
    release
    end

EventScript_Route_1_OakExplainCatch_Left:
    applymovement PLAYER Move_Route_1_OakExplainCatch_Player_Left
    waitmovement PLAYER
    return

EventScript_Route_1_OakExplainCatch_Right:
    applymovement PLAYER Move_Route_1_OakExplainCatch_Player_Right
    waitmovement PLAYER
    return

Move_Route_1_OakExplainCatch_Oak_1:
    .byte pause_long
    .byte exclaim
    .byte end_m

Move_Route_1_OakExplainCatch_Oak_2:
    .byte walk_down
    .byte pause_long
    .byte pause_long
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_Route_1_OakExplainCatch_May_1:
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Route_1_OakExplainCatch_May_2:
    .byte pause_long
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Route_1_OakExplainCatch_May_3:
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Route_1_OakExplainCatch_May_4:
    .byte exclaim
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte end_m

Move_Route_1_OakExplainCatch_May_5:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_right
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_Route_1_OakExplainCatch_Player_1:
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Route_1_OakExplainCatch_Player_2:
    .byte pause_long
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Route_1_OakExplainCatch_Player_3:
    .byte pause_long
    .byte walk_left
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Route_1_OakExplainCatch_Rival_1:
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Route_1_OakExplainCatch_Rival_2:
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Route_1_OakExplainCatch_Rival_3:
    .byte pause_long
    .byte walk_left
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Route_1_OakExplainCatch_Rival_4:
    .byte say_question
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Route_1_OakExplainCatch_Rival_5:
    .byte walk_up
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_Route_1_OakExplainCatch_Player_Left:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_Route_1_OakExplainCatch_Player_Right:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_left
    .byte walk_up
    .byte walk_up
    .byte end_m
