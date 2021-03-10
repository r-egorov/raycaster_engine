# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cisis <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 16:35:10 by cisis             #+#    #+#              #
#    Updated: 2021/03/10 16:35:29 by cisis            ###   ########.fr        #
#    Updated: 2021/02/03 18:01:18 by cisis            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

INCLUDES		=	includes/

LIBFTDIR		=	libft/
LIBFT			=	$(LIBFTDIR)libft.a

MLXDIR			=	minilibx/
MLX				=	$(MLXDIR)libmlx.a

MAINDIR			=	main/
PARCERDIR		=	parser/
ERRDIR			=	errors/
RCSTRDIR		=	raycaster/
HKSDIR			=	hooks/
SRCSDIR			=	srcs/

PARSERSRCS		=	$(PARCERDIR)parse_file.c $(PARCERDIR)validate_list.c \
					$(PARCERDIR)free_memory.c $(PARCERDIR)validate_parameter.c \
					$(PARCERDIR)validate_resolution.c $(PARCERDIR)validate_texture.c \
					$(PARCERDIR)valid_number_params.c $(PARCERDIR)validate_colour.c \
					$(PARCERDIR)validate_map.c $(PARCERDIR)valid_zero_map.c \
					$(PARCERDIR)valid_space_map.c $(PARCERDIR)append_sprite.c \
					$(PARCERDIR)make_map.c

RCSTRSRCS		=	$(RCSTRDIR)drawing_utils.c $(RCSTRDIR)init_player.c\
					$(RCSTRDIR)calculate_plr_pos.c $(RCSTRDIR)raycasting_wall.c \
					$(RCSTRDIR)get_textures.c $(RCSTRDIR)raycasting_wall_drawing.c  \
					$(RCSTRDIR)raycasting_floor_ceiling.c $(RCSTRDIR)raycasting_sprites.c \
					$(RCSTRDIR)raycasting_sprites_drawing.c

HKSSRCS		=		$(HKSDIR)infinite_hook.c \
					$(HKSDIR)key_pressed_hook.c

MAINSRCS		=	$(MAINDIR)main.c $(MAINDIR)init_struct.c \
					$(MAINDIR)close.c $(MAINDIR)init_txtrs.c \
					$(MAINDIR)init_dda.c $(MAINDIR)make_screenshot.c

ERRSRCS			=	$(ERRDIR)process_errors.c

SRCS			=	$(PARSERSRCS) $(MAINSRCS) $(ERRSRCS) $(RCSTRSRCS) $(HKSSRCS)

SRCS 			:=	$(addprefix $(SRCSDIR), $(SRCS))

OBJS			=	$(patsubst %.c,%.o,$(SRCS))

DFILES			=	$(patsubst %.c,%.d,$(SRCS))

CCFLAGS			=	-Wall -Wextra -Werror

.c.o:				
					@ gcc $(CCFLAGS) -c -MD $< -I $(INCLUDES) -I $(MLXDIR) -o $(<:.c=.o) -O2

include $(wildcard $(D_FILES))

all:				$(NAME)

$(LIBFT):
					@ echo " >>> Compiling libft... <<< "
					@ $(MAKE) -C $(LIBFTDIR)
					@ $(MAKE) clean -C $(LIBFTDIR)
					@ echo " >>> Libft compiled <<< "
					
$(MLX):
					@ echo " >>> Compiling minilibx... <<< "
					@ $(MAKE) -C $(MLXDIR)
					@ echo " >>> Minilibx compiled <<< "

$(NAME):			$(LIBFT) $(MLX) $(OBJS)
					@ echo " >>> Compiling cub3D... <<< "
					@ gcc $(CCFLAGS) $(OBJS) -o $(NAME) -L$(LIBFTDIR) -lft \
						-L$(MLXDIR) -lmlx -framework OpenGL -framework Appkit -ggdb -fsanitize=address -fno-omit-frame-pointer
					@ echo " >>> cub3D compiled <<< "

debug:				$(LIBFT) $(MLX) $(OBJS)
					@ echo " >>> Compiling cub3D... <<< "
					@ gcc $(CCFLAGS) $(OBJS) -o $(NAME) -L$(LIBFTDIR) -lft \
						-L$(MLXDIR) -lmlx -framework OpenGL -framework Appkit -g
					@ echo " >>> cub3D compiled <<< "

clean:				
					@ rm -f $(DFILES) $(OBJS) $(LIBFT) $(MLX)
					@ $(MAKE) clean -C $(MLXDIR)
					@ echo " >>> Deleted dependencies <<< "

fclean:				clean
					@ rm -f $(NAME) 
					@ echo " >>> Deleted executable <<< "

re:					fclean all

.PHONY:				all clean fclean re debug
