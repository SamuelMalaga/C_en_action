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
ar rcs [nom_de_lib].a source1.o source2.o
/* ou */
ar rcs [nom_de_lib.a] *.o
``` 
5. Pour utiliser la bibliothèque qui a étè crée, on doit créer une fichier *.c* qui appele le fichier *.h* d'elle
6. Finalement, on doit compiler le fichier *.c* et lui exécuter (évidemment qu'il faut que les fonctions de la bibliothèque soient appelées pour le programme qu'elles soient exécutées)

Plus d'informations sur les fichiers d'extension d'une bibliothèque statiques .a peuvent être trouvées dans les liens suivantes:
-https://en.wikipedia.org/wiki/Ar_(Unix)
-https://www.ibm.com/docs/fr/aix/7.3.0?topic=ar-command

Pour charger une bibliothèque dynamique dans ton programme, c'est-à-dire, utiliser leur contenu seulement au moment choisi et not automatiquement au lancement du programme vous devez utiliser la function ```dlopen()```. Cette fonction peut être utilisée comme autres fonctions habituelles d'ouverture de fichiers, le premier argument est le nom du fichier que contient le contenu de la bibliothèque, le deuxième est le mode d'overture, cette choix est bien restreint, plus specifiquement deux choix: RTLD_LAZY et RTLD_NOW. Au premier, préférable pour raisons de performance, l'indication des symbols dans la bibliothèques sont charge seule quand il sont appelles, par contre le second charge tous les symbols au moment d'appell de la bibliothèque.
Deux options en plus peut être utilisé: RTLD_GLOBAL et RTLD_LOCAL, le premier permet d'autres objets d'utiliser les symbols de la bibliothèque et le deuxième l'en empêche 
Au moment d'overture d'une bibliothèque partagée, le système recherche l'existence d'une fonction nommée _init() que ne prend pas d'arguments, leur utilité est restreinte. 
Pour finir l'utilisation d'une bibliothéque dynamique vous devez appeller la fonction dlclose() qui fait une appel à fonction _fini(), sa fermeture signifie que le compteur de référencees à bibliothèque est décrémenté, et s'il devient nul, la bibliothèque est déchargée de la memoire. Quand on utilise une bibliothèque dynamique avec dlopen() on ne lies pas le programme à la bibliothèque. 
 
#### Créer une bibliothèque dynamique et l'utiliser avec liason dynamique (dynamic linking)

1. Créer les fichiers .c et .h (fichier d'entête)
2. Compilér la bibliothèque dynamique en utilisant les comandes suivnates:
```
gcc -fPIC -c [mon_bib].c -o [mon_bib].o  /* -fPIC rend le code independent de position PIC=Position Independent Code  */
gcc -shared -o [lib_mon_bib].so [mon_bib].o /* -shared est une option qui commande le compilateur de créer une bibliothèque partagée */
```
*note: l'option PIC dit au compilateur qui il peut chargér cette programme dans la memoire dans quelque adresse de memoire*
3. Créer un autre fichier qui appelle la bibliothèque crée dans l'include
4. Compilér et connecter le programme avec la bibliothèque
```
gcc [nom_prog].c -L. -l[mon_bib] -o [nom_prog]
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH /*ce commande dit au systhème le lieu oú chercher les fichiers partages*/
```

**Il y a une difference entre dynamic linking et dynamic loading**  Cette difference peut être explique pour la phrase suivante(a été traduit de cette response dans stack overflow: https://stackoverflow.com/questions/10052464/difference-between-dynamic-loading-and-dynamic-linking ): chargèment dynamique (dynamic loading) verifie si la routine/programme a èté chargé dans la memoire pour le chargeur(loader), par contre, enchaînement dynamique (dynamic linking)est le processus de resolution des references à symbols externes (libraries/ function calls) pendant le temp d'execution.

Ça est une discussion trés specifique et trés intéressante dans le domaine de science de computation. Un super tutorial sur dynamic linking peut être suivi ici: https://developer.ibm.com/tutorials/l-dynamic-libraries/#dynamic-linking-with-linux0 
