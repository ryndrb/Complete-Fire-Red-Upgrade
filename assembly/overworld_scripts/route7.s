.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

@@@@@@@@@@@@@@@@@@@@@@
@ Route 7 Berry Master | Old Lady
@@@@@@@@@@@@@@@@@@@@@@
EventScript_BerryMaster:
    lock
    faceplayer
    msgbox gText_BerryMasterWelcome MSG_KEEPOPEN
    pokemart EventScript_BerryList
    msgbox gText_BerryMasterComeAgain MSG_KEEPOPEN
    closeonkeypress
    release
    end

.align 1
EventScript_BerryList:
    .hword ITEM_BERRY_JUICE
    .hword ITEM_AGUAV_BERRY
    .hword ITEM_APICOT_BERRY
    .hword ITEM_ASPEAR_BERRY
    .hword ITEM_BABIRI_BERRY
    .hword ITEM_CHARTI_BERRY
    .hword ITEM_CHERI_BERRY
    .hword ITEM_CHESTO_BERRY
    .hword ITEM_CHILAN_BERRY
    .hword ITEM_CHOPLE_BERRY
    .hword ITEM_COBA_BERRY
    .hword ITEM_COLBUR_BERRY
    .hword ITEM_CUSTAP_BERRY
    .hword ITEM_FIGY_BERRY
    .hword ITEM_GANLON_BERRY
    .hword ITEM_GREPA_BERRY
    .hword ITEM_HABAN_BERRY
    .hword ITEM_HONDEW_BERRY
    .hword ITEM_IAPAPA_BERRY
    .hword ITEM_JABOCA_BERRY
    .hword ITEM_KASIB_BERRY
    .hword ITEM_KEBIA_BERRY
    .hword ITEM_KEE_BERRY
    .hword ITEM_KELPSY_BERRY
    .hword ITEM_LANSAT_BERRY
    .hword ITEM_LEPPA_BERRY
    .hword ITEM_LIECHI_BERRY
    .hword ITEM_MAGO_BERRY
    .hword ITEM_MARANGA_BERRY
    .hword ITEM_MICLE_BERRY
    .hword ITEM_OCCA_BERRY
    .hword ITEM_ORAN_BERRY
    .hword ITEM_PASSHO_BERRY
    .hword ITEM_PAYAPA_BERRY
    .hword ITEM_PECHA_BERRY
    .hword ITEM_PERSIM_BERRY
    .hword ITEM_PETAYA_BERRY
    .hword ITEM_POMEG_BERRY
    .hword ITEM_QUALOT_BERRY
    .hword ITEM_RAWST_BERRY
    .hword ITEM_RINDO_BERRY
    .hword ITEM_ROSELI_BERRY
    .hword ITEM_ROWAP_BERRY
    .hword ITEM_SALAC_BERRY
    .hword ITEM_SHUCA_BERRY
    .hword ITEM_SITRUS_BERRY
    .hword ITEM_STARF_BERRY
    .hword ITEM_TAMATO_BERRY
    .hword ITEM_TANGA_BERRY
    .hword ITEM_WACAN_BERRY
    .hword ITEM_WIKI_BERRY
    .hword ITEM_YACHE_BERRY
    .hword 0x0
