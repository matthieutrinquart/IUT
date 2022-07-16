varying float isPoint;//variable échangée entre le vertex et le fragment shader qui va determiner si le point s'allume ou pas

void main(void)
{
 	//modif de tous les pixels (bleu)

	if(isPoint == 1.0) //si le point est dans le rayon du cercle
	{
		gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);  //Alors il affiche en rouge
	}else
	{
		gl_FragColor = vec4(0.0, 0.0, 1.0, 1.0);//Alors il affiche en bleu
	}

}
