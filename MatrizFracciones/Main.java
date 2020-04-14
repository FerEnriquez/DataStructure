import java.util.Scanner;
/**
*	Main class 
*	@author María Fernanda Hernández Enriquez A01329383 
*	@author Manuel Alejandro Neri Reyes A01329872
*	@version	1.0
*/
public class Main{
	public static void main (String[] args){
		Scanner x = new Scanner (System.in);
		
		//System.out.println("Primera matriz");
		//System.out.print("Ren: ");
		int rA = x.nextInt();
		//System.out.print("Col: ");
		//System.out.println("");
		int cA = x.nextInt();
		FractionMatrix matrA = new FractionMatrix(rA,cA);
		
		//System.out.println("Segunda matriz");
		//System.out.print("Ren: ");
		int rB = x.nextInt();
		//System.out.print("Col: ");
		//System.out.println(""); 
		int cB = x.nextInt();
		FractionMatrix matrB = new FractionMatrix(rB, cB);

		boolean permiso = matrA.condition(matrB);
		if (permiso){
			//System.out.println("");
			System.out.println("Primera Matriz:");
			Fraction[] aux = new Fraction[cA*rA];
			for(int i = 0; i< aux.length; i++){
				//System.out.print("Num: ");
				int num = x.nextInt();
				//System.out.print("Den: ");
				int dem = x.nextInt();
				Fraction f = new Fraction (num, dem);
				aux[i] = f;
			}
		matrA.addFractions(aux);
		//System.out.println("");
		System.out.println(matrA.toString(matrA.maxLength()));
			
			System.out.println("Segunda Matriz:");
			aux = new Fraction[cB*rB];
			for(int i = 0; i< aux.length; i++){
			//System.out.print("Num: ");
			int num = x.nextInt();
			//System.out.print("Den: ");
			int dem = x.nextInt();
			Fraction f = new Fraction (num, dem);
			aux[i] = f;
			}
		matrB.addFractions(aux);
		//System.out.println("");
		System.out.println(matrB.toString(matrB.maxLength()));
		
			System.out.println("Resultado: ");

			FractionMatrix result = new FractionMatrix(rA,cB);
			Fraction[] aux2 = new Fraction[rA*cB];
			Fraction[][] res = matrA.multiplicar(matrB);
			int z = 0;
			for(int i = 0; i< rA; i++){
				for(int j = 0; j < cB; j++){
					aux2[z] = res[i][j];
					z++;
				}
			}
			result.addFractions(aux2);
			System.out.println(result.toString(result.maxLength()));
		}
		else
			System.out.println("No se puede realizar la operacion.");

	}
}