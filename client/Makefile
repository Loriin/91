NAME	=	bin

CC	=	g++

SRC	=	Engine.cpp \
		main.cpp \
		Module.cpp \
		RPack.cpp \
		Sticker.cpp \
		Game.cpp \
		MainMenu.cpp \
		Tools.cpp \
		GCard.cpp \
		../common/Card.cpp \
		../common/Deck.cpp \
		../common/Randomer.cpp

RM	=	rm -rf

CPPFLAGS	=	-W -Wall -Werror

LIB	=	-L/usr/local/lib

LL	=	-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

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
