SERVER_NAME = server
CLIENT_NAME = client
CC = cc
FLAG = -Wall -Werror -Wextra
INC = -I ./inc

SERVER_FILES = $(addprefix src/, error_handle server)
CLIENT_FILES = $(addprefix src/, error_handle client)

SERVER_SRCS = ${SERVER_FILES:=.c}
CLIENT_SRCS = ${CLIENT_FILES:=.c}

all :
	@echo "Usage : make [Option]\n"
	@echo "Option:"
	@echo "     server  make chat server"
	@echo "     client  make chat client"

server :
	${CC} ${SERVER_SRCS} ${INC} -o ${SERVER_NAME}

client :
	${CC} ${CLIENT_SRCS} ${INC} -o ${CLIENT_NAME}

fclean :
	rm -f ${SERVER_NAME} ${CLIENT_NAME}

re : fclean server client

.PHONY : all clean fclean re
