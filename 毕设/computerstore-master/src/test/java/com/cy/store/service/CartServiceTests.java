package com.cy.store.service;

import com.cy.store.service.exception.ServiceException;
import com.cy.store.vo.CartVo;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.Date;
import java.util.List;

@RunWith(SpringRunner.class)
@SpringBootTest
public class CartServiceTests {
    @Autowired
    private ICartService cartService;

    @Test
    public void queryCartByUid() {
        List<CartVo> list = cartService.queryCartByUid(31);
        System.out.println("count=" + list.size());
        for (CartVo item : list) {
            System.out.println(item);
        }
    }

    @Test
    public void addNum() {
        try {
            Integer num1 = 31;
            Integer cid = 6;
            String modifiedUser = "管理员";
            Date modifiedTime = new Date();
            Integer num = cartService.updateCartNumByCid(num1,modifiedUser,modifiedTime,cid);
            System.out.println("OK. New num=" + num);
        } catch (ServiceException e) {
            System.out.println(e.getClass().getSimpleName());
            System.out.println(e.getMessage());
        }
    }

    @Test
    public void getVOByCids() {
        Integer[] cids = {1, 2, 6, 7, 8, 9, 10};
        List<CartVo> list = cartService.queryCartByCids(cids);
        System.out.println("count=" + list.size());
        for (CartVo item : list) {
            System.out.println(item);
        }
    }

}
