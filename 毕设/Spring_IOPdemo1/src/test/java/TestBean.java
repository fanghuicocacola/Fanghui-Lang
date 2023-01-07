import dao.UserDao;
import  dao.UserDaoImpl;
import org.junit.Test;
import service.UserService;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class TestBean {
    @Test
    public void testAdd(){
        //1.加载spring配置文件
        ApplicationContext context = new ClassPathXmlApplicationContext("spring2.xml");
        //2.获取配置创建的对象
        UserService userService = context.getBean("userService", UserService.class);
        userService.add();
    }
}
