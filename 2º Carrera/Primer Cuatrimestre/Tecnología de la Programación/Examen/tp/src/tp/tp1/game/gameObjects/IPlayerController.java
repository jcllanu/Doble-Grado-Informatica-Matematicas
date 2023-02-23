package tp.tp1.game.gameObjects;

import tp.tp1.exceptions.HyperspaceException;
import tp.tp1.exceptions.MissileInFlightException;
import tp.tp1.exceptions.NoAvailableSupermissileException;
import tp.tp1.exceptions.NoShockwaveException;
import tp.tp1.exceptions.OffWorldException;
import tp.tp1.exceptions.WarmUpEngineException;

public interface IPlayerController {
	
	public void move (int numCells) throws OffWorldException, HyperspaceException, WarmUpEngineException;
	public void shootLaser(boolean supermisil) throws MissileInFlightException, NoAvailableSupermissileException; 
	public void shockWave() throws NoShockwaveException;

	public void receivePoints(int points);
	public void enableShockWave();
	public void enableMissile();
}
