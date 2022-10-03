
public class Ocean 
{
	private char[][] grid; 
	private char HIT='X';
	private char MISS='O';
	private char EMPTY='-';
	private char SHIP= 'S'; 
	
	
	public Ocean(int size)
	{
		 initializeEmptyOcean(size, EMPTY);
	}
	
	
	private void initializeEmptyOcean(int size, char empty)
	{
		grid = new char[size][size];
		for (int r = 0; r < size; r++) 
		{
			for (int c = 0; c < size; c++) 
			{
					grid[r][c]= empty;
			}
		}
	}
	public void placeShip(int row , int col)
	{
		grid[row][col] = SHIP; 
	} 
	
	public boolean explodeShell(int row, int col)
	{
		if(grid[row][col]== SHIP)
		{
			grid[row][col]= HIT; 
			return true;
		}
		else	
		{
			grid[row][col] = MISS; 
			return false; 
		}
	}
	
	public String toString()
	{
		String s = ""; 
		for (int i =0; i< grid.length; i++)
		{
			String row = new String (grid[i]);
			s = s + row + "\n"; 
		}
		return s; 
	}
	/*
	//ADDS SHIP LOCATIONS 
	//FIRGURE OUT HOW MANY AND HOW LARGE THEY ARE
	public void intializeShipLocations(int[][] coodinates)
	{
		
	}
	
	public void initializeRandomShipLocations(int numShips)
	{
		for (int i =0; i<numShips; i++)
		{
			int r= (int)(Math.random()* grid.length) ;
			int c= (int)(Math.random()*grid.length) ; 
			if (grid[r][c] == EMPTY)
				grid[r][c] = SHIP; 
			else 
				;//find a way to get an empty slot
		}
		
	}
	//FIGURE OUT MULTIPLE SHOT PROBLEM
	public void shoot(int r, int c)
	{
		for(r=0; r<grid.length; r++)
		{
			for (c=0; c<grid.length; r++)
			{
				if (grid[r][c]== SHIP)
					grid[r][c]= HIT;
				//PROMPT USER TO FIRE AGAIN 
				// ADD COUNTER IN CASE OF MULTIPLE SHOTS
				else if (grid[r][c] == HIT || grid[r][c] == MISS)
					System.out.println("You have already fired at that location.");
				else if (grid[r][c] == EMPTY)
					grid[r][c]= MISS;
				//ERROR WOULD MOST LIKELY BE OUT OF BOUNDS
				else
					System.out.println("ERROR");
			}
		}
	}
	*/
}
