#include "raylib.h"
#include "./define.h"
#include <stdlib.h>

typedef struct Menu
{
    int option;
    int maxOptions;
} Menu;

void InitMenu(Menu *menu, int maxOptions);
void DrawMenu(Menu *menu, char *options[], int screenWidth, int screenHeight, Texture2D *texture);
void UpdateMenu(Menu *menu, char *options[], int screenWidth, int screenHeight, bool *menuActive);