#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
using namespace std;

int n;
int goal[20][20],board[20][20];
int zx,zy;
int gx, gy;
struct node {
	struct node* par;
	int fn,hn,gn;
	int arr[20][20];
	int zx, zy;
	//struct node* next;
}*head;

struct node *initialize(struct node*par){       //initialize as parent node
	struct node* p = (struct node*) malloc(sizeof(struct node));
	int i,j;
	if(par == NULL){
		for(i =0; i<n ; i++){
			for(j =0; j<n;j++){
				p->arr[i][j] = board[i][j];
			}
		}
		p->zx = zx;
		p->zy = zy;
		p->par = par;
		p->fn = p->hn = p->gn =0;
		return p;
	}
	p->zx = par->zx;
	p->zy = par->zy;
	for(i =0; i<n ; i++){
		for(j =0; j<n;j++){
			p->arr[i][j] = par->arr[i][j];
		}
	}
	p->par = par;
	p->fn = p->gn = p->hn = 0;
	return p;
}

vector <struct node*> closedlist;
vector<struct node* > openlist;
vector<struct node* > generated;

struct node* move_up(struct node *p,int a,int b){
	int t = p->arr[a-1][b];
	p->arr[a-1][b] = p->arr[a][b];
	p->arr[a][b] = t;
	p->zx = a-1;
	p->zy = b;
	return p;	
}
struct node* move_left(struct node *p,int a,int b){
	int t = p->arr[a][b-1];
	p->arr[a][b-1] = p->arr[a][b];
	p->arr[a][b] = t;
	p->zx = a;
	p->zy = b-1;
	return p;	
}
struct node* move_right(struct node *p,int a,int b){
	int t = p->arr[a][b+1];
	p->arr[a][b+1] = p->arr[a][b];
	p->arr[a][b] = t;
	p->zx = a;
	p->zy = b+1;
	return p;	
}
struct node* move_down(struct node *p,int a,int b){
	int t = p->arr[a+1][b];
	p->arr[a+1][b] = p->arr[a][b];
	p->arr[a][b] = t;
	p->zx = a+1;
	p->zy = b;
	return p;	
}
bool check_goal(struct node* p){
	int i,j;
	if(p != NULL ){
		for (i= 0; i<n; i++){
			for(j=0; j<n; j++){
				if(goal[i][j] != p->arr[i][j])
					return false;
			}
		}
		return true;
	}
	return false;
}
void printans(struct node *p){
    	
    	int len;
    	stack<struct node *> ss;
    	while(p && p->par){
         	ss.push(p);
         	p = p->par;
    	}
    	ss.push(p);
    	len = ss.size()-1;
	cout <<len<<endl;
        int r,c,a,b;
    	while(!ss.empty()){
        	struct node * w = ss.top();
        	ss.pop();
            if(!ss.empty() ){
                 r = w->zx;
                c = w->zy;
                 a=ss.top()->zx;
                 b = ss.top()->zy;
            
                if(r == a-1){
                    cout <<"DOWN\n";
                }
                if(r == a+1){
                    cout <<"UP\n";
                }
                if(c == b-1){
                    cout <<"RIGHT\n";
                }
                if(c == b+1){
                    cout <<"LEFT\n";
                }
            }
		}
}


bool visited(struct node* p) {
	int i, c = generated.size();
	if(p != NULL ){
		for(i =0; i<c; i++){
			int j,k;
			int cnt = 0;
			for(j=0; j<n; j++){
				for (k= 0; k<n; k++){
					if(generated[i]->arr[j][k] == p->arr[j][k])
						cnt++;
				}
			}
			if(cnt == n*n) return true;
		}
	}
	return false;
}


bool cmp(const struct node* a, const struct node* b) 
{   
	return a->fn < b->fn;
}  
 
int hn_func(struct node* p){
	int i,j,k,l;
	for(i =0; i<n ;i++){
		for(j=0; j<n; j++){		
			for(k=0; k<n; k++){
				for(l =0; l<n; l++){
					if(p->arr[i][j] == goal[k][l] && p->arr[i][j] != 0){
						p->hn += abs(i-k )+ abs(j-l);
					}
				}
			}
		}
	}
	return p->hn;
}
int gn_func(struct node* p){
	int c=0;
    	while(p ){
         	p = p->par;
		c++;
    	}
    	return c;
}
int fn_func(struct node* p){
	p->hn = hn_func(p);
	p->gn = gn_func(p);
	p->fn = p->hn +p->gn;
	return p->fn;
}


int astar_npuzzle(){
	closedlist.clear();
	openlist.clear();
	generated.clear();
	//cout <<"astar\n";
	head = initialize(NULL);
	head->fn = fn_func(head);
	openlist.push_back(head);
	generated.push_back(head);
	while(! openlist.empty()){
		sort(openlist.begin(), openlist.end(), cmp);
		struct node * p = openlist.front();
		openlist.erase(openlist.begin());
		int a =p->zx;
		int b = p->zy;
		
		//cout <<a << " ," <<b <<endl;
		closedlist.push_back(p);
		if(check_goal(p)){
		//cout<< "found ans\n";
			printans(p);
			return 1;
		}
		if(closedlist.size()> 4000) return 0;
		if(a-1 >=0  ){
			struct node * q = initialize(p);
			q = move_up(q, a,b);
			q->fn = fn_func(q);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
		if( b-1 >=0  ){
			struct node * q = initialize(p);
			q = move_left(q, a,b);
			q->fn = fn_func(q);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
		if( b+1 <n ){
			struct node * q = initialize(p);
			q = move_right(q, a,b);
			q->fn = fn_func(q);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
		if(a+1 <n  ){
			struct node * q = initialize(p);
			q = move_down(q, a,b);
			q->fn = fn_func(q);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
	}

	return 0;
}
int main(){
	cin >>n ;
	int i,j;
	for(i =0;i<n; i++){
		for(j=0; j<n; j++){
			cin >> board[i][j];
			if(board[i][j] == 0){
				zx = i;
				zy = j;
			}
		}
	}
	for(i =0;i<n; i++){
		for(j=0; j<n; j++){
			goal[i][j] = i*n+j;
			if(goal[i][j] == 0){
				gx = i;
				gy = j;
			}
		}
	}
	//printmat(board->arr);
	//printmat(finall->arr);
	int k=astar_npuzzle();

	return 0;
}
