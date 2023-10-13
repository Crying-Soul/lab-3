#!/bin/bash


gcc -o lab-3.out main.c

# Проверяем успешность компиляции
if [ $? -eq 0 ]; then
    # Запускаем программу с разными тестами из файла tests
    while IFS= read -r line; do
        if [[ $line == "#"* ]]; then
            # Начало нового теста, выводим название теста
            echo "Running test: $line"
        else
            # Запускаем программу с текущим тестовым входом
            echo "$line" | ./lab-3.out
        fi
    done < tests
else
    echo "Ошибка компиляции программы."
fi

# Удаляем скомпилированный файл после завершения тестов
rm -f lab-3.out

