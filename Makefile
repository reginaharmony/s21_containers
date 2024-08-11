CPPC = gcc
CPP_FLAGS = -Wall -Wextra -Werror -pedantic -std=c++17
TEST_FLAGS = -lgtest -lgmock -pthread -lgtest_main
LIBS = -lstdc++ -lgtest
LIN= -lrt -lpthread -lm 
INCLUDE = s21_containers
TEST_FILES = test_vector.cc

all: test

test:
	 ${CPPC} ${CPP_FLAGS} ${TEST_FLAGS} ${TEST_FILES} -I${INCLUDE} ${LIBS} ${LIN} -o test.out && ./test.out

leaks: test
	leaks -atExit -- ./test.out

valgrind: test
	valgrind --leak-check=yes --show-leak-kinds=all --track-origins=yes ./test.out

style:
	clang-format -style=Google -n ${INCLUDE}/*/*.h ${INCLUDE}/*/*.tpp ${TEST_FILES}
	clang-format -style=Google -i ${INCLUDE}/*/*.h ${INCLUDE}/*/*.tpp ${TEST_FILES}

clean:
	rm -f *.a
	rm -f *.o
	rm -f *.out
	rm -f test
	rm -f .clang-format