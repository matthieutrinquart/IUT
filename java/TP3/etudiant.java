
import java.util.*;


public class etudiant
{
  String nom,prenom;
  float moyenne;
  public etudiant(String _nom, String _prenom, float _moyenne)
  {
    nom = _nom;
    prenom = _prenom;
    moyenne = _moyenne;
  }


  public void affiche()
  {
    System.out.println(prenom + nom +" a une moyenne de " + moyenne);
  }
}
