#include<stdio.h>
#include<math.h>
#include<string.h>
#include<cstdlib>
#define MAXN (int)500
#define ll long long
#define my_num 20212796
FILE *fp;
int n=0,m,k;//k为操作指令，n学生数量，m考试科目数量;
char exam_name[MAXN][MAXN];//exam_name[i]为第i门考试的名称
struct student{
    char name[MAXN];//name->名称
    int val[MAXN];//val[i]为第i门考试成绩
    ll num;//学号
}stu[MAXN<<2];
//函数声明
int check(ll testnum);
int find(ll testnum);
void del(int cnt);
void print_stu(int cnt);
void query();
void addstu();
void modify();
void output_list();
//
int check(ll testnum){//判断学号是否出现过
    for(register int i=1;i<=n;i++)
        if(testnum==stu[i].num)
            return 1;
    return 0;
}
int find(ll testnum){//查询学号所对应的结构体的序号
	int num; 
    for(int i=1;i<=n;i++)
        if(stu[i].num==testnum)
            num=i;
    return num;
}
void del(int cnt){//该函数的作用是删除编号为cnt的学生的信息
    //为了方便起见，这里直接用后面的学生信息覆盖掉该学生的信息
    for(int i=cnt;i<=n-1;i++){
        stu[i]=stu[i+1];
    }
    n--;//人数减1
    return ;
}
void query(){//查询学生信息
    printf("请输入您要查询的学生的学号:");
    ll asknum;
    while(scanf("%lld",&asknum)){
        if(check(asknum)==0){
            printf("不存在该学号,请重新输入:");
        }
        else break;
    }
    printf("已查询到学号为%lld学生的信息:",asknum);
    print_stu(find(asknum));
    printf("查询已完成,输入1继续查询,输入0返回主界面:");
    int tempk;
    scanf("%d",&tempk);
    if(tempk==1)query();
    else return;
} 
void addstu(){//添加学生信息
    if(m==0){
        printf("检测到当前无考试科目信息,请先添加考试科目信息\n");
        printf("请输入考试科目的总数量:");
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            printf("请输入第%d门考试的名称:",i);
            scanf("%s",exam_name[i]);
        }
	printf("考试信息添加成功，下面添加学生信息:\n");
    }//放在前面，方便后续输入学生的成绩 
    printf("请输入要添加的学生学号:");
    ll tempnum;
    while(scanf("%lld",&tempnum)){//check一下学号是否存在过
        if(check(tempnum))
            printf("该学号已存在，请重新输入:");
        else break;
    }
    stu[++n].num=tempnum;
    printf("请输入学生姓名:");
    scanf("%s",stu[n].name);
    printf("当前共有%d门考试\n",m);
    for(int i=1;i<=m;i++){
        printf("考试名称:%s,该生考试成绩为:",exam_name[i]);
        scanf("%d",&stu[n].val[i]);
    }
    printf("学生信息添加成功!");
    printf("当前共有%d名学生\n",n);
    printf("继续执行请输入1,返回界面请输入0:");
    int temp;
    scanf("%d",&temp);
    if(temp==1)addstu();
    else return;
}
void modify(){
    printf("请选择您要修改/删除的学生信息的学号:");
    ll asknum;
    while(1){
        scanf("%lld",&asknum);
        if(check(asknum)==0){
            printf("不存在该学号,输入1重新输入学号,输入0返回主界面:");
            int tempk;
            scanf("%d",&tempk);
            if(tempk==1)modify();
            else return;
        }
        break;
    }
    int cnt=find(asknum);
    int tempk;
    while(1){
        printf("请输入相应数字执行操作:\n1->修改信息\n2->删除信息\n");
        printf("你的选择:");
        scanf("%d",&tempk);
        if(tempk!=1&&tempk!=2){
            printf("您输入的数字格式不正确,请重新输入:");
            continue;
        }
        else break;
    }
    //````修改学生信息部分
    if(tempk==1){
        printf("请确定您要进行修改的部分:\n");
        int tempk1;
        printf("请输入相应数字执行操作:\n1->修改姓名\n2->修改学号\n3->修改成绩");
        while(scanf("%d",&tempk1)){
            if(tempk1>=1&&tempk1<=3)
                break;
            else{
                printf("您输入的数字格式不正确,请重新输入:");
                continue;
            }
        }
        if(tempk1==1){//修改姓名
            char newname[MAXN];
            printf("请输入您要修改的新名字:");
            scanf("%s",newname);
            strcpy(stu[cnt].name,newname);
            printf("该学生的姓名成功修改为:%s\n",newname);
            printf("继续执行请输入1,返回界面请输入0:");
            int temp;
            scanf("%d",&temp);
            if(temp==1)addstu();
            else return;
        }
        if(tempk1==2){//修改学号
            ll newnum;
            printf("请输入您要修改的新学号:");
            while(scanf("%lld",&newnum)){
                if(check(newnum))
                    printf("该学号已存在,请重新输入:");
                else break;
            }
            stu[cnt].num=newnum;
            printf("该学生的学号成功修改为:%lld\n",newnum);
            printf("继续执行请输入1,返回主界面请输入0:");
            int temp;
            scanf("%d",&temp);
            if(temp==1)modify();
            else return;
        }
        if(tempk1==3){
            print_stu(cnt);
            printf("请输入你要修改的科目编号(从1开始依次增大):");
            int modify_num;
            scanf("%d",&modify_num);
            printf("该科目名称为:%s ,请输入修改后的成绩:",exam_name[modify_num]);
            scanf("%d",&stu[cnt].val[modify_num]);
            printf("修改成功！\n");
            printf("继续执行请输入1,返回主界面请输入0:");
            int temp;
            scanf("%d",&temp);
            if(temp==1)modify();
            else return;
        }
    }
    //````这里是删除信息部分
    if(tempk==2){
        int cnt=find(asknum);
        printf("姓名:%s,学号:%lld的学生信息已被删除\n",stu[cnt].name,asknum);
        del(cnt);
        printf("删除信息成功!当前学生数量:%d\n",m);
        printf("继续执行请输入1,返回主界面请输入0:");
        int temp;
        scanf("%d",&temp);
        if(temp==1)modify();
        else return;
    }
    return ;
}
void output_list(){
    printf("``````````````````````````````\n");
    printf("学生成绩管理系统:\n");
    printf("1. 添加学生信息\n");
    printf("2. 查询学生信息\n");
    printf("3. 删除/修改学生信息\n");
    printf("4. 排序学生信息\n");
    printf("5. 从文件中读入信息\n");
    printf("6. 导出成绩信息文件\n");
    printf("7. 输出所有学生的成绩\n");
    printf("0. 退出系统");
}
int stu_sum(int cnt){//返回一个学生的总成绩
    int ans=0;
    for(int i=1;i<=m;i++)
        ans+=stu[cnt].val[i];
    return ans;
}
double stu_ave(int cnt){//返回一个学生的平均成绩
    return ((double)stu_sum(cnt))/((double)m);
}
void print_stu(int cnt){//输出学生信息
    printf("姓名:%s 学号:%lld\n",stu[cnt].name,stu[cnt].num);
    printf("考试成绩:\n");
    for(int i=1;i<=m;i++)
        printf("科目名称 : %s , 成绩=%d\n",exam_name[i],stu[cnt].val[i]);
    printf("总成绩 = %d\n",stu_sum(cnt));
    printf("平均成绩 = %.2lf\n",stu_ave(cnt));
    return ;
}
void sort_stu(){
//这里牵扯到以学号，总成绩为基准的正序和逆序排序
//由于数据量较小，这里使用时间复杂度O(n^2)的冒泡排序可以减少代码量
    printf("若以总分为基准进行排序请输入1,以学号大小(这里采用整数比较大小)为基准进行排序请输入2:");
    int choice1;
    while(scanf("%d",&choice1)){
        if(choice1!=1&&choice1!=2)
            printf("格式错误!请重新输入:");
        else break;
    }
    printf("升序排序请输入1,降序排列请输入2:");
    int choice2;
    while(scanf("%d",&choice2)){
        if(choice2!=1&&choice2!=2)
            printf("格式错误!请重新输入:");
        else break;
    }
//这里直接判断四种情况并进行排序
    if(choice1==1&&choice2==1){//总分升
        for(int i=1;i<=n-1;i++)
            for(int j=i+1;j<=n-i;j++){
                if(stu_sum(j)>stu_sum(j+1)){
                    student temp;
                    temp=stu[j];
                    stu[j]=stu[j+1];
                    stu[j+1]=temp;
                }
            }
    }
    if(choice1==1&&choice2==2){//总分降
        for(int i=1;i<=n-1;i++)
            for(int j=i;j<=n-i;j++){
                if(stu_sum(j)<stu_sum(j+1)){
                    student temp;
                    temp=stu[j];
                    stu[j]=stu[j+1];
                    stu[j+1]=temp;
                }
            }
    }
    if(choice1==2&&choice2==1){//学号升
        for(int i=1;i<=n-1;i++)
            for(int j=i+1;j<=n-i;j++){
                if(stu[j].num>stu[j+1].num){
                    student temp;
                    temp=stu[j];
                    stu[j]=stu[j+1];
                    stu[j+1]=temp;
                }
            }
    }
    if(choice1==2&&choice2==2){//学号降
        for(int i=1;i<=n-1;i++)
            for(int j=i+1;j<=n-i;j++){
                if(stu[j].num<stu[j+1].num){
                    student temp;
                    temp=stu[j];
                    stu[j]=stu[j+1];
                    stu[j+1]=temp;
                }
            }
    }
    printf("排序成功!\n");
}
int main(){
    while(1){
        output_list();
        scanf("%d",&k);
        while(k<0||k>=8){
            printf("无效命令，请重新输入:");
            scanf("%d",&k);
        }
        switch(k){
            case 1:
                addstu();
                break;
            case 2:
                query();
                break;
            case 3: 
                modify();
                break;
            case 4:
                sort_stu();
                break;
            case 5:
                freopen("in.txt","r",stdin);     //从in.txt 中读入数据
                freopen("out.txt","w",stdout);
                printf("已从in.txt文件中读入数据，并将其写入out.txt文件中\n");
                break;
            case 6:
                printf("导出out.txt文件成功!");
                if(freopen("out.txt","w",stdout)==NULL)
                    fprintf(stderr,"error\n");
                for(int i=1;i<=n;i++){
                    print_stu(i);
                    printf("\n");
                }
                fclose(stdout);
                break;

            case 7: 
                for(int i=1;i<=n;i++){
                    print_stu(i);
                    printf("\n");
                }
                break;
            case 0:
                printf("系统关闭");
                return 0;
                break;
        }
    }
    return 0;
}
