import java.util.*;

public class principal
{
  public static void main (String [] arg)
	{
    Vector<etudiant> listeEtudiant;
    listeEtudiant = new Vector<etudiant>();

    remplirListe(listeEtudiant);

    affEtudiants(listeEtudiant);
  }

  public static void remplirListe(Vector<etudiant> v)
  {
    System.out.println("Combien d'etudiant voulez vous saisir ?");
    Scanner clavier = new Scanner(System.in);
    int nbr;
    nbr = clavier.nextInt();
    clavier.nextLine();
    String nom,prenom;
    float moyenne;
    etudiant eleve;
    for(int i = 0 ; i < nbr ; ++i)
    {
      System.out.println("nom de l'etudiant " + (i+1) );
      nom = clavier.nextLine();
      System.out.println("prenom de l'etudiant " + (i+1));
      prenom = clavier.nextLine();
      System.out.println("moyenne de l'etudiant " + (i+1));
      moyenne = clavier.nextFloat();
      clavier.nextLine();
      eleve = new etudiant(nom,prenom,moyenne);
      v.add(eleve);
    }

  }

  public static void affEtudiants(Vector<etudiant> v)
  {
    for(int i = 0 ; i< v.size() ; ++i)
    {
      v.elementAt(i).affiche();
    }
  }
}
