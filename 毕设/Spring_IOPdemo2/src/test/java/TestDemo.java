import com.example.Course;
import com.example.factoryBean.MyBean;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class TestDemo {
    @Test
    public void testCollection(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring2.xml");
        Course course = context.getBean("myBean", Course.class);
        System.out.println(course);
    }
}
