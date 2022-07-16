import java.util.*;


public class Secu
{

    static String num13;
    static String code2C;
	public static void main (String [] arg)
    {
        System.out.println("Saisissez les 13 premiers n° de Securité Sociale");
        Scanner clavier = new Scanner(System.in);
        num13 = clavier.nextLine();
        System.out.println("Saisissez le code de Securité Sociale (2 derniers chiffres");
		code2C = clavier.nextLine();
		if (isValid(num13, Integer.parseInt(code2C)))
		{
			System.out.println("C'EST VALIDE ");
		}else 
		{
			System.out.println("C'EST PAS VALIDE ");
		}
		
		info(num13);
		

    }

   	public static long calcCode(String num)
    {
		long result;
		if(num.charAt(6) == 'A')
		{
			num = num.replace('A','0');
			long valeurChaine = Long.parseLong(num);
			
			result = 97 - (valeurChaine-1000000)%97;
		}
		else if (num.charAt(6) == 'B')
		{
			num = num.replace('B','0');
			long valeurChaine = Long.parseLong(num);
			
			result = 97 - (valeurChaine-2000000)%97;
		}
		else
		{
		long valeurChaine = Long.parseLong(num);
		
		result = 97 - valeurChaine%97;
		}
		return result;
    }
	
	public static boolean isValid(String code13,int codeCtrl)
	{
		if(calcCode(code13) == codeCtrl)
		{
			return true;
		}else 
		{
			return false;
		}
	}
	
	public static void info(String code)
	{
		if(code.charAt(0) == 1)
		{
			System.out.println("Homme \n");
		}else if(code.charAt(0)==2)
		{
			System.out.println("Femme \n");
		}
		
		System.out.print("il est née en " + code.charAt(1) + code.charAt(2));
		
		String mois = code.substring(3,5);
		int num_mois = Integer.parseInt(mois);
		String noms_mois [] = {"Janvier","Février","Mars","Avril","Mai","Juin","Juillet","Aout","Septembre","Octobre","Novembre","Decembre"};
		System.out.println(noms_mois[num_mois - 1]);
		
		System.out.println("Dans le " + code.substring(5,10));
		System.out.println("Son numéro d'ordre est le" + code.substring(10,12));

	}

}