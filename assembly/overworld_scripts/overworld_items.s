.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_SOOTHE_BELL, 0x0B2
.equ FLAG_OBTAIN_BIG_ROOT, 0x0B3
.equ FLAG_OBTAIN_BINDING_BAND, 0x0B4
.equ FLAG_OBTAIN_SHELL_BELL, 0x0B5
.equ FLAG_OBTAIN_TOXIC_ORB, 0x0B6
.equ FLAG_OBTAIN_FLAME_ORB, 0x0B7
.equ FLAG_OBTAIN_ZOOM_LENS, 0x0B8
.equ FLAG_OBTAIN_PROTECTIVE_PADS, 0x0B9
.equ FLAG_OBTAIN_LIFE_ORB, 0x0BA
.equ FLAG_OBTAIN_GRASS_KNOT, 0x0C0
.equ FLAG_OBTAIN_SMACK_DOWN, 0x0C1
.equ FLAG_OBTAIN_SNARL, 0x0C2
.equ FLAG_OBTAIN_FLAME_CHARGE, 0x0C3
.equ FLAG_OBTAIN_ROCK_SLIDE, 0x0C4
.equ FLAG_OBTAIN_DREAM_EATER, 0x0C5
.equ FLAG_OBTAIN_STRUGGLE_BUG, 0x0C6
.equ FLAG_OBTAIN_DAZZLING_GLEAM, 0x0C7
.equ FLAG_OBTAIN_SLUDGE_WAVE, 0x0C8
.equ FLAG_OBTAIN_PSYSHOCK, 0x0C9
.equ FLAG_OBTAIN_ACROBATICS, 0x0CA
.equ FLAG_OBTAIN_DRAGON_PULSE, 0x0CB
.equ FLAG_OBTAIN_WILL_O_WISP, 0x0CC
.equ FLAG_OBTAIN_SHADOW_CLAW, 0x0CD
.equ FLAG_OBTAIN_AVALANCHE, 0x0CE
.equ FLAG_OBTAIN_AURORA_VEIL, 0x0CF
.equ FLAG_OBTAIN_DARK_PULSE, 0x0D0
.equ FLAG_OBTAIN_FLASH_CANNON, 0x0D1
.equ FLAG_OBTAIN_WILD_CHARGE, 0x0D2
.equ FLAG_OBTAIN_POISON_JAB, 0x0D3
.equ FLAG_OBTAIN_FALSE_SWIPE, 0x0D5
.equ FLAG_OBTAIN_ROCK_POLISH, 0x0DD
.equ FLAG_OBTAIN_INCINERATE, 0x0DF
.equ FLAG_OBTAIN_WORK_UP, 0x0E0
.equ FLAG_OBTAIN_INFESTATION, 0x0E1
.equ FLAG_OBTAIN_DEFOG, 0x0E2
.equ FLAG_OBTAIN_TRICK_ROOM, 0x0E3
.equ FLAG_OBTAIN_STONE_EDGE, 0x0E4
.equ FLAG_OBTAIN_BRINE, 0x0E5
.equ FLAG_OBTAIN_HM07, 0x1F1
.equ FLAG_OBTAIN_ABSOLITE, 0x0E6
.equ FLAG_OBTAIN_AGGRONITE, 0x0E7
.equ FLAG_OBTAIN_AMPHAROSITE, 0x0E8
.equ FLAG_OBTAIN_AUDINITE, 0x0E9
.equ FLAG_OBTAIN_BANETTITE, 0x0EA
.equ FLAG_OBTAIN_CAMERUPTITE, 0x0EB
.equ FLAG_OBTAIN_GLALILITE, 0x0EC
.equ FLAG_OBTAIN_HERACRONITE, 0x0ED
.equ FLAG_OBTAIN_KANGASKHANITE, 0x0EE
.equ FLAG_OBTAIN_LOPUNITE, 0x0EF
.equ FLAG_OBTAIN_LUCARIONITE, 0x0F0
.equ FLAG_OBTAIN_MAWILITE, 0x0F1
.equ FLAG_OBTAIN_MEDICHAMITE, 0x0F2
.equ FLAG_OBTAIN_PIDGEOTITE, 0x0F3
.equ FLAG_OBTAIN_PINSIRITE, 0x0F4
.equ FLAG_OBTAIN_SABLENITE, 0x0F5
.equ FLAG_OBTAIN_SCIZORITE, 0x0F6
.equ FLAG_OBTAIN_SHARPEDONITE, 0x0F7
.equ FLAG_OBTAIN_SLOWBRONITE, 0x0F8

@@@@@@@@@@@@@@@@@@@@@@
@ Soothe Bell | Route 1
@@@@@@@@@@@@@@@@@@@@@@
EventScript_SootheBell:
    giveitem ITEM_SOOTHE_BELL 0x1 MSG_FIND
    setflag FLAG_OBTAIN_SOOTHE_BELL
    hidesprite 0x4
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Big Root | Viridian Forest
@@@@@@@@@@@@@@@@@@@@@@
 EventScript_BigRoot:
    giveitem ITEM_BIG_ROOT 0x1 MSG_FIND
    setflag FLAG_OBTAIN_BIG_ROOT
    hidesprite 0xC
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Shell Bell | Viridian Forest
@@@@@@@@@@@@@@@@@@@@@@
 EventScript_ShellBell:
    giveitem ITEM_SHELL_BELL 0x1 MSG_FIND
    setflag FLAG_OBTAIN_SHELL_BELL
    hidesprite 0xD
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Binding Band | Route 2
@@@@@@@@@@@@@@@@@@@@@@
 EventScript_BindingBand:
    giveitem ITEM_BINDING_BAND 0x1 MSG_FIND
    setflag FLAG_OBTAIN_BIG_ROOT
    hidesprite 0x8
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Toxic Orb | Route 13
@@@@@@@@@@@@@@@@@@@@@@
EventScript_ToxicOrb:
    giveitem ITEM_TOXIC_ORB 0x1 MSG_FIND
    setflag FLAG_OBTAIN_TOXIC_ORB
    hidesprite 0xC
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Flame Orb | Route 13
@@@@@@@@@@@@@@@@@@@@@@
EventScript_FlameOrb:
    giveitem ITEM_FLAME_ORB 0x1 MSG_FIND
    setflag FLAG_OBTAIN_FLAME_ORB
    hidesprite 0xD
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Zoom Lens | Route 21
@@@@@@@@@@@@@@@@@@@@@@
EventScript_ZoomLens:
    giveitem ITEM_ZOOM_LENS 0x1 MSG_FIND
    setflag FLAG_OBTAIN_ZOOM_LENS
    hidesprite 0xD
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Proctective Pads | Route 16
@@@@@@@@@@@@@@@@@@@@@@
EventScript_ProtectivePads:
    giveitem ITEM_PROTECTIVE_PADS 0x1 MSG_FIND
    setflag FLAG_OBTAIN_PROTECTIVE_PADS
    hidesprite 0xB
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Life Orb | Route 6
@@@@@@@@@@@@@@@@@@@@@@
EventScript_LifeOrb:
    giveitem ITEM_LIFE_ORB 0x1 MSG_FIND
    setflag FLAG_OBTAIN_LIFE_ORB
    hidesprite 0x7
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Grass Knot | Req. Surf
@@@@@@@@@@@@@@@@@@@@@@
EventScript_GrassKnot:
    giveitem ITEM_TM86 0x1 MSG_FIND
    setflag FLAG_OBTAIN_GRASS_KNOT
    hidesprite 0xE
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Smack Down | Route 2 | Inside House
@@@@@@@@@@@@@@@@@@@@@@
EventScript_SmackDown:
    giveitem ITEM_TM111 0x1 MSG_FIND
    setflag FLAG_OBTAIN_SMACK_DOWN
    hidesprite 0x3
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Snarl | Route 4
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Snarl:
    giveitem ITEM_TM108 0x1 MSG_FIND
    setflag FLAG_OBTAIN_SNARL
    hidesprite 0x8
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Flame Charge | Route 5
@@@@@@@@@@@@@@@@@@@@@@
EventScript_FlameCharge:
    giveitem ITEM_TM77 0x1 MSG_FIND
    setflag FLAG_OBTAIN_FLAME_CHARGE
    hidesprite 0x1
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Rock Slide | Fuschia City
@@@@@@@@@@@@@@@@@@@@@@
EventScript_RockSlide:
    giveitem ITEM_TM80 0x1 MSG_FIND
    setflag FLAG_OBTAIN_ROCK_SLIDE
    hidesprite 0x11
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Dream Eater | Route 19
@@@@@@@@@@@@@@@@@@@@@@
EventScript_DreamEater:
    giveitem ITEM_TM85 0x1 MSG_FIND
    setflag FLAG_OBTAIN_DREAM_EATER
    hidesprite 0xD
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Struggle Bug | Pewter City
@@@@@@@@@@@@@@@@@@@@@@
EventScript_StruggleBug:
    giveitem ITEM_TM95 0x1 MSG_FIND
    setflag FLAG_OBTAIN_STRUGGLE_BUG
    hidesprite 0x8
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Dazzling Gleam | Celadon Mansion
@@@@@@@@@@@@@@@@@@@@@@
EventScript_DazzlingGleam:
    giveitem ITEM_TM102 0x1 MSG_FIND
    setflag FLAG_OBTAIN_DAZZLING_GLEAM
    hidesprite 0x1
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Sludge Wave | Route 1
@@@@@@@@@@@@@@@@@@@@@@
EventScript_SludgeWave:
    giveitem ITEM_TM103 0x1 MSG_FIND
    setflag FLAG_OBTAIN_SLUDGE_WAVE
    hidesprite 0x5
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Psyshock | Route 10
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Psyshock:
    giveitem ITEM_TM104 0x1 MSG_FIND
    setflag FLAG_OBTAIN_PSYSHOCK
    hidesprite 0xB
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Acrobatics | Route 14
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Acrobatics:
    giveitem ITEM_TM107 0x1 MSG_FIND
    setflag FLAG_OBTAIN_ACROBATICS
    hidesprite 0xE
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Dragon Pulse | Route 21
@@@@@@@@@@@@@@@@@@@@@@
EventScript_DragonPulse:
    giveitem ITEM_TM59 0x1 MSG_FIND
    setflag FLAG_OBTAIN_DRAGON_PULSE
    hidesprite 0x8
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Will O Wisp | Route 15
@@@@@@@@@@@@@@@@@@@@@@
EventScript_WillOWisp:
    giveitem ITEM_TM61 0x1 MSG_FIND
    setflag FLAG_OBTAIN_WILL_O_WISP
    hidesprite 0xF
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Shadow Claw | Lavender Town
@@@@@@@@@@@@@@@@@@@@@@
EventScript_ShadowClaw:
    giveitem ITEM_TM65 0x1 MSG_FIND
    setflag FLAG_OBTAIN_SHADOW_CLAW
    hidesprite 0x7
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Avalanche | Seafoam Island
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Avalanche:
    giveitem ITEM_TM72 0x1 MSG_FIND
    setflag FLAG_OBTAIN_AVALANCHE
    hidesprite 0x4
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Aurora Veil | Seafoam Island
@@@@@@@@@@@@@@@@@@@@@@
EventScript_AuroraVeil:
    giveitem ITEM_TM118 0x1 MSG_FIND
    setflag FLAG_OBTAIN_AURORA_VEIL
    hidesprite 0xC
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Dark Pulse | Team Rocket Base Celadon
@@@@@@@@@@@@@@@@@@@@@@
EventScript_DarkPulse:
    giveitem ITEM_TM79 0x1 MSG_FIND
    setflag FLAG_OBTAIN_DARK_PULSE
    hidesprite 0xA
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Flash Cannon | Rock Tunnel
@@@@@@@@@@@@@@@@@@@@@@
EventScript_FlashCannon:
    giveitem ITEM_TM91 0x1 MSG_FIND
    setflag FLAG_OBTAIN_FLASH_CANNON
    hidesprite 0x2
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Wild Charge | Safari Zone
@@@@@@@@@@@@@@@@@@@@@@
EventScript_WildCharge:
    giveitem ITEM_TM99 0x1 MSG_FIND
    setflag FLAG_OBTAIN_WILD_CHARGE
    hidesprite 0xB
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Poison Jab | Route 17
@@@@@@@@@@@@@@@@@@@@@@
EventScript_PoisonJab:
    giveitem ITEM_TM84 0x1 MSG_FIND
    setflag FLAG_OBTAIN_POISON_JAB
    hidesprite 0xB
    end

@@@@@@@@@@@@@@@@@@@@@@
@ False Swipe | Route 22
@@@@@@@@@@@@@@@@@@@@@@
EventScript_FalseSwipe:
    giveitem ITEM_TM54 0x1 MSG_FIND
    setflag FLAG_OBTAIN_FALSE_SWIPE
    hidesprite 0x2
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Rock Polish | Route 8
@@@@@@@@@@@@@@@@@@@@@@
EventScript_RockPolish:
    giveitem ITEM_TM69 0x1 MSG_FIND
    setflag FLAG_OBTAIN_ROCK_POLISH
    hidesprite 0x11
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Inicinerate | Mt Moon
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Incinerate:
    giveitem ITEM_TM94 0x1 MSG_FIND
    setflag FLAG_OBTAIN_INCINERATE
    hidesprite 0x11
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Work Up | Viridian City
@@@@@@@@@@@@@@@@@@@@@@
EventScript_WorkUp:
    giveitem ITEM_TM98 0x1 MSG_FIND
    setflag FLAG_OBTAIN_WORK_UP
    hidesprite 0xA
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Infestation | Viridian Forest
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Infestation:
    giveitem ITEM_TM100 0x1 MSG_FIND
    setflag FLAG_OBTAIN_INFESTATION
    hidesprite 0x12
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Defog | Route 12
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Defog:
    giveitem ITEM_TM109 0x1 MSG_FIND
    setflag FLAG_OBTAIN_DEFOG
    hidesprite 0xF
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Trick Room | Saffron City Siplh Co. Floor 7
@@@@@@@@@@@@@@@@@@@@@@
EventScript_TrickRoom:
    giveitem ITEM_TM116 0x1 MSG_FIND
    setflag FLAG_OBTAIN_TRICK_ROOM
    hidesprite 0xC
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Stone Edge | Pokemon Mansion
@@@@@@@@@@@@@@@@@@@@@@
EventScript_StoneEdge:
    giveitem ITEM_TM71 0x1 MSG_FIND
    setflag FLAG_OBTAIN_STONE_EDGE
    hidesprite 0x7
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Brine | Route 7
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Brine:
    giveitem ITEM_TM55 0x1 MSG_FIND
    setflag FLAG_OBTAIN_BRINE
    hidesprite 0x3
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Waterfall | Celadon City
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Waterfall:
    giveitem ITEM_HM07 0x1 MSG_FIND
    setflag FLAG_OBTAIN_HM07
    hidesprite 0x10
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Absolite | Safari Zone
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Absolite:
    giveitem ITEM_ABSOLITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_ABSOLITE
    hidesprite 0x5
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Aggronite | Viridian City
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Aggronite:
    giveitem ITEM_AGGRONITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_AGGRONITE
    hidesprite 0xB
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Ampharosite | Power Plant
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Ampharosite:
    giveitem ITEM_AMPHAROSITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_AMPHAROSITE
    hidesprite 0x9
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Audinite | Route 21
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Audinite:
    giveitem ITEM_AUDINITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_AUDINITE
    hidesprite 0x9
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Banettite | Route 9
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Banettite:
    giveitem ITEM_BANETTITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_BANETTITE
    hidesprite 0xF
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Cameruptite | Cinnabar Island
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Cameruptite:
    giveitem ITEM_CAMERUPTITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_CAMERUPTITE
    hidesprite 0x4
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Glalilite | Seafoam Island
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Glalilite:
    giveitem ITEM_GLALITITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_GLALILITE
    hidesprite 0x7
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Heracronite | Route 12
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Heracronite:
    giveitem ITEM_HERACRONITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_HERACRONITE
    hidesprite 0x10
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Kangaskhanite | Safari Zone
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Kangaskhanite:
    giveitem ITEM_KANGASKHANITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_KANGASKHANITE
    hidesprite 0x4
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Lopunite | Route 17
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Lopunite:
    giveitem ITEM_LOPUNNITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_LOPUNITE
    hidesprite 0xC
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Lucarionite | Route 19
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Lucarionite:
    giveitem ITEM_LUCARIONITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_LUCARIONITE
    hidesprite 0xE
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Mawilite | Route 5
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Mawilite:
    giveitem ITEM_MAWILITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_MAWILITE
    hidesprite 0xE
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Medichamite | Route 9
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Medichamite:
    giveitem ITEM_MEDICHAMITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_MEDICHAMITE
    hidesprite 0x10
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Pidgeotite | Route 15
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pidgeotite:
    giveitem ITEM_PIDGEOTITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_PIDGEOTITE
    hidesprite 0x2
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Pinsirite | Viridian Forest
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Pinsirite:
    giveitem ITEM_PINSIRITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_PINSIRITE
    hidesprite 0x11
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Sablenite | Rock Tunnel
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Sablenite:
    giveitem ITEM_SABLENITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_SABLENITE
    hidesprite 0x1B
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Scizorite | Route 14
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Scizorite:
    giveitem ITEM_SCIZORITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_SCIZORITE
    hidesprite 0xE
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Sharpedonite | Route 20
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Sharpedonite:
    giveitem ITEM_SHARPEDONITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_SHARPEDONITE
    hidesprite 0xD
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Slowbronite | Route 24
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Slowbronite:
    giveitem ITEM_SLOWBRONITE 0x1 MSG_FIND
    setflag FLAG_OBTAIN_SLOWBRONITE
    hidesprite 0x9
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Strength Boulder Script
@@@@@@@@@@@@@@@@@@@@@@
EventScript_StrengthBoulder:
    special 0x187
    compare LASTRESULT 0x2
    if 0x1 _goto 0x81A7AE0
    lockall
    checkflag 0x823
    if 0x0 _goto 0x81BE185
    checkflag 0x805
    if 0x1 _goto 0x81BE18E
    checkattack 0x46
    compare LASTRESULT 0x6
    if 0x1 _goto 0x81BE185
    setanimation 0x0 LASTRESULT
    msgbox 0x81BE19A MSG_YESNO
    compare LASTRESULT 0x0
    if 0x1 _goto 0x81BE197
    closeonkeypress
    doanimation 0x28
    waitstate
    goto 0x81BE179
