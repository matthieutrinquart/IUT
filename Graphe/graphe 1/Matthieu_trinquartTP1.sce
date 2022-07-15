//exercice 1

//1)
clear
N_ref=4; // nombre de sommets
M_ref=[0,1,1,0; 1,0,1,1; 1,1,0,1; 0,1,1,0]; // matrice d'adjacence
A_ref=[1,2;1,3;2,3; 2,4; 3,4]; // liste d'aretes
L_ref=[2,3,0;1,3,4; 1,2,4; 2,3,0]; // liste d'adjacence

//2)
//function M=listadjTOmatadj(n,L)
//    A= zeros(n,n)
//    for i = 1:n
//        for j = 1:(n-1)
//            if L(i,j)<>0 then
//                 A(i,L(i,j)) = 1
//            end
//        end
//    end
//  M=A  
//endfunction
//
//M=listadjTOmatadj(N_ref,L_ref)
//disp(M)
//b)
//function L=matadjTOlistadj(n,M)
//    L= zeros(n,n - 1)
//    for i = 1:n
//        k = 1
//        for j = 1:n
//            if M(i,j)<>0 then
//                 L(i,k) = j
//                 k = k+ 1
//             end 
//        end 
//     end  
//endfunction
//
//L=matadjTOlistadj(N_ref,M_ref)
//disp(L)
//


//3)
//function L=listadjTOlistaretes (n ,M)
//        L= []
//    for i = 1:n
//        for j=i:n-1
//            if M(i,j) <> 0 then
//          L = [L;[i,M(i,j)]] 
//        end 
//        end 
// end
//endfunction
//L=listadjTOlistaretes(N_ref,L_ref)
//disp(L)

//b)

function L=listadjTOlistaretes (n ,M)
        L= zeros(n,n - 1)
    for i = 1:n
        for j=i:n-1
            if M(i,j) <> 0 then
          L = [L;[i,M(i,j)]] 
        end 
        end 
 end
endfunction
L=listadjTOlistaretes(N_ref,L_ref)
disp(L)
