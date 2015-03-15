/*
* Author: darkdream
* Created Time: 2014年03月21日 星期五 10时59分45秒
*/
import java.math.BigInteger;
import java.util.Scanner;

public class Main2424 {
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		int n;  						           //用来指示表达式中的符号
		String[] f = new String[30];  	           //字符数组
		BigInteger[] num = new BigInteger[30];     //大数数组
		String str;
		long k = 0;
		f[0] = "1";
		while(cin.hasNext()){
			int flag = 1,ntop = 0,stop = 0;
			k++;                                   //用来标记第几个测试用例
			n=cin.nextInt();
			if(n%2==0)flag=0;                      //flag 标志变量
			for(int i=0; i<n; i++){
				str = cin.next();                  //查找并返回此扫描器的第一个标记  也就是扫描一行中的第一个标记  遇到空格扫描结束
				if(flag == 0)continue;             //至少能表示扫描的不是第一个标记
				if(i%2==0&&(!str.equals("+")&&(!str.equals("*")))){//表示第二个字符不是+ 或者 *的处理  如何是数字而不是* +表示合理
					BigInteger w = new BigInteger(str);            //调用大数的构造方法 将字符串转换成大数
					num[++ntop] = w;                               //在数组的第一个位置存储下这个大数
					if(f[stop].equals("*")){                       //stop是用来标记+和*的位置的 至少在第一次时候不会执行这一句
						num[ntop-1] = num[ntop].multiply(num[ntop-1]);//高精度乘法
						ntop--;
						stop--;
					}
				}else if(i%2!=0&&(str.equals("+")||str.equals("*"))){//对于是+或者*而不是数字的处理
					f[++stop] = str;                                 //将这个字符串保存下来
					if(f[stop].equals("+")&&ntop>1){                 //如果是+表示当前的数字需要同前面的数字先进行运算了
						num[ntop-1] = num[ntop].add(num[ntop-1]);
						ntop--;
						stop--;
					}
				}else {
					flag = 0;
				}
			}
			while(flag!=0&&stop>0){
				if(f[stop].equals("+"))
					num[ntop-1] = num[ntop].add(num[ntop-1]);
				else if(f[stop].equals("*"))
					num[ntop-1] = num[ntop].multiply(num[ntop-1]);
				stop--;
			}
			if(flag == 0)
				System.out.println("Case "+k+": "+"Invalid Expression!");
			else
				System.out.println("Case "+k+": "+num[1]);
		}
	}
}
