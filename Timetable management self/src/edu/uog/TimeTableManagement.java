package edu.uog;
                                          //Roll#18321519-111
import java.util.List;

import uog.edu.campus.Room;
import uog.edu.campus.RoomsData;

//Main class

public class TimeTableManagement {

	public static void main(String[] args) {
		RoomsData roomData= new RoomsData();
	  
		System.out.println("Find One:");
	 Room room= roomData.findOne(3);
	 System.out.println(room.toString());
	 System.out.println("---------------------");
	   
	 System.out.println("Find ALL:");
       List<Room> rooms= roomData.findall();
		for(int i=0;i<rooms.size();i++)
		{
          System.out.println(rooms.get(i).toString());
		
	}
		 System.out.println("---------------------");

			System.out.println("SEARCH");
			  rooms= roomData.search("CR-");
				for(int i=0;i<rooms.size();i++)
				{
		          System.out.println(rooms.get(i).toString());
				
			}
			 System.out.println("---------------------");
			 
			 System.out.println("Save");
			 room.setROOM_NAME("LR-03");
			 room.setROOM_FLOOR(1);
			 room.setROOM_CAPACITY(50);
			 room.setROOM_TYPE("Lab Room"); 
			 room=roomData.Save(room);
			 System.out.println(room.toString());
	
	
	 System.out.println("Find ALL After Save:");
      rooms= roomData.findall();
		for(int i=0;i<rooms.size();i++)
		{
        System.out.println(rooms.get(i).toString());
		
	}
		 System.out.println("---------------------");

}
}
  