NAME_1 = serveur
NAME_2 = client

SRC_CLIENT = client.c
SRC_SERV = serveur.c

FLAG = -Wall -Werror -Wextra

CC = gcc

OBJET_C = $(SRC_CLIENT:.c=.o)
OBJET_S = $(SRC_SERV:.c=.o)
LIBFT_A = libft.a
LIBFT_DIR = libft/
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_A))
PRINTF_A = libftprintf.a
PRINTF_DIR = libft/printf/
PRINTF = $(addprefix $(PRINTF_DIR), $(PRINTF_A))

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJET_S)
	@make -C $(LIBFT_DIR)
	$(CC) $(FLAG) $(OBJET_S) $(LIBFT) $(PRINTF) -o $(NAME_1)

$(NAME_2): $(OBJET_C)
	@make -C $(LIBFT_DIR)
	$(CC) $(FLAG) $(OBJET_C) $(LIBFT) $(PRINTF) -o $(NAME_2)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	@$(RM) $(OBJET_C)
	@$(RM) $(OBJET_S)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME_1)
	@$(RM) $(NAME_2)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
