#!/bin/bash

test_memory_leaks() {
    local size=$1
    echo "Test des fuites mémoire avec $size nombres..."

    # Génère un jeu de test
    ARG=$(ruby -e "puts (1..$size).to_a.shuffle.join(' ')")

    # Lance valgrind et sauvegarde le résultat
    valgrind --leak-check=full \
             --show-leak-kinds=all \
             --track-origins=yes \
             --verbose \
             --log-file="valgrind_$size.log" \
             ./push_swap $ARG >/dev/null

    echo "Résultats de valgrind sauvegardés dans valgrind_$size.log"
    echo "----------------------------------------"
}

test_size() {
    local size=$1
    local total_ops=0
    local valid_count=0

    echo "Test avec $size nombres (100 iterations):"
    for i in {1..100}
    do
        ARG=$(ruby -e "puts (1..$size).to_a.shuffle.join(' ')")

        # Compte les opérations
        ops=$(./push_swap $ARG | wc -l)
        total_ops=$((total_ops + ops))

        # Vérifie la validité
        if [ "$(./push_swap $ARG | ./checker_linux $ARG)" == "OK" ]; then
            valid_count=$((valid_count + 1))
        fi
    done

    echo "Moyenne d'opérations sur 100 tests: $((total_ops / 100))"
    echo "Tests valides: $valid_count/100"
    echo "----------------------------------------"
}

# Tests de performance
echo "=== Tests de Performance ==="
test_size 100
test_size 500

# Tests de fuites mémoire
echo "=== Tests de Fuites Mémoire ==="
test_memory_leaks 100
test_memory_leaks 500
