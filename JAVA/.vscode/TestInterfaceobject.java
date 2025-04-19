interface Usb {
    public void start();

    public void stop();
}

class PS5 implements Usb {
    public void start() {
        System.out.println("PS5 start...");
    }

    public void stop() {
        System.out.println("PS5 stop...");
    }
}

class MP4 implements Usb {
    public void start() {
        System.out.println("MP4 Start...");
    }

    public void stop() {
        System.out.println("MP4 Stop...");
    }
}

class Computer {
    public void work(Usb u) {
        u.start();
        u.stop();
    }
}

public class TestInterfaceobject {
    public static void main(String[] args) {
        new Computer().work(new PS5());
        new Computer().work(new MP4());
    }
}
