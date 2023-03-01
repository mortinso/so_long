# -*- MakeFile -*-

NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf
INC			=	-I mlx -I utils/ft_printf -I utils/get_next_line
LIB			=	-L mlx -lmlx -lXext -lX11

SOL_SRCS	=	src/mlx_teste.c #src/so_long.c
PTF_SRCS	=	utils/ft_printf/ft_printf.c utils/ft_printf/ft_printf_utils.c
GNL_SRCS	=	utils/get_next_line/get_next_line.c utils/get_next_line/get_next_line_utils.c

SRCS		=	$(GNL_SRCS) $(PTF_SRCS) $(SOL_SRCS)
OBJS		=	$(patsubst utils/get_next_line/%, obj/%, $(GNL_SRCS:%.c=%.o)) $(patsubst utils/ft_printf/%, obj/%, $(PTF_SRCS:%.c=%.o)) \
				$(patsubst src/%, obj/%, $(SOL_SRCS:%.c=%.o))

.PHONY:		all clean fclean re val map1 map2 map3

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -g $(INC) $(SRCS) $(LIB) -o $@

obj/%.o:	$(SRCS)
			@mkdir -p obj
			@$(CC) $(CFLAGS) -o $@ -c $<

map1:		$(NAME)
			@./so_long maps/map1.ber

map2:		$(NAME)
			@./so_long maps/map2.ber

map3:		$(NAME)
			@./so_long maps/map3.ber

val:		$(NAME)
			@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./so_long

clean:
			@$(RM) obj

fclean:		clean
			@$(RM) $(NAME)


re: fclean all
