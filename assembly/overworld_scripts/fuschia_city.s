.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_GENGARITE, 0x961
.equ FLAG_OBTAIN_SUBSTITUTE, 0x9A4

@@@@@@@@@@@@@@@@@@@@@@
@ Koga
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymLeaderKoga:
    setvar 0x8004 0x6
    setvar 0x8005 0x2
    special 0x174
    call KogaNameBox
    trainerbattle1 0x1 0x1A2 0x0 0x819832E 0x8198444 EventScript_0x816D580
    checkflag 0x259
    if 0x0 _goto 0x816D5A6
    call KogaNameBox
    msgbox 0x8198481 MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

EventScript_0x816D580:
    setvar 0x8004 0x6
    setvar 0x8005 0x1
    special 0x173
    clearflag 0x9F
    setflag 0x4B4
    setflag 0x824
    setvar 0x8008 0x5
    call 0x81A6B18
    goto EventScript_0x816D5A6
    end

EventScript_0x816D5A6:
    call KogaNameBox
    msgbox 0x819850E MSG_KEEPOPEN
    callasm RemoveNameBox
    checkitemspace 0x126 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816D5E7
    giveitem_msg 0x819858F ITEM_TM06
    setflag 0x259
    call KogaNameBox
    msgbox 0x81985AB MSG_KEEPOPEN
    callasm RemoveNameBox
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Gengarite | Fuschia City | Gym Guy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymGuyGengarite:
    lock
    faceplayer
    setflag 0x4B4
    checkflag 0x4B4
    if 0x1 _goto EventScript_GiveGengarite
    msgbox 0x8191298 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x816A689
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816A697
    end

EventScript_GiveGengarite:
    checkflag FLAG_OBTAIN_GENGARITE
    if 0x1 _goto Obtained
    msgbox gText_GymGuyGiveStone MSG_KEEPOPEN
    giveitem ITEM_GENGARITE 0x1 MSG_OBTAIN
    bufferitem 0x0 ITEM_GENGARITE
    bufferpokemon 0x1 SPECIES_GENGAR
    msgbox gText_ObtainedStone MSG_KEEPOPEN
    setflag FLAG_OBTAIN_GENGARITE
    release
    end

Obtained:
    goto 0x816A67F
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Substitute
@@@@@@@@@@@@@@@@@@@@@@
EventScript_FuschiaSubstitute:
    textcolor BLUE
    lock
    faceplayer
    checkflag FLAG_OBTAIN_SUBSTITUTE
    if 0x0 _goto EventScript_GiveSub
    msgbox gText_WantToBecomeTrainer MSG_FACE
    release
    end

EventScript_GiveSub:
    msgbox gText_KidNotice MSG_KEEPOPEN
    applymovement 0x2 EventScript_KidExclaim
    waitmovement 0x2
    msgbox gText_KidGiveSub MSG_KEEPOPEN
    giveitem ITEM_TM90 0x1 MSG_OBTAIN
    msgbox gText_ObtainedSubstitute MSG_KEEPOPEN
    setflag FLAG_OBTAIN_SUBSTITUTE
    release
    end

EventScript_KidExclaim:
    .byte exclaim
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Former Substitute Kid
@@@@@@@@@@@@@@@@@@@@@@
EventScript_FormerSubstituteKid:
    lock
    faceplayer
    msgbox gText_FormerSubstituteKid MSG_KEEPOPEN
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Retired Fisherman
@@@@@@@@@@@@@@@@@@@@@@
EventScript_RetiredFisherMan:
    lock
    faceplayer
    textcolor BLUE
    msgbox gText_RetireFisherManSpeak1 MSG_KEEPOPEN
    msgbox gText_RetireFisherManSpeak2 MSG_KEEPOPEN
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Fuschia NameBox
@@@@@@@@@@@@@@@@@@@@@@
KogaNameBox:
    setvar 0x8000 16
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
