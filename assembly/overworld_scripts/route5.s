.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_TRAYNEE_ROUTE5_GREET, 0x967
.equ FLAG_TRAYNEE_EXP_TRAINING_NO_EV, 0x968
.equ FLAG_TRAYNEE_HP_TEAM, 0x969
.equ FLAG_TRAYNEE_ATT_TEAM, 0x96A
.equ FLAG_TRAYNEE_DEF_TEAM, 0x96B
.equ FLAG_TRAYNEE_SPA_TEAM, 0x96C
.equ FLAG_TRAYNEE_SPD_TEAM, 0x96D
.equ FLAG_TRAYNEE_SPE_TEAM, 0x96E
.equ FLAG_IVY_ROUTE5_GREET, 0x96F
.equ FLAG_IVY_MAX_IVS, 0x970

@@@@@@@@@@@@@@@@@@@@@@
@ Traynee Services | Drayano inspired
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Traynee:
    textcolor RED
    checkflag FLAG_TRAYNEE_ROUTE5_GREET
    if NOT_SET _goto EventScipt_ExpLadyGreet
    faceplayer
    msgbox gText_ExpTrain MSG_KEEPOPEN
    setvar 0x8000 0x12
    setvar 0x8001 0x6
    setvar 0x8004 0x0
    special 0x158
    waitstate
    compare LASTRESULT 0xA
    if greaterorequal _goto EventScript_TrayneeSeeYa
    switch LASTRESULT
    case 0, EventScript_Exp
    case 1, EventScript_BuyEv
    case 2, EvetnScript_ResetEv
    case 3, EventScript_EvHP
    case 4, EventScript_EvAttack
    case 5, EventScript_EvDefense
    case 6, EventScript_EvSpAttack
    case 7, EventScript_EvSpDefense
    case 8, EventScript_EvSpeed
    case 9, EventScript_TrayneeSeeYa
    end

EventScipt_ExpLadyGreet:
    faceplayer
    msgbox gText_ExpLadyGreet MSG_KEEPOPEN
    setflag FLAG_TRAYNEE_ROUTE5_GREET
    release
    end

EventScript_Exp:
    setflag FLAG_TRAYNEE_EXP_TRAINING_NO_EV
    msgbox gText_Exp MSG_KEEPOPEN
    trainerbattle9 0x9 0x04 0x0 gText_TrainingCompleted gText_Dummy
    special 0x0
    clearflag FLAG_TRAYNEE_EXP_TRAINING_NO_EV
    release
    end

EventScript_BuyEv:
    msgbox gText_BuyForWhichMon MSG_KEEPOPEN
    special 0x9F
    waitstate
    copyvar 0x8005 0x8004
    compare LASTRESULT 0x6
    if greaterorequal _goto EventScript_TrayneeSeeYa
    special 0x148
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_ThisIsAnEggTraynee
    msgbox gText_WhichMonStat MSG_KEEPOPEN
    setvar 0x8000 0x13
    setvar 0x8001 0x6
    setvar 0x8004 0x0
    special 0x158
    waitstate
    copyvar 0x8006 LASTRESULT
    compare LASTRESULT 0x6
    if greaterorequal _goto EventScript_TrayneeSeeYa
    switch LASTRESULT
    case 0, EventScript_BuyHP
    case 1, EventScript_BuyAttack
    case 2, EventScript_BuyDefense
    case 3, EventScript_BuySpeed
    case 4, EventScript_BuySpAttack
    case 5, EventScript_BuySpDefense
    end

EventScript_BuyHP:
    msgbox gText_HowManyEV MSG_KEEPOPEN
    call EventScript_ChooseEVAmount
    end

EventScript_BuyAttack:
    msgbox gText_HowManyEV MSG_KEEPOPEN
    call EventScript_ChooseEVAmount
    end

EventScript_BuyDefense:
    msgbox gText_HowManyEV MSG_KEEPOPEN
    call EventScript_ChooseEVAmount
    end

EventScript_BuySpeed:
    msgbox gText_HowManyEV MSG_KEEPOPEN
    call EventScript_ChooseEVAmount
    end

EventScript_BuySpAttack:
    msgbox gText_HowManyEV MSG_KEEPOPEN
    call EventScript_ChooseEVAmount
    end

EventScript_BuySpDefense:
    msgbox gText_HowManyEV MSG_KEEPOPEN
    call EventScript_ChooseEVAmount
    end

EventScript_ChooseEVAmount:
    setvar 0x8000 0x14
    setvar 0x8001 0x6
    setvar 0x8004 0x0
    special 0x158
    waitstate
    compare LASTRESULT 0x6
    if greaterorequal _goto EventScript_TrayneeSeeYa
    switch LASTRESULT
    case 0, EventScript_4
    case 1, EventScript_8
    case 2, EventScript_12
    case 3, EventScript_64
    case 4, EventScript_128
    case 5, EventScript_252
    return

EventScript_4:
    setvar 0x8008 0x190
    buffernumber 0x0 0x8008
    checkmoney 0x190 0x00
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_NotEnoughMoney
    msgbox gText_AreYouSureToBuyTraynee MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_BuyEv
    removemoney 0x190 0x00
    msgbox gText_AllDone MSG_KEEPOPEN
    setvar 0x8007 0x4
    callasm AddEVsTraynee
    release
    end

EventScript_8:
    setvar 0x8008 0x320
    buffernumber 0x0 0x8008
    checkmoney 0x320 0x00
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_NotEnoughMoney
    msgbox gText_AreYouSureToBuyTraynee MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_BuyEv
    removemoney 0x320 0x00
    msgbox gText_AllDone MSG_KEEPOPEN
    setvar 0x8007 0x8
    callasm AddEVsTraynee
    release
    end

EventScript_12:
    setvar 0x8008 0x640
    buffernumber 0x0 0x8008
    checkmoney 0x640 0x00
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_NotEnoughMoney
    msgbox gText_AreYouSureToBuyTraynee MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_BuyEv
    removemoney 0x640 0x00
    msgbox gText_AllDone MSG_KEEPOPEN
    setvar 0x8007 0xC
    callasm AddEVsTraynee
    release
    end

EventScript_64:
    setvar 0x8008 0x1900
    buffernumber 0x0 0x8008
    checkmoney 0x1900 0x00
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_NotEnoughMoney
    msgbox gText_AreYouSureToBuyTraynee MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_BuyEv
    removemoney 0x1900 0x00
    msgbox gText_AllDone MSG_KEEPOPEN
    setvar 0x8007 0x40
    callasm AddEVsTraynee
    release
    end

EventScript_128:
    setvar 0x8008 0x3200
    buffernumber 0x0 0x8008
    checkmoney 0x3200 0x00
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_NotEnoughMoney
    msgbox gText_AreYouSureToBuyTraynee MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_BuyEv
    removemoney 0x3200 0x00
    msgbox gText_AllDone MSG_KEEPOPEN
    setvar 0x8007 0x80
    callasm AddEVsTraynee
    release
    end

EventScript_252:
    setvar 0x8008 0x6270
    buffernumber 0x0 0x8008
    checkmoney 0x6270 0x00
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_NotEnoughMoney
    msgbox gText_AreYouSureToBuyTraynee MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_BuyEv
    removemoney 0x6270 0x00
    msgbox gText_AllDone MSG_KEEPOPEN
    setvar 0x8007 0xFC
    callasm AddEVsTraynee
    release
    end

EventScript_NotEnoughMoney:
    msgbox gText_NotEnoughMoney MSG_KEEPOPEN
    release
    end

EventScript_EvHP:
    setflag FLAG_TRAYNEE_HP_TEAM
    msgbox gText_Hp MSG_KEEPOPEN
    trainerbattle9 0x9 0x04 0x0 gText_TrainingCompleted gText_Dummy
    special 0x0
    clearflag FLAG_TRAYNEE_HP_TEAM
    release
    end

EventScript_EvAttack:
    setflag FLAG_TRAYNEE_ATT_TEAM
    msgbox gText_Attack MSG_KEEPOPEN
    trainerbattle9 0x9 0x04 0x0 gText_TrainingCompleted gText_Dummy
    special 0x0
    clearflag FLAG_TRAYNEE_ATT_TEAM
    release
    end

EventScript_EvDefense:
    setflag FLAG_TRAYNEE_DEF_TEAM
    msgbox gText_Defense MSG_KEEPOPEN
    trainerbattle9 0x9 0x04 0x0 gText_TrainingCompleted gText_Dummy
    special 0x0
    clearflag FLAG_TRAYNEE_DEF_TEAM
    release
    end

EventScript_EvSpAttack:
    setflag FLAG_TRAYNEE_SPA_TEAM
    msgbox gText_SpAttack MSG_KEEPOPEN
    trainerbattle9 0x9 0x04 0x0 gText_TrainingCompleted gText_Dummy
    special 0x0
    clearflag FLAG_TRAYNEE_SPA_TEAM
    release
    end

EventScript_EvSpDefense:
    setflag FLAG_TRAYNEE_SPD_TEAM
    msgbox gText_SpDefense MSG_KEEPOPEN
    trainerbattle9 0x9 0x04 0x0 gText_TrainingCompleted gText_Dummy
    special 0x0
    clearflag FLAG_TRAYNEE_SPD_TEAM
    release
    end

EventScript_EvSpeed:
    setflag FLAG_TRAYNEE_SPE_TEAM
    msgbox gText_Speed MSG_KEEPOPEN
    trainerbattle9 0x9 0x04 0x0 gText_TrainingCompleted gText_Dummy
    special 0x0
    clearflag FLAG_TRAYNEE_SPE_TEAM
    release
    end

EvetnScript_ResetEv:
    msgbox gText_ResetEV MSG_KEEPOPEN
    special 0x9F
    waitstate
    compare LASTRESULT 0x6
    if greaterorequal _goto EventScript_TrayneeSeeYa
    special 0x148
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_ThisIsAnEggTraynee
    callasm ResetAllEVs
    copyvar 0x8003 0x0
    special 0x7C
    msgbox gText_EVReset MSG_KEEPOPEN
    release
    end

EventScript_TrayneeSeeYa:
    msgbox gText_TrayneeSeeYa MSG_KEEPOPEN
    release
    end

EventScript_ThisIsAnEggTraynee:
    msgbox gText_ThisIsAnEggTraynee MSG_KEEPOPEN
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Ivy Services
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Ivy:
    textcolor RED
    checkflag FLAG_IVY_ROUTE5_GREET
    if NOT_SET _goto EventScript_IvyGreet
    faceplayer
    msgbox gText_IvyService MSG_KEEPOPEN
    setvar 0x8000 0x15
    setvar 0x8001 0x4
    setvar 0x8004 0x0
    special 0x158
    waitstate
    compare LASTRESULT 0x4
    if greaterorequal _goto EventScript_TrayneeSeeYa
    switch LASTRESULT
    case 0, EventScript_MaxAllIV
    case 1, EventScript_ChangeIV
    case 2, EventScript_ChangeHiddenPower
    case 3, EventScript_TrayneeSeeYa
    end

EventScript_IvyGreet:
    msgbox gText_IvyHumming MSG_KEEPOPEN
    applymovement 0x3 EventScript_IvyExclaim
    waitmovement 0x3
    faceplayer
    msgbox gText_IvyGreet MSG_KEEPOPEN
    setflag FLAG_IVY_ROUTE5_GREET
    release
    end

EventScript_MaxAllIV:
    msgbox gText_ChangeIVForWhichMon MSG_KEEPOPEN
    call EventScript_ChoosePokemon
    setvar 0x8008 0xEA60
    buffernumber 0x0 0x8008
    checkmoney 0xEA60 0x00
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_NotEnoughMoney
    msgbox gText_AreYouSureToBuyIvy MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_TrayneeSeeYa
    removemoney 0xEA60 0x00
    msgbox gText_IVChanging MSG_KEEPOPEN
    fadescreen 0x1
    pause 60
    fadescreen 0x0
    setflag FLAG_IVY_MAX_IVS
    callasm ChangeIV
    clearflag FLAG_IVY_MAX_IVS
    copyvar 0x8004 0x8005
    copyvar 0x8003 0x0
    special 0x7C
    msgbox gText_IVChanged MSG_KEEPOPEN
    release
    end

EventScript_ChangeIV:
    msgbox gText_ChangeIVForWhichMon MSG_KEEPOPEN
    call EventScript_ChoosePokemon
    setvar 0x8003 0x0
    special 0x7C
    msgbox gText_WhichStatToChangeIV MSG_KEEPOPEN
    setvar 0x8000 0x13
    setvar 0x8001 0x6
    setvar 0x8004 0x0
    special 0x158
    waitstate
    copyvar 0x8006 LASTRESULT
    compare LASTRESULT 0x6
    if greaterorequal _goto EventScript_TrayneeSeeYa
    switch LASTRESULT
    case 0, EventScript_ChooseIVAmount @hp
    case 1, EventScript_ChooseIVAmount @att
    case 2, EventScript_ChooseIVAmount @def
    case 3, EventScript_ChooseIVAmount @spe
    case 4, EventScript_ChooseIVAmount @spa
    case 5, EventScript_ChooseIVAmount @spd
    end

EventScript_ChooseIVAmount:
    msgbox gText_HowManyIvy MSG_KEEPOPEN
    setvar 0x8000 0x16
    setvar 0x8001 0x6
    setvar 0x8004 0x0
    special 0x158
    waitstate
    copyvar 0x8007 LASTRESULT
    compare LASTRESULT 0x6
    if greaterorequal _goto EventScript_TrayneeSeeYa
    switch LASTRESULT
    case 0, EventScript_CallIVFunc @0
    case 1, EventScript_CallIVFunc @1
    case 2, EventScript_CallIVFunc @14
    case 3, EventScript_CallIVFunc @15
    case 4, EventScript_CallIVFunc @30
    case 5, EventScript_CallIVFunc @31
    return

EventScript_CallIVFunc:
    setvar 0x8008 0x2710
    buffernumber 0x0 0x8008
    checkmoney 0x2710 0x00
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_NotEnoughMoney
    msgbox gText_AreYouSureToBuyIvy MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_TrayneeSeeYa
    removemoney 0x2710 0x00
    msgbox gText_IVChanging MSG_KEEPOPEN
    fadescreen 0x1
    pause 60
    fadescreen 0x0
    callasm ChangeIV
    copyvar 0x8004 0x8005
    copyvar 0x8003 0x0
    special 0x7C
    msgbox gText_IVChanged MSG_KEEPOPEN
    release
    end

EventScript_ChangeHiddenPower:
    msgbox gText_ChangeHiddenPowerForWhichMon MSG_KEEPOPEN
    call EventScript_ChoosePokemon
    msgbox gText_WhichHiddenPower MSG_KEEPOPEN
    setvar 0x8000 0x17
    setvar 0x8001 0x6
    setvar 0x8004 0x0
    special 0x158
    waitstate
    copyvar 0x8006 LASTRESULT
    compare LASTRESULT 0x10
    if greaterorequal _goto EventScript_TrayneeSeeYa
    setvar 0x8008 0xC350
    buffernumber 0x0 0x8008
    checkmoney 0xC350 0x00
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_NotEnoughMoney
    msgbox gText_AreYouSureToBuyIvy MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_TrayneeSeeYa
    removemoney 0xC350 0x00
    msgbox gText_IVChanging MSG_KEEPOPEN
    fadescreen 0x1
    pause 60
    fadescreen 0x0
    callasm ChangeHiddenPower
    copyvar 0x8004 0x8005
    copyvar 0x8003 0x0
    special 0x7C
    msgbox gText_IVChanged MSG_KEEPOPEN
    release
    end

EventScript_ChoosePokemon:
    special 0x9F
    waitstate
    copyvar 0x8005 0x8004
    compare LASTRESULT 0x6
    if greaterorequal _goto EventScript_TrayneeSeeYa
    special 0x148
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_ThisIsAnEggTraynee
    return

EventScript_IvyExclaim:
    .byte exclaim
    .byte end_m
