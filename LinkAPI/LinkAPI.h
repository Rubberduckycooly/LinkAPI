#ifndef LINKAPI_H
#define LINKAPI_H

// set to this 1 to use 1.05/plus/rev 2 (default), set it to 0 to use 1.03/preplus/rev 1
// ignore this if you dont know what you're doing
#define RETRO_USE_PLUS (1)

#include "GameLink.h"

#ifdef _MSC_VER
#define DLLExport __declspec(dllexport)
#else
#define DLLExport
#endif

#define RSDK_EDITABLE_VAR(object, type, var) RSDK.SetEditableVar(type, #var, object->objectID, offsetof(Entity##object, var))

#define RSDK_ADD_OBJECT(object)                                                                                                                      \
    RSDK.CreateObject((Object **)&object, #object, sizeof(Entity##object), sizeof(Object##object), ##object##_Update, ##object##_LateUpdate,         \
                      ##object##_StaticUpdate, ##object##_Draw, ##object##_Create, ##object##_StageLoad, ##object##_EditorDraw,                      \
                      ##object##_EditorLoad, ##object##_Serialize)
#if RETRO_USE_PLUS
#define RSDK_ADD_OBJECT_CONTAINER(object) RSDK.CreateObjectContainer((Object **)&object, #object, sizeof(Object##object))
#endif

#define RSDK_THIS(EntityType) EntityType *entity = (EntityType *)RSDK_sceneInfo->entity

#endif // !LINKAPI_H