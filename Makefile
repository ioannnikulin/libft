CC = cc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_isspace.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_is_in.c ft_empty_string.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstclear.c ft_lst_generate.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lst_print.c ft_lstmap.c ft_lstiter.c ft_putnbr_fd.c ft_xtoa_base.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I .
PACK = ar rcs
#==============================================================================
TESTF = tests
TESTS = $(TESTF)/main_test.c $(TESTF)/ft_isalpha_test.c $(TESTF)/ft_isdigit_test.c $(TESTF)/ft_isalnum_test.c $(TESTF)/ft_isascii_test.c $(TESTF)/ft_isprint_test.c $(TESTF)/ft_strlen_test.c $(TESTF)/ft_memset_test.c $(TESTF)/ft_bzero_test.c $(TESTF)/ft_memcpy_test.c $(TESTF)/ft_memmove_test.c $(TESTF)/ft_strlcpy_test.c $(TESTF)/ft_strlcat_test.c $(TESTF)/ft_tolower_test.c $(TESTF)/ft_toupper_test.c $(TESTF)/ft_strchr_test.c $(TESTF)/ft_strrchr_test.c $(TESTF)/ft_strncmp_test.c $(TESTF)/ft_memchr_test.c $(TESTF)/ft_memcmp_test.c $(TESTF)/ft_strnstr_test.c $(TESTF)/ft_isspace_test.c $(TESTF)/ft_atoi_test.c $(TESTF)/ft_strdup_test.c $(TESTF)/ft_substr_test.c $(TESTF)/ft_strjoin_test.c $(TESTF)/ft_strtrim_test.c $(TESTF)/ft_split_test.c $(TESTF)/ft_itoa_test.c $(TESTF)/ft_striteri_test.c $(TESTF)/ft_strmapi_test.c $(TESTF)/ft_putchar_fd_test.c $(TESTF)/ft_putstr_fd_test.c $(TESTF)/ft_putendl_fd_test.c $(TESTF)/ft_lstnew_test.c $(TESTF)/ft_lstadd_front_test.c $(TESTF)/ft_lst_generate_test.c $(TESTF)/ft_lstclear_test.c $(TESTF)/ft_lstsize_test.c $(TESTF)/ft_lstlast_test.c $(TESTF)/ft_lstadd_back_test.c $(TESTF)/ft_lstdelone_test.c $(TESTF)/ft_lstmap_test.c $(TESTF)/ft_lstiter_test.c $(TESTF)/ft_putnbr_fd_test.c $(TESTF)/ft_lltoa_base_test.c $(TESTF)/ft_ulltoa_base_test.c
TESTOBJS = $(TESTS:.c=.o)
TESTNAME = $(TESTF)/test
TESTFLAGS = -L. -lft -lbsd
TESTINCLUDES = -I $(TESTF)/tests.h
#==============================================================================
SEGFAULTS = $(TESTF)/ft_bzero_segfault_1.c $(TESTF)/ft_memcpy_segfault_1.c $(TESTF)/ft_memcpy_segfault_2.c $(TESTF)/ft_memcpy_segfault_3.c $(TESTF)/ft_memmove_segfault_1.c $(TESTF)/ft_memmove_segfault_2.c $(TESTF)/ft_memmove_segfault_3.c $(TESTF)/ft_strlen_segfault_1.c $(TESTF)/ft_memset_segfault_1.c $(TESTF)/ft_strlcpy_segfault_1.c $(TESTF)/ft_strlcpy_segfault_2.c $(TESTF)/ft_strlcpy_segfault_3.c $(TESTF)/ft_strlcat_segfault_1.c $(TESTF)/ft_strlcat_segfault_2.c $(TESTF)/ft_strlcat_segfault_3.c $(TESTF)/ft_strlcat_segfault_4.c $(TESTF)/ft_strchr_segfault_1.c $(TESTF)/ft_strrchr_segfault_1.c $(TESTF)/ft_strncmp_segfault_1.c $(TESTF)/ft_strncmp_segfault_2.c $(TESTF)/ft_strncmp_segfault_3.c $(TESTF)/ft_memchr_segfault_1.c $(TESTF)/ft_memcmp_segfault_1.c $(TESTF)/ft_memcmp_segfault_2.c $(TESTF)/ft_memcmp_segfault_3.c $(TESTF)/ft_strnstr_segfault_1.c $(TESTF)/ft_strdup_segfault_1.c $(TESTF)/ft_substr_segfault_1.c $(TESTF)/ft_substr_segfault_2.c $(TESTF)/ft_strjoin_segfault_1.c $(TESTF)/ft_strjoin_segfault_2.c $(TESTF)/ft_strjoin_segfault_3.c $(TESTF)/ft_strtrim_segfault_1.c $(TESTF)/ft_strtrim_segfault_2.c $(TESTF)/ft_strtrim_segfault_3.c
AUX = $(TESTF)/aux.c
AUXOBJ = $(AUX:.c=.o)
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

$(AUXOBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(TESTINCLUDES) -g

testfclean:
	rm -f $(TESTOBJS)
	rm -f $(SEGFAULTOBJS)
	rm -f $(TESTNAME)
	rm -f $(SEGFAULTNAMES)

goodtests: $(TESTOBJS) $(AUXOBJ)
	$(CC) $(CFLAGS) $^ $(TESTFLAGS) $(TESTINCLUDES) -o $(TESTNAME) -g

$(SEGFAULTNAMES): %.sf: %.o $(AUXOBJ)
	$(CC) $(CFLAGS) $^ $(TESTFLAGS) $(TESTINCLUDES) -o $@ -g

test: $(SEGFAULTNAMES) goodtests

retest: testfclean test

go: re retest
	tests/test
	rm -rf tmp.tst
	# -------- Multiple segfaults expected, which is part of the testing. --------
	# -------- Stay calm unless you see an error message in UPPER CASE. --------
	$(SEGFAULTNAMES:%.sf=%.sf ||) true
	# -------- Testing finished. --------
