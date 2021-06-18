#include <ps_runtime.h>

#include <ft_stdlib.h>
#include <stdlib.h>
#include <unistd.h>

t_runtime	*rt_ptr(void)
{
	static t_runtime	rt;

	return (&rt);
}

static int	rt_parse_args(int argc, char *argv[])
{
	t_runtime	*rt;
	int			i;
	int			val;

	rt = rt_ptr();
	i = argc;
	while (--i > 0)
	{
		if (!ft_safe_atoi(&val, argv[i]))
			return (0);
		lifo_pushval(&(rt->stack_a), val);
	}
	return (1);
}

static int	rt_init_allocs(int argc)
{
	t_runtime	*rt;

	rt = rt_ptr();
	if (!arraylist_init(&(rt->ops), sizeof(enum e_ops), NULL, NULL))
		return (0);
	if (!lifo_ctor(&(rt->stack_a), argc - 1))
	{
		arraylist_freeres(&(rt->ops));
		return (0);
	}
	if (!lifo_ctor(&(rt->stack_b), argc - 1))
	{
		lifo_dtor(&(rt->stack_a));
		arraylist_freeres(&(rt->ops));
		return (0);
	}
	return (1);
}

enum e_rtinit_ret	rt_init_args(int argc, char *argv[])
{
	t_runtime	*rt;

	rt = rt_ptr();
	if (argc <= 1)
		return (RTINIT_NOARG);
	if (!rt_init_allocs(argc))
		return (RTINIT_ALLOCERROR);
	if (!rt_parse_args(argc, argv))
	{
		lifo_dtor(&(rt->stack_a));
		lifo_dtor(&(rt->stack_b));
		arraylist_freeres(&(rt->ops));
		return (RTINIT_WRONGARGS);
	}	
	return (RTINIT_OK);
}

void	rt_exit(int code)
{
	t_runtime	*rt;

	rt = rt_ptr();
	lifo_dtor(&(rt->stack_a));
	// lifo_dtor(&(rt->stack_b));
	arraylist_freeres(&(rt->ops));
	if (code != 0)
		write(STDERR_FILENO, "Error\n", 6);
	exit(code);
}
