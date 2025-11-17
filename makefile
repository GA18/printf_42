NAME = libftprintf.a

SRC = ft_printf.c  ft_pointer.c  ft_printcstr.c  ft_puthex.c  ft_putnbr.c  ft_putunbr.c  ft_strlen.c

OBJ = $(SRC:%.c=%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c

	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all