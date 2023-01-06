package com.example.service;

import com.example.config.SpringConfig;
import com.example.dao.UserDao;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.stereotype.Service;

//在注解里面value属性值可以省略不写，默认值是类名称首字母小写
//@Component// <bean id="userService" class="UserService"></bean>
@Service
public class UserService {
    //定义dao类型属性
    //添加注入属性注解
    //@Value(value="Hello World")
    //String string;
    @Autowired  //根据类型进行注入
    @Qualifier(value = "userDaolmpl")
    private UserDao userDao;
    //不需要添加set方法
    public void test(){
        System.out.println("Service add...");
        userDao.add();
        //System.out.println(string);
    }
}
