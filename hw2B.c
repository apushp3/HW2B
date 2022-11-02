
#include <stdio.h>

/*
 * TODO
 * func: rotate_right
 * desc:  populates 9x9 2D array dest so that it is
 *   the "90-degree clockwise/right" rotation of given
 *   9x9 2D array src.
 *
 *   Imagine turning a square photo 90 degrees clockwise.
 *
 *   Examples:
 *
 *     given file b1_rot.txt is the 90-degree right rotation
 *     of b1.txt
 *  
 */
void rotate_right(int src[9][9], int dest[9][9]) {

  for(int j = 0; j < 9; j++){

    int k = 0;
    for(int i = 8; i >= 0; i--){
      dest[j][k] = src[i][j];

      k = k + 1;
    }
  }

  printf(" The rotated matrix is \n");
  printf("\n");

  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      printf(" %d ", dest[i][j]);
    }
    printf("\n");
  }
}

/**
 * TODO
 * func: sudoku_checker
 * desc: takes a 9x9 matrix of integers and
 *   "checks" all 27 "entities":
 *     - 9 rows
 *     - 9 columns
 *     - 9 3x3 boxes
 *  return value:  Number of the 27 entities that
 *    are "ok".  Thus if the entire board is
 *    legal, 27 is returned.
 *
 *    NOT SIMPLY 0/1
 *
 * NOTE:  cannot assume that all entries in 2D array are
 *   in the range 1..9
 *
 */
int sudoku_checker(int board[9][9]) {
  int count = 0;
  int i = 0;

  /* checker for 3*3 boards */

  while(i < 9){
    int a[9] = {0,0,0,0,0,0,0,0,0};

    for(int k = i; k< i + 3; k++){
      for(int j = 0; j < 3; j++){
          if(a[board[k][j] - 1] > 0){
            continue;
        }
        else{
          a[board[k][j] - 1] = 1;
        }
      }
    }
    count = count + 1;
    for(int s = 0; s<9; s++){
      if(a[s] > 1 || a[s] == 0){
        count = count - 1;
        break;
      }
    }

    int b[9] = {0,0,0,0,0,0,0,0,0};
    for(int k = i; k< i + 3; k++){
      for(int j = 3; j < 6; j++){
      if(b[board[k][j] - 1] > 0){
        continue;
    }
    else{
      b[board[k][j] - 1] = 1;
      
    }
  }
  }

    count = count + 1;
    for(int s = 0; s<9; s++){
      if(b[s] > 1 || b[s] == 0){
        count = count - 1;
        break;
      }
    }

    int c[9] = {0,0,0,0,0,0,0,0,0};
    for(int k = i; k < i + 3; k++){
      for(int j = 6; j < 9; j++){
      if(c[board[k][j] - 1] > 0){
        continue;
    }
    else{
      c[board[k][j] - 1] = 1;
      
    }
    }
  }

    count = count + 1;
    for(int s = 0; s<9; s++){
      if(c[s] > 1 || c[s] == 0){
        count = count - 1;
        break;
      }
    }


  i = i + 3;
}



/* checker for 9 rows and 9 columns */

for(int i = 0; i < 9; i++){
  int d[9] = {0,0,0,0,0,0,0,0,0};
  for(int j = 0; j < 9; j++){
    if(d[board[i][j] - 1] > 0){
      continue;
    }
    else{
      d[board[i][j] - 1] = 1;
    }
  }

  count = count + 1;

  for(int k = 0; k < 9; k++){
    if(d[k] == 0){
      count = count - 1;
      break;
    }
  }

  int e[9] = {0,0,0,0,0,0,0,0,0};
  for(int j = 0; j < 9; j++){
    if(e[board[j][i] - 1] > 0){
      continue;
    }
    else{
      e[board[j][i] - 1] = 1;
    }
  }
  count = count + 1;

  for(int k = 0; k < 9; k++){
    if(e[k] == 0){
      count = count - 1;
      break;
    }
  }

}

printf(" The sudoku legal count %d", count);

return count;

}

/**
 * func:  disp_board
 * desc:  simple function to display a 9x9 sudoku board
 */
void disp_board(int board[9][9]) {
  int i, j;

  printf("\n");
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      if(j==2 || j==5)
        printf("%2d |", board[i][j]);
      else
        printf("%2d ", board[i][j]);
    }
    printf("\n");
    if(i==2 || i==5)
      printf("-----------------------------\n");
  }
  printf("\n");

}




/*
 * func: read_board
 * desc: utility function which attempts to open the
 *   file specified by the string filename and read
 *   81 integers from it to populate the 2D array
 *   board[][].
 *
 *   return value:  1 for success; 0 for failure
 */
int read_board(char *filename, int board[9][9]) {
  FILE *fp;
  int i, j;
  int x;

  fp = fopen(filename, "r");

  if(fp==NULL)
    return 0;   // failed to open file

  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      if(fscanf(fp, "%d", &x) != 1){
        fclose(fp);
        return 0;
      }
      else
        board[i][j] = x;
    }
  }
  return 1;
}


#ifndef FUNCS_ONLY

// your testing code down here...

int main(int argc, char *argv[]) {
  int b[9][9];

  // setup to take a file containing a board as a cmd-line
  //   argument.
  //
  // e.g. :    ./a.out b1.txt
  if(argc==2) {
    printf("reading board from file '%s'...\n", argv[1]);
    if(!read_board(argv[1], b)) {
      printf("reading board failed...goodbye\n");
      return 0;
    }
    else {
      printf("success\n");
    }

    disp_board(b);
    
  }
  else {
    printf("No filename specified...maybe we had different plans...\n");

  }
  return 0;
}

#endif

