stop_word = ""
while stop_word != "stop":
        print("введите число")
        num = int(input())
        if num < 2:
            print("число не простое")
        elif num == 2: 
            print("число простое")
        elif num == 3:
            print("число прстое")
        else:
            for i in range(2, int(num ** 0.5) + 1):
                if num % i == 0:
                    print("число не простое")
                    break
                else:
                    print("число прстое")
                    break
        print("закончить 'stop' продолжить 'next'")
        stop_word = str(input())
