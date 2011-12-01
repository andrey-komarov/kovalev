all:
	g++ -Wall -pg -o segments *.cpp 
	python gen.py > input.txt
	time ./segments < input.txt > output.txt

