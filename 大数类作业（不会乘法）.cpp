#include <vector>
#include<string>
#include <iostream>
#include<math.h>
#include<cstdlib>
#include <algorithm>
#include <stdlib.h>
using namespace std;
class Box{
	public:
	void dashujiafa(string str1,string str2)
	{
	 e=str1.size();//e为vfir的长度 
    for(b=0;b<e;b++) {
		m=str1[b];
		vfir.push_back(m);
	}
	f=str2.size();//f为vsec的长度 
	for(b=0;b<f;b++) {
		m=str2[b];
		vsec.push_back(m);
	} 
	if(e>f)//前一个数比较大时 
{
	if(f==1) {
	int shu,shu2,shu3,shu4;char dashu;
	shu=atoi(vfir[e-1].c_str())+atoi(vsec[0].c_str());//末位数加和 
	if(shu>=10) {	shu=shu%10;jinwei=1;	}
	else shu=shu;dashu=char(shu+48);dashustr.push_back(dashu);
	if(e>2){                                         //实现两位加一位 
		for(b=e-2;b>=1;b--) {
    	shu2=atoi(vfir[b].c_str())+jinwei;shu3=atoi(vfir[b-1].c_str());
    	if(shu2>=10) {
    		jinwei=shu2/10;shu2=shu2%10;dashu=char(shu2+48);dashustr.insert(dashustr.begin(),dashu);
    		shu3++;	}
		else {dashu=char(shu2+48);dashustr.insert(dashustr.begin(),dashu);jinwei=0;}		
		if(b==1) {
			if(shu3>=10) {shu3=shu3%10;dashu=char(shu3+48);dashustr.insert(dashustr.begin(),dashu);dashu=char(49);dashustr.insert(dashustr.begin(),dashu);}
	    	else {dashu=char(shu3+48);dashustr.insert(dashustr.begin(),dashu);	}
		}
	}
	}
	else if(e<=2){
    	int shu;char dashu;
    	shu=atoi(vfir[0].c_str())+jinwei;
    	if(shu>=10) {shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);dashu=char(49);dashustr.insert(dashustr.begin(),dashu);}
    	else {dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);}
}
	}//if到此为止 ，多加一完成 
	
	else {//实现多加多 
	for(b=e-1,q=f-1;b>=e-f;b--,q--) {
		int shu,shu2,shu3,shu4;char dashu;
		shu=atoi(vfir[b].c_str())+atoi(vsec[q].c_str())+jinwei;
		if(b==e-f) {
        	if(shu>=10) {jinwei1=1;shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);break;			}
            else {jinwei1=0;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);break;	}
		}
		if(shu>=10) {
			jinwei=1;shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);		}
        else {jinwei=0;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);			}
	   }
       	for(b=e-f-1;b>=0;b--) {
    	int shu,shu2;char dashu;
    	shu=atoi(vfir[b].c_str())+jinwei1;
    	if(b==0) {
    		if(shu>=10) {jinwei1=1;shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);dashu=char(49);dashustr.insert(dashustr.begin(),dashu);break;}
    		else {dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);break;}
		}
    	if(shu>=10) {jinwei1=1;shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);}
    	else {jinwei1=0;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);		}
	}
}//else 到这里结束 ，目前大数加（长加短）已完成 
}//大循环(e>f)到此为止 

else if(e==f){  //位数相同（e=f）时的情况 已完成 
	if(e>1) {
		for(q=1;q<e;q++) {    //当e,f不为 1 时  
	int shu,shu2;char dashu;
	shu=atoi(vfir[q].c_str())+atoi(vsec[q].c_str());shu2=atoi(vfir[q-1].c_str())+atoi(vsec[q-1].c_str());
	if(q==1) {
		if(shu>=10) {shu=shu%10;shu2++;}	else shu=shu%10;
		if(shu2>=10) {dashustr.push_back(49);shu2=shu2%10;dashu=char(shu2+48);dashustr.push_back(dashu);}
		else {dashu=char(shu2+48);dashustr.push_back(dashu);}
	         }
	else {
		if(shu>=10) {shu=shu%10;shu2++;}	else shu=shu%10;
		shu2=shu2%10;dashu=char(shu2+48);dashustr.push_back(dashu);
	}    
	if(q==e-1){	shu=shu%10;dashu=char(shu+48);dashustr.push_back(dashu);}
	}
	}
	else if(e==1) {  //当e，f为 1 时 
		int shu,shu2;char dashu;
		shu=atoi(vfir[0].c_str())+atoi(vsec[0].c_str());
		if(shu>=10) {shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);dashu=char(49);dashustr.insert(dashustr.begin(),dashu);		}
		else {dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);}
	}
	
}//else (e=f)的情况到此为止
 
else {        //此时e<f 
	if(e==1) {//实现一加多 
	int shu,shu2,shu3,shu4;char dashu;
	shu=atoi(vfir[0].c_str())+atoi(vsec[f-1].c_str());//末位数加和 
	if(shu>=10) {	shu=shu%10;jinwei=1;	}
	else shu=shu;dashu=char(shu+48);dashustr.push_back(dashu);
	if(f>2) {                                   //实现一位加两位 
		for(b=f-2;b>=1;b--) {
    	shu2=atoi(vsec[b].c_str())+jinwei;shu3=atoi(vsec[b-1].c_str());
    	if(shu2>=10) {
    		jinwei=shu2/10;shu2=shu2%10;dashu=char(shu2+48);dashustr.insert(dashustr.begin(),dashu);
    		shu3++;	}
		else {dashu=char(shu2+48);dashustr.insert(dashustr.begin(),dashu);jinwei=0;}		
		if(b==1) {
			if(shu3>=10) {shu3=shu3%10;dashu=char(shu3+48);dashustr.insert(dashustr.begin(),dashu);dashu=char(49);dashustr.insert(dashustr.begin(),dashu);}
	    	else {dashu=char(shu3+48);dashustr.insert(dashustr.begin(),dashu);	}
		}
	}
	}
	else if(f<=2){
    	int shu;char dashu;
    	shu=atoi(vsec[0].c_str())+jinwei;
    	if(shu>=10) {shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);dashu=char(49);dashustr.insert(dashustr.begin(),dashu);}
    	else {dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);}
	}
	}//if到此为止 ，一加多完成 
	
	else {//实现多加多，e<f 
	for(b=e-1,q=f-1;q>=f-e;b--,q--) {
		int shu,shu2,shu3,shu4;char dashu;
		shu=atoi(vfir[b].c_str())+atoi(vsec[q].c_str())+jinwei;
		if(q==f-e) {
        	if(shu>=10) {jinwei1=1;shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);break;			}
            else {jinwei1=0;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);break;	}
		}
		if(shu>=10) {
			jinwei=1;shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);		}
        else {jinwei=0;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);			}
       }
    for(b=f-e-1;b>=0;b--) {
    	int shu,shu2;char dashu;
    	shu=atoi(vsec[b].c_str())+jinwei1;
    	if(b==0) {
    		if(shu>=10) {jinwei1=1;shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);dashu=char(49);dashustr.insert(dashustr.begin(),dashu);break;}
    		else {dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);break;}
		}
    	if(shu>=10) {jinwei1=1;shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);}
    	else {jinwei1=0;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);		}
	}
}//else 到这里结束 ，目前大数加（短加长）已完成 
}
//大数加法完成，第一行输入一个任意位数数字，第二行输入任意位数数字，第三行输出加和 
cout <<"两大数之和为="; 
for(int li=0;li<dashustr.size();li++) {
	cout << dashustr[li];
}//循环输出 
cout << endl;
	}
	void dashujianfa(string str1,string str2)
	{
e=str1.size();//e为vfir的长度 
    for(b=0;b<e;b++) {
		m=str1[b];
		vfir.push_back(m);
	}
	f=str2.size();//f为vsec的长度 
	for(b=0;b<f;b++) {
		m=str2[b];
		vsec.push_back(m);
	} 
	if(e>f)//前一个数比较大时 
{
	if(f==1) {
	int shu,shu2,shu3,shu4;char dashu;
	shu=atoi(vfir[e-1].c_str())-atoi(vsec[0].c_str());//末位数相减 
	if(shu<0) {	shu=atoi(vfir[e-1].c_str())+10;shu=shu-atoi(vsec[0].c_str());jinwei=1;	}
	else shu=shu;dashu=char(shu+48);dashustr.push_back(dashu);
	if(e>2){                                         //实现多位减一位 
		for(b=e-2;b>=1;b--) {
    	shu2=atoi(vfir[b].c_str())-jinwei;shu3=atoi(vfir[b-1].c_str());
    	if(shu2<0) {
    		jinwei=1;shu2=(-shu2)%10;dashu=char(shu2+48);dashustr.insert(dashustr.begin(),dashu);
    		shu3--;	}
		else {dashu=char(shu2+48);dashustr.insert(dashustr.begin(),dashu);jinwei=0;}		
		if(b==1) {
			if(shu3<0) {shu3=(-shu3)%10;dashu=char(shu3+48);dashustr.insert(dashustr.begin(),dashu);}
	    	else {dashu=char(shu3+48);dashustr.insert(dashustr.begin(),dashu);	}
		}
	}
	}
	else if(e<=2){
    	int shu;char dashu;
    	shu=atoi(vfir[0].c_str())-jinwei;
    	if(shu<0) {/*shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);*/}
    	else {dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);}
}
	}//if到此为止 ，多减一完成 
	
	else {//实现多减多 
	for(b=e-1,q=f-1;b>=e-f;b--,q--) {
		int shu,shu2,shu3,shu4;char dashu;
		shu=atoi(vfir[b].c_str())-atoi(vsec[q].c_str())-jinwei;
		if(b==e-f) {
        	if(shu<0) {jinwei1=1;shu=shu+10;shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);break;			}
            else {jinwei1=0;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);break;	}
		}
		if(shu<0) {
			jinwei=1;shu=10+shu;shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);		}
        else {jinwei=0;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);			}
	   }
       	for(b=e-f-1;b>=0;b--) {
    	int shu,shu2;char dashu;
    	shu=atoi(vfir[b].c_str())-jinwei1;
    	if(b==0) {
    		if(shu<0) {break;}
    		else {dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);break;}
		}
    	if(shu<0) {jinwei1=1;shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);}
    	else {jinwei1=0;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);	}
	}
}//else 到这里结束 ，目前大数加（长减短）已完成 
/*for(int li=0;li<dashustr.size();li++) {
	cout << dashustr[li];
}//循环输出 */
}//大循环(e>f)到此为止 

else if(e==f){  //位数相同（e=f）时的情况 已完成 
	if(e>1) {
		for(b=0;b<e;b++) {
		if(atoi(vfir[b].c_str())>atoi(vsec[b].c_str())) {date=1;break;		}
        else if (atoi(vfir[b].c_str())==atoi(vsec[b].c_str())) {continue;		}
		else {date=0;break;}                                              //1代表vfir大，0代表vstr大 
	}//cout << date<< endl;
		for(q=1;q<e;q++) {    //当e,f不为 1 时  
	int shu,shu2;char dashu;
	if(date==0){
		shu=atoi(vsec[q].c_str())-atoi(vfir[q].c_str());shu2=atoi(vsec[q-1].c_str())-atoi(vfir[q-1].c_str());
	if(q==1) {
		if(shu<0) {shu=shu+10;shu=shu%10;shu2--;}	else shu=shu%10;
		if(shu2<0) {shu2=abs(shu2)%10;dashu=char(shu2+48);dashustr.push_back(dashu);}
		else {dashu=char(shu2+48);dashustr.push_back(dashu);}
		dashustr.insert(dashustr.begin(),45);
	         }
	else {
		if(shu<0) {shu=(shu+10)%10;shu2--;}	else shu=shu%10;
		shu2=abs(10+shu2)%10;dashu=char(shu2+48);dashustr.push_back(dashu);
	}    
	if(q==e-1){	shu=abs(shu)%10;dashu=char(shu+48);dashustr.push_back(dashu);}
	}
	else if(date==1) {                                                      //vfir大，将其交换 
		shu=atoi(vfir[q].c_str())-atoi(vsec[q].c_str());shu2=atoi(vfir[q-1].c_str())-atoi(vsec[q-1].c_str());
	if(q==1) {
		if(shu<0) {shu=shu+10;shu=shu%10;shu2--;}	else shu=shu%10;
		if(shu2<0) {shu2=abs(shu2)%10;dashu=char(shu2+48);dashustr.push_back(dashu);}
		else {dashu=char(shu2+48);dashustr.push_back(dashu);}
	         }
	else {
		if(shu<0) {shu=(shu+10)%10;shu2--;}	else shu=shu%10;
		shu2=abs(10+shu2)%10;dashu=char(shu2+48);dashustr.push_back(dashu);
	}    
	if(q==e-1){	shu=abs(shu)%10;dashu=char(shu+48);dashustr.push_back(dashu);}
	}
	}/*for(int li=0;li<dashustr.size();li++) {
	cout << dashustr[li];}*/
	}//if(e>1)在此结束 
	else if(e==1) {  //当e，f为 1 时 
		int shu,shu2;char dashu;
		shu=atoi(vfir[0].c_str())-atoi(vsec[0].c_str());
		if(shu<=0) {shu=abs(shu)%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);dashu=char(45);dashustr.insert(dashustr.begin(),dashu);}
		else {dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);}
		for(int li=0;li<dashustr.size();li++) {
	cout << dashustr[li];}
	} //"1"减"1"的情况解决 
	}//多减多（相同）已解决 
	
	
else {        //此时e<f 
	if(e==1) {
	int shu,shu2,shu3,shu4;char dashu;
	shu=atoi(vsec[f-1].c_str())-atoi(vfir[0].c_str());//末位数相减 
	if(shu<0) {	shu=atoi(vsec[f-1].c_str())+10;shu=shu-atoi(vfir[0].c_str());jinwei=1;	}
	else shu=shu;dashu=char(shu+48);dashustr.push_back(dashu);
	if(f>2){                                         //实现一位减多位 
		for(b=f-2;b>=1;b--) {
    	shu2=atoi(vsec[b].c_str())-jinwei;shu3=atoi(vsec[b-1].c_str());
    	if(shu2<0) {
    		jinwei=1;shu2=(-shu2)%10;dashu=char(shu2+48);dashustr.insert(dashustr.begin(),dashu);
    		shu3--;	}
		else {dashu=char(shu2+48);dashustr.insert(dashustr.begin(),dashu);jinwei=0;}		
		if(b==1) {
			if(shu3<0) {shu3=(-shu3)%10;dashu=char(shu3+48);dashustr.insert(dashustr.begin(),dashu);}
	    	else {dashu=char(shu3+48);dashustr.insert(dashustr.begin(),dashu);	}
		}
	}
	}
	else if(f<=2){
    	int shu;char dashu;
    	shu=atoi(vsec[0].c_str())-jinwei;
    	if(shu<0) {}
    	else {dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);}
}
        dashustr.insert(dashustr.begin(),45);
	}//if到此为止 ，一减多完成 
	
	else {//实现多减多 
	for(b=f-1,q=e-1;b>=f-e;b--,q--) {
		int shu,shu2,shu3,shu4;char dashu;
		shu=atoi(vsec[b].c_str())-atoi(vfir[q].c_str())-jinwei;
		if(b==f-e) {
        	if(shu<0) {jinwei1=1;shu=shu+10;shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);break;			}
            else {jinwei1=0;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);break;	}
		}
		if(shu<0) {
			jinwei=1;shu=10+shu;shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);		}
        else {jinwei=0;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);			}
	   }
       	for(b=f-e-1;b>=0;b--) {
    	int shu,shu2;char dashu;
    	shu=atoi(vsec[b].c_str())-jinwei1;
    	if(b==0) {
    		if(shu<0) {break;}
    		else {dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);break;}
		}
    	if(shu<0) {jinwei1=1;shu=shu%10;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);}
    	else {jinwei1=0;dashu=char(shu+48);dashustr.insert(dashustr.begin(),dashu);	}
	}
	dashustr.insert(dashustr.begin(),45);
}//else 到这里结束 ，目前大数加（短减长）已完成 
}
cout << "两大数之差为="; 
for(int li=0;li<dashustr.size()-1;li++) {
	if(dashustr[li]=='0'&&dashustr[li+1]=='0') a++;}
if(dashustr[0]!='0'){
	for(int li=0;li<dashustr.size();li++) {
	cout << dashustr[li];
}}
else {for(int li=a+1;li<dashustr.size();li++) {
	cout << dashustr[li];
}}                                                             //调整输出格式 
//大数减法已完成，同位相减，小减大，大减小完成 
cout << endl;
	}
	void dashucheng(string str1,string str2)
	{
		cout <<"大数乘法为完成" << endl; 
	}
	private:
		int a=0,b,c,e,f,q,jinwei=0,jinwei1=0,date;
		vector<string> vfir; //第一个数串 
    vector<string> vsec; //第二个数串 
    vector<char> dashustr;  //输出时用的字符串 
    string m; 
};

int main()
{
	cout <<"大数加减法，第一行输入一个任意位数数字，第二行输入任意位数数字，第三四行输出相加，相减 "<< endl;
	int a=0,b,c,e,f,q,jinwei=0,jinwei1=0,date;
    vector<string> vfir; //第一个数串 
    vector<string> vsec; //第二个数串 
    vector<char> dashustr;  //输出时用的字符串 
    Box Box1;
    Box Box2;
    Box Box3;
	string m; 
	string str1;
	string str2;
	
	cin >> str1;//将string导入 vfir
	e=str1.size();//e为vfir的长度 
    for(b=0;b<e;b++) {
		m=str1[b];
		vfir.push_back(m);
	}
	cin >> str2;//将string导入vsec 
	f=str2.size();//f为vsec的长度 
	for(b=0;b<f;b++) {
		m=str2[b];
		vsec.push_back(m);
	} 

/*for(b=0;b<e;b++) 
{cout << vfir[b] ;}
cout << endl;
//输出检验 
for(b=0;b<f;b++) 
{cout << vsec[b] ;}
cout << endl;*/
Box1.dashujiafa(str1,str2);
Box2.dashujianfa(str1,str2);
Box3.dashucheng(str1,str2);
//大数加减法已完成，同位相减，小减大，大减小完成 
    return 0;
}
