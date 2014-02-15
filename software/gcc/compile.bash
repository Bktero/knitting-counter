# Ce script tente de compiler le projet avec gcc pour si les messages de gcc sont plus parlants que ceux de C18...


gcc -I. -I../includes -D __18F25K22 -c ../sources/*.c


# Mode operatoire
#
# Prendre les en tetes necessaires et les modifier pour les rendre "compatible"
#
# delays.h
# Il suffit de modifier la macro suivant pour enlever le auto:
# #define PARAM_SCLASS //auto
#
# Le fichier d'en tete du micro a quelques mots cles specifiques qu'on peut faire disparaitre
# #define far 
# #define near 
# Ensuite, il faut enlever le type short long ou long short (a priori, on voit surtout la premiere forme)
# cela correspond a un int24_t mais ce type ne semble pas trop fonctionner
# On peut donc utiliser sed pour faire ce remplacement
# sed -i .bk 's/short long/int/g' le_fichier
#
# Le fichier interrupts.c contient trop de pragma pour etre facilement transformable.
