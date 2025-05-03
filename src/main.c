#define CLAY_IMPLEMENTATION
#include <stdio.h>
#include "../backend/clay_renderer_raylib.c"
#include "defines.h"
#include "../include/greed/g_logger.h"
#include "../include/raylib/raylib.h"

// Replace with my greed log library
void HandleClayErrors(Clay_ErrorData errData)
{
  g_log_error(errData.errorText.chars);
}

const i32 SCREEN_WIDTH = 1024;
const i32 SCREEN_HEIGHT = 768;

const char *VINNY = "EXP TRACKER";

int main(void)
{
  Clay_Raylib_Initialize(SCREEN_WIDTH, SCREEN_HEIGHT, VINNY, FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);

  uint64_t clayRequiredMemory = Clay_MinMemorySize();
  Clay_Arena clayArena = Clay_CreateArenaWithCapacityAndMemory(clayRequiredMemory, malloc(clayRequiredMemory));

  Clay_Initialize(clayArena, (Clay_Dimensions){.width = GetScreenWidth(), .height = GetScreenHeight()}, (Clay_ErrorHandler){HandleClayErrors});

  while (!WindowShouldClose())
  {
    Clay_SetLayoutDimensions((Clay_Dimensions){
        .width = GetScreenWidth(),
        .height = GetScreenHeight()});

    Vector2 mousePos = GetMousePosition();
    Vector2 scrollDelta = GetMouseWheelMoveV();

    Clay_SetPointerState((Clay_Vector2){mousePos.x, mousePos.y}, IsMouseButtonDown(0));

    Clay_UpdateScrollContainers(true, (Clay_Vector2){scrollDelta.x, scrollDelta.y}, GetFrameTime());

    BeginDrawing();
    ClearBackground(RED);
    EndDrawing();
  }

  return 0;
}