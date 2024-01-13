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
