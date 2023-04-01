package com.cy.store.mapper;

import com.cy.store.entity.User;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.Date;

// @RunWith(SpringRunner.class)注解是一个测试启动器，可以加载Springboot测试注解
@RunWith(SpringRunner.class)
@SpringBootTest
public class UserMapperTests {
    @Autowired
    private UserMapper userMapper;

    @Test
    public void addUser() {
        User user = new User();
        user.setUsername("user08");
        user.setPassword("123456");
        user.setIsDelete(0);
        Integer rows = userMapper.addUser(user);
        System.out.println("rows=" + rows);
    }

    @Test
    public void queryUserByUsername() {
        String username = "user02";
        User result = userMapper.queryUserByUsername(username);
        System.out.println(result);
    }

    @Test
    public void updatePassword() {
        String password = "654321";
        String modifiedUser = "普通管理员";
        Date modifiedTime = new Date();
        String username = "user02";
        Integer rows = userMapper.updatePassword(password, modifiedUser, modifiedTime,username);
        System.out.println("rows=" + rows);
    }

    @Test
    public void queryUserByUid() {
        Integer uid = 7;
        User result = userMapper.queryUserByUid(uid);
        System.out.println(result);
    }

    @Test
    public void UpdateUserInfo() {
        Integer uid = 30;
        String phone = "17858802222";
        String email = "admin@cy.com";
        Integer gender = 1;
        String modifiedUser = "系统管理员";
        Date modifiedTime = new Date();
        Integer rows = userMapper.UpdateUserInfo(phone,email,gender,modifiedUser,modifiedTime,uid);
        System.out.println("rows=" + rows);
    }

    @Test
    public void updateUserAvatar() {
        Integer uid = 20;
        String avatar = "/upload/avatar.png";
        String modifiedUser = "超级管理员";
        Date modifiedTime = new Date();
        Integer rows = userMapper.updateUserAvatar(avatar, modifiedUser, modifiedTime,uid);
        System.err.println("rows=" + rows);
    }
}

