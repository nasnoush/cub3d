![alt text](image.png)




parsing :


- faire en sorte que la map doit etre apres les autres infos 
- faire les verifs comme : si les textures sont bonne ou si la map est null etc etc
<!-- - regler la segfault quand il y'a qu'une seul ligne avec un 1, adapter la fonction check_wall -->
- faire les checks si les couleurs sont bonne, si les textures le sont aussi
- peut etre que dans load assets il faut que je laisse seulemnt la structure game comme ca je galere pas a l appeler faut voir
<!-- - a voir si pour les couleurs je doit etre strict dans le parsing genre ne pas avoir de caractere autre que des nombres etc ou simplement faire en sorte d'avoir une ligne qui s'ecris comme sa "F 220,100,5" et pas d'une autre maniere, peut etre plus simple -->

<!-- - le check du nombre d'info et d'autre a verifier pour que ca ce fasse dans le bon ordre
ou peut etre retirer le int et le mettre en void et l'ajouter au parsing directement au lieu de passer par la fonction check error -->

<!-- - la segfault vien apparement de checkwall d apres gdb quand j ai une ligne pas valide dans la derniere verif de ligne  -->
<!-- je check si la premiere ligne est valide mais ducoup je check si la derniere aussi est valide mais si y a une ligne la premiere c est la derniere
je pense faire une condition, si j ai une seul ligne avec une fonction qui compte les lignes et bas je met l erreur commme sa sa check -->

- segfault quand y a un caractere dedans autre que ce qui est autorisé

- la verif de si la map est entouré de mur fonctionne mal

- j ai fait une condition de verif si ya tout les caracteres mais si j ai une map sans 0 genre 1
																							  1N1
																							   1

- quand je met la map au debut adapter le message pour qu'il soit plus large

- gerer les doublons dans les texutres


- faire la norminette et leaks sur cette partie de parsing
 