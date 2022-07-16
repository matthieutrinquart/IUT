import java.util.*;


public class tableau2
{
	public static float [][] tab ;
	public static void main (String [] arg)
	{


		int nbrn,nbre,nbryears;
		nbrn = 0;
		nbre = 0;


		Scanner clavier = new Scanner(System.in);
		System.out.println("Veuillez saisir le nombre d'années");
		nbryears = clavier.nextInt();
		tab = new float[12][nbryears];

		//System.out.println(tab[1].length);

		remplirTableau(tab);
		affichTab(tab);
		System.out.println("--------------------------------");
		affichMonth(tab,12);
		System.out.println("--------------------------------");
		affichMonthMinMax(tab,12);
		System.out.println("--------------------------------");


		//System.out.println("il y a "+ nbrn + " Temperatures negatives et "+ nbre + " Temperatures égales a 5.");
	}


	public static void remplirTableau(float [][] tableau)
	{
		//tableau = new float[12];
		System.out.println("-------------------------------------------");
		//Scanner clavier = new Scanner(System.in);
		for(int i = 0 ; i < 12 ; ++i)
		{
				for(int j = 0 ; j < tableau[0].length ; ++j)
				{
						tableau[i][j] = (float)(Math.random()*60)-20; //clavier.nextFloat();
						//System.out.println("Vous venez de saisir " + tableau[i]);
				}
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

	public static void affichTab(float [][] tableau)
	{
		System.out.println("Voici les temperatures : ");
		for(int i = 0 ; i < 12 ; ++i)
		{
				for(int j = 0 ; j < tableau[0].length ; ++j)
				{
						System.out.println(tableau[i][j]);
				}
		}

	}
	public static void affichMonth(float [][] tableau, int mois)
	{
		System.out.println("Voici les temperatures du " + mois + "eme mois :");
		for(int i = 0 ; i < tableau[0].length ; ++i)
		{

						System.out.println(tableau[mois-1][i]);

		}

	}
	public static void affichMonthMinMax(float [][] tableau, int mois)
	{
		float min,max;
		System.out.println("Voici les 12 temperatures : ");

		min = tableau[0][0];
		max = tableau[0][0];

		for(int i = 0 ; i < tableau[0].length ; ++i)
		{
			if(tableau[mois-1][i] < min)
			{
				min = tableau[mois-1][i];
			}

			if(tableau[mois-1][i] > max)
			{
				max = tableau[mois-1][i];
			}

		}
		System.out.println("la veleure min est " + min + " et la valeur max est " + max);
	}
}
