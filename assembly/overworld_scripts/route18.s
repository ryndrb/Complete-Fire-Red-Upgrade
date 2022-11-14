.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_OBTAIN_WEATHER_ROCKS, 0x0BC

@@@@@@@@@@@@@@@@@@@@
@ Damp Rock | Icy Rock | Smooth Rock | Heat Rock | Route 18
@@@@@@@@@@@@@@@@@@@@
EventScript_HoennWeatherGuy:
    lock
    faceplayer
    msgbox gText_EventScript_HoennWeatherGuyIntro MSG_KEEPOPEN
    checkflag FLAG_OBTAIN_WEATHER_ROCKS
    if 0x0 _goto EventScript_HoennWeatherGuyGiveRocks
    release
    end

EventScript_HoennWeatherGuyGiveRocks:
    msgbox gText_EventScript_HoennWeatherGuyGiveRocks MSG_KEEPOPEN
    giveitem ITEM_ICY_ROCK 0x1 MSG_OBTAIN
    giveitem ITEM_DAMP_ROCK 0x1 MSG_OBTAIN
    giveitem ITEM_HEAT_ROCK 0x1 MSG_OBTAIN
    giveitem ITEM_SMOOTH_ROCK 0x1 MSG_OBTAIN
    msgbox gText_EventScript_HoennWeatherGuyEnd MSG_KEEPOPEN
    setflag FLAG_OBTAIN_WEATHER_ROCKS
    closeonkeypress
    release
    end
