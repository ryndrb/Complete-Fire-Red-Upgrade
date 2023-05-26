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

@@@@@@@@@@@@@@@@@@@@@@
@ Winona Route 16
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route16_Winona:
    lock
    npcmsg gText_Route16_Winona_Speak_1 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    pause 30
    sound 0x15
    applymovement 4 Move_Route16_Winona_1
    waitmovement 4
    npcmsg gText_Route16_Winona_Speak_2 MSG_KEEPOPEN gText_Name_Unknown
    closemsg
    npcmsg gText_Route16_Winona_Speak_3 MSG_KEEPOPEN gText_Name_Winona
    closemsg
    npcmsg gText_Route16_Winona_Speak_4 MSG_YESNO gText_Name_Winona
    compare LASTRESULT 0x1
    if notequal _goto EventScript_Route16_Winona_PlayerDontWantToBattle
    closemsg
    trainerbattle3 0x3 85 0x0 gText_Route16_Winona_Defeat
    npcmsg gText_Route16_Winona_Speak_5 MSG_KEEPOPEN gText_Name_Winona
    closemsg
    giveitem ITEM_SHARP_BEAK 0x1 MSG_OBTAIN
    npcmsg gText_Route16_Winona_Speak_6 MSG_KEEPOPEN gText_Name_Winona
    closemsg
    fadescreen 0x1
    hidesprite 4
    setflag FLAG_WINONA_ROUTE16_SPRITE
    fadescreen 0x0
    release
    end

EventScript_Route16_Winona_PlayerDontWantToBattle:
    npcmsg gText_Route16_Winona_PlayerDontWantToBattle MSG_KEEPOPEN gText_Name_Winona
    closemsg
    spriteface 4, UP
    release
    end

Move_Route16_Winona_1:
    .byte exclaim
    .byte pause_long
    .byte face_player
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Sleeping Lax
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Route16_Snorlax:
    lock
    faceplayer
    checkflag 0x23D
    if 0x0 _goto 0x81681A3
    special 0x187
    compare LASTRESULT 0x2
    if 0x1 _goto 0x81A7AE0
    special 0x188
    msgbox 0x81853CC MSG_YESNO
    compare LASTRESULT 0x0
    if 0x1 _goto 0x8168197
    call EventScript_0x81A924B
    setwildbattle 0x8F 0x1E 0x0
    checksound
    cry 0x8F 0x2
    pause 0x28
    waitcry
    setflag 0x80
    setflag 0x807
    dowildbattle
    clearflag 0x807
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x1
    if 0x1 _goto 0x8168199
    compare LASTRESULT 0x4
    if 0x1 _goto 0x8168199
    compare LASTRESULT 0x5
    if 0x1 _goto 0x8168199
    release
    end

.global EventScript_0x81A924B @ shared with route 12
EventScript_0x81A924B:
    preparemsg 0x81853E8
    waitmsg
    fanfare 0x152
    waitfanfare
    checkflag 0x4B5
    if NOT_SET _goto EventScript_Route16_Snorlax_NoSabrinaBadge
    msgbox 0x8185354 MSG_KEEPOPEN
    return

EventScript_Route16_Snorlax_NoSabrinaBadge:
    msgbox gText_Route16_Snorlax_NoSabrinaBadge MSG_KEEPOPEN
    closeonkeypress
    release
    end
