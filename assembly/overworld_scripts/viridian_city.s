.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ Goivanni
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymLeaderGiovanni:
    setvar 0x8004 0xF
    setvar 0x8005 0x2
    special 0x174
    call GiovanniNameBox
    trainerbattle1 0x1 0x15E 0x0 0x818F352 0x818F43F EventScript_0x8169F04
    checkflag 0x298
    if 0x0 _goto 0x8169F2F
    call GiovanniNameBox
    msgbox 0x818F4A2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    fadescreen 0x1
    hidesprite 0x8
    fadescreen 0x0
    release
    end

EventScript_0x8169F04:
    setvar 0x8004 0xF
    setvar 0x8005 0x3
    special 0x173
    setflag 0xAD
    setflag 0x4B7
    setflag 0x827
    setvar 0x4054 0x3
    setvar 0x8008 0x8
    call 0x81A6B18
    goto 0x8169F2F
    end

EventScript_0x8169F2F:
    call GiovanniNameBox
    msgbox 0x818F586 MSG_KEEPOPEN
    callasm RemoveNameBox
    checkitemspace 0x13A 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x8169F70
    giveitem_msg 0x818F675 ITEM_TM26
    setflag 0x298
    call GiovanniNameBox
    msgbox 0x818F695 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Steelixite | Cinnabar Island | Gym Guy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymGuySteelixite:
    lock
    faceplayer
    checkflag 0x4B7
    if 0x1 _goto EventScript_GiveSteelixite
    msgbox 0x8191298 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x816A689
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816A697
    end

EventScript_GiveSteelixite:
    checkflag FLAG_OBTAIN_STEELIXITE
    if 0x1 _goto Obtained
    msgbox gText_GymGuyGiveStone MSG_KEEPOPEN
    giveitem ITEM_STEELIXITE 0x1 MSG_OBTAIN
    bufferitem 0x0 ITEM_STEELIXITE
    bufferpokemon 0x1 SPECIES_STEELIX
    msgbox gText_ObtainedStone MSG_KEEPOPEN
    setflag FLAG_OBTAIN_STEELIXITE
    release
    end

Obtained:
    goto 0x816A67F
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Swords Dance | Viridian City Old Man | Beat Giovanni
@@@@@@@@@@@@@@@@@@@@@@
EventScript_ViridianSwordsDance:
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
    lock
    faceplayer
    setvar 0x5045 0xA
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
    setvar VAR_MAY_ENCOUNTER 0x1
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

@@@@@@@@@@@@@@@@@@@@@@
@ GS Ball Woman
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Viridian_GSBall:
    lock
    faceplayer
    checkflag 0x4B3
    if NOT_SET _goto EventScript_Viridian_GSBall_PlayerNotChampion
    checkflag FLAG_GS_BALL
    if SET _goto EventScript_Viridian_GSBall_Done
    pause 45
    sound 0x15
    applymovement 0x4 Move_Viridian_GSBall
    waitmovement 0x4
    msgbox gText_Viridian_GSBall_Woman_Speak_1 MSG_KEEPOPEN
    msgbox gText_Viridian_GSBall_Woman_Speak_2 MSG_KEEPOPEN
    closeonkeypress
    fanfare 0x13E
    msgbox gText_Viridian_GSBall_Narrator_1 MSG_KEEPOPEN
    waitfanfare
    msgbox gText_Viridian_GSBall_Woman_Speak_3 MSG_KEEPOPEN
    closeonkeypress
    setflag FLAG_GS_BALL
    clearflag FLAG_CELEBI_VIRIDIAN_FOREST
    release
    end

EventScript_Viridian_GSBall_PlayerNotChampion:
    msgbox gText_Viridian_GSBall_PlayerNotChampion MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_Viridian_GSBall_Done:
    msgbox gText_Viridian_GSBall_Woman_Speak_3 MSG_KEEPOPEN
    closeonkeypress
    release
    end

Move_Viridian_GSBall:
    .byte exclaim
    .byte pause_long
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Viridian NameBox
@@@@@@@@@@@@@@@@@@@@@@
GiovanniNameBox:
    setvar 0x8000 18
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
