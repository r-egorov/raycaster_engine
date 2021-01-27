# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cisis <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 16:35:10 by cisis             #+#    #+#              #
#    Updated: 2021/01/27 17:53:20 by cisis            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D
LIBFTNAME		=	libft.a

INCLUDES		=	./includes/

MAINDIR			=	./main/
PARCERDIR		=	./parser/
LIBFTDIR		=	./libft/
ERRDIR			=	./errors/

PARSERSRCS		=	$(PARCERDIR)parser.c $(PARCERDIR)validate_list.c

MAINSRCS		=	$(MAINDIR)main.c

ERRSRCS			=	$(ERRDIR)process_errors.c

SRCS			=	$(PARSERSRCS) $(MAINSRCS) $(ERRSRCS)

OBJS			=	$(patsubst %.c,%.o,$(SRCS))

CCFLAGS			=	-Wall -Wextra -Werror

.c.o:				
					gcc $(CCFLAGS) -c $< -I $(INCLUDES) -o $(<:.c=.o) -O3

all:				$(NAME)

lft:				
					cd $(LIBFTDIR) && make all && make clean

$(NAME):			$(OBJS)
					make lft
					gcc $(CCFLAGS) $? -o $(NAME) -L$(LIBFTDIR) -lft

debug:              $(OBJS)
					make lft
					gcc $(CCFLAGS) -g $? -o $(NAME) -L$(LIBFTDIR) -lft

clean:				
					rm -f $(OBJS) $(LIBFTDIR)$(LIBFTNAME)

fclean:				clean
					@ rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
