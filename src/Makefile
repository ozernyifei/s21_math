CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11
DEBUG_FLAGS = -pedantic -g -fsanitize=address -fsanitize=leak
MATH = s21_math
OS = $(shell uname -s)

GCOV_FLAGS = -ftest-coverage -fprofile-arcs -fPIC

ifeq ($(OS), Linux)
	ADD_FLAGS += -lm -lpthread -lrt -lsubunit 
	TEST_FLAGS = -lcheck
	OPENER = xdg_open
endif

ifeq ($(OS), Darwin)
	TEST_FLAGS = $(shell pkg-config --cflags --libs check)
	OPENER = open
endif

all: $(MATH).a test gcov_report

s21_math.o: s21_math.c s21_math.h
	$(CC) $(FLAGS) $(ADD_FLAGS) -I./ $<  -c -o $@

$(MATH).a: s21_math.o
	ar rcs $@ s21_math.o



test: $(MATH).c $(MATH).a
	$(CC) $(FLAGS) tests_math.c s21_math.a -o tests_math  $(TEST_FLAGS) $(ADD_FLAGS)
	./tests_math

leak_debug:
	$(CC) $(FLAGS) $(DEBUG_FLAGS) 

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

style_check:
	clang-format -n --style=Google *.[ch]

style_clean:
	clang-format -i --style=Google *.[ch]

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info tests_math
	rm -rf report

rebuild:
	make clean
	make all

gcov_report: test
	$(CC) $(FLAGS) $(GCOV_FLAGS) tests_math.c s21_math.a -o tests_math  $(TEST_FLAGS) $(ADD_FLAGS)
	./tests_math
	lcov -t tests_math -o tests_math.info -c -d . --no-external
	genhtml -o report tests_math.info
	open ./report/index.html



install_check: #needed for mac
	sudo apt update
	sudo apt upgrade
	sudo apt install check
