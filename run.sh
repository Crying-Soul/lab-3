#!/bin/bash


gcc -o lab-3.out main.c

if [ $? -eq 0 ]; then
    while IFS= read -r line; do
        if [[ $line == "#"* ]]; then
            echo "Running test: $line"
        else
            echo "$line" | ./lab-3.out
        fi
    done < tests
else
    echo "Ошибка компиляции программы."
fi

rm -f lab-3.out

