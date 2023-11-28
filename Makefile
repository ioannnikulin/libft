CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c aux_printf.c put_c.c put_p.c put_s.c put_x.c pad_n_put.c put_d.c put_percent.c put_u.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I . -I libft
PACK = ar rcs
#==============================================================================
TESTF = tests
TESTS = $(TESTF)/main_test.c
TESTOBJS = $(TESTS:.c=.o)
TESTNAME = $(TESTF)/test
TESTINCLUDES = -I $(TESTF)/tests.h
#==============================================================================

all: $(NAME)

$(NAME): $(OBJS)
	$(PACK) $(NAME) $(OBJS)

LIBFT: libft/libft.h
	cd libft && make all && make clean
	
$(OBJS): %.o: %.c LIBFT
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

#==============================================================================

$(TESTOBJS): %.o: %.c
	$(CC) -c $< -o $@ $(INCLUDES) -g

testfclean:
	rm -f $(TESTOBJS)
	rm -f $(TESTNAME)

test: $(TESTOBJS) $(NAME) libft/libft.a
	$(CC) $(CFLAGS) $^ $(TESTINCLUDES) -o $(TESTNAME) -g -Llibft -L. -lftprintf -lft

retest: testfclean test

go: re retest
	norminette *.c *.h
	tests/test
	rm -f std.tmp custom.tmp
	# -------- Testing finished. --------
