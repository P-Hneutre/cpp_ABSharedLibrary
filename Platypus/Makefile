NAME	=	Platypus.so

SRC	=	Platypus.cpp

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	=	-I../cpp_ABSharedLibrary/ -fPIC

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		g++ $(OBJ) -o $(NAME) --shared
		mv $(NAME) ../plugins/

clean	:	
		rm -f $(OBJ)

fclean	:	clean
		rm -f ../plugins/$(NAME)

re	:	fclean all
