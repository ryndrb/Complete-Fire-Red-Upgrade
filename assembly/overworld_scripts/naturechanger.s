.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"

@NATURE CHANGER SCRIPT
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.global EventScript_NatureChanger
EventScript_NatureChanger:
    	lock
    	faceplayer  
    	msgbox gText_NatureChangerQuestion MSG_YESNO 
	compare LASTRESULT 0x1
    	if 0x0 _goto EndScriptComeAgain
    	special 0x9F
    	waitstate
    	compare 0x8004 0x6
	if greaterorequal _goto EndScriptComeAgain
    	goto NatureList
    	end

NatureList:
    setvar 0x8000 0x2
    setvar 0x8001 0x6
    copyvar 0x5106 0x8004
    setvar 0x8004 0x0
    special 0x158
    waitstate 
    copyvar 0x8004 0x5106 
    compare LASTRESULT 0x25
    if greaterorequal _goto EndScriptComeAgain
    copyvar 0x8005 LASTRESULT
    callasm ChangeMonNature
    goto EndSciptNatureIsChanged
    end

EndSciptNatureIsChanged:
	msgbox gText_EndSciptNatureIsChanged MSG_KEEPOPEN
	closeonkeypress
	release
	end

EndScriptComeAgain:
	msgbox gText_EndScriptComeAgain MSG_KEEPOPEN
	closeonkeypress
	release
	end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
