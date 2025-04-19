package com.cy.store.service;

import com.cy.store.entity.User;
import com.cy.store.service.exception.ServiceException;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

@RunWith(SpringRunner.class)
@SpringBootTest
public class UserServiceTests {
    @Autowired
    private IUserService iUserService;

    @Test
    public void userRegister() {
        try {
            User user = new User();
            user.setUsername("lower");
            user.setPassword("123456");
            user.setGender(1);
            user.setPhone("17858802974");
            user.setEmail("lower@cy.cn");
            user.setAvatar("avatar.png");
            iUserService.userRegister(user);
            System.out.println("注册成功！");
        } catch (ServiceException e) {
            System.out.println("注册失败！" + e.getClass().getSimpleName());
            System.out.println(e.getMessage());
        }
    }

    @Test
    public void userLogin() {
        try {
            User user = new User();
            String username = "lower";
            user.setUsername(username);
            String password = "123456";
            user.setPassword(password);
            User user1 = iUserService.userLogin(user);
            System.out.println("登录成功！" + user1);
        } catch (ServiceException e) {
            System.out.println("登录失败！" + e.getClass().getSimpleName());
            System.out.println(e.getMessage());
        }
    }

    @Test
    public void queryUserByUid() {
        try {
            Integer uid = 20;
            User user = iUserService.queryUserByUid(uid);
            System.out.println(user);
        } catch (ServiceException e) {
            System.out.println(e.getClass().getSimpleName());
            System.out.println(e.getMessage());
        }
    }

    @Test
    public void changeInfo() {
        try {
            Integer uid = 1;
            String username = "数据管理员";
            String phone = "15512328888";
            String email = "admin03@cy.cn";
            Integer gender = 2;
            iUserService.userUpdateInfo(phone,email, gender, username,uid);
            System.out.println("OK.");
        } catch (ServiceException e) {
            System.out.println(e.getClass().getSimpleName());
            System.out.println(e.getMessage());
        }
    }

    @Test
    public void changeAvatar() {
        try {
            Integer uid = 20;
            String avatar = "/upload/avatar.png";
            iUserService.userUploadImg(avatar,uid);
            System.out.println("OK.");
        } catch (ServiceException e) {
            System.out.println(e.getClass().getSimpleName());
            System.out.println(e.getMessage());
        }
    }
}
