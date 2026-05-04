print("введите число")
stop_word = ""
while stop_word != "stop":
    num = int(input())
    if num % 2 == 0:
        print("четно")
    else:
        print("нечетно")
    print("окончить - 'stop' продолжить - 'next'")
    stop_word = str(input())
    if stop_word == "stop":
        break
    else:
        print('введите новое число')
        continue
