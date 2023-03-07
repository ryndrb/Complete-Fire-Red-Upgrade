.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_SUBSTITUTE, 0x0D9

@@@@@@@@@@@@@@@@@@@@@@
@ Substitute
@@@@@@@@@@@@@@@@@@@@@@
EventScript_FuschiaSubstitute:
    textcolor BLUE
    lock
    faceplayer
    checkflag FLAG_OBTAIN_SUBSTITUTE
    if 0x0 _goto EventScript_GiveSub
    msgbox gText_WantToBecomeTrainer MSG_FACE
    release
    end

EventScript_GiveSub:
    msgbox gText_KidNotice MSG_KEEPOPEN
    applymovement 0x2 EventScript_KidExclaim
    waitmovement 0x2
    msgbox gText_KidGiveSub MSG_KEEPOPEN
    giveitem ITEM_TM90 0x1 MSG_OBTAIN
    msgbox gText_ObtainedSubstitute MSG_KEEPOPEN
    setflag FLAG_OBTAIN_SUBSTITUTE
    release
    end

EventScript_KidExclaim:
    .byte exclaim
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@
@ Former Substitute Kid
@@@@@@@@@@@@@@@@@@@@@@
EventScript_FormerSubstituteKid:
    lock
    faceplayer
    msgbox gText_FormerSubstituteKid MSG_KEEPOPEN
    release
    end

@@@@@@@@@@@@@@@@@@@@@@
@ Retired Fisherman
@@@@@@@@@@@@@@@@@@@@@@
EventScript_RetiredFisherMan:
    lock
    faceplayer
    textcolor BLUE
    msgbox gText_RetireFisherManSpeak1 MSG_KEEPOPEN
    msgbox gText_RetireFisherManSpeak2 MSG_KEEPOPEN
    release
    end
