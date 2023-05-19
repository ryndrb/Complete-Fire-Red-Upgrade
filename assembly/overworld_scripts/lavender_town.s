.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ JESSIE, 4
.equ JAMES, 5
.equ MEOWTH, 6

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
@ Mr Fuji PokeTower | After Sabrina Now
@@@@@@@@@@@@@@@@@@@@@@
EventScript_MrFuji:
    lock
    faceplayer
    setvar 0x8004 0xE
    setvar 0x8005 0x2
    special 0x174
    setflag 0x34
    setflag 0x23C
    call MrFujiNameBox
    msgbox 0x817A529 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    warp 0x8 0x2 0xFF 0x4 0x7
    waitstate
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Rival, May, and Player all meet in side PokeTower
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PokeTower_RivalBattle1:
    lockall
    setvar 0x4001 0x0
    @playsong 0x13B 0x0
    compare 0x4001 0x0
    if equal _call EventScript_PokeTower_MoveRivalAndPlayer1
    compare 0x4001 0x1
    if equal _call EventScript_PokeTower_MoveRivalAndPlayer2
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    compare 0x4001 0x0
    if equal _call EventScript_PokeTower_RivalPlayerNoticeMay1
    compare 0x4001 0x1
    if equal _call EventScript_PokeTower_RivalPlayerNoticeMay2
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks1 MSG_KEEPOPEN
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks2 MSG_KEEPOPEN
    callasm RemoveNameBox
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks2 MSG_KEEPOPEN
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks3 MSG_KEEPOPEN
    callasm RemoveNameBox
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks3 MSG_KEEPOPEN
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks4 MSG_KEEPOPEN
    callasm RemoveNameBox
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks4 MSG_KEEPOPEN
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks5 MSG_KEEPOPEN
    callasm RemoveNameBox
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks5 MSG_KEEPOPEN
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks6 MSG_KEEPOPEN
    callasm RemoveNameBox
    setvar LASTTALKED 0x1
    setflag 0x908
    setvar 0x5011 64
    setvar 0x5012 0x3
    compare 0x4031 0x2
    if 0x1 _call EventScrit_RivalSquirtle
    compare 0x4031 0x1
    if 0x1 _call EventScrit_RivalBulbasaur
    compare 0x4031 0x0
    if 0x1 _call EventScrit_RivalCharmander
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks6 MSG_KEEPOPEN
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks7 MSG_KEEPOPEN
    callasm RemoveNameBox
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks7 MSG_KEEPOPEN
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks8 MSG_KEEPOPEN
    callasm RemoveNameBox
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks8 MSG_KEEPOPEN
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks9 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    fadescreen 0x1
    hidesprite 1
    setflag 0x51
    setvar 0x405D 0x1
    fadescreen 0x0
    special 0x0
    compare 0x4001 0x0
    if equal _call EventScript_PokeTower_MayFacePlayer1
    compare 0x4001 0x1
    if equal _call EventScript_PokeTower_MayFacePlayer2
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks9 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    fadescreen 0x1
    hidesprite 3
    setflag FLAG_MAY_POKETOWER_SPRITE
    fadescreen 0x0
    release
    end

EventScript_PokeTower_RivalBattle2:
    lockall
    setvar 0x4001 0x1
    @playsong 0x13B 0x0
    compare 0x4001 0x0
    if equal _call EventScript_PokeTower_MoveRivalAndPlayer1
    compare 0x4001 0x1
    if equal _call EventScript_PokeTower_MoveRivalAndPlayer2
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    compare 0x4001 0x0
    if equal _call EventScript_PokeTower_RivalPlayerNoticeMay1
    compare 0x4001 0x1
    if equal _call EventScript_PokeTower_RivalPlayerNoticeMay2
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks1 MSG_KEEPOPEN
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks2 MSG_KEEPOPEN
    callasm RemoveNameBox
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks2 MSG_KEEPOPEN
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks3 MSG_KEEPOPEN
    callasm RemoveNameBox
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks3 MSG_KEEPOPEN
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks4 MSG_KEEPOPEN
    callasm RemoveNameBox
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks4 MSG_KEEPOPEN
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks5 MSG_KEEPOPEN
    callasm RemoveNameBox
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks5 MSG_KEEPOPEN
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks6 MSG_KEEPOPEN
    callasm RemoveNameBox
    setvar LASTTALKED 0x1
    setflag 0x908
    setvar 0x5011 64
    setvar 0x5012 0x3
    compare 0x4031 0x2
    if 0x1 _call EventScrit_RivalSquirtle
    compare 0x4031 0x1
    if 0x1 _call EventScrit_RivalBulbasaur
    compare 0x4031 0x0
    if 0x1 _call EventScrit_RivalCharmander
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks6 MSG_KEEPOPEN
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks7 MSG_KEEPOPEN
    callasm RemoveNameBox
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks7 MSG_KEEPOPEN
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks8 MSG_KEEPOPEN
    callasm RemoveNameBox
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks8 MSG_KEEPOPEN
    callasm RemoveNameBox
    call RivalNameBox
    msgbox gText_PokeTower_RivalSpeaks9 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    fadescreen 0x1
    hidesprite 1
    setflag 0x51
    setvar 0x405D 0x1
    fadescreen 0x0
    special 0x0
    compare 0x4001 0x0
    if equal _call EventScript_PokeTower_MayFacePlayer1
    compare 0x4001 0x1
    if equal _call EventScript_PokeTower_MayFacePlayer2
    call MayNameBox
    msgbox gText_PokeTower_MaySpeaks9 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    fadescreen 0x1
    hidesprite 3
    setflag FLAG_MAY_POKETOWER_SPRITE
    fadescreen 0x0
    release
    end

EventScrit_RivalSquirtle:
    trainerbattle3 0x3 429 0x0 gText_PokeTower_RivalLost
    return

EventScrit_RivalBulbasaur:
    trainerbattle3 0x3 430 0x0 gText_PokeTower_RivalLost
    return
    
EventScrit_RivalCharmander:
    trainerbattle3 0x3 431 0x0 gText_PokeTower_RivalLost
    return

EventScript_PokeTower_MoveRivalAndPlayer1:
    applymovement 1 EventScript_PokeTower_RivalNoticePlayer1
    applymovement PLAYER EventScript_PokeTower_PlayerFaceRival1
    waitmovement 1
    return

EventScript_PokeTower_MoveRivalAndPlayer2:
    applymovement 1 EventScript_PokeTower_RivalNoticePlayer2
    applymovement PLAYER EventScript_PokeTower_PlayerFaceRival2
    waitmovement 1
    return

EventScript_PokeTower_RivalPlayerNoticeMay1:
    applymovement 1 EventScript_PokeTower_RivalFaceMayDir1
    applymovement PLAYER EventScript_PokeTower_PlayerFaceMayDir1
    waitmovement 1
    applymovement 3 EventScript_PokeTower_MayMoveToBoth1
    waitmovement 3
    return

EventScript_PokeTower_RivalPlayerNoticeMay2:
    applymovement 1 EventScript_PokeTower_RivalFaceMayDir2
    applymovement PLAYER EventScript_PokeTower_PlayerFaceMayDir2
    applymovement 3 EventScript_PokeTower_MayMoveToBoth2
    waitmovement 1
    @applymovement 3 EventScript_PokeTower_MayMoveToBoth2
    @waitmovement 3
    return

EventScript_PokeTower_MayFacePlayer1:
    applymovement 3 MayFacePlayer1
    waitmovement 3
    return

EventScript_PokeTower_MayFacePlayer2:
    applymovement 3 MayFacePlayer1
    waitmovement 3
    return

EventScript_PokeTower_RivalNoticePlayer1:
    .byte walk_right_onspot_fastest
    .byte exclaim
    .byte end_m

EventScript_PokeTower_RivalNoticePlayer2:
    .byte walk_down_onspot_fastest
    .byte exclaim
    .byte end_m

EventScript_PokeTower_PlayerFaceRival1:
    .byte walk_left_onspot_fastest
    .byte end_m

EventScript_PokeTower_PlayerFaceRival2:
    .byte walk_up_onspot_fastest
    .byte end_m

EventScript_PokeTower_RivalFaceMayDir1:
    .byte exclaim
    .byte walk_down_onspot_fastest
    .byte end_m

EventScript_PokeTower_RivalFaceMayDir2:
    .byte exclaim
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte end_m

EventScript_PokeTower_PlayerFaceMayDir1:
    .byte exclaim
    .byte walk_down_onspot_fastest
    .byte end_m

EventScript_PokeTower_PlayerFaceMayDir2:
    .byte pause_long
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte end_m

EventScript_PokeTower_MayMoveToBoth1:
    .byte walk_left
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_left
    .byte walk_up_onspot_fastest
    .byte end_m

EventScript_PokeTower_MayMoveToBoth2:
    .byte walk_left
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_left_onspot_fastest
    .byte end_m

MayFacePlayer1:
    .byte walk_left
    .byte end_m

MayFacePlayer2:
    .byte walk_up
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Mr Fuji Volunteer House
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Lavender_MrFuji:
    lock
    faceplayer
    checkflag 0x23D
    if 0x1 _goto EventScript_0x816B196
    call MrFujiNameBox
    msgbox gText_Lavender_MrFujiSpeak1 MSG_KEEPOPEN
    callasm RemoveNameBox
    checkitemspace 0x15E 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto EventScript_0x816B1A0
    setflag 0x23D
    additem 0x15E 0x1
    loadpointer 0x0 0x81937BD
    giveitemwithfanfare 0x15E 0x1 0x13E
    call MrFujiNameBox
    msgbox gText_Lavender_MrFujiSpeak2 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x816B196:
    call MrFujiNameBox
    msgbox gText_Lavender_MrFujiSpeak3 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x816B1A0:
    call MrFujiNameBox
    msgbox gText_Lavender_MrFujiSpeak4 MSG_KEEPOPEN
    callasm RemoveNameBox
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
    npcmsg gText_Lavender_Flannery_Speak_1 MSG_KEEPOPEN 0 LEFT
    closemsg
    npcmsg gText_Lavender_Flannery_Speak_2 MSG_KEEPOPEN 35 LEFT
    closemsg
    applymovement 8 Move_Lavender_Flannery_2
    waitmovement 8
    npcmsg gText_Lavender_Flannery_Speak_3 MSG_YESNO 35 LEFT
    compare LASTRESULT 0x1
    if notequal _goto EventScript_Lavender_Flannery_PlayerDontWantToBattle
    closemsg
    trainerbattle3 0x3 83 0x0 gText_Lavender_Flannery_Defeat
    npcmsg gText_Lavender_Flannery_Speak_4 MSG_KEEPOPEN 35 LEFT
    closemsg
    giveitem ITEM_CHARCOAL 0x1 MSG_OBTAIN
    npcmsg gText_Lavender_Flannery_Speak_5 MSG_KEEPOPEN 35 LEFT
    closemsg
    npcmsg gText_Lavender_Flannery_Speak_6 MSG_KEEPOPEN 35 LEFT
    closemsg
    fadescreen 0x1
    hidesprite 8
    setflag FLAG_FLANNERY_LAVENDER_SPRITE
    fadescreen 0x0
    release
    end

EventScript_Lavender_Flannery_PlayerDontWantToBattle:
    npcmsg gText_Lavender_Flannery_PlayerDontWantToBattle MSG_KEEPOPEN 35 LEFT
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
    levelscript VAR_ROCKET_GANG_ENCOUNTER, 2, EventScript_Lavender_RocketGang
    .hword LEVEL_SCRIPT_TERMIN

EventScript_Lavender_RocketGang:
    lock
    pause 30
    sound 0x15
    applymovement PLAYER Move_Lavender_RocketGang_Player_1
    waitmovement PLAYER
    special 0x113
    getplayerpos 0x8000 0x8001
    compare 0x8000 0xB
    if equal _call EventScript_Lavender_RocketGang_PlayerPos1
    compare 0x8000 0xC
    if equal _call EventScript_Lavender_RocketGang_PlayerPos2
    special 0x114
    pause 30
    playsong 0x184 0x1
    npcmsg gText_Lavender_RocketGang_Jessie_Speak_1 MSG_KEEPOPEN 29 LEFT
    closemsg
    sound 0x15
    applymovement JESSIE Move_Lavender_RocketGang_Jessie_1
    waitmovement JESSIE
    npcmsg gText_Lavender_RocketGang_Jessie_Speak_2 MSG_KEEPOPEN 29 LEFT
    closemsg
    pause 30
    applymovement MEOWTH Move_Lavender_RocketGang_Meowth_2
    waitmovement MEOWTH
    npcmsg gText_Lavender_RocketGang_Meowth_Speak_1 MSG_KEEPOPEN 31 LEFT
    closemsg
    pause 30
    spriteface JAMES RIGHT
    spriteface MEOWTH RIGHT
    npcmsg gText_Lavender_RocketGang_James_Speak_1 MSG_KEEPOPEN 30 LEFT
    closemsg
    npcmsg gText_Lavender_RocketGang_Jessie_Speak_3 MSG_KEEPOPEN 29 LEFT
    closemsg
    pause 30
    spriteface JAMES LEFT
    spriteface MEOWTH DOWN
    npcmsg gText_Lavender_RocketGang_James_Speak_2 MSG_KEEPOPEN 30 LEFT
    closemsg
    npcmsg gText_Lavender_RocketGang_Meowth_Speak_2 MSG_KEEPOPEN 31 LEFT
    closemsg
    npcmsg gText_Lavender_RocketGang_Jessie_Speak_4 MSG_KEEPOPEN 29 LEFT
    closemsg
    pause 30
    sound 0x15
    applymovement JESSIE Move_Lavender_RocketGang_Jessie_2
    waitmovement JESSIE
    npcmsg gText_Lavender_RocketGang_Jessie_Speak_5 MSG_KEEPOPEN 29 LEFT
    closemsg
    pause 30
    npcmsg gText_Lavender_RocketGang_Meowth_Speak_3 MSG_KEEPOPEN 31 LEFT
    closemsg
    applymovement JESSIE Move_Lavender_RocketGang_Jessie_3
    applymovement JAMES Move_Lavender_RocketGang_James_1
    applymovement MEOWTH Move_Lavender_RocketGang_Meowth_1
    waitmovement JESSIE
    hidesprite JESSIE
    hidesprite JAMES
    hidesprite MEOWTH
    setflag FLAG_ROCKET_LAVENDER_SPRITE
    setvar VAR_ROCKET_GANG_ENCOUNTER 0x3
    fadedefaultbgm
    pause 30
    special 0x113
    compare 0x8002 0xB
    if equal _call EventScript_Lavender_RocketGang_PlayerPos3
    compare 0x8002 0xC
    if equal _call EventScript_Lavender_RocketGang_PlayerPos4
    special 0x114
    release
    end

EventScript_Lavender_RocketGang_PlayerPos1:
    applymovement CAMERA Move_Lavender_RocketGang_Camera_1
    waitmovement CAMERA
    setvar 0x8002 0xB
    return

EventScript_Lavender_RocketGang_PlayerPos2:
    applymovement CAMERA Move_Lavender_RocketGang_Camera_2
    waitmovement CAMERA
    setvar 0x8002 0xC
    return

EventScript_Lavender_RocketGang_PlayerPos3:
    applymovement CAMERA Move_Lavender_RocketGang_Camera_3
    waitmovement CAMERA
    return

EventScript_Lavender_RocketGang_PlayerPos4:
    applymovement CAMERA Move_Lavender_RocketGang_Camera_4
    waitmovement CAMERA
    return

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
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte end_m

Move_Lavender_RocketGang_Camera_2:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_Lavender_RocketGang_Camera_3:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_left
    .byte end_m

Move_Lavender_RocketGang_Camera_4:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Pokemon Tower NameBox
@@@@@@@@@@@@@@@@@@@@@@
RivalNameBox:
    setvar 0x8000 1
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

MayNameBox:
    setvar 0x8000 2
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

MrFujiNameBox:
    setvar 0x8000 8
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
