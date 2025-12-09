#include "raylib.h"
#include <stdlib.h>

#define MAX_BUNNIES 1000000
#define MAX_BATCH_ELEMENTS 8192

typedef struct {
  Vector2 position;
  Vector2 speed;
  Color color;
} Bunny;

int main(void) {
  const int width = 800;
  const int height = 600;

  InitWindow(width, height, "bunny");

  Texture2D texBunny = LoadTexture(ASSET_PATH "bunny.png");

  Bunny *bunnies = (Bunny *)malloc(MAX_BUNNIES * sizeof(Bunny));

  int count = 0;

  SetTargetFPS(60);

  while (!WindowShouldClose()) {

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
      for (int i = 0; i < 100; ++i) {
        if (count < MAX_BUNNIES) {
          bunnies[count].position = GetMousePosition();
          bunnies[count].speed.x = (float)GetRandomValue(-250, 250) / 60.0f;
          bunnies[count].speed.y = (float)GetRandomValue(-250, 250) / 60.0f;
          bunnies[count].color =
              (Color){GetRandomValue(50, 240), GetRandomValue(80, 240),
                      GetRandomValue(100, 240), 255};

          count++;
        }
      }
    }

    for (int i = 0; i < count; ++i) {
      bunnies[i].position.x += bunnies[i].speed.x;
      bunnies[i].position.y += bunnies[i].speed.y;

      float bunnyCX = bunnies[i].position.x + (float)(texBunny.width / 2.0);
      float bunnyCY = bunnies[i].position.y + (float)(texBunny.height / 2.0);

      if (bunnyCX > GetScreenWidth() || bunnyCX < 0)
        bunnies[i].speed.x *= -1;

      if (bunnyCY > GetScreenHeight() || bunnyCY - 40 < 0)
        bunnies[i].speed.y *= -1;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);

    for (int i = 0; i < count; ++i) {
      DrawTexture(texBunny, (int)bunnies[i].position.x,
                  (int)bunnies[i].position.y, bunnies[i].color);
    }

    DrawRectangle(0, 0, width, 40, BLACK);
    DrawText(TextFormat("bunnies: %i", count), 120, 10, 20, GREEN);
    DrawText(TextFormat("draw calls: %i", 1 + count / MAX_BATCH_ELEMENTS), 320,
             10, 20, MAROON);

    DrawFPS(10, 10);

    EndDrawing();
  }

  free(bunnies);
  UnloadTexture(texBunny);
  CloseWindow();

  return 0;
}
