package thuattoan;

import java.util.Scanner;

public class Dijkstra {

    int max = 100;
    int hientai = 0;
    int soNut = 6;
    int ways[][] = new int[max][max];
    int ngan1[] = new int[max];
    int free[] = new int[max];
    int duongdi[] = new int[max];
    int min;

    void init() {
        for (int i = 0; i < soNut; i++) {
            free[i] = 0;
            duongdi[i] = 0;
            ngan1[i] = max;
        }
        for (int i = 0; i < soNut; i++) {
            for (int j = 0; j < soNut; j++) {
                ways[i][j] = max;
            }
        }
        System.out.print("Nhap ways:\n");
        Scanner scan = new Scanner(System.in);
        int x, y, z;
        for (int i = 0; i < 11; i++) {
            //ways[scan.nextInt()][scan.nextInt()]=scan.nextInt();
            x = scan.nextInt();
            y = scan.nextInt();
            z = scan.nextInt();
            ways[x][y] = z;
        }
        System.out.print("ket thuc init\n");
        output();
    }
    void output(){
        for (int i = 0; i < soNut; i++) {
            for (int j = 0; j < soNut; j++) {
                System.out.print(ways[i][j]+"  ");
            }
            System.out.print("\n");
        }
    }
    void outputNgan1(){
        System.out.print("\n---------------------\n");
        for(int i=0;i<soNut;i++){
            System.out.print(ngan1[i]+"  ");
        }
        System.out.print("\n---------------------\n");
    }
    public void dijkstra(int bd, int kt) {
        int kcm, k = 0;
        
        ngan1[bd]=0;
        free[bd]=1;
        hientai=bd;
        
        while (hientai != kt) {
            min = max;
            for (int i = 0; i < soNut; i++) {
                if (free[i] == 0) {
                    kcm = ngan1[hientai] + ways[hientai][i];
                    if (kcm < ngan1[i]) {
                        ngan1[i] = kcm;
                    }
                    if (ngan1[i] < min) {
                        min = ngan1[i];
                        k = i;
                    }
                }
            }
            hientai = k;
            free[k] = 1;
            outputNgan1();
        }
        System.out.print("Chi phi:" + ngan1[kt]+"\n");
    }
public static void main(String argv[]){
	Dijkstra ds=new Dijkstra();
	ds.init();
	ds.dijkstra(0,5);
}
}
