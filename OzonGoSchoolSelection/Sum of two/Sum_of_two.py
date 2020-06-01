fin = open('input.txt', 'r', encoding='utf8')
fout = open('output.txt', 'w', encoding='utf8')
target = int(fin.readline())
arr = [int(i) for i in fin.readline().split() if int(i) <= target]
f1 = False
print(arr)
fin.close()

arr.sort()
left = 0
right = len(arr) - 1

while left < right:
    cur = arr[left] + arr[right]
    if cur == target:
        f1 = True
        left += 1
        right -= 1
    else:
        if cur < target:
            left += 1
        else:
            right -= 1
if f1:
    print(1, file=fout)
else:
    print(0, file=fout)
fout.close()
