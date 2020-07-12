package edu.uog.course;

public class Course {
	
	private int COURSE_ID;
	private String COURSE_CODE;
    private String COURSE_TITLE;
    private String COURSE_DESC;
    private String COURSE_CEREDITHOUR;
    private Course COURSEPREREQUIST_ID;
	public int getCOURSE_ID() {
		return COURSE_ID;
	}
	public void setCOURSE_ID(int cOURSE_ID) {
		COURSE_ID = cOURSE_ID;
	}
	public String getCOURSE_CODE() {
		return COURSE_CODE;
	}
	public void setCOURSE_CODE(String cOURSE_CODE) {
		COURSE_CODE = cOURSE_CODE;
	}
	public String getCOURSE_TITLE() {
		return COURSE_TITLE;
	}
	public void setCOURSE_TITLE(String cOURSE_TITLE) {
		COURSE_TITLE = cOURSE_TITLE;
	}
	public String getCOURSE_DESC() {
		return COURSE_DESC;
	}
	public void setCOURSE_DESC(String cOURSE_DESC) {
		COURSE_DESC = cOURSE_DESC;
	}
	public String getCOURSE_CEREDITHOUR() {
		return COURSE_CEREDITHOUR;
	}
	public void setCOURSE_CEREDITHOUR(String cOURSE_CEREDITHOUR) {
		COURSE_CEREDITHOUR = cOURSE_CEREDITHOUR;
	}
	public Course getCOURSEPREREQUIST_ID() {
		return COURSEPREREQUIST_ID;
	}
	public void setCOURSEPREREQUIST_ID(Course cOURSEPREREQUIST_ID) {
		COURSEPREREQUIST_ID = cOURSEPREREQUIST_ID;
	}
	public String toString() {
		String str = null;
		
		str= this.COURSE_ID
				+","+this.COURSEPREREQUIST_ID
				+","+this.COURSE_CODE
				+","+this.COURSE_TITLE
				+","+ this.COURSE_CEREDITHOUR
	           	+","+this.COURSE_DESC;
		
		
		return str; 
	}
}
