package service;

import dao.UserDao;
import dao.UserDaoImpl;

public class UserService {

    //创建UserDao类型属性，生成set方法
    private UserDao userDao;

    public void setUserDao(UserDao userDao) {
        this.userDao = userDao;
    }

    public void add() {
        System.out.println("service add......");
        /*
        创建UserDao对象
        UserDao m = new UserDaoImpl();
        m.update();
        */
        userDao.update();
    }

}
