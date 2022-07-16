//exercice2

//1)

X1T = imread('C:\Users\matth\Searches\Downloads\lena.pgm');
X1 = mat2gray(X1T)
X2T = imnoise(X1, 'gaussian', 0.01);
X2 = mat2gray(X2T)
X3T = imnoise(X1, 'salt & pepper', 0.05); 
X3 = mat2gray(X3T)
//2)
F = fspecial('average', 3);

Y2 = imfilter(X2, F)

//
//Y = [X1,X2,Y2]
//
//imshow(Y)
//le bruit c'est attenuier mais il reste un effet de flou sur l'image qui est donc moins net que l'image original

//3)

function res = mediane(image,n) //sz = taille de l'élément structurant
    [largeur, hauteur] = size(image)
    res = image
    c = (n-1)/2
    for i = c+1:(largeur-c-1)
        for j = c+1:(hauteur-c-1)
            res(i,j) = median(image(i-c:i+c,j-c:j+c))
        end
    end
endfunction
//
//Y3 = mediane(X3,3)
//Y = [X1,X3,Y3]
//imshow(Y)
//L'effet poivre et sel est bien enlever mais il y a une sorte de flou qui est apparu sur l'image
//4)
function res = PSNR(image1 , image2)
[largeur , hauteur] = size(image1)
somme = 0
for i = 1:largeur
    for j = 1:hauteur
        
        somme = somme +  (image1(i,j) - image2(i,j)).^2
        
        
    end
end
res = 10*log10(1.^2/((1/(largeur*hauteur)) * somme))
endfunction




//5) a)


F1 = fspecial('average', 3);

A1 = imfilter(X2, F1)

M1 = PSNR(X2,A1)
disp(M1)
//le PSNR est a 20.302768 ce qui est au dessus de 20Db le resultat me semble logique au vue du flou qu'on peut observer sur l'image.Le masque ne fais pas bien son travaille

F2 = fspecial('average', 5);

A2 = imfilter(X2, F2)

M2 = PSNR(X2,A2)
disp(M2)
//le PSNR s'approche a 19,577311 l'image s'ameliore

F3 = fspecial('average', 7);

A3 = imfilter(X2, F3)

M3 = PSNR(X2,A3)
disp(M3)
//le PSNR s'approche a 19.117449  l'image s'ameliore encore plus le filtre moyenneur est grand

P1=[X2,A1;
   X2,A2;
   X2,A3;]    
//imshow(A)
//Ce n'est pas logique le PSNR s'améliore mais les image sont de plus en plus flou
///////////////////////////////////////////////////////////////////////////////

F1 = fspecial('average', 3);

A1 = imfilter(X3, F1)

M1 = PSNR(X3,A1)
disp(M1) 
18.479779

F2 = fspecial('average', 5);

A2 = imfilter(X3, F2)

M2 = PSNR(X3,A2)
disp(M2)
//17.954761



F3 = fspecial('average', 7);

A3 = imfilter(X3, F3)

M3 = PSNR(X3,A3)
disp(M3)
//17.713284

D1=[X3,A1;
   X3,A2;
   X3,A3;]    

//imshow(A)
//Ce n'est pas logique le PSNR s'améliore mais les image sont de plus en plus flou
///////////////////////////////
//b)
F1 = fspecial('gaussian', 15, 2);

A1 = imfilter(X3, F1)

M1 = PSNR(X3,A1)
disp(M1)
//17.969543


//
F2 = fspecial('gaussian', 15 ,1.5);

A2= imfilter(X3, F2)

M2 = PSNR(X3,A2)
disp(M2)
////18.316208
//


F3 = fspecial('gaussian', 15, 0.5);

A3 = imfilter(X3, F3)

M3 = PSNR(X3,A3)
disp(M3)
////25.713798
D2=[X3,A1;
   X3,A2;
   X3,A3;] 
//imshow(A)

//l'image la plus net esr A2 avec le filtre a 1.5
//////////////////////////////////////////////////////////////
F1 = fspecial('gaussian', 15, 2);

A1 = imfilter(X2, F1)

M1 = PSNR(X2,A1)
disp(M1)
//19.42181


//
F2 = fspecial('gaussian', 15 ,1.5);

A2= imfilter(X2, F2)

M2 = PSNR(X2,A2)
disp(M2)
////19.908432
//


F3 = fspecial('gaussian', 15, 0.5);

A3 = imfilter(X2, F3)

M3 = PSNR(X2,A3)
disp(M3)
////27.484771
P2=[X2,A1;
   X2,A2;
   X2,A3;] 
//imshow(A)
////visuellement l'image la plus net est A2 meme si elle a pas le meilleur PSNR
////////////////////////////////////////////////////////////////////////////////
//c)



A1 = mediane(X3 , 3)

M1 = PSNR(X3,A1)
disp(M1)
//  18.257487


//
A2=  mediane(X3 , 5)

M2 = PSNR(X3,A2)
disp(M2)
////18.044185
//



A3 = mediane(X3 , 7)

M3 = PSNR(X3,A3)
disp(M3)
////17.863187
D3=[X3,A1;
   X3,A2;
   X3,A3;] 
//imshow(A)

//L'image A2 est la meilleur visuellement
//////////////////////////////////////////////////////////////



A1 = mediane(X2 , 3)

M1 = PSNR(X2,A1)
disp(M1)
//  20.248342


//
A2=  mediane(X2 , 5)

M2 = PSNR(X2,A2)
disp(M2)
////19.746299
//



A3 = mediane(X2 , 7)

M3 = PSNR(X2,A3)
disp(M3)
////19.416983
P3=[X2,A1;
   X2,A2;
   X2,A3;] 
//imshow(A)



D = [D1;D2;D3]
P=[P1;P2;P3]

//imshow(D)
imshow(P)
//pour X2 le filtre le mieux visuellement est le mediane taille 5
//pour X3 le filtre le mieux visuellement est  le filtre gaussieb avec un ecart type de 1.5 
//Mais pour le PSNR le meilleur filtre pour X3 est le median taille 7 avec un score de 17.863187 
//pour X2 celon de PSNR le meilleur filtre est le filtre moyenneur avec un score de 19.117449
