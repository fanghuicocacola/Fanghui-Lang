package com.cy.store.service;

import com.cy.store.entity.Address;
import com.cy.store.service.exception.ServiceException;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.Date;
import java.util.List;

@RunWith(SpringRunner.class)
@SpringBootTest
public class AddressServiceTests {
    @Autowired
    private IAddressService addressService;

    @Test
    public void addAddress() {
        try {
            Integer uid = 1;
            String username = "管理员";
            Address address = new Address();
            address.setName("张三");
            address.setPhone("17858805555");
            address.setAddress("雁塔区小寨华旗");
            addressService.addAddress(address, username, uid);
            System.out.println("OK.");
        } catch (ServiceException e) {
            System.out.println(e.getClass().getSimpleName());
            System.out.println(e.getMessage());
        }
    }

    @Test
    public void queryUserAddress() {
        //用户信息不存在时，对照数据表修改uid
        Integer uid = 1;
        List<Address> list = addressService.queryUserAddress(uid);
        System.out.println("count=" + list.size());
        for (Address item : list) {
            System.out.println(item);
        }
    }

    @Test
    public void setOneAddressDefault() {
        try {
            Integer aid = 18;
            String modifiedUser = "系统管理员";
            Date modifiedTime = new Date();
            addressService.setOneAddressDefault(aid,modifiedUser,modifiedTime);
            System.out.println("OK.");
        } catch (ServiceException e) {
            System.out.println(e.getClass().getSimpleName());
            System.out.println(e.getMessage());
        }
    }

    @Test
    public void deleteOneAddress() {
        try {
            Integer aid = 18;
            String modifiedUser = "明明";
            Date modifiedTime = new Date();
            addressService.deleteOneAddress(aid,modifiedUser,modifiedTime);
            System.out.println("OK.");
        } catch (ServiceException e) {
            System.out.println(e.getClass().getSimpleName());
            System.out.println(e.getMessage());
        }
    }
    @Test
    public void queryAddressByAid() {
        try {
            Integer aid = 6;
            Address address = addressService.queryAddressByAid(aid);
            System.out.println(address);
        } catch (ServiceException e) {
            System.out.println(e.getClass().getSimpleName());
            System.out.println(e.getMessage());
        }
    }
}
