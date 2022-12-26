.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_GIFT_TIMBURR, 0x0BD

@@@@@@@@@@@@@@@@@@@@@@
@ Timburr Gift | Muscle Band | Route 3
@@@@@@@@@@@@@@@@@@@@@@
EventScript_TimburrGift:
    textcolor 0x0
    lock
    faceplayer
    checkflag FLAG_OBTAIN_GIFT_TIMBURR
    if 0x0 _goto EventScript_GiveTimburr
    msgbox gText_EventScript_PostGift MSG_FACE
    release
    end

EventScript_GiveTimburr:
    msgbox 0x8183491 MSG_KEEPOPEN
    msgbox gText_LendWater MSG_KEEPOPEN
    fanfare 0x101
    msgbox gText_Lending MSG_KEEPOPEN
    waitfanfare
    msgbox gText_Gulping MSG_KEEPOPEN
    msgbox gText_EventScript_GiveTimburr MSG_KEEPOPEN
    givepokemoncustom SPECIES_TIMBURR 15 ITEM_MUSCLE_BAND MOVE_ROCKTHROW MOVE_LOWKICK MOVE_MACHPUNCH MOVE_POWERUPPUNCH NATURE_ADAMANT 0 31 31 31 0 31 0 0 0
    showpokepic SPECIES_TIMBURR 0xA 0x3
    fanfare 0x13E
    msgbox gText_ReceivedTimburr MSG_KEEPOPEN
    waitfanfare
    hidepokepic
    setflag FLAG_OBTAIN_GIFT_TIMBURR
    msgbox gText_AfterReceivingTimburr MSG_KEEPOPEN
    closeonkeypress
    release
    end
