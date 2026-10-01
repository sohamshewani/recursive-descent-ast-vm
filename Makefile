all: parser vm

parser: src/parser.o include/parser.h
	g++ $^ -o $@ -std=c++17

test_parser: tests/test_parser.o include/parser.h
	g++ $^ -o $@ -std=c++17
	./$@

vm: src/vm.o include/vm.h
	g++ $^ -o $@ -std=c++17

test_vm: tests/test_vm.o include/vm.h
	g++ $^ -o $@ -std=c++17
	./$@

src/parser.o: include/parser.h src/parser.cpp
	g++ -c $< -o $@ -std=c++17

src/vm.o: include/vm.h src/vm.cpp
	g++ -c $< -o $@ -std=c++17

src/ast_node.o: include/ast_node.h src/ast_node.cpp
	g++ -c $< -o $@ -std=c++17

clean:
	rm -f src/*.o tests/*.o parser vm test_parser test_vm
	find . -name '*.gch' -delete
