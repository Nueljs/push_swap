# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macerver <macerver@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 18:35:31 by macerver          #+#    #+#              #
#    Updated: 2026/02/05 12:06:18 by macerver         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := push_swap.a
CC := cc
CFLAGS := -Wall -Werror -Wextra -I. -Ift_printf
SRC = push_swap.c

FT_PRINTF_SRC = ft_printf/ft_printf.c ft_printf/ft_putunbr.c ft_printf/ft_pvoid.c \
	ft_printf/hex_nlower.c ft_printf/hex_nupper.c ft_printf/printf_putchar.c \
	ft_printf/printf_putnbr.c ft_printf/printf_putstr.c

UTILS_SRC = utils/ft_atoi.c utils/ft_strchr.c utils/ft_split.c utils/ft_lstadd_back.c \
	utils/ft_lstnew.c utils/ft_isnumber.c utils/ft_substr.c utils/ft_strlen.c utils/ft_strdup.c\
	utils/check_doubles.c utils/swap.c utils/sa.c utils/sb.c utils/ss.c utils/ft_lstadd_front.c\
	utils/rrotate.c utils/rra.c utils/rrb.c utils/rrr.c utils/pb.c utils/pa.c utils/push.c


SRC += $(FT_PRINTF_SRC)
SRC += $(UTILS_SRC)
OBJ = $(SRC:.c=.o)

AR := ar rcs
RM := rm -f

all: $(NAME)
$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c 
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJ)
	$(AR) $(NAME) $^

.PHONY: all clean fclean re