#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void zwalnianie_pamieci(int ** busy)
{
	if(!busy) return;
	for (int i=0;busy[i];i++) delete [] busy[i];
	delete [] busy;
}

int ** przydziel_pamiec(int N, int M)
{
    int **A;
     if ((A=(int**)new int*[M+1])==NULL) return NULL;
     	for (int i=0;i<M;i++)
	 {
	 	if (!(A[i]=new int[N])) goto BLAD;
		for (int j=0;j<N;j++) A[i][j]=0;
		
	  }
    
     return A;
     BLAD: zwalnianie_pamieci(A);
     return NULL; 
}

void wyswietlanie(int **busy,int N,int M)
{
	for(int i=0;i<N;i++)
	{
		cout<<"Bus nr"<<i+1<<": ";
		cout<<endl;
		for(int j=0;j<M;j++)
		{
			cout<<"m"<<j+1<<":";
			cout<< busy[i][j]<<"  ";
		}
		cout<<endl;
	}
}

void rezerwacja(int N,int M,int **busy)
{
	int K,L;
	do
	{
	cout<<"Podaj nr busa"<<endl;
	K--;
	cin>>K;
	if(K>N || K<=0)
	{
	 cout<<"Nie ma takiego busa"<<endl;
	 Sleep(1000);
	system( "cls" );
	 continue;
	}
	K--;
	cout<<"Podaj miejsce ktore chcesz zarezerwowac"<<endl;
	cin>>L;
	if(L>M || L<=0)
	{
	 cout<<"Nie ma takiego miejsca w busie"<<endl;
	 L--;
	 Sleep(1000);
	system( "cls" );
	 continue;
	}
	L--;		
	
	if(busy[K][L]==1) 
	{
		cout<<endl<<"Miejsce juz zajete!"<<endl;
		Sleep(1000);
	}
	}
	while(K>N-1 || K<0 || L>M-1 || L<0);
	busy[K][L]=1;
}

void odwolanie(int N,int M,int **busy)
{
	
	int K,L;
	do
	{
		cout<<"Podaj nr busa"<<endl;
		cin>>K;
		if(K>N || K<=0)
		{
			cout<<"Nie ma takiego busa"<<endl;
			K--;
			Sleep(1000);
			system( "cls" );
			continue;
		}
		K--;
		cout<<"Podaj miejsce ktore chcesz zwolnic"<<endl;
		cin>>L;
		if(L>M || L<=0)
		{
			cout<<"Nie ma takiego miejsca w busie"<<endl;
			L--;
			Sleep(1000);
			system( "cls" );
			continue;
		}
		L--;
		if(*(*(busy+K)+L)==0) 
		{
			cout<<endl<<"Miejsce nie jest zajete!"<<endl;
			Sleep(1000);
		}
	}
	while(K>N-1 || K<0 || L>M-1 || L<0);
	*(*(busy+K)+L)=0;
		
}
	


int main()
{
	int **busy;
	int M,N;
	int wybor=0;
	do{
		cout<<"Podaj liczbe busow"<<endl;
		cin>>N;
		if(N<=0)
		{
		 	 cout<<"nie moze byc takiej ilosci busow"<<endl;
		  	Sleep(1000);
			system( "cls" );
		}
	} while(N<=0);
	do
	{
		cout<<"Podaj liczbe miejsc w busach"<<endl;
		cin>>M;
		if(M<=0)
		{
		  	cout<<"nie moze byc takiej ilosci miejsc"<<endl<<endl;
		}
	} while(M<=0);
	if ((busy=(int**)przydziel_pamiec(M, N))==NULL) exit(1);
 	cout << "Udalo sie zaalokowac pamiec\n";
 	Sleep(500);
 	system( "cls" );
	while(wybor!=3)
	{
		wyswietlanie(busy,N,M);
		cout<<endl<<endl;
		cout<<"Wybierz opcje: "<<endl;
		cout<<"1.Zarezerwuj miejsce"<<endl;
		cout<<"2.Odwolaj rezerwacje miejsca"<<endl;
		cout<<"3.Wyjdz"<<endl;
		cin>>wybor;
		switch(wybor)
		{
			case 1:
			cout<<endl;
			rezerwacja(N,M,busy);
			system( "cls" );
			break;
			
			case 2:
			cout<<endl;
			odwolanie(N,M,busy);
			system( "cls" );
			break;
		
			case 3:
		    break;	
			
			default:
			cout<<"nie ma takiej opcji"<<endl;
			Sleep(500);
 			system( "cls" );
			break;	
		
		}
	}
	zwalnianie_pamieci((int **)busy);
	return 1;
}
