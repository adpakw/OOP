all: rebuild

project:
	g++ -o project test.cpp MathTile.cpp

clang:
	clang-format -i *.cpp *.h

clean:
	rm -rf project

rebuild:
	make clean
	make clang
	make project
	