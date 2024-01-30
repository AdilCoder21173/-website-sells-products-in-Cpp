#include<iostream>
#include<string.h>
using namespace std;

class item 
{
    public:
          string name;
          string brand;
          int price;
          int productdetail;
          item *next;
   
    item(string a,string b,int c,int d)
       {
        name=a;
        brand=b;
        price=c;
        productdetail=d;
        next=NULL;
        }
    
    void displaysub()
    { 
      
      cout<<endl<<" Product Name:  "<<name<<"  Brand:  "<<brand<<"  price:  "<<price<<"  Totalprd:  "<<productdetail;
    }
};

class subcategory
{
    public:
          string scname;
          item *subhead;
          item *subtail;
          subcategory *cnext;


     subcategory(string d)
       {
        subhead=NULL;
        subtail=NULL;
        cnext=NULL;
        scname=d;
       } 

      void insertionsub(string a,string b,int c,int d)
      {
        item *i=new item(a,b,c,d);
        if(subhead==NULL)
        {
            subhead=subtail=i;
        }
        else
        {
            subtail->next=i;
            subtail=subtail->next;
        }

      } 
      
      void deletionsub(string d)
      {
        item *temp=subhead;
        item *prev;

      while (temp->name!=d)
      {
        prev=temp;
        temp=temp->next;
      }
      if (temp==subhead)
      {
        subhead=subhead->next;
      }
      else
      {
       item *m=temp->next;
       prev->next=m;
       delete temp;
      }
      }

      void searchingsub(string d)
      {
        item *temp=subhead;

      while (temp->name!=d)
      {
        temp=temp->next;
      }
      if (temp==NULL)
      {
        cout<<"\nNot found";
      }
      else
      {
       cout<<"\nFound:"<<endl;
       cout<<temp->name;
       --temp->productdetail;
       cout<<endl<<"Remaining Product:  "<<temp->productdetail<<endl;
      }
      }  
    
      void displaysubcategory()
      {
        item *temp;
        temp=subhead;
        while (temp!=NULL)
        {
          temp->displaysub();
          temp=temp->next;
        }
         
      }    
};

class category
{
    public:
          string linkname;
          subcategory *chead;
          subcategory *ctail;
          category *lnext;


     category(string d)
       {
        chead=NULL;
        ctail=NULL;
        lnext=NULL;
        linkname=d;
       } 

      void insertioncategory(string a)
      {
        subcategory *j=new subcategory(a);
        if(chead==NULL)
        {
            int choice,price,detail;
            string name,brnd;
            chead=ctail=j;
             do
            { 
              cout<<"\nEnter 1 to add product:"<<endl;
              cout<<"Enter 2 to display product:"<<endl;
              cout<<"Enter 3 to delete product:"<<endl;
              cout<<"Enter 4 to search product:"<<endl;
              cout<<"Enter -1 to exit :"<<endl;
              cin>>choice;
              switch(choice)
              {
              case 1:  
                   cout<<"Enter the Product"<<endl<<"Name of product:";
                   cin.ignore();
                   getline(cin,name);
                   cout<<"Brand of product:";
                   getline(cin,brnd);
                   cout<<"Price of product:";
                   cin>>price;
                   cout<<"Total of a product:";
                   cin>>detail;
                   j->insertionsub(name,brnd,price,detail);
                   break;
              case 2:
                    j->displaysubcategory();
                    break;
              case 3:
                    cout<<"Delete the specific product:";
                    cin.ignore();
                    getline(cin,name);
                    j->deletionsub(name);
                    break;
              case 4:
                     cout<<"Search the specific product:";
                     cin.ignore();
                     getline(cin,name);
                     j->searchingsub(name);
                     break;
              default:
                break;
              }

            }while(choice!=-1);
           
            
        }
        else
        {
            ctail->cnext=j;
            ctail=ctail->cnext;

            int choice,price,detail;
            string name,brnd; 
            do
            { 
              cout<<"\nEnter 1 to add product:"<<endl;
              cout<<"Enter 2 to display product:"<<endl;
              cout<<"Enter 3 to delete product:"<<endl;
              cout<<"Enter 4 to search product:"<<endl;
              cout<<"Enter -1 to exit :"<<endl;
              cin>>choice;
              switch(choice)
              {
              case 1:  
                   cout<<"Enter the Product:"<<endl;
                   cin.ignore();
                   getline(cin,name);
                   cout<<"Brand of product:";
                   getline(cin,brnd);
                   cout<<"Price of product:";
                   cin>>price;
                   cout<<"Detail of a product:";
                   cin>>detail;
                   j->insertionsub(name,brnd,price,detail);
                   break;
              case 2:
                    j->displaysubcategory();
                    break;
              case 3:
                    cout<<"Delete the specific product:";
                    cin.ignore();
                    getline(cin,name);
                    j->deletionsub(name);
                    break;
              case 4:
                     cout<<"Search the specific product:";
                     cin.ignore();
                     getline(cin,name);
                     j->searchingsub(name);
                     break;
              default:
                break;
              }

            }while(choice!=-1);
        }
       

      } 
     void deletioncategory(string d)
      {
        subcategory *temp=chead;
        subcategory *prev;

      while (temp->scname!=d)
      {
        prev=temp;
        temp=temp->cnext;
      }
      if (temp==chead)
      {
        chead=chead->cnext;
      }
      else
      {
       subcategory *m=temp->cnext;
       prev->cnext=m;
       delete temp;
      }
      } 
    
     void searchingcategory(string d)
      {
        subcategory *temp=chead;

      while (temp->scname!=d)
      {
        temp=temp->cnext;
      }
      if (temp==NULL)
      {
        cout<<"Not found";
      }
      else
      {
       cout<<"\nFound :"<<temp->scname;
      }
      } 
     
      void displaycategory()
      {
        subcategory *temp;
        int b=1;
        temp=chead;
        while (temp!=NULL)
        {
          
          cout<<endl<<"    "<<b<<") "<<temp->scname;
          temp->displaysubcategory();
          temp=temp->cnext;
          b++;
        }
       
      }

};

class link
{
    public:
          category *lhead;
          category *ltail;
          
    link()
     { 
        lhead=NULL;
        ltail=NULL;
     }

    void insertionlink(string a)
      {
        category *k=new category(a);
        if(lhead==NULL)
        { 
            string name;
            int choice;
            lhead=ltail=k;
            do
            { 
              cout<<"\nEnter 1 to add Subcategory:"<<endl;
              cout<<"Enter 2 to display Subcategory:"<<endl;
              cout<<"Enter 3 to delete Subcategory:"<<endl;
              cout<<"Enter 4 to search Subcategory:"<<endl;
              cout<<"Enter -1 to exit :"<<endl;
              cin>>choice;
              switch(choice)
              {
              case 1:  
                   cout<<"Enter the Subcategory:"<<endl;
                   cin.ignore();
                   getline(cin,name);
                   k->insertioncategory(name);
                   break;
              case 2:
                    k->displaycategory();
                    break;
              case 3:
                    cout<<"Delete the specific subcategory:";
                    cin.ignore();
                    getline(cin,name);
                    k->deletioncategory(name);
                    break;
              case 4:
                    cout<<"Search the subcategory:";
                    cin.ignore();   
                    getline(cin,name);
                    k->searchingcategory(name);
                     break;     
              default:
                      break;
              }

            }while(choice!=-1);
        }
        else
        {          
            ltail->lnext=k;
            ltail=ltail->lnext;
            string name;
            int choice;
            do
            { 
              cout<<"Enter 1 to add subcategory:"<<endl;
              cout<<"Enter 2 to display subcategory:"<<endl;
              cout<<"Enter 3 to delete Subcategory:"<<endl;
              cout<<"Enter 4 to search Subcategory:"<<endl;
              cout<<"Enter -1 to exit :"<<endl;
              cin>>choice;
              switch(choice)
              {
              case 1:  
                   cout<<" Enter the subcategory:"<<endl;
                   cin.ignore();
                   getline(cin,name);
                   k->insertioncategory(name);
                   break;
              case 2:
                    k->displaycategory();
                    break;
              case 3:
                    cout<<"Delete the specific subcategory:";
                    cin.ignore();
                    getline(cin,name);
                    k->deletioncategory(name);
                    break;
              case 4:
                    cout<<"Search the specific subcategory: ";
                    cin.ignore();
                    getline(cin,name);
                    k->searchingcategory(name);
                     break;
                   
              default:
                     break;
              }

            }while(choice!=-1);
        }

      }
      void deletion(string d)
      {
        category *temp=lhead;
        category *prev;

      while (temp->linkname!=d)
      {
        prev=temp;
        temp=temp->lnext;
      }
      if (temp==lhead)
      {
        lhead=lhead->lnext;
      }
      else
      {
        category *j=temp->lnext;
        prev->lnext=j;
       delete temp;
      }
      } 

      void searching(string k)
      {
        category *temp=lhead;

      while (temp->linkname!=k)
      {
        temp=temp->lnext;
      }
      if(temp==NULL)
      {
        cout<<"\nNot found :"<<endl;
      }
      else
      {
        cout<<"\nIs found:"<<endl;
        cout<<temp->linkname;
      }
     
      } 

      void displaylink()
      {
        category *temp;
        int k=1;
        temp=lhead;
        while (temp!=NULL)
        { 
          cout<<endl<<k<<") "<<temp->linkname<<endl;
          temp->displaycategory();
          temp=temp->lnext;
          k++;
        }
       
        
      }
};
int main()
{
  
  link obj1;
  int choice;
  string name;
  do
  {
              cout<<"\nEnter 1 to add category:"<<endl;
              cout<<"Enter 2 to display category:"<<endl;
              cout<<"Enter 3 to delete category:"<<endl;
              cout<<"Enter 4 to search category:"<<endl;
              cout<<"Enter -1 to exit :"<<endl;
              cin>>choice;
              switch(choice)
              {
              case 1:  
                   cout<<"\nEnter the category:"<<endl;
                   cin.ignore();
                   getline(cin,name);
                   obj1.insertionlink(name);
                   break;
              case 2:
                    obj1.displaylink();
                    break;
              case 3:
                    cout<<"Delete the specific category:";
                    cin.ignore();
                    getline(cin,name);
                    obj1.deletion(name);
              case 4:
                    cout<<"Search the specific category:";
                    cin.ignore();
                    getline(cin,name);
                    obj1.searching(name);
              default:
                break;
              }

  }while(choice!=-1); 

  return 0;
}