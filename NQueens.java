/**
 * nQueensQuestion
 * edit date : 2016-03-23 08:46-09:14 09:14-09:46
 */
import java.util.*;

import javax.print.attribute.standard.PrinterLocation;
 
public abstract class NQueens{
    
    //Number of Queens
    private static int N = 1;

    private static int num = 1;
    
    //Print indexRecorder
    private static void printMartix(int[] indexRecorder){
        
        //place print code here
        for(int i = 0; i < N; i++){
            
            for(int j = 0; j < N; j++){
                
                if(j == indexRecorder[i]){
                    System.out.print("A");
                } else{
                    System.out.print(".");
                }
            }
            System.out.println();
        }
        // System.out.println();	
    }
    
    //judge current martix is true or false
    private static boolean wellDown(int[] indexRecorder, int line){
        
        //place code here
        for(int i = 0; i < line; i++){
            
            if(indexRecorder[i] == indexRecorder[line])
                return false;
            
            if((indexRecorder[i]-indexRecorder[line]) == (i-line) ||
                       (indexRecorder[i]-indexRecorder[line]) == (line-i))
                return false;
        }
        return true;
    }
    
    //Find answers
    private static void nQeens(int n, int[] indexRecorder, int line){
        
        if(line > N-1){
            System.out.println("No "+ num++ +":");
            printMartix(indexRecorder);
        } else {
            
            for(int col = 0; col < N; col++){
                
                indexRecorder[line] = col;
                if(wellDown(indexRecorder, line)){
                    nQeens(n, indexRecorder, line+1);
                }
            }
        }
    }
    
    public static void main(String[] args){
        
        int[] indexRecorder = new int[100];
        N = 8;
        nQeens(N, indexRecorder, 0);
    }
}