.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ JESSIE, 4
.equ JAMES, 5
.equ MEOWTH, 6
.equ MAY, 7
.equ CUBONE, 8

.equ RIVAL_TOWER_1, 1
.equ MAY_TOWER_1, 3

.equ MAY_TOWER_2, 5
.equ CUBONE_TOWER, 6

.equ FUJI, 1
.equ JESSIE_TOWER_TOP, 5
.equ JAMES_TOWER_TOP, 6
.equ MEOWTH_TOWER_TOP, 7

@@@@@@@@@@@@@@@@@@@@@@
@ Lavender Town Items Merchant
@@@@@@@@@@@@@@@@@@@@@@
EventScript_LavenderTownMerchant:
    lock
    faceplayer
    checkflag 0x23C
    if 0x1 _goto EventScript_LavenderTownMerchantSell
    msgbox 0x817F5B6 MSG_FACE
    end

EventScript_LavenderTownMerchantSell:
    checkflag FLAG_LAVENDER_MECHANT_1
    if 0x0 _call EventScript_PlayerRescuedFuji
    checkflag FLAG_LAVENDER_MECHANT_2
    if 0x0 _call EventScript_LavenderTownMerchantAdmit
    msgbox gText_LavenderTownMerchantSell MSG_KEEPOPEN
    pokemart EventScript_LavenderTownMerchantList
    msgbox gText_LavenderTownMerchantBye MSG_KEEPOPEN
    release
    end

EventScript_PlayerRescuedFuji:
    msgbox EventScript_LavenderTownMerchantFujiRescued MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_DoesntMatter
    setflag FLAG_LAVENDER_MECHANT_1
    goto EventScript_LavenderTownMerchantAdmit
    return

EventScript_LavenderTownMerchantAdmit:
    msgbox gText_LavenderTownMerchantAdmit MSG_KEEPOPEN
    setflag FLAG_LAVENDER_MECHANT_2
    return

EventScript_LavenderTownMerchantExclaim:
    .byte exclaim
    .byte end_m

.align 1
EventScript_LavenderTownMerchantList:
    .hword ITEM_ASSAULT_VEST
    .hword ITEM_DESTINY_KNOT
    .hword ITEM_EXPERT_BELT
    .hword ITEM_MACHO_BRACE
    .hword ITEM_RING_TARGET
    .hword ITEM_ROCKY_HELMET
    .hword ITEM_SAFETY_GOGGLES
    .hword ITEM_SCOPE_LENS
    .hword ITEM_TERRAIN_EXTENDER
    .hword ITEM_BLUNDER_POLICY
    .hword ITEM_ROOM_SERVICE
    .hword ITEM_EJECT_PACK
    .hword ITEM_HEAVY_DUTY_BOOTS
    .hword ITEM_UTILITY_UMBRELLA
    .hword ITEM_LUCKY_PUNCH
    .hword 0x0

EventScript_ThisFlagIsSet:
    return

EventScript_DoesntMatter:
    msgbox gText_DoesntMatter MSG_KEEPOPEN
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Pokemon Tower Lady Preventing Enter
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PokeTowerLady:
    lock
    faceplayer
    checkflag 0x5F @ Have Silph Scope?
    if SET _goto EventScript_CanEnterLady
    msgbox gText_PokeTowerLady MSG_KEEPOPEN
    msgbox gText_CheckWorthiness MSG_KEEPOPEN
    release
    end

EventScript_CanEnterLady:
    msgbox gText_PokeTowerLady MSG_FACE
    end

EventScript_PokeTowerLadyTile:
    lock
    checkflag 0x5F @ Have Silph Scope?
    if NOT_SET _goto EventScript_CanEnterPokeTower
    msgbox gText_PokeTowerLady MSG_KEEPOPEN
    release
    end

EventScript_CanEnterPokeTower:
    spriteface 0x2, DOWN
    spriteface PLAYER, UP
    msgbox gText_PokeTowerLady MSG_KEEPOPEN
    msgbox gText_CheckWorthiness MSG_KEEPOPEN
    applymovement PLAYER EventScript_MovePlayer
    waitmovement PLAYER
    release
    end

EventScript_MovePlayer:
    .byte walk_left
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Poke Tower Top Floor Rocket Gang and Fuji
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PokeTower_TopFloor_RocketGang:
    lock
    compare VAR_ROCKET_GANG_ENCOUNTER 0x7
    if greaterorequal _goto EventScript_PokeTower_TopFloor_MrFuji
    pause 30
    npcmsg gText_PokeTower_TopFloor_RocketGang_Jessie_Speak_1 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    pause 30
    sound 0x15
    applymovement PLAYER Move_PokeTower_TopFloor_RocketGang_Player_1
    waitmovement PLAYER
    showsprite JESSIE_TOWER_TOP
    showsprite MEOWTH_TOWER_TOP
    showsprite JAMES_TOWER_TOP
    fadescreen 0x1
    applymovement PLAYER Move_PokeTower_TopFloor_RocketGang_Player_2
    applymovement JESSIE_TOWER_TOP Move_PokeTower_TopFloor_RocketGang_Jessie_2
    applymovement JAMES_TOWER_TOP Move_PokeTower_TopFloor_RocketGang_James_3
    applymovement MEOWTH_TOWER_TOP Move_PokeTower_TopFloor_RocketGang_Meowth_3
    waitmovement MEOWTH_TOWER_TOP
    pause 15
    fadescreen 0x0
    playsong 0x184 0x0
    npcmsg gText_PokeTower_TopFloor_RocketGang_Jessie_Speak_2 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    npcmsg gText_PokeTower_TopFloor_RocketGang_James_Speak_1 MSG_KEEPOPEN gText_Name_James
    closemsg
    pause 15
    npcmsg gText_PokeTower_TopFloor_RocketGang_Meowth_Speak_1 MSG_KEEPOPEN gText_Name_Meowth
    closemsg
    pause 30
    spriteface JESSIE_TOWER_TOP UP
    spriteface MEOWTH_TOWER_TOP UP
    spriteface JAMES_TOWER_TOP UP
    npcmsg gText_PokeTower_TopFloor_RocketGang_Jessie_Speak_3 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    pause 15
    sound 0x15
    applymovement JAMES_TOWER_TOP Move_PokeTower_TopFloor_RocketGang_James_1
    waitmovement JAMES_TOWER_TOP
    npcmsg gText_PokeTower_TopFloor_RocketGang_James_Speak_2 MSG_KEEPOPEN gText_Name_James
    closemsg
    applymovement MEOWTH_TOWER_TOP Move_PokeTower_TopFloor_RocketGang_Meowth_1
    waitmovement MEOWTH_TOWER_TOP
    npcmsg gText_PokeTower_TopFloor_RocketGang_Meowth_Speak_2 MSG_KEEPOPEN gText_Name_Meowth
    closemsg
    pause 15
    spriteface JESSIE_TOWER_TOP DOWN
    spriteface MEOWTH_TOWER_TOP DOWN
    spriteface JAMES_TOWER_TOP DOWN
    pause 15
    npcmsg gText_PokeTower_TopFloor_RocketGang_Jessie_Speak_4 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    npcmsg gText_PokeTower_TopFloor_RocketGang_James_Speak_3 MSG_KEEPOPEN gText_Name_James
    closemsg
    pause 15
    setvar VAR_FURTHER_TRAINER_BATTLES 0x3
    trainerbattle3 0x3 10 0x0 gText_PokeTower_TopFloor_RocketGang_Defeat
    playsong 0x184 0x0
    npcmsg gText_PokeTower_TopFloor_RocketGang_Jessie_Speak_5 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    pause 15
    spriteface JESSIE_TOWER_TOP RIGHT
    spriteface MEOWTH_TOWER_TOP LEFT
    spriteface JAMES_TOWER_TOP LEFT
    npcmsg gText_PokeTower_TopFloor_RocketGang_Meowth_Speak_3 MSG_KEEPOPEN gText_Name_Meowth
    closemsg
    npcmsg gText_PokeTower_TopFloor_RocketGang_Jessie_Speak_6 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    pause 15
    spriteface JESSIE_TOWER_TOP DOWN
    spriteface MEOWTH_TOWER_TOP DOWN
    spriteface JAMES_TOWER_TOP DOWN
    npcmsg gText_PokeTower_TopFloor_RocketGang_James_Speak_4 MSG_KEEPOPEN gText_Name_James
    applymovement JESSIE_TOWER_TOP Move_PokeTower_TopFloor_RocketGang_Jessie_1
    applymovement MEOWTH_TOWER_TOP Move_PokeTower_TopFloor_RocketGang_Meowth_2
    applymovement JAMES_TOWER_TOP Move_PokeTower_TopFloor_RocketGang_James_2
    applymovement PLAYER Move_PokeTower_TopFloor_RocketGang_Player_3
    waitmovement MEOWTH_TOWER_TOP
    closemsg
    pause 15
    fadedefaultbgm
    hidesprite JESSIE_TOWER_TOP
    hidesprite MEOWTH_TOWER_TOP
    hidesprite JAMES_TOWER_TOP
    setvar VAR_ROCKET_GANG_ENCOUNTER 0x7
    release
    end

Move_PokeTower_TopFloor_RocketGang_Player_1:
    .byte exclaim
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_PokeTower_TopFloor_RocketGang_Player_2:
    .byte run_down
    .byte run_down
    .byte run_down
    .byte walk_up_onspot_fastest
    .byte end_m

Move_PokeTower_TopFloor_RocketGang_James_1:
    .byte say_question
    .byte pause_long
    .byte pause_long
    .byte end_m

Move_PokeTower_TopFloor_RocketGang_Meowth_1:
    .byte pause_long
    .byte jump_onspot_up
    .byte end_m

Move_PokeTower_TopFloor_RocketGang_Player_3:
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_PokeTower_TopFloor_RocketGang_Jessie_1:
    .byte run_down
    .byte run_down
    .byte run_down
    .byte run_down
    .byte run_down
    .byte run_down
    .byte run_down
    .byte run_down
    .byte end_m

Move_PokeTower_TopFloor_RocketGang_Meowth_2:
    .byte run_right
    .byte run_down
    .byte run_down
    .byte run_down
    .byte run_down
    .byte run_down
    .byte run_down
    .byte run_down
    .byte run_down
    .byte end_m

Move_PokeTower_TopFloor_RocketGang_James_2:
    .byte run_down
    .byte run_down
    .byte run_down
    .byte run_down
    .byte run_down
    .byte run_down
    .byte run_down
    .byte run_down
    .byte end_m

Move_PokeTower_TopFloor_RocketGang_Jessie_2:
    .byte run_up
    .byte run_up
    .byte run_up
    .byte run_up
    .byte run_up
    .byte run_up
    .byte run_up
    .byte walk_down_onspot_fastest
    .byte end_m

Move_PokeTower_TopFloor_RocketGang_James_3:
    .byte run_right
    .byte run_up
    .byte run_up
    .byte run_up
    .byte run_up
    .byte run_up
    .byte run_up
    .byte run_up
    .byte walk_down_onspot_fastest
    .byte end_m

Move_PokeTower_TopFloor_RocketGang_Meowth_3:
    .byte run_up
    .byte run_up
    .byte run_up
    .byte run_up
    .byte run_up
    .byte run_up
    .byte run_up
    .byte run_left
    .byte walk_down_onspot_fastest
    .byte end_m

EventScript_PokeTower_TopFloor_MrFuji:
    pause 30
    setvar 0x8004 0xE
    setvar 0x8005 0x2
    special 0x174
    setflag 0x34
    clearflag 0x035
    setflag 0x23C
    sound 0x15
    applymovement FUJI Move_PokeTower_TopFloor_MrFuji_1
    waitmovement FUJI
    npcmsg gText_0x817A529 MSG_KEEPOPEN gText_Name_MrFuji
    closemsg
    pause 30
    spriteface FUJI UP
    pause 15
    npcmsg gText_PokeTower_TopFloor_MrFuji_Speak_1 MSG_KEEPOPEN gText_Name_MrFuji
    closemsg
    pause 60
    spriteface FUJI DOWN
    npcmsg gText_PokeTower_TopFloor_MrFuji_Speak_2 MSG_KEEPOPEN gText_Name_MrFuji
    closemsg
    pause 30
    warpmuted 0x8 0x2 0xFF 0x4 0x7
    waitstate
    release
    end

Move_PokeTower_TopFloor_MrFuji_1:
    .byte say_question
    .byte pause_long
    .byte face_player
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ May Poke Tower 1st Floor
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PokeTower_1stFloor_May:
    lock
    faceplayer
    npcmsg gText_PokeTower_1stFloor_May_Speak_13 MSG_KEEPOPEN gText_Name_May
    closemsg
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Rival Poke Tower 1st Floor
@@@@@@@@@@@@@@@@@@@@@@
MapScript_PokeTower_1stFloor:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_PokeTower_1stFloor
    .byte MAP_SCRIPT_TERMIN

LevelScript_PokeTower_1stFloor:
    levelscript 0x405D, 0, EventScript_PokeTower_1stFloor_Rival
    .hword LEVEL_SCRIPT_TERMIN

EventScript_PokeTower_1stFloor_Rival:
    lock
    pause 30
    applymovement RIVAL_TOWER_1 Move_PokeTower_1stFloor_Rival_1
    waitmovement RIVAL_TOWER_1
    spriteface PLAYER UP
    sound 0x15
    applymovement RIVAL_TOWER_1 Move_PokeTower_1stFloor_Rival_2
    waitmovement RIVAL_TOWER_1
    pause 30
    spriteface PLAYER UP
    applymovement PLAYER Move_PokeTower_1stFloor_Player_1
    waitmovement PLAYER
    npcmsg gText_PokeTower_1stFloor_Rival_Speak_1 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    pause 30
    sound 0x15
    applymovement RIVAL_TOWER_1 Move_PokeTower_1stFloor_Rival_2
    waitmovement RIVAL_TOWER_1
    pause 30
    spriteface PLAYER DOWN
    showsprite MAY_TOWER_1
    applymovement MAY_TOWER_1 Move_PokeTower_1stFloor_May_1
    waitmovement MAY_TOWER_1
    sound 0x9
    pause 30
    sound 0x15
    applymovement MAY_TOWER_1 Move_PokeTower_1stFloor_May_2
    waitmovement MAY_TOWER_1
    spriteface RIVAL_TOWER_1 RIGHT
    spriteface PLAYER RIGHT
    npcmsg gText_PokeTower_1stFloor_May_Speak_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    spriteface MAY_TOWER_1 UP
    npcmsg gText_PokeTower_1stFloor_Rival_Speak_2 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    npcmsg gText_PokeTower_1stFloor_May_Speak_2 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_PokeTower_1stFloor_Rival_Speak_3 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    npcmsg gText_PokeTower_1stFloor_May_Speak_3 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_PokeTower_1stFloor_Rival_Speak_4 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    npcmsg gText_PokeTower_1stFloor_May_Speak_4 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_PokeTower_1stFloor_Rival_Speak_5 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    npcmsg gText_PokeTower_1stFloor_May_Speak_5 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_PokeTower_1stFloor_Rival_Speak_6 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    setvar LASTTALKED 0x1
    setflag 0x908
    setvar 0x5011 64
    setvar 0x5012 0x3
    pause 30
    compare 0x4031 0x2
    if 0x1 _call EventScript_PokeTower_1stFloor_Rival_Squirtle
    compare 0x4031 0x1
    if 0x1 _call EventScript_PokeTower_1stFloor_Rival_Bulbasaur
    compare 0x4031 0x0
    if 0x1 _call EventScript_PokeTower_1stFloor_Rival_Charmander
    npcmsg gText_PokeTower_1stFloor_May_Speak_6 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_PokeTower_1stFloor_Rival_Speak_7 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    npcmsg gText_PokeTower_1stFloor_May_Speak_7 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_PokeTower_1stFloor_Rival_Speak_8 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    npcmsg gText_PokeTower_1stFloor_May_Speak_8 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_PokeTower_1stFloor_Rival_Speak_9 MSG_KEEPOPEN gText_Name_Rival
    closemsg
    applymovement RIVAL_TOWER_1 Move_PokeTower_1stFloor_Rival_3
    applymovement PLAYER Move_PokeTower_1stFloor_Player_2
    applymovement MAY_TOWER_1 Move_PokeTower_1stFloor_May_3
    waitmovement RIVAL_TOWER_1
    sound 0x9
    hidesprite RIVAL_TOWER_1
    setflag 0x51
    special 0x0
    pause 30
    spriteface PLAYER RIGHT
    spriteface MAY_TOWER_1 LEFT
    npcmsg gText_PokeTower_1stFloor_May_Speak_9 MSG_KEEPOPEN gText_Name_May
    closemsg
    sound 0x15
    applymovement MAY_TOWER_1 Move_PokeTower_1stFloor_May_4
    waitmovement RIVAL_TOWER_1
    npcmsg gText_PokeTower_1stFloor_May_Speak_10 MSG_KEEPOPEN gText_Name_May
    closemsg
    pause 30
    spriteface MAY_TOWER_1 DOWN
    npcmsg gText_PokeTower_1stFloor_May_Speak_11 MSG_KEEPOPEN gText_Name_May
    closemsg
    pause 15
    spriteface MAY_TOWER_1 LEFT
    npcmsg gText_PokeTower_1stFloor_May_Speak_12 MSG_KEEPOPEN gText_Name_May
    closemsg
    setvar 0x405D 0x1
    release
    end

EventScript_PokeTower_1stFloor_Rival_Squirtle:
    trainerbattle3 0x3 429 0x0 gText_PokeTower_1stFloor_Rival_Defeat
    return

EventScript_PokeTower_1stFloor_Rival_Bulbasaur:
    trainerbattle3 0x3 430 0x0 gText_PokeTower_1stFloor_Rival_Defeat
    return

EventScript_PokeTower_1stFloor_Rival_Charmander:
    trainerbattle3 0x3 431 0x0 gText_PokeTower_1stFloor_Rival_Defeat
    return

Move_PokeTower_1stFloor_Rival_1:
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte end_m

Move_PokeTower_1stFloor_Rival_2:
    .byte exclaim
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_PokeTower_1stFloor_Player_1:
    .byte walk_left
    .byte walk_up
    .byte end_m

Move_PokeTower_1stFloor_May_1:
    .byte walk_left
    .byte end_m

Move_PokeTower_1stFloor_May_2:
    .byte exclaim
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte walk_up
    .byte walk_left_onspot_fastest
    .byte end_m

Move_PokeTower_1stFloor_Rival_3:
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte end_m

Move_PokeTower_1stFloor_Player_2:
    .byte walk_up_onspot_fastest
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte end_m

Move_PokeTower_1stFloor_May_3:
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_PokeTower_1stFloor_May_4:
    .byte exclaim
    .byte pause_long
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Mr Fuji Volunteer House
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Lavender_MrFuji:
    lock
    faceplayer
    checkflag 0x23D
    if 0x1 _goto EventScript_0x816B196
    npcmsg gText_Lavender_MrFujiSpeak1 MSG_KEEPOPEN gText_Name_MrFuji
    closemsg
    checkitemspace 0x15E 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto EventScript_0x816B1A0
    setflag 0x23D
    additem 0x15E 0x1
    loadpointer 0x0 0x81937BD
    giveitemwithfanfare 0x15E 0x1 0x13E
    npcmsg gText_Lavender_MrFujiSpeak2 MSG_KEEPOPEN gText_Name_MrFuji
    closemsg
    release
    end

EventScript_0x816B196:
    npcmsg gText_Lavender_MrFujiSpeak3 MSG_KEEPOPEN gText_Name_MrFuji
    closemsg
    release
    end

EventScript_0x816B1A0:
    npcmsg gText_Lavender_MrFujiSpeak4 MSG_KEEPOPEN gText_Name_MrFuji
    closemsg
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Pokemon head on fire | Jirachi Event
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Lavender_FireHead:
    lock
    faceplayer
    checkflag FLAG_OLD_WOMAN_FIRE_HEAD
    if SET _goto EventScript_Lavender_FireHead_Done
    msgbox gText_Lavender_FireHead_Granny_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    callasm CheckFireHeadMons
    compare 0x8004 0
    if equal _goto EventScript_Lavender_FireHead_End
    pause 30
    sound 0x15
    applymovement 0x2 Move_Lavender_FireHead_Granny_1
    waitmovement 0x2
    bufferpokemon 0x0 0x8004
    msgbox gText_Lavender_FireHead_Granny_Speak_2 MSG_KEEPOPEN
    closeonkeypress
    pause 60
    fadescreenspeed 0x3 5
    cry SPECIES_JIRACHI 0x0
    fadescreenspeed 0x2 5
    msgbox gText_Lavender_FireHead_Narrator_1 MSG_KEEPOPEN
    closeonkeypress
    setflag FLAG_OLD_WOMAN_FIRE_HEAD
    release
    end

EventScript_Lavender_FireHead_Done:
    msgbox gText_Lavender_FireHead_Granny_Speak_3 MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_Lavender_FireHead_End:
    release
    end

Move_Lavender_FireHead_Granny_1:
    .byte exclaim
    .byte pause_long
    .byte pause_long
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Flannery Lavender Town
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Lavender_Flannery:
    lock
    pause 30
    sound 0x15
    applymovement 8 Move_Lavender_Flannery_1
    waitmovement 8
    npcmsg gText_Lavender_Flannery_Speak_1 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    npcmsg gText_Lavender_Flannery_Speak_2 MSG_KEEPOPEN gText_Name_Flannery
    closemsg
    applymovement 8 Move_Lavender_Flannery_2
    waitmovement 8
    npcmsg gText_Lavender_Flannery_Speak_3 MSG_YESNO gText_Name_Flannery
    compare LASTRESULT 0x1
    if notequal _goto EventScript_Lavender_Flannery_PlayerDontWantToBattle
    closemsg
    trainerbattle3 0x3 83 0x0 gText_Lavender_Flannery_Defeat
    npcmsg gText_Lavender_Flannery_Speak_4 MSG_KEEPOPEN gText_Name_Flannery
    closemsg
    giveitem ITEM_CHARCOAL 0x1 MSG_OBTAIN
    npcmsg gText_Lavender_Flannery_Speak_5 MSG_KEEPOPEN gText_Name_Flannery
    closemsg
    npcmsg gText_Lavender_Flannery_Speak_6 MSG_KEEPOPEN gText_Name_Flannery
    closemsg
    fadescreen 0x1
    hidesprite 8
    setflag FLAG_FLANNERY_LAVENDER_SPRITE
    fadescreen 0x0
    release
    end

EventScript_Lavender_Flannery_PlayerDontWantToBattle:
    npcmsg gText_Lavender_Flannery_PlayerDontWantToBattle MSG_KEEPOPEN gText_Name_Flannery
    closemsg
    spriteface 8, UP
    release
    end

Move_Lavender_Flannery_1:
    .byte exclaim
    .byte pause_long
    .byte face_player
    .byte end_m

Move_Lavender_Flannery_2:
    .byte say_question
    .byte pause_long
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Lavender Town Rocket Gang
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Lavender:
    mapscript MAP_SCRIPT_ON_TRANSITION Map_Lavender
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_Lavender_RocketGang
    .byte MAP_SCRIPT_TERMIN

Map_Lavender:
    setworldmapflag 0x894
    setvar 0x405B 0x1
    setflag 0x3D
    end

LevelScript_Lavender_RocketGang:
    levelscript VAR_ROCKET_GANG_ENCOUNTER, 2, EventScript_Lavender_Cubone
    levelscript VAR_ROCKET_GANG_ENCOUNTER, 4, EventScript_Lavender_RocketGang
    .hword LEVEL_SCRIPT_TERMIN

@ CUBONE AND MAY ENTER POKETOWER
EventScript_Lavender_Cubone:
    lock
    pause 30
    special 0x113
    getplayerpos 0x8000 0x8001
    compare 0x8000 0xB
    if equal _call EventScript_Lavender_Cubone_PlayerPos1
    compare 0x8000 0xC
    if equal _call EventScript_Lavender_Cubone_PlayerPos2
    special 0x114
    pause 30
    applymovement CUBONE Move_Lavender_Cubone_1
    waitmovement CUBONE
    sound 0x9
    hidesprite CUBONE
    setflag FLAG_CUBONE_LAVENDER_SPRITE
    showsprite MAY
    applymovement MAY Move_Lavender_May_1
    waitmovement MAY
    npcmsg gText_Lavender_Cubone_May_Speak_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement MAY Move_Lavender_May_2
    waitmovement MAY
    sound 0x9
    hidesprite MAY
    setvar VAR_ROCKET_GANG_ENCOUNTER 0x3
    special 0x113
    compare 0x8002 0xB
    if equal _call EventScript_Lavender_Cubone_PlayerPos3
    compare 0x8002 0xC
    if equal _call EventScript_Lavender_Cubone_PlayerPos4
    special 0x114
    release
    end

EventScript_Lavender_Cubone_PlayerPos1:
    applymovement CAMERA Move_Lavender_Cubone_Camera_1
    waitmovement CAMERA
    setvar 0x8002 0xB
    return

EventScript_Lavender_Cubone_PlayerPos2:
    applymovement CAMERA Move_Lavender_Cubone_Camera_2
    waitmovement CAMERA
    setvar 0x8002 0xC
    return

EventScript_Lavender_Cubone_PlayerPos3:
    applymovement CAMERA Move_Lavender_Cubone_Camera_3
    waitmovement CAMERA
    return

EventScript_Lavender_Cubone_PlayerPos4:
    applymovement CAMERA Move_Lavender_Cubone_Camera_4
    waitmovement CAMERA
    return

Move_Lavender_Cubone_Camera_1:
    .byte walk_down
    .byte walk_down
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
    .byte end_m

Move_Lavender_Cubone_Camera_2:
    .byte walk_down
    .byte walk_down
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
    .byte end_m

Move_Lavender_Cubone_Camera_3:
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_Lavender_Cubone_Camera_4:
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_Lavender_Cubone_1:
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte say_question
    .byte pause_long
    .byte pause_long
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_Lavender_May_1:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte pause_long
    .byte pause_long
    .byte say_question
    .byte pause_long
    .byte end_m

Move_Lavender_May_2:
    .byte walk_up
    .byte walk_up
    .byte end_m

@ ROCKET GANG
EventScript_Lavender_RocketGang:
    lock
    pause 30
    sound 0x15
    applymovement PLAYER Move_Lavender_RocketGang_Player_1
    waitmovement PLAYER
    special 0x113
    applymovement CAMERA Move_Lavender_RocketGang_Camera_1
    waitmovement CAMERA 
    special 0x114
    pause 30
    playsong 0x184 0x1
    npcmsg gText_Lavender_RocketGang_Jessie_Speak_1 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    sound 0x15
    applymovement JESSIE Move_Lavender_RocketGang_Jessie_1
    waitmovement JESSIE
    npcmsg gText_Lavender_RocketGang_Jessie_Speak_2 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    pause 30
    applymovement MEOWTH Move_Lavender_RocketGang_Meowth_2
    waitmovement MEOWTH
    npcmsg gText_Lavender_RocketGang_Meowth_Speak_1 MSG_KEEPOPEN gText_Name_Meowth
    closemsg
    pause 30
    spriteface JAMES RIGHT
    spriteface MEOWTH RIGHT
    npcmsg gText_Lavender_RocketGang_James_Speak_1 MSG_KEEPOPEN gText_Name_James
    closemsg
    npcmsg gText_Lavender_RocketGang_Jessie_Speak_3 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    pause 30
    spriteface JAMES LEFT
    spriteface MEOWTH DOWN
    npcmsg gText_Lavender_RocketGang_James_Speak_2 MSG_KEEPOPEN gText_Name_James
    closemsg
    npcmsg gText_Lavender_RocketGang_Meowth_Speak_2 MSG_KEEPOPEN gText_Name_Meowth
    closemsg
    pause 30
    npcmsg gText_Lavender_RocketGang_Jessie_Speak_4 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    pause 30
    sound 0x15
    applymovement JESSIE Move_Lavender_RocketGang_Jessie_2
    waitmovement JESSIE
    npcmsg gText_Lavender_RocketGang_Jessie_Speak_5 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    pause 30
    npcmsg gText_Lavender_RocketGang_Meowth_Speak_3 MSG_KEEPOPEN gText_Name_Meowth
    closemsg
    applymovement JESSIE Move_Lavender_RocketGang_Jessie_3
    applymovement JAMES Move_Lavender_RocketGang_James_1
    applymovement MEOWTH Move_Lavender_RocketGang_Meowth_1
    waitmovement JESSIE
    hidesprite JESSIE
    hidesprite JAMES
    hidesprite MEOWTH
    setflag FLAG_ROCKET_GANG_LAVENDER_SPRITE
    setvar VAR_ROCKET_GANG_ENCOUNTER 0x5
    fadedefaultbgm
    pause 30
    special 0x113
    applymovement CAMERA Move_Lavender_RocketGang_Camera_2
    waitmovement CAMERA
    special 0x114
    release
    end

Move_Lavender_RocketGang_Jessie_1:
    .byte say_double_exclaim
    .byte pause_long
    .byte end_m

Move_Lavender_RocketGang_Jessie_2:
    .byte say_question
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Lavender_RocketGang_Jessie_3:
    .byte walk_right
    .byte pause_long
    .byte pause_long
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_Lavender_RocketGang_James_1:
    .byte pause_long
    .byte walk_down
    .byte walk_down
    .byte pause_long
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_Lavender_RocketGang_Meowth_1:
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte pause_long
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_Lavender_RocketGang_Meowth_2:
    .byte jump_onspot_down
    .byte pause_long
    .byte end_m

Move_Lavender_RocketGang_Player_1:
    .byte exclaim
    .byte pause_long
    .byte end_m

Move_Lavender_RocketGang_Camera_1:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte end_m

Move_Lavender_RocketGang_Camera_2:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Inside Poke Tower Cubone Event
@@@@@@@@@@@@@@@@@@@@@@
MapScript_PokeTower_2ndFloor:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_PokeTower
    .byte MAP_SCRIPT_TERMIN

LevelScript_PokeTower:
    levelscript VAR_ROCKET_GANG_ENCOUNTER, 3, EventScript_PokeTower_Cubone
    .hword LEVEL_SCRIPT_TERMIN

EventScript_PokeTower_Cubone:
    lock
    pause 30
    applymovement PLAYER Move_PokeTower_Cubone_Player_1
    waitmovement PLAYER
    showsprite MAY_TOWER_2
    applymovement MAY_TOWER_2 Move_PokeTower_Cubone_May_1
    waitmovement MAY_TOWER_2
    spriteface MAY_TOWER_2 DOWN
    npcmsg gText_PokeTower_Cubone_May_Speak_1 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement MAY_TOWER_2 Move_PokeTower_Cubone_May_2
    waitmovement MAY_TOWER_2
    npcmsg gText_PokeTower_Cubone_May_Speak_2 MSG_KEEPOPEN gText_Name_May
    closemsg
    pause 30
    sound 0x15
    applymovement MAY_TOWER_2 Move_PokeTower_Cubone_May_3
    waitmovement MAY_TOWER_2
    npcmsg gText_PokeTower_Cubone_May_Speak_3 MSG_KEEPOPEN gText_Name_May
    closemsg
    pause 30
    spriteface PLAYER UP
    npcmsg gText_PokeTower_Cubone_May_Speak_4 MSG_KEEPOPEN gText_Name_May
    closemsg
    spriteface MAY_TOWER_1 LEFT
    npcmsg gText_PokeTower_Cubone_May_Speak_5 MSG_KEEPOPEN gText_Name_May
    applymovement MAY_TOWER_2 Move_PokeTower_Cubone_May_4
    waitmovement MAY_TOWER_2
    sound 0x9
    closemsg
    hidesprite MAY_TOWER_2
    setflag FLAG_MAY_POKETOWER_SPRITE_2
    pause 30
    signbox gText_PokeTower_Cubone_Ghost_Speak_1 MSG_NORMAL
    pause 30
    applymovement CUBONE_TOWER Move_PokeTower_Cubone_Cubone_1
    waitmovement CUBONE_TOWER
    cry SPECIES_CUBONE 0x0
    msgbox gText_PokeTower_Cubone_Cubone_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    pause 30
    sound 0x15
    applymovement CUBONE_TOWER Move_PokeTower_Cubone_Cubone_2
    waitmovement CUBONE_TOWER
    spriteface PLAYER LEFT
    cry SPECIES_CUBONE 0x0
    msgbox gText_PokeTower_Cubone_Cubone_Speak_2 MSG_KEEPOPEN
    closeonkeypress
    applymovement CUBONE_TOWER Move_PokeTower_Cubone_Cubone_3
    waitmovement CUBONE_TOWER
    sound 0x9
    hidesprite CUBONE_TOWER
    setflag FLAG_CUBONE_POKETOWER_SPRITE
    setvar VAR_ROCKET_GANG_ENCOUNTER 0x4
    clearflag FLAG_ROCKET_GANG_LAVENDER_SPRITE
    signbox gText_PokeTower_Cubone_Narrator_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    fadescreen 0x1
    pause 15
    fadescreen 0x0
    release
    end

Move_PokeTower_Cubone_Player_1:
    .byte walk_right
    .byte walk_left_onspot_fastest
    .byte end_m

Move_PokeTower_Cubone_May_1:
    .byte pause_long
    .byte walk_right
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte end_m

Move_PokeTower_Cubone_May_2:
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte end_m

Move_PokeTower_Cubone_May_3:
    .byte say_question
    .byte walk_up_onspot_fastest
    .byte end_m

Move_PokeTower_Cubone_May_4:
    .byte run_left
    .byte end_m

Move_PokeTower_Cubone_Cubone_1:
    .byte walk_up
    .byte walk_up
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte pause_long
    .byte jump_onspot_up
    .byte jump_onspot_up
    .byte end_m

Move_PokeTower_Cubone_Cubone_2:
    .byte say_question
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte end_m

Move_PokeTower_Cubone_Cubone_3:
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte say_question
    .byte pause_long
    .byte pause_long
    .byte walk_left
    .byte end_m
