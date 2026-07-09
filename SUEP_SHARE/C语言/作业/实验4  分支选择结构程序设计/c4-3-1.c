/* c4-3-1.c */
#include <stdio.h>
int main()
{
	float price,origin,final1,final2,k;
	int num,w1,w2;
	printf("请输入商品单价：");
	scanf("%f",&price);
	printf("请输入商品数量：");
	scanf("%d",&num);
	origin=price*num;
	if (num==1) k=1.0;
	else if (num==2) k=0.85;
	else k=0.7;
	w1=(int)(origin/300);
	w2=(int)(origin*k/300);
	final1=(origin-w1*30)*k;
	final2=origin*k-w2*30;
	if (final1>final2) printf("最优方案为享受规则①再享受规则②\n最低价格为：%.2f",final2);
	else if(final1<final2) printf("最优方案为享受规则②再享受规则①\n最低价格为：%.2f",final1);
	else printf("两种方案价格相同\n最低价格为：%f",final2);
	return 0;
}