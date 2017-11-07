package test;
import java.io.File;  
import java.io.FileNotFoundException;  
import java.util.ArrayList;  
import java.util.Arrays;  
import java.util.Scanner;
import java.io.Reader;
import java.io.InputStream;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;
/**
 *
 * @author jm697 
 */
public class temp {
    
    static int min_sup;
    static int min_con;
    static String[][] in=new String[20][5];
    static String[][] itemsetC=new String[50][2];
    static String[][] itemsetL=new String[20][2];
    static ArrayList<String> freqItemset=new ArrayList<String>();
    static int[] freq=new int[30];
    static ArrayList<String> items=new ArrayList<String>();
    static ArrayList<Integer> itemFreq=new ArrayList<Integer>();
    static int g=0;
    
    public static void main(String[] args) throws IOException{
    
        String path="C:\\Users\\jm697\\Downloads\\test\\txtfiles\\electronic_product.txt";
        String line=null;
        int i=0,j=0;
              
        try{
            FileReader fr=new FileReader(path);
            BufferedReader br=new BufferedReader(fr);
            while((line=br.readLine())!=null){
                String[] temp=line.split(",");
                for(i=0;i<temp.length;i++)
                {
                    in[j][i]=temp[i];
                }
                j++;  
            }
        }
        catch(Exception e){
        }
        for(i=0;i<50;i++){
           itemsetC[i][0]=null;
           itemsetC[i][1]="0";
       }
        System.out.println("-----Dataset Used with 20 Transaction-------");
        System.out.println("--------------------------------------------");
        int k,l;
        for(k=0;k<20;k++){
            System.out.print((k+1)+". ");
                for(l=0;l<5;l++){
                    System.out.print(in[k][l]+", ");
                } 
            System.out.print("\n");
        }
        
       System.out.println("===========================================");

        String[] t=new String[10];
        StringBuilder sb=new StringBuilder("");
        int count=0,temp;
        
        for(i=0;i<20;i++){
            for(j=0;j<5;j++){
                if(in[i][j]!=null){
                    if(count==0){
                        sb.append(in[i][j]);
                        sb.append(",");
                        count++;
                    }
                    else{
                        temp=sb.indexOf(in[i][j]);
                        if(temp==(-1)){
                            sb.append(in[i][j]);
                            sb.append(",");
                        }
                        count++;
                    }
                }
            }
        }
        String temp2;
        int temp4;
        temp2=sb.toString();
        String[] temp3=temp2.split(",");
        
        for(k=0;k<10;k++){
            itemsetC[k][0]=temp3[k];
            itemsetC[k][1]="0";
        }
        for(i=0;i<20;i++){
            for(j=0;j<5;j++){
                if(in[i][j]==null){break;}
                else{
                    for(k=0;k<10;k++){
                        if(itemsetC[k][0].equals(in[i][j])){
                            temp4=Integer.parseInt(itemsetC[k][1]);
                            temp4++;
                            itemsetC[k][1]=Integer.toString(temp4);
                        }
                    }
                }
            }
        }
        System.out.println("-------------Scanning Dataset-------------");
        System.out.println("---Generating Candidate itemset List C1---");
        System.out.println("------------------------------------------");
        
        for(i=0;i<10;i++){
            System.out.println((i+1)+". "+itemsetC[i][0]+" : "+itemsetC[i][1]);
            items.add(itemsetC[i][0]); itemFreq.add(Integer.parseInt(itemsetC[i][1]));
        }
        
        Scanner sc=new Scanner(System.in);
        System.out.println("------------------------------------------");
        System.out.println("Enter Minimum Support Threshold Count: ");
        min_sup=sc.nextInt();
        System.out.println("------------------------------------------");
        System.out.println("Enter Minimum Confidence Threshold Percentage: ");
        min_con=sc.nextInt();
        apriori();
        
    }

    private static void apriori() {
        int flag_setno=1,temp,cno,ino;
        do{
        temp=generateList(flag_setno);
        flag_setno++;
        if(temp>1){
            cno=generateC(temp,flag_setno);
        }
        }while(temp>1);
        //System.out.println(Arrays.toString(freqItemset.toArray()));
        //System.out.println(Arrays.toString(freq.toArray()));
        ino=freqItemset.size();
        System.out.println("------------------------------------------");
        System.out.println("Frequent Itemsets(Count): "+ino);
        generateAssociationRules(ino);
    }

    private static int generateList(int flag_setno) {
       int i,j,k,count=0;
       for(i=0;i<50;i++){
           k=Integer.parseInt(itemsetC[i][1]);
           if(k>=min_sup){
               count++;
           }
       } 
       System.out.println("-----------------------------------------");
       System.out.println("--Generating Frequent itemset List L"+flag_setno+"---");
       System.out.println("-----------------------------------------");
       System.out.println("count : "+count);
       j=0;

       for(i=0;i<50;i++){
           k=Integer.parseInt(itemsetC[i][1]);
           if(k>=min_sup){
               itemsetL[j][0]=itemsetC[i][0];
               itemsetL[j][1]=itemsetC[i][1];
               if(flag_setno>1){
                   freqItemset.add(itemsetC[i][0]);
                   freq[g]=Integer.parseInt(itemsetC[i][1]);
                   g++;
               }
               System.out.println((j+1)+". "+itemsetL[j][0]+": "+itemsetL[j][1]);
               j++;
           }
       }
       return count;
    }

    private static int generateC(int a,int b) {
       int i,j,temp1=0,k;
       String temp;
       boolean att=true;
       a--;
       System.out.println("-----------------------------------------");
       System.out.println("--Generating Candidate itemset List C"+(b)+"---");
       System.out.println("-----------------------------------------");
       for(i=0;i<50;i++){
           itemsetC[i][0]=null;
           itemsetC[i][1]="0";
       }
       for(i=0;i<a;i++){
           for(j=(i+1);j<(a+1);j++){
               att=true;
               temp=itemsetL[i][0]+","+itemsetL[j][0];
               String[] divide=temp.split(",");
               
               Set<String> set = new HashSet<String>();
               set.addAll((List<String>) Arrays.asList(divide));
               divide=(String[]) set.toArray(new String[set.size()]);
               
               String joined = String.join(",", divide);
               for(k=0;k<temp1;k++){
                   if(itemsetC[k][0].equals(joined)){
                       att=false;
                   }
               }
                int freq;
                if(divide.length==b && att==true){
                freq=findFreq(divide,b);
                itemsetC[temp1][0]=joined;
                itemsetC[temp1][1]=Integer.toString(freq);
                temp1++;
                System.out.println(temp1+". "+joined+": "+freq); 
               }
           }
       }
       return temp1;
    }

    private static int findFreq(String[] divide,int b) {
        int f=0,i,j,k,flag=0;
        for(i=0;i<20;i++){
            flag=0;
            for(j=0;j<5;j++){
                for(k=0;k<b;k++){
                    if(divide[k].equals(in[i][j])){
                        flag++;
                        break;
                    }
                }
            }
            if(flag==b){
            f++;
            }
        }
        return f;
    }

    private static void generateAssociationRules(int ino) {
       int i,j,k,s=1,temp3;
       String temp;
       double sup,con;
       //String[] temp1;
       ino--;
       for(i=0;i<=ino;i++){
           temp=freqItemset.get(i);
           String[] temp1=temp.split(",");
           if(temp1.length==2){
                sup=(double)freq[i]/20;
                temp3=calDeno(temp1[0]);
                con=((double)freq[i]/temp3)*100;
                if(con>min_con){
                    System.out.println(s+". {"+temp1[0]+"} -> {"+temp1[1]+"}( Support : "+sup*100+"% , Confidence: "+con+"% )");s++;
                }
           }
           else{
               sup=(double)freq[i]/20; 
               String a="";
               temp3=getDeno(temp1,ino);
               for(int l=0;l<(temp1.length-1);l++){
                   if(l!=temp1.length-2){
                       a=a.concat(temp1[l]);
                       a=a.concat(",");
                   }
                   else{
                        a=a.concat(temp1[l]);            
                   }
               }
               con=(double)freq[i]/temp3;
               if(con>min_con){
                    System.out.println(s+". {"+a+"} -> {"+temp1[temp1.length-1]+"}( Support : "+sup*100+", Confidence: "+con+"% )");s++;
               }
            }
       }
    }

    private static int calDeno(String string) {
        int k=0;
        for(int j=0;j<10;j++){
            if(items.get(j).equals(string)){
                k=itemFreq.get(j);
            }
        }
        return k;
    }

    private static int getDeno(String[] temp1, int a) {
       int i,k=0,l=0,c=0,r=0;
       String aa;
       l=temp1.length-1;
       for(k=0;k<a;k++){
           c=0;
           for(i=0;i<l;i++){
               aa=freqItemset.get(k);
               if(aa.contains(temp1[i])){
                   c++;
               }
               if(c==l){
                   r=freq[k];
               }
           }
       }
       return r;
    }
    
     
}
