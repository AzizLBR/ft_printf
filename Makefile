# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aloubar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 14:28:54 by aloubar           #+#    #+#              #
#    Updated: 2021/02/18 13:52:53 by aloubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR 	=	obj/

SRC_DIR 	=	srcs/

LIB_DIR 	=	lib/

PRINTF_H	=	-I includes/ft_printf.h

LIBFT_H		= 	-I includes/libft.h

SRCS	 	=	ft_printf.c\
				buffer_managment.c\
				convert_char_string.c\
				ft_printf_utils.c\
				parser_flags.c\
				treat_width.c\
				convert_int.c\

NAME 		=	libftprintf.a

LIBFT_A 	=	libft.a

CC			=	gcc  $(PRINTF_H) $(LIBFT_H) -c -o

CFIND		=	$(SRCS:%=$(SRC_DIR)%)

OFILE		=		$(SRCS:%.c=%.o)

OBJ			=		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: ft_printf Object directory

$(NAME): $(OBJ)
		@echo LIBFT START
		@make -C $(LIB_DIR)
		@echo Copying $(LIBFT_A) to root.
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)
		@echo Merged: $(NAME) with $(LIBFT_A)
		@echo FT_PRINTF COMPLETE

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(CC) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean
		@echo Cleaned ft_printf object files

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo Cleaned $(NAME)

re: fclean all

.PHONY: all clean flcean re
