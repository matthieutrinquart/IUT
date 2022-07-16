//Matthieu Trinquart
//info 2  TD IN   TP1







//  /!\ ce TP a fait sur scilab 6.0.2 il ce peut que ces programme ne marche pas sur des versions anterieurs   


//TP numéro 2
//-------Creation des droite 1 et 2 de manière aleatoire avec une declaration de structure pour tester  la fonction intersection-----------//
droite =struct('coefX',double ,'constanteX',double,'coefY',double ,'constanteY',double) ;
droite1 = droite ;
droite1.coefX =rand() * 100 ;
droite1.constanteX =rand() * 100 ;
droite1.coefY =rand() * 100 ;
droite1.constanteY =rand() * 100 ;


droite2 = droite ;
droite2.coefX =rand() * 100 ;
droite2.constanteX =rand() * 100 ;
droite2.coefY =rand() * 100 ;
droite2.constanteY =rand() * 100 ;
//----------------------------------------------------------------------------------------------------------------------------------------//




//exercice 1 )
//--fonction intersection qui trouve la position de l'intersection entre 2 droite dans un plan----//
function b=intersection(droite1,droite2)//prend en paramètre les 2 droite(prend en paramètre une structure droite c'est plus comprehensible que droite1(1) ,droite2(1) droite1(2) etc.. )


//---Calcule A0 , A1 , A2 car pour calculer l'intersection on va utilisé la methode de Cramer--//
    A0 = [(droite2.constanteX - droite1.constanteX),-(droite2.coefX); (droite2.constanteY - droite1.constanteY) , -(droite2.coefY);]

    A1 = [(droite1.coefX),-(droite2.coefX);(droite1.coefY),-(droite2.coefY)]

    A2 = [(droite1.coefX),(droite2.constanteX - droite1.constanteX) ;(droite1.coefY),(droite2.constanteY - droite1.constanteY)]

//---------------------------------------------------------------------------------------------// 


//---verifie que det(A1) n'est pas egale a 0 car une division par 0 n'est pas possible cela voudrait dire que les 2 droite sont parallèlle--//
             if((A1(1,1) * A1(2,2)) - (A1(2,1) * A1(1,2) ) == 0)
            
                  b = "erreur"//si c'est bien egal a 0 alors afficher une erreur
                
             else//sinon continuer le programme
            
//---Calcul T et U qui est l'inconnu dans l'equation des droites paramètrique. La valeur de T et U sera la valeur quand les droite 1 et 2 ce touche--//
                 T = det(A0)/det(A1) ;
            
                 U = det(A2)/det(A1) ;
            
//---------------------------------------------------------------------------------------------------------------------------------------------------//

//--on ajoute T dans l'equation de la droite1 ce qui nous donne le point d'intersection---//
                 X1 = droite1.coefX * T + droite1.constanteX ;

                 Y1 = droite1.coefY * T + droite1.constanteY ;
            
//-----on peut faire pareil avec l'equation de la droite 2 en ajoutant U ----------------//
               //X2 = droite2.coefX * U + droite2.constanteX ;

              //Y2 = droite2.coefY * U + droite2.constanteY ;

                 b = [X1 , Y1 , T , U]//on retourne la position de l'intersection avec en plus les paramètre U et T
end
endfunction ;



//---fonction  qui calcule de ratio d'erreur de la premiere function---//
//exercice 2 )
function b =ratio(n)//prend en paramètre le nombre de teste voulu
//---initialise les variable--//
pareil = 0 ;//si le point appartient au 2 droites
diff1 = 0 ;//si le point n'appartient que a 1 des 2 droites
diff2 = 0 ;//si le point n'apaprtient a aucune roite



    for i =1:n//Boucle for pour faire le teste n fois
        
//-------Creation des droite 1 et 2 de manière aleatoire avec une declaration de structure pour tester  la fonction intersection-----------//
        droite =struct('coefX',double ,'constanteX',double,'coefY',double ,'constanteY',double) ;


        droite1 = droite ;
        droite1.coefX =rand()  ;
        droite1.constanteX =rand()  ;
        droite1.coefY =rand()  ;
        droite1.constanteY =rand()  ;


        droite2 = droite ;
        droite2.coefX =rand()  ;
        droite2.constanteX =rand()  ;
        droite2.coefY =rand()  ;
        droite2.constanteY =rand() ;
//----------------------------------------------------------------------------------------------------------------------------------------//
        
        testdroite1 = %F//initialisation de si le point appartient a la droite1 par defaut a faux
        testdroite2 = %F//initialisation de si le point appartient a la droite2 par defaut a faux
        
//----appelle a la fonction intersection avec en paramètre les droite génerer aleatoirement plus haut.---------------------------------------//
        O = intersection(droite1 , droite2 )// O va donc recuperer le point la position du point d'intersection + les paramètre U et T
//------------------------------------------------------------------------------------------------------------------------------------------//

//----on calcule la position du point des droites 1 et 2 a partir des paramètre U (a la valeur O(4))et T (a la valeur O(3))-----------------//
        X1 = droite1.coefX * O(3) + droite1.constanteX ;

        Y1 = droite1.coefY * O(3) + droite1.constanteY ;

        X2 = droite2.coefX * O(4) + droite2.constanteX ;

        Y2 = droite2.coefY * O(4) + droite2.constanteY ;
        
//------------------------------------------------------------------------------------------------------------------------------------------//


//-----On verifie si les positions des points de la droite 1 et 2  est la meme que celle calculer par la fonction intersection-----//
            if((X1 == O(1)) && (Y1 == O(2)))//valeur X du la position du point d'intersection calculer par intersection correspond a O(1) et Y a O(2)
                 testdroite1 = %T   //si le point appartient a la droite 1 alors mettre testdroite1 a true
            end
            
            if((X2 == O(1)) && (Y2 == O(2)))
                testdroite2 = %T    //si le point appartient a la droite 2 alors mettre testdroite1 a true
            end

            if(testdroite1 == %T && testdroite2 == %T) //si le point appartient au 2 droite alors incrementer pareil
                pareil = pareil + 1
             end
             if(testdroite1 == %T && testdroite2 ~= %T)//si il apparient que a la droite 1 et pas a la droite 2 incrementer diff1
                 diff1 = diff1 + 1
              end
              if(testdroite2 == %T && testdroite1 ~= %T )//si il apparient que a la droite 2 et pas a la droite 1 incrementer diff1
                  diff1 = diff1 + 1
               end
               if(testdroite2 ~= %T && testdroite1 ~= %T )//si  il appartient a aucune droite alors incrementer diff2
                  diff2 = diff2 + 1
               end
    end

b = [pareil/n , diff1/n, diff2/n]//retourne les ratios de point appartenant a 1 2 ou aucune droite (divise par le nombre d'iteration pour avoir le ratio)
endfunction ;





//exercice3)


//--fonction qui prend en paramètre 2 vecteur et fais un produit vectoriel--//
function a=produitvectoriel(V1 , V2 )
    
    
    a = [V1(2) * V2(3) - V1(3) * V2(2);
         V1(3) * V2(1) - V1(1) * V2(3);
        V1(1) * V2(2) - V1(2) * V2(1);
        ]
endfunction
//-------------------------------------------------------------------------//



//--fonction qui prend en paramètre 2 vecteur et fais un produit scalaire--//
function a=produitscalaire(V1 , V2 )
    
    
    a = V1(1) * V2(1) +V1(2) * V2(2) +V1(3) * V2(3) 
endfunction
//-------------------------------------------------------------------------//


//--creation des 2 points d'une droite et 3 points d'un plans-------------//
pointD1 = [0.5,0.5,-10]
pointD2 = [0.5,0.5,10]

droiteP = [ pointD1 ,pointD2 ]



pointP1 =[0,0,0]
pointP2 =[1,0,0]
pointP3 =[0.5,1,0]

planP = [pointP1 ,pointP2,pointP3]
//-------------------------------------------------------------------------//




//-----creation d'une fonction qui calcule la position d'un point d'intersection entre une droite et un plan----//
function a=intersectionplan(droiteP , planP )//prend en paramètre 2 point d'une droite et 3 points d'un plan
    
    
    vecteurD = [droiteP(4) - droiteP(1); droiteP(5) - droiteP(2) ; droiteP(6) - droiteP(3)]//creation d'un vecteur directeur de la droite avec (Xb - Xa;Yb - Ya;Zb - Za)
    
//--creation des 2 vecteur du plan  avec la formule (Xb - Xa;Yb - Ya;Zb - Za) avec les point P0 P1 et P3--//
    P0P1 = [planP(1) - planP(4); planP(2) - planP(5);planP(3) - planP(6)]
    
    P0P2 = [planP(1) - planP(7); planP(2) - planP(8);planP(3) - planP(9)]
//-------------------------------------------------------------------------------------------------------//


    N = produitvectoriel(P0P1 , P0P2 )//creation du vecteur normal du plan avec le produit vectoriel des 2 vecteur P0P1 et P0P2 du plan calculer plus haut
 
 
        if(N == [0;0;0]) //si le vecteur normal est nul alors P0P1 et P0P2 sont colineaire et ne represente pas un plan 
            
            a = "Le plan n existe pas"
            
        else//sinon continuer la fonction
            
//---si le produit scalaire du vecteur directeur de la droite et du vecteur normal au plan est egale a 0 alors le plan et la droite est parallele---//
            parallele = produitscalaire(vecteurD , N )
                if(parallele == 0)
                    a = "Le plan et la droite sont parrallele"
//-------------------------------------------------------------------------------------------------------------------------------------------------//


                 else//sinon continuer la fonction
                
                    P0 = [planP(1) ,planP(2) ,planP(3)]//stock le premier point du plan 
                    d = produitscalaire(P0,N)//fait le produit scalaire du premier point du plan avec le vecteur normal du plan
                    d = (-d)//rend la valeur calculer au dessus negatif
                    U = [N ;d]//met le vecteur normal et la valeur calculer au dessus dans la meme matrice
                    Q = [droiteP(1) ,droiteP(2) ,droiteP(3)  , 1]//met un point de la droite dans une matrice avec comme dernier argument de la matrice 1 

//-----------toutes les variables creer plus tot sont utiliser a la formuler si dessous qui permet de calculer le paramètre t qui permet de connaitre la position du point d'intersection-----------//

                    t = (-produitscalaire(U , Q))/(produitscalaire(N , vecteurD))
//-------------------------------------------------------------------------------------------------------------------------------------------------//



//----en ajoutant t dans les paramètre de la droite on trouve donc la position du point d'intersection entre le plan et la droite----//
                    X = droiteP(1) + vecteurD(1) *t
                    Y = droiteP(2) + vecteurD(2) *t
                    Z = droiteP(3) + vecteurD(3) *t
                    
                    
                    
                    a = [X,Y,Z,t]//retourne la position du point d'intersection + la valeur de t
               end
       end 
endfunction


//exercice 4)

//--fonction qui dit si une droite touche un triangle en 3 dimension


function a=TRIANGE(droite , triangle )//la fonction prend en paramètre 2 points d'une droite et les 3 points du triangles
    
    I = intersectionplan(droite,triangle)//retourne la position du point d'intersection entre la droite et le plan du triangle 
         if(I == "Le plan n existe pas" || I == "Le plan et la droite sont parrallele")
             a="le triangle n existe pas "
         elseif(I == "Le plan et la droite sont parrallele")
             a = "la droite est parallèle au triangle "
         else
//---calcule les vecteurs utiliser plus loin dans une formuler--//
                 IP0 = [triangle(1)-I(1),triangle(2)-I(2),triangle(3)-I(3)]
                 IP1 = [triangle(4)-I(1),triangle(5)-I(2),triangle(6)-I(3)]
                 IP2 = [triangle(7)-I(1),triangle(8)-I(2),triangle(9)-I(3)]
                 P0P1 = [triangle(1)-triangle(4),triangle(2)-triangle(5),triangle(3)-triangle(6)]
                 P0P2= [triangle(1)-triangle(7),triangle(2)-triangle(8),triangle(3)-triangle(9)]
    
    
//---calcule la somme des petits parallèlogrammes former par IP0 et IP , IP1 et IP2 et IP2 et IP0----//
                 sommepetitparallelograme = produitvectoriel(IP0,IP1) + produitvectoriel(IP1,IP2)+ produitvectoriel(IP2,IP0)
                 
                 
//---calcule le parallèllogramme former par les 3 points du triangles----//
                 grandparallelograme = produitvectoriel(P0P1,P0P2)
//---si la somme des petits parallélogramme est égales au grand parrallélogramme provoquer par les 3 points du triangle alors la droite touche le triangle---// 
                 if(sommepetitparallelograme == grandparallelograme)
                         a = "BRAVO L intersection est dans le triangle"
                 else//sinon il a rater le triangle
                         a = "Rater il n est pas dans le triangle"
                 end
        end
endfunction
