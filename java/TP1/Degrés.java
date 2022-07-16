import java.util.*;



public class Degrés
{
	static float Fahrenheit;
	static float Celsius;
	public static void main (String [] arg)
	{
		Scanner clavier = new Scanner(System.in);
		
		System.out.println("Entrez votre temperature en °C");
		Celsius = clavier.nextFloat();
		
		Fahrenheit = CelsiusToF(Celsius);
		System.out.print(Celsius + " °C = " + Fahrenheit + "°F");
	}
	
	public static float CelsiusToF(float celsius)
	{
		celsius = celsius * 9;
		celsius = celsius/5;
		celsius += 32;
		
		return celsius;
	}
}