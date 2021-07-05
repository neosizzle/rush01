#include <stdlib.h>
#include <unistd.h>

int	rush(void);

int	*g_condition;

void	ft_putstr (char *str)
{
	char	a;

	a = *str;
	while (a != '\0')
	{
		write (1, &a, 1);
		a = *(++str);
	}
}

int	ft_strlen (char *str)
{
	int		length;
	char	a;

	a = *str;
	length = 0;
	while (a != '\0')
	{
		length++;
		a = *(str + length);
	}
	return (length);
}

int	*convert_int (char *str)
{	
	static int	array[16];
	int			i;
	char		a;

	i = 0;
	a = *str;
	while (i < 32)
	{
		array[i / 2] = a - 48;
		i = i + 2;
		a = *(str + i);
	}
	return (array);
}

int	is_input_valid(int *a)
{
	int		i;

	i = 0;
	while (i < 12)
	{
		if (((*(a + i) + *(a + i + 4)) > 5) || ((*(a + i) + *(a + i + 4)) < 3))
			return (0);
		i++;
		if (i == 4)
			i = i + 4;
	}
	return (1);
}

int	main (int argc, char *argv[])
{
	int	*arrayptr;
	int	check;

	check = 0;
	if (argc == 2 && ft_strlen(argv[1]) == 31)
	{
		arrayptr = convert_int (argv[1]);
		if (is_input_valid(arrayptr))
		{
			g_condition = arrayptr;
			check = rush();
			if (check == 0)
				ft_putstr ("Error\n");
		}
		else
			ft_putstr ("Error\n");
	}
	else
		ft_putstr ("Error\n");
}
