#include "Example.h"

ObjectExample *Example = NULL;

// Run once per frame, once per entity
void Example_Update()
{
    RSDK_THIS(EntityExample); // gets the current entity, under the name "entity"
    entity->exampleVar = Example->exampleStaticVar;

    //Example of how to get object struct pointers for other objects
    //ObjectExample *objPtr = GetObject("Example"); //get our object called "Example"
    //if (objPtr) { //make sure it existed before we use it
    //    objPtr->exampleStaticVar *= 21;
    //}
}
// Run once per frame, once per entity, after all update events but before rendering
void Example_LateUpdate()
{
    RSDK_THIS(EntityExample); // gets the current entity, under the name "entity"
    // idk, some code you'd wanna do after update()
}
// Run once per object (before any update events), if [object]->active is ACTIVE_NORMAL or ACTIVE_ALWAYS
void Example_StaticUpdate() { Example->exampleStaticVar++; }
// Run once per frame, once per entity, used to draw
void Example_Draw()
{
    RSDK_THIS(EntityExample); // gets the current entity, under the name "entity"

    // Something like
    // RSDK.DrawSprite(&entity->data, NULL, true);
    // or
    // RSDK.DrawRect(0, 0, 25, 25, 0xFF00FF, 0xFF, INK_NONE, true);
}
// Run once per entity when it's created
void Example_Create(void *data)
{
    RSDK_THIS(EntityExample); // gets the current entity, under the name "entity"

    entity->drawOrder = 3;          // a common draw layer for objects (0-15 are valid, any others wont be drawn)
    entity->visible = true;         // this has to be set to true otherwise `Draw()` won't be called
    entity->active = ACTIVE_BOUNDS; // set active flag to be active while on screen (default is ACTIVE_NEVER)

    entity->updateRange.x = 128 << 0x10; //set the amount of pixels offscreen the entity can be on the x axis before its considered "inactive"
    entity->updateRange.y = 128 << 0x10; //set the amount of pixels offscreen the entity can be on the y axis before its considered "inactive"

    RSDK.PrintLog(SEVERITY_NONE, "Example Create(%p) -> slot %d\n", data, RSDK_sceneInfo->entitySlot);
}
// Run once per object, used to load assets in game
void Example_StageLoad() { RSDK.PrintLog(SEVERITY_NONE, "Example StageLoad()\n"); }
// Run once per frame, once per entity, used to render sprites in editor (never used in-game)
void Example_EditorDraw() { RSDK.PrintLog(SEVERITY_NONE, "Example EditorDraw()\n"); }
// Run once per object, used to load assets in the editor (never used in-game)
void Example_EditorLoad() { RSDK.PrintLog(SEVERITY_NONE, "Example EditorLoad()\n"); }
// Run once per object, used for editable vars (attributes)
void Example_Serialize()
{
    // Object, what type the var is, and the name of the var
    RSDK_EDITABLE_VAR(Example, VAR_INT32, exampleEditableVar);
}