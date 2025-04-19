import bean.Emp;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class TestEmp {
    @Test
    public void test_demo(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring4.xml");
        Emp employee = context.getBean("emp", Emp.class);
        employee.add();
    }
}
