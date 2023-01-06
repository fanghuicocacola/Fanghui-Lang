import com.example.autowire.Dept;
import com.example.autowire.Emp;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class TestDemo_EMP {
    @Test
    public void Test(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring3.xml");
        Emp emp = context.getBean("emp", Emp.class);
        System.out.println(emp);
        emp.test();
    }

}
