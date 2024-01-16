all: rebuild

project:
	g++ -o project main.cpp MathTile.cpp PuzzleNode.cpp PuzzleMap.cpp

clang:
	clang-format -i *.cpp *.h

clean:
	rm -rf project

rebuild:
	make clean
	make clang
	make project
	