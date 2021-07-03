#include "LinkAPI.h"

// ================
// DATA
// ================
SceneInfo *RSDK_sceneInfo = NULL;
EngineInfo *RSDK_info;
#if RETRO_USE_PLUS
SKUInfo *RSDK_sku = NULL;
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

RSDKFunctionTable RSDK;
#if RETRO_USE_PLUS
UserFunctionTable User;
#endif

Hitbox defaultHitbox;

Object *(*GetObject)(const char *name) = NULL;

GlobalVariables *globals = NULL;

int RSDK_GameVersion = 0;

// ================
// INTERNALS
// ================
void LinkGameObjects(void);

// This manages RSDKv5/Mania link, so it doesn't need to be edited
void InitLinkAPI(GameInfo *info, void (*initAPI)(void **globals, int size, void **getObject, int *gameVersion))
{
    globals = NULL;
    if (initAPI)
        initAPI((void **)&globals, sizeof(GlobalVariables), (void **)&GetObject, &RSDK_GameVersion);

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

    RSDK_info = info->engineInfo;
#if RETRO_USE_PLUS
    RSDK_sku = info->currentSKU;
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

    defaultHitbox.left   = -10;
    defaultHitbox.top    = -20;
    defaultHitbox.right  = 10;
    defaultHitbox.bottom = 20;
}

DLLExport void LinkGameLogicDLL(GameInfo *info, void (*initAPI)(void **globals, int size, void **getObject, int *gameVersion))
{
    InitLinkAPI(info, initAPI); // init mania and linkAPI internals
    LinkGameObjects();          // init custom objects
}

#include <stdio.h>

// ================
// OBJECTS
// ================
#include "Example.h"

void LinkGameObjects(void)
{
    // Object Adding Example
    RSDK_ADD_OBJECT(Example); // feel free to remove this, its just for an example
    // Add other objects here, just like shown above
}

// ================
// MOD INFO STUFF
// ================

// Generally, this can be ignored
typedef struct {
    int loaderVersion;
    int gameVersion;
} ModInfo;

// mod loader ver is always 1
// if we're using plus we're on 1.05/1.06, we're on 1.03, if we're using EGS/Origin we're on 1.07
DLLExport ModInfo ManiaModInfo = { 1, RETRO_USE_EGS ? 7 : (RETRO_USE_PLUS ? 5 : 3) };