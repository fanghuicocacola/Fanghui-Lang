package com.cy.store.mapper;

import com.cy.store.entity.Cart;
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
public class CartMapperTests {
    @Autowired
    private CartMapper cartMapper;

    @Test
    public void addCart() {
        Cart cart = new Cart();
        cart.setUid(1);
        cart.setPid(2);
        cart.setNum(3);
        cart.setPrice(4L);
        Integer rows = cartMapper.addCart(cart);
        System.out.println("rows=" + rows);
    }

    @Test
    public void UpdateCartNumByCid() {
        Integer cid = 1;
        Integer num = 10;
        String modifiedUser = "购物车管理员";
        Date modifiedTime = new Date();
        Integer rows = cartMapper.UpdateCartNumByCid(num, modifiedUser, modifiedTime,cid);
        System.out.println("rows=" + rows);
    }

    @Test
    public void queryCartByUidAndPid() {
        Integer uid = 1;
        Integer pid = 2;
        Cart result = cartMapper.queryCartByUidAndPid(uid, pid);
        System.out.println(result);
    }

    @Test
    public void queryAllCartsByUid() {
        List<CartVo> list = cartMapper.queryAllCartsByUid(31);
        System.out.println(list);
    }

    @Test
    public void queryCartByCid() {
        Integer cid = 6;
        Cart result = cartMapper.queryCartByCid(cid);
        System.out.println(result);
    }

}
