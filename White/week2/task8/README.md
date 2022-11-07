# Средняя температура

### Условие
 
Даны значения температуры, наблюдавшиеся в течение `N` подряд идущих дней. Найдите номера дней (в нумерации с нуля) со значением температуры выше среднего арифметического за все `N` дней.

Гарантируется, что среднее арифметическое значений температуры является целым числом.

### Формат ввода

Вводится число N, затем N неотрицательных целых чисел — значения температуры в `0-й`, `1-й`, ... `(N−1)-й` день.

### Формат вывода

Первое число `K` — количество дней, значение температуры в которых выше среднего арифметического. Затем `K` целых чисел — номера этих дней.

### Пример

#### Ввод

```c++
1   5
2   7 6 3 0 9
```

#### Вывод

```c++
1   3
2   0 1 4
```