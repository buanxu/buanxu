import java.util.Random;
import java.util.Scanner;

public class RedBag {

	public static void main(String[] args) {
		System.out.println("-----ģ�������-----");
		Scanner sc=new Scanner(System.in);
		System.out.println("�����ܽ�");
		
		
		double total=sc.nextDouble();
		System.out.println("�������ĸ���:");
		int bagsum=sc.nextInt();
		double min=0.01;
		
		Random random=new Random();
		for(int i=1;i<bagsum;i++) {
			
			double max=total-(bagsum-i)*min;
			double bound=max-min;
			double safe=(double)random.nextInt((int)(bound*100))/100;
			double money=safe+min;
			total=total-money;
			System.out.println("��"+i+"�������"+String.format("%.2f", money+"Ԫ"));
		}
		 System.out.println("��"+bagsum+"�������"+String.format("%.2f", total+"Ԫ"));
		 sc.close();
	}
	
	
}
