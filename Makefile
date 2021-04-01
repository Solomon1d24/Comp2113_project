load_game.o : load_game.cpp load_game.h
			g++ -c load_game.cpp

save_game.o: save_game.cpp save_game.h
		 	g++ -c save_game.cpp

main_program.o: main_program.cpp load_game.h save_game.h
				g++ main_program.cpp


main_program:  main_program.cpp delete_file.cpp save_game.cpp load_game.cpp 
				g++  main_program.cpp delete_file.cpp save_game.cpp load_game.cpp -o main_program

clean:
	rm -f main_program main_program.o load_game.o save_game.o game_status.txt

.PHONY: clean