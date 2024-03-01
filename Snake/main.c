#include <ncurses.h>
#include <stdlib.h>

typedef struct Snake
{
    int x;
    int y;
    struct Snake *next;
} snake_t;

int main()
{
    /* Inicializar juego */
    snake_t *snake = malloc(sizeof(snake_t));
    initscr();

    /* Dibujar snake en el centro de la pantalla*/
    snake->x = COLS / 2;
    snake->y = LINES / 2;
    snake->next = NULL;
    mvaddch(snake->y, snake->x, 'o');
    refresh();

    /* Esperar input y cerrar programa */
    getch();
    endwin();

    return 0;
}