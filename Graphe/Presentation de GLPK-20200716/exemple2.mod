
# Variables
var x{i in 1..5}, binary;

# Objectif
maximize z : 12*x[1]+12*x[2]+9*x[3]+15*x[4]+26*x[5];

# Contraintes
subject to
C1 : 3*x[1]+4*x[2]+3*x[3]+3*x[4]+13*x[5] <= 22;

# Affichage
       
printf "lancement du solve \n";
solve;
# display fonction objectif et solution;
printf "x1=%f\n", x[1];
printf "x2=%f\n", x[2];
printf "x3=%f\n", x[3];
printf "x4=%f\n", x[4];
printf "x5=%f\n", x[5];
printf "z=%f\n", z;


