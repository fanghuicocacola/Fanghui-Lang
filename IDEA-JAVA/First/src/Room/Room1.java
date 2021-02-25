package Room;

public class Room1 {
    private int no;
    private String type;
    private boolean status;
    public Room1(){

    }
    public Room1(int no,String type,boolean status){
        this.no = no;
        this.type = type;
        this.status = status;
    }
    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public boolean isStatus() {
        return status;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }

    public int getNo() {
        return no;
    }

    public void setNo(int no) {
        this.no = no;
    }

    public String toString()
    {
        return "["+no+","+type+","+(status?"空闲":"占用")+"]";
    }
    public boolean equals(Object obj){
        if(obj == null || !(obj instanceof Room1))
            return false;
        if(this == obj)
            return true;
        Room1 room = (Room1)obj;
        return this.getNo() == room.getNo();
    }
    public static void main(String[] args) {
        Room1 R1 = new Room1(101,"单人间",true);
        System.out.println(R1.toString());
        Room1 R2 = new Room1(101,"单人间",true);
        System.out.println(R1.equals(R2));
    }
}
