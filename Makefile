NAME	=	push_swap

NAMEBONUS = checker

SRCS	=	main.c	\
			ft_utils.c \
			ft_lstadd.c \
			ft_split.c \
			ft_erreur.c \
			init_and_verif.c \
			ss_p.c \
			rr.c \
			rrr.c \
			ft_small_stack.c \

BONUS = 	main_bonus.c	\
			ft_utils.c \
			ft_lstadd.c \
			ft_split.c \
			ft_erreur.c \
			init_and_verif.c \
			ss_p.c \
			rr.c \
			rrr.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c \
			ft_small_stack.c \
			rrr_bonus.c \
			ss_p_bonus.c \

OBJ =	${SRCS:.c=.o}

BONUSOBJS	= ${BONUS:.c=.o}

CC =	cc

CFLAGS	=	-Wall -Wextra -Werror #-g

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): ${OBJ}
		$(CC) ${OBJ} -o $(NAME) 

$(NAMEBONUS): ${BONUSOBJS}
		$(CC) ${BONUSOBJS} -o $(NAMEBONUS) 

bonus : $(NAMEBONUS) ${BONUSOBJS}

all:	${NAME}

clean:
		rm -f ${OBJ} ${BONUSOBJS}

fclean:	clean
		rm -f ${NAME} $(NAMEBONUS)

re:	fclean all

.PHONY: all clean fclean re