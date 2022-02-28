import java.math.BigInteger;
import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		BigInteger min = new BigInteger("1000000000");
		BigInteger sum = new BigInteger("0");
		
		int num = n + m + 1;
		for (int i = 0; i < num; i++) {
			BigInteger temp = new BigInteger(sc.nextInt()+"");
			sum = sum.add(temp);
			min = temp.compareTo(min)==-1?temp:min;
		}
		System.out.println(sum.subtract(min.multiply(new BigInteger("2"))));
	}
}
