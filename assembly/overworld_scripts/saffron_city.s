.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_ALAKAZITE, 0x960
.equ FLAG_OBTAIN_DRAIN_PUNCH, 0x981
.equ FLAG_OBTAIN_SLEEP_TALK, 0x980

@@@@@@@@@@@@@@@@@@@@@@
@ Sabrina
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymLeaderSabrina:
    setvar 0x8004 0x7
    setvar 0x8005 0x2
    special 0x174
    call SabrinaNameBox
    trainerbattle1 0x1 0x1A4 0x0 0x819B53C 0x819B602 EventScript_0x816EE0A
    checkflag 0x29A
    if 0x0 _goto 0x816EE3D
    call SabrinaNameBox
    msgbox 0x819B7F2 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x816EE0A:
    setvar 0x8004 0x7
    setvar 0x8005 0x2
    special 0x173
    setvar 0x8004 0x7
    setvar 0x8005 0x3
    special 0x173
    clearflag 0xAE
    setflag 0x4B5
    setflag 0x825
    clearflag 0x035
    setvar 0x8008 0x6
    call 0x81A6B18
    goto EventScript_0x816EE3D
    end

EventScript_0x816EE3D:
    call SabrinaNameBox
    msgbox 0x819B6FA MSG_KEEPOPEN
    callasm RemoveNameBox
    checkitemspace 0x124 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816EE7E
    giveitem_msg 0x819B7D3 ITEM_TM04
    setflag 0x29A
    call SabrinaNameBox
    msgbox 0x819B685 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Alakazite | Saffron City | Gym Guy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymGuyAlakazite:
    lock
    faceplayer
    checkflag 0x4B5
    if 0x1 _goto EventScript_GiveAlakazite
    msgbox 0x8191298 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x816A689
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816A697
    end

EventScript_GiveAlakazite:
    checkflag FLAG_OBTAIN_ALAKAZITE
    if 0x1 _goto Obtained
    msgbox gText_GymGuyGiveStone MSG_KEEPOPEN
    giveitem ITEM_ALAKAZITE 0x1 MSG_OBTAIN
    bufferitem 0x0 ITEM_ALAKAZITE
    bufferpokemon 0x1 SPECIES_ALAKAZAM
    msgbox gText_ObtainedStone MSG_KEEPOPEN
    setflag FLAG_OBTAIN_ALAKAZITE
    release
    end

Obtained:
    goto 0x816A67F
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Drain Punch | Saffron City Desk Lady
@@@@@@@@@@@@@@@@@@@@@@
EventScipt_SaffronDrainPunch:
    textcolor RED
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
    textcolor BLUE
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

@@@@@@@@@@@@@@@@@@@@@@
@ Saffron Rival
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Saffron_Rival0:
    lockall
    setvar 0x4001 0x0
    goto EventScript_0x81619D4

EventScript_Saffron_Rival1:
    lockall
    setvar 0x4001 0x1
    goto EventScript_0x81619D4

EventScript_0x81619D4:
    textcolor 0x0
    playsong 0x13B 0x0
    applymovement 0x1 0x81A75DB
    waitmovement 0x0
    applymovement PLAYER 0x81A75ED
    applymovement 0x1 0x81A75DD
    waitmovement 0x0
    msgbox gText_Saffron_RivalSpeak1 MSG_KEEPOPEN
    compare 0x4001 0x0
    if 0x1 _call 0x8161A73
    compare 0x4001 0x1
    if 0x1 _call 0x8161A7F
    msgbox gText_Saffron_RivalSpeak2 MSG_KEEPOPEN
    setvar LASTTALKED 0x1
    compare 0x4031 0x2
    if 0x1 _call 0x8161A80
    compare 0x4031 0x1
    if 0x1 _call 0x8161A8B
    compare 0x4031 0x0
    if 0x1 _call 0x8161A96
    msgbox gText_Saffron_RivalSpeak3 MSG_KEEPOPEN
    closeonkeypress
    playsong 0x13C 0x0
    compare 0x4001 0x0
    if 0x1 _call 0x8161AA1
    compare 0x4001 0x1
    if 0x1 _call 0x8161AAC
    sound 0x27
    fadedefault
    hidesprite 0x1
    checksound
    setvar 0x405C 0x1
    releaseall
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Saffron Giovanni
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Saffron_Giovanni0:
    lockall
    setvar 0x4001 0x0
    goto EventScript_0x8161EA0

EventScript_Saffron_Giovanni1:
    lockall
    setvar 0x4001 0x1
    goto EventScript_0x8161EA0

EventScript_0x8161EA0:
    textcolor 0x0
    applymovement 0x3 0x81A75ED
    waitmovement 0x0
    pause 0x19
    call GiovanniNameBox
    msgbox 0x8177108 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    compare 0x4001 0x0
    if 0x1 _call 0x8161F00
    compare 0x4001 0x1
    if 0x1 _call 0x8161F12
    setvar LASTTALKED 0x3
    trainerbattle3 0x3 0x15D 0x0 0x81771AB
    call GiovanniNameBox
    msgbox 0x81771C2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    fadescreen 0x1
    hidesprite 0x3
    hidesprite 0x4
    hidesprite 0x6
    fadescreen 0x0
    setvar 0x4060 0x1
    setflag 0x3E
    clearflag 0x3F
    releaseall
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Saffron NameBox
@@@@@@@@@@@@@@@@@@@@@@
RivalNameBox:
    setvar 0x8000 1
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

GiovanniNameBox:
    setvar 0x8000 1
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

SabrinaNameBox:
    setvar 0x8000 15
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
