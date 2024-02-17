#include <iostream>
#include <ncurses.h>
#include <unistd.h> // for usleep

using namespace std;

int main() {
    initscr();
    noecho();
    curs_set(FALSE);

    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);

    int birdY = maxY / 2;
    int birdX = maxX / 4;

    int gravity = 1;
    int velocity = 0;
    int pipeX = maxX - 5;
    int gapY = maxY / 4;
    int gapHeight = 4;
    int score = 0;

    timeout(0);

    while (true) {
        clear();

        // Gravity and jump
        int ch = getch();
        if (ch == ' ')
            velocity = -2; // Jump

        velocity += gravity;
        birdY += velocity;

        // Draw bird
        mvprintw(birdY, birdX, "o");

        // Draw pipes
        mvprintw(0, pipeX, "====");
        mvprintw(gapY, pipeX, "    ");
        mvprintw(gapY + gapHeight, pipeX, "====");

        // Move pipes to the left
        pipeX--;

        // Check for collision with pipes
        if (birdX + 1 == pipeX && (birdY < gapY || birdY >= gapY + gapHeight)) {
            mvprintw(maxY / 2, maxX / 2 - 5, "Game Over!");
            refresh();
            usleep(2000000); // Sleep for 2 seconds
            break;
        }

        // Check for scoring
        if (birdX == pipeX)
            score++;

