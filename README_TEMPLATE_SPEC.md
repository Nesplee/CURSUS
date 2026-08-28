# README Template Spec — 42 Cursus Portfolio

Ce document fige le template validé sur **LIBFT** (repo `Nesplee/LIBFT`) pour être répliqué
sur les 12 autres projets : BORN2BEROOT, CPP, CUB3D, FT_PRINTF, GNL, INCEPTION, MINISHELL,
NET_PRACTICE, PHILOSOPHERS, PIPEX, PUSH_SWAP, SO_LONG.

Objectif : README de niveau pro, en anglais, pour un contexte de recherche d'emploi.
Chaque repo garde son propre README **totalement autonome** — jamais de référence à la
structure interne d'un autre projet (voir règle dure en bas de page).

Fichiers de référence dans ce dossier (`templates/`) :
- `LIBFT_README_reference.md` — le README final complet, à utiliser comme gabarit de structure.
- `divider.png` — l'asset de séparation, **littéralement le même fichier** à copier tel quel
  dans chaque repo (ne pas régénérer, ne pas modifier les couleurs).
- `scripts/make_hero.py` — génère la bannière (photo + fondu + titre).
- `scripts/make_badge.py` — génère les petits encadrés bordeaux de catégorie.

---

## 1. Langue, ton, profondeur

- Anglais exclusivement.
- Ton professionnel, orienté recruteur — jamais scolaire/student.
- Contenu "complet et pédagogique" : on explique le POURQUOI d'une contrainte technique
  (Norme 42, gestion mémoire, edge cases), pas juste la liste des fonctions.
- **Zéro tiret cadratin (—) et zéro double-tiret (--) dans les phrases.** Utiliser un point,
  une virgule ou un deux-points à la place. C'est une règle stricte, vérifiée sur tout le texte.
- Pas d'emoji dans les titres ou le texte courant (les icônes GFM des alertes suffisent).

## 2. Structure globale (ordre des sections)

1. Hero banner + tagline + badges + nav (voir §3, 4, 5)
2. `Overview` — pitch du projet, 2 paragraphes + lien vers le sujet PDF
3. `Highlights` — 4 puces avec phrase d'intro, jamais une liste de fragments sans contexte
4. `Build & Usage` — blocs de commande réels (`make`, flags, exemple d'exécution)
5. `Design Notes` (ou nom pertinent au projet) — alertes GFM sur les contraintes/pièges
6. `<Nom> Structure` — arborescence du repo en bloc ```text```, PAS de tableau Fichier/Rôle
7. `Function/Feature Reference` (si pertinent au projet) — voir §6
8. `Skills Developed` — tableau Learning Outcome / Piscine Skill Area
9. `Result` — capture de note/validation
10. Footer — `42 Lausanne · <Cursus>` centré

Chaque section (sauf le hero) est précédée d'un `<img src=".assets/divider.png" width="100%" alt="" />`
et son titre est un `<h2 align="center">Titre</h2>` précédé d'une ancre `<a name="slug"></a>`
(nécessaire car un `<h2>` HTML brut n'obtient pas d'ancre automatique sur GitHub, contrairement
à un titre `## Markdown`).

## 3. Bannière (hero image)

- Une bannière par projet, générée à partir d'une illustration existante du projet
  (`.assets/Illu_*.jpg` ou équivalent déjà présent dans chaque repo).
- Générée avec `scripts/make_hero.py` (police Neue Haas Grotesk Display, déjà installée
  localement dans `~/.fonts/Neue_haas_grotesk/`).
- Format : 1400×600, cover-crop de la photo source, fondu noir progressif (smoothstep)
  dans le tiers bas de l'image pour que le texte reste lisible.
- Titre = nom du projet en majuscules, `NeueHaasDisplay-Bold`, blanc, **contour noir fin
  (`stroke_width=2`)** pour qu'il ressorte sur n'importe quelle photo.
- Sous-titre = une accroche courte du type "C FUNCTION LIBRARY" (2-4 mots, majuscules,
  décrit ce qu'est le projet plutôt que de répéter "42 CURSUS"), `NeueHaasDisplay-Roman`,
  **gris clair `(210, 213, 218)`** (jamais de bleu/teal), **contour noir plus marqué
  (`subtitle_stroke_width=3`)** pour la lisibilité.
- Marge basse : le sous-titre doit se terminer à ~54px du bord bas de l'image (`bottom_margin=54`),
  jamais collé au bord.
- Commande type :
  ```bash
  python3 templates/scripts/make_hero.py <PROJECT>/.assets/Illu_source.jpg <PROJECT>/.assets/banner.png "TITRE" "SOUS-TITRE"
  ```

## 4. Divider (séparateur de section)

- **Un seul asset, partagé tel quel** entre tous les repos : `templates/divider.png`
  (1400×12px, deux bandes fines : gris `(74,79,87)` et bordeaux `(99,33,42)`, fond
  `(13,17,23)` assorti au thème sombre de GitHub).
- Copier ce fichier dans `<PROJECT>/.assets/divider.png` sans le régénérer ni changer les couleurs.
- Utilisé exclusivement comme `<img src=".assets/divider.png" width="100%" alt="" />` entre
  chaque section. Ne jamais utiliser de `---` Markdown brut (rendu trop discret).

## 5. Badges et nav

### 5.1 Badges d'en-tête (sous le tagline)
Reprendre exactement le même jeu que LIBFT (shields.io, `style=for-the-badge`) :
- Badge école (logo 42, cliquable vers `https://42lausanne.ch`)
- Badge langage principal du projet (couleur officielle du langage)
- Badge Norminette (si applicable) : `passing` en vert `2ea44f`
- Badge note : `grade-XXX%2F100` en teal `5ec8c5`

### 5.2 Nav de sections (pills grises)
- Une pill par section (`Overview`, `Highlights`, etc.), générée via shields.io :
  `https://img.shields.io/badge/-<Nom>-2b3137?style=flat-square`
- **Ne jamais les envelopper dans un `<a href="#...">`** : ce sont des pills purement
  visuelles, non cliquables (demande explicite : "les badges ne doivent pas être cliquables").
  Elles reproduisent le sommaire, elles ne servent pas de navigation fonctionnelle.

### 5.3 Badges de catégorie (dans un tableau de référence)
- Générés via `scripts/make_badge.py <"Titre">  <chemin_sortie.png>` : encadré fin
  (`stroke≈1.4px` à l'échelle finale), coins arrondis (`radius=6`), **fond transparent
  (pas de remplissage rouge/bordeaux plein)**, bordure et texte bordeaux `(99,33,42)` /
  `(210,160,165)`.
- Taille : `height="22"` à l'affichage (le script sur-échantillonne ×4 pour rester net).
- Chaque projet régénère ses propres badges avec ses propres intitulés de catégorie
  (le style reste identique, le texte change) — stockés dans `<PROJECT>/.assets/badges/`.
- Toujours en simple `<img>`, jamais de lien : ce sont des titres de section dans un
  tableau, pas des liens.

## 6. Tableaux (Function/Feature Reference)

Point le plus itéré de la conversation — retenir la leçon technique suivante :

> **GitHub applique `width: max-content` en CSS à tous les `<table>` du markdown-body.**
> Cette règle écrase l'attribut HTML `width="100%"`. Résultat : si on découpe un
> tableau de référence en plusieurs petits tableaux indépendants (un par catégorie,
> par exemple dans des `<details>` séparés pour les rendre pliables), **chaque tableau
> se redimensionne sur son propre contenu** et ils n'ont jamais la même largeur d'une
> catégorie à l'autre. C'est visuellement le défaut n°1 signalé plusieurs fois dans
> cette conversation.

**Règle à appliquer partout : un seul `<table>` continu pour toute la référence**,
avec des lignes de séparation de catégorie à l'intérieur (pas des tableaux séparés) :

```html
<table width="100%">
<tr><th width="26%">Function</th><th>Purpose</th></tr>
<tr><td colspan="2" align="right"><img src=".assets/badges/xxx.png" height="22" alt="Category Name" /></td></tr>
<tr><td align="center"><a href="ft_foo.c"><code>ft_foo</code></a></td><td>Description</td></tr>
...
</table>
```

- Une seule table = alignement garanti quel que soit le nombre de lignes par catégorie.
- Le nom de fonction est toujours un lien vers son fichier source (`<a href="fichier.c">`),
  sauf s'il n'existe littéralement pas de fichier dédié.
- **Vérifier systématiquement que chaque fonction listée a un fichier réel** avant de
  poser le lien (erreur commise deux fois sur LIBFT : `ft_putchar`/`ft_putstr`/`ft_putnbr`
  avaient bien leurs propres `.c` et n'étaient pas liés par oubli).
- Une table pliable par catégorie (`<details>`) a été testée et **abandonnée** : en plus
  du problème de largeur ci-dessus, `<details>` ne peut techniquement pas contrôler la
  visibilité de lignes `<tr>` qui ne lui appartiennent pas directement (testé et confirmé
  empiriquement). Le pliage indépendant par section dans un tableau unique n'est donc
  **pas réalisable** en Markdown/HTML pur supporté par GitHub (pas de CSS, pas de JS).
- Au-dessus du grand tableau, garder un petit tableau récapitulatif centré
  (Catégorie | Nombre | Exemple) — c'est un résumé visuel, pas une liste exhaustive,
  il peut garder sa largeur naturelle. C'est le SEUL tableau du README autorisé à
  ne pas suivre la règle d'harmonisation ci-dessous.

### 6.1 Harmoniser la largeur entre plusieurs tableaux du même README

Même en un seul tableau continu par référence, un README a souvent AU MOINS deux
tableaux distincts (ex : Function/Conversion Reference + Skills Developed). Comme
GitHub redimensionne chaque `<table>` indépendamment sur son propre contenu
(`width: max-content`, voir §6 ci-dessus), **deux tableaux différents n'ont quasiment
jamais la même largeur naturellement** si leur contenu textuel diffère en longueur.
Résultat visuel signalé plusieurs fois : les tableaux d'un même README "décalés"
les uns par rapport aux autres.

**Solution retenue, à appliquer systématiquement à partir de maintenant, sur TOUS
les tableaux d'un README sauf le petit récapitulatif centré mentionné ci-dessus** :
un pixel invisible transparent, de largeur fixe, ajouté dans la dernière cellule
d'en-tête (`<th>`) de chaque tableau à harmoniser. Il force le tableau entier à
une largeur minimale identique partout, sans aucun impact visuel.

- Asset partagé : `templates/spacer.png`, un PNG **1×1 pixel entièrement transparent**
  (RGBA `(0,0,0,0)`), à copier tel quel dans `<PROJECT>/.assets/spacer.png` de chaque repo
  (même logique que `divider.png`).
- Dimensions d'affichage forcées via les attributs HTML de l'`<img>`, pas via le fichier
  lui-même : **`width="900" height="1"`**. Ce sont les dimensions de référence à réutiliser
  partout, ne pas en changer projet par projet (c'est tout l'intérêt : ne plus jamais
  avoir à ajuster ce point).
- Insertion : à l'intérieur du texte de la dernière `<th>` de la ligne d'en-tête, par ex. :
  ```html
  <tr><th width="26%">Function</th><th>Purpose<img src=".assets/spacer.png" width="900" height="1" alt="" /></th></tr>
  ```
  Fonctionne identiquement dans un `<th>` de tableau "Skills Developed" à deux colonnes,
  ou dans la dernière colonne d'un tableau de référence à 2 ou 3 colonnes.
- Résultat : tous les tableaux "larges" (Function/Conversion Reference, Skills Developed,
  toute autre table de contenu ajoutée plus tard) rendent exactement à la même largeur
  (~940px de large sur le rendu GitHub standard), quel que soit le nombre de lignes ou
  la longueur du texte contenu.
- Ce point est **acquis pour toute la suite des projets** : l'appliquer par défaut à
  chaque nouveau README dès sa première rédaction, sans attendre une remarque.

## 7. Alertes GFM (Design Notes)

- Utiliser `> [!NOTE]`, `> [!IMPORTANT]`, `> [!TIP]`, `> [!WARNING]`, `> [!CAUTION]`.
- **Varier les types** sur les 3-4 alertes d'une section : ne jamais répéter le même type
  deux fois si un autre type colle mieux au contenu (un piège concret → `WARNING`,
  une règle du sujet → `NOTE`, une contrainte de gestion mémoire → `IMPORTANT`, une astuce
  d'implémentation → `TIP`).
- Chaque alerte : une phrase en gras qui nomme la règle, puis l'explication du pourquoi.

## 8. Listes à puces (Highlights, etc.)

- Toujours une phrase d'intro avant la liste (jamais une liste qui tombe du ciel).
- Chaque puce : `**Constat en gras.** Explication en une phrase.` — pas de fragments
  juxtaposés sans lien logique.

## 9. Autres règles dures (issues de désaccords explicites)

- **Un README = un seul projet.** Ne jamais mentionner, lister ou schématiser la structure
  d'un autre repo à l'intérieur du README d'un projet, même pour montrer une dépendance
  (ex : LIBFT ne doit pas contenir de diagramme listant GNL/FT_PRINTF/PIPEX/etc.). Un lien
  externe simple vers le repo GitHub du projet lié (`https://github.com/Nesplee/XXX`) est
  acceptable dans une cellule de tableau, un schéma cross-repo ne l'est pas.
- Toujours vérifier le rendu réel avant de livrer une capture : passer par
  `gh api /markdown` (mode `gfm`, `context: "Nesplee/<REPO>"`) + `github-markdown-css`
  + Chromium headless (Playwright) plutôt que de deviner le rendu GitHub.
- Ne jamais présumer qu'un push a été fait : vérifier `git status`/`git log` avant
  d'affirmer qu'un asset est en ligne. Si l'utilisateur signale qu'une image ne se
  met pas à jour après un push confirmé par hash identique, c'est un problème de
  cache CDN GitHub (`raw.githubusercontent.com`)/navigateur, pas un vrai problème de repo :
  vérifier avec `curl` sur l'URL raw avant de chercher ailleurs.
- Ne jamais publier d'image avec un fond plein coloré façon "carte" ou de mise en page
  à base de `<style>`/CSS inline : tout est strippé par le sanitizer GitHub. Toute
  variation graphique doit passer par des assets images statiques (bannière, divider,
  badges) ou par les attributs HTML tolérés (`align`, `width`, `height`, `colspan`, `cellpadding`).

## 10. Checklist par projet

Pour chaque repo restant :
- [ ] Repérer l'illustration existante à réutiliser pour la bannière (`.assets/Illu_*`)
- [ ] Générer `banner.png` avec `make_hero.py` (titre = nom du projet, sous-titre à inventer)
- [ ] Copier `divider.png` tel quel dans `.assets/`
- [ ] Adapter les badges d'en-tête (langage, Norminette si applicable, note)
- [ ] Écrire Overview / Highlights / Build & Usage en anglais, ton pro
- [ ] Design Notes avec alertes variées sur les vraies contraintes du sujet
- [ ] Arborescence en bloc de code, pas de tableau Fichier/Rôle
- [ ] Si le projet a un référentiel de fonctions/commandes : un seul tableau, catégories
      en lignes `colspan`, badges de catégorie régénérés via `make_badge.py`
- [ ] Vérifier tous les liens de fichiers (existence réelle du fichier cible)
- [ ] Skills Developed + Result
- [ ] Rendu vérifié via le pipeline `gh api /markdown` avant de considérer terminé
- [ ] Validation explicite de l'utilisateur avant de passer au projet suivant
