#ifndef GAMELINK_H
#define GAMELINK_H

// ================
// STANDARD LIBS
// ================
#include <stddef.h>
#include <stdio.h>
#include <string.h>

// ================
// STANDARD TYPES
// ================
typedef signed char sbyte;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int bool32;

typedef uint colour;
typedef uint color;

// dont change these, its just easier to read this way

#define SCREEN_XMAX    (1280)
#define SCREEN_YSIZE   (240)
#define SCREEN_YCENTER (SCREEN_YSIZE / 2)

#define LAYER_COUNT     (8)
#define DRAWLAYER_COUNT (16)

#if RETRO_USE_PLUS
#define PLAYER_MAX (4)
#define SCREEN_MAX (4)
#else
#define PLAYER_MAX (2)
#define SCREEN_MAX (2)
#endif

#define CAMERA_MAX (4)

// 0x800 scene objects, 0x40 reserved ones, and 0x100 spare slots for creation
#define RESERVE_ENTITY_COUNT (0x40)
#define TEMPENTITY_COUNT     (0x100)
#define SCENEENTITY_COUNT    (0x800)
#define ENTITY_COUNT         (RESERVE_ENTITY_COUNT + SCENEENTITY_COUNT + TEMPENTITY_COUNT)
#define TEMPENTITY_START     (ENTITY_COUNT - TEMPENTITY_COUNT)

#define TYPE_COUNT      (0x100)
#define TYPEGROUP_COUNT (0x104)

#define CHANNEL_COUNT (0x10)

// =======================================
// Game Structs
// =======================================
typedef struct {
    int x;
    int y;
} Vector2;

typedef struct {
    Vector2 position;
    Vector2 scale;
    Vector2 velocity;
    Vector2 updateRange;
    int angle;
    int alpha;
    int rotation;
    int groundVel;
    int depth;
    ushort group;
    ushort objectID;
    bool32 isPermanent;
    bool32 tileCollisions;
    bool32 interaction;
    bool32 onGround;
    byte active;
#if RETRO_USE_PLUS
    byte filter;
#endif
    byte direction;
    byte drawOrder;
    byte collisionLayers;
    byte collisionPlane;
    byte collisionMode;
    byte drawFX;
    byte inkEffect;
    byte visible;
    byte activeScreens;
} Entity;

typedef struct {
    ushort objectID;
    byte active;
} Object;

#define RSDK_OBJECT                                                                                                                                  \
    ushort objectID;                                                                                                                                 \
    byte active;

#if RETRO_USE_PLUS
#define RSDK_ENTITY_FILTER byte filter;
#else
#define RSDK_ENTITY_FILTER
#endif

#define RSDK_ENTITY                                                                                                                                  \
    Vector2 position;                                                                                                                                \
    Vector2 scale;                                                                                                                                   \
    Vector2 velocity;                                                                                                                                \
    Vector2 updateRange;                                                                                                                             \
    int angle;                                                                                                                                       \
    int alpha;                                                                                                                                       \
    int rotation;                                                                                                                                    \
    int groundVel;                                                                                                                                   \
    int depth;                                                                                                                                       \
    ushort group;                                                                                                                                    \
    ushort objectID;                                                                                                                                 \
    bool32 inBounds;                                                                                                                                 \
    bool32 isPermanent;                                                                                                                              \
    bool32 tileCollisions;                                                                                                                           \
    bool32 interaction;                                                                                                                              \
    bool32 onGround;                                                                                                                                 \
    byte active;                                                                                                                                     \
    RSDK_ENTITY_FILTER                                                                                                                               \
    byte direction;                                                                                                                                  \
    byte drawOrder;                                                                                                                                  \
    byte collisionLayers;                                                                                                                            \
    byte collisionPlane;                                                                                                                             \
    byte collisionMode;                                                                                                                              \
    byte drawFX;                                                                                                                                     \
    byte inkEffect;                                                                                                                                  \
    byte visible;                                                                                                                                    \
    byte activeScreens;

#define ENTITY_SIZE (sizeof(Entity) + 0x400)

#if RETRO_USE_PLUS
typedef struct {
    int platform;
    int language;
    int region;
} SKUInfo;

typedef struct {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
} UnknownInfo;
#endif

typedef struct {
    char engineInfo[0x40];
    char gameSubname[0x100];
    char version[0x10];
#if !RETRO_USE_PLUS
    byte platform;
    byte language;
    byte region;
#endif
} EngineInfo;

typedef struct {
    Entity *entity;
    int listData;
    void *listCategory;
    int timeCounter;
    int currentDrawGroup;
    int currentScreenID;
    ushort listPos;
    ushort entitySlot;
    ushort createSlot;
    ushort classCount;
    bool32 inEditor;
    bool32 effectGizmo;
    bool32 debugMode;
    bool32 useGlobalScripts;
    bool32 timeEnabled;
    byte activeCategory;
    byte categoryCount;
    byte state;
#if RETRO_USE_PLUS
    byte filter;
#endif
    byte milliseconds;
    byte seconds;
    byte minutes;
} SceneInfo;

typedef struct {
    bool32 down;
    bool32 press;
    int keyMap;
} InputState;

typedef struct {
    InputState keyUp;
    InputState keyDown;
    InputState keyLeft;
    InputState keyRight;
    InputState keyA;
    InputState keyB;
    InputState keyC;
    InputState keyX;
    InputState keyY;
    InputState keyZ;
    InputState keyStart;
    InputState keySelect;
} ControllerState;

typedef struct {
    InputState keyUp;
    InputState keyDown;
    InputState keyLeft;
    InputState keyRight;
    InputState keyStick;
    float deadzone;
    float hDelta;
    float vDelta;
} AnalogState;

#if RETRO_USE_PLUS
typedef struct {
    InputState key1;
    InputState key2;
    float unknown1;
    float unknown2;
} TriggerState;
#endif

typedef struct {
    float x[0x10];
    float y[0x10];
    bool32 down[0x10];
    byte count;
} TouchMouseData;

typedef struct {
    ushort frameBuffer[SCREEN_XMAX * SCREEN_YSIZE];
    Vector2 position;
    int width;
    int height;
    int centerX;
    int centerY;
    int pitch;
    int clipBound_X1;
    int clipBound_Y1;
    int clipBound_X2;
    int clipBound_Y2;
    int waterDrawPos;
} ScreenInfo;

typedef struct {
    void *functionPtrs;
#if RETRO_USE_PLUS
    void *userdataPtrs;
    SKUInfo *currentSKU;
#endif
    EngineInfo *engineInfo;
    SceneInfo *sceneInfo;
    ControllerState *controller;
    AnalogState *stickL;
#if RETRO_USE_PLUS
    AnalogState *stickR;
    TriggerState *triggerL;
    TriggerState *triggerR;
#endif
    TouchMouseData *touchMouse;
#if RETRO_USE_PLUS
    UnknownInfo *unknown;
#endif
    ScreenInfo *screenInfo;
} GameInfo;

typedef struct {
    int values[4][4];
} Matrix;

typedef struct {
    ushort *text;
    short textLength;
    short length;
} TextInfo;

typedef struct {
    short left;
    short top;
    short right;
    short bottom;
} Hitbox;

typedef struct {
    ushort sprX;
    ushort sprY;
    ushort width;
    ushort height;
    short pivotX;
    short pivotY;
    ushort delay;
    short id;
    byte sheetID;
    byte hitboxCnt;
    Hitbox hitboxes[8];
} SpriteFrame;

typedef struct {
    SpriteFrame *framePtrs;
    int frameID;
    short animationID;
    short prevAnimationID;
    short animationSpeed;
    short animationTimer;
    short frameDelay;
    short frameCount;
    byte loopIndex;
    byte rotationFlag;
} Animator;

typedef struct {
    int unknown;
    int parallaxFactor;
    int scrollSpeed;
    int scrollPos;
    bool32 deform;
} ScrollInfo;

typedef struct {
    Vector2 position;
    Vector2 deform;
} ScanlineInfo;

typedef struct {
    byte behaviour;
    byte drawLayer[4];
    byte widthShift;
    byte heightShift;
    ushort width;
    ushort height;
    Vector2 position;
    int parallaxFactor;
    int scrollSpeed;
    int scrollPos;
    int deformationOffset;
    int deformationOffsetW;
    int deformationData[0x400];
    int deformationDataW[0x400];
    void (*scanlineCallback)(ScanlineInfo *);
    ushort scrollInfoCount;
    ScrollInfo scrollInfo[0x100];
    uint name[4];
    ushort *layout;
    byte *lineScroll;
} TileLayer;

typedef struct {
    byte statID;
    const char *name;
    void *data[64];
} StatInfo;

typedef enum {
    PLATFORM_PC     = 0,
    PLATFORM_PS4    = 1,
    PLATFORM_XB1    = 2,
    PLATFORM_SWITCH = 3,
    PLATFORM_DEV    = 0xFF,
} GamePlatforms;

typedef enum {
    SCOPE_NONE,
    SCOPE_GLOBAL,
    SCOPE_STAGE,
} Scopes;

typedef enum {
    INK_NONE,
    INK_BLEND,
    INK_ALPHA,
    INK_ADD,
    INK_SUB,
    INK_LOOKUP,
    INK_MASKED,
    INK_UNMASKED,
} InkEffects;

typedef enum { FX_NONE = 0, FX_FLIP = 1, FX_ROTATE = 2, FX_SCALE = 4 } DrawFX;

typedef enum { FLIP_NONE, FLIP_X, FLIP_Y, FLIP_XY } FlipFlags;

typedef enum { TYPE_BLANK } DefaultObjTypes;

typedef enum {
    CONT_UNASSIGNED = -2,
    CONT_AUTOASSIGN = -1,
    CONT_ANY        = 0,
    CONT_P1         = 1,
    CONT_P2         = 2,
    CONT_P3         = 3,
    CONT_P4         = 4,
} ControllerIDs;

typedef enum {
    ALIGN_LEFT,
    ALIGN_RIGHT,
    ALIGN_CENTER,
} Alignments;

typedef enum {
    SEVERITY_NONE,
    SEVERITY_WARN,
    SEVERITY_ERROR,
    SEVERITY_FATAL,
} SeverityModes;

typedef enum {
    VAR_UINT8,
    VAR_UINT16,
    VAR_UINT32,
    VAR_INT8,
    VAR_INT16,
    VAR_INT32,
    VAR_ENUM,
    VAR_BOOL,
    VAR_STRING,
    VAR_VECTOR2,
    VAR_UNKNOWN,
    VAR_COLOUR,
} VarTypes;

typedef enum {
    ACTIVE_NEVER,
    ACTIVE_ALWAYS,
    ACTIVE_NORMAL,
    ACTIVE_PAUSED,
    ACTIVE_BOUNDS,
    ACTIVE_XBOUNDS,
    ACTIVE_YBOUNDS,
    ACTIVE_RBOUNDS,
    ACTIVE_NEVER2 = 0xFF,
} ActiveFlags;

typedef enum {
    LAYER_HSCROLL,
    LAYER_VSCROLL,
    LAYER_ROTOZOOM,
    LAYER_BASIC,
} LayerTypes;

typedef enum {
    CMODE_FLOOR,
    CMODE_LWALL,
    CMODE_ROOF,
    CMODE_RWALL,
} CModes;

typedef enum {
    S3D_FLATCLR_WIREFRAME               = 0x0,
    S3D_FLATCLR                         = 0x1,
    S3D_UNKNOWN_2                       = 0x2,
    S3D_UNKNOWN_3                       = 0x3,
    S3D_FLATCLR_SHADED_WIREFRAME        = 0x4,
    S3D_FLATCLR_SHADED                  = 0x5,
    S3D_FLATCLR_SHADED_BLENDED          = 0x6,
    S3D_FLATCLR_SCREEN_WIREFRAME        = 0x7,
    S3D_FLATCLR_SCREEN                  = 0x8,
    S3D_FLATCLR_SHADED_SCREEN_WIREFRAME = 0x9,
    S3D_FLATCLR_SHADED_SCREEN           = 0xA,
    S3D_FLATCLR_SHADED_BLENDED_SCREEN   = 0xB,
} Scene3DDrawTypes;

typedef enum {
    SETTINGS_WINDOWED,
    SETTINGS_BORDERED,
    SETTINGS_EXCLUSIVEFS,
    SETTINGS_VSYNC,
    SETTINGS_TRIPLEBUFFERED,
    SETTINGS_WINDOW_WIDTH,
    SETTINGS_WINDOW_HEIGHT,
    SETTINGS_FSWIDTH,
    SETTINGS_FSHEIGHT,
    SETTINGS_REFRESHRATE,
    SETTINGS_SHADERSUPPORT,
    SETTINGS_SHADERID,
    SETTINGS_SCREENCOUNT,
#if RETRO_USE_PLUS
    SETTINGS_DIMTIMER,
#endif
    SETTINGS_STREAMSENABLED,
    SETTINGS_STREAM_VOL,
    SETTINGS_SFX_VOL,
    SETTINGS_LANGUAGE,
    SETTINGS_STORE,
    SETTINGS_RELOAD,
    SETTINGS_CHANGED,
    SETTINGS_WRITE,
} SettingsValues;

typedef enum {
    GROUP_ALL     = 0,
    GROUP_CUSTOM1 = TYPE_COUNT,
    GROUP_CUSTOM2,
    GROUP_CUSTOM3,
    GROUP_CUSTOM4,
} TypeGroups;

typedef enum { STATUS_CONTINUE = 100, STATUS_OK = 200, STATUS_FORBIDDEN = 403, STATUS_NOTFOUND = 404, STATUS_ERROR = 500 } StatusCodes;

typedef enum {
    REGION_US,
    REGION_JP,
    REGION_EU,
} GameRegions;

typedef enum {
    LANGUAGE_EN,
    LANGUAGE_FR,
    LANGUAGE_IT,
    LANGUAGE_GE,
    LANGUAGE_SP,
    LANGUAGE_JP,
    LANGUAGE_KO,
    LANGUAGE_SC,
    LANGUAGE_TC,
} GameLanguages;

typedef enum {
    ENGINESTATE_LOAD             = 0,
    ENGINESTATE_REGULAR          = 1,
    ENGINESTATE_PAUSED           = 2,
    ENGINESTATE_FROZEN           = 3,
    ENGINESTATE_LOAD_STEPOVER    = 4,
    ENGINESTATE_REGULAR_STEPOVER = 5,
    ENGINESTATE_PAUSED_STEPOVER  = 6,
    ENGINESTATE_FROZEN_STEPOVER  = 7,
    ENGINESTATE_DEVMENU          = 8,
    ENGINESTATE_VIDEOPLAYBACK    = 9,
    ENGINESTATE_SHOWPNG          = 0x0A,
#if RETRO_USE_PLUS
    ENGINESTATE_ERRORMSG       = 0x0B,
    ENGINESTATE_ERRORMSG_FATAL = 0x0C,
#endif
    ENGINESTATE_NULL = 0x0D,
} EngineStates;

// =======================================
// RSDK Function Tables
// =======================================

// Userdata Table
typedef struct {
    int (*GetUserLanguage)(void);
    bool32 (*GetConfirmButtonFlip)(void);
    void (*ExitGame)(void);
    void (*LaunchManual)(void);
    void (*Unknown4)(byte inputID);
    bool32 (*CheckDLC)(int dlc);
    void (*ShowExtensionOverlay)(byte overlay);
    void (*UnlockAchievement)(const char *achName);
    void (*GetAchievementStatus)(void);
    void (*SetAchievementStatus)(int a1);
    void (*LeaderboardsUnknown4)(void);
    void (*FetchLeaderboard)(int a1, int a2);
    void (*TrackScore)(int a1, int a2, int a3);
    void (*GetLeaderboardsUnknown)(void);
    void (*LeaderboardEntryCount)(void);
    int (*GetLeaderboardUnknown2)(void);
    void (*Unknown12)(int a2, uint a3, int a4);
    void (*LeaderboardsUnknown8)(void);
    void (*ReadLeaderboardEntry)(uint a1);
    void (*SetRichPresence)(int, TextInfo *text);
    void (*TryTrackStat)(StatInfo *stat);
    int (*GetStatsStatus)(void);
    void (*SetStatsStatus)(int a1);
    void (*UserStorageUnknown8)(void);
    void (*TryAuth)(void);
    int (*GetUserAuthStatus)(void);
    void (*GetUsername)(TextInfo *text);
    void (*TryInitStorage)(void);
    int (*UserStorageStatusUnknown1)(void);
    int (*UserStorageStatusUnknown2)(void);
    void (*ClearUserStorageStatus)(void);
    void (*SetUserStorageStatus)(void);
    int (*UserStorageStatusUnknown3)(void);
    int (*UserStorageStatusUnknown4)(void);
    int (*UserStorageStatusUnknown5)(void);
    void (*SetUserStorageNoSave)(bool32 state);
    bool32 (*GetUserStorageNoSave)(void);
    void (*LoadUserFile)(const char *name, int *data, int size, void (*callback)(int status));                  // load user file from game dir
    void (*SaveUserFile)(const char *name, int *data, int size, void (*callback)(int status), bool32 compress); // save user file to game dir
    void (*DeleteUserFile)(const char *filename, void (*callback)(int status));                                 // delete user file from game dir
    ushort (*InitUserDB)(const char *name, ...);
    ushort (*LoadUserDB)(const char *filename, int (*callback)(int status));
    void (*SaveUserDB)(ushort tableID, int (*callback)(int status));
    void (*ClearUserDB)(ushort tableID);
    void (*ClearAllUserDBs)(void);
    void (*Unknown31)(ushort tableID);
    int (*GetUserDBStatus)(ushort tableID);
    void (*Unknown33)(ushort tableID, int a2, const char *name, void *value);
    void (*Unknown34)(ushort tableID, int a2, const char *name, void *value);
    int (*GetUserDBUnknownCount)(ushort tableID);
    int (*GetUserDBUnknown)(ushort tableID, ushort entryID);
    int (*AddUserDBEntry)(ushort tableID);
    void (*SetUserDBValue)(ushort tableID, int a2, int a3, const char *name, void *value);
    void (*Unknown39)(ushort tableID, int a2, int a3, const char *name, void *value);
    uint (*GetUserDBEntryUUID)(ushort tableID, ushort entryID);
    void (*GetUserDBByID)(ushort tableID, uint uuid);
    void (*GetUserDBCreationTime)(ushort tableID, ushort entry, char *buf, uint sizeInBytes, const char *format);
    void (*RemoveDBEntry)(ushort tableID, ushort entry);
    void (*RemoveAllDBEntries)(ushort tableID);
    // count: 59
} UserFunctionTable;

// Function Table
typedef struct {
    void (*InitGlobalVariables)(void **globals, int size);
    void (*RegisterObject)(Object **structPtr, const char *name, uint entitySize, uint objectSize, void (*update)(void), void (*lateUpdate)(void),
                           void (*staticUpdate)(void), void (*draw)(void), void (*create)(void *), void (*stageLoad)(void), void (*editorDraw)(void),
                           void (*editorLoad)(void), void (*serialize)(void));
#if RETRO_USE_PLUS
    void (*RegisterObjectContainer)(void **structPtr, const char *name, uint objectSize);
#endif
    bool32 (*GetActiveEntities)(ushort group, Entity **entity);
    bool32 (*GetEntities)(ushort type, Entity **entity);
    void (*BreakForeachLoop)(void);
    void (*SetEditableVar)(byte type, const char *name, byte object, int storeOffset);
    void *(*GetEntityByID)(ushort objectID);
    int (*GetEntityID)(void *entityPtr);
    int (*GetEntityCount)(ushort type, bool32 isActive);
    int (*GetDrawListRef)(byte layerID, ushort entityID);
    void *(*GetDrawListRefPtr)(byte layerID, ushort entityID);
    int (*ResetEntityPtr)(void *entity, ushort type, void *data);
    int (*ResetEntitySlot)(ushort slotID, ushort type, void *data);
    Entity *(*CreateEntity)(ushort type, void *data, int x, int y);
    void (*CopyEntity)(void *destEntity, void *srcEntity, bool32 clearSrcEntity);
    bool32 (*CheckOnScreen)(void *entity, Vector2 *range);
    bool32 (*CheckPosOnScreen)(Vector2 *pos, Vector2 *range);
    void (*AddDrawListRef)(byte layer, ushort entityID);
    void (*SwapDrawListEntries)(byte layer, ushort entryStart, ushort entryEnd, ushort count);
    void (*SetDrawLayerProperties)(byte layer, bool32 sorted, void (*callback)(void));
    void (*LoadScene)(const char *categoryName, const char *sceneName);
    void (*SetGameMode)(byte mode);
#if RETRO_USE_PLUS
    void (*SetHardResetFlag)(bool32 set);
#endif
    bool32 (*CheckValidScene)(void);
    int (*CheckStageFolder)(const char *folderName);
    int (*InitSceneLoad)(void);
    int (*GetObjectIDByName)(const char *name);
    void (*ClearCameras)(void);
    void (*AddCamera)(Vector2 *pos, int offsetX, int offsetY, bool32 worldRelative);
#if !RETRO_USE_PLUS
    void *(*GetFuncPtr)(const char *funcName);
#endif
    int (*GetSettingsValue)(int id);
    void (*SetSettingsValue)(int id, int val);
    void (*UpdateWindow)(void);
    int (*Sin1024)(int angle);
    int (*Cos1024)(int angle);
    int (*Tan1024)(int angle);
    int (*ASin1024)(int angle);
    int (*ACos1024)(int angle);
    int (*Sin512)(int angle);
    int (*Cos512)(int angle);
    int (*Tan512)(int angle);
    int (*ASin512)(int angle);
    int (*ACos512)(int angle);
    int (*Sin256)(int angle);
    int (*Cos256)(int angle);
    int (*Tan256)(int angle);
    int (*ASin256)(int angle);
    int (*ACos256)(int angle);
    int (*Rand)(int min, int max);
    int (*Random)(int min, int max, int *randKey);
    void (*SetRandKey)(int key);
    byte (*ATan2)(int x, int y);
    void (*SetIdentityMatrix)(Matrix *matrix);
    void (*MatrixMultiply)(Matrix *dest, Matrix *matrixA, Matrix *matrixB);
    void (*MatrixTranslateXYZ)(Matrix *matrix, int x, int y, int z, bool32 setIdentity);
    void (*MatrixScaleXYZ)(Matrix *matrix, int scaleX, int scaleY, int scaleZ);
    void (*MatrixRotateX)(Matrix *matrix, int angle);
    void (*MatrixRotateY)(Matrix *matrix, int angle);
    void (*MatrixRotateZ)(Matrix *matrix, int angle);
    void (*MatrixRotateXYZ)(Matrix *matrix, int angleX, int angleY, int angleZ);
    void (*MatrixInverse)(Matrix *dest, Matrix *matrix);
    void (*MatrixCopy)(Matrix *matDest, Matrix *matSrc);
    void (*SetText)(TextInfo *textInfo, const char *text, uint size);
    void (*CopyString)(TextInfo *dst, TextInfo *src);
    void (*PrependString)(TextInfo *info, const char *str);
    void (*AppendString)(TextInfo *info, const char *str);
    void (*Unknown67)(TextInfo *, TextInfo *);
    void (*LoadStrings)(TextInfo *dst, const char *path, int);
    void (*SplitStringList)(TextInfo *list, TextInfo *strings, int start, int end);
    void (*GetCString)(char *text, TextInfo *info);
    void (*StringCompare)(TextInfo *strA, TextInfo *strB, bool32 flag);
    void (*GetDisplayInfo)(int *displayID, int *width, int *height, int *refreshRate, TextInfo *text);
    void (*GetWindowSize)(int *width, int *height);
    int (*SetScreenSize)(byte screenID, ushort width, ushort height);
    void (*SetClipBounds)(byte screenID, int x1, int y1, int x2, int y2);
#if RETRO_USE_PLUS
    void (*SetScreenSplitVerticies)(sbyte p2_1, sbyte p2_2, sbyte p3_1, sbyte p3_2, sbyte p3_3);
#endif
    short (*LoadSpriteSheet)(const char *path, Scopes scope);
    void (*SetLookupTable)(ushort *tablePtr);
    void (*SetPaletteMask)(uint maskColour);
    void (*SetPaletteEntry)(byte paletteID, byte index, uint colour);
    uint (*GetPaletteEntry)(byte paletteID, byte index);
    void (*SetActivePalette)(byte newActivePal, int startLine, int endLine);
    void (*CopyPalette)(byte sourcePalette, byte srcPaletteStart, byte destinationPalette, byte destPaletteStart, ushort count);
#if RETRO_USE_PLUS
    void (*LoadPalette)(byte bank, const char *path, ushort rowFlags);
#endif
    void (*RotatePalette)(byte palID, byte startIndex, byte endIndex, bool32 right);
    void (*SetLimitedFade)(byte destPaletteID, byte srcPaletteA, byte srcPaletteB, ushort blendAmount, int startIndex, int endIndex);
#if RETRO_USE_PLUS
    void (*BlendColours)(byte paletteID, byte *coloursA, byte *coloursB, int alpha, int index, int count);
#endif
    void (*DrawRect)(int x, int y, int width, int height, uint colour, int alpha, InkEffects inkEffect, bool32 screenRelative);
    void (*DrawLine)(int x1, int y1, int x2, int y2, uint colour, int alpha, InkEffects inkEffect, bool32 screenRelative);
    void (*DrawCircle)(int x, int y, int radius, uint colour, int alpha, InkEffects inkEffect, bool32 screenRelative);
    void (*DrawCircleOutline)(int x, int y, int innerRadius, int outerRadius, uint colour, int alpha, InkEffects inkEffect, bool32 screenRelative);
    void (*DrawQuad)(Vector2 *verticies, int vertCount, int r, int g, int b, int alpha, InkEffects inkEffect);
    void (*DrawBlendedQuad)(Vector2 *verticies, colour *vertColours, int vertCount, int alpha, InkEffects inkEffect);
    void (*DrawSprite)(Animator *data, Vector2 *position, bool32 screenRelative);
    void (*DrawDeformedSprite)(ushort sheet, InkEffects inkEffect, bool32 screenRelative);
    void (*DrawText)(Animator *data, Vector2 *position, TextInfo *info, int endFrame, int textLength, Alignments align, int spacing, int a8,
                     Vector2 *charPos, bool32 ScreenRelative);
    void (*DrawTile)(ushort *tileInfo, int countX, int countY, void *entityPtr, Vector2 *position, bool32 screenRelative);
    void (*CopyTile)(void);
    void (*DrawAniTiles)(ushort sheetID, ushort tileIndex, ushort srcX, ushort srcY, ushort width, ushort height);
    void (*FillScreen)(uint colour, int alphaR, int alphaG, int alphaB);
    ushort (*LoadMesh)(const char *filename, byte scope);
    ushort (*Create3DScene)(const char *identifier, ushort faceCount, byte scope);
    void (*Prepare3DScene)(ushort index);
    void (*SetAmbientColour)(ushort index, int x, int y, int z);
    void (*SetDiffuseColour)(ushort index, int x, int y, int z);
    void (*SetSpecularColour)(ushort index, int x, int y, int z);
    void (*AddModelTo3DScene)(ushort modelIndex, ushort sceneIndex, byte type, Matrix *mat1, Matrix *mat2, colour colour);
    void (*SetModelAnimation)(ushort modelAnim, Animator *data, short animSpeed, byte loopIndex, bool32 forceApply, ushort frameID);
    void (*AddMeshFrameTo3DScene)(ushort modelID, ushort sceneID, Animator *data, byte drawMode, Matrix *mat1, Matrix *mat, colour colour);
    void (*Draw3DScene)(ushort index);
    ushort (*LoadSpriteAnimation)(const char *path, Scopes scope);
    ushort (*CreateSpriteAnimation)(const char *filename, uint frameCount, uint animCount, Scopes scope);
    void (*SetSpriteAnimation)(ushort spriteIndex, ushort animationID, Animator *data, bool32 forceApply, ushort frameID);
    void (*EditSpriteAnimation)(ushort spriteIndex, ushort animID, const char *name, int frameOffset, ushort frameCount, short animSpeed,
                                byte loopIndex, byte rotationFlag);
    void (*SetSpriteString)(ushort spriteIndex, ushort animID, TextInfo *info);
    void *(*GetSpriteAnimation)(ushort sprIndex, const char *name);
    SpriteFrame *(*GetFrame)(ushort sprIndex, ushort anim, int frame);
    Hitbox *(*GetHitbox)(Animator *data, byte hitboxID);
    short (*GetFrameID)(Animator *data);
    int (*GetStringWidth)(ushort sprIndex, ushort animID, TextInfo *info, int startIndex, int length, int spacing);
    void (*ProcessAnimation)(Animator *data);
    TileLayer *(*GetSceneLayer)(int layerID);
    int (*GetSceneLayerID)(const char *name);
    void (*GetLayerSize)(ushort layer, Vector2 *size, bool32 pixelSize);
    ushort (*GetTileInfo)(ushort layer, int x, int y);
    void (*SetTileInfo)(ushort layer, int x, int y, ushort tile);
    int (*CopyTileLayer)(ushort dstLayer, int startX1, int startY1, ushort srcLayer, int startX2, int startY2, int countX, int countY);
    void (*ProcessParallax)(TileLayer *TileLayer);
    ScanlineInfo *(*GetScanlines)(void);
    bool32 (*CheckObjectCollisionTouchBox)(void *thisEntity, Hitbox *thisHitbox, void *otherEntity, Hitbox *otherHitbox);
    bool32 (*CheckObjectCollisionTouchCircle)(void *thisEntity, int thisOffset, void *otherEntity, int otherOffset);
    byte (*CheckObjectCollisionBox)(void *thisEntity, Hitbox *thisHitbox, void *otherEntity, Hitbox *otherHitbox, bool32 setPos);
    bool32 (*CheckObjectCollisionPlatform)(void *thisEntity, Hitbox *thisHitbox, void *otherEntity, Hitbox *otherHitbox, bool32 setPos);
    bool32 (*ObjectTileCollision)(void *entity, ushort collisionLayers, byte collisionMode, byte collisionPlane, int xOffset, int yOffset,
                                  bool32 setPos);
    bool32 (*ObjectTileGrip)(void *entity, ushort collisionLayers, byte collisionMode, byte collisionPlane, int xOffset, int yOffset,
                             sbyte tolerance);
    void (*ProcessTileCollisions)(void *entity, Hitbox *outer, Hitbox *inner);
    int (*GetTileAngle)(ushort tileID, byte cPlane, byte cMode);
    void (*SetTileAngle)(ushort tileID, byte cPlane, byte cMode, byte value);
    byte (*GetTileBehaviour)(ushort tileID, byte cPlane);
    void (*SetTileBehaviour)(ushort tileID, byte cPlane, byte value);
    int (*GetSFX)(const char *path);
    int (*PlaySFX)(ushort sfx, int loop, int pan);
    void (*StopSFX)(ushort sfx);
    int (*PlayStream)(const char *filename, uint slot, int a3, uint loopPoint, bool32 loadASync);
    int (*SetChannelAttributes)(byte slot, float volume, float pan, float playbackSpeed);
    void (*StopChannel)(byte slot);
    void (*PauseChannel)(byte slot);
    void (*ResumeChannel)(byte slot);
    bool32 (*IsSFXPlaying)(byte slot);
    bool32 (*ChannelActive)(byte slot);
    int (*GetChannelPos)(byte slot);
    void (*LoadVideo)(const char *filename, double a2, bool32 (*skipCallback)(void));
    bool32 (*LoadImage)(const char *filename, double displayLength, double speed, bool32 (*skipCallback)(void));
#if RETRO_USE_PLUS
    int (*ControllerIDForInputID)(byte controllerID);
    int (*MostRecentActiveControllerID)(int inputID, int a2, uint a3);
    int (*Unknown100)(int inputID);
    int (*GetAssignedControllerID)(int inputID);
    int (*GetAssignedUnknown)(int inputID);
    int (*DoInputUnknown2)(int inputID, int a2, int a3);
    int (*DoInputUnknown3)(int inputID, int a2, int a3);
    int (*Missing24)(void);
    int (*DoInputUnknown2_Active)(byte controllerID, int a2, int a3);
    int (*DoInputUnknown3_Active)(byte controllerID, int a2, int a3);
    void (*AssignControllerID)(byte controllerID, int a2);
    bool32 (*InputIDIsDisconnected)(byte controllerID);
    void (*ResetControllerAssignments)(void);
#endif
#if !RETRO_USE_PLUS
    void (*Unknown92)(int a1, int a2, int *a3);
#endif
    int (*LoadUserFile)(const char *filename, void *buffer, uint size); // load user file from exe dir
    int (*SaveUserFile)(const char *fileName, void *buffer, uint size); // save use file to exe dir
#if RETRO_USE_PLUS
    void (*PrintLog)(SeverityModes severity, const char *message, ...);
    void (*PrintString)(SeverityModes severity, const char *message);
    void (*PrintText)(SeverityModes severity, TextInfo *text);
    void (*PrintIntegerUnsigned)(SeverityModes severity, const char *message, uint integer);
    void (*PrintInteger)(SeverityModes severity, const char *message, int integer);
    void (*PrintFloat)(SeverityModes severity, const char *message, float f);
    void (*PrintVector2)(SeverityModes severity, const char *message, int x, int y);
    void (*PrintHitbox)(SeverityModes severity, const char *message, Hitbox *hitbox);
#endif
    void (*SetActiveVariable)(int objectID, const char *name);
    void (*AddVarEnumValue)(const char *name);
#if RETRO_USE_PLUS
    void (*ClearDebugValues)(void);
    void (*SetDebugValue)(const char *name, void *valPtr, int type, int unknown1, int unknown2);
#endif
#if !RETRO_USE_PLUS
    void (*PrintMessage)(void *message, byte type);
#endif
} RSDKFunctionTable;

// =======================================
// Game Options & RSDKConfig stuff
// =======================================
typedef enum {
#if !RETRO_USE_PLUS
    MODE_NOSAVE,
#endif
    MODE_MANIA,
#if RETRO_USE_PLUS
    MODE_ENCORE,
#endif
    MODE_TIMEATTACK,
    MODE_COMPETITION,
} GameModes;

typedef enum { MEDIA_DEMO } CategoryIDS;

typedef enum {
    ID_NONE     = 0x00,
    ID_SONIC    = 0x01,
    ID_TAILS    = 0x02,
    ID_KNUCKLES = 0x04,
#if RETRO_USE_PLUS
    ID_MIGHTY = 0x08,
    ID_RAY    = 0x10,
#endif
    ID_TAILS_ASSIST   = 0x200,
    ID_DEFAULT_PLAYER = ID_SONIC | ID_TAILS_ASSIST,
} PlayerIDs;

typedef enum { ITEMS_FIXED, ITEMS_RANDOM, ITEMS_TELEPORT } ItemModes;

typedef enum { MEDAL_DEBUGMODE, MEDAL_ANDKNUCKLES, MEDAL_PEELOUT, MEDAL_INSTASHIELD, MEDAL_DROPDASH, MEDAL_NOTIMEOVER } MedalMods;
#define getMod(medal) (1 << medal)

typedef enum { FORCE_SPLIT = 2 } ScreenSplit;

typedef enum { WIDE_SCR_XSIZE = 424, WIDE_SCR_XCENTER = 212 } ScreenSizes;

typedef enum { NO_SAVE_SLOT = 255 } SaveSlots;

#if RETRO_USE_PLUS
typedef enum { FILTER_MANIA = 2, FILTER_ENCORE = 4 } ModeFilters;
typedef enum { SCN_FILTER_MANIA = 3, SCN_FILTER_ENCORE = 5 } SceneFilters;
#endif

typedef enum {
    SLOT_PLAYER1          = 0,
    SLOT_PLAYER2          = 1,
    SLOT_PLAYER3          = 2,
    SLOT_PLAYER4          = 3,
    SLOT_BSS_SETUP        = 8,
    SLOT_PBL_SETUP        = 8,
    SLOT_UFO_SETUP        = 8,
    SLOT_MUSIC            = 9,
    SLOT_BSS_HUD          = 10,
    SLOT_UFO_CAMERA       = 10,
    SLOT_PBL_CAMERA       = 10,
    SLOT_BSS_MESSAGE      = 11,
    SLOT_UFO_HUD          = 11,
    SLOT_ZONE             = 12,
    SLOT_CUTSCENESEQ      = 15,
    SLOT_PAUSEMENU        = 16,
    SLOT_GAMEOVER         = 16,
    SLOT_ACTCLEAR         = 16,
    SLOT_UICONTROL        = 17,
    SLOT_DIALOG           = 21,
    SLOT_DIALOG_UICONTROL = 22,
    SLOT_BSS_HORIZON      = 32,
    SLOT_UFO_SPEEDLINES   = 34,
    SLOT_UFO_PLASMA       = 36,
    SLOT_REPLAYRECORDER   = 37,
    SLOT_CAMERA1          = 60,
    SLOT_CAMERA2          = 61,
    SLOT_CAMERA3          = 62,
    SLOT_CAMERA4          = 63,
} ReservedEntities;

typedef enum {
    CS_Unknown0,
    CS_Unknown1,
    CS_Unknown2,
    CS_Unknown3,
    CS_Unknown4,
    CS_Unknown5,
    CS_Unknown6,
    CS_Unknown7,
    CS_Unknown8,
    CS_Unknown9,
    CS_Unknown10,
    CS_Unknown11,
    CS_Unknown12,
    CS_Unknown13,
    CS_Unknown14,
    CS_Unknown15,
    CS_Unknown16,
    CS_Unknown17,
    CS_Unknown18,
    CS_Unknown19,
    CS_Unknown20,
    CS_Unknown21,
    CS_inMatch,
    CS_PlayerCount,
    CS_LevelIndex,
    CS_ZoneID,
    CS_ActID,
    CS_MatchID,
    CS_MatchCount,
    CS_MonitorMode,
    CS_Unknown29,
    // flags for each zone
    CS_ZoneUnknown30, // GHZ
    CS_ZoneUnknown31, // CPZ
    CS_ZoneUnknown32, // SPZ
    CS_ZoneUnknown33, // FBZ
    CS_ZoneUnknown34, // PGZ
    CS_ZoneUnknown35, // SSZ
    CS_ZoneUnknown36, // HCZ
    CS_ZoneUnknown37, // MSZ
    CS_ZoneUnknown38, // OOZ
    CS_ZoneUnknown39, // LRZ
    CS_ZoneUnknown40, // MMZ
    CS_ZoneUnknown41, // TMZ
    CS_CharacterFlags,
    CS_WinnerFlag1,
    CS_WinnerFlag2,
    CS_WinnerFlag3,
    CS_RingsP1,
    CS_RingsP2,
    CS_RingsP3,
    CS_RingsP4,
    CS_ScoreP1,
    CS_ScoreP2,
    CS_ScoreP3,
    CS_ScoreP4,
    CS_ItemsP1,
    CS_ItemsP2,
    CS_ItemsP3,
    CS_ItemsP4,
    CS_TimeMinutesP1,
    CS_TimeSecondsP1,
    CS_TimeMillisecondsP1,
    CS_TimeMinutesP2,
    CS_TimeSecondsP2,
    CS_TimeMillisecondsP2,
    CS_TimeMinutesP3,
    CS_TimeSecondsP3,
    CS_TimeMillisecondsP3,
    CS_TimeMinutesP4,
    CS_TimeSecondsP4,
    CS_TimeMillisecondsP4,
    CS_FinishFlags,
    CS_TotalRingsP1,
    CS_TotalRingsP2,
    CS_TotalRingsP3,
    CS_TotalRingsP4,
    CS_WinsP1,
    CS_WinsP2,
    CS_WinsP3,
    CS_WinsP4,
    CS_LivesP1,
    CS_LivesP2,
    CS_LivesP3,
    CS_LivesP4,
    CS_Unknown84,
    CS_Unknown85,
    CS_Unknown86,
    CS_Unknown87,
    CS_ReadOnlyDisplayMode,
    CS_Unknown89,
    CS_Unknown90,
    CS_Unknown91,
    CS_Unknown92,
    CS_Unknown93,
    CS_Unknown94,
    CS_Unknown95,
    CS_Unknown96,
    CS_Unknown97,
    CS_Unknown98,
    CS_Unknown99,
} CompetitionSessionIDs;

typedef enum {
    PRESENCE_GENERIC,
    PRESENCE_MENU,
    PRESENCE_MANIA,
#if RETRO_USE_PLUS
    PRESENCE_ENCORE,
#endif
    PRESENCE_TA,
    PRESENCE_COMP,
    PRESENCE_TITLE,
} PresenceTypes;

//this is just mania's default, this can be changed/removed with correct gameconfig edits
typedef struct {
    int gameMode;
    int playerID;
    int specialCleared;
    int specialRingID;
    int blueSpheresID;
    int blueSpheresInit;
    int atlEnabled;
    int atlEntityCount;
    int atlEntitySlot[0x20];
    int atlEntityData[0x4000];
    int saveLoaded;
    int saveRAM[0x4000];
    int saveSlotID;
    int noSaveSlot[0x400];
    int menuParam[0x4000];
    int itemMode;
    int suppressTitlecard;
    int suppressAutoMusic;
    int competitionSession[0x4000];
    int medalMods;
    int parallaxOffset[256];
    int enableIntro;
    int optionsLoaded;
    int optionsRAM[128];
    int presenceID;
    int medallionDebug;
    int noSave;
    int notifiedAutosave;
    int recallEntities;
    int restartRings;
    int restart1UP;
    int restartShield;
    int restartPos[8];
    int restartSlot[4];
    int restartDir[4];
    int restartMinutes;
    int restartSeconds;
    int restartMilliseconds;
    int tempMinutes;
    int tempSeconds;
    int tempMilliseconds;
    int restartScore;
    int restartScore1UP;
    int restartLives[4];
    int restartMusicID;
    int restartFlags;
    int tempFlags;
    int continues;
    int initCoolBonus;
    int coolBonus[4];
#if RETRO_USE_PLUS
    int replayWriteBuffer[0x40000];
    int replayReadBuffer[0x40000];
    int replayTempWBuffer[0x40000];
    int replayTempRBuffer[0x40000];
    int replayTableID;
    int replayTableLoaded;
    int taTableID;
    int taTableLoaded;
    int stock;
    int characterFlags;
    int vapeMode;
    int secrets;
    int superSecret;
    int superMusicEnabled;
    int lastHasPlus;
    int hasPlusInitial;
#endif
} GlobalVariables;

typedef struct {
    const char *name;
    Object **structPtr;
} GameObject;

// =======================================
// Game Link Structs
// =======================================
extern Hitbox defaultHitbox;

extern Object *(*GetObject)(const char *name);

extern GlobalVariables *globals;

extern RSDKFunctionTable RSDK;
#if RETRO_USE_PLUS
extern UserFunctionTable User;
#endif

extern SceneInfo *RSDK_sceneInfo;
extern EngineInfo *RSDK_info;
#if RETRO_USE_PLUS
extern SKUInfo *RSDK_sku;
#endif
extern ControllerState *RSDK_controller;
extern AnalogState *RSDK_stickL;
#if RETRO_USE_PLUS
extern AnalogState *RSDK_stickR;
extern TriggerState *RSDK_triggerL;
extern TriggerState *RSDK_triggerR;
#endif
extern TouchMouseData *RSDK_touchMouse;
#if RETRO_USE_PLUS
extern UnknownInfo *RSDK_unknown;
#endif
extern ScreenInfo *RSDK_screens;

#endif /* GAMELINK_H */
