//exercice1

//1)

X1T = imread('C:\Users\t18001195\Desktop\Math\lena.pgm');
X1 = mat2gray(X1T)
//imshow(X1)
//on met dans la matrice lena.pgm
//2)
X2T = imnoise(X1, 'gaussian', 0.01)//on met que l'ecart type
X2 = mat2gray(X2T)
//imshow(X2)
//on met un bruit blanc gaussien avec une valeur d'ecart type de 0.01.un bruit apparait sur l'image plus l'ecart type est grand plus le bruit est present
//3)

X3T = imnoise(X1, 'salt & pepper', 0.05); //avec sivp
X3 = mat2gray(X3T)
//imshow(X3)
//on applique un poivre et sel sur l'image avec cette fonction et des fixel blanc  et noir apparait.Plus la variable p est gra,de plus le bruit poivre et sel est present.

//4)
//X = [X1,X2,X3]
//imshow(X)



//la premiere modification gaussian met un bruit ambian a l'image er rend l'image moins net,La 2éme met des pixel noir et blanc un peu partout dans l'image ce qui donne un effet poivre et sel



//exercice2)


//2)
//F = fspecial('average', 3);
//
//Y2 = imfilter(X2, F)
//
//
//Y = [X1,X2,Y2]
//
//imshow(Y)
//le bruit c'est attenuier mais il reste un effet de flou sur l'image qui est donc moins net que l'image original

//3)
