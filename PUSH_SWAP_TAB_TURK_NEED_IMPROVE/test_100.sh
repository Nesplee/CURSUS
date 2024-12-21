#!/bin/bash

echo "=== Test avec 100 nombres ==="
# Générer 100 nombres aléatoires
ARG=$(python3 -c "import random; print(' '.join(str(x) for x in random.sample(range(-1000, 1000), 100)))")

echo "1. Nombres générés:"
echo $ARG

echo -e "\n2. Nombre d'opérations:"
./push_swap $ARG | wc -l

echo -e "\n3. Vérification du tri:"
./push_swap $ARG | ./checker_linux $ARG

# Sauvegarder les opérations dans un fichier
echo -e "\n4. Opérations sauvegardées dans operations.txt"
./push_swap $ARG > operations.txt
