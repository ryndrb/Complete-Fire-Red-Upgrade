.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ MOM, 1
.equ DAD, 2
.equ MAY, 3

@@@@@@@@@@@@@@@@@@@@@@
@ May House Map Scripts
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Pallet_Town_May_House:
    mapscript MAP_SCRIPT_ON_LOAD MapOnLoad_Pallet_Town_May_House
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_Pallet_Town_May_House
    .byte MAP_SCRIPT_TERMIN

MapOnLoad_Pallet_Town_May_House:
    compare VAR_MAP_SCENE_PALLET_TOWN_MAY_HOUSE 0x1
    if equal _call EventScript_Pallet_Town_May_House_DadMomSprites
    end

EventScript_Pallet_Town_May_House_DadMomSprites:
    movesprite2 DAD 0x8 0x4
    spritebehave DAD 0x0
    movesprite2 MOM 0x1 0x2
    spritebehave MOM 0x7
    return

LevelScript_Pallet_Town_May_House:
    levelscript VAR_MAP_SCENE_PALLET_TOWN_MAY_HOUSE, 0, EventScript_Pallet_Town_May_House_FamilyArgument
    .hword LEVEL_SCRIPT_TERMIN

@@@@@@@@@@@@@@@@@@@@@@
@ May and her Dad arguing
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_May_House_FamilyArgument:
    lock
    pause 30
    applymovement PLAYER Move_Pallet_Town_May_House_FamilyArgument_Player_1
    waitmovement PLAYER
    special 0x113
    applymovement CAMERA Move_Pallet_Town_May_House_FamilyArgument_Camera_1
    waitmovement CAMERA
    special 0x114
    applymovement DAD Move_Pallet_Town_May_House_FamilyArgument_Dad_1
    waitmovement DAD
    msgbox gText_Pallet_Town_May_House_FamilyArgument_MayDad_1 MSG_KEEPOPEN
    closeonkeypress
    applymovement MAY Move_Pallet_Town_May_House_FamilyArgument_May_1
    waitmovement MAY
    npcmsg gText_Pallet_Town_May_House_FamilyArgument_May_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement MAY Move_Pallet_Town_May_House_FamilyArgument_May_2
    waitmovement MAY
    sound 0x15
    special 0x113
    applymovement CAMERA Move_Pallet_Town_May_House_FamilyArgument_Camera_2
    waitmovement CAMERA
    special 0x114
    applymovement MAY Move_Pallet_Town_May_House_FamilyArgument_May_3
    waitmovement MAY
    pause 15
    npcmsg gText_Pallet_Town_May_House_FamilyArgument_May_2 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement MAY Move_Pallet_Town_May_House_FamilyArgument_May_4
    applymovement PLAYER Move_Pallet_Town_May_House_FamilyArgument_Player_2
    waitmovement MAY
    sound 0x9
    hidesprite MAY
    setflag FLAG_HIDE_PALLET_TOWN_MAY_HOUSE_MAY
    setvar VAR_MAP_SCENE_PALLET_TOWN_MAY_HOUSE 0x1
    clearflag FLAG_HIDE_PALLET_TOWN_OUTSIDE_MAY
    release
    end

Move_Pallet_Town_May_House_FamilyArgument_Player_1:
    .byte pause_long
    .byte walk_up
    .byte end_m

Move_Pallet_Town_May_House_FamilyArgument_Player_2:
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Pallet_Town_May_House_FamilyArgument_Dad_1:
    .byte pause_long
    .byte walk_left
    .byte pause_long
    .byte end_m

Move_Pallet_Town_May_House_FamilyArgument_May_1:
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Pallet_Town_May_House_FamilyArgument_May_2:
    .byte pause_long
    .byte walk_down
    .byte pause_long
    .byte exclaim
    .byte end_m

Move_Pallet_Town_May_House_FamilyArgument_May_3:
    .byte pause_long
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Pallet_Town_May_House_FamilyArgument_May_4:
    .byte pause_long
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte walk_down_onspot_fastest
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Pallet_Town_May_House_FamilyArgument_Camera_1:
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_Pallet_Town_May_House_FamilyArgument_Camera_2:
    .byte walk_down
    .byte walk_down
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ May's Mom
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_May_House_MayMom:
    msgbox gText_Pallet_Town_May_House_MayMom_DontMindHusband MSG_FACE
    end

@@@@@@@@@@@@@@@@@@@@@@
@ May's Dad
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pallet_Town_May_House_MayDad:
    msgbox gText_Pallet_Town_May_House_MayDad_Nonsense MSG_FACE
    end
