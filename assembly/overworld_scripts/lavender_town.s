.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_LAVENDER_MECHANT_1, 0x302
.equ FLAG_LAVENDER_MECHANT_2, 0x303

@@@@@@@@@@@@@@@@@@@@@@
@ Lavender Town Items Merchant
@@@@@@@@@@@@@@@@@@@@@@
EventScript_LavenderTownMerchant:
    lock
    faceplayer
    checkflag 0x23C
    if 0x1 _goto EventScript_LavenderTownMerchantSell
    msgbox 0x817F5B6 MSG_FACE
    end

EventScript_LavenderTownMerchantSell:
    checkflag FLAG_LAVENDER_MECHANT_1
    if 0x0 _call EventScript_PlayerRescuedFuji
    checkflag FLAG_LAVENDER_MECHANT_2
    if 0x0 _call EventScript_LavenderTownMerchantAdmit
    msgbox gText_LavenderTownMerchantSell MSG_KEEPOPEN
    pokemart EventScript_LavenderTownMerchantList
    msgbox gText_LavenderTownMerchantBye MSG_KEEPOPEN
    release
    end

EventScript_PlayerRescuedFuji:
    msgbox EventScript_LavenderTownMerchantFujiRescued MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_DoesntMatter
    setflag FLAG_LAVENDER_MECHANT_1
    goto EventScript_LavenderTownMerchantAdmit
    return

EventScript_LavenderTownMerchantAdmit:
    msgbox gText_LavenderTownMerchantAdmit MSG_KEEPOPEN
    setflag FLAG_LAVENDER_MECHANT_2
    return

EventScript_LavenderTownMerchantExclaim:
    .byte exclaim
    .byte end_m

EventScript_LavenderTownMerchantList:
    .hword ITEM_ASSAULT_VEST
    .hword ITEM_DESTINY_KNOT
    .hword ITEM_EXPERT_BELT
    .hword ITEM_MACHO_BRACE
    .hword ITEM_RING_TARGET
    .hword ITEM_ROCKY_HELMET
    .hword ITEM_SAFETY_GOGGLES
    .hword ITEM_SCOPE_LENS
    .hword ITEM_TERRAIN_EXTENDER
    .hword ITEM_BLUNDER_POLICY
    .hword ITEM_ROOM_SERVICE
    .hword ITEM_EJECT_PACK
    .hword ITEM_HEAVY_DUTY_BOOTS
    .hword ITEM_UTILITY_UMBRELLA
    .hword ITEM_LUCKY_PUNCH
    .hword 0x0

EventScript_ThisFlagIsSet:
    return

EventScript_DoesntMatter:
    msgbox gText_DoesntMatter MSG_KEEPOPEN
    release
    end
