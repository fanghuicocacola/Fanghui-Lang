import org.apache.commons.io.FileUtils;

import java.io.File;
import java.io.IOException;
import java.net.URL;

public class TestThread2 extends Thread{

    private  String url;
    private String name;

    public TestThread2(String url, String name) {
        this.url = url;
        this.name = name;
    }

    //线程执行体
    @Override
    public void run() {
        WebDownloader webDownloader = new WebDownloader(); //默认自动生成变量名的快捷键是Ctrl+Alt+v
        webDownloader.downloader(url,name);
        System.out.println("下载文件名为："+name);
    }

    public static void main(String[] args) {
        // 创建三个线程
        TestThread2 t1 = new TestThread2("http://www.ahstu.edu.cn/__local/E/87/C0/DBCDFBE6B5B8780EBFF4A91B503_37ED18C1_54EAC.jpg","1.jpg");
        TestThread2 t2 = new TestThread2("http://www.ahstu.edu.cn/__local/A/37/34/F38F78E4EC4F2918FF6A3C7F4B2_09095F02_19E3D.jpg","2.jpg");
        TestThread2 t3 = new TestThread2("http://www.ahstu.edu.cn/__local/E/05/88/6342D102032C8854191194F78C7_270318E0_161D0.jpg","3.jpg");
        //启动线程
        t1.start();
        t2.start();
        t3.start();
    }
}

//文件下载器
class WebDownloader{
    public void downloader(String url,String name){

        try {
            FileUtils.copyURLToFile(new URL(url),new File(name));
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("IO 异常，网络出错");
        }
    }
}