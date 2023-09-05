/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */


/**
 *
 * @author omviz
 */
public class CourseEntry {
    private String semester;
    private String courseCode;
    private String courseDescruption;
    private int seats;
    private int status;

    public CourseEntry(String semester, String courseCode, String courseDescruption, int seats, int status) {
        this.semester = semester;
        this.courseCode = courseCode;
        this.courseDescruption = courseDescruption;
        this.seats = seats;
        this.status = status;
    }

    public CourseEntry(String semester, String courseCode, String courseDescruption, int seats) {
        this.semester = semester;
        this.courseCode = courseCode;
        this.courseDescruption = courseDescruption;
        this.seats = seats;
    }

    public String getSemester() {
        return semester;
    }

    public String getCourseCode() {
        return courseCode;
    }

    public String getCourseDescruption() {
        return courseDescruption;
    }

    public int getSeats() {
        return seats;
    }

    public int getStatus() {
        return status;
    }
}