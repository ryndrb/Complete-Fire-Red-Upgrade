.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ OAK, 4
.equ RIVAL, 8
.equ MAY, 11

@@@@@@@@@@@@@@@@@@@@@@
@ Oak Lab Map
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Pallet_Town_Oak_Lab:
    mapscript MAP_SCRIPT_ON_TRANSITION MapOnTransition_Pallet_Town_Oak_Lab
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_Pallet_Town_Oak_Lab
    mapscript MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE LevelScript_2_Pallet_Town_Oak_Lab
    .byte MAP_SCRIPT_TERMIN

MapOnTransition_Pallet_Town_Oak_Lab:
    setflag 0x2CF
    end

LevelScript_Pallet_Town_Oak_Lab:
    levelscript VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 0, EventScript_Pallet_Town_Oak_Lab_Intro
    .hword LEVEL_SCRIPT_TERMIN

LevelScript_2_Pallet_Town_Oak_Lab:
    levelscript VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 0, EventScript_Pallet_Town_Oak_Lab_PlayerFaceUp
    .hword LEVEL_SCRIPT_TERMIN

EventScript_Pallet_Town_Oak_Lab_PlayerFaceUp:
    spriteface PLAYER UP
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Oak Lab Intro
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_Oak_Lab_Intro:
    lock
    pause 30
    applymovement PLAYER Move_Pallet_Town_Oak_Lab_Intro_Player_1
    applymovement RIVAL Move_Pallet_Town_Oak_Lab_Intro_Rival_1
    applymovement MAY Move_Pallet_Town_Oak_Lab_Intro_May_1
    waitmovement PLAYER
    pause 15
    npcmsg gText_Pallet_Town_Oak_Lab_Intro_Oak_1 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    npcmsg gText_Pallet_Town_Oak_Lab_Intro_Rival_1 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    npcmsg gText_Pallet_Town_Oak_Lab_Intro_Oak_2 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    applymovement OAK Move_Pallet_Town_Oak_Lab_Intro_Oak_1
    waitmovement OAK
    npcmsg gText_Pallet_Town_Oak_Lab_Intro_Oak_3 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    npcmsg gText_Pallet_Town_Oak_Lab_Intro_Rival_2 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    pause 5
    sound 0x15
    applymovement MAY Move_Pallet_Town_Oak_Lab_Intro_May_2
    waitmovement MAY
    npcmsg gText_Pallet_Town_Oak_Lab_Intro_May_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_Pallet_Town_Oak_Lab_Intro_Oak_4 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    applymovement OAK Move_Pallet_Town_Oak_Lab_Intro_Oak_2
    applymovement MAY Move_Pallet_Town_Oak_Lab_Intro_May_3
    waitmovement OAK
    npcmsg gText_Pallet_Town_Oak_Lab_Intro_Oak_5 MSG_YESNO gText_Name_ProfOak
    compare LASTRESULT 0x1
    if notequal _call EventScript_Pallet_Town_Oak_Lab_Intro_AnsweredNo
    closemsg
    goto EventScript_Pallet_Town_Oak_Lab_Intro_AnsweredYes
    release
    end

EventScript_Pallet_Town_Oak_Lab_Intro_AnsweredNo:
    applymovement OAK Move_Pallet_Town_Oak_Lab_Intro_Oak_3
    waitmovement OAK
    npcmsg gText_Pallet_Town_Oak_Lab_Intro_Oak_6 MSG_YESNO gText_Name_ProfOak
    compare LASTRESULT 0x1
    if notequal _call EventScript_Pallet_Town_Oak_Lab_Intro_AnsweredNo
    closemsg
    goto EventScript_Pallet_Town_Oak_Lab_Intro_AnsweredYes
    release
    end

EventScript_Pallet_Town_Oak_Lab_Intro_AnsweredYes:
    npcmsg gText_Pallet_Town_Oak_Lab_Intro_May_2 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_Pallet_Town_Oak_Lab_Intro_Rival_3 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    npcmsg gText_Pallet_Town_Oak_Lab_Intro_Oak_7 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    pause 15
    fanfare 0x13E
    signbox gText_Pallet_Town_Oak_Lab_Intro_ReceivedPokedex MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    npcmsg gText_Pallet_Town_Oak_Lab_Intro_Oak_8 MSG_KEEPOPEN gText_Name_ProfOak
    closemsg
    applymovement OAK Move_Pallet_Town_Oak_Lab_Intro_Oak_4
    applymovement PLAYER Move_Pallet_Town_Oak_Lab_Intro_Player_2
    applymovement RIVAL Move_Pallet_Town_Oak_Lab_Intro_Rival_2
    applymovement MAY Move_Pallet_Town_Oak_Lab_Intro_May_4
    waitmovement OAK
    hidesprite OAK
    setflag FLAG_HIDE_PALLET_TOWN_OAK_LAB_OAK
    npcmsg gText_Pallet_Town_Oak_Lab_Intro_May_3 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_Pallet_Town_Oak_Lab_Intro_Rival_4 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    setflag 0x829
    special 0x16F
    clearflag FLAG_HIDE_PALLET_TOWN_OUTSIDE_MOM
    setflag FLAG_HIDE_PALLET_TOWN_KID
    setvar VAR_MAP_SCENE_PALLET_TOWN 0x2
    setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB 0x1
    release
    end

Move_Pallet_Town_Oak_Lab_Intro_Player_1:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_Pallet_Town_Oak_Lab_Intro_Player_2:
    .byte pause_long
    .byte walk_left
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Pallet_Town_Oak_Lab_Intro_Rival_1:
    .byte pause_long
    .byte pause_long
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_Pallet_Town_Oak_Lab_Intro_Rival_2:
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Pallet_Town_Oak_Lab_Intro_May_1:
    .byte pause_long
    .byte pause_long
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_Pallet_Town_Oak_Lab_Intro_May_2:
    .byte say_question
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Pallet_Town_Oak_Lab_Intro_May_3:
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Pallet_Town_Oak_Lab_Intro_May_4:
    .byte pause_long
    .byte walk_left
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Pallet_Town_Oak_Lab_Intro_Oak_1:
    .byte pause_long
    .byte walk_left
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte walk_right
    .byte walk_right
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte walk_left
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Pallet_Town_Oak_Lab_Intro_Oak_2:
    .byte pause_long
    .byte walk_up
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte end_m

Move_Pallet_Town_Oak_Lab_Intro_Oak_3:
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Pallet_Town_Oak_Lab_Intro_Oak_4:
    .byte walk_down
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

@@@@@@@@@@@@@@@@@@@@@@
@ May Oak Lab
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_Oak_Lab_May:
    lock
    faceplayer
    npcmsg gText_Pallet_Town_Oak_Lab_May_HeartPounding MSG_KEEPOPEN gText_Name_May
    closemsg
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Rival Oak Lab
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_Oak_Lab_Rival:
    lock
    faceplayer
    npcmsg gText_Pallet_Town_Oak_Lab_Rival_FinallyTrainer MSG_KEEPOPEN gText_Name_Rival
    closemsg
    release
    end
