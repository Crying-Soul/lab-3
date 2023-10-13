#!/bin/bash


gcc -Wall -Wextra -pedantic -o lab-3.out main.c

if [ $? -eq 0 ]; then
    while IFS= read -r line; do
        if [[ $line == "#"* ]]; then
            echo -e "\033[31mRunning test: $line\033[0m"
        else
            echo "$line" | ./lab-3.out
        fi
	sleep 1.5
    done < tests
else
    echo "Ошибка компиляции программы."
fi

rm -f lab-3.out

