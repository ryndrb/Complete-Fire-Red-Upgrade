.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ BRENDAN, 0x4
.equ ASH, 0xA

@@@@@@@@@@@@@@@@@@@@@@
@ Pewter City Map Scripts
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Pewter:
    mapscript MAP_SCRIPT_ON_TRANSITION Map_Pewter
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_Pewter
    .byte MAP_SCRIPT_TERMIN

Map_Pewter:
    setworldmapflag 0x892
    setvar 0x4061 0x0
    end

LevelScript_Pewter:
    levelscript VAR_BRENDAN_ENCOUNTER, 1, EventScript_BrendanOutsideGym
    levelscript VAR_ENCOUNTER_ASH, 1, EventScript_Pewter_Ash
    .hword LEVEL_SCRIPT_TERMIN

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
    compare VAR_BRENDAN_ENCOUNTER 0x1
    if equal _goto EventScript_GymLeaderBrock_HelpBrendan
    npcmsg gText_0x819110F MSG_KEEPOPEN gText_Name_Brock
    closemsg
    release
    end

EventScript_GymLeaderBrock_HelpBrendan:
    npcmsg gText_GymLeaderBrock_HelpBrendan MSG_KEEPOPEN gText_Name_Brock
    closemsg
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
    npcmsg 0x8190FC1 MSG_KEEPOPEN gText_Name_Brock
    closemsg
    checkitemspace 0x147 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816A634
    giveitem_msg 0x8190FDB ITEM_TM39
    setflag 0x254
    clearflag FLAG_BRENDAN_PEWTER_SPRITE2
    clearflag FLAG_BRENDAN_VERMILLION_SPRITE
    clearflag FLAG_BRENDAN_UNCLE_VERMILLION_SPRITE
    npcmsg 0x8190FF8 MSG_KEEPOPEN gText_Name_Brock
    closemsg
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
    lock
    playsong 0x1D5
    showsprite BRENDAN
    applymovement 0x4 EventScript_BrendanEnterGym
    waitmovement 0x4
    spriteface PLAYER, RIGHT
    spriteface 0x1, RIGHT
    npcmsg gText_BrendanSpeaks1 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    npcmsg gText_BrockSpeaks1 MSG_KEEPOPEN gText_Name_Brock
    closemsg
    npcmsg gText_BrendanSpeaks2 MSG_KEEPOPEN gText_Name_Brendan
    closemsg
    spriteface 0x1, DOWN
    npcmsg gText_BrockSpeaks2 MSG_KEEPOPEN gText_Name_Brock
    closemsg
    spriteface 0x1, RIGHT
    npcmsg gText_BrockSpeaks3 MSG_KEEPOPEN gText_Name_Brock
    closemsg
    fanfare 0x13E
    msgbox gText_BrendanReceivedMon MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    npcmsg gText_BrendanSpeaks3 MSG_KEEPOPEN gText_Name_Brendan
    closemsg
    npcmsg gText_BrockSpeaks4 MSG_KEEPOPEN gText_Name_Brock
    closemsg
    fanfare 0x101
    msgbox gText_BrendanReceivedBall MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    spriteface 0x1, DOWN
    spriteface 0x4, DOWN
    spriteface PLAYER, UP
    npcmsg gText_BrendanSpeaks5 MSG_KEEPOPEN gText_Name_Brendan
    closemsg
    applymovement 0x4 EventScript_BrendanExitGym1
    waitmovement 0x4
    applymovement PLAYER EventScript_PlayerFollowBrendanGym1
    waitmovement PLAYER
    applymovement 0x4 EventScript_BrendanExitGym2
    applymovement PLAYER EventScript_PlayerFollowBrendanGym2
    waitmovement 0x4
    sound 0x9
    hidesprite BRENDAN
    setvar VAR_BRENDAN_ENCOUNTER 0x1
    fadedefaultbgm
    release
    end

EventScript_BrendanOutsideGym:
    lock
    showsprite 0x9
    pause 30
    applymovement 0x9 EventScript_BrendanHeadingToCatchMon
    applymovement PLAYER EventScript_FollowBrendanToCatchMon
    waitmovement 0x9
    npcmsg gText_BrendanSpeaks6 MSG_KEEPOPEN gText_Name_Brendan
    closemsg
    applymovement 0x9 EventScript_BrendanCatchingMon
    waitmovement 0x9
    npcmsg gText_BrendanSpeaks7 MSG_KEEPOPEN gText_Name_Brendan
    closemsg
    setvar VAR_BRENDAN_ENCOUNTER 0x2
    clearflag FLAG_BRENDAN_PEWTER_SPRITE3
    fadedefaultbgm
    warpmuted 0x6 0x2 0xFF 0x6 0x6
    waitstate
    release
    end

MapScript_BrendanAfterCatchingMonInsideGym:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_BrendanAfterCatchingMonInsideGym
    .byte MAP_SCRIPT_TERMIN

LevelScript_BrendanAfterCatchingMonInsideGym:
    levelscript VAR_BRENDAN_ENCOUNTER, 2, EventScript_BrendanAfterCatchingMonInsideGym
    .hword LEVEL_SCRIPT_TERMIN

EventScript_BrendanAfterCatchingMonInsideGym:
    lock
    showsprite BRENDAN
    spriteface PLAYER, UP
    spriteface 0x1, RIGHT
    pause 15
    npcmsg gText_BrockSpeaks6 MSG_KEEPOPEN gText_Name_Brock
    closemsg
    npcmsg gText_BrendanSpeaks8 MSG_KEEPOPEN gText_Name_Brendan
    spriteface 0x5, DOWN
    npcmsg gText_BrendanSpeaks9 MSG_KEEPOPEN gText_Name_Brendan
    closemsg
    applymovement 0x5 EventScript_BrendanExitGymAfterCatchingMon
    waitmovement 0x5
    sound 0x9
    pause 15
    spriteface 0x1, DOWN
    npcmsg gText_BrockSpeaks7 MSG_KEEPOPEN gText_Name_Brock
    closemsg
    hidesprite 0x5
    hidesprite BRENDAN
    setvar VAR_BRENDAN_ENCOUNTER 0x3
    setflag FLAG_BRENDAN_PEWTER_SPRITE2
    setflag FLAG_BRENDAN_PEWTER_SPRITE3
    clearflag FLAG_ASH_PEWTER_SPRITE
    setvar VAR_ENCOUNTER_ASH 0x1
    fadedefaultbgm
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
    closeonkeypress
    sound 0x15
    applymovement 0x4 EventScript_RoostGuy1
    waitmovement 0x4
    pause 30
    applymovement 0x4 EventScript_RoostGuy2
    waitmovement 0x4
    pause 30
    faceplayer
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
    .byte pause_long
    .byte end_m

EventScript_RoostGuy2:
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte walk_left_onspot_fastest
    .byte walk_right_onspot_fastest
    .byte walk_down_onspot_fastest
    .byte walk_up_onspot_fastest
    .byte jump_onspot_up
    .byte pause_short
    .byte jump_onspot_up
    .byte pause_short
    .byte jump_onspot_up
    .byte end_m

@@@@@@@@@@@@@@@@@@@@
@ Did you check Museam guy | Fix
@@@@@@@@@@@@@@@@@@@@
EventScript_0x16607E:
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

@@@@@@@@@@@@@@@@@@@@@@
@ Steven
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pewter_Steven:
    lock
    faceplayer
    checkflag FLAG_PEWTER_STEVEN_BELDUM
    if SET _goto EventScript_Pewter_Steven_AfterIntro
    npcmsg gText_Pewter_Steven_Speak1 MSG_KEEPOPEN gText_Name_Steven
    closemsg
    showpokepic SPECIES_BELDUM 0xA 0x3
    npcmsg gText_Pewter_Steven_Speak2 MSG_YESNO gText_Name_Steven
    compare LASTRESULT 0x1
    if FALSE _call EventScript_Pewter_Steven_DontWantBeldum
    closemsg
    fanfare 0x13E
    givepokemoncustom SPECIES_BELDUM 5 ITEM_NONE MOVE_TACKLE MOVE_NONE MOVE_NONE MOVE_NONE NATURE_JOLLY 0 31 31 31 31 31 31 0 0
    signmsg
    msgbox gText_Pewter_Steven_PlayerReceivedBeldum MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    hidepokepic
    normalmsg
    npcmsg gText_Pewter_Steven_Speak3 MSG_KEEPOPEN gText_Name_Steven
    closemsg
    setflag FLAG_PEWTER_STEVEN_BELDUM
    release
    end

EventScript_Pewter_Steven_DontWantBeldum:
    hidepokepic
    npcmsg gText_Pewter_Steven_DontWantBeldum MSG_KEEPOPEN gText_Name_Steven
    closemsg
    setflag FLAG_PEWTER_STEVEN_BELDUM
    release
    end

EventScript_Pewter_Steven_AfterIntro:
    lock
    faceplayer
    npcmsg gText_Pewter_Steven_Speak4 MSG_KEEPOPEN gText_Name_Steven
    closemsg
    multichoiceoption gText_Pewter_Steven_General 0
    multichoiceoption gText_Pewter_Steven_Quests 1
    multichoiceoption gText_Pewter_Steven_End 2
    multichoice 0x0 0x0 THREE_MULTICHOICE_OPTIONS 0x0
    switch LASTRESULT
    case 0, EventScript_Pewter_Steven_General
    case 1, EventScript_Pewter_Steven_Quests
    case 2, EventScript_Pewter_Steven_End
    release
    end

EventScript_Pewter_Steven_General:
    npcmsg gText_Pewter_Steven_Speak5 MSG_KEEPOPEN gText_Name_Steven
    closemsg
    release
    end

EventScript_Pewter_Steven_Quests:
    checkflag FLAG_QUEST_HEATRAN
    if NOT_SET _goto EventScript_Pewter_Steven_Quests_MagmaStone
    checkflag FLAG_QUEST_LATITWINS
    if NOT_SET _goto EventScript_Pewter_Steven_Quests_LatiTwins
    checkflag FLAG_QUEST_REGIS
    if NOT_SET _goto EventScript_Pewter_Steven_Quests_Regis
    checkflag FLAG_QUEST_WEATHERTRIO
    if NOT_SET _goto EventScript_Pewter_Steven_Quests_WeatherTrio
    npcmsg gText_Pewter_Steven_Speak15 MSG_YESNO gText_Name_Steven
    compare LASTRESULT 0x1
    if FALSE _goto EventScript_Pewter_Steven_End
    closemsg
    release
    end

EventScript_Pewter_Steven_Quests_MagmaStone:
    npcmsg gText_Pewter_Steven_Speak6 MSG_KEEPOPEN gText_Name_Steven
    closemsg
    checkitem ITEM_MAGMA_STONE 0x1
    compare LASTRESULT 0x1
    if FALSE _goto EventScript_Pewter_Steven_End
    pause 30
    sound 0x15
    applymovement 0x3 Move_Pewter_Steven_1
    waitmovement 0x3
    npcmsg gText_Pewter_Steven_Speak7 MSG_KEEPOPEN gText_Name_Steven
    closemsg
    giveitem ITEM_SOUL_DEW 0x1 MSG_OBTAIN
    npcmsg gText_Pewter_Steven_Speak8 MSG_KEEPOPEN gText_Name_Steven
    closemsg
    setflag FLAG_QUEST_HEATRAN
    release
    end

EventScript_Pewter_Steven_Quests_LatiTwins:
    npcmsg gText_Pewter_Steven_Speak8 MSG_KEEPOPEN gText_Name_Steven
    closemsg
    callasm CheckLatiasLatios
    compare 0x8004 0x1
    if FALSE _goto EventScript_Pewter_Steven_End
    pause 30
    sound 0x15
    applymovement 0x3 Move_Pewter_Steven_1
    waitmovement 0x3
    npcmsg gText_Pewter_Steven_Speak9 MSG_KEEPOPEN gText_Name_Steven
    npcmsg gText_Pewter_Steven_Speak10 MSG_KEEPOPEN gText_Name_Steven
    closemsg
    setflag FLAG_QUEST_LATITWINS
    clearflag FLAG_REGIROCK_ROCKTUNNEL
    clearflag FLAG_REGICE_SEAFOAM
    clearflag FLAG_REGISTEEL_MTMOON
    release
    end

EventScript_Pewter_Steven_Quests_Regis:
    npcmsg gText_Pewter_Steven_Speak10 MSG_KEEPOPEN gText_Name_Steven
    closemsg
    callasm CheckRegis
    compare 0x8004 0x1
    if FALSE _goto EventScript_Pewter_Steven_End
    pause 30
    sound 0x15
    applymovement 0x3 Move_Pewter_Steven_1
    waitmovement 0x3
    npcmsg gText_Pewter_Steven_Speak11 MSG_KEEPOPEN gText_Name_Steven
    closemsg
    giveitem ITEM_BLUE_ORB 0x1 MSG_OBTAIN
    giveitem ITEM_RED_ORB 0x1 MSG_OBTAIN
    npcmsg gText_Pewter_Steven_Speak12 MSG_KEEPOPEN gText_Name_Steven
    closemsg
    setflag FLAG_QUEST_REGIS
    checkflag 0x4BC
    if NOT_SET _goto EventScript_Pewter_Steven_End
    clearflag FLAG_GROUDON_ROUTE3
    clearflag FLAG_KYOGRE_ROUTE21
    clearflag FLAG_RAYQUAZA_NAVELROCK
    setflag FLAG_ROUTE21_THUNDERSTORMS
    setflag FLAG_ROUTE3_STEAM
    release
    end

EventScript_Pewter_Steven_Quests_WeatherTrio:
    npcmsg gText_Pewter_Steven_Speak12 MSG_KEEPOPEN gText_Name_Steven
    closemsg
    callasm CheckWeatherTrio
    compare 0x8004 0x1
    if FALSE _goto EventScript_Pewter_Steven_End
    pause 30
    sound 0x15
    applymovement 0x3 Move_Pewter_Steven_1
    waitmovement 0x3
    npcmsg gText_Pewter_Steven_Speak13 MSG_KEEPOPEN gText_Name_Steven
    npcmsg gText_Pewter_Steven_Speak14 MSG_KEEPOPEN gText_Name_Steven
    closemsg
    setflag FLAG_QUEST_WEATHERTRIO
    release
    end

EventScript_Pewter_Steven_End:
    release
    end

Move_Pewter_Steven_1:
    .byte exclaim
    .byte pause_long
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Ash
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pewter_Ash:
    lock
    pause 30
    applymovement ASH Move_Pewter_Ash_1
    waitmovement ASH
    sound 0x15
    applymovement ASH Move_Pewter_Ash_2
    waitmovement ASH
    npcmsg gText_Pewter_Ash_Speak_1 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    pause 30
    sound 0x15
    applymovement PLAYER Move_Pewter_Player_1
    waitmovement PLAYER
    playsong 0x1D5 0x0
    npcmsg gText_Pewter_Ash_Speak_2 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    npcmsg gText_Pewter_Ash_Speak_3 MSG_KEEPOPEN gText_Name_Ash
    closemsg
    pause 30
    giveitem ITEM_GREAT_BALL 10 MSG_OBTAIN
    npcmsg gText_Pewter_Ash_Speak_4 MSG_KEEPOPEN gText_Name_Ash
    closemsg
    pause 30
    sound 0x15
    applymovement ASH Move_Pewter_Ash_3
    waitmovement ASH
    npcmsg gText_Pewter_Ash_Speak_5 MSG_KEEPOPEN gText_Name_Ash
    closemsg
    applymovement ASH Move_Pewter_Ash_4
    waitmovement ASH
    hidesprite ASH
    setflag FLAG_ASH_PEWTER_SPRITE
    setvar VAR_ENCOUNTER_ASH 0x2
    fadedefaultbgm
    release
    end

Move_Pewter_Ash_1:
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte end_m

Move_Pewter_Ash_2:
    .byte exclaim
    .byte pause_long
    .byte end_m

Move_Pewter_Player_1:
    .byte say_question
    .byte pause_long
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_Pewter_Ash_3:
    .byte exclaim
    .byte pause_long
    .byte end_m

Move_Pewter_Ash_4:
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
    .byte end_m
