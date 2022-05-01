<html>
<body>
<%
    String[] xm = {"zhang","li","xiao"};
    for (int i=0;i<3;i++) {%>
    <a href="b.jsp?no=<%=i+1%>&name=<%=xm[i]%>"><%=i+1+" "+xm[i]%></a><br>
<%}%>
</body>
</html>