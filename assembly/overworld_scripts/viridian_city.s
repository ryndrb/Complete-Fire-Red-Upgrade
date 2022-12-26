.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_SWORDS_DANCE, 0x0D8
.equ FLAG_NURSE_JOY_POKE_VIAL, 0x310

@@@@@@@@@@@@@@@@@@@@@@
@ Swords Dance | Viridian City Old Man | Beat Giovanni
@@@@@@@@@@@@@@@@@@@@@@
EventScript_ViridianSwordsDance:
    textcolor 0x0
    lock
    faceplayer
    checkflag FLAG_OBTAIN_SWORDS_DANCE
    if 0x0 _goto EventScript_BeatGiovanni
    compare 0x405A 0x1
    if 0x1 _goto 0x81659EC
    msgbox 0x817DB39 MSG_FACE
    applymovement 0x3 0x81A75E5
    waitmovement 0x0
    release
    end

EventScript_BeatGiovanni:
    checkflag 0x4B7
    if 0x1 _goto EventScript_GiveSwordsDance
    msgbox 0x817DB39 MSG_FACE
    end

EventScript_GiveSwordsDance:
    msgbox gText_GiveSwordsDance MSG_KEEPOPEN
    giveitem ITEM_TM75 0x1 MSG_OBTAIN
    msgbox gText_GiveSwordsDanceObtained MSG_KEEPOPEN
    setflag FLAG_OBTAIN_SWORDS_DANCE
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Nurse Joy Give Poke Vial
@@@@@@@@@@@@@@@@@@@@@@
EventScript_NurseJoyViridian:
    textcolor 0x1
    lock
    faceplayer
    setvar 0x502D 0xA
    checkflag FLAG_NURSE_JOY_POKE_VIAL
    if 0x0 _goto EventScript_GiveVial
    call 0x81A6578
    release
    end

EventScript_GiveVial:
    msgbox gText_NurseJoyGiveVial MSG_KEEPOPEN
    msgbox gText_PlayerReceievedVial MSG_KEEPOPEN
    msgbox gText_NurseJoyExplainsVial MSG_KEEPOPEN
    setflag FLAG_NURSE_JOY_POKE_VIAL
    release
    end
