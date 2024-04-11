#include "raylib.h"
#include "./define.h"
#include <stdlib.h>

typedef struct Fruit
{
    Vector2 position;
    bool active;
} Fruit;

void PlaceFruit(Fruit *fruit, int screenWidth, int screenHeight);