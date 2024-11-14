NAME = libftprintf.a
SRC =  ft_putchar_fd.c ft_putnbr.c ft_putstr_fd.c ft_extra.c ft_unsigned.c ft_printf.c ft_puthex.c ft_putptr.c

SRC_O = $(SRC:.c=.o)

%.o : %.c ft_printf.h
	cc -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

$(NAME): $(SRC_O)
	ar rcs $@ $^

clean :
	rm -f $(SRC_O)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean 