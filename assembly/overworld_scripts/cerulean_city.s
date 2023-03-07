.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_GIFT_SANDILE, 0x0BE
.equ FLAG_BRENDAN_CERULEAN_SPRITE, 0x938
.equ FLAG_BRENDAN_UNCLE_CERULEAN_SPRITE, 0x939
.equ FLAG_MAY_CERULEAN_SPRITE, 0x93D

@@@@@@@@@@@@@@@@@@@@@@
@ Sandile Gift | Wise Glasses | Cerulean City
@@@@@@@@@@@@@@@@@@@@@@
EventScript_SandileGift:
    textcolor BLUE
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
    textcolor BLUE
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
    textcolor RED
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
    textcolor BLUE
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
    textcolor BLUE
    msgbox gText_Cerulean_BrendanSpeaks1 MSG_FACE
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Brendan Cerulean
@@@@@@@@@@@@@@@@@@@@@@
EventsScript_Cerulean_May:
    lock
    faceplayer
    textcolor RED
    msgbox gText_Cerulean_MaySpeaks1 MSG_KEEPOPEN
    closeonkeypress
    fadescreen 0x1
    hidesprite 14
    setflag FLAG_MAY_CERULEAN_SPRITE
    fadescreen 0x0
    release
    end
