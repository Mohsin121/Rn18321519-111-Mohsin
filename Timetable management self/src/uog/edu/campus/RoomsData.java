package uog.edu.campus;

import java.io.BufferedReader;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;



public class RoomsData {



 @SuppressWarnings("resource")
public  List<Room> findall() {
	 List<Room> rooms=new ArrayList<Room>();
	 String line;
	 try {
		BufferedReader bufferreader= new BufferedReader(new FileReader(Room.csvcsvFile));
	   while((line=bufferreader.readLine()) !=null) {
		   Room room= new Room();
		   String[] roomRow= line.split(",");
		   room.setROOM_ID(Integer.parseInt(roomRow[0]));
		   room.setROOM_NAME(roomRow[1]);
		   room.setROOM_FLOOR(Integer.parseInt(roomRow[2]));
		   room.setROOM_CAPACITY(Integer.parseInt(roomRow[3]));
		   room.setROOM_TYPE(roomRow[4]);
		   
		   rooms.add(room);
		   }
	 } catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	return rooms;
 }

@SuppressWarnings("resource")
public Room findOne(int room_ID) {
	 //List<Room> rooms=new ArrayList<Room>();
	 String line;
	 try {
		BufferedReader bufferreader= new BufferedReader(new FileReader(Room.csvcsvFile));
	   while((line=bufferreader.readLine()) !=null) {
		   Room room= new Room();
		   String[] roomRow= line.split(",");
		   if((Integer.parseInt(roomRow[0])==room_ID))
		   {
		   room.setROOM_ID(Integer.parseInt(roomRow[0]));
		   room.setROOM_NAME(roomRow[1]);
		   room.setROOM_FLOOR(Integer.parseInt(roomRow[2]));
		   room.setROOM_CAPACITY(Integer.parseInt(roomRow[3]));
		   room.setROOM_TYPE(roomRow[4]);
	       return room;
		   }   
		   }
	 } catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	return null;
 }
 @SuppressWarnings("resource")
 public List<Room> search(String search) {
	 List<Room> rooms=new ArrayList<Room>();
 	 String line;
 	 try {
 		BufferedReader bufferreader= new BufferedReader(new FileReader(Room.csvcsvFile));
 	   while((line=bufferreader.readLine()) !=null) {
 		   Room room= new Room();
 		   String[] roomRow= line.split(",");
 		   if(roomRow[1].contains(search)==true)
 		   {
 		   room.setROOM_ID(Integer.parseInt(roomRow[0]));
 		   room.setROOM_NAME(roomRow[1]);
 		   room.setROOM_FLOOR(Integer.parseInt(roomRow[2]));
 		   room.setROOM_CAPACITY(Integer.parseInt(roomRow[3]));
 		   room.setROOM_TYPE(roomRow[4]);
 	       rooms.add(room);
 		   }   
 		   }
 	 } catch (IOException e) {
 		// TODO Auto-generated catch block
 		e.printStackTrace();
 	}
 	return rooms;
  }
 @SuppressWarnings("resource")
public Room Save(Room room) {
	 int room_id=0;
	 FileWriter fileWriter;
	 List<Room> rooms= this.findall();
		for(int i=0;i<rooms.size();i++)
		{
       System.out.println(rooms.get(i).toString());
		
	}
	 try {
		fileWriter= new FileWriter(Room.csvcsvFile);
		
		for(int i=0;i<rooms.size();i++)
		{
			fileWriter.append(rooms.get(i).toString());
			fileWriter.append("\n");
	}
		if(rooms.size()>0)
			room.setROOM_ID(rooms.get(rooms.size()-1).getROOM_ID()+1);
	 room.setROOM_ID(room_id+1);
	 fileWriter.append(room.toString()+"\n");
	 fileWriter.flush();
	 fileWriter.close();
	 } catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	return room;
	 
 }
}
 
