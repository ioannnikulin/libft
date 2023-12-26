CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c aux_printf.c put_c.c put_p.c put_s.c put_x.c pad_n_put.c put_d.c put_percent.c put_u.c
OBJS = $(SRCS:.c=.o)
FTUNPACK = libft.tmp
INCLUDES = -I . -I libft
PACK = ar
#==============================================================================
TESTF = tests
TESTS = $(TESTF)/main_test.c
TESTOBJS = $(TESTS:.c=.o)
TESTNAME = $(TESTF)/test
TESTINCLUDES = -I $(TESTF)/tests.h
#==============================================================================

all: $(NAME)

bonus: all

$(NAME): $(OBJS) $(FTUNPACK)
	$(PACK) rcs $@ $^

LIBFT:
	cd libft && make all

$(FTUNPACK): LIBFT
	$(PACK) p libft/libft.a > $@

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

clean:
	rm -f $(OBJS)
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all

#==============================================================================

$(TESTOBJS): %.o: %.c
	$(CC) -c $< -o $@ $(INCLUDES) -g

testfclean:
	rm -f $(TESTOBJS)
	rm -f $(TESTNAME)

test: $(TESTOBJS) $(NAME) libft/libft.a
	$(CC) $(CFLAGS) $^ $(TESTINCLUDES) -o $(TESTNAME) -g -Llibft -L. -lftprintf -lft -fsanitize=address

retest: testfclean test

go: re retest
	norminette *.c *.h
	tests/test
	rm -f std.tmp custom.tmp
	# -------- Testing finished. --------
