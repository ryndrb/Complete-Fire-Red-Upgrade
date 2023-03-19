.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_HOUNDOOMINITE, 0x962
.equ FLAG_OBTAIN_EXPLOSION, 0x9A6
.equ FLAG_MAY_CINNABAR_SPRITE, 0x944
.equ VAR_MAY_CINNABAR_ENCOUNTER, 0x5032

@@@@@@@@@@@@@@@@@@@@@@
@ Blaine
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymLeaderBlaine:
    setvar 0x8004 0x8
    setvar 0x8005 0x2
    special 0x174
    call BlaineNameBox
    trainerbattle1 0x1 0x1A3 0x0 0x8199543 0x81995FA EventScript_0x816DA06
    checkflag 0x24E
    if 0x0 _goto 0x816DA34
    call BlaineNameBox
    msgbox 0x819971D MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x816DA06:
    setvar 0x8004 0x8
    setvar 0x8005 0x1
    special 0x173
    setflag 0x4B6
    setflag 0x826
    sethealingplace 0x9
    setvar 0x4071 0x0
    setvar 0x408A 0x1
    clearflag 0x62
    setvar 0x8008 0x7
    call 0x81A6B18
    goto EventScript_0x816DA34
    end

EventScript_0x816DA34:
    call BlaineNameBox
    msgbox 0x819969E MSG_KEEPOPEN
    callasm RemoveNameBox
    checkitemspace 0x146 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816DA75
    giveitem_msg 0x81996FF ITEM_TM38
    setflag 0x24E
    call BlaineNameBox
    msgbox 0x8199652 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Houndoominite | Cinnabar Island | Gym Guy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymGuyHoundoominite:
    lock
    faceplayer
    checkflag 0x4B6
    if 0x1 _goto EventScript_GiveHoundoominite
    msgbox 0x8191298 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x816A689
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816A697
    end

EventScript_GiveHoundoominite:
    checkflag FLAG_OBTAIN_HOUNDOOMINITE
    if 0x1 _goto Obtained
    msgbox gText_GymGuyGiveStone MSG_KEEPOPEN
    giveitem ITEM_HOUNDOOMINITE 0x1 MSG_OBTAIN
    bufferitem 0x0 ITEM_HOUNDOOMINITE
    bufferpokemon 0x1 SPECIES_HOUNDOOM
    msgbox gText_ObtainedStone MSG_KEEPOPEN
    setflag FLAG_OBTAIN_HOUNDOOMINITE
    release
    end

Obtained:
    goto 0x816A67F
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Explosion | Cinnabar Island
@@@@@@@@@@@@@@@@@@@@@@
EventScript_CinnabarExplosion:
    textcolor BLUE
    lock
    faceplayer
    checkflag FLAG_OBTAIN_EXPLOSION
    if 0x0 _goto EventScript_GiveExplosion
    msgbox gText_ExplosionObtained MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_GiveExplosion:
    msgbox gText_GiveExplosion MSG_KEEPOPEN
    giveitem ITEM_TM64 0x1 MSG_OBTAIN
    setflag FLAG_OBTAIN_EXPLOSION
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ May in Cinnabar
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Cinnabar_FossilCenter:
    mapscript MAP_SCRIPT_ON_TRANSITION MapScript_0x16E279
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_Cinnabar_May
    .byte MAP_SCRIPT_TERMIN

LevelScript_Cinnabar_May:
    levelscript VAR_MAY_CINNABAR_ENCOUNTER, 0, EventSript_Cinnabar_May
    .hword LEVEL_SCRIPT_TERMIN

MapScript_0x16E279:
    compare 0x406A 0x1
    if 0x1 _call MapScript_0x16E285
    end

MapScript_0x16E285:
    setvar 0x406A 0x2
    return

EventSript_Cinnabar_May:
    lock
    textcolor RED
    playsong 0x1A7
    applymovement 2 EventScript_Cinnabar_MayNoticePlayer
    applymovement PLAYER EventScript_Cinnabar_PlayerGetCloseToMay
    waitmovement 2
    call MayNameBox
    msgbox gText_Cinnabar_MaySpeaks1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 2 EventScript_Cinnabar_MayPonders
    waitmovement 2
    call MayNameBox
    msgbox gText_Cinnabar_MaySpeaks2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 2 EventScript_Cinnabar_MaySmiles
    waitmovement 2
    call MayNameBox
    msgbox gText_Cinnabar_MaySpeaks3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    spriteface 2, LEFT
    call MayNameBox
    msgbox gText_Cinnabar_MaySpeaks4 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 2 EventScript_Cinnabar_MayLeave
    applymovement PLAYER EventScript_Cinnabar_PlayerSeeMayLeave
    waitmovement 2
    sound 9
    hidesprite 2
    setvar VAR_MAY_CINNABAR_ENCOUNTER 0x1
    setflag FLAG_MAY_CINNABAR_SPRITE
    fadedefaultbgm
    release
    end

EventScript_Cinnabar_MayNoticePlayer:
    .byte exclaim
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte end_m

EventScript_Cinnabar_PlayerGetCloseToMay:
    .byte pause_long
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_right_onspot_fastest
    .byte end_m

EventScript_Cinnabar_MayPonders:
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte say_question
    .byte pause_long
    .byte end_m

EventScript_Cinnabar_MaySmiles:
    .byte say_smile
    .byte pause_long
    .byte end_m

EventScript_Cinnabar_MayLeave:
    .byte walk_down
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte end_m

EventScript_Cinnabar_PlayerSeeMayLeave:
    .byte walk_down_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Bill in Cinnabar
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Cinnabar:
    mapscript MAP_SCRIPT_ON_TRANSITION MapScript_Cinnabar1
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_Cinnabar_Bill
    .byte MAP_SCRIPT_TERMIN

MapScript_Cinnabar1:
    setworldmapflag 0x898
    switch 0x408A
    case 0, Move_RepositionBill
    end

Move_RepositionBill:
    movesprite2 0x3 0xF 0xC
    spriteface 0x3, LEFT
    return

LevelScript_Cinnabar_Bill:
    levelscript 0x4071, 0, EventSript_Cinnabar_Bill
    levelscript 0x408A, 0, EventScript_Cinnabar_OutsidePokeCenter
    .hword LEVEL_SCRIPT_TERMIN

EventSript_Cinnabar_Bill:
    lockall
    clearflag 0x4001
    textcolor BLUE
    pause 0x14
    applymovement 0x3 Move_BillNoticePlayer
    applymovement PLAYER Move_PlayerFaceBill
    waitmovement 0x3
    call BillNameBox
    msgbox gText_Cinnabar_BillSpeaks1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x3 Move_BillMoveTowardsPlayer
    waitmovement 0x3
    call BillNameBox
    msgbox gText_Cinnabar_BillSpeaks2 MSG_YESNO
    callasm RemoveNameBox
    compare LASTRESULT 0x1
    if TRUE _goto EventScript_0x1670E6
    call BillNameBox
    msgbox gText_Cinnabar_BillSpeaks3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x3 Move_BillWentToPokeCenter
    waitmovement 0x3
    setvar 0x4071 0x1
    clearflag 0xA2
    hidesprite 0x3
    release
    end

EventScript_0x1670E6:
    clearflag 0x6B
    movesprite2 0x4 0x1B 0xF
    call BillNameBox
    msgbox gText_Cinnabar_BillSpeaks4 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x3 Move_BillGoToBoat
    applymovement PLAYER Move_PlayerGoToBoat
    waitmovement 0x3
    applymovement 0x4 Move_BoatArrived
    waitmovement 0x4
    call BillNameBox
    msgbox gText_Cinnabar_BillSpeaks5 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x3 Move_BillGetOnBoat
    applymovement PLAYER Move_PlayerGetOnBoat
    waitmovement 0x3
    hidesprite 0x3
    pause 0x28
    setflag 0x6B
    setvar 0x4075 0x1
    setvar 0x4071 0x1
    setvar 0x8004 0x8
    setvar 0x8006 0x1
    goto 0x81A90DA
    release
    end

Move_BillNoticePlayer:
    .byte exclaim
    .byte walk_right_onspot_fastest
    .byte end_m

Move_PlayerFaceBill:
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte end_m

Move_BillMoveTowardsPlayer:
    .byte walk_right
    .byte end_m

Move_BillWentToPokeCenter:
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_BillGoToBoat:
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right_onspot_fastest
    .byte end_m

Move_PlayerGoToBoat:
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_right_onspot_fastest
    .byte end_m

Move_BoatArrived:
    .byte pause_long
    .byte pause_long
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left_very_slow
    .byte walk_left_very_slow
    .byte walk_left_very_slow
    .byte end_m

Move_BillGetOnBoat:
    .byte walk_right
    .byte walk_right_onspot_fastest
    .byte set_invisible
    .byte end_m

Move_PlayerGetOnBoat:
    .byte walk_right
    .byte walk_right_onspot_fastest
    .byte set_invisible
    .byte end_m

EventScript_Cinnabar_BillPokeCenter:
    lock
    faceplayer
    textcolor BLUE
    call BillNameBox
    msgbox 0x819A725 MSG_YESNO
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816E9A5
    call BillNameBox
    msgbox 0x819A785 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    setflag 0x4001
    pause 0x14
    compare PLAYERFACING 0x1
    if 0x1 _call EventScript_PlayerLookingDown
    compare PLAYERFACING 0x3
    if 0x1 _call EventScript_PlayerLookingLeft
    hidesprite 0x7
    setflag 0xA2
    setvar 0x408A 0x0
    clearflag 0x62
    warp 0x3 0x8 0xFF 0xE 0xB
    waitstate
    release
    end

EventScript_Cinnabar_OutsidePokeCenter:
    callasm RemoveNameBox
    textcolor BLUE
    clearflag 0x6B
    movesprite2 0x4 0x1B 0xF
    applymovement 3 Move_BillGoToBoatAgain
    applymovement PLAYER Move_PlayerGoToBoatAgain
    waitmovement 3
    applymovement 0x4 Move_BoatArrived
    waitmovement 0x4
    call BillNameBox
    msgbox gText_Cinnabar_BillSpeaks5 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x3 Move_BillGetOnBoat
    applymovement PLAYER Move_PlayerGetOnBoat
    waitmovement 0x3
    hidesprite 0x3
    pause 0x28
    setflag 0x6B
    setvar 0x4075 0x1
    setvar 0x408A 0x1
    setvar 0x8004 0x8
    setvar 0x8006 0x1
    goto 0x81A90DA
    release
    end

EventScript_PlayerLookingDown:
    applymovement 7 Move_PlayerLookingDown
    applymovement PLAYER Move_PlayerFollow1
    waitmovement 7
    return

EventScript_PlayerLookingLeft:
    applymovement 7 Move_PlayerLookingLeft
    applymovement PLAYER Move_PlayerFollow2
    waitmovement 7
    sound 9
    return

Move_PlayerLookingDown:
    .byte walk_up
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte set_invisible
    .byte end_m

Move_PlayerFollow1:
    .byte walk_right
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte set_invisible
    .byte end_m

Move_PlayerLookingLeft:
    .byte walk_up
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte set_invisible
    .byte end_m

Move_PlayerFollow2:
    .byte walk_up
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte set_invisible
    .byte end_m

Move_BillGoToBoatAgain:
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right_onspot_fastest
    .byte end_m

Move_PlayerGoToBoatAgain:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_right_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Cinnabar NameBox
@@@@@@@@@@@@@@@@@@@@@@
MayNameBox:
    setvar 0x8000 2
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

BillNameBox:
    setvar 0x8000 7
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

BlaineNameBox:
    setvar 0x8000 17
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
