#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'

run_test() {
    echo -e "${BLUE}Test: $1${NC}"
    echo -e "Expected: $2"
    for i in {1..3}; do
        echo -e "${GREEN}Run $i${NC}"
        timeout 10 ./philo $3
        sleep 1
        echo "----------------------------------------"
    done
}

# Compilation
make re

# Tests obligatoires
run_test "1 philosophe (doit mourir)" "Mort après ~800ms" "1 800 200 200"
run_test "5 philosophes sans mort" "Pas de mort" "5 800 200 200"
run_test "5 philosophes - 7 repas" "Stop après 7 repas" "5 800 200 200 7"
run_test "4 philosophes - pas de mort" "Pas de mort" "4 410 200 200"
run_test "4 philosophes - mort" "Un mort après ~310ms" "4 310 200 100"
run_test "2 philosophes - timing précis" "Mort < 10ms retard" "2 100 200 200"

# Tests supplémentaires
run_test "3 philosophes" "Pas de mort" "3 800 200 200"
run_test "5 philosophes - 5 repas" "Stop après 5 repas" "5 800 200 200 5"

# Test avec valgrind
echo -e "${BLUE}Test mémoire avec valgrind${NC}"
valgrind --leak-check=full --show-leak-kinds=all ./philo 4 410 200 200
