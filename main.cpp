#include <cstdlib>
#include <iostream>
#include <ostream>
#include <vector>

// Drawing the board
void drawSudoku(int grid[9][9]){
  std::cout << "-------------------------------------" << std::endl;
  
  for (int row = 0; row < 9; row++){ // For every row...
      std::cout << "|";
    for (int col = 0; col < 9; col++){ // ...and every column
      if (grid[row][col] == 0){
        std::cout << "  " << " |"; // Replace the 0's with blank spaces for easier readability
      } else std::cout << " " << grid[row][col] << " |"; // ...print its value
    }
      std::cout << std::endl;
      std::cout << "-------------------------------------" << std::endl;
  }
}

// Check if the target number can be placed on the sudoku grid
bool canPlace(int board[9][9], int row, int col, int target){
  if (board[row][col] != 0){ return false; } // If there is a number already present at the location, return false
  
  bool found = true; // boolean to monitor contradictory 
  
  int gridx = (col / 3) * 3;
  int gridy = (row / 3) * 3;
  // Iterate through the board
  for (int i = 0; i < 9; i++){
    if(board[row][i] == target){ found = false; break; } // if the target is found within the row already, break
    if(board[i][col] == target){ found = false; break; } // if the target is found within the col already, break 

    if(board[gridy + i / 3][gridx + i % 3] == target){
      found = false; break;
    }
  }
  return found;
}

std::vector<int> findPlaces(int board[9][9], int row, int col){ // Find grid spaces where you can place numbers
  std::vector<int> rdyBoard = {}; // Create a board to return which placeable nodes

  for (int i = 1; i <= 9; i++){ // Check if you can place numers on the board
    if(canPlace(board, row, col, i))
      rdyBoard.push_back(i);
  }
  return rdyBoard;
}

void copyBoard(int board[9][9], int boardCopy[9][9]){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      boardCopy[i][j] = board[i][j];
    }
  }
}

void findNext(int board[9][9], int row, int col, int &nextRow, int &nextCol){
  int index = 9 * 9 + 1;
  
  for(int i = row * 9 + col + 1; i < 81; i++){
    if(board[i / 9][i % 9] == 0){
      index = i;
      break;
    }
  }
  nextRow = index / 9;
  nextCol = index % 9;
}

bool solveSudoku(int board[9][9], int row, int col){

  if(row > 8){ return true; } // Exit condition: once you have explored all rows, return true
  
  if(board[row][col] != 0){
    int nextRow, nextCol;
    findNext(board, row, col, nextRow, nextCol);
    return solveSudoku(board, nextRow, nextCol);
  }

  std::vector<int> firstBoard = findPlaces(board, row, col);
  if(firstBoard.size() == 0){ return false; }
  
  bool finished = false;
  for(int i = 0; i < firstBoard.size(); i++){
    int n = firstBoard[i];

    int boardCopy[9][9];
    copyBoard(board, boardCopy);
    boardCopy[row][col] = n;
    
    int nextRow = row, nextCol = col;
    findNext(boardCopy, row, col, nextRow, nextCol);
    if(solveSudoku(boardCopy, nextRow, nextCol)){
      copyBoard(boardCopy, board);
      finished = true;
      break;
    }
  }
  return finished;
}

int main(){
  // Generate the puzzle - used sudokuweb.org
  int board[9][9] = {
    {6,0,2,0,8,0,0,0,0},
    {0,0,0,7,6,2,9,0,0},
    {7,9,3,0,0,0,0,0,8},
    {0,0,0,0,3,9,6,7,0},
    {0,6,5,0,0,7,4,0,3},
    {9,3,0,4,5,0,1,0,2},
    {0,0,6,0,4,8,5,0,0},
    {4,5,9,3,7,0,0,2,0},
    {0,0,0,0,9,0,0,0,7},
  };
  
  // Iterate through the numbers to see if you can place them

  // Draw the grid 
  drawSudoku(board);
  solveSudoku(board, 0, 0);
  drawSudoku(board);
  return 0;
}
