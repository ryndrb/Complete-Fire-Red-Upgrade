.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@
@ Lake Viridian Sign post
@@@@@@@@@@@@@@@@@@@@
EventScript_Route2_LakeViridianSignpost:
    signmsg
    msgbox gText_Route2_LakeViridianSignpost MSG_FACE
    release
    end
