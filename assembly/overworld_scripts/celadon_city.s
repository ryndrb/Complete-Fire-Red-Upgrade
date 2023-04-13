.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_MAY_CELADON_SPRITE1, 0x943
.equ FLAG_OBTAIN_ABOMASITE, 0x95F
.equ FLAG_ENCOUNTER_ROCKETHQ_ARIANA, 0x9B7
.equ VAR_ARIANA_BATTLES, 0x5035
.equ VAR_ENCOUNTER_ROCKETHQ_ARIANA, 0x5036

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

Obtained:
    goto 0x816A67F
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Celadon Giovanni
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Celadon_Giovanni:
    lock
    faceplayer
    setvar 0x8004 0xF
    setvar 0x8005 0x0
    special 0x173
    call UnknownNameBox
    msgbox gText_Celadon_GiovanniSpeak1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    call GiovanniNameBox
    msgbox gText_gText_Celadon_GiovanniSpeak2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    playsong 0x11B 0x0
    waitkeypress
    trainerbattle3 0x3 0x15C 0x0 0x8175318
    call GiovanniNameBox
    msgbox gText_gText_Celadon_GiovanniSpeak3 MSG_KEEPOPEN
    callasm RemoveNameBox
    fadescreen 0x1
    closeonkeypress
    hidesprite 0x1
    showsprite 0x2
    clearflag 0x37
    setflag 0x5F
    setvar 0x8004 0xF
    setvar 0x8005 0x2
    special 0x174
    fadescreen 0x0
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Poke Ball Types Celadon Dep. Store
@@@@@@@@@@@@@@@@@@@@@@
EventScript_StorePokeBalls:
    textcolor BLUE
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
    textcolor BLUE
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
    textcolor BLUE
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
    textcolor BLUE
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
    setvar 0x8000 0x10
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
    textcolor BLUE
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
    setvar 0x8000 0x11
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
    textcolor BLUE
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
    textcolor BLUE
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
    textcolor RED
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
    setflag FLAG_MAY_CELADON_SPRITE1
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
    setflag FLAG_MAY_CELADON_SPRITE1
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
@ Ariana Rocket Hideout
@@@@@@@@@@@@@@@@@@@@@@
EventScript_RocketHQ_Ariana:
    lock
    textcolor RED
    sound 0x9
    pause 30
    call UnknownNameBox
    msgbox gText_RocketHQ_ArianaSpeak1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 11 Move_RocketHQ_Ariana1
    sound 0x15
    applymovement PLAYER Move_RocketHQ_Player1
    waitmovement 11
    playsong 0x181 1
    call UnknownNameBox
    msgbox gText_RocketHQ_ArianaSpeak2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 11 Move_RocketHQ_Ariana2
    waitmovement 11
    call ArianaNameBox
    msgbox gText_RocketHQ_ArianaSpeak3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    trainerbattle3 0x3 0x8 0x0 gText_RocketHQ_ArianaDefeated
    call ArianaNameBox
    msgbox gText_RocketHQ_ArianaSpeak4 MSG_KEEPOPEN
    msgbox gText_RocketHQ_ArianaSpeak5 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 11 Move_RocketHQ_Ariana3
    waitmovement 11
    sound 0x9
    fadedefaultbgm
    hidesprite 11
    setflag FLAG_ENCOUNTER_ROCKETHQ_ARIANA
    setvar VAR_ARIANA_BATTLES 1
    setvar VAR_ENCOUNTER_ROCKETHQ_ARIANA 1
    release
    end

Move_RocketHQ_Player1:
    .byte exclaim
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_up
    .byte walk_right
    .byte walk_left_onspot_fastest
    .byte end_m

Move_RocketHQ_Ariana1:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_up
    .byte walk_right_onspot_fastest
    .byte end_m

Move_RocketHQ_Ariana2:
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte end_m

Move_RocketHQ_Ariana3:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Celadon NameBox
@@@@@@@@@@@@@@@@@@@@@@
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

UnknownNameBox:
    setvar 0x8000 0
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
