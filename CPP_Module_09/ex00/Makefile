MAKE			= make

NAME 			= btc

_SUCCESS 		= $(GRN)SUCCESS$(D)

SRC_PATH		= .
INC_PATH		= .

FILES			= main.cpp BitcoinExchange.cpp

SRC				= $(addprefix $(SRC_PATH)/, $(FILES))

CC				= c++

CFLAGS			= -Wall -Wextra -Werror -std=c++98 -g

INC				= -I $(INC_PATH)

RM				= rm -rf
AR				= ar rcs
MKDIR_P			= mkdir -p


all: $(NAME)	## Compile

$(NAME): $(SRC)			## Compile
	@echo "$(GOLD)Compiling $(SILV)$(NAME)$(GOLD) mandatory version$(D)"
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "[$(_SUCCESS) compiling $(SILV)$(NAME)$(D) $(GOLD)🖔$(D)]"

clean:				## Remove object files
	@echo "$(GOLD)Cleaning object files$(D)"
	$(RM) $(NAME)
	@echo "$(GOLD)Removing $(SILV)$(BUILD_PATH) $(D) folder & files$(D): $(_SUCCESS)"; \

fclean: clean			## Remove executable and .gdbinit
	@echo "$(GOLD)Cleaning executables$(D)"
	@echo "$(GOLD)Removing $(SILV)$(NAME)$(D) file: $(_SUCCESS)";

re: fclean all	## Purge & Recompile

.PHONY: clean fclean re

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