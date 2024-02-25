# импортируем библиотеки
import time
import math

# Определяем функцию для вычисления
# Используем функции из библиотеки math для определения наших операций

def compute_expression(x, z, d, b):
   
    # Используем промежуточные переменные, чтобы минимизировать количество операций
    # И предотвратить повторное использование одного и того же кода
    log_b = math.log(b)  
    exp_d2 = math.exp(d**2)
    sin_x_log_z = math.sin(x * math.log(z)) # исправленная строка кода, заменено log_z на math.log(z)

    # Используем промежуточные значения для окончательных вычислений 
    return (2 - 4 * sin_x_log_z**2) / (math.sin(2 * exp_d2 - log_b) + math.sin(2 * exp_d2 + log_b))


# Определение значений переменных
x = 1.2
z = 3.4
d = 5.6
b = 7.8 

# Замеряем текущее время
start = time.time()

# Вызываем нашу функцию и вычисляем выражение
exc_expr = compute_expression(x, z, d, b)

# Замеряем время после выполнения функции
end = time.time()

# Вычисляем разницу между временем начала и окончания, чтобы получить время выполнения функции
computation_time_minimized = end - start

# Выводим окончательные значения
print(f'Вычисленное выражение: {exc_expr}, Время вычисления: {computation_time_minimized}')