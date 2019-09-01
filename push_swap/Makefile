# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 15:34:37 by ljonnel-          #+#    #+#              #
#    Updated: 2019/05/06 16:28:14 by ljonnel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_DIRECTORY)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = libft/


HEADERS_LIST = push_swap.h

HEADERS_DIRECTORY = includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = sources/

SOURCES_LIST = check_read.c\
				check_sort.c\
				instr1.c\
				qsort.c\

SOURCES_LIST_PS = push_swap.c
SOURCES_LIST_CH = checker.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
SOURCES_PS = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST_PS))
SOURCES_CH = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST_CH))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_LIST_PS = $(patsubst %.c, %.o, $(SOURCES_LIST_PS))
OBJECTS_LIST_CH = $(patsubst %.c, %.o, $(SOURCES_LIST_CH))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))
OBJECTS_PS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_PS))
OBJECTS_CH = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_CH))

.PHONY: all clean fclean re

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_PS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) $(OBJECTS_PS) -o $(NAME_PS)

$(NAME_CH): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_CH)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) $(OBJECTS_CH) -o $(NAME_CH)

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIRECTORY)/

clean:
	@make -C $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME_PS)
	@rm -f $(NAME_CH)

re:
	@make fclean
	@make all