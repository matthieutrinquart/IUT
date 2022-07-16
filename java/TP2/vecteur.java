import java.util.*;


public class vecteur
{
	public static Vector vect;
	public static void main (String [] arg)
	{
		vect = new Vector();
		remplissage(vect);
		//System.out.println(vect.size());
		//System.out.println(vect);

		int i = doublon(vect);
		System.out.println("il y a " + i + " doublons");
		supprDoublons(vect);

		i = doublon(vect);
		System.out.println("il y a " + i + " doublons");
	}

	public static void remplissage(Vector v)
	{
		System.out.println("combien d'elements voulez vous saisir ?");
		Scanner clavier = new Scanner(System.in);
		int nbr;
		nbr = clavier.nextInt();
		for(int i = 0 ; i < nbr ; ++i)
			v.add(clavier.next());
	}


	public static int doublon(Vector v)
	{
		int nbr = 0;
		Vector vect2;
		vect2 = new Vector();

		boolean isAlreadyCounted = false;

		for(int i = 0 ; i < v.size() ; ++i)
		{
			vect2.add("");
		}

		for(int i = 0 ; i < v.size() ; ++i)
		{
			vect2.setElementAt(v.elementAt(i),i);
			isAlreadyCounted = false;
			for(int j = 0 ; j < v.size()-i-1 ; ++j)
			{
					//System.out.println("v.elementAt(i) = "+v.elementAt(i)+ "           et v.elementAt(j+i+1) = "+v.elementAt(j+i+1));
					if(j != 0)
					{
						for(int k = 0 ; k< v.size() ; ++k)
						{
							if(vect2.elementAt(i).equals(v.elementAt(j+i+1)))
								isAlreadyCounted = true;
						}
					}
					if(v.elementAt(i).equals(v.elementAt(j+i+1)) && isAlreadyCounted == false)
					{
						nbr++;
					}
			}
		}

		return nbr;
	}

	public static void supprDoublons(Vector v)
	{
		int nbr = doublon(v);
		while(nbr > 0)
		{
			for(int i = 0 ; i < v.size() ; ++i)
			{
				for(int j = 0 ; j < v.size()-i-1 ; ++j)
				{
						//System.out.println("v.elementAt(i) = "+v.elementAt(i)+ "           et v.elementAt(j+i+1) = "+v.elementAt(j+i+1));
						if(v.elementAt(i).equals(v.elementAt(j+i+1)))
						{
							v.removeElementAt(j+i+1);
						}
				}
			}
			nbr--;
		}
	}

}
