//GLOBAL VARIABLES
//g_board[i][j] is the current state of the board,
// where i is row and j is col
//
//g_row_matrix[i][val] is the row matrix for the board,
//i represents the row number and val represents the current 
//value stored in that row
//
//g_col_matrix[i][val] is g_row_matrix for columns
//
//g_condition[i] is the condition that needs to be fulfilled
//e.g. 4 3 2 1 1 2 2 2 1 2 2 2 1 4 3 2 1
//
//g_start_ptr yields the current starting pointer needed for checking solutions
//
//g_offset[i][j] stores the amount of increment needed to perform various
//checking operations

int			g_board[5][5];
int			g_row_matrix[5][5];
int			g_col_matrix[5][5];
extern int	*g_condition;
int			*g_start_ptr[4];
int			g_offset[4][2];

int		fill_board(int row, int col);
int		is_valid_solution(void);
void	ft_print_grid(int grid[5][5]);

//this function sets global variables 
//to the default values upon calling
//
//int g_row_matrix[i][vals] to all 0 to indicate that
//that specified matrix is not occupied, 1 if it is
//
//int g_col_matrix[i][vals] the same to g_row_matix concept
//
//int *g_start_ptr[0] : Starting point of column-checking('up' to 'down').
//which is coordinate (1,1)
//
//int *g_start_ptr[1] : Starting point of column-checking('down' to 'up').
//which is coordinate (4,1)
//
//int *g_start_ptr[2] : Starting point of row-checking('left' to 'right').
//which is coordinate (1,1)
//
//int *g_start_ptr[3] : Starting point of row-checking('right' to 'left').
//Which is coordinate (1,4)
//
//int g_offset[0][0] : (While 'up' to 'down' column-checking) Increment of
//the address to move to next column. Which is +5
//
//int g_offset[0][1] : (While 'up' to 'down' column-checking) Increment of
//the address to move to next row. Which is +1
//
//int g_offset[1][0] : (While 'down' to 'up' column-checking) Increment of
//the address to move to next column. Which is -5
//
//int g_offset[1][1] : (While 'down' to 'up' column-checking) Increment of
//the address to move to next row. Which is +1
//
//int g_offset[2][0] : (While 'left' to 'right' row-checking) Increment of
//the address to move to next row. Which is +1
//
//int g_offset[2][1] : (While 'left' to 'right' row-checking) Increment of
//the address to move to next column. Which is +5
//
//int g_offset[3][0] : (While 'right' to 'left' row-checking) Increment of
//the address to move to next row. Which is -1
//
// int g_offset[3][1] : (While 'right' to 'left' row-checking) Increment of
//the address to move to next column. Which is +5

void	set_vars(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < 5)
	{
		while (++j < 5)
		{
			g_col_matrix[i][j] = 0;
			g_row_matrix[i][j] = 0;
		}
	}
	g_start_ptr[0] = &g_board[1][1];
	g_start_ptr[1] = &g_board[4][1];
	g_start_ptr[2] = &g_board[1][1];
	g_start_ptr[3] = &g_board[1][4];
	g_offset[0][0] = 5;
	g_offset[0][1] = 1;
	g_offset[1][0] = -5;
	g_offset[1][1] = 1;
	g_offset[2][0] = 1;
	g_offset[2][1] = 5;
	g_offset[3][0] = -1;
	g_offset[3][1] = 5;
}

//fill board function helper
//does not do checks, just responsible to recurse
//
//1. it will iterate from 1 to 5, and fill the curr
//box with those values
//
//2. it will only fill non repeating values by checking the matrix
//
//3.once a non repeated value is filled, it will recurse to the following row
//
//4. if recursion returns 1, return 1
//
//5, else, free the matrix and move on to the next value

int	fill_board_helper (int row, int col)
{
	int	val;

	val = 0;
	while (++val < 5)
	{
		if (g_row_matrix[row][val] || g_col_matrix[col][val])
			continue ;
		g_row_matrix[row][val] = 1;
		g_col_matrix[col][val] = 1;
		g_board[row][col] = val;
		if (fill_board(row, col + 1) == 1)
			return (1);
		g_row_matrix[row][val] = 0;
		g_col_matrix[col][val] = 0;
	}
	return (0);
}

//fill booard function
//once all the rows are filled, call checker function
//
//if not, keep calling helper function to recurse

int	fill_board(int row, int col)
{
	if (row == 5)
	{
		if (is_valid_solution())
		{		
			ft_print_grid(g_board);
			return (1);
		}
		return (0);
	}
	if (col == 5)
		return (fill_board(row + 1, 1));
	else
		return (fill_board_helper(row, col));
}

//shell function
//responsible for initiating the variables as well as 
//start filling the board
int	rush(void)
{
	set_vars();
	return (fill_board(1, 1));
}
