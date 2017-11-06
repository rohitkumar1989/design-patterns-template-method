#include<iostream>
#include<time.h>
using namespace std;
class framework_sort{
		int *arr,size;
		virtual int compare(int, int)=0;
	
		public:
	framework_sort(int size):arr(new int[size]),size(size){}//should not call pure virtual function
	
		
	
 	virtual void sort(){
	    	cout<<endl;	cout<<"input ";
	    for(int i=0;i<size;i++){
			arr[i]=rand()%100+4;
			cout<<arr[i]<<" ";
		}
	//	cout<<endl;
		for(int i=0;i<size-1;i++){
			for(int j=0;j<size-i-1;++j){
				if(compare(arr[j],arr[j+1]))
				{
					swap(&arr[j],&arr[j+1]);
				}	
				
			}
		}
	}
	
	int sizefun(){return size;}
		int fundis(int i){return *(arr+i);}
	void swap(int* a ,int* b){
		int temp=*a;
		*a=*b;
		*b=temp;
	}
		virtual void display()=0;
};

class ascend_sort:public framework_sort{
	
	public:
			ascend_sort(int size):framework_sort(size){}

	virtual int compare(int a,int b){
		if(a>b){
			return 1;
		}else{
			return 0;
		}
		
	}
 	void display(){
		sort();
			cout<<endl<<"ascend = ";
		for(int i=0;i<sizefun();i++){
			cout<<fundis(i)<<" ";
		}
	}
	
};

class descend_sort:public framework_sort{
    public:
			descend_sort(int size):framework_sort(size){}
public:	 int compare(int a,int b){
		if(a<b){
			return 1;
		}else{
			return 0;
		}
	}
	 void display(){
	    sort();
	    cout<<endl<<"descend = ";
		for(int i=0;i<sizefun();i++){
			cout<<fundis(i)<<" ";
		}
	}

	
};

int main(){
	srand(time(NULL));
	try{
	int size;
	framework_sort *c[]={new ascend_sort(10),new descend_sort(13)};
	
	c[0]->display();
	c[1]->display();
	}catch(exception e){
	    cout<<e.what();
	}
}
