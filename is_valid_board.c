extern int	g_board[5][5];
extern int	*g_condition;
extern int	*g_start_ptr[4];
extern int	g_offset[4][2];

//helper function to count the buldings seen
//from a pov and return 1 if the number
//is the same as condition
int	compare_cond(int *ptr, int offset, int cond)
{
	int	i;
	int	seen;
	int	peak;

	i = 0;
	peak = 0;
	seen = 0;
	while (++i < 5)
	{		
		if (*ptr > peak)
		{
			peak = *ptr;
			++seen;
		}
		ptr += offset;
	}
	return (cond == seen);
}

//helper function to check if the current board is valid given 
//all rows and cols are filled
int	is_valid_solution(void)
{
	int	cond;
	int	i;
	int	j;
	int	*ptr;

	cond = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		ptr = g_start_ptr[i];
		while (j < 4)
		{	
			if (!compare_cond(ptr, g_offset[i][0], g_condition[cond]))
				return (0);
			j++;
			cond++;
			ptr += g_offset[i][1];
		}
		++i;
	}
	return (1);
}
