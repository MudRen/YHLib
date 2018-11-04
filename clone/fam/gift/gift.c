#include <ansi.h>
inherit COMBINED_ITEM;

string query_autoload()
{
        return query_amount() + "";
}

void create()
{
        set_name(HIY "�ɵ�" NOR, ({ "gift" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "����һ��������ò���ɵ���\n" NOR);
                set("base_unit", "��");
                set("base_value", 10000);
                set("base_weight", 50);
                set("only_do_effect", 1);

                // �����츳������
                set("gift_type", "per");

                // �츳���������
                set("gift_name", "��ò");

                // �ɹ��ļ���
                set("gift_point", 100);

                // �ɹ�������
                set("gift_msg", HIC "ͻȻ�����Ƥ��͸��һ������\n" NOR);
        }
        setup();
}

int do_effect(object me)
{
        int point;

        point = query("gift_point");

        // �������������ɹ�����
        if (me->query("special_skills/emperor"))
                point += 35;

        // ��ɷ���������ɹ�����
        if (me->query("special_skills/lonely"))
                point += 10;

        // ���Ǹ��������ɹ�����
        if (me->query("special_skill/lucky"))
                point += 5;

        message_vision(WHT "$N" WHT "һ������������һ" +
                       query("base_unit") + name() + WHT
                       "��\n" NOR, me);

        if (me->query("gift/" + query("gift_type") + "/all") >= 10)
        {
                tell_object(me, "�������ҩ����ûʲôЧ����\n");
        } else
        if (random(100) >= point)
        {
                tell_object(me, HIR "�����������ҩ����û��ʲô"
                                "���á�\n" NOR);

                // ��¼ʧ�ܵļǺ�
                me->add("gift/" + query("gift_type") + "/fail", 1);
        } else
        {
                tell_object(me, query("gift_msg"));
                tell_object(me, HIC "���" + query("gift_name") +
                                HIC "��������һ�㡣\n" NOR);

                // ��¼�ɹ��ļǺ�
                me->add("gift/" + query("gift_type") + "/succeed", 1);

                // ������Ӧ���츳����
                me->add(query("gift_type"), 1);
        }

        // ��¼��Ե�������
        me->add("gift/" + query("gift_type") + "/all", 1);

        add_amount(-1);
        if (query_amount() < 1)
                destruct(this_object());

        return 1;
}

void autoload(string param)
{
        int amt;

        if (sscanf(param, "%d", amt) == 1)
                set_amount(amt);
}

void setup()
{
        set_amount(1);
        ::setup();
}
