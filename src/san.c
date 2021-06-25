#include <ft_stdio.h>

#include <unistd.h>

void	lifo_error_break()
{
	ft_putendl_fd("!!!! LIFO ERROR BREAK !!!!", STDERR_FILENO);

	return ;
}
