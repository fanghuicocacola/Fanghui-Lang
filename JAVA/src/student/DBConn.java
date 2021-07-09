package student;

import java.sql.Connection;
import java.sql.DriverManager;

public class DBConn {
	public Connection conn;
	public Connection getConn(){		
		try {			
			Class.forName("com.mysql.jdbc.Driver");			
			String url = "jdbc:mysql://localhost:3306/aaa";
			//String url = "jdbc:mysql://localhost:3306/aaa?useUnicode=true&characterEncoding=UTF-8";
			String user="root";
			String pwd="";
			conn = DriverManager.getConnection(url, user, pwd);			
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}	
		return conn;
	}
}
