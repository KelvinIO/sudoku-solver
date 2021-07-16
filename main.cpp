#include <iostream>
#include <ostream>

void drawSudoku(int grid[9][9]){
  std::cout << "------------------" << std::endl;
  
  for (int row = 0; row < 9; row++){ // For every row...
      std::cout << "|";
    for (int col = 0; col < 9; col++){ // ...and every column
      std::cout << " " << grid[row][col] << " |"; // ...print its value
    }
      std::cout << std::endl;
  }

  std::cout << "------------------" << std::endl;
}

int main(){
  // Generate the puzzle
  int sudoku[9][9] = {
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
  };

  // Draw the grid 
  drawSudoku(sudoku);

  return 0;
}
