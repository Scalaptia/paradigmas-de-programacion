#include "../headers/menu.h"

void InitMenu(Menu *menu, int maxOptions)
{
    menu->option = 0;
    menu->maxOptions = maxOptions;
}

void DrawMenu(Menu *menu, char *options[], int screenWidth, int screenHeight, Texture2D *texture)
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(*texture, 0, 0, WHITE);

    DrawText("Snake", screenWidth / 2 - MeasureText("Snake", 54) / 2, screenHeight / 2 - 200, 54, WHITE);

    for (int i = 0; i < menu->maxOptions; i++)
    {
        if (i == menu->option)
        {
            DrawText(options[i], screenWidth / 2 - MeasureText(options[i], 30) / 2, screenHeight / 2 - 25 + 50 * i, 30, RED);
        }
        else
        {
            DrawText(options[i], screenWidth / 2 - MeasureText(options[i], 30) / 2, screenHeight / 2 - 25 + 50 * i, 30, WHITE);
        }
    }
    EndDrawing();
}

void UpdateMenu(Menu *menu, char *options[], int screenWidth, int screenHeight, bool *menuActive)
{
    if (IsKeyPressed(KEY_S))
    {
        menu->option++;
        if (menu->option > menu->maxOptions - 1)
        {
            menu->option = 0;
        }
    }
    else if (IsKeyPressed(KEY_W))
    {
        menu->option--;
        if (menu->option < 0)
        {
            menu->option = menu->maxOptions - 1;
        }
    }

    if (IsKeyPressed(KEY_ENTER))
    {
        if (menu->option == 0)
        {
            *menuActive = false;
        }
        else if (menu->option == 1)
        {
            CloseWindow();
        }
    }
}