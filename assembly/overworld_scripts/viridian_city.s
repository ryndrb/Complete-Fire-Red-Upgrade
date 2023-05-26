.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ Goivanni
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymLeaderGiovanni:
    setvar 0x8004 0xF
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x15E 0x0 0x818F352 0x818F43F EventScript_0x8169F04
    checkflag 0x298
    if 0x0 _goto 0x8169F2F
    npcmsg 0x818F4A2 MSG_KEEPOPEN gText_Name_Giovanni
    closemsg
    fadescreen 0x1
    hidesprite 0x8
    fadescreen 0x0
    release
    end

EventScript_0x8169F04:
    setvar 0x8004 0xF
    setvar 0x8005 0x3
    special 0x173
    setflag 0xAD
    setflag 0x4B7
    setflag 0x827
    setvar 0x4054 0x3
    setvar 0x8008 0x8
    call 0x81A6B18
    goto 0x8169F2F
    end

EventScript_0x8169F2F:
    npcmsg 0x818F586 MSG_KEEPOPEN gText_Name_Giovanni
    closemsg
    checkitemspace 0x13A 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x8169F70
    giveitem_msg 0x818F675 ITEM_TM26
    setflag 0x298
    npcmsg 0x818F695 MSG_KEEPOPEN gText_Name_Giovanni
    closemsg
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Steelixite | Cinnabar Island | Gym Guy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymGuySteelixite:
    lock
    faceplayer
    checkflag 0x4B7
    if 0x1 _goto EventScript_GiveSteelixite
    msgbox 0x8191298 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x816A689
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816A697
    end

EventScript_GiveSteelixite:
    checkflag FLAG_OBTAIN_STEELIXITE
    if 0x1 _goto Obtained
    msgbox gText_GymGuyGiveStone MSG_KEEPOPEN
    giveitem ITEM_STEELIXITE 0x1 MSG_OBTAIN
    bufferitem 0x0 ITEM_STEELIXITE
    bufferpokemon 0x1 SPECIES_STEELIX
    msgbox gText_ObtainedStone MSG_KEEPOPEN
    setflag FLAG_OBTAIN_STEELIXITE
    release
    end

Obtained:
    goto 0x816A67F
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Swords Dance | Viridian City Old Man | Beat Giovanni
@@@@@@@@@@@@@@@@@@@@@@
EventScript_ViridianSwordsDance:
    lock
    faceplayer
    checkflag FLAG_OBTAIN_SWORDS_DANCE
    if 0x0 _goto EventScript_BeatGiovanni
    compare 0x405A 0x1
    if 0x1 _goto 0x81659EC
    msgbox 0x817DB39 MSG_FACE
    applymovement 0x3 0x81A75E5
    waitmovement 0x0
    release
    end

EventScript_BeatGiovanni:
    checkflag 0x4B7
    if 0x1 _goto EventScript_GiveSwordsDance
    msgbox 0x817DB39 MSG_FACE
    end

EventScript_GiveSwordsDance:
    msgbox gText_GiveSwordsDance MSG_KEEPOPEN
    giveitem ITEM_TM75 0x1 MSG_OBTAIN
    msgbox gText_GiveSwordsDanceObtained MSG_KEEPOPEN
    setflag FLAG_OBTAIN_SWORDS_DANCE
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Nurse Joy Give Poke Vial
@@@@@@@@@@@@@@@@@@@@@@
EventScript_NurseJoyViridian:
    lock
    faceplayer
    setvar 0x5045 0xA
    checkflag FLAG_NURSE_JOY_POKE_VIAL
    if 0x0 _goto EventScript_GiveVial
    call 0x81A6578
    release
    end

EventScript_GiveVial:
    msgbox gText_NurseJoyGiveVial MSG_KEEPOPEN
    msgbox gText_PlayerReceievedVial MSG_KEEPOPEN
    msgbox gText_NurseJoyExplainsVial MSG_KEEPOPEN
    setflag FLAG_NURSE_JOY_POKE_VIAL
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Viridan Pokemart
@@@@@@@@@@@@@@@@@@@@@@
MapScript_0x16A1DE:
    mapscript MAP_SCRIPT_ON_LOAD SetMapTileScript_0x16A1DE
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_0x16A1DE
    .byte MAP_SCRIPT_TERMIN

LevelScript_0x16A1DE:
    levelscript 0x4057, 0, EventScript_0x16A205
    .hword LEVEL_SCRIPT_TERMIN

SetMapTileScript_0x16A1DE:
    checkflag 0x829
    if 0x0 _goto EventScript_0x816A1E8
    end

EventScript_0x816A1E8:
    setmaptile 0x1 0x3 0x2BF 0x1
    setmaptile 0x1 0x4 0x2C0 0x1
    end

EventScript_0x16A205:
    lockall
    applymovement 0x1 0x81A75ED
    waitmovement 0x0
    msgbox 0x819021A MSG_KEEPOPEN
    closeonkeypress
    applymovement 0x1 0x816A262
    applymovement PLAYER 0x816A25C
    waitmovement 0x0
    msgbox 0x819023A MSG_KEEPOPEN
    setvar 0x4057 0x1
    additem 0x15D 0x1
    loadpointer 0x0 0x8190289
    giveitemwithfanfare 0x15D 0x1 0x13E
    setvar 0x4055 0x5
    setvar VAR_MAY_ENCOUNTER 0x1
    clearflag FLAG_MAY_ROUTE1_SPRITE
    releaseall
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Old Fising Rod
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Viridian_OldRod:
    lock
    faceplayer
    checkflag 0x240
    if 0x1 _goto 0x816B3CF
    msgbox 0x8193EC1 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x816B3D9
    msgbox 0x8194028 MSG_KEEPOPEN
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ GS Ball Woman
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Viridian_GSBall:
    lock
    faceplayer
    checkflag 0x4B3
    if NOT_SET _goto EventScript_Viridian_GSBall_PlayerNotChampion
    checkflag FLAG_GS_BALL
    if SET _goto EventScript_Viridian_GSBall_Done
    pause 45
    sound 0x15
    applymovement 0x4 Move_Viridian_GSBall
    waitmovement 0x4
    msgbox gText_Viridian_GSBall_Woman_Speak_1 MSG_KEEPOPEN
    msgbox gText_Viridian_GSBall_Woman_Speak_2 MSG_KEEPOPEN
    closeonkeypress
    fanfare 0x13E
    msgbox gText_Viridian_GSBall_Narrator_1 MSG_KEEPOPEN
    waitfanfare
    msgbox gText_Viridian_GSBall_Woman_Speak_3 MSG_KEEPOPEN
    closeonkeypress
    setflag FLAG_GS_BALL
    clearflag FLAG_CELEBI_VIRIDIAN_FOREST
    release
    end

EventScript_Viridian_GSBall_PlayerNotChampion:
    msgbox gText_Viridian_GSBall_PlayerNotChampion MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_Viridian_GSBall_Done:
    msgbox gText_Viridian_GSBall_Woman_Speak_3 MSG_KEEPOPEN
    closeonkeypress
    release
    end

Move_Viridian_GSBall:
    .byte exclaim
    .byte pause_long
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Viridian Wanted Signpost
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Viridian_Wated_Signpost:
    signmsg
    msgbox gText_Viridian_Wated_Signpost MSG_NORMAL
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Rocket Gang
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Viridian_RocketGang_Left:
    setvar 0x4001 0x1
    goto EventScript_Viridian_RocketGang
    end

EventScript_Viridian_RocketGang_Right:
    setvar 0x4001 0x2
    goto EventScript_Viridian_RocketGang
    end

EventScript_Viridian_RocketGang:
    lock
    special 0x113
    compare 0x4001 0x1
    if equal _call EventScript_Viridian_RocketGang_Camera_Left
    compare 0x4001 0x2
    if equal _call EventScript_Viridian_RocketGang_Camera_Right
    special 0x114
    playsong 0x184 0x0
    npcmsg gText_Viridian_RocketGang_Jessie_Speak_1 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    npcmsg gText_Viridian_RocketGang_James_Speak_1 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    applymovement 14 Move_Viridian_RocketGang_James_1
    waitmovement 14
    npcmsg gText_Viridian_RocketGang_James_Speak_2 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    applymovement 13 Move_Viridian_RocketGang_Jessie_1
    waitmovement 13
    npcmsg gText_Viridian_RocketGang_Jessie_Speak_2 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    npcmsg gText_Viridian_RocketGang_James_Speak_3 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    applymovement 13 Move_Viridian_RocketGang_Jessie_2
    waitmovement 13
    npcmsg gText_Viridian_RocketGang_Jessie_Speak_3 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    npcmsg gText_Viridian_RocketGang_James_Speak_4 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    applymovement 15 Move_Viridian_RocketGang_Meowth_1
    waitmovement 15    
    npcmsg gText_Viridian_RocketGang_Meowth_Speak_1 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    npcmsg gText_Viridian_RocketGang_Jessie_Speak_4 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    npcmsg gText_Viridian_RocketGang_James_Speak_5 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    npcmsg gText_Viridian_RocketGang_Meowth_Speak_2 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    npcmsg gText_Viridian_RocketGang_James_Speak_6 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    pause 30
    goto EventScript_Viridian_RocketGang_NoticePlayer

EventScript_Viridian_RocketGang_NoticePlayer:
    sound 0x15
    applymovement 13 Move_Viridian_RocketGang_Jessie_3
    applymovement 14 Move_Viridian_RocketGang_James_2
    applymovement 15 Move_Viridian_RocketGang_Meowth_2
    compare 0x4001 0x1
    if equal _call EventScript_Viridian_RocketGang_Player_Left
    compare 0x4001 0x2
    if equal _call EventScript_Viridian_RocketGang_Player_Right
    waitmovement 15
    pause 15
    npcmsg gText_Viridian_RocketGang_Jessie_Speak_5 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    pause 15
    spriteface 13, RIGHT
    spriteface 14, LEFT
    spriteface 15, LEFT
    npcmsg gText_Viridian_RocketGang_James_Speak_7 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    pause 15
    spriteface 13, DOWN
    spriteface 14, DOWN
    spriteface 15, DOWN
    npcmsg gText_Viridian_RocketGang_Jessie_Speak_6 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    applymovement 13 Move_Viridian_RocketGang_Jessie_4
    waitmovement 13
    npcmsg gText_Viridian_RocketGang_Jessie_Speak_7 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    applymovement 14 Move_Viridian_RocketGang_James_3
    waitmovement 14
    npcmsg gText_Viridian_RocketGang_James_Speak_8 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    pause 30
    spriteface 13, LEFT
    npcmsg gText_Viridian_RocketGang_Jessie_Speak_8 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    spriteface 14, RIGHT
    npcmsg gText_Viridian_RocketGang_James_Speak_9 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    spriteface 13, UP
    npcmsg gText_Viridian_RocketGang_Jessie_Speak_9 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    spriteface 14, UP
    npcmsg gText_Viridian_RocketGang_James_Speak_10 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    sound 0x79
    spriteface 13, DOWN
    npcmsg gText_Viridian_RocketGang_Jessie_Speak_10 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    sound 0x79
    spriteface 14, DOWN
    npcmsg gText_Viridian_RocketGang_James_Speak_11 MSG_KEEPOPEN gText_Name_James
    closemsg
    npcmsg gText_Viridian_RocketGang_Jessie_Speak_11 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    npcmsg gText_Viridian_RocketGang_James_Speak_12 MSG_KEEPOPEN gText_Name_James
    closemsg
    applymovement 15 Move_Viridian_RocketGang_Meowth_3
    waitmovement 15
    npcmsg gText_Viridian_RocketGang_Meowth_Speak_3 MSG_KEEPOPEN gText_Name_Meowth
    closemsg
    sound 0x15
    applymovement 14 Move_Viridian_RocketGang_James_4
    waitmovement 14
    npcmsg gText_Viridian_RocketGang_James_Speak_13 MSG_KEEPOPEN gText_Name_James
    closemsg
    pause 30
    spriteface 13, RIGHT
    spriteface 14, LEFT
    npcmsg gText_Viridian_RocketGang_James_Speak_13 MSG_KEEPOPEN gText_Name_James
    closemsg
    spriteface 14, RIGHT
    spriteface 15, LEFT
    npcmsg gText_Viridian_RocketGang_James_Speak_13 MSG_KEEPOPEN gText_Name_James
    closemsg
    spriteface 13, DOWN
    spriteface 14, DOWN
    spriteface 15, DOWN
    npcmsg gText_Viridian_RocketGang_James_Speak_14 MSG_KEEPOPEN gText_Name_James
    closemsg
    npcmsg gText_Viridian_RocketGang_Meowth_Speak_4 MSG_KEEPOPEN gText_Name_Meowth
    closemsg
    npcmsg gText_Viridian_RocketGang_Jessie_Speak_12 MSG_KEEPOPEN gText_Name_Jessie
    closemsg
    npcmsg gText_Viridian_RocketGang_James_Speak_15 MSG_KEEPOPEN gText_Name_James
    closemsg
    pause 30
    fadescreen 0x1
    hidesprite 13
    hidesprite 14
    hidesprite 15
    setflag FLAG_ROCKET_GANG_VIRIDIAN_SPRITE
    setvar VAR_ROCKET_GANG_ENCOUNTER 0x2
    fadescreen 0x0
    fadedefaultbgm
    release
    end

EventScript_Viridian_RocketGang_Camera_Left:
    applymovement CAMERA Move_Viridian_RocketGang_Camera_1
    waitmovement CAMERA
    return

EventScript_Viridian_RocketGang_Camera_Right:
    applymovement CAMERA Move_Viridian_RocketGang_Camera_2
    waitmovement CAMERA
    return

EventScript_Viridian_RocketGang_Player_Left:
    applymovement PLAYER Move_Viridian_RocketGang_Player_1
    special 0x113
    applymovement CAMERA Move_Viridian_RocketGang_Camera_3
    waitmovement CAMERA
    special 0x114
    return

EventScript_Viridian_RocketGang_Player_Right:
    applymovement PLAYER Move_Viridian_RocketGang_Player_2
    special 0x113
    applymovement CAMERA Move_Viridian_RocketGang_Camera_3
    waitmovement CAMERA
    special 0x114
    return

Move_Viridian_RocketGang_Camera_1:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_right
    .byte walk_right
    .byte end_m

Move_Viridian_RocketGang_Camera_2:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_right
    .byte end_m

Move_Viridian_RocketGang_James_1:
    .byte say_question
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Viridian_RocketGang_Jessie_1:
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Viridian_RocketGang_Jessie_2:
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Viridian_RocketGang_Meowth_1:
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Viridian_RocketGang_Jessie_3:
    .byte exclaim
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte walk_left
    .byte walk_down
    .byte end_m

Move_Viridian_RocketGang_James_2:
    .byte pause_long
    .byte say_question
    .byte walk_down_onspot_fastest
    .byte walk_left
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Viridian_RocketGang_Meowth_2:
    .byte pause_long
    .byte say_question
    .byte walk_down
    .byte walk_left
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Viridian_RocketGang_Player_1:
    .byte walk_right
    .byte walk_up
    .byte end_m

Move_Viridian_RocketGang_Player_2:
    .byte walk_up
    .byte end_m

Move_Viridian_RocketGang_Camera_3:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte end_m

Move_Viridian_RocketGang_Jessie_4:
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Viridian_RocketGang_James_3:
    .byte walk_down_onspot_fastest
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Viridian_RocketGang_Meowth_3:
    .byte pause_long
    .byte jump_onspot_down
    .byte end_m

Move_Viridian_RocketGang_James_4:
    .byte exclaim
    .byte pause_long
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m
