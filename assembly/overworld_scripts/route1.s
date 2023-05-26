.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ May Battle After Receiving Parcel
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Route1_May:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_Route1_May
    .byte MAP_SCRIPT_TERMIN

LevelScript_Route1_May:
    levelscript VAR_MAY_ENCOUNTER, 1, EventScript_Route1_May
    .hword LEVEL_SCRIPT_TERMIN

EventScript_Route1_May:
    lock
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
    applymovement 0x5 EventScrsipt_Route1_MayNoticePlayer
    waitmovement 0x5
    sound 0x15
    applymovement 0x5 EventScript_Route1_MayGotCloserToPlayer
    waitmovement 0x5
    playsong 0x1A7
    checkflag FLAG_MAY_PALLET_TOWN_TALKED
    if SET _goto EventScript_Route1_MetMayInPalletTown
    npcmsg gText_Route1_NotMetMayInPalletTownSpeaks1 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement 0x5 EventScript_MaySighing
    waitmovement 0x5
    npcmsg gText_Route1_NotMetMayInPalletTownSpeaks2 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_Route1_NotMetMayInPalletTownSpeaks3 MSG_KEEPOPEN gText_Name_May
    closemsg
    getplayerpos 0x8000 0x8001
    compare 0x8000 10
    if equal _call EventScript_Route1_MovePlayer1
    compare 0x8000 11
    if equal _call EventScript_Route1_MovePlayer2
    compare 0x8000 12
    if equal _call EventScript_Route1_MovePlayer3
    compare 0x8000 13
    if equal _call EventScript_Route1_MovePlayer4
    waitmovement 0x5
    hidesprite 0x5
    setflag FLAG_MAY_ROUTE1_SPRITE
    setvar VAR_MAY_ENCOUNTER 0x2
    fadedefaultbgm
    release
    end

EventScript_Route1_MetMayInPalletTown:
    npcmsg gText_Route1_MetMayInPalletTownSpeaks1 MSG_KEEPOPEN gText_Name_May
    closemsg
    applymovement 0x5 EventScript_MaySighing
    waitmovement 0x5
    npcmsg gText_Route1_MetMayInPalletTownSpeaks2 MSG_KEEPOPEN gText_Name_May
    closemsg
    npcmsg gText_Route1_MetMayInPalletTownSpeaks3 MSG_KEEPOPEN gText_Name_May
    closemsg
    getplayerpos 0x8000 0x8001
    compare 0x8000 10
    if equal _call EventScript_Route1_MovePlayer1
    compare 0x8000 11
    if equal _call EventScript_Route1_MovePlayer2
    compare 0x8000 12
    if equal _call EventScript_Route1_MovePlayer3
    compare 0x8000 13
    if equal _call EventScript_Route1_MovePlayer4
    waitmovement 0x5
    hidesprite 0x5
    setflag FLAG_MAY_ROUTE1_SPRITE
    setvar VAR_MAY_ENCOUNTER 0x2
    fadedefaultbgm
    release
    end

EventScript_MaySighing:
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte say_question
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

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
    applymovement 0x5 Move_Route1_May_Leaving_1
    applymovement PLAYER Move_Route1_PlayerStepAside1
    return

EventScript_Route1_MovePlayer2:
    applymovement 0x5 Move_Route1_May_Leaving_1
    applymovement PLAYER Move_Route1_PlayerStepAside1
    return 

EventScript_Route1_MovePlayer3:
    applymovement 0x5 Move_Route1_May_Leaving_2
    applymovement PLAYER Move_Route1_PlayerStepAside2
    return 

EventScript_Route1_MovePlayer4:
    applymovement 0x5 Move_Route1_May_Leaving_3
    applymovement PLAYER Move_Route1_PlayerStepAside3
    return

EventScrsipt_Route1_MayNoticePlayer:
    .byte walk_up
    .byte walk_up
    .byte pause_long
    .byte end_m

EventScript_Route1_MayGotCloserToPlayer:
    .byte exclaim
    .byte pause_long
    .byte jump_onspot_up
    .byte pause_long
    .byte run_up
    .byte run_up
    .byte run_up
    .byte end_m

EventScript_Route1_PlayerNoticeMay:
    .byte say_question
    .byte pause_long
    .byte end_m

Move_Route1_May_Leaving_1:
    .byte pause_long
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_Route1_May_Leaving_2:
    .byte walk_left
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_Route1_May_Leaving_3:
    .byte walk_left
    .byte walk_left
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_Route1_PlayerStepAside1:
    .byte walk_right
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Route1_PlayerStepAside2:
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Route1_PlayerStepAside3:
    .byte pause_long
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

End:
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Route 1 Sign Post
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route1_Signpost:
    signmsg
    msgbox gText_Route1_Signpost MSG_NORMAL
    release
    end
