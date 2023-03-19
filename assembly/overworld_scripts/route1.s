.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ VAR_MAY_ROUTE1_ENCOUNTER, 0x5030
.equ FLAG_MAY_ROUTE1_SPRITE, 0x93B

@@@@@@@@@@@@@@@@@@@@@@
@ May Battle After Receiving Parcel
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Route1_May:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_Route1_May
    .byte MAP_SCRIPT_TERMIN

LevelScript_Route1_May:
    levelscript VAR_MAY_ROUTE1_ENCOUNTER, 0, EventScript_Route1_May
    .hword LEVEL_SCRIPT_TERMIN

EventScript_Route1_May:
    lock
    textcolor RED
    playsong 0x1A7
    showsprite 0x5
    getplayerpos 0x8000 0x8001
    compare 0x8000 10
    if equal _call MoveMaySprite1
    compare 0x8000 11
    if equal _call MoveMaySprite2
    compare 0x8000 12
    if equal _call MoveMaySprite3
    compare 0x8000 13
    if equal _call MoveMaySprite4 
    applymovement PLAYER EventScript_Route1_PlayerNoticeMay
    waitmovement PLAYER
    applymovement 0x5 EventScript_Route1_MayGotCloserToPlayer
    waitmovement 0x5
    call MayNameBox
    msgbox gText_Route1_MaySpeaks1 MSG_KEEPOPEN
    msgbox gText_Route1_MaySpeaks2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    getplayerpos 0x8000 0x8001
    compare 0x8000 10
    if equal _call EventScript_Route1_MovePlayer1
    compare 0x8000 13
    if equal _call EventScript_Route1_MovePlayer2
    compare 0x8000 11
    if equal _call EventScript_Route1_MovePlayer3
    compare 0x8000 12
    if equal _call EventScript_Route1_MovePlayer3
    applymovement 0x5 EventScript_Route1_MayLeaving1
    waitmovement 0x5
    hidesprite 0x5
    setflag FLAG_MAY_ROUTE1_SPRITE
    setvar VAR_MAY_ROUTE1_ENCOUNTER 0x1
    fadedefaultbgm
    release
    end

MayNameBox:
    setvar 0x8000 2
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

MoveMaySprite1:
    movesprite 5 10 6
    return
MoveMaySprite2:
    movesprite 5 11 6
    return
MoveMaySprite3:
    movesprite 5 12 6
    return
MoveMaySprite4:
    movesprite 5 13 6
    return

EventScript_Route1_MovePlayer1:
    applymovement PLAYER EventScript_Route1_PlayerStepAside1
    waitmovement PLAYER
    return

EventScript_Route1_MovePlayer2:
    applymovement PLAYER EventScript_Route1_PlayerStepAside2
    waitmovement PLAYER
    return 

EventScript_Route1_MovePlayer3:
    applymovement PLAYER EventScript_Route1_PlayerStepAside3
    waitmovement PLAYER
    return 

EventScript_Route1_MayGotCloserToPlayer:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

EventScript_Route1_PlayerNoticeMay:
    .byte exclaim
    .byte pause_long
    .byte end_m

EventScript_Route1_MayLeaving1:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

EventScript_Route1_PlayerStepAside1:
    .byte walk_right
    .byte walk_left_onspot_fastest
    .byte end_m

EventScript_Route1_PlayerStepAside2:
    .byte walk_left
    .byte walk_right_onspot_fastest
    .byte end_m

EventScript_Route1_PlayerStepAside3:
    .byte walk_right
    .byte walk_up_onspot_fastest
    .byte end_m

End:
    release
    end
