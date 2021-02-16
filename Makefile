# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cisis <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 16:35:10 by cisis             #+#    #+#              #
#    Updated: 2021/02/16 12:21:53 by cisis            ###   ########.fr        #
#    Updated: 2021/02/03 18:01:18 by cisis            ###   ########.fr        #
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
RCSTRDIR		=	./raycaster/
HKSDIR			=	./hooks/

PARSERSRCS		=	$(PARCERDIR)parse_file.c $(PARCERDIR)validate_list.c \
					$(PARCERDIR)free_memory.c $(PARCERDIR)validate_parameter.c \
					$(PARCERDIR)validate_resolution.c $(PARCERDIR)validate_texture.c \
					$(PARCERDIR)valid_number_params.c $(PARCERDIR)validate_colour.c \
					$(PARCERDIR)validate_map.c $(PARCERDIR)valid_zero_map.c \
					$(PARCERDIR)valid_space_map.c

RCSTRSRCS		=	$(RCSTRDIR)drawing_utils.c $(RCSTRDIR)map_draw.c \
					$(RCSTRDIR)player_draw.c $(RCSTRDIR)init_player.c\
					$(RCSTRDIR)calculate_plr_pos.c $(RCSTRDIR)raycasting_wall.c \
					$(RCSTRDIR)get_textures.c $(RCSTRDIR)raycasting_drawing.c  \
					$(RCSTRDIR)raycasting_floor_ceiling.c 

HKSSRCS		=		$(HKSDIR)infinite_hook.c \
					$(HKSDIR)key_pressed_hook.c

MAINSRCS		=	$(MAINDIR)main.c $(MAINDIR)init_struct.c

ERRSRCS			=	$(ERRDIR)process_errors.c

SRCS			=	$(PARSERSRCS) $(MAINSRCS) $(ERRSRCS) $(RCSTRSRCS) $(HKSSRCS)

OBJS			=	$(patsubst %.c,%.o,$(SRCS))

CCFLAGS			=	-Wall -Wextra -Werror

.c.o:				
					gcc $(CCFLAGS) -c $< -I $(INCLUDES) -I $(MLXDIR) -o $(<:.c=.o) -O2

all:				
				$(MAKE) $(NAME) -j 4

lft:				
					cd $(LIBFTDIR) && make all && make clean

mlx:
					cd $(MLXDIR) && make && mv $(MLX) .. && make clean

$(NAME):			$(OBJS)
					make lft
					#make mlx
					gcc $(CCFLAGS) $? -o $(NAME) -L$(LIBFTDIR) -lft \
						-L. -lmlx -framework OpenGL -framework Appkit

debug:              $(OBJS)
					make lft
					#make mlx
					gcc $(CCFLAGS) -g $? -o $(NAME) -L$(LIBFTDIR) -lft \
						-L. -lmlx -framework OpenGL -framework Appkit

clean:				
					rm -f $(OBJS) $(LIBFTDIR)$(LIBFTNAME) 

fclean:				clean
					@ rm -f $(NAME) 
					#$(MLX)

re:					fclean all

.PHONY:				all clean fclean re
