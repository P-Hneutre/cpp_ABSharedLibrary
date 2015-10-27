all	:
		make -C ./cpp_ABSharedLibrary/	

clean	:
		make clean -C ./cpp_ABSharedLibrary/

fclean	:	clean
		make fclean -C ./cpp_ABSharedLibrary/

re	:	fclean all
		

