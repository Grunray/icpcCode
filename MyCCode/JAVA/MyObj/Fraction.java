package Object;


public class Fraction {
    private int fz, fm;
    public Fraction(int fz, int fm) {
        int gcdd = gcd(fz, fm);
        this.fz = fz / gcdd;
        this.fm = fm / gcdd;
    }

    private int gcd(int a, int b) {
        while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    public Fraction plus(Fraction r) {
        Fraction temp = new Fraction(this.fz, this.fm);
        temp.fz = temp.fz * r.fm + r.fz * temp.fm;
        temp.fm *= r.fm;
        int gcdd = gcd(temp.fz, temp.fm);
        temp.fz/= gcdd;
        temp.fm/= gcdd;
        return temp;
    }

    public void print() {
        if(this.fz == 1 && this.fm == 1) {
            System.out.println(1);
        }
        else {
            System.out.println(this.fz + "/" + this.fm);
        }
    }
}
