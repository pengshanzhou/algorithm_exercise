#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int  ROW=50;          //矩阵行数，测试的时候请改变配置
const int  COLUMN=50;       //矩阵列数，测试的时候可以改变
const int level=6;         //id的个数，测试的时候可以改变
int L[ROW][COLUMN];  //二维数组
/*布局连连看*/
void laylout()
{
	for(int i=0;i<ROW;i++)
		for(int j=0;j<COLUMN;j++)
		{
			L[i][j]=(i*ROW+j)%level+1;  
		}

	for(int i=0;i<ROW;i++)
       for(int j=0;j<COLUMN;j++)
		{
			int n=rand()%ROW;      
			int m=rand()%COLUMN;
			int temp=L[n][m];         //随机交换
			L[n][m]=L[i][j];
            L[i][j]=temp;
		}	
}
void show()
{
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COLUMN;j++)
			{
				cout<<L[i][j]<<" ";
				
		    }
		cout<<endl;
	}
}
struct  Point{
	int x;  //行
	int y;  //列
	string path;
	void pathadd(string PrePath)
	{
		char t=x+'0';
		char tt=y+'0';
		path=PrePath+"  "+"("+t+','+tt+')'+' ';
	}
};
/* 
广度搜索一个转角为一层
对于点a1，要找到与其匹配的点a2可以这样做：
1. 找到a1可以直线相连的点集S1;   s1中如果没有匹配的a2则 执行step 2
2. 找到S1中各空白点可以直线相连的点集S2; s2中如果没有匹配的a2则 执行step 3
3. 找到S2中各空白点可以直线相连的点集S3。s3中如果没有匹配的a2则 失败返回
这里面的减枝可以表述为 ：对于一个点从自己出发交替双向（为什么是两个方向交替呢？这样我们可以保证最短）
遍历的时候遇到一个非零点并且和a1不相等时候，则结束此方向的搜索

*/

queue <Point> HoriLineOne;  // 水平第一条线
queue <Point> VertLineOne;  //垂直第一条线
queue <Point> HoriLineTwo;  //水平第二条线
queue <Point> VertLineTwo;  //垂直二条线
queue <Point> HoriLineThree;  //水平第三条线
queue <Point> VertLineThree;
/*
其实这里不需要存储第三层队列，我们在扫描第三层的时候就直接判断
但是为了同一函数接口和内容所以就加上了   不影响时间复杂度
*/


/*水平线搜索*/
int HoriSearch(const Point &p,queue <Point> &v,int val,Point & target)
{
	int x=p.x;
	int y=p.y;
	int i=1;

	/*从自身点出发 交替双向变量 */
	while(1)
	{
		if(y+i<COLUMN &&L[x][y+i]==0  && y-i >=0 && L[x][y-i]==0)
		{
			Point left,right;
			left.x=right.x=x;
			left.y=y-i;
			right.y=y+i;
			left.pathadd(p.path);
			right.pathadd(p.path);
			v.push(right);
			v.push(left);
			i++;
		}
		else 
			break;
	}
	/*交替遍历结束 下面是单线运动 */
	int k=i;
	while(y+i<COLUMN )               //向右
	{
		if(L[x][y+i]==val)
		{
			
			target.x=x;
			target.y=y+i;
			target.pathadd(p.path);
			return 1;
		}
		else if(L[x][y+i]==0)
		{
			Point temp;
			temp.x=p.x;
			temp.y=y+i;
			temp.pathadd(p.path);
			v.push(temp);
			i++;
		}
		else break;
	}

	while(y-k>=0 )              //向左
	{
		if(L[x][y-k]==val)
		{
			
			target.x=x;
			target.y=y-k;
			target.pathadd(p.path);
			
			return 1;
		}
		else if(L[x][y-k]==0)
		{
			Point temp;
			temp.x=p.x;
			temp.y=y-k;
			temp.pathadd(p.path);
			v.push(temp);
			k++;

		}
		else break;
	}

	return 0;
}
/*垂直线搜索*/
int VertSearch(const Point &p,queue <Point> &v,int val,Point & target)
{
	int x=p.x;
	int y=p.y;
	int i=1;

	/*从自身点出发 交替双向变量 */
	while(1)
	{
		if(x+i<ROW &&L[x+i][y]==0  && x-i >=0 && L[x-i][y]==0)
		{
			Point left,right;            //left就是向上，right就是向下
			left.y=right.y=y;
			left.x=x-i;
			right.x=x+i;
			left.pathadd(p.path);
			right.pathadd(p.path);
			v.push(right);
			v.push(left);
			i++;
		}
		else 
			break;
	}
	/*交替遍历结束 下面是单线运动 */
	int k=i;
	while(x+i<ROW )               //向下
	{
		if(L[x+i][y]==val)
		{
			
			target.y=y;
			target.x=x+i;
			target.pathadd(p.path);
			
			return 1;
		}
		else if(L[x+i][y]==0)
		{
			Point temp;
			temp.y=p.y;
			temp.x=x+i;
			temp.pathadd(p.path);
			v.push(temp);
			i++;
		}
		else break;
	}

	while(x-k>=0 )              //向上
	{
		if(L[x-k][y]==val)
		{
			
			target.y=y;
			target.x=x-k;
			target.pathadd(p.path);
	
			return 1;
		}
		else if(L[x-k][y]==0)
		{
			Point temp;
			temp.y=p.y;
			temp.x=x-k;
			temp.pathadd(p.path);
			v.push(temp);
			k++;

		}
		else break;
	}

	return 0;
}

int search(Point cur,Point &target)
{
	int val=L[cur.x][cur.y];
	if(HoriSearch(cur,HoriLineOne,val,target)==1)
		return 1;
	if(VertSearch(cur,VertLineOne,val,target)==1)
		return 1;

	/*二线查找*/
	while(!HoriLineOne.empty())
	{
		Point temp=HoriLineOne.front();
		HoriLineOne.pop();
		if(VertSearch(temp,VertLineTwo,val,target)==1)
			return 1;
	}
	while(!VertLineOne.empty())
	{
		Point temp=VertLineOne.front();
		VertLineOne.pop();
		if(HoriSearch(temp,HoriLineTwo,val,target)==1)
			return 1;
	}

	/*第三线查找*/
	while(!HoriLineTwo.empty())
	{
		Point temp=HoriLineTwo.front();
		HoriLineTwo.pop();
		if(VertSearch(temp,VertLineThree,val,target)==1)
			return 1;
	}
	while(!VertLineTwo.empty())
	{
		Point temp=VertLineTwo.front();
		VertLineTwo.pop();
		if(HoriSearch(temp,HoriLineThree,val,target)==1)
			return 1;
	}
	
	return 0;
}

int solution()
{
	Point target[ROW*COLUMN];
	int count=0;
	
	while(1)
	{
		bool finish=true;
		bool change=false;
		for(int i=0;i<ROW;i++)
	     {
		   for(int j=0;j<COLUMN;j++)
			{
				if(L[i][j]!=0)
				{
					
					finish=false;
					Point cur;
					cur.x=i;
					cur.y=j;
					cur.pathadd("最短路径：");
					if(search(cur,target[count])==1 && !(target[count].x==i && target[count].y==j))
					{
						
						change=true;
						L[i][j]=0;
						L[target[count].x][target[count].y]=0;
	
						cout<<target[count].path<<endl;
						count++;
					}
				 }
				
		     }

	       }// end of for
	    
		if(finish==true)
		{
			cout<<"成功完成所有解算"<<endl;
			return 1;
		}
		if(change==false)
		{
			cout<<"无法再继续下去了"<<endl;
			return 0;
		}
	}
	return 0;
	
}

int main()
{
	laylout();
	show();

	solution();
	show();
	
	
	system("pause");
	return 0;
}
