#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <ncurses.h> // Biblioteca para controle de terminal

using namespace std;
int pontuacao;

// Direções possíveis
enum Direction { UP, DOWN, LEFT, RIGHT };

struct Point {
    int x, y;
};

class SnakeGame {
private:
    int width, height;
    bool gameOver;
    Direction dir;
    vector<Point> snake;
    Point food;
    int pontuacao;

public:
    SnakeGame(int w, int h) : width(w), height(h), gameOver(false), dir(RIGHT), pontuacao(0) {
        // Inicializa cobra no centro
        snake.push_back({w / 2, h / 2});
        spawnFood();
    }

    void spawnFood() {
        bool valid;
        do {
            valid = true;
            food.x = rand() % width;
            food.y = rand() % height;
            // Evita gerar comida em cima da cobra
            for (auto &s : snake) {
                if (s.x == food.x && s.y == food.y) {
                    valid = false;
                    break;
                }
            }
        } while (!valid);
    }

    void draw() {
        clear();
        // Desenha bordas
        for (int i = 0; i < width + 2; i++) mvprintw(0, i, "#");
        for (int i = 0; i < height + 2; i++) {
            mvprintw(i, 0, "#");
            mvprintw(i, width + 1, "#");
        }
        for (int i = 0; i < width + 2; i++) mvprintw(height + 1, i, "#");

        // Desenha comida
        mvprintw(food.y + 1, food.x + 1, "O");

        // Desenha cobra
        for (size_t i = 0; i < snake.size(); i++) {
            mvprintw(snake[i].y + 1, snake[i].x + 1, i == 0 ? "0" : "o");
        }

        // Mostra pontuação
        mvprintw(height + 3, 0, "Pontos: %d", pontuacao);
        refresh();
    }

    void input() {
        int ch = getch();
        switch (ch) {
            case 'w': if (dir != DOWN) dir = UP; break;
            case 's': if (dir != UP) dir = DOWN; break;
            case 'a': if (dir != RIGHT) dir = LEFT; break;
            case 'd': if (dir != LEFT) dir = RIGHT; break;
            case 'q': gameOver = true; break;
        }
    }

    void logic() {
        // Move corpo da cobra
        Point prev = snake[0];
        Point newHead = prev;

        switch (dir) {
            case UP:    newHead.y--; break;
            case DOWN:  newHead.y++; break;
            case LEFT:  newHead.x--; break;
            case RIGHT: newHead.x++; break;
        }

        // Colisão com parede
        if (newHead.x < 0 || newHead.x >= width || newHead.y < 0 || newHead.y >= height) {
            gameOver = true;
            return;
        }

        // Colisão com si mesma
        for (auto &s : snake) {
            if (s.x == newHead.x && s.y == newHead.y) {
                gameOver = true;
                return;
            }
        }

        // Comeu comida
        if (newHead.x == food.x && newHead.y == food.y) {
            snake.insert(snake.begin(), newHead);
            pontuacao += 10;
            spawnFood();
        } else {
            // Move a cobra
            snake.insert(snake.begin(), newHead);
            snake.pop_back();
        }
    }

    bool isGameOver() const {
        return gameOver;
    }
};

void SabrinaYukkiGomes(){
    srand(time(0));
    
    // Inicializa ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    SnakeGame game(20, 10);

    while (!game.isGameOver()) {
        game.draw();
        game.input();
        game.logic();
        napms(300); // Delay para controlar velocidade
    }

    // Fim do jogo
    clear();
    mvprintw(5, 5,"Fim de Jogo! Prime qualquer tecla");
    cout <<"Fim de Jogo! Tua pontuacao foi de: " << pontuacao;
    refresh();
    nodelay(stdscr, FALSE);
    getch();

    endwin(); // Finaliza ncurses
}