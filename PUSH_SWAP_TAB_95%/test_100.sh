#!/bin/bash

# Génère une liste aléatoire de 500 nombres
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`

echo "Test avec 500 nombres:"
echo "Total pb: $(./push_swap $ARG | grep -c "pb")"
echo "Total pa: $(./push_swap $ARG | grep -c "pa")"
echo "Total ra: $(./push_swap $ARG | grep -c "ra")"
echo "Total rb: $(./push_swap $ARG | grep -c "rb")"
echo "Total rra: $(./push_swap $ARG | grep -c "rra")"
echo "Total rrb: $(./push_swap $ARG | grep -c "rrb")"
echo "Total rr: $(./push_swap $ARG | grep -c "rr$")"
echo "Total rrr: $(./push_swap $ARG | grep -c "rrr")"
echo "Total sa: $(./push_swap $ARG | grep -c "sa")"
echo "Total sb: $(./push_swap $ARG | grep -c "sb")"
echo "Total ss: $(./push_swap $ARG | grep -c "ss")"
echo "Nombre total d'opérations: $(./push_swap $ARG | wc -l)"
echo "Validité: $(./push_swap $ARG | ./checker_linux $ARG)"
