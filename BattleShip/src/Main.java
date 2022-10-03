import javax.swing.JOptionPane;


public class Main 
{
	public static void testOcean(Ocean ocean)
	{
		ocean.placeShip(3, 4);
		ocean.placeShip(1, 1); 
		ocean.placeShip(4, 4);
		ocean.explodeShell(3, 4); 
		ocean.explodeShell(2, 2); 
		
	}
	
	public static void main(String[] args)
	{
		BattleshipGame game = new BattleshipGame();
		/*
		//construct oceans
		Ocean enemy = new Ocean(5);
		
		//add ships and shoots 
		testOcean(enemy); 
		
		System.out.println(enemy); 
		 */
	}
	
	

}
