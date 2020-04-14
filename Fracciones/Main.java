import java.util.Scanner;
/**
@author Ma. Fernanda Hernandez Enriquez
A01329383
*/
public class Main{
	public static void main (String[] args){
		
		Scanner x = new Scanner(System.in);

		FracArray set = null;
		int opcion = -1;
		while (opcion != 0){
			System.out.print("Opcion: ");
			opcion = x.nextInt();
			switch (opcion){
				case 1:
				System.out.print("¿Cuantas fracciones? ");
				int tamano = x.nextInt();
				set = new FracArray(tamano);
				int i = 0;
				while(i < tamano){	
					System.out.print("Numerador: ");
					int num = x.nextInt();
					System.out.print("Denominador: ");
					int dem = x.nextInt();
					Fraction f = new Fraction (num, dem);
					set.addFracc(f);

					i++;
				}
				break;
				case 2:
				if (set==null){
					System.out.println("Debes agregar fracciones primero.");
				}
				else{
					Fraction suma = new Fraction(0,0);
					suma = set.getSum();
					suma.gcd(suma.getNum(),suma.getDem());
					suma.simplify();
					int n = set.maxLength();
					System.out.println("La suma de las fracciones es: " + suma.toString1(n));
				}
				break;
				case 3:
				if (set==null){
					System.out.println("Debes agregar fracciones primero.");
				}
				else{	
					Fraction promedio = new Fraction (0,0);
					promedio = set.getAver();
					promedio.gcd(promedio.getNum(), promedio.getDem());
					promedio.simplify();
					System.out.println("El promedio de las fracciones es: " + promedio.toString1(set.maxLength()));
				}
				break;
				case 4:
				if (set==null){
					System.out.println("Debes agregar fracciones primero.");
				}
				else{	
					set.sort();
					System.out.println("Las fracciones ordenadas son: " + set.stringSpace(set.maxLength()));
				}
				break;
				case 0:
				System.out.println("Salir.");
				break;
				default:
				System.out.println("Opcion invalida");
				break;
			}
		}
	}
}