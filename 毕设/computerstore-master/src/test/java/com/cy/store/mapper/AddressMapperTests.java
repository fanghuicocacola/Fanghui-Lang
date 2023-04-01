package com.cy.store.mapper;

import com.cy.store.entity.Address;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.Date;
import java.util.List;

@RunWith(SpringRunner.class)
@SpringBootTest
public class AddressMapperTests {
    @Autowired
    private AddressMapper addressMapper;

    @Test
    public void addAddress() {
        Address address = new Address();
        address.setUid(18);
        address.setName("admin");
        address.setPhone("17858802974");
        address.setAddress("雁塔区小寨赛格");
        Integer rows = addressMapper.addAddress(address);
        System.out.println("rows=" + rows);
    }

    @Test
    public void userAddressCount() {
        Integer uid = 18;
        Integer count = addressMapper.userAddressCount(uid);
        System.out.println("count=" + count);
    }

    @Test
    public void queryUserAddress() {
        Integer uid = 26;
        List<Address> list = addressMapper.queryUserAddress(uid);
        System.out.println("count=" + list.size());
        for (Address item : list) {
            System.out.println(item);
        }
    }

    @Test
    public void setAllAddressNotDefault() {
        Integer uid = 30;
        Integer rows = addressMapper.setAllAddressNotDefault(uid);
        System.out.println("rows=" + rows);
    }

    @Test
    public void setOneAddressDefault() {
        Integer aid = 19;
        String modifiedUser = "管理员";
        Date modifiedTime = new Date();
        Integer rows = addressMapper.setOneAddressDefault(aid, modifiedUser, modifiedTime);
        System.out.println("rows=" + rows);
    }

    @Test
    public void queryUserAddressByAid() {
        Integer aid = 19;
        Address result = addressMapper.queryUserAddressByAid(aid);
        System.out.println(result);
    }


}
