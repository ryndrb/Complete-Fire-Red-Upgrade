.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ One Island Inside Poke Center
@@@@@@@@@@@@@@@@@@@@@@
EventScript_OneIsland_PokeCenter_Event0:
    lockall
    setvar 0x4001 0x1
    goto EventScript_0x81711DA

EventScript_OneIsland_PokeCenter_Event1:
    lockall
    setvar 0x4001 0x2
    goto EventScript_0x81711DA

EventScript_OneIsland_PokeCenter_Event2:
    lockall
    setvar 0x4001 0x3
    goto EventScript_0x81711DA

EventScript_OneIsland_PokeCenter_Event3:
    lockall
    setvar 0x4001 0x4
    goto EventScript_0x81711DA

EventScript_0x81711DA:
    textcolor BLUE
    sound 0x15
    applymovement 0x2 0x81A75DB
    waitmovement 0x0
    call BillNameBox
    msgbox gText_Oneisland_PokeCenter_Event_Bill_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    compare 0x4001 0x1
    if 0x1 _call EventScript_0x81712E4
    compare 0x4001 0x2
    if 0x1 _call EventScript_0x81712EF
    compare 0x4001 0x3
    if 0x1 _call EventScript_0x81712FA
    compare 0x4001 0x4
    if 0x1 _call EventScript_0x8171305
    pause 0xA
    call BillNameBox
    msgbox gText_Oneisland_PokeCenter_Event_Bill_Speak_2 MSG_KEEPOPEN
    callasm RemoveNameBox
    applymovement PLAYER 0x81A75ED
    waitmovement 0x0
    call CelioNameBox
    msgbox gText_Oneisland_PokeCenter_Event_Celio_Speak_1 MSG_KEEPOPEN
    callasm RemoveNameBox
    applymovement 0x2 0x81A75ED
    waitmovement 0x0
    applymovement 0x3 0x81A75E9
    waitmovement 0x0
    call BillNameBox
    msgbox gText_Oneisland_PokeCenter_Event_Bill_Speak_3 MSG_KEEPOPEN
    callasm RemoveNameBox
    call CelioNameBox
    msgbox gText_Oneisland_PokeCenter_Event_Celio_Speak_2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x2 0x81A75E7
    waitmovement 0x0
    pause 0xA
    applymovement PLAYER 0x81A75EB
    waitmovement 0x0
    pause 0xF
    call BillNameBox
    msgbox gText_Oneisland_PokeCenter_Event_Bill_Speak_4 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x2 0x81A75ED
    waitmovement 0x0
    pause 0xF
    applymovement 0x3 0x81A75E7
    waitmovement 0x0
    applymovement PLAYER 0x81A75ED
    waitmovement 0x0
    call CelioNameBox
    msgbox gText_Oneisland_PokeCenter_Event_Celio_Speak_3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    pause 0x19
    applymovement PLAYER 0x8171326
    applymovement 0x2 0x817132D
    waitmovement 0x0
    sound 0x9
    setflag 0x72
    setvar 0x4076 0x3
    clearflag 0x62
    setvar 0x4071 0x3
    setvar 0x8004 0x1
    setvar 0x8006 0x8
    goto EventScript_0x81A90DA

EventScript_0x81712E4:
    applymovement PLAYER 0x8171310
    waitmovement 0x0
    return

EventScript_0x81712EF:
    applymovement PLAYER 0x8171314
    waitmovement 0x0
    return

EventScript_0x81712FA:
    applymovement PLAYER 0x8171316
    waitmovement 0x0
    return

EventScript_0x8171305:
    applymovement PLAYER 0x817131A
    waitmovement 0x0
    return

EventScript_0x81A90DA:
    closeonkeypress
    pause 0x14
    @special 0x187
    @compare LASTRESULT 0x2
    @if 0x1 _goto EventScript_0x81A7AE0
    @special 0x188
    @fadescreen 0x1
    warp 3 8 PLAYER 0x1D 0x26
    waitstate
    @special 0x17B
    @waitstate
    end

EventScript_0x81A7AE0:
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Cinnabar NameBox
@@@@@@@@@@@@@@@@@@@@@@
BillNameBox:
    setvar 0x8000 7
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

CelioNameBox:
    setvar 0x8000 27
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
