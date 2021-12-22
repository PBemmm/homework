#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAXN (int)500
int n=0,m;
char k,exam_num[MAXN][MAXN];//exam_num[i]为第i门考试的名称
struct student{
    char num[MAXN],name[MAXN];//num->学号,name->名称
    int val[MAXN];//val[i]为第i门考试成绩
}stu[MAXN<<2];
void addstu(){
    n++;
    printf("请输入要添加的学生学号:");
    scanf("%s",stu[n].num);
    printf("请输入要添加的学生姓名:");
    scanf("%s",stu[n].name);
    if(m==0){
    	printf("检测到当前无考试科目信息,请添加考试科目信息\n");
    	printf("请输入考试科目的总数量:");
    	scanf("%d",&m);
    	for(int i=1;i<=m;i++){
    		printf("请输入第%d门考试的名称:",i);
            scanf("%s",exam_num[i]);
		}
	}
    printf("当前共有%d门考试\n",m);
    for(int i=1;i<=m;i++){
        printf("考试名称:%s,该生考试成绩为:",exam_num[i]);
        scanf("%d",&stu[n].val[i]);
    }
    printf("学生信息添加成功!\n");
    printf("当前共有%d名学生")
}
void output_list(){
    printf("学生成绩管理系统:\n");
    printf("1. 添加学生信息\n");
    printf("2. 查询学生信息\n");
    printf("3. 删除/修改学生信息\n");
    printf("4. 排序学生信息\n");
    printf("5. 从读入信息\n");
    printf("6. 导出信息文件\n");
}
int main(){
    while(1){
        output_list();
        k=getchar();
        if(k=='1') addstu();
        if(k=='2');
        if(k=='3');
        if(k=='4');
        if(k=='5');
        if(k=='6');
        if(k=='7');
        if(k=='8');
        if(k=='9');
        if(k=='W');
        if(k=='R');
        if(k=='0');
    }
    return 0;
}