#include "../headers/snake.h"

void InitSnake(Snake *snake, Vector2 *snakePosition, Vector2 offset)
{
    snake->speed = 15;
    snake->length = 5;

    for (int i = 0; i < MAX_LENGTH; i++)
    {
        snake[i].position = (Vector2){offset.x / 2, offset.y / 2};
        snake[i].size = (Vector2){SQUARE_SIZE, SQUARE_SIZE};
        snake[i].direction = (Vector2){SQUARE_SIZE, 0};

        if (i == 0)
            snake[i].color = DARKGREEN;
        else
            snake[i].color = GREEN;
    }

    for (int i = 0; i < MAX_LENGTH; i++)
    {
        snakePosition[i] = (Vector2){0.0f, 0.0f};
    }
}