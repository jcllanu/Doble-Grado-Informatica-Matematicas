package tp.tp1.game.gameObjects;

import tp.tp1.exceptions.FileContentsException;
import tp.tp1.game.FileContentsVerifier;
import tp.tp1.game.Game;

public class GameObjectGenerator {
	private static GameObject[] availableGameObjects = {
			new UCMShip(),
			new Ovni(),
			new RegularAlien(),
			new DestroyerAlien(),
			new ExplosiveAlien(),
			new Shockwave(),
			new Bomb(),
			new UCMShipLaser(),
			new UCMShipSuperMisil(),
			new KamikazeAlien()
	}; 
	
	public static GameObject parse(String stringFromFile, Game game, FileContentsVerifier verifier, ListaLabels listaLabel) throws FileContentsException {
		GameObject gameObject = null;
		
		for (GameObject go: availableGameObjects) {
			try {
			gameObject = go.parse(stringFromFile, game, verifier,listaLabel);
			}catch(FileContentsException e) {
				throw new FileContentsException(e);
			}
			if (gameObject != null) {
				break; 
			}
		}
		
		return gameObject;
	}

}
