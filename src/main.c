#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <io.h>

typedef struct Cell Cell;
struct Cell {
    // bomb = -1
    int value;
    int isVisible;
    int isFlagged;
};

// struct Board {
//     int grid[][]
// }

Cell * createCell(int value) {
    Cell * cell;
    cell = malloc(sizeof(struct Cell));
    cell->value = value;
    cell->isVisible = 0;
    cell->isFlagged = 0;
    return cell;
}

// init

// end init

//input processing and validation

// end input 

//

// calculate

//end calculate

//process move
//end of process move

// output


// end output

int printGrid(Cell * grid, int x, int y) {
    wprintf(L"Current board\n");
    wprintf(L"  A B C D E\n");
    for(int i = 0; i<x; i++) {
        wprintf(L"%d", i);
        for(int j = 0; j<y; j++) {
            if (grid->isFlagged) {
                wprintf(L" ⚑");
            } else {
                wprintf(L" ⚑"); //✶ ⚑ ▧
            }
        }
        wprintf(L"\n");
    }
}



bool calculate (int x, int y, int size ,Cell ** grid){
    //mine
    if (grid[x][y].value == -1 )
    {
        grid[x][y].isVisible=1;
        return false;
    } else if (grid[x][y].value == 0)
    {   
        // set visible
        grid[x][y].isVisible=1;
        if (x==0) 
        {   
            // 0,0 >> 3 adjacent cells
            if (y==0){
                // cell 0,1
                if (grid[x][y+1].value==0 && grid[x][y+1].isVisible==0)
                {
                    calculate(x,y+1,size,grid);
                } else
                    grid[x][y+1].isVisible=1; 

                // cell 1,0
                if (grid[x+1][y].value==0 && grid[x+1][y].isVisible==0)
                {
                    calculate(x+1,y,size,grid);
                } else
                    grid[x+1][y].isVisible=1; 

                // cell 1,1
                if (grid[x+1][y+1].value==0 && grid[x+1][y+1].isVisible==0)
                {
                    calculate(x+1,y+1,size,grid);
                } else
                    grid[x+1][y+1].isVisible=1; 

            } else if (y==size -1)
            {
                // 0,n-1 >> 3 adjacent cells


                // cell 0,n-2
                if (grid[x][y-1].value==0 && grid[x][y-1].isVisible==0)
                {
                    calculate(x,y-1,size,grid);
                } else
                    grid[x][y-1].isVisible=1; 

                // cell 1,n-1
                if (grid[x+1][y].value==0 && grid[x+1][y].isVisible==0)
                {
                    calculate(x+1,y,size,grid);
                } else
                    grid[x+1][y].isVisible=1; 

                // cell 1,n-2
                if (grid[x+1][y-1].value==0 && grid[x+1][y-1].isVisible==0)
                {
                    calculate(x+1,y-1,size,grid);
                } else
                    grid[x+1][y-1].isVisible=1; 

            } else {
                //first line  >> 5 adjacent cell

                // left cell
                if (grid[x][y-1].value==0 && grid[x][y-1].isVisible==0)
                {
                    calculate(x,y-1,size,grid);
                } else
                    grid[x][y-1].isVisible=1; 

                // right cell
                if (grid[x][y+1].value==0 && grid[x][y+1].isVisible==0)
                {
                    calculate(x,y+1,size,grid);
                } else
                    grid[x][y+1].isVisible=1; 

                // bottom cell
                if (grid[x+1][y].value==0 && grid[x+1][y].isVisible==0)
                {
                    calculate(x+1,y,size,grid);
                } else
                    grid[x+1][y].isVisible=1; 

                // diagonal to the right cell
                if (grid[x+1][y+1].value==0 && grid[x+1][y+1].isVisible==0)
                {
                    calculate(x+1,y+1,size,grid);
                } else
                    grid[x+1][y+1].isVisible=1; 

                // diagonal to the left cell
                if (grid[x+1][y-1].value==0 && grid[x+1][y-1].isVisible==0)
                {
                    calculate(x+1,y-1,size,grid);
                } else
                    grid[x+1][y-1].isVisible=1; 
                
            }
            
            
        } else if (x== size -1)
        {
            if (y==0){
                // n,0 >> 3 adjacent 
                
                // cell n-1,1
                if (grid[x][y+1].value==0 && grid[x][y+1].isVisible==0)
                {
                    calculate(x,y+1,size,grid);
                } else
                    grid[x][y+1].isVisible=1; 

                // cell n-2,0
                if (grid[x-1][y].value==0 && grid[x-1][y].isVisible==0)
                {
                    calculate(x-1,y,size,grid);
                } else
                    grid[x-1][y].isVisible=1; 

                // cell n-2,1
                if (grid[x-1][y+1].value==0 && grid[x-1][y+1].isVisible==0)
                {
                    calculate(x-1,y+1,size,grid);
                } else
                    grid[x-1][y+1].isVisible=1; 

            } else if (y==size -1)
            {
                // n,n-1 >> 3 adjacent cells

                // cell n-1,n-2
                if (grid[x][y-1].value==0 && grid[x][y-1].isVisible==0)
                {
                    calculate(x,y-1,size,grid);
                } else
                    grid[x][y-1].isVisible=1; 

                // cell n-2,n-1
                if (grid[x-1][y].value==0 && grid[x-1][y].isVisible==0)
                {
                    calculate(x-1,y,size,grid);
                } else
                    grid[x-1][y].isVisible=1; 

                // cell n-2,n-2
                if (grid[x-1][y-1].value==0 && grid[x-1][y-1].isVisible==0)
                {
                    calculate(x-1,y-1,size,grid);
                } else
                    grid[x-1][y-1].isVisible=1; 


            } else {
                //last line  >> 5 adjacent cell


                // left cell
                if (grid[x][y-1].value==0 && grid[x][y-1].isVisible==0)
                {
                    calculate(x,y-1,size,grid);
                } else
                    grid[x][y-1].isVisible=1; 

                // right cell
                if (grid[x][y+1].value==0 && grid[x][y+1].isVisible==0)
                {
                    calculate(x,y+1,size,grid);
                } else
                    grid[x][y+1].isVisible=1; 

                // top cell
                if (grid[x-1][y].value==0 && grid[x-1][y].isVisible==0)
                {
                    calculate(x-1,y,size,grid);
                } else
                    grid[x-1][y].isVisible=1; 

                // diagonal to the right cell
                if (grid[x-1][y+1].value==0 && grid[x-1][y+1].isVisible==0)
                {
                    calculate(x-1,y+1,size,grid);
                } else
                    grid[x-1][y+1].isVisible=1; 

                // diagonal to the left cell
                if (grid[x-1][y-1].value==0 && grid[x-1][y-1].isVisible==0)
                {
                    calculate(x-1,y-1,size,grid);
                } else
                    grid[x-1][y-1].isVisible=1; 



            }
        } else if (y == 0)
        {
            // first column >> 5 adjacent cells


                // right cell
                if (grid[x][y+1].value==0 && grid[x][y+1].isVisible==0)
                {
                    calculate(x,y+1,size,grid);
                } else
                    grid[x][y+1].isVisible=1; 


                // top cell
                if (grid[x-1][y].value==0 && grid[x-1][y].isVisible==0)
                {
                    calculate(x-1,y,size,grid);
                } else
                    grid[x-1][y].isVisible=1; 

                // bottom cell
                if (grid[x+1][y].value==0 && grid[x+1][y].isVisible==0)
                {
                    calculate(x+1,y,size,grid);
                } else
                    grid[x+1][y].isVisible=1; 

                // Up diagonal  cell
                if (grid[x-1][y+1].value==0 && grid[x-1][y+1].isVisible==0)
                {
                    calculate(x-1,y+1,size,grid);
                } else
                    grid[x-1][y+1].isVisible=1; 

                // down diagonal  cell
                if (grid[x+1][y+1].value==0 && grid[x+1][y+1].isVisible==0)
                {
                    calculate(x+1,y+1,size,grid);
                } else
                    grid[x+1][y+1].isVisible=1; 


        } else if (y== size-1)
        {
            // last column >> 5 adjacent cells



                // left cell
                if (grid[x][y-1].value==0 && grid[x][y-1].isVisible==0)
                {
                    calculate(x,y-1,size,grid);
                } else
                    grid[x][y-1].isVisible=1; 


                // top cell
                if (grid[x-1][y].value==0 && grid[x-1][y].isVisible==0)
                {
                    calculate(x-1,y,size,grid);
                } else
                    grid[x-1][y].isVisible=1; 

                // bottom cell
                if (grid[x+1][y].value==0 && grid[x+1][y].isVisible==0)
                {
                    calculate(x+1,y,size,grid);
                } else
                    grid[x+1][y].isVisible=1; 

                // Up diagonal  cell
                if (grid[x-1][y-1].value==0 && grid[x-1][y-1].isVisible==0)
                {
                    calculate(x-1,y-1,size,grid);
                } else
                    grid[x-1][y-1].isVisible=1; 

                // down diagonal  cell
                if (grid[x+1][y-1].value==0 && grid[x+1][y-1].isVisible==0)
                {
                    calculate(x+1,y-1,size,grid);
                } else
                    grid[x+1][y-1].isVisible=1; 




        } else{
            // normal cell is in the middle it has 8 adjacent cells 



                // right cell
                if (grid[x][y+1].value==0 && grid[x][y+1].isVisible==0)
                {
                    calculate(x,y+1,size,grid);
                } else
                    grid[x][y+1].isVisible=1; 

                // left cell
                if (grid[x][y-1].value==0 && grid[x][y-1].isVisible==0)
                {
                    calculate(x,y-1,size,grid);
                } else
                    grid[x][y-1].isVisible=1; 


                // top cell
                if (grid[x-1][y].value==0 && grid[x-1][y].isVisible==0)
                {
                    calculate(x-1,y,size,grid);
                } else
                    grid[x-1][y].isVisible=1; 

                // bottom cell
                if (grid[x+1][y].value==0 && grid[x+1][y].isVisible==0)
                {
                    calculate(x+1,y,size,grid);
                } else
                    grid[x+1][y].isVisible=1; 

                // top right diagonal  cell
                if (grid[x-1][y+1].value==0 && grid[x-1][y+1].isVisible==0)
                {
                    calculate(x-1,y+1,size,grid);
                } else
                    grid[x-1][y+1].isVisible=1; 

                // bottom right diagonal  cell
                if (grid[x+1][y+1].value==0 && grid[x+1][y+1].isVisible==0)
                {
                    calculate(x+1,y+1,size,grid);
                } else
                    grid[x+1][y+1].isVisible=1; 

                // top left diagonal  cell
                if (grid[x-1][y-1].value==0 && grid[x-1][y-1].isVisible==0)
                {
                    calculate(x-1,y-1,size,grid);
                } else
                    grid[x-1][y-1].isVisible=1; 

                // bottom left diagonal  cell
                if (grid[x+1][y-1].value==0 && grid[x+1][y-1].isVisible==0)
                {
                    calculate(x+1,y-1,size,grid);
                } else
                    grid[x+1][y-1].isVisible=1; 

        }
        
        
        
        return true;
    } else {
        // there is mine in adjacent squares
        //set cell visible
        grid[x][y].isVisible=1;
        return true;
    }
    
    

/*     for (int i = 0; i < 10; i++)
    {
        grid[i][5].isVisible = 1;

    } */
    
}

int playMove(Cell * grid, char * move) {
    wprintf(L"Move played\n");
    return 0;
}

int main(int argc , char **argv) {
    _setmode(_fileno(stdout), _O_U16TEXT);

    int difficulty;
    int board_x, board_y;
    int valid_input = 0;
    int gameStop = 0;
    char move[4];

    wprintf(L"Game Start! \n");
    while ( valid_input == 0) {
        valid_input = 1;
        wprintf(L"1 -> Easy\n");
        wprintf(L"2 -> Medium\n");
        wprintf(L"3 -> Hard\n");
        wprintf(L"Enter Difficulty: ");
        scanf("%d", &difficulty);
        switch (difficulty) {
            case 1:
                board_x = board_y = 5;
                break;
            case 2:
                board_x = board_y = 10;
                break;
            case 3:
                board_x = board_y = 15;
                break;
            default:
                wprintf(L"Invalid selection\n");
                valid_input = 0;
                break;
        }
    }
    
    Cell * grid = createCell(5);
   

    //initalize
    int size = 10;
    Cell ** grid_;
    /* allocate the array */
 
  grid_ = malloc(size * sizeof *grid_);
  for (int i=0; i<size; i++)
  {
    grid_[i] = malloc(size * sizeof *grid_[i]);
  }


    for (int i = 0;i<10 ;i++){
        for (int j = 0; j < 10; j++)
        {
            if (i==j){
                grid_[i][j]= (Cell){.value = -1,.isVisible= 0,.isFlagged=0};
            } else if (i-j == 1 || i-j ==-1)
            {
                grid_[i][j]= (Cell){.value = 2,.isVisible= 0,.isFlagged=0};
            } else if (i-j ==2 || i-j ==-2)
            {
                grid_[i][j]= (Cell){.value = 1,.isVisible= 0,.isFlagged=0};
            }else
            grid_[i][j]= (Cell){.value = 0,.isVisible= 0,.isFlagged=0};

            wprintf(L" %d ",grid_[i][j].value);
            wprintf(L" VI%d ",grid_[i][j].isVisible);         
        }
       wprintf(L" \n"); 

    }


    int x,y;


    wprintf(L"Enter x: ");
    scanf("%d", &x);
    wprintf(L"Enter y: ");
    scanf("%d", &y);
   
    //calculate(x,y,grid_);
    for (int i = 0; i < 10; i++)
    {
        wprintf(L" befor calculate:  %d \n",grid_[i][5].isVisible);  
    }
    
    wprintf(L" after calculate:   \n");  

    //calculate(x,y,size,grid_);

    calculate(x,y,size,grid_);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
           // wprintf(L" %d ",grid_[i][j].value);
            wprintf(L" V:%d ",grid_[i][j].isVisible); 
        }
        
         wprintf(L" \n"); 
        //wprintf(L" %d \n",grid_[i][5].isVisible);  
    }
    

    while (gameStop == 0) {
        printGrid(grid, board_x, board_y);
        wprintf(L"Enter move: ");
        scanf("%4c", &move);
        gameStop = playMove(grid, move);
    }




}