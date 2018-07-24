import java.io.IOException;
import java.lang.Process;
import java.io.File;

class Test {

    public static void main(String[] args) {
        String dir = "/home/unibosy/ws/temp/java/Agora_Recording_SDK_for_Linux_FULL/samples/cpp/release/bin/20180724/myrobot_082317";
        String shell= "./video_convert.py -f " + dir;
        try{
            Process p = Runtime.getRuntime().exec(new String[]{"/bin/sh", "-c", shell}, null, new File("/home/unibosy/ws/temp/java/Agora_Recording_SDK_for_Linux_FULL/tools"));
            p.waitFor();
        }catch(IOException e){

        }catch(InterruptedException e) {
            e.printStackTrace();
        }
    }
}
