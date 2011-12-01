from random import *

seed("segments")

n = 10000

maxk = 1000000000

rnd = lambda : random() * 2 * maxk - maxk

print n
for i in range(n):
	print rnd(), rnd(), rnd(), rnd(), rnd(), rnd(), rnd(), rnd()
