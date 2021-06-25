#include <lifo_stack.h>

#pragma message "REMOVE SAN"

#include <san.h>
void	lifo_swap(t_lifo_stack *this)
{
	int	tmp;

	if (this->data_backup_ptr != this->data)
		lifo_error_break();
	if (this->elem_count < 2)
		return ;
	tmp = this->data[this->elem_count - 1];
	this->data[this->elem_count - 1] = this->data[this->elem_count - 2];
	this->data[this->elem_count - 2] = tmp;
}

void	lifo_push(t_lifo_stack *this, t_lifo_stack *src)
{
	if (this->data_backup_ptr != this->data)
		lifo_error_break();
	if (src->elem_count == 0 || this->elem_count >= this->stack_size)
		return ;
	this->data[this->elem_count++] = src->data[src->elem_count - 1];
	src->elem_count--;
}

void	lifo_rotate(t_lifo_stack *this)
{
	int		tmp[2];
	size_t	i;

	if (this->data_backup_ptr != this->data)
		lifo_error_break();
	if (this->elem_count < 2)
		return ;
	i = 0;
	tmp[0] = this->data[0];
	while (++i < this->elem_count)
	{
		tmp[1] = this->data[i];
		this->data[i] = tmp[0];
		tmp[0] = tmp[1];
	}
	this->data[0] = tmp[0];
}

void	lifo_reverse_rotate(t_lifo_stack *this)
{
	int		tmp[2];
	size_t	i;

	if (this->data_backup_ptr != this->data)
		lifo_error_break();
	if (this->elem_count < 2)
		return ;
	i = this->elem_count - 1;
	tmp[0] = this->data[this->elem_count - 1];
	while (--i < this->elem_count)
	{
		tmp[1] = this->data[i];
		this->data[i] = tmp[0];
		tmp[0] = tmp[1];
	}
	this->data[this->elem_count - 1] = tmp[0];
}
