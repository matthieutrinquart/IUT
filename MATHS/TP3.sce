//Exercice 1 TP3

//1)
t=[0:0.01:10];
//b0 = (1-t).^3 ;
//b1 = 3.*t.*((1-t).^2) ;
//b2 = 3.*t.^2.* (1-t) ;   
//b3 = t.^3 ;
//
//
//plot(t,b0);
//plot(t,b1);
//plot(t,b2);
//plot(t,b3);
//2)
P0 = [0 , 0]
P1 = [0 , 1]
P2 = [1 , 1]
P3 = [2 , 0]
ptsControle=[P0 ; P1 ; P2 ; P3 ] ;
X = (1-t).^3 .*P0(1) + 3.*(1-t).^2 .*t.*P1(1) + 3.*(1-t).*t.^2.*P2(1) + t.^3 .*P3(1) ;
Y = (1-t).^3 .*P0(2) + 3.*(1-t).^2 .*t.*P1(2) + 3.*(1-t).*t.^2.*P2(2) + t.^3 .*P3(2) ;
n = 3
i = 4
//
function B = BernsteinValue( n , i, t )
B = (factorial(n)/(factorial(i)*factorial( n - i)) ) *t.^i *(1-t).^(n-i) 

endfunction


function p = computeBezierPoint( nbPtsControle , ptsControle, t , degre )
    p= []
    [A,B] = size(t)
        for(o = 1 : B)
              T = t(o)
              patate = 0 ;
    
                    for( i = 0:nbPtsControle - 1 )
                        patate = patate + ptsControle(i + 1,:) * BernsteinValue(degre ,i, T) ;
                    end
                    p = [p ; patate]
        end
endfunction


/*
function f = fact(n)
if(n==0)then
f=1;
else
f = prod (1:n) ;
end ;
endfunction
*/
nbPtsControle = 4

 p = computeBezierPoint( nbPtsControle , ptsControle, t  , n)
ptsContX= p(:,1) ;
ptsContY= p(:,2) ;

//plot(ptsContX , ptsContY , "-*r" ) ;

//3)


function B = deriverBernsteinValue( n , i, t )
//N = n-1
//I = i - 1
if(i ~= 0 && i~=n )
B = n*(BernsteinValue( n - 1  , i - 1, t )-BernsteinValue( n - 1 , i, t )) 
end
endfunction

function p = derivercomputeBezierPoint( nbPtsControle , ptsControle, t , degre )
p= []
[A,B] = size(t)
for(o = 1 : B)
    T = t(o)
    patate = 0 ;
for( i = 0:nbPtsControle - 1)
patate = patate + ptsControle(i + 1,:) * deriverBernsteinValue(degre ,i, T) ;
end
p = [p ; patate]
end
endfunction

 C = derivercomputeBezierPoint( nbPtsControle , ptsControle, t  , n)
ptsContX= C(:,1) ;
ptsContY= C(:,2) ;

//plot(ptsContX , ptsContY , "-*r" ) ;


//exercice 2 )
function y = homogene ( x )
y = x ;
endfunction


function tabRetours = computeParamValues ( maFonction , numValeurs )
tabRetours = [ ] ;
for u = 0: 1 / numValeurs : 1
v = maFonction ( u ) ;
tabRetours = [ tabRetours , v ] ; 
end
endfunction

function curvePoints = computeBezierCurve (nbPtsControle , ptsControle , t , degre )
    curvePoints = []
param = computeParamValues ( homogene , nbPtsControle )
for p = param//0.1 0.2 0.3
curvePoints = [curvePoints ; computeBezierPoint( nbPtsControle ,ptsControle, p  , degre) ] ; //0.1 0.2 0.3
end
endfunction


//2)
function B = X( t )
B = t^2
endfunction

function p = Xcarrer( nbPtsControle , ptsControle, t)
    p= []
    [A,B] = size(t)
        for(o = 1 : B)
              T = t(o)
              patate = [] ;
    
                   // for( i = 0:nbPtsControle - 1 )
                        patate = [T , X(T)] ;
                  //  end
                    p = [p ; patate]
        end
endfunction
function D = distanceXcarrer ( nbPtsControle , ptsControle , t )
 //   A = computeParamValues( homogene , nbPtsControle )
 D = []
 D(1) = 0
    C = Xcarrer( nbPtsControle ,ptsControle, t  );
    
[n1,n2] = size(C)
  for i = 2 :n1  - 1
      Xa = C(i , 1)
      Xb = C(i + 1 , 1)
      Ya = C(i , 2)
      Yb = C(i + 1 , 2)
    D(i) = sqrt((Xa - Xb)^2 + (Ya -Yb)^2 )
end
endfunction



//3)

function B = Fonction( t )
B = -(2*t - 1)^2 + 1
endfunction


function p = XFonction( nbPtsControle , ptsControle, t)
    p= []
    [A,B] = size(t)
        for(o = 1 : B)
              T = t(o)
              patate = [] ;
    

                        patate = [T , Fonction(T)] ;

                    p = [p ; patate]
        end
endfunction
function D = distanceXFonction( nbPtsControle , ptsControle , t )
 //   A = computeParamValues( homogene , nbPtsControle )
 D = []
 D(1) = 0
    C = XFonction( nbPtsControle ,ptsControle, t  );
    
[n1,n2] = size(C)
  for i = 2 :n1  - 1
      Xa = C(i , 1)
      Xb = C(i + 1 , 1)
      Ya = C(i , 2)
      Yb = C(i + 1 , 2)
    D(i) = sqrt((Xa - Xb)^2 + (Ya -Yb)^2 )
end
endfunction
 C = XFonction( nbPtsControle ,ptsControle, t );
D = distanceXFonction(nbPtsControle , ptsControle , t )
//plot(D) ;
//plot(C) ;
//plot(C) ;
//plot(C, "-*r" ) ;



//3.1.5


function D = distanceXFonction( nbPtsControle , ptsControle , t )
 //   A = computeParamValues( homogene , nbPtsControle )
 D = []
 D(1) = 0
    C = XFonction( nbPtsControle ,ptsControle, t  );
    
[n1,n2] = size(C)
  for i = 2 :n1  - 1
      Xa = C(i , 1)
      Xb = C(i + 1 , 1)
      Ya = C(i , 2)
      Yb = C(i + 1 , 2)
    D(i) = sqrt((Xa - Xb)^2 + (Ya -Yb)^2 )
end
endfunction



//Casteljau
/*
 // Calcul des points intermédiaires
 Pour j de 1 à N faire
 |
 | Pour i de 0 à N-j faire
 | |
 | | T[i][j] = t*T[i+1][j-1] + (1-t)*T[i][j-1]
 | |
 |
 Afficher T[0][N] // Afficher (ou stocker) le point
*/
P0 = [0 , 0]
P1 = [0 , 1]
P2 = [1 , 1]
P3 = [2 , 0]
ptsControle=[P0 ; P1 ; P2 ; P3 ] ;

t=[0:0.01:1];
function D = Casteljau(ptsControle , t)
    [N,B] = size(ptsControle);
    D = []
     [A,B] = size(t)
for  o =  1:B
    T = []
    for i = 1 :N
     T(i ,1 , 1) = ptsControle(i,1)
      T(i ,1 , 2) = ptsControle(i,2)
    end
    for J = 2:N
        for i = 1:N - (J-1)
            
            T(i,J,1) = t(o)*T(i+ 1,J-1,1) + (1 - t(o)) *T(i , J - 1 ,1)
            T(i,J,2) = t(o)*T(i+1,J-1,2) + (1-t(o)) *T(i,J-1,2)
            
        end
    end
      //disp(T(1,N , 2)) 
    D = [D ;[T(1,N , 1),T(1,N , 2)]]
end
disp(D)
endfunction

S =  Casteljau(ptsControle , t)
ptsContX= S(:,1) ;
ptsContY= S(:,2) ;
plot(ptsContX ,ptsContY )

