/*
 * University of Central Florida 
 * COP3330 Spring 2017 
 * Author: Evan Waldmann
 */

import blobz.BlobGUI;
import blobz.SandBox;
import blobz.SandBoxMode;

public class AsteroidField implements BlobGUI{

	public SandBox sandbox; 
	
	public static void main(String[] args) {
		new AsteroidField(); 
	}
	
	public AsteroidField()
	{
		SandBox sandbox1 = new SandBox();
		sandbox1.setSandBoxMode(SandBoxMode.FLOW);
		sandbox1.setFrameRate(15);
		sandbox1.init(this);
		sandbox = sandbox1; 
	}
	
	@Override
	public void generate() 
	{
		int x;
		int y; 
		double r; 
		for (int i=0; i<10; i++)
		{
			x = (int) ((Math.random()*6) -3); 
			if (x==0)
				x=-3; 
			y = (int) ((Math.random()*6) -3); 
			if (y==0)
				y=-3; 
			r = (int)((Math.random()*2));
			if (r ==0)
				r=-.1;
			else 
				r=.1;
			
			Asteroid asteroid = new Asteroid(x,y,r);
			sandbox.addBlob(asteroid);
		}
	}
}

/*

2. Create a separate AsteroidField.java test driver class to create a field of asteroids.
 This class must satisfy the following requirements:

(a) it must implement the BlobGUI interface, as explained in lecture.

(b) it must have a one-line main() method that instantiates the class, as follows:



(c) the constructor for the class must perform the following actions:  

     (i) create a sandbox object;

     (ii) set the sandbox to "flow" mode;

     (iii) set the sandbox to run at 15 frames per second; and

     (iv) initialize the sandbox by passing "this" (the AsteroidField object) to the sandbox's init() 
     method.

(d) the class must contain a generate() method, which is required by the BlobGUI interface. 
The generate() method must perform the following actions:

     (i) it must create 10 asteroids using the velocity components and rotational values described 
     here;

     (ii) it must randomly choose x and y velocity components for each asteroid, where the x and y 
     components are chosen independently of each other and where each of these values is an integer 
     that may range from -3 to +3, but where zero values are disallowed, all as discussed in lecture;

     (iii) it must randomly choose a rotation value of either -.1 or +.1 for each asteroid, with equal
      probability. Values in between -.1 and +.1 are not permitted; and

     (iv) it must add each asteroid to the sandbox.


*/