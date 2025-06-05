### Comment verifier si mon ordinateur a des outils pour compiler (et consequentement) programmer en C
#### Compilation
Pour faire cette verification, on va créer le classique "Hello world" pour essayer. Comment j'utilise un systéme d'exploitation Linux (plus spécifiquement UBUNTU), c'est sure que j'ai au moins un compilateur de C dans ma machine.
Comment je prouve ça? C'est facile, j'utilise le command:
```
gcc -Wall hello_world.c -o hello_world
```
Selon le livre, l'option -Wall permet d'afficher nombreux messages d'avertissement pendant la compilation du code. Cette option est fortement récomandée parce que elle permet de mettre en évidence eventuels problémes d'installation.

Pour le bon fonctionnement de cette command, il faut que on a l'archive hello_world.c dans notre fichier.

#### Automatisation de la compilation
L'auteur mentionne aussi qui est possible d'automatiser la compilation avec une makefile. Ça est super intéressant et extremament utile parce que les makefiles sont utilisées toujour dans un contexte de devops ou même dans l'enginiére de software en general.

Le flux d'action normal pour considerer une makefile si vous n'avez pas passer des arguments pour le command ```make``` est d'exécuter la premiére cible du fichier makefile.

Pour essayer le flux d'un makefile, on va créer trois archives: hellomake.c, hellofunc.c et hellomake.h
Ces archives sont basée dans le matériel dans cette lien: https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ - C'est une tutoriél complementaire qui j'ai trouvé sur l'internet super complet

**Curiosité trouvée 1**  
Il y a une gros difference entre
```
#include <header.h>
// et
#include "header.h"
```
La premiére façon, on doit utiliser pour les archives *header* du systéme et la deuxiéme on doit utiliser pour les archives *header* qui on a crée pour notre propre programme.

#### Optimization de la compilation
L'auteur du livre mentionne aussi comment on peut faire pour compiler notre code d'une façon optimisée, il y a plusieurs options de flags qui on peu utiliser pour optimiser les archives pendant la compilation comme -funroll-loops, -fomit-frame-pointer -pipe et etc...

Pour plus d'options sur les flags d'optimisation, consultez le site du manuel du gcc

#### Passer des paramètres au préprocesseur
Si on veut créer une logique de compilation, ça veut dire, faire notre compilation respecter certaines règles et commands quand on les compile (comment ne compiler pas une bloc de code si le paramètre DEBUG est active) on peut utiliser les macros pour faire ça.

Les modifications ont été faites sur le makefile et l'archive hellomake.c
