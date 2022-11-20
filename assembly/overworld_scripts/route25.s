.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@
@ Rotom Encounter | Route 25 Bill's House
@@@@@@@@@@@@@@@@@@@@
EventScript_RotomEncounter:
    lock
    faceplayer
    msgbox gText_RotomEncounter MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EvenScript_End
    msgbox gText_PlayerThumpMachine MSG_NORMAL
    pause 30
    applymovement PLAYER EventScript_PlayerThump
    waitmovement 0x0
    pause 60
    applymovement PLAYER EventScript_PlayerThump
    waitmovement 0x0
    pause 30
    msgbox gText_RotomAppears MSG_KEEPOPEN
    cry SPECIES_ROTOM 0x0
    wildbattle SPECIES_ROTOM 25 0x0
    release
    end

EventScript_PlayerThump:
    .byte exclaim
    .byte end_m

EvenScript_End:
    release
    end
