#!/usr/bin/python
from random import *
from sys import argv

seed("segments")

n = 10000
if len(argv) == 2:
	n = int(argv[1])

maxk = 1000000000

rnd = lambda : random() * 2 * maxk - maxk

print n
for i in range(n):
	print rnd(), rnd(), rnd(), rnd(), rnd(), rnd(), rnd(), rnd()
