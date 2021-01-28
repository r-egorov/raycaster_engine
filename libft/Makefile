NAME			=	libft.a

INCLUDES		=	../includes
SRCSDIR			=	srcs/

SRCS			=	$(SRCSDIR)ft_strlen.c		$(SRCSDIR)ft_memset.c  \
					$(SRCSDIR)ft_bzero.c		$(SRCSDIR)ft_memcpy.c  \
					$(SRCSDIR)ft_memmove.c		$(SRCSDIR)ft_memchr.c  \
					$(SRCSDIR)ft_memccpy.c		$(SRCSDIR)ft_memcmp.c  \
					$(SRCSDIR)ft_strlcpy.c		$(SRCSDIR)ft_strlcat.c  \
					$(SRCSDIR)ft_strchr.c		$(SRCSDIR)ft_strrchr.c  \
					$(SRCSDIR)ft_strncmp.c		$(SRCSDIR)ft_atoi.c  \
					$(SRCSDIR)ft_strnstr.c		$(SRCSDIR)ft_isalpha.c  \
					$(SRCSDIR)ft_isdigit.c		$(SRCSDIR)ft_isalnum.c  \
					$(SRCSDIR)ft_isascii.c		$(SRCSDIR)ft_isprint.c  \
					$(SRCSDIR)ft_tolower.c		$(SRCSDIR)ft_toupper.c  \
					$(SRCSDIR)ft_calloc.c		$(SRCSDIR)ft_strdup.c \
					$(SRCSDIR)ft_substr.c		$(SRCSDIR)ft_split.c \
					$(SRCSDIR)ft_strjoin.c		$(SRCSDIR)ft_strtrim.c \
					$(SRCSDIR)ft_itoa.c			$(SRCSDIR)ft_strmapi.c \
					$(SRCSDIR)ft_putchar_fd.c	$(SRCSDIR)ft_putstr_fd.c \
					$(SRCSDIR)ft_putendl_fd.c	$(SRCSDIR)ft_putnbr_fd.c \
					$(SRCSDIR)ft_lstnew.c		$(SRCSDIR)ft_lstadd_front.c \
					$(SRCSDIR)ft_lstsize.c		$(SRCSDIR)ft_lstlast.c \
					$(SRCSDIR)ft_lstadd_back.c	$(SRCSDIR)ft_lstdelone.c \
					$(SRCSDIR)ft_lstclear.c 	$(SRCSDIR)ft_lstiter.c \
					$(SRCSDIR)ft_lstmap.c		$(SRCSDIR)ft_lutoa_base.c \
					$(SRCSDIR)ft_nbrlen.c \
					$(SRCSDIR)get_next_line.c

OBJS			=	$(patsubst %.c,%.o,$(SRCS))

D_FILES			=	$(patsubst %.c,%.d,$(SRCS))

CCFLAGS			=	-Wall -Wextra -Werror

.c.o:				
					@ gcc $(CCFLAGS) -c $< -I $(INCLUDES) -o $(<:.c=.o) -MD

include	$(wildcard $(D_FILES))

all:					$(NAME)

$(NAME):			$(OBJS)
					@ ar rcs $(NAME) $?

clean:				
					@ rm -f $(OBJS) $(D_FILES)

fclean:				clean
					@ rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
