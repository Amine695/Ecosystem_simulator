![Title game](img/titlegame.gif)
<br/> 
Ce jeu est une simulation en C++ d'un écosystème simple, où l'on étudie l'évolution de deux espèces animales en fonction du temps.

## Prérequis

### Installation

Pour réaliser ce projet, nous avons utilisé la librairie graphique **SFML** sous Linux.
Pour l'installer, rien de plus simple :
```bash
sudo apt-get install libsfml-dev
```
Si vous utiliser un autre système d'exploitation cf la documentation [ici](https://www.sfml-dev.org/tutorials/2.5/index-fr.php).

### Compilation
Pour compiler notre jeu, utiliser la commande **make** directement depuis le dossier puis lancer l'exécutable *game* avec la commande:
```bash
./game
```

ATTENTION ! La compilation nécessite d’avoir la version standard **C++17**. Si vous êtes sous **C++11**, il vous faudra changer les paramètres de compilation g++ dans votre IDE. Si vous ne posséder pas cette version, il vous faudra l'installer. <br/>

- Sous windows : suivre ce [tutoriel](https://www.geeksforgeeks.org/complete-guide-to-install-c17-in-windows/) en installant la dernière version de [MinGW](https://nuwen.net/mingw.html)
- Sous Linux : suivre ce [tutoriel](https://ducciogasparri.it/2020/07/30/installing-c17-and-c20-on-ubuntu-and-amazon-linux/)

## Lancement

Une fenêtre de lancement apparait avec une musique immersif qui l'on espére vous plaira ainsi qu'un bouton **START**.
![Lancement](img/Capture.jpg)

Une fois le bouton appuyé, la fenêtre du jeu s'ouvre et la simulation démarre en appuyant sur la touche 'Enter'.

![Simulation](img/game.jpg)

## Commandes

Voici les commandes de l'application :

- `Enter` : démarrer la simulation
- `Space` : mettre la simulation sur pause
- `Right arrow` : accélérer la simulation par 2
- `Left arrow` : ralentir la simulation par 2
- `S` : afficher/masquer les statistiques

## Fonctionnement du jeu
- Les animaux sont représentés par des cercles. Les moutons correspondent aux triangles rouge et les loups au losanges bleu, plus gros. La simulation débute avec 30 moutons et 8 loups, tous placés aléatoirement sur la fenêtre et ayant 1000 de point de vie.

- En petit cercle vert sont représentés la nourriture.

- À chaque régénération de la fenêtre , les animaux se déplacent pseudo-aléatoirement en utilisant le bruit de Perlin (*Perlin noise*). Leurs points de vie diminuent d'un point par déplacement.

- Deux entités interagissent entre elles lorsque les figures géometrique qui les représentent se superposent. Voici les interactions entre les entités :

    * **Quand un mouton rencontre de la nourriture**, le mouton mange la nourriture. La nourriture est régénérée à un autre endroit de la fenêtre et le mouton régénère ses points de vie à la valeur de départ.
    * **Quand un loup rencontre un mouton**, le loup mange le mouton. Le loup régénère ses points de vie, et le mouton disparaît.
    * **Quand un mouton rencontre un autre mouton**, un nouveau mouton naît avec une certaine probabilité (définie à `0.3`).
    * **Quand un loup rencontre un autre loup**, un nouveau loup naît avec une certaine probabilité (définie à `0.3`).
    * **Quand un animal n'a plus de points de vie**, il meurt et disparaît de la fenêtre.

## Personnalisation
Evidemment, vous pouvez faire varier les paramètres de la simulation comme bon vous semble ! Elles se situent dans le fichier **constants.hpp** du dossier `src`. Le but étant d'avoir une simulation se rapprochant de la réalité.

## Statistiques
Vous pouvez voir les statistiques de la simulation en haut à gauche de la fenêtre :

- Le temps en secondes
- La vitesse de la simulation
- Le nombre actuel de moutons
- La nombre actuel de loups
- Le nombre total de nourritures mangées par les moutons
- Le nombre total de moutons tués par les loups
- Le nombre de moutons nés
- Le nombre de loups nés

Le mot `Pause` s'affiche si la simulation est sur pause.

## Résultat de la simulation

À la fin de la simulation, un graphique apparaît montrant l'évolution du nombre de loups et de moutons en fonction du temps.
Celui-ci est généré grâce à un script [python](https://github.com/Amine695/Game-of-Life-/blob/main/python/plot.py) en utilisant la bibliothèque *matplotlib*.
**Ne fermer pas la fenêtre à la fin de la simulation !**, le plot met quelques secondes à s'afficher !

![Graph](plot/result.png)

## Tests
Pour vérifier le bon fonctionnement de nos classes, nous avons effectuer plusieurs tests à l'aide de la librairie **catch** que vous pourrez retrouver [ici](https://github.com/Amine695/Game-of-Life-/blob/main/tests/Testcase.cpp).
Pour compiler, utiliser la commande `make testcase` dans le répertoire principale puis `./testcase`.

## Fonctionnalités de notre application
- [x] Créer la fenêtre de lancement
- [x] Créer la fenêtre de simulation
- [x] Définir les classes pour les animaux
- [x] Gérer le déplacement des animaux
- [x] Définir la classe pour la nourriture
- [x] Gérer les interactions entre les entités
- [x] Ajouter sur la fenêtre les statistiques de la simulation
- [x] Gérer la customisation de la simulation
- [x] Utilisation de tests unitaires
- [x] Pouvoir faire pause, accélérer, ralentir la simulation
- [x] Pouvoir générer un graphe de la simulation avec le nombre d'animaux en fonction du temps
- [x] Gérer la partie audio du jeu avec les différents sons
- [x] Respecter les contraintes du projet (fonctions virtuelles, héritage,...)

## Diagramme UML
![UML](UML/UML.png)


## Auteurs
**Amine Berbagui** <br/>
**Ghassen Hachani**
