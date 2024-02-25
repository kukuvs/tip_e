import math

# Функция для вычисления исходного выражения и подсчета времени в у.е.
def calculate_original_expression(x, z, d, b):
    if z <= 0 or b <= 0:
        raise ValueError('z and b must be greater than 0')
    
    log10_z = math.log10(z)  # 13 у.е.
    ln_b = math.log(b)  # 13 у.е.
    exp_d2 = math.exp(d**2)  # 13 у.е.
    
    cos_val = math.cos(2 * x * log10_z)  # 13 у.е.
    sin_val_1 = math.sin(2 * exp_d2 - ln_b)  # 13 у.е.
    sin_val_2 = math.sin(2 * exp_d2 + ln_b)  # 13 у.е.
    
    original_expression = (2 * cos_val) / (sin_val_1 + sin_val_2)  # 7 у.е.
    
    operations_cost = (4 * 13) + 7  # 4 вызова функции и 1 операция деления
    return original_expression, operations_cost

# Функция для вычисления оптимизированного выражения и подсчета времени в у.е.
def calculate_optimized_expression(x, z, d, b):
    if z <= 0 or b <= 0:
        raise ValueError('z and b must be greater than 0')
    
    log10_z = math.log10(z)  # 13 у.е.
    ln_b = math.log(b)  # 13 у.е.
    exp_d2 = math.exp(d**2)  # 13 у.е.
    
    cos_val = math.cos(2 * x * log10_z)  # 13 у.е.
    sin_val = math.sin(2 * exp_d2)  # 13 у.е.
    cos_ln_b = math.cos(ln_b)  # 13 у.е.
    
    optimized_expression = cos_val / (sin_val * cos_ln_b)  # 7 у.е.
    
    operations_cost = (3 * 13) + 7  # 3 вызова функции и 1 операция деления
    return optimized_expression, operations_cost

# Пример значений переменных
x = 1.0  # Значение x
z = 10.0 # Значение z должно быть > 0
d = 1.0  # Значение d
b = 2.71 # Значение b должно быть > 0

# Вычисляем исходное и оптимизированное выражения
original_result, original_cost = calculate_original_expression(x, z, d, b)
optimized_result, optimized_cost = calculate_optimized_expression(x, z, d, b)

# Проверяем совпадение результатов
results_match = math.isclose(original_result, optimized_result, rel_tol=1e-9)

# Вычисляем выигрыш во времени
time_savings = original_cost - optimized_cost

# Выводим результаты
print(f"Исходное выражение: {original_result}")
print(f"Оптимизированное выражение: {optimized_result}")
print(f"Результаты совпадают: {results_match}")
print(f"Исходная стоимость в у.е.: {original_cost}")
print(f"Оптимизированная стоимость в у.е.: {optimized_cost}")
print(f"Выигрыш во времени вычисления в у.е.: {time_savings}")