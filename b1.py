def process_words(words):
    lower_words = map(lambda words: words.lower(), words)
    filtered_words = filter(lambda words: len(words) > 3, lower_words)
    return sorted(filtered_words)

user_input = input("введите слова для сортировки :")
words = user_input.split()

result = process_words(words)
print("результат:", result)
