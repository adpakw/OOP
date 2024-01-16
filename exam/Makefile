all: rebuild

exam:
	g++ -o exam main.cpp Publication.cpp Book.cpp Article.cpp Journal.cpp Library.cpp

clang:
	clang-format -i *.cpp *.h

clean:
	rm -rf exam

rebuild:
	make clean
	make clang
	make exam
	