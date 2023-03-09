NAME = libftprintf.a

RM = rm -f

CFLAGS =  -Wall -Wextra -Werror 

.PHONY: all clean fclean re bonus

SRC = ft_printf.c

SRC_BONUS = ft_lstnew.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstsize.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

bonus: $(OBJ_BONUS)
	@ar -rcs $(NAME) $(OBJ_BONUS)

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	@$(RM) $(NAME) 


re: fclean all



