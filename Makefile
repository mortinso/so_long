# -*- MakeFile -*-

NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf
INC			=	-I minilibx-linux -I utils/ft_printf -I utils/get_next_line -I utils/libft
LIB			=	-L minilibx-linux -lmlx -lXext -lX11

SOL_SRCS	=	src/so_long.c src/map_verifier.c src/error_handler.c src/game_init.c src/events.c src/function_hubs.c src/drawing.c src/animations.c\
				src/game_finish.c

PTF_SRCS	=	utils/ft_printf/ft_printf.c utils/ft_printf/ft_printf_utils.c
GNL_SRCS	=	utils/get_next_line/get_next_line.c utils/get_next_line/get_next_line_utils.c
LFT_SRCS	=	utils/libft/ft_strchr.c utils/libft/ft_itoa.c utils/libft/ft_strnstr.c

SRCS		=	$(LFT_SRCS) $(GNL_SRCS) $(PTF_SRCS) $(SOL_SRCS)
OBJS		=	$(addprefix obj/, $(SRCS:%.c=%.o))

.PHONY:		all clean fclean re val map1 map2 map3

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -g $(INC) $(OBJS) $(LIB) -o $@

obj/%.o:	%.c
			@mkdir -p obj/$(dir $<)
			@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

map1:		$(NAME)
			@./so_long maps/map1.ber

map2:		$(NAME)
			@./so_long maps/map2.ber

map3:		$(NAME)
			@./so_long maps/map3.ber

val:		$(NAME)
			@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./so_long maps/map4.ber

clean:
			@$(RM) obj

fclean:		clean
			@$(RM) $(NAME)


re: fclean all
