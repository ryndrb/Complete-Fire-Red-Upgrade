.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@
@ Rotom Encounter | Route 25 Bill's House
@@@@@@@@@@@@@@@@@@@@
EventScript_RotomEncounter:
    lock
    faceplayer
    msgbox gText_RotomEncounter MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EvenScript_End
    msgbox gText_PlayerThumpMachine MSG_NORMAL
    pause 30
    applymovement PLAYER EventScript_PlayerThump
    waitmovement 0x0
    pause 60
    applymovement PLAYER EventScript_PlayerThump
    waitmovement 0x0
    pause 30
    msgbox gText_RotomAppears MSG_KEEPOPEN
    cry SPECIES_ROTOM 0x0
    wildbattle SPECIES_ROTOM 25 0x0
    release
    end

EventScript_PlayerThump:
    .byte exclaim
    .byte end_m

EvenScript_End:
    release
    end

@@@@@@@@@@@@@@@@@@@@
@ Route 25 Bill
@@@@@@@@@@@@@@@@@@@@
EventScript_Route25_Bill:
    lock
    faceplayer
    checkflag 0x3
    if 0x1 _goto EventScript_0x81706C8
    checkflag 0x234
    if 0x1 _goto EventScript_0x8170640
    checkflag 0x233
    if 0x1 _goto EventScript_0x817064A
    checkgender
    compare LASTRESULT 0x0
    if 0x1 _goto EventScript_0x8170580
    compare LASTRESULT 0x1
    if 0x1 _goto EventScript_0x817058E
    end

EventScript_0x81706C8:
    call BillNameBox
    msgbox gText_Route25_BillSpeak1 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x8170640:
    call BillNameBox
    msgbox gText_Route25_BillSpeak2 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x817064A:
    setvar 0x8004 0xD
    setvar 0x8005 0x2
    special 0x174
    checkgender
    compare LASTRESULT 0x0
    if 0x1 _call EventScript_0x81706AC
    compare LASTRESULT 0x1
    if 0x1 _call EventScript_0x81706B5
    checkitemspace 0x109 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto EventScript_0x81706BE
    additem 0x109 0x1
    loadpointer 0x0 0x81A028E
    giveitemwithfanfare 0x109 0x1 0x13E
    setflag 0x235
    setflag 0x31
    setflag 0x234
    setflag 0x834
    goto 0x8170640

EventScript_0x8170580:
    call BillNameBoxUnknown
    msgbox gText_Route25_BillSpeak2 MSG_KEEPOPEN
    callasm RemoveNameBox
    call BillNameBoxUnknown
    msgbox gText_Route25_BillSpeak3 MSG_YESNO
    callasm RemoveNameBox
    goto EventScript_0x817059C

EventScript_0x817058E:
    call BillNameBox
    msgbox gText_Route25_BillSpeak2 MSG_KEEPOPEN
    callasm RemoveNameBox
    call BillNameBox
    msgbox gText_Route25_BillSpeak4 MSG_YESNO
    callasm RemoveNameBox
    goto EventScript_0x817059C

EventScript_0x81706AC:
    call BillNameBox
    msgbox gText_Route25_BillSpeak5 MSG_KEEPOPEN
    callasm RemoveNameBox
    return

EventScript_0x81706B5:
    call BillNameBox
    msgbox gText_Route25_BillSpeak6 MSG_KEEPOPEN
    callasm RemoveNameBox
    return

EventScript_0x81706BE:
    call BillNameBox
    msgbox 0x81A02B4 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x817059C:
    compare LASTRESULT 0x0
    if 0x1 _call EventScript_0x8170600
    call BillNameBox
    msgbox 0x819FFD3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    pause 0xA
    compare PLAYERFACING 0x1
    if 0x1 _call EventScript_0x817062A
    compare PLAYERFACING 0x2
    if 0x1 _call EventScript_0x8170635
    compare PLAYERFACING 0x3
    if 0x1 _call EventScript_0x8170635
    compare PLAYERFACING 0x4
    if 0x1 _call EventScript_0x8170635
    setdooropen 0xA 0x3
    opendoor 0xA 0x3
    waitdooranim
    applymovement 0x2 0x81706DB
    waitmovement 0x0
    hidesprite 0x2
    sound 0x5B
    setdoorclosed 0xA 0x3
    closedoor 0xA 0x3
    waitdooranim
    setflag 0x2
    release
    end

EventScript_0x8170600:
    checkgender
    compare LASTRESULT 0x0
    if 0x1 _call EventScript_0x8170618
    compare LASTRESULT 0x1
    if 0x1 _call EventScript_0x8170621
    return

EventScript_0x817062A:
    applymovement 0x2 0x81706D5
    waitmovement 0x0
    return

EventScript_0x8170635:
    applymovement 0x2 0x81706D2
    waitmovement 0x0
    return

EventScript_0x8170618:
    call BillNameBox
    msgbox 0x81A0035 MSG_KEEPOPEN
    callasm RemoveNameBox
    return

EventScript_0x8170621:
    call BillNameBox
    msgbox 0x81A00B6 MSG_KEEPOPEN
    callasm RemoveNameBox
    return

@@@@@@@@@@@@@@@@@@@@
@ Route 25 NameBox
@@@@@@@@@@@@@@@@@@@@
BillNameBox:
    setvar 0x8000 7
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

BillNameBoxUnknown:
    setvar 0x8000 0
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
