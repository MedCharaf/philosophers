
NAME = philo



LIBFT_DIR = libft
LIBFT =  $(LIBFT_DIR)/libft.a
LIBFT_SRC = $(addprefix libft/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c)


CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_PS = main.c tools.c
OBJS_C = ${SRC_PS:.c=.o}


all: $(NAME)
$(NAME):  $(OBJS_C)  $(LIBFT) $(LIBFT_SRC)
	@$(CC)  $(CFLAGS) $(OBJS_C) $(LIBFT) -fsanitize=thread -g -o $(NAME)



 $(LIBFT): $(LIBFT_SRC)
	 @make -C $(LIBFT_DIR) all




clean :
	rm -rf  $(OBJS_C)
	@make -C  $(LIBFT_DIR)  clean


fclean : clean
	rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

re : fclean all
