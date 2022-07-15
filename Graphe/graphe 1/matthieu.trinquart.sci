//mathhieu trinquart
//info 1
//TDA
//TP1



//TP4


//exercice 1

//1) On obtient ceci  : 

//M = [1,0;1,2]
 //M  = 

//   1.   0.
//   1.   2.


//--> N = [2,0;0,2]
// N  = 

//   2.   0.
//   0.   2.


//--> M ==N
// ans  =

//  F T
//  F T
  
//  2) si on mets isequal(M, [1 0 ; 1 2])
  
  
//  --> isequal(M, [1 0 ; 1 2])
// ans  =
 
  //T 
  
//  3)
  
//  Comme on a créer avant deux matrice M et N il suffit de faire :
//    isequal(M,N) pour comparer les deux matrices.

  
 // 4)
//MV = [%inf,8,2,%inf,%inf ; %inf,%inf,%inf,1,%inf ; %inf,5,%inf,11,1 ; %inf,%inf,%inf,%inf,%inf ; %inf,%inf,%inf,9,%inf]
//  function Dist= bellman_ford(M)
//[n,p] = size(M)
//Dist = ones(1 ,n)*%inf
//Dist(1) = 0
//Dist2 = list()
//while(isequal(Dist,Dist2) == %F) do 
//    Dist2 = Dist
//    for i = 1:n
//        for j = 1:p
//            if Dist(i) + M(i,j) < Dist(j) then
//               Dist(j)= Dist(i) + M(i,j);
//            end
//        end
//    end
//end
//endfunction
//bellman_ford(MV)
//ans  =
// 
//    0.    7.    2.    8.    3.  
//
//5)
//MV = [%inf,8,2,%inf,%inf ; %inf,%inf,%inf,1,%inf ; %inf,5,%inf,11,1 ; %inf,%inf,%inf,%inf,%inf ; %inf,%inf,%inf,9,%inf]
//function Dist = bf_long(M)
//    [n,p] = size(M);
//    for i=1:n
//        for j=1:p
//            if M(i,j) ~= %inf then
//                M(i,j)=-M(i,j);
//            end
//        end
//    end
//    bellman_ford(M)
//    Dist=bellman_ford(M)*-1;
//endfunction                      
//bf_long(MV)
// ans  =
// 
//    0.    8.    2.    13.    3.  
//
//
//  
  
//  Exercice 2 
//
// M=[0,0,%inf,%inf,%inf,%inf,%inf,%inf,%inf,%inf,%inf,%inf;
//     %inf,0,7,%inf,7,%inf,%inf,%inf,%inf,%inf,%inf,%inf;
//      %inf,%inf,0,3,%inf,%inf,%inf,%inf,%inf,%inf,%inf,%inf;
//      %inf,%inf,%inf,0,%inf,1,1,1,%inf,%inf,%inf,%inf;
//      %inf,%inf,%inf,%inf,0,8,8,8,%inf,%inf,%inf,%inf;
//      %inf,%inf,%inf,%inf,%inf,0,%inf,%inf,%inf,%inf,2,%inf;
//      %inf,%inf,%inf,%inf,%inf,%inf,0,%inf,1,%inf,%inf,%inf;
//      %inf,%inf,%inf,%inf,%inf,%inf,%inf,0,%inf,%inf,1,%inf;
//      %inf,%inf,%inf,%inf,%inf,%inf,%inf,%inf,0,3,%inf,%inf;
//      %inf,%inf,%inf,%inf,%inf,%inf,%inf,%inf,%inf,0,2,%inf;
//      %inf,%inf,%inf,%inf,%inf,%inf,%inf,%inf,%inf,%inf,0,1;
//         %inf,%inf,%inf,%inf,%inf,%inf,%inf,%inf,%inf,%inf,%inf,0;]
// A  = 
//
//
//         column 1 to 8
//
//   0.    0.    Inf   Inf   Inf   Inf   Inf   Inf
//   Inf   0.    7.    Inf   7.    Inf   Inf   Inf
//   Inf   Inf   0.    3.    Inf   Inf   Inf   Inf
//   Inf   Inf   Inf   0.    Inf   1.    1.    1. 
//   Inf   Inf   Inf   Inf   0.    8.    8.    8. 
//   Inf   Inf   Inf   Inf   Inf   0.    Inf   Inf
//   Inf   Inf   Inf   Inf   Inf   Inf   0.    Inf
//   Inf   Inf   Inf   Inf   Inf   Inf   Inf   0. 
//   Inf   Inf   Inf   Inf   Inf   Inf   Inf   Inf
//   Inf   Inf   Inf   Inf   Inf   Inf   Inf   Inf
//   Inf   Inf   Inf   Inf   Inf   Inf   Inf   Inf
//   Inf   Inf   Inf   Inf   Inf   Inf   Inf   Inf
//
//         column 9 to 12
//
//   Inf   Inf   Inf   Inf
//   Inf   Inf   Inf   Inf
//   Inf   Inf   Inf   Inf
//   Inf   Inf   Inf   Inf
//   Inf   Inf   Inf   Inf
//   Inf   Inf   2.    Inf
//   1.    Inf   Inf   Inf
//   Inf   Inf   1.    Inf
//   0.    3.    Inf   Inf
//   Inf   0.    2.    Inf
//   Inf   Inf   0.    1. 
//   Inf   Inf   Inf   0. 
//
//
//-->       

//--> bf_long(A)              chemins le plus long donc la date au plus tot 
// ans  =
//
//
//         column 1 to 8
//
//   0.   0.   7.   10.   7.   15.   15.   15.
//
//         column 9 to 12
//
//   16.   19.   21.   22.
//
//date_plus_tot = bf_long(M) 
//function P = inverse(M)
//T=M'
//A=T
//
//for i = 1:12
//    for j = 1:12
//        A(i,j)=T(13 - i , 13 - j)
//        
//end
//end
//M=A
//P = M 
//endfunction
//N=inverse(M)
//date_plus_tard = inverse(N) 
//date_ = 22 - date_plus_tard 
//







//  
//exercice 3 
//

//function arbre = prim(M)
//    
//    [n,p] = size(M)
//Dist = ones(1 ,n)*%inf
//Dist(1) = 0
//Dist2 = list()
//while(isequal(Dist,Dist2) == %F) do 
//    Dist2 = Dist
//    for i = 1:n
//        for j = 1:p
//            if Dist(i) + M(i,j) < Dist(j) then
//               Dist(j)= Dist(i) + M(i,j);
//            end
//        end
//    end
//end
//    
//    
//    
//    
//    
//endfunction
//




