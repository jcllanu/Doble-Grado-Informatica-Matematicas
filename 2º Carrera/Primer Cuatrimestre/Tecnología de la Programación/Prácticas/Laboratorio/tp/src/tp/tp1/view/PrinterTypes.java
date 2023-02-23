package tp.tp1.view;

import tp.tp1.game.Game;

public enum PrinterTypes {
	BOARDPRINTER("boardprinter", "prints the game formatted as a board of dimension: ", 
			new FormattedPrinter()),
	SERIALIZER("serializer", "prints the game as plain text", new Stringifier());
	
	private String printerName;
	private String helpText; 
	private GamePrinter printerObject; 
	
	private PrinterTypes(String name, String text, GamePrinter printer) { 
		printerName = name;
		helpText = text;
		setPrinterObject(printer); 
	} 
	
	public static String printerHelp(Game game) { 
		String helpString = "";
		for (PrinterTypes printer : PrinterTypes.values()) {
			helpString += String.format("%s : %s%s%n", printer.printerName, printer. helpText, (printer == BOARDPRINTER ? Game.NUM_FILAS+ " x " + Game.NUM_COLUMNAS : "" ) );
		}
		return helpString; 
	} 
	public GamePrinter getObject() { 
		return getPrinterObject(); 
	}

	public GamePrinter getPrinterObject() {
		return printerObject;
	}

	public void setPrinterObject(GamePrinter printerObject) {
		this.printerObject = printerObject;
	}
	
}
