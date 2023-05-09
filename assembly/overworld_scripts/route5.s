.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ Traynee Services | Drayano inspired
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route5_Traynee:
    checkflag FLAG_TRAYNEE_ROUTE5_GREET
    if NOT_SET _goto EventScript_Route5_Traynee_Greet
    faceplayer
    npcmsg gText_Route5_Traynee_WhichToTrain MSG_KEEPOPEN 9 LEFT
    closemsg
    setvar 0x8000 0x12
    setvar 0x8001 0x6
    setvar 0x8004 0x0
    special 0x158
    waitstate
    compare LASTRESULT 0xA
    if greaterorequal _goto EventScript_Route5_Traynee_SeeYa
    switch LASTRESULT
    case 0, EventScript_Route5_Traynee_Exp
    case 1, EventScript_Route5_Traynee_ResetEv
    case 2, EventScript_Route5_Traynee_EvHP
    case 3, EventScript_Route5_Traynee_EvAttack
    case 4, EventScript_Route5_Traynee_EvDefense
    case 5, EventScript_Route5_Traynee_EvSpAttack
    case 6, EventScript_Route5_Traynee_EvSpDefense
    case 7, EventScript_Route5_Traynee_EvSpeed
    case 8, EventScript_Route5_Traynee_SeeYa
    end

EventScript_Route5_Traynee_Greet:
    faceplayer
    npcmsg gText_Route5_Traynee_Greet_1 MSG_KEEPOPEN 0 LEFT
    closemsg
    npcmsg gText_Route5_Traynee_Greet_2 MSG_KEEPOPEN 9 LEFT
    closemsg 
    setflag FLAG_TRAYNEE_ROUTE5_GREET
    release
    end

EventScript_Route5_Traynee_Exp:
    setflag FLAG_TRAYNEE_EXP_TRAINING_NO_EV
    npcmsg gText_Route5_Traynee_Exp MSG_KEEPOPEN 9 LEFT
    closemsg
    trainerbattle3 0x3 66 0x0 gText_Route5_Traynee_TrainingCompleted
    special 0x0
    clearflag FLAG_TRAYNEE_EXP_TRAINING_NO_EV
    release
    end

EventScript_Route5_Traynee_ResetEv:
    npcmsg gText_Route5_Traynee_WhichMonToReset MSG_KEEPOPEN 9 LEFT
    closemsg
    special 0x9F
    waitstate
    compare LASTRESULT 0x6
    if greaterorequal _goto EventScript_Route5_Traynee_SeeYa
    special2 LASTRESULT 0x147
	compare LASTRESULT 0x19C
	if equal _goto EventScript_Route5_Traynee_ThisIsAnEgg
    callasm ResetAllEVs
    pause 30
    copyvar 0x8003 0x0
    special 0x7C
    fanfare 0x13E
    waitfanfare
    npcmsg gText_Route5_Traynee_EVResetDone MSG_KEEPOPEN 9 LEFT
    closemsg
    release
    end

EventScript_Route5_Traynee_EvHP:
    setflag FLAG_TRAYNEE_HP_TEAM
    npcmsg gText_Route5_Traynee_EvHP MSG_KEEPOPEN 9 LEFT
    closemsg
    trainerbattle3 0x3 66 0x0 gText_Route5_Traynee_TrainingCompleted
    special 0x0
    clearflag FLAG_TRAYNEE_HP_TEAM
    release
    end

EventScript_Route5_Traynee_EvAttack:
    setflag FLAG_TRAYNEE_ATT_TEAM
    npcmsg gText_Route5_Traynee_EvAttack MSG_KEEPOPEN 9 LEFT
    closemsg
    trainerbattle3 0x3 66 0x0 gText_Route5_Traynee_TrainingCompleted
    special 0x0
    clearflag FLAG_TRAYNEE_ATT_TEAM
    release
    end

EventScript_Route5_Traynee_EvDefense:
    setflag FLAG_TRAYNEE_DEF_TEAM
    npcmsg gText_Route5_Traynee_EvDefense MSG_KEEPOPEN 9 LEFT
    closemsg
    trainerbattle3 0x3 66 0x0 gText_Route5_Traynee_TrainingCompleted
    special 0x0
    clearflag FLAG_TRAYNEE_DEF_TEAM
    release
    end

EventScript_Route5_Traynee_EvSpAttack:
    setflag FLAG_TRAYNEE_SPA_TEAM
    npcmsg gText_Route5_Traynee_EvSpAttack MSG_KEEPOPEN 9 LEFT
    closemsg
    trainerbattle3 0x3 66 0x0 gText_Route5_Traynee_TrainingCompleted
    special 0x0
    clearflag FLAG_TRAYNEE_SPA_TEAM
    release
    end

EventScript_Route5_Traynee_EvSpDefense:
    setflag FLAG_TRAYNEE_SPD_TEAM
    npcmsg gText_Route5_Traynee_EvSpDefense MSG_KEEPOPEN 9 LEFT
    closemsg
    trainerbattle3 0x3 66 0x0 gText_Route5_Traynee_TrainingCompleted
    special 0x0
    clearflag FLAG_TRAYNEE_SPD_TEAM
    release
    end

EventScript_Route5_Traynee_EvSpeed:
    setflag FLAG_TRAYNEE_SPE_TEAM
    npcmsg gText_Route5_Traynee_EvSpeed MSG_KEEPOPEN 9 LEFT
    closemsg
    trainerbattle3 0x3 66 0x0 gText_Route5_Traynee_TrainingCompleted
    special 0x0
    clearflag FLAG_TRAYNEE_SPE_TEAM
    release
    end

EventScript_Route5_Traynee_ThisIsAnEgg:
    npcmsg gText_Route5_ThisIsAnEgg MSG_KEEPOPEN 9 LEFT
    closemsg
    release
    end

EventScript_Route5_Traynee_SeeYa:
    npcmsg gText_Route5_Traynee_Seeya MSG_KEEPOPEN 9 LEFT
    closemsg
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Ivy Services
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route5_Ivy:
    checkflag FLAG_IVY_ROUTE5_GREET
    if NOT_SET _goto EventScript_Route5_Ivy_Greet
    faceplayer
    npcmsg gText_Route5_Ivy_WhatService MSG_KEEPOPEN 10 LEFT
    closemsg
    setvar 0x8000 0x15
    setvar 0x8001 0x4
    setvar 0x8004 0x0
    special 0x158
    waitstate
    compare LASTRESULT 0x4
    if greaterorequal _goto EventScript_Route5_Ivy_SeeYa
    switch LASTRESULT
    case 0, EventScript_Route5_Ivy_MaxAllIV
    case 1, EventScript_Route5_Ivy_ChangeIV
    case 2, EventScript_Route5_Ivy_ChangeHiddenPower
    case 3, EventScript_Route5_Ivy_SeeYa
    end

EventScript_Route5_Ivy_Greet:
    npcmsg gText_Route5_Ivy_Humming MSG_KEEPOPEN 0 LEFT
    closemsg
    sound 0x15
    applymovement 0x3 Move_Route5_Ivy_Startled
    waitmovement 0x3
    npcmsg gText_Route5_Ivy_Greet_1 MSG_KEEPOPEN 0 LEFT
    closemsg
    npcmsg gText_Route5_Ivy_Greet_2 MSG_KEEPOPEN 10 LEFT
    closemsg
    npcmsg gText_Route5_Ivy_Greet_3 MSG_KEEPOPEN 10 LEFT
    closemsg
    setflag FLAG_IVY_ROUTE5_GREET
    release
    end

EventScript_Route5_Ivy_MaxAllIV:
    npcmsg gText_Route5_Ivy_ChangeIVForWhichMon MSG_KEEPOPEN 10 LEFT
    closemsg
    call EventScript_Route5_ChoosePokemon
    npcmsg gText_Route5_Ivy_DoIVChange MSG_KEEPOPEN 10 LEFT
    closemsg
    fadescreen 0x1
    fanfare 0x13E
    waitfanfare
    fadescreen 0x0
    setvar 0x8008 0x1
    callasm ChangeIV
    npcmsg gText_Route5_Ivy_IVChanged MSG_KEEPOPEN 10 LEFT
    closemsg
    release
    end

EventScript_Route5_Ivy_ChangeIV:
    npcmsg gText_Route5_Ivy_ChangeIVForWhichMon MSG_KEEPOPEN 10 LEFT
    closemsg
    call EventScript_Route5_ChoosePokemon
    npcmsg gText_Route5_Ivy_WhichStatToChange MSG_KEEPOPEN 10 LEFT
    closemsg
    setvar 0x8000 0x13
    setvar 0x8001 0x6
    setvar 0x8004 0x0
    special 0x158
    waitstate
    copyvar 0x8006 LASTRESULT
    compare LASTRESULT 0x6
    if greaterorequal _goto EventScript_Route5_Ivy_SeeYa
    switch LASTRESULT
    case 0, EventScript_Route5_Ivy_ChooseIVAmount @hp
    case 1, EventScript_Route5_Ivy_ChooseIVAmount @att
    case 2, EventScript_Route5_Ivy_ChooseIVAmount @def
    case 3, EventScript_Route5_Ivy_ChooseIVAmount @spe
    case 4, EventScript_Route5_Ivy_ChooseIVAmount @spa
    case 5, EventScript_Route5_Ivy_ChooseIVAmount @spd
    end

EventScript_Route5_Ivy_ChooseIVAmount:
    npcmsg gText_Route5_Ivy_HowManyIvy MSG_KEEPOPEN 10 LEFT
    closemsg
    setvar 0x8000 0x16
    setvar 0x8001 0x6
    setvar 0x8004 0x0
    special 0x158
    waitstate
    copyvar 0x8007 LASTRESULT
    compare LASTRESULT 0x6
    if greaterorequal _goto EventScript_Route5_Ivy_SeeYa
    switch LASTRESULT
    case 0, EventScript_Route5_IvyCallIVFunc @0
    case 1, EventScript_Route5_IvyCallIVFunc @1
    case 2, EventScript_Route5_IvyCallIVFunc @14
    case 3, EventScript_Route5_IvyCallIVFunc @15
    case 4, EventScript_Route5_IvyCallIVFunc @30
    case 5, EventScript_Route5_IvyCallIVFunc @31
    return

EventScript_Route5_IvyCallIVFunc:
    npcmsg gText_Route5_Ivy_DoIVChange MSG_KEEPOPEN 10 LEFT
    closemsg
    fadescreen 0x1
    fanfare 0x13E
    waitfanfare
    fadescreen 0x0
    callasm ChangeIV
    npcmsg gText_Route5_Ivy_IVChanged MSG_KEEPOPEN 10 LEFT
    closemsg
    release
    end

EventScript_Route5_Ivy_ChangeHiddenPower:
    npcmsg gText_Route5_Ivy_ChangeHiddenPowerForWhichMon MSG_KEEPOPEN 10 LEFT
    closemsg
    call EventScript_Route5_ChoosePokemon
    npcmsg gText_Route5_Ivy_WhichHiddenPower MSG_KEEPOPEN 10 LEFT
    closemsg
    setvar 0x8000 0x17
    setvar 0x8001 0x6
    setvar 0x8004 0x0
    special 0x158
    waitstate
    copyvar 0x8006 LASTRESULT
    compare LASTRESULT 0x10
    if greaterorequal _goto EventScript_Route5_Ivy_SeeYa
    npcmsg gText_Route5_Ivy_DoIVChange MSG_KEEPOPEN 10 LEFT
    closemsg
    fadescreen 0x1
    fanfare 0x13E
    waitfanfare
    fadescreen 0x0
    callasm ChangeHiddenPower
    npcmsg gText_Route5_Ivy_IVChanged MSG_KEEPOPEN 10 LEFT
    closemsg
    release
    end

EventScript_Route5_ChoosePokemon:
    special 0x9F
    waitstate
    copyvar 0x8005 0x8004
    compare LASTRESULT 0x6
    if greaterorequal _goto EventScript_Route5_Ivy_SeeYa
    special2 LASTRESULT 0x147
	compare LASTRESULT 0x19C
	if equal _goto EventScript_Route5_Ivy_ThisIsAnEgg
    return

EventScript_Route5_Ivy_ThisIsAnEgg:
    npcmsg gText_Route5_ThisIsAnEgg MSG_KEEPOPEN 10 LEFT
    closemsg
    release
    end

EventScript_Route5_Ivy_SeeYa:
    npcmsg gText_Route5_Ivy_SeeYa MSG_KEEPOPEN 10 LEFT
    closemsg
    release
    end

Move_Route5_Ivy_Startled:
    .byte exclaim
    .byte pause_long
    .byte face_player
    .byte end_m
