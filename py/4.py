print("введите число")
print("вводятся числа, после 'stop' выводит их сумму")
print("число")
stop_word = ""
summ = 0
while stop_word != "stop":
    num = int(input())
    print("продолжить - 'yes' нет - 'stop'")
    stop_word = str(input())
    if stop_word == "stop":
        summ = summ + num
        print(summ)
        break
    else:
        summ = summ + num
        print('введите новое число')
        continue
