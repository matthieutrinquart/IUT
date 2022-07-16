import java.util.*;



public class Random
{
	static int rand;
	static int guess;
	public static void main (String [] arg)
	{
		rand = (int)(Math.random() * 11);
		int nbrtry = 0;
		

		
		do
		{
			System.out.println("devinez le nombre entre 1 et 10");
			Scanner clavier = new Scanner(System.in);
			guess = clavier.nextInt();
			nbrtry ++ ;
		}while(guess != rand && nbrtry < 5);
			
		if(nbrtry >= 5)
			System.out.println("You lose \nle nombre était " + rand);
		else if(guess==rand)
			System.out.println("You win");
		
	}
	
	/*public static void SuiteF(int Ish)
	{
		
		if(Ish < 0 ) 
		{
			System.out.println("NTM MATHIEU");
			return;
		}
		if(Ish == 0 ) 
		{
			System.out.println("t0 = 1");
			return;
		}
		
		int Tm2 = 1;
		int Tm1 = 1;
		System.out.println("t0 = 1");
		System.out.println("t1 = 1");
		
		
		int resultat;
		
		for(int i = 2 ; i<= Ish ; i++)
		{
			resultat = Tm2 + Tm1 ;
			System.out.println("t" + i +" = " + resultat);
			
			Tm2 = Tm1 ;
			Tm1 = resultat;
		}
	}*/
}