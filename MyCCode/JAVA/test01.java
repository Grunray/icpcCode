import java.util.Scanner;

import java.util.Stack;
// import java.util.Queue;
// import java.util.Deque;
// import java.util.ArrayDeque;
// import java.util.ArrayList;

// fastRead
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;


public class test01{
@SuppressWarnings("unused")
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        int number = input.nextInt();
        System.out.println(number);

        Stack<Character> stk = new Stack<>();

        double pi = (double) number;

        
        input.close();
    }
    public boolean isValid(String s) {
        Stack<Character> stk = new Stack<>();

        for(int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if(stk.empty()) {
                stk.push(ch);
            }
            else if(stk.peek() == '{' && ch == '}' || 
                    stk.peek() == '(' && ch == ')' || 
                    stk.peek() == '[' && ch == ']') {
                stk.pop();
            }
            else {
                stk.push(ch);
            }

        }

        if(stk.empty())
            return true;
        else return false;
    }
    public int[] plusOne(int[] digits) {
        Stack<Integer> stk = new Stack<>();

        int n = digits.length;
        int now = 1;
        for(int i = n - 1; i >= 0; i--) {
            now += digits[i];
            stk.push(now % 10);
            now /= 10;
        }
        if(now > 0) stk.push(now);

        int[] arr = new int[stk.size()];

        int pos = 0;
        while(!stk.empty()) {
            arr[pos++] = stk.peek();
            stk.pop();
        }

        return arr;
    }
    public boolean isPowerOfFour(int n) {
        if (n == 1) return true;
        if (n % 4 != 0) return false;
        if (n <= 0) return false;

        int[] arr = new int[35];

        int pos = 0;
        while(n > 0) {
            arr[pos++] = n % 4;
            n >>= 2;
            System.out.println(arr[pos - 1]);
        }

        int ans = 0;
        for(int i = 0; i < pos; i++) {
            if(ans == 2) {
                ans = 0;
                if(arr[i] != 1) return false;
            } 
            else  {
                ans++;
                if(arr[i] != 0) return false;
            }
        }
        return true;
    }
    public String maximumOddBinaryNumber(String s) {
        StringBuilder strb = new StringBuilder(s);
        int one = 0;
        int len = s.length();
        for(int i = 0; i < len; i++) {
            if(s.charAt(i) == '1') one++;
        }
        int pos = 0;
        while(one > 1) {
            strb.setCharAt(pos, '1');
            pos++;
            one--;
            len--;
        }
        while(len > 1) {
            strb.setCharAt(pos, '0');
            pos++;
            len--;
        }
        strb.setCharAt(pos++, '1');

        
        return s;
    }
}

class WeChat {

    private String number;
    private String nickname;

    public WeChat(String number, String nickname) {
        this.number = number;
        this.nickname = nickname;
    }
    // 重写，不是重载 X 
    // public boolean equals(WeChat w) { 这个是重载
    //     return this.number.equals(w.number);
    // }
    @Override
    public boolean equals(Object obj) {
        WeChat w = (WeChat) obj;
        return this.number.equals(w.number);
    }
    public String toString() {
        return "WeChat: " + this.number + ", nicename: " + this.nickname;
    }

}

interface Inne {

    
}


class Read{
	StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	public int nextInt() {
        try {
            st.nextToken();
            return (int)st.nval;
        } catch (IOException e) {
            throw new RuntimeException("", e);
        }
    }
}
