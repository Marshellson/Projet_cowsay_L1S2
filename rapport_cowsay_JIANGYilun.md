<!--
 * @Author: JIANG Yilun
 * @Date: 2022-04-24 14:28:58
 * @LastEditTime: 2022-04-24 15:13:32
 * @LastEditors: JIANG Yilun
 * @Description: 
 * @FilePath: /Projet_cowsay_L1S2/rapport_cowsay_JIANGYilun.md
-->



# Projet Cowsay

<p align="right"> JIANG Yilun

## Sommaire

[TOC]

## 1. Présentation du Projet `cowsay`

Le projet débute au premier jour du cours INF203 et s'achève lors la dernière semaine de cours. Cette dernière fait date de rendu (dimanche soir minuit de la dernière semaine). Vous pouvez progresser sur le projet a votre rythme, mais nous vous recommandons de prendre de l’avance par rapport au cours, du moins aucun retard. Par exemple, la partie “Bash” devra être achevée au moment ou les premiers cours de “C” débuteront.

## 2. Objectif du projet

L’objectif du projet est de découvrir le monde merveilleux de “cowsay”. Au cours du projet, vous réaliserez les objectifs suivants:

### 1. Préliminaires
Découvrir la commande cowsay a travers son manuel (manpage) et l’ensemble des options qu’elle contient.

### 2. Bash
Implémenter un script Bash qui fait réciter a la vache la suite des nombres premiers, des nombres de Fibonacci, ou toute autre suite exotique de votre choix.

### 3. C
Recoder cowsay en C, avec de nouvelles fonctionnalités additionnelles de votre choix (comme par exemple la longueur de la queue).

### 4. Automates
En s’appuyant sur la théorie des automates, implementer un “cow-Tamagoshi” qu’il s’agit de nourrir et faire survivre aussi longtemps que possible.

## Préliminaires

Découvrir du code `cowsay`:
```bash
cowsay -h
```

Nous avons donc le résultat suivant:

```
cow{say,think} version 3.03, (c) 1999 Tony Monroe
Usage: cowsay [-bdgpstwy] [-h] [-e eyes] [-f cowfile] 
          [-l] [-n] [-T tongue] [-W wrapcolumn] [message]
```

Nous apprenons donc que le projet cowsay contient en fait deux commandes, l'une appelée Cowsay et l'autre Cowthink. Cowsay utilise des lignes droites pour relier la vache aux mots prononcés, tandis que cowthink utilise des cercles.

Par exemple, nous utilise `cowsay ` en première:

```bash
cowsay "Hello, my name is JIANG Yilun"
```

Avec les résultats suivant:

```
 _______________________________ 
< Hello, my name is JIANG Yilun >
 ------------------------------- 
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```

Ensuit, nous utilise le commande `cowthink`:

```bash
cowthink "Hello, my name is JIANG Yilun"
```

Avec les résultats suivant:

```
 _______________________________ 
( Hello, my name is JIANG Yilun )
 ------------------------------- 
        o   ^__^
         o  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```

En fait, le cowsay ne se limite pas à la forme de la vache.  Apres nous utilisons le commande `cowsay -l`, nous pouvons constater que nous avons en fait de nombreux modèles à choisir:

```bash
$ cowsay -l
Cow files in /opt/homebrew/Cellar/cowsay/3.04_1/share/cows:
beavis.zen blowfish bong bud-frogs bunny cheese cower daemon default dragon
dragon-and-cow elephant elephant-in-snake eyes flaming-sheep ghostbusters
head-in hellokitty kiss kitty koala kosh luke-koala meow milk moofasa moose
mutilated ren satanic sheep skeleton small stegosaurus stimpy supermilker
surgery three-eyes turkey turtle tux udder vader vader-koala www
```

Par exemple, on peut utilise la forme `sheep`:

```bash
$ cowsay -f sheep hello
 _______ 
< hello >
 ------- 
  \
   \
       __     
      UooU\.'@@@@@@`.
      \__/(@@@@@@@@@@)
           (@@@@@@@@)
           `YY~~~~YY'
            ||    ||
```

On peut aussi utiliser le vase avec des tuyaux:

```bash
$ ll | cowsay
 ________________________________________ 
/ total 8 -rw-r--r--@ 1 yilunjiang staff \
| 3.6K Apr 24 15:03                      |
\ rapport_cowsay_JIANGYilun.md           /
 ---------------------------------------- 
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```

En fait, la sortie de cowsay est très pauvre - pratiquement impossible à visualiser très bien. Mais si nous ajoutons la commande -n:

```bash
$ ll | cowsay -n
 __________________________________________________________________________________ 
/ total 16                                                                         \
\ -rw-r--r--@ 1 yilunjiang  staff   4.2K Apr 24 15:09 rapport_cowsay_JIANGYilun.md /
 ---------------------------------------------------------------------------------- 
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```

De cette façon, les informations décrites peuvent être lues de manière plus visuelle.

La commande cowsay a en fait ces petits extras, par exemple, nous pouvons changer les yeux de la vache:

```bash
$ cowsay -e -- "Hello, my name is JIANG Yilun" 
 _______________________________ 
< Hello, my name is JIANG Yilun >
 ------------------------------- 
        \   ^__^
         \  (--)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```

Nous avons même réussi à lui faire cracher sa langue:

```bash
$ cowsay -T U "Hello, my name is JIANG Yilun" 
 _______________________________ 
< Hello, my name is JIANG Yilun >
 ------------------------------- 
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             U ||----w |
                ||     ||
```

## Bash
