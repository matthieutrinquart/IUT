# Variables
var x1 >= 0;
var x2 >= 0;

# Objectif
maximize z :
    3*x1 + 5*x2;

# Contraintes
subject to
C1: x1 <= 4;
C2: x2 <= 6;
C3: 3*x1 + 2*x2 <= 18;

# Affichage du résultat
printf "lancement du solve \n";
solve;
# display fonction objectif et solution;
printf "x1=%f\n", x1;
printf "x2=%f\n", x2;
printf "z=%f\n", z;


