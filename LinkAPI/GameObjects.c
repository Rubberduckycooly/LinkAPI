#include "LinkAPI.h"

SceneInfo *RSDK_sceneInfo = NULL;
#if RETRO_USE_PLUS
char *RSDK_name   = NULL;
SKUInfo *RSDK_sku = NULL;
#else
EngineInfo *RSDK_info;
#endif
ControllerState *RSDK_controller = NULL;
AnalogState *RSDK_stickL         = NULL;
#if RETRO_USE_PLUS
AnalogState *RSDK_stickR    = NULL;
TriggerState *RSDK_triggerL = NULL;
TriggerState *RSDK_triggerR = NULL;
#endif
TouchMouseData *RSDK_touchMouse = NULL;
#if RETRO_USE_PLUS
UnknownInfo *RSDK_unknown = NULL;
#endif
ScreenInfo *RSDK_screens = NULL;

char textBuffer[0x400];

#if RETRO_USE_PLUS
UserFunctionTable User;
#endif
RSDKFunctionTable RSDK;

Hitbox defaultHitbox;

GameOptions *options;

// This manages RSDKv5/Mania link, so it doesn't need to be edited
void InitLinkAPI(GameInfo *info)
{
#if RETRO_USE_PLUS
    memset(&User, 0, sizeof(UserFunctionTable));
#endif
    memset(&RSDK, 0, sizeof(RSDKFunctionTable));

    if (info->functionPtrs)
        memcpy(&RSDK, info->functionPtrs, sizeof(RSDKFunctionTable));
#if RETRO_USE_PLUS
    if (info->userdataPtrs)
        memcpy(&User, info->userdataPtrs, sizeof(UserFunctionTable));
#endif

#if RETRO_USE_PLUS
    RSDK_name = info->gameName;
    RSDK_sku  = info->currentSKU;
#endif

#if !RETRO_USE_PLUS
    RSDK_info = info->engineInfo;
#endif
    RSDK_sceneInfo  = info->sceneInfo;
    RSDK_controller = info->controller;
    RSDK_stickL     = info->stickL;
#if RETRO_USE_PLUS
    RSDK_stickR   = info->stickR;
    RSDK_triggerL = info->triggerL;
    RSDK_triggerR = info->triggerR;
#endif
    RSDK_touchMouse = info->touchMouse;
#if RETRO_USE_PLUS
    RSDK_unknown = info->unknown;
#endif
    RSDK_screens = info->screenInfo;
    RSDK.InitGameOptions((void **)&options, sizeof(GameOptions));

    defaultHitbox.left   = -10;
    defaultHitbox.top    = -20;
    defaultHitbox.right  = 10;
    defaultHitbox.bottom = 20;
}

// ================
// OBJECTS
// ================
#include "Example.h"

DLLExport void LinkGameLogicDLL(GameInfo *info)
{
    InitLinkAPI(info);

    // Object Adding Example
    RSDK_ADD_OBJECT(Example); //feel free to remove this, its just for an example
    //Add other objects here
}

// Generally, this can be ignored
typedef struct {
    int loaderVersion;
    int gameVersion;
} ModInfo;

// mod loader ver is always 1
// if we're using plus we're on 1.05/1.06, we're on 1.03
DLLExport ModInfo ManiaModInfo = { 1, RETRO_USE_PLUS ? 5 : 3 };