#include "raylib.h"
#include "./define.h"

typedef struct Snake
{
    Vector2 position;
    Vector2 size;
    Vector2 direction;
    int speed;
    int length;
    Color color;
} Snake;

void InitSnake(Snake *snake, Vector2 *snakePosition, Vector2 offset);