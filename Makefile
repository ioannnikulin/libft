CC = clang
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c aux_printf.c put_c.c put_p.c put_s.c put_x.c pad_n_put.c put_d.c put_percent.c put_u.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I. -Ilibft
PACK = ar

all: $(NAME)

bonus: all

$(NAME): $(OBJS) LIBFT
	cp libft/libft.a $@
	$(PACK) rcs $@ $(OBJS)

LIBFT:
	cd libft && make all

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

clean:
	rm -f $(OBJS)
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all
