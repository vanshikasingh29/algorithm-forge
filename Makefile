CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -std=c17 -g

INCLUDE = -Iinclude

PROGRAM = algorithm_forge

ALGORITHM_TEST = algorithm_tests
GRAPH_TEST = graph_tests
DP_TEST = dp_tests
GREEDY_TEST = greedy_tests
AVL_TEST = avl_tests

SOURCES = \
	src/main.c \
	src/algorithms.c \
	src/graph.c \
	src/dp.c \
	src/greedy.c \
	src/avl.c

all:
	$(CC) $(CFLAGS) $(INCLUDE) $(SOURCES) -o $(PROGRAM)

run: all
	./$(PROGRAM)

test-algorithms:
	$(CC) $(CFLAGS) $(INCLUDE) \
	tests/test_algorithms.c \
	src/algorithms.c \
	-o $(ALGORITHM_TEST)

	./$(ALGORITHM_TEST)

test-graph:
	$(CC) $(CFLAGS) $(INCLUDE) \
	tests/test_graph.c \
	src/graph.c \
	-o $(GRAPH_TEST)

	./$(GRAPH_TEST)

test-dp:
	$(CC) $(CFLAGS) $(INCLUDE) \
	tests/test_dp.c \
	src/dp.c \
	-o $(DP_TEST)

	./$(DP_TEST)

test-greedy:
	$(CC) $(CFLAGS) $(INCLUDE) \
	tests/test_greedy.c \
	src/greedy.c \
	-o $(GREEDY_TEST)

	./$(GREEDY_TEST)

test-avl:
	$(CC) $(CFLAGS) $(INCLUDE) \
	tests/test_avl.c \
	src/avl.c \
	-o $(AVL_TEST)

	./$(AVL_TEST)

test-all: test-algorithms test-graph test-dp test-greedy test-avl

advanced-graph-tests:
	$(CC) $(CFLAGS) \
	tests/test_advanced_graph.c \
	src/bellman_ford.c \
	src/floyd_warshall.c \
	src/astar.c \
	-Iinclude \
	-o advanced_graph_tests
	./advanced_graph_tests

benchmark-search:
	$(CC) $(CFLAGS) \
	benchmarks/benchmark_search.c \
	-o search_benchmark
	./search_benchmark


clean:
	rm -f \
	$(PROGRAM) \
	$(ALGORITHM_TEST) \
	$(GRAPH_TEST) \
	$(DP_TEST) \
	$(GREEDY_TEST) \
	$(AVL_TEST) \
	benchmark \
	*.o
clean:
	rm -f algorithm_forge advanced_graph_tests

clean:
	rm -f algorithm_forge \
	      advanced_graph_tests \
	      search_benchmark \
	      algorithm_tests \
	      test_engine \
	      set_tests \
	      relation_tests \
	      function_tests


.PHONY: all run \
test-algorithms \
test-graph \
test-dp \
test-greedy \
test-avl \
test-all \
clean
