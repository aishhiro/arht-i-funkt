import random
import string 

def make_password_generator(length):
    chars = string.ascii_letters + string.digits

    paswd = ''
    while length != 0:
        paswd += random.choice(chars)
        length -= 1
    return paswd

print("введите длинну желаемого пароля ")
length = int(input())
gen = make_password_generator(length)
print(gen)
