// quest.c

#include <ansi.h>
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        mapping q;
        string master;
/*
        write("�ڲ����Դ�ָ����ʱ�رգ�\n");
        return 1;
*/

        if (arg)
        {
                if (arg == "cancel")
                {
                        if (! stringp(master = me->query("quest/master_id")))
                                return notify_fail("������������������\n");

                        if (! objectp(ob = present(master, environment(me))))
                                return notify_fail("������������Ǹ������ڲ�������ɣ�\n");
                } else

                if (! objectp(ob = present(arg, environment(me))))
                        return notify_fail("����û������ˣ�����ô������\n");

                if (ob == me)
                        return notify_fail("�Լ�û�취���Լ�������\n");

                if (! living(ob))
                        return notify_fail("�㻹�ǵ�" + ob->name() + "������˵�ɣ�\n");

                if (me->is_fighting())
                        return notify_fail("ר�Ĵ���ļܣ�\n");

                if (me->is_busy())
                        return notify_fail("�㻹���п����ٺ�" + ob->name() + "̸��Щ����"
                                            "�ɣ�\n");

                if (ob->is_fighting())
                        return notify_fail("�㻹�ǵ�" + ob->name() + "�������˵�ɣ�\n");

                if (ob->is_busy())
                        return notify_fail(ob->name() + "��æ���أ�û�������㡣\n");

                if (! ob->query("can_speak"))
                        return notify_fail("����û��˵������" + ob->name() + "������ġ�\n");

                if (! ob->query("family/family_name"))
                        return notify_fail(CYN + ob->name() + CYN "������һ�ۣ������ص���"
                                           "���ֲ��ǹ�ͷ����Ϲ����ʲô��\n" NOR);

                if (ob->query("family/family_name") != me->query("family/family_name")) 
                        return notify_fail(CYN + ob->name() + CYN "����������������ֲ���"
                                           "����" + ob->query("family/family_name") + CYN
                                           "�ģ�����ʲô�ң�\n" NOR);

                notify_fail(CYN + ob->name() + "��ü�����Ҳ���������������"
                                   "ȥ�������˰ɡ�\n" NOR);
                return (arg == "cancel" ? ob->cancel_quest(me)
                                        : ob->ask_quest(me));
        }

        if (me->query("quest_count"))
                write(sprintf("ʦ����������������Ѿ���������� %d ����\n",
                              me->query("quest_count")));
 
        if (! mapp(q =  me->query("quest")))
        {
                write("������û�����κ�����\n");
                return 1;
        }

        switch (q["type"])
        {
        case "kill":
                write(q["master_name"] + "�Ը�����" + CHINESE_D->chinese_monthday(q["limit"]) +
                      "֮ǰ����" HIR + q["name"] + NOR "����ͷ����" + q["family"] + "���\n" +
                      "��˵����ǰ����������" + q["place"] + "��û��\n");
                return 1;

        case "letter":
                write(q["master_name"] + "�Ը�����" + CHINESE_D->chinese_monthday(q["limit"]) +
                      "֮ǰ���ż��͵�" HIC + q["name"] + NOR "���У�ȡ��ִ���\n" +
                      "���Ų���ǰ����������" + q["place"] + "��\n");
                return 1;
        }

        write("������û�����κ�����\n");
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : quest  ���ָ�����������������ɵ����Ż����ҳ���
��ȡ������������κβ�������ʾ���㵱ǰ������
HELP );
        return 1;
}
