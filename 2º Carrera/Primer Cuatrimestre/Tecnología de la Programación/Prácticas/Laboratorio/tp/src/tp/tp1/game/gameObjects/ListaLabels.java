package tp.tp1.game.gameObjects;

public class ListaLabels {
	private Label[] etiquetas;
	private int contador;
	
	public ListaLabels() {
		contador=0;
		etiquetas= new  Label[0];
	}
	
	public void add (Label object) {
		 Label[] nuevaLista = new  Label[contador+1];
		 for(int i=0; i<contador; i++) {
			 nuevaLista[i]=etiquetas[i];
		 }
		 nuevaLista[contador]=object;
		 contador++;
		 etiquetas = nuevaLista;
		}
	
	public boolean meter (Label label) {
		 for(int i=0; i<contador; i++) {
			if(etiquetas[i].getLabel()==label.getLabel()) {
				if((etiquetas[i].getDestroyer()!=null && label.getDestroyer()!=null)||(etiquetas[i].getBomba()!=null && label.getBomba()!=null)) {
					return false;
				}else if(etiquetas[i].getDestroyer()!=null && etiquetas[i].getBomba()!=null) {
					return false;
				}else {
					if(etiquetas[i].getDestroyer()==null) {
						if(label.getDestroyer()==null) {
							return false;
						}else {
							etiquetas[i].setDestroyer(label.getDestroyer());
							etiquetas[i].getBomba().setPadre(label.getDestroyer());
							return true;
						}
					}else {
						if(label.getBomba()==null) {
							return false;
						}else {
							etiquetas[i].setBomba(label.getBomba());
							etiquetas[i].getBomba().setPadre(etiquetas[i].getDestroyer());
							return true;
						}
					}
				}
			}
		 }
		 this.add(label);
		 return true;
	}

	public boolean casan() {
		for(int i=0; i<contador; i++) {
			if(etiquetas[i].getDestroyer()==null || (etiquetas[i].getDestroyer().getDisparo()&&etiquetas[i].getBomba()==null)) {
				return false;
			}
		}
		return true;
	}
}
