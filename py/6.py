import math
print("введите число")
print("число ")
stop_word = ""
while stop_word != "stop":
    num_fac = int(input())
    print(math.factorial(num_fac))
    print("для остановки прописать - 'Stop' продолжить - 'next'")
    stop_word = str(input())
    if stop_word == "stop":
        break
    else:
        print('введите новое число')
        continue
