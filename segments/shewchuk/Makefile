all:
	g++ -Wall -O2 -o segments *.cpp */*.cpp
	python gen.py > input.txt
	time ./segments < input.txt > output.txt

