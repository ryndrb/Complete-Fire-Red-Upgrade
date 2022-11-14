.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_EXPLOSION, 0x0DC

@@@@@@@@@@@@@@@@@@@@@@
@ Explosion | Cinnabar Island
@@@@@@@@@@@@@@@@@@@@@@
EventScript_CinnabarExplosion:
    lock
    faceplayer
    checkflag FLAG_OBTAIN_EXPLOSION
    if 0x0 _goto EventScript_GiveExplosion
    msgbox gText_ExplosionObtained MSG_KEEPOPEN
    closeonkeypress
    release
    end

EventScript_GiveExplosion:
    msgbox gText_GiveExplosion MSG_KEEPOPEN
    giveitem ITEM_TM64 0x1 MSG_OBTAIN
    setflag FLAG_OBTAIN_EXPLOSION
    release
    end
