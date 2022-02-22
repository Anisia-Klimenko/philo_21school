NAME	=	philo

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

OBJDIR	=	obj
SRCDIR	=	src
LIBDIR	=	$(SRCDIR)/libft

HEADER	=	philo.h

SRC		=	$(SRCDIR)/main.c	\
			$(SRCDIR)/args.c	\
			$(SRCDIR)/time.c	\
			$(SRCDIR)/utils.c	\
			$(SRCDIR)/utils2.c	\
			$(SRCDIR)/threads.c	\
			$(SRCDIR)/routine.c	\
			$(LIBDIR)/ft_strlen.c	\
			$(LIBDIR)/ft_isdigit.c	\
			$(LIBDIR)/ft_atoi.c	\
			$(LIBDIR)/ft_strncmp.c

OBJ		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

GRN 	=	\033[0;32m
RED 	=	\033[0;31m
YEL 	=	\033[1;33m
END 	=	\033[0m
TICK	=	\xE2\x9C\x94

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "\n\t$(GRN) $(TICK) PHILO compiled!$(END)\n"

$(OBJDIR)/$(SRCDIR)/%.o: 	$(SRCDIR)/%.c $(HEADER) Makefile
		@$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)/$(LIBDIR)/%.o: 	$(LIBDIR)/%.c $(HEADER) Makefile
		@$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR) :
		@mkdir $@ $@/$(SRCDIR) $@/$(LIBDIR)

$(OBJ) : | $(OBJDIR)

clean:
		@rm -rf $(OBJDIR)
		@echo "$(RED)clean ...$(END)"
fclean: clean
		@rm -f $(NAME)
		@echo "$(RED)fclean ...$(END)"
re: 	fclean all
