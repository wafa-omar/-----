#include <iostream>

using namespace std;
 void wafa(float Dlta[][100],int n);
 float mul(int i,float value,float x[]);
 float power(float h,int i);
 int fact(int i);

int main()
{
    int n;
    cout<<"enter the number of X & Y = ";
    cin>>n;
    float x[n],y[n],Dlta[100][100],value,sum=0.0,h;
    bool t=true;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            Dlta[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<'X'<<i<<" = ";
        cin>>x[i];
        cout<<'Y'<<i<<" = ";
        cin>>y[i];
        Dlta[i][0]=y[i];
    }
    h=x[1]-x[0];
    cout<<"h="<<h;
    cout<<endl;


    cout<<"| X | ";
    for(int i=0;i<n;i++)
    {
       cout<<x[i]<<" | ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
       cout<<"-----";
    }
    cout<<endl;
    cout<<"| Y | ";
    for(int i=0;i<n;i++)
    {
       cout<<y[i]<<" | ";
    }




    for(int i=1;i<n-1;i++)
    {
        if(h!=(x[i+1]-x[i]))
        {
            t=false;
            break;
        }
    }
    cout<<endl;
    if(t==false)
    {
        cout<<"error ,distances is not equal ."<<endl;
    }
    else
    {
    cout<<"| X | ";
    for(int i=0;i<n;i++)
    {
       cout<<x[i]<<" | ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
       cout<<"-----";
    }
    cout<<endl;
    cout<<"| Y | ";
    for(int i=0;i<n;i++)
    {
       cout<<y[i]<<" | ";
    }
    wafa(Dlta,n);
    cout<<endl<<endl;
    cout<<"enter the value to be rounded = ";
    cin>>value;
    sum+=Dlta[0][0];
    for(int i=1;i<n;i++)
    {
        sum+=(Dlta[0][i]*mul(i,value,x))/(fact(i)*(power(h,i)));
    }
    cout<<endl<<"Rounding depending on the table = "<<sum;
    cout<<endl;
    }
    return 0;
}



void wafa(float Dlta[][100],int n)
{
    int k=0;
    for(int j=0;j<n;j++)
    {
        k++;
        for(int i=0;i<n-k;i++)
        {
            Dlta[i][j+1]=Dlta[i+1][j]-Dlta[i][j];
        }
    }
    cout<<endl<<endl;
    k=0;
    for(int i=0;i<n;i++)
    {
        k++;
        for(int j=0;j<n;j++)
        {
            cout<<Dlta[i][j]<<"   ";
        }
        cout<<endl;
    }
}



float mul(int i,float value,float x[])
{
    float z=1;
    for(int j=0;j<i;j++)
    {
        z*=(value-x[j]);
    }
    return z;
}



float power(float h,int i)
{
    float x=1.0;
    for(int j=0;j<i;j++)
    {
       x*=h;
    }
    return(x);
}



int fact(int i)
{
    int z=1;
    for(int j=0;j<i;j++)
    {
        z*=(i-j);
    }
    return z;
}
