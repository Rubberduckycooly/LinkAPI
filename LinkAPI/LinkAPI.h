#ifndef LINKAPI_H
#define LINKAPI_H

// set to this 1 to use 1.05/plus/rev 2 (default), set it to 0 to use 1.03/preplus/rev 1
// ignore this if you dont know what you're doing
#define RETRO_USE_PLUS (1)

// set to this 1 to use 1.07/EGS/origin, set it to 0 to use 1.06 or below (default)
// ignore this if you dont know what you're doing
#define RETRO_USE_EGS  (0)

#define true 1
#define false 0

#include "GameLink.h"

#ifdef _MSC_VER
#define DLLExport __declspec(dllexport)
#else
#define DLLExport
#endif

#define RSDK_EDITABLE_VAR(object, type, var) RSDK.SetEditableVar(type, #var, (byte)object->objectID, offsetof(Entity##object, var))

#define RSDK_ADD_OBJECT(object)                                                                                                                      \
    RSDK.RegisterObject((Object **)&object, #object, sizeof(Entity##object), sizeof(Object##object), ##object##_Update, ##object##_LateUpdate,         \
                      ##object##_StaticUpdate, ##object##_Draw, ##object##_Create, ##object##_StageLoad, ##object##_EditorDraw,                      \
                      ##object##_EditorLoad, ##object##_Serialize)
#if RETRO_USE_PLUS
#define RSDK_ADD_OBJECT_CONTAINER(object) RSDK.RegisterObjectContainer((Object **)&object, #object, sizeof(Object##object))
#endif


#define RSDK_THIS(type)             Entity##type *entity = (Entity##type *)RSDK_sceneInfo->entity
#define RSDK_GET_ENTITY(slot, type) ((Entity##type *)RSDK.GetEntityByID(slot))

//#define RSDK_REGISTER_OBJECT(object) 

#define foreach_active(type, entityOut)                                                                                                              \
    Entity##type *entityOut = NULL;                                                                                                                  \
    while (RSDK.GetActiveEntities(type->objectID, (Entity **)&entityOut))
#define foreach_all(type, entityOut)                                                                                                                 \
    Entity##type *entityOut = NULL;                                                                                                                  \
    while (RSDK.GetEntities(type->objectID, (Entity **)&entityOut))

// Macros and other handy things

#define maxVal(a, b) (a >= b ? a : b)
#define minVal(a, b) (a <= b ? a : b)

#define intToVoid(x) (void *)(size_t)(x)
#define voidToInt(x) (int)(size_t)(x)

#define unused(x) (void)x

#define StateMachine(name) void (*name)(void)
#define StateMachine_Run(func)                                                                                                                       \
    if (func) {                                                                                                                                      \
        func();                                                                                                                                      \
    }
#define StateMachine_None NULL

#endif // !LINKAPI_H