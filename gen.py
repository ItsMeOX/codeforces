import random

with open('out.txt', 'w') as f:
    f.write('20000\n')
    for i in range(20000):
        f.write(str(2) + ' ')
    