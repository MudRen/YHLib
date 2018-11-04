// bug.c
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        object ob;

        string sp, add;
        int bug, bugp;

        seteuid(getuid(me));

        if (! arg)
                ob = me;
        else
        if (wizardp(me) && wiz_level(me) >= 3)
        {
                // ��� bug ����
                if (sscanf(arg, "+ %s %d", arg, bug) == 2)
                {
                        if (! objectp(ob = find_player(arg)))
                                ob = UPDATE_D->global_find_player(arg);
                        if (! objectp(ob))
                                return notify_fail("��Ҫ���˭�ı����"
                                                   "����\n");
                        if (bug <= 0)
                                return notify_fail("�㵽��������ӻ���"
                                                   "���٣�\n");
                        ob->add("bug", bug);
                        sp = sprintf("�û� " WHT "%s" NOR " �ı������"
                                     "������ " WHT "%d" NOR " �㣬��Ϊ"
                                     WHT " %d " NOR "�㡣\n", arg, bug,
                                     ob->query("bug", 1));

                        tell_object(ob, HIG + me->name() + "��������� " +
                                        bug + " �㱨�������\n" NOR);

                        log_file("static/bug", sprintf("%s wizard %s a"
                                 "dd   %d bug point to user %s.\n",
                                 log_time(), log_id(me), bug, log_id(ob)));

                        UPDATE_D->global_destruct_player(ob);

                        tell_object(me, sp);
                        return 1;
                }
                // ���� bug ����
                if (sscanf(arg, "- %s %d", arg, bug) == 2)
                {
                        if (! objectp(ob = find_player(arg)))
                                ob = UPDATE_D->global_find_player(arg);
                        if (! objectp(ob))
                                return notify_fail("��Ҫ����˭�ı����"
                                                   "����\n");
                        if (bug <= 0)
                                return notify_fail("�㵽��������ٻ���"
                                                   "��ӣ�\n");
                        if (ob->query("bug") < 0)
                                ob->set("bug", 0);
                        ob->add("bug", -bug);

                        sp = sprintf("�û� " WHT "%s" NOR " �ı������"
                                     "������ " WHT "%d" NOR " �㣬��Ϊ"
                                     WHT " %d " NOR "�㡣\n", arg, bug,
                                     ob->query("bug", 1));

                        tell_object(ob, HIG + me->name() + "��������� " +
                                        bug + " �㱨�������\n" NOR);

                        log_file("static/bug", sprintf("%s wizard %s m"
                                 "inus %d bug point to user %s.\n",
                                 log_time(), log_id(me), bug, log_id(ob)));

                        UPDATE_D->global_destruct_player(ob);

                        tell_object(me, sp);
                        return 1;
                }
                
                ob = present(arg, environment(me));
                if (! ob || ! ob->is_character()) ob = find_player(arg);
                if (! ob || ! ob->is_character()) ob = find_living(arg);
                if (! ob || ! ob->is_character())
                        return notify_fail("��Ҫ�쿴˭�ı��������\n");

                if (! userp(ob))
                        return notify_fail("ֻ����Ҳž��д˲�����\n");
                        
        } else
                return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
 
        bug = ob->query("bug", 1);

        if (! bug)
                sp = ((ob == me ? "��" : ob->name()) + "��" +
                         MUD_NAME + NOR "�����ޱ�����κδ���\n");
        else
                sp = ((ob == me ? "��" : ob->name()) + "��" +
                         MUD_NAME + NOR "�еĴ��󱨸���۵���Ϊ"
                         HIC + bug + NOR "�㡣\n");

        tell_object(me, sp);
        return 1;
}
 
int help(object me)
{
        write(@HELP
ָ���ʽ�� bug
           bug       <��������>               (��ʦר��)
           bug       [+|- <��������> <����>]  (��ʦר��)

���ָ�������ʾ������Ϸ�еĴ��󱨸���۵�������ҿ�ͨ��
�˵������һЩ�����������archȨ�޻����ϵ���ʦ���ߣ���ֱ
���ڹ���Ƶ���㱨������ʱ��ʦ���� BUG��С��������ӱ���
����������Ϸ������ʦ���ߣ�������ʽID���Ե���ʦ����ң���
�ǻ��ڵ�һʱ�����޸� BUG������ID���ӱ����������ע�⣬ֻ
�л㱨 BUG��ID���ܻ�õ��������һ�� BUG���������ͬʱ��
�֣�����������ӵ����Ȼ㱨�� BUG��ID�ϡ���

��ʦ����ʹ�� +|- ������ӻ��߼�����ҵı��������

ϸС����1��           (������֡���䲻ͨ��������©��)
һ�����3��           (����Ӱ�쵽��Ϸ�������еĴ���)
���ش���5��           (��������ۡ�����ĳЩϵͳ����)
��������10��1000��    (�����������������������Ĵ���)

HELP);
        return 1;
}

