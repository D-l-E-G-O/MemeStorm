# MemeStorm

**MemeStorm** est un petit programme en C utilisant les librairies **SDL2** et **SDL2_image** et qui fait apparaître des memes aléatoirement sur l’écran.  
Chaque meme s’affiche dans une **fenêtre indépendante**, à un **emplacement et une taille aléatoires**.


## Fonctionnalités

- Affiche des images (memes) à partir d’un dossier
- Position et taille aléatoires pour chaque fenêtre
- Une fenêtre indépendante par meme
- Gestion dynamique des fichiers d’images


## Installation

### Prérequis
Il faut avoir installé les bibliothèques suivantes :

```bash
sudo apt install libsdl2-dev libsdl2-image-dev
```

### Cloner le dépôt
```bash
git clone https://github.com/D-l-E-G-O/MemeStorm.git
cd MemeStorm
```

### Compilation
```bash
make
```

### Exécution
```bash
./bin/MemeStorm
```

### (Optionnel) Nettoyage du projet
Exécutez la commande suivant pour supprimer les fichiers compilés :
```bash
make mrproper
```

### (Optionnel) Ajouter des images
Après avoir cloné le projet, le dossier **assets** contient des images par défaut.
Pour ajouter d'autres images (png et jpg seulement), il suffit d'ajouter ces images dans le dossier **assets**
```bash
assets/
├── meme_1.png
├── meme_2.png
├── ...
└── meme_n.png
```
