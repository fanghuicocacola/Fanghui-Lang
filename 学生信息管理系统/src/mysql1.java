import java.sql.*;

public class mysql1 {
    Connection con = null;
    Statement sql;
    ResultSet rs;

    //连接数据库
    public void MyCon() {
        //加载JDBC-MySQL数据库连接器
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (Exception e) {
        }

        //连接数据库
        String uri = "jdbc:mysql://localhost:3306/user?" +
                "useSSL=false&serverTimezone=GMT&characterEncoding=utf-8";
        String user = "root";
        String password = "";
        try {
            con = DriverManager.getConnection(uri, user, password); //连接代码
            sql = con.createStatement();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public String Selectpw(String username) {
        try {
            sql = con.createStatement();
            rs = sql.executeQuery("select * from userList where username=" + username);
            while (rs.next()) {
                return rs.getString(2);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return "False";
    }

    public String Selectun(String username) {
        try {
            sql = con.createStatement();
            rs = sql.executeQuery("select * from userList where username=" + username);
            while (rs.next()) {
                return rs.getString(1);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return "False";
    }

    public int Selectmy(String username) {
        try {
            sql = con.createStatement();
            rs = sql.executeQuery("select * from userList where username=" + username);
            while (rs.next()) {
                return rs.getInt(3);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return -1;
    }

    public void setMoney(String username, int a) {
        try {
            sql = con.createStatement();
            sql.execute("update userList  set money =" + a + " where username=" + username);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void setpassword(String username, String newPassword) {
        try {
            sql = con.createStatement();
            sql.execute("update userList  set password =" + newPassword + " where username=" + username);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
