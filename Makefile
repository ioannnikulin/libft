CC = cc
NAME = libft.a
SRCF = . 
SRCS = $(SRCF)/ft_isalpha.c $(SRCF)/ft_isdigit.c $(SRCF)/ft_isalnum.c $(SRCF)/ft_isascii.c $(SRCF)/ft_isprint.c $(SRCF)/ft_strlen.c $(SRCF)/ft_memset.c $(SRCF)/ft_bzero.c $(SRCF)/ft_memcpy.c $(SRCF)/ft_memmove.c
TESTF = tests
TESTS = $(TESTF)/ft_isalpha_test.c $(TESTF)/ft_isdigit_test.c $(TESTF)/ft_isalnum_test.c $(TESTF)/ft_isascii_test.c $(TESTF)/ft_isprint_test.c $(TESTF)/ft_strlen_test.c $(TESTF)/ft_memset_test.c $(TESTF)/ft_bzero_test.c $(TESTF)/ft_memcpy_test.c $(TESTF)/ft_memmove_test.c
OBJS = ${SRCS:.c=.o}
TESTOBJS = ${TESTS:.c=.o}
CFLAGS = -Wall -Wextra -Werror
INCLUDES = . 
PACK = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(PACK) $(NAME) $(OBJS)
	
$(SRCF)/%.o: $(SRCF)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	$(CC) $(CFLAGS) -c $< 
