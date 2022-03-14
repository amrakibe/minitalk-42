NAME = minitalk
CC = cc 
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
HEADER = minitalk.h

S_SERVER = server.c
O_SERVER = $(S_SERVER:.c=.o)

S_CLIENT = client.c
O_CLIENT = $(S_CLIENT:.c=.o)

S_MINITALK_UTILE = minitalk_utile.c
O_MINITALK_UTILE = $(S_MINITALK_UTILE:.c=.o)

all: $(NAME)

$(NAME) : $(O_CLIENT) $(O_SERVER) $(O_MINITALK_UTILE)
	$(CC) $(FLAGS) $(O_MINITALK_UTILE) $(O_CLIENT) -o client
	$(CC) $(FLAGS) $(O_MINITALK_UTILE) $(O_SERVER) -o server

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	$(RM) $(O_CLIENT) $(O_SERVER) $(O_MINITALK_UTILE)
fclean: clean
	$(RM) server client
