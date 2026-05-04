print("ввести 2 числа и оператор ( + - * /)")
print("для окончания написать- stop")
stop_word = "none"
while stop_word != "stop":
    num1 = int(input())
    num2 = int(input())
    operator = str(input())
    if operator == "+":
        print(num1+num2)
    elif operator == "-":
        print(num1-num2)
    elif operator == "*":
        print(num1*num2)
    elif operator == "/":
        print(num1/num2)
    print(" закончить - stop , продолжить 'no'")
    stop_word_extra = str(input())
    if stop_word_extra == "stop":
        break
    else:
        print('введите новые числа и оператор')
        continue
