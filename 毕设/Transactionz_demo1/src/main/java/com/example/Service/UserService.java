package com.example.Service;

import com.example.Dao.UserDao;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
@Transactional
public class UserService {
    //注入dao
    @Autowired
    private UserDao userDao;

    public void accountMoney() {
        //try{
        //第一步：开启事务操作
        //第二步：进行业务操作
        //lucy少一百
        userDao.reduceMoney();
        //模拟异常
        int i = 10 / 0;
        //mary多一百
        userDao.addMoney();
        //}catch (Exception e){
        //第四步 出现异常，事务回滚
    }
}
