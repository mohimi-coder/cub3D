CC 						= cc 
FLAGS                   = -Wall -Wextra -Werror -Imlx -Ofast
NAME					= cub3D
NAME_BONUS			    = cub3D_bonus

SRCS					= ./mandatory/raycasting/cub3d.c \
						  ./mandatory/raycasting/player.c \
						  ./mandatory/raycasting/horizontal_inter.c \
						  ./mandatory/raycasting/render.c \
						  ./mandatory/raycasting/vertical_inter.c \
						  ./mandatory/raycasting/utils.c \
						  ./mandatory/raycasting/utils1.c \
						  ./mandatory/raycasting/utils2.c \
						  ./mandatory/raycasting/utils3.c \
						  ./mandatory/raycasting/textures_help.c \
						  ./mandatory/parsing/get_next_line.c \
						  ./mandatory/parsing/get_next_line_utils.c \
                          ./mandatory/parsing/parsing_read_map.c \
                          ./mandatory/parsing/ft_pars.c \
                          ./mandatory/parsing/parsing_helpe1.c \
                          ./mandatory/parsing/parsing_helpe2.c \
                          ./mandatory/parsing/parsing_map.c \
                          ./mandatory/parsing/parsing_map1.c \
                          ./mandatory/parsing/parsing_map2.c \
						  ./mandatory/parsing/parsing_map3.c \
						  ./mandatory/parsing/parsing_helpe3.c \
						  ./mandatory/parsing/mohilloc.c

OBJS					= $(SRCS:.c=.o)

BONUS					= ./bonus/raycasting/cub3d_bonus.c \
						  ./bonus/raycasting/player_bonus.c \
						  ./bonus/raycasting/horizontal_inter_bonus.c \
						  ./bonus/raycasting/render_bonus.c \
						  ./bonus/raycasting/vertical_inter_bonus.c \
						  ./bonus/raycasting/utils_bonus.c \
						  ./bonus/raycasting/utils1_bonus.c \
						  ./bonus/raycasting/utils2_bonus.c \
						  ./bonus/raycasting/utils3_bonus.c\
						  ./bonus/raycasting/utils4_bonus.c\
						  ./bonus/raycasting/utils5_bonus.c\
						  ./bonus/raycasting/minimap_bonus.c \
						  ./bonus/raycasting/textures_help_bonus.c \
						  ./bonus/parsing/get_next_line_bonus.c \
						  ./bonus/parsing/get_next_line_utils_bonus.c \
						  ./bonus/parsing/parsing_read_map_bonus.c \
						  ./bonus/parsing/ft_parsing_bonus.c \
						  ./bonus/parsing/parsing_helpe1_bonus.c \
						  ./bonus/parsing/parsing_helpe2_bonus.c \
						  ./bonus/parsing/parsing_map_bonus.c \
						  ./bonus/parsing/parsing_map1_bonus.c \
						  ./bonus/parsing/parsing_map2_bonus.c \
						  ./bonus/parsing/parsing_map3_bonus.c \
						  ./bonus/parsing/parsing_map4_bonus.c \
						  ./bonus/parsing/parsing_helpe3_bonus.c \
						  ./bonus/parsing/mohilloc_bonus.c

OBJCS_BONUS				= $(BONUS:.c=.o)

all						: $(NAME)

$(NAME)					: $(OBJS)
						  @echo "\033[1;32mLinking $(NAME)...\033[0;m"
						  $(CC) $(FLAGS) -framework OpenGL -framework AppKit libmlx42.a -Iinclude -lglfw -L"$(shell brew --prefix glfw)/lib" $(OBJS) -o $(NAME)

bonus					: $(NAME_BONUS)

$(NAME_BONUS)			: $(OBJCS_BONUS)
						  @echo "\033[1;32mLinking $(NAME_BONUS)...\033[0;m"
						  $(CC) $(FLAGS) -framework OpenGL -framework AppKit libmlx42.a -Iinclude -lglfw -L"$(shell brew --prefix glfw)/lib" $(OBJCS_BONUS) -o $(NAME_BONUS)


bonus/%.o				: bonus/%.c bonus/includes/cub_bonus.h
						  @echo "\033[0;34mCompiling $<...\033[0;m"
						  $(CC) $(FLAGS) -c $< -o $@

mandatory/%.o			: mandatory/%.c mandatory/includes/cub.h
						  @echo "\033[0;34mCompiling $<...\033[0;m"
						  $(CC) $(FLAGS) -c $< -o $@


clean                   :
						 @echo "\033[0;31mRemoving object files.\033[0;m"
						 rm -f $(OBJS) $(OBJCS_BONUS)
						 @echo "\033[1;32mCleaning DONE ✅\033[0;m"


COL_CUBE   = \033[1;36m
COL_TITLE  = \033[1;35m
COL_TXT    = \033[1;37m
COL_SHADOW = \033[1;30m

launch					:
						 clear
						 @echo "$(COL_CUBE)  .–––––––––––––––––––––––––––––––––––––––––––––––––––––––––.	"
						 @echo " / |$(COL_TITLE)           Loading textures, maps, and magic..$(COL_CUBE)          | \	"
						 @echo "+––+––––––––––––––––––––––––––––––––––––––––––––––––––––––––+––+"
						 @echo "|  |$(COL_TXT)             _____       _       _____ ____$(COL_CUBE)             |  |"
						 @echo "|  |$(COL_TXT)            /  __ \     | |     |____ |  _  \ $(COL_CUBE)          |  |"
						 @echo "|  |$(COL_TXT)           |  /  \/_   _| |__       / / | | |$(COL_CUBE)           |  |"
						 @echo "|  |$(COL_TXT)           |  |   | | | | |_ \      \ \ | | |$(COL_CUBE)           |  |"
						 @echo "|  |$(COL_TXT)           |  \__/\ |_| | |_) | ____/ / |_/ /$(COL_CUBE)           |  |"
						 @echo "|  |____________$(COL_TXT)\_____/\____|____/  \____/|____/ $(COL_CUBE)___________|  |"
						 @echo "| / $(COL_SHADOW)           /////// /////////     \\\\\\\\\\\\\\\\\\\ \\\\\\\\\\\\\\\\\\\\\\\\$(COL_CUBE)            \ |"
						 @echo "+––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––+\033[0m"
						 @echo "$(COL_TITLE)by: $(COL_CUBE)zait-bel                   $(COL_TITLE)   &&                      $(COL_CUBE)mohimi"	
fclean                  : clean
						 @echo "\033[0;31mRemoving object files.\033[0;m"
						 rm -f $(NAME) $(NAME_BONUS)
						 @echo "\033[1;32mCleaning DONE ✅\033[0;m"

re                      : fclean all
.PHONY					: clean
