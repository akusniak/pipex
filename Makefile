NAME = pipex
NAME_BONUS =

CC = cc
CFLAGS = -Wall -Wextra -Werror

COLOUR_GREEN=\033[0;32m

RM = rm -f

SRCS = main.c\
		child.c\
		action.c\
		command.c\
		path.c

SRCS_BONUS =

OBJS = $(SRCS:.c=.o)
OBJS_BONUS =  $(SRCS_BONUS:.c=.o)

LIB = make bonus -C ./libft

.c.o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
				$(LIB)
				$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)


lib :
		$(LIB)

all :
		$(NAME)

bonus : $(OBJS_BONUS)
			$(LIB)
			$(CC) $(CFLAGS) $(OBJS_BONUS) libft/libft.a -o $(NAME_BONUS)

clean :
		$(RM) $(OBJS) $(OBJS_BONUS)
		@echo "$(COLOUR_GREEN) clean is done"

fclean : clean
		$(RM) $(NAME) $(CHECKER)
		@cd ./libft && make fclean
		@echo "$(COLOUR_GREEN) fclean is done"

re : fclean all

.PHONY: all clean fclean re lib bonus
