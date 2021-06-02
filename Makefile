.DEFAULT: all
.PHONY: all clean fclean re
.SUFFIXES: .c .o

NAME := push_swap

CC ?= clang
RM ?= rm
LD := $(CC)

CFLAGS ?=
CFLAGS := $(CFLAGS) -Wall -Wextra -Werror -Iinc -Ilibft/inc -g3 -fsanitize=address
LDFLAGS := $(LDFLAGS) -g3 -fsanitize=address

BUILD_TYPE := release

OBJS := src/main.o \
		src/new_median.o \
		src/new_median_ext.o \
		src/array.o \
		src/array_ext.o \
		src/lifo_stack.o \
		src/lifo_stack_op.o \
		src/ps_runtime.o \
		src/sort.o \
		src/ops_push_swap.o \
		src/ops_rotate.o \
		src/ops_rrotate.o \

all: all-dependency $(NAME)

$(NAME): dependency $(OBJS)
	$(LD) $(LDFLAGS) -o $(NAME) $(OBJS) libft/libft.a

%.o: %.c libft.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean: clean-dependency
	$(RM) -f $(OBJS)

fclean: fclean-dependency clean
	$(RM) -f $(NAME)

re: fclean all

debug:	BUILD_TYPE := debug
debug:	all

run:	all
	./$(NAME) -52 1 33 2 5 3 9 4 123

# DEPENDENCIES TARGET

dependency: all-dependency

all-dependency:
	make -C libft/ all

clean-dependency:
	make -C libft/ clean

fclean-dependency:
	make -C libft/ fclean

re-dependency:
	make -C libft/ re
