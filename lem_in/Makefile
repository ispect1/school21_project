# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egottlie <egottlie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/01 17:46:28 by egottlie@42       #+#    #+#              #
#    Updated: 2019/06/23 22:16:18 by ljonnel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LEM_IN = lem-in
NAME_VIZ_LEM_IN = viz
SDL2_F	= -framework SDL2 -framework SDL2_image -framework SDL2_ttf -F ./libSDL/
INCLUDE_SDL2 = -I libSDL/SDL2.framework/Headers \
-I libSDL/SDL2_image.framework/Headers \
-I libSDL/SDL2_ttf.framework/Headers
SDL2_P	= -rpath @loader_path/libSDL/
SRC_LEM_IN =  	 src_lem_in/main.c src_lem_in/ft_queue.c src_lem_in/ft_algoritm.c src_lem_in/ft_clear_and_free.c \
			  	 src_lem_in/ft_display_output.c src_lem_in/ft_options_route.c src_lem_in/ft_few_route.c \
			 	 src_lem_in/ft_search_route.c src_lem_in/ft_parse_ants.c src_lem_in/ft_parse_links.c \
			  	 src_lem_in/ft_parse_rooms.c src_lem_in/ft_sort_str.c
SRC_VIZ_LEM_IN = src_viz_lem_in/ft_draw.c src_viz_lem_in/ft_draw2.c src_viz_lem_in/ft_event.c \
				 src_viz_lem_in/ft_init_free.c src_viz_lem_in/ft_parse_ants.c src_viz_lem_in/ft_parse_links.c \
				 src_viz_lem_in/ft_parse_rooms.c src_viz_lem_in/ft_sort_str.c src_viz_lem_in/ft_viz.c src_viz_lem_in/main.c
INCLUDES = include
INCLUDES_PRINTF = printf/include
FLAG = -Wall -Wextra -Werror
all: $(NAME_LEM_IN) $(NAME_VIZ_LEM_IN)
		
$(NAME_LEM_IN):
		@$(MAKE) -C printf
		@gcc -g -L. $(FLAG) $(SRC_LEM_IN) printf/libftprintf.a -I $(INCLUDES_PRINTF) -I $(INCLUDES) -o $(NAME_LEM_IN) $(INCLUDE_SDL2) $(SDL2_P) $(SDL2_F)
$(NAME_VIZ_LEM_IN):
		@gcc -g -L. $(FLAG) $(SRC_VIZ_LEM_IN) printf/libftprintf.a -I $(INCLUDES_PRINTF) -I $(INCLUDES) -o $(NAME_VIZ_LEM_IN) $(INCLUDE_SDL2) $(SDL2_P) $(SDL2_F)
clean:
		@$(MAKE) -C printf fclean
		@/bin/rm -f rm -f *.o

fclean: clean
		@/bin/rm -f $(NAME_LEM_IN) $(NAME_VIZ_LEM_IN)

re: fclean $(NAME_LEM_IN) $(NAME_VIZ_LEM_IN)
