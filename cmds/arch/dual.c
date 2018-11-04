// dual.c
// this file does nothing if no shell's enabled.
int main(object me, string arg, string flag1)
{
   int flag;
   if (!SECURITY_D->valid_grant(me, "(arch)") 
       && flag1 != "call")
        return 0;

   flag = (int)me->query("env/dual_type");

   if (flag)
       return (int)me->evaluate_shell(arg, flag);

   printf("%O\n", me->evaluate_shell(arg, 0));

   return 1;

}

int help(object me)
{
 write(@HELP
ָ���ʽ : dual [detail]

���ָ�����ִ��һ�ε�����LPC���롣
����ʹ��var������˽�б�����

����öδ���û�з���ֵ��������Ҫʹ��һ����ϵĴ���Ρ�
�������û������� dual_type

��Unix��ͬ����Ҳ����ʹ�� ` ���ŵ���Ƕ�����ʽ��
����Ҫ���� use_shell ����������
���Ǹô�������з���ֵ��
���� chat I am `me->short()`, at `here->query("short")`
���ȼ���� me->short() �� here->query("short") ��ֵ��Ȼ�����滻���
�֣� `here->query("exits")[random(here->query("exits"))]`
�������ѡ��ǰ�����һ���������ߡ�

HELP
   );
   return 1;
}

