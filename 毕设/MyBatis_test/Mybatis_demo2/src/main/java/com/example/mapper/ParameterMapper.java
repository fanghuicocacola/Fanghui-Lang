package com.example.mapper;

import com.example.pojo.User;
import org.apache.ibatis.annotations.Param;

import java.util.List;
import java.util.Map;

public interface ParameterMapper {
    /*
    * 根据用户名查询用户信息
    * */
    User getUserByName(String name);
    /*
    * 查询所有的员工信息
    * */
    List<User> getAllUser();
    /*
    * 验证登录
    * */
    User checkLogin(String name,String password);
    /*
    * 验证登录(参数为map)
    * */
    User checkLoginByMap(Map<String,Object> map);
    /*
    * 添加用户信息
    * */
    int insertUser(User user);
    /*
    * 验证登录(使用@Param)
    * */
    User checkLoginByParam(@Param("name") String name,@Param("password") String password);
}
