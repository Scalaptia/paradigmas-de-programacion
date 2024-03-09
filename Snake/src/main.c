#include "raylib.h"
#include "./headers/snake.h"
#include "./headers/define.h"

const int screenWidth = 800;
const int screenHeight = 600;

int framesCounter = 0;
bool gameOver = false;
bool allowMove = false;

Snake snake;
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
    InitSnake(&snake, offset);
    AddLength(&snake, 106);
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
        if (IsKeyPressed(KEY_W) && (snake.body->direction.y == 0) && allowMove)
        {
            snake.body->direction = (Vector2){0, -SQUARE_SIZE};
            allowMove = false;
        }
        if (IsKeyPressed(KEY_S) && (snake.body->direction.y == 0) && allowMove)
        {
            snake.body->direction = (Vector2){0, SQUARE_SIZE};
            allowMove = false;
        }
        if (IsKeyPressed(KEY_A) && (snake.body->direction.x == 0) && allowMove)
        {
            snake.body->direction = (Vector2){-SQUARE_SIZE, 0};
            allowMove = false;
        }
        if (IsKeyPressed(KEY_D) && (snake.body->direction.x == 0) && allowMove)
        {
            snake.body->direction = (Vector2){SQUARE_SIZE, 0};
            allowMove = false;
        }

        // Actualizar posición de la serpiente a la velocidad actual
        if ((framesCounter % snake.speed) == 0)
        {
            Vector2 temp = snake.body->position; // Almacenar la posición actual
            Vector2 last;                        // Variable temporal para almacenar la última posición

            // Mover cabeza
            snake.body->position.x += snake.body->direction.x;
            snake.body->position.y += snake.body->direction.y;

            // Mover el resto del cuerpo
            SnakeBody *current = snake.body->sig;

            while (current != NULL)
            {
                last = current->position; // Almacenar posición actual
                current->position = temp; // Actualizar posición actual con la posición anterior

                temp = last;            // Actualizar posición anterior con la posición actual
                current = current->sig; // Mover al siguiente cuerpo
            }

            allowMove = true;
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
        SnakeBody *current = snake.body;
        while (current != NULL)
        {
            DrawRectangleV(current->position, snake.size, current->color);
            current = current->sig;
        }
    }
    else
        DrawText("Presiona ENTER para reiniciar", GetScreenWidth() / 2 - MeasureText("Presiona ENTER para reiniciar", 20) / 2, GetScreenHeight() / 2 - 50, 20, WHITE);

    EndDrawing();
}
