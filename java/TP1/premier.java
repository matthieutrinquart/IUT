import java.util.*;



public class premier
{
	static int rand;
	static int guess;
	public static void main (String [] arg)
	{
		if( arg.length == 1 )
		{
			System.out.println("OK");
			// OK, le tableau contient bien une chaine
			int n = Integer.parseInt(arg[0]);
			boolean truc = prems(n);
			System.out.println(truc);
			if(truc)
				System.out.println("true");
			else if(!truc)
				System.out.println("false");
		}
		else
			return;
		
	}
	
	public static boolean prems(int nombre)
	{
		for(int i = 2 ; i <=10000; i++)
		{
			if(i == nombre)
			{
				//do nothing
			}
			else if (nombre%i == 0)
			{
				return false;
			}
		}
		return true;
	}
}