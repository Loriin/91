NAME	=	91

CC	=	g++

SRC	=	Card.cpp \
		Deck.cpp \
		Engine.cpp \
		Foo.cpp \
		Hand.cpp \
		King.cpp \
		Knight.cpp \
		Mage.cpp \
		main.cpp \
		Module.cpp \
		Noble.cpp \
		Queen.cpp \
		SourcePack.cpp \
		SpellBook.cpp \
		Stikers.cpp \
		Valet.cpp \
		BattleArea.cpp \
		Field.cpp \
		Well.cpp

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
