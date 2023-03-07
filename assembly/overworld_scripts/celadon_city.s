.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_MAY_CELADON_SPRITE1, 0x943

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
    textcolor RED
    msgbox gText_Celadon_MaySpeaks1 MSG_KEEPOPEN
    applymovement 17 EventScript_Celadon_MaySmile
    applymovement PLAYER EventScript_Celadon_PlayerSmile
    waitmovement 17
    msgbox gText_Celadon_MaySpeaks2 MSG_KEEPOPEN
    msgbox gText_Celadon_MaySpeaks3 MSG_YESNO
    compare LASTRESULT 0x1
    if FALSE _goto EventScript_PlayerAnsweredNo
    msgbox gText_Celadon_MaySpeaks4 MSG_KEEPOPEN
    closeonkeypress
    fadescreen 0x1
    hidesprite 17
    setflag FLAG_MAY_CELADON_SPRITE1
    fadescreen 0x0
    release
    end

EventScript_PlayerAnsweredNo:
    msgbox gText_Celadon_MaySpeaks5 MSG_KEEPOPEN
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
