package com.mapper;

import com.pojo.User;

import java.util.List;

public interface UserMapper {
    //添加用户信息
    int insertUser();
    //修改用户信息
    void updateUser();
    //删除用户信息
    void deleteUser();
    //根据id查询用户信息
    User selectUserById();
    List<User> selectUserAll();
}
