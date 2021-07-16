#include <iostream>
#include <ostream>

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

int main(){
  // Generate the puzzle - used sudokuweb.org
  int sudoku[9][9] = {
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

  // Draw the grid 
  drawSudoku(sudoku);

  return 0;
}
