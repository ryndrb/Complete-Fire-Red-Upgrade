.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ Member Card Lady
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route16_Fly:
    lock
    checkflag 0x238
    if SET _goto EventScript_Route16_FlyUseful
    faceplayer
    msgbox gText_Route16_Lady_Fly_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    giveitem ITEM_HM02 0x1 MSG_OBTAIN
    goto EventScript_Route16_FlyUseful
    release
    end

EventScript_Route16_FlyUseful:
    checkflag FLAG_ROUTE16_MEMBERCARD
    if NOT_SET _goto EventScript_Route16_MemberCard
    faceplayer
    msgbox gText_Route16_Lady_Fly_Speak_2 MSG_KEEPOPEN
    closeonkeypress
    setflag 0x238
    release
    end

EventScript_Route16_FlyUseful2:
    faceplayer
    msgbox gText_Route16_Lady_Fly_Speak_2 MSG_KEEPOPEN
    closeonkeypress
    setflag 0x238
    release
    end

EventScript_Route16_MemberCard:
    checkflag FLAG_CRESSELIA_EVENT_FINISHED
    if NOT_SET _goto EventScript_Route16_FlyUseful2
    msgbox gText_Route16_Lady_MemberCard_Speak_1 MSG_KEEPOPEN
    closeonkeypress
    msgbox gText_Route16_Player_LunarWingGlow MSG_KEEPOPEN
    fanfare 0x100
    waitfanfare
    closeonkeypress
    pause 30
    sound 0x15
    applymovement 0x1 Move_Route16_Lady_1
    waitmovement 0x1
    faceplayer
    pause 30
    msgbox gText_Route16_Lady_MemberCard_Speak_2 MSG_KEEPOPEN
    closeonkeypress
    fanfare 0x13E
    msgbox gText_Route16_Player_ReceivedMemberCard MSG_KEEPOPEN
    waitfanfare
    msgbox gText_Route16_Lady_MemberCard_Speak_3 MSG_KEEPOPEN
    closeonkeypress
    setflag FLAG_ROUTE16_MEMBERCARD
    release
    end

Move_Route16_Lady_1:
    .byte exclaim
    .byte pause_long
    .byte end_m
