param n_fix;
param T{i in 1..n_fix, j in 1..3};

#variable xijk=1 si case ij=k

var x{i in 1..9, j in 1..9, k in 1.. 9 } binary;

#contraintes

subject to

# un seul chiffre par case

valeurs {i in 1..9, j in 1.. 9}: sum {k in 1..9} x[i,j,k] = 1;

# un meme chiffre par ligne

lignes {i in 1..9, k in 1.. 9}: sum {j in 1..9} x[i,j,k] = 1;

# un meme chiffre par colonne

colonnes {j in 1..9, k in 1.. 9}: sum {i in 1..9} x[i,j,k] = 1;

# un meme chiffre par blocs de 3x3

blocs {xx in {0, 3, 6}, yy in {0, 3, 6}, k in 1..9}:

    sum {i in (xx+1)..(xx+3), j in (yy+1)..(yy+3)} x[i,j,k] = 1;

#cases donnees

C{i in 1..n_fix} :
     x[T[i,1], T[i,2], T[i,3]] = 1;

#calcul

solve;

#affichage

printf "\n\nSolution : \n";

printf "------------------------------------\n";

for {i in 1.. 9} {

    for {j in 1..9} {

         for {k in 1..9 :x[i,j,k] ==1} printf " %d ", k;

         printf "|";   

    }

    printf "\n";

    printf "------------------------------------\n";

}

end;
