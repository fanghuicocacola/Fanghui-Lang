<?php
    header ( "Content-type:text/html;charset=utf-8" );
    //连接数据库操作
    $conn = mysqli_connect('localhost','root','123','testsystem') or die('数据库连接失败');
    // 设置客户端默认字符集为utf8，防止乱码
    $conn->set_charset('utf8');
    //获取传入的用户名，密码，邮箱，地址
    $user = $_POST['username'];
    $pass = $_POST['password'];
    $email = $_POST['email'];
    $address = $_POST['address'];
 	//定义数据库插入语句
    $sql = "INSERT INTO member_info(username,password,email,address) 
    			VALUES ('{$user}' ,'{$pass}','{$email}','{$address}')";
    //执行该语句
    mysqli_query($conn,$sql) or die(mysqli_error($conn));
    echo("注册成功")     
?>
