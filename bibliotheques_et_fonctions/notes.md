### Introduction
Dans quelques programmes ou systhémes d'exploitation, les bibliothèques existent. Elles sont utilisées pour factoriser le code et réutiliser les fonctionnes utiles sans besoin d'implementer ces fonctionnes encore une fois. En général, il y a deux types de bibliothèques: statique(static) ou dynamique(dynamic)
- Les bibliothèques dynamiques sont chargées à demande du premier programme qui en a besoin, et tout autre programme peut ensuite profiter immédiatement des mêmes fontionalités.
- Les bibliothèques statiques sont présènt dans le systéme sur le format binaire, ça signifiée qui elles sont déjà compilée.
Une autre benefice d'une bibliothèque est que les programmeurs peut les utilisér pour augmenter la qualité du code et réglèr quelques bugs du programme. La collaboration est facilitée pour leur usage.

Le livre faire la suggestion de créer une bibliothèque statique pour en exemplifier quelques aspects. En general les bibliothèques doit être nomée sur l'estructure suivante:
[nom_de_lib].majeur.mineur.micro -> majeur: version majeur de la bibliothèque (quelque changement de cette numéro veut dire une changement de la structure d'API) | mineur: version mineur de la bibliothèque (génèralement utilisée pour verifié si la version qui est utilisée est la version mise en jour).

#### Créer une bibliothèque statique
1. Créer les fichiers avec les fonctions/routines et etc... que vous voulez mettre dans la bibliothèque (pour symplifiér, dans chaque fichier il y a une fonctionne qui utilise stdio.h
pour écrire "hello from 1" et "hello from 2" au terminal
```
vim source1.c
vim source2.c
```
2. Créer une header file qui déclare les prototype des fonctionnes qui ont étè declarée dans source1.c et source2.c
3. Compilér les fichiers *.c* creés avec une des commandes suivantes:
```
gcc -c source1.c -o source1.o
gcc -c source2.c -o source2.o
```
ou
```
/*cette commande sélectionne tous les fichiers qui ont l'extension .c, donc on doit faire attention au dossier dans lequel elle est exécutée*/
gcc -c *.c
```
4. Pour les emballer on peut choisisez deux options de commandes (rcs signifie *replace, create, sort* [remplacer, créer, organiser]. rcs est un modificateur de comportement du archiver )
```
ar rcs [nom_de_lib].a source1.o
ar rcs [nom_de_lib].a source2.o
/* ou */
ar rcs [nom_de_lib.a] *.o
``` 
5. Pour utiliser la bibliothèque qui a étè crée, on doit créer une fichier *.c* qui appele le fichier *.h* d'elle
6. Finalement, on doit compiler le fichier *.c* et lui exécuter (évidemment qu'il faut que les fonctions de la bibliothèque soient appelées pour le programme qu'elles soient exécutées)

