#include "../include/bg.h"
#include "../include/event_data.h"
#include "../include/global.h"
#include "../include/menu.h"
#include "../include/menu_helpers.h"
#include "../include/new_menu_helpers.h"
#include "../include/script.h"
#include "../include/string_util.h"
#include "../include/text.h"
#include "../include/text_window.h"
#include "../include/window.h"

#include "../include/gba/syscall.h"

void DrawNameBox(void);
void RemoveNameBox(void);

extern u8 sTimeWindowId;

// Text Colors
static const u8 sTextColor[3]    = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_GREEN, TEXT_COLOR_LIGHT_GREY};

void DrawNameBox(void) {
    u8 name[34]; // max??, like char count in scripts
    StringExpandPlaceholders(name, gLoadPointer);

    u8 width = GetStringWidth(2, name, 0);
    u8 xOff = width;
    u8 rem = width % 8;
    if(rem < 3)
        width = width - rem;
    else
        width = width + 8 - rem;
    width = width / 8 + 1;
    xOff = (width * 8 - xOff) / 2;

    struct WindowTemplate Left = SetWindowTemplateFields(0, 1, 11, width, 2, 15, 0x008);
    sTimeWindowId = AddWindow(&Left);
    PutWindowTilemap(sTimeWindowId);
    FillWindowPixelBuffer(sTimeWindowId, PIXEL_FILL(1));
    TextWindow_SetStdFrame0_WithPal(sTimeWindowId, 0x21D, 0xD0);
    DrawStdFrameWithCustomTileAndPalette(sTimeWindowId, FALSE, 0x21D, 0xD);

    AddTextPrinterParameterized3(sTimeWindowId, 2, xOff, 0, sTextColor, 0xFF, name);
	CopyWindowToVram(sTimeWindowId, COPYWIN_GFX);
}

void RemoveNameBox(void)
{
	if (sTimeWindowId != 0xFF){
		ClearStdWindowAndFrame(sTimeWindowId, TRUE);
		CopyWindowToVram(sTimeWindowId, COPYWIN_GFX);
		RemoveWindow(sTimeWindowId);
	}
}