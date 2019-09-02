#include <unistd.h>
#include <ncurses.h>

#include "gameUtils.h"

/**
 * Place a beacon at the given cell
 */
void placeBeacon(Status** gameBoard, Coordinate cell);

/**
 * Place a toad at the given cell
 */
void placeToad(Status** gameBoard, Coordinate cell);

/**
 * Place a glider at the given cell
 */
void placeGlider(Status** gameBoard, Coordinate cell);

int main(int argc, char* argv[]) {
  const int size = 50;
  int ticksPerSec = 3;
  Status** board = NULL;
  createGameBoard(size);
  Coordinate cell;

  // Initializes the board to have some living cells
  cell.x = 0;
  cell.y = 0;
  placeBeacons(board, cell);

  cell.x = 10;
  cell.y = 5;
  placeToad(board, cell);

  cell.x = 15;
  cell.y = 15;
  placeGlider(board, cell);

  // Initialize Ncurses Screen
  initscr();

  while (true) {
    clear();
    refresh();
    displayBoard(board, size, 5);
    refresh();
    calculateNextIteration(board, size);
    usleep(1000000 / ticksPerSec);
  }

  // Close Ncurses Screen
  endwin();

  return 0;
}

void placeBeacon(Status** gameBoard, Coordinate cell) {
  gameBoard[cell.x][cell.y] = ALIVE;
  gameBoard[cell.x + 1][cell.y] = ALIVE;
  gameBoard[cell.x][cell.y + 1] = ALIVE;

  gameBoard[cell.x + 3][cell.y + 3] = ALIVE;
  gameBoard[cell.x + 3][cell.y + 2] = ALIVE;
  gameBoard[cell.x + 2][cell.y + 3] = ALIVE;
}

void placeToad(Status** gameBoard, Coordinate cell) {
  gameBoard[cell.x + 1][cell.y] = ALIVE;
  gameBoard[cell.x + 2][cell.y] = ALIVE;
  gameBoard[cell.x + 3][cell.y] = ALIVE;

  gameBoard[cell.x][cell.y + 1] = ALIVE;
  gameBoard[cell.x + 1][cell.y + 1] = ALIVE;
  gameBoard[cell.x + 2][cell.y + 1] = ALIVE;
}

void placeGlider(Status** gameBoard, Coordinate cell) {
  gameBoard[cell.x][cell.y + 1] = ALIVE;
  gameBoard[cell.x + 1][cell.y + 2] = ALIVE;
  gameBoard[cell.x + 2][cell.y + 2] = ALIVE;
  gameBoard[cell.x + 2][cell.y + 1] = ALIVE;
  gameBoard[cell.x + 2][cell.y] = ALIVE;
}
