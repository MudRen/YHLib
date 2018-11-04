// accede.c
// ϵͳ���� ultra_quest ������ļ�

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        mapping q;
        string type;

        while (arg)
        {
                // û�������򷵻�
                if (! me->query("ultra_quest/quest"))
                        return notify_fail("�ղ�û������Ѱ�������\n");

                // �鿴��ǰ ultra_quest ���������״̬
                if (! stringp(type = me->query("ultra_quest/quest/type"))
                   || (type != "mathematics"            // ��������
                   && type != "literate"                // ����ʫ��
                   && type != "chess"                   // �����弼
                   && type != "calligraphy"             // ��æ�鷨
                   && type != "drawing"                 // ��æ�滭
                   && type != "medical"))               // ��æ�β�
                        return notify_fail("�ղ�û������Ѱ�������\n");

                if (! objectp(ob = present(arg, environment(me))))
                        return notify_fail("����û������ˡ�\n");

                if (ob->query_temp("need_accede/user") != me->query("id")) 
                        return notify_fail(CYN + ob->name() + CYN "����"
                                           "�������������˭��������ʲô"
                                           "�£�\n" NOR);

                if (ob == me)
                        return notify_fail("�Լ�Ӧ���Լ���\n");

                if (me->is_fighting())
                        return notify_fail("�㻹�Ǵ������˵�ɡ�\n");

                if (me->is_busy())
                        return notify_fail("�㻹���п�����˵�ɡ�\n");

                if (! ob->query("can_speak"))
                        return notify_fail("�������ˮ��\n");

                if (! living(ob))
                        return notify_fail("�㻹�ǵ�" + ob->name() +
                                           "���˺���˵�ɡ�\n");

                if (ob->is_fighting())
                        return notify_fail("�㻹�ǵ�" + ob->name() +
                                           "�������˵�ɡ�\n");

                if (ob->is_busy())
                        return notify_fail("�㻹�ǵ�" + ob->name() +
                                           "æ������˵�ɡ�\n");

                notify_fail(CYN + ob->name() + CYN "�����������������˭"
                            "��������ʲô�£�\n" NOR);

                return ob->need_accede(me);
        }
        write("�����Ӧ��˭��\n");
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��accede <ĳ��>

���ָ���������Ӧ��ĳЩ�˶��������Ҫ��
HELP);
        return 1;
}
