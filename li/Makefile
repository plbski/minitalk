
SRC = 
# char
SRC += ft_isalnum.c
SRC += ft_isalpha.c
SRC += ft_isascii.c
SRC += ft_isdigit.c
SRC += ft_islower.c
SRC += ft_isprint.c
SRC += ft_isspace.c
SRC += ft_isupper.c
SRC += ft_toupper.c
SRC += ft_tolower.c

# put
#SRC += ft_putchar.c

# str
SRC += ft_strcat.c
SRC += ft_strchr.c
SRC += ft_strcmp.c
SRC += ft_strcpy.c
SRC += ft_strlcat.c
SRC += ft_strlcpy.c
SRC += ft_strlen.c
SRC += ft_strncmp.c
SRC += ft_strncpy.c
SRC += ft_strnstr.c
SRC += ft_strrchr.c

# mem
SRC += ft_bzero.c
SRC += ft_memchr.c
SRC += ft_memcmp.c
SRC += ft_memcpy.c
SRC += ft_memmove.c
SRC += ft_memset.c

SRC += ft_atoi.c
SRC += ft_atol.c

# malloc
SRC += ft_calloc.c
SRC += ft_strdup.c
SRC += ft_substr.c
SRC += ft_strjoin.c
SRC += ft_strtrim.c
SRC += ft_split.c
SRC += ft_itoa.c
SRC += ft_strmapi.c
SRC += ft_striteri.c

# fd
SRC += ft_putchar_fd.c
SRC += ft_putstr_fd.c
SRC += ft_putendl_fd.c
SRC += ft_putnbr_fd.c
SRC += ft_printlst.c

#bonus
SRCB = 

PRINTF_A = libftprintf.a
PRINTF_DIR = printfnull/
PRINTF = $(addprefix $(PRINTF_DIR), $(PRINTF_A))

NAME = libft.a
LIBC = ar rcs
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)
OBJBS = $(SRCB:.c=.o)

.c.o:
#	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@$(LIBC) $(NAME) $(OBJS)
	@make -C $(PRINTF_DIR)

bonus: $(NAME) $(OBJBS)
	@echo "-> Compiling bonus files..."
	@$(LIBC) $(NAME) $(OBJBS)

clean:
	@echo "-> Cleaning libft object files.."
	@$(RM) $(OBJS) $(OBJBS)

fclean: clean
	@echo "-> Removing libft archive..."
	@$(RM) $(NAME) $(OBJBS)

re: fclean all

.PHONY: all bonus clean fclean re 
