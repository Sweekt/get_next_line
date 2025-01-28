# Get Next Line

Get Next Line (GNL) est un projet du cursus de l'école 42. Ce projet consiste à créer une fonction capable de lire une ligne à la fois à partir d'un descripteur de fichier, ce qui est utile pour manipuler des fichiers ou des entrées utilisateur de manière efficace.

---

## Table des matières

1. [Description](#description)
2. [Fonctionnalités](#fonctionnalités)
3. [Installation](#installation)
4. [Utilisation](#utilisation)
5. [Structure du projet](#structure-du-projet)
6. [Tests](#tests)
7. [Ressources](#ressources)
8. [Auteur](#auteur)

---

## Description

La fonction `get_next_line` lit une ligne d'un fichier ou de l'entrée standard sans jamais perdre les données non lues. Elle est conçue pour fonctionner avec des tampons de taille arbitraire et peut gérer plusieurs fichiers ouverts simultanément.

Le projet vise à :

- Approfondir la gestion des fichiers et des buffers en C.
- Manipuler des pointeurs et de la mémoire dynamiquement.
- Gérer des cas particuliers comme les EOF et les erreurs.

---

## Fonctionnalités

- Lire une ligne à la fois à partir d'un descripteur de fichier.
- Gérer plusieurs descripteurs de fichier simultanément.
- Fonctionner avec un tampon de taille définie par `BUFFER_SIZE`.

Prototype de la fonction :

```c
char *get_next_line(int fd);
```

---

## Installation

1. Clonez ce dépôt :

   ```bash
   git clone https://github.com/votre-utilisateur/get_next_line.git
   cd get_next_line
   ```

2. Compilez la fonction avec votre projet ou exécutez-la directement :

   ```bash
   gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
   ```

---

## Utilisation

Incluez `get_next_line.h` dans vos fichiers sources et utilisez la fonction `get_next_line` comme suit :

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

---

## Structure du projet

```
get_next_line/
|-- get_next_line.c       # Fonction principale
|-- get_next_line_utils.c # Fonctions utilitaires
|-- get_next_line.h       # Header principal
|-- README.md             # Documentation
```

---

## Tests

1. Testez la fonction avec des fichiers différents :

   ```bash
   echo -e "Ligne 1\nLigne 2\nLigne 3" > test.txt
   ./gnl
   ```

2. Utilisez des outils tiers pour tester :

   - [42TESTERS-GNL](https://github.com/Mazoise/42TESTERS-GNL)
   - [gnl-war-machine](https://github.com/42Paris/gnl-war-machine)

---

## Ressources

- [Documentation du projet Get Next Line (42)](https://projects.intra.42.fr/projects/get_next_line)
- [Manpages pour les fonctions systèmes](https://man7.org/linux/man-pages/)
- [Tester GNL](https://github.com/Mazoise/42TESTERS-GNL)

---

## Auteur

Projet réalisé par :

- **Votre Nom** ([votre-login@42.fr](mailto\:votre-login@42.fr))

---

