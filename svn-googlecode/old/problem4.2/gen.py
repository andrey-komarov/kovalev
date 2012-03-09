from random import randint

out = open('test.txt', 'w').write
n = 100
maxk = 100000

a = [randint(0, maxk) for i in range(n)]

out('typedef ')
out(' '.join('L<%d,'%b for b in a))
out(' EmptyList')
out('> ' * n)
out('list;')
