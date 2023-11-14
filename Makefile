CC = cc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
#==============================================================================
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I libft.h
PACK = ar rcs
#==============================================================================
TESTF = tests
TESTS = $(TESTF)/main_test.c $(TESTF)/ft_isalpha_test.c $(TESTF)/ft_isdigit_test.c $(TESTF)/ft_isalnum_test.c $(TESTF)/ft_isascii_test.c $(TESTF)/ft_isprint_test.c $(TESTF)/ft_strlen_test.c $(TESTF)/ft_memset_test.c $(TESTF)/ft_bzero_test.c $(TESTF)/ft_memcpy_test.c $(TESTF)/ft_memmove_test.c
TESTOBJS = $(TESTS:.c=.o)
TESTNAME = $(TESTF)/test
TESTFLAGS = -L. -lft
TESTINCLUDES = -I $(TESTF)/tests.h
#==============================================================================
SEGFAULTS = $(TESTF)/ft_bzero_segfault_1.c

SEGFAULTOBJS = $(SEGFAULTS:.c=.o)
SEGFAULTNAMES = $(SEGFAULTS:.c=.sf)
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

$(SEGFAULTOBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(TESTINCLUDES) -g

testfclean:
	rm -f $(TESTOBJS)
	rm -f $(SEGFAULTOBJS)
	rm -f $(TESTNAME)
	rm -f $(SEGFAULTNAMES)

goodtests: $(TESTOBJS) 
	$(CC) $(CFLAGS) $^ $(TESTFLAGS) $(TESTINCLUDES) -o $(TESTNAME) -g

$(SEGFAULTNAMES): %.sf: %.o
	$(CC) $(CFLAGS) $^ $(TESTFLAGS) $(TESTINCLUDES) -o $@ -g

test: $(SEGFAULTNAMES) goodtests

retest: testfclean test

go: re retest
	tests/test
	# -------- Multiple segfaults expected, which is part of the testing. --------
	# -------- Stay calm unless you see an error message in UPPER CASE. --------
	@$(SEGFAULTNAMES:%.sf=%.sf ||) true
	# -------- Testing finished. --------
