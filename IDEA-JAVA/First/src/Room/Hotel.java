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
        
    }
}
