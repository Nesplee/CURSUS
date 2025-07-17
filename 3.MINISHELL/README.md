

==========================================================================
				TO_DO_LIST
	-> Liste de tests approfondies (|, ||, &&, (..), (..) &&/|| (..), *.*,)
	-> Tester toutes les commandes
	-> Tester les leaks + fermeture fds
	-> Messages d'erreurs + codes de sorties
	-> Protection contre les crashs
==========================================================================



==========================================================================
			SCHEMA DU PROCESSUS D'EXECUTION D'UNE COMMANDE
==========================================================================

┌───────────────────┐
│     ENTRÉE        │
│  Ligne commande   │
└─────────┬─────────┘
          │
          ▼
┌───────────────────┐												1. ANALYSE LEXICALE
│      LEXER        ├─────────────────────────────┐
└─────────┬─────────┘                             │
          │                                       │
          ▼                                       ▼
┌───────────────────┐                  ┌───────────────────┐
│   TOKENISATION    │                  │  VÉRIFICATIONS    │
│                   │                  │    SYNTAXIQUES    │
│ • Mots            │                  │                   │
│ • Opérateurs      │                  │ • check_operators │
│ • Redirections    │                  │ • check_quotes    │
│ • Variables       │                  │ • check_parens    │
│ • Quotes          │                  │ • check_redirs    │
└─────────┬─────────┘                  │ • check_vars      │
          │                            └─────────┬─────────┘
          │                                      │
          ▼                                      ▼
┌───────────────────────────────────────────────────────┐
│                    VÉRIFICATION                       │
│                     SYNTAXE                           │
└─────────┬─────────────────────────────────┬───────────┘
          │                                 │
          │ Succès                          │ Échec
          ▼                                 ▼
┌───────────────────┐               ┌───────────────────┐
│     PARSER        │               │    AFFICHAGE      │
└─────────┬─────────┘               │     ERREUR        │
          │                         └───────────────────┘
          ▼
┌───────────────────┐												2. ANALYSE SYNTAXIQUE
│    EXPANSION      │
│                   │
│ • Variables       │
│ • Wildcards       │
└─────────┬─────────┘
          │
          ▼
┌───────────────────┐
│   CONSTRUCTION    │
│   ARBRE SYNTAXE   │
│                   │
│ • Commandes       │
│ • Pipes           │
│ • Redirections    │
│ • Opérateurs      │
│   logiques        │
│ • Parenthèses     │
└─────────┬─────────┘
          │
          ▼
┌───────────────────┐												3. EXÉCUTION
│    EXÉCUTEUR      │
└─────────┬─────────┘
          │
          ├───────────────────┐
          │                   │
          ▼                   ▼
┌───────────────────┐  ┌─────────────────────┐
│     BUILTINS      │  │ COMMANDES EXTERNES  │
│                   │  │                     │
│ • echo            │  │ • Recherche chemin  │
│ • cd              │  │ • fork()            │
│ • pwd             │  │ • execve()          │
│ • export          │  │ • wait()            │
│ • unset           │  │                     │
│ • env             │  │                     │
│ • exit            │  │                     │
└─────────┬─────────┘  └──────────┬──────────┘
          │                       │
          ▼                       ▼
┌───────────────────────────────────────────┐
│        GESTION DES OPÉRATEURS             │
│                                           │
│ • Pipes                                   │
│ • Redirections                            │
│ • Opérateurs logiques (&&, ||)            │
│ • Sous-shells (parenthèses)               │
└─────────────────────┬─────────────────────┘
                      │
                      ▼
┌───────────────────────────────────────────┐
│          RÉCUPÉRATION RÉSULTAT            │
│      (Status de sortie des commandes)     │
└─────────────────────┬─────────────────────┘
                      │
                      ▼
┌───────────────────────────────────────────┐
│       NOUVEAU PROMPT / ATTENTE            │
│         NOUVELLE COMMANDE                 │
└───────────────────────────────────────────┘
