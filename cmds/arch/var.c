// var.c
// define var
// poet modified to use F_SHELL
// poet modified to use free command style
#include <shell.h>

int main(object me, string arg)
{
   mixed result;
   string name, value;
   int index;

   if (!arg)
   {
       mapping vars;
       string content;

      if (!SECURITY_D->valid_grant(me, "(arch)"))
                return 0;

       vars = me->query_all_vars();

       content = "����ǰ���õ�˽�б����У�\n";

       content += sprintf("me\t: %s\t== %O\n", typeof(me), me);
       content += sprintf("here\t: %s\t== %O\n",
           typeof(environment(me)), environment(me));
       foreach(name in keys(vars))
       {

           if (undefinedp(vars[name]) || nullp(vars[name]))
               content += sprintf("%s\t: void\n", name);
           else
               content += sprintf("%s\t: %s\t== %O\n", name,
                 typeof(vars[name]), vars[name]);
       }

       tell_object(me, content);
       return 1;
   }

   index = strsrch(arg, '=');

   if ( index == -1 )
   {
       name = arg;
   } else
   {
       name = arg[0..(index-1)];
       value = arg[(index+1)..<1];
   }

   name = replace_string(name, " ", "");

   if ( name == "me" || name == "here" )
   {
       return notify_fail("����ϵͳԤ�����˽�б�����\n");
   }

   if ( !value )
   {
       if (undefinedp(result) || nullp(result))
           printf("%s\t: void\n", name);
       else
           printf("%s\t: %s\t== %O\n", name,
               typeof(me->query_var(name)), me->query_var(name));
       return 1;
   }

   if ( value == "none" || value == " none"
     || value == "null" || value == " null" )
   {
       me->delete_var(name);
       printf("Delete var '%s' Ok.\n", name);


       return 1;
   }

   if (me->query_var_count() >= MAX_VAR_COUNT)
       return notify_fail("�벻Ҫ���ù����˽�б�����\n");

   result = me->evaluate_shell(value, 0);

   result = me->set_var(name, result);

   if (undefinedp(result) || nullp(result))
       printf("%s\t: void\n", name);
   else
       printf("%s\t: %s\t== %O\n", name, typeof(result), result);

   return 1;
}

int help(object me)
{
   write(@HELP
ָ���ʽ : var name=value


���ָ���������˽�б��������� value ���﷨�� LPC ������ȫ��ͬ��
���������� dual ������Ƕ shell ��ʹ�ã����� export ������������ȥ��

����ʹ�� var �����г�Ŀǰ��˽�б����б�

ϵͳ��Ԥ������� me �� here

HELP
   );
   return 1;
}

