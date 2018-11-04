#include <ansi.h>
inherit ITEM;

string long();

void create()
{
        set_name(NOR + WHT "�����ƪ" NOR, ({ "jiandian canpian", "jiandian", "canpian" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ų�ȱ��ȫ����ҳ��\n" NOR);
                set("value", 30);
                set("no_sell", "ʲô��������һ����ֽͷҲ������Ǯ��");
                set("material", "paper");
                set("skill_name", "��������");      // �о����ܵ�����
                set("skill_type", "sword");         // �о����ܵ�����
                set("power_point", 30000);          // ���Ӽ��ܵĵ���
                set("need_exp", 300000);            // �о��������;���
                set("min_lvl", 100);                // �о��������͵ȼ�
                set("max_lvl", 300);                // �ܹ��о�����ߵȼ�
        }
        setup();
}

void init()
{
        add_action("do_read", "read");
}

string long()
{
        string msg;

        if (query("power_point"))
        {
                msg = WHT "����һ��" + name() + NOR + WHT "��������"
                      "�Ѿ�������ʱ�ˡ�ҳƬ����������������д����Ӭ"
                      "ͷС�֣��ƺ�����" + query("skill_name") +
                      "�йأ���������Ŷ���(read)����Ҳ�����ѧ�ܹ�"
                      "����������";
        } else
                msg = "����һ�Ų�ȱ��ȫ����ҳ�����ּ����޷������ˡ�";

        return sort_string(msg, 54);
}

int do_read(string arg)
{
        object me = this_player();
        mapping my = me->query_entire_dbase();

        int na = this_object()->name();
        string booksk = this_object()->query("skill_type");

        if (me->is_busy())
                return notify_fail("����������æ��\n");

        if (me->is_fighting())
                return notify_fail("ս�����޷��ж���֪��\n");

        if (arg && id(arg))
        {
                if (me->query("combat_exp") < query("need_exp"))
                        return notify_fail("����ò�ҳ�ϼ��صĶ���̫����£�ƾ��"
                                           "������ѧ�ƺ����Բ��ꡣ\n");

                if (me->query_skill(booksk, 1) < query("min_lvl"))
                        return notify_fail("������Լ�������ܵ��˽��й�ǳ����"
                                           "һʱ�޷�����͸����\n");

                if (me->query_skill(booksk, 1) >= query("max_lvl"))
                        return notify_fail("����ò�ҳ�ϼ��صĶ���̫��ǳ�ԣ��޷�"
                                           "���л���κΰ�����\n");

                if (! me->can_improve_skill(booksk))
                        return notify_fail("������˰��죬�����ƺ�������������"
                                           "�����Ե�ʣ��ܶණ���޷���⡣\n");

                message_vision(HIW "$N" HIW "�۾�������Ķ���" NOR + na + HIW
                               "���������صĶ������ƺ������ջ�\n" NOR, me);

                if (me->can_improve_skill(booksk))
                        me->improve_skill(booksk, query("power_point"));

                tell_object(me, HIY "��ֻ����ǰ���ڵ�������ʻ�Ȼ���ʣ��ԡ�" +
                                query("skill_name") + "�������µĸ���\n" NOR);

                me->start_busy(random(20) + 20);
                destruct(this_object());
                return 1;
        }
}

int query_autoload()
{
        return 1;
}

