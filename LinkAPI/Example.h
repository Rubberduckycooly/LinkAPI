#ifndef OBJ_EXAMPLE_H
#define OBJ_EXAMPLE_H

#include "LinkAPI.h"

typedef struct {
    RSDK_OBJECT
    // Per-Object Variables Go Here
    int exampleStaticVar;
} ObjectExample;

typedef struct {
    RSDK_ENTITY
    // Per-Entity Variables Go Here
    int exampleEditableVar;
    int exampleVar;
} EntityExample;

// Object Struct
extern ObjectExample *Example;

// Standard Entity Events

// Run once per frame, once per entity
void Example_Update(void);
// Run once per frame, once per entity, after all update events but before rendering
void Example_LateUpdate(void);
// Run once per object (before any update events), if [object]->active is ACTIVE_NORMAL or ACTIVE_ALWAYS
void Example_StaticUpdate(void);
// Run once per frame, once per entity, used to draw
void Example_Draw(void);
// Run once per entity when it's creayed
void Example_Create(void *data);
// Run once per object, used to load assets in game
void Example_StageLoad(void);
// Run once per frame, once per entity, used to render sprites in editor (never used in-game)
void Example_EditorDraw(void);
// Run once per object, used to load assets in the editor (never used in-game)
void Example_EditorLoad(void);
// Run once per object, used for editable vars (attributes)
void Example_Serialize(void);

#endif