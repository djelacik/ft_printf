NAME = libftprintf.a

SOURCES = \
    ft_printf.c \
    functions.c \
    functions2.c \
    parsing_functions.c \
    print_char.c \
    print_ptr.c \
    print_str.c \
    print_hex_lower.c \
    print_hex_upper.c \
    print_int.c \
    print_uns_int.c \
    parse_format.c \
    process_arg_len.c \
    arg_len_str.c \
    arg_len_int.c \
    arg_len_hex.c \
    print_flags.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $@ $^

bonus: .bonus

.bonus: ${OBJECTS}
	$(AR) $(NAME) $(OBJECTS)
	touch .bonus

%.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

.PHONY: all clean fclean re
