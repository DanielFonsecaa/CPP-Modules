MAKE	= make

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

NAME 			= megaphone

### Message Vars

_SUCCESS 		= $(GRN)SUCCESS$(D)

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_PATH		= .
#INC_PATH		= includes
#LIBS_PATH		= lib
#BUILD_PATH		= mandatory/.build

FILES			=	megaphone.cpp

SRC						= $(addprefix $(SRC_PATH)/, $(FILES))
#OBJS					= $(SRC:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)
#HEADERS					= $(INC_PATH)/cub.h

#==============================================================================#
#                              COMPILER & FLAGS                                #
#==============================================================================#

CC						= c++

CFLAGS				= -Wall -Wextra -Werror -std=c++98 -g

INC						= -I $(INC_PATH)

RM		= rm -rf
AR		= ar rcs
MKDIR_P	= mkdir -p

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#


all: $(NAME)	## Compile

$(NAME): $(SRC)			## Compile
	@echo "$(GOLD)Compiling $(SILV)$(NAME)$(GOLD) mandatory version$(D)"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "[$(_SUCCESS) compiling $(SILV)$(NAME)$(D) $(GOLD)🖔$(D)]"
	@clear
#
#$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS)
#	@mkdir -p $(dir $@)
#	@echo -n "$(GRN)█$(D)"
#	$(CC) $(CFLAGS) $(INC) -c $< -o $@
#
#$(BUILD_PATH):
#	$(MKDIR_P) $(BUILD_PATH)
#	@echo "* $(GOLD)Creating $(SILV)$(BUILD_PATH)$(GOLD) folder:$(D) $(_SUCCESS)"

clean:				## Remove object files
	@echo "$(GOLD)Cleaning object files$(D)"
	@$(RM) $(NAME)
	@$(RM) $(BUILD_PATH);
	@$(RM) $(BONUS_BUILD_PATH);
	@echo "$(GOLD)Removing $(SILV)$(BUILD_PATH) $(D) folder & files$(D): $(_SUCCESS)"; 

fclean: clean			## Remove executable and .gdbinit
	@echo "$(GOLD)Cleaning executables$(D)"
	@$(RM) $(NAME) 
	@$(RM) $(NAME_BONUS);
	@echo "$(GOLD)Removing $(SILV)$(NAME)$(D) file: $(_SUCCESS)"; 

#val: re
#	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck ./$(NAME) $(MAP)

re: fclean all	## Purge & Recompile

.PHONY: clean fclean re

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors

B  		= $(shell tput bold)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
BLU		= $(shell tput setaf 4)

# Extended colors used in your makefile
GOLD    = $(shell tput setaf 220)
SILV    = $(shell tput setaf 250)

# Reset
D       = $(shell tput sgr0)