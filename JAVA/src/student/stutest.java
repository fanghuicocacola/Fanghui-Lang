package student;

public class stutest {
	public static void main(String[] args) {
		Student stu = new Student();
		Stusql sql = new Stusql();
		
		stu.setName("aaa");
		stu.setPwd(12);
		stu.setAge(22);
		
		sql.insert(stu);
		
		sql.searchAll();
		
		System.out.println("*******");
		sql.searchSin("aaaa");
		
		//sql.delete("aaaaa");
		
		stu.setAge(33);
		stu.setPwd(123);
		
		sql.update(stu);
		
		sql.searchSin("aaaaaa");
		
		sql.searchAll();
	}

}
