NAME 		=	pipex
# BONUS		=	pipex_b

CC 				=	cc
CFLAGS 			=	-Wall -Wextra -Werror -g3
INCLUDES_DIR 	=	includes/
SRC_DIR 		=	sources/
SRC_BONUS_DIR	=	sources_bonus/
OBJ_DIR 		=	.obj/
OBJ_BONUS_DIR 	=	.obj/
INCLUDES_H		=	-I./$(INCLUDES_DIR)
DEPS 			=	Makefile $(INCLUDES_DIR)pipex.h get_next_line/get_next_line.h

GNL_SRC 		=	$(addprefix get_next_line/, \
					get_next_line.c \
					)

SOURCES 		=	$(addprefix $(SRC_DIR), \
					main.c \
					Utils.c \
					)

SOURCES_BONUS	=	$(addprefix $(SRC_BONUS_DIR), \
					main_bonus.c \
					utils_bonus.c \
					child_bonus.c \
					here_doc_bonus.c \
					) \
					$(GNL_SRC) \

SRC_OBJ			=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o, $(SOURCES))
SRC_BONUS_OBJ 	=	$(patsubst $(SRC_BONUS_DIR)%.c,$(OBJ_BONUS_DIR)%.o, $(SOURCES_BONUS))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES_H) -c -o $@ $<

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.c $(DEPS)
	@mkdir -p $(OBJ_BONUS_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES_H) -c -o $@ $<

$(NAME): $(SRC_OBJ)
	make all -C Libft
	@echo "\e[36mMaking $(NAME)...\e[0m"
	@$(CC) $(CFLAGS) $(INCLUDES_H) $(SRC_OBJ) -LLibft -lft -o $(NAME)
	@echo "\e[32mDone !\e[0m"

bonus: $(SRC_BONUS_OBJ)
	make all -C Libft
	@echo "\e[36mMaking $(NAME) bonus ...\e[0m"
	@$(CC) $(CFLAGS) $(INCLUDES_H) $(SRC_BONUS_OBJ) -LLibft -lft -o $(NAME)
	@echo "\e[32mDone !\e[0m"

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_BONUS_DIR)
	make clean -C Libft
	@echo "\e[31mObject files removed.\e[0m"

fclean:	clean
	@rm -f $(NAME)
	make fclean -C Libft
	@echo "\e[31m$(NAME) removed.\e[0m"
	@rm -f $(BONUS)
	@echo "\e[31m$(BONUS) removed.\e[0m"

re:		fclean all

.PHONY = all bonus clean fclean re