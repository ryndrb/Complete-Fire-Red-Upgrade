.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_ROOST, 0x0D4
.equ FLAG_LANCE_SPRITE_PEWTER, 0x30D
.equ FLAG_OBTAIN_AERODACTYLITE, 0x0F9
.equ FLAG_BRENDAN_PEWTER_ENCOUNTER, 0x301
.equ FLAG_BRENDAN_PEWTER_SPRITE1, 0x300
.equ FLAG_BRENDAN_PEWTER_SPRITE2, 0x304
.equ FLAG_BRENDAN_PEWTER_SPRITE3, 0x312
.equ FLAG_BRENDAN_CATCH_FIRST_MON, 0x311
.equ VAR_BRENDAN_PEWTER_ENCOUNTER1, 0x5013
.equ VAR_BRENDAN_PEWTER_ENCOUNTER2, 0x502F
.equ FLAG_BRENDAN_VERMILLION_SPRITE, 0x936
.equ FLAG_BRENDAN_UNCLE_VERMILLION_SPRITE, 0x937
.equ BRENDAN, 0x4

@@@@@@@@@@@@@@@@@@@@@@
@ Brock
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymLeaderBrock:
    lock
    setvar 0x8004 0x2
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x19E 0x0 0x8190CD4 0x8190E4F EventScript_0x816A5C5
    checkflag 0x254
    if 0x0 _goto EventScript_0x816A5F3
    msgbox 0x819110F MSG_NORMAL
    checkflag FLAG_BRENDAN_PEWTER_ENCOUNTER
    if SET _goto End
    goto EventScript_Pewter_Brendan @ Brendan Event
    release
    end

EventScript_0x816A5C5:
    setvar 0x8004 0x2
    setvar 0x8005 0x1
    special 0x173
    setflag 0x4B0
    setflag 0x820
    setvar 0x406C 0x1
    setflag 0x2E
    clearflag 0x92
    setvar 0x8008 0x1
    call 0x81A6B18
    goto EventScript_0x816A5F3
    end

EventScript_0x816A5F3:
    msgbox 0x8190FC1 MSG_KEEPOPEN
    checkitemspace 0x147 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816A634
    giveitem_msg 0x8190FDB ITEM_TM39
    setflag 0x254
    setflag FLAG_BRENDAN_PEWTER_ENCOUNTER
    clearflag FLAG_BRENDAN_PEWTER_SPRITE1
    clearflag FLAG_BRENDAN_PEWTER_SPRITE2
    clearflag FLAG_BRENDAN_VERMILLION_SPRITE
    clearflag FLAG_BRENDAN_UNCLE_VERMILLION_SPRITE
    msgbox 0x8190FF8 MSG_NORMAL
    goto EventScript_Pewter_Brendan @ Brendan Event
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Aerodactylite | Viridian City | Gym Guy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymGuyAerodactylite:
    lock
    faceplayer
    checkflag 0x4B0
    if 0x1 _goto EventScript_GiveAerodactylite
    msgbox 0x8191298 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x816A689
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816A697
    end

EventScript_GiveAerodactylite:
    checkflag FLAG_OBTAIN_AERODACTYLITE
    if 0x1 _goto Obtained
    msgbox gText_GymGuyGiveStone MSG_KEEPOPEN
    giveitem ITEM_AERODACTYLITE 0x1 MSG_OBTAIN
    bufferitem 0x0 ITEM_AERODACTYLITE
    bufferpokemon 0x1 SPECIES_AERODACTYL
    msgbox gText_ObtainedStone MSG_KEEPOPEN
    setflag FLAG_OBTAIN_AERODACTYLITE
    release
    end

Obtained:
    goto 0x816A67F
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Brendan Pewter City
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pewter_Brendan:
    textcolor BLUE
    lock
    showsprite BRENDAN
    applymovement 0x4 EventScript_BrendanEnterGym
    waitmovement 0x4
    spriteface PLAYER, RIGHT
    spriteface 0x1, RIGHT
    msgbox gText_BrendanSpeaks1 MSG_KEEPOPEN
    msgbox gText_BrockSpeaks1 MSG_KEEPOPEN
    msgbox gText_BrendanSpeaks2 MSG_KEEPOPEN
    spriteface 0x1, DOWN
    msgbox gText_BrockSpeaks2 MSG_KEEPOPEN
    spriteface 0x1, RIGHT
    msgbox gText_BrockSpeaks3 MSG_KEEPOPEN
    fanfare 0x13E
    waitfanfare
    msgbox gText_BrendanSpeaks3 MSG_KEEPOPEN
    msgbox gText_BrockSpeaks4 MSG_KEEPOPEN
    fanfare 0x101
    waitfanfare
    spriteface 0x1, DOWN
    spriteface 0x4, DOWN
    spriteface PLAYER, UP
    msgbox gText_BrockSpeaks5 MSG_KEEPOPEN
    closeonkeypress
    applymovement 0x4 EventScript_BrendanExitGym1
    waitmovement 0x4
    applymovement PLAYER EventScript_PlayerFollowBrendanGym1
    waitmovement PLAYER
    applymovement 0x4 EventScript_BrendanExitGym2
    applymovement PLAYER EventScript_PlayerFollowBrendanGym2
    waitmovement 0x4
    sound 0x9
    hidesprite BRENDAN
    setflag FLAG_BRENDAN_PEWTER_SPRITE1
    release
    end

MapScript_BrendanOutsideGym:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_BrendanOutsideGym
    .byte MAP_SCRIPT_TERMIN

LevelScript_BrendanOutsideGym:
    levelscript VAR_BRENDAN_PEWTER_ENCOUNTER1, 0, EventScript_BrendanOutsideGym
    .hword LEVEL_SCRIPT_TERMIN

EventScript_BrendanOutsideGym:
    lock
    textcolor BLUE
    checkflag FLAG_BRENDAN_PEWTER_ENCOUNTER
    if NOT_SET _goto End
    showsprite 0x9
    applymovement 0x9 EventScript_BrendanHeadingToCatchMon
    applymovement PLAYER EventScript_FollowBrendanToCatchMon
    waitmovement 0x9
    msgbox gText_BrendanSpeaks6 MSG_NORMAL
    applymovement 0x9 EventScript_BrendanCatchingMon
    waitmovement 0x9
    msgbox gText_BrendanSpeaks7 MSG_KEEPOPEN
    setvar VAR_BRENDAN_PEWTER_ENCOUNTER1 0x1
    setvar VAR_BRENDAN_PEWTER_ENCOUNTER2 0x0
    setflag FLAG_BRENDAN_CATCH_FIRST_MON
    clearflag FLAG_BRENDAN_PEWTER_SPRITE3
    warp 0x6 0x2 0xFF 0x6 0x6
    release
    end

MapScript_BrendanAfterCatchingMonInsideGym:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_BrendanAfterCatchingMonInsideGym
    .byte MAP_SCRIPT_TERMIN

LevelScript_BrendanAfterCatchingMonInsideGym:
    levelscript VAR_BRENDAN_PEWTER_ENCOUNTER2, 0, EventScript_BrendanAfterCatchingMonInsideGym
    .hword LEVEL_SCRIPT_TERMIN

EventScript_BrendanAfterCatchingMonInsideGym:
    lock
    textcolor BLUE
    checkflag FLAG_BRENDAN_CATCH_FIRST_MON
    if NOT_SET _goto End
    showsprite BRENDAN
    spriteface PLAYER, UP
    msgbox gText_BrockSpeaks6 MSG_KEEPOPEN
    msgbox gText_BrendanSpeaks8 MSG_KEEPOPEN
    spriteface 0x5, DOWN
    msgbox gText_BrendanSpeaks9 MSG_KEEPOPEN
    closeonkeypress
    applymovement 0x5 EventScript_BrendanExitGymAfterCatchingMon
    waitmovement 0x5
    sound 0x9
    hidesprite 0x5
    hidesprite BRENDAN
    setvar VAR_BRENDAN_PEWTER_ENCOUNTER2 0x1
    setflag FLAG_BRENDAN_PEWTER_SPRITE2
    setflag FLAG_BRENDAN_PEWTER_SPRITE3
    end

End:
    release
    end

EventScript_BrendanEnterGym:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte walk_up
    .byte walk_left
    .byte walk_up
    .byte walk_left_onspot_fastest
    .byte end_m

EventScript_BrendanExitGym1:
    .byte walk_down
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_up_onspot_fastest
    .byte end_m

EventScript_BrendanExitGym2:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

EventScript_PlayerFollowBrendanGym1:
    .byte walk_down
    .byte end_m

EventScript_PlayerFollowBrendanGym2:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

EventScript_BrendanHeadingToCatchMon:
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
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
    .byte walk_right_onspot_fastest
    .byte end_m

EventScript_FollowBrendanToCatchMon:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte end_m

EventScript_BrendanCatchingMon:
    .byte jump_onspot_right
    .byte jump_onspot_right
    .byte jump_onspot_right
    .byte pause_long
    .byte jump_onspot_right
    .byte jump_onspot_right
    .byte jump_onspot_right
    .byte pause_long
    .byte jump_onspot_right
    .byte jump_onspot_right
    .byte jump_onspot_right
    .byte walk_up
    .byte end_m

EventScript_BrendanExitGymAfterCatchingMon:
    .byte walk_down
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m










@@@@@@@@@@@@@@@@@@@@@@
@ Roost | Pewter City Repel Guy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PewterRoostGuy:
    textcolor BLUE
    lock
    faceplayer
    checkflag FLAG_OBTAIN_ROOST
    if 0x0 _goto EventScript_GiveRoost
    msgbox gText_DislikeBirds MSG_KEEPOPEN 
    release
    end

EventScript_GiveRoost:
    msgbox 0x817E602 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x8166263
    msgbox 0x817E644 MSG_KEEPOPEN
    applymovement 0x4 EventScript_RoostGuy1
    waitmovement 0x4
    pause 30
    applymovement 0x4 EventScript_RoostGuy2
    waitmovement 0x4
    pause 30
    applymovement 0x4 EventScript_RoostGuy2GoBack
    waitmovement 0x4
    msgbox gText_GiveRoost MSG_KEEPOPEN
    giveitem ITEM_TM51 0x1 MSG_OBTAIN
    msgbox gText_GiveRoost2 MSG_KEEPOPEN
    msgbox gText_GiveRoost3 MSG_KEEPOPEN
    setflag FLAG_OBTAIN_ROOST
    closeonkeypress
    release
    end

EventScript_RoostGuy1:
    .byte exclaim
    .byte end_m

EventScript_RoostGuy2:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte pause_short
    .byte jump_onspot_up
    .byte pause_short
    .byte jump_onspot_up
    .byte pause_short
    .byte jump_onspot_up
    .byte end_m

EventScript_RoostGuy2GoBack:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte look_down
    .byte end_m

@@@@@@@@@@@@@@@@@@@@
@ Mega Ring Lance | Defeat Surge
@@@@@@@@@@@@@@@@@@@@
EventScript_LanceMegaRing:
    textcolor BLUE
    lock
    faceplayer
    msgbox gText_LanceIntro1 MSG_KEEPOPEN
    closeonkeypress
    applymovement 0x6 EventScript_LanceMove
    waitmovement 0x6
    pause 90
    faceplayer
    msgbox gText_LanceGiveMegaRing MSG_KEEPOPEN
    giveitem ITEM_MEGA_RING 0x1 MSG_OBTAIN
    msgbox gText_MegaRingObtained MSG_FACE
    fadescreen 0x1
    pause 65
    hidesprite 0x6
    fadescreen 0x0
    setflag FLAG_LANCE_SPRITE_PEWTER
    release
    end

EventScript_LanceMove:
    .byte look_down
    .byte say_question
    .byte end_m

@@@@@@@@@@@@@@@@@@@@
@ Did you check Museam guy | Fix
@@@@@@@@@@@@@@@@@@@@
EventScript_0x16607E:
    textcolor BLUE
    lock
    faceplayer
    msgbox 0x817E53E MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto EventScript_0x8166136
    msgbox 0x817E589 MSG_KEEPOPEN
    closeonkeypress
    pause 0xA
    playsong 0x110 0x0
    compare PLAYERFACING 0x2
    if 0x1 _call EventScript_0x81660EE
    msgbox 0x817E5AC MSG_KEEPOPEN
    closeonkeypress
    pause 0xA
    applymovement 0x2 EventScript_0x816621C
    waitmovement 0x0
    fadedefault
    hidesprite 0x2
    clearflag 0x50
    release
    end

EventScript_0x8166136:
    msgbox 0x817E55C MSG_KEEPOPEN
    release
    end

EventScript_0x81660EE:
    applymovement 0x2 EventScript_0x816615C
    applymovement PLAYER EventScript_0x8166140
    waitmovement 0x0
    return

EventScript_0x816621C:
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
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

EventScript_0x816615C:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
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
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_up_onspot_fastest
    .byte end_m

EventScript_0x8166140:
    .byte walk_right
    .byte walk_right_onspot_fastest
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
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
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte 0x1B
    .byte walk_up_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@
@ Check Brock Guy | Fix
@@@@@@@@@@@@@@@@@@@@
EventScript_0x165B9D:
    textcolor BLUE
    lock
    faceplayer
    msgbox gText_0x817E67E MSG_KEEPOPEN
    closeonkeypress
    playsong 0x110 0x0
    fadedefault
    @hidesprite 0x5
    @clearflag 0x2E
    release
    end

EventScript_0x165D8E:
    lockall
    spriteface PLAYER, UP
    setvar 0x4001 0x0
    goto EventScript_0x165DBE

EventScript_0x165D9A:
    lockall
    spriteface PLAYER, UP
    setvar 0x4001 0x1
    goto EventScript_0x165DBE

EventScript_0x165DA6:
    lockall
    spriteface PLAYER, UP
    setvar 0x4001 0x2
    goto EventScript_0x165DBE

EventScript_0x165DBE:
    textcolor BLUE
    applymovement 0x5 EventScript_LookDown
    waitmovement 0x5
    msgbox gText_0x817E67E MSG_KEEPOPEN
    closeonkeypress
    playsong 0x110 0x0
    compare 0x4001 0x0
    if 0x1 _call Eventscript_PlayerNotAllowed
    compare 0x4001 0x1
    if 0x1 _call Eventscript_PlayerNotAllowed
    compare 0x4001 0x2
    if 0x1 _call Eventscript_PlayerNotAllowed
    fadedefault
    @hidesprite 0x5
    @clearflag 0x2E
    releaseall
    end

Eventscript_PlayerNotAllowed:
    applymovement PLAYER Eventscript_PlayerNotAllowedMove
    waitmovement 0x1
    return

Eventscript_PlayerNotAllowedMove:
    .byte walk_left
    .byte end_m

EventScript_LookDown:
    .byte walk_down_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Prof. Aide Dex Nav
@@@@@@@@@@@@@@@@@@@@@@
EventScript_0x1662A9:
    textcolor BLUE
    lock
    faceplayer
    setvar 0x4001 0x0
    call EventScrit_0x81662DE
    release
    end

EventScript_0x1662B7:
    lockall
    setvar 0x4001 0x1
    call EventScrit_0x81662DE
    releaseall
    end

EventScript_0x1662C4:
    lockall
    setvar 0x4001 0x2
    call EventScrit_0x81662DE
    releaseall
    end

EventScript_0x1662D1:
    lockall
    setvar 0x4001 0x3
    call EventScrit_0x81662DE
    releaseall
    end

EventScrit_0x81662DE:
    textcolor BLUE
    compare 0x4001 0x1
    if 0x1 _call 0x81663CA
    compare 0x4001 0x2
    if 0x1 _call 0x81663CA
    compare 0x4001 0x3
    if 0x1 _call 0x81663CA
    checksound
    sound 0x15
    applymovement 0x7 0x81A75DB
    waitmovement 0x0
    applymovement 0x7 0x81A75DD
    waitmovement 0x0
    msgbox 0x817E902 MSG_KEEPOPEN
    compare 0x4001 0x0
    if 0x1 _call 0x81663D5
    compare 0x4001 0x1
    if 0x1 _call 0x81663DA
    compare 0x4001 0x2
    if 0x1 _call 0x81663E6
    compare 0x4001 0x3
    if 0x1 _call 0x81663FC
    msgbox 0x817E90C MSG_KEEPOPEN
    textcolor 0x3
    fanfare 0x13E
    preparemsg gText_ReceivedDexNav
    waitmsg
    waitfanfare
    special 0x171
    signmsg
    msgbox gText_PressRightArrow MSG_KEEPOPEN
    normalmsg
    call 0x81A6675
    msgbox 0x817EA06 MSG_KEEPOPEN
    closeonkeypress
    compare 0x4001 0x0
    if 0x1 _call 0x8166412
    compare 0x4001 0x1
    if 0x1 _call 0x816641D
    compare 0x4001 0x2
    if 0x1 _call 0x8166428
    compare 0x4001 0x3
    if 0x1 _call 0x8166433
    pause 0x1E
    textcolor 0x3
    signmsg
    msgbox gText_MomLetter MSG_KEEPOPEN
    msgbox gText_PlayerFeelWarm MSG_KEEPOPEN
    applymovement PLAYER EventScript_PlayerSmile
    waitmovement 0x0
    closeonkeypress
    hidesprite 0x7
    setflag 0x91E
    setvar 0x406C 0x2
    return

EventScript_PlayerSmile:
    .byte say_smile
    .byte end_m
