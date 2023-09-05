/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

/**
 *
 * @author acv
 */
public class Queries {
    private static Connection connection;
    //private static ArrayList<String> faculty = new ArrayList<String>();
    //Semester
    private static PreparedStatement addSemester;
    private static PreparedStatement getSemesterList;
    //Course
    private static PreparedStatement addCourse;
    private static PreparedStatement getCourse;
    private static PreparedStatement updateSeats;

    
    //Student
    private static PreparedStatement addStudent;
    private static PreparedStatement getallStudents;
    //classes
    private static PreparedStatement addclass;
    private static PreparedStatement getclass;
    
    



    private static ResultSet resultSet;
    //Semester
        //add
        public static void addSemester(String name)
        {
            connection = DBConnection.getConnection();
            try
            {
                addSemester = connection.prepareStatement("insert into app.semester (name) values (?)");
                addSemester.setString(1, name);
                addSemester.executeUpdate();
            }
            catch(SQLException sqlException)
            {
                sqlException.printStackTrace();
            }

        }
        //get
        public static ArrayList<String> getSemesterList()
        {
            connection = DBConnection.getConnection();
            ArrayList<String> semester = new ArrayList<String>();
            try
            {
                getSemesterList = connection.prepareStatement("select name from app.semester order by name");
                resultSet = getSemesterList.executeQuery();

                while(resultSet.next())
                {
                    semester.add(resultSet.getString(1));
                }
            }
            catch(SQLException sqlException)
            {
                sqlException.printStackTrace();
            }
            return semester;

        }
     //Course
        //add
        public static void addCourse(CourseEntry course)
        {
            connection = DBConnection.getConnection();
            try
            {
                addCourse = connection.prepareStatement("insert into app.course (semester,coursecode,description,seats) values (?,?,?,?)");
                addCourse.setString(1, course.getSemester());
                addCourse.setString(2, course.getCourseCode());
                addCourse.setString(3, course.getCourseDescruption());
                addCourse.setInt(4,course.getSeats());
                addCourse.executeUpdate();
            }
            catch(SQLException sqlException)
            {
                sqlException.printStackTrace();
            }

        }
        
     
        //get       
        public static ArrayList<CourseEntry> getcourse(String Semester)
        {
            connection = DBConnection.getConnection();
            ArrayList<CourseEntry> courses = new ArrayList<CourseEntry>();
            try
            {
                
                getCourse = connection.prepareStatement("select * from app.course where Semester=?");
                getCourse.setString(1, Semester);
                resultSet = getCourse.executeQuery();

                while(resultSet.next())
                {
                        CourseEntry course= new CourseEntry(resultSet.getString(1),resultSet.getString(2),resultSet.getString(3),resultSet.getInt(4));
                        courses.add(course);                
                }
            }
            catch(SQLException sqlException)
            {
                sqlException.printStackTrace();
            }
            return courses;
                    
        }
        //update Seats    
            public static void updateSeats(String courseCode, int newSeats) {
                connection = DBConnection.getConnection();
                try {
                    updateSeats = connection.prepareStatement("UPDATE app.course SET seats = ? WHERE coursecode = ?");
                    updateSeats.setInt(1, newSeats);
                    updateSeats.setString(2, courseCode);
                    updateSeats.executeUpdate();
                } catch(SQLException sqlException) {
                    sqlException.printStackTrace();
                }
            }
    //Student
        //add
        public static void addStudent(StudentEntry student) {
            connection = DBConnection.getConnection();
            try {
                addStudent = connection.prepareStatement("insert into app.student (studentid,firstname,lastname) values (?,?,?)");
                addStudent.setString(1, student.getStudentId());
                addStudent.setString(2, student.getFirstname());
                addStudent.setString(3, student.getLastname());

                addStudent.executeUpdate();
            } catch (SQLException sqlException) {
                sqlException.printStackTrace();
            }
        }
        //get
        public static ArrayList<StudentEntry> getallStudents()
            {
                connection = DBConnection.getConnection();
                ArrayList<StudentEntry> students = new ArrayList<StudentEntry>();
                try
                {
                    getallStudents = connection.prepareStatement("select studentid, firstname, lastname from app.student order by studentid");
                    resultSet = getallStudents.executeQuery();

                    while(resultSet.next())
                    {
                        StudentEntry student = new StudentEntry(resultSet.getString("firstname"), resultSet.getString("lastname"), resultSet.getString("studentid"));
                        students.add(student);

                    }
                }
                catch(SQLException sqlException)
                {
                    sqlException.printStackTrace();
                }
                return students;

                }
    //Schedule
   public static void addSchedule(ScheduleEntry classes) {
            connection = DBConnection.getConnection();
            try {
                addclass = connection.prepareStatement("insert into app.schedule (semester,studentid,coursecode,timestamp,status) values (?,?,?,?,?)");
                addclass.setString(1, classes.getSemester());
                addclass.setString(2, classes.getCourseCode());
                addclass.setString(3, classes.getStudentID());
                addclass.setString(4, classes.getTimeStamp());
                addclass.setString(5, classes.getStatus());
                addclass.executeUpdate();
            } catch (SQLException sqlException) {
                sqlException.printStackTrace();
            }
        }
        //get
        public static ArrayList<ScheduleEntry> getclass()
            {
                connection = DBConnection.getConnection();
                ArrayList<ScheduleEntry> classes = new ArrayList<ScheduleEntry>();
                try
                {
                    getclass = connection.prepareStatement("select * from app.schedule order by semester,studentid,coursecode,timestamp,status ");
                    resultSet = getclass.executeQuery();

                    while(resultSet.next())
                    {
                        ScheduleEntry course= new ScheduleEntry(resultSet.getString(1),resultSet.getString(2),resultSet.getString(3),resultSet.getString(4),resultSet.getString(5));
                        classes.add(course);

                    }
                }
                catch(SQLException sqlException)
                {
                    sqlException.printStackTrace();
                }
                return classes;

                }
}



