Pour configurer un nouvel utilisateur (par defaut: 'Lucie'):
     -Aller dans le makefile, et modifier le nom ligne 2.

Pour proposer un exercice:
     - Creer un dossier pour le module associe. 
     Ex: Pour le module 'C00', creer un dossier '42_Training/NOM_UTILISATEUR/C00'
     
     - Creer un dossier pour l'exercice, ainsi que le fichier attendu par l'exercice. 
     Ex: Pour l'exercice 1, le ficher attendu est 'ft_putchar.c'. 
     Il faut donc creer '42_Training/NOM_UTILISATEUR/C00/ex00/ft_putchar.c'.
     
     - Utiliser la commande makefile associee a l'exercice:
       - Ouvrir un terminal dans le dossier '42_Training/Emulation_Moulinette'
       - Lancer la commande en suivant la construction suivante:
       	 'make compile_and_run_{NomDuModule}ex{NumeroExercice}'
       - La console affichera :
         - Les erreurs eventuelles de compilation et d'execution
         - Si la fonction correspond a ce qui est attendu.
    Ex: Pour lancer la verification de l'exercice 0, lancer:
	 'make compile_and_run_C00ex00'
