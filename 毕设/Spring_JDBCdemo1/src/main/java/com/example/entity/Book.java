package com.example.entity;

public class Book {
    private String userID;
    private String userName;
    private String uStatus;

    @Override
    public String toString() {
        return "Book{" +
                "userID='" + userID + '\'' +
                ", userName='" + userName + '\'' +
                ", uStatus='" + uStatus + '\'' +
                '}';
    }
    public void setUserID(String userID) {
        this.userID = userID;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public void setUStatus(String uStatus) {
        this.uStatus = uStatus;
    }

    public String getUserID() {
        return userID;
    }

    public String getUserName() {
        return userName;
    }

    public String getUStatus() {
        return uStatus;
    }

}
