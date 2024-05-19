#include "../headers/fruit.h"

void PlaceFruit(Fruit *fruit)
{
    fruit->position = (Vector2){GetRandomValue(0, SCREEN_WIDTH / SQUARE_SIZE - 1) * SQUARE_SIZE, GetRandomValue(0, SCREEN_HEIGHT / SQUARE_SIZE - 1) * SQUARE_SIZE};
    fruit->active = true;
}