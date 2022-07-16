import java.util.*;



public class Commande
{
	static int i;
	public static void main (String [] arg)
	{
		for(int i = 0; i < arg.length ; i++)
		{
			System.out.println(arg[i]);
		}
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