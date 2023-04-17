.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_ROUTE21_THUNDERSTORMS, 0x9C0

@@@@@@@@@@@@@@@@@@@@@@
@ Route 21 Thunderstorms (Kyogre)
@@@@@@@@@@@@@@@@@@@@@@
MapScript_Route21:
    mapscript MAP_SCRIPT_ON_RESUME EventScript_Route21
    .byte MAP_SCRIPT_TERMIN

EventScript_Route21:
    checkflag FLAG_ROUTE21_THUNDERSTORMS
    if NOT_SET _goto EventScript_Route21_End
    setweather 0xD
    doweather
    release
    end

EventScript_Route21_End:
    release
    end
