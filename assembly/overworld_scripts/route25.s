.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ BILL_CLEF, 0x2
.equ JESSIE, 0x3
.equ MEOWTH, 0x4
.equ JAMES, 0x5

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
    goto EventScript_0x8170640

EventScript_0x8170580:
    call BillNameBoxUnknown
    msgbox gText_Route25_BillSpeak2 MSG_KEEPOPEN
    callasm RemoveNameBox
    call BillNameBoxUnknown
    msgbox gText_Route25_BillSpeak3 MSG_KEEPOPEN
    callasm RemoveNameBox
    closeonkeypress
    call EventScript_Route25_RocketGang
    npcmsg gText_Route25_BillSpeak7 MSG_YESNO 7 LEFT
    closeonkeypress
    goto EventScript_0x817059C

EventScript_0x817058E:
    call BillNameBox
    msgbox gText_Route25_BillSpeak2 MSG_KEEPOPEN
    callasm RemoveNameBox
    call BillNameBox
    msgbox gText_Route25_BillSpeak4 MSG_YESNO
    callasm RemoveNameBox
    closeonkeypress
    call EventScript_Route25_RocketGang
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

EventScript_Route25_RocketGang:
    lock
    pause 30
    sound 0x15
    applymovement PLAYER Move_Route25_RocketGang_Player_1
    applymovement BILL_CLEF Move_Route25_RocketGang_Bill_1
    waitmovement BILL_CLEF
    fadescreen 0x1
    movesprite PLAYER 7 6
    movesprite BILL_CLEF 8 6
    pause 30
    fadescreen 0x0
    call EventScript_Route25_RocketGang_PositionCamera
    sound 0x9
    showsprite JESSIE
    applymovement JESSIE Move_Route25_RocketGang_Jessie_3
    waitmovement JESSIE
    sound 0x9
    showsprite JAMES
    applymovement JAMES Move_Route25_RocketGang_James_3
    waitmovement JAMES
    sound 0x9
    showsprite MEOWTH
    applymovement MEOWTH Move_Route25_RocketGang_Meowth_4
    waitmovement MEOWTH
    playsong 0x184 0x1
    npcmsg gText_Route25_RocketGang_Jessie_Speak_1 MSG_KEEPOPEN 29 LEFT
    closemsg
    npcmsg gText_Route25_RocketGang_James_Speak_1 MSG_KEEPOPEN 30 LEFT
    closemsg
    spriteface JESSIE LEFT
    npcmsg gText_Route25_RocketGang_Jessie_Speak_2 MSG_KEEPOPEN 29 LEFT
    closemsg
    spriteface JAMES RIGHT
    npcmsg gText_Route25_RocketGang_James_Speak_2 MSG_KEEPOPEN 30 LEFT
    closemsg
    spriteface JESSIE DOWN
    npcmsg gText_Route25_RocketGang_Jessie_Speak_3 MSG_KEEPOPEN 29 LEFT
    closemsg
    spriteface JAMES DOWN
    npcmsg gText_Route25_RocketGang_James_Speak_3 MSG_KEEPOPEN 30 LEFT
    closemsg
    sound 0x79
    spriteface JESSIE UP
    npcmsg gText_Route25_RocketGang_Jessie_Speak_4 MSG_KEEPOPEN 29 LEFT
    closemsg
    sound 0x79
    spriteface JAMES UP
    npcmsg gText_Route25_RocketGang_James_Speak_4 MSG_KEEPOPEN 30 LEFT
    closemsg
    npcmsg gText_Route25_RocketGang_Jessie_Speak_5 MSG_KEEPOPEN 29 LEFT
    closemsg
    npcmsg gText_Route25_RocketGang_James_Speak_5 MSG_KEEPOPEN 30 LEFT
    closemsg
    applymovement MEOWTH Move_Route25_RocketGang_Meowth_5
    waitmovement MEOWTH
    npcmsg gText_Route25_RocketGang_Meowth_Speak_1 MSG_KEEPOPEN 31 LEFT
    closemsg
    sound 0x15
    applymovement JESSIE Move_Route25_RocketGang_Jessie_1
    applymovement MEOWTH Move_Route25_RocketGang_Meowth_1
    applymovement JAMES Move_Route25_RocketGang_James_1
    waitmovement JAMES
    pause 30
    npcmsg gText_Route25_RocketGang_Jessie_Speak_6 MSG_KEEPOPEN 29 LEFT
    closemsg
    pause 30
    spriteface JESSIE RIGHT
    spriteface MEOWTH RIGHT
    spriteface JAMES LEFT
    npcmsg gText_Route25_RocketGang_James_Speak_6 MSG_KEEPOPEN 30 LEFT
    closemsg
    npcmsg gText_Route25_RocketGang_Meowth_Speak_2 MSG_KEEPOPEN 31 LEFT
    closemsg
    npcmsg gText_Route25_RocketGang_Bill_Speak_1 MSG_KEEPOPEN 7 LEFT
    closemsg
    pause 30
    spriteface BILL_CLEF, LEFT
    spriteface PLAYER, RIGHT
    spriteface JESSIE UP
    spriteface MEOWTH UP
    spriteface JAMES UP
    npcmsg gText_Route25_RocketGang_Bill_Speak_2 MSG_KEEPOPEN 7 LEFT
    closemsg
    pause 30
    spriteface BILL_CLEF, DOWN
    spriteface PLAYER, DOWN
    sound 0x15
    applymovement BILL_CLEF Move_Route25_RocketGang_Bill_1
    waitmovement BILL_CLEF
    npcmsg gText_Route25_RocketGang_Bill_Speak_3 MSG_KEEPOPEN 7 LEFT
    closemsg
    spriteface BILL_CLEF, LEFT
    spriteface PLAYER, RIGHT
    npcmsg gText_Route25_RocketGang_Bill_Speak_4 MSG_KEEPOPEN 7 LEFT
    closemsg
    spriteface BILL_CLEF, DOWN
    spriteface PLAYER, DOWN
    npcmsg gText_Route25_RocketGang_Jessie_Speak_7 MSG_KEEPOPEN 29 LEFT
    closemsg
    npcmsg gText_Route25_RocketGang_Meowth_Speak_3 MSG_KEEPOPEN 31 LEFT
    closemsg
    pause 30
    applymovement MEOWTH Move_Route25_RocketGang_Meowth_2
    waitmovement MEOWTH
    npcmsg gText_Route25_RocketGang_Bill_Speak_5 MSG_KEEPOPEN 7 LEFT
    closemsg
    applymovement MEOWTH Move_Route25_RocketGang_Meowth_3
    applymovement BILL_CLEF Move_Route25_RocketGang_Bill_2
    waitmovement MEOWTH
    special 0x113
    applymovement CAMERA Move_Route25_RocketGang_Camera_BackToPlayer
    applymovement JESSIE Move_Route25_RocketGang_Jessie_2
    applymovement JAMES Move_Route25_RocketGang_James_2
    waitmovement CAMERA
    special 0x114
    npcmsg gText_Route25_RocketGang_James_Speak_7 MSG_KEEPOPEN 30 LEFT
    closemsg
    trainerbattle3 0x3 10 0x0 gText_Route25_RocketGang_Defeat
    npcmsg gText_Route25_RocketGang_Jessie_Speak_8 MSG_KEEPOPEN 29 LEFT
    closemsg
    fadescreenspeed 0x3 0
    hidesprite JESSIE
    hidesprite MEOWTH
    hidesprite JAMES
    setflag FLAG_ROCKET_GANG_ROUTE25_SPRITE
    fadescreenspeed 0x2 0
    fadedefaultbgm
    applymovement PLAYER Move_Route25_RocketGang_Player_2
    waitmovement PLAYER
    npcmsg gText_Route25_RocketGang_Bill_Speak_6 MSG_KEEPOPEN 7 LEFT
    closemsg
    return

EventScript_Route25_RocketGang_PositionCamera:
    special 0x113
    compare PLAYERFACING RIGHT
    if equal _call EventScript_Route25_RocketGang_PositionCamera_Right
    compare PLAYERFACING LEFT
    if equal _call EventScript_Route25_RocketGang_PositionCamera_Left
    compare PLAYERFACING UP
    if equal _call EventScript_Route25_RocketGang_PositionCamera_Up
    compare PLAYERFACING DOWN
    if equal _call EventScript_Route25_RocketGang_PositionCamera_Down
    special 0x114
    return

EventScript_Route25_RocketGang_PositionCamera_Right:
    applymovement CAMERA Move_Route25_RocketGang_PositionCamera_Right
    waitmovement CAMERA
    return

EventScript_Route25_RocketGang_PositionCamera_Left:
    applymovement CAMERA Move_Route25_RocketGang_PositionCamera_Left
    waitmovement CAMERA
    return

EventScript_Route25_RocketGang_PositionCamera_Up:
    applymovement CAMERA Move_Route25_RocketGang_PositionCamera_Up
    waitmovement CAMERA
    return

EventScript_Route25_RocketGang_PositionCamera_Down:
    applymovement CAMERA Move_Route25_RocketGang_PositionCamera_Down
    waitmovement CAMERA
    return

Move_Route25_RocketGang_PositionCamera_Right:
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_Route25_RocketGang_PositionCamera_Left:
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_Route25_RocketGang_PositionCamera_Up:
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte end_m

Move_Route25_RocketGang_PositionCamera_Down:
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_Route25_RocketGang_Camera_BackToPlayer:
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_Route25_RocketGang_Player_1:
    .byte exclaim
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Route25_RocketGang_Bill_1:
    .byte exclaim
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Route25_RocketGang_Jessie_1:
    .byte exclaim
    .byte pause_long
    .byte end_m

Move_Route25_RocketGang_Meowth_1:
    .byte exclaim
    .byte pause_long
    .byte end_m

Move_Route25_RocketGang_James_1:
    .byte exclaim
    .byte pause_long
    .byte end_m

Move_Route25_RocketGang_Meowth_2:
    .byte walk_up
    .byte walk_right
    .byte walk_up
    .byte pause_long
    .byte jump_onspot_up
    .byte end_m

Move_Route25_RocketGang_Meowth_3:
    .byte walk_right
    .byte walk_right
    .byte walk_left_onspot_fastest
    .byte end_m

Move_Route25_RocketGang_Bill_2:
    .byte walk_right
    .byte walk_right
    .byte walk_left_onspot_fastest
    .byte end_m

Move_Route25_RocketGang_Jessie_2:
    .byte walk_up
    .byte walk_right
    .byte walk_up
    .byte end_m

Move_Route25_RocketGang_James_2:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_left_onspot_fastest
    .byte end_m

Move_Route25_RocketGang_Player_2:
    .byte walk_right
    .byte walk_right
    .byte end_m

Move_Route25_RocketGang_Jessie_3:
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte walk_left
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Route25_RocketGang_James_3:
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte walk_right
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Route25_RocketGang_Meowth_4:
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Route25_RocketGang_Meowth_5:
    .byte pause_long
    .byte jump_onspot_up
    .byte end_m

@@@@@@@@@@@@@@@@@@@@
@ Brawly Route 25
@@@@@@@@@@@@@@@@@@@@
EventScript_Route25_Brawly:
    lock
    pause 30
    sound 0x15
    applymovement 14 Move_Route25_Brawly_1
    waitmovement 14
    npcmsg gText_Route25_Brawly_Speak_1 MSG_KEEPOPEN 0 LEFT
    closemsg
    npcmsg gText_Route25_Brawly_Speak_2 MSG_YESNO 33 LEFT
    compare LASTRESULT 0x1
    if notequal _goto EventScript_Route25_Brawly_PlayerDontWantToBattle
    closemsg
    trainerbattle3 0x3 28 0x0 gText_Route25_Brawly_Defeat
    npcmsg gText_Route25_Brawly_Speak_3 MSG_KEEPOPEN 33 LEFT
    closemsg
    giveitem ITEM_BLACK_BELT 0x1 MSG_OBTAIN
    npcmsg gText_Route25_Brawly_Speak_4 MSG_KEEPOPEN 33 LEFT
    closemsg
    fadescreen 0x1
    hidesprite 14
    setflag FLAG_BRAWLY_ROUTE25_SPRITE
    fadescreen 0x0
    release
    end

EventScript_Route25_Brawly_PlayerDontWantToBattle:
    npcmsg gText_Route25_Brawly_PlayerDontWantToBattle MSG_KEEPOPEN 33 LEFT
    closemsg
    release
    end

Move_Route25_Brawly_1:
    .byte exclaim
    .byte pause_long
    .byte face_player
    .byte end_m

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
