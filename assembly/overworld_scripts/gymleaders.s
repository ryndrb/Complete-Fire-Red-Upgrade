.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ BROCK_DEFEATED 		,0x200
.equ MISTY_DEFEATED 		,0x201
.equ SURGE_DEFEATED 		,0x202
.equ ERIKA_DEFEATED 		,0x203
.equ SABRINA_DEFEATED 		,0x204
.equ KOGA_DEFEATED 			,0x205
.equ BLAINE_DEFEATED 		,0x206
.equ GIOVANNI_DEFEATED 		,0x207

EventScript_GymLeaderBrock:
    lock
    setvar 0x8004 0x2
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x19E 0x0 0x8190CD4 0x8190E4F EventScript_0x816A5C5
    checkflag 0x254
    if 0x0 _goto EventScript_0x816A5F3
    msgbox 0x819110F MSG_KEEPOPEN
    release
    end

EventScript_0x816A5C5:
    setvar 0x8004 0x2
    setvar 0x8005 0x1
    special 0x173
    setflag 0x4B0
    setflag 0x820
    setvar 0x406C 0x1
    setflag 0x2E
    clearflag 0x92
    setvar 0x8008 0x1
    call 0x81A6B18
    setflag BROCK_DEFEATED
    goto EventScript_0x816A5F3
    end

EventScript_0x816A5F3:
    msgbox 0x8190FC1 MSG_KEEPOPEN
    checkitemspace 0x147 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816A634
    giveitem_msg 0x8190FDB ITEM_TM39
    setflag 0x254
    msgbox 0x8190FF8 MSG_KEEPOPEN
    release
    end





EventScript_GymLeaderMisty:
    setvar 0x8004 0x3
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x19F 0x0 0x81921EF 0x819242D EventScript_0x816AAD3
    checkflag 0x297
    if 0x0 _goto EventScript_0x816AAF9
    msgbox 0x81922BF MSG_KEEPOPEN
    release
    end

EventScript_0x816AAD3:
    setvar 0x8004 0x3
    setvar 0x8005 0x1
    special 0x173
    setflag 0x4B1
    setflag 0x821
    sethealingplace 0x4
    setvar 0x8008 0x2
    call 0x81A6B18
    setflag MISTY_DEFEATED
    goto EventScript_0x816AAF9
    end

EventScript_0x816AAF9:
    msgbox 0x81922F7 MSG_KEEPOPEN
    checkitemspace 0x123 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816AB3A
    giveitem_msg 0x81923F1 ITEM_TM03
    setflag 0x297
    msgbox 0x81922BF MSG_KEEPOPEN
    release
    end





EventScript_GymLeaderSurge:
    setvar 0x8004 0x4
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x1A0 0x0 0x8194BA4 0x8194E03 EventScript_0x816B97C
    checkflag 0x231
    if 0x0 _goto EventScript_0x816B9AF
    msgbox 0x8194C8E MSG_KEEPOPEN
    release
    end

EventScript_0x816B97C:
    setvar 0x8004 0x4
    setvar 0x8005 0x1
    special 0x173
    checkflag 0x23B
    if 0x0 _goto 0x816B9AB
    clearflag 0xA0
    setflag 0x4B2
    setflag 0x822
    setvar 0x8008 0x3
    call 0x81A6B18
    setflag SURGE_DEFEATED
    goto EventScript_0x816B9AF
    end

EventScript_0x816B9AF:
    msgbox 0x8194CFA MSG_KEEPOPEN
    checkitemspace 0x142 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816B9F0
    giveitem_msg 0x8194D87 ITEM_TM34
    setflag 0x231
    msgbox 0x8194DA8 MSG_KEEPOPEN
    release
    end





EventScript_GymLeaderErika:
    setvar 0x8004 0x5
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x1A1 0x0 0x8197114 0x8197260 EventScript_0x816D0A0
    checkflag 0x293
    if 0x0 _goto 0x816D0C6
    setvar 0x8004 0x5
    setvar 0x8005 0x4
    special 0x173
    msgbox 0x81972B8 MSG_KEEPOPEN
    release
    end

EventScript_0x816D0A0:
    setvar 0x8004 0x5
    setvar 0x8005 0x1
    special 0x173
    clearflag 0x9E
    setflag 0x4B3
    setflag 0x823
    setvar 0x8008 0x4
    call 0x81A6B18
    setflag ERIKA_DEFEATED
    goto EventScript_0x816D0C6
    end

EventScript_0x816D0C6:
    msgbox 0x8197327 MSG_KEEPOPEN
    checkitemspace 0x133 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816D107
    giveitem_msg 0x81973BA ITEM_TM19
    setflag 0x293
    release
    end





EventScript_GymLeaderSabrina:
    setvar 0x8004 0x7
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x1A4 0x0 0x819B53C 0x819B602 EventScript_0x816EE0A
    checkflag 0x29A
    if 0x0 _goto 0x816EE3D
    msgbox 0x819B7F2 MSG_KEEPOPEN
    release
    end

EventScript_0x816EE0A:
    setvar 0x8004 0x7
    setvar 0x8005 0x2
    special 0x173
    setvar 0x8004 0x7
    setvar 0x8005 0x3
    special 0x173
    clearflag 0xAE
    setflag 0x4B5
    setflag 0x825
    setvar 0x8008 0x6
    call 0x81A6B18
    setflag SABRINA_DEFEATED
    goto EventScript_0x816EE3D
    end

EventScript_0x816EE3D:
    msgbox 0x819B6FA MSG_KEEPOPEN
    checkitemspace 0x124 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816EE7E
    giveitem_msg 0x819B7D3 ITEM_TM04
    setflag 0x29A
    msgbox 0x819B685 MSG_KEEPOPEN
    release
    end





EventScript_GymLeaderKoga:
    setvar 0x8004 0x6
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x1A2 0x0 0x819832E 0x8198444 EventScript_0x816D580
    checkflag 0x259
    if 0x0 _goto 0x816D5A6
    msgbox 0x8198481 MSG_KEEPOPEN
    release
    end

EventScript_0x816D580:
    setvar 0x8004 0x6
    setvar 0x8005 0x1
    special 0x173
    clearflag 0x9F
    setflag 0x4B4
    setflag 0x824
    setvar 0x8008 0x5
    call 0x81A6B18
    setflag KOGA_DEFEATED
    goto EventScript_0x816D5A6
    end

EventScript_0x816D5A6:
    msgbox 0x819850E MSG_KEEPOPEN
    checkitemspace 0x126 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816D5E7
    giveitem_msg 0x819858F ITEM_TM06
    setflag 0x259
    msgbox 0x81985AB MSG_KEEPOPEN
    release
    end





EventScript_GymLeaderBlaine:
    setvar 0x8004 0x8
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x1A3 0x0 0x8199543 0x81995FA EventScript_0x816DA06
    checkflag 0x24E
    if 0x0 _goto 0x816DA34
    msgbox 0x819971D MSG_KEEPOPEN
    release
    end

EventScript_0x816DA06:
    setvar 0x8004 0x8
    setvar 0x8005 0x1
    special 0x173
    setflag 0x4B6
    setflag 0x826
    sethealingplace 0x9
    setvar 0x4071 0x1
    clearflag 0x62
    setvar 0x8008 0x7
    call 0x81A6B18
    setflag BLAINE_DEFEATED
    goto EventScript_0x816DA34
    end

EventScript_0x816DA34:
    msgbox 0x819969E MSG_KEEPOPEN
    checkitemspace 0x146 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x816DA75
    giveitem_msg 0x81996FF ITEM_TM38
    setflag 0x24E
    msgbox 0x8199652 MSG_KEEPOPEN
    release
    end




EventScript_GymLeaderGiovanni:
    setvar 0x8004 0xF
    setvar 0x8005 0x2
    special 0x174
    trainerbattle1 0x1 0x15E 0x0 0x818F352 0x818F43F EventScript_0x8169F04
    checkflag 0x298
    if 0x0 _goto 0x8169F2F
    msgbox 0x818F4A2 MSG_KEEPOPEN
    closeonkeypress
    fadescreen 0x1
    hidesprite 0x8
    fadescreen 0x0
    release
    end

EventScript_0x8169F04:
    setvar 0x8004 0xF
    setvar 0x8005 0x3
    special 0x173
    setflag 0xAD
    setflag 0x4B7
    setflag 0x827
    setvar 0x4054 0x3
    setvar 0x8008 0x8
    call 0x81A6B18
    setflag GIOVANNI_DEFEATED
    goto 0x8169F2F
    end

EventScript_0x8169F2F:
    msgbox 0x818F586 MSG_KEEPOPEN
    checkitemspace 0x13A 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto 0x8169F70
    giveitem_msg 0x818F675 ITEM_TM26
    setflag 0x298
    msgbox 0x818F695 MSG_KEEPOPEN
    release
    end