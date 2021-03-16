#ifndef T1M_GAME_VARS_H
#define T1M_GAME_VARS_H

#include "game/const.h"
#include "game/types.h"
#include "util.h"

#include <stddef.h>
#include <stdint.h>

// clang-format off
#define dword_45A1F0            VAR_U_(0x0045A1F0, int32_t)
#define dword_45E960            VAR_U_(0x0045E960, int32_t)
#define dword_45B940            VAR_U_(0x0045B940, int32_t)

#define AuxDeviceID             VAR_U_(0x0045B984, uint32_t)
#define MCIDeviceID             VAR_U_(0x0045B994, uint32_t)
#define cd_drive                VAR_I_(0x0045A010, char, '.')
#define DEMO                    VAR_I_(0x0045F1C0, uint32_t, 0)
#define RoomCount               VAR_U_(0x00462BDC, uint16_t)
#define RoomInfo                VAR_U_(0x00462BE8, ROOM_INFO*)
#define PhdWinPtr               VAR_U_(0x006CAD0C, uint8_t*)
#define PhdWinMaxX              VAR_U_(0x006CAD00, int32_t)
#define PhdWinMaxY              VAR_U_(0x006CAD10, int32_t)
#define PhdWinCenterX           VAR_U_(0x0068F3AC, int32_t)
#define PhdWinCenterY           VAR_U_(0x0068F3B0, int32_t)
#define PhdViewDist             VAR_U_(0x006D4DE0, int32_t)
#define PhdScrWidth             VAR_U_(0x006D7600, int32_t)
#define PhdScrHeight            VAR_U_(0x006CAD08, int32_t)
#define PhdCenterX              VAR_U_(0x0068F3AC, int32_t)
#define PhdCenterY              VAR_U_(0x0068F3B0, int32_t)
#define PhdPersp                VAR_U_(0x0069518C, int32_t)
#define PhdFarZ                 VAR_U_(0x00695184, int32_t)
#define PhdNearZ                VAR_U_(0x006CAD04, int32_t)
#define PhdWet                  VAR_U_(0x0045A300, int32_t)
#define FloorData               VAR_U_(0x0045F1BC, int16_t*)
#define StringToShow            ARRAY_(0x00456AD0, char, [128])
#define MeshBase                VAR_U_(0x0045F1B8, int16_t*)
#define Meshes                  VAR_U_(0x00461F34, int16_t**)
#define Objects                 ARRAY_(0x0045F9E0, OBJECT_INFO, [NUMBER_OBJECTS])
#define StaticObjects           ARRAY_(0x00462660, STATIC_INFO, [])
#define LevelItemCount          VAR_U_(0x0045A0E0, int32_t)
#define Items                   VAR_U_(0x00462CEC, ITEM_INFO*)
#define GameAllocMemPointer     VAR_U_(0x0045E32C, void*)
#define GameAllocMemUsed        VAR_U_(0x0045E330, uint32_t)
#define GameAllocMemFree        VAR_U_(0x0045E334, uint32_t)
#define GameMemoryPointer       VAR_U_(0x0045A034, void*)
#define GameMemorySize          VAR_U_(0x0045EEF8, uint32_t)
#define GameVidWidth            VAR_I_(0x004546D0, int16_t, 320)
#define GameVidHeight           VAR_I_(0x004546D2, int16_t, 200)
#define ScrPtr                  VAR_I_(0x004546DA, uint8_t*, NULL)
#define BackScreen              VAR_I_(0x00459F68, uint8_t*, NULL)
#define BackScreenSize          VAR_I_(0x00459F6C, int32_t, 0)
#define CurrentLevel            VAR_U_(0x00453C4C, uint32_t)
#define Lara                    VAR_U_(0x0045ED80, LARA_INFO)
#define LaraItem                VAR_U_(0x0045EE6C, ITEM_INFO*)
#define PierreItem              VAR_U_(0x0045E328, int16_t)
#define SecretTotals            ARRAY_(0x00453CB0, int8_t, [MAX_SECRETS])
#define ResetFlag               VAR_I_(0x00459F50, int32_t, 0)
#define Input                   VAR_U_(0x0045EEF4, int32_t)
#define InputDB                 VAR_U_(0x0045A06C, int32_t)
#define KeyChange               VAR_U_(0x0045A234, int32_t)
#define KeyData                 VAR_U_(0x0045B998, KEYSTUFF*)
#define JoyXPos                 VAR_U_(0x0045B958, int32_t)
#define JoyYPos                 VAR_U_(0x0045B95C, int32_t)
#define JoyThrottle             VAR_U_(0x0045B970, int32_t)
#define JoyHat                  VAR_U_(0x0045B9A0, int32_t)
#define JoyFire                 VAR_U_(0x0045B990, int32_t)
#define Conflict                ARRAY_(0x0045EEC0, int32_t, [13])
#define HiRes                   VAR_I_(0x00459F64, int32_t, 0)
#define GameHiRes               VAR_I_(0x00459F60, int32_t, 0)
#define ScreenSizer             VAR_I_(0x00453558, double, 1.0)
#define GameSizer               VAR_I_(0x00453560, double, 1.0)
#define Effects                 VAR_U_(0x0045EE70, FX_INFO*)
#define NextItemFree            VAR_U_(0x0045EE76, int16_t)
#define NextItemActive          VAR_U_(0x0045EE78, int16_t)
#define NextFxFree              VAR_U_(0x0045EE74, int16_t)
#define NextFxActive            VAR_U_(0x0045EE7A, int16_t)
#define BaddieSlots             VAR_U_(0x0045ED64, CREATURE_INFO*)
#define SlotsUsed               VAR_U_(0x0045A1F8, int32_t)
#define NumberBoxes             VAR_U_(0x00462DA0, int32_t)
#define Boxes                   VAR_U_(0x00462D9C, BOX_INFO*)
#define OverlayFlag             VAR_U_(0x004546B4, int32_t)
#define HealthBarTimer          VAR_U_(0x0045A0E4, int32_t)
#define OldGameTimer            VAR_U_(0x0045A028, int32_t)
#define OldHitPoints            VAR_U_(0x0045A02C, int32_t)
#define PhdLeft                 VAR_U_(0x00695190, int32_t)
#define PhdBottom               VAR_U_(0x00695188, int32_t)
#define PhdRight                VAR_U_(0x006E80E0, int32_t)
#define PhdTop                  VAR_U_(0x0068D380, int32_t)
#define PhdWinWidth             VAR_U_(0x006CADD4, int32_t)
#define PhdWinHeight            VAR_U_(0x0068F3A8, int32_t)
#define PhdSpriteInfo           ARRAY_(0x0068D3A0, PHDSPRITESTRUCT, [MAX_SPRITES_PAGE][MAX_SPRITES])
#define PhdTextInfo             ARRAY_(0x006CADE0, PHDTEXTURESTRUCT, [MAX_TEXTURES])
#define LsDivider               VAR_U_(0x006D7604, int32_t)
#define AmmoText                VAR_U_(0x0045A030, TEXTSTRING*)
#define Rand1                   VAR_I_(0x00453CC0, int32_t, 0xD371F947)
#define Rand2                   VAR_I_(0x00453CC4, int32_t, 0xD371F947)
#define ValidLevels             ARRAY_(0x00453C80, int16_t, [])
#define FrameCount              VAR_I_(0x00459F58, int32_t, 0)
#define AnimationRate           VAR_I_(0x004534E0, int32_t, 0x8000)
#define InventoryExtraData      ARRAY_(0x0045A080, int32_t, [8])
#define LevelComplete           VAR_U_(0x0045A014, int32_t)
#define CDTrack                 VAR_I_(0x004534DC, int16_t, -1)
#define CDTrackLooped           VAR_I_(0x0045B97C, int16_t, -1)
#define CDLoop                  VAR_U_(0x0045B94C, int32_t)
#define CDNumTracks             VAR_U_(0x0045B964, int32_t)
#define Camera                  VAR_U_(0x00462D20, CAMERA_INFO)
#define CameraUnderwater        VAR_U_(0x00462BEC, int32_t)
#define PhdMatrixPtr            VAR_U_(0x006CAD14, PHD_MATRIX*)
#define Anims                   VAR_U_(0x00462574, ANIM_STRUCT*)
#define AnimChanges             VAR_U_(0x00462BD8, ANIM_CHANGE_STRUCT*)
#define AnimRanges              VAR_U_(0x00462578, ANIM_RANGE_STRUCT*)
#define AnimCommands            VAR_U_(0x0046257C, int16_t*)
#define AnimBones               VAR_U_(0x00462648, int32_t*)
#define AnimFrames              VAR_U_(0x00461F30, int16_t*)
#define FlipTimer               VAR_I_(0x00459F54, int32_t, 0)
#define FlipEffect              VAR_I_(0x004534E4, int32_t, -1)
#define FlipStatus              VAR_U_(0x00462CA0, int32_t)
#define GroundZone              ARRAY_(0x00462D88, int16_t*, [2])
#define GroundZone2             ARRAY_(0x00462D80, int16_t*, [2])
#define FlyZone                 ARRAY_(0x00462D90, int16_t*, [2])
#define Overlap                 VAR_U_(0x00462D98, uint16_t*)
#define ModeLock                VAR_I_(0x00459F70, int32_t, 0)
#define IsHardwareRenderer      VAR_U_(0x00463610, int32_t)
#define IConfig                 VAR_U_(0x0045A23C, int32_t)
#define AppSettings             VAR_U_(0x0045A240, uint32_t)
#define Quality                 VAR_I_(0x00453030, int32_t, 0x3000000)
#define WibbleTable             ARRAY_(0x006E8060, int32_t, [WIBBLE_SIZE])
#define ShadeTable              ARRAY_(0x006D4E00, int32_t, [WIBBLE_SIZE])
#define RandTable               ARRAY_(0x006CAD20, int32_t, [WIBBLE_SIZE])
#define SoundIsActive           VAR_I_(0x00456688, int32_t, 1)
#define Layout                  ARRAY_(0x00454A08, int16_t, [2][13])
#define CtrlTextA               ARRAY_(0x0045A248, TEXTSTRING*, [13])
#define CtrlTextB               ARRAY_(0x0045A280, TEXTSTRING*, [13])
#define ControlText             ARRAY_(0x0045A2F8, TEXTSTRING*, [2])
#define ScanCodeNames           ARRAY_(0x00454A40, char*, [])
#define OptionMusicVolume       VAR_I_(0x00456334, int32_t, 255)
#define OptionSoundFXVolume     VAR_I_(0x00456330, int32_t, 165)
#define OptionGammaLevel        VAR_U_(0x0045A0A0, int16_t)
#define CDFlags                 ARRAY_(0x00462C20, int16_t, [MAX_CD_TRACKS])
#define FlipMapTable            ARRAY_(0x00462CC0, int32_t, [MAX_FLIP_MAPS])
#define Cine                    VAR_U_(0x00462CF4, int16_t*)
#define CineFrame               VAR_U_(0x00462D14, int16_t)
#define CinematicAnimationRate  VAR_I_(0x004534D8, int32_t, 0x8000)
#define CinematicFrameCount     VAR_I_(0x00459F40, int32_t, 0)
#define CinematicLevel          VAR_U_(0x00462D12, int16_t)
#define CinematicPosition       VAR_U_(0x00462D00, PHD_3DPOS)
#define DumpX                   VAR_I_(0x004546E0, int16_t, 0)
#define DumpY                   VAR_I_(0x004546E2, int16_t, 0)
#define DumpWidth               VAR_I_(0x004546E4, int16_t, 0)
#define DumpHeight              VAR_I_(0x004546E6, int16_t, 0)
#define TriggerIndex            VAR_U_(0x00462CE8, int16_t*)
#define Ticks                   VAR_U_(0x0045A318, int32_t)
#define IMRate                  VAR_U_(0x00462BE0, int32_t)
#define IMFrac                  VAR_U_(0x00462570, int32_t)
#define IMMatrixPtr             VAR_U_(0x00462BE4, PHD_MATRIX*)
#define IMMatrixStack           ARRAY_(0x00461F40, PHD_MATRIX, [32])
#define MatrixStack             VAR_U_(0x006D4E80, PHD_MATRIX)
#define InterpolatedBounds      ARRAY_(0x00462BF0, int16_t, [6])
#define W2VMatrix               VAR_U_(0x006CADA0, PHD_MATRIX)
#define DoorVBuf                ARRAY_(0x00462540, DOOR_VBUF, [4])
#define RoomsToDraw             ARRAY_(0x00462580, int16_t, [MAX_ROOMS_TO_DRAW])
#define RoomsToDrawNum          VAR_U_(0x00461F38, int32_t)
#define Weapons                 ARRAY_(0x004563A8, WEAPON_INFO, [NUM_WEAPONS])
#define TitleLoaded             VAR_U_(0x0045A324, int32_t)
#define DemoPtr                 VAR_U_(0x00462BFC, uint32_t*)
#define DemoCount               VAR_U_(0x00462C00, int32_t)
#define ChunkyFlag              VAR_I_(0x00459F44, int32_t, 0)
#define HeightType              VAR_I_(0x00459F48, int32_t, 0)
#define InventoryChosen         VAR_I_(0x00456328, int16_t, -1)
#define NumberSoundEffects      VAR_U_(0x0045F1C4, int32_t)
#define SoundEffectsTable       VAR_U_(0x0045F1C8, OBJECT_VECTOR*)
#define DepthQTable             ARRAY_(0x006D5600, uint8_t, [32][256])
#define GouraudTable            ARRAY_(0x0068B380, uint8_t, [256][32])
#define AnimTextureRanges       VAR_U_(0x0045E640, int16_t*)
#define NumCineFrames           VAR_U_(0x00462CF0, int16_t)
#define Cine                    VAR_U_(0x00462CF4, int16_t*)
#define CDDrive                 VAR_U_(0x0045A010, char)
#define GamePalette             ARRAY_(0x0045E660, uint8_t, [256 * 3])
#define WaterPalette            ARRAY_(0x0045E33D, uint8_t, [256 * 3])
#define TexturePagePtrs         ARRAY_(0x006E7FC0, int8_t*, [MAX_TEXTPAGES])
#define NumberCameras           VAR_U_(0x0045A314, int32_t)
#define SavedGamesCount         VAR_U_(0x0045F1B4, int32_t)
#define SaveCounter             VAR_U_(0x0045A018, int32_t)
#define InvKeysCurrent          VAR_I_(0x0045A048, int16_t, 0)
#define InvKeysList             ARRAY_(0x00455FA8, INVENTORY_ITEM*, [23])
#define InvKeysObjects          VAR_I_(0x0045A044, int16_t, 1)
#define InvKeysQtys             ARRAY_(0x00455F78, int16_t, [])
#define InvMainCurrent          VAR_U_(0x0045A040, int16_t)
#define InvMainList             ARRAY_(0x00455F18, INVENTORY_ITEM*, [23])
#define InvMainObjects          VAR_I_(0x00455EE0, int16_t, 1)
#define InvMainQtys             ARRAY_(0x00455EE8, int16_t, [])
#define InvOptionCurrent        VAR_U_(0x0045A04C, int16_t)
#define InvOptionList           ARRAY_(0x00456008, INVENTORY_ITEM*, [5])
#define InvOptionObjects        VAR_I_(0x00456004, int16_t, 5)
#define InvDownArrow1           VAR_U_(0x0045A064, TEXTSTRING*)
#define InvDownArrow2           VAR_U_(0x0045A068, TEXTSTRING*)
#define InvItemText             ARRAY_(0x0045A050, TEXTSTRING*, [2])
#define InvRingText             VAR_U_(0x0045A058, TEXTSTRING*)
#define InvUpArrow1             VAR_U_(0x0045A05C, TEXTSTRING*)
#define InvUpArrow2             VAR_U_(0x0045A060, TEXTSTRING*)
#define InventoryMode           VAR_I_(0x0045632C, int16_t, INV_TITLE_MODE)
#define InventoryDisplaying     VAR_U_(0x0045A078, int16_t)
#define InvColours              ARRAY_(0x0045EE80, int16_t, [IC_NUMBER_OF])
#define CompassStatus           VAR_U_(0x0045A0A4, int16_t)
#define CompassSpeed            VAR_U_(0x0045A0A8, int16_t)
#define CompassNeedle           VAR_U_(0x0045A0AC, int16_t)
#define NoInputCount            VAR_I_(0x00459F4C, int32_t, 0)
#define IDelay                  VAR_U_(0x0045A0B0, int32_t)
#define IDCount                 VAR_U_(0x0045A0B4, int32_t)
#define Item_Data               VAR_U_(0x0045A0B8, int16_t)
#define InvNFrames              VAR_U_(0x004550A0, int32_t)
#define LsAdder                 VAR_U_(0x0068F3A0, int32_t)
#define FadeValue               VAR_I_(0x00453568, int32_t, 0x100000)
#define FadeLimit               VAR_I_(0x0045356C, int32_t, 0x100000)
#define FadeAdder               VAR_I_(0x00453570, int32_t, 0x8000)
#define TombHWND                VAR_U_(0x00463600, uint32_t)
#define FMVPaths                ARRAY_(0x00453AC0, char*, [])

#define InvItemCompass          VAR_U_(0x00455760, INVENTORY_ITEM)
#define InvItemMedi             VAR_U_(0x004559E0, INVENTORY_ITEM)
#define InvItemBigMedi          VAR_U_(0x00455A20, INVENTORY_ITEM)
#define InvItemLeadBar          VAR_U_(0x00455A60, INVENTORY_ITEM)
#define InvItemPickup1          VAR_U_(0x00455AA0, INVENTORY_ITEM)
#define InvItemPickup2          VAR_U_(0x00455AE0, INVENTORY_ITEM)
#define InvItemScion            VAR_U_(0x00455B20, INVENTORY_ITEM)
#define InvItemPuzzle1          VAR_U_(0x00455B60, INVENTORY_ITEM)
#define InvItemPuzzle2          VAR_U_(0x00455BA0, INVENTORY_ITEM)
#define InvItemPuzzle3          VAR_U_(0x00455BE0, INVENTORY_ITEM)
#define InvItemPuzzle4          VAR_U_(0x00455C20, INVENTORY_ITEM)
#define InvItemKey1             VAR_U_(0x00455C60, INVENTORY_ITEM)
#define InvItemKey2             VAR_U_(0x00455CA0, INVENTORY_ITEM)
#define InvItemKey3             VAR_U_(0x00455CE0, INVENTORY_ITEM)
#define InvItemKey4             VAR_U_(0x00455D20, INVENTORY_ITEM)
#define InvItemPistols          VAR_U_(0x004557A0, INVENTORY_ITEM)
#define InvItemShotgun          VAR_U_(0x004557E0, INVENTORY_ITEM)
#define InvItemMagnum           VAR_U_(0x00455820, INVENTORY_ITEM)
#define InvItemUzi              VAR_U_(0x00455860, INVENTORY_ITEM)
#define InvItemGrenade          VAR_U_(0x004559A0, INVENTORY_ITEM)
#define InvItemPistolAmmo       VAR_U_(0x004558A0, INVENTORY_ITEM)
#define InvItemShotgunAmmo      VAR_U_(0x004558E0, INVENTORY_ITEM)
#define InvItemMagnumAmmo       VAR_U_(0x00455920, INVENTORY_ITEM)
#define InvItemUziAmmo          VAR_U_(0x00455960, INVENTORY_ITEM)
#define InvItemGame             VAR_U_(0x00455D60, INVENTORY_ITEM)
#define InvItemDetails          VAR_U_(0x00455DA0, INVENTORY_ITEM)
#define InvItemSound            VAR_U_(0x00455DE0, INVENTORY_ITEM)
#define InvItemControls         VAR_U_(0x00455E20, INVENTORY_ITEM)
#define InvItemGamma            VAR_U_(0x00455E60, INVENTORY_ITEM)
#define InvItemLarasHome        VAR_U_(0x00455EA0, INVENTORY_ITEM)
#define InvSprGammaLevel        ARRAY_(0x00455218, INVENTORY_SPRITE, [10])
#define InvSprGammaList         ARRAY_(0x004552F8, INVENTORY_SPRITE*, [])
#define ReqBgndMoreUp           VAR_U_(0x004550A8, SG_COL*)
#define ReqBgndMoreDown         VAR_U_(0x004550C8, SG_COL*)
#define ReqBgndGour1            VAR_U_(0x004550E8, SG_COL*)
#define ReqBgndGour2            VAR_U_(0x00455108, SG_COL*)
#define ReqMainGour1            VAR_U_(0x00455120, SG_COL*)
#define ReqMainGour2            VAR_U_(0x00455140, SG_COL*)
#define ReqUnselGour1           VAR_U_(0x00455190, SG_COL*)
#define ReqUnselGour2           VAR_U_(0x00455178, SG_COL*)
// clang-format on

extern void (*EffectRoutines[])(ITEM_INFO *item);
extern SAVEGAME_INFO SaveGame;
extern int32_t DemoLevel;
extern char *UserSettingsPath;

extern GameFlow GF;

extern int32_t MeshCount;
extern int32_t MeshPtrCount;
extern int32_t AnimCount;
extern int32_t AnimChangeCount;
extern int32_t AnimRangeCount;
extern int32_t AnimCommandCount;
extern int32_t AnimBoneCount;
extern int32_t AnimFrameCount;
extern int32_t ObjectCount;
extern int32_t StaticCount;
extern int32_t TextureCount;
extern int32_t FloorDataSize;
extern int32_t TexturePageCount;
extern int32_t AnimTextureRangeCount;
extern int32_t SpriteInfoCount;
extern int32_t SpriteCount;
extern int32_t OverlapCount;

extern REQUEST_INFO LoadSaveGameRequester;
extern REQUEST_INFO NewGameRequester;

extern int16_t StoredLaraHealth;
extern int16_t BarOffsetY[6];

#endif
