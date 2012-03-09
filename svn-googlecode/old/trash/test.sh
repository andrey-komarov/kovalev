g++ -O2 -Wall problem1.4.cpp -o solve

i=0
while true
do
	python gen.py
	./solve
	python check.py || break
	let i=i+1
	echo $i
	sleep 0.5
done

echo BOTVA
