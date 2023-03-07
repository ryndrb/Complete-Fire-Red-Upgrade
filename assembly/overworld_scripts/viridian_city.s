.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_SWORDS_DANCE, 0x0D8
.equ FLAG_NURSE_JOY_POKE_VIAL, 0x310
.equ FLAG_MAY_ROUTE1_SPRITE, 0x93B
.equ VAR_MAY_ROUTE1_ENCOUNTER, 0x5030

@@@@@@@@@@@@@@@@@@@@@@
@ Swords Dance | Viridian City Old Man | Beat Giovanni
@@@@@@@@@@@@@@@@@@@@@@
EventScript_ViridianSwordsDance:
    textcolor BLUE
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
    textcolor RED
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

@@@@@@@@@@@@@@@@@@@@@@
@ Viridan Pokemart
@@@@@@@@@@@@@@@@@@@@@@
MapScript_0x16A1DE:
    mapscript MAP_SCRIPT_ON_LOAD SetMapTileScript_0x16A1DE
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_0x16A1DE
    .byte MAP_SCRIPT_TERMIN

LevelScript_0x16A1DE:
    levelscript 0x4057, 0, EventScript_0x16A205
    .hword LEVEL_SCRIPT_TERMIN

SetMapTileScript_0x16A1DE:
    checkflag 0x829
    if 0x0 _goto EventScript_0x816A1E8
    end

EventScript_0x816A1E8:
    setmaptile 0x1 0x3 0x2BF 0x1
    setmaptile 0x1 0x4 0x2C0 0x1
    end

EventScript_0x16A205:
    lockall
    textcolor 0x0
    applymovement 0x1 0x81A75ED
    waitmovement 0x0
    msgbox 0x819021A MSG_KEEPOPEN
    closeonkeypress
    applymovement 0x1 0x816A262
    applymovement PLAYER 0x816A25C
    waitmovement 0x0
    msgbox 0x819023A MSG_KEEPOPEN
    setvar 0x4057 0x1
    additem 0x15D 0x1
    loadpointer 0x0 0x8190289
    giveitemwithfanfare 0x15D 0x1 0x13E
    setvar 0x4055 0x5
    setvar VAR_MAY_ROUTE1_ENCOUNTER 0x0
    clearflag FLAG_MAY_ROUTE1_SPRITE
    releaseall
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Old Fising Rod
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Viridian_OldRod:
    lock
    faceplayer
    checkflag 0x240
    if 0x1 _goto 0x816B3CF
    msgbox 0x8193EC1 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x816B3D9
    msgbox 0x8194028 MSG_KEEPOPEN
    release
    end
