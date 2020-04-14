import java.util.Locale;
import java.util.Formatter;
/**
@author Ma. Fernanda Hernández Enriquez
A01329383
*/
public class FracArray{

	private Fraction[] arrFracc;
	private int noFracc;
	private Fraction sum;
	private Fraction aver;

	public FracArray(){
		this.arrFracc = new Fraction[1];
		this.noFracc = 0;
		this.sum = new Fraction(0,0);
		this.aver = new Fraction(0,0);
	}
	public FracArray(int size){
		this.arrFracc = new Fraction[size];
		this.noFracc = 0;
		this.sum = new Fraction(0,0);
		this.aver = new Fraction (0,0);
	}
	public boolean addFracc(Fraction newFracc){
		if (this.noFracc == this.arrFracc.length){
			return false;
		}
		else{
			this.arrFracc[this.noFracc] = newFracc;
			this.noFracc++;
			return true;
		}
	}
	public Fraction getSum(){
		int a = this.noFracc+1;
		Fraction[] aux = new Fraction[this.arrFracc.length];
		for(int i = 0; i < this.arrFracc.length; i++){
			aux[i] = this.arrFracc[i];
		}
		if(this.noFracc<a){
			for(int i = 0; i < this.arrFracc.length-1; i++){
				aux[i+1] = aux[i].fractionAdd(aux[i+1]);
			}
		}
		this.sum = aux[aux.length-1];
		return this.sum;
	}
	public Fraction getAver(){

				int a = this.noFracc+1;
			Fraction[] aux = new Fraction[this.arrFracc.length];
			for(int i = 0; i < this.arrFracc.length; i++){
				aux[i] = this.arrFracc[i];
			}
			if(this.noFracc<a){
				for(int i = 0; i < this.arrFracc.length-1; i++){
					aux[i+1] = aux[i].fractionAdd(aux[i+1]);
				}
			}
			this.sum = aux[aux.length-1];

		int x = this.sum.getDem()*(this.noFracc);
		this.aver.setNum(this.sum.getNum());
		this.aver.setDem(x);
		return this.aver;
	}
	public int maxLength(){
		int[] aux = new int[(this.noFracc+1)];
		for(int cont = 0; cont < this.noFracc; cont++){
			int x = this.arrFracc[cont].getNum();
			int y = this.arrFracc[cont].getDem();
			int i = 0;
			while(x!=0){
				x = x/10;
				i++;
			}
			int j = 0;
			while (y!=0){
				y = y/10;
				j++;
			}
			if(i>j){
				aux[cont] = i;
			}
			else if(j>i){
				aux[cont] = j;
			}
			else{
				aux[cont] = i;
			}
		}
		int nMax = aux[0];
		for(int cont = 0; cont < aux.length; cont++){
			if(aux[cont]>nMax){
				nMax = aux[cont];
			}
		}
		return nMax;
	}
	public String sort(){
		Fraction element;
		int j;
		for(int i = 1; i < this.arrFracc.length; i++){
			element = this.arrFracc[i];
			j = i - 1;
			while(j >= 0 && arrFracc[j].compareTo(element) == 1){
				this.arrFracc[j+1] = this.arrFracc[j];
				j--;
			}
			this.arrFracc[j+1] = element;
		}
		
		int p = 0;
		String q = "";
		while (p < this.noFracc){
			q = " "+arrFracc[p]+ " ";
			p++;
		}
		q += "";
		return q;
	}
	public String stringSpace(int n){
		String[] aux = new String[this.noFracc+1];
		for(int cont = 0; cont < this.noFracc; cont++){
			
		Formatter fx = new Formatter();
		fx.format("%0"+n+"d",this.arrFracc[cont].getNum());
		String x = ""+fx;
			   			 	
		Formatter fy = new Formatter();
		fy.format("%0"+n+"d",this.arrFracc[cont].getDem());
		String y = ""+fy;

		String result = ""+fx+"/"+fy+"";
									
		aux[cont] = result;
		}
		int p = 0;
		String q = "";
		while (p < this.noFracc){
			q += " "+aux[p]+ " ";
			p++;
		}
		return q;
	}
		
}