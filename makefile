tetris-cmd: Tetris-Cmd.o Tetromino.o
	g++ Tetris-Cmd.o Tetromino.o -o tetris-cmd

Tetris-Cmd.o: Tetris-Cmd.cpp
	g++ -c Tetris-Cmd.cpp

Tetromino.o: Tetromino.cpp
	g++ -c Tetromino.cpp

clean:
	del *.o