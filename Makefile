CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -Llibft -lft
SRCS = ft_is
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
	
$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

#==============================================================================

$(TESTOBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(TESTINCLUDES) -g

testfclean:
	rm -f $(TESTOBJS)
	rm -f $(TESTNAME)

test: $(TESTOBJS) $(AUXOBJ)
	$(CC) $(CFLAGS) $^ $(TESTINCLUDES) -o $(TESTNAME) -g

retest: testfclean test

go: re retest
	norminette *.c *.h
	tests/test
	# -------- Testing finished. --------
