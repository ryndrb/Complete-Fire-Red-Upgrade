.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_DRAIN_PUNCH, 0x0D6
.equ FLAG_OBTAIN_SLEEP_TALK, 0x0DB

@@@@@@@@@@@@@@@@@@@@@@
@ Drain Punch | Saffron City Desk Lady
@@@@@@@@@@@@@@@@@@@@@@
EventScipt_SaffronDrainPunch:
    lock
    faceplayer
    checkflag FLAG_OBTAIN_DRAIN_PUNCH
    if 0x0 _goto EventScript_GiveDrainPunch
    msgbox 0x81754F7 MSG_FACE
    end 

EventScript_GiveDrainPunch:
    msgbox gText_GiveDrainPunchQuestion MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EventScript_TooBad
    msgbox gText_GiveDrainPunchAccept MSG_KEEPOPEN
    giveitem ITEM_TM60 0x1 MSG_OBTAIN
    setflag FLAG_OBTAIN_DRAIN_PUNCH
    release
    end

EventScript_TooBad:
    msgbox gText_TooBad MSG_KEEPOPEN
    closeonkeypress
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Sleep Talk | Saffron City
@@@@@@@@@@@@@@@@@@@@@@
EventScript_SaffronSleepTalk:
    lock
    checkflag FLAG_OBTAIN_SLEEP_TALK
    if 0x0 _goto EventScript_GiveSleepTalk
    msgbox gText_SleepTalkObtained MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_GiveSleepTalk:
    msgbox gText_GiveSleepTalk MSG_KEEPOPEN
    giveitem ITEM_TM82 0x1 MSG_OBTAIN
    setflag FLAG_OBTAIN_SLEEP_TALK
    closeonkeypress
    release
    end
