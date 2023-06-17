.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ Daisy
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Rival_House_Daisy:
    lock
    faceplayer
    checkflag FLAG_HIDE_PALLET_TOWN_OAK_LAB_RIVAL
    if NOT_SET _goto EventScript_Rival_House_Daisy_RivalInLab
    msgbox gText_Rival_House_Daisy_DontWorry MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_Rival_House_Daisy_RivalInLab:
    msgbox gText_Rival_House_Daisy_RivalInLab MSG_KEEPOPEN
    closeonkeypress
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Daisy and Rival Dad
@@@@@@@@@@@@@@@@@@@@@@
EventScript_Rival_House_RivalDad:
    lock
    faceplayer
    checkflag FLAG_HIDE_PALLET_TOWN_OAK_LAB_RIVAL
    if NOT_SET _goto EventScript_Rival_House_RivalDad_RivalInLab
    msgbox gText_Rival_House_RivalDad_TravelGreat MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_Rival_House_RivalDad_RivalInLab:
    msgbox gText_Rival_House_RivalDad_RivalInLab MSG_KEEPOPEN
    closeonkeypress
    release
    end
