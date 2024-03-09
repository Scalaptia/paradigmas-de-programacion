#include "raylib.h"
#include "./define.h"
#include <stdlib.h>

typedef struct SnakeBody
{
    Vector2 position;
    Vector2 direction;
    Color color;
    struct SnakeBody *sig;
    struct SnakeBody *ant;
} SnakeBody;

typedef struct Snake
{
    int speed;
    int length;
    Vector2 size;
    SnakeBody *body;
} Snake;

void InitSnake(Snake *snake, Vector2 offset);
void AddLength(Snake *snake, int length);