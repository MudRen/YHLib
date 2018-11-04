// detach.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob, old_app;
        mapping family, skills;
        int i;
        string *skname;

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if (! arg)
                return notify_fail("ָ���ʽ��detach|tuoli [cancel]|<����>\n");

        if (arg == "cancel")
	{
                old_app = me->query_temp("pending/deatch");
                if( !objectp(old_app) )
                        return notify_fail("�����ڲ�û���������ʦ�����뷨��\n");
                write("��ı����ⲻ������ʦ���ˡ�\n");
                tell_object(old_app, me->name() + "�ı����ⲻ������ʦ���ˡ�\n");
                me->delete_temp("pending/detach");
                me->delete_temp("pending/want");
                return 1;
        }

        if (! me->query_temp("pending/want"))
        {
                tell_object(me, HIR "\n��ע�⣬һ��������ʦ�ţ����ᱻ�ϳ�������"
                                "�������书��\n" NOR + HIC "��������˾��ģ���"
                                "������һ���������\n" NOR);
                me->set_temp("pending/want", 1);
                return 1;
        }

        if (! (ob = present(arg, environment(me))) ||
            ! ob->is_character())
        {
                me->delete_temp("pending/want");
                write("�����˭�Ͼ�ʦͽ��ϵ��\n");
                return 1;
        }

        if (ob == me)
        {
                me->delete_temp("pending/want");
                write("������Լ��Ͼ�ʦͽ��ϵ��\n");
                return 1;
        }

        if (! living(ob))
        {
                me->delete_temp("pending/want");
                write("������Ȱ�" + ob->name() + "Ū�ѡ�\n");
                return 1;
        }

        message_vision(CYN "\n$N" CYN "��$n" CYN "����һ��ͷ��˵����ʦ"
                       "�����ҡ���������ʦ�š�\n" NOR, me, ob);

        if (! me->is_apprentice_of(ob))
	{
                if (ob->query("family/family_name") == me->query("family/family_name"))
                {
                        me->delete_temp("pending/want");
                        message_vision(CYN "$N" CYN "���һ������$n" CYN "����ʲ"
                                       "��ʲô����Ҫ����ʦ�ţ����¿ɵ�����ʦ��ȥ"
                                       "��\n" NOR, ob, me);
                        return 1;
                } else
		{
                        me->delete_temp("pending/want");
                        message_vision(CYN "$N" CYN "���˿����ڵ��ϵ�$n" CYN "��"
                                       "��Цһ�����������ֲ�����ʦ��������������"
                                       "\n" NOR, ob, me);
                        return 1;
		}
        }

        me->set_temp("pending/detach", 1);
        tell_object(ob, me->name() + "������ʦ�š�\n");
        ob->attempt_detach(me);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : detach|tuoli [cancel]|<����>
 
���ָ�������������ʦ����������ʦ�ţ���Ϊһ��Ĵ����ɲ�Ը���
����ʦ���ˣ�������������Ͷ�������ɣ���ð��չ������ʦ�ţ�Ȼ
��һ������ʦ�ţ�ʦ����׷��������ѧ���ı�����ѧ����׷�ز�������
�书��֪ʶ�����ܵ��κ�Ӱ�졣

��ο����ָ�� expell
HELP );
        return 1;
}
