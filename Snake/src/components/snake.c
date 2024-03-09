#include "../headers/snake.h"

void InitSnake(Snake *snake, Vector2 offset)
{
    snake->speed = 15;
    snake->length = 1;
    snake->size = (Vector2){SQUARE_SIZE, SQUARE_SIZE};

    snake->body = malloc(sizeof(SnakeBody));
    snake->body->position = (Vector2){offset.x / 2, offset.y / 2};
    snake->body->direction = (Vector2){SQUARE_SIZE, 0};
    snake->body->color = DARKGREEN;
    snake->body->sig = NULL;
    snake->body->ant = NULL;
}

void AddLength(Snake *snake, int length)
{
    snake->length += length;
    SnakeBody *current = snake->body;

    // Mover al final de la serpiente
    while (current->sig != NULL)
    {
        current = current->sig;
    }

    // Agregar nuevo cuerpo
    for (int i = 0; i < length; i++)
    {
        current->sig = malloc(sizeof(SnakeBody));
        current->sig->position = current->position;
        current->sig->direction = current->direction;
        current->sig->color = GREEN;
        current->sig->sig = NULL;
        current->sig->ant = current;
        current = current->sig;
    }
}