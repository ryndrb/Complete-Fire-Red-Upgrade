.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_MoveTutor
EventScript_MoveTutor:
	lock
	faceplayer
	checkflag 0x400
	compare LASTRESULT 0x1
	if 0x1 _goto Learned
	msgbox gText_EventScriptDoYouWantPoisonJab MSG_YESNO
	compare LASTRESULT 0x1
	if 0x0 _goto End
	setvar 0x8005 0x3D
	goto TutorScreen
	setflag 0x400
	release
	end

TutorScreen:
	special 0x18D
	waitstate
	return

Learned:
	msgbox gText_EventScriptLearned MSG_NORMAL
	closeonkeypress
	release
	end

End:
	msgbox gText_EventScriptEnd MSG_NORMAL
	closeonkeypress
	release
	end
	
