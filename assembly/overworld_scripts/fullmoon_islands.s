.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ Fullmoon Island
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Fullmoon_LittleBoyDad:
    lock
    faceplayer
    checkflag FLAG_CRESSELIA_FULLMOON
    if NOT_SET _goto EventScript_Fullmoon_LittleBoyDad_PleaseHelp
    msgbox gText_Fullmoon_LittleBoyDad_Speak_2 MSG_KEEPOPEN
    closeonkeypress
    sound 0x15
    applymovement 0x4 Move_Fullmoon_LittleBoyDad_1
    waitmovement 0x4
    msgbox gText_Fullmoon_LittleBoyDad_Speak_3 MSG_KEEPOPEN
    closeonkeypress
    applymovement 0x4 Move_Fullmoon_LittleBoyDad_2
    applymovement PLAYER Move_Fullmoon_Player_1
    waitmovement 0x4
    warp 3 8 PLAYER 0x1C 0x26
    waitstate
    release
    end

EventScript_Fullmoon_LittleBoyDad_PleaseHelp:
    msgbox gText_Fullmoon_LittleBoyDad_Speak_1 MSG_NORMAL
    release
    end

Move_Fullmoon_LittleBoyDad_1:
    .byte exclaim
    .byte pause_long
    .byte end_m

Move_Fullmoon_LittleBoyDad_2:
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

Move_Fullmoon_Player_1:
    .byte walk_down_onspot_fastest
    .byte pause_long
    .byte walk_down_onspot_fastest
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Fullmoon Island Sign
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Fullmoon_Sign:
    signmsg
    msgbox gText_Fullmoon_Sign MSG_NORMAL
    release
    end
