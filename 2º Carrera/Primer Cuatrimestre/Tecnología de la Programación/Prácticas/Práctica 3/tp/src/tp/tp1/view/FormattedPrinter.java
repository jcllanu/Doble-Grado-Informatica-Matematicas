package tp.tp1.view;

import tp.tp1.game.Game;
import tp.tp1.util.MyStringUtils;

public class FormattedPrinter extends GamePrinter{
	int numRows; 
	int numCols;
	
	String[][] board;
	final String space = " ";
	
	
	public FormattedPrinter (Game game, int rows, int cols) {
		numRows=rows;
		numCols=cols;
		encodeGame(game);
	}
	
	public FormattedPrinter() {
	}

	private void encodeGame(Game game) {
		board = new String[numRows][numCols];
		for(int i = 0; i < numRows; i++) {
			for(int j = 0; j < numCols; j++) {
				board[i][j] =  game.characterAtToString(i, j);
			}
		}
	}
	public String toString() {

		int cellSize = 7;
		int marginSize = 2;
		String vDelimiter = "|";
		String hDelimiter = "-";
		
		String rowDelimiter = MyStringUtils.repeat(hDelimiter, (numCols * (cellSize + 1)) - 1);
		String margin = MyStringUtils.repeat(space, marginSize);
		String lineDelimiter = String.format("%n%s%s%n", margin + space, rowDelimiter);
		
		StringBuilder str = new StringBuilder();
		
		str.append(lineDelimiter);
		
		for(int i=0; i<numRows; i++) {
				str.append(margin).append(vDelimiter);
				for (int j=0; j<numCols; j++) {
					str.append( MyStringUtils.centre(board[i][j], cellSize)).append(vDelimiter);
				}
				str.append(lineDelimiter);
		}
		return str.toString();
	}

	@Override
	protected void prepareToString(Game g) {
		numRows=Game.NUM_FILAS;
		numCols=Game.NUM_COLUMNAS;
		this.encodeGame(g);
	}
}
