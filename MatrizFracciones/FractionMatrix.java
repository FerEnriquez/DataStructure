import java.util.Formatter;
/**
*	Esta clase representa una matriz de fracciones
*	@author María Fernanda Hernández Enriquez A01329383 
*	@author Manuel Alejandro Neri Reyes A01329872
*	@version	1.0
*/
public class FractionMatrix{

	public Fraction [][] matrix;
	//Ancho de la matriz
	public int row; //Número de Renglones en posicion ya llenas
	public int rowLim;
	//Largo de la matriz
	public int col; //Número de Columnas ""
	public int colLim;

	public FractionMatrix(){
		this.matrix = new Fraction[1][1];
		this.row = 1;
		this.rowLim = 1;
		this.col = 1;
		this.colLim = 1;
	}
	public FractionMatrix(int ancho, int largo){
		this.matrix = new Fraction [ancho][largo];
		this.row = 0;
		this.rowLim = ancho;
		this.col = 0;
		this.colLim = largo;
	}
	public int getRow(){
		return this.row;
	}
	public void setRow(int row){
		this.row = row;
	}
	public int getRowLim(){
		return this.rowLim;
	}
	public int getCol(){
		return this.col;
	}
	public void setCol(int col){
		this.col = col;
	}
	public int getColLim(){
		return this.colLim;
	}
	public Fraction getFraction(int x, int y){
		return this.matrix[x][y];
	}
	
	public boolean condition(FractionMatrix otherMatrix){
		int x = this.colLim;
		int y = otherMatrix.getRowLim();
		if(x==y){
			return true;
		}
		else
			return false;
	}

	public void addFractions(Fraction[] fraction){
		if (this.row == this.rowLim && this.col == this.colLim){
		}
		else{
			int z = 0;
			for (int i=0; i<this.rowLim;i++){
				for(int j = 0; j<this.colLim;j++){
					this.matrix[i][j] = fraction[z];
					z++;
				}
			}
		}
	}

	public Fraction[][] multiplicar(FractionMatrix otherMatrix){
		String res = "";
		Fraction[] aux = new Fraction[this.rowLim*otherMatrix.getColLim()];
		Fraction[][] result = new Fraction[this.rowLim][otherMatrix.getColLim()];
		//result[0][0] = new Fraction(0,0);
			for(int i = 0; i < result.length; i++){ 
	        	for(int j = 0; j < result[i].length; j++){
	                for(int k = 0; k < this.colLim; k++ ){
	                    aux[k] = (this.matrix[i][k].multi(otherMatrix.getFraction(k,j)));
	                    if(result[i][j]==null){
	                    	result[i][j] = aux[k];
	                    }
	                    else{
	                   		result[i][j] = result[i][j].sumar(aux[k]); 	
	                    }
	                }
	                res += " "+result[i][j].toString();
	        	}
	        	res += "\n";
			}
		return result;
	}

	public int maxLength(){
		int[] aux = new int[(this.rowLim*this.colLim)];
		int cont = 0;
		for(int largo = 0; largo < this.rowLim; largo++){
			for(int ancho = 0; ancho < this.colLim; ancho++){	
				int x = this.matrix[largo][ancho].getNum();
				int y = this.matrix[largo][ancho].getDem();
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
					cont++;
				}
				else if(j>i){
					aux[cont] = j;
					cont++;
				}
				else{
					aux[cont] = i;
					cont++;
				}
			}
		}
		int nMax = aux[0];
		for(int z = 0; z < aux.length; z++){
			if(aux[z]>nMax){
				nMax = aux[z];
			}
		}
		return nMax;
	}

	public String toString(int n){
		String[] aux = new String[this.rowLim*this.colLim];
		int cont = 0;
		
		for(int x = 0; x <= this.matrix.length-1; x++){
			for(int y = 0; y <= this.matrix[x].length-1; y++){
				Formatter fx = new Formatter();
				fx.format("%0"+n+"d",this.matrix[x][y].getNum());
				String xx = ""+fx;	   			 	
				Formatter fy = new Formatter();
				fy.format("%0"+n+"d",this.matrix[x][y].getDem());
				String yy = ""+fy;
				String result = ""+fx+"/"+fy+"";					
				aux[cont] = result;
				cont++;
			}
		}
	
		String result = "";
		int contador = 0;
		for (int x=0; x <= this.matrix.length-1; x++) {
		  for (int y=0; y <= this.matrix[x].length-1; y++) {
		    result += aux[contador] + " ";
		    contador++;
		  }
		  result += "\n";
		}
		/*String result = "";
		for (int x=0; x <= this.matrix.length-1; x++) {
		  for (int y=0; y <= this.matrix[x].length-1; y++) {
		    result += this.matrix[x][y] + " ";
		  }
		  result += "\n";
		}*/
		return result;
	}
}

	
