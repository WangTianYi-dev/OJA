import java.util.Scanner;
public class xushu {

    public static void main(String[] args) {
        // 扫描字符串
        Scanner sc = new Scanner(System.in);
        String string = sc.next();
        // 字符串的长度
        int length = string.length();
        // 测试运行时间
        long time = System.currentTimeMillis();
        int a[] = new int[10];
        a[0] = 1;
        // 字符排列生成的排列个数
        int sum = 0;
        // 固定字符串长度的可排列个数
        for (int i = 1; i < 10; i++) {
            // a[1],a[2],a[3]......
            a[i] = i * a[i - 1];
        }
        for (int i = 0; i < length; i++) {
            // k表示有多少个比当前字母小的在前面
            int k = 0;
            for (int j = 0; j < i; j++) {
                if (string.charAt(j) < string.charAt(i))
                    k++;
            }
            // a[length-i-1]表示当前第i个字母后还有多少个字母可形成的排列个数
            // string.charAt(i)-'a'-k 第i个字母减去比它小的字母，再计算i字母前还有多少个比它小的字母，可形成排列个数
            // 比如 adcb 计算第1个位置即i=0;=>a[3] 第二个位置i=1,比它小的一个，d前面还可以有b、c 可形成排列个数2*a[2] +.....
            sum = sum + a[length - i - 1] * (string.charAt(i) - 'a' - k);
        }
        System.out.println("sum=" + sum);
    }

}
