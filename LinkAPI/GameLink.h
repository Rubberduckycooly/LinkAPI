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
#define SCREEN_XMAX     (1280)
#define SCREEN_YSIZE    (240)
#define LAYER_COUNT     (8)
#define DRAWLAYER_COUNT (16)
#if RETRO_USE_PLUS
#define PLAYER_MAX (4)
#else
#define PLAYER_MAX (2)
#endif

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
    bool32 inBounds;
    int field_3C;
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
    byte field_57;
} Entity;

typedef struct {
    ushort objectID;
    byte active;
    byte field_3;
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
    int field_3C;                                                                                                                                    \
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

// Unfinished
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
    byte field_30;
} UnknownInfo;
#else
// Unfinished
typedef struct {
    char gameName[32];
    char gameSubname[32];
    char version[16];
    char field_50;
    char field_51;
    char field_52;
    ushort objectCount;
    char field_55;
    char field_56;
    char field_57;
    char field_58;
    char field_59;
    char field_5A;
    char field_5B;
    char field_5C;
    char field_5D;
    char field_5E;
    char field_5F;
    char field_60;
    char field_61;
    char field_62;
    char field_63;
    char field_64;
    char field_65;
    char field_66;
    char field_67;
    char field_68;
    char field_69;
    char field_6A;
    char field_6B;
    char field_6C;
    char field_6D;
    char field_6E;
    char field_6F;
    char field_70;
    char field_71;
    char field_72;
    char field_73;
    char field_74;
    char field_75;
    char field_76;
    char field_77;
    char field_78;
    char field_79;
    char field_7A;
    char field_7B;
    char field_7C;
    char field_7D;
    char field_7E;
    char field_7F;
    char field_80;
    char field_81;
    char field_82;
    char field_83;
    char field_84;
    char field_85;
    char field_86;
    char field_87;
    char field_88;
    char field_89;
    char field_8A;
    char field_8B;
    char field_8C;
    char field_8D;
    char field_8E;
    char field_8F;
    char field_90;
    char field_91;
    char field_92;
    char field_93;
    char field_94;
    char field_95;
    char field_96;
    char field_97;
    char field_98;
    char field_99;
    char field_9A;
    char field_9B;
    char field_9C;
    char field_9D;
    char field_9E;
    char field_9F;
    char field_A0;
    char field_A1;
    char field_A2;
    char field_A3;
    char field_A4;
    char field_A5;
    char field_A6;
    char field_A7;
    char field_A8;
    char field_A9;
    char field_AA;
    char field_AB;
    char field_AC;
    char field_AD;
    char field_AE;
    char field_AF;
    char field_B0;
    char field_B1;
    char field_B2;
    char field_B3;
    char field_B4;
    char field_B5;
    char field_B6;
    char field_B7;
    char field_B8;
    char field_B9;
    char field_BA;
    char field_BB;
    char field_BC;
    char field_BD;
    char field_BE;
    char field_BF;
    char field_C0;
    char field_C1;
    char field_C2;
    char field_C3;
    char field_C4;
    char field_C5;
    char field_C6;
    char field_C7;
    char field_C8;
    char field_C9;
    char field_CA;
    char field_CB;
    char field_CC;
    char field_CD;
    char field_CE;
    char field_CF;
    char field_D0;
    char field_D1;
    char field_D2;
    char field_D3;
    char field_D4;
    char field_D5;
    char field_D6;
    char field_D7;
    char field_D8;
    char field_D9;
    char field_DA;
    char field_DB;
    char field_DC;
    char field_DD;
    char field_DE;
    char field_DF;
    char field_E0;
    char field_E1;
    char field_E2;
    char field_E3;
    char field_E4;
    char field_E5;
    char field_E6;
    char field_E7;
    char field_E8;
    char field_E9;
    char field_EA;
    char field_EB;
    char field_EC;
    char field_ED;
    char field_EE;
    char field_EF;
    char field_F0;
    char field_F1;
    char field_F2;
    char field_F3;
    char field_F4;
    char field_F5;
    char field_F6;
    char field_F7;
    char field_F8;
    char field_F9;
    char field_FA;
    char field_FB;
    char field_FC;
    char field_FD;
    char field_FE;
    char field_FF;
    char field_100;
    char field_101;
    char field_102;
    char field_103;
    char field_104;
    char field_105;
    char field_106;
    char field_107;
    char field_108;
    char field_109;
    char field_10A;
    char field_10B;
    char field_10C;
    char field_10D;
    char field_10E;
    char field_10F;
    char field_110;
    char field_111;
    char field_112;
    char field_113;
    char field_114;
    char field_115;
    char field_116;
    char field_117;
    char field_118;
    char field_119;
    char field_11A;
    char field_11B;
    char field_11C;
    char field_11D;
    char field_11E;
    char field_11F;
    char field_120;
    char field_121;
    char field_122;
    char field_123;
    char field_124;
    char field_125;
    char field_126;
    char field_127;
    char field_128;
    char field_129;
    char field_12A;
    char field_12B;
    char field_12C;
    char field_12D;
    char field_12E;
    char field_12F;
    char field_130;
    char field_131;
    char field_132;
    char field_133;
    char field_134;
    char field_135;
    char field_136;
    char field_137;
    char field_138;
    char field_139;
    char field_13A;
    char field_13B;
    char field_13C;
    char field_13D;
    char field_13E;
    char field_13F;
    char field_140;
    char field_141;
    char field_142;
    char field_143;
    char field_144;
    char field_145;
    char field_146;
    char field_147;
    char field_148;
    char field_149;
    char field_14A;
    char field_14B;
    char field_14C;
    char field_14D;
    char field_14E;
    char field_14F;
    byte platformID;
    byte language;
    byte region;
    char field_153;
    char field_154;
    char field_155;
    char field_156;
    char field_157;
    char field_158;
    char field_159;
    char field_15A;
    char field_15B;
    char field_15C;
    char field_15D;
    char field_15E;
    char field_15F;
    char field_160;
    char field_161;
    char field_162;
    char field_163;
    char field_164;
    char field_165;
    char field_166;
    char field_167;
    char field_168;
    char field_169;
    char field_16A;
    char field_16B;
    char field_16C;
    char field_16D;
    char field_16E;
    char field_16F;
    char field_170;
    char field_171;
    char field_172;
    char field_173;
    char field_174;
    char field_175;
    char field_176;
    char field_177;
    char field_178;
    char field_179;
    char field_17A;
    char field_17B;
    char field_17C;
    char field_17D;
    char field_17E;
    char field_17F;
} EngineInfo;
#endif

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
    char *gameName;
    SKUInfo *currentSKU;
#else
    EngineInfo *engineInfo;
#endif
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
} EntityAnimationData;

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

extern char textBuffer[0x400];

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

#define voidToInt(x) (size_t)(x)

// Userdata Table
typedef struct {
    void (*Unknown1)(void);
    bool32 (*GetConfirmButtonFlip)(void);
    void (*Unknown2)(void);
    void (*Unknown3)(void);
    void (*Unknown4)(int a1);
    bool32 (*CheckDLC)(byte dlc);
    void (*Unknown5)(int a1);
    void (*UnlockAchievement)(const char *achName);
    void (*Missing0)(void);
    void (*Unknown6)(int a1);
    void (*Unknown7)(void);
    void (*Unknown8)(int a1, int a2);
    void (*Unknown9)(int a1, int a2, int a3);
    void (*Unknown10)(void);
    void (*LeaderboardEntryCount)(void);
    void (*Missing1)(void);
    void (*Unknown12)(int a2, uint a3, int a4);
    void (*Missing2)(void);
    void (*ReadLeaderboardEntry)(uint a1);
    void (*SetRichPresence)(int, TextInfo *text);
    void (*Unknown14)(int a1);
    void (*Missing3)(void);
    void (*Unknown15)(int a1);
    void (*Unknown16)(void);
    void (*TryAuth)(void);
    void (*GetUserAuthStatus)(void);
    void (*GetUsername)(TextInfo *text);
    void (*TryInitStorage)(void);
    void (*GetStorageStatus)(void);
    void (*Unknown22)(void);
    void (*Unknown23)(void);
    void (*Unknown24)(void);
    void (*Missing4)(void);
    void (*Unknown25)(void);
    void (*Unknown26)(void);
    void (*Unknown27)(int a1);
    bool32 (*Unknown28)(void);
    void (*LoadUserFile)(const char *name, int *data, int size, void (*callback)(int status));
    void (*SaveUserFile)(const char *name, int *data, int size, void (*callback)(int status), bool32 compress);
    void (*DeleteUserFile)(const char *filename, void (*callback)(int status));
    void (*InitUserDB)(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
    void (*LoadUserDB)(const char *filename, void (*callback)(int status));
    void (*SaveUserDB)(ushort tableID, void (*callback)(int status));
    void (*ClearUserDB)(ushort tableID);
    void (*ClearAllUserDBs)(void);
    void (*Unknown31)(ushort tableID);
    void (*GetUserDBStatus)(ushort tableID);
    void (*Unknown33)(ushort tableID, int a2, int a3, int a4);
    void (*Unknown34)(ushort tableID, int a2, int a3, int a4);
    void (*Unknown35)(ushort tableID);
    int (*GetUserDBUnkownCount)(ushort tableID, ushort entryID);
    int (*GetUserDBUnkown)(ushort tableID);
    void (*AddUserDBEntry)(ushort tableID, void *, void *, void *, void *);
    void (*Unknown39)(ushort tableID, int a2, int a3, int a4, void *dst);
    void (*GetEntryUUID)(ushort tableID, ushort entryID);
    void (*Unknown40)(ushort tableID, ushort entryID);
    void (*GetUserDBTimeA)(ushort tableID, int a2, char *buf, uint sizeInBytes, const char *format);
    void (*Unknown42)(ushort tableID, int a2);
    void (*Unknown43)(ushort tableID);
    // count: 59
} UserFunctionTable;

// Function Table
typedef struct {
    void (*InitGameOptions)(void **options, int size);
    void (*CreateObject)(Object **structPtr, const char *name, uint entitySize, uint objectSize, void (*update)(), void (*lateUpdate)(),
                         void (*staticUpdate)(), void (*draw)(), void (*create)(void *), void (*stageLoad)(), void (*editorDraw)(),
                         void (*editorLoad)(), void (*serialize)());
#if RETRO_USE_PLUS
    void (*CreateObjectContainer)(void **structPtr, const char *name, uint objectSize);
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
    void (*SwapDrawLayers)(byte layer, ushort entityID);
    void (*SetDrawLayerProperties)(byte layer, bool32 active, void (*initDrawPtr)(void));
    void (*LoadScene)(const char *categoryName, const char *sceneName);
    void (*SetGameMode)(byte mode);
#if RETRO_USE_PLUS
    void (*SetHardResetFlag)(bool32 set);
#endif
    void (*CheckValidScene)(void);
    int (*CheckStageFolder)(const char *folderName);
    int (*InitSceneLoad)(void);
    int (*GetObjectIDByName)(const char *name);
    void (*ClearScreens)(void);
    void (*AddScreen)(Vector2 *pos, int offsetX, int offsetY, bool32 worldRelative);
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
    void (*MatrixTranslateXYZ)(Matrix *matrix, short x, short y, short z, bool32 setIdentity);
    void (*MatrixScaleXYZ)(Matrix *matrix, short scaleX, short scaleY, short scaleZ);
    void (*MatrixRotateX)(Matrix *matrix, short angle);
    void (*MatrixRotateY)(Matrix *matrix, short angle);
    void (*MatrixRotateZ)(Matrix *matrix, short angle);
    void (*MatrixRotateXYZ)(Matrix *matrix, short angleX, short angleY, short angleZ);
    void (*MatrixInverse)(Matrix *dest, Matrix *matrix);
    void (*MatrixCopy)(Matrix *matDest, Matrix *matSrc);
    void (*SetText)(TextInfo *textInfo, const char *text, uint size);
    void (*Unknown64)(TextInfo *dst, char *src);
    void (*Unknown65)(TextInfo *, TextInfo *);
    void (*Unknown66)(TextInfo *, TextInfo *);
    void (*Unknown67)(TextInfo *, TextInfo *);
    void (*LoadStrings)(TextInfo *dst, const char *path, int);
    void (*Unknown68)(TextInfo *, TextInfo *, int, int);
    void (*CopyString)(char *text, TextInfo *info);
    void (*Unknown69)(void);
    void (*Unknown70)(void);
    void (*Unknown71)(void);
    int (*SetScreenSize)(void *, void *, void *, void *, void *);
    void (*SetClipBounds)(byte screenID, int x1, int y1, int x2, int y2);
#if RETRO_USE_PLUS
    void (*SetScreenUnknown)(byte, byte, byte, byte, byte);
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
    void (*DrawTexturedQuad)(Vector2 *verticies, Vector2 *vertexUVs, int vertCount, int alpha, InkEffects inkEffect);
    void (*DrawSprite)(EntityAnimationData *data, Vector2 *position, bool32 screenRelative);
    void (*DrawDeformedSprite)(ushort sheet, InkEffects inkEffect, bool32 screenRelative);
    void (*DrawText)(EntityAnimationData *data, Vector2 *position, TextInfo *info, int endFrame, int textLength, FlipFlags direction, int a7, int a8,
                     int a9, bool32 ScreenRelative);
    void (*DrawTile)(ushort *tileInfo, int countX, int countY, void *entityPtr, Vector2 *position, bool32 screenRelative);
    void (*CopyTile)(void);
    void (*DrawAniTiles)(ushort sheetID, ushort tileIndex, ushort srcX, ushort srcY, ushort width, ushort height);
    void (*FillScreen)(int a1, int a2, int a3, int a4);
    ushort (*LoadMesh)(const char *filename, byte scope);
    ushort (*Create3DScene)(const char *identifier, ushort faceCount, byte scope);
    void (*Prepare3DScene)(ushort index);
    void (*View_Something1)(ushort index, int x, int y, int z);
    void (*View_Something2)(ushort index, int x, int y, int z);
    void (*View_Something3)(ushort index, int x, int y, int z);
    void (*AddMeshToScene)(ushort modelIndex, ushort sceneIndex, byte type, Matrix *mat1, Matrix *mat2, colour colour);
    void (*SetModelAnimation)(ushort modelAnim, EntityAnimationData *data, short animSpeed, byte loopIndex, bool32 forceApply, ushort frameID);
    void (*SetupMeshAnimation)(void);
    void (*Draw3DScene)(ushort index);
    ushort (*LoadAnimation)(const char *path, Scopes scope);
    ushort (*CreateAnimation)(const char *filename, uint frameCount, uint animCount, Scopes scope);
    void (*SetSpriteAnimation)(ushort spriteIndex, ushort animationID, EntityAnimationData *data, bool32 forceApply, ushort frameID);
    void (*EditAnimation)(ushort spriteIndex, ushort animID, const char *name, int frameOffset, ushort frameCount, short animSpeed, byte loopIndex,
                          byte rotationFlag);
    void (*SetSpriteString)(ushort spriteIndex, ushort animID, TextInfo *info);
    void (*GetAnimation)(ushort sprIndex, const char *name);
    SpriteFrame *(*GetFrame)(ushort sprIndex, ushort anim, int frame);
    Hitbox *(*GetHitbox)(EntityAnimationData *data, byte hitboxID);
    short (*GetFrameID)(EntityAnimationData *data);
    int (*GetStringWidth)(ushort sprIndex, ushort animID, TextInfo *info, int startIndex, int length, int spacing);
    void (*ProcessAnimation)(EntityAnimationData *data);
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
    void (*GetTileAngle)(ushort tileID, byte cPlane, byte cMode);
    void (*SetTileAngle)(ushort tileID, byte cPlane, byte cMode, byte value);
    void (*GetTileBehaviour)(ushort tileID, byte cPlane);
    void (*SetTileBehaviour)(ushort tileID, byte cPlane, byte value);
    int (*GetSFX)(const char *path);
    int (*PlaySFX)(ushort sfx, int loop, int pan);
    void (*StopSFX)(ushort sfx);
    int (*PlayMusic)(const char *filename, uint slot, int a3, uint loopStart, bool32 loop);
    int (*SetSoundAttributes)(byte a1, uint slot, float volume, float pan, float playbackSpeed);
    void (*SoundUnknown1)(byte slot);
    void (*PauseChannel)(byte slot);
    void (*ResumeChannel)(byte slot);
    bool32 (*SoundPlaying)(byte slot);
    bool32 (*ChannelPlaying)(byte slot);
    bool32 (*TrackPlaying)(byte slot);
    void (*LoadVideo)(const char *filename, int64 a2, int (*a3)(void));
    bool32 (*LoadImage)(const char *filename, double displayLength, double speed, bool32 (*skipCallback)(void));
#if RETRO_USE_PLUS
    int (*ControllerIDForInputID)(byte controllerID);
    int (*MostRecentActiveControllerID)(int a1, int a2, uint a3);
    void (*Unknown100)(int a1);
    void (*Unknown101)(int a1);
    void (*Missing21)(int a1);
    void (*Missing22)(int a1, int a2, int a3);
    void (*Missing23)(int a1, int a2, int a3);
    void (*Missing24)(void);
    void (*Missing25)(byte controllerID, int a2, int a3);
    void (*Missing26)(byte controllerID, int a2, int a3);
    void (*AssignControllerID)(byte controllerID, int a2);
    bool32 (*InputIDIsDisconnected)(byte controllerID);
    void (*ResetControllerAssignments)(void);
#endif
#if !RETRO_USE_PLUS
    void (*Unknown92)(int a1, int a2, int *a3);
#endif
    void (*LoadUserFile)(const char *filename, void *buffer, uint size); // load user file from exe dir
    void (*SaveUserFile)(const char *fileName, void *buffer, uint size); // save use file to exe dir
#if RETRO_USE_PLUS
    void (*PrintLog)(SeverityModes severity, const char *message, ...);
    void (*PrintString)(SeverityModes severity, const char *message);
    void (*PrintText)(SeverityModes severity, const char *message, TextInfo *text);
    void (*PrintIntegerUnsigned)(SeverityModes severity, const char *message, uint integer);
    void (*PrintInteger)(SeverityModes severity, const char *message, int integer);
    void (*PrintFloat)(SeverityModes severity, const char *message, float f);
    void (*PrintVector2)(SeverityModes severity, const char *message, int x, int y);
    void (*PrintHitbox)(SeverityModes severity, const char *message, Hitbox *hitbox);
#endif
    void (*Unknown105)(void);
    void (*Unknown106)(void);
#if RETRO_USE_PLUS
    void (*ClearDebugValues)(void);
    void (*SetDebugValue)(const char *name, void *valPtr, int type, int unknown1, int unknown2);
#else
    void (*PrintMessage)(void *message, byte type);
#endif
} RSDKFunctionTable;

// =======================================
// Game Options & RSDKConfig stuff
// =======================================
enum GameModes {
#if !RETRO_USE_PLUS
    MODE_NOSAVE,
#endif
    MODE_MANIA,
#if RETRO_USE_PLUS
    MODE_ENCORE,
#endif
    MODE_TIMEATTACK,
    MODE_COMPETITION,
};

enum CategoryIDS { MEDIA_DEMO };

enum PlayerIDs {
    MAX_PLAYERS = 4,
    ID_SONIC    = 0x01,
    ID_TAILS    = 0x02,
    ID_KNUCKLES = 0x04,
#if RETRO_USE_PLUS
    ID_MIGHTY = 0x08,
    ID_RAY    = 0x10,
#endif
    ID_TAILS_ASSIST   = 0x200,
    ID_DEFAULT_PLAYER = 0x201,
};

enum ItemModes { ITEMS_FIXED, ITEMS_RANDOM, ITEMS_TELEPORT };

enum MedalMods { MEDAL_DEBUGMODE, MEDAL_ANDKNUCKLES, MEDAL_PEELOUT, MEDAL_INSTASHIELD, MEDAL_DROPDASH, MEDAL_NOTIMEOVER };
#define getMod(medal) (1 << medal)

enum ScreenSplit { FORCE_SPLIT = 2 };

enum ScreenSizes { WIDE_SCR_XSIZE = 424, WIDE_SCR_XCENTER = 212 };

enum SaveSlots { NO_SAVE_SLOT = 255 };

#if RETRO_USE_PLUS
enum ModeFilters { FILTER_MANIA = 2, FILTER_ENCORE = 4 };
#endif

enum ReservedEntities {
    SLOT_PLAYER1        = 0,
    SLOT_PLAYER2        = 1,
    SLOT_PLAYER3        = 2,
    SLOT_PLAYER4        = 3,
    SLOT_MUSIC          = 9,
    SLOT_BSS_MESSAGE    = 11,
    SLOT_ZONE           = 12,
    SLOT_CUTSCENESEQ    = 15,
    SLOT_PAUSEMENU      = 16,
    SLOT_DIALOG         = 21,
    SLOT_REPLAYRECORDER = 37,
    SLOT_CAMERA1        = 60,
    SLOT_CAMERA2        = 61,
    SLOT_CAMERA3        = 62,
    SLOT_CAMERA4        = 63,
};

enum SettingsValues {
    SETTINGS_WINDOWED        = 0x0,
    SETTINGS_BORDERED        = 0x1,
    SETTINGS_EXCLUSIVEFS     = 0x2,
    SETTINGS_VSYNC           = 0x3,
    SETTINGS_TRIPLEBUFFERED  = 0x4,
    SETTINGS_WINDOW_WIDTH    = 0x5,
    SETTINGS_WINDOW_HEIGHT   = 0x6,
    SETTINGS_FSWIDTH         = 0x7,
    SETTINGS_FSHEIGHT        = 0x8,
    SETTINGS_REFRESHRATE     = 0x9,
    SETTINGS_SHADERSUPPORT   = 0xA,
    SETTINGS_SHADERID        = 0xB,
    SETTINGS_C               = 0xC,
    SETTINGS_DIMTIMER        = 0xD,
    SETTINGS_STREAMSENABLED  = 0xE,
    SETTINGS_STREAM_VOL      = 0xF,
    SETTINGS_SFX_VOL         = 0x10,
    SETTINGS_LANGUAGE        = 0x11,
    SETTINGS_12              = 0x12,
    SETTINGS_13              = 0x13,
    SETTINGS_14              = 0x14,
    SETTINGS_SETTINGSCHANGED = 0x15,
    SETTINGS_WRITE           = 0x16,
};

typedef struct {
    int gameMode;
    int playerID;
    int specialCleared;
    int specialRingID;
    int blueSpheresID;
    int blueSpheresInit;
    int atlEnabled;
    int atlEntityCount;
    int atlEntitySlot[32];
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
    int medalMods; // Stuff Like Instashieldand etc (Bonus Stuff that medals unlock)
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
    int stock; // Encore Lives
    int characterFlags;
    int vapeMode;
    int secrets;
    int superSecret;
    int superMusicEnabled;
    int lastHasPlus;
    int hasPlusInitial;
#endif
} GameOptions;

// =======================================
// Game Link Structs
// =======================================
extern Hitbox defaultHitbox;

extern GameOptions *options;

#if RETRO_USE_PLUS
extern UserFunctionTable User;
#endif
extern RSDKFunctionTable RSDK;

extern SceneInfo *RSDK_sceneInfo;
#if RETRO_USE_PLUS
extern char *RSDK_name;
extern SKUInfo *RSDK_sku;
#endif
#if !RETRO_USE_PLUS
extern EngineInfo *RSDK_info;
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
