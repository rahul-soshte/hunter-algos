import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;
class Berkeley{
    int time, avg = 0;
    int[] delays;
    Berkeley(String str){
        String[] s = str.split(":");
        time = 3600*Integer.parseInt(s[0]) + 60*Integer.parseInt(s[1]) + Integer.parseInt(s[2]);
    }
    void setDelays(String[] str){
        delays = new int[str.length];
        for(int i = 0; i < str.length; i++){
            String[] s = str[i].split(":");
            delays[i] = 3600*Integer.parseInt(s[0]) + 60*Integer.parseInt(s[1]) + Integer.parseInt(s[2])-time;
            System.out.println("The delay of node "+i+" is "+getTime(delays[i], true));
        }
        System.out.println("These delays are sent to the master.");
    }
    void setAvg(){
        int sum = 0, n = delays.length;
        for(int i = 0; i < delays.length; i++)
            if(Math.abs(delays[i])<(7200))sum += delays[i]; //if delay is more than 2 hours, ignore it
            else{
                System.out.println("Delay of Node "+i+"is too large. So not counting it in calculating average delay.");
                n--;
            }
        avg =  Math.round(sum/(n+1));
        System.out.println("The average delay is "+getTime(avg, true));
    }
    String getTime(int seconds, boolean eng){
        int h=seconds/3600;
        int m=(seconds-(h*3600))/60;
        int s=(seconds-(h*3600))-(m*60);
        if(eng)
            if(seconds>=0)return  h+" hours "+m+" minutes "+s+" seconds";
            else return "-("+Math.abs(h)+" hours "+ Math.abs(m)+ " minutes "+Math.abs(s)+"  seconds)";
        else
            if(seconds>=0) return String.format("%02d", h)+":"+String.format("%02d", m)+":"+String.format("%02d", s);
            else return "-("+String.format("%02d", h)+":"+String.format("%02d", m)+":"+String.format("%02d", s)+")";
    }
    void calcCorr(){
        System.out.println("The master adjusts its time by " +getTime(avg, true));
        for(int i = 0; i < delays.length; i++)
            System.out.println("Master suggests Node "+i+" to adjust its time by "+getTime(avg-delays[i], true));
        System.out.println("All nodes, including the master show "+getTime(time+avg,false));
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of nodes: ");
        int n = sc.nextInt();
        System.out.println("Enter the times of the other nodes.");
        String[]inp = new String[n];
        for(int i = 0; i < n; i++) inp[i] = sc.next();
        System.out.println(new SimpleDateFormat("hh:mm:ss").format(new Date()))    
        Berkeley b = new Berkeley(new SimpleDateFormat("hh:mm:ss").format(new Date()));
        System.out.println("The master sends its time "+b.getTime(b.time, false)+" to all nodes.");
        b.setDelays(inp);
        b.setAvg();
        b.calcCorr();
    }
}