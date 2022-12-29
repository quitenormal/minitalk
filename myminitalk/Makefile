
SERVER   = server
CLIENT   = client
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra
LIBS	 = -L./libft -lft
LIBFT	 = libft.a

all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) :
	@make -C libft

$(SERVER) : iserver.o
	@$(CC) iserver.o $(LIBS) -o $@
	@printf "\e[38;5;46m./$@ successfully build\e[0m\n"

$(CLIENT) : iclient.o
	@$(CC) iclient.o $(LIBS) -o $@
	@printf "\e[38;5;116m./$@ successfully build\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

clean :
	@make clean -C libft
	@rm -f *.o
	@printf "\e[38;5;216m.o files deleted\e[0m\n"

fclean: clean
	@make fclean -C libft
	@rm -f $(SERVER) $(CLIENT)
	@printf "\e[38;5;210mBinaries deleted\e[0m\n"

re: fclean all
