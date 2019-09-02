
/**
 * An enumerated type to keep traxk of a cell's
 * status, dead or alive
 */
typedef enum {
  DEAD,
  ALIVE
} Status;

/**
 * A structure to keep track of a 2-dimensional
 * Euclidean coordinate
 */
typedef struct {
  int x;
  int y;
} Coordinate;

/**
 * Prints the game board to the standard output
 */
void displayBoard(Status** gameBoard, int size);

/**
 * Computes the next iteration of the game board
 */
Status** calculateNextIteration(Status ** gameBoard, int size);

/**
 * Computes what the new status of the given cell should be.
 */
Status getNewCellStatus(Status** gameBoard, Coordinate cell, int size);

/**
 * Creates a new empty game board with all cells in a
 * DEAD state
 */
Status** createGameBoard(int size);

/**
 * Makes a copy of the game board (or a 2D array of bools/ints)
 */
Status** copyGameBoard(Status** gameBoard, int size);

/**
 * Gets the number of living neighbors for a particular cell in the board.
 * Since it's possible that the cell is on an edge, we need to make sure that
 * we don't try to access something outside the bounds of the board.
 */
int getNumLivingNeighbors(Status** gameBoard, Coordinate cell, int size);
