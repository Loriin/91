NAME	=	server

CC	=	g++

SRC	=	Deck.cpp \
		main.cpp \
		Player.cpp \
		Server.cpp

RM	=	rm -rf

CPPFLAGS	=	-W -Wall -Werror

LIB	=	-L/usr/local/lib

LL	=	-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lsfml-network

OBJ	=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):		$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB) $(LL) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
