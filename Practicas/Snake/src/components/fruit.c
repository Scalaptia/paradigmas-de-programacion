#include "../headers/fruit.h"

void PlaceFruit(Fruit *fruit, int screenWidth, int screenHeight)
{
    fruit->position = (Vector2){GetRandomValue(0, screenWidth / SQUARE_SIZE - 1) * SQUARE_SIZE, GetRandomValue(0, screenHeight / SQUARE_SIZE - 1) * SQUARE_SIZE};
    fruit->active = true;
}