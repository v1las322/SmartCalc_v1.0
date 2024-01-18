CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
VALGRIND=valgrind --leak-check=full --leak-resolution=med -s
OS:= $(shell uname -s)
LINFLAGS=-lcheck -pthread -lrt -lm -lsubunit
SRCFILE = smart_calc.c 
OBJECTS = smart_calc.o 
TESTS =  test.c

ifeq ($(OS), Linux)
	FLAGS = -lcheck -lm -lpthread -lrt -lsubunit 
	LEAKS = CK_FORK=no valgrind  --leak-check=full  --track-origins=yes  ./test
else
	FLAGS = -lcheck
	LEAKS = leaks -atExit -- ./test
endif

all: clean test

smart_calc.a:
	$(CC) -c $(SRCFILE)
	@ar rcs smart_calc.a $(OBJECTS)
	ranlib smart_calc.a

test: smart_calc.a
ifeq ($(OS), Darwin)
	gcc $(TESTS) smart_calc.a -o test $(shell pkg-config --cflags --libs check) -lcheck -lpthread #-fsanitize=address
	./test
	rm -rf *.o *.a
else
	gcc $(TESTS) smart_calc.a -o test $(LINFLAGS)
	./test
	rm -rf *.o *.a
endif

gcov_report: clean
ifeq ($(OS), Darwin)
	gcc --coverage $(TESTS) -o test $(SRCFILE) $(shell pkg-config --cflags --libs check) -lcheck
	./test
	gcov -f s21_decimal.gcda
	lcov -t "s21_test" -o s21_test.info -c -d .   
	genhtml -o report s21_test.info
	open ./report/index.html
else
	# sudo apt-get install xdg-utils
	gcc --coverage $(TESTS) -o test $(SRCFILE) $(LINFLAGS)
	./test
	gcov -f s21_decimal.gcda
	lcov -t "s21_test" -o s21_test.info -c -d .  
	genhtml -o report s21_test.info
	xdg-open ./report/index.html
endif

install: uninstall
	mkdir -p build
	qmake6 qt_module/smart_calc.pro -o build/Makefile
	cd build; make > /dev/zero 2> /dev/zero

uninstall: clean
	rm -rf build

dist:
	cd .. && tar -czvf smart_calc.tar src

dvi:
	open qt_module/dvi.html

check: clean cppcheck style leaks

cppcheck: test
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

valgrind: test
	CK_FORK=no valgrind  --leak-check=full  --track-origins=yes  ./test
	
style: test
	cp ../materials/linters/.clang-format .clang-format
	clang-format -style=google -n *.c *.h qt_module/*.cpp qt_module/*.h
	rm .clang-format 

leaks: test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./test
	rm -rf smart_calc.o
else
	#sudo dnf install valgrind
	$(VALGRIND) --leak-check=full --show-leak-kinds=all ./test
	rm -rf smart_calc.o
endif

clean:
	rm -rf *.o *.a *.out *.gcda *.gcno 
	rm -rf test a.out
	rm -rf *.info && rm -rf *.gcov
	rm -rf ./report/
	rm -rf ../SmartCalc.tar