package edu.uog.student;

import edu.uog.person.Person;

public class Student extends Person {
	public static String csvFile="";
 private int STUDENT_ID;
 
 private String STUDENT_ROLLNO;
 private String STUDENT_PROGRAM;
 private String STUDY_YEAR;
public int getSTUDENT_ID() {
	return STUDENT_ID;
}
public void setSTUDENT_ID(int sTUDENT_ID) {
	STUDENT_ID = sTUDENT_ID;
}
public String getSTUDENT_ROLLNO() {
	return STUDENT_ROLLNO;
}
public void setSTUDENT_ROLLNO(String sTUDENT_ROLLNO) {
	STUDENT_ROLLNO = sTUDENT_ROLLNO;
}
public String getSTUDENT_PROGRAM() {
	return STUDENT_PROGRAM;
}
public void setSTUDENT_PROGRAM(String sTUDENT_PROGRAM) {
	STUDENT_PROGRAM = sTUDENT_PROGRAM;
}
public String getSTUDY_YEAR() {
	return STUDY_YEAR;
}
public void setSTUDY_YEAR(String sTUDY_YEAR) {
	STUDY_YEAR = sTUDY_YEAR;
}
 
public String toString() {
	String str = null;
	
	str= this.STUDENT_ID
     +","+ this.STUDENT_ROLLNO
	+","+this.STUDENT_PROGRAM
	+","+this.STUDY_YEAR;
	return str; 
}
 
}
