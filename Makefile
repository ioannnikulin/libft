CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c aux_printf.c put_c.c put_p.c put_s.c put_x.c pad_n_put.c put_d.c put_percent.c put_u.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I . -I libft
PACK = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(PACK) tmp $(OBJS)
	$(PACK) -T $(NAME) tmp libft/libft.a

LIBFT: libft/libft.h
	cd libft && make all && make clean
	
$(OBJS): %.o: %.c LIBFT
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) tmp libft/libft.a

re: fclean all
