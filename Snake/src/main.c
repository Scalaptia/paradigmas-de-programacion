#include "raylib.h"
#include "./headers/snake.h"
#include "./headers/define.h"

const int screenWidth = 800;
const int screenHeight = 600;

int framesCounter = 0;
bool gameOver = false;
bool allowMove = false;

Snake snake[MAX_LENGTH] = {0};
Vector2 snakePosition[MAX_LENGTH] = {0};
const Vector2 offset = {screenWidth % SQUARE_SIZE, screenWidth % SQUARE_SIZE};

// Prototipos
void InitGame();
void UpdateGame();
void DrawGame();

// Main
int main(void)
{
    // Inicializar juego
    InitWindow(screenWidth, screenHeight, "snake");
    InitGame();
    SetTargetFPS(120);

    // Actualizar estado y dibujar juego
    while (!WindowShouldClose())
    {
        UpdateGame();
        DrawGame();
    }

    CloseWindow();

    return 0;
}

void InitGame()
{
    framesCounter = 0;
    gameOver = false;
    allowMove = false;
    InitSnake(snake, snakePosition, offset);
}

void UpdateGame()
{
    // Salir del juego
    if (IsKeyPressed(KEY_X))
    {
        gameOver = true;
    }

    if (!gameOver)
    {
        // Entrada de usuario

        // Cambiar dirección de la serpiente siempre y cuando no sea la dirección
        // opuesta y no haya cambiado de dirección en el mismo frame.
        if (IsKeyPressed(KEY_W) && (snake[0].direction.y == 0) && allowMove)
        {
            snake[0].direction = (Vector2){0, -SQUARE_SIZE};
            allowMove = false;
        }
        if (IsKeyPressed(KEY_S) && (snake[0].direction.y == 0) && allowMove)
        {
            snake[0].direction = (Vector2){0, SQUARE_SIZE};
            allowMove = false;
        }
        if (IsKeyPressed(KEY_A) && (snake[0].direction.x == 0) && allowMove)
        {
            snake[0].direction = (Vector2){-SQUARE_SIZE, 0};
            allowMove = false;
        }
        if (IsKeyPressed(KEY_D) && (snake[0].direction.x == 0) && allowMove)
        {
            snake[0].direction = (Vector2){SQUARE_SIZE, 0};
            allowMove = false;
        }

        // Guardar la posición de la serpiente
        for (int i = 0; i < snake->length; i++)
        {
            snakePosition[i] = snake[i].position;
        }

        // Actualizar posición de la serpiente a la velocidad actual
        if ((framesCounter % snake->speed) == 0)
        {
            for (int i = 0; i < snake->length; i++)
            {
                if (i == 0)
                {
                    snake[0].position.x += snake[0].direction.x;
                    snake[0].position.y += snake[0].direction.y;
                    allowMove = true;
                }
                else
                {
                    // Mover el nodo a la posición del nodo anterior
                    snake[i].position = snakePosition[i - 1];
                }
            }
        }

        framesCounter++;
    }
    else
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            InitGame();
            gameOver = false;
        }
    }
}

void DrawGame()
{
    BeginDrawing();

    if (!gameOver)
    {
        ClearBackground(BLACK);

        // Pintar matriz
        for (int i = 0; i < screenWidth / SQUARE_SIZE + 1; i++)
        {
            DrawLineV((Vector2){SQUARE_SIZE * i + offset.x / 2, offset.y / 2}, (Vector2){SQUARE_SIZE * i + offset.x / 2, screenHeight - offset.y / 2}, GRAY);
        }

        for (int i = 0; i < screenHeight / SQUARE_SIZE + 1; i++)
        {
            DrawLineV((Vector2){offset.x / 2, SQUARE_SIZE * i + offset.y / 2}, (Vector2){screenWidth - offset.x / 2, SQUARE_SIZE * i + offset.y / 2}, GRAY);
        }

        // Pintar serpiente
        for (int i = 0; i < snake->length; i++)
        {
            DrawRectangleV(snake[i].position, snake[i].size, snake[i].color);
        }
    }
    else
        DrawText("Presiona ENTER para reiniciar", GetScreenWidth() / 2 - MeasureText("Presiona ENTER para reiniciar", 20) / 2, GetScreenHeight() / 2 - 50, 20, WHITE);

    EndDrawing();
}
