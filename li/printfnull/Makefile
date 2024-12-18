
SOURCE = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c


OBJET = $(SOURCE:.c=.o)

FLAG = -Wall -Werror -Wextra

CC = gcc

NAME = libftprintf.a

all : $(NAME)

$(NAME): $(OBJET)
	ar rcs $(NAME) $(OBJET)

%.o: %.c 
	$(CC) $(FLAG) -c $< -o $@


clean:
	rm -f $(OBJET) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

