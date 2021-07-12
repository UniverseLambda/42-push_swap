#include <ft_stdio.h>

#include <unistd.h>

#ifdef LIFO_SANITIZER

void	lifo_error_break(void)
{
	ft_putendl_fd("!!!! LIFO ERROR BREAK !!!!", STDERR_FILENO);
	return ;
}

#else

void	lifo_error_break(void)
{
	ft_putendl_fd("!!!! LIFO ERROR BREAK !!!!", STDERR_FILENO);
	return ;
}

#endif	// LIFO_SANITIZER
