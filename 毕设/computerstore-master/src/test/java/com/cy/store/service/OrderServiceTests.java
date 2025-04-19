package com.cy.store.service;

import com.cy.store.entity.Order;
import com.cy.store.service.exception.ServiceException;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

@RunWith(SpringRunner.class)
@SpringBootTest
public class OrderServiceTests {
    @Autowired
    private IOrderService orderService;

    @Test
    public void insertOrder() {
        try {
            Integer aid = 21;
            Integer[] cids = {4, 5, 6,7};
            Long totalPrice = 59999L;
            Integer uid = 31;
            String username = "订单管理员";
            Order order = orderService.insertOrder(aid,totalPrice, uid, username);
            System.out.println(order);
        } catch (ServiceException e) {
            System.out.println(e.getClass().getSimpleName());
            System.out.println(e.getMessage());
        }
    }
}
