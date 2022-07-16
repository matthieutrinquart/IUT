import java.util.*;



public class Pi
{
	static int i;
	public static void main (String [] arg)
	{
		double PI;
		if( arg.length == 1 )
		{
			// OK, le tableau contient bien une chaine
			int n = Integer.parseInt(arg[0]);
			
			
			PI = 0 ;
			for(int i = 1; i < n ; i++)
			{
				PI= PI + (double)(((double)1/(double)i)*((double)1/(double)i));
				System.out.println(PI);
			}
			PI = PI*6;
			PI = Math.sqrt(PI);
		}
		else
			return;
		
		
		System.out.println(PI);
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