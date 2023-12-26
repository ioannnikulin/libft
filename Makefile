CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c aux_printf.c put_c.c put_p.c put_s.c put_x.c pad_n_put.c put_d.c put_percent.c put_u.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I. -Ilibft
PACK = ar

all: $(NAME)

bonus: all

$(NAME): $(OBJS) $(FTUNPACK)
	$(PACK) rcs $@ $^

LIBFT: libft/libft.h
	cd libft && make all && cp libft.a libft.h ..

FTUNPACK: LIBFT
	$(PACK) x $< $@
	
$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

clean:
	rm -f $(OBJS)
	cd libft && make clean

fclean: clean
	rm -f $(NAME) libft.a
	cd libft && make fclean

re: fclean all
