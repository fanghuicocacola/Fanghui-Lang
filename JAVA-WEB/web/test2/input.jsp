<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<% request.setCharacterEncoding("utf-8"); %>
<%--这两行代码可以解决网页展示和传参的乱码问题。--%>
<HTML>
<head>

    <title>用户注册界面</title>

    <meta http-equiv="content-type" content="text/html;charset=UTF-8">

</head>
<BODY bgcolor=cyan><span style="font-size: small; ">

  <FORM action="receive.jsp" method=post name=form>

    <P>请输入下列信息：

      <BR>输入您的姓名:<INPUT type="text" name="name" value="张三"></P>

      <BR>选择性别:<INPUT type="radio" name="R" value="男" checked="default">男

      <INPUT type="radio" name="R" value="女">女

      </BR>

      <BR>选择您喜欢的歌手:

      <input type="checkbox" name="superstar" value="张歌手">张歌手

      <input type="checkbox" name="superstar" value="李歌手">李歌手

      <input type="checkbox" name="superstar" value="刘歌手">刘歌手

      <input type="checkbox" name="superstar" value="王歌手">王歌手

      </BR>

      <INPUT TYPE="hidden" value="这是隐藏信息" name="secret">

      <INPUT TYPE="submit" value="提交" name="submit">

  </FORM>

</span></BODY>
</HTML>