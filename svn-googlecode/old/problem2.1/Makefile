all:
	g++ -lboost_unit_test_framework container.cpp big_int.cpp big_int_test.cpp -o test
	./test

main:
	g++ main.cpp big_int.cpp container.cpp -o main
	./main
	
clean:
	rm -f *.o main test a.out
