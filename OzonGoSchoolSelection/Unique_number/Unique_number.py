fin = open('input-201.txt', 'r', encoding='utf8')
a = []
for line in fin:
    a.append(int(line))

sum = 0
for w in a:
    sum ^= w

print(sum)