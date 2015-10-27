NAME	=	Platypus.so

SRC	=	Platypus.cpp

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	=	-I../cpp_ABSharedLibrary/ -fPIC

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		g++ $(OBJ) -o $(NAME) --shared

clean	:	
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
