###################
##
##  Fichier de modélisation du problème
##  du sac à dos
##
#####################


#donnees
param n; #nombre d’objets
param U{i in 1..n}; #utilité de l''objet i
param P{i in 1..n}; #poids de l''objet i
param W; #capacité du sac


#variables
var x{1..n} binary;

#objectif
maximize f :sum {i in 1..n} U[i]*x[i];

#contraintes
subject to capacite : sum{i in 1..n} P[i]*x[i] <= W;
