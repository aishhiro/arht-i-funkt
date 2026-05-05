meters = float(input("введите метры для перевода в футы , дюймы , ярды""\n"))
feet = meters * 3.28084
inches = meters * 39.3701
yards = meters * 1.09361
print(f"{meters} м = {feet:.2f} фут")
print(f"{meters} м = {inches:.2f} дюймов")
print(f"{meters} м = {yards:.2f} ярд")
