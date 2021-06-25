#include <lifo_stack.h>

#include <stdlib.h>

#include <ft_stdlib.h>
#include <ft_string.h>

#include <san.h>
#pragma message "REMOVE SAN"

#include <stdio.h>
int	lifo_ctor(t_lifo_stack *this, size_t size)
{
	this->data = ft_calloc(sizeof(*(this->data)), size);
	if (this->data == NULL)
		return (0);
	this->elem_count = 0;
	this->stack_size = size;
	this->data_backup_ptr = this->data;
	return (1);
}

void	lifo_dtor(t_lifo_stack *this)
{
	if (this->data_backup_ptr != this->data)
		lifo_error_break();
	if (this->data != NULL)
		free(this->data);
	this->stack_size = 0;
	this->elem_count = 0;
}

int	lifo_at(t_lifo_stack *this, size_t index)
{
	if (this->data_backup_ptr != this->data)
		lifo_error_break();
	return (this->data[this->elem_count - index - 1]);
}

void	lifo_pushval(t_lifo_stack *this, int value)
{
	if (this->data_backup_ptr != this->data)
		lifo_error_break();
	if (this->elem_count >= this->stack_size)
		return ;
	this->data[this->elem_count++] = value;
}

int	lifo_head(t_lifo_stack *this)
{
	if (this->data_backup_ptr != this->data)
		lifo_error_break();
	return (this->data[this->elem_count - 1]);
}
