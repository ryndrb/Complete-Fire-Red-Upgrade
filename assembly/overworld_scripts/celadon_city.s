.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ GIOVANNI, 1
.equ ARIANA, 11
.equ JESSIE, 12
.equ JAMES, 14
.equ MEOWTH, 13
.equ CUBONE, 15

@@@@@@@@@@@@@@@@@@@@@@
@ Erika
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GymLeaderErika:
    setvar 0x8004 0x5
    setvar 0x8005 0x2
    special 0x174
    call ErikaNameBox
    checkflag 0x4B3
    if SET _goto EventScript_Celadon_GymLeaderErika2
    msgbox gText_Celadon_ErikaSpeak1 MSG_KEEPOPEN
    msgbox gText_Celadon_ErikaSpeak2 MSG_KEEPOPEN
    trainerbattle1 0x1 0x1A1 0x0 gText_Celadon_ErikaSpeak3 0x8197260 EventScript_0x816D0A0
    checkflag 0x293
    if 0x0 _goto EventScript_0x816D0C6
    goto EventScript_Celadon_GymLeaderErika2
    release
    end

EventScript_Celadon_GymLeaderErika2:
    setvar 0x8004 0x5
    setvar 0x8005 0x4
    special 0x173
    call ErikaNameBox
    msgbox 0x81972B8 MSG_KEEPOPEN
    callasm RemoveNameBox
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
    call ErikaNameBox
    msgbox 0x8197327 MSG_KEEPOPEN
    callasm RemoveNameBox
    checkitemspace 0x133 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816D107
    giveitem_msg 0x81973BA ITEM_TM19
    setflag 0x293
    setvar 0x5046 0x1
    setvar VAR_ROAMING_DOGS_EVENT 0x1
    clearflag FLAG_EUSINE_SPRITE_CELADON_OUTSIDE
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

Obtained:
    goto 0x816A67F
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Poke Ball Types Celadon Dep. Store
@@@@@@@@@@@@@@@@@@@@@@
EventScript_StorePokeBalls:
    lock
    faceplayer
    preparemsg 0x81A6211
    waitmsg 
    pokemart EventScript_StorePokeBallsList
    msgbox 0x81A5190 MSG_NORMAL
    release
    end

.align 1
EventScript_StorePokeBallsList:
    .hword ITEM_CHERISH_BALL
    .hword ITEM_DIVE_BALL
    .hword ITEM_DUSK_BALL
    .hword ITEM_FAST_BALL
    .hword ITEM_FRIEND_BALL
    .hword ITEM_HEAL_BALL
    .hword ITEM_HEAVY_BALL
    .hword ITEM_LEVEL_BALL
    .hword ITEM_LOVE_BALL
    .hword ITEM_LURE_BALL
    .hword ITEM_LUXURY_BALL
    .hword ITEM_MOON_BALL
    .hword ITEM_NEST_BALL
    .hword ITEM_NET_BALL
    .hword ITEM_PREMIER_BALL
    .hword ITEM_QUICK_BALL
    .hword ITEM_REPEAT_BALL
    .hword ITEM_TIMER_BALL
    .hword ITEM_BEAST_BALL
    .hword 0x0

@@@@@@@@@@@@@@@@@@@@@@
@ TMs Celadon Dep. Store
@@@@@@@@@@@@@@@@@@@@@@
EventScript_StoreTM:
    lock
    faceplayer
    preparemsg 0x81A6211
    waitmsg 
    pokemart EventScript_StoreTMList
    msgbox 0x81A5190 MSG_NORMAL
    release
    end

.align 1
EventScript_StoreTMList:
    .hword ITEM_TM10
    .hword ITEM_TM14
    .hword ITEM_TM15
    .hword ITEM_TM16
    .hword ITEM_TM17
    .hword ITEM_TM20
    .hword ITEM_TM33
    .hword ITEM_TM52
    .hword ITEM_TM68
    .hword 0x0

@@@@@@@@@@@@@@@@@@@@@@
@ TMs Celadon Game Corner
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GameCornerTM:
    lock
    faceplayer
    preparemsg 0x81A6211
    waitmsg 
    pokemart EventScript_GameCornerTMList
    msgbox 0x81A5190 MSG_NORMAL
    release
    end

.align 1
EventScript_GameCornerTMList:
    .hword ITEM_TM35
    .hword ITEM_TM36
    .hword ITEM_TM49
    .hword ITEM_TM53
    .hword ITEM_TM83
    .hword ITEM_TM89
    .hword ITEM_TM97
    .hword ITEM_TM101
    .hword ITEM_TM105
    .hword ITEM_TM106
    .hword 0x0

@@@@@@@@@@@@@@@@@@@@@@
@ Mega Stones Celadon Game Corner
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GameCornerMegaStones:
    lock
    faceplayer
    checkflag 0x243
    if 0x0 _goto 0x816CD99
    special 0x187
    compare LASTRESULT 0x2
    if 0x1 _goto 0x81A7AE0
    showcoins 0x14 0x0
    msgbox 0x8197057 MSG_KEEPOPEN @ we exchange coins for prices
    goto EventScript_MegaStoneList
    end

EventScript_MegaStoneList:
    msgbox gText_GameCornerStartMessage MSG_KEEPOPEN
    setvar 0x8000 13
    setvar 0x8001 0x5
    setvar 0x8004 0x0
    special 0x158
    waitstate
    switch LASTRESULT
    compare LASTRESULT 11
    if greaterorequal _goto 0x816CC10
    case 0, EventScript_Blatoisinite
    case 1, EventScript_Blazikenite
    case 2, EventScript_CharizarditeX
    case 3, EventScript_CharizarditeY
    case 4, EventScript_Garchampite
    case 5, EventScript_Metagrossite
    case 6, EventScript_Salamencite
    case 7, EventScript_Sceptilite
    case 8, EventScript_Swampertite
    case 9, EventScript_Tyranitarite
    case 10, EventScript_Venusaurite
    end

EventScript_Blatoisinite:
    setvar 0x4001 ITEM_BLASTOISINITE
    setvar 0x4002 0x1F4
    goto EventScript_ChoseMegaStone
    end

EventScript_Blazikenite:
    setvar 0x4001 ITEM_BLAZIKENITE
    setvar 0x4002 0x1F4
    goto EventScript_ChoseMegaStone
    end

EventScript_CharizarditeX:
    setvar 0x4001 ITEM_CHARIZARDITE_X
    setvar 0x4002 0x1F4
    goto EventScript_ChoseMegaStone
    end

EventScript_CharizarditeY:
    setvar 0x4001 ITEM_CHARIZARDITE_Y
    setvar 0x4002 0x1F4
    goto EventScript_ChoseMegaStone
    end

EventScript_Garchampite:
    setvar 0x4001 ITEM_GARCHOMPITE
    setvar 0x4002 0x3E7
    goto EventScript_ChoseMegaStone
    end

EventScript_Metagrossite:
    setvar 0x4001 ITEM_METAGROSSITE
    setvar 0x4002 0x3E7
    goto EventScript_ChoseMegaStone
    end

EventScript_Salamencite:
    setvar 0x4001 ITEM_SALAMENCITE
    setvar 0x4002 0x3E7
    goto EventScript_ChoseMegaStone
    end

EventScript_Sceptilite:
    setvar 0x4001 ITEM_SCEPTILITE
    setvar 0x4002 0x1F4
    goto EventScript_ChoseMegaStone
    end

EventScript_Swampertite:
    setvar 0x4001 ITEM_SWAMPERTITE
    setvar 0x4002 0x1F4
    goto EventScript_ChoseMegaStone
    end

EventScript_Tyranitarite:
    setvar 0x4001 ITEM_TYRANITARITE
    setvar 0x4002 0x3E7
    goto EventScript_ChoseMegaStone
    end

EventScript_Venusaurite:
    setvar 0x4001 ITEM_VENUSAURITE
    setvar 0x4002 0x1F4
    goto EventScript_ChoseMegaStone
    end

EventScript_ChoseMegaStone:
    bufferitem 0x0 0x4001
    buffernumber 0x1 0x4002
    msgbox gText_YouWantThisStone MSG_YESNO
    compare LASTRESULT 0x0
    if 0x1 _goto End
    checkcoins LASTRESULT
    comparevars LASTRESULT 0x4002
    if 0x0 _goto 0x816CDA5 @ need more coins
    copyvar 0x8003 0x4001
    compare 0x8003 ITEM_BLASTOISINITE
    if 0x1 _goto EventScript_GiveBlastoisinite
    compare 0x8003 ITEM_BLAZIKENITE
    if 0x1 _goto EventScript_GiveBlazikenite
    compare 0x8003 ITEM_CHARIZARDITE_X
    if 0x1 _goto EventScript_GiveCharizarditeX
    compare 0x8003 ITEM_CHARIZARDITE_Y
    if 0x1 _goto EventScript_GiveCharizarditeY
    compare 0x8003 ITEM_GARCHOMPITE
    if 0x1 _goto EventScript_GiveGarchompite
    compare 0x8003 ITEM_METAGROSSITE
    if 0x1 _goto EventScript_GiveMetagrossite
    compare 0x8003 ITEM_SALAMENCITE
    if 0x1 _goto EventScript_GiveSalamencite
    compare 0x8003 ITEM_SCEPTILITE
    if 0x1 _goto EventScript_GiveSceptilite
    compare 0x8003 ITEM_SWAMPERTITE
    if 0x1 _goto EventScript_GiveSwampertite
    compare 0x8003 ITEM_TYRANITARITE
    if 0x1 _goto EventScript_GiveTyranitarite
    compare 0x8003 ITEM_VENUSAURITE
    if 0x1 _goto EventScript_GiveVenusaurite
    end

EventScript_GiveBlastoisinite:
    giveitem ITEM_BLASTOISINITE 0x1 MSG_OBTAIN
    goto EventScript_ObtainedStone
    end

EventScript_GiveBlazikenite:
    giveitem ITEM_BLAZIKENITE 0x1 MSG_OBTAIN
    goto EventScript_ObtainedStone
    end

EventScript_GiveCharizarditeX:
    giveitem ITEM_CHARIZARDITE_X 0x1 MSG_OBTAIN
    goto EventScript_ObtainedStone
    end

EventScript_GiveCharizarditeY:
    giveitem ITEM_CHARIZARDITE_Y 0x1 MSG_OBTAIN
    goto EventScript_ObtainedStone
    end

EventScript_GiveGarchompite:
    giveitem ITEM_GARCHOMPITE 0x1 MSG_OBTAIN
    goto EventScript_ObtainedStone
    end

EventScript_GiveMetagrossite:
    giveitem ITEM_METAGROSSITE 0x1 MSG_OBTAIN
    goto EventScript_ObtainedStone
    end

EventScript_GiveSalamencite:
    giveitem ITEM_SALAMENCITE 0x1 MSG_OBTAIN
    goto EventScript_ObtainedStone
    end

EventScript_GiveSceptilite:
    giveitem ITEM_SCEPTILITE 0x1 MSG_OBTAIN
    goto EventScript_ObtainedStone
    end

EventScript_GiveSwampertite:
    giveitem ITEM_SWAMPERTITE 0x1 MSG_OBTAIN
    goto EventScript_ObtainedStone
    end

EventScript_GiveTyranitarite:
    giveitem ITEM_TYRANITARITE 0x1 MSG_OBTAIN
    goto EventScript_ObtainedStone
    end

EventScript_GiveVenusaurite:
    giveitem ITEM_VENUSAURITE 0x1 MSG_OBTAIN
    goto EventScript_ObtainedStone
    end

EventScript_ObtainedStone:
    removecoins 0x4002
    updatecoins 0x0 0x5
    fanfare 0x101
    waitfanfare
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Pseudo Legendaries Celadon Game Corner
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GameCornerPseudo:
    lock
    faceplayer
    checkflag 0x243
    if 0x0 _goto 0x816CD99
    special 0x187
    compare LASTRESULT 0x2
    if 0x1 _goto 0x81A7AE0
    showcoins 0x14 0x0
    msgbox 0x8197057 MSG_KEEPOPEN @ we exchange coins for prices
    goto EventScript_PseudoList
    end

EventScript_PseudoList:
    msgbox gText_GameCornerGivePseudo MSG_KEEPOPEN
    setvar 0x8000 14
    setvar 0x8001 0x5
    setvar 0x8004 0x0
    special 0x158
    waitstate
    switch LASTRESULT
    compare LASTRESULT 11
    if greaterorequal _goto 0x816CC10
    case 0, EventScript_Dratini
    case 1, EventScript_Larvitar
    case 2, EventScript_Bagon
    case 3, EventScript_Beldum
    case 4, EventScript_Gible
    case 5, EventScript_Deino
    case 6, EventScript_Larvesta
    case 7, EventScript_Goomy
    case 8, EventScript_Jangmoo
    case 9, EventScript_Dreepy
    case 10, EventScript_Snom
    end

EventScript_Dratini:
    setvar 0x4001 SPECIES_DRATINI
    setvar 0x4002 0x5DC
    goto EventScript_ChosePseudo
    end

EventScript_Larvitar:
    setvar 0x4001 SPECIES_LARVITAR
    setvar 0x4002 0x5DC
    goto EventScript_ChosePseudo
    end

EventScript_Bagon:
    setvar 0x4001 SPECIES_BAGON
    setvar 0x4002 0x5DC
    goto EventScript_ChosePseudo
    end

EventScript_Beldum:
    setvar 0x4001 SPECIES_BELDUM
    setvar 0x4002 0x5DC
    goto EventScript_ChosePseudo
    end

EventScript_Gible:
    setvar 0x4001 SPECIES_GIBLE
    setvar 0x4002 0x5DC
    goto EventScript_ChosePseudo
    end

EventScript_Deino:
    setvar 0x4001 SPECIES_DEINO
    setvar 0x4002 0x5DC
    goto EventScript_ChosePseudo
    end

EventScript_Larvesta:
    setvar 0x4001 SPECIES_LARVESTA
    setvar 0x4002 0x4E2
    goto EventScript_ChosePseudo
    end

EventScript_Goomy:
    setvar 0x4001 SPECIES_GOOMY
    setvar 0x4002 0x5DC
    goto EventScript_ChosePseudo
    end

EventScript_Jangmoo:
    setvar 0x4001 SPECIES_JANGMO_O
    setvar 0x4002 0x5DC
    goto EventScript_ChosePseudo
    end

EventScript_Dreepy:
    setvar 0x4001 SPECIES_DREEPY
    setvar 0x4002 0x5DC
    goto EventScript_ChosePseudo
    end

EventScript_Snom:
    setvar 0x4001 SPECIES_SNOM
    setvar 0x4002 0x4E2
    goto EventScript_ChosePseudo
    end

EventScript_ChosePseudo:
    bufferpokemon 0x0 0x4001
    buffernumber 0x1 0x4002
    showpokepic 0x4001
    msgbox gText_YouWantThisPokemon MSG_YESNO
    compare LASTRESULT 0x0
    if 0x1 _goto End
    hidepokepic
    checkcoins LASTRESULT
    comparevars LASTRESULT 0x4002
    if 0x0 _goto 0x816CDA5 @ need more coins
    copyvar 0x8003 0x4001
    compare 0x8003 SPECIES_DRATINI
    if 0x1 _goto EventScript_GiveDratini
    compare 0x8003 SPECIES_LARVITAR
    if 0x1 _goto EventScript_GiveLarvitar
    compare 0x8003 SPECIES_BAGON
    if 0x1 _goto EventScript_GiveBagon
    compare 0x8003 SPECIES_BELDUM
    if 0x1 _goto EventScript_GiveBeldum
    compare 0x8003 SPECIES_GIBLE
    if 0x1 _goto EventScript_GiveGible
    compare 0x8003 SPECIES_DEINO
    if 0x1 _goto EventScript_GiveDeino
    compare 0x8003 SPECIES_LARVESTA
    if 0x1 _goto EventScript_GiveLarvesta
    compare 0x8003 SPECIES_GOOMY
    if 0x1 _goto EventScript_GiveGoomy
    compare 0x8003 SPECIES_JANGMO_O
    if 0x1 _goto EventScript_GiveJangmoo
    compare 0x8003 SPECIES_DREEPY
    if 0x1 _goto EventScript_GiveDreepy
    compare 0x8003 SPECIES_SNOM
    if 0x1 _goto EventScript_GiveSnom
    end

End:
    hidepokepic
    goto 0x816CC10
    release
    end

EventScript_GiveDratini:
    givepokemon SPECIES_DRATINI 25 0x0 0x0 0x0 0x0
    goto EventScript_ObtainedPseudo
    end

EventScript_GiveLarvitar:
    givepokemon SPECIES_LARVITAR 25 0x0 0x0 0x0 0x0
    goto EventScript_ObtainedPseudo
    end

EventScript_GiveBagon:
    givepokemon SPECIES_BAGON 25 0x0 0x0 0x0 0x0
    goto EventScript_ObtainedPseudo
    end

EventScript_GiveBeldum:
    givepokemon SPECIES_BELDUM 25 0x0 0x0 0x0 0x0
    goto EventScript_ObtainedPseudo
    end

EventScript_GiveGible:
    givepokemon SPECIES_GIBLE 25 0x0 0x0 0x0 0x0
    goto EventScript_ObtainedPseudo
    end

EventScript_GiveDeino:
    givepokemon SPECIES_DEINO 25 0x0 0x0 0x0 0x0
    goto EventScript_ObtainedPseudo
    end

EventScript_GiveLarvesta:
    givepokemon SPECIES_LARVESTA 25 0x0 0x0 0x0 0x0
    goto EventScript_ObtainedPseudo
    end

EventScript_GiveGoomy:
    givepokemon SPECIES_GOOMY 25 0x0 0x0 0x0 0x0
    goto EventScript_ObtainedPseudo
    end

EventScript_GiveJangmoo:
    givepokemon SPECIES_JANGMO_O 25 0x0 0x0 0x0 0x0
    goto EventScript_ObtainedPseudo
    end

EventScript_GiveDreepy:
    givepokemon SPECIES_DREEPY 25 0x0 0x0 0x0 0x0
    goto EventScript_ObtainedPseudo
    end

EventScript_GiveSnom:
    givepokemon SPECIES_SNOM 25 0x0 0x0 0x0 0x0
    goto EventScript_ObtainedPseudo
    end

EventScript_ObtainedPseudo:
    removecoins 0x4002
    updatecoins 0x0 0x5
    fanfare 0x101
    waitfanfare
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Galar Items Celadon Dep. Store
@@@@@@@@@@@@@@@@@@@@@@
EventScript_StoreGalarItems:
    lock
    faceplayer
    msgbox gText_GalarExclusive MSG_KEEPOPEN
    pokemart EventScript_StoreGalarItemsList
    msgbox 0x81A5190 MSG_KEEPOPEN
    release
    end

.align 1
EventScript_StoreGalarItemsList:
    .hword ITEM_RED_NECTAR
    .hword ITEM_YELLOW_NECTAR
    .hword ITEM_PINK_NECTAR
    .hword ITEM_PURPLE_NECTAR
    .hword ITEM_STRAWBERRY_SWEET
    .hword ITEM_BERRY_SWEET
    .hword ITEM_LOVE_SWEET
    .hword ITEM_CLOVER_SWEET
    .hword ITEM_FLOWER_SWEET
    .hword ITEM_RIBBON_SWEET
    .hword ITEM_STAR_SWEET
    .hword ITEM_SWEET_APPLE
    .hword ITEM_TART_APPLE
    .hword ITEM_CRACKED_POT
    .hword ITEM_CHIPPED_POT
    .hword ITEM_GALARICA_CUFF
    .hword ITEM_GALARICA_WREATH
    .hword 0x0

@@@@@@@@@@@@@@@@@@@@@@
@ Team Rocket Grunt Game Corner
@@@@@@@@@@@@@@@@@@@@@@
EvenScript_0x16CAF5:
    checkflag 0x4B3
    if NOT_SET _goto EventScript_CantEnterRocketHideoutYet
    trainerbattle2 0x2 0x165 0x0 0x8196E69 0x8196E95 0x816CB10
    msgbox 0x8196E9B MSG_NORMAL
    end

EventScript_CantEnterRocketHideoutYet:
    lock
    faceplayer
    msgbox gText_CantEnterRocketHideoutYet MSG_KEEPOPEN
    spriteface 0xB, UP
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ May Celadon Encounter
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Celadon_May:
    lock
    faceplayer
    playsong 0x1A7
    call MayNameBox
    msgbox gText_Celadon_MaySpeaks1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    pause 30
    applymovement 17 EventScript_Celadon_MaySmile
    applymovement PLAYER EventScript_Celadon_PlayerSmile
    waitmovement 17
    call MayNameBox
    msgbox gText_Celadon_MaySpeaks2 MSG_KEEPOPEN
    msgbox gText_Celadon_MaySpeaks3 MSG_YESNO
    callasm RemoveNameBox
    compare LASTRESULT 0x1
    if FALSE _goto EventScript_PlayerAnsweredNo
    call MayNameBox
    msgbox gText_Celadon_MaySpeaks4 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    fadescreen 0x1
    hidesprite 17
    setflag FLAG_MAY_CELADON_SPRITE
    fadescreen 0x0
    fadedefaultbgm
    release
    end

EventScript_PlayerAnsweredNo:
    call MayNameBox
    msgbox gText_Celadon_MaySpeaks5 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    fadescreen 0x1
    hidesprite 17
    setflag FLAG_MAY_CELADON_SPRITE
    fadescreen 0x0
    fadedefaultbgm
    release
    end

EventScript_Celadon_MaySmile:
    .byte say_smile
    .byte pause_long
    .byte end_m

EventScript_Celadon_PlayerSmile:
    .byte say_smile
    .byte pause_long
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Admin Ariana Rocket Hideout
@@@@@@@@@@@@@@@@@@@@@@
EventScript_RocketHQ_Admin:
    lock
    pause 30
    special 0x113
    applymovement CAMERA Move_RocketHQ_Admin_Camera_1
    waitmovement CAMERA
    special 0x114
    npcmsg gText_RocketHQ_Admin_Ariana_Speak_1 MSG_KEEPOPEN 0 LEFT
    closemsg
    npcmsg gText_RocketHQ_Admin_Giovanni_Speak_1 MSG_KEEPOPEN 0 LEFT
    closemsg
    npcmsg gText_RocketHQ_Admin_Ariana_Speak_2 MSG_KEEPOPEN 0 LEFT
    closemsg
    pause 15
    cry SPECIES_CUBONE 0x0
    pause 15
    npcmsg gText_RocketHQ_Admin_Ariana_Speak_3 MSG_KEEPOPEN 0 LEFT
    closemsg
    npcmsg gText_RocketHQ_Admin_Giovanni_Speak_2 MSG_KEEPOPEN 0 LEFT
    closemsg
    npcmsg gText_RocketHQ_Admin_Ariana_Speak_4 MSG_KEEPOPEN 25 LEFT
    closemsg
    pause 30
    applymovement ARIANA Move_RocketHQ_Admin_Ariana_1
    waitmovement ARIANA
    special 0x113
    applymovement CAMERA Move_RocketHQ_Admin_Camera_2
    waitmovement CAMERA
    special 0x114
    sound 0x15
    applymovement ARIANA Move_RocketHQ_Admin_Ariana_2
    waitmovement ARIANA
    playsong 0x181 1
    npcmsg gText_RocketHQ_Admin_Ariana_Speak_5 MSG_KEEPOPEN 25 LEFT
    closemsg
    trainerbattle3 0x3 0x8 0x0 gText_RocketHQ_Admin_Ariana_Defeated
    pause 30
    spriteface ARIANA UP
    npcmsg gText_RocketHQ_Admin_Ariana_Speak_6 MSG_KEEPOPEN 25 LEFT
    closemsg
    pause 30
    spriteface ARIANA DOWN
    npcmsg gText_RocketHQ_Admin_Ariana_Speak_7 MSG_KEEPOPEN 25 LEFT
    closemsg
    npcmsg gText_RocketHQ_Admin_Ariana_Speak_8 MSG_KEEPOPEN 25 LEFT
    closemsg
    applymovement PLAYER Move_RocketHQ_Admin_Player_1
    applymovement ARIANA Move_RocketHQ_Admin_Ariana_3
    waitmovement ARIANA
    hidesprite ARIANA
    setflag FLAG_ENCOUNTER_ROCKETHQ_ARIANA
    setvar VAR_ENCOUNTER_ARIANA 0x1
    fadedefaultbgm
    release
    end

Move_RocketHQ_Admin_Camera_1:
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_RocketHQ_Admin_Camera_2:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_RocketHQ_Admin_Ariana_1:
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte end_m

Move_RocketHQ_Admin_Ariana_2:
    .byte exclaim
    .byte pause_long
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_RocketHQ_Admin_Player_1:
    .byte walk_right
    .byte walk_left_onspot_fastest
    .byte end_m

Move_RocketHQ_Admin_Ariana_3:
    .byte walk_down
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Rocket HQ Cubone
@@@@@@@@@@@@@@@@@@@@@@
EventScript_RocketHQ_Cubone:
    lock
    faceplayer
    pause 15
    cry SPECIES_CUBONE 0x0
    msgbox gText_RocketHQ_Cubone_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Rocket HQ Giovanni
@@@@@@@@@@@@@@@@@@@@@@
EventScript_RocketHQ_Giovanni:
    lock
    faceplayer
    setvar 0x8004 0xF
    setvar 0x8005 0x0
    special 0x173
    npcmsg gText_RocketHQ_Giovanni_Speak_1 MSG_KEEPOPEN 18 LEFT
    closemsg
    pause 15
    spriteface CUBONE LEFT
    cry SPECIES_CUBONE 0x0
    pause 15
    sound 0x15
    applymovement GIOVANNI Move_RocketHQ_Giovanni_1
    waitmovement GIOVANNI
    npcmsg gText_RocketHQ_Giovanni_Speak_2 MSG_KEEPOPEN 18 LEFT
    closemsg
    playsong 0x11B 0x0
    trainerbattle3 0x3 0x15C 0x0 0x8175318
    npcmsg gText_RocketHQ_Giovanni_Speak_3 MSG_KEEPOPEN 18 LEFT
    closemsg
    pause 15
    cry SPECIES_CUBONE 0x0
    applymovement CUBONE Move_RocketHQ_Giovanni_Cubone_1
    waitmovement CUBONE
    npcmsg gText_RocketHQ_Giovanni_Speak_4 MSG_KEEPOPEN 18 LEFT
    closemsg
    fadescreen 0x1
    hidesprite 0x1
    showsprite 0x2
    clearflag 0x37
    setflag 0x5F
    setvar 0x8004 0xF
    setvar 0x8005 0x2
    special 0x174
    fadescreen 0x0
    pause 30
    spriteface CUBONE DOWN
    cry SPECIES_CUBONE 0x0
    msgbox gText_RocketHQ_Giovanni_Cubone_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    applymovement CUBONE Move_RocketHQ_Giovanni_Cubone_2
    applymovement PLAYER Move_RocketHQ_Giovanni_Player_1
    waitmovement CUBONE
    fadescreen 0x1
    hidesprite CUBONE
    setflag FLAG_CUBONE_ROCKETHQ_SPRITE
    signbox gText_RocketHQ_Narrator_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    fadescreen 0x0
    release
    end

Move_RocketHQ_Giovanni_1:
    .byte say_question
    .byte pause_long
    .byte end_m

Move_RocketHQ_Giovanni_Cubone_1:
    .byte say_smile
    .byte jump_onspot_down
    .byte jump_onspot_down
    .byte pause_long
    .byte end_m

Move_RocketHQ_Giovanni_Cubone_2:
    .byte say_smile
    .byte jump_onspot_down
    .byte jump_onspot_down
    .byte pause_long
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

Move_RocketHQ_Giovanni_Player_1:
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Eusine | Roaming Dogs | Outside
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Celadon:
    mapscript MAP_SCRIPT_ON_TRANSITION MapEventScript_Celadon
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_Celadon_RoamingDogs
    .byte MAP_SCRIPT_TERMIN

MapEventScript_Celadon:
    setworldmapflag 0x896
    end

LevelScript_Celadon_RoamingDogs:
    levelscript VAR_ROAMING_DOGS_EVENT, 1, EventScript_Celadon_RoamingDogs
    .hword LEVEL_SCRIPT_TERMIN

EventScript_Celadon_RoamingDogs:
    lock
    applymovement 18 Move_Celadon_RoamingDogs_Eusine_1
    applymovement PLAYER Move_Celadon_RoamingDogs_Player_1
    waitmovement 18
    sound 0x15
    applymovement 18 Move_Celadon_RoamingDogs_Eusine_2
    waitmovement 18
    call EusineNameBox
    msgbox gText_Celadon_RoamingDogs_Eusine_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 18 Move_Celadon_RoamingDogs_Eusine_3
    waitmovement 18
    call EusineNameBox
    msgbox gText_Celadon_RoamingDogs_Eusine_Speak_2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    pause 30
    applymovement PLAYER Move_Celadon_RoamingDogs_Player_2
    waitmovement PLAYER
    signmsg
    msgbox gText_Celadon_RoamingDogs_Narrator_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    normalmsg
    sound 0x2
    pause 60
    setvar 0x8000 SPECIES_RAIKOU
    setvar 0x8001 50
    setvar 0x8002 0x1
    setvar 0x8003 0x0
    special 0x129
    compare LASTRESULT 0x0
    if TRUE _goto EventScript_Celadon_RoamingDogs_TooManyRoamers
    sound 0x2
    pause 60
    setvar 0x8000 SPECIES_ENTEI
    setvar 0x8001 50
    setvar 0x8002 0x1
    setvar 0x8003 0x0
    special 0x129
    compare LASTRESULT 0x0
    if TRUE _goto EventScript_Celadon_RoamingDogs_TooManyRoamers
    sound 0x2
    pause 60
    setvar 0x8000 SPECIES_SUICUNE
    setvar 0x8001 50
    setvar 0x8002 0x1
    setvar 0x8003 0x0
    special 0x129
    compare LASTRESULT 0x0
    if TRUE _goto EventScript_Celadon_RoamingDogs_TooManyRoamers
    call EusineNameBox
    msgbox gText_Celadon_RoamingDogs_Eusine_Speak_3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 18 Move_Celadon_RoamingDogs_Eusine_4
    waitmovement 18
    hidesprite 18
    setflag FLAG_EUSINE_SPRITE_CELADON_OUTSIDE
    setvar VAR_ROAMING_DOGS_EVENT 0x2
    clearflag FLAG_EUSINE_SPRITE_CELADON_RESTO
    release
    end

EventScript_Celadon_RoamingDogs_TooManyRoamers:
    signmsg
    msgbox gText_Celadon_RoamingDogs_TooManyRoamers MSG_KEEPOPEN
    closeonkeypress
    release
    end

Move_Celadon_RoamingDogs_Player_1:
    .byte pause_long
    .byte say_question
    .byte end_m

Move_Celadon_RoamingDogs_Eusine_1:
    .byte pause_long
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte walk_right
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte end_m

Move_Celadon_RoamingDogs_Eusine_2:
    .byte exclaim
    .byte pause_long
    .byte walk_left
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte end_m

Move_Celadon_RoamingDogs_Eusine_3:
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte say_question
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

Move_Celadon_RoamingDogs_Player_2:
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Celadon_RoamingDogs_Eusine_4:
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
    .byte walk_right
    .byte walk_right
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Eusine | Roaming Dogs | Resto
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Celadon_Eusine_InsideResto:
    lock
    faceplayer
    checkflag FLAG_ROAMING_DOGS_EVENT_FINISHED
    if SET _goto EventScript_Celadon_RoamingDogs_Finished
    callasm CheckRoamingDogs
    compare 0x8004 1
    if TRUE _goto EventScript_Celadon_InsideResto_DogInParty_1
    call EusineNameBox
    msgbox gText_Celadon_Eusine_InsideResto_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    release
    end

EventScript_Celadon_InsideResto_DogInParty_1:
    pause 30
    sound 0x15
    applymovement 6 Move_Celadon_Eusine_InsideResto_1
    waitmovement 6
    call EusineNameBox
    msgbox gText_Celadon_Eusine_InsideResto_Speak_2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 6 Move_Celadon_Eusine_InsideResto_2
    waitmovement 6
    faceplayer
    call EusineNameBox
    msgbox gText_Celadon_Eusine_InsideResto_Speak_3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    giveitem ITEM_MASTER_BALL 0x1 MSG_OBTAIN
    call EusineNameBox
    msgbox gText_Celadon_Eusine_InsideResto_Speak_4 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    setflag FLAG_ROAMING_DOGS_EVENT_FINISHED
    release
    end

EventScript_Celadon_RoamingDogs_Finished:
    checkflag 0x4BC
    if SET _goto EventScrit_Celadon_Eusine_InsideResto_Battle
    call EusineNameBox
    msgbox gText_Celadon_Eusine_InsideResto_Speak_5 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    release
    end

EventScript_Celadon_Eusine_InsideResto_PlayerDontWantBattle:
    call EusineNameBox
    msgbox gText_Celadon_Eusine_InsideResto_PlayerDontWantBattle MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    release
    end

EventScrit_Celadon_Eusine_InsideResto_Battle:
    call EusineNameBox
    trainerbattle1 0x3 0x9 0x0 gText_Celadon_Eusine_InsideResto_Speak_6 gText_Celadon_Eusine_InsideResto_Battle_Defeated EventScript_Celadon_Eusine_InsideResto_Battle_After
    release
    end

EventScript_Celadon_Eusine_InsideResto_Battle_After:
    call EusineNameBox
    msgbox gText_Celadon_Eusine_InsideResto_Speak_7 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    fadescreen 0x1
    hidesprite 0x6
    setflag FLAG_EUSINE_SPRITE_CELADON_RESTO
    fadescreen 0x0
    release
    end

Move_Celadon_Eusine_InsideResto_1:
    .byte exclaim
    .byte end_m

Move_Celadon_Eusine_InsideResto_2:
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte say_question
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Normal Celadon
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Celadon_Norman:
    lock
    pause 30
    sound 0x15
    applymovement 3 Move_Celadon_Norman_1
    waitmovement 3
    npcmsg gText_Celadon_Norman_Speak_1 MSG_KEEPOPEN 0 LEFT
    closemsg
    npcmsg gText_Celadon_Norman_Speak_2 MSG_YESNO 36 LEFT
    compare LASTRESULT 0x1
    if notequal _goto EventScript_Celadon_Norman_PlayerDontWantToBattle
    closemsg
    trainerbattle3 0x3 84 0x0 gText_Celadon_Norman_Defeat
    npcmsg gText_Celadon_Norman_Speak_3 MSG_KEEPOPEN 36 LEFT
    closemsg
    giveitem ITEM_SILK_SCARF 0x1 MSG_OBTAIN
    npcmsg gText_Celadon_Norman_Speak_4 MSG_KEEPOPEN 36 LEFT
    closemsg
    fadescreen 0x1
    hidesprite 3
    setflag FLAG_NORMAN_CELADON_SPRITE
    fadescreen 0x0
    release
    end

EventScript_Celadon_Norman_PlayerDontWantToBattle:
    npcmsg gText_Celadon_Norman_PlayerDontWantToBattle MSG_KEEPOPEN 36 LEFT
    spriteface 3, DOWN
    closemsg
    release
    end

Move_Celadon_Norman_1:
    .byte exclaim
    .byte pause_long
    .byte face_player
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Rocket Hideout Rocket Gang
@@@@@@@@@@@@@@@@@@@@@@
MapScript_RocketHQ_4thFloor:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScript_RocketHQ_4thFloor
    .byte MAP_SCRIPT_TERMIN

LevelScript_RocketHQ_4thFloor:
    levelscript VAR_ROCKET_GANG_ENCOUNTER, 0x5, EventScript_RocketHQ_RocketGang
    .hword LEVEL_SCRIPT_TERMIN

EventScript_RocketHQ_RocketGang:
    lock
    pause 30
    sound 0x15
    applymovement PLAYER Move_RocketHQ_RocketGang_Player_1
    waitmovement PLAYER
    special 0x113
    applymovement CAMERA Move_RocketHQ_RocketGang_Camera_1
    waitmovement CAMERA
    special 0x114
    playsong 0x184 0x1
    sound 0x15
    applymovement JESSIE Move_RocketHQ_RocketGang_Jessie_1
    waitmovement JESSIE
    pause 30
    npcmsg gText_RocketHQ_RocketGang_Jessie_Speak_1 MSG_KEEPOPEN 29 LEFT
    closemsg
    npcmsg gText_RocketHQ_RocketGang_James_Speak_1 MSG_KEEPOPEN 30 LEFT
    closemsg
    pause 30
    sound 0x15
    applymovement MEOWTH Move_RocketHQ_RocketGang_Meowth_1
    waitmovement MEOWTH
    npcmsg gText_RocketHQ_RocketGang_Meowth_Speak_1 MSG_KEEPOPEN 31 LEFT
    closemsg
    applymovement JESSIE Move_RocketHQ_RocketGang_Jessie_2
    applymovement JAMES Move_RocketHQ_RocketGang_James_1
    waitmovement JAMES
    special 0x113
    applymovement CAMERA Move_RocketHQ_RocketGang_Camera_2
    waitmovement CAMERA
    special 0x114
    sound 0x15
    applymovement JESSIE Move_RocketHQ_RocketGang_Jessie_3
    applymovement JAMES Move_RocketHQ_RocketGang_James_2
    applymovement MEOWTH Move_RocketHQ_RocketGang_Meowth_2
    waitmovement MEOWTH
    pause 30
    npcmsg gText_RocketHQ_RocketGang_Jessie_Speak_2 MSG_KEEPOPEN 29 LEFT
    closemsg
    npcmsg gText_RocketHQ_RocketGang_James_Speak_2 MSG_KEEPOPEN 30 LEFT
    closemsg
    npcmsg gText_RocketHQ_RocketGang_Meowth_Speak_2 MSG_KEEPOPEN 31 LEFT
    closemsg
    setvar VAR_FURTHER_TRAINER_BATTLES 0x2
    trainerbattle3 0x3 10 0x0 gText_RocketHQ_RocketGang_Defeat
    npcmsg gText_RocketHQ_RocketGang_Jessie_Speak_3 MSG_KEEPOPEN 29 LEFT
    closemsg
    npcmsg gText_RocketHQ_RocketGang_James_Speak_3 MSG_KEEPOPEN 30 LEFT
    closemsg
    pause 30
    sound 0x15
    applymovement JAMES Move_RocketHQ_RocketGang_James_3
    waitmovement JAMES
    spriteface JESSIE DOWN
    spriteface MEOWTH UP
    npcmsg gText_RocketHQ_RocketGang_James_Speak_4 MSG_KEEPOPEN 30 LEFT
    closemsg
    npcmsg gText_RocketHQ_RocketGang_Meowth_Speak_3 MSG_KEEPOPEN 31 LEFT
    closemsg
    fadescreen 0x1
    hidesprite JESSIE
    hidesprite JAMES
    hidesprite MEOWTH
    setflag FLAG_ROCKET_ROCKETHQ_SPRITE
    setvar VAR_ROCKET_GANG_ENCOUNTER 0x6
    fadescreen 0x0
    fadedefaultbgm
    special 0x113
    applymovement CAMERA Move_RocketHQ_RocketGang_Camera_3
    waitmovement CAMERA
    special 0x114
    release
    end

Move_RocketHQ_RocketGang_Player_1:
    .byte exclaim
    .byte pause_long
    .byte end_m

Move_RocketHQ_RocketGang_Camera_1:
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte end_m

Move_RocketHQ_RocketGang_Jessie_1:
    .byte say_question
    .byte pause_long
    .byte end_m

Move_RocketHQ_RocketGang_Meowth_1:
    .byte exclaim
    .byte pause_long
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte end_m

Move_RocketHQ_RocketGang_Jessie_2:
    .byte pause_long
    .byte pause_long
    .byte say_question
    .byte pause_long
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte end_m

Move_RocketHQ_RocketGang_James_1:
    .byte pause_long
    .byte pause_long
    .byte say_question
    .byte pause_long
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte end_m

Move_RocketHQ_RocketGang_Jessie_3:
    .byte exclaim
    .byte pause_long
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte end_m

Move_RocketHQ_RocketGang_James_2:
    .byte exclaim
    .byte pause_long
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte end_m

Move_RocketHQ_RocketGang_Meowth_2:
    .byte pause_long
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte end_m

Move_RocketHQ_RocketGang_James_3:
    .byte exclaim
    .byte pause_long
    .byte jump_onspot_right
    .byte say_question
    .byte end_m

Move_RocketHQ_RocketGang_Camera_2:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte end_m

Move_RocketHQ_RocketGang_Camera_3:
    .byte walk_right
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Celadon NameBox
@@@@@@@@@@@@@@@@@@@@@@
UnknownNameBox:
    setvar 0x8000 0
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

MayNameBox:
    setvar 0x8000 2
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

ErikaNameBox:
    setvar 0x8000 14
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

GiovanniNameBox:
    setvar 0x8000 18
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

ArianaNameBox:
    setvar 0x8000 25
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

EusineNameBox:
    setvar 0x8000 28
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
