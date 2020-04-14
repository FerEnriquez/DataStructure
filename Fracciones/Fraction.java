import java.util.Scanner;
import java.util.Locale;
import java.util.Formatter;
/**
	@author María Fernanda Hernández Enriquez
	A01329383
*/
public class Fraction{
	
	private int num;
	private int dem;
	public int newNum;
	public int newDem;

	public Fraction(){
		this.num = 0;
		this.dem = 0;
		this.newNum = 0;
		this.newDem = 0;
	}

	public Fraction(int num, int dem){
		this.num = num;
		this.dem = dem;
	}

	public int getNum(){
		return this.num;
	}
	public void setNum(int num){
		this.num = num;
	}
	public int getDem(){
		return this.dem;
	}
	public void setDem(int dem){
		this.dem = dem;
	}
	
	public Fraction fractionAdd(Fraction otFrac){
		Fraction x;
		if (this.dem == otFrac.getDem()){
			this.newNum = this.num + otFrac.getNum();
			x = new Fraction (this.newNum, this.dem);
		}
		else{
			this.newNum = (this.num*otFrac.getDem())+(this.dem*otFrac.getNum());
			this.newDem = this.dem*otFrac.getDem();
			x = new Fraction (this.newNum, this.newDem);
		}
		return x;
	}	
	public Fraction mul(Fraction other){
		Fraction result = new Fraction( this.num*other.getNum(), this.dem*other.getDem() );
		result.simplify();
		return result;
	}
	public void simplify(){
		int gcd = this.gcd(this.num, this.dem);
		
		this.num = this.num / gcd;
		this.dem = this.dem / gcd;
	}
	public int gcd(int x, int y){
		int temp;
		while(y != 0){
			temp = y;
			y = x%y;
			x = temp;
		}
		
		return x;
	}
	public int compareTo(Fraction other){
		if(this.num*other.getDem() == other.getNum()*this.dem){
			return 0;
		}
		else if(this.num*other.getDem() > other.getNum()*this.dem){
			return 1;
		}
		else if(this.num*other.getDem() < other.getNum()*this.dem){
			return -1;
		}
		else{
			throw new IllegalStateException("An impossible comparison state in compareTo method"); // Should never execute, but better safe than sorry
		}
	}
	public String toString(){
		String x = "" + this.num +"/"+ this.dem;
		return x;
	}
	public String toString1(int n){
		Formatter fx = new Formatter();
		fx.format("%0"+n+"d",this.num);
		String x = ""+fx;
						   			 	
		Formatter fy = new Formatter();
		fy.format("%0"+n+"d",this.dem);
		String y = ""+fy;

		String result = ""+fx+"/"+fy+"";
									
		return result;					
	}
}
