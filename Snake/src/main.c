#include "raylib.h"
#include "./headers/snake.h"
#include "./headers/define.h"
#include "./headers/fruit.h"

const int screenWidth = 800;
const int screenHeight = 600;

int framesCounter = 0;
bool gameOver = false;
bool allowMove = false;

Snake snake;
Fruit fruit;

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
    InitSnake(&snake, (Vector2){0, 0});
    PlaceFruit(&fruit, screenWidth, screenHeight);
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

            // Verificar colisión con los bordes
            if (snake.body->position.x >= screenWidth || snake.body->position.x < 0 || snake.body->position.y >= screenHeight || snake.body->position.y < 0)
            {
                gameOver = true;
            }

            // Verificar colisión con el cuerpo
            SnakeBody *current = snake.body->sig;
            while (current != NULL)
            {
                if (CheckCollisionRecs((Rectangle){snake.body->position.x, snake.body->position.y, snake.size.x, snake.size.y}, (Rectangle){current->position.x, current->position.y, snake.size.x, snake.size.y}))
                {
                    gameOver = true;
                }
                current = current->sig;
            }

            // Verificar colisión con la fruta
            if (CheckCollisionRecs((Rectangle){snake.body->position.x, snake.body->position.y, snake.size.x, snake.size.y}, (Rectangle){fruit.position.x, fruit.position.y, snake.size.x, snake.size.y}))
            {
                AddLength(&snake, 1);
                PlaceFruit(&fruit, screenWidth, screenHeight);
            }

            // Mover el resto del cuerpo
            current = snake.body->sig;
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
        for (int i = 0; i < GetScreenWidth(); i += SQUARE_SIZE)
        {
            for (int j = 0; j < GetScreenHeight(); j += SQUARE_SIZE)
            {
                DrawRectangle(i, j, SQUARE_SIZE, SQUARE_SIZE, (i + j) % (SQUARE_SIZE * 2) == 0 ? WHITE : LIGHTGRAY);
            }
        }

        // Pintar serpiente
        SnakeBody *current = snake.body;
        while (current != NULL)
        {
            DrawRectangleV(current->position, snake.size, current->color);
            current = current->sig;
        }

        // Pintar fruta
        if (fruit.active)
        {
            DrawRectangleV(fruit.position, snake.size, RED);
        }
    }
    else
        DrawText("Presiona ENTER para reiniciar", GetScreenWidth() / 2 - MeasureText("Presiona ENTER para reiniciar", 40) / 2, GetScreenHeight() / 2 - 50, 40, BLACK);

    EndDrawing();
}
