<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/5/1
  Time: 17:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>计算教师工资</title>
</head>
<body>
<p style="text-indent: 4em">计算教师工资</p>
<form action="#" method="post">
    姓名<input type="text" name="name"><br>
    职称<input type="radio" value="助教" name="1">助教
    <input type="radio" value="讲师" name="2">讲师
    <input type="radio" value="副教授" name="3">副教授
    <input type="radio" value="教授" name="4">教授<br>
    性别<select name="gender">
    <option>男</option>
    <option>女</option>
    <option>未知</option>
</select><br>
    <input type="submit" value="提交" style="margin-left: 2.5em">
</form>
</body>
</html>
