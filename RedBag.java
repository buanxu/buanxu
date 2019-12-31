import java.util.Random;
import java.util.Scanner;

public class RedBag {

	public static void main(String[] args) {
		System.out.println("-----模拟随机数-----");
		Scanner sc=new Scanner(System.in);
		System.out.println("输入总金额：");
		
		
		double total=sc.nextDouble();
		System.out.println("输入红包的个数:");
		int bagsum=sc.nextInt();
		double min=0.01;
		
		Random random=new Random();
		for(int i=1;i<bagsum;i++) {
			
			double max=total-(bagsum-i)*min;
			double bound=max-min;
			double safe=(double)random.nextInt((int)(bound*100))/100;
			double money=safe+min;
			total=total-money;
			System.out.println("第"+i+"个红包："+String.format("%.2f", money+"元"));
		}
		 System.out.println("第"+bagsum+"个红包："+String.format("%.2f", total+"元"));
		 sc.close();
	}
	
	
}
