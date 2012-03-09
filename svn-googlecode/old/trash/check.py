a, b = map(int, open('in.txt').read().split())
c = int(open('out.txt').read())
assert c == a / b;
