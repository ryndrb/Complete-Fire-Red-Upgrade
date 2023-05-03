.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@
@ Rival | Route 22 | First Encounter
@@@@@@@@@@@@@@@@@@@@
EventScript_0x16828C:
    lockall
    spriteface PLAYER, LEFT
    setvar 0x4001 0x0
    goto EventScript_0x81682BE

EventScript_0x168298:
    lockall
    setvar 0x4001 0x1
    movesprite2 0x1 0x17 0x5
    goto EventScript_0x81682BE

EventScript_0x1682AB:
    lockall
    setvar 0x4001 0x2
    movesprite2 0x1 0x17 0x5
    goto EventScript_0x81682BE

EventScript_0x81682BE:
    playsong 0x13B 0x0
    showsprite 0x1
    compare 0x4001 0x0
    if 0x1 _call EventScript_0x8168350
    compare 0x4001 0x1
    if 0x1 _call EventScript_0x8168350
    compare 0x4001 0x2
    if 0x1 _call EventScript_0x816835B
    pause 0x6
    call RivalNameBox
    msgbox gText_Route22_RivalSpeak1 MSG_KEEPOPEN
    callasm RemoveNameBox
    compare 0x4031 0x2
    if 0x1 _call EventScript_0x816836D
    compare 0x4031 0x1
    if 0x1 _call EventScript_0x816837C
    compare 0x4031 0x0
    if 0x1 _call EventScript_0x816838B
    call RivalNameBox
    msgbox gText_Route22_RivalSpeak2 MSG_KEEPOPEN
    callasm RemoveNameBox
    closeonkeypress
    pause 0xA
    playsong 0x13C 0x0
    compare 0x4001 0x0
    if 0x1 _call EventScript_0x816839A
    compare 0x4001 0x1
    if 0x1 _call EventScript_0x816839A_2
    compare 0x4001 0x2
    if 0x1 _call EventScript_0x81683A5
    fadedefault
    hidesprite 0x1
    setvar 0x4054 0x2
    releaseall
    end

EventScript_0x8168350:
    applymovement 0x1 EventScript_0x81683D1
    waitmovement 0x0
    return

EventScript_0x816835B:
    applymovement 0x1 EventScript_0x81683D9
    applymovement PLAYER EventScript_0x81683E3
    waitmovement 0x0
    return

EventScript_0x816836D:
    trainerbattle9 0x9 0x149 0x0 0x8188959 0x818DE1A
    return

EventScript_0x816837C:
    trainerbattle9 0x9 0x14A 0x0 0x8188959 0x818DE1A
    return

EventScript_0x816838B:
    trainerbattle9 0x9 0x14B 0x0 0x8188959 0x818DE1A
    return

EventScript_0x816839A:
    applymovement 0x1 EventScript_0x81683B8
    waitmovement 0x0
    return

EventScript_0x816839A_2:
    applymovement 0x1 EventScript_0x81683B8_2
    waitmovement 0x0
    return

EventScript_0x81683A5:
    applymovement 0x1 EventScript_0x81683C5
    waitmovement 0x0
    return

EventScript_0x81683D1:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte 0xFE

EventScript_0x81683D9:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down_onspot_fastest
    .byte end_m

EventScript_0x81683E3:
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte 0x1B
    .byte walk_up_onspot_fastest
    .byte end_m

EventScript_0x81683B8:
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte walk_up
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

EventScript_0x81683B8_2:
    .byte walk_up
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

EventScript_0x81683C5:
    .byte walk_up
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

@@@@@@@@@@@@@@@@@@@@
@ Rival | Route 22 | Second Encounter
@@@@@@@@@@@@@@@@@@@@
EventScript_0x1683ED:
    lockall
    spriteface PLAYER, LEFT
    setvar 0x4001 0x0
    goto EventScript_0x16841F

EventScript_0x1683F9:
    lockall
    setvar 0x4001 0x1
    movesprite2 0x1 0x17 0x5
    goto EventScript_0x16841F

EventScript_0x16840C:
    lockall
    setvar 0x4001 0x2
    movesprite2 0x1 0x17 0x5
    goto EventScript_0x16841F

EventScript_0x16841F:
    playsong 0x13B 0x0
    showsprite 0x1
    compare 0x4001 0x0
    if 0x1 _call EventScript_0x16849C
    compare 0x4001 0x1
    if 0x1 _call EventScript_0x16849C
    compare 0x4001 0x2
    if 0x1 _call EventScript_0x1684A7
    call RivalNameBox
    msgbox gText_Route22_RivalSpeak3 MSG_KEEPOPEN
    callasm RemoveNameBox
    setvar LASTTALKED 0x1
    compare 0x4031 0x2
    if 0x1 _call EventScript_0x1684B9
    compare 0x4031 0x1
    if 0x1 _call EventScript_0x1684C4
    compare 0x4031 0x0
    if 0x1 _call EventScript_0x1684CF
    call RivalNameBox
    msgbox gText_Route22_RivalSpeak4 MSG_KEEPOPEN
    callasm RemoveNameBox
    closeonkeypress
    pause 0xA
    playsong 0x13C 0x0
    applymovement 0x1 EventScript_0x1684DA
    waitmovement 0x0
    fadedefault
    hidesprite 0x1
    setvar 0x4054 0x4
    releaseall
    end

EventScript_0x16849C:
    applymovement 0x1 EventScript_0x1683D1
    waitmovement 0x0
    return

EventScript_0x1684A7:
    applymovement 0x1 EventScript_0x1683D9
    applymovement PLAYER EventScript_0x1683E3
    waitmovement 0x0
    return

EventScript_0x1684B9:
    trainerbattle3 0x3 0x1B3 0x0 0x8188B08
    return

EventScript_0x1684C4:
    trainerbattle3 0x3 0x1B4 0x0 0x8188B08
    return

EventScript_0x1684CF:
    trainerbattle3 0x3 0x1B5 0x0 0x8188B08
    return

EventScript_0x1684DA:
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte end_m

EventScript_0x1683D1:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte end_m

EventScript_0x1683D9:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_down_onspot_fastest
    .byte end_m

EventScript_0x1683E3:
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte pause_long
    .byte 0x1B
    .byte walk_up_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@
@ Route 22 NameBox
@@@@@@@@@@@@@@@@@@@@
RivalNameBox:
    setvar 0x8000 1
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
