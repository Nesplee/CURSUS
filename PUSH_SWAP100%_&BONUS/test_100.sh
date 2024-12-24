#!/bin/bash

test_size() {
    local size=$1
    local total_ops=0
    local valid_count=0
    local max_ops=0
    local min_ops=9999999

    echo "Test avec $size nombres (100 iterations):"
    for i in {1..100}
    do
        ARG=$(ruby -e "puts (1..$size).to_a.shuffle.join(' ')")

        # Sauvegarde les instructions dans un fichier temporaire
        ./push_swap $ARG > temp_ops

        # Compte les opérations
        ops=$(wc -l < temp_ops)

        # Met à jour min/max
        if [ $ops -gt $max_ops ]; then
            max_ops=$ops
        fi
        if [ $ops -lt $min_ops ]; then
            min_ops=$ops
        fi

        total_ops=$((total_ops + ops))

        # Vérifie la validité
        if [ "$(cat temp_ops | ./checker $ARG)" == "OK" ]; then
            valid_count=$((valid_count + 1))
        fi
    done

    echo "Moyenne d'opérations: $((total_ops / 100))"
    echo "Minimum d'opérations: $min_ops"
    echo "Maximum d'opérations: $max_ops"
    echo "Tests valides: $valid_count/100"
    echo "----------------------------------------"

    rm temp_ops
}

# Lance les tests pour 100 et 500 nombres
test_size 100
test_size 500
