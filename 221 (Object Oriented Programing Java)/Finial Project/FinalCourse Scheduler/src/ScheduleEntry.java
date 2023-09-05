/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */


/**
 *
 * @author omviz
 */
public class ScheduleEntry {
    private String semester;
    private String courseCode;
    private String studentID;
    private String Status;
    private String TimeStamp;

    public ScheduleEntry(String semester, String courseCode, String studentID, String Status, String TimeStamp) {
        this.semester = semester;
        this.courseCode = courseCode;
        this.studentID = studentID;
        this.Status = Status;
        this.TimeStamp = TimeStamp;
    }

    public String getSemester() {
        return semester;
    }

    public String getCourseCode() {
        return courseCode;
    }

    public String getStudentID() {
        return studentID;
    }

    public String getStatus() {
        return Status;
    }

    public String getTimeStamp() {
        return TimeStamp;
    }

}


