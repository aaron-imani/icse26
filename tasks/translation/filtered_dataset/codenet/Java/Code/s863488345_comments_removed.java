import java.util.*;
 
public class Main{
    static int mapNum;

    static int h;

    static int w;

    static char[][] battleTown;

    static int bomberActNum;

    static char [] bomberAct;





    static int []tank = new int [2];
    static int xOfTank;
    static int yOfTank;
    static int xOfBomber;
    static int yOfBomber;    
    static int s;

    static int k;

    static int a;

    static int b;

    static int x;

    static int y;

    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        mapNum = sc.nextInt();

        for(int i = 0;i < mapNum; i++){
            if(1<=i && i< mapNum){
                System.out.println("");
            }
            h = sc.nextInt();
            w = sc.nextInt();

            battleTown = new char[h][w];


            for(int j=0; j<h; j++){
                char[] c = sc.next().toCharArray();
                for(int k=0; k<w; k++){
                    battleTown[j][k] = c[k];



                    if('^'==battleTown[j][k]
                    ||'v'==battleTown[j][k]
                    ||'<'==battleTown[j][k]
                    ||'>'==battleTown[j][k]){


                        x = j;
                        y = k; 
                        
                    }

                } 

            }




            bomberActNum = sc.nextInt();
            bomberAct = sc.next().toCharArray();

            if(0 <= x && x <= h && 0<= y && y <= w){ 
                for(int l=0; l<bomberActNum; l++){
                
                    if(bomberAct[l] == 'U'){




                        battleTown[x][y] ='^';
                            if(x-1 >=0 && battleTown[x-1][y]=='.'){
    


                                 battleTown[x-1][y] ='^';
                                 battleTown[x][y] ='.';
                                 x--;
                            }
                    }
                    if(bomberAct[l] == 'D'){
                        





                        battleTown[x][y] ='v';
                            if(x+1 <h && battleTown[x+1][y]=='.'){


                                battleTown[x+1][y] ='v';
                                battleTown[x][y] ='.';
                                x++;

                            }
                    }
                    if(bomberAct[l] == 'L'){




                         battleTown[x][y] ='<';
                            if(y-1 >=0 && battleTown[x][y-1]=='.'){


                                battleTown[x][y-1] ='<';
                                battleTown[x][y] ='.';
                                y--;
                            }
                    }
                    if(bomberAct[l] == 'R'){




                        battleTown[x][y] ='>';
                           if(y+1 <w && battleTown[x][y+1]=='.'){


                                battleTown[x][y+1] ='>';
                                battleTown[x][y] ='.';
                                y++;
                           }
                    }
                    
                    if(bomberAct[l] == 'S'){




                        xOfBomber = x;
                        yOfBomber = y;
                        moveBomber(xOfBomber,yOfBomber);
                    }
                }
                for(s =0; s < h;s++){
                    for(k =0; k <w;k++){
                        System.out.print(battleTown[s][k]);
                    }System.out.println();




                
                }
            }
        }
    }
    
    
    


 


    public static void moveBomber(int a,int b){




               
      if(0 <= a && a <= h && 0<= b && b <= w){

            if('^'==battleTown[a][b]){


                 for(int i = a-1;  i >= 0; i--){
                     if(a<=0){
                            return;
                     }else




                  
                    if(battleTown[a-1][b]=='*'){


                        
                        battleTown[a-1][b]='.';


                        
                        return;
                    }else if(battleTown[a-1][b]=='#'){


                        
                        return;
                    }else{
                
                        a--;


                        if(a==0){
                            return;
                        }


                    }
           }
        }

        if('v'==battleTown[a][b]){
            for(int i = a+1; i < h; i++){



                    
                    if(battleTown[a+1][b]=='*'){
                        battleTown[a+1][b]='.';


                        
                        return;
                    }else if(battleTown[a+1][b]=='#'){


                        
                        return;
                    }else{
                        a++;
                        if(a==h){
                            return;
                        }


                        
                    }
            }
        }
        if('<'==battleTown[a][b]){
            for(int i = b-1; i >= 0; i--){


                   
                     if(battleTown[a][b-1]=='*'){
                        battleTown[a][b-1]='.';


                        
                        return;
                     }else if(battleTown[a][b-1]=='#'){


                         
                        return;
                    }else{
                        b--;
                        if(b==0){
                            return;
                        }


                        
                    }
            }
        }
        if('>'==battleTown[a][b]){
            for(int i = b+1; i < w; i++){


                    
                     if(battleTown[a][b+1]=='*'){
                        battleTown[a][b+1]='.';


                        
                        return;
                     }else if(battleTown[a][b+1]=='#'){


                         
                        return;
                    }else{
                        b++;
                        if(b==w){
                            return;
                        }




                        
                    }
            }
        }
        }
    }
    
}


