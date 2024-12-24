#!/bin/bash

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

# Lance les tests pour 100 et 500 nombres
test_size 100
test_size 500
