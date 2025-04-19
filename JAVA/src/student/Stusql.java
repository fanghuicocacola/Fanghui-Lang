package student;

import java.sql.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Stusql {	
	public Statement stmt;
	public ResultSet rs;
	public String sql;
	public DBConn dbc;
	
	public void insert(Student stu){		
		try {		
			dbc = new DBConn();		
			stmt = dbc.getConn().createStatement();			
			sql ="insert into user values ('"+
			      stu.getName()+"',"+stu.getPwd()+","+stu.getAge()+")";			
			stmt.executeUpdate(sql);
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}finally{
			closeRes();
		}
	}
	
	public void searchAll(){	
		ArrayList<Student> al = new ArrayList<Student>();	
		try {		
			dbc = new DBConn();			
			stmt = dbc.getConn().createStatement();			
			sql ="select * from user";		
			rs = stmt.executeQuery(sql);			
			while(rs.next()){				
				Student stu = new Student();				
				String name =rs.getString(1);
				int pwd = rs.getInt(2);
				int age = rs.getInt(3);				
				stu.setName(name);
				stu.setPwd(pwd);
				stu.setAge(age);				
				al.add(stu);
			}			
			for(Student s:al){
				System.out.println(s.toString());
			}
			
			Collections.sort(al, new Comparator<Student>() {

				@Override
				public int compare(Student o1, Student o2) {
					
					if(o1.getAge()>o2.getAge()){
						return -1;
					}else if(o1.getAge()<o2.getAge()){
						return 1;
					}else{
						return 0;
					}
					
				}
			});
			System.out.println("*************");
			for(Student s:al){
				System.out.println(s.toString());
			}
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}finally{
			closeRes();
		}
	}
	
	public void searchSin(String name){		
		try {			
			dbc = new DBConn();			
			stmt = dbc.getConn().createStatement();			
			sql ="select * from user where name = '"+name+"'";			
			rs = stmt.executeQuery(sql);			
			while(rs.next()){				
				Student stu = new Student();				
				String name1 =rs.getString(1);
				int pwd = rs.getInt(2);
				int age = rs.getInt(3);				
				stu.setName(name1);
				stu.setPwd(pwd);
				stu.setAge(age);				
				System.out.println(stu.toString());
			}	
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}finally{
			closeRes();
		}
	}
	
	public void update(Student stu){		
		try {			
			dbc = new DBConn();		
			stmt = dbc.getConn().createStatement();			
			sql ="update user set pwd = "+stu.getPwd()+",age="+
			      stu.getAge()+" where name='"+stu.getName()+"'";			
			stmt.executeUpdate(sql);		
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}finally{
			closeRes();
		}
	}
	
	public void delete(String name){	
		try {			
			dbc = new DBConn();			
			stmt = dbc.getConn().createStatement();			
			sql ="delete from user where name='"+name+"'";			
			stmt.executeUpdate(sql);			
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}finally{
			closeRes();
		}
	}

	public void closeRes() {
		try {
			
			if(rs!=null){
				rs.close();
			}
			
			if(stmt!=null){
				stmt.close();
			}
			
			if(dbc!=null){
				dbc.getConn().close();
			}
			
			
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
		
	}
	
	

}
