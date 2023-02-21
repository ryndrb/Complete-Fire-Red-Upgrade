.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_AERODACTYLITE, 0x0F9
.equ FLAG_OBTAIN_GYARADOSITE, 0x0FA
.equ FLAG_OBTAIN_MANECTITE, 0x0FB
.equ FLAG_OBTAIN_ABOMASITE, 0x0FC
.equ FLAG_OBTAIN_ALAKAZITE, 0x0FD
.equ FLAG_OBTAIN_GENGARITE, 0x0FE
.equ FLAG_OBTAIN_HOUNDOOMINITE, 0x0FF
.equ FLAG_OBTAIN_STEELIXITE, 0x100

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
    msgbox 0x819110F MSG_KEEPOPEN
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
    msgbox 0x8190FF8 MSG_KEEPOPEN
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

@@@@@@@@@@@@@@@@@@@@@@
@ Misty
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymLeaderMisty:
    setvar 0x8004 0x3
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x19F 0x0 0x81921EF 0x819242D EventScript_0x816AAD3
    checkflag 0x297
    if 0x0 _goto EventScript_0x816AAF9
    msgbox 0x81922BF MSG_KEEPOPEN
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
    msgbox 0x81922F7 MSG_KEEPOPEN
    checkitemspace 0x123 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816AB3A
    giveitem_msg 0x81923F1 ITEM_TM03
    setflag 0x297
    msgbox 0x81922BF MSG_KEEPOPEN
    release
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
@ Surge
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymLeaderSurge:
    setvar 0x8004 0x4
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x1A0 0x0 0x8194BA4 0x8194E03 EventScript_0x816B97C
    checkflag 0x231
    if 0x0 _goto EventScript_0x816B9AF
    msgbox 0x8194C8E MSG_KEEPOPEN
    release
    end

EventScript_0x816B97C:
    setvar 0x8004 0x4
    setvar 0x8005 0x1
    special 0x173
    checkflag 0x23B
    if 0x0 _call 0x816B9AB
    clearflag 0xA0
    setflag 0x4B2
    setflag 0x822
    setvar 0x8008 0x3
    call 0x81A6B18
    goto EventScript_0x816B9AF
    end

EventScript_0x816B9AF:
    msgbox 0x8194CFA MSG_KEEPOPEN
    checkitemspace 0x142 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816B9F0
    giveitem_msg 0x8194D87 ITEM_TM34
    setflag 0x231
    msgbox 0x8194DA8 MSG_KEEPOPEN
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Manectite | Vermillion City | Gym Guy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymGuyManectite:
    lock
    faceplayer
    checkflag 0x4B2
    if 0x1 _goto EventScript_GiveManectite
    msgbox 0x8191298 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x816A689
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816A697
    end

EventScript_GiveManectite:
    checkflag FLAG_OBTAIN_MANECTITE
    if 0x1 _goto Obtained
    msgbox gText_GymGuyGiveStone MSG_KEEPOPEN
    giveitem ITEM_MANECTITE 0x1 MSG_OBTAIN
    bufferitem 0x0 ITEM_MANECTITE
    bufferpokemon 0x1 SPECIES_MANECTRIC
    msgbox gText_ObtainedStone MSG_KEEPOPEN
    setflag FLAG_OBTAIN_MANECTITE
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Erika
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymLeaderErika:
    setvar 0x8004 0x5
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x1A1 0x0 0x8197114 0x8197260 EventScript_0x816D0A0
    checkflag 0x293
    if 0x0 _goto 0x816D0C6
    setvar 0x8004 0x5
    setvar 0x8005 0x4
    special 0x173
    msgbox 0x81972B8 MSG_KEEPOPEN
    release
    end

EventScript_0x816D0A0:
    setvar 0x8004 0x5
    setvar 0x8005 0x1
    special 0x173
    clearflag 0x9E
    setflag 0x4B3
    setflag 0x823
    clearflag 0x101
    setvar 0x8008 0x4
    call 0x81A6B18
    goto EventScript_0x816D0C6
    end

EventScript_0x816D0C6:
    msgbox 0x8197327 MSG_KEEPOPEN
    checkitemspace 0x133 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816D107
    giveitem_msg 0x81973BA ITEM_TM19
    setflag 0x293
    setvar 0x502E 0x1
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Abomasite | Celadon City | Gym Guy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymGuyAbomasite:
    lock
    faceplayer
    checkflag 0x4B3
    if 0x1 _goto EventScript_GiveAbomasite
    msgbox 0x8191298 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x816A689
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816A697
    end

EventScript_GiveAbomasite:
    checkflag FLAG_OBTAIN_ABOMASITE
    if 0x1 _goto Obtained
    msgbox gText_GymGuyGiveStone MSG_KEEPOPEN
    giveitem ITEM_ABOMASITE 0x1 MSG_OBTAIN
    bufferitem 0x0 ITEM_ABOMASITE
    bufferpokemon 0x1 SPECIES_ABOMASNOW
    msgbox gText_ObtainedStone MSG_KEEPOPEN
    setflag FLAG_OBTAIN_ABOMASITE
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Sabrina
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymLeaderSabrina:
    setvar 0x8004 0x7
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x1A4 0x0 0x819B53C 0x819B602 EventScript_0x816EE0A
    checkflag 0x29A
    if 0x0 _goto 0x816EE3D
    msgbox 0x819B7F2 MSG_KEEPOPEN
    release
    end

EventScript_0x816EE0A:
    setvar 0x8004 0x7
    setvar 0x8005 0x2
    special 0x173
    setvar 0x8004 0x7
    setvar 0x8005 0x3
    special 0x173
    clearflag 0xAE
    setflag 0x4B5
    setflag 0x825
    clearflag 0x035
    setvar 0x8008 0x6
    call 0x81A6B18
    goto EventScript_0x816EE3D
    end

EventScript_0x816EE3D:
    msgbox 0x819B6FA MSG_KEEPOPEN
    checkitemspace 0x124 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816EE7E
    giveitem_msg 0x819B7D3 ITEM_TM04
    setflag 0x29A
    msgbox 0x819B685 MSG_KEEPOPEN
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Alakazite | Saffron City | Gym Guy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymGuyAlakazite:
    lock
    faceplayer
    checkflag 0x4B5
    if 0x1 _goto EventScript_GiveAlakazite
    msgbox 0x8191298 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x816A689
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816A697
    end

EventScript_GiveAlakazite:
    checkflag FLAG_OBTAIN_ALAKAZITE
    if 0x1 _goto Obtained
    msgbox gText_GymGuyGiveStone MSG_KEEPOPEN
    giveitem ITEM_ALAKAZITE 0x1 MSG_OBTAIN
    bufferitem 0x0 ITEM_ALAKAZITE
    bufferpokemon 0x1 SPECIES_ALAKAZAM
    msgbox gText_ObtainedStone MSG_KEEPOPEN
    setflag FLAG_OBTAIN_ALAKAZITE
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Koga
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymLeaderKoga:
    setvar 0x8004 0x6
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x1A2 0x0 0x819832E 0x8198444 EventScript_0x816D580
    checkflag 0x259
    if 0x0 _goto 0x816D5A6
    msgbox 0x8198481 MSG_KEEPOPEN
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
    msgbox 0x819850E MSG_KEEPOPEN
    checkitemspace 0x126 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816D5E7
    giveitem_msg 0x819858F ITEM_TM06
    setflag 0x259
    msgbox 0x81985AB MSG_KEEPOPEN
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

@@@@@@@@@@@@@@@@@@@@@@
@ Blaine
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymLeaderBlaine:
    setvar 0x8004 0x8
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x1A3 0x0 0x8199543 0x81995FA EventScript_0x816DA06
    checkflag 0x24E
    if 0x0 _goto 0x816DA34
    msgbox 0x819971D MSG_KEEPOPEN
    release
    end

EventScript_0x816DA06:
    setvar 0x8004 0x8
    setvar 0x8005 0x1
    special 0x173
    setflag 0x4B6
    setflag 0x826
    sethealingplace 0x9
    setvar 0x4071 0x1
    clearflag 0x62
    setvar 0x8008 0x7
    call 0x81A6B18
    goto EventScript_0x816DA34
    end

EventScript_0x816DA34:
    msgbox 0x819969E MSG_KEEPOPEN
    checkitemspace 0x146 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816DA75
    giveitem_msg 0x81996FF ITEM_TM38
    setflag 0x24E
    msgbox 0x8199652 MSG_KEEPOPEN
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Houndoominite | Cinnabar Island | Gym Guy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymGuyHoundoominite:
    lock
    faceplayer
    checkflag 0x4B6
    if 0x1 _goto EventScript_GiveHoundoominite
    msgbox 0x8191298 MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto 0x816A689
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816A697
    end

EventScript_GiveHoundoominite:
    checkflag FLAG_OBTAIN_HOUNDOOMINITE
    if 0x1 _goto Obtained
    msgbox gText_GymGuyGiveStone MSG_KEEPOPEN
    giveitem ITEM_HOUNDOOMINITE 0x1 MSG_OBTAIN
    bufferitem 0x0 ITEM_HOUNDOOMINITE
    bufferpokemon 0x1 SPECIES_HOUNDOOM
    msgbox gText_ObtainedStone MSG_KEEPOPEN
    setflag FLAG_OBTAIN_HOUNDOOMINITE
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Goivanni
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymLeaderGiovanni:
    setvar 0x8004 0xF
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x15E 0x0 0x818F352 0x818F43F EventScript_0x8169F04
    checkflag 0x298
    if 0x0 _goto 0x8169F2F
    msgbox 0x818F4A2 MSG_KEEPOPEN
    closeonkeypress
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
    msgbox 0x818F586 MSG_KEEPOPEN
    checkitemspace 0x13A 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x8169F70
    giveitem_msg 0x818F675 ITEM_TM26
    setflag 0x298
    msgbox 0x818F695 MSG_KEEPOPEN
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
