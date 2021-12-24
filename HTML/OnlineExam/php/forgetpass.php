<?php
//声明内容类型
header ( "Content-type:text/html;charset=utf-8" );
//连接数据库操作
$conn = mysqli_connect('localhost','root','123','testsystem') or die('数据库连接失败');
//获取传入的用户名和邮箱
$user = $_POST['userName'];
$email = $_POST['email'];
//定义一个数据库查询语句
$sql = "SELECT * FROM member_info where username='{$user}' and email='{$email}'";
//执行查询语句
$result = $conn->query($sql);
//获取查询后返回的结果集行数
$row = mysqli_num_rows($result);
//根据返回的结果集生成一个数组
$rows = mysqli_fetch_assoc($result);
if ($row == true) {
    echo $row. "邮箱正确!";
    //输出对应的密码
    echo "密码是".$rows["password"];
} else {
    echo "不存在该用户！";
}
?>