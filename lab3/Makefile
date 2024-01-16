all: rebuild

lab3:
	g++ -o lab3 Vector.cpp KitchenCabinet.cpp Item.cpp ItemType.cpp HomeAppliances.cpp Plan.cpp main.cpp

clang:
	clang-format -i *.cpp *.h

clean:
	rm -rf lab3

rebuild:
	make clean
	make clang
	make lab3
	