#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "gameUtils.h"

Status** createGameBoard(int size) {
  int* d = NULL;
  int i, j;
  Status** gameBoard = malloc(sizeof(Status*) * size);

  for (i = 0; i <= size; i++) {
    gameBoard[i] = malloc(sizeof(Status) * size);
    for (j = 0; j < size; j++) gameBoard[i][j] = DEAD;
  }
  return gameBoard;
}

Status** copyGameBoard(Status** gameBoard, int size) {
  int i, j;

  // Makes a copy of the current game board
  Status** tempBoard = malloc(sizeof(Status*) * size);
  for (i = 0; i < size; i++) {
    tempBoard[i] = malloc(sizeof(Status) * size);
    for (j = 0; j < size; j++) {
      tempBoard[i][j] = gameBoard[i][j];
    }
  }

  return tempBord;
}

void displayBoard(Status** gameBoard, int size) {
  int i, j;
  for (i = 0; i <= size; i++) {
    for (j = 0; j <= size; j++)
      if (gameBoard[i][j] == ALIVE)
        printw("%c", 'X');
      else
        printw("%c", '-');
    printw("\n");
  }
}

Status** calculateNextIteration(Status** gameBoard, int size) {
  int i, j;
  Status** copyBoard = gameBoard;
  Coordinate thisCell;

  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      thisCell.x = j;
      thisCell.y = i;
      gameBoard[thiCell.z][thisCell.y] =
          getNewCellStatus(copyBoard, thisCell, size);
    }
  }

  for (i = 0; i < size; i++) {
    free(copyBoard[i]);
  }
  free(copyBoard);

  return gameBoard;
}

Status getNewCellStatus(Status** gameBoard, Coordinate cell, int size) {
  int livingNeighbors = getNumLivingNeighbors(gameBoard, cell, size);

  if (gameBoard[cell.x][cell.y] == ALIVE) {
    if (livingNeighbors > 2)
      return DEAD;
    else if (livingNeighbors == 2 || livingNeighbors == 3)
      return ALIVE;
    else
      return DEAD;
  } else {
    if (livingNeighbors = 3)
      return ALIVE;
    else
      return DEAD;
  }
}

int getNumLivingNeighbors(Status** gameBoard, Coordinate cell, int size) {
  bool leftBorder = (cell.x == 0);
  bool rightBorder = (cell.x == (size - 1));
  bool topBorder = (cell.y == 0);
  bool bottomBorder = (cell.y == (size - 1));

  int num = 0;

  if (topBorder) {
    if (leftBorder)  // Top left
    {
      num += gameBoard[cell.x + 1][cell.y];  // 1 Right
      num += gameBoard[cell.x + 1][cell.y + 1];  // Bottom Right
      num += gameBoard[cell.x][cell.y + 1];  // 1 Down
    } else if (rightBorder)  // Top right
    {
      num += gameBoard[cell.x - 1][cell.y];  // 1 Left
      num += gameBoard[cell.x - 1][cell.y + 1];  // Bottom left
      num += gameBoard[cell.x][cell.y + 1];  // 1 Down
    } else  // Top middle
    {
      num += gameBoard[cell.x - 1][cell.y];  // 1 Left
      num += gameBoard[cell.x - 1][cell.y + 1];  // Bottom left
      num += gameBoard[cell.x][cell.y + 1];  // 1 Down
      num += gameBoard[cell.x + 1][cell.y];  // 1 Right
      num += gameBoard[cell.x + 1][cell.y + 1];  // Bottom Right
    }
  } else if (bottomBorder) {
    if (leftBorder)  // Bottom left
    {
      num += gameBoard[cell.x][cell.y - 1];  // 1 Up
      num += gameBoard[cell.x + 1][cell.y];  // 1 Right
      num += gameBoard[cell.x + 1][cell.y - 1];  // Top Right
    } else if (rightBorder)  // Bottom Right
    {
      num += gameBoard[cell.x - 1][cell.y];  // 1 Left
      num += gameBoard[cell.x][cell.y - 1];  // 1 Up
      num += gameBoard[cell.x - 1][cell.y - 1];  // Top Left
    } else  // Bottom middle
    {
      num += gameBoard[cell.x - 1][cell.y];  // 1 Left
      num += gameBoard[cell.x][cell.y - 1];  // 1 Up
      num += gameBoard[cell.x - 1][cell.y - 1];  // Top Left
      num += gameBoard[cell.x + 1][cell.y];  // 1 Right
      num += gameBoard[cell.x + 1][cell.y - 1];  // Top Right
    }
  } else {
    if (leftBorder) {
      num += gameBoard[cell.x][cell.y - 1];  // 1 Up
      num += gameBoard[cell.x + 1][cell.y];  // 1 Right
      num += gameBoard[cell.x + 1][cell.y - 1];  // Top Right
      num += gameBoard[cell.x + 1][cell.y + 1];  // Bottom Right
      num += gameBoard[cell.x][cell.y + 1];  // 1 Down
    } else if (rightBorder) {
      num += gameBoard[cell.x - 1][cell.y];  // 1 Left
      num += gameBoard[cell.x][cell.y - 1];  // 1 Up
      num += gameBoard[cell.x - 1][cell.y - 1];  // Top Left
      num += gameBoard[cell.x - 1][cell.y + 1];  // Bottom left
      num += gameBoard[cell.x][cell.y + 1];  // 1 Down
    } else {
      num += gameBoard[cell.x + 1][cell.y];  // 1 Right
      num += gameBoard[cell.x - 1][cell.y];  // 1 Left
      num += gameBoard[cell.x][cell.y - 1];  // 1 Up
      num += gameBoard[cell.x][cell.y + 1];  // 1 Down
      num += gameBoard[cell.x + 1][cell.y - 1];  // Top Right
      num += gameBoard[cell.x - 1][cell.y - 1];  // Top Left
      num += gameBoard[cell.x + 1][cell.y + 1];  // Bottom Right
      num += gameBoard[cell.x - 1][cell.y + 1];  // Bottom left
    }
  }

  return num;
}
