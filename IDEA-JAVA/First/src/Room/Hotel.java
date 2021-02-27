package Room;

public class Hotel {
    private Room1[][] room1s;
    public Hotel(){
        room1s = new Room1[3][10];
        for (int i = 0;i<room1s.length;i++){
            for(int j = 0;j<room1s[i].length;j++){
                if(j%2==0) {
                    room1s[i][j] = new Room1((i + 1) * 100 + j + 1, "单人间", true);
                }
                else if (j == 9) {
                    room1s[i][j] = new Room1((i + 1) * 100 + j + 1, "豪华套房", true);
                }
                else {
                    room1s[i][j] = new Room1((i + 1) * 100 + j + 1, "双人间", true);
                }
            }
        }
    }
    public void print(){
        for (int i = 0;i<room1s.length;i++){
            for(int j = 0;j<room1s[i].length;j++) {
                Room1 room1 = room1s[i][j];
                System.out.println(room1);
            }
            System.out.println();
        }
    }
    public void order(int roomNo){
        Room1 room1 = room1s[roomNo/100-1][roomNo%100-1];
        room1.setStatus(false);
    }
    public void  exit(int roomNo){
        Room1 room1 = room1s[roomNo/100-1][roomNo%100-1];
        room1.setStatus(true);
    }
}
