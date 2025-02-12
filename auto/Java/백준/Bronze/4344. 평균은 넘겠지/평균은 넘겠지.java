import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner Sc = new Scanner(System.in);
        
        int[] Array;
        
        int TC = Sc.nextInt();
        
        for (int i=0; i<TC; i++)
        {
            int N = Sc.nextInt();
            Array = new int[N];
            double sum=0;
            
            for (int j=0; j<N; j++)
            {
                int k = Sc.nextInt();
                Array[j]=k;
                sum += Array[j];
            }
            
            double mean = (sum/N);
            double cnt = 0;
            
            for(int l=0; l<N; l++)
            {
                if (Array[l] > mean)
                {
                    cnt++;
                }
            }
            
            System.out.printf("%.3f%%\n", (cnt/N)*100);
        }
    }
}