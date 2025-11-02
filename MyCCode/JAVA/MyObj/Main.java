package MyObj;

import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        StringBuilder sb=new StringBuilder();
        TreeMap<String,Integer> tm2=getMap(sc.nextLine());//tm2是z教授
        TreeMap<String,Integer> tm1=getMap(sc.nextLine());//tm1是w教授
        Set<String> strings1 = tm1.keySet();
        Set<String> strings2 = tm2.keySet();
        for (String string : strings1) {
            if (strings2.contains(string)){
                int num1=tm1.get(string);
                int num2=tm2.get(string);
                if (num1>num2){
                    sb.append("w:").append(string).append(" ").append(num1).append(",");
                }else{
                    sb.append("z:").append(string).append(" ").append(num2).append(",");
                }
            }
        }
        if (sb.toString().equals("")) System.out.println("none");
        else{
            String[] split = sb.toString().split(",");
            for (int i = 0; i < split.length; i++) {
                System.out.print(split[i]);
                if (i!=split.length-1) System.out.print(",");
            }
        }
        sc.close();
    }

    public static TreeMap<String,Integer> getMap(String s){
        TreeMap<String,Integer> tm2=new TreeMap<>();
        String sss= s.replace(","," ");
        String[] ss=sss.split(":");
        String[] s1 = ss[1].split(" ");
        for (int i1 = 0; i1 < s1.length; i1+=2) {
            if (tm2.get(s1[i1])!=null){
                tm2.put(s1[i1], tm2.get(s1[i1])+Integer.parseInt(s1[i1+1]));
            }else{
                tm2.put(s1[i1],Integer.parseInt(s1[i1+1]));
            }
        }
        return tm2;
    }
}

