// emote.c (Mon  09-04-95)

#include <ansi.h>

inherit F_CLEAN_UP;
 
int main(object me, string str)
{
        string prefix;
        object env;
        mixed info;

        if (me->ban_say())
                return 0;

        env = environment(me);
        if (info = env->query("no_say"))
        {
                if (stringp(info))
                {
                        write(info);
                        return 1;
                }

                write("����ط���������������\n");
                return 1;
        }

        if (me->query("doing") == "scheme")
        {
                if (me->query("jing") < 100)
                        return notify_fail("�����ڵľ��񲻼ã���һ����ɡ�\n");
                me->add("jing", -50);
        }

        if (! str)
        {
                write(CYN"�㿴��������ḻ��\n"NOR);
                tell_room(env, CYN + (string)me->name()+
		          "����������ḻ��\n" + NOR, me);
                return 1;
        }

        prefix = me->query("env/no_prefix") ? "" : "~";
        write(CYN "��" + str + "\n" NOR);
        tell_room(env, CYN + prefix + (string)me->name() +
                  str + "\n" NOR, me);
        return 1;
}
 
int help(object me)
{
	write(@HELP
ָ���ʽ: emote <������>

���ָ�����������һ��ϵͳû��Ԥ��Ķ�����, ϵͳ�Ὣ��������
�����ּ��������������ʾ��������ͬһ���ط������￴��Ϊ�˱�����
������, ���������Ĵʾ�ǰ������ ~ �Թ�����

����: emote ����������
��ῴ��: ������������
�����˻ῴ��: ~��������������

����, ���Ӿ����������.

���ָ��: semote
HELP );
        return 1;
}
