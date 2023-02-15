NAME =so_long
NAME_bonus =so_long_bonus/so_long
CFLAGS = -Wall -Wextra -Werror 
SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c helpers/ft_split.c \
	   helpers/ft_calloc.c helpers/ft_itoa.c helpers/ft_strdup.c helpers/ft_strncmp.c helpers/ft_add.c helpers/ft_printf.c \
		helpers/functions_printf.c so_long_men/upload_image.c so_long_men/check_map.c so_long_men/move_player.c so_long_men/valid_path.c so_long_men/help_me_move.c so_long_men/help_check_map.c so_long_men/so_long.c \

SRCS_BONUS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c helpers/ft_split.c \
	   helpers/ft_calloc.c helpers/ft_itoa.c helpers/ft_strdup.c helpers/ft_add.c helpers/ft_printf.c \
		helpers/functions_printf.c bonus/upload_image.c bonus/check_map.c bonus/move_player.c bonus/valid_path.c bonus/help_me_move.c bonus/help_check_map.c bonus/animation.c bonus/so_long.c \

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all : $(NAME)

$(NAME): $(OBJS)
	cc -lmlx -framework OpenGL -framework appkit $(OBJS) -o ${NAME} 

bonus :${OBJS_BONUS} 
	cc -lmlx -framework OpenGL -framework appkit $(OBJS_BONUS)  -o ${NAME} 

clean :
	rm -f ${OBJS} $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) 

re: fclean all