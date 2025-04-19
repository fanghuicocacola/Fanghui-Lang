package com.cy.store.mapper;

import com.cy.store.entity.Product;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.List;

@RunWith(SpringRunner.class)
@SpringBootTest
public class ProductMapperTests {
    @Autowired
    private ProductMapper productMapper;

    @Test
    public void queryPriorityProduct() {
        List<Product> list = productMapper.queryPriorityProduct();
        System.out.println("count=" + list.size());
        for (Product item : list) {
            System.out.println(item);
        }
    }

    @Test
    public void queryProductById() {
        Integer id = 10000017;
        Product result = productMapper.queryProductById(id);
        System.out.println(result);
    }
}
