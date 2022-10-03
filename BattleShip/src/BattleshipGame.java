
public class BattleshipGame 
{
	Ocean ocean; 
	
	public BattleshipGame()
	{
		this(5); 
	}
	
	public BattleshipGame(int size)
	{
		ocean = new Ocean(size); 
	}
	public void runGame()
	{
		int i =11; 
		// run through will put it at infinite loop
		while(i<11)
		{
			i--; 
			if (i==5 )
				break;
			System.out.println("i="+ i);
			
		}
	}

}
