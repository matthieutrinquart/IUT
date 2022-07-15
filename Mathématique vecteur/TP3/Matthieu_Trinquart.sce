//Matthieu Trinquart Info 2 TP1
//exercice de casteljau toute a la fin ligne 226


////Exercice 1 TP3
//
////1)
//
//t=[0:0.01:10];
////b0 = (1-t).^3 ;
////b1 = 3.*t.*((1-t).^2) ;
////b2 = 3.*t.^2.* (1-t) ;   
////b3 = t.^3 ;
////
////
////plot(t,b0);
////plot(t,b1);
////plot(t,b2);
////plot(t,b3);
////2)
//P0 = [0 , 0]
//P1 = [0 , 1]
//P2 = [1 , 1]
//P3 = [2 , 0]
//ptsControle=[P0 ; P1 ; P2 ; P3 ] ;
//X = (1-t).^3 .*P0(1) + 3.*(1-t).^2 .*t.*P1(1) + 3.*(1-t).*t.^2.*P2(1) + t.^3 .*P3(1) ;
//Y = (1-t).^3 .*P0(2) + 3.*(1-t).^2 .*t.*P1(2) + 3.*(1-t).*t.^2.*P2(2) + t.^3 .*P3(2) ;
//n = 3
//i = 4
////
//function B = BernsteinValue( n , i, t )
//B = (factorial(n)/(factorial(i)*factorial( n - i)) ) *t.^i *(1-t).^(n-i) 
//
//endfunction
//
//
//function p = computeBezierPoint( nbPtsControle , ptsControle, t , degre )
//    p= []
//    [A,B] = size(t)
//        for(o = 1 : B)
//              T = t(o)
//              patate = 0 ;
//    
//                    for( i = 0:nbPtsControle - 1 )
//                        patate = patate + ptsControle(i + 1,:) * BernsteinValue(degre ,i, T) ;
//                    end
//                    p = [p ; patate]
//        end
//endfunction
//
//
//
//function f = fact(n)
//if(n==0)then
//f=1;
//else
//f = prod (1:n) ;
//end 
//endfunction
//
//nbPtsControle = 4
//
// p = computeBezierPoint( nbPtsControle , ptsControle, t  , n)
//ptsContX= p(:,1) ;
//ptsContY= p(:,2) ;
//
////plot(ptsContX , ptsContY , "-*r" ) ;
////
//////3)
////
////
////function B = deriverBernsteinValue( n , i, t )
//////N = n-1
//////I = i - 1
////if(i ~= 0 && i~=n )
////B = n*(BernsteinValue( n - 1  , i - 1, t )-BernsteinValue( n - 1 , i, t )) 
////end
////endfunction
////
////function p = derivercomputeBezierPoint( nbPtsControle , ptsControle, t , degre )
////p= []
////[A,B] = size(t)
////for(o = 1 : B)
////    T = t(o)
////    patate = 0 ;
////for( i = 0:nbPtsControle - 1)
////patate = patate + ptsControle(i + 1,:) * deriverBernsteinValue(degre ,i, T) ;
////end
////p = [p ; patate]
////end
////endfunction
////
//// C = derivercomputeBezierPoint( nbPtsControle , ptsControle, t  , n)
////ptsContX= C(:,1) ;
////ptsContY= C(:,2) ;
////
//////plot(ptsContX , ptsContY , "-*r" ) ;
////
////
//////exercice 2 )
////function y = homogene ( x )
////y = x ;
////endfunction
////
////
////function tabRetours = computeParamValues ( maFonction , numValeurs )
////tabRetours = [ ] ;
////for u = 0: 1 / numValeurs : 1
////v = maFonction ( u ) ;
////tabRetours = [ tabRetours , v ] ; 
////end
////endfunction
////
////function curvePoints = computeBezierCurve (nbPtsControle , ptsControle , t , degre )
////    curvePoints = []
////param = computeParamValues ( homogene , nbPtsControle )
////for p = param//0.1 0.2 0.3
////curvePoints = [curvePoints ; computeBezierPoint( nbPtsControle ,ptsControle, p  , degre) ] ; //0.1 0.2 0.3
////end
////endfunction
////
////
//////2)
////function B = X( t )
////B = t^2
////endfunction
////
////function p = Xcarrer( nbPtsControle , ptsControle, t)
////    p= []
////    [A,B] = size(t)
////        for(o = 1 : B)
////              T = t(o)
////              patate = [] ;
////    
////                   // for( i = 0:nbPtsControle - 1 )
////                        patate = [T , X(T)] ;
////                  //  end
////                    p = [p ; patate]
////        end
////endfunction
////function D = distanceXcarrer ( nbPtsControle , ptsControle , t )
//// //   A = computeParamValues( homogene , nbPtsControle )
//// D = []
//// D(1) = 0
////    C = Xcarrer( nbPtsControle ,ptsControle, t  );
////    
////[n1,n2] = size(C)
////  for i = 2 :n1  - 1
////      Xa = C(i , 1)
////      Xb = C(i + 1 , 1)
////      Ya = C(i , 2)
////      Yb = C(i + 1 , 2)
////    D(i) = sqrt((Xa - Xb)^2 + (Ya -Yb)^2 )
////end
////endfunction
////
////
////
//////3)
////
////function B = Fonction( t )
////B = -(2*t - 1)^2 + 1
////endfunction
////
////
////function p = XFonction( nbPtsControle , ptsControle, t)
////    p= []
////    [A,B] = size(t)
////        for(o = 1 : B)
////              T = t(o)
////              patate = [] ;
////    
////
////                        patate = [T , Fonction(T)] ;
////
////                    p = [p ; patate]
////        end
////endfunction
////function D = distanceXFonction( nbPtsControle , ptsControle , t )
//// //   A = computeParamValues( homogene , nbPtsControle )
//// D = []
//// D(1) = 0
////    C = XFonction( nbPtsControle ,ptsControle, t  );
////    
////[n1,n2] = size(C)
////  for i = 2 :n1  - 1
////      Xa = C(i , 1)
////      Xb = C(i + 1 , 1)
////      Ya = C(i , 2)
////      Yb = C(i + 1 , 2)
////    D(i) = sqrt((Xa - Xb)^2 + (Ya -Yb)^2 )
////end
////endfunction
//// C = XFonction( nbPtsControle ,ptsControle, t );
////D = distanceXFonction(nbPtsControle , ptsControle , t )
//////plot(D) ;
//////plot(C) ;
//////plot(C) ;
//////plot(C, "-*r" ) ;
////
////
////
//////3.1.5
////
////
////function D = distanceXFonction( nbPtsControle , ptsControle , t )
//// //   A = computeParamValues( homogene , nbPtsControle )
//// D = []
//// D(1) = 0
////    C = XFonction( nbPtsControle ,ptsControle, t  );
////    
////[n1,n2] = size(C)
////  for i = 2 :n1  - 1
////      Xa = C(i , 1)
////      Xb = C(i + 1 , 1)
////      Ya = C(i , 2)
////      Yb = C(i + 1 , 2)
////    D(i) = sqrt((Xa - Xb)^2 + (Ya -Yb)^2 )
////end
////endfunction





//3)Casteljau



/*---Déclaration des points---*/
P0 = [0.5 , 1 ]
P1 = [0.3 , 3 ]
P2 = [0.8 , 5 ]
P3 = [2 , 0 ]

ptsControle=[P0 ; P1 ; P2 ; P3 ] ;//stockage des points dans une meme matrice
//---Affichage du polygone de controle----//
Xpos = ptsControle(:,1)
Ypos = ptsControle(:,2)
plot(Xpos ,Ypos , "-*g")   


//--declaration de t le nombre de point créer
t=[0:0.01:1];
function  Casteljau(ptsControle , t , R)//Fonction de Casteljau qui stocke les points de controles , une matrice t les paramètre de la courbe,et R qui savoir pour quelle moment on trace les polynomes intermediaire
[Ligne,Colonne] = size(ptsControle); //stocke les lignes et les colonnes de ptsControle pour savoir le nombre de point et le nombre de dimension
POINT = [] 
EnsemblePointFinal = []//stockera les coordonner des points 
[A,B] = size(t)//stocke les dimension de la matrice t pour pourvoir parcourir t 
    for  o =  1:B//parcour t pour toutes c'est valeur
         T = [] //stockera les point par rapport au temps t et a quelle point de controle
         //---stocke les point de controle dans le tableau T --//
         for i = 1 :Ligne
             for u = 1 :Colonne
                    T(i ,1 , u) = ptsControle(i,u)
             end
          end
          
        for J = 2:Ligne // parcour les point de controle
                     aff = []
                        for i = 1:Ligne - (J-1) 
                            ptsCoord = []
                            //--Utilise l'algorithme de casteljau pour toute dimension
                             for u = 1 :Colonne
                                T(i,J,u) = t(o)*T(i+ 1,J-1,u) + (1 - t(o)) *T(i , J - 1 ,u)
                             end
                             //--affiche les polynomes intermédiaire--/
                                    if(o == ((R)*100 + 1))
                                        H = []
                                        //--on stockes les point--//
                                        for u = 1 :Colonne
                                            H = [H , T(i,J , u)]
                                        end
                                        aff = [aff ;H]

                                         for u = 1 :Colonne
                                         ptsCoord = [ptsCoord ,aff(:,u)] ;
                                      end
                                      
                                      plot(ptsCoord(:,1),ptsCoord(:,2), "-*r" )//affiche les polynomes intermédiaire que pour la dimension 2
                        end

         end
     end
     Y = []
     
     //--stockes le points en fonctions de leur dimension
     for u = 1 :Colonne
         Y = [Y ,T(1,Ligne , u)]
         end
//on stocke tout les point dans dans POINT--/
          POINT = [POINT ;Y]
end 
plot(POINT(:,1) ,POINT(:,2))//affiche  la courbe que pour la dimension 2 
endfunction
R = 0.5
Casteljau(ptsControle , t , R)
