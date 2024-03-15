<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/6/15
  Time: 16:26
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<%@ page import="java.lang.Math" %>
<%@ page import="java.lang.String" %>
<%
    String a="",b="",c="";
    a=request.getParameter("a");
    b=request.getParameter("b");
    c=request.getParameter("c");
    if(a==null)a="";
    if(b==null)b="";
    if(c==null)c="";
%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>方程求根</title>
    <style>
        .myinput{
            width:40px;
        }
    </style>
</head>
<body>
<p>
    计算方程ax<sup>2</sup>+bx+c=0的根。
</p>
<p>
    编写jsp程序代码实现对方程的求解
</p>
<form action="" method="post">
    <input class="myinput" type=text id="a" name="a" value="<%=a%>">x<sup>2</sup>+
    <input class="myinput" type=text id="b" name="b" value="<%=b%>">x+
    <input class="myinput" type=text id="c" name="c" value="<%=c%>">=0
    <input type=submit name="js" value="求解" >
</form>
<%
    float A=0,B=0,C=0;
    if(!a.isEmpty() && !b.isEmpty() && !c.isEmpty())
    {
        A = Float.parseFloat(a);
        B = Float.parseFloat(b);
        C = Float.parseFloat(c);
    }

    float D,x1,x2;
    D=B*B-4*A*C;        //计算判别式
    if(D<0)
        out.println("无实数根！\n");
    else if(D==0)
        out.println("有两个相等的实数根"+-B/(2*A));
    else
    {
        x1= (float) ((-B+Math.sqrt(D))/(2*A));
        x2= (float) ((-B-Math.sqrt(D))/(2*A));
        out.println("x1"+x1+"x2"+x2);
    }
%>
</body>
</html>