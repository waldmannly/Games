/*
 * University of Central Florida 
 * COP3330 Spring 2017 
 * Author: Evan Waldmann
 */

import java.awt.Point;
import blobz.BlobUtils;
import blobz.PolyBlob;

public class Asteroid extends PolyBlob {

	public Asteroid(int x, int y, double r) 
	{
		super(-100, -100, r);
		this.setDelta(x, y);
		this.setRate(r);
		
		int numSides = (int)( Math.random()* 5 + 5) ; 
		
		int[] distance = new int[numSides];
		double[] angle = new double[numSides];
		Point[] points = new Point[numSides];
		
		double region = 2* Math.PI / (double)(numSides); 
		
		for (int i=0; i<numSides; i++)
		{
			distance[i] = (int) (Math.random()*10 +5); 
			angle[i] = (i*region) + (Math.random() * region);
			points[i] = BlobUtils.rotatePoint(distance[i], angle[i]);
		}
		
		setPolygon(points); 
	}

}

/*
  1. Create an Asteroid.java class file in your project for your program. This class must satisfy the
   following requirements:
 

    (a) it must extend the PolyBlob class, so that it inherits from PolyBlob, which in turn inherits 
    from Blob. The class will will have only a constructor and no other methods.

    (b) the constructor must take these three input parameters as arguments: 
    	(i) an int that represents the x-component of the asteroid's velocity vector; 
    	(ii) an int that represents the y-component of the asteroid's velocity vector; and 
    	(iii) a double that represents the angular rotation rate.

    (c) the constructor must set the asteroid to start at the offscreen location (-100, -100), 
    since we will be using "flow" mode, as discussed in lecture.

    (d) the constructor must also initialize the asteroid's velocity vector with the velocity component 
    values that the constructor receives as input.

    (e) the constructor must create a random simple polygon (no lines crossing) shape for the asteroid 
    that has between 5 and 9 sides and is between 10 and 30 pixels in diameter, as discussed in lecture.
     When displayed, the shape must not have any lines that cross.
     
     */