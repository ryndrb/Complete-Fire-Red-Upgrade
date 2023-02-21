.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_DRAIN_PUNCH, 0x0D6
.equ FLAG_OBTAIN_SLEEP_TALK, 0x0DB

@@@@@@@@@@@@@@@@@@@@@@
@ Drain Punch | Saffron City Desk Lady
@@@@@@@@@@@@@@@@@@@@@@
EventScipt_SaffronDrainPunch:
    textcolor 0x1
    lock
    faceplayer
    checkflag FLAG_OBTAIN_DRAIN_PUNCH
    if 0x0 _goto EventScript_GiveDrainPunch
    msgbox 0x81754F7 MSG_FACE
    end 

EventScript_GiveDrainPunch:
    msgbox gText_GiveDrainPunchQuestion MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_TooBad
    msgbox gText_GiveDrainPunchAccept MSG_KEEPOPEN
    giveitem ITEM_TM60 0x1 MSG_OBTAIN
    setflag FLAG_OBTAIN_DRAIN_PUNCH
    release
    end

EventScript_TooBad:
    msgbox gText_TooBad MSG_KEEPOPEN
    closeonkeypress
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Sleep Talk | Saffron City
@@@@@@@@@@@@@@@@@@@@@@
EventScript_SaffronSleepTalk:
    textcolor 0x0
    lock
    checkflag FLAG_OBTAIN_SLEEP_TALK
    if 0x0 _goto EventScript_GiveSleepTalk
    msgbox gText_SleepTalkObtained MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_GiveSleepTalk:
    msgbox gText_GiveSleepTalk MSG_KEEPOPEN
    giveitem ITEM_TM82 0x1 MSG_OBTAIN
    setflag FLAG_OBTAIN_SLEEP_TALK
    closeonkeypress
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Elevator Saffron
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Elevator:
    lockall
    setvar 0x8004 0x1
    checkflag 0x2
    if 0x0 _call EventScript_0x81A7AB9
    copyvar 0x8005 0x403A
    special 0x132
    preparemsg 0x81A535C
    waitmsg
    setvar 0x8000 0x18
    setvar 0x8001 0x6
    setvar 0x8004 0x0
    special 0x158
    waitstate
    compare LASTRESULT 0xC
    if greaterorequal _goto EventScript_ElevatorExit
    switch LASTRESULT
    case 0, EventScript_11Floor
    case 1, EventScript_10Floor
    case 2, EventScript_9Floor
    case 3, EventScript_8Floor
    case 4, EventScript_7Floor
    case 5, EventScript_6Floor
    case 6, EventScript_5Floor
    case 7, EventScript_4Floor
    case 8, EventScript_3Floor
    case 9, EventScript_2Floor
    case 10, EventScript_1Floor
    case 11, EventScript_ElevatorExit
    end

EventScript_0x81A7AB9:
    special 0xD8
    return

 EventScript_11Floor:
    setvar 0x8006 0xE
    setdynamicwarp 0x1 0x39 0xFF 0xD 0x3
    compare 0x403A 0xE
    if 0x1 _goto EventScript_ElevatorExit
    call EventScript_ElevatorAnim
    setvar 0x403A 0xE
    goto EventScript_ElevatorExit

EventScript_10Floor:
    setvar 0x8006 0xD
    setdynamicwarp 0x1 0x38 0xFF 0xD 0x3
    compare 0x403A 0xD
    if 0x1 _goto EventScript_ElevatorExit
    call EventScript_ElevatorAnim
    setvar 0x403A 0xD
    goto EventScript_ElevatorExit

EventScript_9Floor:
    setvar 0x8006 0xC
    setdynamicwarp 0x1 0x37 0xFF 0x18 0x3
    compare 0x403A 0xC
    if 0x1 _goto EventScript_ElevatorExit
    call EventScript_ElevatorAnim
    setvar 0x403A 0xC
    goto EventScript_ElevatorExit

EventScript_8Floor:
    setvar 0x8006 0xB
    setdynamicwarp 0x1 0x36 0xFF 0x16 0x3
    compare 0x403A 0xB
    if 0x1 _goto EventScript_ElevatorExit
    call EventScript_ElevatorAnim
    setvar 0x403A 0xB
    goto EventScript_ElevatorExit

EventScript_7Floor:
    setvar 0x8006 0xA
    setdynamicwarp 0x1 0x35 0xFF 0x17 0x3
    compare 0x403A 0xA
    if 0x1 _goto EventScript_ElevatorExit
    call EventScript_ElevatorAnim
    setvar 0x403A 0xA
    goto EventScript_ElevatorExit

EventScript_6Floor:
    setvar 0x8006 0x9
    setdynamicwarp 0x1 0x34 0xFF 0x14 0x3
    compare 0x403A 0x9
    if 0x1 _goto EventScript_ElevatorExit
    call EventScript_ElevatorAnim
    setvar 0x403A 0x9
    goto EventScript_ElevatorExit

EventScript_5Floor:
    setvar 0x8006 0x8
    setdynamicwarp 0x1 0x33 0xFF 0x16 0x3
    compare 0x403A 0x8
    if 0x1 _goto EventScript_ElevatorExit
    call EventScript_ElevatorAnim
    setvar 0x403A 0x8
    goto EventScript_ElevatorExit

EventScript_4Floor:
    setvar 0x8006 0x7
    setdynamicwarp 0x1 0x32 0xFF 0x16 0x3
    compare 0x403A 0x7
    if 0x1 _goto EventScript_ElevatorExit
    call EventScript_ElevatorAnim
    setvar 0x403A 0x7
    goto EventScript_ElevatorExit

EventScript_3Floor:
    setvar 0x8006 0x6
    setdynamicwarp 0x1 0x31 0xFF 0x16 0x3
    compare 0x403A 0x6
    if 0x1 _goto EventScript_ElevatorExit
    call EventScript_ElevatorAnim
    setvar 0x403A 0x6
    goto EventScript_ElevatorExit

EventScript_2Floor:
    setvar 0x8006 0x5
    setdynamicwarp 0x1 0x30 0xFF 0x16 0x3
    compare 0x403A 0x5
    if 0x1 _goto EventScript_ElevatorExit
    call EventScript_ElevatorAnim
    setvar 0x403A 0x5
    goto EventScript_ElevatorExit

EventScript_1Floor:
    setvar 0x8006 0x4
    setdynamicwarp 0x1 0x2F 0xFF 0x16 0x3
    compare 0x403A 0x4
    if 0x1 _goto EventScript_ElevatorExit
    call EventScript_ElevatorAnim
    setvar 0x403A 0x4
    goto EventScript_ElevatorExit

EventScript_ElevatorExit:
    special 0x160
    releaseall
    end

EventScript_ElevatorAnim:
    special 0x160
    closeonkeypress
    checksound
    special 0x111
    waitstate
    setflag 0x2
    return
