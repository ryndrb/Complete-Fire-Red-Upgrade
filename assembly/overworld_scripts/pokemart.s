.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_DEFEATED_BROCK, 0x4B0
.equ FLAG_DEFEATED_MISTY, 0x4B1   
.equ FLAG_DEFEATED_LT_SURGE, 0x4B2       
.equ FLAG_DEFEATED_ERIKA, 0x4B3 
.equ FLAG_DEFEATED_KOGA, 0x4B4           
.equ FLAG_DEFEATED_SABRINA, 0x4B5      
.equ FLAG_DEFEATED_BLAINE, 0x4B6        
.equ FLAG_DEFEATED_LEADER_GIOVANNI, 0x4B7     

@@@@@@@@@@@@@@@@@@@@Inspired by Incl. Emerald
@ 1st Pokemart Clerk
@@@@@@@@@@@@@@@@@@@@
EventScript_PokeMartMain:
    textcolor 0x0
    lock
    msgbox gText_WelcomeText MSG_KEEPOPEN
    checkflag FLAG_DEFEATED_BROCK
    if 0x1 _goto EventScript_BrockBadge
    pokemart EnventScript_ItemsNoBadge  
    goto EnventScript_EndScript  
    end

EventScript_BrockBadge:
    checkflag FLAG_DEFEATED_MISTY
    if 0x1 _goto EventScript_MistyBadge
    pokemart EventScript_ItemsBrockBadge
    goto EnventScript_EndScript
    end

EventScript_MistyBadge:
    checkflag FLAG_DEFEATED_LT_SURGE
    if 0x1 _goto EventScript_SurgeBadge
    pokemart EventScript_ItemsMistyBadge
    goto EnventScript_EndScript
    end

EventScript_SurgeBadge:
    checkflag FLAG_DEFEATED_ERIKA
    if 0x1 _goto EventScript_ErikaBadge
    pokemart EventScript_ItemsSurgeBadge
    goto EnventScript_EndScript
    end

EventScript_ErikaBadge:
    checkflag FLAG_DEFEATED_KOGA
    if 0x1 _goto EventScript_KogaBadge
    pokemart EventScript_ItemsErikaBadge
    goto EnventScript_EndScript
    end

EventScript_KogaBadge:
    checkflag FLAG_DEFEATED_SABRINA
    if 0x1 _goto EventScript_SabrinaBadge
    pokemart EventScript_ItemsKogaBadge
    goto EnventScript_EndScript
    end

EventScript_SabrinaBadge:
    checkflag FLAG_DEFEATED_BLAINE
    if 0x1 _goto EventScript_BlaineBadge
    pokemart EventScript_ItemsSabrinaBadge
    goto EnventScript_EndScript
    end

EventScript_BlaineBadge:
    pokemart EventScript_ItemsBlaineBadge
    goto EnventScript_EndScript
    end

.align 1
EnventScript_ItemsNoBadge:
    .hword ITEM_MENTAL_HERB
    .hword ITEM_RED_CARD
    .hword ITEM_CELL_BATTERY
    .hword 0x0

.align 1
EventScript_ItemsBrockBadge:
    .hword ITEM_MENTAL_HERB
    .hword ITEM_RED_CARD
    .hword ITEM_CELL_BATTERY
    .hword ITEM_EJECT_BUTTON
    .hword ITEM_ABSORB_BULB
    .hword 0x0

.align 1
EventScript_ItemsMistyBadge:
    .hword ITEM_MENTAL_HERB
    .hword ITEM_RED_CARD
    .hword ITEM_CELL_BATTERY
    .hword ITEM_EJECT_BUTTON
    .hword ITEM_ABSORB_BULB
    .hword ITEM_WHITE_HERB
    .hword ITEM_SNOWBALL
    .hword 0x0

.align 1
EventScript_ItemsSurgeBadge:
    .hword ITEM_MENTAL_HERB
    .hword ITEM_RED_CARD
    .hword ITEM_CELL_BATTERY
    .hword ITEM_EJECT_BUTTON
    .hword ITEM_ABSORB_BULB
    .hword ITEM_WHITE_HERB
    .hword ITEM_SNOWBALL
    .hword ITEM_LUMINOUS_MOSS
    .hword 0x0

.align 1
EventScript_ItemsErikaBadge:
    .hword ITEM_MENTAL_HERB
    .hword ITEM_RED_CARD
    .hword ITEM_CELL_BATTERY
    .hword ITEM_EJECT_BUTTON
    .hword ITEM_ABSORB_BULB
    .hword ITEM_WHITE_HERB
    .hword ITEM_SNOWBALL
    .hword ITEM_LUMINOUS_MOSS
    .hword ITEM_AIR_BALLOON
    .hword 0x0

.align 1
EventScript_ItemsKogaBadge:
    .hword ITEM_MENTAL_HERB
    .hword ITEM_RED_CARD
    .hword ITEM_CELL_BATTERY
    .hword ITEM_EJECT_BUTTON
    .hword ITEM_ABSORB_BULB
    .hword ITEM_WHITE_HERB
    .hword ITEM_SNOWBALL
    .hword ITEM_LUMINOUS_MOSS
    .hword ITEM_AIR_BALLOON
    .hword ITEM_POWER_HERB
    .hword ITEM_ELECTRIC_SEED
    .hword ITEM_GRASSY_SEED
    .hword ITEM_MISTY_SEED
    .hword ITEM_PSYCHIC_SEED
    .hword 0x0

.align 1
EventScript_ItemsSabrinaBadge:
    .hword ITEM_MENTAL_HERB
    .hword ITEM_RED_CARD
    .hword ITEM_CELL_BATTERY
    .hword ITEM_EJECT_BUTTON
    .hword ITEM_ABSORB_BULB
    .hword ITEM_WHITE_HERB
    .hword ITEM_SNOWBALL
    .hword ITEM_LUMINOUS_MOSS
    .hword ITEM_AIR_BALLOON
    .hword ITEM_POWER_HERB
    .hword ITEM_ELECTRIC_SEED
    .hword ITEM_GRASSY_SEED
    .hword ITEM_MISTY_SEED
    .hword ITEM_PSYCHIC_SEED
    .hword ITEM_WEAKNESS_POLICY    
    .hword 0x0

.align 1
EventScript_ItemsBlaineBadge:
    .hword ITEM_MENTAL_HERB
    .hword ITEM_RED_CARD
    .hword ITEM_CELL_BATTERY
    .hword ITEM_EJECT_BUTTON
    .hword ITEM_ABSORB_BULB
    .hword ITEM_WHITE_HERB
    .hword ITEM_SNOWBALL
    .hword ITEM_LUMINOUS_MOSS
    .hword ITEM_AIR_BALLOON
    .hword ITEM_POWER_HERB
    .hword ITEM_ELECTRIC_SEED
    .hword ITEM_GRASSY_SEED
    .hword ITEM_MISTY_SEED
    .hword ITEM_PSYCHIC_SEED
    .hword ITEM_WEAKNESS_POLICY
    .hword ITEM_FOCUS_SASH
    .hword 0x0


@@@@@@@@@@@@@@@@@@@@
@ 2nd Pokemart Clerk
@@@@@@@@@@@@@@@@@@@@
EventScript_ViridianCity:
    textcolor 0x0
    lock 
    msgbox gText_WelcomeText MSG_KEEPOPEN
    pokemart EventScript_ItemsViridianCity
    goto EnventScript_EndScript
    end

EventScript_CeruleanCity:
    lock 
    msgbox gText_WelcomeText MSG_KEEPOPEN
    pokemart EventScript_ItemsCeruleanCity
    goto EnventScript_EndScript
    end

EventScript_VermillionCity: @ also in celadon department store?
    lock 
    msgbox gText_WelcomeText MSG_KEEPOPEN
    pokemart EventScript_ItemsVermillionCity
    goto EnventScript_EndScript
    end

EventScript_LavenderTown:
    lock 
    msgbox gText_WelcomeText MSG_KEEPOPEN
    pokemart EventScript_ItemsLavenderTown
    goto EnventScript_EndScript
    end

EventScript_CeladonCity:
    lock 
    msgbox gText_WelcomeText MSG_KEEPOPEN
    pokemart EventScript_ItemsCeladonCity
    goto EnventScript_EndScript
    end

EventScript_FuschiaCity:
    lock 
    msgbox gText_WelcomeText MSG_KEEPOPEN
    pokemart EventScript_ItemsFuschiaCity
    goto EnventScript_EndScript
    end

EventScript_SaffronCity:
    lock 
    msgbox gText_WelcomeText MSG_KEEPOPEN
    pokemart EventScript_ItemsSaffronCity
    goto EnventScript_EndScript
    end

.align 1
EventScript_ItemsViridianCity:
    .hword ITEM_X_SPEED
    .hword 0x0

.align 1
EventScript_ItemsCeruleanCity:
    .hword ITEM_X_ATTACK
    .hword ITEM_X_DEFEND
    .hword ITEM_X_ACCURACY
    .hword ITEM_X_SPECIAL
    .hword ITEM_X_SP_DEF
    .hword ITEM_GUARD_SPEC
    .hword ITEM_DIRE_HIT
    .hword 0x0

.align 1
EventScript_ItemsVermillionCity:
    .hword ITEM_FIRE_STONE
    .hword ITEM_WATER_STONE
    .hword ITEM_LEAF_STONE
    .hword ITEM_THUNDER_STONE
    .hword ITEM_ICE_STONE
    .hword ITEM_MOON_STONE
    .hword ITEM_SUN_STONE
    .hword ITEM_OVAL_STONE
    .hword 0x0

.align 1
EventScript_ItemsLavenderTown:
    .hword ITEM_UPGRADE
    .hword ITEM_METAL_POWDER
    .hword ITEM_STICK 
    .hword ITEM_LIGHT_BALL
    .hword ITEM_DEEP_SEA_SCALE
    .hword ITEM_DEEP_SEA_TOOTH
    .hword ITEM_METAL_COAT
    .hword ITEM_KINGS_ROCK
    .hword ITEM_PRISM_SCALE
    .hword ITEM_WHIPPED_DREAM
    .hword ITEM_SACHET
    .hword ITEM_LINK_CABLE
    .hword 0x0

.align 1
EventScript_ItemsCeladonCity:
    .hword ITEM_SHINY_STONE
    .hword ITEM_DAWN_STONE
    .hword ITEM_DUSK_STONE
    .hword 0x0

.align 1
EventScript_ItemsSaffronCity:
    .hword ITEM_NORMAL_GEM
    .hword ITEM_FIGHTING_GEM
    .hword ITEM_FLYING_GEM
    .hword ITEM_POISON_GEM
    .hword ITEM_GROUND_GEM
    .hword ITEM_ROCK_GEM
    .hword ITEM_BUG_GEM
    .hword ITEM_GHOST_GEM
    .hword ITEM_STEEL_GEM
    .hword ITEM_FIRE_GEM
    .hword ITEM_WATER_GEM
    .hword ITEM_GRASS_GEM
    .hword ITEM_ELECTRIC_GEM
    .hword ITEM_PSYCHIC_GEM
    .hword ITEM_ICE_GEM
    .hword ITEM_DRAGON_GEM
    .hword ITEM_DARK_GEM
    .hword ITEM_FAIRY_GEM
    .hword 0x0

.align 1
EventScript_ItemsFuschiaCity:
    .hword ITEM_PROTECTOR
    .hword ITEM_ELECTIRIZER
    .hword ITEM_MAGMARIZER
    .hword ITEM_RAZOR_FANG
    .hword ITEM_RAZOR_CLAW
    .hword ITEM_DUBIOUS_DISC
    .hword ITEM_DRAGON_SCALE
    .hword ITEM_REAPER_CLOTH
    .hword 0x0

@@@@@@@@@@@@@@@@@@@@
@ Pokecenter Clerk
@@@@@@@@@@@@@@@@@@@@
EventScript_PokemonCenterClerk:
    textcolor 0x0
    lock
    msgbox gText_WelcomeText MSG_KEEPOPEN
    checkflag FLAG_DEFEATED_BROCK
    if 0x1 _goto EventScript_BrockBadge2
    checkflag 0x829
    if 0x1 _goto EventScript_PokedexObtained
    pokemart EnventScript_ItemsNoBadge2
    goto EnventScript_EndScript
    end

EventScript_PokedexObtained:
    pokemart EventScript_PokedexObtainedItems
    goto EnventScript_EndScript
    end

EventScript_BrockBadge2:
    checkflag FLAG_DEFEATED_MISTY
    if 0x1 _goto EventScript_MistyBadge2
    pokemart EventScript_ItemsBrockBadge2
    goto EnventScript_EndScript
    end

EventScript_MistyBadge2:
    checkflag FLAG_DEFEATED_LT_SURGE
    if 0x1 _goto EventScript_SurgeBadge2
    pokemart EventScript_ItemsMistyBadge2
    goto EnventScript_EndScript
    end

EventScript_SurgeBadge2:
    checkflag FLAG_DEFEATED_ERIKA
    if 0x1 _goto EventScript_ErikaBadge2
    pokemart EventScript_ItemsSurgeBadge2
    goto EnventScript_EndScript
    end

EventScript_ErikaBadge2:
    checkflag FLAG_DEFEATED_KOGA
    if 0x1 _goto EventScript_KogaBadge2
    pokemart EventScript_ItemsErikaBadge2
    goto EnventScript_EndScript
    end

EventScript_KogaBadge2:
    checkflag FLAG_DEFEATED_SABRINA
    if 0x1 _goto EventScript_SabrinaBadge2
    pokemart EventScript_ItemsKogaBadge2
    goto EnventScript_EndScript
    end

EventScript_SabrinaBadge2:
    pokemart EventScript_ItemsSabrinaBadge2
    goto EnventScript_EndScript
    end

.align 1
EnventScript_ItemsNoBadge2:
    .hword ITEM_POTION
    .hword ITEM_ANTIDOTE
    .hword ITEM_PARALYZE_HEAL
    .hword ITEM_AWAKENING
    .hword 0x0

.align 1
EventScript_PokedexObtainedItems:
    .hword ITEM_POTION
    .hword ITEM_ANTIDOTE
    .hword ITEM_PARALYZE_HEAL
    .hword ITEM_AWAKENING
    .hword ITEM_POKE_BALL
    .hword 0x0

.align 1
EventScript_ItemsBrockBadge2:
    .hword ITEM_POTION
    .hword ITEM_ANTIDOTE
    .hword ITEM_PARALYZE_HEAL
    .hword ITEM_AWAKENING
    .hword ITEM_POKE_BALL
    .hword ITEM_SUPER_POTION
    .hword ITEM_GREAT_BALL
    .hword ITEM_HONEY
    .hword ITEM_REPEL
    .hword 0x0

.align 1
EventScript_ItemsMistyBadge2:
    .hword ITEM_POTION
    .hword ITEM_ANTIDOTE
    .hword ITEM_PARALYZE_HEAL
    .hword ITEM_AWAKENING
    .hword ITEM_POKE_BALL
    .hword ITEM_SUPER_POTION
    .hword ITEM_GREAT_BALL
    .hword ITEM_HONEY
    .hword ITEM_REPEL
    .hword ITEM_HYPER_POTION
    .hword ITEM_REVIVE
    .hword ITEM_DREAM_BALL
    .hword ITEM_SUPER_REPEL
    .hword 0x0

.align 1
EventScript_ItemsSurgeBadge2:
    .hword ITEM_POTION
    .hword ITEM_ANTIDOTE
    .hword ITEM_PARALYZE_HEAL
    .hword ITEM_AWAKENING
    .hword ITEM_POKE_BALL
    .hword ITEM_SUPER_POTION
    .hword ITEM_GREAT_BALL
    .hword ITEM_HONEY
    .hword ITEM_REPEL
    .hword ITEM_HYPER_POTION
    .hword ITEM_REVIVE
    .hword ITEM_DREAM_BALL
    .hword ITEM_SUPER_REPEL
    .hword ITEM_ULTRA_BALL
    .hword ITEM_FULL_HEAL
    .hword ITEM_MAX_REPEL
    .hword ITEM_PP_UP
    .hword 0x0

.align 1
EventScript_ItemsErikaBadge2:
    .hword ITEM_POTION
    .hword ITEM_ANTIDOTE
    .hword ITEM_PARALYZE_HEAL
    .hword ITEM_AWAKENING
    .hword ITEM_POKE_BALL
    .hword ITEM_SUPER_POTION
    .hword ITEM_GREAT_BALL
    .hword ITEM_HONEY
    .hword ITEM_REPEL
    .hword ITEM_HYPER_POTION
    .hword ITEM_REVIVE
    .hword ITEM_DREAM_BALL
    .hword ITEM_SUPER_REPEL
    .hword ITEM_ULTRA_BALL
    .hword ITEM_FULL_HEAL
    .hword ITEM_MAX_REPEL
    .hword ITEM_PP_UP
    .hword ITEM_MAX_POTION
    .hword ITEM_ETHER
    .hword ITEM_ELIXIR
    .hword 0x0

.align 1
EventScript_ItemsKogaBadge2:
    .hword ITEM_POTION
    .hword ITEM_ANTIDOTE
    .hword ITEM_PARALYZE_HEAL
    .hword ITEM_AWAKENING
    .hword ITEM_POKE_BALL
    .hword ITEM_SUPER_POTION
    .hword ITEM_GREAT_BALL
    .hword ITEM_HONEY
    .hword ITEM_REPEL
    .hword ITEM_HYPER_POTION
    .hword ITEM_REVIVE
    .hword ITEM_DREAM_BALL
    .hword ITEM_SUPER_REPEL
    .hword ITEM_ULTRA_BALL
    .hword ITEM_FULL_HEAL
    .hword ITEM_MAX_REPEL
    .hword ITEM_PP_UP
    .hword ITEM_MAX_POTION
    .hword ITEM_ETHER
    .hword ITEM_ELIXIR
    .hword ITEM_FULL_RESTORE   
    .hword 0x0

.align 1
EventScript_ItemsSabrinaBadge2:
    .hword ITEM_POTION
    .hword ITEM_ANTIDOTE
    .hword ITEM_PARALYZE_HEAL
    .hword ITEM_AWAKENING
    .hword ITEM_POKE_BALL
    .hword ITEM_SUPER_POTION
    .hword ITEM_GREAT_BALL
    .hword ITEM_HONEY
    .hword ITEM_REPEL
    .hword ITEM_HYPER_POTION
    .hword ITEM_REVIVE
    .hword ITEM_DREAM_BALL
    .hword ITEM_SUPER_REPEL
    .hword ITEM_ULTRA_BALL
    .hword ITEM_FULL_HEAL
    .hword ITEM_MAX_REPEL
    .hword ITEM_PP_UP
    .hword ITEM_MAX_POTION
    .hword ITEM_ETHER
    .hword ITEM_ELIXIR
    .hword ITEM_FULL_RESTORE
    .hword ITEM_MAX_ETHER
    .hword ITEM_MAX_ELIXIR
    .hword ITEM_MAX_REVIVE
    .hword ITEM_PP_MAX    
    .hword 0x0

EnventScript_EndScript:
    msgbox gText_ComeAgain MSG_KEEPOPEN
    releaseall
    end
 