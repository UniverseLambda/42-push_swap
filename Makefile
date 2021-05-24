.DEFAULT: all
.PHONY: all clean fclean re
.SUFFIXES: .c .o

NAME := push_swap

CC ?= clang
RM ?= rm
LD := $(CC)

CFLAGS ?=
CFLAGS := $(CFLAGS) -Wall -Wextra -Werror -Iinc -Ilibft/inc -g3
LDFLAGS := $(LDFLAGS) -g3

BUILD_TYPE := release

OBJS := src/main.o \
		src/lifo_stack.o \
		src/lifo_stack_op.o \
		src/ps_runtime.o \
		src/sort.o \
		src/median.o \

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
	./$(NAME) 1 2 3 4 5

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
