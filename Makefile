# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cisis <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 16:35:10 by cisis             #+#    #+#              #
#    Updated: 2021/01/29 18:28:27 by cisis            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D
LIBFTNAME		=	libft.a
MLX				=	libmlx.dylib	

INCLUDES		=	./includes/

LIBFTDIR		=	./libft/
MLXDIR			=	./minilibx/

MAINDIR			=	./main/
PARCERDIR		=	./parser/
ERRDIR			=	./errors/

PARSERSRCS		=	$(PARCERDIR)parse_file.c $(PARCERDIR)validate_list.c \
					$(PARCERDIR)free_memory.c $(PARCERDIR)validate_parameter.c \
					$(PARCERDIR)validate_resolution.c

MAINSRCS		=	$(MAINDIR)main.c

ERRSRCS			=	$(ERRDIR)process_errors.c

SRCS			=	$(PARSERSRCS) $(MAINSRCS) $(ERRSRCS)

OBJS			=	$(patsubst %.c,%.o,$(SRCS))

CCFLAGS			=	-Wall -Wextra -Werror

.c.o:				
					gcc $(CCFLAGS) -c $< -I $(INCLUDES) -I $(MLXDIR) -o $(<:.c=.o) -O3

all:				$(NAME)

lft:				
					cd $(LIBFTDIR) && make all && make clean

mlx:
					cd $(MLXDIR) && make && mv $(MLX) .. && make clean

$(NAME):			$(OBJS)
					make lft
					#make mlx
					gcc $(CCFLAGS) $? -o $(NAME) -L$(LIBFTDIR) -lft \
						#-L. -lmlx -framework OpenGL -framework Appkit

debug:              $(OBJS)
					make lft
					#make mlx
					gcc $(CCFLAGS) -g $? -o $(NAME) -L$(LIBFTDIR) -lft \
						#-L. -lmlx -framework OpenGL -framework Appkit

clean:				
					rm -f $(OBJS) $(LIBFTDIR)$(LIBFTNAME) $(MLX)

fclean:				clean
					@ rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
