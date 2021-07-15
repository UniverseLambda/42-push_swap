.DEFAULT: all
.PHONY: all clean fclean re
.SUFFIXES: .c .o

NAME := libft.a

CC ?= cc
AR ?= ar

CFLAGS ?=
CFLAGS := $(CFLAGS) -g -Wall -Wextra -Werror -Iinc # -fsanitize=address

include src/Makefile
include inc/Makefile

INCLUDES :=	$(LIBFT_INCLUDES)

OBJS := $(LIBFT_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	$(AR) rcs $(NAME) $(OBJS)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
