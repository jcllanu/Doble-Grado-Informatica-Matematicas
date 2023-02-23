package tp.tp1.game.gameObjects;

public interface IPlayerController {
	
	public boolean move (int numCells);
	public boolean shootLaser(boolean supermisil); 
	public boolean shockWave();

	public void receivePoints(int points);
	public void enableShockWave();
	public void enableMissile();
}
