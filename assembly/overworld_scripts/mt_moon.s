.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ Proton Encounter
@@@@@@@@@@@@@@@@@@@@@@
EventScript_MtMoon_Proton:
    lock
    applymovement 13 Move_MtMoon_Proton1
    waitmovement 13
    sound 0x15
    applymovement 13 Move_MtMoon_Proton2
    waitmovement 13
    playsong 0x184 1
    call UnknownNameBox
    msgbox gText_MtMoon_ProtonSpeak1 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 13 Move_MtMoon_Proton3
    waitmovement 13
    call ProtonNameBox
    msgbox gText_MtMoon_ProtonSpeak2 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    trainerbattle3 0x3 0x6 0x0 gText_MtMoon_ProtonDefeated
    call ProtonNameBox
    msgbox gText_MtMoon_ProtonSpeak3 MSG_KEEPOPEN
    closeonkeypress
    callasm RemoveNameBox
    applymovement 13 Move_MtMoon_Proton4
    waitmovement 13
    sound 9
    hidesprite 13
    setflag FLAG_ENCOUNTER_MTMOON_PROTON
    fadedefaultbgm
    release
    end

Move_MtMoon_Proton1:
    .byte pause_long
    .byte exclaim
    .byte end_m

Move_MtMoon_Proton2:
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

Move_MtMoon_Proton3:
    .byte walk_right_onspot_fastest
    .byte pause_long
    .byte walk_left_onspot_fastest
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte pause_long
    .byte walk_up_onspot_fastest
    .byte end_m

Move_MtMoon_Proton4:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_up_onspot_fastest
    .byte pause_long
    .byte walk_left
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ MtMoon NameBox
@@@@@@@@@@@@@@@@@@@@@@
UnknownNameBox:
    setvar 0x8000 0
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return

ProtonNameBox:
    setvar 0x8000 23
    setvar 0x8001 LEFT
    callasm DrawNameBox
    return
