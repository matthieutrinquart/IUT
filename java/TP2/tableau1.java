import java.util.*;


public class tableau1
{
	public static float [] tab ;
	public static void main (String [] arg)
	{

		tab = new float[12];
		int nbrn,nbre;

		remplirTableau(tab);
		nbrn = nbrTempN(tab);
		nbre = nbrTempE(tab, 5f);
		System.out.println("il y a "+ nbrn + " Temperatures negatives et "+ nbre + " Temperatures égales a 5.");
	}


	public static void remplirTableau(float [] tableau)
	{
		//tableau = new float[12];
		System.out.println("Veuillez saisir les 12 temperatures : ");
		Scanner clavier = new Scanner(System.in);
		for(int i = 0 ; i < 12 ; ++i)
		{
			tableau[i] = clavier.nextFloat();
			System.out.println("Vous venez de saisir " + tableau[i]);

		}
	}

	public static int nbrTempN(float [] tableau)
	{
		int nbr = 0;
		for(int i = 0 ; i < (int)12 ; ++i)
		{
			if (tableau[i] < 0)
			{
				nbr++;
			}
		}
		return nbr;
	}


	public static int nbrTempE(float [] tableau, float temp)
	{
		int nbr = 0;
		for(int i = 0 ; i < (int)12 ; ++i)
		{
			if (tableau[i] == temp)
			{
				nbr++;
			}
		}
		return nbr;
	}
}
