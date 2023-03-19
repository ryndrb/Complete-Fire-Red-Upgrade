#include "../include/m4a.h"
#include "../include/overworld.h"
#include "../include/script.h"
#include "../include/sound.h"

#include "../include/new/dns.h"

#include "../include/constants/maps.h"
#include "../include/constants/songs.h"

u16 GetLocationMusicNew(struct WarpData* warp)
{
    bool8 day = IsDayTime();        // 4am - 8pm
    bool8 night = IsNightTime();    // 8pm - 4am
    u16 music = Overworld_GetMapHeaderByGroupAndId(warp->mapGroup, warp->mapNum)->music;

    switch (music)
    {
        case BGM_PALLET_TOWN:
            if(day)
                music = BGM_RSE_LITTLEROOT_TOWN;
            if(night)
                music = BGM_RSE_LITTLEROOT_TOWN_ALT;
            break;
        case BGM_ROUTE_1:
            if(day || night)
                music = BGM_RSE_ROUTE_1;
            break;
        case BGM_VIRIDIAN_CITY:
            if(day || night){
                // PEWTER CITY
                if (3 == warp->mapGroup
                &&  2 == warp->mapNum){
				    music = BGM_CINNABAR_ISLAND;
                }
                // SAFFRON CITY
                if (3 == warp->mapGroup
                &&  10 == warp->mapNum){
				    music = BGM_CELADON_CITY;
                }
            }
            break;
        case BGM_CERULEAN_CITY:
            if(day || night){
                // FUSCHIA CITY
                if(3 == warp->mapGroup
                && 7 == warp->mapNum){
                    music = BGM_RSE_LILYCOVE_CITY;
                }else{
                    music = BGM_RSE_MAUVILLE_CITY;
                }
            }
            break;
        case BGM_VERMILION_CITY:
            if(day || night)
                music = BGM_RSE_MAUVILLE_CITY;
            break;
        case BGM_CELADON_CITY:
            if(day || night)
                music = BGM_RSE_SLATEPORT_CITY;
            break;
        case BGM_CINNABAR_ISLAND:
            if(day || night)
                music = BGM_RSE_FALLARBOR_TOWN;
            break;


        case BGM_POKEMON_CENTER:
            if(day)
                music = BGM_RSE_POKECENTER;
            if(night)
                music = BGM_RSE_THEME_UNUSED_1;
            if((5 == warp->mapGroup && 3 == warp->mapNum)
            || (6 == warp->mapGroup && 3 == warp->mapNum)
            || (7 == warp->mapGroup && 7 == warp->mapNum)
            || (8 == warp->mapGroup && 5 == warp->mapNum)
            || (9 == warp->mapGroup && 5 == warp->mapNum)
            || (11 == warp->mapGroup && 1 == warp->mapNum)
            || (12 == warp->mapGroup && 7 == warp->mapNum)
            || (14 == warp->mapGroup && 5 == warp->mapNum)){
                music = BGM_RSE_MART;
            }
            break;
        case BGM_EVIL_LURKS:
            if(day || night)
                music = BGM_RSE_AQUA_MAGMA_BASE;
            break;
        case BGM_GAME_CORNER:
            if(day || night)
                music = BGM_RSE_GAME_CORNER;
            break;
        case BGM_VICTORY_ROAD:
            if(day || night){
                // ROUTE 23
                if(3 == warp->mapGroup
                && 42 == warp->mapNum){
                    music = BGM_RSE_ABANDONED_SHIP;
                }
            }
            break;
        case BGM_VIRIDIAN_FOREST:
            if(day || night){
                // VIRIDIAN FOGGY LAKE
                if(43 == warp->mapGroup
                && 0 == warp->mapNum){
                    music = BGM_RSE_PETALBURG_WOODS;
                }
            }
            break;
    }

    return music;
}