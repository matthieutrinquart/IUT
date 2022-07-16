
uniform vec3 pointActuel;//le points que nous envoie le CPU
varying float isPoint;//variable échangée entre le vertex et le fragment shader qui va determiner si le point s'allume ou pas

void main(void)
{
	vec4 point = gl_Vertex;//vecteur
/*On aurait pu directement comparer point avec pointActuel */
	float d = distance(vec4(pointActuel, 1.0), point);//on fait la distance entre le point que le CPU nous a envoyé et le point que traite le GPU
	gl_Position = gl_ModelViewProjectionMatrix * point;



/*isPoint determine si oui ou non les points doivent etre rouge ou bleu*/
	    if(d <= 0.005)//On aurait pu mettre ==0 mais on met <=0.005 pour faire une zone autour du point
	        isPoint = 1.0;
	    else
	        isPoint = 0.0;
}
