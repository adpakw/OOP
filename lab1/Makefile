all: rebuild

lab1:
	g++ -o lab1 Vector.cpp KitchenCabinet.cpp  main.cpp

clang:
	clang-format -i *.cpp *.h

clean:
	rm -rf lab1

rebuild:
	make clean
	make clang
	make lab1