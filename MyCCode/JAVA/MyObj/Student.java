package Object;
public class Student {
    
    private String S_name;
    private int S_age;
    private int S_id;

    public static void main(String[] args) {
        Student s1 = new Student("abc", 18, 1);
        Student.setKind("PKU");

        System.out.println(s1.getName());
    }

    public static String kind = "";

    public static void setKind(String k) {
        kind = k;
    }

    public Student() {
        S_name = "Unknow";
        S_age = -1;
        S_id = -1;
    }
    public Student(String name, int age, int id) {
        this.S_name = name;
        this.S_age = age;
        this.S_id = id;
        // this(name, age, 1);
    }

    public String getName() {
        return S_name;
    }
    public int getAge() {
        return S_age;
    }
    public int getId() {
        return S_id;
    }

    public void sayhello() {
        System.out.println("Hello! " + S_name);
    }

}

