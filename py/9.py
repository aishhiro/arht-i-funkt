text = input("введите строку \n")
words = text.split()
if len(words) == 0: 
    print("ошибка")
else:
    longest = max(words, key=len) 
    print(f"самое длинное слово: {longest}")
    print(f"его длинна: {len(longest)} символов")
