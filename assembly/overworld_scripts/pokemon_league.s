.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ Pokemon League Lorelei
@@@@@@@@@@@@@@@@@@@@@@
EventScript_League_Lorelei:
    lock
    faceplayer
    setvar 0x8004 0x9
    setvar 0x8005 0x2
    special 0x174
    checkflag 0x4B8
    if 0x1 _goto EventScript_0x8162669
    setvar 0x8004 0x9
    setvar 0x8005 0x0
    special 0x173
    setvar 0x8004 0x9
    setvar 0x8005 0x1
    special 0x173
    checkflag 0x844
    if 0x0 _call EventScript_0x8162641
    checkflag 0x844
    if 0x1 _call EventScript_0x816264A
    setflag 0x3
    setflag 0x5
    checkflag 0x844
    if 0x0 _call EventScript_0x8162653
    checkflag 0x844
    if 0x1 _call EventScript_0x816265E
    clearflag 0x5
    goto EventScript_0x8162673

EventScript_0x8162669:
    call LoreleiNameBox
    msgbox 0x81781B0 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8162641:
    call LoreleiNameBox
    msgbox 0x8177FA4 MSG_KEEPOPEN
    callasm RemoveNameBox
    return

EventScript_0x816264A:
    call LoreleiNameBox
    msgbox 0x8178089 MSG_KEEPOPEN
    callasm RemoveNameBox
    return

EventScript_0x8162653:
    trainerbattle3 0x3 0x19A 0x0 0x8178191
    return

EventScript_0x816265E:
    trainerbattle3 0x3 0x2DF 0x0 0x8178191
    return

EventScript_0x8162673:
    setflag 0x4B8
    call EventScript_0x81A7506
    call LoreleiNameBox
    msgbox 0x81781B0 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Pokemon League Bruno
@@@@@@@@@@@@@@@@@@@@@@
EventScript_League_Bruno:
    lock
    faceplayer
    setvar 0x8004 0xA
    setvar 0x8005 0x2
    special 0x174
    checkflag 0x4B9
    if 0x1 _goto EventScript_0x8162779
    setvar 0x8004 0xA
    setvar 0x8005 0x0
    special 0x173
    setvar 0x8004 0xA
    setvar 0x8005 0x1
    special 0x173
    checkflag 0x82C
    if 0x0 _call EventScript_0x8162751
    checkflag 0x82C
    if 0x1 _call EventScript_0x816275A
    setflag 0x3
    setflag 0x5
    checkflag 0x844
    if 0x0 _call EventScript_0x8162763
    checkflag 0x844
    if 0x1 _call EventScript_0x816276E
    clearflag 0x5
    goto EventScript_0x81627B0

EventScript_0x8162779:
    call BrunoNameBox
    msgbox 0x8178420 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    compare PLAYERFACING 0x2
    if 0x1 _call 0x81627FA
    compare PLAYERFACING 0x1
    if 0x1 _call 0x81627EF
    compare PLAYERFACING 0x3
    if 0x1 _call 0x8162805
    compare PLAYERFACING 0x4
    if 0x1 _call 0x8162805
    release
    end

EventScript_0x8162751:
    call BrunoNameBox
    msgbox 0x817820F MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    return

EventScript_0x816275A:
    call BrunoNameBox
    msgbox 0x817830C MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    return

EventScript_0x8162763:
    trainerbattle3 0x3 0x19B 0x0 0x8178409
    return

EventScript_0x816276E:
    trainerbattle3 0x3 0x2E0 0x0 0x8178409
    return

EventScript_0x81627B0:
    setflag 0x4B9
    call EventScript_0x81A7506
    call BrunoNameBox
    msgbox 0x8178420 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    compare PLAYERFACING 0x2
    if 0x1 _call EventScript_0x81627FA
    compare PLAYERFACING 0x1
    if 0x1 _call EventScript_0x81627EF
    compare PLAYERFACING 0x3
    if 0x1 _call EventScript_0x8162805
    compare PLAYERFACING 0x4
    if 0x1 _call EventScript_0x8162805
    release
    end

EventScript_0x81627FA:
    applymovement 0x1 0x81A75EB
    waitmovement 0x0
    return

EventScript_0x81627EF:
    applymovement 0x1 0x81A75E7
    waitmovement 0x0
    return

EventScript_0x8162805:
    applymovement 0x1 0x81A75ED
    waitmovement 0x0
    return

@@@@@@@@@@@@@@@@@@@@@@
@ Pokemon League Agatha
@@@@@@@@@@@@@@@@@@@@@@
EventScript_League_Agatha:
    lock
    faceplayer
    setvar 0x8004 0xB
    setvar 0x8005 0x2
    special 0x174
    checkflag 0x4BA
    if 0x1 _goto EventScript_0x8162911
    setvar 0x8004 0xB
    setvar 0x8005 0x0
    special 0x173
    setvar 0x8004 0xB
    setvar 0x8005 0x4
    special 0x173
    setvar 0x8004 0x0
    setvar 0x8005 0x4
    special 0x173
    checkflag 0x82C
    if 0x0 _call EventScript_0x81628E9
    checkflag 0x82C
    if 0x1 _call EventScript_0x81628F2
    setflag 0x3
    setflag 0x5
    checkflag 0x844
    if 0x0 _call EventScript_0x81628FB
    checkflag 0x844
    if 0x1 _call EventScript_0x8162906
    clearflag 0x5
    goto EventScript_0x816291B

EventScript_0x8162911:
    call AgathaNameBox
    msgbox 0x8178700 MSG_KEEPOPEN
    callasm RemoveNameBox
    special 0x0
    release
    end

EventScript_0x81628E9:
    call AgathaNameBox
    msgbox 0x817844D MSG_KEEPOPEN
    callasm RemoveNameBox
    return

EventScript_0x81628F2:
    call AgathaNameBox
    msgbox 0x817858D MSG_KEEPOPEN
    callasm RemoveNameBox
    return

EventScript_0x81628FB:
    trainerbattle3 0x3 0x19C 0x0 0x81786D7
    return

EventScript_0x8162906:
    trainerbattle3 0x3 0x2E1 0x0 0x81786D7
    return

EventScript_0x816291B:
    setflag 0x4BA
    call EventScript_0x81A7506
    call AgathaNameBox
    msgbox 0x8178700 MSG_KEEPOPEN
    callasm RemoveNameBox
    special 0x0
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Pokemon League Lance
@@@@@@@@@@@@@@@@@@@@@@
EventScript_League_Lance:
    lock
    faceplayer
    setvar 0x8004 0xC
    setvar 0x8005 0x2
    showsprite 2
    special 0x174
    checkflag 0x4BB
    if 0x1 _goto EventScript_0x8162AA1
    setvar 0x8004 0xC
    setvar 0x8005 0x0
    special 0x173
    setvar 0x8004 0xC
    setvar 0x8005 0x1
    special 0x173
    checkflag 0x82C
    if 0x0 _call EventScript_0x8162A79
    checkflag 0x82C
    if 0x1 _call EventScript_0x8162A82
    setflag 0x3
    setflag 0x5
    checkflag 0x844
    if 0x0 _call EventScript_0x8162A8B
    checkflag 0x844
    if 0x1 _call EventScript_0x8162A96
    clearflag 0x5
    goto EventScript_0x8162AAB
    end

EventScript_0x8162AA1:
    call LanceNameBox
    msgbox 0x8178A52 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8162A79:
    call LanceNameBox
    msgbox 0x8178764 MSG_KEEPOPEN
    callasm RemoveNameBox
    return

EventScript_0x8162A82:
    call LanceNameBox
    msgbox 0x81788BD MSG_KEEPOPEN
    callasm RemoveNameBox
    return

EventScript_0x8162A8B:
    trainerbattle3 0x3 0x19D 0x0 0x8178A15
    return

EventScript_0x8162A96:
    trainerbattle3 0x3 0x2E2 0x0 0x8178A15
    return

EventScript_0x8162AAB:
    setvar 0x8004 0x0
    special 0xAA
    setflag 0x4BB
    call EventScript_0x81A7563
    call LanceNameBox
    msgbox gText_League_LanceSpeak1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    fadescreen 0x1
    fanfare 0x0100
	special 0x0
    waitfanfare
    spriteface 0x1, DOWN
    movesprite PLAYER 0x6 0x9
    spriteface PLAYER, UP
    fadescreen 0x0
    call LanceNameBox
    msgbox gText_League_LanceSpeak2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    playsong 0x1A7
    applymovement 2 Move_League_May1
    waitmovement 2
    applymovement PLAYER Move_League_Player1
    waitmovement PLAYER
    call MayNameBox
    msgbox gText_League_MaySpeak1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    sound 0x15
    applymovement 2 Move_League_May2
    waitmovement 2
    msgbox gText_League_MaySpeak3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    fadedefaultbgm
    release
    end

EventScript_0x81A7563:
    applymovement PLAYER 0x81A75FE
    waitmovement 0x0
    sound 0x8
    setmaptile 0x6 0x4 0x28E 0x1
    setmaptile 0x6 0x5 0x296 0x0
    special 0x8E
    setflag 0x4
    return

Move_League_May1:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_left
    .byte walk_up
    .byte walk_right_onspot_fastest
    .byte end_m

Move_League_Player1:
    .byte walk_left_onspot_fastest
    .byte end_m

Move_League_May2:
    .byte exclaim
    .byte pause_long
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Pokemon League May
@@@@@@@@@@@@@@@@@@@@@@
EventScript_League_May:
    lock
    faceplayer
    call MayNameBox
    msgbox gText_League_MaySpeak4 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Pokemon League Champion Room
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Legue_FinalRoom:
    mapscript MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE LevelScript2_League_FinalRoom
    mapscript MAP_SCRIPT_ON_RESUME MapScript_0x162AF2
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript1_League_FinalRoom
    .byte MAP_SCRIPT_TERMIN

MapScript_0x162AF2:
    setvar 0x8004 0x4
    call 0x81A75D5
    compare 0x4031 0x2
    if 0x1 _call 0x8162B1E
    compare 0x4031 0x1
    if 0x1 _call 0x8162B31
    compare 0x4031 0x0
    if 0x1 _call 0x8162B44
    end

LevelScript2_League_FinalRoom:
    levelscript 0x4001, 0, LevelScript_League_0x162B67
    .hword LEVEL_SCRIPT_TERMIN

LevelScript_League_0x162B67:
    spriteface 0xFF 0x2
    end

LevelScript1_League_FinalRoom:
    levelscript 0x4001, 0, EventScript_League_0x162B76
    .hword LEVEL_SCRIPT_TERMIN

EventScript_League_0x162B76:
    lockall
    setflag 0x2
    applymovement PLAYER 0x8162D07
    waitmovement 0x0
    pause 0x14
    checkflag 0x82C
    if 0x0 _call EventScript_0x8162CB3
    checkflag 0x82C
    if 0x1 _call EventScript_0x8162CBC
    special 0x187
    compare LASTRESULT 0x2
    if 0x1 _goto 0x8162C68
    setflag 0x3
    setflag 0x5
    playsong2 0x138
    checkflag 0x844
    if 0x0 _call 0x8162C6F
    checkflag 0x844
    if 0x1 _call 0x8162C91
    setflag 0x4
    clearflag 0x5
    setflag 0x4BC
    setflag 0x4
    call RivalNameBox
    msgbox gText_League_RivalSpeak3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    playsong 0x159 0x0
    showsprite 0x2
    call OakNameBox
    msgbox gText_League_OakSpeak1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement PLAYER 0x8162D1F
    applymovement 0x1 0x8162D41
    applymovement 0x2 0x8162D2A
    waitmovement 0x0
    pause 0x19
    special2 LASTRESULT 0x162
    bufferpokemon 0x0 LASTRESULT
    call OakNameBox
    msgbox gText_League_OakSpeak2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x2 0x81A75EB
    applymovement 0x1 0x81A75E7
    waitmovement 0x0
    call OakNameBox
    msgbox gText_League_OakSpeak3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x2 0x81A75ED
    waitmovement 0x0
    pause 0x14
    call OakNameBox
    msgbox gText_League_OakSpeak4 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    pause 0xD
    applymovement 0x2 0x8162D37
    applymovement PLAYER 0x8162D12
    waitmovement 0x0
    setvar 0x4001 0x1
    setflag FLAG_MAY_LEAGUE_SPRITE
    warp 0x1 0x50 0xFF 0x5 0xC
    waitstate
    releaseall
    end

EventScript_0x8162CB3:
    call RivalNameBox
    msgbox gText_League_RivalSpeak1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    return

EventScript_0x8162CBC:
    call RivalNameBox
    msgbox gText_League_RivalSpeak2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    return

@@@@@@@@@@@@@@@@@@@@@@
@ Pokemon League Hall of Fame Room
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Legue_HallOfFameRoom:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_League_HallOfFameRoom
    mapscript MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE LevelScript2_League_HallOfFameRoom
    .byte MAP_SCRIPT_TERMIN

LevelScript_League_HallOfFameRoom:
    levelscript 0x4001, 0, EventScript_League_HallOfFameRoom
    .hword LEVEL_SCRIPT_TERMIN

LevelScript2_League_HallOfFameRoom:
    levelscript 0x4001, 0, EventScript2_League_HallOfFameRoom
    .hword LEVEL_SCRIPT_TERMIN

EventScript_League_HallOfFameRoom:
    lockall
    applymovement PLAYER 0x8162DCD
    waitmovement 0x0
    applymovement 0x1 0x81A75E7
    applymovement PLAYER 0x81A75EB
    waitmovement 0x0
    pause 0x12
    call OakNameBox
    msgbox gText_League_OakSpeak5 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x1 0x81A75E9
    applymovement PLAYER 0x81A75E9
    waitmovement 0x0
    pause 0x14
    doanimation 0x3E
    waitanimation 0x3E
    pause 0x28
    setvar 0x4001 0x1
    call 0x81A651A
    sethealingplace 0x1
    fadescreenspeed 0x1 0x18
    special 0x110
    waitstate
    releaseall
    end

EventScript2_League_HallOfFameRoom:
    spriteface 0xFF 0x2
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Pokemon League Duplicates
@@@@@@@@@@@@@@@@@@@@@@
EventScript_0x81A7506:
    applymovement PLAYER 0x81A75FE
    waitmovement 0x0
    sound 0x8
    call EventScript_0x81A7538
    special 0x8E
    setflag 0x4
    return

EventScript_0x81A7538:
    setmaptile 0x6 0x1 0x28E 0x1
    setmaptile 0x6 0x2 0x296 0x0
    return

@@@@@@@@@@@@@@@@@@@@@@
@ Pokemon League NameBox
@@@@@@@@@@@@@@@@@@@@@@
LanceNameBox:
    setvar 0x8000 22
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

MayNameBox:
    setvar 0x8000 2
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

RivalNameBox:
    setvar 0x8000 1
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

OakNameBox:
    setvar 0x8000 4
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

AgathaNameBox:
    setvar 0x8000 21
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

BrunoNameBox:
    setvar 0x8000 20
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

LoreleiNameBox:
    setvar 0x8000 19
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
