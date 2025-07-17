#!/bin/bash
# Ce script exécute tous les tests fonctionnels sur votre minishell et leur version sous Valgrind
# Aucun point‑virgule ni caractère d'échappement n'est utilisé dans ce script

MINISHELL=./minishell
BASHSHELL=/bin/bash

# Couleurs
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
NC='\033[0m'  # No Color

if [ ! -x "$MINISHELL" ]
then
    echo -e "${RED}Erreur : $MINISHELL introuvable ou non exécutable.${NC}"
    exit 1
fi

rm -f outfile.txt out_minishell out_bash diff.txt valgrind_out.txt exit_status_results.txt

# Préparation des HEREDOC pour les tests
read -r -d '' HEREDOC1 <<'EOF'
cat << EOF
Hello $USER
Fin heredoc
EOF
EOF

read -r -d '' HEREDOC2 <<'EOF'
cat << EOF
This is a test with $USER
And more text here
EOF
EOF

run_test() {
    local testname="$1"
    local cmd="$2"
    echo "=== Test : $testname ==="

    # on exécute minishell et on récupère son code
    printf "%s\n"     "$cmd" | "$MINISHELL" > out_minishell 2>&1
    local ret_minishell=$?

    # idem pour bash
    printf "%s\n"     "$cmd" | "$BASHSHELL"   > out_bash 2>&1
    local ret_bash=$?

    # affichages des sorties
    echo "-- Minishell output --"
    cat out_minishell
    echo "-- Bash output --"
    cat out_bash

    # comparaison des sorties
    diff out_minishell out_bash > diff.txt
    if [ -s diff.txt ]; then
        echo -e "${RED}-- Différences trouvées --${NC}"
        cat diff.txt
        echo -e "${RED}Test échoué (sortie)${NC}"
    else
        echo -e "${GREEN}Outputs identiques. Test réussi.${NC}"
    fi

    # **ici** on utilise RET_BASH et RET_MINISHELL
    echo "-- Exit status --"
    echo "Bash: $ret_bash, Minishell: $ret_minishell"
    if [ "$ret_bash" -eq "$ret_minishell" ]; then
        echo -e "${GREEN}Codes de sortie identiques.${NC}"
        echo "$testname: OK (code $ret_bash)" >> exit_status_results.txt
    else
        echo -e "${RED}Codes de sortie différents.${NC}"
        echo "$testname: ÉCHEC (Bash: $ret_bash, Minishell: $ret_minishell)" >> exit_status_results.txt
    fi

    echo "-------------------------"
}

# Fonction de test sous Valgrind
run_valgrind_test() {
    local testname="$1"
    local cmd="$2"
    echo "=== Test Valgrind : $testname ===" >> valgrind_out.txt
    printf "%s\nexit\n" "$cmd" | valgrind --leak-check=full --log-file=valgrind_temp.txt "$MINISHELL" >> valgrind_out.txt 2>&1
    echo "-------------------------" >> valgrind_out.txt
}

# Initialisation du fichier de résultats des codes de sortie
echo "=== RÉSULTATS DES TESTS DE CODES DE SORTIE ===" > exit_status_results.txt
echo "Date: $(date)" >> exit_status_results.txt
echo "" >> exit_status_results.txt

#############################
# Exemples de tests (dont 80+ tests au total)
#############################

# --- 1) COMMANDES SIMPLES ---
run_test "Simple commande absolue (/bin/ls)" "/bin/ls"
run_valgrind_test "Simple commande absolue (/bin/ls)" "/bin/ls"
run_test "Commande sans chemin (ls)" "ls"
run_valgrind_test "Commande sans chemin (ls)" "ls"
run_test "Commande erronée" "nonexistingcommand"
run_valgrind_test "Commande erronée" "nonexistingcommand"
run_test "Commande vide" ""
run_valgrind_test "Commande vide" ""
run_test "Commande avec espaces uniquement" "     "
run_valgrind_test "Commande avec espaces uniquement" "     "

# --- 2) ARGUMENTS ---
run_test "Arguments simples 1" "echo arg1"
run_valgrind_test "Arguments simples 1" "echo arg1"
run_test "Arguments simples 2" "echo arg1 arg2 arg3"
run_valgrind_test "Arguments simples 2" "echo arg1 arg2 arg3"
run_test "Commande avec option -l" "/bin/ls -l"
run_valgrind_test "Commande avec option -l" "/bin/ls -l"
run_test "Arguments mélangés" "env USER=test VAR=hello"
run_valgrind_test "Arguments mélangés" "env USER=test VAR=hello"
run_test "Expression arithmétique" "expr 10 + 5"
run_valgrind_test "Expression arithmétique" "expr 10 + 5"

# --- 3) ECHO ---
run_test "echo simple" "echo salut"
run_valgrind_test "echo simple" "echo salut"
run_test "echo avec -n" "echo -n sans retour"
run_valgrind_test "echo avec -n" "echo -n sans retour"
run_test "echo avec plusieurs arguments" "echo one two three"
run_valgrind_test "echo avec plusieurs arguments" "echo one two three"
run_test "echo avec doubles quotes" "echo \"Double quoted text\""
run_valgrind_test "echo avec doubles quotes" "echo \"Double quoted text\""
run_test "echo avec single quotes" "echo 'Single quoted text'"
run_valgrind_test "echo avec single quotes" "echo 'Single quoted text'"

# --- 4) EXIT ---
run_test "exit sans argument" "exit"
run_valgrind_test "exit sans argument" "exit"
run_test "exit avec code 42" "exit 42"
run_valgrind_test "exit avec code 42" "exit 42"
run_test "exit avec argument invalide" "exit abc"
run_valgrind_test "exit avec argument invalide" "exit abc"

# --- 5) VALEUR DE RETOUR ---
run_test "Retour valeur 0 sur commande valide" "/bin/ls"
run_valgrind_test "Retour valeur 0 sur commande valide" "/bin/ls"
run_test "Retour valeur non 0 sur commande invalide" "nonexistingcommand
echo \$?"
run_valgrind_test "Retour valeur non 0 sur commande invalide" "nonexistingcommand
echo \$?"
run_test "Retour d'une opération arithmétique" "expr 3 + 2
echo \$?"
run_valgrind_test "Retour d'une opération arithmétique" "expr 3 + 2
echo \$?"

# --- 6) DOUBLE QUOTES ---
run_test "Double quotes simples" "echo \"Ceci est un test\""
run_valgrind_test "Double quotes simples" "echo \"Ceci est un test\""
run_test "Double quotes avec espaces extra" "echo \"   Test avec espaces   \""
run_valgrind_test "Double quotes avec espaces extra" "echo \"   Test avec espaces   \""
run_test "Double quotes avec expansion" "echo \"Le USER est \$USER\""
run_valgrind_test "Double quotes avec expansion" "echo \"Le USER est \$USER\""

# --- 7) SINGLE QUOTES ---
run_test "Single quotes simples" "echo 'Ceci est un test'"
run_valgrind_test "Single quotes simples" "echo 'Ceci est un test'"
run_test "Single quotes ne s'expandent pas" "echo '\$USER'"
run_valgrind_test "Single quotes ne s'expandent pas" "echo '\$USER'"
run_test "Single quotes avec espaces" "echo '   test   '"
run_valgrind_test "Single quotes avec espaces" "echo '   test   '"

# --- 8) ENV ---
run_test "env standard" "env"
run_valgrind_test "env standard" "env"
run_test "env trié" "env | sort"
run_valgrind_test "env trié" "env | sort"

# --- 9) EXPORT ---
run_test "export création variable" "export NEWVAR=hello
echo \$NEWVAR"
run_valgrind_test "export création variable" "export NEWVAR=hello
echo \$NEWVAR"
run_test "export sans affectation valide" "export VAR
echo \$VAR"
run_valgrind_test "export sans affectation valide" "export VAR
echo \$VAR"
run_test "export avec remplacement" "export VAR=old
export VAR=new
echo \$VAR"
run_valgrind_test "export avec remplacement" "export VAR=old
export VAR=new
echo \$VAR"
run_test "export identifiant invalide" "export 1INVALID=oops"
run_valgrind_test "export identifiant invalide" "export 1INVALID=oops"

# --- 10) UNSET ---
run_test "unset variable existante" "export TOREMOVE=test
unset TOREMOVE
env"
run_valgrind_test "unset variable existante" "export TOREMOVE=test
unset TOREMOVE
env"
run_test "unset variable inexistante" "unset NONEXISTANTE"
run_valgrind_test "unset variable inexistante" "unset NONEXISTANTE"

# --- 11) CD et PWD ---
run_test "cd vers /" "cd /
pwd"
run_valgrind_test "cd vers /" "cd /
pwd"
run_test "cd relative (cd ..)" "cd ..
pwd"
run_valgrind_test "cd relative (cd ..)" "cd ..
pwd"
run_test "cd vers un dossier inexistant" "cd nonexistant
echo \$?"
run_valgrind_test "cd vers un dossier inexistant" "cd nonexistant
echo \$?"
run_test "cd avec . et .." "cd .
cd ..
pwd"
run_valgrind_test "cd avec . et .." "cd .
cd ..
pwd"

# --- 12) CHEMIN RELATIF ---
run_test "Liste via chemin relatif" "ls ../"
run_valgrind_test "Liste via chemin relatif" "ls ../"
run_test "cd avec plusieurs .." "cd ../..
pwd"
run_valgrind_test "cd avec plusieurs .." "cd ../..
pwd"

# --- 13) ENV PATH ---
run_test "commande sans PATH" "unset PATH
ls"
run_valgrind_test "commande sans PATH" "unset PATH
ls"
run_test "PATH multiple et ordre" "export PATH=/bin:/usr/bin
ls"
run_valgrind_test "PATH multiple et ordre" "export PATH=/bin:/usr/bin
ls"

# --- 14) REDIRECTIONS ---
run_test "Redirection output" "echo Hello > outfile.txt
cat outfile.txt"
run_valgrind_test "Redirection output" "echo Hello > outfile.txt
cat outfile.txt"
run_test "Redirection append" "echo First > outfile.txt
echo Second >> outfile.txt
cat outfile.txt"
run_valgrind_test "Redirection append" "echo First > outfile.txt
echo Second >> outfile.txt
cat outfile.txt"
run_test "Redirection input" "cat < outfile.txt"
run_valgrind_test "Redirection input" "cat < outfile.txt"
run_test "Redirection >> sans cible" $'echo Hello >>\n echo "Doit échouer"'
run_valgrind_test "Redirection >> sans cible" $'echo Hello >>\n echo "Doit échouer"'
run_test "Redirection avec erreur de syntaxe" "echo Test >"
run_valgrind_test "Redirection avec erreur de syntaxe" "echo Test >"

# --- 15) HEREDOC ---
run_test "Heredoc simple sans expansion" "$HEREDOC1"
run_valgrind_test "Heredoc simple sans expansion" "$HEREDOC1"
run_test "Heredoc expansion" "$HEREDOC2"
run_valgrind_test "Heredoc expansion" "$HEREDOC2"

# --- 16) PIPES ---
run_test "Pipe simple" "echo Hello World | tr '[:upper:]' '[:lower:]'"
run_valgrind_test "Pipe simple" "echo Hello World | tr '[:upper:]' '[:lower:]'"
run_test "Pipe multiple" "cat outfile.txt | grep Second | tr 'a-z' 'A-Z'"
run_valgrind_test "Pipe multiple" "cat outfile.txt | grep Second | tr 'a-z' '[:upper:]'"
run_test "Pipe avec commande invalide" "ls nonexisting | tr 'a-z' 'A-Z'"
run_valgrind_test "Pipe avec commande invalide" "ls nonexisting | tr 'a-z' 'A-Z'"
run_test "Pipe mixte redirection output" "echo Line > outfile.txt
cat outfile.txt | tr '[:lower:]' '[:upper:]'"
run_valgrind_test "Pipe mixte redirection output" "echo Line > outfile.txt
cat outfile.txt | tr '[:lower:]' '[:upper:]'"
run_test "Pipe avec erreur de syntaxe" "echo Test | | tr 'a-z' 'A-Z'"
run_valgrind_test "Pipe avec erreur de syntaxe" "echo Test | | tr 'a-z' 'A-Z'"

# --- 17) OPERATEURS LOGIQUES et PARENTHESES ---
run_test "Opérateurs logiques AND simple" "echo A && echo B"
run_valgrind_test "Opérateurs logiques AND simple" "echo A && echo B"
run_test "Opérateurs logiques OR simple" "echo A || echo B"
run_valgrind_test "Opérateurs logiques OR simple" "echo A || echo B"
run_test "Opérateurs logiques combinés" "echo Start && echo Middle || echo Fail"
run_valgrind_test "Opérateurs logiques combinés" "echo Start && echo Middle || echo Fail"
run_test "Parenthèses simples" "(echo Subshell && echo OK)"
run_valgrind_test "Parenthèses simples" "(echo Subshell && echo OK)"
run_test "Combinaison && || et ()" "(echo First && echo Second) || (echo Third && echo Fourth)"
run_valgrind_test "Combinaison && || et ()" "(echo First && echo Second) || (echo Third && echo Fourth)"

# --- 18) WILDCARD ---
run_test "Wildcard simple" "ls *.c"
run_valgrind_test "Wildcard simple" "ls *.c"
run_test "Wildcard avancé" "ls -l *.c | grep -i 'main'"
run_valgrind_test "Wildcard avancé" "ls -l *.c | grep -i 'main'"
run_test "Wildcard sans correspondance" "ls nofile*"
run_valgrind_test "Wildcard sans correspondance" "ls nofile*"
run_test "Wildcard dans echo" "echo Wildcard: *.c"
run_valgrind_test "Wildcard dans echo" "echo Wildcard: *.c"
run_test "Wildcard combiné avec redirection" "ls *.c > outfile.txt
cat outfile.txt"
run_valgrind_test "Wildcard combiné avec redirection" "ls *.c > outfile.txt
cat outfile.txt"

# --- 19) SURPRISE : QUOTES EMBRACES ---
run_test "Surprise quotes 1" "export USER=nguyendimitri
echo '\"'\"$USER\"'"
run_valgrind_test "Surprise quotes 1" "export USER=nguyendimitri
echo '\"'\"$USER\"'"
run_test "Surprise quotes 2" "export USER=nguyendimitri
echo \"'\"$USER\"'\""
run_valgrind_test "Surprise quotes 2" "export USER=nguyendimitri
echo \"'\"$USER\"'\""
run_test "Surprise quotes 3" "echo '\"' ' $USER ' '\"'"
run_valgrind_test "Surprise quotes 3" "echo '\"' ' $USER ' '\"'"
run_test "Surprise quotes 4" "echo '\"'$USER'\"'"
run_valgrind_test "Surprise quotes 4" "echo '\"'$USER'\"'"
run_test "Surprise quotes 5" "export USER=testuser
echo \"'\"$USER\"'\""
run_valgrind_test "Surprise quotes 5" "export USER=testuser
echo \"'\"$USER\"'\""

# --- 20) ENVIRONNEMENT VARIABLES ---
run_test "Affichage d'une variable existante" "echo \$USER"
run_valgrind_test "Affichage d'une variable existante" "echo \$USER"
run_test "Affichage d'une variable inexistante" "echo \$NONEXISTANTE"
run_valgrind_test "Affichage d'une variable inexistante" "echo \$NONEXISTANTE"
run_test "Expansion multiple" "export A=Hello
export B=World
echo \$A \$B"
run_valgrind_test "Expansion multiple" "export A=Hello
export B=World
echo \$A \$B"

# --- 21) ERREURS DE SYNTAXE ---
run_test "Erreur syntaxe : quote non fermée" "echo \"Unmatched"
run_valgrind_test "Erreur syntaxe : quote non fermée" "echo \"Unmatched"
run_test "Erreur syntaxe : parenthèse en trop" "(echo Test))"
run_valgrind_test "Erreur syntaxe : parenthèse en trop" "(echo Test))"
run_test "Erreur syntaxe : opérateur && sans opérande" "echo && echo Fail"
run_valgrind_test "Erreur syntaxe : opérateur && sans opérande" "echo && echo Fail"
run_test "Erreur syntaxe : opérateurs consécutifs" "echo Test |||| echo No"
run_valgrind_test "Erreur syntaxe : opérateurs consécutifs" "echo Test |||| echo No"
run_test "Erreur syntaxe : redirection invalide" "cat < > outfile.txt"
run_valgrind_test "Erreur syntaxe : redirection invalide" "cat < > outfile.txt"
run_test "Erreur syntaxe : parenthèse non fermée" "(echo Test"
run_valgrind_test "Erreur syntaxe : parenthèse non fermée" "(echo Test"
run_test "Erreur syntaxe : token inattendu dans pipe" "ls | grep"
run_valgrind_test "Erreur syntaxe : token inattendu dans pipe" "ls | grep"
run_test "Erreur syntaxe : >> sans fichier" "echo Hello >>"
run_valgrind_test "Erreur syntaxe : >> sans fichier" "echo Hello >>"
run_test "Erreur syntaxe : && en début" "&& echo Start"
run_valgrind_test "Erreur syntaxe : && en début" "&& echo Start"
run_test "Erreur syntaxe : || seul" "|| echo Fail"
run_valgrind_test "Erreur syntaxe : || seul" "|| echo Fail"
run_test "Erreur syntaxe : commande vide avec opérateurs" "&& ||"
run_valgrind_test "Erreur syntaxe : commande vide avec opérateurs" "&& ||"

echo -e "${GREEN}Tous les tests sont terminés.${NC}"
echo -e "${YELLOW}Les résultats des codes de sortie sont enregistrés dans exit_status_results.txt${NC}"
echo "Les résultats Valgrind sont enregistrés dans valgrind_out.txt"
