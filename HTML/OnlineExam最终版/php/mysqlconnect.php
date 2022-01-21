<?php
header("Content-type:text/html;charset=utf-8");
//连接数据库操作
$conn = mysqli_connect('localhost', 'root', '123', 'testsystem') or die('数据库连接失败');
//获取传入的用户名和密码信息
$user = $_POST['userName'];
$pass = $_POST['password'];
//定义一个数据库查询语句
$sql = "SELECT * FROM member_info where username='{$user}' and password='{$pass}'";
//执行查询，获取查询结果集
$result = $conn->query($sql);
//返回查询结果集的行数
$row = mysqli_num_rows($result);
// 行数大于等于1，则登录成功
if ($row == true) {
    echo $row . "登录成功!";
} else {
    echo "登录失败，请重新登录！";
}
