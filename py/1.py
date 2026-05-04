
start = input("введжите начало (чч:мм): ")
end = input("окончание собатия (чч:мм): ")

start_h, start_m = map(int, start.split(":"))
end_h, end_m = map(int, end.split(":"))  #разделение на 2 переменные

start_total = start_h * 60 + start_m
end_total = end_h * 60 + end_m

if end_total < start_total:
    end_total += 24 * 60
duration = end_total - start_total
hours = duration // 60
minutes = duration % 60
print(f"длительность: {hours} ч {minutes} м")
