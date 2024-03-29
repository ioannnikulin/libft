CC = cc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

LIST_F = lists
LIST_NAMES = ft_lst_add_back.c ft_lst_add_front.c ft_lst_clear.c ft_lst_delone.c ft_lst_iter.c ft_lst_generate.c ft_lst_last.c ft_lst_new.c ft_lst_size.c ft_lst_map.c
LIST_SRCS = $(addprefix $(LIST_F)/, $(LIST_NAMES))

MEM_F = memory
MEM_NAMES = ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c
MEM_SRCS = $(addprefix $(MEM_F)/, $(MEM_NAMES))

NUM_F = numbers
NUM_NAMES = ft_atoi.c ft_itoa.c ft_xtoa_base.c
NUM_SRCS = $(addprefix $(NUM_F)/, $(NUM_NAMES))

STR_F = strings
STR_NAMES = ft_empty_string.c ft_split.c ft_strlen.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcpy.c ft_strlcat.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c
STR_SRCS = $(addprefix $(STR_F)/, $(STR_NAMES))

SYM_F = symbols
SYM_NAMES = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_is_in.c ft_isprint.c ft_isspace.c ft_tolower.c ft_toupper.c
SYM_SRCS = $(addprefix $(SYM_F)/, $(SYM_NAMES))


PRINTF_F = printf
PRINTF_NAMES = aux_printf.c ft_printf.c pad_n_put.c put_c.c put_d.c put_percent.c put_s.c put_u.c put_x.c put_x.c put_p.c
PRINTF_SRCS = $(addprefix $(PRINTF_F)/, $(PRINTF_NAMES))

SRCS = $(LIST_SRCS) $(MEM_SRCS) $(NUM_SRCS) $(STR_SRCS) $(SYM_SRCS) $(PRINTF_SRCS)
OBJS = $(SRCS:.c=.o)
INCLUDES = -I . 
PACK = ar rcs

all: $(NAME)

$(NAME): clean $(OBJS) 
	$(PACK) $(NAME) $(OBJS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# ------------------------------------------------------------------------------
TESTF = tests
TESTS = $(TESTF)/main_test.c $(TESTF)/ft_isalpha_test.c $(TESTF)/ft_isdigit_test.c $(TESTF)/ft_isalnum_test.c $(TESTF)/ft_isascii_test.c $(TESTF)/ft_isprint_test.c $(TESTF)/ft_strlen_test.c $(TESTF)/ft_memset_test.c $(TESTF)/ft_bzero_test.c $(TESTF)/ft_memcpy_test.c $(TESTF)/ft_memmove_test.c $(TESTF)/ft_strlcpy_test.c $(TESTF)/ft_strlcat_test.c $(TESTF)/ft_tolower_test.c $(TESTF)/ft_toupper_test.c $(TESTF)/ft_strchr_test.c $(TESTF)/ft_strrchr_test.c $(TESTF)/ft_strncmp_test.c $(TESTF)/ft_memchr_test.c $(TESTF)/ft_memcmp_test.c $(TESTF)/ft_strnstr_test.c $(TESTF)/ft_atoi_test.c $(TESTF)/ft_strdup_test.c $(TESTF)/ft_substr_test.c $(TESTF)/ft_strjoin_test.c $(TESTF)/ft_strtrim_test.c $(TESTF)/ft_split_test.c $(TESTF)/ft_itoa_test.c $(TESTF)/ft_striteri_test.c $(TESTF)/ft_strmapi_test.c
NOTMYTESTS = $(TESTF)/ft_putchar_fd_test.c $(TESTF)/ft_putstr_fd_test.c $(TESTS)/ft_putendl_fd_test.c $(TESTF)/ft_putchar_fd_test.c $(TESTF)/ft_putstr_fd_test.c $(TESTF)/ft_putendl_fd_test.c $(TESTF)/ft_putnbr_fd_test.c
JUSTMYTESTS = $(TESTF)/ft_lltoa_base_test.c $(TESTF)/ft_ulltoa_base_test.c $(TESTF)/ft_lst_generate_test.c $(TESTF)/ft_isspace_test.c 
BONUSTESTS = $(TESTF)/ft_lstnew_test.c $(TESTF)/ft_lstadd_front_test.c $(TESTF)/ft_lstclear_test.c $(TESTF)/ft_lstsize_test.c $(TESTF)/ft_lstlast_test.c $(TESTF)/ft_lstadd_back_test.c $(TESTF)/ft_lstdelone_test.c $(TESTF)/ft_lstmap_test.c $(TESTF)/ft_lstiter_test.c
PRINTFTESTS = $(TESTF)/ft_printf_test.c
TESTOBJS = $(TESTS:.c=.o) $(JUSTMYTESTS:.c=.o) $(BONUSTESTS:.c=.o) $(PRINTFTESTS:.c=.o)
TESTNAME = $(TESTF)/test
TESTFLAGS = -L. -lft -lbsd
TESTINCLUDES = -I $(TESTF)/tests.h

SEGFAULTS = $(TESTF)/ft_bzero_segfault_1.c $(TESTF)/ft_memcpy_segfault_1.c $(TESTF)/ft_memcpy_segfault_2.c $(TESTF)/ft_memcpy_segfault_3.c $(TESTF)/ft_memmove_segfault_1.c $(TESTF)/ft_memmove_segfault_2.c $(TESTF)/ft_memmove_segfault_3.c $(TESTF)/ft_strlen_segfault_1.c $(TESTF)/ft_memset_segfault_1.c $(TESTF)/ft_strlcpy_segfault_1.c $(TESTF)/ft_strlcpy_segfault_2.c $(TESTF)/ft_strlcpy_segfault_3.c $(TESTF)/ft_strlcat_segfault_1.c $(TESTF)/ft_strlcat_segfault_2.c $(TESTF)/ft_strlcat_segfault_3.c $(TESTF)/ft_strlcat_segfault_4.c $(TESTF)/ft_strchr_segfault_1.c $(TESTF)/ft_strrchr_segfault_1.c $(TESTF)/ft_strncmp_segfault_1.c $(TESTF)/ft_strncmp_segfault_2.c $(TESTF)/ft_strncmp_segfault_3.c $(TESTF)/ft_memchr_segfault_1.c $(TESTF)/ft_memcmp_segfault_1.c $(TESTF)/ft_memcmp_segfault_2.c $(TESTF)/ft_memcmp_segfault_3.c $(TESTF)/ft_strnstr_segfault_1.c $(TESTF)/ft_strdup_segfault_1.c $(TESTF)/ft_substr_segfault_1.c $(TESTF)/ft_substr_segfault_2.c $(TESTF)/ft_strjoin_segfault_1.c $(TESTF)/ft_strjoin_segfault_2.c $(TESTF)/ft_strjoin_segfault_3.c $(TESTF)/ft_strtrim_segfault_1.c $(TESTF)/ft_strtrim_segfault_2.c $(TESTF)/ft_strtrim_segfault_3.c
AUX = $(TESTF)/aux.c
AUXOBJ = $(AUX:.c=.o)
SEGFAULTOBJS = $(SEGFAULTS:.c=.o)
SEGFAULTNAMES = $(SEGFAULTS:.c=.sf)

$(TESTOBJS): %.o: %.c
	$(CC) -Werror -c $< -o $@ $(TESTINCLUDES) -g

$(SEGFAULTOBJS): %.o: %.c
	$(CC) -Werror -c $< -o $@ $(TESTINCLUDES) -g

$(AUXOBJ): %.o: %.c
	$(CC) -Werror -c $< -o $@ $(TESTINCLUDES) -g

testfclean:
	rm -f $(TESTOBJS)
	rm -f $(SEGFAULTOBJS)
	rm -f $(TESTNAME)
	rm -f $(SEGFAULTNAMES)

goodtests: $(TESTOBJS) $(AUXOBJ)
	$(CC) $^ $(TESTFLAGS) $(TESTINCLUDES) -o $(TESTNAME) -g

$(SEGFAULTNAMES): %.sf: %.o $(AUXOBJ)
	$(CC) $^ $(TESTFLAGS) $(TESTINCLUDES) -o $@ -g

test: $(SEGFAULTNAMES) goodtests

retest: testfclean test

go: re retest
	tests/test
	rm -rf tmp.tst
	# -------- Multiple segfaults expected, which is part of the testing. --------
	# -------- Stay calm unless you see an error message in UPPER CASE. --------
	$(SEGFAULTNAMES:%.sf=%.sf ||) true
	# -------- Testing finished. --------
