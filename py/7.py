from random import randint
random_number = randint(1, 100)
print("было загадано число, задача - угадать")
print(" если число неверно - будет подсказщка")
user_num = 0
while user_num != random_number:
    user_num = int(input())
    if user_num < random_number:
        print("слишком маленькое")
    elif user_num > random_number:
        print("слишком большое")
    else:
        print("верно, число - " + str(user_num))
