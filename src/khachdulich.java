package test;

import java.util.Scanner;

public class khachdulich {

    int MAX = 100;
    int MIN = MAX;
    int ways[][];
    int sotp;
    int tpxp;
    int free[];
    int buocdi[];
    int chiphi[];
    int best[];

    public khachdulich() {
        Scanner scan = new Scanner(System.in);
        System.out.print("So thanh pho: ");
        sotp = scan.nextInt();
        ways = new int[sotp + 1][sotp + 1];
        free = new int[sotp + 1];
        buocdi = new int[sotp + 1];
        chiphi = new int[sotp + 1];
        best = new int[sotp + 1];
        for (int i = 1; i <= sotp; i++) {
            free[i] = 0;
            for (int j = 1; j <= sotp; j++) {
                ways[i][j] = MAX;
            }
        }
        int n = scan.nextInt();
        int x, y, z;
        for (int i = 0; i < n; i++) {
            x = scan.nextInt();
            y = scan.nextInt();
            z = scan.nextInt();
            ways[x][y] = z;
            ways[y][x] = ways[x][y];
        }
        System.out.print("Thanh pho xuat phat: ");
        tpxp = scan.nextInt();
        free[tpxp] = 1;
        buocdi[1] = tpxp;
        chiphi[1] = 0;
    }

    public void Try(int k) {
        for (int i = 1; i <= sotp; i++) {
            if (free[i] == 0) {
                buocdi[k] = i;
                chiphi[k] = chiphi[k - 1] + ways[buocdi[k - 1]][i];
                if(chiphi[k]<MIN){
                    free[i]=1;
                    if(k==sotp){
                        if(chiphi[k]+ways[buocdi[k]][tpxp]<MIN){
                            for(int j=1;j<=sotp;j++){
                                best[j]=buocdi[j];
                            }
                            MIN=chiphi[k]+ways[buocdi[k]][tpxp];
                        }
                    }else{
                        Try(k+1);
                    }
                    free[i]=0;
                }
            }
        }
    }

    public void output() {
        if(MIN!=MAX){
            for(int i=1;i<=sotp;i++){
                System.out.print(best[i]+"->");
            }
            System.out.print(tpxp);
            System.out.println("Chi phi toi uu: "+MIN);
        }else
            System.out.println("NO SOLUTION");
    }

    public static void main(String[] args) {
        khachdulich kdl = new khachdulich();
        kdl.Try(2);
        kdl.output();
    }
}
