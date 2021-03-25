#include <iostream>
#include<fstream>
#include<conio.h>
using namespace std;
struct di {
	int x;
	int y;
}d;
bool grand=true;
int pcount = 0;
class c {
protected:
	int**board;
	string n;
public:

	c() :board(0) {}
	c(int p1,string n1){
	  board=newfile(board);    // for new game
	}
	c(int p) {                      // for saved game
		board = file(board);
	}
	~c(){
	
	}
	c(char k) {}
	void out() {
		//5 for hook
		//4 for knights
		//3 for bishops
		//1 for kings
		//2 for queen
		//6 for pawn

		for(int i=7;i>=0;i--){
			cout<<endl;
			int j;
			for(int k=0;k<=13;k++){
			
			cout<<"___";
			}
			cout<<i;
			cout<<endl;
			for( j=7;j>=0;j--){
				if(board[i][j]==5){
				
				cout<<"| "<<"wR"<<" ";
				}
				else if(board[i][j]==-5){
				
				cout<<"| "<<"bR"<<" ";
				}
				else if(board[i][j]==-4){
				
				cout<<"| "<<"bN"<<" ";
				}
				else if(board[i][j]==4){
				
				cout<<"| "<<"wN"<<" ";
				}
				else if(board[i][j]==-3){
				
				cout<<"| "<<"bB"<<" ";
				}
				else if(board[i][j]==3){
				
				cout<<"| "<<"wB"<<" ";
				}
				else if(board[i][j]==-2){
				
				cout<<"| "<<"bQ"<<" ";
				}
			else if(board[i][j]==2){
				
				cout<<"| "<<"wQ"<<" ";
				}
			else if(board[i][j]==-1){
				
				cout<<"| "<<"bK"<<" ";
				}
			else if(board[i][j]==1){
				
				cout<<"| "<<"wK"<<" ";
				}
			else if(board[i][j]==-6){
				
				cout<<"| "<<"bP"<<" ";
				}
			else if(board[i][j]==6){
				
				cout<<"| "<<"wP"<<" ";
				}
			//cout<<"| "<<board[i][j]<<" ";
			else if(board[i][j]==0){
			
			    cout<<"| "<<"  "<<" ";
			}
			}
			
			cout<<"|";
		   	
		}
		cout<<endl;
		
		for(int j=0;j<=10;j++){
			
			cout<<"___";
			}
       	
		cout << endl;

		for (int j = 0;j <= 10;j++) {

			cout << "_____";
		}
		cout<<endl;
	}
	void empty(int**b) {

		cout << endl;
		cout << "Empty Postions:";
		for (int i = 0;i <= 7;i++) {

			for (int j = 0;j <= 7;j++) {

				if (b[i][j] == 0) {

					cout << "(" << i << "," << j << ")";
				}
			}

		}


	}
	void savefilecaller(){
	    savefile(board);
	}
	friend void savefile(int**b);
	friend int**file(int**b);
	friend int**newfile(int**b1);
};
void savefile(int**b2){
	remove("chess.txt");
    ofstream output;
	output.open("chess.txt");
	for (int i = 0;i <= 7;i = i + 7) {

		 output<<b2[0][i]<<" ";       // rooks white
	}
	output<<" ";
	for (int i = 1;i <= 6;i = i + 5) {
		output<<b2[0][i]<<" ";          //knights white
	}
	output<<" ";
    for (int i = 2;i <= 5;i = i + 3) {
		output<<b2[0][i]<<" ";		// bishops white
	}
	output<<" ";
	output<<b2[0][3]<<" ";                    // white king
	output<<b2[0][4]<<" ";                     //white queen
	for (int i = 0;i <= 7;i++) {
		output<<b2[1][i]<<" ";              // white pawns
	}
	output<<" ";

	for (int i = 0;i <= 7;i = i + 7) {
		output<<b2[7][i]<<" ";       // rooks black
	}
	output<<" ";
	for (int i = 1;i <= 6;i = i + 5) {
	 output<<b2[7][i]<<" ";          //black knight
	}
	output<<" ";
	for (int i = 2;i <= 5;i = i + 3) {
		output<<b2[7][i]<<" "; // bishops black
	}
	output<<" ";
	 output<<b2[7][3]<<" ";                    // black King
     output<<b2[7][4]<<" ";		                             //black Queen
	 for (int i = 0;i <= 7;i++) {

		output<<b2[6][i]<<" ";              // black pawns
	}
	 output<<" ";
	for (int i = 2;i <= 5;i = i + 1) {
		for (int j = 0;j <= 7;j++) {
			
			output<<b2[i][j]<<" ";
		}
	}


}
int**newfile(int**b1){
    b1=new int*[8];
	for (int i = 0;i<8;i++) {
		b1[i] = new int[8];
	}
	for (int i = 0;i <= 7;i = i + 7) {

		 b1[0][i]=5;;       // rooks white
	}
	for (int i = 1;i <= 6;i = i + 5) {
		b1[0][i]=4;          //knights white
	}
    for (int i = 2;i <= 5;i = i + 3) {
		b1[0][i]=3;		// bishops white
	}
	b1[0][3]=1;                    // white king
	b1[0][4]=2;                     //white queen
	for (int i = 0;i <= 7;i++) {
		b1[1][i]=6;              // white pawns
	}


	for (int i = 0;i <= 7;i = i + 7) {
		b1[7][i]=-5;       // rooks black
	}
	for (int i = 1;i <= 6;i = i + 5) {
	 b1[7][i]=-4;          //black knight
	}
	for (int i = 2;i <= 5;i = i + 3) {
		b1[7][i]=-3; // bishops black
	}
	 b1[7][3]=-1;                    // black King
     b1[7][4]=-2;		                             //black Queen
	 for (int i = 0;i <= 7;i++) {

		b1[6][i]=-6;              // black pawns
	}

	for (int i = 2;i <= 5;i = i + 1) {
		for (int j = 0;j <= 7;j++) {
			b1[i][j] = 0;
		}
	}
	return b1;
}
int**file(int**b) {
	ifstream   input;
	input.open("chess.txt");
	b = new int*[8];
	for (int i = 0;i<8;i++) {
		b[i] = new int[8];
	}
	for (int i = 0;i <= 7;i = i + 7) {

		input >> b[0][i];       // rooks white
	}
	for (int i = 1;i <= 6;i = i + 5) {
		input >> b[0][i];          //knights white
	}
	for (int i = 2;i <= 5;i = i + 3) {

		input >> b[0][i];		// bishops white
	}
	input >> b[0][3];                    // white queen
	input >> b[0][4];		                             //white king

	for (int i = 0;i <= 7;i++) {

		input >> b[1][i];              // white pawns
	}

	for (int i = 0;i <= 7;i = i + 7) {
		input >> b[7][i];       // rooks black
	}
	for (int i = 1;i <= 6;i = i + 5) {
		input >> b[7][i];          //black white
	}
	for (int i = 2;i <= 5;i = i + 3) {
		input >> b[7][i];	// bishops black
	}
	input >> b[7][3];                    // black queen
	input >> b[7][4];		                             //black king


	for (int i = 0;i <= 7;i++) {

		input >> b[6][i];              // black pawns
	}

	for (int i = 2;i <= 5;i = i + 1) {
		for (int j = 0;j <= 7;j++) {
			input>>b[i][j];
		}
	}

	return b;
}
class checkmate{

  
public:
	checkmate(){}
	~checkmate(){}
	int**checkmateblackpawn(int i,int j,int**t){
	     
	      t[i][j]=-6;
			  return t;
	
	
	} 

     int**checkmatewhitepawn(int i,int j,int**t){
	     
	      t[i][j]=+6;
			  return t;
	
	
	} 

	 int**checkmatewhitequeen(int i,int j,int**t1){
	           t1[i][j]=+2;
	              return t1;
	 }


	 int**whitepawnpromotionchecker(int i,int j,int**t){     
	                                                         //white pawn promotion 
	     cout<<"As white pawn have been reached at opponent ending line so it is being promoted"<<endl;
		 cout<<"To Promote it to Rook press   r"<<endl;
		 cout<<"To promote it to bishop press b"<<endl;
		 cout<<"To promote it to Knight press n"<<endl;
		 cout<<"To promote it to Queen Press  q"<<endl;
	   char p;
	   cin>>p;
	   if(p=='r'){
	      t[i][j]=5;
	   }
	   if(p=='n'){
	      t[i][j]=4;
	   
	   }
	   if(p=='b'){
	      t[i][j]=3;
	   
	   }
	   if(p=='q'){
	      t[i][j]=2;
	   
	   }
	   return t;
	 }
	 int**blackpawnpromotionchecker(int i,int j,int**t){     
	                                                         //black pawn promotion 
	     cout<<"As white pawn have been reached at opponent ending line so it is being promoted"<<endl;
		 cout<<"To Promote it to Rook press   r"<<endl;
		 cout<<"To promote it to bishop press b"<<endl;
		 cout<<"To promote it to Knight press n"<<endl;
		 cout<<"To promote it to Queen Press  q"<<endl;
	   char p;
	   cin>>p;
	   if(p=='r'){
	      t[i][j]=-5;
	   }
	   if(p=='n'){
	      t[i][j]=-4;
	   
	   }
	   if(p=='b'){
	      t[i][j]=-3;
	   
	   }
	   if(p=='q'){
	      t[i][j]=-2;
	   
	   }
	   return t;
	 }


};


class players :public checkmate,public c {
	int play;


public:
	~players(){
	
	cout<<"Destructor called"<<endl;
	}
	players(int p) :play(p), c(play) {
	}
	players(int p1,string n):play(p1),c(p1,n){}
	players() {
	}
	void plays() {
		out();
			 char sel;
		cout << "Enter E to end game" << endl;
		cout << "White Player Turn:" << endl;
		cout << "For Selecting Pawn Press 6:" << endl;
		cout << "For Selecting Hook  Press 5:" << endl;
		cout << "For Selecting Knight Press 4:" << endl;
		cout << "For Selecting Bishop Press 3:" << endl;
		cout << "For Selecting Queen Press 2;" << endl;
		cout << "For Selecting King Press 1:" << endl;
		sel = _getch();

		if (sel == '6') {
			wpawn(pcount);
		}
		pcount++;
		if(sel=='5'){
		  wrook();
		}
		if(sel=='1'){
		    wking();
		}
		if(sel=='3'){
		    wbis();
		}
			if(sel=='2'){
		    wqueen();
		}
			if(sel=='4'){
			    wknight();
			}
	}
	void wpawn(int pc){
	
	int wpcount=0;
	int checkpc=0;
		cout<<endl<<"White Pawns are present at positions:"<<endl;
		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
				if(board[i][j]==+6){
				cout<<"("<<i<<","<<j<<")";
				wpcount++;
				}
			}
		}
		cout<<endl;
		int**wpc=new int*[wpcount];
		for(int i=0;i<wpcount;i++){
		  wpc[i]=new int[2];
		}
		cout<<"Moveable White Pawns:"<<endl;
		int k=0;
		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
				if(board[i][j]==+6){
					if(board[i+1][j]==0){
					cout<<"("<<i<<","<<j<<")"<<" ";
					   wpc[k][0]=i;
					   wpc[k][1]=j;
					   k++;
					}

					if(board[i+1][j+1]<-1 && i!=7 && j!=7){
					
					/*cout<<"Positions to knockout Opponent piece"<<endl;
			
					cout<<"("<<i-1<<","<<j-1<<")";*/
		            checkpc++;
					}
					if (board[i+1][j-1]<-1  && i!=7 && j!=7)
					{
					//	cout<<"("<<i-1<<","<<j+1<<")";
		//			cout<<endl;
		            checkpc++;
					
					}

				}
			
			}
		}
		cout<<endl;
		di*bo=new di[checkpc]; // to store coordinates required to kockout opponent piece
		int x=0;
		cout<<endl;
		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
				if(board[i][j]==6){

					if(board[i+1][j+1]<-1 && i!=7 && j!=7){
				
						cout<<"Positions to knockout Opponent piece:";
			
					cout<<"("<<i+1<<","<<j+1<<")"<<" ";

						bo[x].x=i+1;
					bo[x].y=j+1;
				   x++;	
					}
					if(board[i+1][j-1]<-1 && i!=7 && j!=7 && j!=0){
						cout<<"("<<i+1<<","<<j-1<<")";
						bo[x].x=i+1;
					bo[x].y=j-1;
					x++;
					}}}}

		di bd[8];
		cout<<endl<<"Enter Coordinates from above mentioned movable postions:"<<endl;
		cout<<"X:";
		cin>>bd[0].x;
		cout<<endl<<"Y:";
		cin>>bd[0].y;
		bool check3=false;
		bool check4=false;
		bool check1=false;
		bool check2=false;
		int ground=1;
		//cout<<bpcount<<endl;
		for(int j=0;j<checkpc;j++)
		{
		
			if(bo[j].x==bd[0].x){
			  check3=true;
			}
			if(bo[j].y==bd[0].y){
			  check4=true;
			}

			if(check3==true && check4==true){
		
		     board=checkmatewhitepawn(bo[j].x,bo[j].y,board);  
			 ground=0;
		}

		}

			if(ground!=0){



					bool check1=false;
		bool check2=false;
		//cout<<bpcount<<endl;
		for(int j=0;j<wpcount;j++)
		{
		
			if(wpc[j][0]==bd[0].x){
			  check1=true;
			}
			if(wpc[j][1]==bd[0].y){//i love you 
			  check2=true;
			}

		}
		if(check1==false  || check2==false){
		  cout<<"Enter Correct Values. You have enter wrong coordinates:"<<endl;
		  cout<<"Enter Coordinates from above mentioned movable postions:"<<endl;
		cout<<"X:";
		cin>>bd[0].x;
		cout<<endl<<"Y:";
		cin>>bd[0].y;
		check1=false;
		check2=false;
		for(int j=0;j<wpcount;j++)
		{
		
			if(wpc[j][0]==bd[0].x){
			 
				check1=true;
			}
			if(wpc[j][1]==bd[0].y){
			  
				check2=true;
			}

		}
		}

		if(check1==false  || check2==false){
		  cout<<"Enter Correct Values. You have enter wrong coordinates:"<<endl;
		  cout<<"Enter Coordinates from above mentioned movable postions:"<<endl;
		cout<<"X:";
		cin>>bd[0].x;
		cout<<endl<<"Y:";
		cin>>bd[0].y;
		check1=false;
		check2=false;

		for(int j=0;j<wpcount;j++)
		{
		
			if(wpc[j][0]==bd[0].x){
			 
				check1=true;
			}
			if(wpc[j][1]==bd[0].y){
			  				  
				check2=true;
			}

		}
		}
			
		//cout<<bpcount<<endl;
		for(int j=0;j<wpcount;j++)
		{
		
			if(wpc[j][0]==bd[0].x){
			  check1=true;
			}
			if(wpc[j][1]==bd[0].y){
			  check2=true;
			}

		}
		if(check1==false  || check2==false){
		  cout<<"Enter Correct Values. You have enter wrong coordinates:"<<endl;
		  cout<<"Enter Coordinates from above mentioned movable postions:"<<endl;
		cout<<"X:";
		cin>>bd[0].x;
		cout<<endl<<"Y:";
		cin>>bd[0].y;
		check1=false;
		check2=false;
		for(int j=0;j<wpcount;j++)
		{
		
			if(wpc[j][0]==bd[0].x){
			 
				check1=true;
			}
			if(wpc[j][1]==bd[0].y){
			  
				check2=true;
			}

		}
		}


		if(check1==true && check2==true){
		
		board[bd[0].x+1][bd[0].y]=board[bd[0].x][bd[0].y];
		board[bd[0].x][bd[0].y]=0;
		 
		}
		}

    out();
	if(bd[0].x==7){                           //check whther pawn is promoted or not
	  cout<<"Your Pawn is being Promoted"<<endl;
	  board=whitepawnpromotionchecker(bd[0].x,bd[0].y,board);
	    out();
	}	         
	}
	
	void bplays(){
		cout<<endl;
	   cout<<"Black Player Turn"<<endl;
	   char select;
		cout << "Enter E to end game" << endl;
		//cout << "White Player Turn:" << endl;
		cout << "For Selecting Pawn Press 6:" << endl;
		cout << "For Selecting Hook  Press 5:" << endl;
		cout << "For Selecting Knight Press 4:" << endl;
		cout << "For Selecting Bishop Press 3:" << endl;
		cout << "For Selecting King Press 2;" << endl;
		cout << "For Selecting Queen Press 1:" << endl;
		//select = _getch();
		cin>>select;

		if(select=='6'){
	
		bpawn();
		}
		if(select=='2'){
		
		bqueen();
		}
	
		if(select=='5'){
		
		brook();
		}
		
		
	}

	void bpawn(){
		int bpcount=0;
		cout<<endl<<"Black Pawns are present at positions:"<<endl;
		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
				if(board[i][j]==-6){
				cout<<"("<<i<<","<<j<<")";
				bpcount++;
				}
			}
		}
		int**bpc=new int*[bpcount];
		for(int i=0;i<bpcount;i++){
		  bpc[i]=new int[2];
		}
		cout<<endl<<"Movable Black Pawns:"<<endl;
			int k=0;
	   int checkpc=0;   // for knocking out opponent piece;
		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
				if(board[i][j]==-6){
					if(board[i-1][j]==0  && i-1>=0){
					   cout<<"("<<i<<","<<j<<")"<<" ";
					   bpc[k][0]=i;
					   bpc[k][1]=j;
					   k++;
					}
					if(board[i-1][j-1]>1){
					
					/*cout<<"Positions to knockout Opponent piece"<<endl;
			
					cout<<"("<<i-1<<","<<j-1<<")";*/
		            checkpc++;
					}
					if (board[i-1][j+1]>1)
					{
					//	cout<<"("<<i-1<<","<<j+1<<")";
					cout<<endl;
		            checkpc++;
							}
				}
			
			}
		}
		cout<<endl;
		di*bo=new di[checkpc];
		int x=0;
		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
				if(board[i][j]==-6){
			
					if(board[i-1][j-1]>1){
				
						cout<<"Positions to knockout Opponent piece:"<<" ";
					cout<<"("<<i-1<<","<<j-1<<")"<<" ";

						bo[x].x=i-1;
					bo[x].y=j-1;
				   x++;	
					}
					if(board[i-1][j+1]>1){
						cout<<"("<<i-1<<","<<j+1<<")"<<" ";
						bo[x].x=i-1;
					bo[x].y=j+1;
					x++;
					}}}}

		cout<<endl;
		di bd[8];
		cout<<"Enter Coordinates from above mentioned movable postions:"<<endl;
		cout<<"X:";
		cin>>bd[0].x;
		cout<<endl<<"Y:";
		cin>>bd[0].y;
		bool check3=false;
		bool check4=false;
		bool check1=false;
		bool check2=false;
		int ground=1;
		//cout<<bpcount<<endl;
		for(int j=0;j<checkpc;j++)
		{
		
			if(bo[j].x==bd[0].x){
			  check3=true;
			}
			if(bo[j].y==bd[0].y){
			  check4=true;
			}

			if(check3==true && check4==true){
		
		     board=checkmateblackpawn(bo[j].x,bo[j].y,board);  
			 ground=0;
		}

		}
			if(ground!=0){

					bool check1=false;
		bool check2=false;
		//cout<<bpcount<<endl;
		for(int j=0;j<bpcount;j++)
		{
		
			if(bpc[j][0]==bd[0].x){
			  check1=true;
			}
			if(bpc[j][1]==bd[0].y){
			  check2=true;
			}

		}
		if(check1==false  || check2==false){
		  cout<<"Enter Correct Values. You have enter wrong coordinates:"<<endl;
		  cout<<"Enter Coordinates from above mentioned movable postions:"<<endl;
		cout<<"X:";
		cin>>bd[0].x;
		cout<<endl<<"Y:";
		cin>>bd[0].y;
		check1=false;
		check2=false;
		for(int j=0;j<bpcount;j++)
		{
		
			if(bpc[j][0]==bd[0].x){
			 
				check1=true;
			}
			if(bpc[j][1]==bd[0].y){
			  
				check2=true;
			}

		}
		}

		if(check1==false  || check2==false){
		  cout<<"Enter Correct Values. You have enter wrong coordinates:"<<endl;
		  cout<<"Enter Coordinates from above mentioned movable postions:"<<endl;
		cout<<"X:";
		cin>>bd[0].x;
		cout<<endl<<"Y:";
		cin>>bd[0].y;
		check1=false;
		check2=false;

		for(int j=0;j<bpcount;j++)
		{
		
			if(bpc[j][0]==bd[0].x){
			 
				check1=true;
			}
			if(bpc[j][1]==bd[0].y){
			  				  
				check2=true;
			}

		}
		}
			
		//cout<<bpcount<<endl;
		for(int j=0;j<bpcount;j++)
		{
		
			if(bpc[j][0]==bd[0].x){
			  check1=true;
			}
			if(bpc[j][1]==bd[0].y){
			  check2=true;
			}

		}
		if(check1==false  || check2==false){
		  cout<<"Enter Correct Values. You have enter wrong coordinates:"<<endl;
		  cout<<"Enter Coordinates from above mentioned movable postions:"<<endl;
		cout<<"X:";
		cin>>bd[0].x;
		cout<<endl<<"Y:";
		cin>>bd[0].y;
		check1=false;
		check2=false;
		for(int j=0;j<bpcount;j++)
		{
		
			if(bpc[j][0]==bd[0].x){
			 
				check1=true;
			}
			if(bpc[j][1]==bd[0].y){
			  
				check2=true;
			}

		}
		}


		if(check1==true && check2==true){
		
		board[bd[0].x-1][bd[0].y]=board[bd[0].x][bd[0].y];
		board[bd[0].x][bd[0].y]=0;
		 
		}
		}
    out();
	if(bd[0].x==7){
	 cout<<"Your Black Pawn is being Promoted"<<endl;
	 board=blackpawnpromotionchecker(bd[0].x,bd[0].y,board);
	  out();
	}
	}
	
	
	
void wbis(){
	int upright=0;
	   int upright2=0;
	   int upleft=0;
	   int upleft2=0;
	   int downright=0;
	   int downright2=0;
	   int downleft=0;
	   int downleft2=0;
	   int bw[2];
	   int bwy[2];
	   int k=0;
	   cout<<"black Bi**ops are present"<<endl;    
		   for(int i2=0;i2<=7;i2++){
			   for(int j=0;j<=7;j++){
				   if(board[i2][j]==+3){
				     bw[k]=i2;
					 bwy[k]=j;
					 k++;
				   cout<<"("<<i2<<","<<j<<")"<<" ";}
			   }}
            int x;
        int y;

     cout<<"Enter coordinates for Bishops:"<<endl;
     cout<<"X:";
       cin>>x;
               cout<<"Y:"<<endl;
             cin>>y;
			 
                      if(x==bw[0] && y==bwy[0]){
 
				    for(int a=0;a<=7;a++){
			   for(int j=bwy[0];j<=7;j++){
				  
                                     if(a<=6 && j<=1 ){
				    if( a<=6 && j<=1  && board[a+1][j-1]==0 || board[a+1][j-1]<-1){
				        
				      for(int t=a+1,t1=j-1;t<=6 && t1<=1   && board[t][t1]==0 || board[t][t1]<-1;t++,t1--){
                                                 upright++;

                                    }}}}}



                                  for(int i=bw[0];i<=7;i++){

                                  for(int j=bwy[0];j<=7;j++){
				  
                                     if(i<=6 && j<=1 ){
					  if(i<=6 && j<=6){
				   if(i<=6 && j<=6 && board[i+1][j+1]==0 || board[i+1][j+1]<-1){
				   
				  
                                       for(int t=i+1,t2=j+1;t<=6 && t2<=6 && board[t][t2]==0 || board[t][t2]<-1;t++,t2++){
                                                   upleft++;
                
                                                 }}}}}


                             for(int i=bw[0];i<=7;i++){

                                  for(int j=bwy[0];j<=7;j++){
				  
                                    
            				   if(i>=1 && j>=1){
				   if(i>=1 && j>=1 && board[i-1][j-1]==0   || board[i-1][j-1]<-1 ) 
				   {
				     
						   for(int t=i-1,t2=j-1-1;t>=1 && t2>=1 && board[t][t2]==0 || board[t][t2]<-1;i--,j--){
							   
							    downright++;
							   
						   
						  }}}}}


                                    
                             for(int i=bw[0];i<=7;i++){

                                  for(int j=bwy[0];j<=7;j++){
				
                              
				   if(i>=1 && j>=6){
				   if(  i>=1 && j<=6 && board[i-1][j+1]<-1 || board[i-1][j+1]==0 ) 
				   {
				     
					 
						   for(int t=i-1,t2=j+1+1;t<=1 && t2<=6 && board[t][t2]==0 || board[t][t2]<-1;t--,t2++){
							  
							    downleft++;
							    
							  
					}}}}}
	                                  
     	int**ur=new int*[upright];
		int**dr=new int*[downright];
		int**dl=new int*[downleft];
		int**ul=new int*[upleft];
		
		
			for(int i=0;i<upright;i++){
			
			ur[i]=new int[2];
			}
		
		for(int i=0;i<downright;i++){
			
			dr[i]=new int[2];
			
		}
		for(int i=0;i<upleft;i++){
			
			ul[i]=new int[2];
			
		}
		for(int i=0;i<downleft;i++){

			
			dl[i]=new int[2];
			}
		
				
		int k1=0;
		int k2=0;
		int k3=0;
		int k4=0;
		
	 //cout<<upright<<downleft<<upleft<<downleft<<endl;
	     

                       for(int i=bw[0];i<=7;i++){
			   for(int j=bwy[0];j<=7;j++){
				   if(board[bw[0]][bwy[0]]==3){ 
                                     if(i<=6 && j<=1 ){
				    if( j<=6  && i<=6 && j<=6  && board[i+1][j-1]==0 || board[i+1][j-1]<-1){
				        
				      for(int t=i+1,t1=j-1;t<=6 && t1<=1   && board[t][t1]==0 || board[t][t1]<-1;t++,t1--){
                                                 ur[k1][0]=t;
                                                 ur[k1][1]=t1;
                                                    k1++;
                                              cout<<"("<<ur[k1][0]<<","<<ur[k1][1]<<")"<<" ";
                                    }
					   
				   }
					  }}}}
            
    
					   for(int i=bw[0];i<=7;i++){

                                  for(int j=bwy[0];j<=7;j++){
				  if(board[bw[0]][bwy[0]]==3)
                                     if(i<=6 && j<=1 ){
					  if(i<=6 && j<=6){
				   if(i<=6 && j<=6 && board[i][j]==0 || board[i][j]<-1){
				   
				  
                                       for(int t=i+1,t2=j+1;t<=6 && t2<=6 && board[t][t2]==0 || board[t][t2]<-1;t++,t2++){
                                                   ul[k2][0]=t;
                                                    ul[k2][1]=t2;
                                                      k2++;
                                                      cout<<"("<<ur[k2][0]<<","<<ur[k2][1]<<")"<<" ";
                                                 }}}}}}


               for(int i=bw[0];i<=7;i++){

                                  for(int j=bwy[0];j<=7;j++){
				  if(board[bw[0]][bwy[0]]==3)
                                    
            				   if(i>=1 && j>=1){
				   if(i>=1 && j>=1 && i>=6 && j>=6  &&  board[i-1][j-1]==0   || board[i-1][j-1]<-1  ) 
				   {
				     
						   for(int t=i-1,t2=j-1-1;t>=1 && t2>=1 && board[t][t2]==0 || board[t][t2]<-1;i--,j--){
							   
							    dr[k3][0]=t;
                                                    dr[k3][1]=t2;
                                                      k3++;
                                                      cout<<"("<<dr[k3][0]<<","<<dr[k3][1]<<")"<<" ";
							   
						   
						  }}}}}}



                        for(int i=bw[0];i<=7;i++){

                                  for(int j=bwy[0];j<=7;j++){
				 if(board[bw[0]][bwy[0]]==3){
                              
				   if(i>=1 && j>=6){
				   if(  i>=1 && j<=6 && board[i-1][j+1]<-1 || board[i-1][j+1]==0 ) 
				   {
				     
					 
						   for(int t=i-1,t2=j+1+1;t<=1 && t2<=6 && board[t][t2]==0 || board[t][t2]<-1;t--,t2++){
							  
							    /*dl[k4][0]=t;
                                                    dl[k4][1]=t2;
                                                      k4++;
                                                      cout<<"("<<dl[k4][0]<<","<<dl[k4][1]<<")"<<" ";
							    
							  */
					}}}}}}


                   cout<<"Choose from above positions:"<<endl;
                   int x1;
                   int y1;
                board[bw[0]][bwy[0]]=0;
                board[x1][y1]=3;

  }// major check
 









}

	   void wqueen(){
	   int up=0;
	   int down=0;
	   int left=0;
	   int right=0;
	   int upright=0;
	   int downright=0;
	   int upleft=0;
	   int downleft=0;
		   for(int i=0; i<7;i++){
			   for(int j=0;j<7;j++){
			   if(board[i][j]==+2){
				   if(i<7 && j<7){
				   
					   if(board[i+1][j]==0){
						   for(int t=i+1; ;t++){
						   if(board[t][j]!=0){
						     break;
						   }
							   up++;
						  
						   if(board[t][j]<-1){
							   up++;
						      break;
						   }
						   
						   
						   }
					   
					   }
				   
				   }
			   }


			   }
		   }
	   

        int**u=new int*[2];
		for(int i=0;i<up;i++){
		u[i]=new int[2];
		}
		int k1=0;
		cout<<endl<<"Moveable Positions by Queen"<<endl;
		for(int i=0; i<=7;i++){
			   for(int j=0;j<=7;j++){
			   if(board[i][j]==+2){
				   if(i<7 && j<7){
				   
					   if(board[i+1][j]==0){
						   for(int t=i+1; ;t++){
						  // up++;
							   if(board[t][j]!=0){
						     break;
						   }
							   u[k1][0]=t;
							   u[k1][1]=j;
							   cout<<"("<<u[k1][0]<<","<<u[k1][1]<<")"<<" ";
						        
						   if(board[t][j]<-1){
							  cout<<"Knockout Position:";
							  cout<<"("<<u[k1][0]<<","<<u[k1][1]<<")"<<" "<<endl;
						      break;
						   }
						  k1++;
						   }}}}}}
		
		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==+2){
				
					if(i>0){
					
						if(board[i-1][j]==0 || board[i-1][j]){

							for(int t=i-1;;t--){
								if(t<0){ break;}
								if(board[t][j]!=0){
								    break;
								}
	
							   down++;
							   if(board[t][j]<-1){
							   break;
							   }}}}}}}

			int**d=new int*[2];
		for(int i=0;i<down;i++){
		d[i]=new int[2];
		}
		

		int k2=0;

                         		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==+2){
				
					if(i>0){
					
						if(board[i-1][j]==0 || board[i-1][j]){
							for(int t=i-1;;t--){
								if(t<0){break;}
								if(board[t][j]!=0){
								    break;
								}
							   d[k2][0]=t;
							   d[k2][1]=j;
							   cout<<"("<<d[k2][0]<<","<<d[k2][1]<<")"<<" ";
								if(board[t][j]<-1){
								   cout<<endl<<"Knockout postions:"<<" "<<"("<<d[k2][0]<<","<<d[k2][1]<<")"<<" ";
							   break;
							   }

						 
							   k2++;
							   
							
							
							}}}}}}

	         ///---------------------------------/////

                   cout<<endl<<"Moveable Positions by Queen"<<endl;

								for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==+2){
				
					if(i>=0 && j>=1){
					
						if(board[i][j-1]==0 || board[i][j-1]<-1){
							for(int t=j-1;;t--){
								if(board[i][t]!=0){
								    break;
								}
							   right++;
							   if(board[i][t]<-1){
							   break;
							   }}}}}}}

			int**r=new int*[2];
		for(int i=0;i<right;i++){
		r[i]=new int[2];
		}
		cout<<right;
		int k3=0;

                         		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==+2){
				
					if(i>=0 && j>=1){
					
						if(board[i][j-1]==0 || board[i][j-1]<-1){
							for(int t=j-1;;t--){
								if(board[i][t]!=0){
								    break;
								}
								r[k3][0]=i;
							   r[k3][1]=t;
							   cout<<"("<<r[k3][0]<<","<<r[k3][1]<<")"<<" ";
								if(board[t][j]<-1){
								   cout<<endl<<"Knockout postions:"<<" "<<"("<<r[k3][0]<<","<<r[k3][1]<<")"<<endl;
							   break;
							   }
								
						
							   k3++;
							   }}}}}}

                ///------------------------------------///


								cout<<endl<<"Moveable Positions by Queen"<<endl;
               		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==+2){
				
					if(i>=0 && j<=6){
					
						if(board[i][j+1]==0 || board[i][j+1]){
							for(int t=j+1;;t++){
								if(board[i][t]!=0){
								    break;
								}
							   left++;
							   if(board[i][t]<-1){
							   break;
							   }}}}}}}

			int**l=new int*[2];
		for(int i=0;i<left;i++){
		l[i]=new int[2];
		}
		int k4=0;

                         		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==+2){
				
					if(i>=0 && j<=6){
					
						if(board[i][j+1]==0 || board[i][j+1]){
							for(int t=j+1;;t++){
								if(board[i][t]!=0){
								    break;
								}
							   l[k4][0]=i;
							   l[k4][1]=t;
						 cout<<"("<<l[k4][0]<<","<<l[k4][1]<<")"<<" ";
							   
							   if(board[t][j]<-1){
								   cout<<endl<<"Knockout postions:"<<" "<<"("<<l[k4][0]<<","<<l[k4][1]<<")"<<" ";
							   break;
							   }
							k4++;
							}}}}}}
            

								////--------------------------------/////////

								cout<<endl<<"Moveable Positions by Queen"<<endl;

								for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==+2){
											if(i>=1 && j>=1){
											
												if(board[i-1][j-1]==0 || board[i-1][j-1]<-1){
												
												for(int t1=i-1,t2=j-1;;t1--,t2--){
													if(t1<0 || t2<0){
													  break;
													}
													else{
														if(board[t1][t2]!=0 && board[t1][t2]<-1){
														    downright++;
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]>-1){
														  break; 
														
														}
													    downright++;
													}
												}
												}
											
											}							
										
										}
									
									}
								
								}
								
		int**dr=new int*[2];
		for(int i=0;i<downright;i++){
		dr[i]=new int[2];
		}
		int k5=0;



		              for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==+2){
											if(i>=1 && j>=1){
											
												if(board[i-1][j-1]==0 || board[i-1][j-1]<-1){
												
												for(int t1=i-1,t2=j-1;;t1--,t2--){
													if(t1<0 || t2<0){
													  break;
													}
													else{

														dr[k5][0]=t1;
														dr[k5][1]=t2;
														cout<<"("<<dr[k5][0]<<","<<dr[k5][1]<<")"<<" ";
														if(board[t1][t2]!=0 && board[t1][t2]>-1){
														    
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]<-1){
	                                                      cout<<endl<<"Knockout Positions:"<<"("<<dr[k5][0]<<","<<dr[k5][1]<<")"<<" "<<endl;
															break; 
						
														}
													    


														
													        k5++;
																											}
												}
												}
											
											}							
										
										}
									
									}
								
								}


		/////---------------------////////////--------------///////////
    
					  cout<<endl<<"Moveable Positions by Queen"<<endl;


					  for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==+2){
											if(i>=1 && j<=6){
											
												if(board[i-1][j+1]==0 || board[i-1][j+1]<-1){
												
												for(int t1=i-1,t2=j+1;;t1--,t2++){
													if(t1<0 || t2>7){
													  break;
													}
													else{
														if(board[t1][t2]!=0 && board[t1][t2]<-1){
														    downleft++;
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]>-1){
														  break; 
														
														}
													    downleft++;
													}
												}
												}
											
											}							
										
										}
									
									}
								
								}
								
		int**dl=new int*[2];
		for(int i=0;i<downleft;i++){
		dl[i]=new int[2];
		}
		int k6=0;



		              for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==+2){
											if(i>=1 && j<=7 && j>=1){
											
												if(board[i-1][j+1]==0 || board[i-1][j+1]<-1){
												
												for(int t1=i-1,t2=j+1;;t1--,t2++){
													if(t1<0 || t2>7){
													  break;
													}
													else{

														dl[k6][0]=t1;
                                                        dl[k6][1]=t2;
														cout<<"("<<dl[k6][0]<<","<<dl[k6][1]<<")"<<" ";

														if(board[t1][t2]!=0 && board[t1][t2]>-1){
														         
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]<-1){
	                                                      cout<<endl<<"Knockout Positions:"<<"("<<dl[k6][0]<<","<<dl[k6][1]<<")"<<" "<<endl;
															break; 
						
														}

																											        k6++;
														
													}
												}
												}
											
											}							
										
										}
									
									}
								
								}



                       /////---------------------////////
                

					  cout<<endl<<"Moveable Positions by Queen"<<endl;

					  for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==+2){
											if(i<=6 && j<=6){
											
												if(board[i+1][j+1]==0 || board[i+1][j+1]<-1){
												
												for(int t1=i+1,t2=j+1;;t1++,t2++){
													if(t1>7 || t2>7){
													  break;
													}
													else{
														
														 if(board[t1][t2]!=0 && board[t1][t2]>-1){
														  break; 
														
														}
													    upleft++;
													}
												}
												}
											
											}							
										
										}
									
									}
								
								}
								
		int**ul=new int*[2];
		for(int i=0;i<upleft;i++){
		ul[i]=new int[2];
		}
		int k7=0;
		//cout<<upleft<<endl;


		              for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==+2){
											if(i<=6 && j<=6){
											
												if(board[i+1][j+1]==0 || board[i+1][j+1]<-1){
												
												for(int t1=i+1,t2=j+1;;t1++,t2++){
													if(t1>7 || t2>7){
													  break;
													}
													else{
														if(board[t1][t2]!=0 && board[t1][t2]>-1){
														    
															break;
														}

														ul[k7][0]=t1;
														ul[k7][1]=t2;
														cout<<"("<<ul[k7][0]<<","<<ul[k7][1]<<")"<<" ";
														 if(board[t1][t2]!=0 && board[t1][t2]<-1){
	                                                      cout<<endl<<"Knockout Positions:"<<"("<<ul[k7][0]<<","<<ul[k7][1]<<")"<<" "<<endl;
															break; 
						
														}
														
													        k7++;
														}}}}}}}

					  ///----------------------------------------///


					  cout<<endl<<"Moveable Positions by Queen"<<endl;

					  for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==+2){
											if(i<=6 && j>=1){
											
												if(board[i+1][j-1]==0 || board[i+1][j-1]<-1){
												
												for(int t1=i+1,t2=j-1;;t1++,t2--){
													if(t1>7 || t2<0){
													  break;
													}
													else{
														if(board[t1][t2]!=0 && board[t1][t2]<-1){
														    upright++;
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]>-1){
														  break; 
														
														}
													    upright++;
													}
												}
												}
											
											}							
										
										}
									
									}
								
								}
								
		int**ur=new int*[2];
		for(int i=0;i<upright;i++){
		ur[i]=new int[2];
		}
		int k8=0;



		              for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==+2){
											if(i<=6 && j>=1){
											
												if(board[i+1][j-1]==0 || board[i+1][j-1]<-1){
												
												for(int t1=i+1,t2=j-1;;t1++,t2--){
													if(t1>7 || t2<0){
													  break;
													}
													else{

														ur[k8][0]=t1;
														ur[k8][1]=t2;
												if(board[t1][t2]!=0 && board[t1][t2]>-1){
														    
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]<-1){
	                                                      cout<<endl<<"Knockout Positions:"<<"("<<ur[k8][0]<<","<<ur[k8][1]<<")"<<" ";
															break; 
						
	                                 }
														cout<<"("<<ur[k8][0]<<","<<ur[k8][1]<<")"<<" ";
													        k8++;
}}}}}}}

					  //---///
					  cout<<endl;
					  bool check=false;
					  di pos;
					  
					  for(int i=0;i<=7;i++){
						  for(int j=0;j<=7;j++){
							  if(board[i][j]==+2){
							  cout<<"Position of Queen:"<<endl;
							  cout<<"("<<i<<","<<j<<")"<<endl;
							   pos.x=i;
							   pos.y=j;
							  if(i<7 && j<=7){
							  
								  if(board[i+1][j]==0 || board[i+1][j]<-1){
								     check=true;
								  }
							
							  }
								  if(i!=0 && j<=7){
								  
									  if(board[i-1][j]==0  || board[i-1][j]<-1){
									  check=true;
									  }
								      
								  }
								  if(j>=1 && i<=7){
									  if(board[i][j-1]==0 || board[i][j-1]<-1){
									  check=true;
									  }
								  }
								    if(i<=7 && j<=6){
									  if(board[i][j+1]==0 || board[i][j+1]<-1){
									  check=true;
									  }
								  }
									if(i<=6 && j<=6){
										if(board[i+1][j+1]==0 || board[i+1][j+1]<-1){
										check=true;
										}
									}
									if(i<=6 && j<=1){
									
										if(board[i+1][j-1]==0 ||  board[i+1][j-1]<-1){
										 check=true;
										}
									}
									if(i>=1 && j<=6){
									
										if(board[i-1][j+1]==0 || board[i-1][j+1]<-1){
										  check=true;
										}
									}
									if(i>=1 && j<=1){
									
										if(board[i-1][j-1]==0 || board[i-1][j-1]<-1){
										  check=true;
										
										}
									}

							  }
						  }//end for loop
					  }

					  if(check==false){
					     cout<<endl;
					   cout<<"Queen can move in any number of empty boxes iny any Direction But no box is empty for movement. Choose another:"<<endl;
					     plays();
					  }
					  if(check==true){
					  di q;
					  cout<<"Enter Coordiantes from above mentioned movable positions:"<<endl;
					  cout<<"X:";
					  cin>>q.x;
					  cout<<endl<<"Y:";
					  cin>>q.y;
					  bool check1=false;
				
					  for(int i=0;i<k1;i++){
						 
						  if(u[i][0]==q.x && u[i][1]==q.y){
							    
						check1=true;  
						  }
						  if(check1==true){
						
						board=checkmatewhitequeen(q.x,q.y,board);
						board[pos.x][pos.y]=0;
						
						  }
					  }
					  check1=false;
					  for(int i=0;i<k2;i++){
						  if(d[i][0]==q.x && d[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);
						board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k3;i++){
						  if(r[i][0]==q.x && r[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);
						board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k4;i++){
						  if(l[i][0]==q.x && l[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);  
						  board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k5;i++){
						  if(dr[i][0]==q.x && dr[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);  
						  board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k6;i++){
						  if(dl[i][0]==q.x && dl[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);  
						  board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k7;i++){
						  if(ul[i][0]==q.x && ul[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);  
						  board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k8;i++){
						  if(ur[i][0]==q.x && ur[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);  
						  board[pos.x][pos.y]=0;
						  }
					  }

					  }///end of else if
                      
}
     void bqueen(){
	 
	 
	 
	  int up=0;
	   int down=0;
	   int left=0;
	   int right=0;
	   int upright=0;
	   int downright=0;
	   int upleft=0;
	   int downleft=0;
		   for(int i=0; i<7;i++){
			   for(int j=0;j<7;j++){
			   if(board[i][j]==-2){
				   if(i>=1 && j<=7){
				   
					   if(board[i-1][j]==0 || board[i-1][j]){
						   for(int t=i-1; ;t--){
						   if(board[t][j]!=0 || board[t][j]<-1){
						     break;
						   }
							   up++;
						  
						   if(board[t][j]>1){
							   up++;
						      break;
						   }
						   
						   
						   }
					   
					   }
				   
				   }
			   }


			   }
		   }
	   

        int**u=new int*[2];
		for(int i=0;i<up;i++){
		u[i]=new int[2];
		}
		int k1=0;
		cout<<endl<<"Moveable Positions by Queen"<<endl;
		for(int i=0; i<=7;i++){
			   for(int j=0;j<=7;j++){
			   if(board[i][j]==-2){
				   if(i>=1 && j<=7){
				   
					   if(board[i-1][j]==0 || board[i-1][j]>1){
						   for(int t=i-1; ;t--){
						  // up++;
							   if(board[t][j]!=0){
						     break;
						   }
							   u[k1][0]=t;
							   u[k1][1]=j;
							   cout<<"("<<u[k1][0]<<","<<u[k1][1]<<")"<<" ";
						        
						   if(board[t][j]>1){
							  cout<<"Knockout Position:";
							  cout<<"("<<u[k1][0]<<","<<u[k1][1]<<")"<<" "<<endl;
						      break;
						   }
						  k1++;
						   }}}}}}
		
		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==-2){
				
					if(i<=6){
					
						if(board[i+1][j]==0 || board[i+1][j]>1){

							for(int t=i+1;;t++){
								if(t>7){ break;}
								if(board[t][j]!=0){
								    break;
								}
	
							   down++;
							   if(board[t][j]<-1){
							   break;
							   }}}}}}}

			int**d=new int*[2];
		for(int i=0;i<down;i++){
		d[i]=new int[2];
		}
		

		int k2=0;

                         		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==-2){
				
					if(i<=0){
					
						if(board[i+1][j]==0 || board[i+1][j]>1){
							for(int t=i+1;;t++){
								if(t>7){break;}
								if(board[t][j]!=0){
								    break;
								}
							   d[k2][0]=t;
							   d[k2][1]=j;
							   cout<<"("<<d[k2][0]<<","<<d[k2][1]<<")"<<" ";
								if(board[t][j]>1){
								   cout<<endl<<"Knockout postions:"<<" "<<"("<<d[k2][0]<<","<<d[k2][1]<<")"<<" ";
							   break;
							   }

						 
							   k2++;
							   
							
							
							}}}}}}

	         ///---------------------------------/////

                   cout<<endl<<"Moveable Positions by Queen"<<endl;

								for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==-2){
				
					if(i<=7 && j<=6){
					
						if(board[i][j+1]==0 || board[i][j+1]>1){
							for(int t=j+1;;t++){
								if(board[i][t]!=0){
								    break;
								}
							   right++;
							   if(board[i][t]<-1){
							   break;
							   }}}}}}}

			int**r=new int*[2];
		for(int i=0;i<right;i++){
		r[i]=new int[2];
		}
		
		int k3=0;

                         		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==-2){
				
					if(i<=7 && j<=6){
					
						if(board[i][j+1]==0 || board[i][j+1]>1){
							for(int t=j+1;;t++){
								if(board[i][t]!=0){
								    break;
								}
								r[k3][0]=i;
							   r[k3][1]=t;
							   cout<<"("<<r[k3][0]<<","<<r[k3][1]<<")"<<" ";
								if(board[t][j]>1){
								   cout<<endl<<"Knockout postions:"<<" "<<"("<<r[k3][0]<<","<<r[k3][1]<<")"<<endl;
							   break;
							   }
								
						
							   k3++;
							   }}}}}}

                ///------------------------------------///


								cout<<endl<<"Moveable Positions by Queen"<<endl;
               		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==-2){
				
					if(i<=7 && j<=1){
					
						if(board[i][j-1]==0 || board[i][j-1]>1){
							for(int t=j-1;;t--){
								if(board[i][t]!=0){
								    break;
								}
							   left++;
							   if(board[i][t]<-1){
							   break;
							   }}}}}}}

			int**l=new int*[2];
		for(int i=0;i<left;i++){
		l[i]=new int[2];
		}
		int k4=0;

                         		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==-2){
				
					if(i<=7 && j>=1){
					
						if(board[i][j-1]==0 || board[i][j-1]>1){
							for(int t=j-1;;t--){
								if(board[i][t]!=0 && board[i][j-1]<-1){
								    break;
								}
							   l[k4][0]=i;
							   l[k4][1]=t;
						 cout<<"("<<l[k4][0]<<","<<l[k4][1]<<")"<<" ";
							   
							   if(board[t][j]>1){
								   cout<<endl<<"Knockout postions:"<<" "<<"("<<l[k4][0]<<","<<l[k4][1]<<")"<<" ";
							   break;
							   }
							k4++;
							}}}}}}
            

								////--------------------------------/////////

								cout<<endl<<"Moveable Positions by Queen"<<endl;

								for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==-2){
											if(i>=6 && j>=6){
											
												if(board[i+1][j+1]==0 || board[i+1][j+1]>1){
												
												for(int t1=i+1,t2=j+1;;t1++,t2++){
													if(t1>7 || t2>7){
													  break;
													}
													else{
														if(board[t1][t2]!=0 && board[t1][t2]>1){
														    downright++;
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]<-1){
														  break; 
														
														}
													    downright++;
													}
												}
												}
											
											}							
										
										}
									
									}
								
								}
								
		int**dr=new int*[2];
		for(int i=0;i<downright;i++){
		dr[i]=new int[2];
		}
		int k5=0;
		              for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==-2){
											if(i<=6 && j<=6){
											
												if(board[i+1][j+1]==0 || board[i+1][j+1]>1){
												
												for(int t1=i+1,t2=j+1;;t1++,t2++){
													if(t1>7 || t2>7){
													  break;
													}
													else{

														dr[k5][0]=t1;
														dr[k5][1]=t2;
														cout<<"("<<dr[k5][0]<<","<<dr[k5][1]<<")"<<" ";
														if(board[t1][t2]!=0 && board[t1][t2]<-1){
														    
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]>1){
	                                                      cout<<endl<<"Knockout Positions:"<<"("<<dr[k5][0]<<","<<dr[k5][1]<<")"<<" "<<endl;
															break; 
						
														}
													    
													        k5++;
																											}
												}
												}
											
											}							
										
										}
									
									}
								
								}


		/////---------------------////////////--------------///////////
    
					  cout<<endl<<"Moveable Positions by Queen"<<endl;


					  for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==-2){
											if(i<=6 && j<=6){
											
												if(board[i+1][j+1]==0 || board[i+1][j+1]>1){
												
												for(int t1=i+1,t2=j+1;;t1++,t2++){
													if(t1>7 || t2>7){
													  break;
													}
													else{
														if(board[t1][t2]!=0 && board[t1][t2]>1){
														    downleft++;
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]<-1){
														  break; 
														
														}
													    downleft++;
													}
												}
												}
											
											}							
										
										}
									
									}
								
								}
								
		int**dl=new int*[2];
		for(int i=0;i<downleft;i++){
		dl[i]=new int[2];
		}
		int k6=0;



		              for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==-2){
											if(i<=6 && j<=6 && i>=1){
											
												if(board[i+1][j+1]==0 || board[i+1][j+1]>1){
												
												for(int t1=i+1,t2=j-1;;t1++,t2--){
													if(t1>7 || t2<0){
													  break;
													}
													else{

														dl[k6][0]=t1;
                                                        dl[k6][1]=t2;
														cout<<"("<<dl[k6][0]<<","<<dl[k6][1]<<")"<<" ";

														if(board[t1][t2]!=0 && board[t1][t2]<-1){
														         
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]>1){
	                                                      cout<<endl<<"Knockout Positions:"<<"("<<dl[k6][0]<<","<<dl[k6][1]<<")"<<" "<<endl;
															break; 
						
														}

																											        k6++;
														
													}
												}
												}
											
											}							
										
										}
									
									}
								
								}



                       /////---------------------////////
                

					  cout<<endl<<"Moveable Positions by Queen"<<endl;

					  for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==-2){
											if(i>=1 && j>=1){
											
												if(board[i-1][j-1]==0 || board[i-1][j-1]>1){
												
												for(int t1=i-1,t2=j-1;;t1--,t2--){
													if(t1<0 || t2<0){
													  break;
													}
													else{
														
														 if(board[t1][t2]!=0 && board[t1][t2]<-1){
														  break; 
														
														}
													    upleft++;
													}
												}
												}
											
											}							
										
										}
									
									}
								
								}
								
		int**ul=new int*[2];
		for(int i=0;i<upleft;i++){
		ul[i]=new int[2];
		}
		int k7=0;
		//cout<<upleft<<endl;


		              for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==-2){
											if(i>=1 && j>=1){
											
												if(board[i-1][j-1]==0 || board[i-1][j-1]>1){
												
												for(int t1=i-1,t2=j-1;;t1--,t2--){
													if(t1<0 || t2<0){
													  break;
													}
													else{
														if(board[t1][t2]!=0 && board[t1][t2]<-1){
														    
															break;
														}

														ul[k7][0]=t1;
														ul[k7][1]=t2;
														cout<<"("<<ul[k7][0]<<","<<ul[k7][1]<<")"<<" ";
														 if(board[t1][t2]!=0 && board[t1][t2]>1){
	                                                      cout<<endl<<"Knockout Positions:"<<"("<<ul[k7][0]<<","<<ul[k7][1]<<")"<<" "<<endl;
															break; 
						
														}
														
													        k7++;
														}}}}}}}

					  ///----------------------------------------///


					  cout<<endl<<"Moveable Positions by Queen"<<endl;

					  for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==-2){
											if(i>=1 && j<=6){
											
												if(board[i-1][j+1]==0 || board[i-1][j+1]>1){
												
												for(int t1=i-1,t2=j+1;;t1--,t2++){
													if(t1<0 || t2>7){
													  break;
													}
													else{
														if(board[t1][t2]!=0 && board[t1][t2]>1){
														    upright++;
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]<-1){
														  break; 
														
														}
													    upright++;
													}
												}
												}
											
											}							
										
										}
									
									}
								
								}
								
		int**ur=new int*[2];
		for(int i=0;i<upright;i++){
		ur[i]=new int[2];
		}
		int k8=0;



		              for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==-2){
											if(i>=1 && j<=6){
											
												if(board[i-1][j+1]==0 || board[i-1][j+1]>1){
												
												for(int t1=i-1,t2=j+1;;t1--,t2++){
													if(t1<0 || t2>7){
													  break;
													}
													else{

														ur[k8][0]=t1;
														ur[k8][1]=t2;
												if(board[t1][t2]!=0 && board[t1][t2]<-1){
														    
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]>1){
	                                                      cout<<endl<<"Knockout Positions:"<<"("<<ur[k8][0]<<","<<ur[k8][1]<<")"<<" ";
															break; 
						
	                                 }
														cout<<"("<<ur[k8][0]<<","<<ur[k8][1]<<")"<<" ";
													        k8++;
}}}}}}}

					  //---///
					  cout<<endl;
					  bool check=false;
					  di pos;
					  
					  for(int i=0;i<=7;i++){
						  for(int j=0;j<=7;j++){
							  if(board[i][j]==-2){
							  cout<<"Position of Queen:"<<endl;
							  cout<<"("<<i<<","<<j<<")"<<endl;
							   pos.x=i;
							   pos.y=j;
							  if(i>=1 && j<=7){
							  
								  if(board[i-1][j]==0 || board[i-1][j]>1){
								     check=true;
								  }
							
							  }
								  if(i<=6 && j<=7){
								  
									  if(board[i+1][j]==0  || board[i+1][j]>1){
									  check=true;
									  }
								      
								  }
								  if(j>=1 && i<=7){
									  if(board[i][j-1]==0 || board[i][j-1]>1){
									  check=true;
									  }
								  }
								    if(i<=7 && j<=6){
									  if(board[i][j+1]==0 || board[i][j+1]>1){
									  check=true;
									  }
								  }
									if(i>=1 && j>=1){
										if(board[i-1][j-1]==0 || board[i-1][j-1]>1){
										check=true;
										}
									}
									if(i>=1 && j>=6){
									
										if(board[i-1][j+1]==0 ||  board[i-1][j+1]>1){
										 check=true;
										}
									}
									if(i<=6 && j>=1){
									
										if(board[i+1][j-1]==0 || board[i+1][j-1]>1){
										  check=true;
										}
									}
									if(i<=6 && j<=6){
									
										if(board[i+1][j+1]==0 || board[i+1][j+1]>1){
										  check=true;
										
										}
									}

							  }
						  }//end for loop
					  }

					  if(check==false){
					     cout<<endl;
					   cout<<"Queen can move in any number of empty boxes iny any Direction But no box is empty for movement. Choose another:"<<endl;
					     bplays();
					  }
					  if(check==true){
					  di q;
					  cout<<"Enter Coordiantes from above mentioned movable positions:"<<endl;
					  cout<<"X:";
					  cin>>q.x;
					  cout<<endl<<"Y:";
					  cin>>q.y;
					  bool check1=false;
				
					  for(int i=0;i<k1;i++){
						 
						  if(u[i][0]==q.x && u[i][1]==q.y){
							    
						check1=true;  
						  }
						  if(check1==true){
						
						board=checkmatewhitequeen(q.x,q.y,board);
						board[pos.x][pos.y]=0;
						
						  }
					  }
					  check1=false;
					  for(int i=0;i<k2;i++){
						  if(d[i][0]==q.x && d[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);
						board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k3;i++){
						  if(r[i][0]==q.x && r[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);
						board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k4;i++){
						  if(l[i][0]==q.x && l[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);  
						  board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k5;i++){
						  if(dr[i][0]==q.x && dr[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);  
						  board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k6;i++){
						  if(dl[i][0]==q.x && dl[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);  
						  board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k7;i++){
						  if(ul[i][0]==q.x && ul[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);  
						  board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k8;i++){
						  if(ur[i][0]==q.x && ur[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);  
						  board[pos.x][pos.y]=0;
						  }
					  }

					  }///end of else if
                       
	 }
	 
	  
	void wrook(){
	     di dh[2];       // for saving hook dimensions
	   int k=0;
	   int uphookcount=0,downhookcount=0,righthookcount=0,lefthookcount=0;
	   for(int i=0;i<=7;i++){
		   for(int j=0;j<=7;j++){
		   
			   if(board[i][j]==+5){
	                 cout<<"("<<i<<","<<j<<")"<<" ";		       
				   dh[k].x=i;
				   dh[k].y=j;
			    k++;     
			   }}}
	   cout<<"Select hooks from above two"<<endl;
	   int x;
	   cout<<"Enter X coordinate:"<<endl;
	   cin>>x;
	   cout<<"Enter Y coordinate:"<<endl;
	   int y;
	   cin>>y;
	   if(x==dh[0].x && y==dh[0].y){
	   if(dh[0].x+1<7){
	   if(board[dh[0].x+1][dh[0].y]==0 || board[dh[0].x+1][dh[0].y]<-1 ){      //uphook
	   
		   for(int i=dh[0].x+1;board[i][dh[0].y]<-1 ||board[i][dh[0].y]==0 && i<7;i++){
		      
		   uphookcount++;

		   }
	   }
		   }
	   if(dh[0].x-1>=1){
	    if(board[dh[0].x-1][dh[0].y]==0  && board[dh[0].x-1][dh[0].y]<-1){      //donwhook
	   
		   for(int i=dh[0].x-1;board[i][dh[0].y]<-1 || board[i][dh[0].y]==0 && i>=1;i--){
		      
		   downhookcount++;
		   }
		}
	   } 
	   if(dh[0].y+1<=6 ){
		   	    if(board[dh[0].x][dh[0].y+1]==0){      //lefthook
	   
		   for(int i=dh[0].y+1;board[dh[0].x][i]<-1 || board[dh[0].x][i]==0 && i<7;i++){ 
		      
		  lefthookcount++;
		   }	}
	   }
		
	   if(dh[0].y-1>=1){     // out of bound check
	   if(board[dh[0].x][dh[0].y-1]==0){      //righthook
	   
		   for(int j=dh[0].y-1;board[dh[0].x][j]<-1 || board[dh[0].x][j]==0 && j>=1;j--){ 
		      
		  righthookcount++;
		   }	}           

	   } 
	   
							
	   
	   
	   
	                        bool check=false;
							if(board[dh[0].x+1][dh[0].y]!=0  && board[dh[0].x][dh[0].y+1]!=0 && board[dh[0].x][dh[0].y+1]!=0){
								check=true;
									}
							if(dh[0].x!=0){
							 if(board[dh[0].x-1][dh[0].y]!=0 || board[dh[0].x-1][dh[0].y]>1) 
							 {
								 check=true;
							}
							}
							if (check==true){
							cout<<"This hook cannot move as it has not as space empty in stright line"<<endl;
									cout<<"Select Another or Select other hook if its free"<<endl;
									plays();
							
							}
	   


	   
	   int**upc= new int*[uphookcount];
	   for(int i=0;i<uphookcount;i++){
	        upc[i]=new int[2];
	   }
	   int**dch=new int*[downhookcount];
	   for(int i=0;i<downhookcount;i++){
	        dch[i]=new int[2];
	   }
	  int**rch=new int*[lefthookcount];
	  for(int i=0;i<lefthookcount;i++){
	        rch[i]=new int[2];
	   }
	  int**lch=new int*[righthookcount];
	   for(int i=0;i<righthookcount;i++){
	        lch[i]=new int[2];
	   }
	  //upc[1][2];
	   int k1=0;
	   int k2=0;
	   int k3=0;
	   int k4=0;
	   if(x==dh[0].x && y==dh[0].y){
		   
		   if(dh[0].x+1<=6){
			   if(uphookcount>0){
				   if(dh[0].x<=6 && board[dh[0].x+1][dh[0].y]==0 || board[dh[0].x+1][dh[0].y]<-1){      //uphook
	           //int k=0;
		   for(int i=dh[0].x+1;board[i][dh[0].y]<-1 || board[i][dh[0].y]==0 && i<=6;i++){
		       upc[k1][0]=i;              
		       upc[k1][1]=dh[0].y;
				   k1++;
		   }
	   }
			   }
		   }
	   if(dh[0].x-1<=1){
		   if(downhookcount>0){
	    if( dh[0].x>=1  && board[dh[0].x-1][dh[0].y]==0 || board[dh[0].x-1][dh[0].y]<-1){      //donwhook
	   
		   for(int i=dh[0].x-1;board[i][dh[0].y]<-1 || board[i][dh[0].y]==0 && i>=1;i--){
		      
		   dch[k2][0]=i;              
		       dch[k2][1]=dh[0].y;
				   k2++;
		   }
		}
		   }
	   } 
	   if(dh[0].y+1<=6){
		   if(lefthookcount>0){
		   	    if(dh[0].y<=6 && board[dh[0].x][dh[0].y+1]==0  ||board[dh[0].x][dh[0].y+1]<-1 ){      //lefthook
	       int k=0;
		   for(int i=dh[0].y+1;board[dh[0].x][dh[0].y+1]<-1 || board[dh[0].x][i]==0 && i<=6;i++){ 
		      
		      lch[k3][0]=dh[0].x;              
		       lch[k3][1]=i;
				   k3++;
		   }	}
	   }
	   }
	   if(dh[0].y-1>=1){     // out of bound check
		   if(righthookcount>0){
	   if(dh[0].y-1>=1 && board[dh[0].x][dh[0].y-1]==0 ||board[dh[0].x][dh[0].y-1]==0){      //righthook
	     int k=0;
		   for(int i=dh[0].y-1;board[dh[0].x][i]<-1 && board[dh[0].x][i]==0 && i<=1;i--){ 
		
			   
			   rch[k4][0]=dh[0].x;              
		       rch[k4][1]=i;
				   k4++;
		        
		  
		   }	}           

	   }
	   }
	   cout<<"Movable positions available:"<<endl;
	   for(int i=0;i<uphookcount;i++){
		    cout<<"(";
		   for(int j=0;j<2;j++){
		   
		  cout<<upc[i][j]<<",";
		   }
		   cout<<")";
	   }
	   for(int i=0;i<downhookcount;i++){
		   cout<<"(";
		   for(int j=0;j<2;j++){   
		   cout<<dch[i][j]<<",";
		   }
		   cout<<")";
	   }
	   for(int i=0;i<righthookcount;i++){
		   cout<<"(";
		   for(int j=0;j<2;j++){
		   
		   cout<<rch[i][j]<<",";
		   }
		   cout<<")";
	   }

	   for(int i=0;i<lefthookcount;i++){
		   cout<<"(";
		   for(int j=0;j<2;j++){
		   
		   cout<<lch[i][j]<<",";
		   }
		   cout<<")";
	   }
	   cout<<endl;
	
	   }


	   
	   cout<<"SELECT from Above Positions available"<<endl;
	   int x1;
	   cout<<"X:";
	   cin>>x1;
	   int y1;
	   cout<<"Y:";
	   cin>>y1;
	board[x1][y1]=-5;
	board[x][y]=0;
	   }

	   else if(x==dh[1].x && y==dh[1].y){
	   if(dh[1].x+1<7){
	   if(board[dh[1].x+1][dh[1].y]==0 || board[dh[1].x+1][dh[1].y]<-1 ){      //uphook
	   
		   for(int i=dh[1].x+1;board[i][dh[1].y]<-1 ||board[i][dh[1].y]==0 && i<=6;i++){
		      
		   uphookcount++;

		   }
	   }
		   }
	   if(dh[1].x-1>=1){
	    if(board[dh[1].x-1][dh[1].y]==0  && board[dh[1].x-1][dh[1].y]<-1){      //donwhook
	   
		   for(int i=dh[1].x-1;board[i][dh[1].y]<-1 || board[i][dh[1].y]==0 && i>=1;i--){
		      
		   downhookcount++;
		   }
		}
	   } 
	   if(dh[1].y+1<=6 ){
		   	    if(board[dh[1].x][dh[1].y+1]==0){      //lefthook
	   
		   for(int i=dh[1].y+1;board[dh[1].x][i]<-1 || board[dh[1].x][i]==0 && i<7;i++){ 
		      
		  lefthookcount++;
		   }	}
	   }
		
	   if(dh[1].y-1>=1){     // out of bound check
	   if(board[dh[1].x][dh[1].y-1]==0){      //righthook
	   
		   for(int j=dh[1].y-1;board[dh[1].x][j]<-1 || board[dh[1].x][j]==0 && j>=1;j--){ 
		      
		  righthookcount++;
		   }	}           

	   } 
	   
							
	   
	   
	   
		                    
		   
						 bool check=false;
							if(board[dh[1].x+1][dh[1].y]!=0  && board[dh[1].x][dh[1].y+1]!=0 && board[dh[1].x][dh[1].y+1]!=0){
								check=true;
									}
							if(dh[0].x!=0){
							 if(board[dh[0].x-1][dh[0].y]-=0 || board[dh[0].x-1][dh[0].y]<-1) 
							 {
								 check=true;
							}
							}
							if (check==true){
							cout<<"This hook cannot move as it has not as space empty in stright line"<<endl;
									cout<<"Select Another or Select other hook if its free"<<endl;
									plays();
							
							}
	    
	   


	   
	   int**upc= new int*[uphookcount];
	   for(int i=0;i<uphookcount;i++){
	        upc[i]=new int[2];
	   }
	   int**dch=new int*[downhookcount];
	   for(int i=0;i<downhookcount;i++){
	        dch[i]=new int[2];
	   }
	  int**rch=new int*[lefthookcount];
	  for(int i=0;i<lefthookcount;i++){
	        rch[i]=new int[2];
	   }
	  int**lch=new int*[righthookcount];
	   for(int i=0;i<righthookcount;i++){
	        lch[i]=new int[2];
	   }
	  //upc[1][2];
	   int k1=0;
	   int k2=0;
	   int k3=0;
	   int k4=0;
	   if(x==dh[1].x && y==dh[1].y){
		   
		   if(dh[1].x+1<=6){
			   if(uphookcount>0){
				   if(dh[1].x<=6 && board[dh[1].x+1][dh[0].y]==0 || board[dh[1].x+1][dh[1].y]<-1){      //uphook
	           //int k=0;
		   for(int i=dh[1].x+1;board[i][dh[1].y]<-1 || board[i][dh[1].y]==0 && i<=6;i++){
		       upc[k1][0]=i;              
		       upc[k1][1]=dh[0].y;
				   k1++;
		   }
	   }
			   }
		   }
	   if(dh[1].x-1<=1){
		   if(downhookcount>0){
	    if( dh[1].x>=1  && board[dh[1].x-1][dh[1].y]==0 || board[dh[1].x-1][dh[1].y]<-1){      //donwhook
	   
		   for(int i=dh[1].x-1;board[i][dh[1].y]<-1 || board[i][dh[0].y]==0 && i>=1;i--){
		      
		   dch[k2][0]=i;              
		       dch[k2][1]=dh[0].y;
				   k2++;
		   }
		}
		   }
	   } 
	   if(dh[1].y+1<=6){
		   if(lefthookcount>0){
		   	    if(dh[1].y<=6 && board[dh[1].x][dh[1].y+1]==0  ||board[dh[1].x][dh[1].y+1]<-1 ){      //lefthook
	       int k=0;
		   for(int i=dh[1].y+1;board[dh[1].x][dh[1].y+1]<-1 || board[dh[1].x][i]==0 && i<=6;i++){ 
		      
		      lch[k3][0]=dh[0].x;              
		       lch[k3][1]=i;
				   k3++;
		   }	}
	   }
	   }
	   if(dh[1].y-1>=1){     // out of bound check
		   if(righthookcount>0){
	   if(dh[1].y-1>=1 && board[dh[1].x][dh[1].y-1]==0 ||board[dh[1].x][dh[1].y-1]==0){      //righthook
	     int k=0;
		   for(int i=dh[1].y-1;board[dh[1].x][i]<-1 && board[dh[1].x][i]==0 && i<=1;i--){ 
		
			   
			   rch[k4][0]=dh[0].x;              
		       rch[k4][1]=i;
				   k4++;
		        
		  
		   }	}           

	   }
	   }
	   cout<<"Movable positions available:"<<endl;
	   for(int i=0;i<uphookcount;i++){
		    cout<<"(";
		   for(int j=0;j<2;j++){
		   
		  cout<<upc[i][j]<<",";
		   }
		   cout<<")";
	   }
	   for(int i=0;i<downhookcount;i++){
		   cout<<"(";
		   for(int j=0;j<2;j++){   
		   cout<<dch[i][j]<<",";
		   }
		   cout<<")";
	   }
	   for(int i=0;i<righthookcount;i++){
		   cout<<"(";
		   for(int j=0;j<2;j++){
		   
		  // cout<<rch[i][j]<<",";
		   }
		   cout<<")";
	   }

	   for(int i=0;i<lefthookcount;i++){
		   cout<<"(";
		   for(int j=0;j<2;j++){
		   
		   cout<<lch[i][j]<<",";
		   }
		   cout<<")";
	   }
	   cout<<endl;
	
	   }


	   
	   cout<<"SELECT from Above Positions available"<<endl;
	   int x1;
	   cout<<"X:";
	   cin>>x1;
	   int y1;
	   cout<<"Y:";
	   cin>>y1;
	board[x1][y1]=+5;
	board[x][y]=0;
	   }

	   }

	void brook(){
	
	
        di dh[2];       // for saving hook dimensions
	   int k=0;
	   int uphookcount=0,downhookcount=0,righthookcount=0,lefthookcount=0;
	   for(int i=0;i<=7;i++){
		   for(int j=0;j<=7;j++){
		   
			   if(board[i][j]==-5){
	                 cout<<"("<<i<<","<<j<<")"<<" ";		       
				   dh[k].x=i;
				   dh[k].y=j;
			    k++;     
			   }}}
	   cout<<"Select hooks from above two"<<endl;
	   int x;
	   cout<<"Enter X coordinate:"<<endl;
	   cin>>x;
	   cout<<"Enter Y coordinate:"<<endl;
	   int y;
	   cin>>y;
	  if(dh[0].x-1>=1){
	   if(board[dh[0].x-1][dh[0].y]==0 || board[dh[0].x-1][dh[0].y]>1 ){      //uphook
	   
		   for(int i=dh[0].x-1;board[i][dh[0].y]>-1 ||board[i][dh[0].y]==0 && i<7;i--){
		      
		   uphookcount++;

		   }
	   }
		   }
	   if(dh[0].x<=6){
	    if(board[dh[0].x+1][dh[0].y]==0  || board[dh[0].x+1][dh[0].y]<-1){      //donwhook
	   
		   for(int i=dh[0].x+1;board[i][dh[0].y]>-1 || board[i][dh[0].y]==0 && i>=1;i++){
		      
		   downhookcount++;
		   }
		}
	   } 
	   if(dh[0].y<=1){
		   	    if(board[dh[0].x][dh[0].y-1]==0 ||  board[dh[0].x][dh[0].y-1]<-1){      //lefthook
	   
		   for(int i=dh[0].y-1;board[dh[0].x][i]>-1 || board[dh[0].x][i]==0 && i>=1;i--){ 
		      
		  lefthookcount++;
		   }	}
	   }
		
	   if(dh[0].y+1<=6){     // out of bound check
	   if(board[dh[0].x][dh[0].y+1]==0 ||  board[dh[0].x][dh[0].y+1]<-1){      //righthook
	   
		   for(int j=dh[0].y+1;board[dh[0].x][j]>-1 || board[dh[0].x][j]==0 && j<=6;j++){ 
		      
		  righthookcount++;
		   }	}            


	   }                                        
	                                             bool check=false;
							if(board[dh[0].x-1][dh[0].y]!=0  && board[dh[0].x][dh[0].y-1]!=0 && board[dh[0].x][dh[0].y+1]){
								check=true;
									}
							if(dh[0].x!=7){
							 if(board[dh[0].x+1][dh[0].y]!=0 || board[dh[0].x+1][dh[0].y]>1) 
							 {
								 check=true;
							}
							}
							if (check==true){
							cout<<"This hook cannot move as it has not as space empty in stright line"<<endl;
									cout<<"Select Another or Select other hook if its free"<<endl;
									plays();
							
							}
	    
	 
	   
	   
	   int**upc= new int*[uphookcount];
	   for(int i=0;i<uphookcount;i++){
	        upc[i]=new int[2];
	   }
	   int**dch=new int*[downhookcount];
	   for(int i=0;i<downhookcount;i++){
	        dch[i]=new int[2];
	   }
	  int**rch=new int*[lefthookcount];
	  for(int i=0;i<lefthookcount;i++){
	        rch[i]=new int[2];
	   }
	  int**lch=new int*[righthookcount];
	   for(int i=0;i<righthookcount;i++){
	        lch[i]=new int[2];
	   }
	  
	   int k1=0;
	   int k2=0;
	   int k3=0;
	   int k4=0;
	   if(x==dh[0].x && y==dh[0].y){
		   
		   if(dh[0].x-1>=1){
			   if(uphookcount>0){
				   if(dh[0].x>=1 && board[dh[0].x-1][dh[0].y]==0 || board[dh[0].x-1][dh[0].y]>1){      //uphook
	           //int k=0;
		   for(int i=dh[0].x-1;board[i][dh[0].y]>1 || board[i][dh[0].y]==0 && i>=1;i--){
		       upc[k1][0]=i;              
		       upc[k1][1]=dh[0].y;
				   k1++;
		   }
	   }
			   }
		   }
	   if(dh[0].x+1<=6){
		   if(downhookcount>0){
	    if( dh[0].x<=6  && board[dh[0].x+1][dh[0].y]==0 || board[dh[0].x+1][dh[0].y]>1){      //donwhook
	   
		   for(int i=dh[0].x+1;board[i][dh[0].y]>1 || board[i][dh[0].y]==0 && i<=6;i++){
		      
		   dch[k2][0]=i;              
		       dch[k2][1]=dh[0].y;
				   k2++;
		   }
		}
		   }
	   } 
	   if(dh[0].y-1>=1){
		   if(lefthookcount>0){
		   	    if(dh[0].y>=1 && board[dh[0].x][dh[0].y-1]==0  ||board[dh[0].x][dh[0].y-1]>1 ){      //lefthook
	      
		   for(int i=dh[0].y-1;board[dh[0].x][i]>1 || board[dh[0].x][i]==0 && i>=1;i--){ 
		      
		      lch[k3][0]=dh[0].x;              
		       lch[k3][1]=i;
				   k3++;
		   }	}
	   }
	   }
	   if(dh[0].y+1<=6){     // out of bound check
		   if(righthookcount>0){
	   if(dh[0].y+1<=6 && board[dh[0].x][dh[0].y+1]==0 ||board[dh[0].x][dh[0].y+1]>1){      //righthook
	     
		   for(int i=dh[0].y+1;board[dh[0].x][i]>1 && board[dh[0].x][i]==0 && i>=6;i++){ 
		
			   
			   rch[k4][0]=dh[0].x;              
		       rch[k4][1]=i;
				   k4++;
		        
		  
		   }	}           

	   }
	   }
	   cout<<"Movable positions available:"<<endl;
	   for(int i=0;i<uphookcount;i++){
		    cout<<"(";
		   for(int j=0;j<2;j++){
		   
		  cout<<upc[i][j]<<",";
		   }
		   cout<<")";
	   }
	   for(int i=0;i<downhookcount;i++){
		   cout<<"(";
		   for(int j=0;j<2;j++){   
		   cout<<dch[i][j]<<",";
		   }
		   cout<<")";
	   }
	   for(int i=0;i<righthookcount;i++){
		   cout<<"(";
		   for(int j=0;j<2;j++){
		   
		   cout<<rch[i][j]<<",";
		   }
		   cout<<")";
	   }

	   for(int i=0;i<lefthookcount;i++){
		   cout<<"(";
		   for(int j=0;j<2;j++){
		   
		   cout<<lch[i][j]<<",";
		   }
		   cout<<")";
	   }
	   cout<<endl;
	   cout<<"SELECT from Above Positions available"<<endl;
	   int x1;
	   cout<<"X:";
	   cin>>x1;
	   int y1;
	   cout<<"Y:";
	   cin>>y1;
	board[x1][y1]=-5;
	board[x][y]=0;
	
  


	   }
	}
	void wknight(){
	
	  int up=0;
	  int left=0;
	  int right=0;
	  int down=0;
	  cout<<endl;
	  cout<<"White Knights are present at:"<<endl;
	  int k[2][2]; int ko=0;
	  for(int i=0;i<=7;i++){
		  for(int j=0;j<=7;j++){
			  if(board[i][j]==4){
			       cout<<"("<<i<<","<<j<<")"<<" ";
				   k[ko][0]=i;
				   k[ko][1]=j;
				   ko++;
			  }
		  
		  }
	  }
	  cout<<endl;
	  cout<<"Enter Coordinates of Knight you want to play with"<<endl;
	  int x;
	  int y;
	  cout<<"X:";
	  cin>>x;
	  cout<<"Y:";
	  cin>>y;
	  if(x==k[0][0] && y==k[0][1]){
	     int c=k[0][0];
		 int d=k[0][1];
		
		 bool check1=true;
		 bool check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(i<=6 && board[i][j]==4){
					
					 if(i+1<=7 && j>=2)
					 {
						 int l=i+1;
						 if(board[l][l-2]==0 || board[l][l-2]<-1 && l-2>=0){
						check1=false;
						check2=false;
						up++; 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}
		 check1=true;
		 check2=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 cout<<"J"<<j<<endl;
			 if(i<=5 && board[i][j]==4){
					
					 if(i+2<=7 && j>=2)
					 {
						 int l=i+2;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){
						check1=false;
						check2=false;
						up++; 
						 }
					  
					 }
			 
			 }
			 if(check1==false){break;}}if(check2==false){break;}}
		 
	   int**u=0;
		 if(up>0){
		   u=new int*[up];
		   int k1=0;
		   for(int i=0;i<=up;i++){
		     u[i]=new int[2];
		   }
		   int k=0;
		    for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				  if(i<=6 && board[i][j]==4){
					
					   if(i+1<=7 && j>=2)
					 {
						 int l=i+2;
						 
						 if(board[l][j-1]==0 || board[l][j-1]<-1 && j-1>=0){

						u[k][0]=l;
						u[k][1]=j-1;
					//	cout<<"L1"<<l<<j-1<<endl;
						cout<<"("<<u[k][0]<<","<<u[k][1]<<")"<<" ";
						k++;
						 }}}if(check1=false){break;}}   if(check2==false){break;}}



			for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					
					   if(i+2<=7 && j>=2)
					 {
						 int l=i+1;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){

						u[k][0]=l;
						u[k][1]=j-2;
					  // cout<<"L2"<<l<<j-2<<endl;
						cout<<"("<<u[k][0]<<","<<u[k][1]<<")"<<" ";
						k++;
						 }}}}}}
	  
		 up=0;
	  
	  bool check3=true;
		 bool check4=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 if(i<=6 && board[i][j]==4){
					
					 if(i+1<=7 && j>=2)
					 {
						 int l=i+1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=0){
						check3=false;
						check4=false;
						up++; 
						 }
					  
					 }}if(check3==false){break;}}   if(check4==false){break;}}
		 check3=true;
		 check4=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 
			 if(i<=5 && board[i][j]==4){
					
					 if(i+2<=7 && j>=2)
					 {
						 int l=i+2;
						 if(board[l][j+1]==0 || board[l][j+1]<-1 && j+1>=7){
						check3=false;
						check4=false;
						up++; 
						 }
					  
					 }
			 
			 }
			 if(check3==false){break;}}if(check4==false){break;}}
		 
	     int**u1=0;
		 if(up>0){
		   u1=new int*[up];
		   
		   for(int i=0;i<=up;i++){
		     u1[i]=new int[2];
		   }
		   int k2=0;
		    for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				  if(i<=6 && board[i][j]==4){
					
					   if(i+1<=7 && j>=2)
					 {
						 int l=i+1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=0){

						u1[k2][0]=l;
						u1[k2][1]=j+2;
					
						cout<<"("<<u[k2][0]<<","<<u[k2][1]<<")"<<" ";
						k2++;
						 }}}if(check1=false){break;}}   if(check2==false){break;}}
	  
	         
	           for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					
					   if(i+2<=7 && j>=2)
					 {
						 int l=i+2;
						 if(board[l][j+1]==0 || board[l][j+1]<-1 && j+1>=0){

						u1[k2][0]=l;
						u1[k2][1]=j+1;
					  //cout<<"L3"<<l<<j+1<<endl;
						cout<<"("<<u1[k2][0]<<","<<u1[k2][1]<<")"<<" "<<endl;
						k2++;
						 }}}}}}
	  
	  
	  /////////----------------------//////
	       
		  int right=0;
		     check1=true;
		     check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(j>=2 && board[i][j]==4){
					
					 if(j>=2 && i<=6)
					 {
						 int l=j-2;
						 if(board[i+1][l]==0 || board[i+1][l]<-1 && l>=0){
						check1=false;
						check2=false;
						right++; 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}
		 check1=true;
		 check2=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 //cout<<"J"<<j<<endl;
			 if(i<=1 && board[i][j]==4){
					
					 if(i>=1 && j>=2)
					 {
						 int l=j-2;
						 if(board[i-1][l]==0 || board[i-1][l]<-1 && j-2>=0){
						check1=false;
						check2=false;
						right++; 
						 }
					  
					 }
			 
			 }
			 if(check1==false){break;}}if(check2==false){break;}}
		 int**r=0;
		 	 if(right>0){
		   r=new int*[right];
		  
		   for(int i=0;i<right;i++){
		     r[i]=new int[2];
		   }
		   int r1=0;
		  check1=true;
		     check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(j>=2 && board[i][j]==4){
					
					 if(j>=2 && i<=6)
					 {
						 int l=j-2;
						 if(board[i+1][l]==0 || board[i+1][l]<-1 && l>=0){
						r[r1][0]=i+1;
						r[r1][1]=l;
						
						
						cout<<"("<<r[r1][0]<<","<<r[r1][1]<<")"<<" ";
						r1++;
						 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}

		   r1=0;

			for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					 if(i>=1 && j>=2)
					 {
						 int l=j-2;
						 if(board[i-1][l]==0 || board[i-1][l]<-1 && j-2>=0){

						r[r1][0]=i-1;
						r[r1][1]=l;
					   //cout<<"L2"<<l<<j-2<<endl;
						cout<<"("<<r[r1][0]<<","<<r[r1][1]<<")"<<" ";
						r1++;
						 }}}}}}


			 //////-------------//////////////----------------/////////////
	  
	               int left=0;
		     check1=true;
		     check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(j<=5 && board[i][j]==4){
					
					 if(j<=5 && i<=6)
					 {
						 int l=j+2;
						 if(board[i+1][l]==0 || board[i+1][l]<-1 && l<=7){
						check1=false;
						check2=false;
						left++; 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}
		 check1=true;
		 check2=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 //cout<<"J"<<j<<endl;
			 if(i<=1 && board[i][j]==4){
					
					 if(i>=1 && j<=5)
					 {
						 int l=j+2;
						 if(board[i-1][l]==0 || board[i-1][l]<-1 && j-2>=0){
						check1=false;
						check2=false;
						left++; 
						 }
					  
					 }
			 
			 }
			 if(check1==false){break;}}if(check2==false){break;}}
		 int**at=0;
		 	 if(left>0){
		   at=new int*[left];
		  
		   for(int i=0;i<=left;i++){
		     at[i]=new int[2];
		   }
		   int l1=0;

		  check1=true;
		     check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(j<=5 && board[i][j]==4){
					
					 if(j<=5 && i<=6)
					 {
						 int l=j+2;
						 if(board[i+1][l]==0 || board[i+1][l]<-1 && l>=0){
						at[l1][0]=i+1;
						at[l1][1]=l;
						
						
						cout<<"("<<at[l1][0]<<","<<at[l1][1]<<")"<<" ";
						l1++;
						 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}



			for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					 if(i>=1 && j<=5)
					 {
						 int l=j+2;
						 if(board[i-1][l]==0 || board[i-1][l]<-1 && j-2>=0){

						at[l1][0]=i-1;
						at[l1][1]=l;
					   //cout<<"L2"<<l<<j-2<<endl;
						cout<<"("<<at[l1][0]<<","<<at[l1][1]<<")"<<" ";
						l1++;
						 }}}}}}

			 ///////////--////    
			  check1=true;
   check2=true;
int down=0;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(i>=1 && board[i][j]==4){
					
					 if(i-1>=0 && j>=2)
					 {
						 int l=i-1;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){
						check1=false;
						check2=false;
						down++; 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}
		 check1=true;
		 check2=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				
			 if(i>=2 && board[i][j]==4){
					
					 if(i-2>=0 && j>=2)
					 {
						 int l=i-2;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){
						check1=false;
						check2=false;
						down++; 
						 }
					  
					 }
			 
			 }
			 if(check1==false){break;}}if(check2==false){break;}}
		 
	   int**d1=0;
		 if(down>0){
		   d1=new int*[down];
		   int k3=0;
		   for(int i=0;i<=down;i++){
		     d1[i]=new int[2];
		   }
		   int k=0;
		    for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				  if(i>=2 && board[i][j]==4){
					
					   if(i-2>=0 && j>=2)
					 {
						 int l=i-2;
						 
						 if(board[l][j-1]==0 || board[l][j-1]<-1 && j-1>=0){

						d1[k3][0]=l;
						d1[k3][1]=j-1;
					//	cout<<"L1"<<l<<j-1<<endl;
						cout<<"("<<d1[k3][0]<<","<<d1[k3][1]<<")"<<" ";
						k3++;
						 }}}if(check1=false){break;}}   if(check2==false){break;}}



			for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					
					   if(i-1>=6 && j>=2)
					 {
						 int l=i-1;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){

						d1[k3][0]=l;
						d1[k3][1]=j-2;
					  // cout<<"L2"<<l<<j-2<<endl;
						cout<<"("<<d1[k3][0]<<","<<d1[k3][1]<<")"<<" ";
						k3++;
						 }}}}}}
	  
		 down=0;
	  
	   check3=true;
		  check4=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 if(i>=1  && board[i][j]==4){
					
					 if(i-1>=0 && j>=2)
					 {
						 int l=i-1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=7){
						check3=false;
						check4=false;
						down++; 
						 }
					  
					 }}if(check3==false){break;}}   if(check4==false){break;}}
		 check3=true;
		 check4=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 
			 if(i>=2 && board[i][j]==4){
					
					 if(i-2<=0 && j>=2)
					 {
						 int l=i-2;
						 if(board[l][j+1]==0 || board[l][j+1]<-1 && j+1>=7){
						check3=false;
						check4=false;
						down++; 
						 }
					  
					 }
			 
			 }
			 if(check3==false){break;}}if(check4==false){break;}}
		 
	     int**down2=0;
		 if(down>0){
		   down2=new int*[down];
		   
		   for(int i=0;i<=down;i++){
		     down2[i]=new int[2];
		   }
		   int mn=0;
		    for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				  if(i>=1 && board[i][j]==4){
					
					   if(i-1>=0 && j>=2)
					 {
						 int l=i-1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=7){

						down2[mn][0]=l;
						down2[mn][1]=j+2;
					
						cout<<"("<<down2[mn][0]<<","<<down2[mn][1]<<")"<<" ";
						mn++;
						 }}}if(check1=false){break;}}   if(check2==false){break;}}
	  
	         
	           for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i>=2 && board[i][j]==4){
					
					   if(i-2<=7 && j>=2)
					 {
						 int l=i-2;
						 if(board[l][j+1]==0 || board[l][j+1]<-1 && j+1>=7){

						down2[mn][0]=l;
						down2[mn][1]=j+1;
					  //cout<<"L3"<<l<<j+1<<endl;
						cout<<"("<<down2[mn][0]<<","<<down2[mn][1]<<")"<<" "<<endl;
						mn++;
						 }}}}}}
	  

		 cout<<endl<<"Enter From Above Positions"<<endl;
		 int v;
		 int w;
		 cout<<"X:";
		 cin>>v;
		 cout<<endl<<"Y:";
		 cin>>w;
		 board[v][w]=+4;
		 board[x][y]=0;
         }
	  else if(x==k[1][0] && y==k[1][1]){
	  
	      int c=k[1][0];
		 int d=k[1][1];
		
		 bool check1=true;
		 bool check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(i<=6 && board[i][j]==4){
					
					 if(i+1<=7 && j>=2)
					 {
						 int l=i+1;
						 if(board[l][l-2]==0 || board[l][l-2]<-1 && l-2>=0){
						check1=false;
						check2=false;
						up++; 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}
		 check1=true;
		 check2=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 cout<<"J"<<j<<endl;
			 if(i<=5 && board[i][j]==4){
					
					 if(i+2<=7 && j>=2)
					 {
						 int l=i+2;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){
						check1=false;
						check2=false;
						up++; 
						 }
					  
					 }
			 
			 }
			 if(check1==false){break;}}if(check2==false){break;}}
		 
	   int**u=0;
		 if(up>0){
		   u=new int*[up];
		   int k1=0;
		   for(int i=0;i<=up;i++){
		     u[i]=new int[2];
		   }
		   int k=0;
		    for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				  if(i<=6 && board[i][j]==4){
					
					   if(i+1<=7 && j>=2)
					 {
						 int l=i+2;
						 
						 if(board[l][j-1]==0 || board[l][j-1]<-1 && j-1>=0){

						u[k][0]=l;
						u[k][1]=j-1;
					//	cout<<"L1"<<l<<j-1<<endl;
						cout<<"("<<u[k][0]<<","<<u[k][1]<<")"<<" ";
						k++;
						 }}}if(check1=false){break;}}   if(check2==false){break;}}



			for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					
					   if(i+2<=7 && j>=2)
					 {
						 int l=i+1;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){

						u[k][0]=l;
						u[k][1]=j-2;
					  // cout<<"L2"<<l<<j-2<<endl;
						cout<<"("<<u[k][0]<<","<<u[k][1]<<")"<<" ";
						k++;
						 }}}}}}
	  
		 up=0;
	  
	  bool check3=true;
		 bool check4=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 if(i<=6 && board[i][j]==4){
					
					 if(i+1<=7 && j>=2)
					 {
						 int l=i+1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=0){
						check3=false;
						check4=false;
						up++; 
						 }
					  
					 }}if(check3==false){break;}}   if(check4==false){break;}}
		 check3=true;
		 check4=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 
			 if(i<=5 && board[i][j]==4){
					
					 if(i+2<=7 && j>=2)
					 {
						 int l=i+2;
						 if(board[l][j+1]==0 || board[l][j+1]<-1 && j+1>=7){
						check3=false;
						check4=false;
						up++; 
						 }
					  
					 }
			 
			 }
			 if(check3==false){break;}}if(check4==false){break;}}
		 
	     int**u1=0;
		 if(up>0){
		   u1=new int*[up];
		   
		   for(int i=0;i<=up;i++){
		     u1[i]=new int[2];
		   }
		   int k2=0;
		    for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				  if(i<=6 && board[i][j]==4){
					
					   if(i+1<=7 && j>=2)
					 {
						 int l=i+1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=0){

						u1[k2][0]=l;
						u1[k2][1]=j+2;
					
						cout<<"("<<u[k2][0]<<","<<u[k2][1]<<")"<<" ";
						k2++;
						 }}}if(check1=false){break;}}   if(check2==false){break;}}
	  
	         
	           for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					
					   if(i+2<=7 && j>=2)
					 {
						 int l=i+2;
						 if(board[l][j+1]==0 || board[l][j+1]<-1 && j+1>=0){

						u1[k2][0]=l;
						u1[k2][1]=j+1;
					  //cout<<"L3"<<l<<j+1<<endl;
						cout<<"("<<u1[k2][0]<<","<<u1[k2][1]<<")"<<" "<<endl;
						k2++;
						 }}}}}}
	  
	  
	  /////////----------------------//////
	       
		  int right=0;
		     check1=true;
		     check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(j>=2 && board[i][j]==4){
					
					 if(j>=2 && i<=6)
					 {
						 int l=j-2;
						 if(board[i+1][l]==0 || board[i+1][l]<-1 && l>=0){
						check1=false;
						check2=false;
						right++; 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}
		 check1=true;
		 check2=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 //cout<<"J"<<j<<endl;
			 if(i<=1 && board[i][j]==4){
					
					 if(i>=1 && j>=2)
					 {
						 int l=j-2;
						 if(board[i-1][l]==0 || board[i-1][l]<-1 && j-2>=0){
						check1=false;
						check2=false;
						right++; 
						 }
					  
					 }
			 
			 }
			 if(check1==false){break;}}if(check2==false){break;}}
		 int**r=0;
		 	 if(right>0){
		   r=new int*[right];
		  
		   for(int i=0;i<right;i++){
		     r[i]=new int[2];
		   }
		   int r1=0;
		  check1=true;
		     check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(j>=2 && board[i][j]==4){
					
					 if(j>=2 && i<=6)
					 {
						 int l=j-2;
						 if(board[i+1][l]==0 || board[i+1][l]<-1 && l>=0){
						r[r1][0]=i+1;
						r[r1][1]=l;
						
						
						cout<<"("<<r[r1][0]<<","<<r[r1][1]<<")"<<" ";
						r1++;
						 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}

		   r1=0;

			for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					 if(i>=1 && j>=2)
					 {
						 int l=j-2;
						 if( j-2>=0 && board[i-1][l]==0 || board[i-1][l]<-1 ){

						r[r1][0]=i-1;
						r[r1][1]=l;
					   //cout<<"L2"<<l<<j-2<<endl;
						cout<<"("<<r[r1][0]<<","<<r[r1][1]<<")"<<" ";
						r1++;
						 }}}}}}


			 //////-------------//////////////----------------/////////////
	  
	               int left=0;
		     check1=true;
		     check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(j<=5 && board[i][j]==4){
					
					 if(j<=5 && i<=6)
					 {
						 int l=j+2;
						 if(board[i+1][l]==0 || board[i+1][l]<-1 && l<=7){
						check1=false;
						check2=false;
						left++; 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}
		 check1=true;
		 check2=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 //cout<<"J"<<j<<endl;
			 if(i<=1 && board[i][j]==4){
					
					 if(i>=1 && j<=5)
					 {
						 int l=j+2;
						 if(board[i-1][l]==0 || board[i-1][l]<-1 && j-2>=0){
						check1=false;
						check2=false;
						left++; 
						 }
					  
					 }
			 
			 }
			 if(check1==false){break;}}if(check2==false){break;}}
		 int**at=0;
		 	 if(left>0){
		   at=new int*[left];
		  
		   for(int i=0;i<=left;i++){
		     at[i]=new int[2];
		   }
		   int l1=0;

		  check1=true;
		     check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(j<=5 && board[i][j]==4){
					
					 if(j<=5 && i<=6)
					 {
						 int l=j+2;
						 if(board[i+1][l]==0 || board[i+1][l]<-1 && l>=0){
						at[l1][0]=i+1;
						at[l1][1]=l;
						
						
						cout<<"("<<at[l1][0]<<","<<at[l1][1]<<")"<<" ";
						l1++;
						 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}



			for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					 if(i>=1 && j<=5)
					 {
						 int l=j+2;
						 if(board[i-1][l]==0 || board[i-1][l]<-1 && j-2>=0){

						at[l1][0]=i-1;
						at[l1][1]=l;
					   //cout<<"L2"<<l<<j-2<<endl;
						cout<<"("<<at[l1][0]<<","<<at[l1][1]<<")"<<" ";
						l1++;
						 }}}}}}

			 ///////////--////    
			  check1=true;
   check2=true;
int down=0;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(i>=1 && board[i][j]==4){
					
					 if(i-1>=0 && j>=2)
					 {
						 int l=i-1;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){
						check1=false;
						check2=false;
						down++; 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}
		 check1=true;
		 check2=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				
			 if(i>=2 && board[i][j]==4){
					
					 if(i-2>=0 && j>=2)
					 {
						 int l=i-2;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){
						check1=false;
						check2=false;
						down++; 
						 }
					  
					 }
			 
			 }
			 if(check1==false){break;}}if(check2==false){break;}}
		 
	   int**d1=0;
		 if(down>0){
		   d1=new int*[down];
		   int k3=0;
		   for(int i=0;i<=down;i++){
		     d1[i]=new int[2];
		   }
		   int k=0;
		    for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				  if(i>=2 && board[i][j]==4){
					
					   if(i-2>=0 && j>=2)
					 {
						 int l=i-2;
						 
						 if(board[l][j-1]==0 || board[l][j-1]<-1 && j-1>=0){

						d1[k3][0]=l;
						d1[k3][1]=j-1;
					//	cout<<"L1"<<l<<j-1<<endl;
						cout<<"("<<d1[k3][0]<<","<<d1[k3][1]<<")"<<" ";
						k3++;
						 }}}if(check1=false){break;}}   if(check2==false){break;}}



			for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					
					   if(i-1>=6 && j>=2)
					 {
						 int l=i-1;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){

						d1[k3][0]=l;
						d1[k3][1]=j-2;
					  // cout<<"L2"<<l<<j-2<<endl;
						cout<<"("<<d1[k3][0]<<","<<d1[k3][1]<<")"<<" ";
						k3++;
						 }}}}}}
	  
		 down=0;
	  
	   check3=true;
		  check4=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 if(i>=1  && board[i][j]==4){
					
					 if(i-1>=0 && j>=2)
					 {
						 int l=i-1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=7){
						check3=false;
						check4=false;
						down++; 
						 }
					  
					 }}if(check3==false){break;}}   if(check4==false){break;}}
		 check3=true;
		 check4=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 
			 if(i>=2 && board[i][j]==4){
					
					 if(i-2<=0 && j>=2)
					 {
						 int l=i-2;
						 if(board[l][j+1]==0 || board[l][j+1]<-1 && j+1>=7){
						check3=false;
						check4=false;
						down++; 
						 }
					  
					 }
			 
			 }
			 if(check3==false){break;}}if(check4==false){break;}}
		 
	     int**down2=0;
		 if(down>0){
		   down2=new int*[down];
		   
		   for(int i=0;i<=down;i++){
		     down2[i]=new int[2];
		   }
		   int mn=0;
		    for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				  if(i>=1 && board[i][j]==4){
					
					   if(i-1>=0 && j>=2)
					 {
						 int l=i-1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=7){

						down2[mn][0]=l;
						down2[mn][1]=j+2;
					
						cout<<"("<<down2[mn][0]<<","<<down2[mn][1]<<")"<<" ";
						mn++;
						 }}}if(check1=false){break;}}   if(check2==false){break;}}
	  
	         
	           for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i>=2 && board[i][j]==4){
					
					   if(i-2<=7 && j>=2)
					 {
						 int l=i-2;
						 if(board[l][j+1]==0 || board[l][j+1]<-1 && j+1>=7){

						down2[mn][0]=l;
						down2[mn][1]=j+1;
					  //cout<<"L3"<<l<<j+1<<endl;
						cout<<"("<<down2[mn][0]<<","<<down2[mn][1]<<")"<<" "<<endl;
						mn++;
						 }}}}}}
	  

		 cout<<endl<<"Enter From Above Positions"<<endl;
		 int v;
		 int w;
		 cout<<"X:";
		 cin>>v;
		 cout<<endl<<"Y:";
		 cin>>w;
		 board[v][w]=+4;
		 board[x][y]=0;
	  
	  
	  }
	        

	}
	
	void wking(){
	   int up=0;
	   int down=0;
	   int left=0;
	   int right=0;
	   int upright=0;
	   int downright=0;
	   int upleft=0;
	   int downleft=0;
	   di k;
	   
	   for(int i=0;i<7;i++){
		   for(int j=0;j<7;j++){
			   if(board[i][j]==1){
			   
			     k.x=i;
				 k.y=j;
				 cout<<"KING can move in any direction just one step at a time"<<endl;
				 cout<<"KING IS present in Position:"<<"("<<k.x<<","<<k.y<<")"<<endl;
				 
			   }}}
	   bool final=true;
	   if(board[k.x+1][k.y]==0 || board[k.x+1][k.y]<-1){
	        bool check1=true;
			bool check2=true;
			bool check3=true;
			bool check4=true;
			
			if(k.x<=6 && board[k.x+1+1][k.y-1]==-6 ||  board[k.x+1+1][k.y+1]==-6){  // black pawn
			    check1=false;
			}
			else {
			  check1=true;
			}
			if(k.x<=6 && k.y<=6 && k.y>=1 && k.x>=1){ //rook
			
				for(int t=k.x+1; t<=7;t++){
					if(board[t][k.y]==-5){
					  check2=false;
					}
				}
				for(int t=k.y+1;t<=7;t++){
					if(board[k.x][t]==-5){
					  check2=false;
					}
				
				}
				for(int t=k.y-1;t>=1;t--){
					if(board[k.x][t]==-5){
					  check2=false;
					}
				} 
			}
			if(k.x<=6 && k.y<=6 && k.y>=1 && k.x>=1){        //bshop
			      
				for(int t1=k.x+1,t2=k.y-1; t1<=7 && t2>=1;t1++,t2--){
					if(board[t1][t2]==-3){
					  check2=false;
					}				
				} 
				for(int t1=k.x+1,t2=k.y+1; t1<=7 && t2<=7;t1++,t2++){
					if(board[t1][t2]==-3){
					  check2=false;
					}				
				} 
			   
			}
			if(k.x<=6 && k.y<=6 && k.y>=1 && k.x>=1){
			    for(int t=t+1; t<=7;t++){
					if(board[t][k.y]==-5){
					  check4=false;
					}
				}
				for(int t=t+1;t<=7;t++){
					if(board[k.x][t]==-5){
					  check4=false;
					}
				
				}
				for(int t=t-1;t>=1;t--){
					if(board[k.x][t]==-5){
					  check4=false;
					}
				} 
			

				for(int t1=k.x+1,t2=k.y-1; t1<=7 && t2>=1;t1++,t2--){
					if(board[t1][t2]==-3){
					  check4=false;
					}				
				} 
				for(int t1=k.x+1,t2=k.y+1; t1<=7 && t2<=7;t1++,t2++){
					if(board[t1][t2]==-3){
					  check4=false;
					}				
				} 

			}



			   if(check1==true && check2==true && check3==true && check4==true){
			     //cout<<"("<<k.x<<","<<k.y<<")"<<endl;
			   grand=true;
			   final=true;
			   }

			   else {
				   final=false;
			     cout<<"Checkmate Your King is under Attack Use other pieces aur replace Kings Position to save it from Attack"<<endl;
				 plays();
			   
			   }

	   }
	   bool final2=true;
	   if(k.x!=0){
	   if(k.x>=2 && board[k.x-1][k.y]==0 || board[k.x-1][k.y]<-1){
	        bool check1=true;
			bool check2=true;
			bool check3=true;
			bool check4=true;
			
			if(k.x>=1  && board[k.x-1-1][k.y-1]==-6 ||  board[k.x-1-1][k.y+1]==-6){  // black pawn
			    check1=false;
			}
			else {
			  check1=true;
			}
			if(k.x<=6 && k.y<=6 && k.y>=1 && k.x>=1){ //rook
			  if(k.x!=0){
				for(int t=k.y-1; t>=0;t--){
					if(board[t][k.y]==-5){
					  check2=false;
					}
				}
				for(int t=k.y+1;t<=7;t++){
					if(board[k.x][t]==-5){
					  check2=false;
					}
				
				}
				for(int t=k.x-1;t>=1;t--){
					if(board[k.x][t]==-5){
					  check2=false;
					}
				} }
			}
			if(k.x<=6 && k.y<=6 && k.y>=1 && k.x<=1){        //bshop
			      if(k.x!=0){
				for(int t1=k.x-1,t2=k.y-1; t1>=1 && t2>=1;t1--,t2--){
					if(board[t1][t2]==-3){
					  check3=false;
					}				
				} 
				for(int t1=k.x+1,t2=k.y-1; t1<=7 && t2>=1;t1++,t2--){
					if(board[t1][t2]==-3){
					  check3=false;
					}				
				} 
			   
				  }}
			if(k.x<=6 && k.y<=6 && k.y>=1 && k.x<=1){
			    for(int t=k.x+1; t<=7;t++){
					if(board[t][k.y]==-5){
					  check4=false;
					}
				}
				for(int t=k.x+1;t<=7;t++){
					if(board[k.x][t]==-5){
					  check4=false;
					}
				
				}
				if(k.x!=0){
				for(int t=k.y-1; t>=0;t--){
					if(board[t][k.y]==-5){
					  check4=false;
					}
				}
				for(int t=k.y+1;t<=7;t++){
					if(board[k.x][t]==-5){
					  check4=false;
					}
				
				}
				for(int t=k.x-1;t>=1;t--){
					if(board[k.x][t]==-5){
					  check4=false;
					}
				} }
				  if(k.x!=0){
				for(int t1=k.x-1,t2=k.y-1; t1>=1 && t2>=1;t1--,t2--){
					if(board[t1][t2]==-3){
					  check4=false;
					}				
				} 
				for(int t1=k.x+1,t2=k.y-1; t1<=7 && t2>=1;t1++,t2--){
					if(board[t1][t2]==-3){
					  check4=false;
					}				
				} 
			   
				  }

			}

			   if(check1==true && check2==true && check3==true && check4==true){
			     //cout<<"("<<k.x<<","<<k.y<<")"<<endl;
			   grand=true;
			   final2=true;
			   }

			   else {
				   grand=false;
				   final2=false;
			     cout<<"Checkmate Your King is under Attack Use other pieces aur replace Kings Position to save it from Attack"<<endl;
				 plays();
			   
			   }

	   }}

	   bool final3=true;
	   if(k.x>=1  && k.y>=1 && board[k.x][k.y+1]==0 || board[k.x][k.y+1]<-1)   // right
	   {      bool check1=true;
			bool check2=true;
			bool check3=true;
			bool check4=true;
	        
			
			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
				if(k.x>=2 && board[k.x+1][k.y-1]==-6 || board[k.x+1][k.y+1]==-6){
				     check1=false;
				}
			
			}
			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
				if(k.y<=6){
					for(int t1=k.x+1;t1<=7 ;t1++){
						if(board[t1][k.y]==-5){
						 check2=false;
						
						}
					} 
				}
				if(k.x<=6 && k.x>=1 && k.y<=6 && k.y>=1){
				
					for(int t1=k.y-1;t1<=1;t1--){
					   if(board[k.x][t1]==-5){
						 check2=false;
						
						}
					}
				
				}
			}
			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
			    
				for(int t1=k.x+1,t2=k.y-1;t1<=7 && t2>=0;t1++,t2--){
					if(board[t1][t2]==-5){
					  check3=false;
					}	
				
				}
			
			}
			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
			 
			     for(int t1=k.x-1,t2=k.y-1;t1>=0 && t2>=0;t1--,t2--){
					if(board[t1][t2]==-5){
					  check3=false;
					}	
				
				}
			}

			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
			 
			     for(int t1=k.x-1,t2=k.y+1;t1>=0 && t2<=7;t1--,t2++){
					if(board[t1][t2]==-5){
					  check3=false;
					}	
				
				}
			}
			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
			    if(k.x>=2 && board[k.x+1][k.y-1]==-6 || board[k.x+1][k.y+1]==-6){
				     check4=false;
				}
			
			if(k.y<=6){
					for(int t1=k.x+1;t1<=7 ;t1++){
						if(board[t1][k.y]==-5){
						 check4=false;
						
						}
					} 
					for(int t1=k.y-1;t1<=1;t1--){
					   if(board[k.x][t1]==-5){
						 check4=false;
						
						}
					}
			}
			     for(int t1=k.x-1,t2=k.y-1;t1>=0 && t2>=0;t1--,t2--){
					if(board[t1][t2]==-5){
					  check4=false;
					}	
				
				}	
			
		
			 for(int t1=k.x-1,t2=k.y+1;t1>=0 && t2<=7;t1--,t2++){
					if(board[t1][t2]==-5){
					  check3=false;
					}	
				
				}
			}
	        if(check1==true && check2==true && check3==true && check4==true){
			     //cout<<"("<<k.x<<","<<k.y<<")"<<endl;
			   grand=true;
			   final3=true;
			   
			}

			   else {
				   final3=false;
				   grand=false;
			     cout<<"Checkmate Your King is under Attack Use other pieces aur replace Kings Position to save it from Attack"<<endl;

				 plays();
			   
			   }
	   }

	    bool final4=true;
	   if(k.x>=1  && k.y>=1 && board[k.x][k.y-1]==0 || board[k.x][k.y-1]<-1)   // left
	   {      bool check1=true;
			bool check2=true;
			bool check3=true;
			bool check4=true;
	        
			
			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
				if(k.x>=2 && board[k.x+1][k.y-1]==-6 || board[k.x+1][k.y+1]==-6){
				     check1=false;
				}
			
			}
			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
				if(k.y<=6){
					for(int t1=k.x+1;t1<=7 ;t1++){
						if(board[t1][k.y]==-5){
						 check2=false;
						
						}
					} 
				}
				if(k.x<=6 && k.x>=1 && k.y<=6 && k.y>=1){
				
					for(int t1=k.y-1;t1<=1;t1--){
					   if(board[k.x][t1]==-5){
						 check2=false;
						
						}
					}
				
				}
			}
			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
			    
				for(int t1=k.x+1,t2=k.y-1;t1<=7 && t2>=0;t1++,t2--){
					if(board[t1][t2]==-5){
					  check3=false;
					}	
				
				}
			
			}
			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
			 
			     for(int t1=k.x-1,t2=k.y-1;t1>=0 && t2>=0;t1--,t2--){
					if(board[t1][t2]==-5){
					  check3=false;
					}	
				
				}
			}

			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
			 
			     for(int t1=k.x-1,t2=k.y+1;t1>=0 && t2<=7;t1--,t2++){
					if(board[t1][t2]==-5){
					  check3=false;
					}	
				
				}
			}
			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
			    if(k.x>=2 && board[k.x+1][k.y-1]==-6 || board[k.x+1][k.y+1]==-6){
				     check4=false;
				}
			
			if(k.y<=6){
					for(int t1=k.x+1;t1<=7 ;t1++){
						if(board[t1][k.y]==-5){
						 check4=false;
						
						}
					} 
					for(int t1=k.y-1;t1<=1;t1--){
					   if(board[k.x][t1]==-5){
						 check4=false;
						
						}
					}
			}
			     for(int t1=k.x-1,t2=k.y-1;t1>=0 && t2>=0;t1--,t2--){
					if(board[t1][t2]==-5){
					  check4=false;
					}	
				
				}	
			
		
			 for(int t1=k.x-1,t2=k.y+1;t1>=0 && t2<=7;t1--,t2++){
					if(board[t1][t2]==-5){
					  check3=false;
					}	
				
				}
			}
	        if(check1==true && check2==true && check3==true && check4==true){
			     //cout<<"("<<k.x<<","<<k.y<<")"<<endl;
			   grand=true;
			   final3=true;
			   
			}

			   else {
				   final3=false;
				   grand=false;
			     cout<<"Checkmate Your King is under Attack Use other pieces aur replace Kings Position to save it from Attack"<<endl;

				 plays();
			   
			   }
	   }
	   bool f=true;
	   if(board[k.x+1][k.y]!=0 || board[k.x+1][k.y]<1 && board[k.x][k.y+1]!=0 || board[k.x][k.y+1]<1 && board[k.x][k.y-1]!=0 || board[k.x][k.y-1]<1 && board[k.x-1][k.y-1]!=0 || board[k.x-1][k.y-1]<1 && board[k.x-1][k.y+1]!=0 || board[k.x-1][k.y+1]<1){
	      f=false;
	   } 
	   if(k.x>=1 && k.y>=1){
		   if(board[k.x-1][k.y]!=0 || board[k.x-1][k.y]<1 && board[k.x-1][k.y-1]!=0 || board[k.x-1][k.y-1]<1 && board[k.x-1][k.y+1]!=0 || board[k.x-1][k.y+1]<1){
		
			   f=false;
		   }   
		   else{
		   f=true;
		   }
	   }
	   if(f==false){
	     cout<<"King is not able to move due to lack of empty positions and attacking black pieces. Choose another piece"<<endl;
		 plays();
	   }
	   if(f==true){
	   cout<<"Positions Available:"<<endl;
	   
	   if(final==true){
	     cout<<"("<<k.x+1<<","<<k.y<<")"<<" ";
	   
	   }
	   
	   if(final2==true){
	     cout<<"("<<k.x-1<<","<<k.y<<")"<<" ";
	   
	   }
	   
	   if(final3==true){
	     cout<<"("<<k.x<<","<<k.y-1<<")"<<" ";
	   
	   }
	   
	   if(final4==true){
	     cout<<"("<<k.x<<","<<k.y+1<<")"<<" ";
	   
	   }
	   }
	   if(grand==false){
	   
	    cout<<"White have been checked..Black Player Won the game"<<endl;
		
	   }


 }
	   
	   
   void bking(){
         di k;
	   
	   for(int i=0;i<7;i++){
		   for(int j=0;j<7;j++){
			   if(board[i][j]==-1){
			   
			     k.x=i;
				 k.y=j;
				 cout<<"KING can move in any direction just one step at a time"<<endl;
				 cout<<"KING IS present in Position:"<<"("<<k.x<<","<<k.y<<")"<<endl;
				 
			   }}}
	   bool final=true;
	   if(board[k.x-1][k.y]==0 || board[k.x-1][k.y]>1){
	        bool check1=true;
			bool check2=true;
			bool check3=true;
			bool check4=true;
			
			if(k.x>=1 && board[k.x-1-1][k.y+1]==6 ||  board[k.x-1-1][k.y-1]==6){  // black pawn
			    check1=false;
			}
			else {
			  check1=true;
			}
			if(k.x<=6 && k.y<=6 && k.y>=1 && k.x>=1){ //rook
			
				for(int t=k.x-1; t>=0;t--){
					if(board[t][k.y]==5){
					  check2=false;
					}
				}
				if(k.y-1!=0){
				for(int t=k.y-1;t>=0;t--){
					if(board[k.x][t]==5){
					  check2=false;
					}
				}
				}
				if(k.y+1>=6){
				for(int t=k.y+1;t<=7;t++){
					if(board[k.x][t]==5){
					  check2=false;
					}
				}} 
			}
			if(k.x<=6 && k.y<=6 && k.y>=1 && k.x>=1){        //bshop
			      
				for(int t1=k.x-1,t2=k.y-1; t1>=1 && t2>=1;t1--,t2--){
					if(board[t1][t2]==3){
					  check3=false;
					}				
				} 
				for(int t1=k.x-1,t2=k.y+1; t1>=1 && t2<=7;t1--,t2++){
					if(board[t1][t2]==3){
					  check3=false;
					}				
				} 
			   
			}
			if(k.x<=6 && k.y<=6 && k.y>=1 && k.x>=1){
			   if(k.x>=1 && board[k.x-1-1][k.y+1]==6 ||  board[k.x-1-1][k.y-1]==6){  // black pawn
			    check4=false;
			}
			else {
			  check4=true;
			}
			if(k.x<=6 && k.y<=6 && k.y>=1 && k.x>=1){ //rook
			
				for(int t=k.x-1; t>=0;t--){
					if(board[t][k.y]==5){
					  check4=false;
					}
				}
				if(k.y-1!=0){
				for(int t=k.y-1;t>=0;t--){
					if(board[k.x][t]==5){
					  check4=false;
					}
				}
				}
				if(k.y+1>=6){
				for(int t=k.y+1;t<=7;t++){
					if(board[k.x][t]==5){
					  check4=false;
					}
				}} 
			}
			if(k.x<=6 && k.y<=6 && k.y>=1 && k.x>=1){        //bshop
			      
				for(int t1=k.x-1,t2=k.y-1; t1>=1 && t2>=1;t1--,t2--){
					if(board[t1][t2]==3){
					  check4=false;
					}				
				} 
				for(int t1=k.x-1,t2=k.y+1; t1>=1 && t2<=7;t1--,t2++){
					if(board[t1][t2]==3){
					  check4=false;
					}				
				} 
			
			
			}



			   if(check1==true && check2==true && check3==true && check4==true){
			     //cout<<"("<<k.x<<","<<k.y<<")"<<endl;
			   grand=true;
			   final=true;
			   }

			   else {
				   final=false;
			     cout<<"Checkmate Your King is under Attack Use other pieces aur replace Kings Position to save it from Attack"<<endl;
				 plays();
			   
			   }

	   }
	   bool final2=true;
	   if(k.x<=6 && board[k.x+1][k.y]==0 || board[k.x+1][k.y]<-1){
	        bool check1=true;
			bool check2=true;
			bool check3=true;
			bool check4=true;
			
			if(k.x<=5  && board[k.x+1+1][k.y-1]==6 ||  board[k.x+1+1][k.y+1]==6){  // black pawn
			    check1=false;
			}
			else {
			  check1=true;
			}
	   }
			if(k.x<=6 && k.y<=6 && k.y>=1 && k.x>=1){ //rook
			  if(k.x!=5){
				for(int t=k.x+1; t<=7;t++){
					if(board[t][k.y]==5){
					  check2=false;
					}
				}
				for(int t=k.y+1;t<=7;t++){
					if(board[k.x][t]==5){
					  check2=false;
					}
				
				}
				for(int t=k.x-1;t>=1;t--){
					if(board[k.x][t]==5){
					  check2=false;
					}
				} }
			}
			if(k.x<=6 && k.y<=6 && k.y>=1 && k.x<=1){        //bshop
			      if(k.x>=5){
				for(int t1=k.x+1,t2=k.y-1; t1<=7 && t2>=1;t1++,t2--){
					if(board[t1][t2]==3){
					  check3=false;
					}				
				 
				for(int t1=k.x+1,t2=k.y+1; t1<=7 && t2<=7;t1++,t2++){
					if(board[t1][t2]==-3){
					  check3=false;
					}				
				}
				}
			   
				  }}
			if(k.x<=6 && k.y<=6 && k.y>=1 && k.x<=1){
		              if(k.x<=5  && board[k.x+1+1][k.y-1]==6 ||  board[k.x+1+1][k.y+1]==6){  // black pawn
			    check4=false;
			}
			else {
			  check4=true;
			}
			if(k.x!=5){
				for(int t=k.x+1; t<=7;t++){
					if(board[t][k.y]==5){
					  check4=false;
					}
				}
				for(int t=k.y+1;t<=7;t++){
					if(board[k.x][t]==5){
					  check4=false;
					}
				
				}
				for(int t=k.x-1;t>=1;t--){
					if(board[k.x][t]==5){
					  check4=false;
					}
				} }
				  if(k.x>=5){
				for(int t1=k.x+1,t2=k.y-1; t1<=7 && t2>=1;t1++,t2--){
					if(board[t1][t2]==3){
					  check4=false;
					}				
				 
				for(int t1=k.x+1,t2=k.y+1; t1<=7 && t2<=7;t1++,t2++){
					if(board[t1][t2]==-3){
					  check4=false;
					}				
				}
				}
			   
				  }
				
				  }

			   if(check1==true && check2==true && check3==true && check4==true){
			     //cout<<"("<<k.x<<","<<k.y<<")"<<endl;
			   grand=true;
			   final2=true;
			   }

			   else {
				   grand=false;
				   final2=false;
			     cout<<"Checkmate Your King is under Attack Use other pieces aur replace Kings Position to save it from Attack"<<endl;
				 plays();
			   
			   }

	   }
 
	               bool final3=true;
	   if(k.x>=1  && k.y>=1 && board[k.x][k.y+1]==0 || board[k.x][k.y+1]<-1)   // right
	   {      bool check1=true;
			bool check2=true;
			bool check3=true;
			bool check4=true;
	        
			
			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
				if(k.x-1<=5 && board[k.x-1][k.y-1]==6 || board[k.x-1][k.y+1]==6){
				     check1=false;
				}
			
			}
			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
				if(k.y<=6){
					for(int t1=k.y+1;t1<=7 ;t1++){
						if(board[t1][k.y]==5){
						 check2=false;
						
						}
					} 
				}
				if(k.x<=6 && k.x>=1 && k.y<=6 && k.y>=1){
				
					for(int t1=k.y+1;t1>=7;t1++){
					   if(board[k.x][t1]==5){
						 check2=false;
						
						}
					}
				
				}
			}
			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
			     
				for(int t1=k.x+1,t2=k.y-1;t1<=7 && t2>=0;t1++,t2--){   // yahan se
					if(board[t1][t2]==5){
					  check3=false;
					}	
				
				}
			
			}
			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
			 
			     for(int t1=k.x-1,t2=k.y-1;t1>=0 && t2>=0;t1--,t2--){
					if(board[t1][t2]==-5){
					  check3=false;
					}	
				
				}
			}

			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
			 
			     for(int t1=k.x-1,t2=k.y+1;t1>=0 && t2<=7;t1--,t2++){
					if(board[t1][t2]==-5){
					  check3=false;
					}	
				
				}
			}
			if(k.y>=1 && k.x>=1 && k.x>=6 && k.y>=6){
			    if(k.x>=2 && board[k.x+1][k.y-1]==-6 || board[k.x+1][k.y+1]==-6){
				     check4=false;
				}
			
			if(k.y<=6){
					for(int t1=k.x+1;t1<=7 ;t1++){
						if(board[t1][k.y]==-5){
						 check4=false;
						
						}
					} 
					for(int t1=k.y-1;t1<=1;t1--){
					   if(board[k.x][t1]==-5){
						 check4=false;
						
						}
					}
			}
			     for(int t1=k.x-1,t2=k.y-1;t1>=0 && t2>=0;t1--,t2--){
					if(board[t1][t2]==-5){
					  check4=false;
					}	
				
				}	
			
		
			 for(int t1=k.x-1,t2=k.y+1;t1>=0 && t2<=7;t1--,t2++){
					if(board[t1][t2]==-5){
					  check3=false;
					}	
				
				}
			}
	        if(check1==true && check2==true && check3==true && check4==true){
			     //cout<<"("<<k.x<<","<<k.y<<")"<<endl;
			   grand=true;
			   final3=true;
			   
			}

			   else {
				   final3=false;
				   grand=false;
			     cout<<"Checkmate Your King is under Attack Use other pieces aur replace Kings Position to save it from Attack"<<endl;
				 plays();
			   
			   }
	   }

	    bool f=true;
	   if(board[k.x+1][k.y]!=0 || board[k.x+1][k.y]<1 && board[k.x][k.y+1]!=0 || board[k.x][k.y+1]<1 && board[k.x][k.y-1]!=0 || board[k.x][k.y-1]<1 && board[k.x-1][k.y-1]!=0 || board[k.x-1][k.y-1]<1 && board[k.x-1][k.y+1]!=0 || board[k.x-1][k.y+1]<1){
	      f=false;
	   } 
	   if(k.x>=1 && k.y>=1){
		   if(board[k.x-1][k.y]!=0 || board[k.x-1][k.y]<1 && board[k.x-1][k.y-1]!=0 || board[k.x-1][k.y-1]<1 && board[k.x-1][k.y+1]!=0 || board[k.x-1][k.y+1]<1){
		
			   f=false;
		   }   
		   else{
		   f=true;
		   }
	   }
	   if(f==false){
	     cout<<"King is not able to move due to lack of empty positions and attacking black pieces. Choose another piece"<<endl;
		 plays();
	   }
	   if(f==true){
	   cout<<"Positions Available:"<<endl;
	   
	   if(final==true){
	     cout<<"("<<k.x+1<<","<<k.y<<")"<<" ";
	   
	   }
	   
	 
	   
	   if(final3==true){
	     cout<<"("<<k.x<<","<<k.y-1<<")"<<" ";
	   
	   }
	   
	   
	   }
	   if(grand==false){
	   
	    cout<<"Black have been checked..White Player Won the game"<<endl;
		
	   }


    }    

	void bknight(){
	 int up=0;
	  int left=0;
	  int right=0;
	  int down=0;
	  cout<<endl;
	  cout<<"Black Knights are present at:"<<endl;
	  int k[2][2]; int ko=0;
	  for(int i=0;i<=7;i++){
		  for(int j=0;j<=7;j++){
			  if(board[i][j]==-4){
			       cout<<"("<<i<<","<<j<<")"<<" ";
				   k[ko][0]=i;
				   k[ko][1]=j;
				   ko++;
			  }
		  
		  }
	  }
	  cout<<endl;
	  cout<<"Enter Coordinates of Knight you want to play with"<<endl;
	  int x;
	  int y;
	  cout<<"X:";
	  cin>>x;
	  cout<<"Y:";
	  cin>>y;
	  if(x==k[0][0] && y==k[0][1]){
	     int c=k[0][0];
		 int d=k[0][1];
		
		 bool check1=true;
		 bool check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(i<=6 && board[i][j]==-4){
					
					 if(i-1>=0 && j>=2)
					 {
						 int l=i-1;
						 if(board[l][l-2]==0 || board[l][l-2]>1 && l-2>=0){
						check1=false;
						check2=false;
						up++; 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}
		 check1=true;
		 check2=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 
			 if(i>=2 && board[i][j]==-4){
					
					 if(i-2>=0 && j>=2)
					 {
						 int l=i-2;
						 if(board[l][j-2]==0 || board[l][j-2]>1 && j-2>=0){
						check1=false;
						check2=false;
						up++; 
						 }
					  
					 }
			 
			 }
			 if(check1==false){break;}}if(check2==false){break;}}
		 
	   int**u=0;
		 if(up>0){
		   u=new int*[up];
		   int k1=0;
		   for(int i=0;i<=up;i++){
		     u[i]=new int[2];
		   }
		   int k=0;
		    for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				  if(i<=6 && board[i][j]==-4){
					
					   if(i-1>=0 && j>=2)
					 {
						 int l=i-2;
						 
						 if(board[l][j-1]==0 || board[l][j-1]>1 && j-1>=0){

						u[k][0]=l;
						u[k][1]=j-1;
					//	cout<<"L1"<<l<<j-1<<endl;
						cout<<"("<<u[k][0]<<","<<u[k][1]<<")"<<" ";
						k++;
						 }}}if(check1=false){break;}}   if(check2==false){break;}}



			for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i>=2 && board[i][j]==-4){
					
					   if(i+2<=7 && j>=2)
					 {
						 int l=i+1;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){

						u[k][0]=l;
						u[k][1]=j-2;
					  // cout<<"L2"<<l<<j-2<<endl;
						cout<<"("<<u[k][0]<<","<<u[k][1]<<")"<<" ";
						k++;
						 }}}}}}
	  
		 up=0;
	  
	  bool check3=true;
		 bool check4=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 if(i<=6 && board[i][j]==4){
					
					 if(i+1<=7 && j>=2)
					 {
						 int l=i+1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=0){
						check3=false;
						check4=false;
						up++; 
						 }
					  
					 }}if(check3==false){break;}}   if(check4==false){break;}}
		 check3=true;
		 check4=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 
			 if(i<=5 && board[i][j]==-4){
					
					 if(i+2<=7 && j>=2)
					 {
						 int l=i+2;
						 if(board[l][j+1]==0 || board[l][j+1]<-1 && j+1>=7){
						check3=false;
						check4=false;
						up++; 
						 }
					  
					 }
			 
			 }
			 if(check3==false){break;}}if(check4==false){break;}}
		 
	     int**u1=0;
		 if(up>0){
		   u1=new int*[up];
		   
		   for(int i=0;i<=up;i++){
		     u1[i]=new int[2];
		   }
		   int k2=0;
		    for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				  if(i<=6 && board[i][j]==4){
					
					   if(i+1<=7 && j>=2)
					 {
						 int l=i+1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=0){

						u1[k2][0]=l;
						u1[k2][1]=j+2;
					
						cout<<"("<<u[k2][0]<<","<<u[k2][1]<<")"<<" ";
						k2++;
						 }}}if(check1=false){break;}}   if(check2==false){break;}}
	  
	         
	           for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					
					   if(i+2<=7 && j>=2)
					 {
						 int l=i+2;
						 if(board[l][j+1]==0 || board[l][j+1]<-1 && j+1>=0){

						u1[k2][0]=l;
						u1[k2][1]=j+1;
					  //cout<<"L3"<<l<<j+1<<endl;
						cout<<"("<<u1[k2][0]<<","<<u1[k2][1]<<")"<<" "<<endl;
						k2++;
						 }}}}}}
	  
	  
	  /////////----------------------//////
	       
		  int right=0;
		     check1=true;
		     check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(j>=2 && board[i][j]==-4){
					
					 if(j>=2 && i<=6)
					 {
						 int l=j-2;
						 if(board[i+1][l]==0 || board[i+1][l]>1 && l>=0){
						check1=false;
						check2=false;
						right++; 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}
		 check1=true;
		 check2=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 //cout<<"J"<<j<<endl;
			 if(i<=1 && board[i][j]==-4){
					
					 if(i>=1 && j>=2)
					 {
						 int l=j-2;
						 if(board[i-1][l]==0 || board[i-1][l]>1 && j-2>=0){
						check1=false;
						check2=false;
						right++; 
						 }
					  
					 }
			 
			 }
			 if(check1==false){break;}}if(check2==false){break;}}
		 int**r=0;
		 	 if(right>0){
		   r=new int*[right];
		  
		   for(int i=0;i<right;i++){
		     r[i]=new int[2];
		   }
		   int r1=0;
		  check1=true;
		     check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(j>=2 && board[i][j]==-4){
					
					 if(j>=2 && i<=6)
					 {
						 int l=j-2;
						 if(board[i+1][l]==0 || board[i+1][l]>1 && l>=0){
						r[r1][0]=i+1;
						r[r1][1]=l;
						
						
						cout<<"("<<r[r1][0]<<","<<r[r1][1]<<")"<<" ";
						r1++;
						 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}

		   r1=0;

			for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==-4){
					 if(i>=1 && j>=2)
					 {
						 int l=j-2;
						 if(board[i-1][l]==0 || board[i-1][l]>1 && j-2>=0){

						r[r1][0]=i-1;
						r[r1][1]=l;
					   //cout<<"L2"<<l<<j-2<<endl;
						cout<<"("<<r[r1][0]<<","<<r[r1][1]<<")"<<" ";
						r1++;
						 }}}}}}


			 //////-------------//////////////----------------/////////////
	  
	               int left=0;
		     check1=true;
		     check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(j<=5 && board[i][j]==-4){
					
					 if(j<=5 && i<=6)
					 {
						 int l=j+2;
						 if(board[i+1][l]==0 || board[i+1][l]>1 && l<=7){
						check1=false;
						check2=false;
						left++; 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}
		 check1=true;
		 check2=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 //cout<<"J"<<j<<endl;
			 if(i<=1 && board[i][j]==-4){
					
					 if(i>=1 && j<=5)
					 {
						 int l=j+2;
						 if(board[i-1][l]==0 || board[i-1][l]>1 && j-2>=0){
						check1=false;
						check2=false;
						left++; 
						 }
					  
					 }
			 
			 }
			 if(check1==false){break;}}if(check2==false){break;}}
		 int**at=0;
		 	 if(left>0){
		   at=new int*[left];
		  
		   for(int i=0;i<=left;i++){
		     at[i]=new int[2];
		   }
		   int l1=0;

		  check1=true;
		     check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(j<=5 && board[i][j]==-4){
					
					 if(j<=5 && i<=6)
					 {
						 int l=j+2;
						 if(board[i+1][l]==0 || board[i+1][l]>1 && l>=0){
						at[l1][0]=i+1;
						at[l1][1]=l;
						
						
						cout<<"("<<at[l1][0]<<","<<at[l1][1]<<")"<<" ";
						l1++;
						 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}



			for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==-4){
					 if(i>=1 && j<=5)
					 {
						 int l=j+2;
						 if(board[i-1][l]==0 || board[i-1][l]>1 && j-2>=0){

						at[l1][0]=i-1;
						at[l1][1]=l;
					   //cout<<"L2"<<l<<j-2<<endl;
						cout<<"("<<at[l1][0]<<","<<at[l1][1]<<")"<<" ";
						l1++;
						 }}}}}}

			 ///////////--////    
			  check1=true;
   check2=true;
int down=0;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(i<=6 && board[i][j]==-4){
					
					 if(i+1<=6 && j>=2)
					 {
						 int l=i+1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=0){
						check1=false;
						check2=false;
						down++; 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}
		 check1=true;
		 check2=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				
			 if(i=2 && board[i][j]==4){
					
					 if(i-2>=0 && j>=2)
					 {
						 int l=i-2;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){
						check1=false;
						check2=false;
						down++; 
						 }
					  
					 }
			 
			 }
			 if(check1==false){break;}}if(check2==false){break;}}
		 
	   int**d1=0;
		 if(down>0){
		   d1=new int*[down];
		   int k3=0;
		   for(int i=0;i<=down;i++){
		     d1[i]=new int[2];
		   }
		   int k=0;
		    for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				  if(i>=2 && board[i][j]==4){
					
					   if(i-2>=0 && j>=2)
					 {
						 int l=i-2;
						 
						 if(board[l][j-1]==0 || board[l][j-1]<-1 && j-1>=0){

						d1[k3][0]=l;
						d1[k3][1]=j-1;
					//	cout<<"L1"<<l<<j-1<<endl;
						cout<<"("<<d1[k3][0]<<","<<d1[k3][1]<<")"<<" ";
						k3++;
						 }}}if(check1=false){break;}}   if(check2==false){break;}}



			for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					
					   if(i-1>=6 && j>=2)
					 {
						 int l=i-1;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){

						d1[k3][0]=l;
						d1[k3][1]=j-2;
					  // cout<<"L2"<<l<<j-2<<endl;
						cout<<"("<<d1[k3][0]<<","<<d1[k3][1]<<")"<<" ";
						k3++;
						 }}}}}}
	  
		 down=0;
	  
	   check3=true;
		  check4=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 if(i>=1  && board[i][j]==4){
					
					 if(i-1>=0 && j>=2)
					 {
						 int l=i-1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=7){
						check3=false;
						check4=false;
						down++; 
						 }
					  
					 }}if(check3==false){break;}}   if(check4==false){break;}}
		 check3=true;
		 check4=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 
			 if(i>=2 && board[i][j]==4){
					
					 if(i-2<=0 && j>=2)
					 {
						 int l=i-2;
						 if(board[l][j+1]==0 || board[l][j+1]<-1 && j+1>=7){
						check3=false;
						check4=false;
						down++; 
						 }
					  
					 }
			 
			 }
			 if(check3==false){break;}}if(check4==false){break;}}
		 
	     int**down2=0;
		 if(down>0){
		   down2=new int*[down];
		   
		   for(int i=0;i<=down;i++){
		     down2[i]=new int[2];
		   }
		   int mn=0;
		    for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				  if(i>=1 && board[i][j]==4){
					
					   if(i-1>=0 && j>=2)
					 {
						 int l=i-1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=7){

						down2[mn][0]=l;
						down2[mn][1]=j+2;
					
						cout<<"("<<down2[mn][0]<<","<<down2[mn][1]<<")"<<" ";
						mn++;
						 }}}if(check1=false){break;}}   if(check2==false){break;}}
	  
	         
	           for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i>=2 && board[i][j]==4){
					
					   if(i-2<=7 && j>=2)
					 {
						 int l=i-2;
						 if(board[l][j+1]==0 || board[l][j+1]<-1 && j+1>=7){

						down2[mn][0]=l;
						down2[mn][1]=j+1;
					  //cout<<"L3"<<l<<j+1<<endl;
						cout<<"("<<down2[mn][0]<<","<<down2[mn][1]<<")"<<" "<<endl;
						mn++;
						 }}}}}}
	  

		 cout<<endl<<"Enter From Above Positions"<<endl;
		 int v;
		 int w;
		 cout<<"X:";
		 cin>>v;
		 cout<<endl<<"Y:";
		 cin>>w;
		 board[v][w]=+4;
		 board[x][y]=0;
         }
	  else if(x==k[1][0] && y==k[1][1]){
	  
	      int c=k[1][0];
		 int d=k[1][1];
		
		 bool check1=true;
		 bool check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(i<=6 && board[i][j]==4){
					
					 if(i+1<=7 && j>=2)
					 {
						 int l=i+1;
						 if(board[l][l-2]==0 || board[l][l-2]<-1 && l-2>=0){
						check1=false;
						check2=false;
						up++; 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}
		 check1=true;
		 check2=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 cout<<"J"<<j<<endl;
			 if(i<=5 && board[i][j]==4){
					
					 if(i+2<=7 && j>=2)
					 {
						 int l=i+2;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){
						check1=false;
						check2=false;
						up++; 
						 }
					  
					 }
			 
			 }
			 if(check1==false){break;}}if(check2==false){break;}}
		 
	   int**u=0;
		 if(up>0){
		   u=new int*[up];
		   int k1=0;
		   for(int i=0;i<=up;i++){
		     u[i]=new int[2];
		   }
		   int k=0;
		    for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				  if(i<=6 && board[i][j]==4){
					
					   if(i+1<=7 && j>=2)
					 {
						 int l=i+2;
						 
						 if(board[l][j-1]==0 || board[l][j-1]<-1 && j-1>=0){

						u[k][0]=l;
						u[k][1]=j-1;
					//	cout<<"L1"<<l<<j-1<<endl;
						cout<<"("<<u[k][0]<<","<<u[k][1]<<")"<<" ";
						k++;
						 }}}if(check1=false){break;}}   if(check2==false){break;}}



			for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					
					   if(i+2<=7 && j>=2)
					 {
						 int l=i+1;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){

						u[k][0]=l;
						u[k][1]=j-2;
					  // cout<<"L2"<<l<<j-2<<endl;
						cout<<"("<<u[k][0]<<","<<u[k][1]<<")"<<" ";
						k++;
						 }}}}}}
	  
		 up=0;
	  
	  bool check3=true;
		 bool check4=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 if(i<=6 && board[i][j]==4){
					
					 if(i+1<=7 && j>=2)
					 {
						 int l=i+1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=0){
						check3=false;
						check4=false;
						up++; 
						 }
					  
					 }}if(check3==false){break;}}   if(check4==false){break;}}
		 check3=true;
		 check4=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 
			 if(i<=5 && board[i][j]==4){
					
					 if(i+2<=7 && j>=2)
					 {
						 int l=i+2;
						 if(board[l][j+1]==0 || board[l][j+1]<-1 && j+1>=7){
						check3=false;
						check4=false;
						up++; 
						 }
					  
					 }
			 
			 }
			 if(check3==false){break;}}if(check4==false){break;}}
		 
	     int**u1=0;
		 if(up>0){
		   u1=new int*[up];
		   
		   for(int i=0;i<=up;i++){
		     u1[i]=new int[2];
		   }
		   int k2=0;
		    for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				  if(i<=6 && board[i][j]==4){
					
					   if(i+1<=7 && j>=2)
					 {
						 int l=i+1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=0){

						u1[k2][0]=l;
						u1[k2][1]=j+2;
					
						cout<<"("<<u[k2][0]<<","<<u[k2][1]<<")"<<" ";
						k2++;
						 }}}if(check1=false){break;}}   if(check2==false){break;}}
	  
	         
	           for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					
					   if(i+2<=7 && j>=2)
					 {
						 int l=i+2;
						 if(board[l][j+1]==0 || board[l][j+1]<-1 && j+1>=0){

						u1[k2][0]=l;
						u1[k2][1]=j+1;
					  //cout<<"L3"<<l<<j+1<<endl;
						cout<<"("<<u1[k2][0]<<","<<u1[k2][1]<<")"<<" "<<endl;
						k2++;
						 }}}}}}
	  
	  
	  /////////----------------------//////
	       
		  int right=0;
		     check1=true;
		     check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(j>=2 && board[i][j]==4){
					
					 if(j>=2 && i<=6)
					 {
						 int l=j-2;
						 if(board[i+1][l]==0 || board[i+1][l]<-1 && l>=0){
						check1=false;
						check2=false;
						right++; 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}
		 check1=true;
		 check2=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 //cout<<"J"<<j<<endl;
			 if(i<=1 && board[i][j]==4){
					
					 if(i>=1 && j>=2)
					 {
						 int l=j-2;
						 if(board[i-1][l]==0 || board[i-1][l]<-1 && j-2>=0){
						check1=false;
						check2=false;
						right++; 
						 }
					  
					 }
			 
			 }
			 if(check1==false){break;}}if(check2==false){break;}}
		 int**r=0;
		 	 if(right>0){
		   r=new int*[right];
		  
		   for(int i=0;i<right;i++){
		     r[i]=new int[2];
		   }
		   int r1=0;
		  check1=true;
		     check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(j>=2 && board[i][j]==4){
					
					 if(j>=2 && i<=6)
					 {
						 int l=j-2;
						 if(board[i+1][l]==0 || board[i+1][l]<-1 && l>=0){
						r[r1][0]=i+1;
						r[r1][1]=l;
						
						
						cout<<"("<<r[r1][0]<<","<<r[r1][1]<<")"<<" ";
						r1++;
						 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}

		   r1=0;

			for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					 if(i>=1 && j>=2)
					 {
						 int l=j-2;
						 if( j-2>=0 && board[i-1][l]==0 || board[i-1][l]<-1 ){

						r[r1][0]=i-1;
						r[r1][1]=l;
					   //cout<<"L2"<<l<<j-2<<endl;
						cout<<"("<<r[r1][0]<<","<<r[r1][1]<<")"<<" ";
						r1++;
						 }}}}}}


			 //////-------------//////////////----------------/////////////
	  
	               int left=0;
		     check1=true;
		     check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(j<=5 && board[i][j]==4){
					
					 if(j<=5 && i<=6)
					 {
						 int l=j+2;
						 if(board[i+1][l]==0 || board[i+1][l]<-1 && l<=7){
						check1=false;
						check2=false;
						left++; 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}
		 check1=true;
		 check2=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 //cout<<"J"<<j<<endl;
			 if(i<=1 && board[i][j]==4){
					
					 if(i>=1 && j<=5)
					 {
						 int l=j+2;
						 if(board[i-1][l]==0 || board[i-1][l]<-1 && j-2>=0){
						check1=false;
						check2=false;
						left++; 
						 }
					  
					 }
			 
			 }
			 if(check1==false){break;}}if(check2==false){break;}}
		 int**at=0;
		 	 if(left>0){
		   at=new int*[left];
		  
		   for(int i=0;i<=left;i++){
		     at[i]=new int[2];
		   }
		   int l1=0;

		  check1=true;
		     check2=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(j<=5 && board[i][j]==4){
					
					 if(j<=5 && i<=6)
					 {
						 int l=j+2;
						 if(board[i+1][l]==0 || board[i+1][l]<-1 && l>=0){
						at[l1][0]=i+1;
						at[l1][1]=l;
						
						
						cout<<"("<<at[l1][0]<<","<<at[l1][1]<<")"<<" ";
						l1++;
						 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}



			for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					 if(i>=1 && j<=5)
					 {
						 int l=j+2;
						 if(board[i-1][l]==0 || board[i-1][l]<-1 && j-2>=0){

						at[l1][0]=i-1;
						at[l1][1]=l;
					   //cout<<"L2"<<l<<j-2<<endl;
						cout<<"("<<at[l1][0]<<","<<at[l1][1]<<")"<<" ";
						l1++;
						 }}}}}}

			 ///////////--////    
			  check1=true;
   check2=true;
int down=0;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 
				 if(i>=1 && board[i][j]==4){
					
					 if(i-1>=0 && j>=2)
					 {
						 int l=i-1;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){
						check1=false;
						check2=false;
						down++; 
						 }
					  
					 }}if(check1==false){break;}}   if(check2==false){break;}}
		 check1=true;
		 check2=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				
			 if(i>=2 && board[i][j]==4){
					
					 if(i-2>=0 && j>=2)
					 {
						 int l=i-2;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){
						check1=false;
						check2=false;
						down++; 
						 }
					  
					 }
			 
			 }
			 if(check1==false){break;}}if(check2==false){break;}}
		 
	   int**d1=0;
		 if(down>0){
		   d1=new int*[down];
		   int k3=0;
		   for(int i=0;i<=down;i++){
		     d1[i]=new int[2];
		   }
		   int k=0;
		    for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				  if(i>=2 && board[i][j]==4){
					
					   if(i-2>=0 && j>=2)
					 {
						 int l=i-2;
						 
						 if(board[l][j-1]==0 || board[l][j-1]<-1 && j-1>=0){

						d1[k3][0]=l;
						d1[k3][1]=j-1;
					//	cout<<"L1"<<l<<j-1<<endl;
						cout<<"("<<d1[k3][0]<<","<<d1[k3][1]<<")"<<" ";
						k3++;
						 }}}if(check1=false){break;}}   if(check2==false){break;}}



			for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i<=6 && board[i][j]==4){
					
					   if(i-1>=6 && j>=2)
					 {
						 int l=i-1;
						 if(board[l][j-2]==0 || board[l][j-2]<-1 && j-2>=0){

						d1[k3][0]=l;
						d1[k3][1]=j-2;
					  // cout<<"L2"<<l<<j-2<<endl;
						cout<<"("<<d1[k3][0]<<","<<d1[k3][1]<<")"<<" ";
						k3++;
						 }}}}}}
	  
		 down=0;
	  
	   check3=true;
		  check4=true;
		 for(int i=c;i<=7;i++){
			 
			 for(int j=d;j<=7;j++){
				 if(i>=1  && board[i][j]==4){
					
					 if(i-1>=0 && j>=2)
					 {
						 int l=i-1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=7){
						check3=false;
						check4=false;
						down++; 
						 }
					  
					 }}if(check3==false){break;}}   if(check4==false){break;}}
		 check3=true;
		 check4=true;
		 for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				 
			 if(i>=2 && board[i][j]==4){
					
					 if(i-2<=0 && j>=2)
					 {
						 int l=i-2;
						 if(board[l][j+1]==0 || board[l][j+1]<-1 && j+1>=7){
						check3=false;
						check4=false;
						down++; 
						 }
					  
					 }
			 
			 }
			 if(check3==false){break;}}if(check4==false){break;}}
		 
	     int**down2=0;
		 if(down>0){
		   down2=new int*[down];
		   
		   for(int i=0;i<=down;i++){
		     down2[i]=new int[2];
		   }
		   int mn=0;
		    for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
				  if(i>=1 && board[i][j]==4){
					
					   if(i-1>=0 && j>=2)
					 {
						 int l=i-1;
						 if(board[l][j+2]==0 || board[l][j+2]<-1 && j+2>=7){

						down2[mn][0]=l;
						down2[mn][1]=j+2;
					
						cout<<"("<<down2[mn][0]<<","<<down2[mn][1]<<")"<<" ";
						mn++;
						 }}}if(check1=false){break;}}   if(check2==false){break;}}
	  
	         
	           for(int i=c;i<=7;i++){
			 for(int j=d;j<=7;j++){
					 
			    	  if(i>=2 && board[i][j]==4){
					
					   if(i-2<=7 && j>=2)
					 {
						 int l=i-2;
						 if(board[l][j+1]==0 || board[l][j+1]<-1 && j+1>=7){

						down2[mn][0]=l;
						down2[mn][1]=j+1;
					  //cout<<"L3"<<l<<j+1<<endl;
						cout<<"("<<down2[mn][0]<<","<<down2[mn][1]<<")"<<" "<<endl;
						mn++;
						 }}}}}}
	  

		 cout<<endl<<"Enter From Above Positions"<<endl;
		 int v;
		 int w;
		 cout<<"X:";
		 cin>>v;
		 cout<<endl<<"Y:";
		 cin>>w;
		 board[v][w]=+4;
		 board[x][y]=0;
	  
	  
	  }
	        

	
	
	}
	virtual void out() {
		//5 for hook
		//4 for knights
		//3 for bishops
		//1 for kings
		//2 for queen
		//6 for pawn

		for(int i=7;i>=0;i--){
			cout<<endl;
			int j;
			for(int k=0;k<=13;k++){
			
			cout<<"___";
			}
			cout<<i;
			cout<<endl;
			for( j=7;j>=0;j--){
				if(board[i][j]==5){
				
				cout<<"| "<<"wR"<<" ";
				}
				else if(board[i][j]==-5){
				
				cout<<"| "<<"bR"<<" ";
				}
				else if(board[i][j]==-4){
				
				cout<<"| "<<"bN"<<" ";
				}
				else if(board[i][j]==4){
				
				cout<<"| "<<"wN"<<" ";
				}
				else if(board[i][j]==-3){
				
				cout<<"| "<<"bB"<<" ";
				}
				else if(board[i][j]==3){
				
				cout<<"| "<<"wB"<<" ";
				}
				else if(board[i][j]==-2){
				
				cout<<"| "<<"bQ"<<" ";
				}
			else if(board[i][j]==2){
				
				cout<<"| "<<"wQ"<<" ";
				}
			else if(board[i][j]==-1){
				
				cout<<"| "<<"bK"<<" ";
				}
			else if(board[i][j]==1){
				
				cout<<"| "<<"wK"<<" ";
				}
			else if(board[i][j]==-6){
				
				cout<<"| "<<"bP"<<" ";
				}
			else if(board[i][j]==6){
				
				cout<<"| "<<"wP"<<" ";
				}
			//cout<<"| "<<board[i][j]<<" ";
			else if(board[i][j]==0){
			
			    cout<<"| "<<"  "<<" ";
			}
			}
			
			cout<<"|";
		   	
		}
		cout<<endl;
		
		for(int j=0;j<=10;j++){
			
			cout<<"___";
			}
       	
		cout << endl;

		for (int j = 0;j <= 10;j++) {

			cout << "_____";
		}
		cout<<endl;
	}
	
};
int main()
{
	cout << "\t" << "\t" << "                    Chess Game" << endl;
	cout << "Press 1 to Start new Game:" << endl;
	cout << "Press 2 to Reload Game:" << endl;
	cout << "Press e to end and Save Game:" << endl;
	char press;
	cin>>press;
	players s(1);
	if (press == '2') {
		while(press!='e'){
			cout<<"Press E to exit"<<endl;
		press=getch();
		if(press=='e'){
		cout<<endl<<"saving game"<<endl;
		s.savefilecaller();
			break;
		}
		
		
		s.plays();
		s.bplays();
		
		}

	}



	if (press == '1') {

		players s(1,"new");
		while(press!='e'){
			cout<<"Press E to exit"<<endl;
		press=getch();
		if(press=='e'){
		cout<<endl<<"saving game"<<endl;
		s.savefilecaller();
			break;
		}
		
		
		s.plays();
		s.bplays();
		
		}

	}
	system("pause");

	return 0;
}