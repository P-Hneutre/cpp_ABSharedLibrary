NAME	=	ABSharedLibrary

SRC	=	main.cpp

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	=	

LDFLAGS	=	-ldl

all	:	ARMADILLO PLATYPUS $(NAME)

ARMADILLO	:
			make -C ../Armadillo/

PLATYPUS	:
			make -C ../Platypus/

$(NAME)		:	$(OBJ)
			g++ $(OBJ) -o $(NAME) $(LDFLAGS)
			mv $(NAME) ..

clean		:
			rm -rf $(OBJ)
			make clean -C ../Armadillo
			make clean -C ../Platypus

fclean		:	clean
			rm -rf ../$(NAME)
			make fclean -C ../Armadillo
			make fclean -C ../Platypus

re		:	fclean all
		

