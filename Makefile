all: PacMan

PacMan: pacman.o ghost.o maze.o painter.o pellet.o game_engine.o main.o
	g++ -o pacman.exe pacman.o ghost.o maze.o painter.o pellet.o game_engine.o main.o

pacman.o:
	g++ pacman.cpp -o pacman.o -c

ghost.o:
	g++ ghost.cpp -o ghost.o -c

maze.o:
	g++ maze.cpp -o maze.o -c

painter.o:
	g++ painter.cpp -o painter.o -c

pellet.o:
	g++ pellet.cpp -o pellet.o -c

point.o:
	g++ point.cpp -o point.o -c

game_engine.o:
	g++ game_engine.cpp -o game_engine.o -c

main.o:
	g++ main.cpp -o main.o -c

clean:
	del /Q *.o *.exe
