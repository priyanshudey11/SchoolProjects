/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */


/**
 *
 * @author omviz
 */
public class StudentEntry {
    private String Firstname;
    private String Lastname;
    private String studentId;

    public String getFirstname() {
        return Firstname;
    }

    public String getLastname() {
        return Lastname;
    }

    public String getStudentId() {
        return studentId;
    }

    public StudentEntry(String Firstname, String Lastname, String studentId) {
        this.Firstname = Firstname;
        this.Lastname = Lastname;
        this.studentId = studentId;
    }

}