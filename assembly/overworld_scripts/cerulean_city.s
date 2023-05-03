.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ Misty
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymLeaderMisty:
    setvar 0x8004 0x3
    setvar 0x8005 0x2
    special 0x174
    call MistyNameBox
    trainerbattle1 0x1 0x19F 0x0 0x81921EF 0x819242D EventScript_0x816AAD3
    callasm RemoveNameBox
    checkflag 0x297
    if 0x0 _goto EventScript_0x816AAF9
    call MistyNameBox
    msgbox 0x81922BF MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x816AAD3:
    setvar 0x8004 0x3
    setvar 0x8005 0x1
    special 0x173
    setflag 0x4B1
    setflag 0x821
    sethealingplace 0x4
    setvar 0x8008 0x2
    call 0x81A6B18
    goto EventScript_0x816AAF9
    end

EventScript_0x816AAF9:
    call MistyNameBox
    msgbox 0x81922F7 MSG_KEEPOPEN
    callasm RemoveNameBox
    checkitemspace 0x123 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816AB3A
    giveitem_msg 0x81923F1 ITEM_TM03
    setflag 0x297
    call MistyNameBox
    msgbox 0x81922BF MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

Obtained:
    goto 0x816A67F
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Gyaradosite | Cerulean City | Gym Guy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymGuyGyaradosite:
    lock
    faceplayer
    checkflag 0x4B1
    if 0x1 _goto EventScript_GiveGyaradosite
    msgbox 0x8191298 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x816A689
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816A697
    end

EventScript_GiveGyaradosite:
    checkflag FLAG_OBTAIN_GYARADOSITE
    if 0x1 _goto Obtained
    msgbox gText_GymGuyGiveStone MSG_KEEPOPEN
    giveitem ITEM_GYARADOSITE 0x1 MSG_OBTAIN
    bufferitem 0x0 ITEM_GYARADOSITE
    bufferpokemon 0x1 SPECIES_GYARADOS
    msgbox gText_ObtainedStone MSG_KEEPOPEN
    setflag FLAG_OBTAIN_GYARADOSITE
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Sandile Gift | Wise Glasses | Cerulean City
@@@@@@@@@@@@@@@@@@@@@@
EventScript_SandileGift:
    lock
    checkflag FLAG_OBTAIN_GIFT_SANDILE
    if 0x0 _goto EventScript_GiveSandile
    applymovement 0xD EventScript_TurnBackConfuse
    waitmovement 0xD
    release
    end

EventScript_GiveSandile:
    msgbox gText_LookBeautiful MSG_NORMAL
    applymovement 0xD EventScript_FirstInteraction
    waitmovement 0xD
    faceplayer
    msgbox gText_NoticePlayer MSG_KEEPOPEN
    applymovement 0xD EventScript_TurnBackAndAdmireAgain
    waitmovement 0xD
    msgbox gText_AdmireAgain MSG_KEEPOPEN
    msgbox gText_AskPlayer MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EndScript
    applymovement 0xD EventScript_SecondInteraction
    waitmovement 0xD
    faceplayer
    msgbox gText_LikePlayer MSG_NORMAL
    givepokemoncustom SPECIES_SANDILE 20 ITEM_WISE_GLASSES MOVE_BITE MOVE_FIREFANG MOVE_THUNDERFANG MOVE_COUNTER NATURE_ADAMANT 1 31 31 31 31 31 31 3 1
    showpokepic SPECIES_SANDILE 0xA 0x3
    msgbox gText_ReceivedSandile MSG_KEEPOPEN
    fanfare 0x13E
    waitfanfare
    hidepokepic
    msgbox gText_EndMessage MSG_KEEPOPEN
    applymovement 0xD EventScript_TurnBackConfuse
    waitmovement 0xD
    setflag FLAG_OBTAIN_GIFT_SANDILE
    releaseall
    end

EventScript_FirstInteraction:
    .byte say_question
    .byte end_m

EventScript_TurnBackAndAdmireAgain:
    .byte look_up
    .byte end_m

EventScript_SecondInteraction:
    .byte exclaim
    .byte end_m

EventScript_TurnBackConfuse:
    .byte say_question
    .byte look_up
    .byte end_m

EndScript:
    msgbox gText_Farce MSG_KEEPOPEN
    closeonkeypress
    releaseall
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Cerulean TM Merchant
@@@@@@@@@@@@@@@@@@@@@@
EventScript_CeruleanTMMerchant:
    msgbox gText_CeruleanTMMerchantGreet MSG_KEEPOPEN
    pokemart EventScript_CeruleanTMMerchantList
    msgbox gText_CeruleanTMMerchantEnd MSG_KEEPOPEN
    release
    end

.align 1
EventScript_CeruleanTMMerchantList:
    .hword ITEM_TM42
    .hword ITEM_TM56
    .hword ITEM_TM62
    .hword ITEM_TM88
    .hword ITEM_TM110
    .hword ITEM_TM112
    .hword ITEM_TM113
    .hword ITEM_TM114
    .hword ITEM_TM115
    .hword ITEM_TM117
    .hword ITEM_TM119
    .hword ITEM_TM120
    .hword 0x0

@@@@@@@@@@@@@@@@@@@@@@
@ Brendan's Mom
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Brendan_Mom:
    lock
    faceplayer
    msgbox gText_Brendan_Mom MSG_FACE
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Brendan's Uncle
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Brendan_Uncle:
    lock
    faceplayer
    checkflag 0x935
    if SET _goto EventScript_Brendan_Uncle_AfterVermillion
    msgbox gtext_Brendan_Uncle1 MSG_FACE
    release
    end

EventScript_Brendan_Uncle_AfterVermillion:
    lock
    faceplayer
    msgbox gtext_Brendan_Uncle2 MSG_FACE
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Brendan Cerulean
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Cerulean_Brendan:
    lock
    faceplayer
    call BrendanNameBox
    msgbox gText_Cerulean_BrendanSpeaks1 MSG_FACE
    callasm RemoveNameBox
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ May Cerulean
@@@@@@@@@@@@@@@@@@@@@@
EventsScript_Cerulean_May:
    lock
    faceplayer
    playsong 0x1A7
    checkflag 0x4B1
    if SET _goto EventScript_Cerulean_PlayerDefeatMisty
    checkflag 0x29B
    if SET _goto EventScript_Cerulean_PlayerMetRival
    call MayNameBox
    msgbox gText_Cerulean_May_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    fadedefaultbgm
    release
    end

EventScript_Cerulean_PlayerMetRival:
    call MayNameBox
    msgbox gText_Cerulean_May_Speak_2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    fadedefaultbgm
    release
    end

EventScript_Cerulean_PlayerDefeatMisty:
    pause 15
    sound 0x15
    applymovement 14 Move_Cerulean_May_1
    waitmovement 14
    call MayNameBox
    msgbox gText_Cerulean_May_Speak_3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    fadescreen 0x1
    hidesprite 14
    setflag FLAG_MAY_CERULEAN_SPRITE
    fadescreen 0x0
    fadedefaultbgm
    release
    end

Move_Cerulean_May_1:
    .byte exclaim
    .byte pause_long
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Rival Cerulean
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Cerulean_Rival0:
    lockall
    setvar 0x4001 0x0
    goto EventScript_0x81664CC

EventScript_Cerulean_Rival1:
    lockall
    setvar 0x4001 0x1
    movesprite2 0x8 0x17 0x0
    goto EventScript_0x81664CC

EventScript_Cerulean_Rival2:
    lockall
    setvar 0x4001 0x2
    movesprite2 0x8 0x18 0x0
    goto EventScript_0x81664CC

EventScript_0x81664CC:
    setvar 0x4054 0x2
    playsong 0x13B 0x0
    showsprite 0x8
    applymovement 0x8 0x81665D3
    waitmovement 0x0
    call RivalNameBox
    msgbox gText_Cerulean_RivalSpeaks1 MSG_KEEPOPEN
    callasm RemoveNameBox
    setvar LASTTALKED 0x8
    compare 0x4031 0x2
    if 0x1 _call 0x8166582
    compare 0x4031 0x1
    if 0x1 _call 0x816658D
    compare 0x4031 0x0
    if 0x1 _call 0x8166598
    setvar 0x8004 0xD
    setvar 0x8005 0x0
    special 0x173
    call RivalNameBox
    msgbox gText_Cerulean_RivalSpeaks2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    playsong 0x13C 0x0
    compare 0x4001 0x0
    if 0x1 _call 0x81665A3
    compare 0x4001 0x1
    if 0x1 _call 0x81665A3
    compare 0x4001 0x2
    if 0x1 _call 0x81665B5
    call RivalNameBox
    msgbox gText_Cerulean_RivalSpeaks3 MSG_KEEPOPEN
    callasm RemoveNameBox
    setvar 0x4052 0x1
    setflag 0x29B
    giveitem 0x16B 0x1 MSG_OBTAIN
    call RivalNameBox
    msgbox gText_Cerulean_RivalSpeaks4 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 0x8 0x81665FB
    waitmovement 0x0
    fadedefault
    hidesprite 0x8
    hidesprite 14
    setflag FLAG_MAY_CERULEAN_SPRITE
    releaseall
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Clefairy Lady | Jirachi Event
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Ceruleann_TeachDazzlingGleam_Clefairy:
    faceplayer
    cry SPECIES_CLEFAIRY 0x0
    msgbox gText_Ceruleann_TeachDazzlingGleam_Clefairy_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_Ceruleann_TeachDazzlingGleam_Lady:
    lock
    faceplayer
    checkflag FLAG_TEACH_CLEFAIRY_DAZZLING_GLEAM
    if SET _goto EventScript_Ceruleann_TeachDazzlingGleam_Done
    msgbox gText_Ceruleann_TeachDazzlingGleam_Lady_Speak_1 MSG_YESNO
    compare LASTRESULT 0x1
    if FALSE _goto EventScript_Ceruleann_TeachDazzlingGleam_Rejected
    pause 45
    checkitem ITEM_TM102 0x1
    compare LASTRESULT 0x1
    if FALSE _goto EventScript_Ceruleann_TeachDazzlingGleam_PlayerDoesntHaveIt
    sound 0x2
    msgbox gText_Ceruleann_TeachDazzlingGleam_Narrator_1 MSG_KEEPOPEN
    closeonkeypress
    fanfare 0x13E
    waitfanfare
    applymovement 0x6 Move_Ceruleann_TeachDazzlingGleam_Clefairy
    waitmovement 0x6
    cry SPECIES_CLEFAIRY 0x0
    msgbox gText_Ceruleann_TeachDazzlingGleam_Clefairy_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    msgbox gText_Ceruleann_TeachDazzlingGleam_Lady_Speak_2 MSG_KEEPOPEN
    closeonkeypress
    pause 60
    fadescreenspeed 0x3 5
    cry SPECIES_JIRACHI 0x0
    fadescreenspeed 0x2 5
    msgbox gText_Ceruleann_TeachDazzlingGleam_Narrator_2 MSG_KEEPOPEN
    closeonkeypress
    setflag FLAG_TEACH_CLEFAIRY_DAZZLING_GLEAM
    release
    end

EventScript_Ceruleann_TeachDazzlingGleam_Rejected:
    msgbox gText_Ceruleann_TeachDazzlingGleam_Lady_Rejected MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_Ceruleann_TeachDazzlingGleam_Done:
    msgbox gText_Ceruleann_TeachDazzlingGleam_Lady_Speak_2 MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_Ceruleann_TeachDazzlingGleam_PlayerDoesntHaveIt:
    msgbox gText_Ceruleann_TeachDazzlingGleam_PlayerDoesntHaveIt MSG_KEEPOPEN
    closeonkeypress
    release
    end

Move_Ceruleann_TeachDazzlingGleam_Clefairy:
    .byte jump_onspot_down
    .byte jump_onspot_down
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Cerulean NameBox
@@@@@@@@@@@@@@@@@@@@@@
MayNameBox:
    setvar 0x8000 2
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

RivalNameBox:
    setvar 0x8000 1
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

MistyNameBox:
    setvar 0x8000 12
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

BrendanNameBox:
    setvar 0x8000 3
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
