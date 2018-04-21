#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<cstdlib>
#include<math.h>
#include<iomanip>
using namespace std;
int t;
int x=0;
int val=0;
int count=0;
int flag=0;
ostream& operator << (ostream& os,const vector<int>& c)
{
  string g="";
  for(int it2=0;it2<c.size();it2++)
  {
  g=g+to_string(c[it2]);
  }
  os << g;
  return os;
}
ostream& operator << (ostream& os,const vector<string>& c1)
{
  os << c1[0];
  return os;
}
class shiftregister
{
private:
  char **argv1;
  int x;
  string k;
  int size1;
  int totalsum2;
  vector<int> v;
  vector<int> v1;
  vector<string> result;
  vector<int>::iterator it;
  vector<int>::iterator it1;
public:
  shiftregister(int argc, char *argv[])
  {
  v.push_back(0);//default register1 of 1 bit.
  v1.push_back(0);//default register2 of 1 bit.
  result.push_back("0");
  argv1=argv;
  for (int i=1 ; i< argc ; i++)
  {
    if(!strcmp(argv[i],"-i"))
    {
      if(argv[i+1]==nullptr)
      {
        exit(-1);
      }
      k=argv[i+1];
      i++;
      t=1;
    }
    else if(!strcmp(argv[i],"-s"))
    {
      if(argv[i+1]==nullptr)
      {
        exit(-1);
      }
      size1=stoi(argv[i+1]);
      i++;
      t=2;
    }

    else if(!strcmp(argv[i],"-r"))
    {
      if(argv[i+1]==nullptr)
      {
        exit(-1);
      }
      x=stoi(argv[i+1]);
      i++;
      t=3;
    }

    else if(!strcmp(argv[i],"-l"))
    {
      if(argv[i+1]==nullptr)
      {
        exit(-1);
      }
      x=stoi(argv[i+1]);
      i++;
      t=4;
    }

    else if(!strcmp(argv[i],"-v"))
    {
      if(argv[i+1]==nullptr)
      {
        exit(-1);
      }
      x=stoi(argv[i+1]);
      i++;
      t=5;
    }
    else if(!strcmp(argv[i],"-p"))
    {
      t=6;
    }
    else if(!strcmp(argv[i],"-I"))
    {
      if(argv[i+1]==nullptr)
      {
        exit(-1);
      }
      k=argv[i+1];
      i++;
      t=7;
    }
    else if(!strcmp(argv[i],"-S"))
    {
      if(argv[i+1]==nullptr)
      {
        exit(-1);
      }
      size1=stoi(argv[i+1]);
      i++;
      t=8;
    }
    else if(!strcmp(argv[i],"-R"))
    {
      if(argv[i+1]==nullptr)
      {
        exit(-1);
      }
      x=stoi(argv[i+1]);
      i++;
      t=9;
    }
    else if(!strcmp(argv[i],"-L"))
    {
      if(argv[i+1]==nullptr)
      {
        exit(-1);
      }
      x=stoi(argv[i+1]);
      i++;
      t=10;
    }
    else if(!strcmp(argv[i],"-d"))
    {
      t=12;
    }
    else if(!strcmp(argv[i],"-h"))
    {
      t=13;
    }
    else if(!strcmp(argv[i],"-o"))
    {
      if(argv[i+1]==nullptr)
      {
        exit(-1);
      }
        k=argv[i+1];
        i++;
        t=11;
    }
    else
    {
      t=0;
    }
    switch(t)
    {
    case 1:
initialize();
    break;
    case 2:
resize();
    break;
    case 3:
shiftright();
    break;
    case 4:
shiftleft();
    break;
    case 5:
value();
    break;
    case 6:
print();
    break;
    case 7:
initialize1();
    break;
    case 8:
resize1();
    break;
    case 9:
shiftright1();
    break;
    case 10:
shiftleft1();
    break;
    case 11:
operation();
    break;
    case 12:
    dec1();
    break;
    case 13:
    hex1();
    break;
    default:
    exit(-1);
    break;
  }
  }
}
void resize()
{
v.resize(size1);
}
void resize1()
{
v1.resize(size1);
}
void dec1()
{
  flag=1;
}
void hex1()
{
  flag=2;
}
void value()
{
  if(x==1 || x==0)
  {
    val=x;
  }
  else
  {
    exit(-1);
  }
}
void shiftright()
{

  int size2=v.size();
  if((x>size2)||(x<0))
  {
    exit(-1);
  }
   for(int i=0;i<x;i++)
  {
    v.erase(v.end()-1);
  }

  for(int i=0;i<x;i++)
  {
    v.insert(v.begin(),val);
  }
}
int decimal(std::vector<int>& v4)
{
  int z=0;
  int base=0;
  int decimal=0;
  int k;
vector<int>::reverse_iterator rit=v4.rbegin();
vector<int>::iterator i5;
for(i5=v4.begin();i5!=v4.end();++i5)
{
  if(*i5==1)
  {
    for(rit=v4.rbegin();rit!=v4.rend()-1;++rit)
    {
     z=*rit;
     k=pow(2,base);
     z=z*k;
     decimal=decimal+z;
     base++;
    }
    decimal=decimal*(-1);
    break;
  }
  else if(*i5==0)
  {
    for(rit=v4.rbegin();rit!=v4.rend()-1;++rit)
    {
     z=*rit;
     k=pow(2,base);
     z=z*k;
     decimal=decimal+z;
     base++;
    }
    break;
  }
  break;
}
return decimal;
}
/*int hexadecimal()
{
  string hexadecimal="";
std::vector<int>::reverse_iterator rit1;
for(rit=v.rbegin();rit!=v.rend();++rit1)
{
  rit2=*rit1;
  string hexadecimal=hexadecimal+(*rit1);
}
int hexadecimal1=stoi(hexadecimal);
return hexadecimal1;
}*/
void shiftright1()
{

  int size2=v1.size();
  if((x>size2)||(x<0))
  {
    exit(-1);
  }
   for(int i=0;i<x;i++)
  {
    v1.erase(v1.end()-1);
  }

  for(int i=0;i<x;i++)
  {
    v1.insert(v1.begin(),val);
  }
}
void shiftleft()
{
  int size2=v.size();
  if((x>size2)||(x<0))
  {
    exit(-1);
  }
  for(int i=0;i<x;i++)
 {
   v.erase(v.begin());
 }

 for(int i=0;i<x;i++)
 {
   v.insert(v.end(),val);
 }
}
void shiftleft1()
{
  int size2=v1.size();
  if((x>size2)||(x<0))
  {
    exit(-1);
  }
  for(int i=0;i<x;i++)
 {
   v1.erase(v1.begin());
 }

 for(int i=0;i<x;i++)
 {
   v1.insert(v1.end(),val);
 }
}
void initialize()
{
  v.clear();
  for (int q=0;q<k.size();q++)
  {
    char w=k[q];
    int x=(int)w-48;
    if((x==0)||(x==1))
    {
    v.push_back(x);
  }
  else
  {
    exit(-1);
  }
  }
}
void initialize1()
{
  v1.clear();
  for (int q=0;q<k.size();q++)
  {
    char w=k[q];
    int x=(int)w-48;
    if((x==0)||(x==1))
    {
    v1.push_back(x);
  }
  else
  {
    exit(-1);
  }
  }
}
void operation()
{
  int totalsum1=0;
  totalsum2=0;
  string r="";
  result.clear();
  if(k.compare("+")==0)
  {
    int x1=decimal(v);
    int x2=decimal(v1);
    totalsum1=x1+x2;
    totalsum2=totalsum1;
    if(totalsum1==0)
    {
      r="0";
    }
    if(totalsum1>0)
    {
    while(totalsum1!=0)
    {
      r=(totalsum1%2==0 ?"0":"1")+r;
      totalsum1=totalsum1/2;
    }
    r="0"+r;
  }
  else if(totalsum1<0)
  {
    while(totalsum1!=0)
    {
      r=(totalsum1%2==0 ?"0":"1")+r;
      totalsum1=totalsum1/2;
    }
    r="1"+r;
  }
  }
  else if(k.compare("-")==0)
  {
    int x1=decimal(v);
    int x2=decimal(v1);
    totalsum1=x1-x2;
    totalsum2=totalsum1;
    if(totalsum1==0)
    {
      int size1=0;
      if(v.size()>v1.size())
      {
        size1=v.size();
      }
      else
      {
        size1=v1.size();
      }
      for(int i=0;i<size1;i++)
      {
      r="0"+r;
    }
    }
    else if(totalsum1>0)
    {
    while(totalsum1!=0)
    {
      r=(totalsum1%2==0 ?"0":"1")+r;
      totalsum1=totalsum1/2;
    }
    r="0"+r;
    }
    else if(totalsum1<0)
    {
      while(totalsum1!=0)
      {
        r=(totalsum1%2==0 ?"0":"1")+r;
        totalsum1=totalsum1/2;
      }
      r="1"+r;
        }
  }
  result.push_back(r);
}
void print()
{
   if(flag==0)
    {
    cout << v << endl;
    cout << v1 << endl;
    cout << result << endl;
  }
  else if(flag==1)
  {
   cout << v;
   cout << "(";
   int r = decimal(v);
   cout << r << ")"<< endl << v1 <<"(";
   int r1 = decimal(v1);
   cout << r1 << ")" << endl;
   cout <<result;
   string rt=result[0];
   if(rt.compare("0")==0)
   {
     cout<<"("<<"0"<<")"<<endl;
   }
   else
   {
   cout << "(" << totalsum2 << ")"<<endl;
 }
  }
  else if(flag==2)
  {
      cout << v;
      int rs1=decimal(v);
      cout<<uppercase<<setbase(16);
      if(rs1==0)
      {
        cout << "(0x";
        cout<<rs1;
      }
      else if(rs1>0)
      {
        cout << "(0x";
        cout<<rs1;
      }
    else if(rs1<0)
    {
      cout << "(-0x";
      rs1=rs1*(-1);
      cout<<rs1;
    }
      cout << ")"<<endl;
      cout << v1;

      int rs2=decimal(v1);
      cout<<uppercase<<setbase(16);
      if(rs2==0)
      {
      cout << "(0x"<<rs2;
      }
       if(rs2>0)
      {
        cout << "(0x"<<rs2;
      }
      else if(rs2<0)
      {
        cout << "(-0x";
        rs2=rs2*(-1);
        cout<<rs2;
      }
      cout<<")"<<endl;
      cout <<result;
      string i=result[0];
      if(i.compare("0")==0)
      {
        cout << "(0x" << "00"<< ")" << endl;
      }
      else
    {
      if(totalsum2==0)
      {
      cout << "(0x" << totalsum2 << ")" << endl;
      }
      if(totalsum2>0)
      {
      cout << "(0x" << totalsum2 << ")" << endl;
    }
    else if(totalsum2<0)
    {
      totalsum2=totalsum2*(-1);
      cout << "(-0x" << totalsum2 << ")" << endl;
    }
  }
  }
}
};

int main(int argc, char *argv[])
{
  shiftregister e(argc,argv);
  return 0;
}
