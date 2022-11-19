.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ VAR_MEW_VERMILLION_CITY_ENCOUNTER, 0x5014
.equ FLAG_OBTAIN_EVIOLITE, 0x0BB
.equ FLAG_MEW_VERMILLION_CITY_ENCOUNTER, 0x301

@@@@@@@@@@@@@@@@@@@@
@ Eviolite
@@@@@@@@@@@@@@@@@@@@
EventScript_Eviolite:
    lock
    faceplayer
    checkflag FLAG_OBTAIN_EVIOLITE
    if 0x0 _goto EventScript_GiveEviolite
    msgbox gText_GenericDialogue MSG_FACE
    end

EventScript_GiveEviolite:
    msgbox gText_EventScript_GiveEviolite MSG_FACE
    applymovement 0x2 EventScript_GiveEvioliteNPCMove
    waitmovement 0x2
    msgbox gText_EventScript_GiveEviolite2 MSG_FACE
    giveitem ITEM_EVIOLITE 0x1 MSG_OBTAIN
    msgbox gText_EventScript_GiveEviolite3 MSG_FACE
    setflag FLAG_OBTAIN_EVIOLITE
    release
    end

EventScript_GiveEvioliteNPCMove:
    .byte exclaim
    .byte end_m

@@@@@@@@@@@@@@@@@@@@
@ Power Items Seller Old Man
@@@@@@@@@@@@@@@@@@@@
EventScript_PowerItemsSeller:
    lock
    faceplayer
    msgbox gText_EventScript_PowerItemsSeller MSG_KEEPOPEN
    pokemart EventScript_PowerItemsList
    msgbox gText_PowerItemsSelleComeAgain MSG_KEEPOPEN
    release
    end

.align 1
EventScript_PowerItemsList:
    .hword ITEM_POWER_ANKLET
    .hword ITEM_POWER_BAND
    .hword ITEM_POWER_BELT
    .hword ITEM_POWER_BRACER
    .hword ITEM_POWER_LENS
    .hword ITEM_POWER_WEIGHT
    .hword 0x0

@@@@@@@@@@@@@@@@@@@@
@ Mew Under Truck | Req. Champion | Re-battle if not beat or catch
@@@@@@@@@@@@@@@@@@@@
EventScript_MewUnderTruckEncounter:
    lock
    call EventScript_ReturnMewEvent
    checkflag 0x4BC
    if 0x1 _goto EventScript_MewEncounter
    release
    end

EventScript_ReturnMewEvent:
    applymovement PLAYER EventScript_PlayerMovementMew1
    waitmovement 0x0
    pause 30
    msgbox gText_SomethingHere MSG_FACE
    return

EventScript_MewEncounter:
    applymovement PLAYER EventScript_PlayerMovementMew2
    waitmovement 0x0
    pause 30
    cry SPECIES_MEW 0x0
    msgbox gText_MewString MSG_KEEPOPEN
    wildbattle SPECIES_MEW 30 0x0
    fadescreen 0x1
    hidesprite 0x9
    fadescreen 0x0
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_DidNotBeatCatchMew
    setvar VAR_MEW_VERMILLION_CITY_ENCOUNTER 0x1
    release
    end

EventScript_PlayerMovementMew1:
    .byte say_question
    .byte look_left
    .byte end_m

EventScript_PlayerMovementMew2:
    .byte exclaim
    .byte end_m

EventScript_DidNotBeatCatchMew:
    release
    end

@@@@@@@@@@@@@@@@@@@@
@ Vermillion City TM Merchant
@@@@@@@@@@@@@@@@@@@@
EventScript_VermillionTMMerchant:
    lock
    faceplayer
    msgbox gText_VermillionTMMerchantGreet MSG_KEEPOPEN
    pokemart EventScript_VermillionTMMerchantList
    msgbox gText_VermillionTMMerchantBye MSG_KEEPOPEN
    closeonkeypress
    release
    end

.align 1
EventScript_VermillionTMMerchantList:
    .hword ITEM_TM57
    .hword ITEM_TM58
    .hword ITEM_TM67
    .hword ITEM_TM73
    .hword ITEM_TM76
    .hword ITEM_TM78
    .hword ITEM_TM87
    .hword ITEM_TM92
    .hword ITEM_TM93
    .hword ITEM_TM96
    .hword 0x0
